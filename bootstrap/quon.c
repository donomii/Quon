
//Start include block
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

typedef int*  array;
typedef int bool;
#define true 1
#define false 0



int start();  //Forwards declare the user's main routine
char* caller;
char** globalArgs;
int globalArgsCount;
bool globalTrace = false;
bool globalStepTrace = false;
bool releaseMode = false;

void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }
//End include block

typedef struct Box {
  struct Box* lis;
  char* str;
  int i;
  float f;
  char* typ;
  bool voi;
  bool boo;
  int lengt;
  struct Box* car;
  struct Box* cdr;
  struct Box* tag;

} Box;
typedef   Box Pair;
typedef   Box* pair;
typedef   Box* box;
typedef   Box* list;
typedef   int unsigned uint;
typedef   int bool;
typedef   int* array;
Box* globalStackTrace = NULL;

bool isNil(list p) {
    return p == NULL;
}


//Forward declarations

bool notBool(bool a);
bool andBool(bool a, bool b);
bool orBool(bool a, bool b);
bool nand(bool a, bool b);
bool xor(bool a, bool b);
bool lessThan(int a, int b);
list node2FunctionArgs(list tree);
list node2Atom(box tree);
list node2Expression(list tree, int indent);
list node2RecurList(list expr, int indent);
list node2If(list node, int indent, char* functionName);
list node2SetStruct(list node, int indent);
list node2Set(list node, int indent);
list node2Return(list node, int indent);
list node2Statement(list node, int indent, char* functionName);
list node2Body(list tree, int indent, char* functionName);
list node2Declarations(list decls, int indent);
list node2Function(list node);
list node2Functions(list tree);
list node2Includes(list nodes);
list node2Types(list nodes);
box node2FuncMap(box aSym);
list node2MainEntry();
list node2LoadProgram(char* filename);
list node2ProgramTree(list tree);
char* node2Program(list tree);
char* node2CompileString(char* filename);
void node2Compile(char* filename);
void test0();
void test1();
void test2_do(char* message);
void test2();
void test3_do(int b, char* c);
void test3();
char* test4_do();
char* returnThis(char* returnMessage);
void test4();
void test5();
void test6();
int test7_do(int count);
void test7();
void beer();
char* plural(int num);
int beers(int count);
void test8();
void test9();
void test10();
void test12();
void test13();
void test14();
void test15();
void test16();
void test17();
void test18();
void test19();
list concatenateLists(list oldL, list newL);
void test20();
void test21();
void test22();
void test23();
void test24();
void test25();
void test27();
void test28();
char* haskellBackslash();
char* haskellDoubleQuote();
char* haskellEscapedBackslash();
char* haskellEscapedDoubleQuote();
char* haskellEscapeString(char* s);
char* haskellSafeNameString(char* name);
box haskellSafeName(box aSym);
char* haskellFieldName(box aSym);
char* haskellNewName(box aSym);
bool haskellStringEndsWith(char* s, char* suffix);
bool haskellStringStartsWith(char* s, char* prefix);
box haskellPointerBase(box aSym);
bool haskellTypeIsPointer(box aSym);
box haskellTypeMap(box aSym);
char* haskellDefaultValue(box typeSym);
char* haskellRefType(box typeSym);
list haskellGlobalVariables();
list haskellCollectVariablesFromArgs(list args);
list haskellCollectVariablesFromDecls(list decls);
list haskellCollectVariables(list args, list decls);
box haskellFuncMap(box aSym, list variables);
list haskellNumberAtom(box tree);
list haskellAtom(box tree, list variables);
list haskellArgNames(list expr, int pos);
list haskellBindArgs(list expr, int indent, list variables, int pos);
list haskellCall(box name, list args, int indent, list variables);
list haskellBinop(list tree, int indent, list variables);
list haskellGetStruct(list tree, int indent, list variables);
list haskellNewExpression(list tree);
list haskellExpression(list tree, int indent, list variables);
list haskellSet(list node, int indent, list variables);
list haskellSetStruct(list node, int indent, list variables);
list haskellReturn(list node, int indent, list variables);
list haskellIf(list node, int indent, list variables);
list haskellStatement(list node, int indent, list variables);
list haskellBody(list tree, int indent, list variables);
list haskellFunctionArgsSignature(list tree);
list haskellFunctionArgs(list tree);
list haskellArgRefs(list args, int indent);
list haskellDeclarations(list decls, int indent, list variables);
list haskellFunction(list node);
list haskellFunctions(list tree);
list haskellTypeDecl(list l);
list haskellStructFields(list node);
list haskellNewStructField(list l, int indent);
list haskellNewStructFields(list fields, int indent);
list haskellStructCtorFields(list fields);
list haskellType(list node);
list haskellTypes(list nodes);
list haskellIncludes(list nodes);
list haskellMainEntry();
list haskellApplyTypeAliases(list tree, list types);
list haskellLoadProgram(char* filename);
list haskellProgramTree(list tree);
char* haskellProgram(list tree);
char* haskellCompileString(char* filename);
void haskellCompile(char* filename);
list javaFunctionArgs(list tree);
list javaAtom(box tree);
list javaExpression(list tree, int indent);
list javaRecurList(list expr, int indent);
list javaIf(list node, int indent);
list javaSetStruct(list node, int indent);
list javaSet(list node, int indent);
list javaReturn(list node, int indent);
list javaStatement(list node, int indent);
list javaBody(list tree, int indent);
list javaDeclarations(list decls, int indent);
list javaFunction(list node);
list javaFunctions(list tree);
list javaIncludes(list nodes);
box javaTypeMap(box aSym);
box javaPointerBase(box aSym);
box javaFuncMap(box aSym);
list javaTypeDecl(list l);
list javaStructComponents(list node);
list javaStruct(list node);
list javaType(list node);
list javaTypes(list nodes);
list javaApplyTypeAliases(list tree, list types);
list javaMainEntry();
list javaLoadProgram(char* filename);
list javaProgramTree(list tree);
char* javaProgram(list tree);
char* javaCompileString(char* filename);
void javaCompile(char* filename);
list ansi3FunctionArgs(list tree);
list ansi3Atom(box tree);
list ansi3Expression(list tree, int indent);
list ansi3RecurList(list expr, int indent);
list ansi3If(list node, int indent, char* functionName);
list ansi3SetStruct(list node, int indent);
list ansi3Set(list node, int indent);
list ansi3Return(list node, int indent);
list ansi3TraceReturn(list node, int indent, char* functionName);
list ansi3Statement(list node, int indent, char* functionName);
list ansi3StatementTrace(list code, int indent, char* functionName);
list ansi3StepTrace(int indent);
list ansi3Body(list tree, int indent, char* functionName);
list ansi3Declarations(list decls, int indent);
list ansi3FunctionTrace(box name);
list ansi3FunctionStackTrace(box name);
list ansi3Function(list node);
list ansi3ForwardDeclaration(list node);
list ansi3ForwardDeclarations(list tree);
list ansi3Functions(list tree);
list ansi3Includes(list nodes);
list ansi3TypeDecl(list l);
list ansi3StructComponents(list node);
list ansi3Struct(list node);
box ansi3TypeMap(box aSym);
box ansi3FuncMap(box aSym);
list ansi3Type(list node);
list ansi3Types(list nodes);
list ansi3LoadProgram(char* filename);
list ansi3ProgramTree(list tree);
char* ansi3Program(list tree);
char* ansi3CompileString(char* filename);
void ansi3Compile(char* filename);
char* dollar();
char* atsymbol();
char* singleQuote();
char* escapedSingleQuote();
char* backslash();
char* escapedDollar();
char* escapedAtSign();
char* escapeSingleQuotes(char* s);
char* escapePerlString(char* s);
list getGlobalVariables();
list collectVariables(list args, list decls);
list perlGlobalVariables();
list perlMainEntry();
list collectVariablesFromArgs(list args);
list collectVariablesFromDecls(list decls);
list appendVariables(list vars1, list vars2);
list perlFunctionArgs(list tree);
list perlAtom(box tree, list variables);
list perlExpression(list tree, int indent, list variables);
list perlRecurList(list expr, int indent, list variables);
list perlSet(list node, int indent, list variables);
list perlSetStruct(list node, int indent, list variables);
list perlReturn(list node, int indent, list variables);
list perlIf(list node, int indent, list variables);
list perlStatement(list node, int indent, list variables);
list perlBody(list tree, int indent, list variables);
list perlGetStruct(list node, int indent);
list perlDeclarations(list decls, int indent, list variables);
list perlFunction(list node);
list perlForwardDeclaration(list node);
list perlForwardDeclarations(list tree);
list perlFunctions(list tree);
list perlIncludes(list nodes);
list perlTypes(list nodes);
box perlTypeMap(box aSym);
box perlFuncMap(box aSym, list variables);
list perlLoadProgram(char* filename);
list perlProgramTree(list tree);
char* perlProgram(list tree);
char* perlCompileString(char* filename);
void perlCompile(char* filename);
list readSexpr(char* aStr, char* filename);
void parserPanicAt(char* filename, box token, char* message);
void parserPanicAtNode(char* filename, box node, char* message);
bool parserSymbolIs(box b, char* name);
bool parserListStartsWith(box node, char* name);
void parserValidateParens(list tokens, list openStack, char* filename);
void parserValidateRoot(list roots, char* filename);
void parserValidateSection(box section, char* name, char* filename);
bool parserIsFunctionDefinition(box node);
void parserRejectFunctionDefinitions(box node, char* filename);
void parserRejectFunctionDefinitionsList(list nodes, char* filename);
void parserValidateProgram(box program, char* filename);
void parserValidateFunctions(list functions, char* filename);
void parserValidateFunction(list fn, char* filename);
void parserValidateBody(list forms, char* filename);
void parserValidateStatement(box stmt, char* filename);
void parserValidateReturn(list stmt, char* filename);
void parserValidateSet(list stmt, char* filename);
void parserValidateSetStruct(list stmt, char* filename);
void parserValidateIf(list stmt, char* filename);
void parserValidateBranch(box branch, char* name, char* filename);
void parserValidateExpression(box expr, char* filename);
void parserValidateExpressionList(list exprs, char* filename);
list sexprTree(list l);
list loadQuon(char* filename);
list getIncludes(list program);
list getTypes(list program);
list getFunctions(list program);
list insertInclude(list tree, char* extra);
bool stringInList(char* item, list l);
list appendMissingIncludes(list candidates, list pending, list seen);
list loadIncludes(list tree, list seen);
list buildProg(list includes, list types, list functions);
box car(list l);
list cdr(list l);
list cons(box data, list l);
box caar(list l);
box cadr(list l);
box caddr(list l);
box cadddr(list l);
box caddddr(list l);
box cddr(list l);
box first(list l);
box second(list l);
box third(list l);
box fourth(list l);
box fifth(list l);
box sixth(list l);
box seventh(list l);
box eighth(list l);
box ninth(list l);
box tenth(list l);
box eleventh(list l);
box twelfth(list l);
box rest(list l);
bool isList(box b);
list emptyList();
bool isEmpty(box b);
int listLength(list l);
list alistCons(box key, box value, list alist);
list assoc(char* searchTerm, list l);
char* chooseBox(char* aType);
box mlistLiteral(box b);
list doMultiList(list l);
bool isDigit(char* val);
bool isUnsignedIntFrom(char* val, int pos);
bool isInt(char* val);
bool isFloatFrom(char* val, int pos, bool seenDot, bool seenDigit, bool digitAfterDot);
bool isFloat(char* val);
box id(box b);
char* chooseBoxInterp(box b);
list doInterpolatedList(list l);
list doStringList(list l);
list doSymbolList(list l);
list doBoxList(list l);
list concatLists(list seq1, list seq2);
list alistKeys(list alist);
void display(list l);
void displayList(list l, int indent, bool first);
char* StringListJoinRec(list l, char* sep);
char* StringListJoin(list l, char* sep);
box ListToBoxString(list l, int indent);
char* ListToString(list l, int indent, bool first, bool withNewLines);
list listReverse(list l);
bool inList(box item, list l);
bool equalList(list a, list b);
list reverseRec(list oldL, list newL);
list reverseList(list l);
list flatten(list tree);
void printStringTree(list tree);
list macrowalk(list l);
list macrosingle(list tree, char* search, char* replace);
list macroSymbolSingle(list tree, char* search, char* replace);
list macrolist(list l, char* search, list replace);
list filterVoid(list l);
list filterTokens(list l);
box finish_token(char* prog, int start, int len, int line, int column, char* filename);
char* readString(char* prog, int start, int len);
char* readComment(char* prog, int start, int len);
bool isLineBreak(char* s);
int incForNewLine(box token, int val);
box annotateReadPosition(char* filename, int linecount, int column, int start, box newBox);
list scan(char* prog, int start, int len, int linecount, int column, char* filename);
bool isOpenBrace(box b);
bool isCloseBrace(box b);
list skipList(list l);
int add(int a, int b);
float addf(float a, float b);
int sub1(int a);
int add1(int a);
box clone(box b);
box tern(bool cond, list tr, list fal);
char* ternString(bool cond, char* tr, char* fal);
list ternList(bool cond, list tr, list fal);
box newVoid();
void stackDump();
void nop();
bool equalBox(box a, box b);
char* openBrace();
char* closeBrace();
char* boxType(box b);
box makeBox();
pair makePair();
box boxString(char* s);
box boxSymbol(char* s);
box boxBool(bool boo);
box boxInt(int val);
box boxFloat(float val);
void assertType(char* atype, box abox, int line, char* file);
char* unBoxString(box b);
char* unBoxSymbol(box b);
bool unBoxBool(box b);
int unBoxInt(box b);
float unBoxFloat(box b);
char* stringify_rec(box b);
char* stringify(box b);
bool hasTag(box aBox, box key);
box getTag(box aBox, box key);
box getTagFail(box aBox, box key, box onFail);
bool assocExists(char* key, box aBox);
box assocFail(char* key, box aBox, box onFail);
box assocPanic(char* key, box aBox, char* onFail);
box setTag(box key, list val, box aStruct);
void locPanic(char* file, char* line, char* message);
bool truthy(box aVal);
bool isNotFalse(box aVal);
box toStr(box thing);
box listLast(list alist);
void newLine(int indent);
void printIndent(int ii);
char* stringIndent(int ii);
list listIndent(int ii);
list listNewLine(int ii);
list argList(int count, int pos, char** args);
void tron();
void troff();
void stron();
void stroff();
void StackTraceMove(char* direction, char* filename, char* fname, char* line);
void StackTracePrint();
void StackTracePrintHelper(list stack);
list NoStackTrace_list();
list NoTrace_list();
int indexOfHelper(char* haystack, char* needle, int start, int current);
int indexOf(char* haystack, char* needle, int start);
char* stringReplace(char* old, char* new, char* s);
bool stringContains(char* haystack, char* needle);
bool stringContainsHelper(char* haystack, char* needle, int startIndex);
bool isWhiteSpace(char* s);
char* stringTrim(char* s);
list stringSplit(char* s, char* delimiter);
bool ansi3IsNil(void* a);
void* pointerAdd(void* a, int b);
char* getEnv(char* key);
void panic(char* s);
int sub(int a, int b);
float mult(int a, int b);
int greaterthan(int a, int b);
float subf(float a, float b);
float multf(float a, float b);
int greaterthanf(float a, float b);
int equalf(float a, float b);
int equal(int a, int b);
int equalString(char* a, char* b);
int string_length(char* s);
char* setSubString(char* target, int start, char* source);
char* sub_string(char* s, int start, int length);
char* stringConcatenate(char* a, char* b);
char* intToString(int a);
char* floatToString(float a);
void* gc_malloc(uint size);
int* makeArray(int length);
int at(int* arr, int index);
void setAt(int* array, int index, int value);
void setCharAt(char* array, int index, int value);
box read_file(char* filename);
void write_file(char* filename, char* data);
char* getStringArray(int index, char** strs);
char** programArgs();
int programArgsCount();
int main(int argc, char** argv);
char* character(int num);
void displays(char* s);
int start();

//End forward declarations



bool notBool(bool a) {
  
if (globalTrace)
    printf("notBool at q/boolean.qon:3 (%s)\n", caller);

  StackTraceMove("in", "q/boolean.qon", "notBool", "3" );

if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:5");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( a) {
if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:6");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:7");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return true;;

  };

}


bool andBool(bool a, bool b) {
  
if (globalTrace)
    printf("andBool at q/boolean.qon:10 (%s)\n", caller);

  StackTraceMove("in", "q/boolean.qon", "andBool", "10" );

if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:12");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( a) {
if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:14");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( b) {
if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:15");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:16");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return false;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:17");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  };

}


bool orBool(bool a, bool b) {
  
if (globalTrace)
    printf("orBool at q/boolean.qon:20 (%s)\n", caller);

  StackTraceMove("in", "q/boolean.qon", "orBool", "20" );

if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:22");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( a) {
if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:23");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:25");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( b) {
if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:26");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:27");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return false;;

    };

  };

}


bool nand(bool a, bool b) {
  
if (globalTrace)
    printf("nand at q/boolean.qon:31 (%s)\n", caller);

  StackTraceMove("in", "q/boolean.qon", "nand", "31" );

if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:33");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return notBool(andBool(a, b));;

}


bool xor(bool a, bool b) {
  
if (globalTrace)
    printf("xor at q/boolean.qon:35 (%s)\n", caller);

  StackTraceMove("in", "q/boolean.qon", "xor", "35" );

if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:37");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return nand(nand(a, nand(a, b)), nand(b, nand(a, b)));;

}


bool lessThan(int a, int b) {
  
if (globalTrace)
    printf("lessThan at q/boolean.qon:39 (%s)\n", caller);

  StackTraceMove("in", "q/boolean.qon", "lessThan", "39" );

if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:41");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return andBool(notBool(equal(a, b)), notBool(greaterthan(a, b)));;

}


list node2FunctionArgs(list tree) {
  
if (globalTrace)
    printf("node2FunctionArgs at q/node2.qon:5 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2FunctionArgs", "5" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:7");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:8");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:10");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(stringify(first(tree)), "...")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:12");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isNil(cddr(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:13");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(boxString("..."), NULL);;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:14");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(boxString("..."), cons(boxString(", "), cons(id(node2FunctionArgs(cddr(tree))), NULL)));;

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:16");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isNil(cddr(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:17");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(node2FuncMap(second(tree))), NULL);;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:18");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(node2FuncMap(second(tree))), cons(boxString(", "), cons(id(node2FunctionArgs(cddr(tree))), NULL)));;

      };

    };

  };

}


list node2Atom(box tree) {
  
if (globalTrace)
    printf("node2Atom at q/node2.qon:20 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Atom", "20" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:22");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("string", boxType(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:23");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString("\""), cons(id(boxString(stringify(tree))), cons(boxString("\""), NULL)));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:24");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(node2FuncMap(tree)), NULL);;

  };

}


list node2Expression(list tree, int indent) {
  list thing = NULL;

if (globalTrace)
    printf("node2Expression at q/node2.qon:26 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Expression", "26" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( notBool(isList(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:29");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return node2Atom(tree);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:31");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equal(1, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:33");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("return"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:34");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(node2FuncMap(car(tree))), NULL);;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:35");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(node2FuncMap(car(tree))), cons(boxString("()"), NULL));;

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:37");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      thing = first(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:38");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxSymbol("get-struct"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:40");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(node2Expression(second(tree), indent)), cons(boxString("."), cons(id(third(tree)), NULL)));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:45");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxSymbol("new"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:46");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return cons(boxString("{}"), NULL);;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:48");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("passthrough"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:49");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return cons(id(second(tree)), NULL);;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:51");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("binop"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:53");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return cons(boxString("("), cons(id(node2Expression(third(tree), indent)), cons(boxString(" "), cons(id(second(tree)), cons(boxString(" "), cons(id(node2Expression(fourth(tree), indent)), cons(boxString(")"), NULL)))))));;

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:62");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return cons(id(node2FuncMap(car(tree))), cons(boxString("("), cons(id(node2RecurList(cdr(tree), indent)), cons(boxString(")"), NULL))));;

            };

          };

        };

      };

    };

  };

}


list node2RecurList(list expr, int indent) {
  
if (globalTrace)
    printf("node2RecurList at q/node2.qon:68 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2RecurList", "68" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:70");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:71");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:73");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:74");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return node2Expression(car(expr), indent);;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:75");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(id(node2Expression(car(expr), indent)), cons(boxString(", "), cons(id(node2RecurList(cdr(expr), indent)), NULL)));;

    };

  };

}


list node2If(list node, int indent, char* functionName) {
  
if (globalTrace)
    printf("node2If at q/node2.qon:80 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2If", "80" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:82");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(boxString("if ("), cons(id(node2Expression(second(node), 0)), cons(boxString(") {"), cons(id(node2Body(cdr(third(node)), add1(indent), functionName)), cons(id(listNewLine(indent)), cons(boxString("} else {"), cons(id(node2Body(cdr(fourth(node)), add1(indent), functionName)), cons(id(listNewLine(indent)), cons(boxString("}"), NULL))))))))));;

}


list node2SetStruct(list node, int indent) {
  
if (globalTrace)
    printf("node2SetStruct at q/node2.qon:94 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2SetStruct", "94" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:96");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(id(node2Expression(second(node), indent)), cons(boxString("."), cons(id(third(node)), cons(boxString(" = "), cons(id(node2Expression(fourth(node), indent)), NULL))))));;

}


list node2Set(list node, int indent) {
  
if (globalTrace)
    printf("node2Set at q/node2.qon:104 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Set", "104" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:106");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(id(node2Expression(second(node), indent)), cons(boxString(" = "), cons(id(node2Expression(third(node), indent)), NULL))));;

}


list node2Return(list node, int indent) {
  
if (globalTrace)
    printf("node2Return at q/node2.qon:112 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Return", "112" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:114");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(listLength(node), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:115");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(listNewLine(indent)), cons(boxString("return"), NULL));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:117");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(listNewLine(indent)), cons(boxString("return "), cons(id(node2Expression(cadr(node), indent)), NULL)));;

  };

}


list node2Statement(list node, int indent, char* functionName) {
  
if (globalTrace)
    printf("node2Statement at q/node2.qon:122 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Statement", "122" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:124");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("set"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:125");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(node2Set(node, indent)), cons(boxString(";\n"), NULL));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:127");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("set-struct"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:128");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(id(node2SetStruct(node, indent)), cons(boxString(";\n"), NULL));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:130");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:131");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(node2If(node, indent, functionName)), cons(boxString(";\n"), NULL));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:133");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("return"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:134");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return cons(id(node2Return(node, indent)), cons(boxString(";\n"), NULL));;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:136");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return cons(id(listNewLine(indent)), cons(id(node2Expression(node, indent)), cons(boxString(";\n"), NULL)));;

        };

      };

    };

  };

}


list node2Body(list tree, int indent, char* functionName) {
  list code = NULL;

if (globalTrace)
    printf("node2Body at q/node2.qon:141 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Body", "141" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:143");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:144");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:146");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    code = car(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:147");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(node2Statement(code, indent, functionName)), cons(id(node2Body(cdr(tree), indent, functionName)), NULL));;

  };

}


list node2Declarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("node2Declarations at q/node2.qon:151 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Declarations", "151" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:153");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:154");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:156");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:157");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(boxString(stringIndent(indent))), cons(boxString("let "), cons(id(node2FuncMap(second(decl))), cons(boxString(" = "), cons(id(node2Expression(third(decl), indent)), cons(boxString(";\n"), cons(id(node2Declarations(cdr(decls), indent)), NULL)))))));;

  };

}


list node2Function(list node) {
  box name = NULL;

if (globalTrace)
    printf("node2Function at q/node2.qon:166 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Function", "166" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:168");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = second(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:169");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:170");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:172");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(listNewLine(0)), cons(id(listNewLine(0)), cons(boxString("function "), cons(id(node2FuncMap(second(node))), cons(boxString("("), cons(id(node2FunctionArgs(third(node))), cons(boxString(") {"), cons(id(listNewLine(1)), cons(id(node2Declarations(cdr(fourth(node)), 1)), cons(id(node2Body(cdr(fifth(node)), 1, stringify(name))), cons(boxString("\n}\n"), NULL)))))))))));;

  };

}


list node2Functions(list tree) {
  
if (globalTrace)
    printf("node2Functions at q/node2.qon:185 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Functions", "185" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:187");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:188");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:190");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(node2Function(car(tree))), cons(id(node2Functions(cdr(tree))), NULL));;

  };

}


list node2Includes(list nodes) {
  
if (globalTrace)
    printf("node2Includes at q/node2.qon:194 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Includes", "194" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:196");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(boxString("\"use strict\";\n"), cons(boxString("const fs = require(\"fs\");\n"), cons(boxString("let globalArgsCount = 0;\n"), cons(boxString("let globalArgs = [];\n"), cons(boxString("let releaseMode = false;\n"), cons(boxString("let globalTrace = false;\n"), cons(boxString("let globalStepTrace = false;\n"), cons(boxString("let globalStackTrace = null;\n"), cons(boxString("let caller = \"\";\n"), cons(boxString("let stderr = process.stderr;\n"), cons(boxString("function cformat(fmt, ...args) {\n"), cons(boxString("  fmt = String(fmt);\n"), cons(boxString("  let out = '';\n"), cons(boxString("  let argi = 0;\n"), cons(boxString("  for (let pos = 0; pos < fmt.length; pos++) {\n"), cons(boxString("    let ch = fmt[pos];\n"), cons(boxString("    if (ch !== '%') { out += ch; continue; }\n"), cons(boxString("    if (fmt[pos + 1] === '%') { out += '%'; pos++; continue; }\n"), cons(boxString("    let precision = null;\n"), cons(boxString("    if (fmt[pos + 1] === '.') {\n"), cons(boxString("      let end = pos + 2;\n"), cons(boxString("      while (end < fmt.length && fmt[end] >= '0' && fmt[end] <= '9') end++;\n"), cons(boxString("      precision = Number(fmt.slice(pos + 2, end));\n"), cons(boxString("      pos = end - 1;\n"), cons(boxString("    }\n"), cons(boxString("    let spec = fmt[pos + 1];\n"), cons(boxString("    if (spec === 's' || spec === 'd') {\n"), cons(boxString("      let value = String(args[argi++]);\n"), cons(boxString("      if (precision !== null) value = value.slice(0, precision);\n"), cons(boxString("      out += value;\n"), cons(boxString("      pos++;\n"), cons(boxString("    } else {\n"), cons(boxString("      out += ch;\n"), cons(boxString("    }\n"), cons(boxString("  }\n"), cons(boxString("  return out;\n"), cons(boxString("}\n"), cons(boxString("function printf(fmt, ...args) { process.stdout.write(cformat(fmt, ...args)); }\n"), cons(boxString("function fprintf(stream, fmt, ...args) { stream.write(cformat(fmt, ...args)); }\n"), NULL)))))))))))))))))))))))))))))))))))))));;

}


