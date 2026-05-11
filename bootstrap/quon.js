"use strict";
const fs = require("fs");
let globalArgsCount = 0;
let globalArgs = [];
let releaseMode = false;
let globalTrace = false;
let globalStepTrace = false;
let globalStackTrace = null;
let caller = "";
let stderr = process.stderr;
function cformat(fmt, ...args) {
  fmt = String(fmt);
  let out = '';
  let argi = 0;
  for (let pos = 0; pos < fmt.length; pos++) {
    let ch = fmt[pos];
    if (ch !== '%') { out += ch; continue; }
    if (fmt[pos + 1] === '%') { out += '%'; pos++; continue; }
    let precision = null;
    if (fmt[pos + 1] === '.') {
      let end = pos + 2;
      while (end < fmt.length && fmt[end] >= '0' && fmt[end] <= '9') end++;
      precision = Number(fmt.slice(pos + 2, end));
      pos = end - 1;
    }
    let spec = fmt[pos + 1];
    if (spec === 's' || spec === 'd') {
      let value = String(args[argi++]);
      if (precision !== null) value = value.slice(0, precision);
      out += value;
      pos++;
    } else {
      out += ch;
    }
  }
  return out;
}
function printf(fmt, ...args) { process.stdout.write(cformat(fmt, ...args)); }
function fprintf(stream, fmt, ...args) { stream.write(cformat(fmt, ...args)); }


function notBool(a) {
  
  if (a) {
    return false;

  } else {
    return true;

  };

}


function andBool(a, b) {
  
  if (a) {
    if (b) {
      return true;

    } else {
      return false;

    };

  } else {
    return false;

  };

}


function orBool(a, b) {
  
  if (a) {
    return true;

  } else {
    if (b) {
      return true;

    } else {
      return false;

    };

  };

}


function nand(a, b) {
  
  return notBool(andBool(a, b));

}


function xor(a, b) {
  
  return nand(nand(a, nand(a, b)), nand(b, nand(a, b)));

}


function lessThan(a, b) {
  
  return andBool(notBool(equal(a, b)), notBool(greaterthan(a, b)));

}


function node2FunctionArgs(tree) {
  
  if (isEmpty(tree)) {
    return emptyList();

  } else {
    if (equalString(stringify(first(tree)), "...")) {
      if (isNil(cddr(tree))) {
        return cons(boxString("..."), null);

      } else {
        return cons(boxString("..."), cons(boxString(", "), cons(id(node2FunctionArgs(cddr(tree))), null)));

      };

    } else {
      if (isNil(cddr(tree))) {
        return cons(id(node2FuncMap(second(tree))), null);

      } else {
        return cons(id(node2FuncMap(second(tree))), cons(boxString(", "), cons(id(node2FunctionArgs(cddr(tree))), null)));

      };

    };

  };

}


function node2Atom(tree) {
  
  if (equalString("string", boxType(tree))) {
    return cons(boxString("\""), cons(id(boxString(stringify(tree))), cons(boxString("\""), null)));

  } else {
    return cons(id(node2FuncMap(tree)), null);

  };

}


function node2Expression(tree, indent) {
    let thing = null;

  if (notBool(isList(tree))) {
    return node2Atom(tree);

  } else {
    if (equal(1, listLength(tree))) {
      if (equalBox(boxString("return"), car(tree))) {
        return cons(id(node2FuncMap(car(tree))), null);

      } else {
        return cons(id(node2FuncMap(car(tree))), cons(boxString("()"), null));

      };

    } else {
      thing = first(tree);

      if (equalBox(boxSymbol("get-struct"), thing)) {
        return cons(id(node2Expression(second(tree), indent)), cons(boxString("."), cons(id(third(tree)), null)));

      } else {
        if (equalBox(boxSymbol("new"), thing)) {
          return cons(boxString("{}"), null);

        } else {
          if (equalBox(boxSymbol("passthrough"), thing)) {
            return cons(id(second(tree)), null);

          } else {
            if (equalBox(boxSymbol("binop"), thing)) {
              return cons(boxString("("), cons(id(node2Expression(third(tree), indent)), cons(boxString(" "), cons(id(second(tree)), cons(boxString(" "), cons(id(node2Expression(fourth(tree), indent)), cons(boxString(")"), null)))))));

            } else {
              return cons(id(node2FuncMap(car(tree))), cons(boxString("("), cons(id(node2RecurList(cdr(tree), indent)), cons(boxString(")"), null))));

            };

          };

        };

      };

    };

  };

}


function node2RecurList(expr, indent) {
  
  if (isEmpty(expr)) {
    return emptyList();

  } else {
    if (isNil(cdr(expr))) {
      return node2Expression(car(expr), indent);

    } else {
      return cons(id(node2Expression(car(expr), indent)), cons(boxString(", "), cons(id(node2RecurList(cdr(expr), indent)), null)));

    };

  };

}


function node2If(node, indent, functionName) {
  
  return cons(id(listNewLine(indent)), cons(boxString("if ("), cons(id(node2Expression(second(node), 0)), cons(boxString(") {"), cons(id(node2Body(cdr(third(node)), add1(indent), functionName)), cons(id(listNewLine(indent)), cons(boxString("} else {"), cons(id(node2Body(cdr(fourth(node)), add1(indent), functionName)), cons(id(listNewLine(indent)), cons(boxString("}"), null))))))))));

}


function node2SetStruct(node, indent) {
  
  return cons(id(listNewLine(indent)), cons(id(node2Expression(second(node), indent)), cons(boxString("."), cons(id(third(node)), cons(boxString(" = "), cons(id(node2Expression(fourth(node), indent)), null))))));

}


function node2Set(node, indent) {
  
  return cons(id(listNewLine(indent)), cons(id(node2Expression(second(node), indent)), cons(boxString(" = "), cons(id(node2Expression(third(node), indent)), null))));

}


function node2Return(node, indent) {
  
  if (equal(listLength(node), 1)) {
    return cons(id(listNewLine(indent)), cons(boxString("return"), null));

  } else {
    return cons(id(listNewLine(indent)), cons(boxString("return "), cons(id(node2Expression(cadr(node), indent)), null)));

  };

}


function node2Statement(node, indent, functionName) {
  
  if (equalBox(boxString("set"), first(node))) {
    return cons(id(node2Set(node, indent)), cons(boxString(";\n"), null));

  } else {
    if (equalBox(boxString("set-struct"), first(node))) {
      return cons(id(node2SetStruct(node, indent)), cons(boxString(";\n"), null));

    } else {
      if (equalBox(boxString("if"), first(node))) {
        return cons(id(node2If(node, indent, functionName)), cons(boxString(";\n"), null));

      } else {
        if (equalBox(boxString("return"), first(node))) {
          return cons(id(node2Return(node, indent)), cons(boxString(";\n"), null));

        } else {
          return cons(id(listNewLine(indent)), cons(id(node2Expression(node, indent)), cons(boxString(";\n"), null)));

        };

      };

    };

  };

}


function node2Body(tree, indent, functionName) {
    let code = null;

  if (isEmpty(tree)) {
    return emptyList();

  } else {
    code = car(tree);

    return cons(id(node2Statement(code, indent, functionName)), cons(id(node2Body(cdr(tree), indent, functionName)), null));

  };

}


function node2Declarations(decls, indent) {
    let decl = null;

  if (isEmpty(decls)) {
    return emptyList();

  } else {
    decl = car(decls);

    return cons(id(boxString(stringIndent(indent))), cons(boxString("let "), cons(id(node2FuncMap(second(decl))), cons(boxString(" = "), cons(id(node2Expression(third(decl), indent)), cons(boxString(";\n"), cons(id(node2Declarations(cdr(decls), indent)), null)))))));

  };

}


function node2Function(node) {
    let name = null;

  name = second(node);

  if (isNil(node)) {
    return emptyList();

  } else {
    return cons(id(listNewLine(0)), cons(id(listNewLine(0)), cons(boxString("function "), cons(id(node2FuncMap(second(node))), cons(boxString("("), cons(id(node2FunctionArgs(third(node))), cons(boxString(") {"), cons(id(listNewLine(1)), cons(id(node2Declarations(cdr(fourth(node)), 1)), cons(id(node2Body(cdr(fifth(node)), 1, stringify(name))), cons(boxString("\n}\n"), null)))))))))));

  };

}


function node2Functions(tree) {
  
  if (isEmpty(tree)) {
    return emptyList();

  } else {
    return cons(id(node2Function(car(tree))), cons(id(node2Functions(cdr(tree))), null));

  };

}


function node2Includes(nodes) {
  
  return cons(boxString("\"use strict\";\n"), cons(boxString("const fs = require(\"fs\");\n"), cons(boxString("let globalArgsCount = 0;\n"), cons(boxString("let globalArgs = [];\n"), cons(boxString("let releaseMode = false;\n"), cons(boxString("let globalTrace = false;\n"), cons(boxString("let globalStepTrace = false;\n"), cons(boxString("let globalStackTrace = null;\n"), cons(boxString("let caller = \"\";\n"), cons(boxString("let stderr = process.stderr;\n"), cons(boxString("function cformat(fmt, ...args) {\n"), cons(boxString("  fmt = String(fmt);\n"), cons(boxString("  let out = '';\n"), cons(boxString("  let argi = 0;\n"), cons(boxString("  for (let pos = 0; pos < fmt.length; pos++) {\n"), cons(boxString("    let ch = fmt[pos];\n"), cons(boxString("    if (ch !== '%') { out += ch; continue; }\n"), cons(boxString("    if (fmt[pos + 1] === '%') { out += '%'; pos++; continue; }\n"), cons(boxString("    let precision = null;\n"), cons(boxString("    if (fmt[pos + 1] === '.') {\n"), cons(boxString("      let end = pos + 2;\n"), cons(boxString("      while (end < fmt.length && fmt[end] >= '0' && fmt[end] <= '9') end++;\n"), cons(boxString("      precision = Number(fmt.slice(pos + 2, end));\n"), cons(boxString("      pos = end - 1;\n"), cons(boxString("    }\n"), cons(boxString("    let spec = fmt[pos + 1];\n"), cons(boxString("    if (spec === 's' || spec === 'd') {\n"), cons(boxString("      let value = String(args[argi++]);\n"), cons(boxString("      if (precision !== null) value = value.slice(0, precision);\n"), cons(boxString("      out += value;\n"), cons(boxString("      pos++;\n"), cons(boxString("    } else {\n"), cons(boxString("      out += ch;\n"), cons(boxString("    }\n"), cons(boxString("  }\n"), cons(boxString("  return out;\n"), cons(boxString("}\n"), cons(boxString("function printf(fmt, ...args) { process.stdout.write(cformat(fmt, ...args)); }\n"), cons(boxString("function fprintf(stream, fmt, ...args) { stream.write(cformat(fmt, ...args)); }\n"), null)))))))))))))))))))))))))))))))))))))));

}


function node2Types(nodes) {
  
  return emptyList();

}


function node2FuncMap(aSym) {
    let symMap = null;

  if (equalString("symbol", boxType(aSym))) {
    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("new"), boxSymbol("new_"), alistCons(boxSymbol("nil"), boxSymbol("null"), null))))))));

    if (truthy(assoc(stringify(aSym), symMap))) {
      return cdr(assoc(stringify(aSym), symMap));

    } else {
      return aSym;

    };

  } else {
    return aSym;

  };

}


function node2MainEntry() {
  
  return cons(boxString("\n// Main entry point\n"), cons(boxString("globalArgs = [\"fixmeprogname\", ...process.argv.slice(2)];\n"), cons(boxString("globalArgsCount = globalArgs.length;\n"), cons(boxString("start();\n"), null))));

}


function node2LoadProgram(filename) {
    let tree = null;
  let replace = null;

  tree = loadQuon(filename);

  tree = insertInclude(tree, "q/shims/node2.qon");

  tree = loadIncludes(tree, null);

  tree = macrowalk(tree);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), null));

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

  return tree;

}


function node2ProgramTree(tree) {
  
  return cons(id(node2Includes(cdr(first(tree)))), cons(id(node2Types(cdr(second(tree)))), cons(id(node2Functions(cdr(third(tree)))), cons(id(node2MainEntry()), cons(boxString("\n"), null)))));

}


function node2Program(tree) {
  
  return ListToString(flatten(node2ProgramTree(tree)), 0, true, false);

}


function node2CompileString(filename) {
  
  return node2Program(node2LoadProgram(filename));

}


function node2Compile(filename) {
    let tree = null;
  let replace = null;

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


function test0() {
  
  if (equalString(stringify(boxString("hello")), stringify(boxString("hello")))) {
    printf("0.  pass string compare works\n");

  } else {
    printf("0.  pass string compare fails\n");

  };

  if (equalString(stringify(boxString("hello")), stringify(boxSymbol("hello")))) {
    printf("0.  pass string compare works\n");

  } else {
    printf("0.  pass string compare fails\n");

  };

}


function test1() {
  
  printf("1.  pass Function call and print work\n");

}


function test2_do(message) {
  
  printf("2.  pass Function call with arg works: %s\n", message);

}


function test2() {
  
  test2_do("This is the argument");

}


function test3_do(b, c) {
  
  printf("3.1 pass Two arg call, first arg: %d\n", b);

  printf("3.2 pass Two arg call, second arg: %s\n", c);

}


function test3() {
  
  test3_do(42, "Fourty-two");

}


function test4_do() {
  
  return "pass Return works";

}


function returnThis(returnMessage) {
  
  return returnMessage;

}


function test4() {
    let message = "fail";

  message = test4_do();

  printf("4.  %s\n", message);

}


function test5() {
    let message = "fail";

  message = returnThis("pass return passthrough string");

  printf("5.  %s\n", message);

}


function test6() {
  
  if (true) {
    printf("6.  pass If statement works\n");

  } else {
    printf("6.  fail If statement works\n");

  };

}


function test7_do(count) {
  
  count = sub(count, 1);

  if (greaterthan(count, 0)) {
    count = test7_do(count);

  } else {
    return count;

  };

  return count;

}


function test7() {
  
  if (equal(0, test7_do(10))) {
    printf("7.  pass count works\n");

  } else {
    printf("7.  fail count fails\n");

  };

}


function beer() {
  
  printf("%d bottle of beer on the wall, %d bottle of beer.  Take one down, pass it round, no bottles of beer on the wall\n", 1, 1);

}


function plural(num) {
  
  if (equal(num, 1)) {
    return "";

  } else {
    return "s";

  };

}


function beers(count) {
    let newcount = 0;

  newcount = sub(count, 1);

  printf("%d bottle%s of beer on the wall, %d bottle%s of beer.  Take one down, pass it round, %d bottle%s of beer on the wall\n", count, plural(count), count, plural(count), newcount, plural(newcount));

  if (greaterthan(count, 1)) {
    count = beers(newcount);

  } else {
    return count;

  };

  return 0;

}


function test8() {
  
  if (equal(sub(sub(2, 1), sub(3, 1)), -1)) {
    printf("8.  pass Nested expressions work\n");

  } else {
    printf("8.  fail Nested expressions don't work\n");

  };

}


function test9() {
    let answer = -999999;
  let a = 2;
  let b = 3;

  answer = sub(sub(20, 1), sub(3, 1));

  if (equal(answer, 17)) {
    printf("9.1  pass sub works\n");

  } else {
    printf("9.1  fail sub\n");

  };

  answer = add(2, 3);

  if (equal(answer, 5)) {
    printf("9.2  pass add works\n");

  } else {
    printf("9.2  fail add\n");

  };

  answer = mult(a, b);

  if (equal(answer, 6)) {
    printf("9.3  pass mult works\n");

  } else {
    printf("9.3  fail mult\n");

  };

  if (greaterthan(2, 1)) {
    printf("9.4  pass greaterthan works\n");

  } else {
    printf("9.4  fail greaterthan\n");

  };

  if (equal(1, 1)) {
    printf("9.5  pass integer equal works\n");

  } else {
    printf("9.5  fail integer equal\n");

  };

  if (equalString("hello", "hello")) {
    printf("9.6  pass string equal works\n");

  } else {
    printf("9.6  fail string equal\n");

  };

  if (equalString("hello", "world")) {
    printf("9.7  fail string equal\n");

  } else {
    printf("9.7  pass string equal\n");

  };

  if (andBool(false, false)) {
    printf("9.8  fail andBool\n");

  } else {
    printf("9.8  pass andBool works\n");

  };

  if (andBool(true, true)) {
    printf("9.9  pass andBool works\n");

  } else {
    printf("9.9  fail andBool\n");

  };

  if (andBool(true, false)) {
    printf("9.10  fail andBool\n");

  } else {
    printf("9.10  pass andBool works\n");

  };

  if (equalString("hello", "hello")) {
    printf("9.11  pass string equal\n");

  } else {
    printf("9.11  fail string equal\n");

  };

  if (equalString("!", character(33))) {
    printf("9.12  pass character\n");

  } else {
    printf("9.12  fail character\n");

  };

  if (equalString("33", intToString(33))) {
    printf("9.13  pass intToString\n");

  } else {
    printf("9.13  fail intToString\n");

  };

  if (equalString("llo", sub_string("hello", a, b))) {
    printf("9.14  pass sub-string\n");

  } else {
    printf("9.14  fail sub-string: %s\n", sub_string("hello", a, b));

  };

}


function test10() {
    let testString = "This is a test string";

  if (equalString(testString, unBoxString(car(cons(boxString(testString), null))))) {
    printf("10. pass cons and car work\n");

  } else {
    printf("10. fail cons and car fail\n");

  };

}


function test12() {
    let b = null;

  b = {};

  b.str = "12. pass structure accessors\n";

  printf("%s", b.str);

}


function test13() {
    let testString = "Hello from the filesystem!";
  let contentsBox = null;
  let contents = "";

  write_file("test.txt", testString);

  contentsBox = read_file("test.txt");

  if (isNil(contentsBox)) {
    printf("13. fail Read and write files\n");

    printf("Expected: %s\n", testString);

    printf("Got: nil\n");

  } else {
    contents = unBoxString(contentsBox);

    if (equalString(testString, contents)) {
      printf("13. pass Read and write files\n");

    } else {
      printf("13. fail Read and write files\n");

      printf("Expected: %s\n", testString);

      printf("Got: %s\n", contents);

    };

  };

}


function test14() {
    let contentsBox = null;

  contentsBox = read_file("q/this-file-should-not-exist.qon");

  if (isNil(contentsBox)) {
    printf("14. pass Missing read-file returns nil\n");

  } else {
    printf("14. fail Missing read-file returns nil\n");

    printf("Got: %s\n", unBoxString(contentsBox));

  };

}


function test15() {
    let a = "hello";
  let b = " world";
  let c = "";

  c = stringConcatenate(a, b);

  if (equalString(c, "hello world")) {
    printf("15. pass String concatenate\n");

  } else {
    printf("15. fail String concatenate\n");

  };

}


function test16() {
    let assocCell1 = null;
  let assList = null;
  let assocCell2 = null;
  let assocCell3 = null;

  assocCell1 = cons(boxString("Hello"), boxString("world"));

  assocCell2 = cons(boxString("goodnight"), boxString("moon"));

  assocCell3 = cons(boxSymbol("ohio"), boxString("gozaimasu"));

  assList = cons(assocCell2, emptyList());

  assList = cons(assocCell1, assList);

  assList = cons(assocCell3, assList);

  if (equalBox(cdr(assoc("Hello", assList)), boxString("world"))) {
    printf("16.1 pass Basic assoc works\n");

  } else {
    printf("16.1 fail Basic assoc fails\n");

  };

  if (andBool(andBool(equalBox(cdr(assoc("Hello", assList)), boxString("world")), equalBox(cdr(assoc("goodnight", assList)), boxString("moon"))), equalBox(cdr(assoc("ohio", assList)), boxString("gozaimasu")))) {
    printf("16.2 pass assoc list\n");

  } else {
    printf("16.2 fail assoc list\n");

  };

}


function test17() {
    let l = null;

  l = cons(boxInt(1), cons(boxInt(2), cons(boxInt(3), null)));

  if (equalBox(car(l), boxInt(1))) {
    printf("17. pass list literal works\n");

  } else {
    printf("17. fail list literal failed\n");

  };

}


function test18() {
    let val1 = "a";
  let val2 = "b";
  let l = null;

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), null)));

  if (equalList(l, cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), null))))) {
    printf("18. pass string list constructor works\n");

  } else {
    printf("18. fail string list constructor failed\n");

  };

}


