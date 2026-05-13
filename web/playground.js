(() => {
  "use strict";

  const compiler = globalThis.QuonProgram;
  const sources = globalThis.QUON_SOURCE_BUNDLE || {};

  const exampleSelect = document.getElementById("exampleSelect");
  const targetSelect = document.getElementById("targetSelect");
  const supportLibrariesToggle = document.getElementById("supportLibrariesToggle");
  const compileButton = document.getElementById("compileButton");
  const runButton = document.getElementById("runButton");
  const sourceEditor = document.getElementById("sourceEditor");
  const compiledOutput = document.getElementById("compiledOutput");
  const runOutput = document.getElementById("runOutput");
  const status = document.getElementById("status");
  const sourceName = document.getElementById("sourceName");
  const outputName = document.getElementById("outputName");

  const examples = [
    { name: "hello body", source: "(printf \"%s\" \"Hello world\\n\")\n(printf \"%d\\n\" 42)" },
    { name: "branch body", source: "(if (> 3 2)\n  (then (printf \"%s\" \"yes\\n\"))\n  (else (printf \"%s\" \"no\\n\")))" },
    { name: "start function", source: "(int start () (declare)\n  (body\n    (printf \"%s\" \"Hello from start\\n\")\n    (return 0)))" },
    { name: "simple type", source: "(Thing\n  (struct\n    (name string)\n    (count int)))" },
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
      const detected = tryBareCompile(sourceEditor.value);

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
      outputName.textContent = `${targetSelect.options[targetSelect.selectedIndex].text} ${detected.mode}`;
      setStatus(diagnostics ? `Compiled ${detected.mode} with diagnostics` : `Compiled ${detected.mode}`);
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
    compiledOutput.textContent = "";
    runOutput.textContent = "";
    lastOutput = "";
    lastCompileMode = "";
    lastIncludesSupport = false;
    updateRunButton();
    setStatus("Ready");
  }

  function populateExamples() {
    const previous = exampleSelect.value;
    exampleSelect.textContent = "";

    for (const example of examples) {
      if (example.sourceName && !Object.prototype.hasOwnProperty.call(sources, example.sourceName)) continue;
      const option = document.createElement("option");
      option.value = example.name;
      option.textContent = example.name;
      exampleSelect.appendChild(option);
    }

    const names = examples.map((example) => example.name);
    const next = names.includes(previous) ? previous : exampleSelect.value || names[0];
    if (next) {
      exampleSelect.value = next;
      loadExample(next);
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
    supportLibrariesToggle.addEventListener("change", updateRunButton);
    compileButton.addEventListener("click", compile);
    runButton.addEventListener("click", runGeneratedJs);

    populateExamples();
  }

  init();
})();