list node2Types(list nodes) {
  
if (globalTrace)
    printf("node2Types at q/node2.qon:237 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Types", "237" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:239");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return emptyList();;

}


box node2FuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("node2FuncMap at q/node2.qon:241 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2FuncMap", "241" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:243");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:245");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("new"), boxSymbol("new_"), alistCons(boxSymbol("nil"), boxSymbol("null"), NULL))))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:254");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:255");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cdr(assoc(stringify(aSym), symMap));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:256");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return aSym;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:257");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


list node2MainEntry() {
  
if (globalTrace)
    printf("node2MainEntry at q/node2.qon:259 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2MainEntry", "259" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:261");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(boxString("\n// Main entry point\n"), cons(boxString("globalArgs = [\"fixmeprogname\", ...process.argv.slice(2)];\n"), cons(boxString("globalArgsCount = globalArgs.length;\n"), cons(boxString("start();\n"), NULL))));;

}


list node2LoadProgram(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    printf("node2LoadProgram at q/node2.qon:267 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2LoadProgram", "267" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:269");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:270");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = insertInclude(tree, "q/shims/node2.qon");

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:271");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree, NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:272");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:273");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:274");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:275");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return tree;;

}


list node2ProgramTree(list tree) {
  
if (globalTrace)
    printf("node2ProgramTree at q/node2.qon:277 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2ProgramTree", "277" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:279");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(node2Includes(cdr(first(tree)))), cons(id(node2Types(cdr(second(tree)))), cons(id(node2Functions(cdr(third(tree)))), cons(id(node2MainEntry()), cons(boxString("\n"), NULL)))));;

}


char* node2Program(list tree) {
  
if (globalTrace)
    printf("node2Program at q/node2.qon:286 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Program", "286" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:288");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return ListToString(flatten(node2ProgramTree(tree)), 0, true, false);;

}


char* node2CompileString(char* filename) {
  
if (globalTrace)
    printf("node2CompileString at q/node2.qon:290 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2CompileString", "290" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:292");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return node2Program(node2LoadProgram(filename));;

}


void node2Compile(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    printf("node2Compile at q/node2.qon:294 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Compile", "294" );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Scanning file...%s\n", filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:297");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Loading shim node2\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:299");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = insertInclude(tree, "q/shims/node2.qon");

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Loading all includes\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:301");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree, NULL);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Applying macros\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:303");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:304");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:305");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Printing program\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:307");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printStringTree(node2ProgramTree(tree));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Done printing program\n");

}


void test0() {
  
if (globalTrace)
    printf("test0 at q/tests.qon:7 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test0", "7" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:9");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(stringify(boxString("hello")), stringify(boxString("hello")))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:12");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("0.  pass string compare works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:13");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("0.  pass string compare fails\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:14");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(stringify(boxString("hello")), stringify(boxSymbol("hello")))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:17");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("0.  pass string compare works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:18");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("0.  pass string compare fails\n");

  };

}


void test1() {
  
if (globalTrace)
    printf("test1 at q/tests.qon:20 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test1", "20" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:21");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("1.  pass Function call and print work\n");

}


void test2_do(char* message) {
  
if (globalTrace)
    printf("test2_do at q/tests.qon:24 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test2_do", "24" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:27");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("2.  pass Function call with arg works: %s\n", message);

}


void test2() {
  
if (globalTrace)
    printf("test2 at q/tests.qon:28 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test2", "28" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  test2_do("This is the argument");

}


void test3_do(int b, char* c) {
  
if (globalTrace)
    printf("test3_do at q/tests.qon:30 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test3_do", "30" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:34");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("3.1 pass Two arg call, first arg: %d\n", b);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:35");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("3.2 pass Two arg call, second arg: %s\n", c);

}


void test3() {
  
if (globalTrace)
    printf("test3 at q/tests.qon:36 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test3", "36" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:36");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  test3_do(42, "Fourty-two");

}


char* test4_do() {
  
if (globalTrace)
    printf("test4_do at q/tests.qon:37 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test4_do", "37" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:37");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return "pass Return works";;

}


char* returnThis(char* returnMessage) {
  
if (globalTrace)
    printf("returnThis at q/tests.qon:39 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "returnThis", "39" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:40");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return returnMessage;;

}


void test4() {
  char* message = "fail";

if (globalTrace)
    printf("test4 at q/tests.qon:42 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test4", "42" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:43");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  message = test4_do();

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:43");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("4.  %s\n", message);

}


void test5() {
  char* message = "fail";

if (globalTrace)
    printf("test5 at q/tests.qon:45 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test5", "45" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:47");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  message = returnThis("pass return passthrough string");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:48");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("5.  %s\n", message);

}


void test6() {
  
if (globalTrace)
    printf("test6 at q/tests.qon:50 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test6", "50" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:54");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( true) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:55");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("6.  pass If statement works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:56");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("6.  fail If statement works\n");

  };

}


int test7_do(int count) {
  
if (globalTrace)
    printf("test7_do at q/tests.qon:58 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test7_do", "58" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:62");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  count = sub(count, 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:63");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(count, 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:63");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    count = test7_do(count);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:63");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return count;;

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:64");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return count;;

}


void test7() {
  
if (globalTrace)
    printf("test7 at q/tests.qon:66 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test7", "66" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:70");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(0, test7_do(10))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:71");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("7.  pass count works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:72");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("7.  fail count fails\n");

  };

}


void beer() {
  
if (globalTrace)
    printf("beer at q/tests.qon:74 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "beer", "74" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:78");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%d bottle of beer on the wall, %d bottle of beer.  Take one down, pass it round, no bottles of beer on the wall\n", 1, 1);

}


char* plural(int num) {
  
if (globalTrace)
    printf("plural at q/tests.qon:83 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "plural", "83" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:86");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(num, 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:86");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:86");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "s";;

  };

}


int beers(int count) {
  int newcount = 0;

if (globalTrace)
    printf("beers at q/tests.qon:88 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "beers", "88" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:92");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newcount = sub(count, 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:93");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%d bottle%s of beer on the wall, %d bottle%s of beer.  Take one down, pass it round, %d bottle%s of beer on the wall\n", count, plural(count), count, plural(count), newcount, plural(newcount));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:101");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(count, 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:101");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    count = beers(newcount);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:101");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return count;;

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:102");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return 0;;

}


void test8() {
  
if (globalTrace)
    printf("test8 at q/tests.qon:104 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test8", "104" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:108");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(sub(sub(2, 1), sub(3, 1)), -1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:109");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("8.  pass Nested expressions work\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:110");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("8.  fail Nested expressions don't work\n");

  };

}


void test9() {
  int answer = -999999;
int a = 2;
int b = 3;

if (globalTrace)
    printf("test9 at q/tests.qon:112 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test9", "112" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:119");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  answer = sub(sub(20, 1), sub(3, 1));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:120");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(answer, 17)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:121");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.1  pass sub works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:122");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.1  fail sub\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:123");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  answer = add(2, 3);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:124");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(answer, 5)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:125");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.2  pass add works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:126");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.2  fail add\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:127");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  answer = mult(a, b);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:128");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(answer, 6)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:129");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.3  pass mult works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:130");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.3  fail mult\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:131");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(2, 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:132");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.4  pass greaterthan works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:133");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.4  fail greaterthan\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:134");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(1, 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:135");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.5  pass integer equal works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:136");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.5  fail integer equal\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:137");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("hello", "hello")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:138");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.6  pass string equal works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:139");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.6  fail string equal\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:140");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("hello", "world")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:141");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.7  fail string equal\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:142");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.7  pass string equal\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:143");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( andBool(false, false)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:144");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.8  fail andBool\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:145");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.8  pass andBool works\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:146");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( andBool(true, true)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:147");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.9  pass andBool works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:148");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.9  fail andBool\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:149");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( andBool(true, false)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:150");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.10  fail andBool\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:151");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.10  pass andBool works\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:152");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("hello", "hello")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:153");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.11  pass string equal\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:154");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.11  fail string equal\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:155");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("!", character(33))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:156");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.12  pass character\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:157");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.12  fail character\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:158");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("33", intToString(33))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:159");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.13  pass intToString\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:160");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.13  fail intToString\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:164");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("llo", sub_string("hello", a, b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:165");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.14  pass sub-string\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:166");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.14  fail sub-string: %s\n", sub_string("hello", a, b));

  };

}


void test10() {
  char* testString = "This is a test string";

if (globalTrace)
    printf("test10 at q/tests.qon:170 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test10", "170" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:174");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(testString, unBoxString(car(cons(boxString(testString), NULL))))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:177");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("10. pass cons and car work\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:178");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("10. fail cons and car fail\n");

  };

}


void test12() {
  box b = NULL;

if (globalTrace)
    printf("test12 at q/tests.qon:180 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test12", "180" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:184");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = malloc(sizeof(Box));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:185");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->str = "12. pass structure accessors\n";

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:186");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", b->str);

}


void test13() {
  char* testString = "Hello from the filesystem!";
box contentsBox = NULL;
char* contents = "";

if (globalTrace)
    printf("test13 at q/tests.qon:188 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test13", "188" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:195");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  write_file("test.txt", testString);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:196");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  contentsBox = read_file("test.txt");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:197");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(contentsBox)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:199");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("13. fail Read and write files\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:200");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Expected: %s\n", testString);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:201");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Got: nil\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:203");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    contents = unBoxString(contentsBox);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:204");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(testString, contents)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:205");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("13. pass Read and write files\n");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:207");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("13. fail Read and write files\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:208");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("Expected: %s\n", testString);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:209");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("Got: %s\n", contents);

    };

  };

}


void test14() {
  box contentsBox = NULL;

if (globalTrace)
    printf("test14 at q/tests.qon:213 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test14", "213" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:217");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  contentsBox = read_file("q/this-file-should-not-exist.qon");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:218");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(contentsBox)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:219");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("14. pass Missing read-file returns nil\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:221");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("14. fail Missing read-file returns nil\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:222");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Got: %s\n", unBoxString(contentsBox));

  };

}


void test15() {
  char* a = "hello";
char* b = " world";
char* c = "";

if (globalTrace)
    printf("test15 at q/tests.qon:224 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test15", "224" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:227");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  c = stringConcatenate(a, b);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:228");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(c, "hello world")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:229");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("15. pass String concatenate\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:230");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("15. fail String concatenate\n");

  };

}


void test16() {
  list assocCell1 = NULL;
list assList = NULL;
list assocCell2 = NULL;
list assocCell3 = NULL;

if (globalTrace)
    printf("test16 at q/tests.qon:232 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test16", "232" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:239");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assocCell1 = cons(boxString("Hello"), boxString("world"));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:240");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assocCell2 = cons(boxString("goodnight"), boxString("moon"));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:241");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assocCell3 = cons(boxSymbol("ohio"), boxString("gozaimasu"));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:242");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assList = cons(assocCell2, emptyList());

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:243");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assList = cons(assocCell1, assList);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:244");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assList = cons(assocCell3, assList);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:245");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(cdr(assoc("Hello", assList)), boxString("world"))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:246");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("16.1 pass Basic assoc works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:247");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("16.1 fail Basic assoc fails\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:248");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( andBool(andBool(equalBox(cdr(assoc("Hello", assList)), boxString("world")), equalBox(cdr(assoc("goodnight", assList)), boxString("moon"))), equalBox(cdr(assoc("ohio", assList)), boxString("gozaimasu")))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:253");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("16.2 pass assoc list\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:254");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("16.2 fail assoc list\n");

  };

}


void test17() {
  list l = NULL;

if (globalTrace)
    printf("test17 at q/tests.qon:256 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test17", "256" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:258");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxInt(1), cons(boxInt(2), cons(boxInt(3), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:259");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(car(l), boxInt(1))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:260");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("17. pass list literal works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:261");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("17. fail list literal failed\n");

  };

}


void test18() {
  char* val1 = "a";
char* val2 = "b";
list l = NULL;

if (globalTrace)
    printf("test18 at q/tests.qon:267 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test18", "267" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:273");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:274");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(l, cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), NULL))))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:275");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("18. pass string list constructor works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:276");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("18. fail string list constructor failed\n");

  };

}


void test19() {
  char* val1 = "a";
char* val2 = "b";
list l = NULL;
list revlist = NULL;
list answer = NULL;

if (globalTrace)
    printf("test19 at q/tests.qon:281 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test19", "281" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:290");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:291");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  answer = cons(boxString("c"), cons(boxString(val2), cons(boxString(val1), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:292");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  revlist = reverseList(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:293");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(answer, revlist)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:294");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("19. pass reverseList\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:295");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("19. fail reverseList\n");

  };

}


list concatenateLists(list oldL, list newL) {
  
if (globalTrace)
    printf("concatenateLists at q/tests.qon:299 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "concatenateLists", "299" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:301");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return reverseRec(reverseList(oldL), newL);;

}


void test20() {
  char* val1 = "a";
char* val2 = "b";
char* val3 = "c";
list l = NULL;
list l2 = NULL;
list l3 = NULL;
list combined = NULL;

if (globalTrace)
    printf("test20 at q/tests.qon:304 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test20", "304" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:314");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:315");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l2 = cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:316");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l3 = cons(boxString(val1), cons(boxString(val2), cons(boxString(val3), cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), NULL))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:317");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  combined = concatenateLists(l, l2);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:318");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(l3, combined)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:319");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("21. pass concatenateLists\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:320");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("21. fail concatenateLists\n");

  };

}


void test21() {
  char* val1 = "a";
char* val2 = "b";
char* val3 = "c";
list l = NULL;
list l2 = NULL;

if (globalTrace)
    printf("test21 at q/tests.qon:324 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test21", "324" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:332");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString(val3), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:333");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l2 = cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:334");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(l, l2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:335");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("21. pass equalList\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:336");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("21. fail equalList\n");

  };

}


void test22() {
  list original = NULL;
list out = NULL;
list replace = NULL;
list correct = NULL;

if (globalTrace)
    printf("test22 at q/tests.qon:340 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test22", "340" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:347");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:348");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxString("fprintf"), cons(boxString("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:349");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  out = macrolist(original, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:351");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  correct = cons(boxString("fprintf"), cons(boxString("stderr"), cons(boxString("%s"), cons(boxString("hello"), NULL))));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:352");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(out, correct)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:353");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("22. pass macroList\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:354");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("22. fail macroList\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:355");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("In: ");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:356");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    displayList(original, 0, true);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:357");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\nOut: ");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:358");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    displayList(out, 0, true);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:359");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n");

  };

}


void test23() {
  list original = NULL;
list out = NULL;
list replace = NULL;
list correct = NULL;

if (globalTrace)
    printf("test23 at q/tests.qon:363 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test23", "363" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:370");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:371");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxString("fprintf"), cons(boxString("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:372");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  out = concatLists(original, replace);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:374");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  correct = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), cons(boxString("fprintf"), cons(boxString("stderr"), NULL)))));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:375");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(out, correct)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:376");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("23. pass concatLists\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:377");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("23. fail concatLists\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:378");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("In: ");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:379");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    displayList(original, 0, true);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:380");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\nOut: ");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:381");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    displayList(out, 0, true);

  };

}


void test24() {
  char* expected = "a b c";
char* res = "";

if (globalTrace)
    printf("test24 at q/tests.qon:386 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test24", "386" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:392");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  res = StringListJoin(cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), NULL))), " ");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:393");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(expected, res)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:394");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("24. pass StringListJoin\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:395");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("24. fail StringListJoin.  expected %s, got %s\n", expected, res);

  };

}


void test25() {
  char* expected = "( a b ) c d e";
char* res = "";
list testsubstr = cons(boxString("c "), cons(boxString("d "), cons(boxString("e"), NULL)));
list input = NULL;

if (globalTrace)
    printf("test25 at q/tests.qon:400 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test25", "400" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:408");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  input = cons(boxString("a "), cons(boxString("b "), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:409");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  input = cons(input, testsubstr);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:410");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  res = ListToString(input, 0, true, false);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:411");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(expected, res)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:412");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("25. pass ListToString\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:413");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("25. fail ListToString.  expected %s, got %s\n", expected, res);

  };

}


void test27() {
  char* expected = "a b c d e";
char* floatExpected = "6.5";
char* floatResult = "";
char* res = "";
box floatBox = NULL;
list variable = cons(boxString("c "), cons(boxString("d "), NULL));
list input = NULL;

if (globalTrace)
    printf("test27 at q/tests.qon:436 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test27", "436" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:447");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  input = cons(boxString("a "), cons(boxString("b "), cons(id(variable), cons(boxString("e"), NULL))));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:448");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  res = ListToString(flatten(input), 0, true, false);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:449");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(expected, res)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:450");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("27. pass Interpolated List\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:451");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("27. fail Interpolated List.  expected %s, got %s\n", expected, res);

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:453");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  floatBox = boxFloat(6.5);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:454");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  floatResult = stringify(floatBox);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:455");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(floatExpected, floatResult)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:456");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("27. pass Float box stringify\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:457");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("27. fail Float box stringify.  expected %s, got %s\n", floatExpected, floatResult);

  };

}


void test28() {
  list splitExpected = NULL;
list splitResult = NULL;

if (globalTrace)
    printf("test28 at q/tests.qon:462 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test28", "462" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:467");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("aXYZc", stringReplace("b", "XYZ", "abc"))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:468");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("28.1 pass stringReplace\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:469");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("28.1 fail stringReplace\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:470");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("abc", stringTrim(" abc "))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:471");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("28.2 pass stringTrim\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:472");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("28.2 fail stringTrim\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:473");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  splitExpected = cons(boxString("a"), cons(boxString("b"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:474");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  splitResult = stringSplit("a,b", ",");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:475");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(splitExpected, splitResult)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:476");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("28.3 pass stringSplit\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:477");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("28.3 fail stringSplit\n");

  };

}


char* haskellBackslash() {
  
if (globalTrace)
    printf("haskellBackslash at q/haskell.qon:5 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellBackslash", "5" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:6");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return character(92);;

}


char* haskellDoubleQuote() {
  
if (globalTrace)
    printf("haskellDoubleQuote at q/haskell.qon:8 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellDoubleQuote", "8" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:9");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return character(34);;

}


char* haskellEscapedBackslash() {
  
if (globalTrace)
    printf("haskellEscapedBackslash at q/haskell.qon:11 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellEscapedBackslash", "11" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:12");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return stringConcatenate(haskellBackslash(), haskellBackslash());;

}


char* haskellEscapedDoubleQuote() {
  
if (globalTrace)
    printf("haskellEscapedDoubleQuote at q/haskell.qon:14 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellEscapedDoubleQuote", "14" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:15");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return stringConcatenate(haskellBackslash(), haskellDoubleQuote());;

}


char* haskellEscapeString(char* s) {
  
if (globalTrace)
    printf("haskellEscapeString at q/haskell.qon:17 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellEscapeString", "17" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:19");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  s = stringReplace(character(10), stringConcatenate(haskellBackslash(), "n"), s);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:20");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  s = stringReplace(character(13), stringConcatenate(haskellBackslash(), "r"), s);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:21");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  s = stringReplace(character(9), stringConcatenate(haskellBackslash(), "t"), s);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:22");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return s;;

}


char* haskellSafeNameString(char* name) {
  
if (globalTrace)
    printf("haskellSafeNameString at q/haskell.qon:24 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellSafeNameString", "24" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:26");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "case")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:26");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "caseValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:27");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "class")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:27");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "classValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "data")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:28");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "dataValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:29");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "default")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:29");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "defaultValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:30");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "deriving")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:30");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "derivingValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:31");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "do")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:31");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "doValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:32");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "else")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:32");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "elseValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:33");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "foreign")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:33");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "foreignValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:34");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "if")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:34");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "ifValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:35");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "import")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:35");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "importValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:36");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "in")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:36");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "inValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:37");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "infix")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:37");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "infixValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:38");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "infixl")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:38");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "infixlValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:39");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "infixr")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:39");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "infixrValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:40");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "instance")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:40");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "instanceValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:41");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "let")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:41");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "letValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:42");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "module")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:42");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "moduleValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:43");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "newtype")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:43");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "newtypeValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:44");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "of")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:44");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "ofValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:45");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "then")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:45");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "thenValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:46");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "type")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:46");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "typeValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:47");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "where")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:47");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "whereValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:48");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "id")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:48");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "qid";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:49");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "old")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:49");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "oldValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:50");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "new")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:50");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "newValue";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:51");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( haskellStringStartsWith(name, "-")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:51");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return name;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:52");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "StringListJoinRec")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:52");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "stringListJoinRec";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:53");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "StringListJoin")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:53");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "stringListJoin";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:54");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "ListToBoxString")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:54");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "listToBoxString";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:55");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "ListToString")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:55");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "listToString";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:56");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "StackTraceMove")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:56");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "stackTraceMove";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:57");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "StackTracePrint")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:57");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "stackTracePrint";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:58");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "StackTracePrintHelper")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:58");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "stackTracePrintHelper";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:59");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "NoStackTrace_list")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:59");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "noStackTrace_list";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:60");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(name, "NoTrace_list")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:60");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "noTrace_list";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:61");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = stringReplace("-", "_", name);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:62");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = stringReplace("?", "_q", name);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:63");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = stringReplace("!", "_bang", name);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:64");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return name;;

}


box haskellSafeName(box aSym) {
  
if (globalTrace)
    printf("haskellSafeName at q/haskell.qon:66 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellSafeName", "66" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:68");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return boxSymbol(haskellSafeNameString(stringify(aSym)));;

}


char* haskellFieldName(box aSym) {
  
if (globalTrace)
    printf("haskellFieldName at q/haskell.qon:70 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellFieldName", "70" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:72");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return stringConcatenate("qf_", haskellSafeNameString(stringify(aSym)));;

}


char* haskellNewName(box aSym) {
  
if (globalTrace)
    printf("haskellNewName at q/haskell.qon:74 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellNewName", "74" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:76");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return stringConcatenate("new", stringify(aSym));;

}


bool haskellStringEndsWith(char* s, char* suffix) {
  int start = 0;

if (globalTrace)
    printf("haskellStringEndsWith at q/haskell.qon:78 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellStringEndsWith", "78" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:80");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(string_length(suffix), string_length(s))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:81");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:83");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    start = sub(string_length(s), string_length(suffix));

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:84");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return equalString(sub_string(s, start, string_length(suffix)), suffix);;

  };

}


bool haskellStringStartsWith(char* s, char* prefix) {
  
if (globalTrace)
    printf("haskellStringStartsWith at q/haskell.qon:86 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellStringStartsWith", "86" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:88");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(string_length(prefix), string_length(s))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:89");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:90");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return equalString(sub_string(s, 0, string_length(prefix)), prefix);;

  };

}


box haskellPointerBase(box aSym) {
  char* name = "";

if (globalTrace)
    printf("haskellPointerBase at q/haskell.qon:92 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellPointerBase", "92" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:94");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = stringify(aSym);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:95");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( haskellStringEndsWith(name, "*")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:96");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return boxSymbol(sub_string(name, 0, sub1(string_length(name))));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:97");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


bool haskellTypeIsPointer(box aSym) {
  char* mapped = "";

if (globalTrace)
    printf("haskellTypeIsPointer at q/haskell.qon:99 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellTypeIsPointer", "99" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:101");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  mapped = stringify(haskellTypeMap(aSym));

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:102");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return haskellStringStartsWith(mapped, "Maybe ");;

}


box haskellTypeMap(box aSym) {
  list symMap = NULL;
char* name = "";

if (globalTrace)
    printf("haskellTypeMap at q/haskell.qon:104 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellTypeMap", "104" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:106");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("pair"), boxSymbol("Maybe Box"), alistCons(boxSymbol("box"), boxSymbol("Maybe Box"), alistCons(boxSymbol("list"), boxSymbol("Maybe Box"), alistCons(boxSymbol("Box*"), boxSymbol("Maybe Box"), alistCons(boxSymbol("Pair"), boxSymbol("Box"), alistCons(boxSymbol("struct"), boxSymbol(""), alistCons(boxSymbol("bool"), boxSymbol("Bool"), alistCons(boxSymbol("uint"), boxSymbol("Int"), alistCons(boxSymbol("int"), boxSymbol("Int"), alistCons(boxSymbol("float"), boxSymbol("Double"), alistCons(boxSymbol("void"), boxSymbol("()"), alistCons(boxSymbol("stringArray"), boxSymbol("[String]"), alistCons(boxSymbol("array"), boxSymbol("[String]"), alistCons(boxSymbol("hashmap"), boxSymbol("IORef [(String, String)]"), alistCons(boxSymbol("string"), boxSymbol("String"), NULL)))))))))))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:122");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:123");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:125");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    name = stringify(aSym);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:126");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( haskellStringEndsWith(name, "*")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:127");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return boxSymbol(stringConcatenate("Maybe ", stringify(haskellPointerBase(aSym))));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:128");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return aSym;;

    };

  };

}