function test19() {
    let val1 = "a";
  let val2 = "b";
  let l = null;
  let revlist = null;
  let answer = null;

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), null)));

  answer = cons(boxString("c"), cons(boxString(val2), cons(boxString(val1), null)));

  revlist = reverseList(l);

  if (equalList(answer, revlist)) {
    printf("19. pass reverseList\n");

  } else {
    printf("19. fail reverseList\n");

  };

}


function concatenateLists(oldL, newL) {
  
  return reverseRec(reverseList(oldL), newL);

}


function test20() {
    let val1 = "a";
  let val2 = "b";
  let val3 = "c";
  let l = null;
  let l2 = null;
  let l3 = null;
  let combined = null;

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), null)));

  l2 = cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), null)));

  l3 = cons(boxString(val1), cons(boxString(val2), cons(boxString(val3), cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), null))))));

  combined = concatenateLists(l, l2);

  if (equalList(l3, combined)) {
    printf("21. pass concatenateLists\n");

  } else {
    printf("21. fail concatenateLists\n");

  };

}


function test21() {
    let val1 = "a";
  let val2 = "b";
  let val3 = "c";
  let l = null;
  let l2 = null;

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString(val3), null)));

  l2 = cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), null)));

  if (equalList(l, l2)) {
    printf("21. pass equalList\n");

  } else {
    printf("21. fail equalList\n");

  };

}


function test22() {
    let original = null;
  let out = null;
  let replace = null;
  let correct = null;

  original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), null)));

  replace = cons(boxString("fprintf"), cons(boxString("stderr"), null));

  out = macrolist(original, stringConcatenate("q", "log"), replace);

  correct = cons(boxString("fprintf"), cons(boxString("stderr"), cons(boxString("%s"), cons(boxString("hello"), null))));

  if (equalList(out, correct)) {
    printf("22. pass macroList\n");

  } else {
    printf("22. fail macroList\n");

    printf("In: ");

    displayList(original, 0, true);

    printf("\nOut: ");

    displayList(out, 0, true);

    printf("\n");

  };

}


function test23() {
    let original = null;
  let out = null;
  let replace = null;
  let correct = null;

  original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), null)));

  replace = cons(boxString("fprintf"), cons(boxString("stderr"), null));

  out = concatLists(original, replace);

  correct = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), cons(boxString("fprintf"), cons(boxString("stderr"), null)))));

  if (equalList(out, correct)) {
    printf("23. pass concatLists\n");

  } else {
    printf("23. fail concatLists\n");

    printf("In: ");

    displayList(original, 0, true);

    printf("\nOut: ");

    displayList(out, 0, true);

  };

}


function test24() {
    let expected = "a b c";
  let res = "";

  res = StringListJoin(cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), null))), " ");

  if (equalString(expected, res)) {
    printf("24. pass StringListJoin\n");

  } else {
    printf("24. fail StringListJoin.  expected %s, got %s\n", expected, res);

  };

}


function test25() {
    let expected = "( a b ) c d e";
  let res = "";
  let testsubstr = cons(boxString("c "), cons(boxString("d "), cons(boxString("e"), null)));
  let input = null;

  input = cons(boxString("a "), cons(boxString("b "), null));

  input = cons(input, testsubstr);

  res = ListToString(input, 0, true, false);

  if (equalString(expected, res)) {
    printf("25. pass ListToString\n");

  } else {
    printf("25. fail ListToString.  expected %s, got %s\n", expected, res);

  };

}


function test27() {
    let expected = "a b c d e";
  let floatExpected = "6.5";
  let floatResult = "";
  let res = "";
  let floatBox = null;
  let variable = cons(boxString("c "), cons(boxString("d "), null));
  let input = null;

  input = cons(boxString("a "), cons(boxString("b "), cons(id(variable), cons(boxString("e"), null))));

  res = ListToString(flatten(input), 0, true, false);

  if (equalString(expected, res)) {
    printf("27. pass Interpolated List\n");

  } else {
    printf("27. fail Interpolated List.  expected %s, got %s\n", expected, res);

  };

  floatBox = boxFloat(6.5);

  floatResult = stringify(floatBox);

  if (equalString(floatExpected, floatResult)) {
    printf("27. pass Float box stringify\n");

  } else {
    printf("27. fail Float box stringify.  expected %s, got %s\n", floatExpected, floatResult);

  };

}


function test28() {
    let splitExpected = null;
  let splitResult = null;

  if (equalString("aXYZc", stringReplace("b", "XYZ", "abc"))) {
    printf("28.1 pass stringReplace\n");

  } else {
    printf("28.1 fail stringReplace\n");

  };

  if (equalString("abc", stringTrim(" abc "))) {
    printf("28.2 pass stringTrim\n");

  } else {
    printf("28.2 fail stringTrim\n");

  };

  splitExpected = cons(boxString("a"), cons(boxString("b"), null));

  splitResult = stringSplit("a,b", ",");

  if (equalList(splitExpected, splitResult)) {
    printf("28.3 pass stringSplit\n");

  } else {
    printf("28.3 fail stringSplit\n");

  };

}


function haskellBackslash() {
  
  return character(92);

}


function haskellDoubleQuote() {
  
  return character(34);

}


function haskellEscapedBackslash() {
  
  return stringConcatenate(haskellBackslash(), haskellBackslash());

}


function haskellEscapedDoubleQuote() {
  
  return stringConcatenate(haskellBackslash(), haskellDoubleQuote());

}


function haskellEscapeString(s) {
  
  s = stringReplace(character(10), stringConcatenate(haskellBackslash(), "n"), s);

  s = stringReplace(character(13), stringConcatenate(haskellBackslash(), "r"), s);

  s = stringReplace(character(9), stringConcatenate(haskellBackslash(), "t"), s);

  return s;

}


function haskellSafeNameString(name) {
  
  if (equalString(name, "case")) {
    return "caseValue";

  } else {
  };

  if (equalString(name, "class")) {
    return "classValue";

  } else {
  };

  if (equalString(name, "data")) {
    return "dataValue";

  } else {
  };

  if (equalString(name, "default")) {
    return "defaultValue";

  } else {
  };

  if (equalString(name, "deriving")) {
    return "derivingValue";

  } else {
  };

  if (equalString(name, "do")) {
    return "doValue";

  } else {
  };

  if (equalString(name, "else")) {
    return "elseValue";

  } else {
  };

  if (equalString(name, "foreign")) {
    return "foreignValue";

  } else {
  };

  if (equalString(name, "if")) {
    return "ifValue";

  } else {
  };

  if (equalString(name, "import")) {
    return "importValue";

  } else {
  };

  if (equalString(name, "in")) {
    return "inValue";

  } else {
  };

  if (equalString(name, "infix")) {
    return "infixValue";

  } else {
  };

  if (equalString(name, "infixl")) {
    return "infixlValue";

  } else {
  };

  if (equalString(name, "infixr")) {
    return "infixrValue";

  } else {
  };

  if (equalString(name, "instance")) {
    return "instanceValue";

  } else {
  };

  if (equalString(name, "let")) {
    return "letValue";

  } else {
  };

  if (equalString(name, "module")) {
    return "moduleValue";

  } else {
  };

  if (equalString(name, "newtype")) {
    return "newtypeValue";

  } else {
  };

  if (equalString(name, "of")) {
    return "ofValue";

  } else {
  };

  if (equalString(name, "then")) {
    return "thenValue";

  } else {
  };

  if (equalString(name, "type")) {
    return "typeValue";

  } else {
  };

  if (equalString(name, "where")) {
    return "whereValue";

  } else {
  };

  if (equalString(name, "id")) {
    return "qid";

  } else {
  };

  if (equalString(name, "old")) {
    return "oldValue";

  } else {
  };

  if (equalString(name, "new")) {
    return "newValue";

  } else {
  };

  if (haskellStringStartsWith(name, "-")) {
    return name;

  } else {
  };

  if (equalString(name, "StringListJoinRec")) {
    return "stringListJoinRec";

  } else {
  };

  if (equalString(name, "StringListJoin")) {
    return "stringListJoin";

  } else {
  };

  if (equalString(name, "ListToBoxString")) {
    return "listToBoxString";

  } else {
  };

  if (equalString(name, "ListToString")) {
    return "listToString";

  } else {
  };

  if (equalString(name, "StackTraceMove")) {
    return "stackTraceMove";

  } else {
  };

  if (equalString(name, "StackTracePrint")) {
    return "stackTracePrint";

  } else {
  };

  if (equalString(name, "StackTracePrintHelper")) {
    return "stackTracePrintHelper";

  } else {
  };

  if (equalString(name, "NoStackTrace_list")) {
    return "noStackTrace_list";

  } else {
  };

  if (equalString(name, "NoTrace_list")) {
    return "noTrace_list";

  } else {
  };

  name = stringReplace("-", "_", name);

  name = stringReplace("?", "_q", name);

  name = stringReplace("!", "_bang", name);

  return name;

}


function haskellSafeName(aSym) {
  
  return boxSymbol(haskellSafeNameString(stringify(aSym)));

}


function haskellFieldName(aSym) {
  
  return stringConcatenate("qf_", haskellSafeNameString(stringify(aSym)));

}


function haskellNewName(aSym) {
  
  return stringConcatenate("new", stringify(aSym));

}


function haskellStringEndsWith(s, suffix) {
    let start = 0;

  if (greaterthan(string_length(suffix), string_length(s))) {
    return false;

  } else {
    start = sub(string_length(s), string_length(suffix));

    return equalString(sub_string(s, start, string_length(suffix)), suffix);

  };

}


function haskellStringStartsWith(s, prefix) {
  
  if (greaterthan(string_length(prefix), string_length(s))) {
    return false;

  } else {
    return equalString(sub_string(s, 0, string_length(prefix)), prefix);

  };

}


function haskellPointerBase(aSym) {
    let name = "";

  name = stringify(aSym);

  if (haskellStringEndsWith(name, "*")) {
    return boxSymbol(sub_string(name, 0, sub1(string_length(name))));

  } else {
    return aSym;

  };

}


function haskellTypeIsPointer(aSym) {
    let mapped = "";

  mapped = stringify(haskellTypeMap(aSym));

  return haskellStringStartsWith(mapped, "Maybe ");

}


function haskellTypeMap(aSym) {
    let symMap = null;
  let name = "";

  symMap = alistCons(boxSymbol("pair"), boxSymbol("Maybe Box"), alistCons(boxSymbol("box"), boxSymbol("Maybe Box"), alistCons(boxSymbol("list"), boxSymbol("Maybe Box"), alistCons(boxSymbol("Box*"), boxSymbol("Maybe Box"), alistCons(boxSymbol("Pair"), boxSymbol("Box"), alistCons(boxSymbol("struct"), boxSymbol(""), alistCons(boxSymbol("bool"), boxSymbol("Bool"), alistCons(boxSymbol("uint"), boxSymbol("Int"), alistCons(boxSymbol("int"), boxSymbol("Int"), alistCons(boxSymbol("float"), boxSymbol("Double"), alistCons(boxSymbol("void"), boxSymbol("()"), alistCons(boxSymbol("stringArray"), boxSymbol("[String]"), alistCons(boxSymbol("array"), boxSymbol("[String]"), alistCons(boxSymbol("hashmap"), boxSymbol("IORef [(String, String)]"), alistCons(boxSymbol("string"), boxSymbol("String"), null)))))))))))))));

  if (truthy(assoc(stringify(aSym), symMap))) {
    return cdr(assoc(stringify(aSym), symMap));

  } else {
    name = stringify(aSym);

    if (haskellStringEndsWith(name, "*")) {
      return boxSymbol(stringConcatenate("Maybe ", stringify(haskellPointerBase(aSym))));

    } else {
      return aSym;

    };

  };

}


function haskellDefaultValue(typeSym) {
    let typ = "";

  typ = stringify(haskellTypeMap(typeSym));

  if (equalString(typ, "()")) {
    return "()";

  } else {
  };

  if (equalString(typ, "Bool")) {
    return "False";

  } else {
  };

  if (equalString(typ, "Int")) {
    return "0";

  } else {
  };

  if (equalString(typ, "Double")) {
    return "0.0";

  } else {
  };

  if (equalString(typ, "String")) {
    return "\"\"";

  } else {
  };

  if (equalString(typ, "[String]")) {
    return "[]";

  } else {
  };

  if (haskellStringStartsWith(typ, "Maybe ")) {
    return "Nothing";

  } else {
  };

  return stringConcatenate("(error \"no default value for ", stringConcatenate(typ, "\")"));

}


function haskellRefType(typeSym) {
  
  return stringConcatenate("(", stringConcatenate(stringify(haskellTypeMap(typeSym)), ")"));

}


function haskellGlobalVariables() {
  
  return cons(id(boxSymbol("globalArgsCount")), cons(id(boxSymbol("globalArgs")), cons(id(boxSymbol("releaseMode")), cons(id(boxSymbol("caller")), cons(id(boxSymbol("globalTrace")), cons(id(boxSymbol("globalStepTrace")), cons(id(boxSymbol("globalStackTrace")), null)))))));

}


function haskellCollectVariablesFromArgs(args) {
    let variables = null;

  if (isNil(args)) {
    return variables;

  } else {
    variables = cons(second(args), variables);

    return appendVariables(variables, haskellCollectVariablesFromArgs(cddr(args)));

  };

}


function haskellCollectVariablesFromDecls(decls) {
    let variables = null;
  let decl = null;

  if (isNil(decls)) {
    return variables;

  } else {
    decl = car(decls);

    variables = cons(second(decl), variables);

    return appendVariables(variables, haskellCollectVariablesFromDecls(cdr(decls)));

  };

}


function haskellCollectVariables(args, decls) {
    let variables = null;

  variables = haskellCollectVariablesFromArgs(args);

  variables = appendVariables(variables, haskellCollectVariablesFromDecls(decls));

  variables = appendVariables(variables, haskellGlobalVariables());

  return variables;

}


function haskellFuncMap(aSym, variables) {
    let symMap = null;

  if (orBool(equalString("symbol", boxType(aSym)), equalString("string", boxType(aSym)))) {
    if (inList(aSym, variables)) {
      return haskellSafeName(aSym);

    } else {
      symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("Nothing"), alistCons(boxSymbol("true"), boxSymbol("True"), alistCons(boxSymbol("false"), boxSymbol("False"), alistCons(boxSymbol("old"), boxSymbol("oldValue"), alistCons(boxSymbol("new"), boxSymbol("newValue"), null)))))))))));

      if (truthy(assoc(stringify(aSym), symMap))) {
        return cdr(assoc(stringify(aSym), symMap));

      } else {
        return haskellSafeName(aSym);

      };

    };

  } else {
    return aSym;

  };

}


function haskellNumberAtom(tree) {
    let val = "";

  val = stringify(tree);

  if (haskellStringStartsWith(val, "-")) {
    return cons(boxString("pure ("), cons(id(boxString(val)), cons(boxString(")"), null)));

  } else {
    return cons(boxString("pure "), cons(id(boxString(val)), null));

  };

}


function haskellAtom(tree, variables) {
  
  if (equalString("int", boxType(tree))) {
    return haskellNumberAtom(tree);

  } else {
    if (equalString("float", boxType(tree))) {
      return haskellNumberAtom(tree);

    } else {
      if (equalString("string", boxType(tree))) {
        return cons(boxString("pure \""), cons(id(boxString(haskellEscapeString(stringify(tree)))), cons(boxString("\""), null)));

      } else {
        if (isInt(stringify(tree))) {
          return haskellNumberAtom(tree);

        } else {
          if (isFloat(stringify(tree))) {
            return haskellNumberAtom(tree);

          } else {
            if (haskellStringStartsWith(stringify(tree), "-")) {
              return cons(boxString("pure ("), cons(id(haskellFuncMap(tree, variables)), cons(boxString(")"), null)));

            } else {
              if (inList(tree, variables)) {
                return cons(boxString("liftIO (readIORef "), cons(id(haskellFuncMap(tree, variables)), cons(boxString(")"), null)));

              } else {
                return cons(boxString("pure "), cons(id(haskellFuncMap(tree, variables)), null));

              };

            };

          };

        };

      };

    };

  };

}


function haskellArgNames(expr, pos) {
  
  if (isEmpty(expr)) {
    return emptyList();

  } else {
    if (isNil(cdr(expr))) {
      return cons(boxString(" arg"), cons(id(boxString(intToString(pos))), null));

    } else {
      return cons(boxString(" arg"), cons(id(boxString(intToString(pos))), cons(id(haskellArgNames(cdr(expr), add1(pos))), null)));

    };

  };

}


function haskellBindArgs(expr, indent, variables, pos) {
  
  if (isEmpty(expr)) {
    return emptyList();

  } else {
    return cons(id(listNewLine(indent)), cons(boxString("arg"), cons(id(boxString(intToString(pos))), cons(boxString(" <- "), cons(id(haskellExpression(car(expr), indent, variables)), cons(id(haskellBindArgs(cdr(expr), indent, variables, add1(pos))), null))))));

  };

}


function haskellCall(name, args, indent, variables) {
  
  if (isEmpty(args)) {
    return cons(boxString("liftIO "), cons(id(haskellFuncMap(name, null)), null));

  } else {
    return cons(boxString("do"), cons(id(haskellBindArgs(args, add1(indent), variables, 0)), cons(id(listNewLine(add1(indent))), cons(boxString("liftIO ("), cons(id(haskellFuncMap(name, null)), cons(id(haskellArgNames(args, 0)), cons(boxString(")"), null)))))));

  };

}


function haskellBinop(tree, indent, variables) {
  
  return cons(boxString("do"), cons(id(listNewLine(add1(indent))), cons(boxString("arg0 <- "), cons(id(haskellExpression(third(tree), add1(indent), variables)), cons(id(listNewLine(add1(indent))), cons(boxString("arg1 <- "), cons(id(haskellExpression(fourth(tree), add1(indent), variables)), cons(id(listNewLine(add1(indent))), cons(boxString("pure (arg0 "), cons(id(second(tree)), cons(boxString(" arg1)"), null)))))))))));

}


function haskellGetStruct(tree, indent, variables) {
  
  return cons(boxString("do"), cons(id(listNewLine(add1(indent))), cons(boxString("hobj <- "), cons(id(haskellExpression(second(tree), add1(indent), variables)), cons(id(listNewLine(add1(indent))), cons(boxString("liftIO (readIORef ("), cons(boxString("getField @\""), cons(id(boxString(haskellFieldName(third(tree)))), cons(boxString("\" (expect hobj)))"), null)))))))));

}


function haskellNewExpression(tree) {
  
  if (haskellTypeIsPointer(second(tree))) {
    return cons(boxString("liftIO (Just <$> "), cons(id(boxString(haskellNewName(third(tree)))), cons(boxString(")"), null)));

  } else {
    return cons(boxString("liftIO "), cons(id(boxString(haskellNewName(third(tree)))), null));

  };

}


function haskellExpression(tree, indent, variables) {
    let thing = null;

  if (notBool(isList(tree))) {
    return haskellAtom(tree, variables);

  } else {
    if (equal(1, listLength(tree))) {
      if (equalBox(boxString("return"), car(tree))) {
        return cons(boxString("pure "), cons(id(haskellFuncMap(car(tree), variables)), null));

      } else {
        return haskellCall(car(tree), null, indent, variables);

      };

    } else {
      thing = first(tree);

      if (equalBox(boxSymbol("get-struct"), thing)) {
        return haskellGetStruct(tree, indent, variables);

      } else {
        if (equalBox(boxSymbol("new"), thing)) {
          return haskellNewExpression(tree);

        } else {
          if (equalBox(boxSymbol("passthrough"), thing)) {
            return cons(boxString("pure ("), cons(id(second(tree)), cons(boxString(")"), null)));

          } else {
            if (equalBox(boxSymbol("binop"), thing)) {
              return haskellBinop(tree, indent, variables);

            } else {
              return haskellCall(car(tree), cdr(tree), indent, variables);

            };

          };

        };

      };

    };

  };

}


function haskellSet(node, indent, variables) {
  
  return cons(id(listNewLine(indent)), cons(boxString("qset <- "), cons(id(haskellExpression(third(node), indent, variables)), cons(id(listNewLine(indent)), cons(boxString("liftIO (writeIORef "), cons(id(haskellFuncMap(second(node), variables)), cons(boxString(" qset)"), null)))))));

}


