import fs from "node:fs";
import path from "node:path";
import { fileURLToPath } from "node:url";

const here = path.dirname(fileURLToPath(import.meta.url));
const root = path.resolve(here, "..");

function collectFiles(dir) {
  const entries = fs.readdirSync(path.join(root, dir), { withFileTypes: true });
  const files = [];

  for (const entry of entries) {
    const rel = path.join(dir, entry.name);
    if (entry.isDirectory()) {
      files.push(...collectFiles(rel));
    } else if (entry.isFile() && entry.name.endsWith(".qon")) {
      files.push(rel);
    }
  }

  return files;
}

const files = [
  "compiler.qon",
  ...collectFiles("q"),
  ...collectFiles("examples"),
].sort();

const bundle = {};
for (const file of files) {
  bundle[file] = fs.readFileSync(path.join(root, file), "utf8");
}

const output = `globalThis.QUON_SOURCE_BUNDLE = Object.freeze(${JSON.stringify(bundle, null, 2)});\n`;
fs.writeFileSync(path.join(here, "source-bundle.js"), output);