char* haskellDefaultValue(box typeSym) {
  char* typ = "";

if (globalTrace)
    printf("haskellDefaultValue at q/haskell.qon:130 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellDefaultValue", "130" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:132");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  typ = stringify(haskellTypeMap(typeSym));

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:133");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(typ, "()")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:133");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "()";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:134");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(typ, "Bool")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:134");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "False";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:135");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(typ, "Int")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:135");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "0";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:136");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(typ, "Double")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:136");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "0.0";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:137");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(typ, "String")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:137");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "\"\"";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:138");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(typ, "[String]")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:138");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "[]";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:139");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( haskellStringStartsWith(typ, "Maybe ")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:139");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "Nothing";;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:140");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return stringConcatenate("(error \"no default value for ", stringConcatenate(typ, "\")"));;

}


char* haskellRefType(box typeSym) {
  
if (globalTrace)
    printf("haskellRefType at q/haskell.qon:142 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellRefType", "142" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:144");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return stringConcatenate("(", stringConcatenate(stringify(haskellTypeMap(typeSym)), ")"));;

}


list haskellGlobalVariables() {
  
if (globalTrace)
    printf("haskellGlobalVariables at q/haskell.qon:146 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellGlobalVariables", "146" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:148");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(boxSymbol("globalArgsCount")), cons(id(boxSymbol("globalArgs")), cons(id(boxSymbol("releaseMode")), cons(id(boxSymbol("caller")), cons(id(boxSymbol("globalTrace")), cons(id(boxSymbol("globalStepTrace")), cons(id(boxSymbol("globalStackTrace")), NULL)))))));;

}


list haskellCollectVariablesFromArgs(list args) {
  list variables = NULL;

if (globalTrace)
    printf("haskellCollectVariablesFromArgs at q/haskell.qon:157 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellCollectVariablesFromArgs", "157" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:159");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(args)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:160");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return variables;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:162");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    variables = cons(second(args), variables);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:163");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return appendVariables(variables, haskellCollectVariablesFromArgs(cddr(args)));;

  };

}


list haskellCollectVariablesFromDecls(list decls) {
  list variables = NULL;
box decl = NULL;

if (globalTrace)
    printf("haskellCollectVariablesFromDecls at q/haskell.qon:165 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellCollectVariablesFromDecls", "165" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:167");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:168");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return variables;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:170");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:171");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    variables = cons(second(decl), variables);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:172");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return appendVariables(variables, haskellCollectVariablesFromDecls(cdr(decls)));;

  };

}


list haskellCollectVariables(list args, list decls) {
  list variables = NULL;

if (globalTrace)
    printf("haskellCollectVariables at q/haskell.qon:174 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellCollectVariables", "174" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:176");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  variables = haskellCollectVariablesFromArgs(args);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:177");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  variables = appendVariables(variables, haskellCollectVariablesFromDecls(decls));

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:178");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  variables = appendVariables(variables, haskellGlobalVariables());

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:179");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return variables;;

}


box haskellFuncMap(box aSym, list variables) {
  list symMap = NULL;

if (globalTrace)
    printf("haskellFuncMap at q/haskell.qon:181 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellFuncMap", "181" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:183");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( orBool(equalString("symbol", boxType(aSym)), equalString("string", boxType(aSym)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:185");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(aSym, variables)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:186");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return haskellSafeName(aSym);;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:188");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("Nothing"), alistCons(boxSymbol("true"), boxSymbol("True"), alistCons(boxSymbol("false"), boxSymbol("False"), alistCons(boxSymbol("old"), boxSymbol("oldValue"), alistCons(boxSymbol("new"), boxSymbol("newValue"), NULL)))))))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:200");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:201");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cdr(assoc(stringify(aSym), symMap));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:202");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return haskellSafeName(aSym);;

      };

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:203");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


list haskellNumberAtom(box tree) {
  char* val = "";

if (globalTrace)
    printf("haskellNumberAtom at q/haskell.qon:205 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellNumberAtom", "205" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:207");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  val = stringify(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:208");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( haskellStringStartsWith(val, "-")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:209");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString("pure ("), cons(id(boxString(val)), cons(boxString(")"), NULL)));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:210");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString("pure "), cons(id(boxString(val)), NULL));;

  };

}


list haskellAtom(box tree, list variables) {
  
if (globalTrace)
    printf("haskellAtom at q/haskell.qon:212 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellAtom", "212" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:214");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("int", boxType(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:215");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return haskellNumberAtom(tree);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:217");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("float", boxType(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:218");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return haskellNumberAtom(tree);;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:220");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("string", boxType(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:221");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(boxString("pure \""), cons(id(boxString(haskellEscapeString(stringify(tree)))), cons(boxString("\""), NULL)));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:223");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( isInt(stringify(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:224");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return haskellNumberAtom(tree);;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:226");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( isFloat(stringify(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:227");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return haskellNumberAtom(tree);;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:229");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( haskellStringStartsWith(stringify(tree), "-")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:230");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return cons(boxString("pure ("), cons(id(haskellFuncMap(tree, variables)), cons(boxString(")"), NULL)));;

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:232");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              if ( inList(tree, variables)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:233");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                StackTraceMove("out", "", "", "");

                return cons(boxString("liftIO (readIORef "), cons(id(haskellFuncMap(tree, variables)), cons(boxString(")"), NULL)));;

              } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:234");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                StackTraceMove("out", "", "", "");

                return cons(boxString("pure "), cons(id(haskellFuncMap(tree, variables)), NULL));;

              };

            };

          };

        };

      };

    };

  };

}


list haskellArgNames(list expr, int pos) {
  
if (globalTrace)
    printf("haskellArgNames at q/haskell.qon:236 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellArgNames", "236" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:238");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:239");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:241");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:242");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(boxString(" arg"), cons(id(boxString(intToString(pos))), NULL));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:243");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(boxString(" arg"), cons(id(boxString(intToString(pos))), cons(id(haskellArgNames(cdr(expr), add1(pos))), NULL)));;

    };

  };

}


list haskellBindArgs(list expr, int indent, list variables, int pos) {
  
if (globalTrace)
    printf("haskellBindArgs at q/haskell.qon:245 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellBindArgs", "245" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:247");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:248");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:249");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(listNewLine(indent)), cons(boxString("arg"), cons(id(boxString(intToString(pos))), cons(boxString(" <- "), cons(id(haskellExpression(car(expr), indent, variables)), cons(id(haskellBindArgs(cdr(expr), indent, variables, add1(pos))), NULL))))));;

  };

}


list haskellCall(box name, list args, int indent, list variables) {
  
if (globalTrace)
    printf("haskellCall at q/haskell.qon:257 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellCall", "257" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:259");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(args)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:260");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString("liftIO "), cons(id(haskellFuncMap(name, NULL)), NULL));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:261");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString("do"), cons(id(haskellBindArgs(args, add1(indent), variables, 0)), cons(id(listNewLine(add1(indent))), cons(boxString("liftIO ("), cons(id(haskellFuncMap(name, NULL)), cons(id(haskellArgNames(args, 0)), cons(boxString(")"), NULL)))))));;

  };

}


list haskellBinop(list tree, int indent, list variables) {
  
if (globalTrace)
    printf("haskellBinop at q/haskell.qon:270 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellBinop", "270" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:272");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(boxString("do"), cons(id(listNewLine(add1(indent))), cons(boxString("arg0 <- "), cons(id(haskellExpression(third(tree), add1(indent), variables)), cons(id(listNewLine(add1(indent))), cons(boxString("arg1 <- "), cons(id(haskellExpression(fourth(tree), add1(indent), variables)), cons(id(listNewLine(add1(indent))), cons(boxString("pure (arg0 "), cons(id(second(tree)), cons(boxString(" arg1)"), NULL)))))))))));;

}


list haskellGetStruct(list tree, int indent, list variables) {
  
if (globalTrace)
    printf("haskellGetStruct at q/haskell.qon:285 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellGetStruct", "285" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:287");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(boxString("do"), cons(id(listNewLine(add1(indent))), cons(boxString("hobj <- "), cons(id(haskellExpression(second(tree), add1(indent), variables)), cons(id(listNewLine(add1(indent))), cons(boxString("liftIO (readIORef ("), cons(boxString("getField @\""), cons(id(boxString(haskellFieldName(third(tree)))), cons(boxString("\" (expect hobj)))"), NULL)))))))));;

}


list haskellNewExpression(list tree) {
  
if (globalTrace)
    printf("haskellNewExpression at q/haskell.qon:298 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellNewExpression", "298" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:300");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( haskellTypeIsPointer(second(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:301");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString("liftIO (Just <$> "), cons(id(boxString(haskellNewName(third(tree)))), cons(boxString(")"), NULL)));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:302");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString("liftIO "), cons(id(boxString(haskellNewName(third(tree)))), NULL));;

  };

}


list haskellExpression(list tree, int indent, list variables) {
  list thing = NULL;

if (globalTrace)
    printf("haskellExpression at q/haskell.qon:304 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellExpression", "304" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:306");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( notBool(isList(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:307");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return haskellAtom(tree, variables);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:309");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equal(1, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:311");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("return"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:312");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(boxString("pure "), cons(id(haskellFuncMap(car(tree), variables)), NULL));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:313");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return haskellCall(car(tree), NULL, indent, variables);;

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:315");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      thing = first(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:316");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxSymbol("get-struct"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:317");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return haskellGetStruct(tree, indent, variables);;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:319");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxSymbol("new"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:320");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return haskellNewExpression(tree);;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:322");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("passthrough"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:323");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return cons(boxString("pure ("), cons(id(second(tree)), cons(boxString(")"), NULL)));;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:325");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("binop"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:326");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return haskellBinop(tree, indent, variables);;

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:327");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return haskellCall(car(tree), cdr(tree), indent, variables);;

            };

          };

        };

      };

    };

  };

}


list haskellSet(list node, int indent, list variables) {
  
if (globalTrace)
    printf("haskellSet at q/haskell.qon:329 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellSet", "329" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:331");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(boxString("qset <- "), cons(id(haskellExpression(third(node), indent, variables)), cons(id(listNewLine(indent)), cons(boxString("liftIO (writeIORef "), cons(id(haskellFuncMap(second(node), variables)), cons(boxString(" qset)"), NULL)))))));;

}


list haskellSetStruct(list node, int indent, list variables) {
  
if (globalTrace)
    printf("haskellSetStruct at q/haskell.qon:340 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellSetStruct", "340" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:342");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(boxString("hobj <- "), cons(id(haskellExpression(second(node), indent, variables)), cons(id(listNewLine(indent)), cons(boxString("qset <- "), cons(id(haskellExpression(fourth(node), indent, variables)), cons(id(listNewLine(indent)), cons(boxString("liftIO (writeIORef ("), cons(boxString("getField @\""), cons(id(boxString(haskellFieldName(third(node)))), cons(boxString("\" (expect hobj)) qset)"), NULL)))))))))));;

}


list haskellReturn(list node, int indent, list variables) {
  
if (globalTrace)
    printf("haskellReturn at q/haskell.qon:355 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellReturn", "355" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:357");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(node), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:358");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(listNewLine(indent)), cons(boxString("hret <- "), cons(id(haskellExpression(cadr(node), indent, variables)), cons(id(listNewLine(indent)), cons(boxString("qreturn hret"), NULL)))));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:364");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(listNewLine(indent)), cons(boxString("qreturn ()"), NULL));;

  };

}


list haskellIf(list node, int indent, list variables) {
  
if (globalTrace)
    printf("haskellIf at q/haskell.qon:366 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellIf", "366" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:368");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(boxString("hcond <- "), cons(id(haskellExpression(second(node), indent, variables)), cons(id(listNewLine(indent)), cons(boxString("if hcond"), cons(id(listNewLine(indent)), cons(boxString("  then do"), cons(id(haskellBody(cdr(third(node)), add(indent, 2), variables)), cons(id(listNewLine(add(indent, 2))), cons(boxString("pure ()"), cons(id(listNewLine(indent)), cons(boxString("  else do"), cons(id(haskellBody(cdr(fourth(node)), add(indent, 2), variables)), cons(id(listNewLine(add(indent, 2))), cons(boxString("pure ()"), NULL)))))))))))))));;

}


list haskellStatement(list node, int indent, list variables) {
  
if (globalTrace)
    printf("haskellStatement at q/haskell.qon:385 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellStatement", "385" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:387");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("set"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:388");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return haskellSet(node, indent, variables);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:390");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("set-struct"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:391");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return haskellSetStruct(node, indent, variables);;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:393");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:394");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return haskellIf(node, indent, variables);;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:396");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("return"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:397");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return haskellReturn(node, indent, variables);;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:398");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return cons(id(listNewLine(indent)), cons(boxString("_ <- "), cons(id(haskellExpression(node, indent, variables)), NULL)));;

        };

      };

    };

  };

}


list haskellBody(list tree, int indent, list variables) {
  
if (globalTrace)
    printf("haskellBody at q/haskell.qon:403 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellBody", "403" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:405");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:406");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:407");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(haskellStatement(car(tree), indent, variables)), cons(id(haskellBody(cdr(tree), indent, variables)), NULL));;

  };

}


list haskellFunctionArgsSignature(list tree) {
  
if (globalTrace)
    printf("haskellFunctionArgsSignature at q/haskell.qon:411 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellFunctionArgsSignature", "411" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:413");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:414");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:416");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:417");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(id(haskellTypeMap(first(tree))), cons(boxString(" -> "), NULL));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:418");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(id(haskellTypeMap(first(tree))), cons(boxString(" -> "), cons(id(haskellFunctionArgsSignature(cddr(tree))), NULL)));;

    };

  };

}


list haskellFunctionArgs(list tree) {
  
if (globalTrace)
    printf("haskellFunctionArgs at q/haskell.qon:420 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellFunctionArgs", "420" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:422");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:423");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:425");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:426");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(boxString(" "), cons(id(haskellFuncMap(second(tree), NULL)), cons(boxString("_arg"), NULL)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:427");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(boxString(" "), cons(id(haskellFuncMap(second(tree), NULL)), cons(boxString("_arg"), cons(id(haskellFunctionArgs(cddr(tree))), NULL))));;

    };

  };

}


list haskellArgRefs(list args, int indent) {
  
if (globalTrace)
    printf("haskellArgRefs at q/haskell.qon:429 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellArgRefs", "429" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:431");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(args)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:432");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:433");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(listNewLine(indent)), cons(id(haskellFuncMap(second(args), NULL)), cons(boxString(" <- liftIO (newIORef "), cons(id(haskellFuncMap(second(args), NULL)), cons(boxString("_arg)"), cons(id(haskellArgRefs(cddr(args), indent)), NULL))))));;

  };

}


list haskellDeclarations(list decls, int indent, list variables) {
  box decl = NULL;

if (globalTrace)
    printf("haskellDeclarations at q/haskell.qon:441 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellDeclarations", "441" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:443");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:444");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:446");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:447");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(listNewLine(indent)), cons(boxString("qinit <- "), cons(id(haskellExpression(third(decl), indent, variables)), cons(id(listNewLine(indent)), cons(id(haskellFuncMap(second(decl), NULL)), cons(boxString(" <- liftIO (newIORef qinit)"), cons(id(haskellDeclarations(cdr(decls), indent, variables)), NULL)))))));;

  };

}


list haskellFunction(list node) {
  list variables = NULL;
list args = NULL;
list decls = NULL;

if (globalTrace)
    printf("haskellFunction at q/haskell.qon:456 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellFunction", "456" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:458");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:459");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:461");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    args = third(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:462");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decls = cdr(fourth(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:463");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    variables = haskellCollectVariables(args, decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:464");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(listNewLine(0)), cons(id(haskellFuncMap(second(node), NULL)), cons(boxString(" :: "), cons(id(haskellFunctionArgsSignature(args)), cons(boxString("IO "), cons(id(boxString(haskellRefType(first(node)))), cons(id(listNewLine(0)), cons(id(haskellFuncMap(second(node), NULL)), cons(id(haskellFunctionArgs(args)), cons(boxString(" = evalContT $ callCC $ \\qreturn -> do"), cons(id(haskellArgRefs(args, 1)), cons(id(haskellDeclarations(decls, 1, variables)), cons(id(haskellBody(cdr(fifth(node)), 1, variables)), cons(id(listNewLine(1)), cons(boxString("pure "), cons(id(boxString(haskellDefaultValue(first(node)))), cons(boxString("\n"), NULL)))))))))))))))));;

  };

}


list haskellFunctions(list tree) {
  
if (globalTrace)
    printf("haskellFunctions at q/haskell.qon:483 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellFunctions", "483" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:485");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:486");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:487");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(haskellFunction(car(tree))), cons(id(haskellFunctions(cdr(tree))), NULL));;

  };

}


list haskellTypeDecl(list l) {
  box fieldType = NULL;

if (globalTrace)
    printf("haskellTypeDecl at q/haskell.qon:491 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellTypeDecl", "491" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:493");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:494");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fieldType = listLast(l);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:495");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fieldType = second(l);

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:496");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(boxString("  "), cons(id(boxString(haskellFieldName(first(l)))), cons(boxString(" :: IORef "), cons(id(boxString(haskellRefType(fieldType))), NULL))));;

}


list haskellStructFields(list node) {
  
if (globalTrace)
    printf("haskellStructFields at q/haskell.qon:502 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellStructFields", "502" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:504");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:505");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:507");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:508");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return haskellTypeDecl(car(node));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:509");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(id(haskellTypeDecl(car(node))), cons(boxString("\n, "), cons(id(haskellStructFields(cdr(node))), NULL)));;

    };

  };

}


list haskellNewStructField(list l, int indent) {
  box fieldType = NULL;

if (globalTrace)
    printf("haskellNewStructField at q/haskell.qon:514 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellNewStructField", "514" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:516");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:517");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fieldType = listLast(l);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:518");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fieldType = second(l);

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:519");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(boxString("v_"), cons(id(boxString(haskellFieldName(first(l)))), cons(boxString(" <- newIORef "), cons(id(boxString(haskellDefaultValue(fieldType))), NULL)))));;

}


list haskellNewStructFields(list fields, int indent) {
  
if (globalTrace)
    printf("haskellNewStructFields at q/haskell.qon:526 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellNewStructFields", "526" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:528");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(fields)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:529");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:530");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(haskellNewStructField(car(fields), indent)), cons(id(haskellNewStructFields(cdr(fields), indent)), NULL));;

  };

}


list haskellStructCtorFields(list fields) {
  
if (globalTrace)
    printf("haskellStructCtorFields at q/haskell.qon:534 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellStructCtorFields", "534" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:536");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(fields)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:537");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:539");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(fields))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:540");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(id(boxString(haskellFieldName(first(car(fields))))), cons(boxString(" = v_"), cons(id(boxString(haskellFieldName(first(car(fields))))), NULL)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:541");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(id(boxString(haskellFieldName(first(car(fields))))), cons(boxString(" = v_"), cons(id(boxString(haskellFieldName(first(car(fields))))), cons(boxString(", "), cons(id(haskellStructCtorFields(cdr(fields))), NULL)))));;

    };

  };

}


list haskellType(list node) {
  list fields = NULL;

if (globalTrace)
    printf("haskellType at q/haskell.qon:548 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellType", "548" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:550");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(second(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:552");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fields = cdr(second(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:553");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString("\ndata "), cons(id(first(node)), cons(boxString(" = "), cons(id(first(node)), cons(boxString(" { "), cons(id(haskellStructFields(fields)), cons(boxString("\n}\n\n"), cons(id(boxString(haskellNewName(first(node)))), cons(boxString(" :: IO "), cons(id(first(node)), cons(boxString("\n"), cons(id(boxString(haskellNewName(first(node)))), cons(boxString(" = do"), cons(id(haskellNewStructFields(fields, 1)), cons(id(listNewLine(1)), cons(boxString("pure "), cons(id(first(node)), cons(boxString(" { "), cons(id(haskellStructCtorFields(fields)), cons(boxString(" }\n"), NULL))))))))))))))))))));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:574");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  };

}


list haskellTypes(list nodes) {
  
if (globalTrace)
    printf("haskellTypes at q/haskell.qon:576 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellTypes", "576" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:578");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:579");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:580");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(haskellType(car(nodes))), cons(id(haskellTypes(cdr(nodes))), NULL));;

  };

}


list haskellIncludes(list nodes) {
  
if (globalTrace)
    printf("haskellIncludes at q/haskell.qon:584 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellIncludes", "584" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:586");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(boxString("{-# LANGUAGE DataKinds #-}\n"), cons(boxString("{-# LANGUAGE DuplicateRecordFields #-}\n"), cons(boxString("{-# LANGUAGE ExtendedDefaultRules #-}\n"), cons(boxString("{-# LANGUAGE TypeApplications #-}\n"), cons(boxString("import Control.Monad.Trans.Cont\n"), cons(boxString("import Control.Monad.IO.Class\n"), cons(boxString("import Data.Char (chr)\n"), cons(boxString("import Data.IORef\n"), cons(boxString("import Data.Maybe (isNothing)\n"), cons(boxString("import GHC.Records (getField)\n"), cons(boxString("import System.Directory (doesFileExist)\n"), cons(boxString("import System.Environment (getArgs, lookupEnv)\n"), cons(boxString("import System.Exit (ExitCode(..), exitWith)\n"), cons(boxString("import System.IO (Handle, stderr, hPutStr, hFlush)\n"), cons(boxString("import System.IO.Unsafe (unsafePerformIO)\n"), cons(boxString("import Text.Printf (printf, hPrintf)\n\n"), cons(boxString("default (Int, Double)\n\n"), cons(boxString("expect :: Maybe a -> a\n"), cons(boxString("expect (Just x) = x\n"), cons(boxString("expect Nothing = error \"Quon nil dereference\"\n\n"), cons(boxString("globalTrace :: IORef Bool\n"), cons(boxString("globalTrace = unsafePerformIO (newIORef False)\n"), cons(boxString("{-# NOINLINE globalTrace #-}\n\n"), cons(boxString("globalStepTrace :: IORef Bool\n"), cons(boxString("globalStepTrace = unsafePerformIO (newIORef False)\n"), cons(boxString("{-# NOINLINE globalStepTrace #-}\n\n"), cons(boxString("releaseMode :: IORef Bool\n"), cons(boxString("releaseMode = unsafePerformIO (newIORef False)\n"), cons(boxString("{-# NOINLINE releaseMode #-}\n\n"), cons(boxString("caller :: IORef String\n"), cons(boxString("caller = unsafePerformIO (newIORef \"\")\n"), cons(boxString("{-# NOINLINE caller #-}\n\n"), cons(boxString("globalArgs :: IORef [String]\n"), cons(boxString("globalArgs = unsafePerformIO (newIORef [])\n"), cons(boxString("{-# NOINLINE globalArgs #-}\n\n"), cons(boxString("globalArgsCount :: IORef Int\n"), cons(boxString("globalArgsCount = unsafePerformIO (newIORef 0)\n"), cons(boxString("{-# NOINLINE globalArgsCount #-}\n\n"), cons(boxString("globalStackTrace :: IORef (Maybe Box)\n"), cons(boxString("globalStackTrace = unsafePerformIO (newIORef Nothing)\n"), cons(boxString("{-# NOINLINE globalStackTrace #-}\n\n"), cons(boxString("hsIsNil :: Maybe a -> IO Bool\n"), cons(boxString("hsIsNil = pure . isNothing\n\n"), cons(boxString("hsGetEnv :: String -> IO String\n"), cons(boxString("hsGetEnv key = do\n"), cons(boxString("  value <- lookupEnv key\n"), cons(boxString("  pure (maybe \"\" (\\x -> x) value)\n\n"), cons(boxString("hsPanic :: String -> IO ()\n"), cons(boxString("hsPanic = error\n\n"), cons(boxString("hsExit :: Int -> IO ()\n"), cons(boxString("hsExit 0 = exitWith ExitSuccess\n"), cons(boxString("hsExit n = exitWith (ExitFailure n)\n\n"), cons(boxString("hsStringLength :: String -> IO Int\n"), cons(boxString("hsStringLength = pure . length\n\n"), cons(boxString("hsSubString :: String -> Int -> Int -> IO String\n"), cons(boxString("hsSubString s start len = pure (take len (drop start s))\n\n"), cons(boxString("hsSetSubString :: String -> Int -> String -> IO String\n"), cons(boxString("hsSetSubString target start source = pure (take start target ++ source ++ drop (start + 1) target)\n\n"), cons(boxString("hsShowInt :: Int -> IO String\n"), cons(boxString("hsShowInt = pure . show\n\n"), cons(boxString("hsShowFloat :: Double -> IO String\n"), cons(boxString("hsShowFloat = pure . show\n\n"), cons(boxString("hsReadFile :: String -> IO (Maybe Box)\n"), cons(boxString("hsReadFile filename = do\n"), cons(boxString("  exists <- doesFileExist filename\n"), cons(boxString("  if exists then do\n"), cons(boxString("    contents <- readFile filename\n"), cons(boxString("    boxString contents\n"), cons(boxString("  else pure Nothing\n\n"), cons(boxString("hsWriteFile :: String -> String -> IO ()\n"), cons(boxString("hsWriteFile = writeFile\n\n"), cons(boxString("hsGetStringArray :: Int -> [String] -> IO String\n"), cons(boxString("hsGetStringArray index strs = pure (strs !! index)\n\n"), cons(boxString("hsProgramArgs :: IO [String]\n"), cons(boxString("hsProgramArgs = readIORef globalArgs\n\n"), cons(boxString("hsProgramArgsCount :: IO Int\n"), cons(boxString("hsProgramArgsCount = readIORef globalArgsCount\n\n"), cons(boxString("hsCharacter :: Int -> IO String\n"), cons(boxString("hsCharacter num = pure [chr num]\n\n"), cons(boxString("hsRemainder :: Int -> Int -> IO Int\n"), cons(boxString("hsRemainder a b = pure (a `mod` b)\n\n"), cons(boxString("hsMakeHash :: IO (IORef [(String, String)])\n"), cons(boxString("hsMakeHash = newIORef []\n\n"), cons(boxString("hsSetHash :: IORef [(String, String)] -> String -> String -> IO ()\n"), cons(boxString("hsSetHash hash key value = modifyIORef hash ((key, value) :)\n\n"), cons(boxString("hsGetHash :: IORef [(String, String)] -> String -> IO String\n"), cons(boxString("hsGetHash hash key = do\n"), cons(boxString("  pairs <- readIORef hash\n"), cons(boxString("  pure (maybe \"\" (\\x -> x) (lookup key pairs))\n\n"), cons(boxString("hsInHash :: IORef [(String, String)] -> String -> IO Bool\n"), cons(boxString("hsInHash hash key = do\n"), cons(boxString("  pairs <- readIORef hash\n"), cons(boxString("  pure (not (isNothing (lookup key pairs)))\n\n"), cons(boxString("hsMakeArray :: Int -> IO [String]\n"), cons(boxString("hsMakeArray len = pure (replicate len \"\")\n\n"), cons(boxString("hsSetArray :: [String] -> Int -> String -> IO ()\n"), cons(boxString("hsSetArray _ _ _ = pure ()\n\n"), cons(boxString("hsGetArray :: [String] -> Int -> IO String\n"), cons(boxString("hsGetArray array index = pure (array !! index)\n\n"), NULL)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));;

}


list haskellMainEntry() {
  
if (globalTrace)
    printf("haskellMainEntry at q/haskell.qon:687 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellMainEntry", "687" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:689");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(boxString("\nmain :: IO ()\n"), cons(boxString("main = do\n"), cons(boxString("  args <- getArgs\n"), cons(boxString("  let qargs = \"fixmeprogname\" : args\n"), cons(boxString("  writeIORef globalArgs qargs\n"), cons(boxString("  writeIORef globalArgsCount (length qargs)\n"), cons(boxString("  _ <- start\n"), cons(boxString("  pure ()\n"), NULL))))))));;

}