function haskellSetStruct(node, indent, variables) {
  
  return cons(id(listNewLine(indent)), cons(boxString("hobj <- "), cons(id(haskellExpression(second(node), indent, variables)), cons(id(listNewLine(indent)), cons(boxString("qset <- "), cons(id(haskellExpression(fourth(node), indent, variables)), cons(id(listNewLine(indent)), cons(boxString("liftIO (writeIORef ("), cons(boxString("getField @\""), cons(id(boxString(haskellFieldName(third(node)))), cons(boxString("\" (expect hobj)) qset)"), null)))))))))));

}


function haskellReturn(node, indent, variables) {
  
  if (greaterthan(listLength(node), 1)) {
    return cons(id(listNewLine(indent)), cons(boxString("hret <- "), cons(id(haskellExpression(cadr(node), indent, variables)), cons(id(listNewLine(indent)), cons(boxString("qreturn hret"), null)))));

  } else {
    return cons(id(listNewLine(indent)), cons(boxString("qreturn ()"), null));

  };

}


function haskellIf(node, indent, variables) {
  
  return cons(id(listNewLine(indent)), cons(boxString("hcond <- "), cons(id(haskellExpression(second(node), indent, variables)), cons(id(listNewLine(indent)), cons(boxString("if hcond"), cons(id(listNewLine(indent)), cons(boxString("  then do"), cons(id(haskellBody(cdr(third(node)), add(indent, 2), variables)), cons(id(listNewLine(add(indent, 2))), cons(boxString("pure ()"), cons(id(listNewLine(indent)), cons(boxString("  else do"), cons(id(haskellBody(cdr(fourth(node)), add(indent, 2), variables)), cons(id(listNewLine(add(indent, 2))), cons(boxString("pure ()"), null)))))))))))))));

}


function haskellStatement(node, indent, variables) {
  
  if (equalBox(boxString("set"), first(node))) {
    return haskellSet(node, indent, variables);

  } else {
    if (equalBox(boxString("set-struct"), first(node))) {
      return haskellSetStruct(node, indent, variables);

    } else {
      if (equalBox(boxString("if"), first(node))) {
        return haskellIf(node, indent, variables);

      } else {
        if (equalBox(boxString("return"), first(node))) {
          return haskellReturn(node, indent, variables);

        } else {
          return cons(id(listNewLine(indent)), cons(boxString("_ <- "), cons(id(haskellExpression(node, indent, variables)), null)));

        };

      };

    };

  };

}


function haskellBody(tree, indent, variables) {
  
  if (isEmpty(tree)) {
    return emptyList();

  } else {
    return cons(id(haskellStatement(car(tree), indent, variables)), cons(id(haskellBody(cdr(tree), indent, variables)), null));

  };

}


function haskellFunctionArgsSignature(tree) {
  
  if (isEmpty(tree)) {
    return emptyList();

  } else {
    if (isNil(cddr(tree))) {
      return cons(id(haskellTypeMap(first(tree))), cons(boxString(" -> "), null));

    } else {
      return cons(id(haskellTypeMap(first(tree))), cons(boxString(" -> "), cons(id(haskellFunctionArgsSignature(cddr(tree))), null)));

    };

  };

}


function haskellFunctionArgs(tree) {
  
  if (isEmpty(tree)) {
    return emptyList();

  } else {
    if (isNil(cddr(tree))) {
      return cons(boxString(" "), cons(id(haskellFuncMap(second(tree), null)), cons(boxString("_arg"), null)));

    } else {
      return cons(boxString(" "), cons(id(haskellFuncMap(second(tree), null)), cons(boxString("_arg"), cons(id(haskellFunctionArgs(cddr(tree))), null))));

    };

  };

}


function haskellArgRefs(args, indent) {
  
  if (isEmpty(args)) {
    return emptyList();

  } else {
    return cons(id(listNewLine(indent)), cons(id(haskellFuncMap(second(args), null)), cons(boxString(" <- liftIO (newIORef "), cons(id(haskellFuncMap(second(args), null)), cons(boxString("_arg)"), cons(id(haskellArgRefs(cddr(args), indent)), null))))));

  };

}


function haskellDeclarations(decls, indent, variables) {
    let decl = null;

  if (isEmpty(decls)) {
    return emptyList();

  } else {
    decl = car(decls);

    return cons(id(listNewLine(indent)), cons(boxString("qinit <- "), cons(id(haskellExpression(third(decl), indent, variables)), cons(id(listNewLine(indent)), cons(id(haskellFuncMap(second(decl), null)), cons(boxString(" <- liftIO (newIORef qinit)"), cons(id(haskellDeclarations(cdr(decls), indent, variables)), null)))))));

  };

}


function haskellFunction(node) {
    let variables = null;
  let args = null;
  let decls = null;

  if (isNil(node)) {
    return emptyList();

  } else {
    args = third(node);

    decls = cdr(fourth(node));

    variables = haskellCollectVariables(args, decls);

    return cons(id(listNewLine(0)), cons(id(haskellFuncMap(second(node), null)), cons(boxString(" :: "), cons(id(haskellFunctionArgsSignature(args)), cons(boxString("IO "), cons(id(boxString(haskellRefType(first(node)))), cons(id(listNewLine(0)), cons(id(haskellFuncMap(second(node), null)), cons(id(haskellFunctionArgs(args)), cons(boxString(" = evalContT $ callCC $ \\qreturn -> do"), cons(id(haskellArgRefs(args, 1)), cons(id(haskellDeclarations(decls, 1, variables)), cons(id(haskellBody(cdr(fifth(node)), 1, variables)), cons(id(listNewLine(1)), cons(boxString("pure "), cons(id(boxString(haskellDefaultValue(first(node)))), cons(boxString("\n"), null)))))))))))))))));

  };

}


function haskellFunctions(tree) {
  
  if (isEmpty(tree)) {
    return emptyList();

  } else {
    return cons(id(haskellFunction(car(tree))), cons(id(haskellFunctions(cdr(tree))), null));

  };

}


function haskellTypeDecl(l) {
    let fieldType = null;

  if (greaterthan(listLength(l), 2)) {
    fieldType = listLast(l);

  } else {
    fieldType = second(l);

  };

  return cons(boxString("  "), cons(id(boxString(haskellFieldName(first(l)))), cons(boxString(" :: IORef "), cons(id(boxString(haskellRefType(fieldType))), null))));

}


function haskellStructFields(node) {
  
  if (isEmpty(node)) {
    return emptyList();

  } else {
    if (isNil(cdr(node))) {
      return haskellTypeDecl(car(node));

    } else {
      return cons(id(haskellTypeDecl(car(node))), cons(boxString("\n, "), cons(id(haskellStructFields(cdr(node))), null)));

    };

  };

}


function haskellNewStructField(l, indent) {
    let fieldType = null;

  if (greaterthan(listLength(l), 2)) {
    fieldType = listLast(l);

  } else {
    fieldType = second(l);

  };

  return cons(id(listNewLine(indent)), cons(boxString("v_"), cons(id(boxString(haskellFieldName(first(l)))), cons(boxString(" <- newIORef "), cons(id(boxString(haskellDefaultValue(fieldType))), null)))));

}


function haskellNewStructFields(fields, indent) {
  
  if (isEmpty(fields)) {
    return emptyList();

  } else {
    return cons(id(haskellNewStructField(car(fields), indent)), cons(id(haskellNewStructFields(cdr(fields), indent)), null));

  };

}


function haskellStructCtorFields(fields) {
  
  if (isEmpty(fields)) {
    return emptyList();

  } else {
    if (isNil(cdr(fields))) {
      return cons(id(boxString(haskellFieldName(first(car(fields))))), cons(boxString(" = v_"), cons(id(boxString(haskellFieldName(first(car(fields))))), null)));

    } else {
      return cons(id(boxString(haskellFieldName(first(car(fields))))), cons(boxString(" = v_"), cons(id(boxString(haskellFieldName(first(car(fields))))), cons(boxString(", "), cons(id(haskellStructCtorFields(cdr(fields))), null)))));

    };

  };

}


function haskellType(node) {
    let fields = null;

  if (isList(second(node))) {
    fields = cdr(second(node));

    return cons(boxString("\ndata "), cons(id(first(node)), cons(boxString(" = "), cons(id(first(node)), cons(boxString(" { "), cons(id(haskellStructFields(fields)), cons(boxString("\n}\n\n"), cons(id(boxString(haskellNewName(first(node)))), cons(boxString(" :: IO "), cons(id(first(node)), cons(boxString("\n"), cons(id(boxString(haskellNewName(first(node)))), cons(boxString(" = do"), cons(id(haskellNewStructFields(fields, 1)), cons(id(listNewLine(1)), cons(boxString("pure "), cons(id(first(node)), cons(boxString(" { "), cons(id(haskellStructCtorFields(fields)), cons(boxString(" }\n"), null))))))))))))))))))));

  } else {
    return emptyList();

  };

}


function haskellTypes(nodes) {
  
  if (isEmpty(nodes)) {
    return emptyList();

  } else {
    return cons(id(haskellType(car(nodes))), cons(id(haskellTypes(cdr(nodes))), null));

  };

}


