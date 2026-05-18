(() => {
  "use strict";

  class ImaginarySyntaxError extends Error {
    constructor(message, token) {
      const location = token ? ` at ${token.line}:${token.column}` : "";
      super(`${message}${location}`);
      this.name = "ImaginarySyntaxError";
    }
  }

  function isSpace(ch) {
    return ch === " " || ch === "\t" || ch === "\n" || ch === "\r";
  }

  function isSpecial(ch) {
    return ch === "(" || ch === ")" || ch === "," || ch === ";" || ch === ":" || ch === "=";
  }

  function tokenize(source) {
    const tokens = [];
    let pos = 0;
    let line = 1;
    let column = 1;

    function push(type, value, startLine, startColumn) {
      tokens.push({ type, value, line: startLine, column: startColumn });
    }

    function advance(ch) {
      pos += 1;
      if (ch === "\n") {
        line += 1;
        column = 1;
      } else {
        column += 1;
      }
    }

    while (pos < source.length) {
      const ch = source[pos];
      if (isSpace(ch)) {
        advance(ch);
        continue;
      }

      const startLine = line;
      const startColumn = column;

      if (ch === "\"") {
        let out = "\"";
        advance(ch);
        while (pos < source.length) {
          const next = source[pos];
          out += next;
          advance(next);
          if (next === "\\") {
            if (pos >= source.length) break;
            out += source[pos];
            advance(source[pos]);
          } else if (next === "\"") {
            break;
          }
        }
        if (!out.endsWith("\"")) throw new ImaginarySyntaxError("unterminated string", { line: startLine, column: startColumn });
        push("string", out, startLine, startColumn);
        continue;
      }

      if (source.startsWith("->", pos)) {
        push("symbol", "->", startLine, startColumn);
        advance("-");
        advance(">");
        continue;
      }

      if (isSpecial(ch)) {
        push("symbol", ch, startLine, startColumn);
        advance(ch);
        continue;
      }

      let value = "";
      while (pos < source.length && !isSpace(source[pos]) && !isSpecial(source[pos])) {
        if (source.startsWith("->", pos)) break;
        value += source[pos];
        advance(source[pos]);
      }
      push("word", value, startLine, startColumn);
    }

    return tokens;
  }

  class Parser {
    constructor(source) {
      this.tokens = tokenize(source);
      this.pos = 0;
    }

    peek(offset = 0) {
      return this.tokens[this.pos + offset] || null;
    }

    at(value) {
      const token = this.peek();
      return Boolean(token && token.value === value);
    }

    atLabel(value) {
      return this.at(value) && this.peek(1) && this.peek(1).value === ":";
    }

    take() {
      const token = this.peek();
      if (!token) throw new ImaginarySyntaxError("unexpected end of input", this.tokens[this.tokens.length - 1]);
      this.pos += 1;
      return token;
    }

    expect(value) {
      const token = this.take();
      if (token.value !== value) throw new ImaginarySyntaxError(`expected ${value}, got ${token.value}`, token);
      return token;
    }

    expectLabel(value) {
      this.expect(value);
      this.expect(":");
    }

    expectWord(label) {
      const token = this.take();
      if (token.type !== "word" && token.type !== "string") {
        throw new ImaginarySyntaxError(`expected ${label}, got ${token.value}`, token);
      }
      return token.value;
    }

    eof() {
      return this.pos >= this.tokens.length;
    }

    parseProgram() {
      this.expectLabel("Includes");
      const includes = [];
      while (!this.atLabel("Types")) includes.push(this.expectWord("include"));
      this.expectLabel("Types");
      const types = [];
      while (!this.atLabel("Functions")) types.push(this.parseType());
      this.expectLabel("Functions");
      const functions = [];
      while (!this.eof()) functions.push(this.parseFunction());
      return `(\n(includes ${includes.join(" ")} )\n\n(types ${types.join("")})\n(functions \n\n${functions.join("")} )\n)`;
    }

    parseType() {
      this.expect("type");
      const name = this.expectWord("type name");
      this.expect("is");
      if (this.at("struct")) {
        this.take();
        this.expect("(");
        const fields = [];
        while (!this.at(")")) fields.push(this.parseTypeBody());
        this.expect(")");
        this.expect(";");
        return `(${name} (struct \n${fields.join("")}))`;
      }
      const body = [];
      while (!this.at(";")) body.push(this.expectWord("type body"));
      this.expect(";");
      return `(${name} ${body.join(" ")})\n`;
    }

    parseTypeBody() {
      const name = this.expectWord("type body name");
      this.expect("is");
      const body = [];
      while (!this.at(";")) body.push(this.expectWord("type body"));
      this.expect(";");
      return `(${name} ${body.join(" ")})\n`;
    }

    parseFunction() {
      this.expect("fu");
      const name = this.expectWord("function name");
      this.expect("(");
      const args = this.parseArgList();
      this.expect(")");
      this.expect("->");
      const returnType = this.expectWord("return type");
      const declarations = [];
      while (!this.at("in")) declarations.push(this.parseDeclaration());
      this.expect("in");
      const body = this.parseStatements(["end"]);
      this.expect("end");
      this.expect("function");
      return `(${returnType} ${name} (${args.join(" ")})\n(declare ${declarations.join("")})\n(body ${body.join("")}))\n `;
    }

    parseArgList() {
      const args = [];
      if (this.at(")")) return args;
      while (true) {
        const name = this.expectWord("argument name");
        this.expect(":");
        const type = this.expectWord("argument type");
        args.push(`${type} ${name}`);
        if (!this.at(",")) break;
        this.take();
      }
      return args;
    }

    parseDeclaration() {
      const name = this.expectWord("declaration name");
      this.expect(":");
      const type = this.expectWord("declaration type");
      const expression = this.parseExpression();
      return `\n(${type} ${name} ${expression})`;
    }

    parseStatements(stoppers) {
      const statements = [];
      while (!this.eof() && !stoppers.includes(this.peek().value)) statements.push(this.parseStatement());
      return statements;
    }

    parseStatement() {
      if (this.at("if")) return this.parseIf();
      if (this.at("return")) return this.parseReturn();
      if (this.peek(1) && this.peek(1).value === "=") return this.parseSet();
      const expression = this.parseExpression();
      this.expect(";");
      return `\n${expression}`;
    }

    parseIf() {
      this.expect("if");
      const condition = this.parseExpression();
      this.expect("then");
      const trueBranch = this.parseStatements(["else"]);
      this.expect("else");
      const falseBranch = this.parseStatements(["end"]);
      this.expect("end");
      return `\n(if ${condition} \n(then ${trueBranch.join("")}) \n(else ${falseBranch.join("")}))\n`;
    }

    parseReturn() {
      this.expect("return");
      if (this.at(";")) {
        this.take();
        return "\n(return)";
      }
      let expression = "";
      if (this.at("(")) {
        this.take();
        expression = this.parseExpression();
        this.expect(")");
      } else {
        expression = this.parseExpression();
      }
      this.expect(";");
      return `\n(return ${expression})`;
    }

    parseSet() {
      const name = this.expectWord("assignment target");
      this.expect("=");
      const expression = this.parseExpression();
      this.expect(";");
      return `\n(set ${name} ${expression})`;
    }

    parseExpression() {
      const head = this.expectWord("expression");
      if (!this.at("(")) return head;
      this.take();
      const args = [];
      if (!this.at(")")) {
        while (true) {
          args.push(this.parseExpression());
          if (!this.at(",")) break;
          this.take();
        }
      }
      this.expect(")");
      return `(${head}${args.length ? ` ${args.join(" ")}` : ""})`;
    }
  }

  function convertImaginaryToQuon(source) {
    const parser = new Parser(source);
    const program = parser.parseProgram();
    if (!parser.eof()) throw new ImaginarySyntaxError(`unexpected token ${parser.peek().value}`, parser.peek());
    return program;
  }

  const api = { convertImaginaryToQuon, ImaginarySyntaxError, tokenize };

  if (typeof module !== "undefined" && module.exports) module.exports = api;
  if (typeof globalThis !== "undefined") globalThis.QuonImaginary = api;

  if (typeof require === "function" && typeof module !== "undefined" && require.main === module) {
    const fs = require("fs");
    const path = require("path");
    const args = process.argv.slice(2);
    const filename = args.length > 0 && !args[0].startsWith("--") ? args.shift() : null;

    function readProjectFile(name) {
      const normalized = String(name || "").replace(/\\/g, "/").replace(/^\.\//, "");
      const candidates = [
        path.resolve(process.cwd(), normalized),
        path.resolve(__dirname, "..", normalized),
      ];
      for (const candidate of candidates) {
        try {
          return fs.readFileSync(candidate, "utf8");
        } catch (error) {
          // Try the next candidate.
        }
      }
      return null;
    }

    try {
      const source = filename ? fs.readFileSync(filename, "utf8") : fs.readFileSync(0, "utf8");
      const quonSource = convertImaginaryToQuon(source);
      if (args.length === 0) {
        process.stdout.write(quonSource);
        process.stdout.write("\n");
      } else {
        const compiler = require("../bootstrap/quon.js");
        let output = "";
        let diagnostics = "";
        compiler.runQuon(["imaginary-output.qon", ...args], {
          readFile: (name) => name === "imaginary-output.qon" ? quonSource : readProjectFile(name),
          write: (s) => { output += s; },
          error: (s) => { diagnostics += s; },
          exit: (code) => { throw new Error(`exit ${code}`); },
        });
        if (diagnostics) process.stderr.write(diagnostics);
        process.stdout.write(output);
      }
    } catch (error) {
      process.stderr.write(`${error && error.message ? error.message : error}\n`);
      process.exit(1);
    }
  }
})();