list haskellApplyTypeAliases(list tree, list types) {
  list node = NULL;
box alias = NULL;
box target = NULL;

if (globalTrace)
    printf("haskellApplyTypeAliases at q/haskell.qon:699 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellApplyTypeAliases", "699" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:701");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(types)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:702");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return tree;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:704");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  node = car(types);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:705");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(second(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:706");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return haskellApplyTypeAliases(tree, cdr(types));;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:708");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  alias = first(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:709");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(stringify(haskellTypeMap(alias)), stringify(alias))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:711");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    target = haskellTypeMap(second(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:712");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return haskellApplyTypeAliases(macroSymbolSingle(tree, stringify(alias), stringify(target)), cdr(types));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:713");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return haskellApplyTypeAliases(tree, cdr(types));;

  };

}


list haskellLoadProgram(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    printf("haskellLoadProgram at q/haskell.qon:715 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellLoadProgram", "715" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:717");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:718");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = insertInclude(tree, "q/shims/haskell.qon");

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:719");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree, NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:720");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:721");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("hPrintf"), cons(boxSymbol("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:722");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:723");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = haskellApplyTypeAliases(tree, cdr(getTypes(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:724");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return tree;;

}


list haskellProgramTree(list tree) {
  
if (globalTrace)
    printf("haskellProgramTree at q/haskell.qon:726 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellProgramTree", "726" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:728");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(haskellIncludes(cdr(first(tree)))), cons(id(haskellTypes(cdr(second(tree)))), cons(id(haskellFunctions(cdr(third(tree)))), cons(id(haskellMainEntry()), cons(boxString("\n"), NULL)))));;

}


char* haskellProgram(list tree) {
  
if (globalTrace)
    printf("haskellProgram at q/haskell.qon:735 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellProgram", "735" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:737");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return ListToString(flatten(haskellProgramTree(tree)), 0, true, false);;

}


char* haskellCompileString(char* filename) {
  
if (globalTrace)
    printf("haskellCompileString at q/haskell.qon:739 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellCompileString", "739" );

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:741");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return haskellProgram(haskellLoadProgram(filename));;

}


void haskellCompile(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    printf("haskellCompile at q/haskell.qon:743 (%s)\n", caller);

  StackTraceMove("in", "q/haskell.qon", "haskellCompile", "743" );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Scanning file...%s\n", filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:746");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Adding Haskell shim functions\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:748");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = insertInclude(tree, "q/shims/haskell.qon");

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Loading includes\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:750");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree, NULL);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Walking tree\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:752");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Replacing q log\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:754");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("hPrintf"), cons(boxSymbol("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:755");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:756");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = haskellApplyTypeAliases(tree, cdr(getTypes(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Printing program\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/haskell.qon:758");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printStringTree(haskellProgramTree(tree));

}


list javaFunctionArgs(list tree) {
  
if (globalTrace)
    printf("javaFunctionArgs at q/java.qon:5 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaFunctionArgs", "5" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:7");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:8");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:10");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(stringify(first(tree)), "...")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:12");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isNil(cddr(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:13");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(boxString("Object... args"), NULL);;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:14");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(boxString("Object... args, "), cons(id(javaFunctionArgs(cddr(tree))), NULL));;

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:16");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isNil(cddr(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:17");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(javaTypeMap(first(tree))), cons(boxString(" "), cons(id(javaFuncMap(second(tree))), NULL)));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:19");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(javaTypeMap(first(tree))), cons(boxString(" "), cons(id(javaFuncMap(second(tree))), cons(boxString(", "), cons(id(javaFunctionArgs(cddr(tree))), NULL)))));;

      };

    };

  };

}


list javaAtom(box tree) {
  
if (globalTrace)
    printf("javaAtom at q/java.qon:26 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaAtom", "26" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("string", boxType(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:29");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString("\""), cons(id(boxString(stringify(tree))), cons(boxString("\""), NULL)));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:30");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(javaFuncMap(tree)), NULL);;

  };

}


list javaExpression(list tree, int indent) {
  list thing = NULL;

if (globalTrace)
    printf("javaExpression at q/java.qon:32 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaExpression", "32" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:34");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( notBool(isList(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:35");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return javaAtom(tree);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:37");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equal(1, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:39");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("return"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:40");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(javaFuncMap(car(tree))), NULL);;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:41");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(javaFuncMap(car(tree))), cons(boxString("()"), NULL));;

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:43");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      thing = first(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:44");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxSymbol("get-struct"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:46");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(javaExpression(second(tree), indent)), cons(boxString("."), cons(id(third(tree)), NULL)));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:51");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxSymbol("new"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:53");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return cons(boxString("new "), cons(id(javaTypeMap(second(tree))), cons(boxString("()"), NULL)));;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:58");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("passthrough"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:59");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return cons(id(second(tree)), NULL);;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:61");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("binop"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:63");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return cons(boxString("("), cons(id(javaExpression(third(tree), indent)), cons(boxString(" "), cons(id(second(tree)), cons(boxString(" "), cons(id(javaExpression(fourth(tree), indent)), cons(boxString(")"), NULL)))))));;

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:72");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return cons(id(javaFuncMap(car(tree))), cons(boxString("("), cons(id(javaRecurList(cdr(tree), indent)), cons(boxString(")"), NULL))));;

            };

          };

        };

      };

    };

  };

}


list javaRecurList(list expr, int indent) {
  
if (globalTrace)
    printf("javaRecurList at q/java.qon:78 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaRecurList", "78" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:80");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:81");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:83");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:84");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return javaExpression(car(expr), indent);;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:86");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(id(javaExpression(car(expr), indent)), cons(boxString(", "), cons(id(javaRecurList(cdr(expr), indent)), NULL)));;

    };

  };

}


list javaIf(list node, int indent) {
  
if (globalTrace)
    printf("javaIf at q/java.qon:91 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaIf", "91" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:93");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(boxString("if ( "), cons(id(javaExpression(second(node), 0)), cons(boxString(") {"), cons(id(javaBody(cdr(third(node)), add1(indent))), cons(id(listNewLine(indent)), cons(boxString("} else {"), cons(id(javaBody(cdr(fourth(node)), add1(indent))), cons(id(listNewLine(indent)), cons(boxString("}"), NULL))))))))));;

}


list javaSetStruct(list node, int indent) {
  
if (globalTrace)
    printf("javaSetStruct at q/java.qon:105 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaSetStruct", "105" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:107");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(id(javaExpression(second(node), indent)), cons(boxString("."), cons(id(third(node)), cons(boxString(" = "), cons(id(javaExpression(fourth(node), indent)), NULL))))));;

}


list javaSet(list node, int indent) {
  
if (globalTrace)
    printf("javaSet at q/java.qon:115 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaSet", "115" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:117");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(id(javaExpression(second(node), indent)), cons(boxString(" = "), cons(id(javaExpression(third(node), indent)), NULL))));;

}


list javaReturn(list node, int indent) {
  
if (globalTrace)
    printf("javaReturn at q/java.qon:123 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaReturn", "123" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:125");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(listLength(node), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:126");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(listNewLine(indent)), cons(boxString("return"), NULL));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:128");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(listNewLine(indent)), cons(boxString("return "), cons(id(javaExpression(cadr(node), indent)), NULL)));;

  };

}


list javaStatement(list node, int indent) {
  
if (globalTrace)
    printf("javaStatement at q/java.qon:133 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaStatement", "133" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:135");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("set"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:136");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(javaSet(node, indent)), cons(boxString(";\n"), NULL));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:138");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("set-struct"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:139");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(id(javaSetStruct(node, indent)), cons(boxString(";\n"), NULL));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:141");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:142");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(javaIf(node, indent)), cons(boxString("\n"), NULL));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:144");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("return"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:145");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return cons(id(javaReturn(node, indent)), cons(boxString(";\n"), NULL));;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:147");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return cons(id(listNewLine(indent)), cons(id(javaExpression(node, indent)), cons(boxString(";\n"), NULL)));;

        };

      };

    };

  };

}


list javaBody(list tree, int indent) {
  list code = NULL;

if (globalTrace)
    printf("javaBody at q/java.qon:152 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaBody", "152" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:154");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:155");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:157");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    code = car(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:158");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(javaStatement(code, indent)), cons(id(javaBody(cdr(tree), indent)), NULL));;

  };

}


list javaDeclarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("javaDeclarations at q/java.qon:162 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaDeclarations", "162" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:164");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:165");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:167");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:168");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(javaTypeMap(first(decl))), cons(boxString(" "), cons(id(javaFuncMap(second(decl))), cons(boxString(" = "), cons(id(javaExpression(third(decl), indent)), cons(boxString(";\n"), cons(id(javaDeclarations(cdr(decls), indent)), NULL)))))));;

  };

}


list javaFunction(list node) {
  box name = NULL;

if (globalTrace)
    printf("javaFunction at q/java.qon:177 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaFunction", "177" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:179");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = second(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:180");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:181");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:183");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(listNewLine(0)), cons(id(listNewLine(0)), cons(id(javaTypeMap(first(node))), cons(boxString(" "), cons(id(javaFuncMap(second(node))), cons(boxString("("), cons(id(javaFunctionArgs(third(node))), cons(boxString(") {"), cons(id(listNewLine(1)), cons(id(javaDeclarations(cdr(fourth(node)), 1)), cons(id(javaBody(cdr(fifth(node)), 1)), cons(boxString("\n}\n"), NULL))))))))))));;

  };

}


list javaFunctions(list tree) {
  
if (globalTrace)
    printf("javaFunctions at q/java.qon:197 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaFunctions", "197" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:199");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:200");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:202");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(javaFunction(car(tree))), cons(id(javaFunctions(cdr(tree))), NULL));;

  };

}


list javaIncludes(list nodes) {
  
if (globalTrace)
    printf("javaIncludes at q/java.qon:206 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaIncludes", "206" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:208");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(boxString("import java.nio.charset.StandardCharsets;\n"), cons(boxString("import java.nio.file.Files;\n"), cons(boxString("import java.nio.file.Paths;\n"), cons(boxString("import java.util.HashMap;\n\n"), cons(boxString("class QuonProgram {\n"), cons(boxString("  boolean globalTrace = false;\n"), cons(boxString("  boolean globalStepTrace = false;\n"), cons(boxString("  boolean releaseMode = false;\n"), cons(boxString("  Box globalStackTrace = null;\n"), cons(boxString("  String caller = \"\";\n"), cons(boxString("  String[] globalArgs = new String[0];\n"), cons(boxString("  int globalArgsCount = 0;\n\n"), cons(boxString("  Object stderr = new Object();\n\n"), cons(boxString("  void fprintf(Object stream, String format, Object... args) {\n"), cons(boxString("    if (args.length == 0) {\n"), cons(boxString("      System.err.print(format);\n"), cons(boxString("    } else {\n"), cons(boxString("      System.err.printf(format, args);\n"), cons(boxString("    }\n"), cons(boxString("  }\n\n"), cons(boxString("  void exit(int code) {\n"), cons(boxString("    System.exit(code);\n"), cons(boxString("  }\n\n"), cons(boxString("  Box readFileBox(String filename) {\n"), cons(boxString("    try {\n"), cons(boxString("      return boxString(Files.readString(Paths.get(filename)));\n"), cons(boxString("    } catch (Exception e) {\n"), cons(boxString("      return null;\n"), cons(boxString("    }\n"), cons(boxString("  }\n\n"), cons(boxString("  void writeFileUnchecked(String filename, String data) {\n"), cons(boxString("    try {\n"), cons(boxString("      Files.write(Paths.get(filename), data.getBytes(StandardCharsets.UTF_8));\n"), cons(boxString("    } catch (Exception e) {\n"), cons(boxString("      throw new RuntimeException(\"Could not write file: \" + filename, e);\n"), cons(boxString("    }\n"), cons(boxString("  }\n"), NULL)))))))))))))))))))))))))))))))))))));;

}


box javaTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("javaTypeMap at q/java.qon:247 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaTypeMap", "247" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:249");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("pair"), boxSymbol("Box"), alistCons(boxSymbol("box"), boxSymbol("Box"), alistCons(boxSymbol("list"), boxSymbol("Box"), alistCons(boxSymbol("Box*"), boxSymbol("Box"), alistCons(boxSymbol("struct"), boxSymbol(""), alistCons(boxSymbol("bool"), boxSymbol("boolean"), alistCons(boxSymbol("uint"), boxSymbol("int"), alistCons(boxSymbol("float"), boxSymbol("double"), alistCons(boxSymbol("stringArray"), boxSymbol("String[]"), alistCons(boxSymbol("array"), boxSymbol("String[]"), alistCons(boxSymbol("hashmap"), boxSymbol("HashMap<String, String>"), alistCons(boxSymbol("string"), boxSymbol("String"), NULL))))))))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:263");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:264");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:265");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


box javaPointerBase(box aSym) {
  char* name = "";

if (globalTrace)
    printf("javaPointerBase at q/java.qon:267 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaPointerBase", "267" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:269");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = stringify(aSym);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:270");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("*", sub_string(name, sub1(string_length(name)), 1))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:271");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return boxSymbol(sub_string(name, 0, sub1(string_length(name))));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:272");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


box javaFuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("javaFuncMap at q/java.qon:274 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaFuncMap", "274" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:276");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:278");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("printf"), boxSymbol("System.out.printf"), alistCons(boxSymbol(stringConcatenate("q", "log")), boxSymbol("System.err.printf"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("null"), alistCons(boxSymbol("old"), boxSymbol("oldValue"), alistCons(boxSymbol("new"), boxSymbol("newValue"), NULL)))))))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:311");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:312");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cdr(assoc(stringify(aSym), symMap));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:313");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return aSym;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:314");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


list javaTypeDecl(list l) {
  
if (globalTrace)
    printf("javaTypeDecl at q/java.qon:316 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaTypeDecl", "316" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:318");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:320");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(boxString(stringIndent(1))), cons(id(javaTypeMap(listLast(l))), cons(boxString(" "), cons(id(first(l)), cons(boxString(";\n"), NULL)))));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:327");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(boxString(stringIndent(1))), cons(id(javaTypeMap(listLast(l))), cons(boxString(" "), cons(id(car(l)), cons(boxString(";\n"), NULL)))));;

  };

}


list javaStructComponents(list node) {
  
if (globalTrace)
    printf("javaStructComponents at q/java.qon:334 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaStructComponents", "334" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:336");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:337");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:339");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(javaTypeDecl(car(node))), cons(id(javaStructComponents(cdr(node))), NULL));;

  };

}


list javaStruct(list node) {
  
if (globalTrace)
    printf("javaStruct at q/java.qon:343 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaStruct", "343" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:345");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return javaStructComponents(cdr(node));;

}


list javaType(list node) {
  
if (globalTrace)
    printf("javaType at q/java.qon:347 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaType", "347" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:349");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(second(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:351");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString("\nclass "), cons(id(first(node)), cons(boxString(" {\n"), cons(id(javaStruct(second(node))), cons(boxString("}\n"), NULL)))));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:357");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  };

}


list javaTypes(list nodes) {
  
if (globalTrace)
    printf("javaTypes at q/java.qon:359 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaTypes", "359" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:361");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:362");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:364");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(javaType(car(nodes))), cons(id(javaTypes(cdr(nodes))), NULL));;

  };

}


list javaApplyTypeAliases(list tree, list types) {
  list node = NULL;
box alias = NULL;
box target = NULL;

if (globalTrace)
    printf("javaApplyTypeAliases at q/java.qon:368 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaApplyTypeAliases", "368" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:370");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(types)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:371");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return tree;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:373");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  node = car(types);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:374");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(second(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:375");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return javaApplyTypeAliases(tree, cdr(types));;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:377");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  alias = first(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:378");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(stringify(javaTypeMap(alias)), stringify(alias))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:380");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    target = javaTypeMap(javaPointerBase(second(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:381");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return javaApplyTypeAliases(macroSymbolSingle(tree, stringify(alias), stringify(target)), cdr(types));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:382");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return javaApplyTypeAliases(tree, cdr(types));;

  };

}


list javaMainEntry() {
  
if (globalTrace)
    printf("javaMainEntry at q/java.qon:384 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaMainEntry", "384" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:386");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(boxString("\npublic static void main(String[] args) {\n"), cons(boxString("  QuonProgram program = new QuonProgram();\n"), cons(boxString("  program.globalArgs = new String[args.length + 1];\n"), cons(boxString("  program.globalArgs[0] = \"fixmeprogname\";\n"), cons(boxString("  System.arraycopy(args, 0, program.globalArgs, 1, args.length);\n"), cons(boxString("  program.globalArgsCount = program.globalArgs.length;\n"), cons(boxString("  program.start();\n"), cons(boxString("}\n"), cons(boxString("}\n"), NULL)))))))));;

}


list javaLoadProgram(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    printf("javaLoadProgram at q/java.qon:397 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaLoadProgram", "397" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:399");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:400");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = buildProg(cons(boxString("q/shims/java.qon"), getIncludes(tree)), getTypes(tree), getFunctions(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:401");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree, NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:402");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:403");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:404");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:405");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = javaApplyTypeAliases(tree, cdr(getTypes(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:406");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return tree;;

}


list javaProgramTree(list tree) {
  
if (globalTrace)
    printf("javaProgramTree at q/java.qon:408 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaProgramTree", "408" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:410");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(javaIncludes(cdr(first(tree)))), cons(id(javaTypes(cdr(second(tree)))), cons(id(javaFunctions(cdr(third(tree)))), cons(id(javaMainEntry()), cons(boxString("\n"), NULL)))));;

}


char* javaProgram(list tree) {
  
if (globalTrace)
    printf("javaProgram at q/java.qon:417 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaProgram", "417" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:419");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return ListToString(flatten(javaProgramTree(tree)), 0, true, false);;

}


char* javaCompileString(char* filename) {
  
if (globalTrace)
    printf("javaCompileString at q/java.qon:421 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaCompileString", "421" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:423");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return javaProgram(javaLoadProgram(filename));;

}


void javaCompile(char* filename) {
  
if (globalTrace)
    printf("javaCompile at q/java.qon:425 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaCompile", "425" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:427");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printStringTree(javaProgramTree(javaLoadProgram(filename)));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Done printing program\n");

}


list ansi3FunctionArgs(list tree) {
  
if (globalTrace)
    printf("ansi3FunctionArgs at q/ansi3.qon:5 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3FunctionArgs", "5" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:7");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:8");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:10");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(stringify(first(tree)), "...")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:12");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isNil(cddr(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:13");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(boxString("..."), NULL);;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:14");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(boxString("..."), cons(boxString(", "), cons(id(ansi3FunctionArgs(cddr(tree))), NULL)));;

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:16");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isNil(cddr(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:17");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(ansi3TypeMap(first(tree))), cons(boxString(" "), cons(id(second(tree)), NULL)));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:19");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(ansi3TypeMap(first(tree))), cons(boxString(" "), cons(id(second(tree)), cons(boxString(", "), cons(id(ansi3FunctionArgs(cddr(tree))), NULL)))));;

      };

    };

  };

}


list ansi3Atom(box tree) {
  
if (globalTrace)
    printf("ansi3Atom at q/ansi3.qon:26 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Atom", "26" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("string", boxType(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:29");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString("\""), cons(id(boxString(stringify(tree))), cons(boxString("\""), NULL)));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:30");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(ansi3FuncMap(tree)), NULL);;

  };

}


list ansi3Expression(list tree, int indent) {
  list thing = NULL;

if (globalTrace)
    printf("ansi3Expression at q/ansi3.qon:32 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Expression", "32" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:34");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( notBool(isList(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:35");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return ansi3Atom(tree);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:37");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equal(1, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:39");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("return"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:40");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(ansi3FuncMap(car(tree))), NULL);;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:41");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(ansi3FuncMap(car(tree))), cons(boxString("()"), NULL));;

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:43");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      thing = first(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:44");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxSymbol("get-struct"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:46");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(second(tree)), cons(boxString("->"), cons(id(third(tree)), NULL)));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:51");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxSymbol("new"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:53");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return cons(boxString("malloc(sizeof("), cons(id(third(tree)), cons(boxString("))"), NULL)));;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:58");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("passthrough"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:59");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return cons(id(second(tree)), NULL);;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:61");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("binop"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:63");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return cons(boxString("("), cons(id(ansi3Expression(third(tree), indent)), cons(boxString(" "), cons(id(second(tree)), cons(boxString(" "), cons(id(ansi3Expression(fourth(tree), indent)), cons(boxString(")"), NULL)))))));;

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:72");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return cons(id(ansi3FuncMap(car(tree))), cons(boxString("("), cons(id(ansi3RecurList(cdr(tree), indent)), cons(boxString(")"), NULL))));;

            };

          };

        };

      };

    };

  };

}


list ansi3RecurList(list expr, int indent) {
  
if (globalTrace)
    printf("ansi3RecurList at q/ansi3.qon:78 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3RecurList", "78" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:80");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:81");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:83");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:84");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return ansi3Expression(car(expr), indent);;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:86");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(id(ansi3Expression(car(expr), indent)), cons(boxString(", "), cons(id(ansi3RecurList(cdr(expr), indent)), NULL)));;

    };

  };

}


list ansi3If(list node, int indent, char* functionName) {
  
if (globalTrace)
    printf("ansi3If at q/ansi3.qon:91 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3If", "91" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:93");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(boxString("if ( "), cons(id(ansi3Expression(second(node), 0)), cons(boxString(") {"), cons(id(ansi3Body(cdr(third(node)), add1(indent), functionName)), cons(id(listNewLine(indent)), cons(boxString("} else {"), cons(id(ansi3Body(cdr(fourth(node)), add1(indent), functionName)), cons(id(listNewLine(indent)), cons(boxString("}"), NULL))))))))));;

}


list ansi3SetStruct(list node, int indent) {
  
if (globalTrace)
    printf("ansi3SetStruct at q/ansi3.qon:105 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3SetStruct", "105" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:107");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(id(second(node)), cons(boxString("->"), cons(id(third(node)), cons(boxString(" = "), cons(id(ansi3Expression(fourth(node), indent)), NULL))))));;

}


list ansi3Set(list node, int indent) {
  
if (globalTrace)
    printf("ansi3Set at q/ansi3.qon:115 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Set", "115" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:117");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(id(ansi3Expression(second(node), indent)), cons(boxString(" = "), cons(id(ansi3Expression(third(node), indent)), NULL))));;

}


list ansi3Return(list node, int indent) {
  
if (globalTrace)
    printf("ansi3Return at q/ansi3.qon:123 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Return", "123" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:125");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(listLength(node), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:126");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(listNewLine(indent)), cons(boxString("return;"), NULL));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:128");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(listNewLine(indent)), cons(boxString("return "), cons(id(ansi3Expression(cadr(node), indent)), cons(boxString(";"), NULL))));;

  };

}


list ansi3TraceReturn(list node, int indent, char* functionName) {
  
if (globalTrace)
    printf("ansi3TraceReturn at q/ansi3.qon:134 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3TraceReturn", "134" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:136");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:137");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return ansi3Return(node, indent);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:139");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(boxString(functionName), NoStackTrace_list())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:140");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return ansi3Return(node, indent);;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:142");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(boxString("\n"), cons(id(boxString(stringIndent(indent))), cons(boxString("StackTraceMove(\"out\", \"\", \"\", \"\");\n"), cons(id(ansi3Return(node, indent)), NULL))));;

    };

  };

}