function haskellIncludes(nodes) {
  
  return cons(boxString("{-# LANGUAGE DataKinds #-}\n"), cons(boxString("{-# LANGUAGE DuplicateRecordFields #-}\n"), cons(boxString("{-# LANGUAGE ExtendedDefaultRules #-}\n"), cons(boxString("{-# LANGUAGE TypeApplications #-}\n"), cons(boxString("import Control.Monad.Trans.Cont\n"), cons(boxString("import Control.Monad.IO.Class\n"), cons(boxString("import Data.Char (chr)\n"), cons(boxString("import Data.IORef\n"), cons(boxString("import Data.Maybe (isNothing)\n"), cons(boxString("import GHC.Records (getField)\n"), cons(boxString("import System.Directory (doesFileExist)\n"), cons(boxString("import System.Environment (getArgs, lookupEnv)\n"), cons(boxString("import System.Exit (ExitCode(..), exitWith)\n"), cons(boxString("import System.IO (Handle, stderr, hPutStr, hFlush)\n"), cons(boxString("import System.IO.Unsafe (unsafePerformIO)\n"), cons(boxString("import Text.Printf (printf, hPrintf)\n\n"), cons(boxString("default (Int, Double)\n\n"), cons(boxString("expect :: Maybe a -> a\n"), cons(boxString("expect (Just x) = x\n"), cons(boxString("expect Nothing = error \"Quon nil dereference\"\n\n"), cons(boxString("globalTrace :: IORef Bool\n"), cons(boxString("globalTrace = unsafePerformIO (newIORef False)\n"), cons(boxString("{-# NOINLINE globalTrace #-}\n\n"), cons(boxString("globalStepTrace :: IORef Bool\n"), cons(boxString("globalStepTrace = unsafePerformIO (newIORef False)\n"), cons(boxString("{-# NOINLINE globalStepTrace #-}\n\n"), cons(boxString("releaseMode :: IORef Bool\n"), cons(boxString("releaseMode = unsafePerformIO (newIORef False)\n"), cons(boxString("{-# NOINLINE releaseMode #-}\n\n"), cons(boxString("caller :: IORef String\n"), cons(boxString("caller = unsafePerformIO (newIORef \"\")\n"), cons(boxString("{-# NOINLINE caller #-}\n\n"), cons(boxString("globalArgs :: IORef [String]\n"), cons(boxString("globalArgs = unsafePerformIO (newIORef [])\n"), cons(boxString("{-# NOINLINE globalArgs #-}\n\n"), cons(boxString("globalArgsCount :: IORef Int\n"), cons(boxString("globalArgsCount = unsafePerformIO (newIORef 0)\n"), cons(boxString("{-# NOINLINE globalArgsCount #-}\n\n"), cons(boxString("globalStackTrace :: IORef (Maybe Box)\n"), cons(boxString("globalStackTrace = unsafePerformIO (newIORef Nothing)\n"), cons(boxString("{-# NOINLINE globalStackTrace #-}\n\n"), cons(boxString("hsIsNil :: Maybe a -> IO Bool\n"), cons(boxString("hsIsNil = pure . isNothing\n\n"), cons(boxString("hsGetEnv :: String -> IO String\n"), cons(boxString("hsGetEnv key = do\n"), cons(boxString("  value <- lookupEnv key\n"), cons(boxString("  pure (maybe \"\" (\\x -> x) value)\n\n"), cons(boxString("hsPanic :: String -> IO ()\n"), cons(boxString("hsPanic = error\n\n"), cons(boxString("hsExit :: Int -> IO ()\n"), cons(boxString("hsExit 0 = exitWith ExitSuccess\n"), cons(boxString("hsExit n = exitWith (ExitFailure n)\n\n"), cons(boxString("hsStringLength :: String -> IO Int\n"), cons(boxString("hsStringLength = pure . length\n\n"), cons(boxString("hsSubString :: String -> Int -> Int -> IO String\n"), cons(boxString("hsSubString s start len = pure (take len (drop start s))\n\n"), cons(boxString("hsSetSubString :: String -> Int -> String -> IO String\n"), cons(boxString("hsSetSubString target start source = pure (take start target ++ source ++ drop (start + 1) target)\n\n"), cons(boxString("hsShowInt :: Int -> IO String\n"), cons(boxString("hsShowInt = pure . show\n\n"), cons(boxString("hsShowFloat :: Double -> IO String\n"), cons(boxString("hsShowFloat = pure . show\n\n"), cons(boxString("hsReadFile :: String -> IO (Maybe Box)\n"), cons(boxString("hsReadFile filename = do\n"), cons(boxString("  exists <- doesFileExist filename\n"), cons(boxString("  if exists then do\n"), cons(boxString("    contents <- readFile filename\n"), cons(boxString("    boxString contents\n"), cons(boxString("  else pure Nothing\n\n"), cons(boxString("hsWriteFile :: String -> String -> IO ()\n"), cons(boxString("hsWriteFile = writeFile\n\n"), cons(boxString("hsGetStringArray :: Int -> [String] -> IO String\n"), cons(boxString("hsGetStringArray index strs = pure (strs !! index)\n\n"), cons(boxString("hsProgramArgs :: IO [String]\n"), cons(boxString("hsProgramArgs = readIORef globalArgs\n\n"), cons(boxString("hsProgramArgsCount :: IO Int\n"), cons(boxString("hsProgramArgsCount = readIORef globalArgsCount\n\n"), cons(boxString("hsCharacter :: Int -> IO String\n"), cons(boxString("hsCharacter num = pure [chr num]\n\n"), cons(boxString("hsRemainder :: Int -> Int -> IO Int\n"), cons(boxString("hsRemainder a b = pure (a `mod` b)\n\n"), cons(boxString("hsMakeHash :: IO (IORef [(String, String)])\n"), cons(boxString("hsMakeHash = newIORef []\n\n"), cons(boxString("hsSetHash :: IORef [(String, String)] -> String -> String -> IO ()\n"), cons(boxString("hsSetHash hash key value = modifyIORef hash ((key, value) :)\n\n"), cons(boxString("hsGetHash :: IORef [(String, String)] -> String -> IO String\n"), cons(boxString("hsGetHash hash key = do\n"), cons(boxString("  pairs <- readIORef hash\n"), cons(boxString("  pure (maybe \"\" (\\x -> x) (lookup key pairs))\n\n"), cons(boxString("hsInHash :: IORef [(String, String)] -> String -> IO Bool\n"), cons(boxString("hsInHash hash key = do\n"), cons(boxString("  pairs <- readIORef hash\n"), cons(boxString("  pure (not (isNothing (lookup key pairs)))\n\n"), cons(boxString("hsMakeArray :: Int -> IO [String]\n"), cons(boxString("hsMakeArray len = pure (replicate len \"\")\n\n"), cons(boxString("hsSetArray :: [String] -> Int -> String -> IO ()\n"), cons(boxString("hsSetArray _ _ _ = pure ()\n\n"), cons(boxString("hsGetArray :: [String] -> Int -> IO String\n"), cons(boxString("hsGetArray array index = pure (array !! index)\n\n"), null)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));

}


function haskellMainEntry() {
  
  return cons(boxString("\nmain :: IO ()\n"), cons(boxString("main = do\n"), cons(boxString("  args <- getArgs\n"), cons(boxString("  let qargs = \"fixmeprogname\" : args\n"), cons(boxString("  writeIORef globalArgs qargs\n"), cons(boxString("  writeIORef globalArgsCount (length qargs)\n"), cons(boxString("  _ <- start\n"), cons(boxString("  pure ()\n"), null))))))));

}


function haskellApplyTypeAliases(tree, types) {
    let node = null;
  let alias = null;
  let target = null;

  if (isEmpty(types)) {
    return tree;

  } else {
  };

  node = car(types);

  if (isList(second(node))) {
    return haskellApplyTypeAliases(tree, cdr(types));

  } else {
  };

  alias = first(node);

  if (equalString(stringify(haskellTypeMap(alias)), stringify(alias))) {
    target = haskellTypeMap(second(node));

    return haskellApplyTypeAliases(macroSymbolSingle(tree, stringify(alias), stringify(target)), cdr(types));

  } else {
    return haskellApplyTypeAliases(tree, cdr(types));

  };

}


function haskellLoadProgram(filename) {
    let tree = null;
  let replace = null;

  tree = loadQuon(filename);

  tree = insertInclude(tree, "q/shims/haskell.qon");

  tree = loadIncludes(tree, null);

  tree = macrowalk(tree);

  replace = cons(boxSymbol("hPrintf"), cons(boxSymbol("stderr"), null));

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

  tree = haskellApplyTypeAliases(tree, cdr(getTypes(tree)));

  return tree;

}


function haskellProgramTree(tree) {
  
  return cons(id(haskellIncludes(cdr(first(tree)))), cons(id(haskellTypes(cdr(second(tree)))), cons(id(haskellFunctions(cdr(third(tree)))), cons(id(haskellMainEntry()), cons(boxString("\n"), null)))));

}


function haskellProgram(tree) {
  
  return ListToString(flatten(haskellProgramTree(tree)), 0, true, false);

}


function haskellCompileString(filename) {
  
  return haskellProgram(haskellLoadProgram(filename));

}


function haskellCompile(filename) {
    let tree = null;
  let replace = null;

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


function javaFunctionArgs(tree) {
  
  if (isEmpty(tree)) {
    return emptyList();

  } else {
    if (equalString(stringify(first(tree)), "...")) {
      if (isNil(cddr(tree))) {
        return cons(boxString("Object... args"), null);

      } else {
        return cons(boxString("Object... args, "), cons(id(javaFunctionArgs(cddr(tree))), null));

      };

    } else {
      if (isNil(cddr(tree))) {
        return cons(id(javaTypeMap(first(tree))), cons(boxString(" "), cons(id(javaFuncMap(second(tree))), null)));

      } else {
        return cons(id(javaTypeMap(first(tree))), cons(boxString(" "), cons(id(javaFuncMap(second(tree))), cons(boxString(", "), cons(id(javaFunctionArgs(cddr(tree))), null)))));

      };

    };

  };

}


function javaAtom(tree) {
  
  if (equalString("string", boxType(tree))) {
    return cons(boxString("\""), cons(id(boxString(stringify(tree))), cons(boxString("\""), null)));

  } else {
    return cons(id(javaFuncMap(tree)), null);

  };

}


function javaExpression(tree, indent) {
    let thing = null;

  if (notBool(isList(tree))) {
    return javaAtom(tree);

  } else {
    if (equal(1, listLength(tree))) {
      if (equalBox(boxString("return"), car(tree))) {
        return cons(id(javaFuncMap(car(tree))), null);

      } else {
        return cons(id(javaFuncMap(car(tree))), cons(boxString("()"), null));

      };

    } else {
      thing = first(tree);

      if (equalBox(boxSymbol("get-struct"), thing)) {
        return cons(id(javaExpression(second(tree), indent)), cons(boxString("."), cons(id(third(tree)), null)));

      } else {
        if (equalBox(boxSymbol("new"), thing)) {
          return cons(boxString("new "), cons(id(javaTypeMap(second(tree))), cons(boxString("()"), null)));

        } else {
          if (equalBox(boxSymbol("passthrough"), thing)) {
            return cons(id(second(tree)), null);

          } else {
            if (equalBox(boxSymbol("binop"), thing)) {
              return cons(boxString("("), cons(id(javaExpression(third(tree), indent)), cons(boxString(" "), cons(id(second(tree)), cons(boxString(" "), cons(id(javaExpression(fourth(tree), indent)), cons(boxString(")"), null)))))));

            } else {
              return cons(id(javaFuncMap(car(tree))), cons(boxString("("), cons(id(javaRecurList(cdr(tree), indent)), cons(boxString(")"), null))));

            };

          };

        };

      };

    };

  };

}


function javaRecurList(expr, indent) {
  
  if (isEmpty(expr)) {
    return emptyList();

  } else {
    if (isNil(cdr(expr))) {
      return javaExpression(car(expr), indent);

    } else {
      return cons(id(javaExpression(car(expr), indent)), cons(boxString(", "), cons(id(javaRecurList(cdr(expr), indent)), null)));

    };

  };

}


function javaIf(node, indent) {
  
  return cons(id(listNewLine(indent)), cons(boxString("if ( "), cons(id(javaExpression(second(node), 0)), cons(boxString(") {"), cons(id(javaBody(cdr(third(node)), add1(indent))), cons(id(listNewLine(indent)), cons(boxString("} else {"), cons(id(javaBody(cdr(fourth(node)), add1(indent))), cons(id(listNewLine(indent)), cons(boxString("}"), null))))))))));

}


function javaSetStruct(node, indent) {
  
  return cons(id(listNewLine(indent)), cons(id(javaExpression(second(node), indent)), cons(boxString("."), cons(id(third(node)), cons(boxString(" = "), cons(id(javaExpression(fourth(node), indent)), null))))));

}


function javaSet(node, indent) {
  
  return cons(id(listNewLine(indent)), cons(id(javaExpression(second(node), indent)), cons(boxString(" = "), cons(id(javaExpression(third(node), indent)), null))));

}


function javaReturn(node, indent) {
  
  if (equal(listLength(node), 1)) {
    return cons(id(listNewLine(indent)), cons(boxString("return"), null));

  } else {
    return cons(id(listNewLine(indent)), cons(boxString("return "), cons(id(javaExpression(cadr(node), indent)), null)));

  };

}


function javaStatement(node, indent) {
  
  if (equalBox(boxString("set"), first(node))) {
    return cons(id(javaSet(node, indent)), cons(boxString(";\n"), null));

  } else {
    if (equalBox(boxString("set-struct"), first(node))) {
      return cons(id(javaSetStruct(node, indent)), cons(boxString(";\n"), null));

    } else {
      if (equalBox(boxString("if"), first(node))) {
        return cons(id(javaIf(node, indent)), cons(boxString("\n"), null));

      } else {
        if (equalBox(boxString("return"), first(node))) {
          return cons(id(javaReturn(node, indent)), cons(boxString(";\n"), null));

        } else {
          return cons(id(listNewLine(indent)), cons(id(javaExpression(node, indent)), cons(boxString(";\n"), null)));

        };

      };

    };

  };

}


function javaBody(tree, indent) {
    let code = null;

  if (isEmpty(tree)) {
    return emptyList();

  } else {
    code = car(tree);

    return cons(id(javaStatement(code, indent)), cons(id(javaBody(cdr(tree), indent)), null));

  };

}


function javaDeclarations(decls, indent) {
    let decl = null;

  if (isEmpty(decls)) {
    return emptyList();

  } else {
    decl = car(decls);

    return cons(id(javaTypeMap(first(decl))), cons(boxString(" "), cons(id(javaFuncMap(second(decl))), cons(boxString(" = "), cons(id(javaExpression(third(decl), indent)), cons(boxString(";\n"), cons(id(javaDeclarations(cdr(decls), indent)), null)))))));

  };

}


function javaFunction(node) {
    let name = null;

  name = second(node);

  if (isNil(node)) {
    return emptyList();

  } else {
    return cons(id(listNewLine(0)), cons(id(listNewLine(0)), cons(id(javaTypeMap(first(node))), cons(boxString(" "), cons(id(javaFuncMap(second(node))), cons(boxString("("), cons(id(javaFunctionArgs(third(node))), cons(boxString(") {"), cons(id(listNewLine(1)), cons(id(javaDeclarations(cdr(fourth(node)), 1)), cons(id(javaBody(cdr(fifth(node)), 1)), cons(boxString("\n}\n"), null))))))))))));

  };

}


function javaFunctions(tree) {
  
  if (isEmpty(tree)) {
    return emptyList();

  } else {
    return cons(id(javaFunction(car(tree))), cons(id(javaFunctions(cdr(tree))), null));

  };

}


function javaIncludes(nodes) {
  
  return cons(boxString("import java.nio.charset.StandardCharsets;\n"), cons(boxString("import java.nio.file.Files;\n"), cons(boxString("import java.nio.file.Paths;\n"), cons(boxString("import java.util.HashMap;\n\n"), cons(boxString("class QuonProgram {\n"), cons(boxString("  boolean globalTrace = false;\n"), cons(boxString("  boolean globalStepTrace = false;\n"), cons(boxString("  boolean releaseMode = false;\n"), cons(boxString("  Box globalStackTrace = null;\n"), cons(boxString("  String caller = \"\";\n"), cons(boxString("  String[] globalArgs = new String[0];\n"), cons(boxString("  int globalArgsCount = 0;\n\n"), cons(boxString("  Object stderr = new Object();\n\n"), cons(boxString("  void fprintf(Object stream, String format, Object... args) {\n"), cons(boxString("    if (args.length == 0) {\n"), cons(boxString("      System.err.print(format);\n"), cons(boxString("    } else {\n"), cons(boxString("      System.err.printf(format, args);\n"), cons(boxString("    }\n"), cons(boxString("  }\n\n"), cons(boxString("  void exit(int code) {\n"), cons(boxString("    System.exit(code);\n"), cons(boxString("  }\n\n"), cons(boxString("  Box readFileBox(String filename) {\n"), cons(boxString("    try {\n"), cons(boxString("      return boxString(Files.readString(Paths.get(filename)));\n"), cons(boxString("    } catch (Exception e) {\n"), cons(boxString("      return null;\n"), cons(boxString("    }\n"), cons(boxString("  }\n\n"), cons(boxString("  void writeFileUnchecked(String filename, String data) {\n"), cons(boxString("    try {\n"), cons(boxString("      Files.write(Paths.get(filename), data.getBytes(StandardCharsets.UTF_8));\n"), cons(boxString("    } catch (Exception e) {\n"), cons(boxString("      throw new RuntimeException(\"Could not write file: \" + filename, e);\n"), cons(boxString("    }\n"), cons(boxString("  }\n"), null)))))))))))))))))))))))))))))))))))));

}


function javaTypeMap(aSym) {
    let symMap = null;

  symMap = alistCons(boxSymbol("pair"), boxSymbol("Box"), alistCons(boxSymbol("box"), boxSymbol("Box"), alistCons(boxSymbol("list"), boxSymbol("Box"), alistCons(boxSymbol("Box*"), boxSymbol("Box"), alistCons(boxSymbol("struct"), boxSymbol(""), alistCons(boxSymbol("bool"), boxSymbol("boolean"), alistCons(boxSymbol("uint"), boxSymbol("int"), alistCons(boxSymbol("float"), boxSymbol("double"), alistCons(boxSymbol("stringArray"), boxSymbol("String[]"), alistCons(boxSymbol("array"), boxSymbol("String[]"), alistCons(boxSymbol("hashmap"), boxSymbol("HashMap<String, String>"), alistCons(boxSymbol("string"), boxSymbol("String"), null))))))))))));

  if (truthy(assoc(stringify(aSym), symMap))) {
    return cdr(assoc(stringify(aSym), symMap));

  } else {
    return aSym;

  };

}


function javaPointerBase(aSym) {
    let name = "";

  name = stringify(aSym);

  if (equalString("*", sub_string(name, sub1(string_length(name)), 1))) {
    return boxSymbol(sub_string(name, 0, sub1(string_length(name))));

  } else {
    return aSym;

  };

}


function javaFuncMap(aSym) {
    let symMap = null;

  if (equalString("symbol", boxType(aSym))) {
    symMap = alistCons(boxSymbol("printf"), boxSymbol("System.out.printf"), alistCons(boxSymbol(stringConcatenate("q", "log")), boxSymbol("System.err.printf"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("null"), alistCons(boxSymbol("old"), boxSymbol("oldValue"), alistCons(boxSymbol("new"), boxSymbol("newValue"), null)))))))))));

    if (truthy(assoc(stringify(aSym), symMap))) {
      return cdr(assoc(stringify(aSym), symMap));

    } else {
      return aSym;

    };

  } else {
    return aSym;

  };

}


function javaTypeDecl(l) {
  
  if (greaterthan(listLength(l), 2)) {
    return cons(id(boxString(stringIndent(1))), cons(id(javaTypeMap(listLast(l))), cons(boxString(" "), cons(id(first(l)), cons(boxString(";\n"), null)))));

  } else {
    return cons(id(boxString(stringIndent(1))), cons(id(javaTypeMap(listLast(l))), cons(boxString(" "), cons(id(car(l)), cons(boxString(";\n"), null)))));

  };

}


function javaStructComponents(node) {
  
  if (isEmpty(node)) {
    return emptyList();

  } else {
    return cons(id(javaTypeDecl(car(node))), cons(id(javaStructComponents(cdr(node))), null));

  };

}


function javaStruct(node) {
  
  return javaStructComponents(cdr(node));

}


function javaType(node) {
  
  if (isList(second(node))) {
    return cons(boxString("\nclass "), cons(id(first(node)), cons(boxString(" {\n"), cons(id(javaStruct(second(node))), cons(boxString("}\n"), null)))));

  } else {
    return emptyList();

  };

}


function javaTypes(nodes) {
  
  if (isEmpty(nodes)) {
    return emptyList();

  } else {
    return cons(id(javaType(car(nodes))), cons(id(javaTypes(cdr(nodes))), null));

  };

}


function javaApplyTypeAliases(tree, types) {
    let node = null;
  let alias = null;
  let target = null;

  if (isEmpty(types)) {
    return tree;

  } else {
  };

  node = car(types);

  if (isList(second(node))) {
    return javaApplyTypeAliases(tree, cdr(types));

  } else {
  };

  alias = first(node);

  if (equalString(stringify(javaTypeMap(alias)), stringify(alias))) {
    target = javaTypeMap(javaPointerBase(second(node)));

    return javaApplyTypeAliases(macroSymbolSingle(tree, stringify(alias), stringify(target)), cdr(types));

  } else {
    return javaApplyTypeAliases(tree, cdr(types));

  };

}


function javaMainEntry() {
  
  return cons(boxString("\npublic static void main(String[] args) {\n"), cons(boxString("  QuonProgram program = new QuonProgram();\n"), cons(boxString("  program.globalArgs = new String[args.length + 1];\n"), cons(boxString("  program.globalArgs[0] = \"fixmeprogname\";\n"), cons(boxString("  System.arraycopy(args, 0, program.globalArgs, 1, args.length);\n"), cons(boxString("  program.globalArgsCount = program.globalArgs.length;\n"), cons(boxString("  program.start();\n"), cons(boxString("}\n"), cons(boxString("}\n"), null)))))))));

}


function javaLoadProgram(filename) {
    let tree = null;
  let replace = null;

  tree = loadQuon(filename);

  tree = buildProg(cons(boxString("q/shims/java.qon"), getIncludes(tree)), getTypes(tree), getFunctions(tree));

  tree = loadIncludes(tree, null);

  tree = macrowalk(tree);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), null));

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

  tree = javaApplyTypeAliases(tree, cdr(getTypes(tree)));

  return tree;

}


function javaProgramTree(tree) {
  
  return cons(id(javaIncludes(cdr(first(tree)))), cons(id(javaTypes(cdr(second(tree)))), cons(id(javaFunctions(cdr(third(tree)))), cons(id(javaMainEntry()), cons(boxString("\n"), null)))));

}


function javaProgram(tree) {
  
  return ListToString(flatten(javaProgramTree(tree)), 0, true, false);

}


function javaCompileString(filename) {
  
  return javaProgram(javaLoadProgram(filename));

}


function javaCompile(filename) {
  
  printStringTree(javaProgramTree(javaLoadProgram(filename)));

  fprintf(stderr, "//Done printing program\n");

}


function ansi3FunctionArgs(tree) {
  
  if (isEmpty(tree)) {
    return emptyList();

  } else {
    if (equalString(stringify(first(tree)), "...")) {
      if (isNil(cddr(tree))) {
        return cons(boxString("..."), null);

      } else {
        return cons(boxString("..."), cons(boxString(", "), cons(id(ansi3FunctionArgs(cddr(tree))), null)));

      };

    } else {
      if (isNil(cddr(tree))) {
        return cons(id(ansi3TypeMap(first(tree))), cons(boxString(" "), cons(id(second(tree)), null)));

      } else {
        return cons(id(ansi3TypeMap(first(tree))), cons(boxString(" "), cons(id(second(tree)), cons(boxString(", "), cons(id(ansi3FunctionArgs(cddr(tree))), null)))));

      };

    };

  };

}


function ansi3Atom(tree) {
  
  if (equalString("string", boxType(tree))) {
    return cons(boxString("\""), cons(id(boxString(stringify(tree))), cons(boxString("\""), null)));

  } else {
    return cons(id(ansi3FuncMap(tree)), null);

  };

}


function ansi3Expression(tree, indent) {
    let thing = null;

  if (notBool(isList(tree))) {
    return ansi3Atom(tree);

  } else {
    if (equal(1, listLength(tree))) {
      if (equalBox(boxString("return"), car(tree))) {
        return cons(id(ansi3FuncMap(car(tree))), null);

      } else {
        return cons(id(ansi3FuncMap(car(tree))), cons(boxString("()"), null));

      };

    } else {
      thing = first(tree);

      if (equalBox(boxSymbol("get-struct"), thing)) {
        return cons(id(second(tree)), cons(boxString("->"), cons(id(third(tree)), null)));

      } else {
        if (equalBox(boxSymbol("new"), thing)) {
          return cons(boxString("malloc(sizeof("), cons(id(third(tree)), cons(boxString("))"), null)));

        } else {
          if (equalBox(boxSymbol("passthrough"), thing)) {
            return cons(id(second(tree)), null);

          } else {
            if (equalBox(boxSymbol("binop"), thing)) {
              return cons(boxString("("), cons(id(ansi3Expression(third(tree), indent)), cons(boxString(" "), cons(id(second(tree)), cons(boxString(" "), cons(id(ansi3Expression(fourth(tree), indent)), cons(boxString(")"), null)))))));

            } else {
              return cons(id(ansi3FuncMap(car(tree))), cons(boxString("("), cons(id(ansi3RecurList(cdr(tree), indent)), cons(boxString(")"), null))));

            };

          };

        };

      };

    };

  };

}


function ansi3RecurList(expr, indent) {
  
  if (isEmpty(expr)) {
    return emptyList();

  } else {
    if (isNil(cdr(expr))) {
      return ansi3Expression(car(expr), indent);

    } else {
      return cons(id(ansi3Expression(car(expr), indent)), cons(boxString(", "), cons(id(ansi3RecurList(cdr(expr), indent)), null)));

    };

  };

}


function ansi3If(node, indent, functionName) {
  
  return cons(id(listNewLine(indent)), cons(boxString("if ( "), cons(id(ansi3Expression(second(node), 0)), cons(boxString(") {"), cons(id(ansi3Body(cdr(third(node)), add1(indent), functionName)), cons(id(listNewLine(indent)), cons(boxString("} else {"), cons(id(ansi3Body(cdr(fourth(node)), add1(indent), functionName)), cons(id(listNewLine(indent)), cons(boxString("}"), null))))))))));

}


function ansi3SetStruct(node, indent) {
  
  return cons(id(listNewLine(indent)), cons(id(second(node)), cons(boxString("->"), cons(id(third(node)), cons(boxString(" = "), cons(id(ansi3Expression(fourth(node), indent)), null))))));

}


function ansi3Set(node, indent) {
  
  return cons(id(listNewLine(indent)), cons(id(ansi3Expression(second(node), indent)), cons(boxString(" = "), cons(id(ansi3Expression(third(node), indent)), null))));

}


function ansi3Return(node, indent) {
  
  if (equal(listLength(node), 1)) {
    return cons(id(listNewLine(indent)), cons(boxString("return;"), null));

  } else {
    return cons(id(listNewLine(indent)), cons(boxString("return "), cons(id(ansi3Expression(cadr(node), indent)), cons(boxString(";"), null))));

  };

}


function ansi3TraceReturn(node, indent, functionName) {
  
  if (releaseMode) {
    return ansi3Return(node, indent);

  } else {
    if (inList(boxString(functionName), NoStackTrace_list())) {
      return ansi3Return(node, indent);

    } else {
      return cons(boxString("\n"), cons(id(boxString(stringIndent(indent))), cons(boxString("StackTraceMove(\"out\", \"\", \"\", \"\");\n"), cons(id(ansi3Return(node, indent)), null))));

    };

  };

}


function ansi3Statement(node, indent, functionName) {
  
  if (equalBox(boxString("set"), first(node))) {
    return cons(id(ansi3Set(node, indent)), cons(boxString(";\n"), null));

  } else {
    if (equalBox(boxString("set-struct"), first(node))) {
      return cons(id(ansi3SetStruct(node, indent)), cons(boxString(";\n"), null));

    } else {
      if (equalBox(boxString("if"), first(node))) {
        return cons(id(ansi3If(node, indent, functionName)), cons(boxString(";\n"), null));

      } else {
        if (equalBox(boxString("return"), first(node))) {
          return cons(id(ansi3TraceReturn(node, indent, functionName)), cons(boxString(";\n"), null));

        } else {
          return cons(id(listNewLine(indent)), cons(id(ansi3Expression(node, indent)), cons(boxString(";\n"), null)));

        };

      };

    };

  };

}


function ansi3StatementTrace(code, indent, functionName) {
  
  if (releaseMode) {
    return emptyList();

  } else {
    if (inList(boxString(functionName), NoTrace_list())) {
      return emptyList();

    } else {
      return cons(boxString("\nif (globalTrace)\n    snprintf(caller, 1024, \"from "), cons(id(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), cons(boxString(":"), cons(id(getTagFail(car(code), boxString("line"), boxString("Line missing"))), cons(boxString("\");\n"), null)))));

    };

  };

}


function ansi3StepTrace(indent) {
  
  if (releaseMode) {
    return emptyList();

  } else {
    return cons(id(boxString(stringIndent(indent))), cons(boxString("if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n"), null));

  };

}


function ansi3Body(tree, indent, functionName) {
    let code = null;

  if (isEmpty(tree)) {
    return emptyList();

  } else {
    code = car(tree);

    return cons(id(ansi3StatementTrace(code, indent, functionName)), cons(id(ansi3StepTrace(indent)), cons(id(ansi3Statement(code, indent, functionName)), cons(id(ansi3Body(cdr(tree), indent, functionName)), null))));

  };

}


function ansi3Declarations(decls, indent) {
    let decl = null;

  if (isEmpty(decls)) {
    return emptyList();

  } else {
    decl = car(decls);

    return cons(id(ansi3TypeMap(first(decl))), cons(boxString(" "), cons(id(second(decl)), cons(boxString(" = "), cons(id(ansi3Expression(third(decl), indent)), cons(boxString(";\n"), cons(id(ansi3Declarations(cdr(decls), indent)), null)))))));

  };

}


function ansi3FunctionTrace(name) {
  
  if (releaseMode) {
    return emptyList();

  } else {
    if (inList(name, NoTrace_list())) {
      return emptyList();

    } else {
      return cons(boxString("\nif (globalTrace)\n    printf(\""), cons(id(name), cons(boxString(" at "), cons(id(getTag(name, boxString("filename"))), cons(boxString(":"), cons(id(getTag(name, boxString("line"))), cons(boxString(" (%s)\\n\", caller);\n"), null)))))));

    };

  };

}


function ansi3FunctionStackTrace(name) {
  
  if (releaseMode) {
    return emptyList();

  } else {
    if (inList(name, NoStackTrace_list())) {
      return emptyList();

    } else {
      return cons(boxString("\n  StackTraceMove(\"in\", \""), cons(id(getTag(name, boxString("filename"))), cons(boxString("\", \""), cons(id(name), cons(boxString("\", \""), cons(id(getTag(name, boxString("line"))), cons(boxString("\" );\n"), null)))))));

    };

  };

}


function ansi3Function(node) {
    let name = null;

  name = second(node);

  if (isNil(node)) {
    return emptyList();

  } else {
    return cons(id(listNewLine(0)), cons(id(listNewLine(0)), cons(id(ansi3TypeMap(first(node))), cons(boxString(" "), cons(id(second(node)), cons(boxString("("), cons(id(ansi3FunctionArgs(third(node))), cons(boxString(") {"), cons(id(listNewLine(1)), cons(id(ansi3Declarations(cdr(fourth(node)), 1)), cons(id(ansi3FunctionTrace(name)), cons(id(ansi3FunctionStackTrace(name)), cons(id(ansi3Body(cdr(fifth(node)), 1, stringify(name))), cons(boxString("\n}\n"), null))))))))))))));

  };

}


function ansi3ForwardDeclaration(node) {
  
  if (isNil(node)) {
    return emptyList();

  } else {
    return cons(boxString("\n"), cons(id(ansi3TypeMap(first(node))), cons(boxString(" "), cons(id(second(node)), cons(boxString("("), cons(id(ansi3FunctionArgs(third(node))), cons(boxString(");"), null)))))));

  };

}


function ansi3ForwardDeclarations(tree) {
  
  if (isEmpty(tree)) {
    return emptyList();

  } else {
    return cons(id(ansi3ForwardDeclaration(car(tree))), cons(id(ansi3ForwardDeclarations(cdr(tree))), null));

  };

}


function ansi3Functions(tree) {
  
  if (isEmpty(tree)) {
    return emptyList();

  } else {
    return cons(id(ansi3Function(car(tree))), cons(id(ansi3Functions(cdr(tree))), null));

  };

}


function ansi3Includes(nodes) {
  
  return cons(boxString("\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\n#include <unistd.h>\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\nbool releaseMode = false;\n\n"), cons(boxString("void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n"), null));

}


function ansi3TypeDecl(l) {
  
  if (greaterthan(listLength(l), 2)) {
    return cons(id(boxString(stringIndent(1))), cons(id(second(l)), cons(boxString(" "), cons(id(ansi3TypeMap(listLast(l))), cons(boxString(" "), cons(id(first(l)), cons(boxString(";\n"), null)))))));

  } else {
    return cons(id(boxString(stringIndent(1))), cons(id(ansi3TypeMap(listLast(l))), cons(boxString(" "), cons(id(car(l)), cons(boxString(";\n"), null)))));

  };

}


function ansi3StructComponents(node) {
  
  if (isEmpty(node)) {
    return emptyList();

  } else {
    return cons(id(ansi3TypeDecl(car(node))), cons(id(ansi3StructComponents(cdr(node))), null));

  };

}


function ansi3Struct(node) {
  
  return ansi3StructComponents(cdr(node));

}


function ansi3TypeMap(aSym) {
    let symMap = null;

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), null));

  if (truthy(assoc(stringify(aSym), symMap))) {
    return cdr(assoc(stringify(aSym), symMap));

  } else {
    return aSym;

  };

}


function ansi3FuncMap(aSym) {
    let symMap = null;

  if (equalString("symbol", boxType(aSym))) {
    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), null)))))));

    if (truthy(assoc(stringify(aSym), symMap))) {
      return cdr(assoc(stringify(aSym), symMap));

    } else {
      return aSym;

    };

  } else {
    return aSym;

  };

}


function ansi3Type(node) {
  
  if (isList(second(node))) {
    return cons(boxString("\ntypedef struct "), cons(id(first(node)), cons(boxString(" {\n"), cons(id(ansi3Struct(second(node))), cons(boxString("\n} "), cons(id(first(node)), cons(boxString(";\n"), null)))))));

  } else {
    return cons(boxString("typedef "), cons(id(ansi3TypeDecl(node)), null));

  };

}


function ansi3Types(nodes) {
  
  if (isEmpty(nodes)) {
    return emptyList();

  } else {
    return cons(id(ansi3Type(car(nodes))), cons(id(ansi3Types(cdr(nodes))), null));

  };

}


function ansi3LoadProgram(filename) {
    let tree = null;
  let replace = null;

  tree = loadQuon(filename);

  tree = buildProg(cons(boxString("q/shims/ansi3.qon"), getIncludes(tree)), getTypes(tree), getFunctions(tree));

  tree = loadIncludes(tree, null);

  tree = macrowalk(tree);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), null));

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

  return tree;

}


function ansi3ProgramTree(tree) {
  
  return cons(id(ansi3Includes(cdr(first(tree)))), cons(id(ansi3Types(cdr(second(tree)))), cons(boxString("Box* globalStackTrace = NULL;\n"), cons(boxString("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n"), cons(id(ansi3ForwardDeclarations(cdr(third(tree)))), cons(boxString("\n\n//End forward declarations\n\n"), cons(id(ansi3Functions(cdr(third(tree)))), cons(boxString("\n"), null))))))));

}


function ansi3Program(tree) {
  
  return ListToString(flatten(ansi3ProgramTree(tree)), 0, true, false);

}


function ansi3CompileString(filename) {
  
  return ansi3Program(ansi3LoadProgram(filename));

}


function ansi3Compile(filename) {
  
  printStringTree(ansi3ProgramTree(ansi3LoadProgram(filename)));

  fprintf(stderr, "//Done printing program\n");

}


function dollar() {
  
  return character(36);

}


function atsymbol() {
  
  return character(64);

}


function singleQuote() {
  
  return "'";

}


function escapedSingleQuote() {
  
  return "\\'";

}


function backslash() {
  
  return character(92);

}


function escapedDollar() {
  
  return StringListJoin(cons(boxString(backslash()), cons(boxString(dollar()), null)), "");

}


function escapedAtSign() {
  
  return StringListJoin(cons(boxString(backslash()), cons(boxString(atsymbol()), null)), "");

}


function escapeSingleQuotes(s) {
  
  return stringReplace(singleQuote(), escapedSingleQuote(), s);

}


function escapePerlString(s) {
  
  return stringReplace(atsymbol(), escapedAtSign(), stringReplace(dollar(), escapedDollar(), s));

}


function getGlobalVariables() {
  
  return cons(id(boxSymbol("stderr")), cons(id(boxSymbol("true")), cons(id(boxSymbol("false")), cons(id(boxSymbol("releaseMode")), cons(id(boxSymbol("caller")), cons(id(boxSymbol("globalTrace")), cons(id(boxSymbol("globalStepTrace")), cons(id(boxSymbol("globalStackTrace")), cons(id(boxSymbol("globalArgsCount")), cons(id(boxSymbol("globalArgs")), cons(id(boxSymbol("quonGlobalArgs")), null)))))))))));

}


function collectVariables(args, decls) {
    let variables = null;
  let decl = null;

  variables = collectVariablesFromArgs(args);

  variables = appendVariables(variables, collectVariablesFromDecls(decls));

  variables = appendVariables(variables, getGlobalVariables());

  return variables;

}


function perlGlobalVariables() {
  
  return cons(boxString("our "), cons(boxString(dollar()), cons(boxString("globalArgsCount;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("globalArgs;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("releaseMode;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("globalTrace;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("globalStepTrace;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("globalStackTrace;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("caller;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("false = 0;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("true = 1;\n"), cons(boxString("my "), cons(boxString(dollar()), cons(boxString("stderr = \\*STDERR;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("quonGlobalArgs;\n"), null)))))))))))))))))))))))))))))))));

}


function perlMainEntry() {
  
  return cons(boxString("\n# Main entry point\n"), cons(boxString(dollar()), cons(boxString("globalArgsCount = scalar("), cons(boxString(atsymbol()), cons(boxString("ARGV) + 1;\n"), cons(boxString(dollar()), cons(boxString("globalArgs = \\"), cons(boxString(atsymbol()), cons(boxString("ARGV;\n"), cons(boxString("unshift "), cons(boxString(atsymbol()), cons(boxString(dollar()), cons(boxString("globalArgs, 'fixmeprogname' ;\n"), cons(boxString(dollar()), cons(boxString("quonGlobalArgs = [];\n"), cons(boxString("for my "), cons(boxString(dollar()), cons(boxString("arg ("), cons(boxString(atsymbol()), cons(boxString(dollar()), cons(boxString("globalArgs) {\n"), cons(boxString("    push "), cons(boxString(atsymbol()), cons(boxString(dollar()), cons(boxString("quonGlobalArgs, {car => "), cons(boxString(dollar()), cons(boxString("arg, cdr => undef};\n"), cons(boxString("}\n"), cons(boxString("for (my "), cons(boxString(dollar()), cons(boxString("i = scalar("), cons(boxString(atsymbol()), cons(boxString(dollar()), cons(boxString("quonGlobalArgs) - 1; "), cons(boxString(dollar()), cons(boxString("i >= 0; "), cons(boxString(dollar()), cons(boxString("i--) {\n"), cons(boxString("    "), cons(boxString(dollar()), cons(boxString("quonGlobalArgs->["), cons(boxString(dollar()), cons(boxString("i]->{cdr} = "), cons(boxString(dollar()), cons(boxString("quonGlobalArgs->["), cons(boxString(dollar()), cons(boxString("i + 1];\n"), cons(boxString("}\n"), cons(boxString("*stderr = *STDERR;\n"), cons(boxString("sub fprintf { my "), cons(boxString(dollar()), cons(boxString("f = shift; printf "), cons(boxString(dollar()), cons(boxString("f "), cons(boxString(atsymbol()), cons(boxString("_ }\n"), cons(boxString("start();\n"), null)))))))))))))))))))))))))))))))))))))))))))))))))))))))));

}


function collectVariablesFromArgs(args) {
    let variables = null;

  if (isNil(args)) {
    return variables;

  } else {
    if (equalString(stringify(first(args)), "list")) {
      variables = cons(second(args), variables);

      return appendVariables(variables, collectVariablesFromArgs(cddr(args)));

    } else {
      variables = cons(second(args), variables);

      return appendVariables(variables, collectVariablesFromArgs(cddr(args)));

    };

  };

}


function collectVariablesFromDecls(decls) {
    let variables = null;
  let decl = null;

  if (isNil(decls)) {
    return variables;

  } else {
    decl = car(decls);

    variables = cons(second(decl), variables);

    return appendVariables(variables, collectVariablesFromDecls(cdr(decls)));

  };

}


function appendVariables(vars1, vars2) {
  
  if (isNil(vars2)) {
    return vars1;

  } else {
    vars1 = cons(car(vars2), vars1);

    return appendVariables(vars1, cdr(vars2));

  };

}


function perlFunctionArgs(tree) {
  
  if (isEmpty(tree)) {
    return emptyList();

  } else {
    if (isNil(cddr(tree))) {
      return cons(id(boxString(dollar())), cons(id(second(tree)), null));

    } else {
      return cons(id(boxString(dollar())), cons(id(second(tree)), cons(boxString(", "), cons(id(perlFunctionArgs(cddr(tree))), null))));

    };

  };

}


function perlAtom(tree, variables) {
  
  if (equalString("string", boxType(tree))) {
    return cons(boxString("\""), cons(id(boxString(escapePerlString(stringify(tree)))), cons(boxString("\""), null)));

  } else {
    return cons(id(perlFuncMap(tree, variables)), null);

  };

}


function perlExpression(tree, indent, variables) {
    let thing = null;

  if (notBool(isList(tree))) {
    return perlAtom(tree, variables);

  } else {
    if (equal(1, listLength(tree))) {
      if (equalBox(boxString("return"), car(tree))) {
        return cons(id(perlFuncMap(car(tree), variables)), null);

      } else {
        return cons(id(perlFuncMap(car(tree), variables)), cons(boxString("()"), null));

      };

    } else {
      thing = first(tree);

      if (equalBox(boxSymbol("get-struct"), thing)) {
        return cons(id(boxString(dollar())), cons(id(second(tree)), cons(boxString("->{"), cons(id(third(tree)), cons(boxString("}"), null)))));

      } else {
        if (equalBox(boxSymbol("new"), thing)) {
          return cons(boxString("{}"), null);

        } else {
          if (equalBox(boxSymbol("passthrough"), thing)) {
            return cons(id(second(tree)), null);

          } else {
            if (equalBox(boxSymbol("binop"), thing)) {
              return cons(boxString("("), cons(id(perlExpression(third(tree), indent, variables)), cons(boxString(" "), cons(id(second(tree)), cons(boxString(" "), cons(id(perlExpression(fourth(tree), indent, variables)), cons(boxString(")"), null)))))));

            } else {
              return cons(id(perlFuncMap(car(tree), variables)), cons(boxString("("), cons(id(perlRecurList(cdr(tree), indent, variables)), cons(boxString(")"), null))));

            };

          };

        };

      };

    };

  };

}


function perlRecurList(expr, indent, variables) {
  
  if (isEmpty(expr)) {
    return emptyList();

  } else {
    if (isNil(cdr(expr))) {
      return perlExpression(car(expr), indent, variables);

    } else {
      return cons(id(perlExpression(car(expr), indent, variables)), cons(boxString(", "), cons(id(perlRecurList(cdr(expr), indent, variables)), null)));

    };

  };

}


function perlSet(node, indent, variables) {
  
  return cons(id(listNewLine(indent)), cons(id(perlFuncMap(second(node), variables)), cons(boxString(" = "), cons(id(perlExpression(third(node), indent, variables)), null))));

}


function perlSetStruct(node, indent, variables) {
  
  return cons(id(listNewLine(indent)), cons(id(perlFuncMap(second(node), variables)), cons(boxString("->{"), cons(id(third(node)), cons(boxString("} = "), cons(id(perlExpression(fourth(node), indent, variables)), null))))));

}


function perlReturn(node, indent, variables) {
  
  if (greaterthan(listLength(node), 1)) {
    return cons(id(listNewLine(indent)), cons(boxString("return "), cons(id(perlExpression(cadr(node), indent, variables)), null)));

  } else {
    return cons(id(listNewLine(indent)), cons(boxString("return"), null));

  };

}


function perlIf(node, indent, variables) {
  
  return cons(id(listNewLine(indent)), cons(boxString("if ( "), cons(id(perlExpression(second(node), 0, variables)), cons(boxString(" ) {"), cons(id(perlBody(cdr(third(node)), add1(indent), variables)), cons(id(listNewLine(indent)), cons(boxString("} else {"), cons(id(perlBody(cdr(fourth(node)), add1(indent), variables)), cons(id(listNewLine(indent)), cons(boxString("}"), null))))))))));

}


function perlStatement(node, indent, variables) {
  
  if (equalBox(boxString("set"), first(node))) {
    return cons(id(perlSet(node, indent, variables)), cons(boxString(";\n"), null));

  } else {
    if (equalBox(boxString("set-struct"), first(node))) {
      return cons(id(perlSetStruct(node, indent, variables)), cons(boxString(";\n"), null));

    } else {
      if (equalBox(boxString("if"), first(node))) {
        return cons(id(perlIf(node, indent, variables)), cons(boxString(";\n"), null));

      } else {
        if (equalBox(boxString("return"), first(node))) {
          return cons(id(perlReturn(node, indent, variables)), cons(boxString(";\n"), null));

        } else {
          return cons(id(listNewLine(indent)), cons(id(perlExpression(node, indent, variables)), cons(boxString(";\n"), null)));

        };

      };

    };

  };

}


function perlBody(tree, indent, variables) {
    let code = null;

  if (isEmpty(tree)) {
    return emptyList();

  } else {
    code = car(tree);

    return cons(id(perlStatement(code, indent, variables)), cons(id(perlBody(cdr(tree), indent, variables)), null));

  };

}


function perlGetStruct(node, indent) {
  
  return cons(id(listNewLine(indent)), cons(id(boxString(dollar())), cons(id(first(node)), cons(boxString("->{"), cons(id(second(node)), cons(boxString("}"), null))))));

}


function perlDeclarations(decls, indent, variables) {
    let decl = null;

  if (isEmpty(decls)) {
    return emptyList();

  } else {
    decl = car(decls);

    return cons(boxString("my "), cons(id(boxString(dollar())), cons(id(second(decl)), cons(boxString(" = "), cons(id(perlExpression(third(decl), indent, variables)), cons(boxString(";\n"), cons(id(perlDeclarations(cdr(decls), indent, variables)), null)))))));

  };

}


function perlFunction(node) {
    let name = null;
  let variables = null;
  let args = null;
  let decls = null;

  name = second(node);

  if (isNil(node)) {
    return emptyList();

  } else {
    args = third(node);

    decls = cdr(fourth(node));

    variables = collectVariables(args, decls);

    return cons(boxString("\n\n# Function "), cons(id(name), cons(boxString(" from line "), cons(id(getTag(name, boxString("line"))), cons(id(listNewLine(0)), cons(id(listNewLine(0)), cons(boxString("sub "), cons(id(perlFuncMap(second(node), null)), cons(boxString(" {"), cons(id(listNewLine(1)), cons(boxString("my ("), cons(id(perlFunctionArgs(args)), cons(boxString(") = "), cons(id(boxString(atsymbol())), cons(boxString("_;"), cons(id(listNewLine(1)), cons(id(perlDeclarations(decls, 1, variables)), cons(id(perlBody(cdr(fifth(node)), 1, variables)), cons(boxString("\n}\n"), null)))))))))))))))))));

  };

}


function perlForwardDeclaration(node) {
  
  if (isNil(node)) {
    return emptyList();

  } else {
    return cons(boxString("sub "), cons(id(perlFuncMap(second(node), null)), cons(boxString(";\n"), null)));

  };

}


function perlForwardDeclarations(tree) {
  
  if (isEmpty(tree)) {
    return emptyList();

  } else {
    return cons(id(perlForwardDeclaration(car(tree))), cons(id(perlForwardDeclarations(cdr(tree))), null));

  };

}


function perlFunctions(tree) {
  
  if (isEmpty(tree)) {
    return emptyList();

  } else {
    return cons(id(perlFunction(car(tree))), cons(id(perlFunctions(cdr(tree))), null));

  };

}


function perlIncludes(nodes) {
  
  return cons(boxString("use strict;\n"), cons(boxString("use warnings;\n"), cons(boxString("use v5.10;\n\n"), cons(boxString("no warnings 'recursion';\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("^M = 10_000;\n"), null)))))));

}


function perlTypes(nodes) {
  
  return emptyList();

}


function perlTypeMap(aSym) {
    let symMap = null;

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("array"), alistCons(boxSymbol("string"), boxSymbol("string"), null));

  if (truthy(assoc(stringify(aSym), symMap))) {
    return cdr(assoc(stringify(aSym), symMap));

  } else {
    return aSym;

  };

}


function perlFuncMap(aSym, variables) {
    let symMap = null;

  if (equalString("symbol", boxType(aSym))) {
    if (inList(aSym, variables)) {
      return boxSymbol(stringConcatenate(dollar(), stringify(aSym)));

    } else {
      symMap = alistCons(boxSymbol("sub"), boxSymbol("subtract"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("substr"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("length"), alistCons(boxSymbol("say"), boxSymbol("say_"), alistCons(boxSymbol("nil"), boxSymbol("undef"), null)))))))));

      if (truthy(assoc(stringify(aSym), symMap))) {
        return cdr(assoc(stringify(aSym), symMap));

      } else {
        return aSym;

      };

    };

  } else {
    return aSym;

  };

}


function perlLoadProgram(filename) {
    let tree = null;
  let replace = null;

  tree = loadQuon(filename);

  tree = insertInclude(tree, "q/shims/perl.qon");

  tree = loadIncludes(tree, null);

  tree = macrowalk(tree);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), null));

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

  return tree;

}


function perlProgramTree(tree) {
  
  return cons(id(perlIncludes(cdr(first(tree)))), cons(id(perlTypes(cdr(second(tree)))), cons(id(perlGlobalVariables()), cons(boxString("\n# Forward declarations\n"), cons(id(perlForwardDeclarations(cdr(third(tree)))), cons(boxString("\n# End forward declarations\n"), cons(id(perlFunctions(cdr(third(tree)))), cons(id(perlMainEntry()), cons(boxString("\n"), null)))))))));

}


function perlProgram(tree) {
  
  return ListToString(flatten(perlProgramTree(tree)), 0, true, false);

}


function perlCompileString(filename) {
  
  return perlProgram(perlLoadProgram(filename));

}


function perlCompile(filename) {
    let tree = null;
  let replace = null;

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


function readSexpr(aStr, filename) {
    let tokens = null;
  let as = null;
  let tree = null;

  tokens = emptyList();

  tokens = filterTokens(filterVoid(scan(aStr, 0, 1, 0, 0, filename)));

  parserValidateParens(tokens, null, filename);

  as = sexprTree(tokens);

  parserValidateRoot(as, filename);

  tree = car(as);

  parserValidateProgram(tree, filename);

  return tree;

}


function parserPanicAt(filename, token, message) {
  
  if (isNil(token)) {
    printf("Parse error in %s: %s\n", filename, message);

  } else {
    printf("Parse error in %s:%s:%s: %s\n", stringify(getTagFail(token, boxString("filename"), boxString(filename))), stringify(getTagFail(token, boxString("line"), boxString("?"))), stringify(getTagFail(token, boxString("column"), boxString("?"))), message);

  };

  exit(1);

}


function parserPanicAtNode(filename, node, message) {
  
  if (isNil(node)) {
    parserPanicAt(filename, null, message);

  } else {
    if (isList(node)) {
      if (isEmpty(node)) {
        parserPanicAt(filename, null, message);

      } else {
        parserPanicAt(filename, car(node), message);

      };

    } else {
      parserPanicAt(filename, node, message);

    };

  };

}


function parserSymbolIs(b, name) {
  
  if (isNil(b)) {
    return false;

  } else {
  };

  if (isList(b)) {
    return false;

  } else {
  };

  if (equalString("symbol", boxType(b))) {
    return equalString(name, stringify(b));

  } else {
    return false;

  };

}


function parserListStartsWith(node, name) {
  
  if (isNil(node)) {
    return false;

  } else {
  };

  if (isList(node)) {
    if (isEmpty(node)) {
      return false;

    } else {
      return parserSymbolIs(car(node), name);

    };

  } else {
    return false;

  };

}


function parserValidateParens(tokens, openStack, filename) {
    let token = null;

  if (isEmpty(tokens)) {
    if (isEmpty(openStack)) {
      return;

    } else {
      parserPanicAt(filename, car(openStack), "missing ')'");

    };

  } else {
    token = car(tokens);

    if (isOpenBrace(token)) {
      parserValidateParens(cdr(tokens), cons(token, openStack), filename);

    } else {
      if (isCloseBrace(token)) {
        if (isEmpty(openStack)) {
          parserPanicAt(filename, token, "unexpected ')'");

        } else {
          parserValidateParens(cdr(tokens), cdr(openStack), filename);

        };

      } else {
        parserValidateParens(cdr(tokens), openStack, filename);

      };

    };

  };

}


function parserValidateRoot(roots, filename) {
  
  if (equal(listLength(roots), 1)) {
    return;

  } else {
    if (isEmpty(roots)) {
      parserPanicAt(filename, null, "expected one top-level program form");

    } else {
      parserPanicAtNode(filename, second(roots), "extra top-level form after program");

    };

  };

}


function parserValidateSection(section, name, filename) {
  
  if (isNil(section)) {
    parserPanicAt(filename, null, "missing program section");

  } else {
  };

  if (isList(section)) {
  } else {
    parserPanicAtNode(filename, section, "program section must be a list");

  };

  if (parserListStartsWith(section, name)) {
    return;

  } else {
    parserPanicAtNode(filename, section, stringConcatenate("expected program section ", name));

  };

}


function parserIsFunctionDefinition(node) {
  
  if (isNil(node)) {
    return false;

  } else {
  };

  if (isList(node)) {
  } else {
    return false;

  };

  if (equal(listLength(node), 5)) {
  } else {
    return false;

  };

  if (isList(first(node))) {
    return false;

  } else {
  };

  if (isList(second(node))) {
    return false;

  } else {
  };

  if (isList(third(node))) {
  } else {
    return false;

  };

  if (parserListStartsWith(fourth(node), "declare")) {
  } else {
    return false;

  };

  if (parserListStartsWith(fifth(node), "body")) {
    return true;

  } else {
    return false;

  };

}


function parserRejectFunctionDefinitions(node, filename) {
  
  if (isNil(node)) {
    return;

  } else {
  };

  if (parserIsFunctionDefinition(node)) {
    parserPanicAtNode(filename, node, "function definition is not allowed here");

  } else {
  };

  if (isList(node)) {
    parserRejectFunctionDefinitionsList(node, filename);

  } else {
    return;

  };

}


function parserRejectFunctionDefinitionsList(nodes, filename) {
  
  if (isEmpty(nodes)) {
    return;

  } else {
    parserRejectFunctionDefinitions(car(nodes), filename);

    parserRejectFunctionDefinitionsList(cdr(nodes), filename);

  };

}


function parserValidateProgram(program, filename) {
  
  if (isNil(program)) {
    parserPanicAt(filename, null, "empty program");

  } else {
  };

  if (isList(program)) {
  } else {
    parserPanicAtNode(filename, program, "program must be a list");

  };

  if (equal(listLength(program), 3)) {
  } else {
    if (equal(listLength(program), 4)) {
    } else {
      parserPanicAtNode(filename, program, "program must contain includes, types, and functions sections");

    };

  };

  parserValidateSection(first(program), "includes", filename);

  parserValidateSection(second(program), "types", filename);

  parserValidateSection(third(program), "functions", filename);

  parserRejectFunctionDefinitions(cdr(first(program)), filename);

  parserRejectFunctionDefinitions(cdr(second(program)), filename);

  if (equal(listLength(program), 4)) {
    parserValidateSection(fourth(program), "globals", filename);

    parserRejectFunctionDefinitions(cdr(fourth(program)), filename);

  } else {
  };

  parserValidateFunctions(cdr(third(program)), filename);

}


function parserValidateFunctions(functions, filename) {
    let fn = null;

  if (isEmpty(functions)) {
    return;

  } else {
    fn = car(functions);

    if (parserIsFunctionDefinition(fn)) {
      parserValidateFunction(fn, filename);

    } else {
      parserPanicAtNode(filename, fn, "invalid function definition");

    };

    parserValidateFunctions(cdr(functions), filename);

  };

}


function parserValidateFunction(fn, filename) {
  
  parserRejectFunctionDefinitions(third(fn), filename);

  parserRejectFunctionDefinitions(cdr(fourth(fn)), filename);

  parserValidateBody(cdr(fifth(fn)), filename);

}


function parserValidateBody(forms, filename) {
  
  if (isEmpty(forms)) {
    return;

  } else {
    parserValidateStatement(car(forms), filename);

    parserValidateBody(cdr(forms), filename);

  };

}


function parserValidateStatement(stmt, filename) {
  
  if (isNil(stmt)) {
    return;

  } else {
  };

  if (isList(stmt)) {
  } else {
    parserPanicAtNode(filename, stmt, "statement must be a list");

  };

  if (isEmpty(stmt)) {
    return;

  } else {
  };

  if (parserIsFunctionDefinition(stmt)) {
    parserPanicAtNode(filename, stmt, "function definition nested inside body");

  } else {
  };

  if (parserListStartsWith(stmt, "if")) {
    parserValidateIf(stmt, filename);

    return;

  } else {
  };

  if (parserListStartsWith(stmt, "then")) {
    parserPanicAtNode(filename, stmt, "then branch outside if");

  } else {
  };

  if (parserListStartsWith(stmt, "else")) {
    parserPanicAtNode(filename, stmt, "else branch outside if");

  } else {
  };

  if (parserListStartsWith(stmt, "declare")) {
    parserPanicAtNode(filename, stmt, "declare block outside function header");

  } else {
  };

  if (parserListStartsWith(stmt, "body")) {
    parserPanicAtNode(filename, stmt, "body block nested inside body");

  } else {
  };

  if (parserListStartsWith(stmt, "functions")) {
    parserPanicAtNode(filename, stmt, "functions section nested inside body");

  } else {
  };

  if (parserListStartsWith(stmt, "types")) {
    parserPanicAtNode(filename, stmt, "types section nested inside body");

  } else {
  };

  if (parserListStartsWith(stmt, "includes")) {
    parserPanicAtNode(filename, stmt, "includes section nested inside body");

  } else {
  };

  if (parserListStartsWith(stmt, "return")) {
    parserValidateReturn(stmt, filename);

    return;

  } else {
  };

  if (parserListStartsWith(stmt, "set")) {
    parserValidateSet(stmt, filename);

    return;

  } else {
  };

  if (parserListStartsWith(stmt, "set-struct")) {
    parserValidateSetStruct(stmt, filename);

    return;

  } else {
  };

  parserValidateExpression(stmt, filename);

}


function parserValidateReturn(stmt, filename) {
  
  if (greaterthan(listLength(stmt), 2)) {
    parserPanicAtNode(filename, stmt, "return takes zero or one value");

  } else {
  };

  if (equal(listLength(stmt), 2)) {
    parserValidateExpression(second(stmt), filename);

  } else {
    return;

  };

}


function parserValidateSet(stmt, filename) {
  
  if (equal(listLength(stmt), 3)) {
    parserValidateExpression(second(stmt), filename);

    parserValidateExpression(third(stmt), filename);

  } else {
    parserPanicAtNode(filename, stmt, "set takes a target and value");

  };

}


function parserValidateSetStruct(stmt, filename) {
  
  if (equal(listLength(stmt), 4)) {
    parserValidateExpression(second(stmt), filename);

    parserValidateExpression(third(stmt), filename);

    parserValidateExpression(fourth(stmt), filename);

  } else {
    parserPanicAtNode(filename, stmt, "set-struct takes a target, field, and value");

  };

}


function parserValidateIf(stmt, filename) {
  
  if (equal(listLength(stmt), 4)) {
  } else {
    parserPanicAtNode(filename, stmt, "if must contain condition, then, and else");

  };

  parserValidateExpression(second(stmt), filename);

  parserValidateBranch(third(stmt), "then", filename);

  parserValidateBranch(fourth(stmt), "else", filename);

}


function parserValidateBranch(branch, name, filename) {
  
  if (parserListStartsWith(branch, name)) {
    parserValidateBody(cdr(branch), filename);

  } else {
    parserPanicAtNode(filename, branch, stringConcatenate("expected ", name));

  };

}


function parserValidateExpression(expr, filename) {
  
  if (isNil(expr)) {
    return;

  } else {
  };

  if (isList(expr)) {
  } else {
    return;

  };

  if (isEmpty(expr)) {
    return;

  } else {
  };

  if (parserIsFunctionDefinition(expr)) {
    parserPanicAtNode(filename, expr, "function definition nested inside expression");

  } else {
  };

  if (parserListStartsWith(expr, "if")) {
    parserValidateIf(expr, filename);

    return;

  } else {
  };

  if (parserListStartsWith(expr, "then")) {
    parserPanicAtNode(filename, expr, "then branch outside if");

  } else {
  };

  if (parserListStartsWith(expr, "else")) {
    parserPanicAtNode(filename, expr, "else branch outside if");

  } else {
  };

  if (parserListStartsWith(expr, "declare")) {
    parserPanicAtNode(filename, expr, "declare block inside expression");

  } else {
  };

  if (parserListStartsWith(expr, "body")) {
    parserPanicAtNode(filename, expr, "body block inside expression");

  } else {
  };

  if (parserListStartsWith(expr, "functions")) {
    parserPanicAtNode(filename, expr, "functions section inside expression");

  } else {
  };

  if (parserListStartsWith(expr, "types")) {
    parserPanicAtNode(filename, expr, "types section inside expression");

  } else {
  };

  if (parserListStartsWith(expr, "includes")) {
    parserPanicAtNode(filename, expr, "includes section inside expression");

  } else {
  };

  parserValidateExpressionList(expr, filename);

}


function parserValidateExpressionList(exprs, filename) {
  
  if (isEmpty(exprs)) {
    return;

  } else {
    parserValidateExpression(car(exprs), filename);

    parserValidateExpressionList(cdr(exprs), filename);

  };

}


function sexprTree(l) {
    let b = null;

  if (isEmpty(l)) {
    return emptyList();

  } else {
    b = car(l);

    if (isOpenBrace(b)) {
      return cons(sexprTree(cdr(l)), sexprTree(skipList(cdr(l))));

    } else {
      if (isCloseBrace(b)) {
        return emptyList();

      } else {
        return setTag(boxString("line"), getTagFail(b, boxString("line"), boxInt(-1)), cons(b, sexprTree(cdr(l))));

      };

    };

  };

}


function loadQuon(filename) {
    let programBox = null;
  let programStr = "";
  let tree = null;

  programBox = read_file(filename);

  if (isNil(programBox)) {
    fprintf(stderr, "Could not read file: ");

    fprintf(stderr, filename);

    fprintf(stderr, "\n");

    exit(1);

  } else {
  };

  programStr = unBoxString(programBox);

  tree = readSexpr(programStr, filename);

  return tree;

}


function getIncludes(program) {
  
  return cdr(first(program));

}


function getTypes(program) {
  
  return cdr(second(program));

}


function getFunctions(program) {
  
  return cdr(third(program));

}


function insertInclude(tree, extra) {
    let newProg = null;
  let includes = null;
  let types = null;
  let functions = null;
  let boxedExtra = null;
  let newIncludes = null;

  if (isNil(tree)) {
    printf("insertInlcude: tree is nil");

    return null;

  } else {
    includes = getIncludes(tree);

    types = getTypes(tree);

    functions = getFunctions(tree);

    boxedExtra = boxSymbol(extra);

    newIncludes = cons(boxedExtra, includes);

    newProg = buildProg(newIncludes, types, functions);

    return newProg;

  };

}


function stringInList(item, l) {
  
  if (isNil(l)) {
    return false;

  } else {
    if (equalString(item, stringify(car(l)))) {
      return true;

    } else {
      return stringInList(item, cdr(l));

    };

  };

}


function appendMissingIncludes(candidates, pending, seen) {
    let candidate = null;
  let candidateFile = "";

  if (isNil(candidates)) {
    return pending;

  } else {
    candidate = car(candidates);

    candidateFile = stringify(candidate);

    if (orBool(stringInList(candidateFile, seen), stringInList(candidateFile, pending))) {
      return appendMissingIncludes(cdr(candidates), pending, seen);

    } else {
      return cons(candidate, appendMissingIncludes(cdr(candidates), pending, seen));

    };

  };

}


function loadIncludes(tree, seen) {
    let newProg = null;
  let includeFile = "";
  let functionsCombined = null;
  let typesCombined = null;
  let includeTree = null;
  let pendingIncludes = null;
  let nextIncludes = null;
  let nextSeen = null;
  let contentsBox = null;
  let contents = "";

  if (greaterthan(listLength(getIncludes(tree)), 0)) {
    includeFile = stringify(first(getIncludes(tree)));

    if (stringInList(includeFile, seen)) {
      newProg = buildProg(cdr(getIncludes(tree)), getTypes(tree), getFunctions(tree));

      return loadIncludes(newProg, seen);

    } else {
    };

    nextSeen = cons(boxString(includeFile), seen);

    contentsBox = read_file(includeFile);

    if (isNil(contentsBox)) {
      fprintf(stderr, "Could not read include file: ");

      fprintf(stderr, includeFile);

      fprintf(stderr, "\n");

      exit(1);

      return null;

    } else {
    };

    contents = unBoxString(contentsBox);

    includeTree = readSexpr(contents, includeFile);

    if (isNil(includeTree)) {
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

    };

  } else {
    return tree;

  };

}


function buildProg(includes, types, functions) {
    let program = null;

  includes = cons(boxSymbol("includes"), includes);

  types = cons(boxSymbol("types"), types);

  functions = cons(boxSymbol("functions"), functions);

  program = cons(includes, cons(types, cons(functions, null)));

  return program;

}


function car(l) {
  
  if (isNil(l)) {
    printf("Cannot call car on empty list!\n");

    panic("Cannot call car on empty list!\n");

    return null;

  } else {
    assertType("list", l, 18, "q/lists.qon");

    if (isNil(l.car)) {
      return null;

    } else {
      return l.car;

    };

  };

}


function cdr(l) {
  
  if (isEmpty(l)) {
    printf("Attempt to cdr an empty list!!!!\n");

    panic("Attempt to cdr an empty list!!!!\n");

    return null;

  } else {
    return l.cdr;

  };

}


function cons(data, l) {
    let p = null;

  p = makePair();

  p.cdr = l;

  p.car = data;

  p.typ = "list";

  return p;

}


function caar(l) {
  
  return car(car(l));

}


function cadr(l) {
  
  return car(cdr(l));

}


function caddr(l) {
  
  return car(cdr(cdr(l)));

}


function cadddr(l) {
  
  return car(cdr(cdr(cdr(l))));

}


function caddddr(l) {
  
  return car(cdr(cdr(cdr(cdr(l)))));

}


function cddr(l) {
  
  return cdr(cdr(l));

}


function first(l) {
  
  return car(l);

}


function second(l) {
  
  return cadr(l);

}


function third(l) {
  
  return caddr(l);

}


function fourth(l) {
  
  return cadddr(l);

}


function fifth(l) {
  
  return caddddr(l);

}


function sixth(l) {
  
  return car(cdr(cdr(cdr(cdr(cdr(l))))));

}


function seventh(l) {
  
  return car(cdr(cdr(cdr(cdr(cdr(cdr(l)))))));

}


function eighth(l) {
  
  return car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(l))))))));

}


function ninth(l) {
  
  return car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(l)))))))));

}


function tenth(l) {
  
  return car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(l))))))))));

}


function eleventh(l) {
  
  return car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(l)))))))))));

}


function twelfth(l) {
  
  return car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(l))))))))))));

}


function rest(l) {
  
  return cdr(l);

}


function isList(b) {
  
  if (isNil(b)) {
    return true;

  } else {
    return equalString("list", b.typ);

  };

}


function emptyList() {
  
  return null;

}


function isEmpty(b) {
  
  if (isNil(b)) {
    return true;

  } else {
    return false;

  };

}


function listLength(l) {
  
  if (isEmpty(l)) {
    return 0;

  } else {
    return add1(listLength(cdr(l)));

  };

}


function alistCons(key, value, alist) {
  
  return cons(cons(key, value), alist);

}


function assoc(searchTerm, l) {
    let elem = null;

  assertType("list", l, 96, "q/lists.qon");

  if (isEmpty(l)) {
    return boxBool(false);

  } else {
    elem = car(l);

    assertType("list", elem, 102, "q/lists.qon");

    if (isEmpty(elem)) {
      return assoc(searchTerm, cdr(l));

    } else {
      if (false) {
        printf("Comparing %s and %s\n", searchTerm, stringify(car(elem)));

      } else {
        printf("");

      };

      if (equalString(searchTerm, stringify(car(elem)))) {
        return elem;

      } else {
        return assoc(searchTerm, cdr(l));

      };

    };

  };

}


function chooseBox(aType) {
  
  if (equalString("string", aType)) {
    return "boxString";

  } else {
    if (equalString("symbol", aType)) {
      return "boxSymbol";

    } else {
      if (equalString("bool", aType)) {
        return "boxBool";

      } else {
        if (equalString("int", aType)) {
          return "boxInt";

        } else {
          if (equalString("float", aType)) {
            return "boxFloat";

          } else {
            panic("Invalid type");

          };

        };

      };

    };

  };

  return "";

}


function mlistLiteral(b) {
  
  if (isNil(b)) {
    return null;

  } else {
    if (equalString("string", boxType(b))) {
      return b;

    } else {
      if (equalString("bool", boxType(b))) {
        return b;

      } else {
        if (equalString("int", boxType(b))) {
          return b;

        } else {
          if (equalString("symbol", boxType(b))) {
            return boxString(unBoxSymbol(b));

          } else {
            return boxString(stringConcatenate("Unsupported type in mlistLiteral: ", boxType(b)));

          };

        };

      };

    };

  };

}


function doMultiList(l) {
    let newlist = null;
  let ret = null;
  let elem = null;

  if (isNil(l)) {
    return cons(boxSymbol("nil"), null);

  } else {
    if (isEmpty(l)) {
      return null;

    } else {
      elem = first(l);

      newlist = cons(boxString(chooseBox(elem.typ)), cons(mlistLiteral(first(l)), newlist));

      ret = cons(cons(boxSymbol("cons"), cons(newlist, doMultiList(cdr(l)))), null);

      return ret;

    };

  };

}


function isDigit(val) {
  
  if (equal(string_length(val), 1)) {
    return stringContains("0123456789", val);

  } else {
    return false;

  };

}


function isUnsignedIntFrom(val, pos) {
    let len = 0;

  len = string_length(val);

  if (greaterthan(add1(pos), len)) {
    return true;

  } else {
    if (isDigit(sub_string(val, pos, 1))) {
      return isUnsignedIntFrom(val, add1(pos));

    } else {
      return false;

    };

  };

}


function isInt(val) {
    let len = 0;
  let firstLetter = "";

  len = string_length(val);

  if (equal(len, 0)) {
    return false;

  } else {
  };

  firstLetter = sub_string(val, 0, 1);

  if (equalString("-", firstLetter)) {
    if (equal(len, 1)) {
      return false;

    } else {
      return isUnsignedIntFrom(val, 1);

    };

  } else {
    return isUnsignedIntFrom(val, 0);

  };

}


function isFloatFrom(val, pos, seenDot, seenDigit, digitAfterDot) {
    let len = 0;
  let ch = "";

  len = string_length(val);

  if (greaterthan(add1(pos), len)) {
    return andBool(seenDot, andBool(seenDigit, digitAfterDot));

  } else {
  };

  ch = sub_string(val, pos, 1);

  if (isDigit(ch)) {
    return isFloatFrom(val, add1(pos), seenDot, true, orBool(digitAfterDot, seenDot));

  } else {
    if (equalString(".", ch)) {
      if (seenDot) {
        return false;

      } else {
        return isFloatFrom(val, add1(pos), true, seenDigit, false);

      };

    } else {
      return false;

    };

  };

}


function isFloat(val) {
    let len = 0;
  let firstLetter = "";

  len = string_length(val);

  if (equal(len, 0)) {
    return false;

  } else {
  };

  firstLetter = sub_string(val, 0, 1);

  if (equalString("-", firstLetter)) {
    if (equal(len, 1)) {
      return false;

    } else {
      return isFloatFrom(val, 1, false, false, false);

    };

  } else {
    return isFloatFrom(val, 0, false, false, false);

  };

}


function id(b) {
  
  return b;

}


function chooseBoxInterp(b) {
    let val = stringify(b);
  let firstLetter = sub_string(val, 0, 1);

  if (equalString("string", boxType(b))) {
    return "boxString";

  } else {
    if (equalString("\"", firstLetter)) {
      return "boxString";

    } else {
      if (equalString("true", val)) {
        return "boxBool";

      } else {
        if (equalString("false", val)) {
          return "boxBool";

        } else {
          if (isFloat(val)) {
            return "boxFloat";

          } else {
            if (isInt(val)) {
              return "boxInt";

            } else {
              return "id";

            };

          };

        };

      };

    };

  };

}


function doInterpolatedList(l) {
    let newlist = null;
  let ret = null;
  let elem = null;

  if (isNil(l)) {
    return cons(boxSymbol("nil"), null);

  } else {
    if (isEmpty(l)) {
      return null;

    } else {
      elem = first(l);

      newlist = cons(boxString(chooseBoxInterp(elem)), cons(first(l), newlist));

      ret = cons(cons(boxSymbol("cons"), cons(newlist, doInterpolatedList(cdr(l)))), null);

      return ret;

    };

  };

}


function doStringList(l) {
    let newlist = null;
  let ret = null;

  if (isNil(l)) {
    return cons(boxSymbol("nil"), null);

  } else {
    newlist = cons(boxSymbol("boxString"), cons(first(l), newlist));

    ret = cons(cons(boxSymbol("cons"), cons(newlist, doStringList(cdr(l)))), null);

    return ret;

  };

}


function doSymbolList(l) {
    let newlist = null;
  let ret = null;

  if (isNil(l)) {
    return cons(boxSymbol("nil"), null);

  } else {
    newlist = cons(boxSymbol("boxSymbol"), cons(first(l), newlist));

    ret = cons(cons(boxSymbol("cons"), cons(newlist, doSymbolList(cdr(l)))), null);

    return ret;

  };

}


function doBoxList(l) {
  
  if (isNil(l)) {
    return cons(boxSymbol("nil"), null);

  } else {
    return cons(cons(boxSymbol("cons"), cons(first(l), doBoxList(cdr(l)))), null);

  };

}


function concatLists(seq1, seq2) {
  
  if (isNil(seq1)) {
    return seq2;

  } else {
    return cons(car(seq1), concatLists(cdr(seq1), seq2));

  };

}


function alistKeys(alist) {
  
  if (isNil(alist)) {
    return null;

  } else {
    return cons(car(car(alist)), alistKeys(cdr(alist)));

  };

}


function display(l) {
  
  if (isEmpty(l)) {
    printf("nil ");

    return;

  } else {
    if (isList(l)) {
      printf("[");

      displayList(l, 0, true);

      printf("]");

    } else {
      displayList(l, 0, true);

    };

  };

}


function displayList(l, indent, first) {
    let val = null;

  if (isEmpty(l)) {
    return;

  } else {
    if (isList(l)) {
      if (isEmpty(l)) {
        return;

      } else {
        if (first) {
        } else {
          printf(" ");

        };

        val = car(l);

        if (isList(val)) {
          newLine(indent);

          printf("%s", openBrace());

          displayList(car(l), add1(indent), true);

          printf("%s", closeBrace());

          displayList(cdr(l), indent, false);

        } else {
          if (equalString("string", val.typ)) {
            printf("\"%s\"", unBoxString(val));

          } else {
            printf("%s", stringify(val));

          };

          displayList(cdr(l), indent, false);

        };

      };

    } else {
      if (equalString("string", l.typ)) {
        printf("\"%s\"", unBoxString(l));

      } else {
        printf("%s", stringify(l));

      };

    };

  };

}


function StringListJoinRec(l, sep) {
    let val = null;

  if (isEmpty(l)) {
    return "";

  } else {
    if (isList(l)) {
      if (isEmpty(l)) {
        return "";

      } else {
        if (equal(listLength(l), 1)) {
          return stringify(car(l));

        } else {
          return stringConcatenate(stringify(car(l)), stringConcatenate(sep, StringListJoinRec(cdr(l), sep)));

        };

      };

    } else {
      return "";

    };

  };

}


function StringListJoin(l, sep) {
    let val = null;

  if (greaterthan(listLength(l), 1)) {
    return stringConcatenate(stringify(car(l)), stringConcatenate(sep, StringListJoinRec(cdr(l), sep)));

  } else {
    return stringify(car(l));

  };

}


function ListToBoxString(l, indent) {
  
  return boxString(ListToString(l, indent, true, false));

}


function ListToString(l, indent, first, withNewLines) {
    let val = null;

  if (isEmpty(l)) {
    return "";

  } else {
    if (isList(l)) {
      if (isEmpty(l)) {
        return "";

      } else {
        val = car(l);

        if (isList(val)) {
          return StringListJoin(cons(boxString(stringify(tern(withNewLines, boxString("\n"), boxString(stringIndent(indent))))), cons(boxString(openBrace()), cons(boxString(" "), cons(boxString(ListToString(car(l), add1(indent), true, withNewLines)), cons(boxString(closeBrace()), cons(boxString(" "), cons(boxString(ListToString(cdr(l), indent, false, withNewLines)), null))))))), "");

        } else {
          return stringConcatenate(stringify(val), ListToString(cdr(l), indent, false, withNewLines));

        };

      };

    } else {
      return stringify(l);

    };

  };

}


function listReverse(l) {
  
  if (isNil(l)) {
    return null;

  } else {
    return cons(car(l), listReverse(cdr(l)));

  };

}


function inList(item, l) {
  
  if (isNil(l)) {
    return false;

  } else {
    if (equalBox(car(l), item)) {
      return true;

    } else {
      return inList(item, cdr(l));

    };

  };

}


function equalList(a, b) {
  
  if (isNil(a)) {
    if (isNil(b)) {
      return true;

    } else {
      return false;

    };

  } else {
  };

  if (isNil(b)) {
    if (isNil(a)) {
      return true;

    } else {
      return false;

    };

  } else {
  };

  if (equalBox(car(a), car(b))) {
    return equalList(cdr(a), cdr(b));

  } else {
    return false;

  };

}


function reverseRec(oldL, newL) {
  
  if (isEmpty(oldL)) {
    return newL;

  } else {
    return reverseRec(cdr(oldL), cons(first(oldL), newL));

  };

}


function reverseList(l) {
  
  return reverseRec(l, null);

}


function flatten(tree) {
  
  if (isEmpty(tree)) {
    return emptyList();

  } else {
    if (isList(car(tree))) {
      return concatLists(flatten(car(tree)), flatten(cdr(tree)));

    } else {
      return cons(car(tree), flatten(cdr(tree)));

    };

  };

}


function printStringTree(tree) {
    let val = null;

  if (isEmpty(tree)) {
    return;

  } else {
  };

  val = car(tree);

  if (isList(val)) {
    printStringTree(car(tree));

  } else {
    printf("%s", stringify(val));

  };

  printStringTree(cdr(tree));

}


function macrowalk(l) {
  
  if (isEmpty(l)) {
    return null;

  } else {
    if (isList(l)) {
      if (equalString(stringConcatenate("box", "List"), stringify(car(l)))) {
        return car(doBoxList(cdr(l)));

      } else {
      };

      if (equalString(stringConcatenate("string", "List"), stringify(car(l)))) {
        return car(doStringList(cdr(l)));

      } else {
      };

      if (equalString(stringConcatenate("symbol", "List"), stringify(car(l)))) {
        return car(doSymbolList(cdr(l)));

      } else {
      };

      if (equalString(stringConcatenate("multi", "List"), stringify(car(l)))) {
        return car(doMultiList(cdr(l)));

      } else {
      };

      if (equalString(stringConcatenate("makeL", "ist"), stringify(car(l)))) {
        return car(doInterpolatedList(cdr(l)));

      } else {
      };

      return cons(macrowalk(car(l)), macrowalk(cdr(l)));

    } else {
      return l;

    };

  };

}


function macrosingle(tree, search, replace) {
    let val = null;

  if (isEmpty(tree)) {
    return null;

  } else {
    if (isList(tree)) {
      return cons(macrosingle(car(tree), search, replace), macrosingle(cdr(tree), search, replace));

    } else {
      if (equalString(search, stringify(tree))) {
        val = clone(tree);

        val.str = replace;

        return val;

      } else {
      };

      return tree;

    };

  };

}


function macroSymbolSingle(tree, search, replace) {
    let val = null;

  if (isEmpty(tree)) {
    return null;

  } else {
    if (isList(tree)) {
      return cons(macroSymbolSingle(car(tree), search, replace), macroSymbolSingle(cdr(tree), search, replace));

    } else {
      if (equalString("symbol", boxType(tree))) {
        if (equalString(search, stringify(tree))) {
          val = clone(tree);

          val.str = replace;

          return val;

        } else {
        };

      } else {
      };

      return tree;

    };

  };

}


function macrolist(l, search, replace) {
    let val = null;

  if (isEmpty(l)) {
    return null;

  } else {
    if (isList(l)) {
      if (equalString(search, stringify(car(l)))) {
        return concatLists(replace, macrolist(cdr(l), search, replace));

      } else {
        return cons(macrolist(car(l), search, replace), macrolist(cdr(l), search, replace));

      };

    } else {
      return l;

    };

  };

}


function filterVoid(l) {
    let token = null;

  if (isEmpty(l)) {
    return emptyList();

  } else {
    token = car(l);

    if (equalString("void", token.typ)) {
      return filterVoid(cdr(l));

    } else {
      return cons(token, filterVoid(cdr(l)));

    };

  };

}


function filterTokens(l) {
    let token = null;

  if (isEmpty(l)) {
    return emptyList();

  } else {
    token = car(l);

    if (equalString(boxType(token), "symbol")) {
      if (equalString("__LINE__", stringify(token))) {
        return cons(getTagFail(token, boxString("line"), boxInt(-1)), filterTokens(cdr(l)));

      } else {
        if (equalString("__COLUMN__", stringify(token))) {
          return cons(getTagFail(token, boxString("column"), boxInt(-1)), filterTokens(cdr(l)));

        } else {
          if (equalString("__FILE__", stringify(token))) {
            return cons(getTagFail(token, boxString("filename"), boxString("Unknown file")), filterTokens(cdr(l)));

          } else {
            return cons(token, filterTokens(cdr(l)));

          };

        };

      };

    } else {
      return cons(token, filterTokens(cdr(l)));

    };

  };

}


function finish_token(prog, start, len, line, column, filename) {
    let token = null;

  if (greaterthan(len, 0)) {
    token = boxSymbol(sub_string(prog, start, len));

    token.tag = alistCons(boxString("filename"), boxString(filename), alistCons(boxString("column"), boxInt(column), alistCons(boxString("line"), boxInt(line), alistCons(boxString("totalCharPos"), boxInt(start), null))));

    return token;

  } else {
    return newVoid();

  };

}


function readString(prog, start, len) {
    let token = "";

  token = sub_string(prog, sub1(add(start, len)), 1);

  if (equalString("\"", token)) {
    return sub_string(prog, start, sub1(len));

  } else {
    if (equalString("\\", token)) {
      return readString(prog, start, add(2, len));

    } else {
      return readString(prog, start, add1(len));

    };

  };

}


function readComment(prog, start, len) {
    let token = "";

  if (greaterthan(add(start, len), string_length(prog))) {
    return "";

  } else {
    token = sub_string(prog, sub1(add(start, len)), 1);

    if (isLineBreak(token)) {
      return sub_string(prog, start, sub1(len));

    } else {
      return readComment(prog, start, add1(len));

    };

  };

}


function isLineBreak(s) {
  
  if (equalString("\n", s)) {
    return true;

  } else {
    if (equalString("\r", s)) {
      return true;

    } else {
      return false;

    };

  };

}


function incForNewLine(token, val) {
  
  if (equalString("\n", stringify(token))) {
    return add1(val);

  } else {
    return val;

  };

}


function annotateReadPosition(filename, linecount, column, start, newBox) {
  
  return setTag(boxString("filename"), boxString(filename), setTag(boxString("column"), boxInt(column), setTag(boxString("line"), boxInt(linecount), setTag(boxString("totalCharPos"), boxInt(start), newBox))));

}


function scan(prog, start, len, linecount, column, filename) {
    let token = null;
  let newString = "";
  let newBox = null;

  if (greaterthan(string_length(prog), sub1(add(start, len)))) {
    token = boxSymbol(sub_string(prog, sub1(add(start, len)), 1));

    token.tag = alistCons(boxString("totalCharPos"), boxInt(start), null);

    if (isOpenBrace(token)) {
      return cons(finish_token(prog, start, sub1(len), linecount, column, filename), cons(annotateReadPosition(filename, linecount, column, start, boxSymbol(openBrace())), scan(prog, add1(start), 1, linecount, add1(column), filename)));

    } else {
      if (isCloseBrace(token)) {
        return cons(finish_token(prog, start, sub1(len), linecount, column, filename), cons(annotateReadPosition(filename, linecount, column, start, boxSymbol(closeBrace())), scan(prog, add(start, len), 1, linecount, add1(column), filename)));

      } else {
        if (isWhiteSpace(stringify(token))) {
          return cons(finish_token(prog, start, sub1(len), linecount, column, filename), scan(prog, add(start, len), 1, incForNewLine(token, linecount), 0, filename));

        } else {
          if (equalBox(boxSymbol(";"), token)) {
            return scan(prog, add(start, add1(add1(string_length(readComment(prog, add1(start), len))))), 1, add1(linecount), 0, filename);

          } else {
            if (equalBox(boxSymbol("\""), token)) {
              newString = readString(prog, add1(start), len);

              newBox = annotateReadPosition(filename, linecount, column, start, boxString(newString));

              return cons(newBox, scan(prog, add(start, add1(add1(string_length(newString)))), 1, linecount, add1(column), filename));

            } else {
              return scan(prog, start, sub(len, -1), linecount, add1(column), filename);

            };

          };

        };

      };

    };

  } else {
    return emptyList();

  };

}


function isOpenBrace(b) {
  
  if (equalBox(boxSymbol(openBrace()), b)) {
    return true;

  } else {
    return false;

  };

}


function isCloseBrace(b) {
  
  if (equalBox(boxSymbol(closeBrace()), b)) {
    return true;

  } else {
    return false;

  };

}


function skipList(l) {
    let b = null;

  if (isEmpty(l)) {
    return emptyList();

  } else {
    b = car(l);

    if (isOpenBrace(b)) {
      return skipList(skipList(cdr(l)));

    } else {
      if (isCloseBrace(b)) {
        return cdr(l);

      } else {
        return skipList(cdr(l));

      };

    };

  };

}


function add(a, b) {
  
  return sub(a, sub(0, b));

}


function addf(a, b) {
  
  return subf(a, subf(0, b));

}


function sub1(a) {
  
  return sub(a, 1);

}


function add1(a) {
  
  return add(a, 1);

}


function clone(b) {
    let newb = null;

  newb = makeBox();

  if (isNil(newb)) {
    printf("clone: newb is nil\n");

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

  };

}


function tern(cond, tr, fal) {
  
  if (cond) {
    return tr;

  } else {
    return fal;

  };

}


function ternString(cond, tr, fal) {
  
  if (cond) {
    return tr;

  } else {
    return fal;

  };

}


function ternList(cond, tr, fal) {
  
  if (cond) {
    return tr;

  } else {
    return fal;

  };

}


function newVoid() {
    let newb = null;

  newb = makeBox();

  newb.voi = true;

  newb.typ = "void";

  return newb;

}


function stackDump() {
  
  printf("");

}


function nop() {
  
  printf("");

}


function equalBox(a, b) {
  
  if (isList(b)) {
    return false;

  } else {
    if (equalString("string", boxType(a))) {
      return equalString(unBoxString(a), stringify(b));

    } else {
      if (equalString("bool", boxType(a))) {
        return andBool(unBoxBool(a), unBoxBool(b));

      } else {
        if (equalString("symbol", boxType(a))) {
          if (equalString("symbol", boxType(b))) {
            return equalString(unBoxSymbol(a), unBoxSymbol(b));

          } else {
            return false;

          };

        } else {
          if (equalString("int", boxType(a))) {
            return equal(unBoxInt(a), unBoxInt(b));

          } else {
            if (equalString("float", boxType(a))) {
              if (equalString("float", boxType(b))) {
                return equalf(unBoxFloat(a), unBoxFloat(b));

              } else {
                return false;

              };

            } else {
              return false;

            };

          };

        };

      };

    };

  };

}


function openBrace() {
  
  return "(";

}


function closeBrace() {
  
  return ")";

}


function boxType(b) {
  
  return b.typ;

}


function makeBox() {
    let b = null;

  b = {};

  if (isNil(b)) {
    panic("failed to create box!");

  } else {
  };

  b.tag = null;

  b.car = null;

  b.cdr = null;

  b.lis = null;

  b.typ = "None - error!";

  return b;

}


function makePair() {
  
  return makeBox();

}


function boxString(s) {
    let b = null;

  b = makeBox();

  b.str = s;

  b.lengt = string_length(s);

  b.typ = "string";

  return b;

}


function boxSymbol(s) {
    let b = null;

  b = boxString(s);

  b.typ = "symbol";

  return b;

}


function boxBool(boo) {
    let b = null;

  b = makeBox();

  b.boo = boo;

  b.typ = "bool";

  return b;

}


function boxInt(val) {
    let b = null;

  b = makeBox();

  b.i = val;

  b.typ = "int";

  return b;

}


function boxFloat(val) {
    let b = null;

  b = makeBox();

  b.f = val;

  b.typ = "float";

  return b;

}


function assertType(atype, abox, line, file) {
  
  if (isNil(abox)) {
    if (equalString(atype, "nil")) {
      return;

    } else {
      return;

    };

  } else {
    if (equalString(atype, boxType(abox))) {
      return;

    } else {
      printf("Assertion failure at line %d, in file %s: provided value is not a '%s'!  It was actually '%s'. Contents:", line, file, atype, boxType(abox));

      display(abox);

      printf("\n");

      display(cons(boxString("Token may have been read from "), cons(boxString(stringify(getTagFail(abox, boxString("filename"), boxString("source file not found")))), cons(boxString(":"), cons(boxString(stringify(getTagFail(abox, boxString("line"), boxString("source line not found")))), null)))));

      StackTracePrint();

      panic("Invalid type!");

    };

  };

}


function unBoxString(b) {
  
  assertType("string", b, 199, "q/base.qon");

  return b.str;

}


function unBoxSymbol(b) {
  
  return b.str;

}


function unBoxBool(b) {
  
  return b.boo;

}


function unBoxInt(b) {
  
  return b.i;

}


function unBoxFloat(b) {
  
  return b.f;

}


function stringify_rec(b) {
  
  if (isNil(b)) {
    return "";

  } else {
    return stringConcatenate(stringify(car(b)), stringConcatenate(" ", stringify_rec(cdr(b))));

  };

}


function stringify(b) {
  
  if (isNil(b)) {
    return "()";

  } else {
    if (equalString("string", boxType(b))) {
      return unBoxString(b);

    } else {
      if (equalString("bool", boxType(b))) {
        if (unBoxBool(b)) {
          return "true";

        } else {
          return "false";

        };

      } else {
        if (equalString("int", boxType(b))) {
          return intToString(unBoxInt(b));

        } else {
          if (equalString("float", boxType(b))) {
            return floatToString(unBoxFloat(b));

          } else {
            if (equalString("symbol", boxType(b))) {
              return unBoxSymbol(b);

            } else {
              if (equalString("list", boxType(b))) {
                return stringConcatenate("(", stringConcatenate(stringify(car(b)), stringConcatenate(" ", stringConcatenate(stringify_rec(cdr(b)), ")"))));

              } else {
                return stringConcatenate("Unsupported type in stringify: ", boxType(b));

              };

            };

          };

        };

      };

    };

  };

}


function hasTag(aBox, key) {
  
  if (isNil(aBox)) {
    return false;

  } else {
    return isNotFalse(assoc(stringify(key), aBox.tag));

  };

}


function getTag(aBox, key) {
  
  if (false) {
    printf("Getting %s from: ", stringify(key));

    display(alistKeys(aBox.tag));

    printf("\n");

  } else {
    printf("");

  };

  return cdr(assoc(stringify(key), aBox.tag));

}


function getTagFail(aBox, key, onFail) {
  
  if (hasTag(aBox, key)) {
    return getTag(aBox, key);

  } else {
    return onFail;

  };

}


function assocExists(key, aBox) {
  
  if (isNil(aBox)) {
    return false;

  } else {
    return isNotFalse(assoc(key, aBox));

  };

}


function assocFail(key, aBox, onFail) {
  
  if (assocExists(key, aBox)) {
    return assoc(key, aBox);

  } else {
    return cons(boxString(key), onFail);

  };

}


function assocPanic(key, aBox, onFail) {
  
  if (assocExists(key, aBox)) {
    return assoc(key, aBox);

  } else {
    panic(onFail);

  };

  panic("Inconceivable");

  return null;

}


function setTag(key, val, aStruct) {
  
  aStruct.tag = alistCons(key, val, aStruct.tag);

  return aStruct;

}


function locPanic(file, line, message) {
  
  printf("%s %s:%s\n", file, line, message);

  panic(message);

}


function truthy(aVal) {
  
  return isNotFalse(aVal);

}


function isNotFalse(aVal) {
  
  if (equalString(boxType(aVal), "bool")) {
    if (unBoxBool(aVal)) {
      return true;

    } else {
      return false;

    };

  } else {
    return true;

  };

}


function toStr(thing) {
  
  return boxString(stringify(thing));

}


function listLast(alist) {
  
  if (isEmpty(cdr(alist))) {
    return car(alist);

  } else {
    return listLast(cdr(alist));

  };

}


function newLine(indent) {
  
  printf("\n");

  printIndent(indent);

}


function printIndent(ii) {
  
  if (greaterthan(ii, 0)) {
    printf("  ");

    printIndent(sub1(ii));

  } else {
    return;

  };

}


function stringIndent(ii) {
  
  if (greaterthan(ii, 0)) {
    return stringConcatenate("  ", stringIndent(sub1(ii)));

  } else {
    return "";

  };

}


function listIndent(ii) {
  
  return cons(id(boxString(stringIndent(ii))), null);

}


function listNewLine(ii) {
  
  return cons(id(boxString(stringConcatenate("\n", stringIndent(ii)))), null);

}


function argList(count, pos, args) {
  
  if (greaterthan(count, pos)) {
    return cons(boxString(getStringArray(pos, args)), argList(count, add1(pos), args));

  } else {
    return null;

  };

}


function tron() {
  
  globalTrace = true;

}


function troff() {
  
  globalTrace = false;

}


function stron() {
  
  globalStepTrace = true;

}


function stroff() {
  
  globalStepTrace = false;

}


function StackTraceMove(direction, filename, fname, line) {
  
  if (equalString(direction, "in")) {
    globalStackTrace = cons(cons(boxString(filename), cons(boxString(line), cons(boxString(fname), null))), globalStackTrace);

  } else {
    globalStackTrace = cdr(globalStackTrace);

  };

}


function StackTracePrint() {
  
  printf("Stack trace:\n");

  if (isNil(globalStackTrace)) {
    printf("  <empty>\n");

  } else {
    StackTracePrintHelper(globalStackTrace);

  };

}


function StackTracePrintHelper(stack) {
    let file = stringify(first(car(stack)));
  let line = "";
  let func = "";

  if (isNil(stack)) {
    printf("  <end>\n");

    return;

  } else {
    file = stringify(first(car(stack)));

    line = stringify(second(car(stack)));

    func = stringify(third(first(stack)));

    printf("  %s:%s %s\n", file, line, func);

    StackTracePrintHelper(cdr(stack));

  };

}


function NoStackTrace_list() {
  
  return cons(boxString("StackTraceMove"), cons(boxString("StackTracePrint"), cons(boxString("StackTracePrintHelper"), cons(boxString("NoStackTrace_list"), cons(boxString("car"), cons(boxString("cdr"), cons(boxString("cons"), cons(boxString("set"), cons(boxString("boxString"), cons(boxString("makePair"), cons(boxString("set-struct"), cons(boxString("display"), cons(boxString("list"), cons(boxString("assertType"), cons(boxString("isEmpty"), cons(boxString("isNil"), cons(boxString("get-struct"), cons(boxString("equalString"), cons(boxString("binop"), cons(boxString("strcmp"), cons(boxString("main"), cons(boxString("makeBox"), cons(boxString("string_length"), cons(boxString("boxType"), cons(boxString("displayList"), cons(boxString("newLine"), cons(boxString("panic"), null)))))))))))))))))))))))))));

}


function NoTrace_list() {
  
  return cons(boxString("StackTraceMove"), cons(boxString("StackTracePrint"), cons(boxString("StackTracePrintHelper"), cons(boxString("NoStackTrace_list"), cons(boxString("car"), cons(boxString("cdr"), cons(boxString("cons"), cons(boxString("set"), cons(boxString("boxString"), cons(boxString("makePair"), cons(boxString("set-struct"), cons(boxString("display"), cons(boxString("list"), cons(boxString("assertType"), cons(boxString("isEmpty"), cons(boxString("isNil"), cons(boxString("get-struct"), cons(boxString("equalString"), cons(boxString("binop"), cons(boxString("strcmp"), cons(boxString("main"), cons(boxString("makeBox"), cons(boxString("string_length"), cons(boxString("boxType"), cons(boxString("displayList"), cons(boxString("newLine"), cons(boxString("panic"), cons(boxString("boxString"), cons(boxString("boxSymbol"), cons(boxString("boxType"), cons(boxString("equalString"), cons(boxString("unBoxSymbol"), cons(boxString("isList"), cons(boxString("makeBox"), cons(boxString("equalBox"), cons(boxString("sub"), cons(boxString("sub1"), cons(boxString("stringify"), cons(boxString("add"), cons(boxString("greaterthan"), null))))))))))))))))))))))))))))))))))))))));

}


function indexOfHelper(haystack, needle, start, current) {
  
  if (greaterthan(add(current, string_length(needle)), string_length(haystack))) {
    return -1;

  } else {
    if (equalString(sub_string(haystack, current, string_length(needle)), needle)) {
      return current;

    } else {
      return indexOfHelper(haystack, needle, start, add1(current));

    };

  };

}


function indexOf(haystack, needle, start) {
  
  if (equal(string_length(needle), 0)) {
    return start;

  } else {
    return indexOfHelper(haystack, needle, start, start);

  };

}


function stringReplace(old, new_, s) {
    let pos = 0;

  pos = indexOf(s, old, 0);

  if (equal(pos, -1)) {
    return s;

  } else {
    return stringConcatenate(sub_string(s, 0, pos), stringConcatenate(new_, stringReplace(old, new_, sub_string(s, add(pos, string_length(old)), sub(string_length(s), add(pos, string_length(old)))))));

  };

}


function stringContains(haystack, needle) {
    let haystackLength = 0;
  let needleLength = 0;

  haystackLength = string_length(haystack);

  needleLength = string_length(needle);

  if (greaterthan(needleLength, haystackLength)) {
    return false;

  } else {
    return stringContainsHelper(haystack, needle, 0);

  };

}


function stringContainsHelper(haystack, needle, startIndex) {
    let haystackLength = 0;
  let needleLength = 0;

  haystackLength = string_length(haystack);

  needleLength = string_length(needle);

  if (greaterthan(add(startIndex, needleLength), haystackLength)) {
    return false;

  } else {
    if (equalString(sub_string(haystack, startIndex, needleLength), needle)) {
      return true;

    } else {
      return stringContainsHelper(haystack, needle, add(startIndex, 1));

    };

  };

}


function isWhiteSpace(s) {
  
  if (equalString(" ", s)) {
    return true;

  } else {
    if (equalString("\t", s)) {
      return true;

    } else {
      if (equalString("\n", s)) {
        return true;

      } else {
        if (equalString("\r", s)) {
          return true;

        } else {
          return false;

        };

      };

    };

  };

}


function stringTrim(s) {
  
  if (equal(string_length(s), 0)) {
    return "";

  } else {
    if (isWhiteSpace(sub_string(s, 0, 1))) {
      return stringTrim(sub_string(s, 1, sub1(string_length(s))));

    } else {
      if (isWhiteSpace(sub_string(s, sub(string_length(s), 1), 1))) {
        return stringTrim(sub_string(s, 0, sub(string_length(s), 1)));

      } else {
        return s;

      };

    };

  };

}


function stringSplit(s, delimiter) {
    let end = 0;
  let delimiterLength = 0;

  printf("Entering stringSplit with s: %.20s..., delimiter: %s\n", s, delimiter);

  delimiterLength = string_length(delimiter);

  end = indexOf(s, delimiter, 0);

  if (equal(end, -1)) {
    printf("No delimiter found in stringSplit\n");

    return cons(boxString(s), null);

  } else {
    printf("Splitting string in stringSplit\n");

    return cons(boxString(sub_string(s, 0, end)), stringSplit(sub_string(s, add(end, delimiterLength), sub(string_length(s), add(end, delimiterLength))), delimiter));

  };

}


function isNil(a) {
  
  return a == null;

}


function getEnv(key) {
  
  return process.env[key];

}


function panic(s) {
  
  throw new Error(s);

}


function exit(status) {
  
  process.exit(status);

}


function sub(a, b) {
  
  return (a - b);

}


function mult(a, b) {
  
  return (a * b);

}


function greaterthan(a, b) {
  
  return (a > b);

}


function subf(a, b) {
  
  return (a - b);

}


function multf(a, b) {
  
  return (a * b);

}


function greaterthanf(a, b) {
  
  return (a > b);

}


function equalf(a, b) {
  
  return (a == b);

}


function equal(a, b) {
  
  return (a == b);

}


function equalString(a, b) {
  
  return (a == b);

}


function string_length(s) {
  
  return s.length;

}


function setSubString(target, start, source) {
  
  return target.substring(0, start) + source + target.substring(start + 1);

}


function sub_string(s, start, length) {
  
  return s.substring(start, start + length);

}


function stringConcatenate(a, b) {
  
  return (a + b);

}


function intToString(a) {
  
  return String(a);

}


function floatToString(a) {
  
  return String(a);

}


function read_file(filename) {
  
  return (() => { try { return boxString(fs.readFileSync(filename, 'utf8')); } catch (e) { return null; } })();

}


function write_file(filename, data) {
  
  fs.writeFileSync(filename, data);

}


function getStringArray(index, strs) {
  
  return strs[index];

}


function programArgs() {
  
  return globalArgs;

}


function programArgsCount() {
  
  return globalArgsCount;

}


function character(num) {
  
  return String.fromCharCode(num);

}


function displays(s) {
  
  printf("%s", s);

}


function remainder(a, b) {
  
  return (a % b);

}


function or(a, b) {
  
  return (a || b);

}


function max(a, b) {
  
  if (greaterthan(a, b)) {
    return a;

  } else {
    return b;

  };

}


function min(a, b) {
  
  if (greaterthan(a, b)) {
    return b;

  } else {
    return a;

  };

}


function makeHash() {
  
  return {};

}


function setHash(hash, key, value) {
  
  hash[key] = value;

}


function getHash(hash, key) {
  
  return hash[key];

}


function inHash(hash, key) {
  
  return Object.prototype.hasOwnProperty.call(hash, key);

}


function makeArray(length) {
  
  return new Array(length);

}


function setArray(array, index, value) {
  
  array[index] = value;

}


function getArray(array, index) {
  
  return array[index];

}


function readString(prog, start, len) {
  
  return (() => { let currentLen = len; while (true) { const token = sub_string(prog, sub1(add(start, currentLen)), 1); if (token === String.fromCharCode(34)) { return sub_string(prog, start, sub1(currentLen)); } if (token === String.fromCharCode(92)) { currentLen = add(2, currentLen); } else { currentLen = add1(currentLen); } } })();

}


function readComment(prog, start, len) {
  
  return (() => { let currentLen = len; while (true) { if (greaterthan(add(start, currentLen), string_length(prog))) { return ''; } const token = sub_string(prog, sub1(add(start, currentLen)), 1); if (isLineBreak(token)) { return sub_string(prog, start, sub1(currentLen)); } currentLen = add1(currentLen); } })();

}


function scan(prog, start, len, linecount, column, filename) {
  
  return (() => { const tokens = []; while (greaterthan(string_length(prog), sub1(add(start, len)))) { const token = boxSymbol(sub_string(prog, sub1(add(start, len)), 1)); token.tag = alistCons(boxString('totalCharPos'), boxInt(start), null); if (isOpenBrace(token)) { tokens.push(finish_token(prog, start, sub1(len), linecount, column, filename)); tokens.push(annotateReadPosition(filename, linecount, column, start, boxSymbol(openBrace()))); start = add1(start); len = 1; column = add1(column); } else if (isCloseBrace(token)) { tokens.push(finish_token(prog, start, sub1(len), linecount, column, filename)); tokens.push(annotateReadPosition(filename, linecount, column, start, boxSymbol(closeBrace()))); start = add(start, len); len = 1; column = add1(column); } else if (isWhiteSpace(stringify(token))) { tokens.push(finish_token(prog, start, sub1(len), linecount, column, filename)); start = add(start, len); len = 1; linecount = incForNewLine(token, linecount); column = 0; } else if (equalBox(boxSymbol(';'), token)) { start = add(start, add1(add1(string_length(readComment(prog, add1(start), len))))); len = 1; linecount = add1(linecount); column = 0; } else if (equalBox(boxSymbol(String.fromCharCode(34)), token)) { const newString = readString(prog, add1(start), len); tokens.push(annotateReadPosition(filename, linecount, column, start, boxString(newString))); start = add(start, add1(add1(string_length(newString)))); len = 1; column = add1(column); } else { len = sub(len, -1); column = add1(column); } } let out = null; for (let i = tokens.length - 1; i >= 0; i--) { out = cons(tokens[i], out); } return out; })();

}


function filterVoid(l) {
  
  return (() => { const tokens = []; for (let p = l; p !== null; p = p.cdr) { const token = p.car; if (!equalString('void', boxType(token))) { tokens.push(token); } } let out = null; for (let i = tokens.length - 1; i >= 0; i--) { out = cons(tokens[i], out); } return out; })();

}


function filterTokens(l) {
  
  return (() => { const tokens = []; for (let p = l; p !== null; p = p.cdr) { const token = p.car; if (equalString(boxType(token), 'symbol')) { if (equalString('__LINE__', stringify(token))) { tokens.push(getTagFail(token, boxString('line'), boxInt(-1))); } else if (equalString('__COLUMN__', stringify(token))) { tokens.push(getTagFail(token, boxString('column'), boxInt(-1))); } else if (equalString('__FILE__', stringify(token))) { tokens.push(getTagFail(token, boxString('filename'), boxString('Unknown file'))); } else { tokens.push(token); } } else { tokens.push(token); } } let out = null; for (let i = tokens.length - 1; i >= 0; i--) { out = cons(tokens[i], out); } return out; })();

}


function concatLists(seq1, seq2) {
  
  return (() => { const values = []; for (let p = seq1; p !== null; p = p.cdr) { values.push(p.car); } let out = seq2; for (let i = values.length - 1; i >= 0; i--) { out = cons(values[i], out); } return out; })();

}


function flatten(tree) {
  
  return (() => { let out = null; const stack = [tree]; while (stack.length > 0) { const item = stack.pop(); if (item === null) { continue; } if (isList(item)) { stack.push(item.cdr); stack.push(item.car); } else { out = cons(item, out); } } let rev = null; for (let p = out; p !== null; p = p.cdr) { rev = cons(p.car, rev); } return rev; })();

}


function ListToString(l, indent, first, withNewLines) {
  
  return (() => { let out = ''; const frames = [{ value: l, indent: indent, first: first, withNewLines: withNewLines }]; while (frames.length > 0) { const frame = frames.pop(); if (frame.text !== undefined) { out += frame.text; continue; } const value = frame.value; if (value === null) { continue; } if (isList(value)) { const val = value.car; if (isList(val)) { frames.push({ value: value.cdr, indent: frame.indent, first: false, withNewLines: frame.withNewLines }); frames.push({ text: ' ' }); frames.push({ text: closeBrace() }); frames.push({ value: val, indent: add1(frame.indent), first: true, withNewLines: frame.withNewLines }); frames.push({ text: ' ' }); frames.push({ text: openBrace() }); frames.push({ text: frame.withNewLines ? String.fromCharCode(10) : stringIndent(frame.indent) }); } else { frames.push({ value: value.cdr, indent: frame.indent, first: false, withNewLines: frame.withNewLines }); frames.push({ text: stringify(val) }); } } else { out += stringify(value); } } return out; })();

}


function start() {
    let runTests = false;
  let cmdLine = null;
  let filenameBox = null;
  let filename = "";
  let runPerl = false;
  let runJava = false;
  let runNode = false;
  let runNode2 = false;
  let runHaskell = false;
  let runAnsi3 = false;
  let runTree = false;

  cmdLine = listReverse(argList(globalArgsCount, 0, globalArgs));

  if (greaterthan(listLength(cmdLine), 1)) {
    filenameBox = second(cmdLine);

  } else {
    filenameBox = boxString("compiler.qon");

  };

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

  if (orBool(inList(boxString("--help"), cmdLine), inList(boxString("-h"), cmdLine))) {
    printf("Usage: quon file [options]\n\nNote the options go after the file name\n");

    printf("Options:\n");

    printf("  -h, --help  Display this help\n");

    printf("  --release   Compile in release mode\n");

    printf("  --test      Run the test suite\n");

    printf("  --java      Compile to Java\n");

    printf("  --perl      Compile to Perl\n");

    printf("  --tree      Compile to an s-expression tree\n");

    printf("  --node      Compile to Node.js\n");

    printf("  --node2      Compile to Node.js, new outputter\n");

    printf("  --haskell, --hs Compile to Haskell\n");

    printf("  --ansi3     Compile to ANSI C (quon version 3)\n");

    printf("  --trace     Trace execution\n");

    printf("  --steptrace Step trace execution\n");

    exit(0);

  } else {
  };

  if (runTests) {
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

    printf("\n\nAfter all that hard work, I need a beer...\n");

    beers(9);

  } else {
    if (runTree) {
      display(macrowalk(loadQuon(filename)));

    } else {
      if (orBool(runNode, runNode2)) {
        node2Compile(filename);

        printf("\n");

      } else {
        if (runHaskell) {
          haskellCompile(filename);

          printf("\n");

        } else {
          if (runPerl) {
            perlCompile(filename);

            printf("\n");

          } else {
            if (runJava) {
              javaCompile(filename);

              printf("\n");

            } else {
              if (runAnsi3) {
                ansi3Compile(filename);

                printf("\n");

              } else {
                ansi3Compile(filename);

                printf("\n");

              };

            };

          };

        };

      };

    };

  };

  return 0;

}

// Main entry point
globalArgs = ["fixmeprogname", ...process.argv.slice(2)];
globalArgsCount = globalArgs.length;
start();


