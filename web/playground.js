(() => {
  "use strict";

  const compiler = globalThis.QuonProgram;
  const sources = globalThis.QUON_SOURCE_BUNDLE || {};

  const exampleSelect = document.getElementById("exampleSelect");
  const targetSelect = document.getElementById("targetSelect");
  const inputSyntaxSelect = document.getElementById("inputSyntaxSelect");
  const supportLibrariesToggle = document.getElementById("supportLibrariesToggle");
  const compileButton = document.getElementById("compileButton");
  const runButton = document.getElementById("runButton");
  const sourceEditor = document.getElementById("sourceEditor");
  const compiledOutput = document.getElementById("compiledOutput");
  const runOutput = document.getElementById("runOutput");
  const imaginaryDocs = document.getElementById("imaginaryDocs");
  const imaginaryDocsStatus = document.getElementById("imaginaryDocsStatus");
  const convertedPreview = document.getElementById("convertedPreview");
  const status = document.getElementById("status");
  const sourceName = document.getElementById("sourceName");
  const outputName = document.getElementById("outputName");

  const examples = [
    { name: "hello body", source: "(printf \"%s\" \"Hello world\\n\")\n(printf \"%d\\n\" 42)" },
    { name: "branch body", source: "(if (> 3 2)\n  (then (printf \"%s\" \"yes\\n\"))\n  (else (printf \"%s\" \"no\\n\")))" },
    { name: "start function", source: "(int start () (declare)\n  (body\n    (printf \"%s\" \"Hello from start\\n\")\n    (return 0)))" },
    { name: "simple type", source: "(Thing\n  (struct\n    (name string)\n    (count int)))" },
    { name: "imaginary hello", sourceName: "ima/hello.ima", syntax: "imaginary" },
    {
      name: "imaginary branch",
      syntax: "imaginary",
      source: "Includes: \"q/base.qon\"\nTypes:\nFunctions:\nfu start() -> int\n  count: int 3\nin\n  if greaterthan(count, 1) then\n    printf(\"large %d\\n\", count);\n  else\n    printf(\"small %d\\n\", count);\n  end\n  return(0);\nend function",
    },
    {
      name: "imaginary locals",
      syntax: "imaginary",
      source: "Includes: \"q/base.qon\"\nTypes:\ntype Counter is int;\nFunctions:\nfu start() -> int\n  name: string \"Quon\"\n  count: int 2\nin\n  printf(\"Hello %s %d\\n\", name, count);\n  return(0);\nend function",
    },
    { name: "imaginary factorial", sourceName: "ima/pairsum.ima", syntax: "imaginary" },
    { name: "hello program", sourceName: "examples/hello.qon" },
    { name: "compiler", sourceName: "compiler.qon" },
  ];

  let currentProgramName = examples[0].name;
  let lastOutput = "";
  let lastCompileMode = "";
  let lastIncludesSupport = false;
  let activeCompileSource = null;

  function normalizeName(filename) {
    return String(filename || "").replace(/\\/g, "/").replace(/^\.\//, "");
  }

  function readFile(filename) {
    const name = normalizeName(filename);
    if (name === currentProgramName || name === "playground.qon") {
      return activeCompileSource || sourceEditor.value;
    }
    if (Object.prototype.hasOwnProperty.call(sources, name)) return sources[name];
    if (Object.prototype.hasOwnProperty.call(sources, `q/${name}`)) return sources[`q/${name}`];
    if (Object.prototype.hasOwnProperty.call(sources, `examples/${name}`)) return sources[`examples/${name}`];
    return null;
  }

  function setStatus(message, isError = false) {
    status.textContent = message;
    status.classList.toggle("error", isError);
  }

  function selectedFlags() {
    return (targetSelect.selectedOptions[0].dataset.flags || "").split(" ").filter(Boolean);
  }

  function selectedTarget() {
    return targetSelect.value;
  }

  function includeSupportLibraries() {
    return supportLibrariesToggle.checked;
  }

  function selectedInputSyntax() {
    return inputSyntaxSelect.value;
  }

  function exampleSyntax(example) {
    return example && example.syntax ? example.syntax : "quon";
  }

  function exampleAvailable(example) {
    return !example.sourceName || Object.prototype.hasOwnProperty.call(sources, example.sourceName);
  }

  function sourceToQuon(source) {
    if (selectedInputSyntax() === "imaginary") {
      if (!globalThis.QuonImaginary || typeof globalThis.QuonImaginary.convertImaginaryToQuon !== "function") {
        throw new Error("Imaginary converter unavailable");
      }
      return globalThis.QuonImaginary.convertImaginaryToQuon(source);
    }
    return source;
  }

  function clearCompileResult() {
    lastOutput = "";
    lastCompileMode = "";
    lastIncludesSupport = false;
    compiledOutput.textContent = "";
    runOutput.textContent = "";
    outputName.textContent = "";
    updateRunButton();
  }

  function updateDocs() {
    const isImaginary = selectedInputSyntax() === "imaginary";
    imaginaryDocs.hidden = !isImaginary;
    if (!isImaginary) return;

    if (!globalThis.QuonImaginary || typeof globalThis.QuonImaginary.convertImaginaryToQuon !== "function") {
      convertedPreview.textContent = "";
      imaginaryDocsStatus.textContent = "Converter unavailable";
      imaginaryDocsStatus.classList.add("docs-error");
      return;
    }

    try {
      convertedPreview.textContent = globalThis.QuonImaginary.convertImaginaryToQuon(sourceEditor.value);
      imaginaryDocsStatus.textContent = "Converted preview";
      imaginaryDocsStatus.classList.remove("docs-error");
    } catch (error) {
      convertedPreview.textContent = "";
      imaginaryDocsStatus.textContent = error && error.message ? error.message : String(error);
      imaginaryDocsStatus.classList.add("docs-error");
    }
  }

  function supportProgramFromBody(source, hasBodyForm) {
    const body = hasBodyForm ? source : `(body\n${source}\n(return 0))`;
    return `(\n (includes q/base.qon)\n (types)\n (functions\n  (int start () (declare)\n   ${body})\n ))`;
  }

  function supportProgramFromFunctions(source, hasSection) {
    const functions = hasSection ? source : `(functions\n${source}\n)`;
    return `(\n (includes q/base.qon)\n (types)\n ${functions}\n)`;
  }

  function supportProgramFromTypes(source, hasSection) {
    const types = hasSection ? source : `(types\n${source}\n)`;
    return `(\n (includes q/base.qon)\n ${types}\n (functions\n  (int start () (declare) (body (return 0))))\n)`;
  }

  function tryBareCompile(source) {
    const target = selectedTarget();
    const attempts = [
      {
        mode: "body",
        compile: () => compiler.compileBodyString(source, "playground-body.qon", target),
        supportSource: () => supportProgramFromBody(source, false),
      },
      {
        mode: "body section",
        compile: () => compiler.compileBodySectionString(source, "playground-body.qon", target),
        supportSource: () => supportProgramFromBody(source, true),
      },
      {
        mode: "functions",
        compile: () => compiler.compileFunctionsString(source, "playground-functions.qon", target),
        supportSource: () => supportProgramFromFunctions(source, false),
      },
      {
        mode: "functions section",
        compile: () => compiler.compileFunctionsSectionString(source, "playground-functions.qon", target),
        supportSource: () => supportProgramFromFunctions(source, true),
      },
      {
        mode: "types",
        compile: () => compiler.compileTypesString(source, "playground-types.qon", target),
        supportSource: () => supportProgramFromTypes(source, false),
      },
      {
        mode: "types section",
        compile: () => compiler.compileTypesSectionString(source, "playground-types.qon", target),
        supportSource: () => supportProgramFromTypes(source, true),
      },
      {
        mode: "program",
        compile: () => compiler.compileProgramBareString(source, "playground.qon", target),
        supportSource: () => source,
      },
    ];

    const failures = [];
    for (const attempt of attempts) {
      try {
        return {
          mode: attempt.mode,
          output: attempt.compile(),
          supportSource: attempt.supportSource(),
        };
      } catch (error) {
        failures.push(`${attempt.mode}: ${error && error.message ? error.message : error}`);
      }
    }

    throw new Error(`Could not parse as body, functions, types, or program.\n${failures.join("\n")}`);
  }

  function compile() {
    let output = "";
    let diagnostics = "";
    runOutput.textContent = "";

    try {
      const inputSyntax = selectedInputSyntax();
      const quonSource = sourceToQuon(sourceEditor.value);
      const detected = tryBareCompile(quonSource);

      if (includeSupportLibraries()) {
        activeCompileSource = detected.supportSource;
        compiler.runQuon(["playground.qon", ...selectedFlags()], {
          readFile,
          write: (s) => { output += s; },
          error: (s) => { diagnostics += s; },
          exit: (code) => { throw new Error(`exit ${code}`); },
        });
        activeCompileSource = null;
        lastIncludesSupport = true;
      } else {
        output = detected.output;
        lastIncludesSupport = false;
      }
      lastCompileMode = detected.mode;
      lastOutput = output;
      compiledOutput.textContent = output;
      const inputLabel = inputSyntax === "imaginary" ? "Imaginary -> " : "";
      outputName.textContent = `${inputLabel}${targetSelect.options[targetSelect.selectedIndex].text} ${detected.mode}`;
      setStatus(diagnostics ? `Compiled ${inputSyntax} ${detected.mode} with diagnostics` : `Compiled ${inputSyntax} ${detected.mode}`);
      if (diagnostics) runOutput.textContent = diagnostics;
    } catch (error) {
      activeCompileSource = null;
      lastOutput = output;
      lastIncludesSupport = false;
      lastCompileMode = "";
      compiledOutput.textContent = output;
      runOutput.textContent = diagnostics + String(error && error.stack ? error.stack : error);
      setStatus("Compile failed", true);
    }

    updateRunButton();
  }

  function runGeneratedJs() {
    let output = "";
    let diagnostics = "";

    try {
      if (!lastIncludesSupport) {
        if (!lastCompileMode.startsWith("body")) {
          throw new Error("Only body snippets can run without support libraries");
        }
        const stderr = { write: (s) => { diagnostics += String(s); } };
        const printf = (fmt, ...args) => { output += compiler.cformat(fmt, ...args); };
        const fprintf = (stream, fmt, ...args) => { stream.write(compiler.cformat(fmt, ...args)); };
        const runSnippet = new Function("printf", "fprintf", "stderr", lastOutput);
        runSnippet(printf, fprintf, stderr);
        runOutput.textContent = diagnostics + output;
        setStatus("Ran JS body");
        return;
      }

      const module = { exports: {} };
      const sandboxGlobal = {};
      const loadProgram = new Function(
        "module",
        "exports",
        "require",
        "process",
        "console",
        "globalThis",
        `${lastOutput}\nreturn module.exports || globalThis.QuonProgram;`,
      );
      const program = loadProgram(module, module.exports, undefined, undefined, console, sandboxGlobal);
      if (!program || typeof program.runQuon !== "function") {
        throw new Error("generated program did not export runQuon");
      }
      program.runQuon([], {
        readFile,
        write: (s) => { output += s; },
        error: (s) => { diagnostics += s; },
        exit: (code) => { throw new Error(`exit ${code}`); },
      });
      runOutput.textContent = diagnostics + output;
      setStatus("Ran JS");
    } catch (error) {
      runOutput.textContent = diagnostics + output + String(error && error.stack ? error.stack : error);
      setStatus("Run failed", true);
    }
  }

  function updateRunButton() {
    runButton.disabled = selectedTarget() !== "node2" || !lastOutput || (!lastIncludesSupport && !lastCompileMode.startsWith("body"));
  }

  function loadExample(name) {
    currentProgramName = name;
    const example = examples.find((item) => item.name === name);
    sourceEditor.value = example && example.sourceName ? sources[example.sourceName] || "" : example ? example.source : "";
    sourceName.textContent = name;
    clearCompileResult();
    updateDocs();
    setStatus("Ready");
  }

  function populateExamples() {
    const previous = exampleSelect.value;
    const syntax = selectedInputSyntax();
    const availableExamples = examples.filter((example) => exampleAvailable(example) && exampleSyntax(example) === syntax);
    exampleSelect.textContent = "";

    for (const example of availableExamples) {
      const option = document.createElement("option");
      option.value = example.name;
      option.textContent = example.name;
      exampleSelect.appendChild(option);
    }

    const names = availableExamples.map((example) => example.name);
    const next = names.includes(previous) ? previous : names[0];
    if (next) {
      exampleSelect.value = next;
      loadExample(next);
    } else {
      currentProgramName = "";
      sourceEditor.value = "";
      sourceName.textContent = "";
      clearCompileResult();
      updateDocs();
      setStatus("No examples");
    }
  }

  function init() {
    if (!compiler || typeof compiler.runQuon !== "function") {
      setStatus("Compiler unavailable", true);
      compileButton.disabled = true;
      runButton.disabled = true;
      return;
    }

    exampleSelect.addEventListener("change", () => loadExample(exampleSelect.value));
    targetSelect.addEventListener("change", updateRunButton);
    inputSyntaxSelect.addEventListener("change", () => {
      populateExamples();
    });
    sourceEditor.addEventListener("input", () => {
      clearCompileResult();
      updateDocs();
      setStatus("Ready");
    });
    supportLibrariesToggle.addEventListener("change", updateRunButton);
    compileButton.addEventListener("click", compile);
    runButton.addEventListener("click", runGeneratedJs);

    populateExamples();
  }

  init();
})();