list ansi3Statement(list node, int indent, char* functionName) {
  
if (globalTrace)
    printf("ansi3Statement at q/ansi3.qon:148 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Statement", "148" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:150");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("set"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:151");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(ansi3Set(node, indent)), cons(boxString(";\n"), NULL));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:153");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("set-struct"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:154");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(id(ansi3SetStruct(node, indent)), cons(boxString(";\n"), NULL));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:156");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:157");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(ansi3If(node, indent, functionName)), cons(boxString(";\n"), NULL));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:159");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("return"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:160");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return cons(id(ansi3TraceReturn(node, indent, functionName)), cons(boxString(";\n"), NULL));;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:162");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return cons(id(listNewLine(indent)), cons(id(ansi3Expression(node, indent)), cons(boxString(";\n"), NULL)));;

        };

      };

    };

  };

}


list ansi3StatementTrace(list code, int indent, char* functionName) {
  
if (globalTrace)
    printf("ansi3StatementTrace at q/ansi3.qon:167 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3StatementTrace", "167" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:169");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:170");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:172");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(boxString(functionName), NoTrace_list())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:173");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return emptyList();;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:175");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(boxString("\nif (globalTrace)\n    snprintf(caller, 1024, \"from "), cons(id(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), cons(boxString(":"), cons(id(getTagFail(car(code), boxString("line"), boxString("Line missing"))), cons(boxString("\");\n"), NULL)))));;

    };

  };

}


list ansi3StepTrace(int indent) {
  
if (globalTrace)
    printf("ansi3StepTrace at q/ansi3.qon:182 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3StepTrace", "182" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:184");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:185");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:187");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(boxString(stringIndent(indent))), cons(boxString("if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n"), NULL));;

  };

}


list ansi3Body(list tree, int indent, char* functionName) {
  list code = NULL;

if (globalTrace)
    printf("ansi3Body at q/ansi3.qon:191 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Body", "191" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:193");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:194");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:196");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    code = car(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:197");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(ansi3StatementTrace(code, indent, functionName)), cons(id(ansi3StepTrace(indent)), cons(id(ansi3Statement(code, indent, functionName)), cons(id(ansi3Body(cdr(tree), indent, functionName)), NULL))));;

  };

}


list ansi3Declarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("ansi3Declarations at q/ansi3.qon:203 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Declarations", "203" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:205");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:206");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:208");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:209");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(ansi3TypeMap(first(decl))), cons(boxString(" "), cons(id(second(decl)), cons(boxString(" = "), cons(id(ansi3Expression(third(decl), indent)), cons(boxString(";\n"), cons(id(ansi3Declarations(cdr(decls), indent)), NULL)))))));;

  };

}


list ansi3FunctionTrace(box name) {
  
if (globalTrace)
    printf("ansi3FunctionTrace at q/ansi3.qon:218 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3FunctionTrace", "218" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:220");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:221");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:223");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(name, NoTrace_list())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:224");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return emptyList();;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:226");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(boxString("\nif (globalTrace)\n    printf(\""), cons(id(name), cons(boxString(" at "), cons(id(getTag(name, boxString("filename"))), cons(boxString(":"), cons(id(getTag(name, boxString("line"))), cons(boxString(" (%s)\\n\", caller);\n"), NULL)))))));;

    };

  };

}


list ansi3FunctionStackTrace(box name) {
  
if (globalTrace)
    printf("ansi3FunctionStackTrace at q/ansi3.qon:235 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3FunctionStackTrace", "235" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:237");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:238");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:240");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(name, NoStackTrace_list())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:241");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return emptyList();;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:243");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(boxString("\n  StackTraceMove(\"in\", \""), cons(id(getTag(name, boxString("filename"))), cons(boxString("\", \""), cons(id(name), cons(boxString("\", \""), cons(id(getTag(name, boxString("line"))), cons(boxString("\" );\n"), NULL)))))));;

    };

  };

}


list ansi3Function(list node) {
  box name = NULL;

if (globalTrace)
    printf("ansi3Function at q/ansi3.qon:252 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Function", "252" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:254");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = second(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:255");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:256");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:258");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(listNewLine(0)), cons(id(listNewLine(0)), cons(id(ansi3TypeMap(first(node))), cons(boxString(" "), cons(id(second(node)), cons(boxString("("), cons(id(ansi3FunctionArgs(third(node))), cons(boxString(") {"), cons(id(listNewLine(1)), cons(id(ansi3Declarations(cdr(fourth(node)), 1)), cons(id(ansi3FunctionTrace(name)), cons(id(ansi3FunctionStackTrace(name)), cons(id(ansi3Body(cdr(fifth(node)), 1, stringify(name))), cons(boxString("\n}\n"), NULL))))))))))))));;

  };

}


list ansi3ForwardDeclaration(list node) {
  
if (globalTrace)
    printf("ansi3ForwardDeclaration at q/ansi3.qon:274 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3ForwardDeclaration", "274" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:276");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:277");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:279");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString("\n"), cons(id(ansi3TypeMap(first(node))), cons(boxString(" "), cons(id(second(node)), cons(boxString("("), cons(id(ansi3FunctionArgs(third(node))), cons(boxString(");"), NULL)))))));;

  };

}


list ansi3ForwardDeclarations(list tree) {
  
if (globalTrace)
    printf("ansi3ForwardDeclarations at q/ansi3.qon:288 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3ForwardDeclarations", "288" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:290");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:291");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:293");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(ansi3ForwardDeclaration(car(tree))), cons(id(ansi3ForwardDeclarations(cdr(tree))), NULL));;

  };

}


list ansi3Functions(list tree) {
  
if (globalTrace)
    printf("ansi3Functions at q/ansi3.qon:297 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Functions", "297" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:299");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:300");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:302");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(ansi3Function(car(tree))), cons(id(ansi3Functions(cdr(tree))), NULL));;

  };

}


list ansi3Includes(list nodes) {
  
if (globalTrace)
    printf("ansi3Includes at q/ansi3.qon:306 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Includes", "306" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:308");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(boxString("\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\n#include <unistd.h>\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\nbool releaseMode = false;\n\n"), cons(boxString("void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n"), NULL));;

}


list ansi3TypeDecl(list l) {
  
if (globalTrace)
    printf("ansi3TypeDecl at q/ansi3.qon:312 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3TypeDecl", "312" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:314");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:316");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(boxString(stringIndent(1))), cons(id(second(l)), cons(boxString(" "), cons(id(ansi3TypeMap(listLast(l))), cons(boxString(" "), cons(id(first(l)), cons(boxString(";\n"), NULL)))))));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:325");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(boxString(stringIndent(1))), cons(id(ansi3TypeMap(listLast(l))), cons(boxString(" "), cons(id(car(l)), cons(boxString(";\n"), NULL)))));;

  };

}


list ansi3StructComponents(list node) {
  
if (globalTrace)
    printf("ansi3StructComponents at q/ansi3.qon:332 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3StructComponents", "332" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:334");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:335");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:337");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(ansi3TypeDecl(car(node))), cons(id(ansi3StructComponents(cdr(node))), NULL));;

  };

}


list ansi3Struct(list node) {
  
if (globalTrace)
    printf("ansi3Struct at q/ansi3.qon:341 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Struct", "341" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:343");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return ansi3StructComponents(cdr(node));;

}


box ansi3TypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("ansi3TypeMap at q/ansi3.qon:345 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3TypeMap", "345" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:347");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:351");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:352");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:353");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


box ansi3FuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("ansi3FuncMap at q/ansi3.qon:355 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3FuncMap", "355" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:357");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:359");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), NULL)))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:380");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:381");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cdr(assoc(stringify(aSym), symMap));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:382");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return aSym;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:383");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


list ansi3Type(list node) {
  
if (globalTrace)
    printf("ansi3Type at q/ansi3.qon:385 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Type", "385" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:387");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(second(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:389");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString("\ntypedef struct "), cons(id(first(node)), cons(boxString(" {\n"), cons(id(ansi3Struct(second(node))), cons(boxString("\n} "), cons(id(first(node)), cons(boxString(";\n"), NULL)))))));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:398");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString("typedef "), cons(id(ansi3TypeDecl(node)), NULL));;

  };

}


list ansi3Types(list nodes) {
  
if (globalTrace)
    printf("ansi3Types at q/ansi3.qon:402 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Types", "402" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:404");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:405");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:407");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(ansi3Type(car(nodes))), cons(id(ansi3Types(cdr(nodes))), NULL));;

  };

}


list ansi3LoadProgram(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    printf("ansi3LoadProgram at q/ansi3.qon:411 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3LoadProgram", "411" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:413");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:414");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = buildProg(cons(boxString("q/shims/ansi3.qon"), getIncludes(tree)), getTypes(tree), getFunctions(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:415");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree, NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:416");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:417");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:418");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:419");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return tree;;

}


list ansi3ProgramTree(list tree) {
  
if (globalTrace)
    printf("ansi3ProgramTree at q/ansi3.qon:421 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3ProgramTree", "421" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:423");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(ansi3Includes(cdr(first(tree)))), cons(id(ansi3Types(cdr(second(tree)))), cons(boxString("Box* globalStackTrace = NULL;\n"), cons(boxString("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n"), cons(id(ansi3ForwardDeclarations(cdr(third(tree)))), cons(boxString("\n\n//End forward declarations\n\n"), cons(id(ansi3Functions(cdr(third(tree)))), cons(boxString("\n"), NULL))))))));;

}


char* ansi3Program(list tree) {
  
if (globalTrace)
    printf("ansi3Program at q/ansi3.qon:433 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Program", "433" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:435");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return ListToString(flatten(ansi3ProgramTree(tree)), 0, true, false);;

}


char* ansi3CompileString(char* filename) {
  
if (globalTrace)
    printf("ansi3CompileString at q/ansi3.qon:437 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3CompileString", "437" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:439");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return ansi3Program(ansi3LoadProgram(filename));;

}


void ansi3Compile(char* filename) {
  
if (globalTrace)
    printf("ansi3Compile at q/ansi3.qon:441 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Compile", "441" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:443");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printStringTree(ansi3ProgramTree(ansi3LoadProgram(filename)));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Done printing program\n");

}


char* dollar() {
  
if (globalTrace)
    printf("dollar at q/perl.qon:4 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "dollar", "4" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:6");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return character(36);;

}


char* atsymbol() {
  
if (globalTrace)
    printf("atsymbol at q/perl.qon:8 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "atsymbol", "8" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:10");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return character(64);;

}


char* singleQuote() {
  
if (globalTrace)
    printf("singleQuote at q/perl.qon:12 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "singleQuote", "12" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:14");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return "'";;

}


char* escapedSingleQuote() {
  
if (globalTrace)
    printf("escapedSingleQuote at q/perl.qon:16 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "escapedSingleQuote", "16" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:18");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return "\\'";;

}


char* backslash() {
  
if (globalTrace)
    printf("backslash at q/perl.qon:20 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "backslash", "20" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:22");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return character(92);;

}


char* escapedDollar() {
  
if (globalTrace)
    printf("escapedDollar at q/perl.qon:24 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "escapedDollar", "24" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:26");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return StringListJoin(cons(boxString(backslash()), cons(boxString(dollar()), NULL)), "");;

}


char* escapedAtSign() {
  
if (globalTrace)
    printf("escapedAtSign at q/perl.qon:28 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "escapedAtSign", "28" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:30");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return StringListJoin(cons(boxString(backslash()), cons(boxString(atsymbol()), NULL)), "");;

}


char* escapeSingleQuotes(char* s) {
  
if (globalTrace)
    printf("escapeSingleQuotes at q/perl.qon:32 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "escapeSingleQuotes", "32" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:34");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return stringReplace(singleQuote(), escapedSingleQuote(), s);;

}


char* escapePerlString(char* s) {
  
if (globalTrace)
    printf("escapePerlString at q/perl.qon:36 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "escapePerlString", "36" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:38");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return stringReplace(atsymbol(), escapedAtSign(), stringReplace(dollar(), escapedDollar(), s));;

}


list getGlobalVariables() {
  
if (globalTrace)
    printf("getGlobalVariables at q/perl.qon:41 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "getGlobalVariables", "41" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:43");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(boxSymbol("stderr")), cons(id(boxSymbol("true")), cons(id(boxSymbol("false")), cons(id(boxSymbol("releaseMode")), cons(id(boxSymbol("caller")), cons(id(boxSymbol("globalTrace")), cons(id(boxSymbol("globalStepTrace")), cons(id(boxSymbol("globalStackTrace")), cons(id(boxSymbol("globalArgsCount")), cons(id(boxSymbol("globalArgs")), cons(id(boxSymbol("quonGlobalArgs")), NULL)))))))))));;

}


list collectVariables(list args, list decls) {
  list variables = NULL;
box decl = NULL;

if (globalTrace)
    printf("collectVariables at q/perl.qon:45 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "collectVariables", "45" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:47");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  variables = collectVariablesFromArgs(args);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:48");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  variables = appendVariables(variables, collectVariablesFromDecls(decls));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:49");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  variables = appendVariables(variables, getGlobalVariables());

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:50");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return variables;;

}


list perlGlobalVariables() {
  
if (globalTrace)
    printf("perlGlobalVariables at q/perl.qon:52 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlGlobalVariables", "52" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:54");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(boxString("our "), cons(boxString(dollar()), cons(boxString("globalArgsCount;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("globalArgs;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("releaseMode;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("globalTrace;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("globalStepTrace;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("globalStackTrace;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("caller;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("false = 0;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("true = 1;\n"), cons(boxString("my "), cons(boxString(dollar()), cons(boxString("stderr = \\*STDERR;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("quonGlobalArgs;\n"), NULL)))))))))))))))))))))))))))))))));;

}


list perlMainEntry() {
  
if (globalTrace)
    printf("perlMainEntry at q/perl.qon:67 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlMainEntry", "67" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:69");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(boxString("\n# Main entry point\n"), cons(boxString(dollar()), cons(boxString("globalArgsCount = scalar("), cons(boxString(atsymbol()), cons(boxString("ARGV) + 1;\n"), cons(boxString(dollar()), cons(boxString("globalArgs = \\"), cons(boxString(atsymbol()), cons(boxString("ARGV;\n"), cons(boxString("unshift "), cons(boxString(atsymbol()), cons(boxString(dollar()), cons(boxString("globalArgs, 'fixmeprogname' ;\n"), cons(boxString(dollar()), cons(boxString("quonGlobalArgs = [];\n"), cons(boxString("for my "), cons(boxString(dollar()), cons(boxString("arg ("), cons(boxString(atsymbol()), cons(boxString(dollar()), cons(boxString("globalArgs) {\n"), cons(boxString("    push "), cons(boxString(atsymbol()), cons(boxString(dollar()), cons(boxString("quonGlobalArgs, {car => "), cons(boxString(dollar()), cons(boxString("arg, cdr => undef};\n"), cons(boxString("}\n"), cons(boxString("for (my "), cons(boxString(dollar()), cons(boxString("i = scalar("), cons(boxString(atsymbol()), cons(boxString(dollar()), cons(boxString("quonGlobalArgs) - 1; "), cons(boxString(dollar()), cons(boxString("i >= 0; "), cons(boxString(dollar()), cons(boxString("i--) {\n"), cons(boxString("    "), cons(boxString(dollar()), cons(boxString("quonGlobalArgs->["), cons(boxString(dollar()), cons(boxString("i]->{cdr} = "), cons(boxString(dollar()), cons(boxString("quonGlobalArgs->["), cons(boxString(dollar()), cons(boxString("i + 1];\n"), cons(boxString("}\n"), cons(boxString("*stderr = *STDERR;\n"), cons(boxString("sub fprintf { my "), cons(boxString(dollar()), cons(boxString("f = shift; printf "), cons(boxString(dollar()), cons(boxString("f "), cons(boxString(atsymbol()), cons(boxString("_ }\n"), cons(boxString("start();\n"), NULL)))))))))))))))))))))))))))))))))))))))))))))))))))))))));;

}


list collectVariablesFromArgs(list args) {
  list variables = NULL;

if (globalTrace)
    printf("collectVariablesFromArgs at q/perl.qon:85 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "collectVariablesFromArgs", "85" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:87");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(args)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:88");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return variables;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:90");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(stringify(first(args)), "list")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:92");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      variables = cons(second(args), variables);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:93");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return appendVariables(variables, collectVariablesFromArgs(cddr(args)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:95");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      variables = cons(second(args), variables);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:96");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return appendVariables(variables, collectVariablesFromArgs(cddr(args)));;

    };

  };

}


list collectVariablesFromDecls(list decls) {
  list variables = NULL;
box decl = NULL;

if (globalTrace)
    printf("collectVariablesFromDecls at q/perl.qon:98 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "collectVariablesFromDecls", "98" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:100");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:101");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return variables;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:103");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:104");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    variables = cons(second(decl), variables);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:105");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return appendVariables(variables, collectVariablesFromDecls(cdr(decls)));;

  };

}


list appendVariables(list vars1, list vars2) {
  
if (globalTrace)
    printf("appendVariables at q/perl.qon:107 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "appendVariables", "107" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:109");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(vars2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:111");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return vars1;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:113");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    vars1 = cons(car(vars2), vars1);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:114");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return appendVariables(vars1, cdr(vars2));;

  };

}


list perlFunctionArgs(list tree) {
  
if (globalTrace)
    printf("perlFunctionArgs at q/perl.qon:116 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlFunctionArgs", "116" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:118");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:119");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:121");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:122");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(id(boxString(dollar())), cons(id(second(tree)), NULL));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:123");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(id(boxString(dollar())), cons(id(second(tree)), cons(boxString(", "), cons(id(perlFunctionArgs(cddr(tree))), NULL))));;

    };

  };

}


list perlAtom(box tree, list variables) {
  
if (globalTrace)
    printf("perlAtom at q/perl.qon:129 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlAtom", "129" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:131");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("string", boxType(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:132");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString("\""), cons(id(boxString(escapePerlString(stringify(tree)))), cons(boxString("\""), NULL)));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:133");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(perlFuncMap(tree, variables)), NULL);;

  };

}


list perlExpression(list tree, int indent, list variables) {
  list thing = NULL;

if (globalTrace)
    printf("perlExpression at q/perl.qon:135 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlExpression", "135" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:137");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( notBool(isList(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:138");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return perlAtom(tree, variables);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:140");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equal(1, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:142");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("return"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:143");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(perlFuncMap(car(tree), variables)), NULL);;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:144");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(perlFuncMap(car(tree), variables)), cons(boxString("()"), NULL));;

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:146");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      thing = first(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:147");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxSymbol("get-struct"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:149");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(boxString(dollar())), cons(id(second(tree)), cons(boxString("->{"), cons(id(third(tree)), cons(boxString("}"), NULL)))));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:156");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxSymbol("new"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:157");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return cons(boxString("{}"), NULL);;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:159");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("passthrough"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:160");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return cons(id(second(tree)), NULL);;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:162");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("binop"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:164");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return cons(boxString("("), cons(id(perlExpression(third(tree), indent, variables)), cons(boxString(" "), cons(id(second(tree)), cons(boxString(" "), cons(id(perlExpression(fourth(tree), indent, variables)), cons(boxString(")"), NULL)))))));;

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:173");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return cons(id(perlFuncMap(car(tree), variables)), cons(boxString("("), cons(id(perlRecurList(cdr(tree), indent, variables)), cons(boxString(")"), NULL))));;

            };

          };

        };

      };

    };

  };

}


list perlRecurList(list expr, int indent, list variables) {
  
if (globalTrace)
    printf("perlRecurList at q/perl.qon:179 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlRecurList", "179" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:181");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:182");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:184");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:185");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return perlExpression(car(expr), indent, variables);;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:186");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(id(perlExpression(car(expr), indent, variables)), cons(boxString(", "), cons(id(perlRecurList(cdr(expr), indent, variables)), NULL)));;

    };

  };

}


list perlSet(list node, int indent, list variables) {
  
if (globalTrace)
    printf("perlSet at q/perl.qon:191 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlSet", "191" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:193");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(id(perlFuncMap(second(node), variables)), cons(boxString(" = "), cons(id(perlExpression(third(node), indent, variables)), NULL))));;

}


list perlSetStruct(list node, int indent, list variables) {
  
if (globalTrace)
    printf("perlSetStruct at q/perl.qon:199 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlSetStruct", "199" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:201");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(id(perlFuncMap(second(node), variables)), cons(boxString("->{"), cons(id(third(node)), cons(boxString("} = "), cons(id(perlExpression(fourth(node), indent, variables)), NULL))))));;

}


list perlReturn(list node, int indent, list variables) {
  
if (globalTrace)
    printf("perlReturn at q/perl.qon:209 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlReturn", "209" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:211");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(node), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:212");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(listNewLine(indent)), cons(boxString("return "), cons(id(perlExpression(cadr(node), indent, variables)), NULL)));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:216");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(listNewLine(indent)), cons(boxString("return"), NULL));;

  };

}


list perlIf(list node, int indent, list variables) {
  
if (globalTrace)
    printf("perlIf at q/perl.qon:218 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlIf", "218" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:220");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(boxString("if ( "), cons(id(perlExpression(second(node), 0, variables)), cons(boxString(" ) {"), cons(id(perlBody(cdr(third(node)), add1(indent), variables)), cons(id(listNewLine(indent)), cons(boxString("} else {"), cons(id(perlBody(cdr(fourth(node)), add1(indent), variables)), cons(id(listNewLine(indent)), cons(boxString("}"), NULL))))))))));;

}


list perlStatement(list node, int indent, list variables) {
  
if (globalTrace)
    printf("perlStatement at q/perl.qon:232 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlStatement", "232" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:234");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("set"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:235");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(perlSet(node, indent, variables)), cons(boxString(";\n"), NULL));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:237");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("set-struct"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:238");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(id(perlSetStruct(node, indent, variables)), cons(boxString(";\n"), NULL));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:240");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:241");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(perlIf(node, indent, variables)), cons(boxString(";\n"), NULL));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:243");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("return"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:244");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return cons(id(perlReturn(node, indent, variables)), cons(boxString(";\n"), NULL));;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:246");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return cons(id(listNewLine(indent)), cons(id(perlExpression(node, indent, variables)), cons(boxString(";\n"), NULL)));;

        };

      };

    };

  };

}


list perlBody(list tree, int indent, list variables) {
  list code = NULL;

if (globalTrace)
    printf("perlBody at q/perl.qon:251 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlBody", "251" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:253");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:254");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:256");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    code = car(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:257");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(perlStatement(code, indent, variables)), cons(id(perlBody(cdr(tree), indent, variables)), NULL));;

  };

}


list perlGetStruct(list node, int indent) {
  
if (globalTrace)
    printf("perlGetStruct at q/perl.qon:261 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlGetStruct", "261" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:263");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(id(boxString(dollar())), cons(id(first(node)), cons(boxString("->{"), cons(id(second(node)), cons(boxString("}"), NULL))))));;

}


list perlDeclarations(list decls, int indent, list variables) {
  box decl = NULL;

if (globalTrace)
    printf("perlDeclarations at q/perl.qon:271 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlDeclarations", "271" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:273");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:274");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:276");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:277");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString("my "), cons(id(boxString(dollar())), cons(id(second(decl)), cons(boxString(" = "), cons(id(perlExpression(third(decl), indent, variables)), cons(boxString(";\n"), cons(id(perlDeclarations(cdr(decls), indent, variables)), NULL)))))));;

  };

}


list perlFunction(list node) {
  box name = NULL;
list variables = NULL;
list args = NULL;
list decls = NULL;

if (globalTrace)
    printf("perlFunction at q/perl.qon:286 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlFunction", "286" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:288");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = second(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:289");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:290");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:292");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    args = third(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:293");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decls = cdr(fourth(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:294");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    variables = collectVariables(args, decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:295");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString("\n\n# Function "), cons(id(name), cons(boxString(" from line "), cons(id(getTag(name, boxString("line"))), cons(id(listNewLine(0)), cons(id(listNewLine(0)), cons(boxString("sub "), cons(id(perlFuncMap(second(node), NULL)), cons(boxString(" {"), cons(id(listNewLine(1)), cons(boxString("my ("), cons(id(perlFunctionArgs(args)), cons(boxString(") = "), cons(id(boxString(atsymbol())), cons(boxString("_;"), cons(id(listNewLine(1)), cons(id(perlDeclarations(decls, 1, variables)), cons(id(perlBody(cdr(fifth(node)), 1, variables)), cons(boxString("\n}\n"), NULL)))))))))))))))))));;

  };

}


list perlForwardDeclaration(list node) {
  
if (globalTrace)
    printf("perlForwardDeclaration at q/perl.qon:316 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlForwardDeclaration", "316" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:318");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:319");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:321");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString("sub "), cons(id(perlFuncMap(second(node), NULL)), cons(boxString(";\n"), NULL)));;

  };

}


list perlForwardDeclarations(list tree) {
  
if (globalTrace)
    printf("perlForwardDeclarations at q/perl.qon:323 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlForwardDeclarations", "323" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:325");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:326");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:328");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(perlForwardDeclaration(car(tree))), cons(id(perlForwardDeclarations(cdr(tree))), NULL));;

  };

}


list perlFunctions(list tree) {
  
if (globalTrace)
    printf("perlFunctions at q/perl.qon:332 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlFunctions", "332" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:334");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:335");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:337");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(perlFunction(car(tree))), cons(id(perlFunctions(cdr(tree))), NULL));;

  };

}


list perlIncludes(list nodes) {
  
if (globalTrace)
    printf("perlIncludes at q/perl.qon:341 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlIncludes", "341" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:343");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(boxString("use strict;\n"), cons(boxString("use warnings;\n"), cons(boxString("use v5.10;\n\n"), cons(boxString("no warnings 'recursion';\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("^M = 10_000;\n"), NULL)))))));;

}


