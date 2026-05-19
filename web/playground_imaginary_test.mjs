import fs from "node:fs";

import "../bootstrap/quon.js";
import "./source-bundle.js";
import "../ima/imaginary.js";

const handlers = {};

function makeElement(id) {
  const element = {
    id,
    hidden: false,
    value: "",
    classList: {
      add() {},
      remove() {},
      toggle() {},
    },
    dataset: {},
    options: [],
    selectedIndex: 0,
    selectedOptions: [{ dataset: { flags: "--node2" } }],
    appendChild(child) {
      this.options.push(child);
      if (!this.value) this.value = child.value;
    },
    addEventListener(type, fn) {
      handlers[`${id}:${type}`] = fn;
    },
  };

  let textContent = "";
  Object.defineProperty(element, "textContent", {
    get() {
      return textContent;
    },
    set(value) {
      textContent = value;
      if (id === "exampleSelect") {
        element.options = [];
        element.value = "";
      }
    },
  });

  return element;
}

const ids = [
  "exampleSelect",
  "targetSelect",
  "inputSyntaxSelect",
  "supportLibrariesToggle",
  "compileButton",
  "runButton",
  "sourceEditor",
  "compiledOutput",
  "runOutput",
  "imaginaryDocs",
  "imaginaryDocsStatus",
  "convertedPreview",
  "status",
  "sourceName",
  "outputName",
];

const elements = Object.fromEntries(ids.map((id) => [id, makeElement(id)]));
elements.targetSelect.value = "node2";
elements.targetSelect.options = [{ text: "Node.js" }];
elements.targetSelect.selectedOptions = [{ dataset: { flags: "--node2" } }];
elements.inputSyntaxSelect.value = "quon";

globalThis.document = {
  getElementById(id) {
    return elements[id];
  },
  createElement(tag) {
    return { tag, value: "", textContent: "", dataset: {} };
  },
};

const playgroundSource = fs.readFileSync(new URL("./playground.js", import.meta.url), "utf8");
new Function(playgroundSource)();

if (elements.inputSyntaxSelect.value !== "quon") {
  throw new Error("initial input changed");
}
if (elements.exampleSelect.options.some((option) => option.value.startsWith("imaginary"))) {
  throw new Error("Quon examples include Imaginary examples");
}

elements.inputSyntaxSelect.value = "imaginary";
handlers["inputSyntaxSelect:change"]();

if (elements.inputSyntaxSelect.value !== "imaginary") {
  throw new Error("input reset after changing to Imaginary");
}
if (!elements.exampleSelect.options.every((option) => option.value.startsWith("imaginary"))) {
  throw new Error("Imaginary example list is not filtered");
}

elements.exampleSelect.value = "imaginary branch";
handlers["exampleSelect:change"]();

if (elements.inputSyntaxSelect.value !== "imaginary") {
  throw new Error("example selection reset input");
}
if (elements.imaginaryDocs.hidden) {
  throw new Error("Imaginary docs are hidden");
}
if (!elements.convertedPreview.textContent.includes("(functions")) {
  throw new Error("converted preview missing functions section");
}
if (!elements.convertedPreview.textContent.includes("large %d")) {
  throw new Error("converted preview missing selected example");
}

console.log("playground imaginary docs ok");
