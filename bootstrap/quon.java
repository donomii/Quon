import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.HashMap;

class QuonProgram {
  boolean globalTrace = false;
  boolean globalStepTrace = false;
  boolean releaseMode = false;
  Box globalStackTrace = null;
  String caller = "";
  String[] globalArgs = new String[0];
  int globalArgsCount = 0;

  Object stderr = new Object();

  void fprintf(Object stream, String format, Object... args) {
    if (args.length == 0) {
      System.err.print(format);
    } else {
      System.err.printf(format, args);
    }
  }

  void exit(int code) {
    System.exit(code);
  }

  Box readFileBox(String filename) {
    try {
      return boxString(Files.readString(Paths.get(filename)));
    } catch (Exception e) {
      return null;
    }
  }

  void writeFileUnchecked(String filename, String data) {
    try {
      Files.write(Paths.get(filename), data.getBytes(StandardCharsets.UTF_8));
    } catch (Exception e) {
      throw new RuntimeException("Could not write file: " + filename, e);
    }
  }

class Box {
  Box lis;
  String str;
  int i;
  double f;
  String typ;
  boolean voi;
  boolean boo;
  int lengt;
  Box car;
  Box cdr;
  Box tag;
}


boolean notBool(boolean a) {
  
  if ( a) {
    return false;

  } else {
    return true;

  }

}


boolean andBool(boolean a, boolean b) {
  
  if ( a) {
    if ( b) {
      return true;

    } else {
      return false;

    }

  } else {
    return false;

  }

}


boolean orBool(boolean a, boolean b) {
  
  if ( a) {
    return true;

  } else {
    if ( b) {
      return true;

    } else {
      return false;

    }

  }

}


boolean nand(boolean a, boolean b) {
  
  return notBool(andBool(a, b));

}


boolean xor(boolean a, boolean b) {
  
  return nand(nand(a, nand(a, b)), nand(b, nand(a, b)));

}


boolean lessThan(int a, int b) {
  
  return andBool(notBool(equal(a, b)), notBool(greaterthan(a, b)));

}


void parserValidateBodyForm(Box bodyForm, String filename) {
  
  if ( isNil(bodyForm)) {
    parserPanicAt(filename, null, "empty body fragment");

  } else {
  }

  if ( isList(bodyForm)) {
  } else {
    parserPanicAtNode(filename, bodyForm, "body fragment must be a list");

  }

  if ( parserListStartsWith(bodyForm, "body")) {
    parserValidateBody(cdr(bodyForm), filename);

  } else {
    parserPanicAtNode(filename, bodyForm, "expected body fragment");

  }

}


Box readBodySexpr(String aStr, String filename) {
  Box tokens = null;
Box as = null;
Box bodyForm = null;

  bodyForm = readSingleSexpr(aStr, filename);

  parserValidateBodyForm(bodyForm, filename);

  return bodyForm;

}


Box readSingleSexpr(String aStr, String filename) {
  Box tokens = null;
Box as = null;

  tokens = emptyList();

  tokens = filterTokens(filterVoid(scan(aStr, 0, 1, 0, 0, filename)));

  parserValidateParens(tokens, null, filename);

  as = sexprTree(tokens);

  parserValidateRoot(as, filename);

  return car(as);

}


Box readBodyFragment(String source, String filename) {
  String wrapped = "";

  wrapped = stringConcatenate("(body\n", stringConcatenate(source, "\n)"));

  return readBodySexpr(wrapped, filename);

}


Box readFunctionsSexpr(String aStr, String filename) {
  Box section = null;

  section = readSingleSexpr(aStr, filename);

  parserValidateSection(section, "functions", filename);

  parserValidateFunctions(cdr(section), filename);

  return section;

}


Box readFunctionsFragment(String source, String filename) {
  String wrapped = "";

  wrapped = stringConcatenate("(functions\n", stringConcatenate(source, "\n)"));

  return readFunctionsSexpr(wrapped, filename);

}


Box readTypesSexpr(String aStr, String filename) {
  Box section = null;

  section = readSingleSexpr(aStr, filename);

  parserValidateSection(section, "types", filename);

  parserRejectFunctionDefinitions(cdr(section), filename);

  return section;

}


Box readTypesFragment(String source, String filename) {
  String wrapped = "";

  wrapped = stringConcatenate("(types\n", stringConcatenate(source, "\n)"));

  return readTypesSexpr(wrapped, filename);

}


String bodyTreeToString(Box tree) {
  
  return ListToString(flatten(tree), 0, true, false);

}


String compileBodySectionString(String source, String filename, String target) {
  Box bodyForm = null;

  bodyForm = readBodySexpr(source, filename);

  return compileBodyForm(bodyForm, target);

}


String compileBodyString(String source, String filename, String target) {
  Box bodyForm = null;

  bodyForm = readBodyFragment(source, filename);

  return compileBodyForm(bodyForm, target);

}


String compileBodyForm(Box bodyForm, String target) {
  Box variables = null;

  if ( equalString(target, "node2")) {
    return bodyTreeToString(node2Body(cdr(bodyForm), 0, "snippet"));

  } else {
  }

  if ( equalString(target, "perl")) {
    variables = getGlobalVariables();

    return bodyTreeToString(perlBody(cdr(bodyForm), 0, variables));

  } else {
  }

  if ( equalString(target, "java")) {
    return bodyTreeToString(javaBody(cdr(bodyForm), 0));

  } else {
  }

  if ( equalString(target, "haskell")) {
    variables = haskellGlobalVariables();

    return bodyTreeToString(haskellBody(cdr(bodyForm), 0, variables));

  } else {
  }

  if ( orBool(equalString(target, "ansi3"), equalString(target, "ansi3-release"))) {
    releaseMode = true;

    return bodyTreeToString(ansi3Body(cdr(bodyForm), 0, "snippet"));

  } else {
  }

  panic(stringConcatenate("unknown body target: ", target));

  return "";

}


String compileFunctionsSectionString(String source, String filename, String target) {
  Box section = null;

  section = readFunctionsSexpr(source, filename);

  return compileFunctionsSection(section, target);

}


String compileFunctionsString(String source, String filename, String target) {
  Box section = null;

  section = readFunctionsFragment(source, filename);

  return compileFunctionsSection(section, target);

}


String compileFunctionsSection(Box section, String target) {
  
  if ( equalString(target, "node2")) {
    return bodyTreeToString(node2Functions(cdr(section)));

  } else {
  }

  if ( equalString(target, "perl")) {
    return bodyTreeToString(perlFunctions(cdr(section)));

  } else {
  }

  if ( equalString(target, "java")) {
    return bodyTreeToString(javaFunctions(cdr(section)));

  } else {
  }

  if ( equalString(target, "haskell")) {
    return bodyTreeToString(haskellFunctions(cdr(section)));

  } else {
  }

  if ( orBool(equalString(target, "ansi3"), equalString(target, "ansi3-release"))) {
    releaseMode = true;

    return bodyTreeToString(ansi3Functions(cdr(section)));

  } else {
  }

  panic(stringConcatenate("unknown functions target: ", target));

  return "";

}


String compileTypesSectionString(String source, String filename, String target) {
  Box section = null;

  section = readTypesSexpr(source, filename);

  return compileTypesSection(section, target);

}


String compileTypesString(String source, String filename, String target) {
  Box section = null;

  section = readTypesFragment(source, filename);

  return compileTypesSection(section, target);

}


String compileTypesSection(Box section, String target) {
  
  if ( equalString(target, "node2")) {
    return bodyTreeToString(node2Types(cdr(section)));

  } else {
  }

  if ( equalString(target, "perl")) {
    return bodyTreeToString(perlTypes(cdr(section)));

  } else {
  }

  if ( equalString(target, "java")) {
    return bodyTreeToString(javaTypes(cdr(section)));

  } else {
  }

  if ( equalString(target, "haskell")) {
    return bodyTreeToString(haskellTypes(cdr(section)));

  } else {
  }

  if ( orBool(equalString(target, "ansi3"), equalString(target, "ansi3-release"))) {
    return bodyTreeToString(ansi3Types(cdr(section)));

  } else {
  }

  panic(stringConcatenate("unknown types target: ", target));

  return "";

}


String compileProgramBareString(String source, String filename, String target) {
  Box tree = null;

  tree = readSexpr(source, filename);

  tree = macrowalk(tree);

  if ( equalString(target, "java")) {
    tree = javaApplyTypeAliases(tree, cdr(getTypes(tree)));

  } else {
  }

  if ( equalString(target, "haskell")) {
    tree = haskellApplyTypeAliases(tree, cdr(getTypes(tree)));

  } else {
  }

  if ( equalString(target, "node2")) {
    return bodyTreeToString(cons(id(node2Types(getTypes(tree))), cons(id(node2Functions(getFunctions(tree))), null)));

  } else {
  }

  if ( equalString(target, "perl")) {
    return bodyTreeToString(cons(id(perlTypes(getTypes(tree))), cons(id(perlFunctions(getFunctions(tree))), null)));

  } else {
  }

  if ( equalString(target, "java")) {
    return bodyTreeToString(cons(id(javaTypes(getTypes(tree))), cons(id(javaFunctions(getFunctions(tree))), null)));

  } else {
  }

  if ( equalString(target, "haskell")) {
    return bodyTreeToString(cons(id(haskellTypes(getTypes(tree))), cons(id(haskellFunctions(getFunctions(tree))), null)));

  } else {
  }

  if ( orBool(equalString(target, "ansi3"), equalString(target, "ansi3-release"))) {
    releaseMode = true;

    return bodyTreeToString(cons(id(ansi3Types(getTypes(tree))), cons(id(ansi3Functions(getFunctions(tree))), null)));

  } else {
  }

  panic(stringConcatenate("unknown program target: ", target));

  return "";

}


Box node2FunctionArgs(Box tree) {
  
  if ( isEmpty(tree)) {
    return emptyList();

  } else {
    if ( equalString(stringify(first(tree)), "...")) {
      if ( isNil(cddr(tree))) {
        return cons(boxString("..."), null);

      } else {
        return cons(boxString("..."), cons(boxString(", "), cons(id(node2FunctionArgs(cddr(tree))), null)));

      }

    } else {
      if ( isNil(cddr(tree))) {
        return cons(id(node2FuncMap(second(tree))), null);

      } else {
        return cons(id(node2FuncMap(second(tree))), cons(boxString(", "), cons(id(node2FunctionArgs(cddr(tree))), null)));

      }

    }

  }

}


Box node2Atom(Box tree) {
  
  if ( equalString("string", boxType(tree))) {
    return cons(boxString("\""), cons(id(boxString(stringify(tree))), cons(boxString("\""), null)));

  } else {
    return cons(id(node2FuncMap(tree)), null);

  }

}


Box node2Expression(Box tree, int indent) {
  Box thing = null;

  if ( notBool(isList(tree))) {
    return node2Atom(tree);

  } else {
    if ( equal(1, listLength(tree))) {
      if ( equalBox(boxString("return"), car(tree))) {
        return cons(id(node2FuncMap(car(tree))), null);

      } else {
        return cons(id(node2FuncMap(car(tree))), cons(boxString("()"), null));

      }

    } else {
      thing = first(tree);

      if ( equalBox(boxSymbol("get-struct"), thing)) {
        return cons(id(node2Expression(second(tree), indent)), cons(boxString("."), cons(id(third(tree)), null)));

      } else {
        if ( equalBox(boxSymbol("new"), thing)) {
          return cons(boxString("{}"), null);

        } else {
          if ( equalBox(boxSymbol("passthrough"), thing)) {
            return cons(id(second(tree)), null);

          } else {
            if ( equalBox(boxSymbol("binop"), thing)) {
              return cons(boxString("("), cons(id(node2Expression(third(tree), indent)), cons(boxString(" "), cons(id(second(tree)), cons(boxString(" "), cons(id(node2Expression(fourth(tree), indent)), cons(boxString(")"), null)))))));

            } else {
              return cons(id(node2FuncMap(car(tree))), cons(boxString("("), cons(id(node2RecurList(cdr(tree), indent)), cons(boxString(")"), null))));

            }

          }

        }

      }

    }

  }

}


Box node2RecurList(Box expr, int indent) {
  
  if ( isEmpty(expr)) {
    return emptyList();

  } else {
    if ( isNil(cdr(expr))) {
      return node2Expression(car(expr), indent);

    } else {
      return cons(id(node2Expression(car(expr), indent)), cons(boxString(", "), cons(id(node2RecurList(cdr(expr), indent)), null)));

    }

  }

}


Box node2If(Box node, int indent, String functionName) {
  
  return cons(id(listNewLine(indent)), cons(boxString("if ("), cons(id(node2Expression(second(node), 0)), cons(boxString(") {"), cons(id(node2Body(cdr(third(node)), add1(indent), functionName)), cons(id(listNewLine(indent)), cons(boxString("} else {"), cons(id(node2Body(cdr(fourth(node)), add1(indent), functionName)), cons(id(listNewLine(indent)), cons(boxString("}"), null))))))))));

}


Box node2SetStruct(Box node, int indent) {
  
  return cons(id(listNewLine(indent)), cons(id(node2Expression(second(node), indent)), cons(boxString("."), cons(id(third(node)), cons(boxString(" = "), cons(id(node2Expression(fourth(node), indent)), null))))));

}


Box node2Set(Box node, int indent) {
  
  return cons(id(listNewLine(indent)), cons(id(node2Expression(second(node), indent)), cons(boxString(" = "), cons(id(node2Expression(third(node), indent)), null))));

}


Box node2Return(Box node, int indent) {
  
  if ( equal(listLength(node), 1)) {
    return cons(id(listNewLine(indent)), cons(boxString("return"), null));

  } else {
    return cons(id(listNewLine(indent)), cons(boxString("return "), cons(id(node2Expression(cadr(node), indent)), null)));

  }

}


Box node2Statement(Box node, int indent, String functionName) {
  
  if ( equalBox(boxString("set"), first(node))) {
    return cons(id(node2Set(node, indent)), cons(boxString(";\n"), null));

  } else {
    if ( equalBox(boxString("set-struct"), first(node))) {
      return cons(id(node2SetStruct(node, indent)), cons(boxString(";\n"), null));

    } else {
      if ( equalBox(boxString("if"), first(node))) {
        return cons(id(node2If(node, indent, functionName)), cons(boxString(";\n"), null));

      } else {
        if ( equalBox(boxString("return"), first(node))) {
          return cons(id(node2Return(node, indent)), cons(boxString(";\n"), null));

        } else {
          return cons(id(listNewLine(indent)), cons(id(node2Expression(node, indent)), cons(boxString(";\n"), null)));

        }

      }

    }

  }

}


Box node2Body(Box tree, int indent, String functionName) {
  Box code = null;

  if ( isEmpty(tree)) {
    return emptyList();

  } else {
    code = car(tree);

    return cons(id(node2Statement(code, indent, functionName)), cons(id(node2Body(cdr(tree), indent, functionName)), null));

  }

}


Box node2Declarations(Box decls, int indent) {
  Box decl = null;

  if ( isEmpty(decls)) {
    return emptyList();

  } else {
    decl = car(decls);

    return cons(id(boxString(stringIndent(indent))), cons(boxString("let "), cons(id(node2FuncMap(second(decl))), cons(boxString(" = "), cons(id(node2Expression(third(decl), indent)), cons(boxString(";\n"), cons(id(node2Declarations(cdr(decls), indent)), null)))))));

  }

}


Box node2Function(Box node) {
  Box name = null;

  name = second(node);

  if ( isNil(node)) {
    return emptyList();

  } else {
    return cons(id(listNewLine(0)), cons(id(listNewLine(0)), cons(boxString("function "), cons(id(node2FuncMap(second(node))), cons(boxString("("), cons(id(node2FunctionArgs(third(node))), cons(boxString(") {"), cons(id(listNewLine(1)), cons(id(node2Declarations(cdr(fourth(node)), 1)), cons(id(node2Body(cdr(fifth(node)), 1, stringify(name))), cons(boxString("\n}\n"), null)))))))))));

  }

}


Box node2Functions(Box tree) {
  
  if ( isEmpty(tree)) {
    return emptyList();

  } else {
    return cons(id(node2Function(car(tree))), cons(id(node2Functions(cdr(tree))), null));

  }

}


Box node2Includes(Box nodes) {
  
  return cons(boxString("\"use strict\";\n"), cons(boxString("const fs = (typeof require === \"function\") ? require(\"fs\") : null;\n"), cons(boxString("let globalArgsCount = 0;\n"), cons(boxString("let globalArgs = [];\n"), cons(boxString("let releaseMode = false;\n"), cons(boxString("let globalTrace = false;\n"), cons(boxString("let globalStepTrace = false;\n"), cons(boxString("let globalStackTrace = null;\n"), cons(boxString("let caller = \"\";\n"), cons(boxString("let quonIO = makeDefaultQuonIO();\n"), cons(boxString("let stderr = { write: function(s) { quonIO.error(String(s)); } };\n"), cons(boxString("function makeDefaultQuonIO() {\n"), cons(boxString("  return {\n"), cons(boxString("    write: function(s) {\n"), cons(boxString("      if (typeof process !== \"undefined\" && process.stdout) process.stdout.write(String(s));\n"), cons(boxString("    },\n"), cons(boxString("    error: function(s) {\n"), cons(boxString("      if (typeof process !== \"undefined\" && process.stderr) process.stderr.write(String(s));\n"), cons(boxString("      else if (typeof console !== \"undefined\" && console.error) console.error(String(s));\n"), cons(boxString("    },\n"), cons(boxString("    readFile: null,\n"), cons(boxString("    writeFile: null,\n"), cons(boxString("    exit: null,\n"), cons(boxString("    env: (typeof process !== \"undefined\" && process.env) ? process.env : {}\n"), cons(boxString("  };\n"), cons(boxString("}\n"), cons(boxString("function configureQuonIO(io) {\n"), cons(boxString("  const defaults = makeDefaultQuonIO();\n"), cons(boxString("  quonIO = Object.assign(defaults, io || {});\n"), cons(boxString("  if (!quonIO.error) quonIO.error = defaults.error;\n"), cons(boxString("  if (!quonIO.write) quonIO.write = defaults.write;\n"), cons(boxString("  return quonIO;\n"), cons(boxString("}\n"), cons(boxString("function qreadFile(filename) {\n"), cons(boxString("  if (quonIO.readFile) {\n"), cons(boxString("    const data = quonIO.readFile(filename);\n"), cons(boxString("    if (data === null || data === undefined) return null;\n"), cons(boxString("    return boxString(String(data));\n"), cons(boxString("  }\n"), cons(boxString("  if (fs) {\n"), cons(boxString("    try { return boxString(fs.readFileSync(filename, \"utf8\")); } catch (e) { return null; }\n"), cons(boxString("  }\n"), cons(boxString("  return null;\n"), cons(boxString("}\n"), cons(boxString("function qwriteFile(filename, data) {\n"), cons(boxString("  if (quonIO.writeFile) return quonIO.writeFile(filename, data);\n"), cons(boxString("  if (fs) return fs.writeFileSync(filename, data);\n"), cons(boxString("  throw new Error(\"write-file is not available in this environment\");\n"), cons(boxString("}\n"), cons(boxString("function qexit(status) {\n"), cons(boxString("  if (quonIO.exit) return quonIO.exit(status);\n"), cons(boxString("  if (typeof process !== \"undefined\" && process.exit) return process.exit(status);\n"), cons(boxString("  throw new Error(\"Quon exit \" + status);\n"), cons(boxString("}\n"), cons(boxString("function cformat(fmt, ...args) {\n"), cons(boxString("  fmt = String(fmt);\n"), cons(boxString("  let out = '';\n"), cons(boxString("  let argi = 0;\n"), cons(boxString("  for (let pos = 0; pos < fmt.length; pos++) {\n"), cons(boxString("    let ch = fmt[pos];\n"), cons(boxString("    if (ch !== '%') { out += ch; continue; }\n"), cons(boxString("    if (fmt[pos + 1] === '%') { out += '%'; pos++; continue; }\n"), cons(boxString("    let precision = null;\n"), cons(boxString("    if (fmt[pos + 1] === '.') {\n"), cons(boxString("      let end = pos + 2;\n"), cons(boxString("      while (end < fmt.length && fmt[end] >= '0' && fmt[end] <= '9') end++;\n"), cons(boxString("      precision = Number(fmt.slice(pos + 2, end));\n"), cons(boxString("      pos = end - 1;\n"), cons(boxString("    }\n"), cons(boxString("    let spec = fmt[pos + 1];\n"), cons(boxString("    if (spec === 's' || spec === 'd') {\n"), cons(boxString("      let value = String(args[argi++]);\n"), cons(boxString("      if (precision !== null) value = value.slice(0, precision);\n"), cons(boxString("      out += value;\n"), cons(boxString("      pos++;\n"), cons(boxString("    } else {\n"), cons(boxString("      out += ch;\n"), cons(boxString("    }\n"), cons(boxString("  }\n"), cons(boxString("  return out;\n"), cons(boxString("}\n"), cons(boxString("function printf(fmt, ...args) { quonIO.write(cformat(fmt, ...args)); }\n"), cons(boxString("function fprintf(stream, fmt, ...args) { stream.write(cformat(fmt, ...args)); }\n"), null)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));

}


Box node2Types(Box nodes) {
  
  return emptyList();

}


Box node2FuncMap(Box aSym) {
  Box symMap = null;

  if ( equalString("symbol", boxType(aSym))) {
    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("new"), boxSymbol("new_"), alistCons(boxSymbol("nil"), boxSymbol("null"), null))))))));

    if ( truthy(assoc(stringify(aSym), symMap))) {
      return cdr(assoc(stringify(aSym), symMap));

    } else {
      return aSym;

    }

  } else {
    return aSym;

  }

}


Box node2MainEntry() {
  
  return cons(boxString("\n// Main entry point\n"), cons(boxString("function runQuon(args = [], io = {}) {\n"), cons(boxString("  configureQuonIO(io);\n"), cons(boxString("  globalArgs = [\"fixmeprogname\", ...args];\n"), cons(boxString("  globalArgsCount = globalArgs.length;\n"), cons(boxString("  return start();\n"), cons(boxString("}\n"), cons(boxString("const __quonProgramApi = { runQuon, configureQuonIO, cformat, start };\n"), cons(boxString("if (typeof compileBodyString === \"function\") __quonProgramApi.compileBodyString = compileBodyString;\n"), cons(boxString("if (typeof compileBodySectionString === \"function\") __quonProgramApi.compileBodySectionString = compileBodySectionString;\n"), cons(boxString("if (typeof compileFunctionsString === \"function\") __quonProgramApi.compileFunctionsString = compileFunctionsString;\n"), cons(boxString("if (typeof compileFunctionsSectionString === \"function\") __quonProgramApi.compileFunctionsSectionString = compileFunctionsSectionString;\n"), cons(boxString("if (typeof compileTypesString === \"function\") __quonProgramApi.compileTypesString = compileTypesString;\n"), cons(boxString("if (typeof compileTypesSectionString === \"function\") __quonProgramApi.compileTypesSectionString = compileTypesSectionString;\n"), cons(boxString("if (typeof compileProgramBareString === \"function\") __quonProgramApi.compileProgramBareString = compileProgramBareString;\n"), cons(boxString("if (typeof readBodyFragment === \"function\") __quonProgramApi.readBodyFragment = readBodyFragment;\n"), cons(boxString("if (typeof module !== \"undefined\" && module.exports) module.exports = __quonProgramApi;\n"), cons(boxString("if (typeof globalThis !== \"undefined\") globalThis.QuonProgram = __quonProgramApi;\n"), cons(boxString("if (typeof require === \"function\" && typeof module !== \"undefined\" && require.main === module) {\n"), cons(boxString("  runQuon((typeof process !== \"undefined\" && process.argv) ? process.argv.slice(2) : []);\n"), cons(boxString("}\n"), null)))))))))))))))))))));

}


Box node2LoadProgram(String filename) {
  Box tree = null;
Box replace = null;

  tree = loadQuon(filename);

  tree = insertInclude(tree, "q/shims/node2.qon");

  tree = loadIncludes(tree, null);

  tree = macrowalk(tree);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), null));

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

  return tree;

}


Box node2ProgramTree(Box tree) {
  
  return cons(id(node2Includes(cdr(first(tree)))), cons(id(node2Types(cdr(second(tree)))), cons(id(node2Functions(cdr(third(tree)))), cons(id(node2MainEntry()), cons(boxString("\n"), null)))));

}


String node2Program(Box tree) {
  
  return ListToString(flatten(node2ProgramTree(tree)), 0, true, false);

}


String node2CompileString(String filename) {
  
  return node2Program(node2LoadProgram(filename));

}


void node2Compile(String filename) {
  Box tree = null;
Box replace = null;

  fprintf(stderr, "//Scanning file...%s\n", filename);

  tree = loadQuon(filename);

  fprintf(stderr, "Loading shim node2\n");

  tree = insertInclude(tree, "q/shims/node2.qon");

  fprintf(stderr, "Loading all includes\n");

  tree = loadIncludes(tree, null);

  fprintf(stderr, "Applying macros\n");

  tree = macrowalk(tree);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), null));

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

  fprintf(stderr, "//Printing program\n");

  printStringTree(node2ProgramTree(tree));

  fprintf(stderr, "//Done printing program\n");

}


void test0() {
  
  if ( equalString(stringify(boxString("hello")), stringify(boxString("hello")))) {
    System.out.printf("0.  pass string compare works\n");

  } else {
    System.out.printf("0.  pass string compare fails\n");

  }

  if ( equalString(stringify(boxString("hello")), stringify(boxSymbol("hello")))) {
    System.out.printf("0.  pass string compare works\n");

  } else {
    System.out.printf("0.  pass string compare fails\n");

  }

}


void test1() {
  
  System.out.printf("1.  pass Function call and print work\n");

}


void test2_do(String message) {
  
  System.out.printf("2.  pass Function call with arg works: %s\n", message);

}


void test2() {
  
  test2_do("This is the argument");

}


void test3_do(int b, String c) {
  
  System.out.printf("3.1 pass Two arg call, first arg: %d\n", b);

  System.out.printf("3.2 pass Two arg call, second arg: %s\n", c);

}


void test3() {
  
  test3_do(42, "Fourty-two");

}


String test4_do() {
  
  return "pass Return works";

}


String returnThis(String returnMessage) {
  
  return returnMessage;

}


void test4() {
  String message = "fail";

  message = test4_do();

  System.out.printf("4.  %s\n", message);

}


void test5() {
  String message = "fail";

  message = returnThis("pass return passthrough string");

  System.out.printf("5.  %s\n", message);

}


void test6() {
  
  if ( true) {
    System.out.printf("6.  pass If statement works\n");

  } else {
    System.out.printf("6.  fail If statement works\n");

  }

}


int test7_do(int count) {
  
  count = sub(count, 1);

  if ( greaterthan(count, 0)) {
    count = test7_do(count);

  } else {
    return count;

  }

  return count;

}


void test7() {
  
  if ( equal(0, test7_do(10))) {
    System.out.printf("7.  pass count works\n");

  } else {
    System.out.printf("7.  fail count fails\n");

  }

}


void beer() {
  
  System.out.printf("%d bottle of beer on the wall, %d bottle of beer.  Take one down, pass it round, no bottles of beer on the wall\n", 1, 1);

}


String plural(int num) {
  
  if ( equal(num, 1)) {
    return "";

  } else {
    return "s";

  }

}


int beers(int count) {
  int newcount = 0;

  newcount = sub(count, 1);

  System.out.printf("%d bottle%s of beer on the wall, %d bottle%s of beer.  Take one down, pass it round, %d bottle%s of beer on the wall\n", count, plural(count), count, plural(count), newcount, plural(newcount));

  if ( greaterthan(count, 1)) {
    count = beers(newcount);

  } else {
    return count;

  }

  return 0;

}


void test8() {
  
  if ( equal(sub(sub(2, 1), sub(3, 1)), -1)) {
    System.out.printf("8.  pass Nested expressions work\n");

  } else {
    System.out.printf("8.  fail Nested expressions don't work\n");

  }

}


void test9() {
  int answer = -999999;
int a = 2;
int b = 3;

  answer = sub(sub(20, 1), sub(3, 1));

  if ( equal(answer, 17)) {
    System.out.printf("9.1  pass sub works\n");

  } else {
    System.out.printf("9.1  fail sub\n");

  }

  answer = add(2, 3);

  if ( equal(answer, 5)) {
    System.out.printf("9.2  pass add works\n");

  } else {
    System.out.printf("9.2  fail add\n");

  }

  answer = mult(a, b);

  if ( equal(answer, 6)) {
    System.out.printf("9.3  pass mult works\n");

  } else {
    System.out.printf("9.3  fail mult\n");

  }

  if ( greaterthan(2, 1)) {
    System.out.printf("9.4  pass greaterthan works\n");

  } else {
    System.out.printf("9.4  fail greaterthan\n");

  }

  if ( equal(1, 1)) {
    System.out.printf("9.5  pass integer equal works\n");

  } else {
    System.out.printf("9.5  fail integer equal\n");

  }

  if ( equalString("hello", "hello")) {
    System.out.printf("9.6  pass string equal works\n");

  } else {
    System.out.printf("9.6  fail string equal\n");

  }

  if ( equalString("hello", "world")) {
    System.out.printf("9.7  fail string equal\n");

  } else {
    System.out.printf("9.7  pass string equal\n");

  }

  if ( andBool(false, false)) {
    System.out.printf("9.8  fail andBool\n");

  } else {
    System.out.printf("9.8  pass andBool works\n");

  }

  if ( andBool(true, true)) {
    System.out.printf("9.9  pass andBool works\n");

  } else {
    System.out.printf("9.9  fail andBool\n");

  }

  if ( andBool(true, false)) {
    System.out.printf("9.10  fail andBool\n");

  } else {
    System.out.printf("9.10  pass andBool works\n");

  }

  if ( equalString("hello", "hello")) {
    System.out.printf("9.11  pass string equal\n");

  } else {
    System.out.printf("9.11  fail string equal\n");

  }

  if ( equalString("!", character(33))) {
    System.out.printf("9.12  pass character\n");

  } else {
    System.out.printf("9.12  fail character\n");

  }

  if ( equalString("33", intToString(33))) {
    System.out.printf("9.13  pass intToString\n");

  } else {
    System.out.printf("9.13  fail intToString\n");

  }

  if ( equalString("llo", sub_string("hello", a, b))) {
    System.out.printf("9.14  pass sub-string\n");

  } else {
    System.out.printf("9.14  fail sub-string: %s\n", sub_string("hello", a, b));

  }

}


void test10() {
  String testString = "This is a test string";

  if ( equalString(testString, unBoxString(car(cons(boxString(testString), null))))) {
    System.out.printf("10. pass cons and car work\n");

  } else {
    System.out.printf("10. fail cons and car fail\n");

  }

}


void test12() {
  Box b = null;

  b = new Box();

  b.str = "12. pass structure accessors\n";

  System.out.printf("%s", b.str);

}


void test13() {
  String testString = "Hello from the filesystem!";
Box contentsBox = null;
String contents = "";

  write_file("test.txt", testString);

  contentsBox = read_file("test.txt");

  if ( isNil(contentsBox)) {
    System.out.printf("13. fail Read and write files\n");

    System.out.printf("Expected: %s\n", testString);

    System.out.printf("Got: nil\n");

  } else {
    contents = unBoxString(contentsBox);

    if ( equalString(testString, contents)) {
      System.out.printf("13. pass Read and write files\n");

    } else {
      System.out.printf("13. fail Read and write files\n");

      System.out.printf("Expected: %s\n", testString);

      System.out.printf("Got: %s\n", contents);

    }

  }

}


void test14() {
  Box contentsBox = null;

  contentsBox = read_file("q/this-file-should-not-exist.qon");

  if ( isNil(contentsBox)) {
    System.out.printf("14. pass Missing read-file returns nil\n");

  } else {
    System.out.printf("14. fail Missing read-file returns nil\n");

    System.out.printf("Got: %s\n", unBoxString(contentsBox));

  }

}


void test15() {
  String a = "hello";
String b = " world";
String c = "";

  c = stringConcatenate(a, b);

  if ( equalString(c, "hello world")) {
    System.out.printf("15. pass String concatenate\n");

  } else {
    System.out.printf("15. fail String concatenate\n");

  }

}


void test16() {
  Box assocCell1 = null;
Box assList = null;
Box assocCell2 = null;
Box assocCell3 = null;

  assocCell1 = cons(boxString("Hello"), boxString("world"));

  assocCell2 = cons(boxString("goodnight"), boxString("moon"));

  assocCell3 = cons(boxSymbol("ohio"), boxString("gozaimasu"));

  assList = cons(assocCell2, emptyList());

  assList = cons(assocCell1, assList);

  assList = cons(assocCell3, assList);

  if ( equalBox(cdr(assoc("Hello", assList)), boxString("world"))) {
    System.out.printf("16.1 pass Basic assoc works\n");

  } else {
    System.out.printf("16.1 fail Basic assoc fails\n");

  }

  if ( andBool(andBool(equalBox(cdr(assoc("Hello", assList)), boxString("world")), equalBox(cdr(assoc("goodnight", assList)), boxString("moon"))), equalBox(cdr(assoc("ohio", assList)), boxString("gozaimasu")))) {
    System.out.printf("16.2 pass assoc list\n");

  } else {
    System.out.printf("16.2 fail assoc list\n");

  }

}


void test17() {
  Box l = null;

  l = cons(boxInt(1), cons(boxInt(2), cons(boxInt(3), null)));

  if ( equalBox(car(l), boxInt(1))) {
    System.out.printf("17. pass list literal works\n");

  } else {
    System.out.printf("17. fail list literal failed\n");

  }

}


void test18() {
  String val1 = "a";
String val2 = "b";
Box l = null;

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), null)));

  if ( equalList(l, cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), null))))) {
    System.out.printf("18. pass string list constructor works\n");

  } else {
    System.out.printf("18. fail string list constructor failed\n");

  }

}


void test19() {
  String val1 = "a";
String val2 = "b";
Box l = null;
Box revlist = null;
Box answer = null;

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), null)));

  answer = cons(boxString("c"), cons(boxString(val2), cons(boxString(val1), null)));

  revlist = reverseList(l);

  if ( equalList(answer, revlist)) {
    System.out.printf("19. pass reverseList\n");

  } else {
    System.out.printf("19. fail reverseList\n");

  }

}


Box concatenateLists(Box oldL, Box newL) {
  
  return reverseRec(reverseList(oldL), newL);

}


void test20() {
  String val1 = "a";
String val2 = "b";
String val3 = "c";
Box l = null;
Box l2 = null;
Box l3 = null;
Box combined = null;

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), null)));

  l2 = cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), null)));

  l3 = cons(boxString(val1), cons(boxString(val2), cons(boxString(val3), cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), null))))));

  combined = concatenateLists(l, l2);

  if ( equalList(l3, combined)) {
    System.out.printf("21. pass concatenateLists\n");

  } else {
    System.out.printf("21. fail concatenateLists\n");

  }

}


void test21() {
  String val1 = "a";
String val2 = "b";
String val3 = "c";
Box l = null;
Box l2 = null;

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString(val3), null)));

  l2 = cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), null)));

  if ( equalList(l, l2)) {
    System.out.printf("21. pass equalList\n");

  } else {
    System.out.printf("21. fail equalList\n");

  }

}


void test22() {
  Box original = null;
Box out = null;
Box replace = null;
Box correct = null;

  original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), null)));

  replace = cons(boxString("fprintf"), cons(boxString("stderr"), null));

  out = macrolist(original, stringConcatenate("q", "log"), replace);

  correct = cons(boxString("fprintf"), cons(boxString("stderr"), cons(boxString("%s"), cons(boxString("hello"), null))));

  if ( equalList(out, correct)) {
    System.out.printf("22. pass macroList\n");

  } else {
    System.out.printf("22. fail macroList\n");

    System.out.printf("In: ");

    displayList(original, 0, true);

    System.out.printf("\nOut: ");

    displayList(out, 0, true);

    System.out.printf("\n");

  }

}


void test23() {
  Box original = null;
Box out = null;
Box replace = null;
Box correct = null;

  original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), null)));

  replace = cons(boxString("fprintf"), cons(boxString("stderr"), null));

  out = concatLists(original, replace);

  correct = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), cons(boxString("fprintf"), cons(boxString("stderr"), null)))));

  if ( equalList(out, correct)) {
    System.out.printf("23. pass concatLists\n");

  } else {
    System.out.printf("23. fail concatLists\n");

    System.out.printf("In: ");

    displayList(original, 0, true);

    System.out.printf("\nOut: ");

    displayList(out, 0, true);

  }

}


void test24() {
  String expected = "a b c";
String res = "";

  res = StringListJoin(cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), null))), " ");

  if ( equalString(expected, res)) {
    System.out.printf("24. pass StringListJoin\n");

  } else {
    System.out.printf("24. fail StringListJoin.  expected %s, got %s\n", expected, res);

  }

}


void test25() {
  String expected = "( a b ) c d e";
String res = "";
Box testsubstr = cons(boxString("c "), cons(boxString("d "), cons(boxString("e"), null)));
Box input = null;

  input = cons(boxString("a "), cons(boxString("b "), null));

  input = cons(input, testsubstr);

  res = ListToString(input, 0, true, false);

  if ( equalString(expected, res)) {
    System.out.printf("25. pass ListToString\n");

  } else {
    System.out.printf("25. fail ListToString.  expected %s, got %s\n", expected, res);

  }

}


void test27() {
  String expected = "a b c d e";
String floatExpected = "6.5";
String floatResult = "";
String res = "";
Box floatBox = null;
Box variable = cons(boxString("c "), cons(boxString("d "), null));
Box input = null;

  input = cons(boxString("a "), cons(boxString("b "), cons(id(variable), cons(boxString("e"), null))));

  res = ListToString(flatten(input), 0, true, false);

  if ( equalString(expected, res)) {
    System.out.printf("27. pass Interpolated List\n");

  } else {
    System.out.printf("27. fail Interpolated List.  expected %s, got %s\n", expected, res);

  }

  floatBox = boxFloat(6.5);

  floatResult = stringify(floatBox);

  if ( equalString(floatExpected, floatResult)) {
    System.out.printf("27. pass Float box stringify\n");

  } else {
    System.out.printf("27. fail Float box stringify.  expected %s, got %s\n", floatExpected, floatResult);

  }

}


void test28() {
  Box splitExpected = null;
Box splitResult = null;

  if ( equalString("aXYZc", stringReplace("b", "XYZ", "abc"))) {
    System.out.printf("28.1 pass stringReplace\n");

  } else {
    System.out.printf("28.1 fail stringReplace\n");

  }

  if ( equalString("abc", stringTrim(" abc "))) {
    System.out.printf("28.2 pass stringTrim\n");

  } else {
    System.out.printf("28.2 fail stringTrim\n");

  }

  splitExpected = cons(boxString("a"), cons(boxString("b"), null));

  splitResult = stringSplit("a,b", ",");

  if ( equalList(splitExpected, splitResult)) {
    System.out.printf("28.3 pass stringSplit\n");

  } else {
    System.out.printf("28.3 fail stringSplit\n");

  }

}


String haskellBackslash() {
  
  return character(92);

}


String haskellDoubleQuote() {
  
  return character(34);

}


String haskellEscapedBackslash() {
  
  return stringConcatenate(haskellBackslash(), haskellBackslash());

}


String haskellEscapedDoubleQuote() {
  
  return stringConcatenate(haskellBackslash(), haskellDoubleQuote());

}


String haskellEscapeString(String s) {
  
  s = stringReplace(character(10), stringConcatenate(haskellBackslash(), "n"), s);

  s = stringReplace(character(13), stringConcatenate(haskellBackslash(), "r"), s);

  s = stringReplace(character(9), stringConcatenate(haskellBackslash(), "t"), s);

  return s;

}


String haskellSafeNameString(String name) {
  
  if ( equalString(name, "case")) {
    return "caseValue";

  } else {
  }

  if ( equalString(name, "class")) {
    return "classValue";

  } else {
  }

  if ( equalString(name, "data")) {
    return "dataValue";

  } else {
  }

  if ( equalString(name, "default")) {
    return "defaultValue";

  } else {
  }

  if ( equalString(name, "deriving")) {
    return "derivingValue";

  } else {
  }

  if ( equalString(name, "do")) {
    return "doValue";

  } else {
  }

  if ( equalString(name, "else")) {
    return "elseValue";

  } else {
  }

  if ( equalString(name, "foreign")) {
    return "foreignValue";

  } else {
  }

  if ( equalString(name, "if")) {
    return "ifValue";

  } else {
  }

  if ( equalString(name, "import")) {
    return "importValue";

  } else {
  }

  if ( equalString(name, "in")) {
    return "inValue";

  } else {
  }

  if ( equalString(name, "infix")) {
    return "infixValue";

  } else {
  }

  if ( equalString(name, "infixl")) {
    return "infixlValue";

  } else {
  }

  if ( equalString(name, "infixr")) {
    return "infixrValue";

  } else {
  }

  if ( equalString(name, "instance")) {
    return "instanceValue";

  } else {
  }

  if ( equalString(name, "let")) {
    return "letValue";

  } else {
  }

  if ( equalString(name, "module")) {
    return "moduleValue";

  } else {
  }

  if ( equalString(name, "newtype")) {
    return "newtypeValue";

  } else {
  }

  if ( equalString(name, "of")) {
    return "ofValue";

  } else {
  }

  if ( equalString(name, "then")) {
    return "thenValue";

  } else {
  }

  if ( equalString(name, "type")) {
    return "typeValue";

  } else {
  }

  if ( equalString(name, "where")) {
    return "whereValue";

  } else {
  }

  if ( equalString(name, "id")) {
    return "qid";

  } else {
  }

  if ( equalString(name, "old")) {
    return "oldValue";

  } else {
  }

  if ( equalString(name, "new")) {
    return "newValue";

  } else {
  }

  if ( haskellStringStartsWith(name, "-")) {
    return name;

  } else {
  }

  if ( equalString(name, "StringListJoinRec")) {
    return "stringListJoinRec";

  } else {
  }

  if ( equalString(name, "StringListJoin")) {
    return "stringListJoin";

  } else {
  }

  if ( equalString(name, "ListToBoxString")) {
    return "listToBoxString";

  } else {
  }

  if ( equalString(name, "ListToString")) {
    return "listToString";

  } else {
  }

  if ( equalString(name, "StackTraceMove")) {
    return "stackTraceMove";

  } else {
  }

  if ( equalString(name, "StackTracePrint")) {
    return "stackTracePrint";

  } else {
  }

  if ( equalString(name, "StackTracePrintHelper")) {
    return "stackTracePrintHelper";

  } else {
  }

  if ( equalString(name, "NoStackTrace_list")) {
    return "noStackTrace_list";

  } else {
  }

  if ( equalString(name, "NoTrace_list")) {
    return "noTrace_list";

  } else {
  }

  name = stringReplace("-", "_", name);

  name = stringReplace("?", "_q", name);

  name = stringReplace("!", "_bang", name);

  return name;

}


Box haskellSafeName(Box aSym) {
  
  return boxSymbol(haskellSafeNameString(stringify(aSym)));

}


String haskellFieldName(Box aSym) {
  
  return stringConcatenate("qf_", haskellSafeNameString(stringify(aSym)));

}


String haskellNewName(Box aSym) {
  
  return stringConcatenate("new", stringify(aSym));

}


boolean haskellStringEndsWith(String s, String suffix) {
  int start = 0;

  if ( greaterthan(string_length(suffix), string_length(s))) {
    return false;

  } else {
    start = sub(string_length(s), string_length(suffix));

    return equalString(sub_string(s, start, string_length(suffix)), suffix);

  }

}


boolean haskellStringStartsWith(String s, String prefix) {
  
  if ( greaterthan(string_length(prefix), string_length(s))) {
    return false;

  } else {
    return equalString(sub_string(s, 0, string_length(prefix)), prefix);

  }

}


Box haskellPointerBase(Box aSym) {
  String name = "";

  name = stringify(aSym);

  if ( haskellStringEndsWith(name, "*")) {
    return boxSymbol(sub_string(name, 0, sub1(string_length(name))));

  } else {
    return aSym;

  }

}


boolean haskellTypeIsPointer(Box aSym) {
  String mapped = "";

  mapped = stringify(haskellTypeMap(aSym));

  return haskellStringStartsWith(mapped, "Maybe ");

}


Box haskellTypeMap(Box aSym) {
  Box symMap = null;
String name = "";

  symMap = alistCons(boxSymbol("pair"), boxSymbol("Maybe Box"), alistCons(boxSymbol("box"), boxSymbol("Maybe Box"), alistCons(boxSymbol("list"), boxSymbol("Maybe Box"), alistCons(boxSymbol("Box*"), boxSymbol("Maybe Box"), alistCons(boxSymbol("Pair"), boxSymbol("Box"), alistCons(boxSymbol("struct"), boxSymbol(""), alistCons(boxSymbol("bool"), boxSymbol("Bool"), alistCons(boxSymbol("uint"), boxSymbol("Int"), alistCons(boxSymbol("int"), boxSymbol("Int"), alistCons(boxSymbol("float"), boxSymbol("Double"), alistCons(boxSymbol("void"), boxSymbol("()"), alistCons(boxSymbol("stringArray"), boxSymbol("[String]"), alistCons(boxSymbol("array"), boxSymbol("[String]"), alistCons(boxSymbol("hashmap"), boxSymbol("IORef [(String, String)]"), alistCons(boxSymbol("string"), boxSymbol("String"), null)))))))))))))));

  if ( truthy(assoc(stringify(aSym), symMap))) {
    return cdr(assoc(stringify(aSym), symMap));

  } else {
    name = stringify(aSym);

    if ( haskellStringEndsWith(name, "*")) {
      return boxSymbol(stringConcatenate("Maybe ", stringify(haskellPointerBase(aSym))));

    } else {
      return aSym;

    }

  }

}


String haskellDefaultValue(Box typeSym) {
  String typ = "";

  typ = stringify(haskellTypeMap(typeSym));

  if ( equalString(typ, "()")) {
    return "()";

  } else {
  }

  if ( equalString(typ, "Bool")) {
    return "False";

  } else {
  }

  if ( equalString(typ, "Int")) {
    return "0";

  } else {
  }

  if ( equalString(typ, "Double")) {
    return "0.0";

  } else {
  }

  if ( equalString(typ, "String")) {
    return "\"\"";

  } else {
  }

  if ( equalString(typ, "[String]")) {
    return "[]";

  } else {
  }

  if ( haskellStringStartsWith(typ, "Maybe ")) {
    return "Nothing";

  } else {
  }

  return stringConcatenate("(error \"no default value for ", stringConcatenate(typ, "\")"));

}


String haskellRefType(Box typeSym) {
  
  return stringConcatenate("(", stringConcatenate(stringify(haskellTypeMap(typeSym)), ")"));

}


Box haskellGlobalVariables() {
  
  return cons(id(boxSymbol("globalArgsCount")), cons(id(boxSymbol("globalArgs")), cons(id(boxSymbol("releaseMode")), cons(id(boxSymbol("caller")), cons(id(boxSymbol("globalTrace")), cons(id(boxSymbol("globalStepTrace")), cons(id(boxSymbol("globalStackTrace")), null)))))));

}


Box haskellCollectVariablesFromArgs(Box args) {
  Box variables = null;

  if ( isNil(args)) {
    return variables;

  } else {
    variables = cons(second(args), variables);

    return appendVariables(variables, haskellCollectVariablesFromArgs(cddr(args)));

  }

}


Box haskellCollectVariablesFromDecls(Box decls) {
  Box variables = null;
Box decl = null;

  if ( isNil(decls)) {
    return variables;

  } else {
    decl = car(decls);

    variables = cons(second(decl), variables);

    return appendVariables(variables, haskellCollectVariablesFromDecls(cdr(decls)));

  }

}


Box haskellCollectVariables(Box args, Box decls) {
  Box variables = null;

  variables = haskellCollectVariablesFromArgs(args);

  variables = appendVariables(variables, haskellCollectVariablesFromDecls(decls));

  variables = appendVariables(variables, haskellGlobalVariables());

  return variables;

}


Box haskellFuncMap(Box aSym, Box variables) {
  Box symMap = null;

  if ( orBool(equalString("symbol", boxType(aSym)), equalString("string", boxType(aSym)))) {
    if ( inList(aSym, variables)) {
      return haskellSafeName(aSym);

    } else {
      symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("Nothing"), alistCons(boxSymbol("true"), boxSymbol("True"), alistCons(boxSymbol("false"), boxSymbol("False"), alistCons(boxSymbol("old"), boxSymbol("oldValue"), alistCons(boxSymbol("new"), boxSymbol("newValue"), null)))))))))));

      if ( truthy(assoc(stringify(aSym), symMap))) {
        return cdr(assoc(stringify(aSym), symMap));

      } else {
        return haskellSafeName(aSym);

      }

    }

  } else {
    return aSym;

  }

}


Box haskellNumberAtom(Box tree) {
  String val = "";

  val = stringify(tree);

  if ( haskellStringStartsWith(val, "-")) {
    return cons(boxString("pure ("), cons(id(boxString(val)), cons(boxString(")"), null)));

  } else {
    return cons(boxString("pure "), cons(id(boxString(val)), null));

  }

}


Box haskellAtom(Box tree, Box variables) {
  
  if ( equalString("int", boxType(tree))) {
    return haskellNumberAtom(tree);

  } else {
    if ( equalString("float", boxType(tree))) {
      return haskellNumberAtom(tree);

    } else {
      if ( equalString("string", boxType(tree))) {
        return cons(boxString("pure \""), cons(id(boxString(haskellEscapeString(stringify(tree)))), cons(boxString("\""), null)));

      } else {
        if ( isInt(stringify(tree))) {
          return haskellNumberAtom(tree);

        } else {
          if ( isFloat(stringify(tree))) {
            return haskellNumberAtom(tree);

          } else {
            if ( haskellStringStartsWith(stringify(tree), "-")) {
              return cons(boxString("pure ("), cons(id(haskellFuncMap(tree, variables)), cons(boxString(")"), null)));

            } else {
              if ( inList(tree, variables)) {
                return cons(boxString("liftIO (readIORef "), cons(id(haskellFuncMap(tree, variables)), cons(boxString(")"), null)));

              } else {
                return cons(boxString("pure "), cons(id(haskellFuncMap(tree, variables)), null));

              }

            }

          }

        }

      }

    }

  }

}


Box haskellArgNames(Box expr, int pos) {
  
  if ( isEmpty(expr)) {
    return emptyList();

  } else {
    if ( isNil(cdr(expr))) {
      return cons(boxString(" arg"), cons(id(boxString(intToString(pos))), null));

    } else {
      return cons(boxString(" arg"), cons(id(boxString(intToString(pos))), cons(id(haskellArgNames(cdr(expr), add1(pos))), null)));

    }

  }

}


Box haskellBindArgs(Box expr, int indent, Box variables, int pos) {
  
  if ( isEmpty(expr)) {
    return emptyList();

  } else {
    return cons(id(listNewLine(indent)), cons(boxString("arg"), cons(id(boxString(intToString(pos))), cons(boxString(" <- "), cons(id(haskellExpression(car(expr), indent, variables)), cons(id(haskellBindArgs(cdr(expr), indent, variables, add1(pos))), null))))));

  }

}


Box haskellCall(Box name, Box args, int indent, Box variables) {
  
  if ( isEmpty(args)) {
    return cons(boxString("liftIO "), cons(id(haskellFuncMap(name, null)), null));

  } else {
    return cons(boxString("do"), cons(id(haskellBindArgs(args, add1(indent), variables, 0)), cons(id(listNewLine(add1(indent))), cons(boxString("liftIO ("), cons(id(haskellFuncMap(name, null)), cons(id(haskellArgNames(args, 0)), cons(boxString(")"), null)))))));

  }

}


Box haskellBinop(Box tree, int indent, Box variables) {
  
  return cons(boxString("do"), cons(id(listNewLine(add1(indent))), cons(boxString("arg0 <- "), cons(id(haskellExpression(third(tree), add1(indent), variables)), cons(id(listNewLine(add1(indent))), cons(boxString("arg1 <- "), cons(id(haskellExpression(fourth(tree), add1(indent), variables)), cons(id(listNewLine(add1(indent))), cons(boxString("pure (arg0 "), cons(id(second(tree)), cons(boxString(" arg1)"), null)))))))))));

}


Box haskellGetStruct(Box tree, int indent, Box variables) {
  
  return cons(boxString("do"), cons(id(listNewLine(add1(indent))), cons(boxString("hobj <- "), cons(id(haskellExpression(second(tree), add1(indent), variables)), cons(id(listNewLine(add1(indent))), cons(boxString("liftIO (readIORef ("), cons(boxString("getField @\""), cons(id(boxString(haskellFieldName(third(tree)))), cons(boxString("\" (expect hobj)))"), null)))))))));

}


Box haskellNewExpression(Box tree) {
  
  if ( haskellTypeIsPointer(second(tree))) {
    return cons(boxString("liftIO (Just <$> "), cons(id(boxString(haskellNewName(third(tree)))), cons(boxString(")"), null)));

  } else {
    return cons(boxString("liftIO "), cons(id(boxString(haskellNewName(third(tree)))), null));

  }

}


Box haskellExpression(Box tree, int indent, Box variables) {
  Box thing = null;

  if ( notBool(isList(tree))) {
    return haskellAtom(tree, variables);

  } else {
    if ( equal(1, listLength(tree))) {
      if ( equalBox(boxString("return"), car(tree))) {
        return cons(boxString("pure "), cons(id(haskellFuncMap(car(tree), variables)), null));

      } else {
        return haskellCall(car(tree), null, indent, variables);

      }

    } else {
      thing = first(tree);

      if ( equalBox(boxSymbol("get-struct"), thing)) {
        return haskellGetStruct(tree, indent, variables);

      } else {
        if ( equalBox(boxSymbol("new"), thing)) {
          return haskellNewExpression(tree);

        } else {
          if ( equalBox(boxSymbol("passthrough"), thing)) {
            return cons(boxString("pure ("), cons(id(second(tree)), cons(boxString(")"), null)));

          } else {
            if ( equalBox(boxSymbol("binop"), thing)) {
              return haskellBinop(tree, indent, variables);

            } else {
              return haskellCall(car(tree), cdr(tree), indent, variables);

            }

          }

        }

      }

    }

  }

}


Box haskellSet(Box node, int indent, Box variables) {
  
  return cons(id(listNewLine(indent)), cons(boxString("qset <- "), cons(id(haskellExpression(third(node), indent, variables)), cons(id(listNewLine(indent)), cons(boxString("liftIO (writeIORef "), cons(id(haskellFuncMap(second(node), variables)), cons(boxString(" qset)"), null)))))));

}


Box haskellSetStruct(Box node, int indent, Box variables) {
  
  return cons(id(listNewLine(indent)), cons(boxString("hobj <- "), cons(id(haskellExpression(second(node), indent, variables)), cons(id(listNewLine(indent)), cons(boxString("qset <- "), cons(id(haskellExpression(fourth(node), indent, variables)), cons(id(listNewLine(indent)), cons(boxString("liftIO (writeIORef ("), cons(boxString("getField @\""), cons(id(boxString(haskellFieldName(third(node)))), cons(boxString("\" (expect hobj)) qset)"), null)))))))))));

}


Box haskellReturn(Box node, int indent, Box variables) {
  
  if ( greaterthan(listLength(node), 1)) {
    return cons(id(listNewLine(indent)), cons(boxString("hret <- "), cons(id(haskellExpression(cadr(node), indent, variables)), cons(id(listNewLine(indent)), cons(boxString("qreturn hret"), null)))));

  } else {
    return cons(id(listNewLine(indent)), cons(boxString("qreturn ()"), null));

  }

}


Box haskellIf(Box node, int indent, Box variables) {
  
  return cons(id(listNewLine(indent)), cons(boxString("hcond <- "), cons(id(haskellExpression(second(node), indent, variables)), cons(id(listNewLine(indent)), cons(boxString("if hcond"), cons(id(listNewLine(indent)), cons(boxString("  then do"), cons(id(haskellBody(cdr(third(node)), add(indent, 2), variables)), cons(id(listNewLine(add(indent, 2))), cons(boxString("pure ()"), cons(id(listNewLine(indent)), cons(boxString("  else do"), cons(id(haskellBody(cdr(fourth(node)), add(indent, 2), variables)), cons(id(listNewLine(add(indent, 2))), cons(boxString("pure ()"), null)))))))))))))));

}


Box haskellStatement(Box node, int indent, Box variables) {
  
  if ( equalBox(boxString("set"), first(node))) {
    return haskellSet(node, indent, variables);

  } else {
    if ( equalBox(boxString("set-struct"), first(node))) {
      return haskellSetStruct(node, indent, variables);

    } else {
      if ( equalBox(boxString("if"), first(node))) {
        return haskellIf(node, indent, variables);

      } else {
        if ( equalBox(boxString("return"), first(node))) {
          return haskellReturn(node, indent, variables);

        } else {
          return cons(id(listNewLine(indent)), cons(boxString("_ <- "), cons(id(haskellExpression(node, indent, variables)), null)));

        }

      }

    }

  }

}


Box haskellBody(Box tree, int indent, Box variables) {
  
  if ( isEmpty(tree)) {
    return emptyList();

  } else {
    return cons(id(haskellStatement(car(tree), indent, variables)), cons(id(haskellBody(cdr(tree), indent, variables)), null));

  }

}


Box haskellFunctionArgsSignature(Box tree) {
  
  if ( isEmpty(tree)) {
    return emptyList();

  } else {
    if ( isNil(cddr(tree))) {
      return cons(id(haskellTypeMap(first(tree))), cons(boxString(" -> "), null));

    } else {
      return cons(id(haskellTypeMap(first(tree))), cons(boxString(" -> "), cons(id(haskellFunctionArgsSignature(cddr(tree))), null)));

    }

  }

}


Box haskellFunctionArgs(Box tree) {
  
  if ( isEmpty(tree)) {
    return emptyList();

  } else {
    if ( isNil(cddr(tree))) {
      return cons(boxString(" "), cons(id(haskellFuncMap(second(tree), null)), cons(boxString("_arg"), null)));

    } else {
      return cons(boxString(" "), cons(id(haskellFuncMap(second(tree), null)), cons(boxString("_arg"), cons(id(haskellFunctionArgs(cddr(tree))), null))));

    }

  }

}


Box haskellArgRefs(Box args, int indent) {
  
  if ( isEmpty(args)) {
    return emptyList();

  } else {
    return cons(id(listNewLine(indent)), cons(id(haskellFuncMap(second(args), null)), cons(boxString(" <- liftIO (newIORef "), cons(id(haskellFuncMap(second(args), null)), cons(boxString("_arg)"), cons(id(haskellArgRefs(cddr(args), indent)), null))))));

  }

}


Box haskellDeclarations(Box decls, int indent, Box variables) {
  Box decl = null;

  if ( isEmpty(decls)) {
    return emptyList();

  } else {
    decl = car(decls);

    return cons(id(listNewLine(indent)), cons(boxString("qinit <- "), cons(id(haskellExpression(third(decl), indent, variables)), cons(id(listNewLine(indent)), cons(id(haskellFuncMap(second(decl), null)), cons(boxString(" <- liftIO (newIORef qinit)"), cons(id(haskellDeclarations(cdr(decls), indent, variables)), null)))))));

  }

}


Box haskellFunction(Box node) {
  Box variables = null;
Box args = null;
Box decls = null;

  if ( isNil(node)) {
    return emptyList();

  } else {
    args = third(node);

    decls = cdr(fourth(node));

    variables = haskellCollectVariables(args, decls);

    return cons(id(listNewLine(0)), cons(id(haskellFuncMap(second(node), null)), cons(boxString(" :: "), cons(id(haskellFunctionArgsSignature(args)), cons(boxString("IO "), cons(id(boxString(haskellRefType(first(node)))), cons(id(listNewLine(0)), cons(id(haskellFuncMap(second(node), null)), cons(id(haskellFunctionArgs(args)), cons(boxString(" = evalContT $ callCC $ \\qreturn -> do"), cons(id(haskellArgRefs(args, 1)), cons(id(haskellDeclarations(decls, 1, variables)), cons(id(haskellBody(cdr(fifth(node)), 1, variables)), cons(id(listNewLine(1)), cons(boxString("pure "), cons(id(boxString(haskellDefaultValue(first(node)))), cons(boxString("\n"), null)))))))))))))))));

  }

}


Box haskellFunctions(Box tree) {
  
  if ( isEmpty(tree)) {
    return emptyList();

  } else {
    return cons(id(haskellFunction(car(tree))), cons(id(haskellFunctions(cdr(tree))), null));

  }

}


Box haskellTypeDecl(Box l) {
  Box fieldType = null;

  if ( greaterthan(listLength(l), 2)) {
    fieldType = listLast(l);

  } else {
    fieldType = second(l);

  }

  return cons(boxString("  "), cons(id(boxString(haskellFieldName(first(l)))), cons(boxString(" :: IORef "), cons(id(boxString(haskellRefType(fieldType))), null))));

}


Box haskellStructFields(Box node) {
  
  if ( isEmpty(node)) {
    return emptyList();

  } else {
    if ( isNil(cdr(node))) {
      return haskellTypeDecl(car(node));

    } else {
      return cons(id(haskellTypeDecl(car(node))), cons(boxString("\n, "), cons(id(haskellStructFields(cdr(node))), null)));

    }

  }

}


Box haskellNewStructField(Box l, int indent) {
  Box fieldType = null;

  if ( greaterthan(listLength(l), 2)) {
    fieldType = listLast(l);

  } else {
    fieldType = second(l);

  }

  return cons(id(listNewLine(indent)), cons(boxString("v_"), cons(id(boxString(haskellFieldName(first(l)))), cons(boxString(" <- newIORef "), cons(id(boxString(haskellDefaultValue(fieldType))), null)))));

}


Box haskellNewStructFields(Box fields, int indent) {
  
  if ( isEmpty(fields)) {
    return emptyList();

  } else {
    return cons(id(haskellNewStructField(car(fields), indent)), cons(id(haskellNewStructFields(cdr(fields), indent)), null));

  }

}


Box haskellStructCtorFields(Box fields) {
  
  if ( isEmpty(fields)) {
    return emptyList();

  } else {
    if ( isNil(cdr(fields))) {
      return cons(id(boxString(haskellFieldName(first(car(fields))))), cons(boxString(" = v_"), cons(id(boxString(haskellFieldName(first(car(fields))))), null)));

    } else {
      return cons(id(boxString(haskellFieldName(first(car(fields))))), cons(boxString(" = v_"), cons(id(boxString(haskellFieldName(first(car(fields))))), cons(boxString(", "), cons(id(haskellStructCtorFields(cdr(fields))), null)))));

    }

  }

}


Box haskellType(Box node) {
  Box fields = null;

  if ( isList(second(node))) {
    fields = cdr(second(node));

    return cons(boxString("\ndata "), cons(id(first(node)), cons(boxString(" = "), cons(id(first(node)), cons(boxString(" { "), cons(id(haskellStructFields(fields)), cons(boxString("\n}\n\n"), cons(id(boxString(haskellNewName(first(node)))), cons(boxString(" :: IO "), cons(id(first(node)), cons(boxString("\n"), cons(id(boxString(haskellNewName(first(node)))), cons(boxString(" = do"), cons(id(haskellNewStructFields(fields, 1)), cons(id(listNewLine(1)), cons(boxString("pure "), cons(id(first(node)), cons(boxString(" { "), cons(id(haskellStructCtorFields(fields)), cons(boxString(" }\n"), null))))))))))))))))))));

  } else {
    return emptyList();

  }

}


Box haskellTypes(Box nodes) {
  
  if ( isEmpty(nodes)) {
    return emptyList();

  } else {
    return cons(id(haskellType(car(nodes))), cons(id(haskellTypes(cdr(nodes))), null));

  }

}


Box haskellIncludes(Box nodes) {
  
  return cons(boxString("{-# LANGUAGE DataKinds #-}\n"), cons(boxString("{-# LANGUAGE DuplicateRecordFields #-}\n"), cons(boxString("{-# LANGUAGE ExtendedDefaultRules #-}\n"), cons(boxString("{-# LANGUAGE TypeApplications #-}\n"), cons(boxString("import Control.Monad.Trans.Cont\n"), cons(boxString("import Control.Monad.IO.Class\n"), cons(boxString("import Data.Char (chr)\n"), cons(boxString("import Data.IORef\n"), cons(boxString("import Data.Maybe (isNothing)\n"), cons(boxString("import GHC.Records (getField)\n"), cons(boxString("import System.Directory (doesFileExist)\n"), cons(boxString("import System.Environment (getArgs, lookupEnv)\n"), cons(boxString("import System.Exit (ExitCode(..), exitWith)\n"), cons(boxString("import System.IO (Handle, stderr, hPutStr, hFlush)\n"), cons(boxString("import System.IO.Unsafe (unsafePerformIO)\n"), cons(boxString("import Text.Printf (printf, hPrintf)\n\n"), cons(boxString("default (Int, Double)\n\n"), cons(boxString("expect :: Maybe a -> a\n"), cons(boxString("expect (Just x) = x\n"), cons(boxString("expect Nothing = error \"Quon nil dereference\"\n\n"), cons(boxString("globalTrace :: IORef Bool\n"), cons(boxString("globalTrace = unsafePerformIO (newIORef False)\n"), cons(boxString("{-# NOINLINE globalTrace #-}\n\n"), cons(boxString("globalStepTrace :: IORef Bool\n"), cons(boxString("globalStepTrace = unsafePerformIO (newIORef False)\n"), cons(boxString("{-# NOINLINE globalStepTrace #-}\n\n"), cons(boxString("releaseMode :: IORef Bool\n"), cons(boxString("releaseMode = unsafePerformIO (newIORef False)\n"), cons(boxString("{-# NOINLINE releaseMode #-}\n\n"), cons(boxString("caller :: IORef String\n"), cons(boxString("caller = unsafePerformIO (newIORef \"\")\n"), cons(boxString("{-# NOINLINE caller #-}\n\n"), cons(boxString("globalArgs :: IORef [String]\n"), cons(boxString("globalArgs = unsafePerformIO (newIORef [])\n"), cons(boxString("{-# NOINLINE globalArgs #-}\n\n"), cons(boxString("globalArgsCount :: IORef Int\n"), cons(boxString("globalArgsCount = unsafePerformIO (newIORef 0)\n"), cons(boxString("{-# NOINLINE globalArgsCount #-}\n\n"), cons(boxString("globalStackTrace :: IORef (Maybe Box)\n"), cons(boxString("globalStackTrace = unsafePerformIO (newIORef Nothing)\n"), cons(boxString("{-# NOINLINE globalStackTrace #-}\n\n"), cons(boxString("hsIsNil :: Maybe a -> IO Bool\n"), cons(boxString("hsIsNil = pure . isNothing\n\n"), cons(boxString("hsGetEnv :: String -> IO String\n"), cons(boxString("hsGetEnv key = do\n"), cons(boxString("  value <- lookupEnv key\n"), cons(boxString("  pure (maybe \"\" (\\x -> x) value)\n\n"), cons(boxString("hsPanic :: String -> IO ()\n"), cons(boxString("hsPanic = error\n\n"), cons(boxString("hsExit :: Int -> IO ()\n"), cons(boxString("hsExit 0 = exitWith ExitSuccess\n"), cons(boxString("hsExit n = exitWith (ExitFailure n)\n\n"), cons(boxString("hsStringLength :: String -> IO Int\n"), cons(boxString("hsStringLength = pure . length\n\n"), cons(boxString("hsSubString :: String -> Int -> Int -> IO String\n"), cons(boxString("hsSubString s start len = pure (take len (drop start s))\n\n"), cons(boxString("hsSetSubString :: String -> Int -> String -> IO String\n"), cons(boxString("hsSetSubString target start source = pure (take start target ++ source ++ drop (start + 1) target)\n\n"), cons(boxString("hsShowInt :: Int -> IO String\n"), cons(boxString("hsShowInt = pure . show\n\n"), cons(boxString("hsShowFloat :: Double -> IO String\n"), cons(boxString("hsShowFloat = pure . show\n\n"), cons(boxString("hsReadFile :: String -> IO (Maybe Box)\n"), cons(boxString("hsReadFile filename = do\n"), cons(boxString("  exists <- doesFileExist filename\n"), cons(boxString("  if exists then do\n"), cons(boxString("    contents <- readFile filename\n"), cons(boxString("    boxString contents\n"), cons(boxString("  else pure Nothing\n\n"), cons(boxString("hsWriteFile :: String -> String -> IO ()\n"), cons(boxString("hsWriteFile = writeFile\n\n"), cons(boxString("hsGetStringArray :: Int -> [String] -> IO String\n"), cons(boxString("hsGetStringArray index strs = pure (strs !! index)\n\n"), cons(boxString("hsProgramArgs :: IO [String]\n"), cons(boxString("hsProgramArgs = readIORef globalArgs\n\n"), cons(boxString("hsProgramArgsCount :: IO Int\n"), cons(boxString("hsProgramArgsCount = readIORef globalArgsCount\n\n"), cons(boxString("hsCharacter :: Int -> IO String\n"), cons(boxString("hsCharacter num = pure [chr num]\n\n"), cons(boxString("hsRemainder :: Int -> Int -> IO Int\n"), cons(boxString("hsRemainder a b = pure (a `mod` b)\n\n"), cons(boxString("hsMakeHash :: IO (IORef [(String, String)])\n"), cons(boxString("hsMakeHash = newIORef []\n\n"), cons(boxString("hsSetHash :: IORef [(String, String)] -> String -> String -> IO ()\n"), cons(boxString("hsSetHash hash key value = modifyIORef hash ((key, value) :)\n\n"), cons(boxString("hsGetHash :: IORef [(String, String)] -> String -> IO String\n"), cons(boxString("hsGetHash hash key = do\n"), cons(boxString("  pairs <- readIORef hash\n"), cons(boxString("  pure (maybe \"\" (\\x -> x) (lookup key pairs))\n\n"), cons(boxString("hsInHash :: IORef [(String, String)] -> String -> IO Bool\n"), cons(boxString("hsInHash hash key = do\n"), cons(boxString("  pairs <- readIORef hash\n"), cons(boxString("  pure (not (isNothing (lookup key pairs)))\n\n"), cons(boxString("hsMakeArray :: Int -> IO [String]\n"), cons(boxString("hsMakeArray len = pure (replicate len \"\")\n\n"), cons(boxString("hsSetArray :: [String] -> Int -> String -> IO ()\n"), cons(boxString("hsSetArray _ _ _ = pure ()\n\n"), cons(boxString("hsGetArray :: [String] -> Int -> IO String\n"), cons(boxString("hsGetArray array index = pure (array !! index)\n\n"), null)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));

}


Box haskellMainEntry() {
  
  return cons(boxString("\nmain :: IO ()\n"), cons(boxString("main = do\n"), cons(boxString("  args <- getArgs\n"), cons(boxString("  let qargs = \"fixmeprogname\" : args\n"), cons(boxString("  writeIORef globalArgs qargs\n"), cons(boxString("  writeIORef globalArgsCount (length qargs)\n"), cons(boxString("  _ <- start\n"), cons(boxString("  pure ()\n"), null))))))));

}


Box haskellApplyTypeAliases(Box tree, Box types) {
  Box node = null;
Box alias = null;
Box target = null;

  if ( isEmpty(types)) {
    return tree;

  } else {
  }

  node = car(types);

  if ( isList(second(node))) {
    return haskellApplyTypeAliases(tree, cdr(types));

  } else {
  }

  alias = first(node);

  if ( equalString(stringify(haskellTypeMap(alias)), stringify(alias))) {
    target = haskellTypeMap(second(node));

    return haskellApplyTypeAliases(macroSymbolSingle(tree, stringify(alias), stringify(target)), cdr(types));

  } else {
    return haskellApplyTypeAliases(tree, cdr(types));

  }

}


Box haskellLoadProgram(String filename) {
  Box tree = null;
Box replace = null;

  tree = loadQuon(filename);

  tree = insertInclude(tree, "q/shims/haskell.qon");

  tree = loadIncludes(tree, null);

  tree = macrowalk(tree);

  replace = cons(boxSymbol("hPrintf"), cons(boxSymbol("stderr"), null));

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

  tree = haskellApplyTypeAliases(tree, cdr(getTypes(tree)));

  return tree;

}


Box haskellProgramTree(Box tree) {
  
  return cons(id(haskellIncludes(cdr(first(tree)))), cons(id(haskellTypes(cdr(second(tree)))), cons(id(haskellFunctions(cdr(third(tree)))), cons(id(haskellMainEntry()), cons(boxString("\n"), null)))));

}


String haskellProgram(Box tree) {
  
  return ListToString(flatten(haskellProgramTree(tree)), 0, true, false);

}


String haskellCompileString(String filename) {
  
  return haskellProgram(haskellLoadProgram(filename));

}


void haskellCompile(String filename) {
  Box tree = null;
Box replace = null;

  fprintf(stderr, "Scanning file...%s\n", filename);

  tree = loadQuon(filename);

  fprintf(stderr, "Adding Haskell shim functions\n");

  tree = insertInclude(tree, "q/shims/haskell.qon");

  fprintf(stderr, "Loading includes\n");

  tree = loadIncludes(tree, null);

  fprintf(stderr, "Walking tree\n");

  tree = macrowalk(tree);

  fprintf(stderr, "Replacing q log\n");

  replace = cons(boxSymbol("hPrintf"), cons(boxSymbol("stderr"), null));

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

  tree = haskellApplyTypeAliases(tree, cdr(getTypes(tree)));

  fprintf(stderr, "Printing program\n");

  printStringTree(haskellProgramTree(tree));

}


Box javaFunctionArgs(Box tree) {
  
  if ( isEmpty(tree)) {
    return emptyList();

  } else {
    if ( equalString(stringify(first(tree)), "...")) {
      if ( isNil(cddr(tree))) {
        return cons(boxString("Object... args"), null);

      } else {
        return cons(boxString("Object... args, "), cons(id(javaFunctionArgs(cddr(tree))), null));

      }

    } else {
      if ( isNil(cddr(tree))) {
        return cons(id(javaTypeMap(first(tree))), cons(boxString(" "), cons(id(javaFuncMap(second(tree))), null)));

      } else {
        return cons(id(javaTypeMap(first(tree))), cons(boxString(" "), cons(id(javaFuncMap(second(tree))), cons(boxString(", "), cons(id(javaFunctionArgs(cddr(tree))), null)))));

      }

    }

  }

}


Box javaAtom(Box tree) {
  
  if ( equalString("string", boxType(tree))) {
    return cons(boxString("\""), cons(id(boxString(stringify(tree))), cons(boxString("\""), null)));

  } else {
    return cons(id(javaFuncMap(tree)), null);

  }

}


Box javaExpression(Box tree, int indent) {
  Box thing = null;

  if ( notBool(isList(tree))) {
    return javaAtom(tree);

  } else {
    if ( equal(1, listLength(tree))) {
      if ( equalBox(boxString("return"), car(tree))) {
        return cons(id(javaFuncMap(car(tree))), null);

      } else {
        return cons(id(javaFuncMap(car(tree))), cons(boxString("()"), null));

      }

    } else {
      thing = first(tree);

      if ( equalBox(boxSymbol("get-struct"), thing)) {
        return cons(id(javaExpression(second(tree), indent)), cons(boxString("."), cons(id(third(tree)), null)));

      } else {
        if ( equalBox(boxSymbol("new"), thing)) {
          return cons(boxString("new "), cons(id(javaTypeMap(second(tree))), cons(boxString("()"), null)));

        } else {
          if ( equalBox(boxSymbol("passthrough"), thing)) {
            return cons(id(second(tree)), null);

          } else {
            if ( equalBox(boxSymbol("binop"), thing)) {
              return cons(boxString("("), cons(id(javaExpression(third(tree), indent)), cons(boxString(" "), cons(id(second(tree)), cons(boxString(" "), cons(id(javaExpression(fourth(tree), indent)), cons(boxString(")"), null)))))));

            } else {
              return cons(id(javaFuncMap(car(tree))), cons(boxString("("), cons(id(javaRecurList(cdr(tree), indent)), cons(boxString(")"), null))));

            }

          }

        }

      }

    }

  }

}


Box javaRecurList(Box expr, int indent) {
  
  if ( isEmpty(expr)) {
    return emptyList();

  } else {
    if ( isNil(cdr(expr))) {
      return javaExpression(car(expr), indent);

    } else {
      return cons(id(javaExpression(car(expr), indent)), cons(boxString(", "), cons(id(javaRecurList(cdr(expr), indent)), null)));

    }

  }

}


Box javaIf(Box node, int indent) {
  
  return cons(id(listNewLine(indent)), cons(boxString("if ( "), cons(id(javaExpression(second(node), 0)), cons(boxString(") {"), cons(id(javaBody(cdr(third(node)), add1(indent))), cons(id(listNewLine(indent)), cons(boxString("} else {"), cons(id(javaBody(cdr(fourth(node)), add1(indent))), cons(id(listNewLine(indent)), cons(boxString("}"), null))))))))));

}


Box javaSetStruct(Box node, int indent) {
  
  return cons(id(listNewLine(indent)), cons(id(javaExpression(second(node), indent)), cons(boxString("."), cons(id(third(node)), cons(boxString(" = "), cons(id(javaExpression(fourth(node), indent)), null))))));

}


Box javaSet(Box node, int indent) {
  
  return cons(id(listNewLine(indent)), cons(id(javaExpression(second(node), indent)), cons(boxString(" = "), cons(id(javaExpression(third(node), indent)), null))));

}


Box javaReturn(Box node, int indent) {
  
  if ( equal(listLength(node), 1)) {
    return cons(id(listNewLine(indent)), cons(boxString("return"), null));

  } else {
    return cons(id(listNewLine(indent)), cons(boxString("return "), cons(id(javaExpression(cadr(node), indent)), null)));

  }

}


Box javaStatement(Box node, int indent) {
  
  if ( equalBox(boxString("set"), first(node))) {
    return cons(id(javaSet(node, indent)), cons(boxString(";\n"), null));

  } else {
    if ( equalBox(boxString("set-struct"), first(node))) {
      return cons(id(javaSetStruct(node, indent)), cons(boxString(";\n"), null));

    } else {
      if ( equalBox(boxString("if"), first(node))) {
        return cons(id(javaIf(node, indent)), cons(boxString("\n"), null));

      } else {
        if ( equalBox(boxString("return"), first(node))) {
          return cons(id(javaReturn(node, indent)), cons(boxString(";\n"), null));

        } else {
          return cons(id(listNewLine(indent)), cons(id(javaExpression(node, indent)), cons(boxString(";\n"), null)));

        }

      }

    }

  }

}


Box javaBody(Box tree, int indent) {
  Box code = null;

  if ( isEmpty(tree)) {
    return emptyList();

  } else {
    code = car(tree);

    return cons(id(javaStatement(code, indent)), cons(id(javaBody(cdr(tree), indent)), null));

  }

}


Box javaDeclarations(Box decls, int indent) {
  Box decl = null;

  if ( isEmpty(decls)) {
    return emptyList();

  } else {
    decl = car(decls);

    return cons(id(javaTypeMap(first(decl))), cons(boxString(" "), cons(id(javaFuncMap(second(decl))), cons(boxString(" = "), cons(id(javaExpression(third(decl), indent)), cons(boxString(";\n"), cons(id(javaDeclarations(cdr(decls), indent)), null)))))));

  }

}


Box javaFunction(Box node) {
  Box name = null;

  name = second(node);

  if ( isNil(node)) {
    return emptyList();

  } else {
    return cons(id(listNewLine(0)), cons(id(listNewLine(0)), cons(id(javaTypeMap(first(node))), cons(boxString(" "), cons(id(javaFuncMap(second(node))), cons(boxString("("), cons(id(javaFunctionArgs(third(node))), cons(boxString(") {"), cons(id(listNewLine(1)), cons(id(javaDeclarations(cdr(fourth(node)), 1)), cons(id(javaBody(cdr(fifth(node)), 1)), cons(boxString("\n}\n"), null))))))))))));

  }

}


Box javaFunctions(Box tree) {
  
  if ( isEmpty(tree)) {
    return emptyList();

  } else {
    return cons(id(javaFunction(car(tree))), cons(id(javaFunctions(cdr(tree))), null));

  }

}


Box javaIncludes(Box nodes) {
  
  return cons(boxString("import java.nio.charset.StandardCharsets;\n"), cons(boxString("import java.nio.file.Files;\n"), cons(boxString("import java.nio.file.Paths;\n"), cons(boxString("import java.util.HashMap;\n\n"), cons(boxString("class QuonProgram {\n"), cons(boxString("  boolean globalTrace = false;\n"), cons(boxString("  boolean globalStepTrace = false;\n"), cons(boxString("  boolean releaseMode = false;\n"), cons(boxString("  Box globalStackTrace = null;\n"), cons(boxString("  String caller = \"\";\n"), cons(boxString("  String[] globalArgs = new String[0];\n"), cons(boxString("  int globalArgsCount = 0;\n\n"), cons(boxString("  Object stderr = new Object();\n\n"), cons(boxString("  void fprintf(Object stream, String format, Object... args) {\n"), cons(boxString("    if (args.length == 0) {\n"), cons(boxString("      System.err.print(format);\n"), cons(boxString("    } else {\n"), cons(boxString("      System.err.printf(format, args);\n"), cons(boxString("    }\n"), cons(boxString("  }\n\n"), cons(boxString("  void exit(int code) {\n"), cons(boxString("    System.exit(code);\n"), cons(boxString("  }\n\n"), cons(boxString("  Box readFileBox(String filename) {\n"), cons(boxString("    try {\n"), cons(boxString("      return boxString(Files.readString(Paths.get(filename)));\n"), cons(boxString("    } catch (Exception e) {\n"), cons(boxString("      return null;\n"), cons(boxString("    }\n"), cons(boxString("  }\n\n"), cons(boxString("  void writeFileUnchecked(String filename, String data) {\n"), cons(boxString("    try {\n"), cons(boxString("      Files.write(Paths.get(filename), data.getBytes(StandardCharsets.UTF_8));\n"), cons(boxString("    } catch (Exception e) {\n"), cons(boxString("      throw new RuntimeException(\"Could not write file: \" + filename, e);\n"), cons(boxString("    }\n"), cons(boxString("  }\n"), null)))))))))))))))))))))))))))))))))))));

}


Box javaTypeMap(Box aSym) {
  Box symMap = null;

  symMap = alistCons(boxSymbol("pair"), boxSymbol("Box"), alistCons(boxSymbol("box"), boxSymbol("Box"), alistCons(boxSymbol("list"), boxSymbol("Box"), alistCons(boxSymbol("Box*"), boxSymbol("Box"), alistCons(boxSymbol("struct"), boxSymbol(""), alistCons(boxSymbol("bool"), boxSymbol("boolean"), alistCons(boxSymbol("uint"), boxSymbol("int"), alistCons(boxSymbol("float"), boxSymbol("double"), alistCons(boxSymbol("stringArray"), boxSymbol("String[]"), alistCons(boxSymbol("array"), boxSymbol("String[]"), alistCons(boxSymbol("hashmap"), boxSymbol("HashMap<String, String>"), alistCons(boxSymbol("string"), boxSymbol("String"), null))))))))))));

  if ( truthy(assoc(stringify(aSym), symMap))) {
    return cdr(assoc(stringify(aSym), symMap));

  } else {
    return aSym;

  }

}


Box javaPointerBase(Box aSym) {
  String name = "";

  name = stringify(aSym);

  if ( equalString("*", sub_string(name, sub1(string_length(name)), 1))) {
    return boxSymbol(sub_string(name, 0, sub1(string_length(name))));

  } else {
    return aSym;

  }

}


Box javaFuncMap(Box aSym) {
  Box symMap = null;

  if ( equalString("symbol", boxType(aSym))) {
    symMap = alistCons(boxSymbol("printf"), boxSymbol("System.out.printf"), alistCons(boxSymbol(stringConcatenate("q", "log")), boxSymbol("System.err.printf"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("null"), alistCons(boxSymbol("old"), boxSymbol("oldValue"), alistCons(boxSymbol("new"), boxSymbol("newValue"), null)))))))))));

    if ( truthy(assoc(stringify(aSym), symMap))) {
      return cdr(assoc(stringify(aSym), symMap));

    } else {
      return aSym;

    }

  } else {
    return aSym;

  }

}


Box javaTypeDecl(Box l) {
  
  if ( greaterthan(listLength(l), 2)) {
    return cons(id(boxString(stringIndent(1))), cons(id(javaTypeMap(listLast(l))), cons(boxString(" "), cons(id(first(l)), cons(boxString(";\n"), null)))));

  } else {
    return cons(id(boxString(stringIndent(1))), cons(id(javaTypeMap(listLast(l))), cons(boxString(" "), cons(id(car(l)), cons(boxString(";\n"), null)))));

  }

}


Box javaStructComponents(Box node) {
  
  if ( isEmpty(node)) {
    return emptyList();

  } else {
    return cons(id(javaTypeDecl(car(node))), cons(id(javaStructComponents(cdr(node))), null));

  }

}


Box javaStruct(Box node) {
  
  return javaStructComponents(cdr(node));

}


Box javaType(Box node) {
  
  if ( isList(second(node))) {
    return cons(boxString("\nclass "), cons(id(first(node)), cons(boxString(" {\n"), cons(id(javaStruct(second(node))), cons(boxString("}\n"), null)))));

  } else {
    return emptyList();

  }

}


Box javaTypes(Box nodes) {
  
  if ( isEmpty(nodes)) {
    return emptyList();

  } else {
    return cons(id(javaType(car(nodes))), cons(id(javaTypes(cdr(nodes))), null));

  }

}


Box javaApplyTypeAliases(Box tree, Box types) {
  Box node = null;
Box alias = null;
Box target = null;

  if ( isEmpty(types)) {
    return tree;

  } else {
  }

  node = car(types);

  if ( isList(second(node))) {
    return javaApplyTypeAliases(tree, cdr(types));

  } else {
  }

  alias = first(node);

  if ( equalString(stringify(javaTypeMap(alias)), stringify(alias))) {
    target = javaTypeMap(javaPointerBase(second(node)));

    return javaApplyTypeAliases(macroSymbolSingle(tree, stringify(alias), stringify(target)), cdr(types));

  } else {
    return javaApplyTypeAliases(tree, cdr(types));

  }

}


Box javaMainEntry() {
  
  return cons(boxString("\npublic static void main(String[] args) {\n"), cons(boxString("  QuonProgram program = new QuonProgram();\n"), cons(boxString("  program.globalArgs = new String[args.length + 1];\n"), cons(boxString("  program.globalArgs[0] = \"fixmeprogname\";\n"), cons(boxString("  System.arraycopy(args, 0, program.globalArgs, 1, args.length);\n"), cons(boxString("  program.globalArgsCount = program.globalArgs.length;\n"), cons(boxString("  program.start();\n"), cons(boxString("}\n"), cons(boxString("}\n"), null)))))))));

}


Box javaLoadProgram(String filename) {
  Box tree = null;
Box replace = null;

  tree = loadQuon(filename);

  tree = buildProg(cons(boxString("q/shims/java.qon"), getIncludes(tree)), getTypes(tree), getFunctions(tree));

  tree = loadIncludes(tree, null);

  tree = macrowalk(tree);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), null));

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

  tree = javaApplyTypeAliases(tree, cdr(getTypes(tree)));

  return tree;

}


Box javaProgramTree(Box tree) {
  
  return cons(id(javaIncludes(cdr(first(tree)))), cons(id(javaTypes(cdr(second(tree)))), cons(id(javaFunctions(cdr(third(tree)))), cons(id(javaMainEntry()), cons(boxString("\n"), null)))));

}


String javaProgram(Box tree) {
  
  return ListToString(flatten(javaProgramTree(tree)), 0, true, false);

}


String javaCompileString(String filename) {
  
  return javaProgram(javaLoadProgram(filename));

}


void javaCompile(String filename) {
  
  printStringTree(javaProgramTree(javaLoadProgram(filename)));

  fprintf(stderr, "//Done printing program\n");

}


Box ansi3FunctionArgs(Box tree) {
  
  if ( isEmpty(tree)) {
    return emptyList();

  } else {
    if ( equalString(stringify(first(tree)), "...")) {
      if ( isNil(cddr(tree))) {
        return cons(boxString("..."), null);

      } else {
        return cons(boxString("..."), cons(boxString(", "), cons(id(ansi3FunctionArgs(cddr(tree))), null)));

      }

    } else {
      if ( isNil(cddr(tree))) {
        return cons(id(ansi3TypeMap(first(tree))), cons(boxString(" "), cons(id(second(tree)), null)));

      } else {
        return cons(id(ansi3TypeMap(first(tree))), cons(boxString(" "), cons(id(second(tree)), cons(boxString(", "), cons(id(ansi3FunctionArgs(cddr(tree))), null)))));

      }

    }

  }

}


Box ansi3Atom(Box tree) {
  
  if ( equalString("string", boxType(tree))) {
    return cons(boxString("\""), cons(id(boxString(stringify(tree))), cons(boxString("\""), null)));

  } else {
    return cons(id(ansi3FuncMap(tree)), null);

  }

}


Box ansi3Expression(Box tree, int indent) {
  Box thing = null;

  if ( notBool(isList(tree))) {
    return ansi3Atom(tree);

  } else {
    if ( equal(1, listLength(tree))) {
      if ( equalBox(boxString("return"), car(tree))) {
        return cons(id(ansi3FuncMap(car(tree))), null);

      } else {
        return cons(id(ansi3FuncMap(car(tree))), cons(boxString("()"), null));

      }

    } else {
      thing = first(tree);

      if ( equalBox(boxSymbol("get-struct"), thing)) {
        return cons(id(second(tree)), cons(boxString("->"), cons(id(third(tree)), null)));

      } else {
        if ( equalBox(boxSymbol("new"), thing)) {
          return cons(boxString("malloc(sizeof("), cons(id(third(tree)), cons(boxString("))"), null)));

        } else {
          if ( equalBox(boxSymbol("passthrough"), thing)) {
            return cons(id(second(tree)), null);

          } else {
            if ( equalBox(boxSymbol("binop"), thing)) {
              return cons(boxString("("), cons(id(ansi3Expression(third(tree), indent)), cons(boxString(" "), cons(id(second(tree)), cons(boxString(" "), cons(id(ansi3Expression(fourth(tree), indent)), cons(boxString(")"), null)))))));

            } else {
              return cons(id(ansi3FuncMap(car(tree))), cons(boxString("("), cons(id(ansi3RecurList(cdr(tree), indent)), cons(boxString(")"), null))));

            }

          }

        }

      }

    }

  }

}


Box ansi3RecurList(Box expr, int indent) {
  
  if ( isEmpty(expr)) {
    return emptyList();

  } else {
    if ( isNil(cdr(expr))) {
      return ansi3Expression(car(expr), indent);

    } else {
      return cons(id(ansi3Expression(car(expr), indent)), cons(boxString(", "), cons(id(ansi3RecurList(cdr(expr), indent)), null)));

    }

  }

}


Box ansi3If(Box node, int indent, String functionName) {
  
  return cons(id(listNewLine(indent)), cons(boxString("if ( "), cons(id(ansi3Expression(second(node), 0)), cons(boxString(") {"), cons(id(ansi3Body(cdr(third(node)), add1(indent), functionName)), cons(id(listNewLine(indent)), cons(boxString("} else {"), cons(id(ansi3Body(cdr(fourth(node)), add1(indent), functionName)), cons(id(listNewLine(indent)), cons(boxString("}"), null))))))))));

}


Box ansi3SetStruct(Box node, int indent) {
  
  return cons(id(listNewLine(indent)), cons(id(second(node)), cons(boxString("->"), cons(id(third(node)), cons(boxString(" = "), cons(id(ansi3Expression(fourth(node), indent)), null))))));

}


Box ansi3Set(Box node, int indent) {
  
  return cons(id(listNewLine(indent)), cons(id(ansi3Expression(second(node), indent)), cons(boxString(" = "), cons(id(ansi3Expression(third(node), indent)), null))));

}


Box ansi3Return(Box node, int indent) {
  
  if ( equal(listLength(node), 1)) {
    return cons(id(listNewLine(indent)), cons(boxString("return;"), null));

  } else {
    return cons(id(listNewLine(indent)), cons(boxString("return "), cons(id(ansi3Expression(cadr(node), indent)), cons(boxString(";"), null))));

  }

}


Box ansi3TraceReturn(Box node, int indent, String functionName) {
  
  if ( releaseMode) {
    return ansi3Return(node, indent);

  } else {
    if ( inList(boxString(functionName), NoStackTrace_list())) {
      return ansi3Return(node, indent);

    } else {
      return cons(boxString("\n"), cons(id(boxString(stringIndent(indent))), cons(boxString("StackTraceMove(\"out\", \"\", \"\", \"\");\n"), cons(id(ansi3Return(node, indent)), null))));

    }

  }

}


Box ansi3Statement(Box node, int indent, String functionName) {
  
  if ( equalBox(boxString("set"), first(node))) {
    return cons(id(ansi3Set(node, indent)), cons(boxString(";\n"), null));

  } else {
    if ( equalBox(boxString("set-struct"), first(node))) {
      return cons(id(ansi3SetStruct(node, indent)), cons(boxString(";\n"), null));

    } else {
      if ( equalBox(boxString("if"), first(node))) {
        return cons(id(ansi3If(node, indent, functionName)), cons(boxString(";\n"), null));

      } else {
        if ( equalBox(boxString("return"), first(node))) {
          return cons(id(ansi3TraceReturn(node, indent, functionName)), cons(boxString(";\n"), null));

        } else {
          return cons(id(listNewLine(indent)), cons(id(ansi3Expression(node, indent)), cons(boxString(";\n"), null)));

        }

      }

    }

  }

}


Box ansi3StatementTrace(Box code, int indent, String functionName) {
  
  if ( releaseMode) {
    return emptyList();

  } else {
    if ( inList(boxString(functionName), NoTrace_list())) {
      return emptyList();

    } else {
      return cons(boxString("\nif (globalTrace)\n    snprintf(caller, 1024, \"from "), cons(id(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), cons(boxString(":"), cons(id(getTagFail(car(code), boxString("line"), boxString("Line missing"))), cons(boxString("\");\n"), null)))));

    }

  }

}


Box ansi3StepTrace(int indent) {
  
  if ( releaseMode) {
    return emptyList();

  } else {
    return cons(id(boxString(stringIndent(indent))), cons(boxString("if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n"), null));

  }

}


Box ansi3Body(Box tree, int indent, String functionName) {
  Box code = null;

  if ( isEmpty(tree)) {
    return emptyList();

  } else {
    code = car(tree);

    return cons(id(ansi3StatementTrace(code, indent, functionName)), cons(id(ansi3StepTrace(indent)), cons(id(ansi3Statement(code, indent, functionName)), cons(id(ansi3Body(cdr(tree), indent, functionName)), null))));

  }

}


Box ansi3Declarations(Box decls, int indent) {
  Box decl = null;

  if ( isEmpty(decls)) {
    return emptyList();

  } else {
    decl = car(decls);

    return cons(id(ansi3TypeMap(first(decl))), cons(boxString(" "), cons(id(second(decl)), cons(boxString(" = "), cons(id(ansi3Expression(third(decl), indent)), cons(boxString(";\n"), cons(id(ansi3Declarations(cdr(decls), indent)), null)))))));

  }

}


Box ansi3FunctionTrace(Box name) {
  
  if ( releaseMode) {
    return emptyList();

  } else {
    if ( inList(name, NoTrace_list())) {
      return emptyList();

    } else {
      return cons(boxString("\nif (globalTrace)\n    printf(\""), cons(id(name), cons(boxString(" at "), cons(id(getTag(name, boxString("filename"))), cons(boxString(":"), cons(id(getTag(name, boxString("line"))), cons(boxString(" (%s)\\n\", caller);\n"), null)))))));

    }

  }

}


Box ansi3FunctionStackTrace(Box name) {
  
  if ( releaseMode) {
    return emptyList();

  } else {
    if ( inList(name, NoStackTrace_list())) {
      return emptyList();

    } else {
      return cons(boxString("\n  StackTraceMove(\"in\", \""), cons(id(getTag(name, boxString("filename"))), cons(boxString("\", \""), cons(id(name), cons(boxString("\", \""), cons(id(getTag(name, boxString("line"))), cons(boxString("\" );\n"), null)))))));

    }

  }

}


Box ansi3Function(Box node) {
  Box name = null;

  name = second(node);

  if ( isNil(node)) {
    return emptyList();

  } else {
    return cons(id(listNewLine(0)), cons(id(listNewLine(0)), cons(id(ansi3TypeMap(first(node))), cons(boxString(" "), cons(id(second(node)), cons(boxString("("), cons(id(ansi3FunctionArgs(third(node))), cons(boxString(") {"), cons(id(listNewLine(1)), cons(id(ansi3Declarations(cdr(fourth(node)), 1)), cons(id(ansi3FunctionTrace(name)), cons(id(ansi3FunctionStackTrace(name)), cons(id(ansi3Body(cdr(fifth(node)), 1, stringify(name))), cons(boxString("\n}\n"), null))))))))))))));

  }

}


Box ansi3ForwardDeclaration(Box node) {
  
  if ( isNil(node)) {
    return emptyList();

  } else {
    return cons(boxString("\n"), cons(id(ansi3TypeMap(first(node))), cons(boxString(" "), cons(id(second(node)), cons(boxString("("), cons(id(ansi3FunctionArgs(third(node))), cons(boxString(");"), null)))))));

  }

}


Box ansi3ForwardDeclarations(Box tree) {
  
  if ( isEmpty(tree)) {
    return emptyList();

  } else {
    return cons(id(ansi3ForwardDeclaration(car(tree))), cons(id(ansi3ForwardDeclarations(cdr(tree))), null));

  }

}


Box ansi3Functions(Box tree) {
  
  if ( isEmpty(tree)) {
    return emptyList();

  } else {
    return cons(id(ansi3Function(car(tree))), cons(id(ansi3Functions(cdr(tree))), null));

  }

}


Box ansi3Includes(Box nodes) {
  
  return cons(boxString("\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\n#include <unistd.h>\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\nbool releaseMode = false;\n\n"), cons(boxString("void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n"), null));

}


Box ansi3TypeDecl(Box l) {
  
  if ( greaterthan(listLength(l), 2)) {
    return cons(id(boxString(stringIndent(1))), cons(id(second(l)), cons(boxString(" "), cons(id(ansi3TypeMap(listLast(l))), cons(boxString(" "), cons(id(first(l)), cons(boxString(";\n"), null)))))));

  } else {
    return cons(id(boxString(stringIndent(1))), cons(id(ansi3TypeMap(listLast(l))), cons(boxString(" "), cons(id(car(l)), cons(boxString(";\n"), null)))));

  }

}


Box ansi3StructComponents(Box node) {
  
  if ( isEmpty(node)) {
    return emptyList();

  } else {
    return cons(id(ansi3TypeDecl(car(node))), cons(id(ansi3StructComponents(cdr(node))), null));

  }

}


Box ansi3Struct(Box node) {
  
  return ansi3StructComponents(cdr(node));

}


Box ansi3TypeMap(Box aSym) {
  Box symMap = null;

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), null));

  if ( truthy(assoc(stringify(aSym), symMap))) {
    return cdr(assoc(stringify(aSym), symMap));

  } else {
    return aSym;

  }

}


Box ansi3FuncMap(Box aSym) {
  Box symMap = null;

  if ( equalString("symbol", boxType(aSym))) {
    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), null)))))));

    if ( truthy(assoc(stringify(aSym), symMap))) {
      return cdr(assoc(stringify(aSym), symMap));

    } else {
      return aSym;

    }

  } else {
    return aSym;

  }

}


Box ansi3Type(Box node) {
  
  if ( isList(second(node))) {
    return cons(boxString("\ntypedef struct "), cons(id(first(node)), cons(boxString(" {\n"), cons(id(ansi3Struct(second(node))), cons(boxString("\n} "), cons(id(first(node)), cons(boxString(";\n"), null)))))));

  } else {
    return cons(boxString("typedef "), cons(id(ansi3TypeDecl(node)), null));

  }

}


Box ansi3Types(Box nodes) {
  
  if ( isEmpty(nodes)) {
    return emptyList();

  } else {
    return cons(id(ansi3Type(car(nodes))), cons(id(ansi3Types(cdr(nodes))), null));

  }

}


Box ansi3LoadProgram(String filename) {
  Box tree = null;
Box replace = null;

  tree = loadQuon(filename);

  tree = buildProg(cons(boxString("q/shims/ansi3.qon"), getIncludes(tree)), getTypes(tree), getFunctions(tree));

  tree = loadIncludes(tree, null);

  tree = macrowalk(tree);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), null));

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

  return tree;

}


Box ansi3ProgramTree(Box tree) {
  
  return cons(id(ansi3Includes(cdr(first(tree)))), cons(id(ansi3Types(cdr(second(tree)))), cons(boxString("Box* globalStackTrace = NULL;\n"), cons(boxString("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n"), cons(id(ansi3ForwardDeclarations(cdr(third(tree)))), cons(boxString("\n\n//End forward declarations\n\n"), cons(id(ansi3Functions(cdr(third(tree)))), cons(boxString("\n"), null))))))));

}


String ansi3Program(Box tree) {
  
  return ListToString(flatten(ansi3ProgramTree(tree)), 0, true, false);

}


String ansi3CompileString(String filename) {
  
  return ansi3Program(ansi3LoadProgram(filename));

}


void ansi3Compile(String filename) {
  
  printStringTree(ansi3ProgramTree(ansi3LoadProgram(filename)));

  fprintf(stderr, "//Done printing program\n");

}


String dollar() {
  
  return character(36);

}


String atsymbol() {
  
  return character(64);

}


String singleQuote() {
  
  return "'";

}


String escapedSingleQuote() {
  
  return "\\'";

}


String backslash() {
  
  return character(92);

}


String escapedDollar() {
  
  return StringListJoin(cons(boxString(backslash()), cons(boxString(dollar()), null)), "");

}


String escapedAtSign() {
  
  return StringListJoin(cons(boxString(backslash()), cons(boxString(atsymbol()), null)), "");

}


String escapeSingleQuotes(String s) {
  
  return stringReplace(singleQuote(), escapedSingleQuote(), s);

}


String escapePerlString(String s) {
  
  return stringReplace(atsymbol(), escapedAtSign(), stringReplace(dollar(), escapedDollar(), s));

}


Box getGlobalVariables() {
  
  return cons(id(boxSymbol("stderr")), cons(id(boxSymbol("true")), cons(id(boxSymbol("false")), cons(id(boxSymbol("releaseMode")), cons(id(boxSymbol("caller")), cons(id(boxSymbol("globalTrace")), cons(id(boxSymbol("globalStepTrace")), cons(id(boxSymbol("globalStackTrace")), cons(id(boxSymbol("globalArgsCount")), cons(id(boxSymbol("globalArgs")), cons(id(boxSymbol("quonGlobalArgs")), null)))))))))));

}


Box collectVariables(Box args, Box decls) {
  Box variables = null;
Box decl = null;

  variables = collectVariablesFromArgs(args);

  variables = appendVariables(variables, collectVariablesFromDecls(decls));

  variables = appendVariables(variables, getGlobalVariables());

  return variables;

}


Box perlGlobalVariables() {
  
  return cons(boxString("our "), cons(boxString(dollar()), cons(boxString("globalArgsCount;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("globalArgs;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("releaseMode;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("globalTrace;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("globalStepTrace;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("globalStackTrace;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("caller;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("false = 0;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("true = 1;\n"), cons(boxString("my "), cons(boxString(dollar()), cons(boxString("stderr = \\*STDERR;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("quonGlobalArgs;\n"), null)))))))))))))))))))))))))))))))));

}


Box perlMainEntry() {
  
  return cons(boxString("\n# Main entry point\n"), cons(boxString(dollar()), cons(boxString("globalArgsCount = scalar("), cons(boxString(atsymbol()), cons(boxString("ARGV) + 1;\n"), cons(boxString(dollar()), cons(boxString("globalArgs = \\"), cons(boxString(atsymbol()), cons(boxString("ARGV;\n"), cons(boxString("unshift "), cons(boxString(atsymbol()), cons(boxString(dollar()), cons(boxString("globalArgs, 'fixmeprogname' ;\n"), cons(boxString(dollar()), cons(boxString("quonGlobalArgs = [];\n"), cons(boxString("for my "), cons(boxString(dollar()), cons(boxString("arg ("), cons(boxString(atsymbol()), cons(boxString(dollar()), cons(boxString("globalArgs) {\n"), cons(boxString("    push "), cons(boxString(atsymbol()), cons(boxString(dollar()), cons(boxString("quonGlobalArgs, {car => "), cons(boxString(dollar()), cons(boxString("arg, cdr => undef};\n"), cons(boxString("}\n"), cons(boxString("for (my "), cons(boxString(dollar()), cons(boxString("i = scalar("), cons(boxString(atsymbol()), cons(boxString(dollar()), cons(boxString("quonGlobalArgs) - 1; "), cons(boxString(dollar()), cons(boxString("i >= 0; "), cons(boxString(dollar()), cons(boxString("i--) {\n"), cons(boxString("    "), cons(boxString(dollar()), cons(boxString("quonGlobalArgs->["), cons(boxString(dollar()), cons(boxString("i]->{cdr} = "), cons(boxString(dollar()), cons(boxString("quonGlobalArgs->["), cons(boxString(dollar()), cons(boxString("i + 1];\n"), cons(boxString("}\n"), cons(boxString("*stderr = *STDERR;\n"), cons(boxString("sub fprintf { my "), cons(boxString(dollar()), cons(boxString("f = shift; printf "), cons(boxString(dollar()), cons(boxString("f "), cons(boxString(atsymbol()), cons(boxString("_ }\n"), cons(boxString("start();\n"), null)))))))))))))))))))))))))))))))))))))))))))))))))))))))));

}


Box collectVariablesFromArgs(Box args) {
  Box variables = null;

  if ( isNil(args)) {
    return variables;

  } else {
    if ( equalString(stringify(first(args)), "list")) {
      variables = cons(second(args), variables);

      return appendVariables(variables, collectVariablesFromArgs(cddr(args)));

    } else {
      variables = cons(second(args), variables);

      return appendVariables(variables, collectVariablesFromArgs(cddr(args)));

    }

  }

}


Box collectVariablesFromDecls(Box decls) {
  Box variables = null;
Box decl = null;

  if ( isNil(decls)) {
    return variables;

  } else {
    decl = car(decls);

    variables = cons(second(decl), variables);

    return appendVariables(variables, collectVariablesFromDecls(cdr(decls)));

  }

}


Box appendVariables(Box vars1, Box vars2) {
  
  if ( isNil(vars2)) {
    return vars1;

  } else {
    vars1 = cons(car(vars2), vars1);

    return appendVariables(vars1, cdr(vars2));

  }

}


Box perlFunctionArgs(Box tree) {
  
  if ( isEmpty(tree)) {
    return emptyList();

  } else {
    if ( isNil(cddr(tree))) {
      return cons(id(boxString(dollar())), cons(id(second(tree)), null));

    } else {
      return cons(id(boxString(dollar())), cons(id(second(tree)), cons(boxString(", "), cons(id(perlFunctionArgs(cddr(tree))), null))));

    }

  }

}


Box perlAtom(Box tree, Box variables) {
  
  if ( equalString("string", boxType(tree))) {
    return cons(boxString("\""), cons(id(boxString(escapePerlString(stringify(tree)))), cons(boxString("\""), null)));

  } else {
    return cons(id(perlFuncMap(tree, variables)), null);

  }

}


Box perlExpression(Box tree, int indent, Box variables) {
  Box thing = null;

  if ( notBool(isList(tree))) {
    return perlAtom(tree, variables);

  } else {
    if ( equal(1, listLength(tree))) {
      if ( equalBox(boxString("return"), car(tree))) {
        return cons(id(perlFuncMap(car(tree), variables)), null);

      } else {
        return cons(id(perlFuncMap(car(tree), variables)), cons(boxString("()"), null));

      }

    } else {
      thing = first(tree);

      if ( equalBox(boxSymbol("get-struct"), thing)) {
        return cons(id(boxString(dollar())), cons(id(second(tree)), cons(boxString("->{"), cons(id(third(tree)), cons(boxString("}"), null)))));

      } else {
        if ( equalBox(boxSymbol("new"), thing)) {
          return cons(boxString("{}"), null);

        } else {
          if ( equalBox(boxSymbol("passthrough"), thing)) {
            return cons(id(second(tree)), null);

          } else {
            if ( equalBox(boxSymbol("binop"), thing)) {
              return cons(boxString("("), cons(id(perlExpression(third(tree), indent, variables)), cons(boxString(" "), cons(id(second(tree)), cons(boxString(" "), cons(id(perlExpression(fourth(tree), indent, variables)), cons(boxString(")"), null)))))));

            } else {
              return cons(id(perlFuncMap(car(tree), variables)), cons(boxString("("), cons(id(perlRecurList(cdr(tree), indent, variables)), cons(boxString(")"), null))));

            }

          }

        }

      }

    }

  }

}


Box perlRecurList(Box expr, int indent, Box variables) {
  
  if ( isEmpty(expr)) {
    return emptyList();

  } else {
    if ( isNil(cdr(expr))) {
      return perlExpression(car(expr), indent, variables);

    } else {
      return cons(id(perlExpression(car(expr), indent, variables)), cons(boxString(", "), cons(id(perlRecurList(cdr(expr), indent, variables)), null)));

    }

  }

}


Box perlSet(Box node, int indent, Box variables) {
  
  return cons(id(listNewLine(indent)), cons(id(perlFuncMap(second(node), variables)), cons(boxString(" = "), cons(id(perlExpression(third(node), indent, variables)), null))));

}


Box perlSetStruct(Box node, int indent, Box variables) {
  
  return cons(id(listNewLine(indent)), cons(id(perlFuncMap(second(node), variables)), cons(boxString("->{"), cons(id(third(node)), cons(boxString("} = "), cons(id(perlExpression(fourth(node), indent, variables)), null))))));

}


Box perlReturn(Box node, int indent, Box variables) {
  
  if ( greaterthan(listLength(node), 1)) {
    return cons(id(listNewLine(indent)), cons(boxString("return "), cons(id(perlExpression(cadr(node), indent, variables)), null)));

  } else {
    return cons(id(listNewLine(indent)), cons(boxString("return"), null));

  }

}


Box perlIf(Box node, int indent, Box variables) {
  
  return cons(id(listNewLine(indent)), cons(boxString("if ( "), cons(id(perlExpression(second(node), 0, variables)), cons(boxString(" ) {"), cons(id(perlBody(cdr(third(node)), add1(indent), variables)), cons(id(listNewLine(indent)), cons(boxString("} else {"), cons(id(perlBody(cdr(fourth(node)), add1(indent), variables)), cons(id(listNewLine(indent)), cons(boxString("}"), null))))))))));

}


Box perlStatement(Box node, int indent, Box variables) {
  
  if ( equalBox(boxString("set"), first(node))) {
    return cons(id(perlSet(node, indent, variables)), cons(boxString(";\n"), null));

  } else {
    if ( equalBox(boxString("set-struct"), first(node))) {
      return cons(id(perlSetStruct(node, indent, variables)), cons(boxString(";\n"), null));

    } else {
      if ( equalBox(boxString("if"), first(node))) {
        return cons(id(perlIf(node, indent, variables)), cons(boxString(";\n"), null));

      } else {
        if ( equalBox(boxString("return"), first(node))) {
          return cons(id(perlReturn(node, indent, variables)), cons(boxString(";\n"), null));

        } else {
          return cons(id(listNewLine(indent)), cons(id(perlExpression(node, indent, variables)), cons(boxString(";\n"), null)));

        }

      }

    }

  }

}


Box perlBody(Box tree, int indent, Box variables) {
  Box code = null;

  if ( isEmpty(tree)) {
    return emptyList();

  } else {
    code = car(tree);

    return cons(id(perlStatement(code, indent, variables)), cons(id(perlBody(cdr(tree), indent, variables)), null));

  }

}


Box perlGetStruct(Box node, int indent) {
  
  return cons(id(listNewLine(indent)), cons(id(boxString(dollar())), cons(id(first(node)), cons(boxString("->{"), cons(id(second(node)), cons(boxString("}"), null))))));

}


Box perlDeclarations(Box decls, int indent, Box variables) {
  Box decl = null;

  if ( isEmpty(decls)) {
    return emptyList();

  } else {
    decl = car(decls);

    return cons(boxString("my "), cons(id(boxString(dollar())), cons(id(second(decl)), cons(boxString(" = "), cons(id(perlExpression(third(decl), indent, variables)), cons(boxString(";\n"), cons(id(perlDeclarations(cdr(decls), indent, variables)), null)))))));

  }

}


Box perlFunction(Box node) {
  Box name = null;
Box variables = null;
Box args = null;
Box decls = null;

  name = second(node);

  if ( isNil(node)) {
    return emptyList();

  } else {
    args = third(node);

    decls = cdr(fourth(node));

    variables = collectVariables(args, decls);

    return cons(boxString("\n\n# Function "), cons(id(name), cons(boxString(" from line "), cons(id(getTag(name, boxString("line"))), cons(id(listNewLine(0)), cons(id(listNewLine(0)), cons(boxString("sub "), cons(id(perlFuncMap(second(node), null)), cons(boxString(" {"), cons(id(listNewLine(1)), cons(boxString("my ("), cons(id(perlFunctionArgs(args)), cons(boxString(") = "), cons(id(boxString(atsymbol())), cons(boxString("_;"), cons(id(listNewLine(1)), cons(id(perlDeclarations(decls, 1, variables)), cons(id(perlBody(cdr(fifth(node)), 1, variables)), cons(boxString("\n}\n"), null)))))))))))))))))));

  }

}


Box perlForwardDeclaration(Box node) {
  
  if ( isNil(node)) {
    return emptyList();

  } else {
    return cons(boxString("sub "), cons(id(perlFuncMap(second(node), null)), cons(boxString(";\n"), null)));

  }

}


Box perlForwardDeclarations(Box tree) {
  
  if ( isEmpty(tree)) {
    return emptyList();

  } else {
    return cons(id(perlForwardDeclaration(car(tree))), cons(id(perlForwardDeclarations(cdr(tree))), null));

  }

}


Box perlFunctions(Box tree) {
  
  if ( isEmpty(tree)) {
    return emptyList();

  } else {
    return cons(id(perlFunction(car(tree))), cons(id(perlFunctions(cdr(tree))), null));

  }

}


Box perlIncludes(Box nodes) {
  
  return cons(boxString("use strict;\n"), cons(boxString("use warnings;\n"), cons(boxString("use v5.10;\n\n"), cons(boxString("no warnings 'recursion';\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("^M = 10_000;\n"), null)))))));

}


Box perlTypes(Box nodes) {
  
  return emptyList();

}


Box perlTypeMap(Box aSym) {
  Box symMap = null;

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("array"), alistCons(boxSymbol("string"), boxSymbol("string"), null));

  if ( truthy(assoc(stringify(aSym), symMap))) {
    return cdr(assoc(stringify(aSym), symMap));

  } else {
    return aSym;

  }

}


Box perlFuncMap(Box aSym, Box variables) {
  Box symMap = null;

  if ( equalString("symbol", boxType(aSym))) {
    if ( inList(aSym, variables)) {
      return boxSymbol(stringConcatenate(dollar(), stringify(aSym)));

    } else {
      symMap = alistCons(boxSymbol("sub"), boxSymbol("subtract"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("substr"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("length"), alistCons(boxSymbol("say"), boxSymbol("say_"), alistCons(boxSymbol("nil"), boxSymbol("undef"), null)))))))));

      if ( truthy(assoc(stringify(aSym), symMap))) {
        return cdr(assoc(stringify(aSym), symMap));

      } else {
        return aSym;

      }

    }

  } else {
    return aSym;

  }

}


Box perlLoadProgram(String filename) {
  Box tree = null;
Box replace = null;

  tree = loadQuon(filename);

  tree = insertInclude(tree, "q/shims/perl.qon");

  tree = loadIncludes(tree, null);

  tree = macrowalk(tree);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), null));

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

  return tree;

}


Box perlProgramTree(Box tree) {
  
  return cons(id(perlIncludes(cdr(first(tree)))), cons(id(perlTypes(cdr(second(tree)))), cons(id(perlGlobalVariables()), cons(boxString("\n# Forward declarations\n"), cons(id(perlForwardDeclarations(cdr(third(tree)))), cons(boxString("\n# End forward declarations\n"), cons(id(perlFunctions(cdr(third(tree)))), cons(id(perlMainEntry()), cons(boxString("\n"), null)))))))));

}


String perlProgram(Box tree) {
  
  return ListToString(flatten(perlProgramTree(tree)), 0, true, false);

}


String perlCompileString(String filename) {
  
  return perlProgram(perlLoadProgram(filename));

}


void perlCompile(String filename) {
  Box tree = null;
Box replace = null;

  fprintf(stderr, "Scanning file...%s\n", filename);

  tree = loadQuon(filename);

  fprintf(stderr, "Adding shim functions\n");

  tree = insertInclude(tree, "q/shims/perl.qon");

  fprintf(stderr, "Loading includes\n");

  tree = loadIncludes(tree, null);

  fprintf(stderr, "Walking tree\n");

  tree = macrowalk(tree);

  fprintf(stderr, "Replacing q log\n");

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), null));

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

  fprintf(stderr, "Printing program\n");

  printStringTree(perlProgramTree(tree));

}


Box readSexpr(String aStr, String filename) {
  Box tokens = null;
Box as = null;
Box tree = null;

  tokens = emptyList();

  tokens = filterTokens(filterVoid(scan(aStr, 0, 1, 0, 0, filename)));

  parserValidateParens(tokens, null, filename);

  as = sexprTree(tokens);

  parserValidateRoot(as, filename);

  tree = car(as);

  parserValidateProgram(tree, filename);

  return tree;

}


void parserPanicAt(String filename, Box token, String message) {
  
  if ( isNil(token)) {
    System.out.printf("Parse error in %s: %s\n", filename, message);

  } else {
    System.out.printf("Parse error in %s:%s:%s: %s\n", stringify(getTagFail(token, boxString("filename"), boxString(filename))), stringify(getTagFail(token, boxString("line"), boxString("?"))), stringify(getTagFail(token, boxString("column"), boxString("?"))), message);

  }

  exit(1);

}


void parserPanicAtNode(String filename, Box node, String message) {
  
  if ( isNil(node)) {
    parserPanicAt(filename, null, message);

  } else {
    if ( isList(node)) {
      if ( isEmpty(node)) {
        parserPanicAt(filename, null, message);

      } else {
        parserPanicAt(filename, car(node), message);

      }

    } else {
      parserPanicAt(filename, node, message);

    }

  }

}


boolean parserSymbolIs(Box b, String name) {
  
  if ( isNil(b)) {
    return false;

  } else {
  }

  if ( isList(b)) {
    return false;

  } else {
  }

  if ( equalString("symbol", boxType(b))) {
    return equalString(name, stringify(b));

  } else {
    return false;

  }

}


boolean parserListStartsWith(Box node, String name) {
  
  if ( isNil(node)) {
    return false;

  } else {
  }

  if ( isList(node)) {
    if ( isEmpty(node)) {
      return false;

    } else {
      return parserSymbolIs(car(node), name);

    }

  } else {
    return false;

  }

}


void parserValidateParens(Box tokens, Box openStack, String filename) {
  Box token = null;

  if ( isEmpty(tokens)) {
    if ( isEmpty(openStack)) {
      return;

    } else {
      parserPanicAt(filename, car(openStack), "missing ')'");

    }

  } else {
    token = car(tokens);

    if ( isOpenBrace(token)) {
      parserValidateParens(cdr(tokens), cons(token, openStack), filename);

    } else {
      if ( isCloseBrace(token)) {
        if ( isEmpty(openStack)) {
          parserPanicAt(filename, token, "unexpected ')'");

        } else {
          parserValidateParens(cdr(tokens), cdr(openStack), filename);

        }

      } else {
        parserValidateParens(cdr(tokens), openStack, filename);

      }

    }

  }

}


void parserValidateRoot(Box roots, String filename) {
  
  if ( equal(listLength(roots), 1)) {
    return;

  } else {
    if ( isEmpty(roots)) {
      parserPanicAt(filename, null, "expected one top-level program form");

    } else {
      parserPanicAtNode(filename, second(roots), "extra top-level form after program");

    }

  }

}


void parserValidateSection(Box section, String name, String filename) {
  
  if ( isNil(section)) {
    parserPanicAt(filename, null, "missing program section");

  } else {
  }

  if ( isList(section)) {
  } else {
    parserPanicAtNode(filename, section, "program section must be a list");

  }

  if ( parserListStartsWith(section, name)) {
    return;

  } else {
    parserPanicAtNode(filename, section, stringConcatenate("expected program section ", name));

  }

}


boolean parserIsFunctionDefinition(Box node) {
  
  if ( isNil(node)) {
    return false;

  } else {
  }

  if ( isList(node)) {
  } else {
    return false;

  }

  if ( equal(listLength(node), 5)) {
  } else {
    return false;

  }

  if ( isList(first(node))) {
    return false;

  } else {
  }

  if ( isList(second(node))) {
    return false;

  } else {
  }

  if ( isList(third(node))) {
  } else {
    return false;

  }

  if ( parserListStartsWith(fourth(node), "declare")) {
  } else {
    return false;

  }

  if ( parserListStartsWith(fifth(node), "body")) {
    return true;

  } else {
    return false;

  }

}


void parserRejectFunctionDefinitions(Box node, String filename) {
  
  if ( isNil(node)) {
    return;

  } else {
  }

  if ( parserIsFunctionDefinition(node)) {
    parserPanicAtNode(filename, node, "function definition is not allowed here");

  } else {
  }

  if ( isList(node)) {
    parserRejectFunctionDefinitionsList(node, filename);

  } else {
    return;

  }

}


void parserRejectFunctionDefinitionsList(Box nodes, String filename) {
  
  if ( isEmpty(nodes)) {
    return;

  } else {
    parserRejectFunctionDefinitions(car(nodes), filename);

    parserRejectFunctionDefinitionsList(cdr(nodes), filename);

  }

}


void parserValidateProgram(Box program, String filename) {
  
  if ( isNil(program)) {
    parserPanicAt(filename, null, "empty program");

  } else {
  }

  if ( isList(program)) {
  } else {
    parserPanicAtNode(filename, program, "program must be a list");

  }

  if ( equal(listLength(program), 3)) {
  } else {
    if ( equal(listLength(program), 4)) {
    } else {
      parserPanicAtNode(filename, program, "program must contain includes, types, and functions sections");

    }

  }

  parserValidateSection(first(program), "includes", filename);

  parserValidateSection(second(program), "types", filename);

  parserValidateSection(third(program), "functions", filename);

  parserRejectFunctionDefinitions(cdr(first(program)), filename);

  parserRejectFunctionDefinitions(cdr(second(program)), filename);

  if ( equal(listLength(program), 4)) {
    parserValidateSection(fourth(program), "globals", filename);

    parserRejectFunctionDefinitions(cdr(fourth(program)), filename);

  } else {
  }

  parserValidateFunctions(cdr(third(program)), filename);

}


void parserValidateFunctions(Box functions, String filename) {
  Box fn = null;

  if ( isEmpty(functions)) {
    return;

  } else {
    fn = car(functions);

    if ( parserIsFunctionDefinition(fn)) {
      parserValidateFunction(fn, filename);

    } else {
      parserPanicAtNode(filename, fn, "invalid function definition");

    }

    parserValidateFunctions(cdr(functions), filename);

  }

}


void parserValidateFunction(Box fn, String filename) {
  
  parserRejectFunctionDefinitions(third(fn), filename);

  parserRejectFunctionDefinitions(cdr(fourth(fn)), filename);

  parserValidateBody(cdr(fifth(fn)), filename);

}


void parserValidateBody(Box forms, String filename) {
  
  if ( isEmpty(forms)) {
    return;

  } else {
    parserValidateStatement(car(forms), filename);

    parserValidateBody(cdr(forms), filename);

  }

}


void parserValidateStatement(Box stmt, String filename) {
  
  if ( isNil(stmt)) {
    return;

  } else {
  }

  if ( isList(stmt)) {
  } else {
    parserPanicAtNode(filename, stmt, "statement must be a list");

  }

  if ( isEmpty(stmt)) {
    return;

  } else {
  }

  if ( parserIsFunctionDefinition(stmt)) {
    parserPanicAtNode(filename, stmt, "function definition nested inside body");

  } else {
  }

  if ( parserListStartsWith(stmt, "if")) {
    parserValidateIf(stmt, filename);

    return;

  } else {
  }

  if ( parserListStartsWith(stmt, "then")) {
    parserPanicAtNode(filename, stmt, "then branch outside if");

  } else {
  }

  if ( parserListStartsWith(stmt, "else")) {
    parserPanicAtNode(filename, stmt, "else branch outside if");

  } else {
  }

  if ( parserListStartsWith(stmt, "declare")) {
    parserPanicAtNode(filename, stmt, "declare block outside function header");

  } else {
  }

  if ( parserListStartsWith(stmt, "body")) {
    parserPanicAtNode(filename, stmt, "body block nested inside body");

  } else {
  }

  if ( parserListStartsWith(stmt, "functions")) {
    parserPanicAtNode(filename, stmt, "functions section nested inside body");

  } else {
  }

  if ( parserListStartsWith(stmt, "types")) {
    parserPanicAtNode(filename, stmt, "types section nested inside body");

  } else {
  }

  if ( parserListStartsWith(stmt, "includes")) {
    parserPanicAtNode(filename, stmt, "includes section nested inside body");

  } else {
  }

  if ( parserListStartsWith(stmt, "return")) {
    parserValidateReturn(stmt, filename);

    return;

  } else {
  }

  if ( parserListStartsWith(stmt, "set")) {
    parserValidateSet(stmt, filename);

    return;

  } else {
  }

  if ( parserListStartsWith(stmt, "set-struct")) {
    parserValidateSetStruct(stmt, filename);

    return;

  } else {
  }

  parserValidateExpression(stmt, filename);

}


void parserValidateReturn(Box stmt, String filename) {
  
  if ( greaterthan(listLength(stmt), 2)) {
    parserPanicAtNode(filename, stmt, "return takes zero or one value");

  } else {
  }

  if ( equal(listLength(stmt), 2)) {
    parserValidateExpression(second(stmt), filename);

  } else {
    return;

  }

}


void parserValidateSet(Box stmt, String filename) {
  
  if ( equal(listLength(stmt), 3)) {
    parserValidateExpression(second(stmt), filename);

    parserValidateExpression(third(stmt), filename);

  } else {
    parserPanicAtNode(filename, stmt, "set takes a target and value");

  }

}


void parserValidateSetStruct(Box stmt, String filename) {
  
  if ( equal(listLength(stmt), 4)) {
    parserValidateExpression(second(stmt), filename);

    parserValidateExpression(third(stmt), filename);

    parserValidateExpression(fourth(stmt), filename);

  } else {
    parserPanicAtNode(filename, stmt, "set-struct takes a target, field, and value");

  }

}


void parserValidateIf(Box stmt, String filename) {
  
  if ( equal(listLength(stmt), 4)) {
  } else {
    parserPanicAtNode(filename, stmt, "if must contain condition, then, and else");

  }

  parserValidateExpression(second(stmt), filename);

  parserValidateBranch(third(stmt), "then", filename);

  parserValidateBranch(fourth(stmt), "else", filename);

}


void parserValidateBranch(Box branch, String name, String filename) {
  
  if ( parserListStartsWith(branch, name)) {
    parserValidateBody(cdr(branch), filename);

  } else {
    parserPanicAtNode(filename, branch, stringConcatenate("expected ", name));

  }

}


void parserValidateExpression(Box expr, String filename) {
  
  if ( isNil(expr)) {
    return;

  } else {
  }

  if ( isList(expr)) {
  } else {
    return;

  }

  if ( isEmpty(expr)) {
    return;

  } else {
  }

  if ( parserIsFunctionDefinition(expr)) {
    parserPanicAtNode(filename, expr, "function definition nested inside expression");

  } else {
  }

  if ( parserListStartsWith(expr, "if")) {
    parserValidateIf(expr, filename);

    return;

  } else {
  }

  if ( parserListStartsWith(expr, "then")) {
    parserPanicAtNode(filename, expr, "then branch outside if");

  } else {
  }

  if ( parserListStartsWith(expr, "else")) {
    parserPanicAtNode(filename, expr, "else branch outside if");

  } else {
  }

  if ( parserListStartsWith(expr, "declare")) {
    parserPanicAtNode(filename, expr, "declare block inside expression");

  } else {
  }

  if ( parserListStartsWith(expr, "body")) {
    parserPanicAtNode(filename, expr, "body block inside expression");

  } else {
  }

  if ( parserListStartsWith(expr, "functions")) {
    parserPanicAtNode(filename, expr, "functions section inside expression");

  } else {
  }

  if ( parserListStartsWith(expr, "types")) {
    parserPanicAtNode(filename, expr, "types section inside expression");

  } else {
  }

  if ( parserListStartsWith(expr, "includes")) {
    parserPanicAtNode(filename, expr, "includes section inside expression");

  } else {
  }

  parserValidateExpressionList(expr, filename);

}


void parserValidateExpressionList(Box exprs, String filename) {
  
  if ( isEmpty(exprs)) {
    return;

  } else {
    parserValidateExpression(car(exprs), filename);

    parserValidateExpressionList(cdr(exprs), filename);

  }

}


Box sexprTree(Box l) {
  Box b = null;

  if ( isEmpty(l)) {
    return emptyList();

  } else {
    b = car(l);

    if ( isOpenBrace(b)) {
      return cons(sexprTree(cdr(l)), sexprTree(skipList(cdr(l))));

    } else {
      if ( isCloseBrace(b)) {
        return emptyList();

      } else {
        return setTag(boxString("line"), getTagFail(b, boxString("line"), boxInt(-1)), cons(b, sexprTree(cdr(l))));

      }

    }

  }

}


Box loadQuon(String filename) {
  Box programBox = null;
String programStr = "";
Box tree = null;

  programBox = read_file(filename);

  if ( isNil(programBox)) {
    fprintf(stderr, "Could not read file: ");

    fprintf(stderr, filename);

    fprintf(stderr, "\n");

    exit(1);

  } else {
  }

  programStr = unBoxString(programBox);

  tree = readSexpr(programStr, filename);

  return tree;

}


Box getIncludes(Box program) {
  
  return cdr(first(program));

}


Box getTypes(Box program) {
  
  return cdr(second(program));

}


Box getFunctions(Box program) {
  
  return cdr(third(program));

}


Box insertInclude(Box tree, String extra) {
  Box newProg = null;
Box includes = null;
Box types = null;
Box functions = null;
Box boxedExtra = null;
Box newIncludes = null;

  if ( isNil(tree)) {
    System.out.printf("insertInlcude: tree is nil");

    return null;

  } else {
    includes = getIncludes(tree);

    types = getTypes(tree);

    functions = getFunctions(tree);

    boxedExtra = boxSymbol(extra);

    newIncludes = cons(boxedExtra, includes);

    newProg = buildProg(newIncludes, types, functions);

    return newProg;

  }

}


boolean stringInList(String item, Box l) {
  
  if ( isNil(l)) {
    return false;

  } else {
    if ( equalString(item, stringify(car(l)))) {
      return true;

    } else {
      return stringInList(item, cdr(l));

    }

  }

}


Box appendMissingIncludes(Box candidates, Box pending, Box seen) {
  Box candidate = null;
String candidateFile = "";

  if ( isNil(candidates)) {
    return pending;

  } else {
    candidate = car(candidates);

    candidateFile = stringify(candidate);

    if ( orBool(stringInList(candidateFile, seen), stringInList(candidateFile, pending))) {
      return appendMissingIncludes(cdr(candidates), pending, seen);

    } else {
      return cons(candidate, appendMissingIncludes(cdr(candidates), pending, seen));

    }

  }

}


Box loadIncludes(Box tree, Box seen) {
  Box newProg = null;
String includeFile = "";
Box functionsCombined = null;
Box typesCombined = null;
Box includeTree = null;
Box pendingIncludes = null;
Box nextIncludes = null;
Box nextSeen = null;
Box contentsBox = null;
String contents = "";

  if ( greaterthan(listLength(getIncludes(tree)), 0)) {
    includeFile = stringify(first(getIncludes(tree)));

    if ( stringInList(includeFile, seen)) {
      newProg = buildProg(cdr(getIncludes(tree)), getTypes(tree), getFunctions(tree));

      return loadIncludes(newProg, seen);

    } else {
    }

    nextSeen = cons(boxString(includeFile), seen);

    contentsBox = read_file(includeFile);

    if ( isNil(contentsBox)) {
      fprintf(stderr, "Could not read include file: ");

      fprintf(stderr, includeFile);

      fprintf(stderr, "\n");

      exit(1);

      return null;

    } else {
    }

    contents = unBoxString(contentsBox);

    includeTree = readSexpr(contents, includeFile);

    if ( isNil(includeTree)) {
      fprintf(stderr, "Could not parse include file: ");

      fprintf(stderr, includeFile);

      fprintf(stderr, "\n");

      exit(1);

      return null;

    } else {
      functionsCombined = concatLists(getFunctions(includeTree), getFunctions(tree));

      typesCombined = concatLists(getTypes(includeTree), getTypes(tree));

      pendingIncludes = cdr(getIncludes(tree));

      nextIncludes = appendMissingIncludes(getIncludes(includeTree), pendingIncludes, nextSeen);

      newProg = buildProg(nextIncludes, typesCombined, functionsCombined);

      return loadIncludes(newProg, nextSeen);

    }

  } else {
    return tree;

  }

}


Box buildProg(Box includes, Box types, Box functions) {
  Box program = null;

  includes = cons(boxSymbol("includes"), includes);

  types = cons(boxSymbol("types"), types);

  functions = cons(boxSymbol("functions"), functions);

  program = cons(includes, cons(types, cons(functions, null)));

  return program;

}


Box car(Box l) {
  
  if ( isNil(l)) {
    System.out.printf("Cannot call car on empty list!\n");

    panic("Cannot call car on empty list!\n");

    return null;

  } else {
    assertType("list", l, 18, "q/lists.qon");

    if ( isNil(l.car)) {
      return null;

    } else {
      return l.car;

    }

  }

}


Box cdr(Box l) {
  
  if ( isEmpty(l)) {
    System.out.printf("Attempt to cdr an empty list!!!!\n");

    panic("Attempt to cdr an empty list!!!!\n");

    return null;

  } else {
    return l.cdr;

  }

}


Box cons(Box data, Box l) {
  Box p = null;

  p = makePair();

  p.cdr = l;

  p.car = data;

  p.typ = "list";

  return p;

}


Box caar(Box l) {
  
  return car(car(l));

}


Box cadr(Box l) {
  
  return car(cdr(l));

}


Box caddr(Box l) {
  
  return car(cdr(cdr(l)));

}


Box cadddr(Box l) {
  
  return car(cdr(cdr(cdr(l))));

}


Box caddddr(Box l) {
  
  return car(cdr(cdr(cdr(cdr(l)))));

}


Box cddr(Box l) {
  
  return cdr(cdr(l));

}


Box first(Box l) {
  
  return car(l);

}


Box second(Box l) {
  
  return cadr(l);

}


Box third(Box l) {
  
  return caddr(l);

}


Box fourth(Box l) {
  
  return cadddr(l);

}


Box fifth(Box l) {
  
  return caddddr(l);

}


Box sixth(Box l) {
  
  return car(cdr(cdr(cdr(cdr(cdr(l))))));

}


Box seventh(Box l) {
  
  return car(cdr(cdr(cdr(cdr(cdr(cdr(l)))))));

}


Box eighth(Box l) {
  
  return car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(l))))))));

}


Box ninth(Box l) {
  
  return car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(l)))))))));

}


Box tenth(Box l) {
  
  return car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(l))))))))));

}


Box eleventh(Box l) {
  
  return car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(l)))))))))));

}


Box twelfth(Box l) {
  
  return car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(l))))))))))));

}


Box rest(Box l) {
  
  return cdr(l);

}


boolean isList(Box b) {
  
  if ( isNil(b)) {
    return true;

  } else {
    return equalString("list", b.typ);

  }

}


Box emptyList() {
  
  return null;

}


boolean isEmpty(Box b) {
  
  if ( isNil(b)) {
    return true;

  } else {
    return false;

  }

}


int listLength(Box l) {
  
  if ( isEmpty(l)) {
    return 0;

  } else {
    return add1(listLength(cdr(l)));

  }

}


Box alistCons(Box key, Box value, Box alist) {
  
  return cons(cons(key, value), alist);

}


Box assoc(String searchTerm, Box l) {
  Box elem = null;

  assertType("list", l, 96, "q/lists.qon");

  if ( isEmpty(l)) {
    return boxBool(false);

  } else {
    elem = car(l);

    assertType("list", elem, 102, "q/lists.qon");

    if ( isEmpty(elem)) {
      return assoc(searchTerm, cdr(l));

    } else {
      if ( false) {
        System.out.printf("Comparing %s and %s\n", searchTerm, stringify(car(elem)));

      } else {
        System.out.printf("");

      }

      if ( equalString(searchTerm, stringify(car(elem)))) {
        return elem;

      } else {
        return assoc(searchTerm, cdr(l));

      }

    }

  }

}


String chooseBox(String aType) {
  
  if ( equalString("string", aType)) {
    return "boxString";

  } else {
    if ( equalString("symbol", aType)) {
      return "boxSymbol";

    } else {
      if ( equalString("bool", aType)) {
        return "boxBool";

      } else {
        if ( equalString("int", aType)) {
          return "boxInt";

        } else {
          if ( equalString("float", aType)) {
            return "boxFloat";

          } else {
            panic("Invalid type");

          }

        }

      }

    }

  }

  return "";

}


Box mlistLiteral(Box b) {
  
  if ( isNil(b)) {
    return null;

  } else {
    if ( equalString("string", boxType(b))) {
      return b;

    } else {
      if ( equalString("bool", boxType(b))) {
        return b;

      } else {
        if ( equalString("int", boxType(b))) {
          return b;

        } else {
          if ( equalString("symbol", boxType(b))) {
            return boxString(unBoxSymbol(b));

          } else {
            return boxString(stringConcatenate("Unsupported type in mlistLiteral: ", boxType(b)));

          }

        }

      }

    }

  }

}


Box doMultiList(Box l) {
  Box newlist = null;
Box ret = null;
Box elem = null;

  if ( isNil(l)) {
    return cons(boxSymbol("nil"), null);

  } else {
    if ( isEmpty(l)) {
      return null;

    } else {
      elem = first(l);

      newlist = cons(boxString(chooseBox(elem.typ)), cons(mlistLiteral(first(l)), newlist));

      ret = cons(cons(boxSymbol("cons"), cons(newlist, doMultiList(cdr(l)))), null);

      return ret;

    }

  }

}


boolean isDigit(String val) {
  
  if ( equal(string_length(val), 1)) {
    return stringContains("0123456789", val);

  } else {
    return false;

  }

}


boolean isUnsignedIntFrom(String val, int pos) {
  int len = 0;

  len = string_length(val);

  if ( greaterthan(add1(pos), len)) {
    return true;

  } else {
    if ( isDigit(sub_string(val, pos, 1))) {
      return isUnsignedIntFrom(val, add1(pos));

    } else {
      return false;

    }

  }

}


boolean isInt(String val) {
  int len = 0;
String firstLetter = "";

  len = string_length(val);

  if ( equal(len, 0)) {
    return false;

  } else {
  }

  firstLetter = sub_string(val, 0, 1);

  if ( equalString("-", firstLetter)) {
    if ( equal(len, 1)) {
      return false;

    } else {
      return isUnsignedIntFrom(val, 1);

    }

  } else {
    return isUnsignedIntFrom(val, 0);

  }

}


boolean isFloatFrom(String val, int pos, boolean seenDot, boolean seenDigit, boolean digitAfterDot) {
  int len = 0;
String ch = "";

  len = string_length(val);

  if ( greaterthan(add1(pos), len)) {
    return andBool(seenDot, andBool(seenDigit, digitAfterDot));

  } else {
  }

  ch = sub_string(val, pos, 1);

  if ( isDigit(ch)) {
    return isFloatFrom(val, add1(pos), seenDot, true, orBool(digitAfterDot, seenDot));

  } else {
    if ( equalString(".", ch)) {
      if ( seenDot) {
        return false;

      } else {
        return isFloatFrom(val, add1(pos), true, seenDigit, false);

      }

    } else {
      return false;

    }

  }

}


boolean isFloat(String val) {
  int len = 0;
String firstLetter = "";

  len = string_length(val);

  if ( equal(len, 0)) {
    return false;

  } else {
  }

  firstLetter = sub_string(val, 0, 1);

  if ( equalString("-", firstLetter)) {
    if ( equal(len, 1)) {
      return false;

    } else {
      return isFloatFrom(val, 1, false, false, false);

    }

  } else {
    return isFloatFrom(val, 0, false, false, false);

  }

}


Box id(Box b) {
  
  return b;

}


String chooseBoxInterp(Box b) {
  String val = stringify(b);
String firstLetter = sub_string(val, 0, 1);

  if ( equalString("string", boxType(b))) {
    return "boxString";

  } else {
    if ( equalString("\"", firstLetter)) {
      return "boxString";

    } else {
      if ( equalString("true", val)) {
        return "boxBool";

      } else {
        if ( equalString("false", val)) {
          return "boxBool";

        } else {
          if ( isFloat(val)) {
            return "boxFloat";

          } else {
            if ( isInt(val)) {
              return "boxInt";

            } else {
              return "id";

            }

          }

        }

      }

    }

  }

}


Box doInterpolatedList(Box l) {
  Box newlist = null;
Box ret = null;
Box elem = null;

  if ( isNil(l)) {
    return cons(boxSymbol("nil"), null);

  } else {
    if ( isEmpty(l)) {
      return null;

    } else {
      elem = first(l);

      newlist = cons(boxString(chooseBoxInterp(elem)), cons(first(l), newlist));

      ret = cons(cons(boxSymbol("cons"), cons(newlist, doInterpolatedList(cdr(l)))), null);

      return ret;

    }

  }

}


Box doStringList(Box l) {
  Box newlist = null;
Box ret = null;

  if ( isNil(l)) {
    return cons(boxSymbol("nil"), null);

  } else {
    newlist = cons(boxSymbol("boxString"), cons(first(l), newlist));

    ret = cons(cons(boxSymbol("cons"), cons(newlist, doStringList(cdr(l)))), null);

    return ret;

  }

}


Box doSymbolList(Box l) {
  Box newlist = null;
Box ret = null;

  if ( isNil(l)) {
    return cons(boxSymbol("nil"), null);

  } else {
    newlist = cons(boxSymbol("boxSymbol"), cons(first(l), newlist));

    ret = cons(cons(boxSymbol("cons"), cons(newlist, doSymbolList(cdr(l)))), null);

    return ret;

  }

}


Box doBoxList(Box l) {
  
  if ( isNil(l)) {
    return cons(boxSymbol("nil"), null);

  } else {
    return cons(cons(boxSymbol("cons"), cons(first(l), doBoxList(cdr(l)))), null);

  }

}


Box concatLists(Box seq1, Box seq2) {
  
  if ( isNil(seq1)) {
    return seq2;

  } else {
    return cons(car(seq1), concatLists(cdr(seq1), seq2));

  }

}


Box alistKeys(Box alist) {
  
  if ( isNil(alist)) {
    return null;

  } else {
    return cons(car(car(alist)), alistKeys(cdr(alist)));

  }

}


void display(Box l) {
  
  if ( isEmpty(l)) {
    System.out.printf("nil ");

    return;

  } else {
    if ( isList(l)) {
      System.out.printf("[");

      displayList(l, 0, true);

      System.out.printf("]");

    } else {
      displayList(l, 0, true);

    }

  }

}


void displayList(Box l, int indent, boolean first) {
  Box val = null;

  if ( isEmpty(l)) {
    return;

  } else {
    if ( isList(l)) {
      if ( isEmpty(l)) {
        return;

      } else {
        if ( first) {
        } else {
          System.out.printf(" ");

        }

        val = car(l);

        if ( isList(val)) {
          newLine(indent);

          System.out.printf("%s", openBrace());

          displayList(car(l), add1(indent), true);

          System.out.printf("%s", closeBrace());

          displayList(cdr(l), indent, false);

        } else {
          if ( equalString("string", val.typ)) {
            System.out.printf("\"%s\"", unBoxString(val));

          } else {
            System.out.printf("%s", stringify(val));

          }

          displayList(cdr(l), indent, false);

        }

      }

    } else {
      if ( equalString("string", l.typ)) {
        System.out.printf("\"%s\"", unBoxString(l));

      } else {
        System.out.printf("%s", stringify(l));

      }

    }

  }

}


String StringListJoinRec(Box l, String sep) {
  Box val = null;

  if ( isEmpty(l)) {
    return "";

  } else {
    if ( isList(l)) {
      if ( isEmpty(l)) {
        return "";

      } else {
        if ( equal(listLength(l), 1)) {
          return stringify(car(l));

        } else {
          return stringConcatenate(stringify(car(l)), stringConcatenate(sep, StringListJoinRec(cdr(l), sep)));

        }

      }

    } else {
      return "";

    }

  }

}


String StringListJoin(Box l, String sep) {
  Box val = null;

  if ( greaterthan(listLength(l), 1)) {
    return stringConcatenate(stringify(car(l)), stringConcatenate(sep, StringListJoinRec(cdr(l), sep)));

  } else {
    return stringify(car(l));

  }

}


Box ListToBoxString(Box l, int indent) {
  
  return boxString(ListToString(l, indent, true, false));

}


String ListToString(Box l, int indent, boolean first, boolean withNewLines) {
  Box val = null;

  if ( isEmpty(l)) {
    return "";

  } else {
    if ( isList(l)) {
      if ( isEmpty(l)) {
        return "";

      } else {
        val = car(l);

        if ( isList(val)) {
          return StringListJoin(cons(boxString(stringify(tern(withNewLines, boxString("\n"), boxString(stringIndent(indent))))), cons(boxString(openBrace()), cons(boxString(" "), cons(boxString(ListToString(car(l), add1(indent), true, withNewLines)), cons(boxString(closeBrace()), cons(boxString(" "), cons(boxString(ListToString(cdr(l), indent, false, withNewLines)), null))))))), "");

        } else {
          return stringConcatenate(stringify(val), ListToString(cdr(l), indent, false, withNewLines));

        }

      }

    } else {
      return stringify(l);

    }

  }

}


Box listReverse(Box l) {
  
  if ( isNil(l)) {
    return null;

  } else {
    return cons(car(l), listReverse(cdr(l)));

  }

}


boolean inList(Box item, Box l) {
  
  if ( isNil(l)) {
    return false;

  } else {
    if ( equalBox(car(l), item)) {
      return true;

    } else {
      return inList(item, cdr(l));

    }

  }

}


boolean equalList(Box a, Box b) {
  
  if ( isNil(a)) {
    if ( isNil(b)) {
      return true;

    } else {
      return false;

    }

  } else {
  }

  if ( isNil(b)) {
    if ( isNil(a)) {
      return true;

    } else {
      return false;

    }

  } else {
  }

  if ( equalBox(car(a), car(b))) {
    return equalList(cdr(a), cdr(b));

  } else {
    return false;

  }

}


Box reverseRec(Box oldL, Box newL) {
  
  if ( isEmpty(oldL)) {
    return newL;

  } else {
    return reverseRec(cdr(oldL), cons(first(oldL), newL));

  }

}


Box reverseList(Box l) {
  
  return reverseRec(l, null);

}


Box flatten(Box tree) {
  
  if ( isEmpty(tree)) {
    return emptyList();

  } else {
    if ( isList(car(tree))) {
      return concatLists(flatten(car(tree)), flatten(cdr(tree)));

    } else {
      return cons(car(tree), flatten(cdr(tree)));

    }

  }

}


void printStringTree(Box tree) {
  Box val = null;

  if ( isEmpty(tree)) {
    return;

  } else {
  }

  val = car(tree);

  if ( isList(val)) {
    printStringTree(car(tree));

  } else {
    System.out.printf("%s", stringify(val));

  }

  printStringTree(cdr(tree));

}


Box macrowalk(Box l) {
  
  if ( isEmpty(l)) {
    return null;

  } else {
    if ( isList(l)) {
      if ( equalString(stringConcatenate("box", "List"), stringify(car(l)))) {
        return car(doBoxList(cdr(l)));

      } else {
      }

      if ( equalString(stringConcatenate("string", "List"), stringify(car(l)))) {
        return car(doStringList(cdr(l)));

      } else {
      }

      if ( equalString(stringConcatenate("symbol", "List"), stringify(car(l)))) {
        return car(doSymbolList(cdr(l)));

      } else {
      }

      if ( equalString(stringConcatenate("multi", "List"), stringify(car(l)))) {
        return car(doMultiList(cdr(l)));

      } else {
      }

      if ( equalString(stringConcatenate("makeL", "ist"), stringify(car(l)))) {
        return car(doInterpolatedList(cdr(l)));

      } else {
      }

      return cons(macrowalk(car(l)), macrowalk(cdr(l)));

    } else {
      return l;

    }

  }

}


Box macrosingle(Box tree, String search, String replace) {
  Box val = null;

  if ( isEmpty(tree)) {
    return null;

  } else {
    if ( isList(tree)) {
      return cons(macrosingle(car(tree), search, replace), macrosingle(cdr(tree), search, replace));

    } else {
      if ( equalString(search, stringify(tree))) {
        val = clone(tree);

        val.str = replace;

        return val;

      } else {
      }

      return tree;

    }

  }

}


Box macroSymbolSingle(Box tree, String search, String replace) {
  Box val = null;

  if ( isEmpty(tree)) {
    return null;

  } else {
    if ( isList(tree)) {
      return cons(macroSymbolSingle(car(tree), search, replace), macroSymbolSingle(cdr(tree), search, replace));

    } else {
      if ( equalString("symbol", boxType(tree))) {
        if ( equalString(search, stringify(tree))) {
          val = clone(tree);

          val.str = replace;

          return val;

        } else {
        }

      } else {
      }

      return tree;

    }

  }

}


Box macrolist(Box l, String search, Box replace) {
  Box val = null;

  if ( isEmpty(l)) {
    return null;

  } else {
    if ( isList(l)) {
      if ( equalString(search, stringify(car(l)))) {
        return concatLists(replace, macrolist(cdr(l), search, replace));

      } else {
        return cons(macrolist(car(l), search, replace), macrolist(cdr(l), search, replace));

      }

    } else {
      return l;

    }

  }

}


Box filterVoid(Box l) {
  Box token = null;

  if ( isEmpty(l)) {
    return emptyList();

  } else {
    token = car(l);

    if ( equalString("void", token.typ)) {
      return filterVoid(cdr(l));

    } else {
      return cons(token, filterVoid(cdr(l)));

    }

  }

}


Box filterTokens(Box l) {
  Box token = null;

  if ( isEmpty(l)) {
    return emptyList();

  } else {
    token = car(l);

    if ( equalString(boxType(token), "symbol")) {
      if ( equalString("__LINE__", stringify(token))) {
        return cons(getTagFail(token, boxString("line"), boxInt(-1)), filterTokens(cdr(l)));

      } else {
        if ( equalString("__COLUMN__", stringify(token))) {
          return cons(getTagFail(token, boxString("column"), boxInt(-1)), filterTokens(cdr(l)));

        } else {
          if ( equalString("__FILE__", stringify(token))) {
            return cons(getTagFail(token, boxString("filename"), boxString("Unknown file")), filterTokens(cdr(l)));

          } else {
            return cons(token, filterTokens(cdr(l)));

          }

        }

      }

    } else {
      return cons(token, filterTokens(cdr(l)));

    }

  }

}


Box finish_token(String prog, int start, int len, int line, int column, String filename) {
  Box token = null;

  if ( greaterthan(len, 0)) {
    token = boxSymbol(sub_string(prog, start, len));

    token.tag = alistCons(boxString("filename"), boxString(filename), alistCons(boxString("column"), boxInt(column), alistCons(boxString("line"), boxInt(line), alistCons(boxString("totalCharPos"), boxInt(start), null))));

    return token;

  } else {
    return newVoid();

  }

}


String readString(String prog, int start, int len) {
  String token = "";

  token = sub_string(prog, sub1(add(start, len)), 1);

  if ( equalString("\"", token)) {
    return sub_string(prog, start, sub1(len));

  } else {
    if ( equalString("\\", token)) {
      return readString(prog, start, add(2, len));

    } else {
      return readString(prog, start, add1(len));

    }

  }

}


String readComment(String prog, int start, int len) {
  String token = "";

  if ( greaterthan(add(start, len), string_length(prog))) {
    return "";

  } else {
    token = sub_string(prog, sub1(add(start, len)), 1);

    if ( isLineBreak(token)) {
      return sub_string(prog, start, sub1(len));

    } else {
      return readComment(prog, start, add1(len));

    }

  }

}


boolean isLineBreak(String s) {
  
  if ( equalString("\n", s)) {
    return true;

  } else {
    if ( equalString("\r", s)) {
      return true;

    } else {
      return false;

    }

  }

}


int incForNewLine(Box token, int val) {
  
  if ( equalString("\n", stringify(token))) {
    return add1(val);

  } else {
    return val;

  }

}


Box annotateReadPosition(String filename, int linecount, int column, int start, Box newBox) {
  
  return setTag(boxString("filename"), boxString(filename), setTag(boxString("column"), boxInt(column), setTag(boxString("line"), boxInt(linecount), setTag(boxString("totalCharPos"), boxInt(start), newBox))));

}


Box scan(String prog, int start, int len, int linecount, int column, String filename) {
  Box token = null;
String newString = "";
Box newBox = null;

  if ( greaterthan(string_length(prog), sub1(add(start, len)))) {
    token = boxSymbol(sub_string(prog, sub1(add(start, len)), 1));

    token.tag = alistCons(boxString("totalCharPos"), boxInt(start), null);

    if ( isOpenBrace(token)) {
      return cons(finish_token(prog, start, sub1(len), linecount, column, filename), cons(annotateReadPosition(filename, linecount, column, start, boxSymbol(openBrace())), scan(prog, add1(start), 1, linecount, add1(column), filename)));

    } else {
      if ( isCloseBrace(token)) {
        return cons(finish_token(prog, start, sub1(len), linecount, column, filename), cons(annotateReadPosition(filename, linecount, column, start, boxSymbol(closeBrace())), scan(prog, add(start, len), 1, linecount, add1(column), filename)));

      } else {
        if ( isWhiteSpace(stringify(token))) {
          return cons(finish_token(prog, start, sub1(len), linecount, column, filename), scan(prog, add(start, len), 1, incForNewLine(token, linecount), 0, filename));

        } else {
          if ( equalBox(boxSymbol(";"), token)) {
            return scan(prog, add(start, add1(add1(string_length(readComment(prog, add1(start), len))))), 1, add1(linecount), 0, filename);

          } else {
            if ( equalBox(boxSymbol("\""), token)) {
              newString = readString(prog, add1(start), len);

              newBox = annotateReadPosition(filename, linecount, column, start, boxString(newString));

              return cons(newBox, scan(prog, add(start, add1(add1(string_length(newString)))), 1, linecount, add1(column), filename));

            } else {
              return scan(prog, start, sub(len, -1), linecount, add1(column), filename);

            }

          }

        }

      }

    }

  } else {
    return emptyList();

  }

}


boolean isOpenBrace(Box b) {
  
  if ( equalBox(boxSymbol(openBrace()), b)) {
    return true;

  } else {
    return false;

  }

}


boolean isCloseBrace(Box b) {
  
  if ( equalBox(boxSymbol(closeBrace()), b)) {
    return true;

  } else {
    return false;

  }

}


Box skipList(Box l) {
  Box b = null;

  if ( isEmpty(l)) {
    return emptyList();

  } else {
    b = car(l);

    if ( isOpenBrace(b)) {
      return skipList(skipList(cdr(l)));

    } else {
      if ( isCloseBrace(b)) {
        return cdr(l);

      } else {
        return skipList(cdr(l));

      }

    }

  }

}


int add(int a, int b) {
  
  return sub(a, sub(0, b));

}


double addf(double a, double b) {
  
  return subf(a, subf(0, b));

}


int sub1(int a) {
  
  return sub(a, 1);

}


int add1(int a) {
  
  return add(a, 1);

}


Box clone(Box b) {
  Box newb = null;

  newb = makeBox();

  if ( isNil(newb)) {
    System.out.printf("clone: newb is nil\n");

    panic("clone: newb is nil");

    return newb;

  } else {
    newb.typ = b.typ;

    newb.voi = b.voi;

    newb.boo = b.boo;

    newb.tag = b.tag;

    newb.lis = b.lis;

    newb.str = b.str;

    newb.i = b.i;

    newb.f = b.f;

    newb.lengt = b.lengt;

    newb.car = b.car;

    newb.cdr = b.cdr;

    return newb;

  }

}


Box tern(boolean cond, Box tr, Box fal) {
  
  if ( cond) {
    return tr;

  } else {
    return fal;

  }

}


String ternString(boolean cond, String tr, String fal) {
  
  if ( cond) {
    return tr;

  } else {
    return fal;

  }

}


Box ternList(boolean cond, Box tr, Box fal) {
  
  if ( cond) {
    return tr;

  } else {
    return fal;

  }

}


Box newVoid() {
  Box newb = null;

  newb = makeBox();

  newb.voi = true;

  newb.typ = "void";

  return newb;

}


void stackDump() {
  
  System.out.printf("");

}


void nop() {
  
  System.out.printf("");

}


boolean equalBox(Box a, Box b) {
  
  if ( isList(b)) {
    return false;

  } else {
    if ( equalString("string", boxType(a))) {
      return equalString(unBoxString(a), stringify(b));

    } else {
      if ( equalString("bool", boxType(a))) {
        return andBool(unBoxBool(a), unBoxBool(b));

      } else {
        if ( equalString("symbol", boxType(a))) {
          if ( equalString("symbol", boxType(b))) {
            return equalString(unBoxSymbol(a), unBoxSymbol(b));

          } else {
            return false;

          }

        } else {
          if ( equalString("int", boxType(a))) {
            return equal(unBoxInt(a), unBoxInt(b));

          } else {
            if ( equalString("float", boxType(a))) {
              if ( equalString("float", boxType(b))) {
                return equalf(unBoxFloat(a), unBoxFloat(b));

              } else {
                return false;

              }

            } else {
              return false;

            }

          }

        }

      }

    }

  }

}


String openBrace() {
  
  return "(";

}


String closeBrace() {
  
  return ")";

}


String boxType(Box b) {
  
  return b.typ;

}


Box makeBox() {
  Box b = null;

  b = new Box();

  if ( isNil(b)) {
    panic("failed to create box!");

  } else {
  }

  b.tag = null;

  b.car = null;

  b.cdr = null;

  b.lis = null;

  b.typ = "None - error!";

  return b;

}


Box makePair() {
  
  return makeBox();

}


Box boxString(String s) {
  Box b = null;

  b = makeBox();

  b.str = s;

  b.lengt = string_length(s);

  b.typ = "string";

  return b;

}


Box boxSymbol(String s) {
  Box b = null;

  b = boxString(s);

  b.typ = "symbol";

  return b;

}


Box boxBool(boolean boo) {
  Box b = null;

  b = makeBox();

  b.boo = boo;

  b.typ = "bool";

  return b;

}


Box boxInt(int val) {
  Box b = null;

  b = makeBox();

  b.i = val;

  b.typ = "int";

  return b;

}


Box boxFloat(double val) {
  Box b = null;

  b = makeBox();

  b.f = val;

  b.typ = "float";

  return b;

}


void assertType(String atype, Box abox, int line, String file) {
  
  if ( isNil(abox)) {
    if ( equalString(atype, "nil")) {
      return;

    } else {
      return;

    }

  } else {
    if ( equalString(atype, boxType(abox))) {
      return;

    } else {
      System.out.printf("Assertion failure at line %d, in file %s: provided value is not a '%s'!  It was actually '%s'. Contents:", line, file, atype, boxType(abox));

      display(abox);

      System.out.printf("\n");

      display(cons(boxString("Token may have been read from "), cons(boxString(stringify(getTagFail(abox, boxString("filename"), boxString("source file not found")))), cons(boxString(":"), cons(boxString(stringify(getTagFail(abox, boxString("line"), boxString("source line not found")))), null)))));

      StackTracePrint();

      panic("Invalid type!");

    }

  }

}


String unBoxString(Box b) {
  
  assertType("string", b, 199, "q/base.qon");

  return b.str;

}


String unBoxSymbol(Box b) {
  
  return b.str;

}


boolean unBoxBool(Box b) {
  
  return b.boo;

}


int unBoxInt(Box b) {
  
  return b.i;

}


double unBoxFloat(Box b) {
  
  return b.f;

}


String stringify_rec(Box b) {
  
  if ( isNil(b)) {
    return "";

  } else {
    return stringConcatenate(stringify(car(b)), stringConcatenate(" ", stringify_rec(cdr(b))));

  }

}


String stringify(Box b) {
  
  if ( isNil(b)) {
    return "()";

  } else {
    if ( equalString("string", boxType(b))) {
      return unBoxString(b);

    } else {
      if ( equalString("bool", boxType(b))) {
        if ( unBoxBool(b)) {
          return "true";

        } else {
          return "false";

        }

      } else {
        if ( equalString("int", boxType(b))) {
          return intToString(unBoxInt(b));

        } else {
          if ( equalString("float", boxType(b))) {
            return floatToString(unBoxFloat(b));

          } else {
            if ( equalString("symbol", boxType(b))) {
              return unBoxSymbol(b);

            } else {
              if ( equalString("list", boxType(b))) {
                return stringConcatenate("(", stringConcatenate(stringify(car(b)), stringConcatenate(" ", stringConcatenate(stringify_rec(cdr(b)), ")"))));

              } else {
                return stringConcatenate("Unsupported type in stringify: ", boxType(b));

              }

            }

          }

        }

      }

    }

  }

}


boolean hasTag(Box aBox, Box key) {
  
  if ( isNil(aBox)) {
    return false;

  } else {
    return isNotFalse(assoc(stringify(key), aBox.tag));

  }

}


Box getTag(Box aBox, Box key) {
  
  if ( false) {
    System.out.printf("Getting %s from: ", stringify(key));

    display(alistKeys(aBox.tag));

    System.out.printf("\n");

  } else {
    System.out.printf("");

  }

  return cdr(assoc(stringify(key), aBox.tag));

}


Box getTagFail(Box aBox, Box key, Box onFail) {
  
  if ( hasTag(aBox, key)) {
    return getTag(aBox, key);

  } else {
    return onFail;

  }

}


boolean assocExists(String key, Box aBox) {
  
  if ( isNil(aBox)) {
    return false;

  } else {
    return isNotFalse(assoc(key, aBox));

  }

}


Box assocFail(String key, Box aBox, Box onFail) {
  
  if ( assocExists(key, aBox)) {
    return assoc(key, aBox);

  } else {
    return cons(boxString(key), onFail);

  }

}


Box assocPanic(String key, Box aBox, String onFail) {
  
  if ( assocExists(key, aBox)) {
    return assoc(key, aBox);

  } else {
    panic(onFail);

  }

  panic("Inconceivable");

  return null;

}


Box setTag(Box key, Box val, Box aStruct) {
  
  aStruct.tag = alistCons(key, val, aStruct.tag);

  return aStruct;

}


void locPanic(String file, String line, String message) {
  
  System.out.printf("%s %s:%s\n", file, line, message);

  panic(message);

}


boolean truthy(Box aVal) {
  
  return isNotFalse(aVal);

}


boolean isNotFalse(Box aVal) {
  
  if ( equalString(boxType(aVal), "bool")) {
    if ( unBoxBool(aVal)) {
      return true;

    } else {
      return false;

    }

  } else {
    return true;

  }

}


Box toStr(Box thing) {
  
  return boxString(stringify(thing));

}


Box listLast(Box alist) {
  
  if ( isEmpty(cdr(alist))) {
    return car(alist);

  } else {
    return listLast(cdr(alist));

  }

}


void newLine(int indent) {
  
  System.out.printf("\n");

  printIndent(indent);

}


void printIndent(int ii) {
  
  if ( greaterthan(ii, 0)) {
    System.out.printf("  ");

    printIndent(sub1(ii));

  } else {
    return;

  }

}


String stringIndent(int ii) {
  
  if ( greaterthan(ii, 0)) {
    return stringConcatenate("  ", stringIndent(sub1(ii)));

  } else {
    return "";

  }

}


Box listIndent(int ii) {
  
  return cons(id(boxString(stringIndent(ii))), null);

}


Box listNewLine(int ii) {
  
  return cons(id(boxString(stringConcatenate("\n", stringIndent(ii)))), null);

}


Box argList(int count, int pos, String[] args) {
  
  if ( greaterthan(count, pos)) {
    return cons(boxString(getStringArray(pos, args)), argList(count, add1(pos), args));

  } else {
    return null;

  }

}


void tron() {
  
  globalTrace = true;

}


void troff() {
  
  globalTrace = false;

}


void stron() {
  
  globalStepTrace = true;

}


void stroff() {
  
  globalStepTrace = false;

}


void StackTraceMove(String direction, String filename, String fname, String line) {
  
  if ( equalString(direction, "in")) {
    globalStackTrace = cons(cons(boxString(filename), cons(boxString(line), cons(boxString(fname), null))), globalStackTrace);

  } else {
    globalStackTrace = cdr(globalStackTrace);

  }

}


void StackTracePrint() {
  
  System.out.printf("Stack trace:\n");

  if ( isNil(globalStackTrace)) {
    System.out.printf("  <empty>\n");

  } else {
    StackTracePrintHelper(globalStackTrace);

  }

}


void StackTracePrintHelper(Box stack) {
  String file = stringify(first(car(stack)));
String line = "";
String func = "";

  if ( isNil(stack)) {
    System.out.printf("  <end>\n");

    return;

  } else {
    file = stringify(first(car(stack)));

    line = stringify(second(car(stack)));

    func = stringify(third(first(stack)));

    System.out.printf("  %s:%s %s\n", file, line, func);

    StackTracePrintHelper(cdr(stack));

  }

}


Box NoStackTrace_list() {
  
  return cons(boxString("StackTraceMove"), cons(boxString("StackTracePrint"), cons(boxString("StackTracePrintHelper"), cons(boxString("NoStackTrace_list"), cons(boxString("car"), cons(boxString("cdr"), cons(boxString("cons"), cons(boxString("set"), cons(boxString("boxString"), cons(boxString("makePair"), cons(boxString("set-struct"), cons(boxString("display"), cons(boxString("list"), cons(boxString("assertType"), cons(boxString("isEmpty"), cons(boxString("isNil"), cons(boxString("get-struct"), cons(boxString("equalString"), cons(boxString("binop"), cons(boxString("strcmp"), cons(boxString("main"), cons(boxString("makeBox"), cons(boxString("string_length"), cons(boxString("boxType"), cons(boxString("displayList"), cons(boxString("newLine"), cons(boxString("panic"), null)))))))))))))))))))))))))));

}


Box NoTrace_list() {
  
  return cons(boxString("StackTraceMove"), cons(boxString("StackTracePrint"), cons(boxString("StackTracePrintHelper"), cons(boxString("NoStackTrace_list"), cons(boxString("car"), cons(boxString("cdr"), cons(boxString("cons"), cons(boxString("set"), cons(boxString("boxString"), cons(boxString("makePair"), cons(boxString("set-struct"), cons(boxString("display"), cons(boxString("list"), cons(boxString("assertType"), cons(boxString("isEmpty"), cons(boxString("isNil"), cons(boxString("get-struct"), cons(boxString("equalString"), cons(boxString("binop"), cons(boxString("strcmp"), cons(boxString("main"), cons(boxString("makeBox"), cons(boxString("string_length"), cons(boxString("boxType"), cons(boxString("displayList"), cons(boxString("newLine"), cons(boxString("panic"), cons(boxString("boxString"), cons(boxString("boxSymbol"), cons(boxString("boxType"), cons(boxString("equalString"), cons(boxString("unBoxSymbol"), cons(boxString("isList"), cons(boxString("makeBox"), cons(boxString("equalBox"), cons(boxString("sub"), cons(boxString("sub1"), cons(boxString("stringify"), cons(boxString("add"), cons(boxString("greaterthan"), null))))))))))))))))))))))))))))))))))))))));

}


int indexOfHelper(String haystack, String needle, int start, int current) {
  
  if ( greaterthan(add(current, string_length(needle)), string_length(haystack))) {
    return -1;

  } else {
    if ( equalString(sub_string(haystack, current, string_length(needle)), needle)) {
      return current;

    } else {
      return indexOfHelper(haystack, needle, start, add1(current));

    }

  }

}


int indexOf(String haystack, String needle, int start) {
  
  if ( equal(string_length(needle), 0)) {
    return start;

  } else {
    return indexOfHelper(haystack, needle, start, start);

  }

}


String stringReplace(String oldValue, String newValue, String s) {
  int pos = 0;

  pos = indexOf(s, oldValue, 0);

  if ( equal(pos, -1)) {
    return s;

  } else {
    return stringConcatenate(sub_string(s, 0, pos), stringConcatenate(newValue, stringReplace(oldValue, newValue, sub_string(s, add(pos, string_length(oldValue)), sub(string_length(s), add(pos, string_length(oldValue)))))));

  }

}


boolean stringContains(String haystack, String needle) {
  int haystackLength = 0;
int needleLength = 0;

  haystackLength = string_length(haystack);

  needleLength = string_length(needle);

  if ( greaterthan(needleLength, haystackLength)) {
    return false;

  } else {
    return stringContainsHelper(haystack, needle, 0);

  }

}


boolean stringContainsHelper(String haystack, String needle, int startIndex) {
  int haystackLength = 0;
int needleLength = 0;

  haystackLength = string_length(haystack);

  needleLength = string_length(needle);

  if ( greaterthan(add(startIndex, needleLength), haystackLength)) {
    return false;

  } else {
    if ( equalString(sub_string(haystack, startIndex, needleLength), needle)) {
      return true;

    } else {
      return stringContainsHelper(haystack, needle, add(startIndex, 1));

    }

  }

}


boolean isWhiteSpace(String s) {
  
  if ( equalString(" ", s)) {
    return true;

  } else {
    if ( equalString("\t", s)) {
      return true;

    } else {
      if ( equalString("\n", s)) {
        return true;

      } else {
        if ( equalString("\r", s)) {
          return true;

        } else {
          return false;

        }

      }

    }

  }

}


String stringTrim(String s) {
  
  if ( equal(string_length(s), 0)) {
    return "";

  } else {
    if ( isWhiteSpace(sub_string(s, 0, 1))) {
      return stringTrim(sub_string(s, 1, sub1(string_length(s))));

    } else {
      if ( isWhiteSpace(sub_string(s, sub(string_length(s), 1), 1))) {
        return stringTrim(sub_string(s, 0, sub(string_length(s), 1)));

      } else {
        return s;

      }

    }

  }

}


Box stringSplit(String s, String delimiter) {
  int end = 0;
int delimiterLength = 0;

  System.out.printf("Entering stringSplit with s: %.20s..., delimiter: %s\n", s, delimiter);

  delimiterLength = string_length(delimiter);

  end = indexOf(s, delimiter, 0);

  if ( equal(end, -1)) {
    System.out.printf("No delimiter found in stringSplit\n");

    return cons(boxString(s), null);

  } else {
    System.out.printf("Splitting string in stringSplit\n");

    return cons(boxString(sub_string(s, 0, end)), stringSplit(sub_string(s, add(end, delimiterLength), sub(string_length(s), add(end, delimiterLength))), delimiter));

  }

}


boolean isNil(Box a) {
  
  return a == null;

}


String getEnv(String key) {
  
  return System.getenv(key);

}


void panic(String s) {
  
  throw new RuntimeException(s);

}


int sub(int a, int b) {
  
  return (a - b);

}


int mult(int a, int b) {
  
  return (a * b);

}


boolean greaterthan(int a, int b) {
  
  return (a > b);

}


double subf(double a, double b) {
  
  return (a - b);

}


double multf(double a, double b) {
  
  return (a * b);

}


boolean greaterthanf(double a, double b) {
  
  return (a > b);

}


boolean equalf(double a, double b) {
  
  return (a == b);

}


boolean equal(int a, int b) {
  
  return (a == b);

}


boolean equalString(String a, String b) {
  
  return a.equals(b);

}


int string_length(String s) {
  
  return s.length();

}


String setSubString(String target, int start, String source) {
  
  return target.substring(0, start) + source + target.substring(start + 1);

}


String sub_string(String s, int start, int length) {
  
  return s.substring(start, start + length);

}


String stringConcatenate(String a, String b) {
  
  return (a + b);

}


String intToString(int a) {
  
  return Integer.toString(a);

}


String floatToString(double a) {
  
  return Double.toString(a);

}


Box read_file(String filename) {
  
  return readFileBox(filename);

}


void write_file(String filename, String data) {
  
  writeFileUnchecked(filename, data);

}


String getStringArray(int index, String[] strs) {
  
  return strs[index];

}


String[] programArgs() {
  
  return globalArgs;

}


int programArgsCount() {
  
  return globalArgsCount;

}


String character(int num) {
  
  return Character.toString((char) num);

}


void displays(String s) {
  
  System.out.printf("%s", s);

}


int remainder(int a, int b) {
  
  return (a % b);

}


boolean or(boolean a, boolean b) {
  
  return (a || b);

}


int max(int a, int b) {
  
  if ( greaterthan(a, b)) {
    return a;

  } else {
    return b;

  }

}


int min(int a, int b) {
  
  if ( greaterthan(a, b)) {
    return b;

  } else {
    return a;

  }

}


HashMap<String, String> makeHash() {
  
  return new HashMap<String, String>();

}


void setHash(HashMap<String, String> hash, String key, String value) {
  
  hash.put(key, value);

}


String getHash(HashMap<String, String> hash, String key) {
  
  return hash.get(key);

}


boolean inHash(HashMap<String, String> hash, String key) {
  
  return hash.containsKey(key);

}


Box makeArray(int length) {
  
  return new Box();

}


void setArray(Box array, int index, String value) {
  
  panic("setArray is not implemented for Java yet");

}


String getArray(Box array, int index) {
  
  panic("getArray is not implemented for Java yet");

  return "";

}


int start() {
  boolean runTests = false;
Box cmdLine = null;
Box filenameBox = null;
String filename = "";
boolean runPerl = false;
boolean runJava = false;
boolean runNode = false;
boolean runNode2 = false;
boolean runHaskell = false;
boolean runAnsi3 = false;
boolean runTree = false;

  cmdLine = listReverse(argList(globalArgsCount, 0, globalArgs));

  if ( greaterthan(listLength(cmdLine), 1)) {
    filenameBox = second(cmdLine);

  } else {
    filenameBox = boxString("compiler.qon");

  }

  filename = unBoxString(filenameBox);

  releaseMode = inList(boxString("--release"), cmdLine);

  runTests = inList(boxString("--test"), cmdLine);

  runJava = inList(boxString("--java"), cmdLine);

  runPerl = inList(boxString("--perl"), cmdLine);

  runTree = inList(boxString("--tree"), cmdLine);

  runNode = inList(boxString("--node"), cmdLine);

  runNode2 = inList(boxString("--node2"), cmdLine);

  runHaskell = orBool(inList(boxString("--haskell"), cmdLine), inList(boxString("--hs"), cmdLine));

  runAnsi3 = inList(boxString("--ansi3"), cmdLine);

  globalTrace = inList(boxString("--trace"), cmdLine);

  globalStepTrace = inList(boxString("--steptrace"), cmdLine);

  if ( orBool(inList(boxString("--help"), cmdLine), inList(boxString("-h"), cmdLine))) {
    System.out.printf("Usage: quon file [options]\n\nNote the options go after the file name\n");

    System.out.printf("Options:\n");

    System.out.printf("  -h, --help  Display this help\n");

    System.out.printf("  --release   Compile in release mode\n");

    System.out.printf("  --test      Run the test suite\n");

    System.out.printf("  --java      Compile to Java\n");

    System.out.printf("  --perl      Compile to Perl\n");

    System.out.printf("  --tree      Compile to an s-expression tree\n");

    System.out.printf("  --node      Compile to Node.js\n");

    System.out.printf("  --node2      Compile to Node.js, new outputter\n");

    System.out.printf("  --haskell, --hs Compile to Haskell\n");

    System.out.printf("  --ansi3     Compile to ANSI C (quon version 3)\n");

    System.out.printf("  --trace     Trace execution\n");

    System.out.printf("  --steptrace Step trace execution\n");

    exit(0);

  } else {
  }

  if ( runTests) {
    test0();

    test1();

    test2();

    test3();

    test4();

    test5();

    test6();

    test7();

    test8();

    test9();

    test10();

    test12();

    test13();

    test14();

    test15();

    test16();

    test17();

    test18();

    test19();

    test20();

    test21();

    test22();

    test23();

    test24();

    test25();

    test27();

    test28();

    System.out.printf("\n\nAfter all that hard work, I need a beer...\n");

    beers(9);

  } else {
    if ( runTree) {
      display(macrowalk(loadQuon(filename)));

    } else {
      if ( orBool(runNode, runNode2)) {
        node2Compile(filename);

        System.out.printf("\n");

      } else {
        if ( runHaskell) {
          haskellCompile(filename);

          System.out.printf("\n");

        } else {
          if ( runPerl) {
            perlCompile(filename);

            System.out.printf("\n");

          } else {
            if ( runJava) {
              javaCompile(filename);

              System.out.printf("\n");

            } else {
              if ( runAnsi3) {
                ansi3Compile(filename);

                System.out.printf("\n");

              } else {
                ansi3Compile(filename);

                System.out.printf("\n");

              }

            }

          }

        }

      }

    }

  }

  return 0;

}

public static void main(String[] args) {
  QuonProgram program = new QuonProgram();
  program.globalArgs = new String[args.length + 1];
  program.globalArgs[0] = "fixmeprogname";
  System.arraycopy(args, 0, program.globalArgs, 1, args.length);
  program.globalArgsCount = program.globalArgs.length;
  program.start();
}
}