list perlTypes(list nodes) {
  
if (globalTrace)
    printf("perlTypes at q/perl.qon:350 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlTypes", "350" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:352");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return emptyList();;

}


box perlTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("perlTypeMap at q/perl.qon:354 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlTypeMap", "354" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:356");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("array"), alistCons(boxSymbol("string"), boxSymbol("string"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:359");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:360");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:361");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


box perlFuncMap(box aSym, list variables) {
  list symMap = NULL;

if (globalTrace)
    printf("perlFuncMap at q/perl.qon:363 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlFuncMap", "363" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:365");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:368");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(aSym, variables)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:369");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return boxSymbol(stringConcatenate(dollar(), stringify(aSym)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:371");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      symMap = alistCons(boxSymbol("sub"), boxSymbol("subtract"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("substr"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("length"), alistCons(boxSymbol("say"), boxSymbol("say_"), alistCons(boxSymbol("nil"), boxSymbol("undef"), NULL)))))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:381");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:382");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cdr(assoc(stringify(aSym), symMap));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:383");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return aSym;;

      };

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:384");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


list perlLoadProgram(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    printf("perlLoadProgram at q/perl.qon:386 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlLoadProgram", "386" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:388");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:389");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = insertInclude(tree, "q/shims/perl.qon");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:390");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree, NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:391");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:392");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:393");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:394");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return tree;;

}


list perlProgramTree(list tree) {
  
if (globalTrace)
    printf("perlProgramTree at q/perl.qon:396 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlProgramTree", "396" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:398");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(perlIncludes(cdr(first(tree)))), cons(id(perlTypes(cdr(second(tree)))), cons(id(perlGlobalVariables()), cons(boxString("\n# Forward declarations\n"), cons(id(perlForwardDeclarations(cdr(third(tree)))), cons(boxString("\n# End forward declarations\n"), cons(id(perlFunctions(cdr(third(tree)))), cons(id(perlMainEntry()), cons(boxString("\n"), NULL)))))))));;

}


char* perlProgram(list tree) {
  
if (globalTrace)
    printf("perlProgram at q/perl.qon:409 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlProgram", "409" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:411");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return ListToString(flatten(perlProgramTree(tree)), 0, true, false);;

}


char* perlCompileString(char* filename) {
  
if (globalTrace)
    printf("perlCompileString at q/perl.qon:413 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlCompileString", "413" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:415");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return perlProgram(perlLoadProgram(filename));;

}


void perlCompile(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    printf("perlCompile at q/perl.qon:417 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlCompile", "417" );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Scanning file...%s\n", filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:420");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Adding shim functions\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:422");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = insertInclude(tree, "q/shims/perl.qon");

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Loading includes\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:424");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree, NULL);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Walking tree\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:426");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Replacing q log\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:428");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:429");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Printing program\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:431");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printStringTree(perlProgramTree(tree));

}


list readSexpr(char* aStr, char* filename) {
  list tokens = NULL;
list as = NULL;
list tree = NULL;

if (globalTrace)
    printf("readSexpr at q/newparser.qon:4 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "readSexpr", "4" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:6");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tokens = emptyList();

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:7");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tokens = filterTokens(filterVoid(scan(aStr, 0, 1, 0, 0, filename)));

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:8");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  parserValidateParens(tokens, NULL, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:9");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  as = sexprTree(tokens);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:10");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  parserValidateRoot(as, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:11");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = car(as);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:12");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  parserValidateProgram(tree, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:13");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return tree;;

}


void parserPanicAt(char* filename, box token, char* message) {
  
if (globalTrace)
    printf("parserPanicAt at q/newparser.qon:15 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserPanicAt", "15" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:17");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(token)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:19");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Parse error in %s: %s\n", filename, message);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:21");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Parse error in %s:%s:%s: %s\n", stringify(getTagFail(token, boxString("filename"), boxString(filename))), stringify(getTagFail(token, boxString("line"), boxString("?"))), stringify(getTagFail(token, boxString("column"), boxString("?"))), message);

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:27");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  exit(1);

}


void parserPanicAtNode(char* filename, box node, char* message) {
  
if (globalTrace)
    printf("parserPanicAtNode at q/newparser.qon:29 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserPanicAtNode", "29" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:31");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:32");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAt(filename, NULL, message);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:34");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:36");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:37");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        parserPanicAt(filename, NULL, message);

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:38");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        parserPanicAt(filename, car(node), message);

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:39");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      parserPanicAt(filename, node, message);

    };

  };

}


bool parserSymbolIs(box b, char* name) {
  
if (globalTrace)
    printf("parserSymbolIs at q/newparser.qon:41 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserSymbolIs", "41" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:43");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:43");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:44");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:44");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:45");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:46");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return equalString(name, stringify(b));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:47");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  };

}


bool parserListStartsWith(box node, char* name) {
  
if (globalTrace)
    printf("parserListStartsWith at q/newparser.qon:49 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserListStartsWith", "49" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:51");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:51");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:52");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:54");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:55");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return false;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:56");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return parserSymbolIs(car(node), name);;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:57");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  };

}


void parserValidateParens(list tokens, list openStack, char* filename) {
  box token = NULL;

if (globalTrace)
    printf("parserValidateParens at q/newparser.qon:59 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserValidateParens", "59" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:61");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tokens)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:63");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isEmpty(openStack)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:64");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:65");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      parserPanicAt(filename, car(openStack), "missing ')'");

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:67");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token = car(tokens);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:68");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isOpenBrace(token)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:69");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      parserValidateParens(cdr(tokens), cons(token, openStack), filename);

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:71");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isCloseBrace(token)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:73");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( isEmpty(openStack)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:74");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          parserPanicAt(filename, token, "unexpected ')'");

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:75");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          parserValidateParens(cdr(tokens), cdr(openStack), filename);

        };

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:76");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        parserValidateParens(cdr(tokens), openStack, filename);

      };

    };

  };

}


void parserValidateRoot(list roots, char* filename) {
  
if (globalTrace)
    printf("parserValidateRoot at q/newparser.qon:78 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserValidateRoot", "78" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:80");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(listLength(roots), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:81");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:83");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isEmpty(roots)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:84");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      parserPanicAt(filename, NULL, "expected one top-level program form");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:85");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      parserPanicAtNode(filename, second(roots), "extra top-level form after program");

    };

  };

}


void parserValidateSection(box section, char* name, char* filename) {
  
if (globalTrace)
    printf("parserValidateSection at q/newparser.qon:87 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserValidateSection", "87" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:89");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(section)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:90");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAt(filename, NULL, "missing program section");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:92");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(section)) {
  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:94");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, section, "program section must be a list");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:95");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(section, name)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:96");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:97");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, section, stringConcatenate("expected program section ", name));

  };

}


bool parserIsFunctionDefinition(box node) {
  
if (globalTrace)
    printf("parserIsFunctionDefinition at q/newparser.qon:99 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserIsFunctionDefinition", "99" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:101");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:101");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:102");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(node)) {
  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:102");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:103");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(listLength(node), 5)) {
  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:103");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:104");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:104");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:105");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(second(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:105");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:106");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(third(node))) {
  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:106");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:107");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(fourth(node), "declare")) {
  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:107");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:108");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(fifth(node), "body")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:108");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:108");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  };

}


void parserRejectFunctionDefinitions(box node, char* filename) {
  
if (globalTrace)
    printf("parserRejectFunctionDefinitions at q/newparser.qon:110 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserRejectFunctionDefinitions", "110" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:112");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:113");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:115");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserIsFunctionDefinition(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:116");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, node, "function definition is not allowed here");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:118");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:119");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserRejectFunctionDefinitionsList(node, filename);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:120");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  };

}


void parserRejectFunctionDefinitionsList(list nodes, char* filename) {
  
if (globalTrace)
    printf("parserRejectFunctionDefinitionsList at q/newparser.qon:122 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserRejectFunctionDefinitionsList", "122" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:124");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:125");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:127");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserRejectFunctionDefinitions(car(nodes), filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:128");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserRejectFunctionDefinitionsList(cdr(nodes), filename);

  };

}


void parserValidateProgram(box program, char* filename) {
  
if (globalTrace)
    printf("parserValidateProgram at q/newparser.qon:130 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserValidateProgram", "130" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:132");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:133");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAt(filename, NULL, "empty program");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:135");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(program)) {
  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:137");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, program, "program must be a list");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:138");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(listLength(program), 3)) {
  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:141");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equal(listLength(program), 4)) {
    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:143");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      parserPanicAtNode(filename, program, "program must contain includes, types, and functions sections");

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:144");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  parserValidateSection(first(program), "includes", filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:145");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  parserValidateSection(second(program), "types", filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:146");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  parserValidateSection(third(program), "functions", filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:147");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  parserRejectFunctionDefinitions(cdr(first(program)), filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:148");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  parserRejectFunctionDefinitions(cdr(second(program)), filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:149");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(listLength(program), 4)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:151");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserValidateSection(fourth(program), "globals", filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:152");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserRejectFunctionDefinitions(cdr(fourth(program)), filename);

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:154");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  parserValidateFunctions(cdr(third(program)), filename);

}


void parserValidateFunctions(list functions, char* filename) {
  box fn = NULL;

if (globalTrace)
    printf("parserValidateFunctions at q/newparser.qon:156 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserValidateFunctions", "156" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:158");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(functions)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:159");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:161");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fn = car(functions);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:162");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( parserIsFunctionDefinition(fn)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:163");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      parserValidateFunction(fn, filename);

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:164");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      parserPanicAtNode(filename, fn, "invalid function definition");

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:165");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserValidateFunctions(cdr(functions), filename);

  };

}


void parserValidateFunction(list fn, char* filename) {
  
if (globalTrace)
    printf("parserValidateFunction at q/newparser.qon:167 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserValidateFunction", "167" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:169");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  parserRejectFunctionDefinitions(third(fn), filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:170");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  parserRejectFunctionDefinitions(cdr(fourth(fn)), filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:171");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  parserValidateBody(cdr(fifth(fn)), filename);

}


void parserValidateBody(list forms, char* filename) {
  
if (globalTrace)
    printf("parserValidateBody at q/newparser.qon:173 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserValidateBody", "173" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:175");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(forms)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:176");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:178");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserValidateStatement(car(forms), filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:179");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserValidateBody(cdr(forms), filename);

  };

}


void parserValidateStatement(box stmt, char* filename) {
  
if (globalTrace)
    printf("parserValidateStatement at q/newparser.qon:181 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserValidateStatement", "181" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:183");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(stmt)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:184");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:186");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(stmt)) {
  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:188");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, stmt, "statement must be a list");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:189");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(stmt)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:190");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:192");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserIsFunctionDefinition(stmt)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:193");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, stmt, "function definition nested inside body");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:195");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(stmt, "if")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:196");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserValidateIf(stmt, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:196");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:198");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(stmt, "then")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:199");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, stmt, "then branch outside if");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:201");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(stmt, "else")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:202");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, stmt, "else branch outside if");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:204");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(stmt, "declare")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:205");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, stmt, "declare block outside function header");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:207");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(stmt, "body")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:208");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, stmt, "body block nested inside body");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:210");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(stmt, "functions")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:211");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, stmt, "functions section nested inside body");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:213");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(stmt, "types")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:214");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, stmt, "types section nested inside body");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:216");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(stmt, "includes")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:217");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, stmt, "includes section nested inside body");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:219");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(stmt, "return")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:220");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserValidateReturn(stmt, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:220");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:222");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(stmt, "set")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:223");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserValidateSet(stmt, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:223");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:225");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(stmt, "set-struct")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:226");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserValidateSetStruct(stmt, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:226");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:228");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  parserValidateExpression(stmt, filename);

}


void parserValidateReturn(list stmt, char* filename) {
  
if (globalTrace)
    printf("parserValidateReturn at q/newparser.qon:230 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserValidateReturn", "230" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:232");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(stmt), 2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:233");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, stmt, "return takes zero or one value");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:235");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(listLength(stmt), 2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:236");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserValidateExpression(second(stmt), filename);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:237");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  };

}


void parserValidateSet(list stmt, char* filename) {
  
if (globalTrace)
    printf("parserValidateSet at q/newparser.qon:239 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserValidateSet", "239" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:241");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(listLength(stmt), 3)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:243");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserValidateExpression(second(stmt), filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:244");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserValidateExpression(third(stmt), filename);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:245");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, stmt, "set takes a target and value");

  };

}


void parserValidateSetStruct(list stmt, char* filename) {
  
if (globalTrace)
    printf("parserValidateSetStruct at q/newparser.qon:247 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserValidateSetStruct", "247" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:249");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(listLength(stmt), 4)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:251");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserValidateExpression(second(stmt), filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:252");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserValidateExpression(third(stmt), filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:253");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserValidateExpression(fourth(stmt), filename);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:254");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, stmt, "set-struct takes a target, field, and value");

  };

}


void parserValidateIf(list stmt, char* filename) {
  
if (globalTrace)
    printf("parserValidateIf at q/newparser.qon:256 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserValidateIf", "256" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:258");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(listLength(stmt), 4)) {
  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:260");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, stmt, "if must contain condition, then, and else");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:261");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  parserValidateExpression(second(stmt), filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:262");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  parserValidateBranch(third(stmt), "then", filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:263");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  parserValidateBranch(fourth(stmt), "else", filename);

}


void parserValidateBranch(box branch, char* name, char* filename) {
  
if (globalTrace)
    printf("parserValidateBranch at q/newparser.qon:265 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserValidateBranch", "265" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:267");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(branch, name)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:268");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserValidateBody(cdr(branch), filename);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:269");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, branch, stringConcatenate("expected ", name));

  };

}


void parserValidateExpression(box expr, char* filename) {
  
if (globalTrace)
    printf("parserValidateExpression at q/newparser.qon:271 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserValidateExpression", "271" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:273");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:274");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:276");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(expr)) {
  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:278");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:279");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:280");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:282");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserIsFunctionDefinition(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:283");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, expr, "function definition nested inside expression");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:285");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(expr, "if")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:286");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserValidateIf(expr, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:286");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:288");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(expr, "then")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:289");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, expr, "then branch outside if");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:291");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(expr, "else")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:292");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, expr, "else branch outside if");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:294");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(expr, "declare")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:295");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, expr, "declare block inside expression");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:297");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(expr, "body")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:298");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, expr, "body block inside expression");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:300");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(expr, "functions")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:301");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, expr, "functions section inside expression");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:303");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(expr, "types")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:304");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, expr, "types section inside expression");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:306");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( parserListStartsWith(expr, "includes")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:307");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserPanicAtNode(filename, expr, "includes section inside expression");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:309");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  parserValidateExpressionList(expr, filename);

}


void parserValidateExpressionList(list exprs, char* filename) {
  
if (globalTrace)
    printf("parserValidateExpressionList at q/newparser.qon:311 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "parserValidateExpressionList", "311" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:313");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(exprs)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:314");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:316");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserValidateExpression(car(exprs), filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:317");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    parserValidateExpressionList(cdr(exprs), filename);

  };

}


list sexprTree(list l) {
  box b = NULL;

if (globalTrace)
    printf("sexprTree at q/newparser.qon:319 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "sexprTree", "319" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:321");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:322");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:324");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    b = car(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:325");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isOpenBrace(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:327");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(sexprTree(cdr(l)), sexprTree(skipList(cdr(l))));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:329");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isCloseBrace(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:330");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return emptyList();;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:332");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return setTag(boxString("line"), getTagFail(b, boxString("line"), boxInt(-1)), cons(b, sexprTree(cdr(l))));;

      };

    };

  };

}


list loadQuon(char* filename) {
  box programBox = NULL;
char* programStr = "";
list tree = NULL;

if (globalTrace)
    printf("loadQuon at q/newparser.qon:337 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "loadQuon", "337" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:340");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programBox = read_file(filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:341");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(programBox)) {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fprintf(stderr, "Could not read file: ");

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fprintf(stderr, filename);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fprintf(stderr, "\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:346");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    exit(1);

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:348");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = unBoxString(programBox);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:349");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:351");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return tree;;

}


list getIncludes(list program) {
  
if (globalTrace)
    printf("getIncludes at q/newparser.qon:354 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "getIncludes", "354" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:356");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cdr(first(program));;

}


list getTypes(list program) {
  
if (globalTrace)
    printf("getTypes at q/newparser.qon:358 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "getTypes", "358" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:360");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cdr(second(program));;

}


list getFunctions(list program) {
  
if (globalTrace)
    printf("getFunctions at q/newparser.qon:362 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "getFunctions", "362" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:364");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cdr(third(program));;

}


list insertInclude(list tree, char* extra) {
  list newProg = NULL;
list includes = NULL;
list types = NULL;
list functions = NULL;
list boxedExtra = NULL;
list newIncludes = NULL;

if (globalTrace)
    printf("insertInclude at q/newparser.qon:366 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "insertInclude", "366" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:375");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:377");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("insertInlcude: tree is nil");

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:378");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:381");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    includes = getIncludes(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:383");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    types = getTypes(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:385");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    functions = getFunctions(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:387");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    boxedExtra = boxSymbol(extra);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:388");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newIncludes = cons(boxedExtra, includes);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:390");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newProg = buildProg(newIncludes, types, functions);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:392");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return newProg;;

  };

}


bool stringInList(char* item, list l) {
  
if (globalTrace)
    printf("stringInList at q/newparser.qon:395 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "stringInList", "395" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:397");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:398");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:400");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(item, stringify(car(l)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:401");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:402");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return stringInList(item, cdr(l));;

    };

  };

}


list appendMissingIncludes(list candidates, list pending, list seen) {
  box candidate = NULL;
char* candidateFile = "";

if (globalTrace)
    printf("appendMissingIncludes at q/newparser.qon:404 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "appendMissingIncludes", "404" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:406");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(candidates)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:407");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return pending;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:409");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    candidate = car(candidates);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:410");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    candidateFile = stringify(candidate);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:411");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( orBool(stringInList(candidateFile, seen), stringInList(candidateFile, pending))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:412");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return appendMissingIncludes(cdr(candidates), pending, seen);;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:413");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(candidate, appendMissingIncludes(cdr(candidates), pending, seen));;

    };

  };

}


list loadIncludes(list tree, list seen) {
  list newProg = NULL;
char* includeFile = "";
list functionsCombined = NULL;
list typesCombined = NULL;
list includeTree = NULL;
list pendingIncludes = NULL;
list nextIncludes = NULL;
list nextSeen = NULL;
box contentsBox = NULL;
char* contents = "";

if (globalTrace)
    printf("loadIncludes at q/newparser.qon:415 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "loadIncludes", "415" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:427");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(getIncludes(tree)), 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:429");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    includeFile = stringify(first(getIncludes(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:430");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( stringInList(includeFile, seen)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:432");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      newProg = buildProg(cdr(getIncludes(tree)), getTypes(tree), getFunctions(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:433");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return loadIncludes(newProg, seen);;

    } else {
    };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:435");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nextSeen = cons(boxString(includeFile), seen);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:436");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    contentsBox = read_file(includeFile);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:437");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(contentsBox)) {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      fprintf(stderr, "Could not read include file: ");

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      fprintf(stderr, includeFile);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      fprintf(stderr, "\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:442");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      exit(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:443");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return NULL;;

    } else {
    };

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:445");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    contents = unBoxString(contentsBox);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:446");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    includeTree = readSexpr(contents, includeFile);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:447");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(includeTree)) {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      fprintf(stderr, "Could not parse include file: ");

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      fprintf(stderr, includeFile);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      fprintf(stderr, "\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:452");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      exit(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:453");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return NULL;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:455");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      functionsCombined = concatLists(getFunctions(includeTree), getFunctions(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:456");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      typesCombined = concatLists(getTypes(includeTree), getTypes(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:457");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      pendingIncludes = cdr(getIncludes(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:458");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      nextIncludes = appendMissingIncludes(getIncludes(includeTree), pendingIncludes, nextSeen);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:459");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      newProg = buildProg(nextIncludes, typesCombined, functionsCombined);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:460");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return loadIncludes(newProg, nextSeen);;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:462");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return tree;;

  };

}


list buildProg(list includes, list types, list functions) {
  list program = NULL;

if (globalTrace)
    printf("buildProg at q/newparser.qon:464 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "buildProg", "464" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:466");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  includes = cons(boxSymbol("includes"), includes);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:467");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  types = cons(boxSymbol("types"), types);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:468");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  functions = cons(boxSymbol("functions"), functions);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:469");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = cons(includes, cons(types, cons(functions, NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:472");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return program;;

}


box car(list l) {
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Cannot call car on empty list!\n");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Cannot call car on empty list!\n");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return NULL;;

  } else {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    assertType("list", l, 18, "q/lists.qon");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(l->car)) {      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return NULL;;

    } else {      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return l->car;;

    };

  };

}


list cdr(list l) {
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Attempt to cdr an empty list!!!!\n");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Attempt to cdr an empty list!!!!\n");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return NULL;;

  } else {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return l->cdr;;

  };

}


list cons(box data, list l) {
  pair p = NULL;
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  p = makePair();
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  p->cdr = l;
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  p->car = data;
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  p->typ = "list";
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return p;;

}


box caar(list l) {
  
if (globalTrace)
    printf("caar at q/lists.qon:45 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "caar", "45" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:45");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return car(car(l));;

}


box cadr(list l) {
  
if (globalTrace)
    printf("cadr at q/lists.qon:46 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "cadr", "46" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:46");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return car(cdr(l));;

}


box caddr(list l) {
  
if (globalTrace)
    printf("caddr at q/lists.qon:47 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "caddr", "47" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:47");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return car(cdr(cdr(l)));;

}


box cadddr(list l) {
  
if (globalTrace)
    printf("cadddr at q/lists.qon:48 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "cadddr", "48" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:48");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return car(cdr(cdr(cdr(l))));;

}


box caddddr(list l) {
  
if (globalTrace)
    printf("caddddr at q/lists.qon:49 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "caddddr", "49" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:49");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return car(cdr(cdr(cdr(cdr(l)))));;

}


box cddr(list l) {
  
if (globalTrace)
    printf("cddr at q/lists.qon:50 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "cddr", "50" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:50");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cdr(cdr(l));;

}


box first(list l) {
  
if (globalTrace)
    printf("first at q/lists.qon:51 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "first", "51" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:51");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return car(l);;

}


box second(list l) {
  
if (globalTrace)
    printf("second at q/lists.qon:52 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "second", "52" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:52");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cadr(l);;

}


box third(list l) {
  
if (globalTrace)
    printf("third at q/lists.qon:53 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "third", "53" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:53");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return caddr(l);;

}


box fourth(list l) {
  
if (globalTrace)
    printf("fourth at q/lists.qon:54 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "fourth", "54" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:54");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cadddr(l);;

}


box fifth(list l) {
  
if (globalTrace)
    printf("fifth at q/lists.qon:55 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "fifth", "55" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:55");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return caddddr(l);;

}


box sixth(list l) {
  
if (globalTrace)
    printf("sixth at q/lists.qon:56 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "sixth", "56" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:56");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return car(cdr(cdr(cdr(cdr(cdr(l))))));;

}


box seventh(list l) {
  
if (globalTrace)
    printf("seventh at q/lists.qon:57 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "seventh", "57" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:57");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return car(cdr(cdr(cdr(cdr(cdr(cdr(l)))))));;

}


box eighth(list l) {
  
if (globalTrace)
    printf("eighth at q/lists.qon:58 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "eighth", "58" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:58");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(l))))))));;

}


box ninth(list l) {
  
if (globalTrace)
    printf("ninth at q/lists.qon:59 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "ninth", "59" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:59");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(l)))))))));;

}


box tenth(list l) {
  
if (globalTrace)
    printf("tenth at q/lists.qon:60 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "tenth", "60" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:60");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(l))))))))));;

}


box eleventh(list l) {
  
if (globalTrace)
    printf("eleventh at q/lists.qon:61 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "eleventh", "61" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:61");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(l)))))))))));;

}


box twelfth(list l) {
  
if (globalTrace)
    printf("twelfth at q/lists.qon:62 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "twelfth", "62" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:62");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(l))))))))))));;

}


box rest(list l) {
  
if (globalTrace)
    printf("rest at q/lists.qon:63 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "rest", "63" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:63");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cdr(l);;

}


bool isList(box b) {
  
  StackTraceMove("in", "q/lists.qon", "isList", "66" );
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return true;;

  } else {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return equalString("list", b->typ);;

  };

}


list emptyList() {
  
if (globalTrace)
    printf("emptyList at q/lists.qon:73 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "emptyList", "73" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:73");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return NULL;;

}


bool isEmpty(box b) {
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return true;;

  } else {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return false;;

  };

}


int listLength(list l) {
  
if (globalTrace)
    printf("listLength at q/lists.qon:82 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "listLength", "82" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:86");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:87");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return 0;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:88");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return add1(listLength(cdr(l)));;

  };

}


list alistCons(box key, box value, list alist) {
  
if (globalTrace)
    printf("alistCons at q/lists.qon:91 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "alistCons", "91" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:92");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(cons(key, value), alist);;

}


list assoc(char* searchTerm, list l) {
  list elem = NULL;

if (globalTrace)
    printf("assoc at q/lists.qon:94 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "assoc", "94" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:96");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assertType("list", l, 96, "q/lists.qon");

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:98");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:99");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return boxBool(false);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:101");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    elem = car(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:102");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    assertType("list", elem, 102, "q/lists.qon");

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:103");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isEmpty(elem)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:104");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return assoc(searchTerm, cdr(l));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:106");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( false) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:106");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("Comparing %s and %s\n", searchTerm, stringify(car(elem)));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:106");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("");

      };

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:107");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(searchTerm, stringify(car(elem)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:110");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return elem;;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:111");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return assoc(searchTerm, cdr(l));;

      };

    };

  };

}


char* chooseBox(char* aType) {
  
if (globalTrace)
    printf("chooseBox at q/lists.qon:114 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "chooseBox", "114" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:116");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("string", aType)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:117");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "boxString";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:118");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("symbol", aType)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:119");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return "boxSymbol";;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:120");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("bool", aType)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:121");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return "boxBool";;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:122");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("int", aType)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:123");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return "boxInt";;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:124");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("float", aType)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:125");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return "boxFloat";;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:126");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            panic("Invalid type");

          };

        };

      };

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:127");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return "";;

}


box mlistLiteral(box b) {
  
if (globalTrace)
    printf("mlistLiteral at q/lists.qon:130 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "mlistLiteral", "130" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:132");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:133");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:135");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("string", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:136");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return b;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:138");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("bool", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:140");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return b;;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:142");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("int", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:143");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return b;;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:145");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("symbol", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:146");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return boxString(unBoxSymbol(b));;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:150");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return boxString(stringConcatenate("Unsupported type in mlistLiteral: ", boxType(b)));;

          };

        };

      };

    };

  };

}


list doMultiList(list l) {
  list newlist = NULL;
list ret = NULL;
box elem = NULL;

if (globalTrace)
    printf("doMultiList at q/lists.qon:154 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "doMultiList", "154" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:156");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:157");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxSymbol("nil"), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:159");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:160");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return NULL;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:163");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      elem = first(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:164");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      newlist = cons(boxString(chooseBox(elem->typ)), cons(mlistLiteral(first(l)), newlist));

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:165");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ret = cons(cons(boxSymbol("cons"), cons(newlist, doMultiList(cdr(l)))), NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:174");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return ret;;

    };

  };

}


bool isDigit(char* val) {
  
if (globalTrace)
    printf("isDigit at q/lists.qon:176 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "isDigit", "176" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:178");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(string_length(val), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:179");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return stringContains("0123456789", val);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:180");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  };

}


bool isUnsignedIntFrom(char* val, int pos) {
  int len = 0;

if (globalTrace)
    printf("isUnsignedIntFrom at q/lists.qon:182 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "isUnsignedIntFrom", "182" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:184");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  len = string_length(val);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:185");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(add1(pos), len)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:186");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:188");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isDigit(sub_string(val, pos, 1))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:189");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return isUnsignedIntFrom(val, add1(pos));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:190");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return false;;

    };

  };

}


bool isInt(char* val) {
  int len = 0;
char* firstLetter = "";

if (globalTrace)
    printf("isInt at q/lists.qon:192 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "isInt", "192" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:194");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  len = string_length(val);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:195");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(len, 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:196");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:198");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  firstLetter = sub_string(val, 0, 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:199");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("-", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:201");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equal(len, 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:202");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return false;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:203");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return isUnsignedIntFrom(val, 1);;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:204");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return isUnsignedIntFrom(val, 0);;

  };

}


bool isFloatFrom(char* val, int pos, bool seenDot, bool seenDigit, bool digitAfterDot) {
  int len = 0;
char* ch = "";

if (globalTrace)
    printf("isFloatFrom at q/lists.qon:206 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "isFloatFrom", "206" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:208");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  len = string_length(val);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:209");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(add1(pos), len)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:210");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return andBool(seenDot, andBool(seenDigit, digitAfterDot));;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:212");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ch = sub_string(val, pos, 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:213");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isDigit(ch)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:214");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return isFloatFrom(val, add1(pos), seenDot, true, orBool(digitAfterDot, seenDot));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:216");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(".", ch)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:218");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( seenDot) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:219");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return false;;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:220");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return isFloatFrom(val, add1(pos), true, seenDigit, false);;

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:221");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return false;;

    };

  };

}


bool isFloat(char* val) {
  int len = 0;
char* firstLetter = "";

if (globalTrace)
    printf("isFloat at q/lists.qon:223 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "isFloat", "223" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:225");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  len = string_length(val);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:226");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(len, 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:227");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:229");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  firstLetter = sub_string(val, 0, 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:230");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("-", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:232");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equal(len, 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:233");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return false;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:234");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return isFloatFrom(val, 1, false, false, false);;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:235");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return isFloatFrom(val, 0, false, false, false);;

  };

}


box id(box b) {
  
if (globalTrace)
    printf("id at q/lists.qon:237 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "id", "237" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:237");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return b;;

}


char* chooseBoxInterp(box b) {
  char* val = stringify(b);
char* firstLetter = sub_string(val, 0, 1);

if (globalTrace)
    printf("chooseBoxInterp at q/lists.qon:240 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "chooseBoxInterp", "240" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:244");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("string", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:245");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "boxString";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:247");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("\"", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:248");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return "boxString";;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:249");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("true", val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:250");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return "boxBool";;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:251");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("false", val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:252");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return "boxBool";;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:253");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( isFloat(val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:254");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return "boxFloat";;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:255");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( isInt(val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:256");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return "boxInt";;

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:257");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return "id";;

            };

          };

        };

      };

    };

  };

}


list doInterpolatedList(list l) {
  list newlist = NULL;
list ret = NULL;
box elem = NULL;

if (globalTrace)
    printf("doInterpolatedList at q/lists.qon:265 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "doInterpolatedList", "265" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:267");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:268");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxSymbol("nil"), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:270");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:271");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return NULL;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:274");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      elem = first(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:276");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      newlist = cons(boxString(chooseBoxInterp(elem)), cons(first(l), newlist));

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:277");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ret = cons(cons(boxSymbol("cons"), cons(newlist, doInterpolatedList(cdr(l)))), NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:286");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return ret;;

    };

  };

}


list doStringList(list l) {
  list newlist = NULL;
list ret = NULL;

if (globalTrace)
    printf("doStringList at q/lists.qon:289 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "doStringList", "289" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:291");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:292");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxSymbol("nil"), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:294");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newlist = cons(boxSymbol("boxString"), cons(first(l), newlist));

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:295");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ret = cons(cons(boxSymbol("cons"), cons(newlist, doStringList(cdr(l)))), NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:304");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return ret;;

  };

}


list doSymbolList(list l) {
  list newlist = NULL;
list ret = NULL;

if (globalTrace)
    printf("doSymbolList at q/lists.qon:306 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "doSymbolList", "306" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:308");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:309");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxSymbol("nil"), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:311");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newlist = cons(boxSymbol("boxSymbol"), cons(first(l), newlist));

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:312");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ret = cons(cons(boxSymbol("cons"), cons(newlist, doSymbolList(cdr(l)))), NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:321");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return ret;;

  };

}


list doBoxList(list l) {
  
if (globalTrace)
    printf("doBoxList at q/lists.qon:324 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "doBoxList", "324" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:327");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:328");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxSymbol("nil"), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:330");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(cons(boxSymbol("cons"), cons(first(l), doBoxList(cdr(l)))), NULL);;

  };

}


list concatLists(list seq1, list seq2) {
  
if (globalTrace)
    printf("concatLists at q/lists.qon:343 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "concatLists", "343" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:345");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(seq1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:346");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return seq2;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:347");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(car(seq1), concatLists(cdr(seq1), seq2));;

  };

}


list alistKeys(list alist) {
  
if (globalTrace)
    printf("alistKeys at q/lists.qon:349 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "alistKeys", "349" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:351");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(alist)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:352");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:353");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(car(car(alist)), alistKeys(cdr(alist)));;

  };

}


void display(list l) {
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("nil ");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("[");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      displayList(l, 0, true);
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("]");

    } else {      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      displayList(l, 0, true);

    };

  };

}


void displayList(list l, int indent, bool first) {
  box val = NULL;
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isEmpty(l)) {        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return;;

      } else {        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( first) {
        } else {          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf(" ");

        };
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        val = car(l);
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( isList(val)) {          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("%s", openBrace());
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          displayList(car(l), add1(indent), true);
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("%s", closeBrace());
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          displayList(cdr(l), indent, false);

        } else {          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("string", val->typ)) {            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("\"%s\"", unBoxString(val));

          } else {            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s", stringify(val));

          };
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          displayList(cdr(l), indent, false);

        };

      };

    } else {      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("string", l->typ)) {        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("\"%s\"", unBoxString(l));

      } else {        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s", stringify(l));

      };

    };

  };

}


char* StringListJoinRec(list l, char* sep) {
  box val = NULL;

if (globalTrace)
    printf("StringListJoinRec at q/lists.qon:395 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "StringListJoinRec", "395" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:397");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:398");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:400");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:402");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:403");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return "";;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:405");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equal(listLength(l), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:406");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return stringify(car(l));;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:408");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return stringConcatenate(stringify(car(l)), stringConcatenate(sep, StringListJoinRec(cdr(l), sep)));;

        };

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:410");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return "";;

    };

  };

}


char* StringListJoin(list l, char* sep) {
  box val = NULL;

if (globalTrace)
    printf("StringListJoin at q/lists.qon:418 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "StringListJoin", "418" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:420");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:423");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return stringConcatenate(stringify(car(l)), stringConcatenate(sep, StringListJoinRec(cdr(l), sep)));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:425");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return stringify(car(l));;

  };

}


box ListToBoxString(list l, int indent) {
  
if (globalTrace)
    printf("ListToBoxString at q/lists.qon:428 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "ListToBoxString", "428" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:430");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return boxString(ListToString(l, indent, true, false));;

}


char* ListToString(list l, int indent, bool first, bool withNewLines) {
  box val = NULL;

if (globalTrace)
    printf("ListToString at q/lists.qon:433 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "ListToString", "433" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:435");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:436");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:438");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:440");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:441");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return "";;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:445");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        val = car(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:446");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( isList(val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:448");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return StringListJoin(cons(boxString(stringify(tern(withNewLines, boxString("\n"), boxString(stringIndent(indent))))), cons(boxString(openBrace()), cons(boxString(" "), cons(boxString(ListToString(car(l), add1(indent), true, withNewLines)), cons(boxString(closeBrace()), cons(boxString(" "), cons(boxString(ListToString(cdr(l), indent, false, withNewLines)), NULL))))))), "");;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:464");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return stringConcatenate(stringify(val), ListToString(cdr(l), indent, false, withNewLines));;

        };

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:466");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return stringify(l);;

    };

  };

}


list listReverse(list l) {
  
if (globalTrace)
    printf("listReverse at q/lists.qon:473 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "listReverse", "473" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:475");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:476");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:477");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(car(l), listReverse(cdr(l)));;

  };

}


bool inList(box item, list l) {
  
if (globalTrace)
    printf("inList at q/lists.qon:479 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "inList", "479" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:481");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:482");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:485");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(car(l), item)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:486");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:487");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return inList(item, cdr(l));;

    };

  };

}


bool equalList(list a, list b) {
  
if (globalTrace)
    printf("equalList at q/lists.qon:489 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "equalList", "489" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:491");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(a)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:492");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:494");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:496");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return false;;

    };

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:499");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:500");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(a)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:502");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:504");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return false;;

    };

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:507");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(car(a), car(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:508");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return equalList(cdr(a), cdr(b));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:509");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  };

}


list reverseRec(list oldL, list newL) {
  
if (globalTrace)
    printf("reverseRec at q/lists.qon:512 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "reverseRec", "512" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:514");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(oldL)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:515");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return newL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:516");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return reverseRec(cdr(oldL), cons(first(oldL), newL));;

  };

}


list reverseList(list l) {
  
if (globalTrace)
    printf("reverseList at q/lists.qon:519 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "reverseList", "519" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:521");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return reverseRec(l, NULL);;

}


list flatten(list tree) {
  
if (globalTrace)
    printf("flatten at q/lists.qon:524 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "flatten", "524" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:526");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:527");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:529");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:530");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return concatLists(flatten(car(tree)), flatten(cdr(tree)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:531");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(car(tree), flatten(cdr(tree)));;

    };

  };

}


void printStringTree(list tree) {
  box val = NULL;

if (globalTrace)
    printf("printStringTree at q/lists.qon:535 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "printStringTree", "535" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:537");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:538");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:540");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  val = car(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:541");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:542");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printStringTree(car(tree));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:543");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s", stringify(val));

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:544");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printStringTree(cdr(tree));

}


list macrowalk(list l) {
  
if (globalTrace)
    printf("macrowalk at q/macros.qon:5 (%s)\n", caller);

  StackTraceMove("in", "q/macros.qon", "macrowalk", "5" );

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:6");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:7");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:11");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:18");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringConcatenate("box", "List"), stringify(car(l)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:21");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return car(doBoxList(cdr(l)));;

      } else {
      };

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:25");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringConcatenate("string", "List"), stringify(car(l)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:28");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return car(doStringList(cdr(l)));;

      } else {
      };

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:32");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringConcatenate("symbol", "List"), stringify(car(l)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:35");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return car(doSymbolList(cdr(l)));;

      } else {
      };

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:37");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringConcatenate("multi", "List"), stringify(car(l)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:40");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return car(doMultiList(cdr(l)));;

      } else {
      };

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:43");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringConcatenate("makeL", "ist"), stringify(car(l)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:45");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return car(doInterpolatedList(cdr(l)));;

      } else {
      };

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:48");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(macrowalk(car(l)), macrowalk(cdr(l)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:50");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return l;;

    };

  };

}


list macrosingle(list tree, char* search, char* replace) {
  box val = NULL;

if (globalTrace)
    printf("macrosingle at q/macros.qon:55 (%s)\n", caller);

  StackTraceMove("in", "q/macros.qon", "macrosingle", "55" );

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:56");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:58");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:62");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:65");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(macrosingle(car(tree), search, replace), macrosingle(cdr(tree), search, replace));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:71");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(search, stringify(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:74");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        val = clone(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:75");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        val->str = replace;

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:76");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return val;;

      } else {
      };

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:78");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return tree;;

    };

  };

}


list macroSymbolSingle(list tree, char* search, char* replace) {
  box val = NULL;

if (globalTrace)
    printf("macroSymbolSingle at q/macros.qon:81 (%s)\n", caller);

  StackTraceMove("in", "q/macros.qon", "macroSymbolSingle", "81" );

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:82");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:83");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:85");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:87");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(macroSymbolSingle(car(tree), search, replace), macroSymbolSingle(cdr(tree), search, replace));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:89");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("symbol", boxType(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:91");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString(search, stringify(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:93");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          val = clone(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:94");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          val->str = replace;

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:95");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return val;;

        } else {
        };

      } else {
      };

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:98");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return tree;;

    };

  };

}


list macrolist(list l, char* search, list replace) {
  box val = NULL;

if (globalTrace)
    printf("macrolist at q/macros.qon:101 (%s)\n", caller);

  StackTraceMove("in", "q/macros.qon", "macrolist", "101" );

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:102");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:103");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:107");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:110");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(search, stringify(car(l)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:113");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return concatLists(replace, macrolist(cdr(l), search, replace));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:116");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(macrolist(car(l), search, replace), macrolist(cdr(l), search, replace));;

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:124");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return l;;

    };

  };

}


list filterVoid(list l) {
  box token = NULL;

if (globalTrace)
    printf("filterVoid at q/compiler.qon:8 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "filterVoid", "8" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:12");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:13");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:15");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token = car(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:16");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("void", token->typ)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:17");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return filterVoid(cdr(l));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:18");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(token, filterVoid(cdr(l)));;

    };

  };

}


list filterTokens(list l) {
  box token = NULL;

if (globalTrace)
    printf("filterTokens at q/compiler.qon:20 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "filterTokens", "20" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:24");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:25");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:27");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token = car(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:28");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(boxType(token), "symbol")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:30");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("__LINE__", stringify(token))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:32");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(getTagFail(token, boxString("line"), boxInt(-1)), filterTokens(cdr(l)));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:37");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("__COLUMN__", stringify(token))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:39");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return cons(getTagFail(token, boxString("column"), boxInt(-1)), filterTokens(cdr(l)));;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:44");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("__FILE__", stringify(token))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:46");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return cons(getTagFail(token, boxString("filename"), boxString("Unknown file")), filterTokens(cdr(l)));;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:51");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return cons(token, filterTokens(cdr(l)));;

          };

        };

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:52");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(token, filterTokens(cdr(l)));;

    };

  };

}


box finish_token(char* prog, int start, int len, int line, int column, char* filename) {
  box token = NULL;

if (globalTrace)
    printf("finish_token at q/compiler.qon:54 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "finish_token", "54" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:56");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(len, 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:58");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token = boxSymbol(sub_string(prog, start, len));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:59");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token->tag = alistCons(boxString("filename"), boxString(filename), alistCons(boxString("column"), boxInt(column), alistCons(boxString("line"), boxInt(line), alistCons(boxString("totalCharPos"), boxInt(start), NULL))));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:66");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return token;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:67");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return newVoid();;

  };

}


char* readString(char* prog, int start, int len) {
  char* token = "";

if (globalTrace)
    printf("readString at q/compiler.qon:69 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "readString", "69" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:71");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  token = sub_string(prog, sub1(add(start, len)), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:72");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("\"", token)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:73");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return sub_string(prog, start, sub1(len));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:75");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("\\", token)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:76");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return readString(prog, start, add(2, len));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:77");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return readString(prog, start, add1(len));;

    };

  };

}


char* readComment(char* prog, int start, int len) {
  char* token = "";

if (globalTrace)
    printf("readComment at q/compiler.qon:80 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "readComment", "80" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:82");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(add(start, len), string_length(prog))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:83");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:85");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token = sub_string(prog, sub1(add(start, len)), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:86");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isLineBreak(token)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:87");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return sub_string(prog, start, sub1(len));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:88");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return readComment(prog, start, add1(len));;

    };

  };

}


bool isLineBreak(char* s) {
  
if (globalTrace)
    printf("isLineBreak at q/compiler.qon:90 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "isLineBreak", "90" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:92");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("\n", s)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:93");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:95");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("\r", s)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:95");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:95");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return false;;

    };

  };

}


int incForNewLine(box token, int val) {
  
if (globalTrace)
    printf("incForNewLine at q/compiler.qon:97 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "incForNewLine", "97" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:101");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("\n", stringify(token))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:102");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return add1(val);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:103");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return val;;

  };

}


box annotateReadPosition(char* filename, int linecount, int column, int start, box newBox) {
  
if (globalTrace)
    printf("annotateReadPosition at q/compiler.qon:105 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "annotateReadPosition", "105" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:107");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return setTag(boxString("filename"), boxString(filename), setTag(boxString("column"), boxInt(column), setTag(boxString("line"), boxInt(linecount), setTag(boxString("totalCharPos"), boxInt(start), newBox))));;

}


list scan(char* prog, int start, int len, int linecount, int column, char* filename) {
  box token = NULL;
char* newString = "";
box newBox = NULL;

if (globalTrace)
    printf("scan at q/compiler.qon:117 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "scan", "117" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:120");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(string_length(prog), sub1(add(start, len)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:122");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token = boxSymbol(sub_string(prog, sub1(add(start, len)), 1));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:123");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token->tag = alistCons(boxString("totalCharPos"), boxInt(start), NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:124");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isOpenBrace(token)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:126");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(finish_token(prog, start, sub1(len), linecount, column, filename), cons(annotateReadPosition(filename, linecount, column, start, boxSymbol(openBrace())), scan(prog, add1(start), 1, linecount, add1(column), filename)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:130");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isCloseBrace(token)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:132");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(finish_token(prog, start, sub1(len), linecount, column, filename), cons(annotateReadPosition(filename, linecount, column, start, boxSymbol(closeBrace())), scan(prog, add(start, len), 1, linecount, add1(column), filename)));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:137");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( isWhiteSpace(stringify(token))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:139");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return cons(finish_token(prog, start, sub1(len), linecount, column, filename), scan(prog, add(start, len), 1, incForNewLine(token, linecount), 0, filename));;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:142");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol(";"), token)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:144");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return scan(prog, add(start, add1(add1(string_length(readComment(prog, add1(start), len))))), 1, add1(linecount), 0, filename);;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:146");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("\""), token)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:148");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              newString = readString(prog, add1(start), len);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:149");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              newBox = annotateReadPosition(filename, linecount, column, start, boxString(newString));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:151");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return cons(newBox, scan(prog, add(start, add1(add1(string_length(newString)))), 1, linecount, add1(column), filename));;

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:153");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return scan(prog, start, sub(len, -1), linecount, add1(column), filename);;

            };

          };

        };

      };

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:154");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  };

}


bool isOpenBrace(box b) {
  
if (globalTrace)
    printf("isOpenBrace at q/compiler.qon:157 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "isOpenBrace", "157" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:159");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxSymbol(openBrace()), b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:160");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:161");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  };

}


bool isCloseBrace(box b) {
  
if (globalTrace)
    printf("isCloseBrace at q/compiler.qon:164 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "isCloseBrace", "164" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:168");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxSymbol(closeBrace()), b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:169");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:170");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  };

}


list skipList(list l) {
  box b = NULL;

if (globalTrace)
    printf("skipList at q/compiler.qon:174 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "skipList", "174" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:176");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:177");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:179");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    b = car(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:180");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isOpenBrace(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:181");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return skipList(skipList(cdr(l)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:183");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isCloseBrace(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:184");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cdr(l);;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:185");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return skipList(cdr(l));;

      };

    };

  };

}


int add(int a, int b) {
  
  StackTraceMove("in", "q/base.qon", "add", "20" );
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return sub(a, sub(0, b));;

}


float addf(float a, float b) {
  
if (globalTrace)
    printf("addf at q/base.qon:21 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "addf", "21" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:21");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return subf(a, subf(0, b));;

}


int sub1(int a) {
  
  StackTraceMove("in", "q/base.qon", "sub1", "22" );
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return sub(a, 1);;

}


int add1(int a) {
  
if (globalTrace)
    printf("add1 at q/base.qon:23 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "add1", "23" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:23");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return add(a, 1);;

}


box clone(box b) {
  box newb = NULL;

if (globalTrace)
    printf("clone at q/base.qon:25 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "clone", "25" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb = makeBox();

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:29");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(newb)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:31");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("clone: newb is nil\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:32");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("clone: newb is nil");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:33");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return newb;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:35");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newb->typ = b->typ;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:36");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newb->voi = b->voi;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:37");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newb->boo = b->boo;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:38");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newb->tag = b->tag;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:39");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newb->lis = b->lis;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:40");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newb->str = b->str;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:41");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newb->i = b->i;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:42");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newb->f = b->f;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:43");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newb->lengt = b->lengt;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:44");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newb->car = b->car;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:45");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newb->cdr = b->cdr;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:46");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return newb;;

  };

}


box tern(bool cond, list tr, list fal) {
  
if (globalTrace)
    printf("tern at q/base.qon:48 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "tern", "48" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:50");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( cond) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:50");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return tr;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:50");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return fal;;

  };

}


char* ternString(bool cond, char* tr, char* fal) {
  
if (globalTrace)
    printf("ternString at q/base.qon:52 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "ternString", "52" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:54");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( cond) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:54");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return tr;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:54");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return fal;;

  };

}


list ternList(bool cond, list tr, list fal) {
  
if (globalTrace)
    printf("ternList at q/base.qon:56 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "ternList", "56" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:58");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( cond) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:58");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return tr;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:58");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return fal;;

  };

}


box newVoid() {
  box newb = NULL;

if (globalTrace)
    printf("newVoid at q/base.qon:61 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "newVoid", "61" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:65");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb = makeBox();

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:66");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->voi = true;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:67");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->typ = "void";

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:68");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return newb;;

}


void stackDump() {
  
if (globalTrace)
    printf("stackDump at q/base.qon:70 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stackDump", "70" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:71");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("");

}


void nop() {
  
if (globalTrace)
    printf("nop at q/base.qon:75 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "nop", "75" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:76");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("");

}


bool equalBox(box a, box b) {
  
  StackTraceMove("in", "q/base.qon", "equalBox", "78" );
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(b)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("string", boxType(a))) {      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return equalString(unBoxString(a), stringify(b));;

    } else {      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("bool", boxType(a))) {        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return andBool(unBoxBool(a), unBoxBool(b));;

      } else {        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("symbol", boxType(a))) {          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("symbol", boxType(b))) {            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return equalString(unBoxSymbol(a), unBoxSymbol(b));;

          } else {            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return false;;

          };

        } else {          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("int", boxType(a))) {            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return equal(unBoxInt(a), unBoxInt(b));;

          } else {            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalString("float", boxType(a))) {              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              if ( equalString("float", boxType(b))) {                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                StackTraceMove("out", "", "", "");

                return equalf(unBoxFloat(a), unBoxFloat(b));;

              } else {                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                StackTraceMove("out", "", "", "");

                return false;;

              };

            } else {              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return false;;

            };

          };

        };

      };

    };

  };

}


char* openBrace() {
  
if (globalTrace)
    printf("openBrace at q/base.qon:105 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "openBrace", "105" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:105");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return "(";;

}


char* closeBrace() {
  
if (globalTrace)
    printf("closeBrace at q/base.qon:106 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "closeBrace", "106" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:106");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return ")";;

}


char* boxType(box b) {
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return b->typ;;

}


box makeBox() {
  box b = NULL;
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = malloc(sizeof(Box));
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("failed to create box!");

  } else {
  };
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->tag = NULL;
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->car = NULL;
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->cdr = NULL;
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->lis = NULL;
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "None - error!";
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return b;;

}


pair makePair() {
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return makeBox();;

}


box boxString(char* s) {
  box b = NULL;
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = makeBox();
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->str = s;
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->lengt = string_length(s);
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "string";
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return b;;

}


box boxSymbol(char* s) {
  box b = NULL;

  StackTraceMove("in", "q/base.qon", "boxSymbol", "144" );
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = boxString(s);
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "symbol";
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return b;;

}


box boxBool(bool boo) {
  box b = NULL;

if (globalTrace)
    printf("boxBool at q/base.qon:153 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "boxBool", "153" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:157");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = makeBox();

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:158");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->boo = boo;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:159");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "bool";

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:160");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return b;;

}


box boxInt(int val) {
  box b = NULL;

if (globalTrace)
    printf("boxInt at q/base.qon:162 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "boxInt", "162" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:166");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = makeBox();

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:167");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->i = val;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:168");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "int";

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:169");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return b;;

}


box boxFloat(float val) {
  box b = NULL;

if (globalTrace)
    printf("boxFloat at q/base.qon:172 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "boxFloat", "172" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:176");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = makeBox();

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:177");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->f = val;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:178");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "float";

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:179");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return b;;

}


void assertType(char* atype, box abox, int line, char* file) {
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(abox)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(atype, "nil")) {      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return;;

    } else {      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return;;

    };

  } else {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(atype, boxType(abox))) {      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return;;

    } else {      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("Assertion failure at line %d, in file %s: provided value is not a '%s'!  It was actually '%s'. Contents:", line, file, atype, boxType(abox));
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(abox);
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\n");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(cons(boxString("Token may have been read from "), cons(boxString(stringify(getTagFail(abox, boxString("filename"), boxString("source file not found")))), cons(boxString(":"), cons(boxString(stringify(getTagFail(abox, boxString("line"), boxString("source line not found")))), NULL)))));
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTracePrint();
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      panic("Invalid type!");

    };

  };

}


char* unBoxString(box b) {
  
if (globalTrace)
    printf("unBoxString at q/base.qon:198 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "unBoxString", "198" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:199");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assertType("string", b, 199, "q/base.qon");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:199");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return b->str;;

}


char* unBoxSymbol(box b) {
  
  StackTraceMove("in", "q/base.qon", "unBoxSymbol", "201" );
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return b->str;;

}


bool unBoxBool(box b) {
  
if (globalTrace)
    printf("unBoxBool at q/base.qon:202 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "unBoxBool", "202" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:202");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return b->boo;;

}


int unBoxInt(box b) {
  
if (globalTrace)
    printf("unBoxInt at q/base.qon:203 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "unBoxInt", "203" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:203");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return b->i;;

}


float unBoxFloat(box b) {
  
if (globalTrace)
    printf("unBoxFloat at q/base.qon:204 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "unBoxFloat", "204" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:204");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return b->f;;

}


char* stringify_rec(box b) {
  
if (globalTrace)
    printf("stringify_rec at q/base.qon:206 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stringify_rec", "206" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:208");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:209");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:211");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return stringConcatenate(stringify(car(b)), stringConcatenate(" ", stringify_rec(cdr(b))));;

  };

}


char* stringify(box b) {
  
  StackTraceMove("in", "q/base.qon", "stringify", "215" );
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "()";;

  } else {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("string", boxType(b))) {      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return unBoxString(b);;

    } else {      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("bool", boxType(b))) {        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( unBoxBool(b)) {          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return "true";;

        } else {          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return "false";;

        };

      } else {        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("int", boxType(b))) {          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return intToString(unBoxInt(b));;

        } else {          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("float", boxType(b))) {            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return floatToString(unBoxFloat(b));;

          } else {            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalString("symbol", boxType(b))) {              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return unBoxSymbol(b);;

            } else {              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              if ( equalString("list", boxType(b))) {                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                StackTraceMove("out", "", "", "");

                return stringConcatenate("(", stringConcatenate(stringify(car(b)), stringConcatenate(" ", stringConcatenate(stringify_rec(cdr(b)), ")"))));;

              } else {                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                StackTraceMove("out", "", "", "");

                return stringConcatenate("Unsupported type in stringify: ", boxType(b));;

              };

            };

          };

        };

      };

    };

  };

}


bool hasTag(box aBox, box key) {
  
if (globalTrace)
    printf("hasTag at q/base.qon:253 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "hasTag", "253" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:255");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(aBox)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:256");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:257");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return isNotFalse(assoc(stringify(key), aBox->tag));;

  };

}


box getTag(box aBox, box key) {
  
if (globalTrace)
    printf("getTag at q/base.qon:260 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "getTag", "260" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:262");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( false) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:264");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Getting %s from: ", stringify(key));

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:265");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(alistKeys(aBox->tag));

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:266");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:268");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:269");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cdr(assoc(stringify(key), aBox->tag));;

}


box getTagFail(box aBox, box key, box onFail) {
  
if (globalTrace)
    printf("getTagFail at q/base.qon:272 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "getTagFail", "272" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:274");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( hasTag(aBox, key)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:275");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return getTag(aBox, key);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:276");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return onFail;;

  };

}


bool assocExists(char* key, box aBox) {
  
if (globalTrace)
    printf("assocExists at q/base.qon:282 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "assocExists", "282" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:286");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(aBox)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:287");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:288");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return isNotFalse(assoc(key, aBox));;

  };

}


box assocFail(char* key, box aBox, box onFail) {
  
if (globalTrace)
    printf("assocFail at q/base.qon:290 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "assocFail", "290" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:293");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( assocExists(key, aBox)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:294");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return assoc(key, aBox);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:295");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString(key), onFail);;

  };

}


box assocPanic(char* key, box aBox, char* onFail) {
  
if (globalTrace)
    printf("assocPanic at q/base.qon:297 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "assocPanic", "297" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:300");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( assocExists(key, aBox)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:301");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return assoc(key, aBox);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:302");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic(onFail);

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:303");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  panic("Inconceivable");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:305");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return NULL;;

}


box setTag(box key, list val, box aStruct) {
  
if (globalTrace)
    printf("setTag at q/base.qon:308 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "setTag", "308" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:311");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  aStruct->tag = alistCons(key, val, aStruct->tag);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:312");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return aStruct;;

}


void locPanic(char* file, char* line, char* message) {
  
if (globalTrace)
    printf("locPanic at q/base.qon:314 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "locPanic", "314" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:317");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s %s:%s\n", file, line, message);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:318");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  panic(message);

}


bool truthy(box aVal) {
  
if (globalTrace)
    printf("truthy at q/base.qon:320 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "truthy", "320" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:323");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return isNotFalse(aVal);;

}


bool isNotFalse(box aVal) {
  
if (globalTrace)
    printf("isNotFalse at q/base.qon:325 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "isNotFalse", "325" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:328");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(boxType(aVal), "bool")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:329");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( unBoxBool(aVal)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:329");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:329");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return false;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:330");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return true;;

  };

}


box toStr(box thing) {
  
if (globalTrace)
    printf("toStr at q/base.qon:332 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "toStr", "332" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:334");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return boxString(stringify(thing));;

}


box listLast(list alist) {
  
if (globalTrace)
    printf("listLast at q/base.qon:336 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "listLast", "336" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:339");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(cdr(alist))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:340");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return car(alist);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:341");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return listLast(cdr(alist));;

  };

}


void newLine(int indent) {
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printIndent(indent);

}


void printIndent(int ii) {
  
if (globalTrace)
    printf("printIndent at q/base.qon:347 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "printIndent", "347" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:350");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(ii, 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:351");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  ");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:351");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(sub1(ii));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:352");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  };

}


char* stringIndent(int ii) {
  
if (globalTrace)
    printf("stringIndent at q/base.qon:354 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stringIndent", "354" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:357");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(ii, 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:358");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return stringConcatenate("  ", stringIndent(sub1(ii)));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:359");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "";;

  };

}


list listIndent(int ii) {
  
if (globalTrace)
    printf("listIndent at q/base.qon:360 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "listIndent", "360" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:363");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(boxString(stringIndent(ii))), NULL);;

}


list listNewLine(int ii) {
  
if (globalTrace)
    printf("listNewLine at q/base.qon:366 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "listNewLine", "366" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:369");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(boxString(stringConcatenate("\n", stringIndent(ii)))), NULL);;

}


list argList(int count, int pos, char** args) {
  
if (globalTrace)
    printf("argList at q/base.qon:372 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "argList", "372" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:375");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(count, pos)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:377");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString(getStringArray(pos, args)), argList(count, add1(pos), args));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:380");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  };

}


void tron() {
  
if (globalTrace)
    printf("tron at q/base.qon:382 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "tron", "382" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:382");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalTrace = true;

}


void troff() {
  
if (globalTrace)
    printf("troff at q/base.qon:383 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "troff", "383" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:383");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalTrace = false;

}


void stron() {
  
if (globalTrace)
    printf("stron at q/base.qon:384 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stron", "384" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:384");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalStepTrace = true;

}


void stroff() {
  
if (globalTrace)
    printf("stroff at q/base.qon:385 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stroff", "385" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:385");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalStepTrace = false;

}


void StackTraceMove(char* direction, char* filename, char* fname, char* line) {
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(direction, "in")) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    globalStackTrace = cons(cons(boxString(filename), cons(boxString(line), cons(boxString(fname), NULL))), globalStackTrace);

  } else {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    globalStackTrace = cdr(globalStackTrace);

  };

}


void StackTracePrint() {
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("Stack trace:\n");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(globalStackTrace)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  <empty>\n");

  } else {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTracePrintHelper(globalStackTrace);

  };

}


void StackTracePrintHelper(list stack) {
  char* file = stringify(first(car(stack)));
char* line = "";
char* func = "";
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(stack)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  <end>\n");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    file = stringify(first(car(stack)));
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    line = stringify(second(car(stack)));
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    func = stringify(third(first(stack)));
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  %s:%s %s\n", file, line, func);
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTracePrintHelper(cdr(stack));

  };

}


list NoStackTrace_list() {
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cons(boxString("StackTraceMove"), cons(boxString("StackTracePrint"), cons(boxString("StackTracePrintHelper"), cons(boxString("NoStackTrace_list"), cons(boxString("car"), cons(boxString("cdr"), cons(boxString("cons"), cons(boxString("set"), cons(boxString("boxString"), cons(boxString("makePair"), cons(boxString("set-struct"), cons(boxString("display"), cons(boxString("list"), cons(boxString("assertType"), cons(boxString("isEmpty"), cons(boxString("isNil"), cons(boxString("get-struct"), cons(boxString("equalString"), cons(boxString("binop"), cons(boxString("strcmp"), cons(boxString("main"), cons(boxString("makeBox"), cons(boxString("string_length"), cons(boxString("boxType"), cons(boxString("displayList"), cons(boxString("newLine"), cons(boxString("panic"), NULL)))))))))))))))))))))))))));;

}


list NoTrace_list() {
  
if (globalTrace)
    printf("NoTrace_list at q/base.qon:435 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "NoTrace_list", "435" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:437");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(boxString("StackTraceMove"), cons(boxString("StackTracePrint"), cons(boxString("StackTracePrintHelper"), cons(boxString("NoStackTrace_list"), cons(boxString("car"), cons(boxString("cdr"), cons(boxString("cons"), cons(boxString("set"), cons(boxString("boxString"), cons(boxString("makePair"), cons(boxString("set-struct"), cons(boxString("display"), cons(boxString("list"), cons(boxString("assertType"), cons(boxString("isEmpty"), cons(boxString("isNil"), cons(boxString("get-struct"), cons(boxString("equalString"), cons(boxString("binop"), cons(boxString("strcmp"), cons(boxString("main"), cons(boxString("makeBox"), cons(boxString("string_length"), cons(boxString("boxType"), cons(boxString("displayList"), cons(boxString("newLine"), cons(boxString("panic"), cons(boxString("boxString"), cons(boxString("boxSymbol"), cons(boxString("boxType"), cons(boxString("equalString"), cons(boxString("unBoxSymbol"), cons(boxString("isList"), cons(boxString("makeBox"), cons(boxString("equalBox"), cons(boxString("sub"), cons(boxString("sub1"), cons(boxString("stringify"), cons(boxString("add"), cons(boxString("greaterthan"), NULL))))))))))))))))))))))))))))))))))))))));;

}


int indexOfHelper(char* haystack, char* needle, int start, int current) {
  
if (globalTrace)
    printf("indexOfHelper at q/base.qon:444 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "indexOfHelper", "444" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:446");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(add(current, string_length(needle)), string_length(haystack))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:447");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return -1;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:449");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(sub_string(haystack, current, string_length(needle)), needle)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:450");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return current;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:451");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return indexOfHelper(haystack, needle, start, add1(current));;

    };

  };

}


int indexOf(char* haystack, char* needle, int start) {
  
if (globalTrace)
    printf("indexOf at q/base.qon:453 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "indexOf", "453" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:455");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(string_length(needle), 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:456");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return start;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:457");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return indexOfHelper(haystack, needle, start, start);;

  };

}


char* stringReplace(char* old, char* new, char* s) {
  int pos = 0;

if (globalTrace)
    printf("stringReplace at q/base.qon:460 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stringReplace", "460" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:462");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  pos = indexOf(s, old, 0);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:463");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(pos, -1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:464");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return s;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:465");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return stringConcatenate(sub_string(s, 0, pos), stringConcatenate(new, stringReplace(old, new, sub_string(s, add(pos, string_length(old)), sub(string_length(s), add(pos, string_length(old)))))));;

  };

}


bool stringContains(char* haystack, char* needle) {
  int haystackLength = 0;
int needleLength = 0;

if (globalTrace)
    printf("stringContains at q/base.qon:475 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stringContains", "475" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:479");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  haystackLength = string_length(haystack);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:480");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  needleLength = string_length(needle);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:482");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(needleLength, haystackLength)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:485");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:488");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return stringContainsHelper(haystack, needle, 0);;

  };

}


bool stringContainsHelper(char* haystack, char* needle, int startIndex) {
  int haystackLength = 0;
int needleLength = 0;

if (globalTrace)
    printf("stringContainsHelper at q/base.qon:490 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stringContainsHelper", "490" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:495");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  haystackLength = string_length(haystack);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:496");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  needleLength = string_length(needle);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:498");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(add(startIndex, needleLength), haystackLength)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:501");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:503");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(sub_string(haystack, startIndex, needleLength), needle)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:506");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:509");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return stringContainsHelper(haystack, needle, add(startIndex, 1));;

    };

  };

}


bool isWhiteSpace(char* s) {
  
if (globalTrace)
    printf("isWhiteSpace at q/base.qon:511 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "isWhiteSpace", "511" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:513");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(" ", s)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:514");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:516");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("\t", s)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:517");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:519");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("\n", s)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:520");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return true;;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:522");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("\r", s)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:523");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return true;;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:524");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return false;;

        };

      };

    };

  };

}


char* stringTrim(char* s) {
  
if (globalTrace)
    printf("stringTrim at q/base.qon:526 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stringTrim", "526" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:528");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(string_length(s), 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:530");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:532");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isWhiteSpace(sub_string(s, 0, 1))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:534");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return stringTrim(sub_string(s, 1, sub1(string_length(s))));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:536");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isWhiteSpace(sub_string(s, sub(string_length(s), 1), 1))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:538");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return stringTrim(sub_string(s, 0, sub(string_length(s), 1)));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:540");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return s;;

      };

    };

  };

}


list stringSplit(char* s, char* delimiter) {
  int end = 0;
int delimiterLength = 0;

if (globalTrace)
    printf("stringSplit at q/base.qon:542 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stringSplit", "542" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:546");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("Entering stringSplit with s: %.20s..., delimiter: %s\n", s, delimiter);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:547");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  delimiterLength = string_length(delimiter);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:548");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  end = indexOf(s, delimiter, 0);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:549");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(end, -1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:551");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("No delimiter found in stringSplit\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:552");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString(s), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:554");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Splitting string in stringSplit\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:555");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString(sub_string(s, 0, end)), stringSplit(sub_string(s, add(end, delimiterLength), sub(string_length(s), add(end, delimiterLength))), delimiter));;

  };

}


bool ansi3IsNil(void* a) {
  
if (globalTrace)
    printf("ansi3IsNil at q/shims/ansi3.qon:13 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "ansi3IsNil", "13" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:15");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( (a == NULL)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:16");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:17");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  };

}


void* pointerAdd(void* a, int b) {
  
if (globalTrace)
    printf("pointerAdd at q/shims/ansi3.qon:20 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "pointerAdd", "20" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:22");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return (a + b);;

}


char* getEnv(char* key) {
  
if (globalTrace)
    printf("getEnv at q/shims/ansi3.qon:24 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "getEnv", "24" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:26");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return getenv(key);;

}


void panic(char* s) {
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalStepTrace = false;
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTracePrint();
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  abort();
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  exit(1);

}


int sub(int a, int b) {
  
  StackTraceMove("in", "q/shims/ansi3.qon", "sub", "35" );
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return (a - b);;

}


float mult(int a, int b) {
  
if (globalTrace)
    printf("mult at q/shims/ansi3.qon:39 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "mult", "39" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:41");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return (a * b);;

}


int greaterthan(int a, int b) {
  
  StackTraceMove("in", "q/shims/ansi3.qon", "greaterthan", "43" );
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return (a > b);;

}


float subf(float a, float b) {
  
if (globalTrace)
    printf("subf at q/shims/ansi3.qon:47 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "subf", "47" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:49");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return (a - b);;

}


float multf(float a, float b) {
  
if (globalTrace)
    printf("multf at q/shims/ansi3.qon:51 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "multf", "51" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:53");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return (a * b);;

}


int greaterthanf(float a, float b) {
  
if (globalTrace)
    printf("greaterthanf at q/shims/ansi3.qon:55 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "greaterthanf", "55" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:57");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return (a > b);;

}


int equalf(float a, float b) {
  
if (globalTrace)
    printf("equalf at q/shims/ansi3.qon:59 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "equalf", "59" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:61");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return (a == b);;

}


int equal(int a, int b) {
  
if (globalTrace)
    printf("equal at q/shims/ansi3.qon:63 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "equal", "63" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:65");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return (a == b);;

}


int equalString(char* a, char* b) {
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return (0 == strcmp(a, b));;

}


int string_length(char* s) {
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return strlen(s);;

}


char* setSubString(char* target, int start, char* source) {
  
if (globalTrace)
    printf("setSubString at q/shims/ansi3.qon:75 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "setSubString", "75" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:77");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  target[start]=source[0];

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:78");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return target;;

}


char* sub_string(char* s, int start, int length) {
  char* substr = "";

if (globalTrace)
    printf("sub_string at q/shims/ansi3.qon:81 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "sub_string", "81" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:83");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  substr = calloc(add(length, 1), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:84");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  strncpy(substr, (s + start), length);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:85");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return substr;;

}


char* stringConcatenate(char* a, char* b) {
  int len = 0;
char* target = NULL;

if (globalTrace)
    printf("stringConcatenate at q/shims/ansi3.qon:88 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "stringConcatenate", "88" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:90");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  len = add(add(strlen(a), strlen(b)), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:91");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  target = calloc(len, 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:92");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  strncat(target, a, len);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:93");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  strncat(target, b, len);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:94");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return target;;

}


char* intToString(int a) {
  int len = 0;
char* target = NULL;

if (globalTrace)
    printf("intToString at q/shims/ansi3.qon:97 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "intToString", "97" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:99");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  len = 100;

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:100");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  target = calloc(len, 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:101");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  snprintf(target, 99, "%d", a);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:102");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return target;;

}


char* floatToString(float a) {
  int len = 0;
char* target = NULL;

if (globalTrace)
    printf("floatToString at q/shims/ansi3.qon:105 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "floatToString", "105" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:107");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  len = 100;

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:108");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  target = calloc(len, 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:109");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  snprintf(target, 99, "%g", a);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:110");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return target;;

}


void* gc_malloc(uint size) {
  
if (globalTrace)
    printf("gc_malloc at q/shims/ansi3.qon:113 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "gc_malloc", "113" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:115");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return malloc(size);;

}


int* makeArray(int length) {
  int* array = NULL;

if (globalTrace)
    printf("makeArray at q/shims/ansi3.qon:118 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "makeArray", "118" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:120");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  array = gc_malloc(mult(length, sizeof(int)));

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:121");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return array;;

}


int at(int* arr, int index) {
  
if (globalTrace)
    printf("at at q/shims/ansi3.qon:124 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "at", "124" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:126");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return arr[index];;

}


void setAt(int* array, int index, int value) {
  
if (globalTrace)
    printf("setAt at q/shims/ansi3.qon:129 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "setAt", "129" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:131");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  array[index] = value;

}


void setCharAt(char* array, int index, int value) {
  
if (globalTrace)
    printf("setCharAt at q/shims/ansi3.qon:134 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "setCharAt", "134" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:136");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  array[index] = value;

}


box read_file(char* filename) {
  char* buffer = NULL;
long length = 0;
FILE* f = NULL;

if (globalTrace)
    printf("read_file at q/shims/ansi3.qon:139 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "read_file", "139" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:141");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  f = fopen(filename, "rb");

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:142");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( ansi3IsNil(f)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:143");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:145");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fseek(f, 0, SEEK_END);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:146");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    length = ftell(f);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:147");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fseek(f, 0, SEEK_SET);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:148");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    buffer = calloc(add(1, length), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:150");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( ansi3IsNil(buffer)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:151");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      panic("Malloc failed!\n");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:152");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      fread(buffer, 1, length, f);

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:153");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fclose(f);

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:156");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return boxString(buffer);;

}


void write_file(char* filename, char* data) {
  char* buffer = NULL;
long length = 0;
FILE* f = NULL;

if (globalTrace)
    printf("write_file at q/shims/ansi3.qon:159 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "write_file", "159" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:161");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  f = fopen(filename, "w");

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:162");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( ansi3IsNil(f)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:163");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Error opening file!");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:165");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fprintf(f, "%s", data);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:166");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fclose(f);

  };

}


char* getStringArray(int index, char** strs) {
  
if (globalTrace)
    printf("getStringArray at q/shims/ansi3.qon:170 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "getStringArray", "170" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:172");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return strs[index];;

}


char** programArgs() {
  
if (globalTrace)
    printf("programArgs at q/shims/ansi3.qon:174 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "programArgs", "174" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:176");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return globalArgs;;

}


int programArgsCount() {
  
if (globalTrace)
    printf("programArgsCount at q/shims/ansi3.qon:179 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "programArgsCount", "179" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:181");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return globalArgsCount;;

}


int main(int argc, char** argv) {
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  caller = calloc(1024, 1);
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalArgs = argv;
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalArgsCount = argc;
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return start();;

}


char* character(int num) {
  char* buffer = NULL;
char* str = NULL;

if (globalTrace)
    printf("character at q/shims/ansi3.qon:193 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "character", "193" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:195");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  str = malloc(2);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:196");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( ansi3IsNil(str)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:197");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return 0;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:199");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    setCharAt(str, 0, num);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:200");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    setCharAt(str, 1, 0);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:201");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return str;;

  };

}


void displays(char* s) {
  
if (globalTrace)
    printf("displays at q/shims/ansi3.qon:208 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "displays", "208" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:210");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", s);

}


int start() {
  bool runTests = false;
list cmdLine = NULL;
box filenameBox = NULL;
char* filename = "";
bool runPerl = false;
bool runJava = false;
bool runNode = false;
bool runNode2 = false;
bool runHaskell = false;
bool runAnsi3 = false;
bool runTree = false;

if (globalTrace)
    printf("start at compiler.qon:5 (%s)\n", caller);

  StackTraceMove("in", "compiler.qon", "start", "5" );

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:19");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  cmdLine = listReverse(argList(globalArgsCount, 0, globalArgs));

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:21");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(cmdLine), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:22");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    filenameBox = second(cmdLine);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:23");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    filenameBox = boxString("compiler.qon");

  };

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:24");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  filename = unBoxString(filenameBox);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:26");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  releaseMode = inList(boxString("--release"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:27");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runTests = inList(boxString("--test"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runJava = inList(boxString("--java"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:29");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runPerl = inList(boxString("--perl"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:30");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runTree = inList(boxString("--tree"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:31");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runNode = inList(boxString("--node"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:32");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runNode2 = inList(boxString("--node2"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:33");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runHaskell = orBool(inList(boxString("--haskell"), cmdLine), inList(boxString("--hs"), cmdLine));

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:34");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runAnsi3 = inList(boxString("--ansi3"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:35");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalTrace = inList(boxString("--trace"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:36");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalStepTrace = inList(boxString("--steptrace"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:37");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( orBool(inList(boxString("--help"), cmdLine), inList(boxString("-h"), cmdLine))) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:39");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Usage: quon file [options]\n\nNote the options go after the file name\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:40");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Options:\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:41");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  -h, --help  Display this help\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:42");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --release   Compile in release mode\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:43");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --test      Run the test suite\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:44");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --java      Compile to Java\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:45");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --perl      Compile to Perl\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:46");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --tree      Compile to an s-expression tree\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:47");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --node      Compile to Node.js\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:48");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --node2      Compile to Node.js, new outputter\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:49");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --haskell, --hs Compile to Haskell\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:51");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --ansi3     Compile to ANSI C (quon version 3)\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:52");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --trace     Trace execution\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:53");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --steptrace Step trace execution\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:54");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    exit(0);

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:58");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( runTests) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:60");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test0();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:61");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test1();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:62");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test2();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:63");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test3();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:64");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test4();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:65");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test5();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:66");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test6();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:67");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test7();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:68");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test8();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:69");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test9();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:70");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test10();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:71");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test12();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:72");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test13();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:73");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test14();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:74");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test15();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:75");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test16();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:76");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test17();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:77");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test18();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:78");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test19();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:79");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test20();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:80");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test21();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:81");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test22();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:82");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test23();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:83");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test24();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:84");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test25();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:85");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test27();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:86");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test28();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:88");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n\nAfter all that hard work, I need a beer...\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:89");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    beers(9);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:91");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( runTree) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:92");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(macrowalk(loadQuon(filename)));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:94");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( orBool(runNode, runNode2)) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:95");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        node2Compile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:95");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("\n");

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:97");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( runHaskell) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:98");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          haskellCompile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:98");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("\n");

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:100");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( runPerl) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:101");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            perlCompile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:101");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("\n");

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:103");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( runJava) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:104");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              javaCompile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:104");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("\n");

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:106");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              if ( runAnsi3) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:107");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                ansi3Compile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:107");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                printf("\n");

              } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:108");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                ansi3Compile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:108");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                printf("\n");

              };

            };

          };

        };

      };

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:109");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return 0;;

}


