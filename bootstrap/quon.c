
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

void bashdisplays(char* s);
void bashFunctionArgs(list decls, int argNum, int indent);
void bashExpression(list tree, int indent, bool statement);
box bashVarOrLit(box a);
void bashRecurList(list expr, int indent);
void bashIf(list node, int indent);
void bashSetStruct(list node, int indent);
void bashGetStruct(list node, int indent);
void bashSet(list node, int indent);
void bashReturn(list node, int indent);
void bashStatement(list node, int indent);
void bashBody(list tree, int indent);
void bashDeclarations(list decls, int indent);
void bashFunction(list node);
void bashForwardDeclaration(list node);
void bashForwardDeclarations(list tree);
void bashFunctions(list tree);
void bashIncludes(list nodes);
void bashTypeDecl(list l);
void bashStructComponents(list node);
void bashStruct(list node);
box bashTypeMap(box aSym);
box bashFuncMap(box aSym);
void bashType(list node);
void bashTypes(list nodes);
void bashCompile(char* filename);
bool notBool(bool a);
bool andBool(bool a, bool b);
bool nand(bool a, bool b);
bool xor(bool a, bool b);
bool lessThan(int a, int b);
void luaFunctionArgs(int indent, list tree);
void luaFunction(int indent, list functionDefinition);
void luaDeclarations(int indent, list declarations);
void luaExpressionStart(int indent, list program);
void luaExpression(int indent, list program);
void luaStatement(int indent, list statement);
void luaBody(char* local_caller, int indent, list program);
void luaFunctions(int indent, list program);
void luaProgram(list program);
void luaIncludes(list nodes);
void luaCompile(char* filename);
void javaFunctionArgs(list tree);
void javaLeaf(list thisNode, int indent);
void javaStructGetterExpression(list thisNode, int indent);
void javaExpression(list node, int indent);
void javaRecurList(list expr, int indent);
void javaSubExpression(list tree, int indent);
void javaIf(list node, int indent);
void javaSetStruct(list node, int indent);
void javaGetStruct(list node, int indent);
void javaSet(list node, int indent);
void javaStatement(list node, int indent);
void javaBody(list tree, int indent);
void javaDeclarations(list decls, int indent);
void javaFunction(list node);
void javaFunctions(list tree);
void javaIncludes(list nodes);
void javaTypeDecl(list l);
void javaStructComponents(list node);
void javaStruct(list node);
box javaTypeMap(box aSym);
box javaTypesNoDeclare();
box javaFuncMap(box aSym);
void javaType(list node);
void javaTypes(list nodes);
void javaCompile(char* filename);
list node2FunctionArgs(list tree);
list node2Expression(list tree, int indent);
list node2RecurList(list expr, int indent);
list node2If(list node, int indent, char* functionName);
list node2SetStruct(list node, int indent);
list node2GetStruct(list node, int indent);
list node2Set(list node, int indent);
list node2Return(list node, int indent);
list node2Statement(list node, int indent, char* functionname);
list node2Body(list tree, int indent, char* functionName);
list node2eclarations(list decls, int indent);
list node2Function(list node);
list node2Functions(list tree);
list node2Includes(list nodes);
list node2TypeDecl(list l);
list node2StructComponents(list node);
void node2Struct(list node);
box node2TypeMap(box aSym);
box node2FuncMap(box aSym);
list node2Type(list node);
list node2Types(list nodes);
void node2Compile(char* filename);
void nodeFunctionArgs(list tree);
void nodeLeaf(list thisNode, int indent);
void nodeStructGetterExpression(list thisNode, int indent);
void nodeExpression(list tree, int indent);
void nodeRecurList(list expr, int indent);
void nodeIf(list node, int indent);
void nodeGetStruct(list node, int indent);
void nodeSet(list node, int indent);
void nodeSetStruct(list node, int indent);
void nodeStatement(list node, int indent);
void nodeBody(list tree, int indent);
void nodeDeclarations(list decls, int indent);
void nodeFunction(list node);
void nodeForwardDeclaration(list node);
void nodeForwardDeclarations(list tree);
void nodeFunctions(list tree);
void nodeIncludes(list nodes);
void nodeTypeDecl(list l);
void nodeStructComponents(list node);
void nodeStruct(list node);
box nodeTypeMap(box aSym);
box nodeFuncMap(box aSym);
void nodeType(list node);
void nodeTypes(list nodes);
void nodeCompile(char* filename);
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
void ansi3displays(char* s);
void ansi3FunctionArgs(list tree);
void ansi3Expression(list tree, int indent);
void ansi3RecurList(list expr, int indent);
void ansi3If(list node, int indent, char* functionName);
void ansi3SetStruct(list node, int indent);
void ansi3GetStruct(list node, int indent);
void ansi3Set(list node, int indent);
void ansi3Return(list node, int indent);
void ansi3Statement(list node, int indent, char* functionname);
void ansi3Body(list tree, int indent, char* functionName);
void ansi3Declarations(list decls, int indent);
void ansi3Function(list node);
void ansi3ForwardDeclaration(list node);
void ansi3ForwardDeclarations(list tree);
void ansi3Functions(list tree);
void ansi3Includes(list nodes);
void ansi3TypeDecl(list l);
void ansi3StructComponents(list node);
void ansi3Struct(list node);
box ansi3TypeMap(box aSym);
box ansi3FuncMap(box aSym);
void ansi3Type(list node);
void ansi3Types(list nodes);
void ansi3Compile(char* filename);
char* dollar();
char* escapeSingleQuotes(char* s);
list getGlobalVariables();
list collectVariables(list args, list decls);
void perlGlobalVariables();
void perlMainEntry();
list collectVariablesFromArgs(list args);
list collectVariablesFromDecls(list decls);
list appendVariables(list vars1, list vars2);
void perlFunctionArgs(list tree);
void perlExpression(list tree, int indent, list variables);
void perlRecurList(list expr, int indent, list variables);
void perlStatement(list node, int indent, list variables);
void perlBody(list tree, int indent, list variables);
void perlSet(list node, int indent, list variables);
void perlSetStruct(list node, int indent, list variables);
void perlIf(list node, int indent, list variables);
void perlGetStruct(list node, int indent);
void perlDeclarations(list decls, int indent, list variables);
void perlFunction(list node);
void perlForwardDeclaration(list node);
void perlForwardDeclarations(list tree);
void perlFunctions(list tree);
void perlIncludes(list nodes);
box perlTypeMap(box aSym);
box perlFuncMap(box aSym, list variables);
void perlCompile(char* filename);
list readSexpr(char* aStr, char* filename);
list sexprTree(list l);
list loadQuon(char* filename);
list getIncludes(list program);
list getTypes(list program);
list getFunctions(list program);
list loadIncludes(list tree);
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
bool isInt(char* val);
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
list macrowalk(list l);
list macrosingle(list tree, char* search, char* replace);
list macrolist(list l, char* search, list replace);
list filterVoid(list l);
list filterTokens(list l);
box finish_token(char* prog, int start, int len, int line, int column, char* filename);
char* readString(char* prog, int start, int len);
char* readComment(char* prog, int start, int len);
bool isWhiteSpace(char* s);
bool isLineBreak(char* s);
int incForNewLine(box token, int val);
box annotateReadPosition(char* filename, int linecount, int column, int start, box newBox);
list scan(char* prog, int start, int len, int linecount, int column, char* filename);
bool isOpenBrace(box b);
bool isCloseBrace(box b);
list skipList(list l);
list makeNode(char* name, char* subname, list code, list children);
list addToNode(box key, box val, list node);
list makeStatementNode(char* name, char* subname, list code, list children, box functionName);
list astExpression(list tree);
list astSubExpression(list tree);
list astIf(list tree, box fname);
list astSetStruct(list tree);
list astSet(list tree);
list astGetStruct(list tree);
list astReturnVoid(box fname);
list astStatement(list tree, box fname);
list astBody(list tree, box fname);
list astFunction(list tree);
list astFunctionList(list tree);
list astFunctions(list tree);
list loadLib(char* path);
list astInclude(list tree);
list astIncludeList(list tree);
list astIncludes(list tree);
list astStruct(list tree);
list astType(list tree);
list astTypeList(list tree);
list astTypes(list tree);
list declarationsof(list ass);
list codeof(list ass);
list functionNameof(list ass);
list nodeof(list ass);
list lineof(list ass);
list subnameof(list ass);
list nameof(list ass);
list childrenof(list ass);
bool isNode(list val);
bool isLeaf(list n);
list noStackTrace();
list treeCompile(char* filename);
list astBuild(char* filename);
void astCompile(char* filename);
list mergeIncludes(list program);
list merge_recur(list incs, list program);
list mergeInclude(list inc, list program);
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
void assertType(char* atype, box abox, int line, char* file);
char* unBoxString(box b);
char* unBoxSymbol(box b);
bool unBoxBool(box b);
int unBoxInt(box b);
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
int equal(int a, int b);
int equalString(char* a, char* b);
int string_length(char* s);
char* setSubString(char* target, int start, char* source);
char* sub_string(char* s, int start, int length);
char* stringConcatenate(char* a, char* b);
char* intToString(int a);
void* gc_malloc(uint size);
int* makeArray(int length);
int at(int* arr, int index);
void setAt(int* array, int index, int value);
void setCharAt(char* array, int index, int value);
char* read_file(char* filename);
void write_file(char* filename, char* data);
char* getStringArray(int index, char** strs);
char** programArgs();
int programArgsCount();
int main(int argc, char** argv);
char* character(int num);
void displays(char* s);
int start();

//End forward declarations



void bashdisplays(char* s) {
  
if (globalTrace)
    printf("bashdisplays at q/bash.qon:5 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashdisplays", "5" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:7");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", s);

}


void bashFunctionArgs(list decls, int argNum, int indent) {
  
if (globalTrace)
    printf("bashFunctionArgs at q/bash.qon:11 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashFunctionArgs", "11" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:13");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:14");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:16");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("local %s=\"%s%s", stringify(second(decls)), dollar(), stringify(boxInt(argNum)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:21");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\" ;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:22");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashFunctionArgs(cdr(cdr(decls)), add(1, argNum), indent);

  };

}


void bashExpression(list tree, int indent, bool statement) {
  list thing = NULL;

if (globalTrace)
    printf("bashExpression at q/bash.qon:26 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashExpression", "26" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:32");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equal(1, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:35");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:37");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("return"), car(tree))) {
      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:41");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        bashdisplays("()");

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:44");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      thing = first(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:45");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxSymbol("get-struct"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:48");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s->%s", stringify(second(tree)), stringify(third(tree)));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:53");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxSymbol("new"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:56");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("malloc(sizeof(%s))", stringify(third(tree)));

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:60");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("passthrough"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:63");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s", stringify(second(tree)));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:67");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("binop"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:70");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("(");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:71");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              bashExpression(third(tree), indent, false);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:72");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(" %s ", stringify(second(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:75");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              bashExpression(fourth(tree), indent, false);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:76");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:80");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              if ( statement) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:82");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                printf("%s ", stringify(bashFuncMap(car(tree))));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:83");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                bashRecurList(cdr(tree), indent);

              } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:86");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                printf("%s(%s ", dollar(), stringify(bashFuncMap(car(tree))));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:91");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                bashRecurList(cdr(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:92");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                printf(")");

              };

            };

          };

        };

      };

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:100");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(bashVarOrLit(tree));

  };

}


box bashVarOrLit(box a) {
  
if (globalTrace)
    printf("bashVarOrLit at q/bash.qon:102 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashVarOrLit", "102" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:104");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(a))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:105");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return boxSymbol(stringConcatenate(dollar(), stringify(a)));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:106");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return a;;

  };

}


void bashRecurList(list expr, int indent) {
  
if (globalTrace)
    printf("bashRecurList at q/bash.qon:111 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashRecurList", "111" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:115");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:116");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:118");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashExpression(car(expr), indent, false);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:119");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:120");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      bashdisplays("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:121");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      bashdisplays(" ");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:121");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      bashRecurList(cdr(expr), indent);

    };

  };

}


void bashIf(list node, int indent) {
  
if (globalTrace)
    printf("bashIf at q/bash.qon:128 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashIf", "128" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:130");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:131");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashdisplays("if (( ");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:132");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashExpression(second(node), 0, false);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:133");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashdisplays(" )) ; then ");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:134");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashBody(cdr(third(node)), add1(indent));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:135");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:136");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashdisplays(" else ");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:137");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashBody(cdr(fourth(node)), add1(indent));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:138");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:139");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashdisplays("fi");

}


void bashSetStruct(list node, int indent) {
  
if (globalTrace)
    printf("bashSetStruct at q/bash.qon:141 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashSetStruct", "141" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:143");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:144");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s_%s%s=", dollar(), stringify(second(node)), dollar(), stringify(third(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:150");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashExpression(fourth(node), indent, false);

}


void bashGetStruct(list node, int indent) {
  
if (globalTrace)
    printf("bashGetStruct at q/bash.qon:152 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashGetStruct", "152" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:154");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:155");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s_%s%s", dollar(), stringify(first(node)), dollar(), stringify(second(node)));

}


void bashSet(list node, int indent) {
  
if (globalTrace)
    printf("bashSet at q/bash.qon:162 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashSet", "162" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:164");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:165");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  display(first(cdr(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:166");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("=");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:167");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashExpression(third(node), indent, false);

}


void bashReturn(list node, int indent) {
  
if (globalTrace)
    printf("bashReturn at q/bash.qon:169 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashReturn", "169" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:171");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:172");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(listLength(node), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:173");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashdisplays("return;");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:175");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashdisplays("return ");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:176");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashExpression(cadr(node), indent, false);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:177");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashdisplays(";");

  };

}


void bashStatement(list node, int indent) {
  
if (globalTrace)
    printf("bashStatement at q/bash.qon:180 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashStatement", "180" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:182");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("set"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:183");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashSet(node, indent);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:185");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("set-struct"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:186");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      bashSetStruct(node, indent);

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:188");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:189");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        bashIf(node, indent);

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:191");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("return"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:192");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          bashReturn(node, indent);

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:194");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:195");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          bashExpression(node, indent, true);

        };

      };

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:196");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashdisplays(" \n");

}


void bashBody(list tree, int indent) {
  list code = NULL;

if (globalTrace)
    printf("bashBody at q/bash.qon:198 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashBody", "198" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:200");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:201");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:203");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    code = tree;

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:204");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(code)) {
    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:207");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      code = car(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:208");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( notBool(releaseMode)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:211");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("\nif (( $globalTrace )) ; then\n    caller=\"from %s:%s\"\nfi", stringify(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), stringify(getTagFail(car(code), boxString("line"), boxString("Line missing"))));

      } else {
      };

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:215");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( notBool(releaseMode)) {
    } else {
    };

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:218");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashStatement(code, indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:219");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashBody(cdr(tree), indent);

  };

}


void bashDeclarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("bashDeclarations at q/bash.qon:221 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashDeclarations", "221" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:223");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:224");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:226");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:227");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("local %s=\"", stringify(second(decl)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:230");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashExpression(third(decl), indent, false);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:231");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\";\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:232");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashDeclarations(cdr(decls), indent);

  };

}


void bashFunction(list node) {
  box name = NULL;

if (globalTrace)
    printf("bashFunction at q/bash.qon:234 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashFunction", "234" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:236");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = second(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:237");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n#Building function %s from line:%s", stringify(name), stringify(getTag(name, boxString("line"))));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:238");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:239");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:240");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:242");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:243");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s(", stringify(second(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:245");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(") {");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:246");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:247");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashFunctionArgs(third(node), 1, 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:248");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashDeclarations(cdr(fourth(node)), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:249");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:250");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:252");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (( $globalTrace )) ; then\n    echo \"%s at %s:%s \" $caller\nfi", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:253");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:254");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
    };

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:259");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashBody(cdr(fifth(node)), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:260");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:261");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:263");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (( $globalTrace ))\n    echo \"Leaving %s\\n\"\n", stringify(name));

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:265");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n");

  };

}


void bashForwardDeclaration(list node) {
  
if (globalTrace)
    printf("bashForwardDeclaration at q/bash.qon:267 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashForwardDeclaration", "267" );

}


void bashForwardDeclarations(list tree) {
  
if (globalTrace)
    printf("bashForwardDeclarations at q/bash.qon:270 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashForwardDeclarations", "270" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:272");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:272");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:273");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashForwardDeclaration(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:274");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashForwardDeclarations(cdr(tree));

  };

}


void bashFunctions(list tree) {
  
if (globalTrace)
    printf("bashFunctions at q/bash.qon:276 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashFunctions", "276" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:278");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:278");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:279");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashFunction(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:279");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashFunctions(cdr(tree));

  };

}


void bashIncludes(list nodes) {
  
if (globalTrace)
    printf("bashIncludes at q/bash.qon:282 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashIncludes", "282" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:284");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "\n\n#define true 1\n#define false 0\n\n\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\nbool releaseMode = false;\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:287");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n");

}


void bashTypeDecl(list l) {
  
if (globalTrace)
    printf("bashTypeDecl at q/bash.qon:290 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashTypeDecl", "290" );

}


void bashStructComponents(list node) {
  
if (globalTrace)
    printf("bashStructComponents at q/bash.qon:294 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashStructComponents", "294" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:296");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:297");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:298");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashTypeDecl(car(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:298");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashStructComponents(cdr(node));

  };

}


void bashStruct(list node) {
  
if (globalTrace)
    printf("bashStruct at q/bash.qon:300 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashStruct", "300" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:301");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashStructComponents(cdr(node));

}


box bashTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("bashTypeMap at q/bash.qon:303 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashTypeMap", "303" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:305");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:309");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:310");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:311");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


box bashFuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("bashFuncMap at q/bash.qon:313 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashFuncMap", "313" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:315");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:317");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), NULL)))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:339");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:340");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cdr(assoc(stringify(aSym), symMap));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:341");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return aSym;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:342");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


void bashType(list node) {
  
if (globalTrace)
    printf("bashType at q/bash.qon:344 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashType", "344" );

}


void bashTypes(list nodes) {
  
if (globalTrace)
    printf("bashTypes at q/bash.qon:349 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashTypes", "349" );

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:351");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:352");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:353");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashType(car(nodes));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:353");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashTypes(cdr(nodes));

  };

}


void bashCompile(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    printf("bashCompile at q/bash.qon:359 (%s)\n", caller);

  StackTraceMove("in", "q/bash.qon", "bashCompile", "359" );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Scanning file...%s\n", filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:363");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Building sexpr\n");

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Loading shim bash\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:367");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = buildProg(cons(boxString("q/shims/bash.qon"), getIncludes(tree)), getTypes(tree), getFunctions(tree));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Loading all includes\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:369");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Applying macros\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:371");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:372");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:373");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Printing program\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:379");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashIncludes(cdr(first(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:380");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashTypes(cdr(second(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:382");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashdisplays("Box* globalStackTrace = NULL;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:383");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashdisplays("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:385");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashForwardDeclarations(cdr(third(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:386");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashdisplays("\n\n//End forward declarations\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:387");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashFunctions(cdr(third(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:388");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashdisplays("\n");

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Done printing program\n");

}


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


bool nand(bool a, bool b) {
  
if (globalTrace)
    printf("nand at q/boolean.qon:20 (%s)\n", caller);

  StackTraceMove("in", "q/boolean.qon", "nand", "20" );

if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:22");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return notBool(andBool(a, b));;

}


bool xor(bool a, bool b) {
  
if (globalTrace)
    printf("xor at q/boolean.qon:24 (%s)\n", caller);

  StackTraceMove("in", "q/boolean.qon", "xor", "24" );

if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:26");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return nand(nand(a, nand(a, b)), nand(b, nand(a, b)));;

}


bool lessThan(int a, int b) {
  
if (globalTrace)
    printf("lessThan at q/boolean.qon:28 (%s)\n", caller);

  StackTraceMove("in", "q/boolean.qon", "lessThan", "28" );

if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:30");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return andBool(notBool(equal(a, b)), notBool(greaterthan(a, b)));;

}


void luaFunctionArgs(int indent, list tree) {
  
if (globalTrace)
    printf("luaFunctionArgs at q/lua.qon:4 (%s)\n", caller);

  StackTraceMove("in", "q/lua.qon", "luaFunctionArgs", "4" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:6");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:7");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:9");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(second(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:10");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:10");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:10");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(",");

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:11");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaFunctionArgs(indent, cddr(tree));

  };

}


void luaFunction(int indent, list functionDefinition) {
  char* fname = "";

if (globalTrace)
    printf("luaFunction at q/lua.qon:14 (%s)\n", caller);

  StackTraceMove("in", "q/lua.qon", "luaFunction", "14" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:16");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fname = stringify(second(functionDefinition));

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:17");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("-- Chose function name %s", fname);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:18");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nfunction %s(", fname);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:19");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  luaFunctionArgs(indent, third(functionDefinition));

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:20");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(")\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:21");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("print(\"caller: \", caller, \"-> %s\")\n", fname);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:22");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  luaDeclarations(add1(indent), cdr(fourth(functionDefinition)));

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:23");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  luaBody(fname, indent, cdr(fifth(functionDefinition)));

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:24");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("end\n");

}


void luaDeclarations(int indent, list declarations) {
  list decl = NULL;

if (globalTrace)
    printf("luaDeclarations at q/lua.qon:26 (%s)\n", caller);

  StackTraceMove("in", "q/lua.qon", "luaDeclarations", "26" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(declarations)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:30");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:32");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = first(declarations);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:33");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("local %s =", stringify(second(decl)));

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:34");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaExpressionStart(indent, third(decl));

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:35");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:36");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaDeclarations(indent, cdr(declarations));

  };

}


void luaExpressionStart(int indent, list program) {
  
if (globalTrace)
    printf("luaExpressionStart at q/lua.qon:42 (%s)\n", caller);

  StackTraceMove("in", "q/lua.qon", "luaExpressionStart", "42" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:44");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:46");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:48");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:50");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringify(car(program)), "get-struct")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:52");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s.%s", stringify(second(program)), stringify(third(program)));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:55");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString(stringify(car(program)), ">")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:57");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("greaterthan(");

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:58");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          luaExpression(indent, cdr(program));

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:59");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf(")");

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:62");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString(stringify(car(program)), "=")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:64");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("equal(");

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:65");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            luaExpression(indent, cdr(program));

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:66");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf(")");

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:69");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s(", stringify(car(program)));

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:70");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            luaExpression(indent, cdr(program));

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:71");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf(")");

          };

        };

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:77");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      luaExpression(indent, program);

    };

  };

}


void luaExpression(int indent, list program) {
  
if (globalTrace)
    printf("luaExpression at q/lua.qon:84 (%s)\n", caller);

  StackTraceMove("in", "q/lua.qon", "luaExpression", "84" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:86");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:88");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:90");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:92");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isList(car(program))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:94");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        luaExpressionStart(indent, car(program));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:98");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        display(car(program));

      };

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:101");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( greaterthan(listLength(program), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:103");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf(", ");

      } else {
      };

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:105");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      luaExpression(indent, cdr(program));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:108");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(program);

    };

  };

}


void luaStatement(int indent, list statement) {
  
if (globalTrace)
    printf("luaStatement at q/lua.qon:112 (%s)\n", caller);

  StackTraceMove("in", "q/lua.qon", "luaStatement", "112" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:114");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(stringify(car(statement)), "if")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:117");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:118");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("if ");

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:119");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    add1(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:120");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaExpressionStart(add1(indent), second(statement));

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:122");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" then\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:123");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaBody(caller, add1(indent), cdr(third(statement)));

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:124");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:125");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("else\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:126");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaBody(caller, add1(indent), cdr(fourth(statement)));

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:127");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:128");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("end\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:131");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(stringify(car(statement)), "set")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:133");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:134");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("%s = ", stringify(second(statement)));

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:135");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      luaExpressionStart(add1(indent), third(statement));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:138");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringify(car(statement)), "set-struct")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:140");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s.%s = ", stringify(second(statement)), stringify(third(statement)));

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:141");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        luaExpressionStart(indent, fourth(statement));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:144");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString(stringify(car(statement)), "return")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:146");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:147");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("return ");

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:148");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( greaterthan(listLength(statement), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:150");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            luaExpressionStart(indent, second(statement));

          } else {
          };

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:152");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("\n");

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:155");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:156");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          luaExpressionStart(indent, statement);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:157");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf(";\n");

        };

      };

    };

  };

}


void luaBody(char* local_caller, int indent, list program) {
  list statement = NULL;

if (globalTrace)
    printf("luaBody at q/lua.qon:164 (%s)\n", caller);

  StackTraceMove("in", "q/lua.qon", "luaBody", "164" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:166");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:167");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:169");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    statement = car(program);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:170");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("caller = \"%s:%s:%d\"\n", local_caller, unBoxString(getTagFail(statement, boxString("filename"), boxString("Unknown file"))), unBoxInt(getTagFail(statement, boxString("line"), boxInt(-1))));

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:171");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaStatement(add1(indent), statement);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:172");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:173");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaBody(local_caller, indent, cdr(program));

  };

}


void luaFunctions(int indent, list program) {
  
if (globalTrace)
    printf("luaFunctions at q/lua.qon:176 (%s)\n", caller);

  StackTraceMove("in", "q/lua.qon", "luaFunctions", "176" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:178");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:180");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:182");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaFunction(indent, car(program));

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:183");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaFunctions(indent, cdr(program));

  };

}


void luaProgram(list program) {
  
if (globalTrace)
    printf("luaProgram at q/lua.qon:188 (%s)\n", caller);

  StackTraceMove("in", "q/lua.qon", "luaProgram", "188" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:190");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  luaIncludes(NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:191");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  luaFunctions(0, cdr(third(program)));

}


void luaIncludes(list nodes) {
  
if (globalTrace)
    printf("luaIncludes at q/lua.qon:195 (%s)\n", caller);

  StackTraceMove("in", "q/lua.qon", "luaIncludes", "195" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:197");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "\nfunction luaDump(o)\n   if type(o) == 'table' then\n      local s = '{ '\n      for k,v in pairs(o) do\n         if type(k) ~= 'number' then k = '\"'..k..'\"' end\n         s = s .. '['..k..'] = ' .. luaDump(v) .. ','\n      end\n      return s .. '} '\n   else\n      return tostring(o)\n   end\nend\nprintf = function(s,...)\nreturn io.write(s:format(...))\nend -- function\n    \nfunction stringConcatenate(a,b)\nreturn a..b\nend\n    \nfunction getStringArray(index, arr)\nreturn arr[index]\nend\n       \nfunction luaWriteFile(name, data)  \nlocal file = io.open(name, \"w\")\nfile:write(data)\nfile:close(file)\nend\n    function luaSubstring(s, start, length)\nreturn string.sub(s, start, start+length)\nend\n    \n    function luaReadFile(file)\n      local f = assert(io.open(file, \"rb\"))\n      local content = f:read(\"*all\")      f:close()\n      return content\n    end\n     \nfunction equalString(a,b)\n        return a==b;\n     end\n    \n     function new()\n        return {};\n     end\n    \n     function isNil(val)\n        return val == nil;\n     end\n    \n     function getEnv(key)\n        return os.getenv(key);\n     end\n    \n    function panic(s)\n      print(s);\n    os.exit()\n    end\n    \n    function sub(a, b) \n      return a - b; \n    end\n\n    function mult(a, b) \n      return a * b;\n    end\n    \n    function greaterthan(a, b)\n      return a > b;\n    end\n    \n    function subf(a, b) \n      return a - b;\n    end\n    \n    function multf(a, b)\n      return a * b;\n    end\n    \n    function greaterthanf(a, b)\n      return a > b;\n    end\n    \n    function equal(a, b)\n      return a == b;\n    end\n    \n    function andBool(a, b)\n      return a == b;\n    end\n    \n    function string_length(s)\n      return strlen(s);\n    end\n    \n    function setSubString(target, start, source)\n      panic(\"stub\");\n      end\n    \n    function sub_string(s, start, length)\n      panic(\"stub\");\n    end\n    \n    function intToString(a)\n      panic(\"stub\")\n return a\n    end\n\n    function gc_malloc(size)\n      return \"\"\n    end\n    \n    function makeArray(length)\n      return {}\n    end\n    \n    function at(arr, index)\n      return arr[index+1];\n    end\n    \n    function setAt(array, index, value)\n      array[index+1] = value;\n    end\n    \n    function read_file(file)\n      local f = io.open(file, \"r\")\n      local content = \"\"\n      local length = 0\n\n      while f:read(0) ~= \"\" do\n          local current = f:read(\"*all\")\n\n          print(#current, length)\n          length = length + #current\n\n          content = content .. current\n      end\n\n      return content\n    end\n    \n    function write_file(filename, data)\n      local file = io.open(filename,'w')\n      file:write(tostring(data))\n      file:close()\n    end\n    \n    caller=\"main\";\n    \n    globalArgs={};\n    globalArgsCount=0;\n    globalTrace = false;\n    globalStepTrace = false;\n\n    function main()\n      globalArgs = arg;\n      globalArgsCount = #arg + 1;\n      return start();\n    end\n    \n");

}


void luaCompile(char* filename) {
  list tree = NULL;

if (globalTrace)
    printf("luaCompile at q/lua.qon:203 (%s)\n", caller);

  StackTraceMove("in", "q/lua.qon", "luaCompile", "203" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:206");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:209");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:210");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:211");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "write-file", "luaWriteFile");

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:212");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "read-file", "luaReadFile");

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:213");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "string-length", "string.len");

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:215");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "sub-string", "luaSubstring");

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:216");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "stringLength", "string.len");

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:218");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  luaProgram(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:219");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:220");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("function main()\nglobalArgs = arg\nglobalArgsCount = #arg\nstart()\nend\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:221");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("main()");

}


void javaFunctionArgs(list tree) {
  
if (globalTrace)
    printf("javaFunctionArgs at q/java.qon:3 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaFunctionArgs", "3" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:5");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:6");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:8");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(javaTypeMap(first(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:9");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" ");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:10");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(second(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:11");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:11");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:11");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(",");

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:12");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaFunctionArgs(cddr(tree));

  };

}


void javaLeaf(list thisNode, int indent) {
  
if (globalTrace)
    printf("javaLeaf at q/java.qon:14 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaLeaf", "14" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:15");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  display(javaFuncMap(codeof(thisNode)));

}


void javaStructGetterExpression(list thisNode, int indent) {
  
if (globalTrace)
    printf("javaStructGetterExpression at q/java.qon:17 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaStructGetterExpression", "17" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:19");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("structGetter"), subnameof(thisNode))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:20");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaGetStruct(thisNode, indent);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:21");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaLeaf(thisNode, indent);

  };

}


void javaExpression(list node, int indent) {
  
if (globalTrace)
    printf("javaExpression at q/java.qon:23 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaExpression", "23" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:25");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isLeaf(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:26");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(javaFuncMap(codeof(node)));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:27");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaSubExpression(node, indent);

  };

}


void javaRecurList(list expr, int indent) {
  
if (globalTrace)
    printf("javaRecurList at q/java.qon:29 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaRecurList", "29" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:33");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:34");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:36");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaExpression(car(expr), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:37");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:38");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:39");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(", ");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:39");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      javaRecurList(cdr(expr), indent);

    };

  };

}


void javaSubExpression(list tree, int indent) {
  box thing = NULL;

if (globalTrace)
    printf("javaSubExpression at q/java.qon:41 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaSubExpression", "41" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:43");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:44");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:46");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNode(childrenof(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:47");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      javaSubExpression(childrenof(tree), indent);

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:49");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isLeaf(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:50");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        display(javaFuncMap(codeof(tree)));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:52");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equal(1, listLength(childrenof(tree)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:54");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          display(codeof(car(childrenof(tree))));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:55");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxString("return"), codeof(car(childrenof(tree))))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:58");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("");

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:59");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("()");

          };

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:61");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          thing = codeof(car(childrenof(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:62");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("get-struct"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:64");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s.%s", stringify(codeof(second(childrenof(tree)))), stringify(codeof(third(childrenof(tree)))));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:69");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("new"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:71");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("new %s()", stringify(codeof(third(childrenof(tree)))));

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:75");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s(", stringify(javaFuncMap(codeof(car(childrenof(tree))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:79");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              javaRecurList(cdr(childrenof(tree)), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:80");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            };

          };

        };

      };

    };

  };

}


void javaIf(list node, int indent) {
  
if (globalTrace)
    printf("javaIf at q/java.qon:81 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaIf", "81" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:83");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:84");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("if ( ");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:85");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaExpression(car(first(childrenof(node))), 0);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:86");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(") {");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:87");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaBody(second(childrenof(node)), add1(indent));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:88");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:89");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("} else {");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:90");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaBody(third(childrenof(node)), add1(indent));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:91");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:92");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("}");

}


void javaSetStruct(list node, int indent) {
  
if (globalTrace)
    printf("javaSetStruct at q/java.qon:94 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaSetStruct", "94" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:96");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:97");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s.%s = ", stringify(first(codeof(node))), stringify(second(codeof(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:101");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaExpression(childrenof(node), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:102");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(";");

}


void javaGetStruct(list node, int indent) {
  
if (globalTrace)
    printf("javaGetStruct at q/java.qon:105 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaGetStruct", "105" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:107");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:108");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s.%s", stringify(first(codeof(node))), stringify(second(codeof(node))));

}


void javaSet(list node, int indent) {
  
if (globalTrace)
    printf("javaSet at q/java.qon:113 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaSet", "113" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:115");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:116");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s = ", stringify(first(codeof(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:117");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaExpression(childrenof(node), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:118");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(";");

}


void javaStatement(list node, int indent) {
  
if (globalTrace)
    printf("javaStatement at q/java.qon:121 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaStatement", "121" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:123");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("setter"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:124");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaSet(node, indent);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:126");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("structSetter"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:127");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      javaSetStruct(node, indent);

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:129");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:130");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        javaIf(node, indent);

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:132");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("returnvoid"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:133");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:133");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("return;");

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:135");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:136");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          javaExpression(childrenof(node), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:137");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf(";");

        };

      };

    };

  };

}


void javaBody(list tree, int indent) {
  
if (globalTrace)
    printf("javaBody at q/java.qon:141 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaBody", "141" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:143");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:144");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:146");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:147");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:148");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaStatement(car(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:149");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaBody(cdr(tree), indent);

  };

}


void javaDeclarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("javaDeclarations at q/java.qon:151 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaDeclarations", "151" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:153");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:154");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:156");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:157");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s = ", stringify(javaTypeMap(first(decl))), stringify(second(decl)));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:161");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(javaFuncMap(third(decl)));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:162");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:163");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaDeclarations(cdr(decls), indent);

  };

}


void javaFunction(list node) {
  box name = NULL;

if (globalTrace)
    printf("javaFunction at q/java.qon:165 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaFunction", "165" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:167");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = subnameof(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:168");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:169");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:170");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:171");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:173");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:174");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("public %s %s(", stringify(javaTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:178");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaFunctionArgs(cdr(assoc("intype", cdr(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:179");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(") {");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:180");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:181");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaDeclarations(declarationsof(node), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:182");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:183");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:185");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:186");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:187");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
    };

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:191");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaBody(childrenof(node), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:192");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:193");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:195");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("void", stringify(javaTypeMap(cdr(assoc("outtype", cdr(node))))))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:197");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("\nif (globalTrace)\n   System.out. printf(\"Leaving %s\\n\");\n", stringify(name));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:198");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("");

      };

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:200");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n");

  };

}


void javaFunctions(list tree) {
  
if (globalTrace)
    printf("javaFunctions at q/java.qon:204 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaFunctions", "204" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:206");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:207");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:208");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaFunction(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:208");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaFunctions(cdr(tree));

  };

}


void javaIncludes(list nodes) {
  
if (globalTrace)
    printf("javaIncludes at q/java.qon:210 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaIncludes", "210" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:212");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public void panic(String s) {System.exit(1);}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:213");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public void exit(Integer s) {System.exit(s);}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:214");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public int sub(int a, int b) { return a - b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:215");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public Integer mult(int a, int b) { return a * b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:216");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public boolean greaterthan(int a, int b) { return a > b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:217");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public double subf(double a, double b) { return a - b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:218");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public double multf(double a, double b) { return a * b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:219");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public boolean greaterthanf(double a, double b) { return a > b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:220");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public boolean equal(int a, int b) { return a == b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:221");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public boolean equalString(String a, String b) { return a.equals(b); }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:222");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public int string_length(String s) { return s.length();}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:223");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public String stringConcatenate(String s1, String s2) { return s1 + s2; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:224");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public int strcmp(String s1, String s2) { return s1.compareTo(s2);}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:225");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public String read_file(String filename) {try { return new String(Files.readAllBytes(Paths.get(filename)));} catch (Exception e) {panic(\"Could not read file\");return \"\";}}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:226");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public void write_file(String filename, String data) {try {Files.write(Paths.get(filename), data.getBytes(\"UTF-8\"));} catch (Exception e) {panic(\"Could not write file\");}}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:227");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public String sub_string(String s, int start, int length) {\nreturn s.substring(start, start+length);\n}\n\n\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:228");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public String intToString(int num) { char c=(char) num;  String s=Character.toString(c); return s;}");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:229");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public String character(int num) { char c=(char) num;  String s=Character.toString(c); return s;}");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:230");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public String getStringArray(int index, String[] arr) { return arr[index];}");

}


void javaTypeDecl(list l) {
  
if (globalTrace)
    printf("javaTypeDecl at q/java.qon:233 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaTypeDecl", "233" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:235");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:237");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:238");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s;\n", stringify(javaTypeMap(listLast(l))), stringify(first(l)));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:244");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:245");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s;\n", stringify(javaTypeMap(listLast(l))), stringify(car(l)));

  };

}


void javaStructComponents(list node) {
  
if (globalTrace)
    printf("javaStructComponents at q/java.qon:250 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaStructComponents", "250" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:252");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:253");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:254");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaTypeDecl(car(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:254");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaStructComponents(cdr(node));

  };

}


void javaStruct(list node) {
  
if (globalTrace)
    printf("javaStruct at q/java.qon:256 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaStruct", "256" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:257");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaStructComponents(cdr(car(node)));

}


box javaTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("javaTypeMap at q/java.qon:259 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaTypeMap", "259" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:261");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("pair"), boxSymbol("Box"), alistCons(boxSymbol("bool"), boxSymbol("boolean"), alistCons(boxSymbol("box"), boxSymbol("Box"), alistCons(boxSymbol("list"), boxSymbol("Box"), alistCons(boxSymbol("Box*"), boxSymbol("Box"), alistCons(boxSymbol("struct"), boxSymbol(""), alistCons(boxSymbol("int"), boxSymbol("Integer"), alistCons(boxSymbol("float"), boxSymbol("double"), alistCons(boxSymbol("stringArray"), boxSymbol("String[]"), alistCons(boxSymbol("string"), boxSymbol("String"), NULL))))))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:273");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:274");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:275");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


box javaTypesNoDeclare() {
  list syms = NULL;

if (globalTrace)
    printf("javaTypesNoDeclare at q/java.qon:277 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaTypesNoDeclare", "277" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:279");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  syms = cons(boxString("pair"), cons(boxString("box"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:284");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return syms;;

}


box javaFuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("javaFuncMap at q/java.qon:286 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaFuncMap", "286" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:288");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:290");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("printf"), boxSymbol("System.out.printf"), alistCons(boxSymbol(stringConcatenate("q", "log")), boxSymbol("System.err.printf"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("null"), NULL)))))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:302");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:303");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cdr(assoc(stringify(aSym), symMap));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:304");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return aSym;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:305");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


void javaType(list node) {
  
if (globalTrace)
    printf("javaType at q/java.qon:307 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaType", "307" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:309");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(subnameof(node), boxString("struct"))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:311");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\npublic class %s {\n", stringify(first(codeof(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:312");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\npublic String caller =\"\";");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:314");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaStruct(cdr(codeof(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:315");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n};\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:317");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(boxString(stringify(first(codeof(node)))), javaTypesNoDeclare())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:318");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:320");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("public class %s extends %s {};\n", stringify(first(codeof(node))), stringify(javaTypeMap(listLast(codeof(node)))));

    };

  };

}


void javaTypes(list nodes) {
  
if (globalTrace)
    printf("javaTypes at q/java.qon:324 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaTypes", "324" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:326");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:327");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:328");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaType(car(nodes));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:328");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaTypes(cdr(nodes));

  };

}


void javaCompile(char* filename) {
  char* programStr = "";
list tree = NULL;
list program = NULL;

if (globalTrace)
    printf("javaCompile at q/java.qon:330 (%s)\n", caller);

  StackTraceMove("in", "q/java.qon", "javaCompile", "330" );

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:332");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "package quonverter;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:333");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "import java.nio.file.Files;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:334");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "import java.nio.file.Paths;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:335");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "import java.io.IOException;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:336");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "import java.io.UnsupportedEncodingException;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:337");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("class MyProgram {\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:338");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\npublic String caller =\"\";");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:339");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:340");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:341");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:351");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = mergeIncludes(program);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:352");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaIncludes(cdr(assoc("includes", program)));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:353");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaTypes(childrenof(cdr(assoc("types", program))));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:354");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public boolean globalStackTrace = false;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:355");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public boolean globalStepTrace = false;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:356");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public boolean globalTrace = false;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:357");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public boolean releaseMode = false;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:358");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public String FILE = null;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:359");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public Integer LINE = 0;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:360");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public static Integer globalArgsCount = 0;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:361");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public static String globalArgs[];\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:362");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\npublic boolean isNil(Box p) {\n    return p == null;\n}\n\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:364");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:366");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public static void main(String args[]) {\nglobalArgs = args;\nglobalArgsCount = args.length;MyProgram mp = new MyProgram(); mp.start();\n}");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:367");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("}\n");

}


list node2FunctionArgs(list tree) {
  list out = NULL;

if (globalTrace)
    printf("node2FunctionArgs at q/node2.qon:4 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2FunctionArgs", "4" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:7");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  out = NULL;

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:8");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:9");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:11");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(stringify(first(tree)), "...")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:12");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      out = cons(id(out), cons(boxString("..."), NULL));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:14");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      out = cons(boxString(" "), cons(id(second(tree)), NULL));

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:16");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree))) {
    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:16");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      out = cons(id(out), cons(boxString(", "), NULL));

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:17");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(out), cons(id(node2FunctionArgs(cddr(tree))), NULL));;

  };

}


list node2Expression(list tree, int indent) {
  list thing = NULL;

if (globalTrace)
    printf("node2Expression at q/node2.qon:21 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Expression", "21" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:23");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:27");
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

        return boxString("return");;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:35");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(car(tree)), cons(boxString("()"), NULL));;

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:38");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      thing = first(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:39");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxSymbol("get-struct"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:42");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(id(second(tree)), cons(id(boxString(".")), cons(id(third(tree)), NULL)));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:47");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxSymbol("new"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:50");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return cons(id(boxString("new")), cons(id(third(tree)), NULL));;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:54");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("passthrough"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:57");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return second(tree);;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:59");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("binop"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:62");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return cons(id(boxString("(1")), cons(id(node2Expression(third(tree), indent)), cons(id(boxString(" ")), cons(id(second(tree)), cons(id(boxString(" ")), cons(id(node2Expression(fourth(tree), indent)), cons(id(boxString(")")), NULL)))))));;

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:74");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return cons(id(node2FuncMap(car(tree))), cons(id(boxString("(2")), cons(id(node2RecurList(cdr(tree), indent)), cons(id(boxString(")")), NULL))));;

            };

          };

        };

      };

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:83");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return node2FuncMap(tree);;

  };

}


list node2RecurList(list expr, int indent) {
  
if (globalTrace)
    printf("node2RecurList at q/node2.qon:85 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2RecurList", "85" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:88");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:89");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return boxString("");;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:91");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return node2Expression(car(expr), indent);;

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:92");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:93");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      boxString("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:95");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(id(boxString(", ")), cons(id(node2RecurList(cdr(expr), indent)), NULL));;

    };

  };

}


list node2If(list node, int indent, char* functionName) {
  
if (globalTrace)
    printf("node2If at q/node2.qon:103 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2If", "103" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:105");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(id(boxString("if (4 ")), cons(id(boxString(stringify(node2Expression(second(node), 0)))), cons(id(boxString(") {")), cons(id(node2Body(cdr(third(node)), add1(indent), functionName)), cons(id(listNewLine(indent)), cons(id(boxString("} else {")), cons(id(node2Body(cdr(fourth(node)), add1(indent), functionName)), cons(id(listNewLine(indent)), cons(id(boxString("}")), NULL))))))))));;

}


list node2SetStruct(list node, int indent) {
  
if (globalTrace)
    printf("node2SetStruct at q/node2.qon:117 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2SetStruct", "117" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:119");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(id(boxString(stringify(second(node)))), cons(id(boxString(".")), cons(id(boxString(stringify(third(node)))), cons(id(boxString(" = ")), cons(id(boxString(stringify(node2Expression(fourth(node), indent)))), NULL))))));;

}


list node2GetStruct(list node, int indent) {
  
if (globalTrace)
    printf("node2GetStruct at q/node2.qon:127 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2GetStruct", "127" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:129");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(id(boxString(stringify(first(node)))), cons(id(boxString(".")), cons(id(boxString(stringify(second(node)))), NULL))));;

}


list node2Set(list node, int indent) {
  
if (globalTrace)
    printf("node2Set at q/node2.qon:135 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Set", "135" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:137");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(listNewLine(indent)), cons(id(boxString(stringify(node2Expression(first(cdr(node)), indent)))), cons(id(boxString(" = ")), cons(id(boxString(stringify(node2Expression(third(node), indent)))), NULL))));;

}


list node2Return(list node, int indent) {
  
if (globalTrace)
    printf("node2Return at q/node2.qon:143 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Return", "143" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:145");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(listLength(node), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:146");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(listNewLine(indent)), cons(id(boxString("return;")), NULL));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:148");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(listNewLine(indent)), cons(id(boxString("return ")), cons(id(node2Expression(cadr(node), indent)), cons(id(boxString(";")), NULL))));;

  };

}


list node2Statement(list node, int indent, char* functionname) {
  list out = NULL;

if (globalTrace)
    printf("node2Statement at q/node2.qon:153 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Statement", "153" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:155");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  out = NULL;

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:156");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("set"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:157");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    out = node2Set(node, indent);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:159");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("set-struct"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:160");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      out = node2SetStruct(node, indent);

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:162");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:163");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        out = node2If(node, indent, functionname);

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:165");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("return"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:167");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( inList(boxString(functionname), NoStackTrace_list())) {
          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:170");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            out = cons(id(boxString("\n")), cons(id(listIndent(indent)), cons(id(boxString("StackTraceMove(\"out\", \"\", \"\", \"\");\n")), NULL)));

          };

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:174");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          out = cons(id(out), cons(id(node2Return(node, indent)), NULL));

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:176");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          out = cons(id(listNewLine(indent)), cons(id(boxString(stringify(node2Expression(node, indent)))), NULL));

        };

      };

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:179");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  out = cons(id(out), cons(id(boxString(";\n")), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:180");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return out;;

}


list node2Body(list tree, int indent, char* functionName) {
  list code = NULL;
list out = NULL;

if (globalTrace)
    printf("node2Body at q/node2.qon:182 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Body", "182" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:184");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  out = NULL;

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:185");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:186");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:188");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    code = tree;

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:189");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(code)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:190");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return NULL;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:192");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      code = car(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:193");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( notBool(releaseMode)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:195");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( inList(boxString(functionName), NoTrace_list())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:197");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          out = cons(id(out), cons(id(boxString("//Function ")), cons(id(boxString(functionName)), cons(id(boxString(" omitted due to the no trace list\n")), NULL))));

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:202");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          out = cons(id(out), cons(id(boxString("\nif (globalTrace)\n    snprintf(caller, 1024, \"from:%s:%s\", ")), cons(id(boxString(stringify(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))))), cons(id(boxString(stringify(getTagFail(car(code), boxString("line"), boxString("Line missing"))))), NULL))));

        };

      } else {
      };

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:208");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( notBool(releaseMode)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:210");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      out = cons(id(out), cons(id(listIndent(indent)), cons(id(boxString("if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n")), NULL)));

    } else {
    };

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:215");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(out), cons(id(node2Statement(code, indent, functionName)), cons(id(node2Body(cdr(tree), indent, functionName)), NULL)));;

  };

}


list node2eclarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("node2eclarations at q/node2.qon:219 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2eclarations", "219" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:221");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:222");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:224");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:225");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(boxString("var ")), cons(id(boxString(stringify(node2TypeMap(first(decl))))), cons(id(boxString(" ")), cons(id(boxString(stringify(second(decl)))), cons(id(boxString(" = ")), cons(id(node2Expression(third(decl), indent)), cons(id(boxString(";\n")), cons(id(node2eclarations(cdr(decls), indent)), NULL))))))));;

  };

}


list node2Function(list node) {
  box name = NULL;

if (globalTrace)
    printf("node2Function at q/node2.qon:235 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Function", "235" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:238");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = second(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:240");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:241");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:242");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:244");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(listNewLine(0)), cons(id(boxString("function")), cons(id(boxString(" ")), cons(id(boxString(stringify(second(node)))), cons(id(boxString("(3")), cons(id(node2FunctionArgs(third(node))), cons(id(boxString(") {")), cons(id(listNewLine(1)), cons(id(node2eclarations(cdr(fourth(node)), 1)), cons(id(node2Body(cdr(fifth(node)), 1, stringify(name))), cons(id(boxString("\n}\n")), NULL)))))))))));;

  };

}


list node2Functions(list tree) {
  
if (globalTrace)
    printf("node2Functions at q/node2.qon:264 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Functions", "264" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:266");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:267");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:269");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(node2Function(car(tree))), cons(id(node2Functions(cdr(tree))), NULL));;

  };

}


list node2Includes(list nodes) {
  
if (globalTrace)
    printf("node2Includes at q/node2.qon:274 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Includes", "274" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:276");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return NULL;;

}


list node2TypeDecl(list l) {
  
if (globalTrace)
    printf("node2TypeDecl at q/node2.qon:278 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2TypeDecl", "278" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:280");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return NULL;;

}


list node2StructComponents(list node) {
  
if (globalTrace)
    printf("node2StructComponents at q/node2.qon:282 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2StructComponents", "282" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:284");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:285");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:286");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(node2TypeDecl(car(node))), cons(id(node2StructComponents(cdr(node))), NULL));;

  };

}


void node2Struct(list node) {
  
if (globalTrace)
    printf("node2Struct at q/node2.qon:288 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Struct", "288" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:289");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  node2StructComponents(cdr(node));

}


box node2TypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("node2TypeMap at q/node2.qon:291 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2TypeMap", "291" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:293");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:297");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:298");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:299");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


box node2FuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("node2FuncMap at q/node2.qon:301 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2FuncMap", "301" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:303");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:305");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), NULL)))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:327");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:328");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cdr(assoc(stringify(aSym), symMap));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:329");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return aSym;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:330");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


list node2Type(list node) {
  
if (globalTrace)
    printf("node2Type at q/node2.qon:332 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Type", "332" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:334");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return NULL;;

}


list node2Types(list nodes) {
  
if (globalTrace)
    printf("node2Types at q/node2.qon:337 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Types", "337" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:339");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:340");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:341");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(id(node2Type(car(nodes))), cons(id(node2Types(cdr(nodes))), NULL));;

  };

}


void node2Compile(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    printf("node2Compile at q/node2.qon:347 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Compile", "347" );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Scanning file...%s\n", filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:354");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Building sexpr\n");

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Loading shim node2\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:358");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = buildProg(cons(boxString("q/shims/node2.qon"), getIncludes(tree)), getTypes(tree), getFunctions(tree));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Loading all includes\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:360");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Applying macros\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:362");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:363");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:364");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Printing program\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:369");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", stringify(flatten(node2Includes(cdr(first(tree))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:370");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", stringify(flatten(node2Types(cdr(second(tree))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:371");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", stringify(flatten(node2Functions(cdr(third(tree))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:372");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n");

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Done printing program\n");

}


void nodeFunctionArgs(list tree) {
  
if (globalTrace)
    printf("nodeFunctionArgs at q/node.qon:4 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeFunctionArgs", "4" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:6");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:7");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:9");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(second(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:10");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:10");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:10");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(",");

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:11");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeFunctionArgs(cddr(tree));

  };

}


void nodeLeaf(list thisNode, int indent) {
  
if (globalTrace)
    printf("nodeLeaf at q/node.qon:13 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeLeaf", "13" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:14");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  display(nodeFuncMap(codeof(thisNode)));

}


void nodeStructGetterExpression(list thisNode, int indent) {
  
if (globalTrace)
    printf("nodeStructGetterExpression at q/node.qon:16 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeStructGetterExpression", "16" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:18");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("structGetter"), subnameof(thisNode))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:19");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeGetStruct(thisNode, indent);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:20");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeLeaf(thisNode, indent);

  };

}


void nodeExpression(list tree, int indent) {
  list thing = NULL;

if (globalTrace)
    printf("nodeExpression at q/node.qon:23 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeExpression", "23" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:25");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:29");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equal(1, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:33");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:35");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("return"), car(tree))) {
      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:39");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("()");

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:42");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      thing = first(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:43");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxSymbol("get-struct"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:46");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s->%s", stringify(second(tree)), stringify(third(tree)));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:51");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxSymbol("new"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:54");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("malloc(sizeof(%s))", stringify(third(tree)));

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:58");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("passthrough"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:61");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s", stringify(second(tree)));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:65");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("binop"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:68");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("(");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:69");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              nodeExpression(third(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:70");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(" %s ", stringify(second(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:73");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              nodeExpression(fourth(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:74");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:78");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s(", stringify(nodeFuncMap(car(tree))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:82");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              nodeRecurList(cdr(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:83");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            };

          };

        };

      };

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:91");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(nodeFuncMap(tree));

  };

}


void nodeRecurList(list expr, int indent) {
  
if (globalTrace)
    printf("nodeRecurList at q/node.qon:96 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeRecurList", "96" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:100");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:101");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:103");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeExpression(car(expr), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:104");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:105");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:106");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(", ");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:106");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      nodeRecurList(cdr(expr), indent);

    };

  };

}


void nodeIf(list node, int indent) {
  
if (globalTrace)
    printf("nodeIf at q/node.qon:111 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeIf", "111" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:113");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:114");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("if ( ");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:115");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeExpression(car(first(childrenof(node))), 0);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:116");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(") {");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:117");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeBody(second(childrenof(node)), add1(indent));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:118");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:119");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("} else {");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:120");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeBody(third(childrenof(node)), add1(indent));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:121");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:122");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("}");

}


void nodeGetStruct(list node, int indent) {
  
if (globalTrace)
    printf("nodeGetStruct at q/node.qon:125 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeGetStruct", "125" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:127");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:128");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s.%s", stringify(first(codeof(node))), stringify(second(codeof(node))));

}


void nodeSet(list node, int indent) {
  
if (globalTrace)
    printf("nodeSet at q/node.qon:133 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeSet", "133" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:135");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:136");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s = ", stringify(first(codeof(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:137");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeExpression(childrenof(node), indent);

}


void nodeSetStruct(list node, int indent) {
  
if (globalTrace)
    printf("nodeSetStruct at q/node.qon:139 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeSetStruct", "139" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:141");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:142");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s.%s = ", stringify(first(codeof(node))), stringify(second(codeof(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:143");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeExpression(childrenof(node), indent);

}


void nodeStatement(list node, int indent) {
  
if (globalTrace)
    printf("nodeStatement at q/node.qon:147 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeStatement", "147" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:149");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("setter"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:150");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeSet(node, indent);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:152");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("structSetter"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:153");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      nodeSetStruct(node, indent);

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:155");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:156");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        nodeIf(node, indent);

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:158");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("returnvoid"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:159");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:159");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("return");

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:161");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:162");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          nodeExpression(childrenof(node), indent);

        };

      };

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:163");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(";\n");

}


void nodeBody(list tree, int indent) {
  
if (globalTrace)
    printf("nodeBody at q/node.qon:166 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeBody", "166" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:170");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:171");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:173");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:174");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s", "if (globalStepTrace) {console.log(new Error(\"StepTrace \\n\"));}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:177");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeStatement(car(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:178");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeBody(cdr(tree), indent);

  };

}


void nodeDeclarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("nodeDeclarations at q/node.qon:180 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeDeclarations", "180" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:182");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:183");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:185");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:186");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("var %s = ", stringify(second(decl)));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:189");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeExpression(cons(id(third(decl)), NULL), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:190");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:191");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeDeclarations(cdr(decls), indent);

  };

}


void nodeFunction(list node) {
  box name = NULL;

if (globalTrace)
    printf("nodeFunction at q/node.qon:195 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeFunction", "195" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:197");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = subnameof(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:198");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:199");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:200");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:201");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:203");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:204");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("function %s(", stringify(subnameof(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:207");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeFunctionArgs(cdr(assoc("intype", cdr(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:208");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(") {");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:209");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:210");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeDeclarations(declarationsof(node), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:211");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:212");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:214");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    {printf(\"%s at %s:%s\\n\");}\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:215");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:216");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
    };

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:220");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeBody(childrenof(node), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:221");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:222");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:224");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    {printf(\"Leaving %s\\n\");}\n", stringify(name));

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:226");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n");

  };

}


void nodeForwardDeclaration(list node) {
  
if (globalTrace)
    printf("nodeForwardDeclaration at q/node.qon:228 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeForwardDeclaration", "228" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:230");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:231");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:233");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n%s %s(", stringify(nodeTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:237");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeFunctionArgs(cdr(assoc("intype", cdr(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:238");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(");");

  };

}


void nodeForwardDeclarations(list tree) {
  
if (globalTrace)
    printf("nodeForwardDeclarations at q/node.qon:240 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeForwardDeclarations", "240" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:244");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:245");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:247");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeForwardDeclaration(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:248");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeForwardDeclarations(cdr(tree));

  };

}


void nodeFunctions(list tree) {
  
if (globalTrace)
    printf("nodeFunctions at q/node.qon:250 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeFunctions", "250" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:254");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:255");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:256");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeFunction(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:256");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeFunctions(cdr(tree));

  };

}


void nodeIncludes(list nodes) {
  
if (globalTrace)
    printf("nodeIncludes at q/node.qon:258 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeIncludes", "258" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:260");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function read_file(filename) {return fs.readFileSync(filename);}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:261");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function write_file(filename, data) {fs.writeFileSync(filename, data);}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:262");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "var util = require('util');\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:263");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function printf() {process.stdout.write(util.format.apply(this, arguments));}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:264");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function qlog()   {process.stderr.write(util.format.apply(this, arguments));}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:265");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "var fs = require('fs');\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:266");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function equalString(a,b) {if (a==null) {return false;}if (b==null) {return false;}return a.toString()===b.toString() }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:267");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function panic(s){console.trace(s);process.exit(1);}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:268");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function dump(s){console.log(s)}");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:269");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function sub(a, b) { return a - b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:270");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function mult(a, b) { return a * b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:271");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function greaterthan(a, b) { return a > b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:272");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function subf(a, b) { return a - b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:273");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function multf(a, b) { return a * b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:274");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function greaterthanf(a, b) { return a > b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:275");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function equal(a, b) { return a == b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:276");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function andBool(a, b) { return a == b;}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:277");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function string_length(s) { return s.length;}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:278");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function sub_string(str, start, len) {str = ''+str;return str.substring(start, start+len)};\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:279");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function stringConcatenate(a, b) { return a + b}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:280");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function intToString(a) {}\n\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:281");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function gc_malloc( size ) {\nreturn {};\n}\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:282");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function makeArray(length) {\n   return [];\n}\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:283");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function at(arr, index) {\n  return arr[index];\n}\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:284");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function setAt(array, index, value) {\n    array[index] = value;\n}\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:285");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function getStringArray(index, strs) {\nreturn strs[index];\n}\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:286");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "var NULL = null;");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:287");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "var globalArgs;\nvar globalArgsCount;\nvar globalTrace = false;\nvar globalStepTrace = false;\nvar releaseMode = false;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:288");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function character(num) {}");

}


void nodeTypeDecl(list l) {
  
if (globalTrace)
    printf("nodeTypeDecl at q/node.qon:292 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeTypeDecl", "292" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:294");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:296");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:297");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s %s;\n", stringify(second(l)), stringify(nodeTypeMap(listLast(l))), stringify(first(l)));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:303");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:304");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s;\n", stringify(nodeTypeMap(listLast(l))), stringify(car(l)));

  };

}


void nodeStructComponents(list node) {
  
if (globalTrace)
    printf("nodeStructComponents at q/node.qon:309 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeStructComponents", "309" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:313");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:314");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:315");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeTypeDecl(car(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:315");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeStructComponents(cdr(node));

  };

}


void nodeStruct(list node) {
  
if (globalTrace)
    printf("nodeStruct at q/node.qon:317 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeStruct", "317" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:320");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeStructComponents(cdr(car(node)));

}


box nodeTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("nodeTypeMap at q/node.qon:322 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeTypeMap", "322" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:326");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:332");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:333");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:334");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


box nodeFuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("nodeFuncMap at q/node.qon:337 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeFuncMap", "337" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:340");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:342");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), NULL)))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:364");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:365");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cdr(assoc(stringify(aSym), symMap));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:366");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return aSym;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:367");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


void nodeType(list node) {
  
if (globalTrace)
    printf("nodeType at q/node.qon:368 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeType", "368" );

}


void nodeTypes(list nodes) {
  
if (globalTrace)
    printf("nodeTypes at q/node.qon:372 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeTypes", "372" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:376");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:377");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:378");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeType(car(nodes));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:378");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeTypes(cdr(nodes));

  };

}


void nodeCompile(char* filename) {
  char* programStr = "";
list tree = NULL;
list program = NULL;

if (globalTrace)
    printf("nodeCompile at q/node.qon:380 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeCompile", "380" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:384");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:385");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:386");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:395");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = mergeIncludes(program);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:396");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeIncludes(cdr(assoc("includes", program)));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:397");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeTypes(childrenof(cdr(assoc("types", program))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:398");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nvar globalStackTrace = NULL;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:399");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nvar caller = \"\";\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:400");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nfunction isNil(p) {\n    return p == NULL;\n}\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:401");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:403");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:404");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("const [asfdasdf, ...qwerqwer] = process.argv;");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:405");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("globalArgs = qwerqwer;");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:406");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("globalArgsCount = qwerqwer.length;");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:407");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "start();\n");

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
char* contents = "";

if (globalTrace)
    printf("test13 at q/tests.qon:188 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test13", "188" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:194");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  write_file("test.txt", testString);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:195");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  contents = read_file("test.txt");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:196");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(testString, contents)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:197");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("13. pass Read and write files\n");

  } else {
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

    printf("Got: %s\n", contents);

  };

}


void test15() {
  char* a = "hello";
char* b = " world";
char* c = "";

if (globalTrace)
    printf("test15 at q/tests.qon:204 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test15", "204" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:207");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  c = stringConcatenate(a, b);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:208");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(c, "hello world")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:209");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("15. pass String concatenate\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:210");
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
    printf("test16 at q/tests.qon:212 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test16", "212" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:219");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assocCell1 = cons(boxString("Hello"), boxString("world"));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:220");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assocCell2 = cons(boxString("goodnight"), boxString("moon"));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:221");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assocCell3 = cons(boxSymbol("ohio"), boxString("gozaimasu"));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:222");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assList = cons(assocCell2, emptyList());

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:223");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assList = cons(assocCell1, assList);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:224");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assList = cons(assocCell3, assList);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:225");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(cdr(assoc("Hello", assList)), boxString("world"))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:226");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("16.1 pass Basic assoc works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:227");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("16.1 fail Basic assoc fails\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:228");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( andBool(andBool(equalBox(cdr(assoc("Hello", assList)), boxString("world")), equalBox(cdr(assoc("goodnight", assList)), boxString("moon"))), equalBox(cdr(assoc("ohio", assList)), boxString("gozaimasu")))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:233");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("16.2 pass assoc list\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:234");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("16.2 fail assoc list\n");

  };

}


void test17() {
  list l = NULL;

if (globalTrace)
    printf("test17 at q/tests.qon:236 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test17", "236" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:238");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxInt(1), cons(boxInt(2), cons(boxInt(3), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:239");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(car(l), boxInt(1))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:240");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("17. pass list literal works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:241");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("17. fail list literal failed\n");

  };

}


void test18() {
  char* val1 = "a";
char* val2 = "b";
list l = NULL;

if (globalTrace)
    printf("test18 at q/tests.qon:247 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test18", "247" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:253");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:254");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(l, cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), NULL))))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:255");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("18. pass string list constructor works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:256");
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
    printf("test19 at q/tests.qon:261 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test19", "261" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:270");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:271");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  answer = cons(boxString("c"), cons(boxString(val2), cons(boxString(val1), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:272");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  revlist = reverseList(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:273");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(answer, revlist)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:274");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("19. pass reverseList\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:275");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("19. fail reverseList\n");

  };

}


list concatenateLists(list oldL, list newL) {
  
if (globalTrace)
    printf("concatenateLists at q/tests.qon:279 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "concatenateLists", "279" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:281");
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
    printf("test20 at q/tests.qon:284 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test20", "284" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:294");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:295");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l2 = cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:296");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l3 = cons(boxString(val1), cons(boxString(val2), cons(boxString(val3), cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), NULL))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:297");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  combined = concatenateLists(l, l2);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:298");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(l3, combined)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:299");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("21. pass concatenateLists\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:300");
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
    printf("test21 at q/tests.qon:304 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test21", "304" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:312");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString(val3), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:313");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l2 = cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:314");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(l, l2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:315");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("21. pass equalList\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:316");
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
    printf("test22 at q/tests.qon:320 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test22", "320" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:327");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:328");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxString("fprintf"), cons(boxString("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:329");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  out = macrolist(original, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:331");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  correct = cons(boxString("fprintf"), cons(boxString("stderr"), cons(boxString("%s"), cons(boxString("hello"), NULL))));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:332");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(out, correct)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:333");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("22. pass macroList\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:334");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("22. fail macroList\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:335");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("In: ");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:336");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    displayList(original, 0, true);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:337");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\nOut: ");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:338");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    displayList(out, 0, true);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:339");
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
    printf("test23 at q/tests.qon:343 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test23", "343" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:350");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:351");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxString("fprintf"), cons(boxString("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:352");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  out = concatLists(original, replace);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:354");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  correct = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), cons(boxString("fprintf"), cons(boxString("stderr"), NULL)))));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:355");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(out, correct)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:356");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("23. pass concatLists\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:357");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("23. fail concatLists\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:358");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("In: ");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:359");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    displayList(original, 0, true);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:360");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\nOut: ");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:361");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    displayList(out, 0, true);

  };

}


void test24() {
  char* expected = "a b c";
char* res = "";

if (globalTrace)
    printf("test24 at q/tests.qon:366 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test24", "366" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:372");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  res = StringListJoin(cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), NULL))), " ");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:373");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(expected, res)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:374");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("24. pass StringListJoin\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:375");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("24. fail StringListJoin.  expected '%s', got '%s'\n", expected, res);

  };

}


void test25() {
  char* expected = "( a b ) c d e";
char* res = "";
list testsubstr = cons(boxString("c "), cons(boxString("d "), cons(boxString("e"), NULL)));
list input = NULL;

if (globalTrace)
    printf("test25 at q/tests.qon:380 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test25", "380" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:388");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  input = cons(boxString("a "), cons(boxString("b "), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:389");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  input = cons(input, testsubstr);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:390");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  res = ListToString(input, 0, true, false);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:391");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(expected, res)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:392");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("25. pass ListToString\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:393");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("25. fail ListToString.  expected '%s', got '%s'\n", expected, res);

  };

}


void test27() {
  char* expected = "a b c d e";
char* res = "";
list variable = cons(boxString("c "), cons(boxString("d "), NULL));
list input = NULL;

if (globalTrace)
    printf("test27 at q/tests.qon:416 (%s)\n", caller);

  StackTraceMove("in", "q/tests.qon", "test27", "416" );

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:424");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  input = cons(boxString("a "), cons(boxString("b "), cons(id(variable), cons(boxString("e"), NULL))));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:425");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  res = ListToString(flatten(input), 0, true, false);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:426");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(expected, res)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:427");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("27. pass Interpolated List\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:428");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("27. fail Interpolated List.  expected '%s', got '%s'\n", expected, res);

  };

}


void ansi3displays(char* s) {
  
if (globalTrace)
    printf("ansi3displays at q/ansi3.qon:5 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3displays", "5" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:7");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", s);

}


void ansi3FunctionArgs(list tree) {
  
if (globalTrace)
    printf("ansi3FunctionArgs at q/ansi3.qon:11 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3FunctionArgs", "11" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:13");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:14");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:16");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(stringify(first(tree)), "...")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:17");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("...");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:19");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(ansi3TypeMap(first(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:20");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi3displays(" ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:21");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(second(tree));

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:23");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree))) {
    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:23");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi3displays(", ");

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:24");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3FunctionArgs(cddr(tree));

  };

}


void ansi3Expression(list tree, int indent) {
  list thing = NULL;

if (globalTrace)
    printf("ansi3Expression at q/ansi3.qon:28 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Expression", "28" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:30");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:34");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equal(1, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:38");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:40");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("return"), car(tree))) {
      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:44");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        ansi3displays("()");

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:47");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      thing = first(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:48");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxSymbol("get-struct"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:51");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s->%s", stringify(second(tree)), stringify(third(tree)));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:56");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxSymbol("new"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:59");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("malloc(sizeof(%s))", stringify(third(tree)));

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:63");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("passthrough"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:66");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s", stringify(second(tree)));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:70");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("binop"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:73");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("(");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:74");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              ansi3Expression(third(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:75");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(" %s ", stringify(second(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:78");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              ansi3Expression(fourth(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:79");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:83");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s(", stringify(ansi3FuncMap(car(tree))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:87");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              ansi3RecurList(cdr(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:88");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            };

          };

        };

      };

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:96");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(ansi3FuncMap(tree));

  };

}


void ansi3RecurList(list expr, int indent) {
  
if (globalTrace)
    printf("ansi3RecurList at q/ansi3.qon:99 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3RecurList", "99" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:103");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:104");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:106");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Expression(car(expr), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:107");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:108");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi3displays("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:109");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi3displays(", ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:109");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi3RecurList(cdr(expr), indent);

    };

  };

}


void ansi3If(list node, int indent, char* functionName) {
  
if (globalTrace)
    printf("ansi3If at q/ansi3.qon:116 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3If", "116" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:118");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:119");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("if ( ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:120");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Expression(second(node), 0);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:121");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays(") {");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:122");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Body(cdr(third(node)), add1(indent), functionName);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:123");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:124");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("} else {");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:125");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Body(cdr(fourth(node)), add1(indent), functionName);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:126");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:127");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("}");

}


void ansi3SetStruct(list node, int indent) {
  
if (globalTrace)
    printf("ansi3SetStruct at q/ansi3.qon:129 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3SetStruct", "129" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:131");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:132");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->%s = ", stringify(second(node)), stringify(third(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:136");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Expression(fourth(node), indent);

}


void ansi3GetStruct(list node, int indent) {
  
if (globalTrace)
    printf("ansi3GetStruct at q/ansi3.qon:138 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3GetStruct", "138" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:140");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:141");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->%s", stringify(first(node)), stringify(second(node)));

}


void ansi3Set(list node, int indent) {
  
if (globalTrace)
    printf("ansi3Set at q/ansi3.qon:146 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Set", "146" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:148");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:149");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Expression(first(cdr(node)), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:150");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(" = ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:151");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Expression(third(node), indent);

}


void ansi3Return(list node, int indent) {
  
if (globalTrace)
    printf("ansi3Return at q/ansi3.qon:153 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Return", "153" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:158");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:159");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(listLength(node), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:160");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3displays("return;");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:162");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3displays("return ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:163");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Expression(cadr(node), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:164");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3displays(";");

  };

}


void ansi3Statement(list node, int indent, char* functionname) {
  
if (globalTrace)
    printf("ansi3Statement at q/ansi3.qon:167 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Statement", "167" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:169");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("set"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:170");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Set(node, indent);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:172");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("set-struct"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:173");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi3SetStruct(node, indent);

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:175");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:176");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        ansi3If(node, indent, functionname);

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:178");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("return"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:180");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( inList(boxString(functionname), NoStackTrace_list())) {
          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:183");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:184");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:185");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s", "StackTraceMove(\"out\", \"\", \"\", \"\");\n");

          };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:186");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          ansi3Return(node, indent);

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:188");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:189");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          ansi3Expression(node, indent);

        };

      };

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:190");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays(";\n");

}


void ansi3Body(list tree, int indent, char* functionName) {
  list code = NULL;

if (globalTrace)
    printf("ansi3Body at q/ansi3.qon:192 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Body", "192" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:194");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:195");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:197");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    code = tree;

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:198");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(code)) {
    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:201");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      code = car(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:202");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( notBool(releaseMode)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:205");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( inList(boxString(functionName), NoTrace_list())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:207");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("//Function %s omitted due to the no trace list\n", functionName);

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:208");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("\nif (globalTrace)\n    snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), stringify(getTagFail(car(code), boxString("line"), boxString("Line missing"))));

        };

      } else {
      };

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:213");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( notBool(releaseMode)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:214");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:215");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n");

    } else {
    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:218");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Statement(code, indent, functionName);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:219");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Body(cdr(tree), indent, functionName);

  };

}


void ansi3Declarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("ansi3Declarations at q/ansi3.qon:221 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Declarations", "221" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:223");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:224");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:226");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:227");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s = ", stringify(ansi3TypeMap(first(decl))), stringify(second(decl)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:231");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Expression(third(decl), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:232");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:233");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Declarations(cdr(decls), indent);

  };

}


void ansi3Function(list node) {
  box name = NULL;

if (globalTrace)
    printf("ansi3Function at q/ansi3.qon:235 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Function", "235" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:237");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = second(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:239");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:240");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:241");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:243");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:244");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s(", stringify(ansi3TypeMap(first(node))), stringify(second(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:248");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3FunctionArgs(third(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:249");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(") {");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:250");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:251");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Declarations(cdr(fourth(node)), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:252");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:253");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:256");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( inList(name, NoTrace_list())) {
      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:261");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("\nif (globalTrace)\n    printf(\"%s at %s:%s (%%s)\\n\", caller);\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

      };

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:262");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:263");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:265");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( inList(name, NoStackTrace_list())) {
      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:268");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("\n  StackTraceMove(\"in\", \"%s\", \"%s\", \"%s\" );\n", stringify(getTag(name, boxString("filename"))), stringify(name), stringify(getTag(name, boxString("line"))));

      };

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:271");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Body(cdr(fifth(node)), 1, stringify(name));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:273");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n");

  };

}


void ansi3ForwardDeclaration(list node) {
  
if (globalTrace)
    printf("ansi3ForwardDeclaration at q/ansi3.qon:275 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3ForwardDeclaration", "275" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:277");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:277");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:278");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n%s %s(", stringify(ansi3TypeMap(first(node))), stringify(second(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:282");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3FunctionArgs(third(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:283");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3displays(");");

  };

}


void ansi3ForwardDeclarations(list tree) {
  
if (globalTrace)
    printf("ansi3ForwardDeclarations at q/ansi3.qon:285 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3ForwardDeclarations", "285" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:287");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:287");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:288");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3ForwardDeclaration(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:289");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3ForwardDeclarations(cdr(tree));

  };

}


void ansi3Functions(list tree) {
  
if (globalTrace)
    printf("ansi3Functions at q/ansi3.qon:291 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Functions", "291" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:293");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:293");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:294");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Function(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:294");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Functions(cdr(tree));

  };

}


void ansi3Includes(list nodes) {
  
if (globalTrace)
    printf("ansi3Includes at q/ansi3.qon:297 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Includes", "297" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:299");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\n#include <unistd.h>\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\nbool releaseMode = false;\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:302");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n");

}


void ansi3TypeDecl(list l) {
  
if (globalTrace)
    printf("ansi3TypeDecl at q/ansi3.qon:305 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3TypeDecl", "305" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:307");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:309");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:310");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s %s;\n", stringify(second(l)), stringify(ansi3TypeMap(listLast(l))), stringify(first(l)));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:316");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:317");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s;\n", stringify(ansi3TypeMap(listLast(l))), stringify(car(l)));

  };

}


void ansi3StructComponents(list node) {
  
if (globalTrace)
    printf("ansi3StructComponents at q/ansi3.qon:322 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3StructComponents", "322" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:324");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:325");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:326");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3TypeDecl(car(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:326");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3StructComponents(cdr(node));

  };

}


void ansi3Struct(list node) {
  
if (globalTrace)
    printf("ansi3Struct at q/ansi3.qon:328 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Struct", "328" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:329");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3StructComponents(cdr(node));

}


box ansi3TypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("ansi3TypeMap at q/ansi3.qon:331 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3TypeMap", "331" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:333");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:337");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:338");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:339");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


box ansi3FuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("ansi3FuncMap at q/ansi3.qon:341 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3FuncMap", "341" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:343");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:345");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), NULL)))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:367");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:368");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cdr(assoc(stringify(aSym), symMap));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:369");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return aSym;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:370");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


void ansi3Type(list node) {
  
if (globalTrace)
    printf("ansi3Type at q/ansi3.qon:372 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Type", "372" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:374");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(second(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:376");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\ntypedef struct %s {\n", stringify(first(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:377");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Struct(second(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:378");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n} %s;\n", stringify(first(node)));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:379");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3displays("typedef ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:379");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3TypeDecl(node);

  };

}


void ansi3Types(list nodes) {
  
if (globalTrace)
    printf("ansi3Types at q/ansi3.qon:382 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Types", "382" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:384");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:385");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:386");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Type(car(nodes));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:386");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Types(cdr(nodes));

  };

}


void ansi3Compile(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    printf("ansi3Compile at q/ansi3.qon:392 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Compile", "392" );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Scanning file...%s\n", filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:399");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Building sexpr\n");

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Loading shim ansi3\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:403");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = buildProg(cons(boxString("q/shims/ansi3.qon"), getIncludes(tree)), getTypes(tree), getFunctions(tree));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Loading all includes\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:405");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Applying macros\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:407");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:408");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:409");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Printing program\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:415");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Includes(cdr(first(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:416");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Types(cdr(second(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:418");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("Box* globalStackTrace = NULL;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:419");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:421");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3ForwardDeclarations(cdr(third(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:422");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("\n\n//End forward declarations\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:423");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Functions(cdr(third(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:424");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("\n");

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

  return "$";;

}


char* escapeSingleQuotes(char* s) {
  
if (globalTrace)
    printf("escapeSingleQuotes at q/perl.qon:8 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "escapeSingleQuotes", "8" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:10");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return stringReplace("'", "\\'", s);;

}


list getGlobalVariables() {
  
if (globalTrace)
    printf("getGlobalVariables at q/perl.qon:12 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "getGlobalVariables", "12" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:14");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(boxSymbol("stderr")), cons(id(boxSymbol("true")), cons(id(boxSymbol("false")), cons(id(boxSymbol("releaseMode")), cons(id(boxSymbol("caller")), cons(id(boxSymbol("globalTrace")), cons(id(boxSymbol("globalArgsCount")), cons(id(boxSymbol("globalArgs")), cons(id(boxSymbol("quonGlobalArgs")), NULL)))))))));;

}


list collectVariables(list args, list decls) {
  list variables = NULL;
box decl = NULL;

if (globalTrace)
    printf("collectVariables at q/perl.qon:16 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "collectVariables", "16" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:18");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  variables = collectVariablesFromArgs(args);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:19");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  variables = appendVariables(variables, collectVariablesFromDecls(decls));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:20");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  variables = appendVariables(variables, getGlobalVariables());

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:21");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return variables;;

}


void perlGlobalVariables() {
  
if (globalTrace)
    printf("perlGlobalVariables at q/perl.qon:23 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlGlobalVariables", "23" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:25");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("our $globalArgsCount;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:26");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("our $globalArgs;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:27");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("our $releaseMode;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("our $globalTrace;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:29");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("our $caller;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:30");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("our $false = 0;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:31");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("our $true = 1;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:32");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("my $stderr = \\*STDERR;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:33");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("our $quonGlobalArgs;\n");

}


void perlMainEntry() {
  
if (globalTrace)
    printf("perlMainEntry at q/perl.qon:35 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlMainEntry", "35" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:37");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n# Main entry point\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:38");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("$globalArgsCount = scalar(@ARGV);\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:39");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("$globalArgs = \\@ARGV;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:40");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("$quonGlobalArgs = [];\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:41");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("for my $arg (@$globalArgs) {\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:42");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("    push @$quonGlobalArgs, {car => $arg, cdr => undef};\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:43");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:44");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("for (my $i = $#$quonGlobalArgs - 1; $i >= 0; $i--) {\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:45");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("    $quonGlobalArgs->[$i]->{cdr} = $quonGlobalArgs->[$i + 1];\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:46");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:47");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("start();\n");

}


list collectVariablesFromArgs(list args) {
  list variables = NULL;

if (globalTrace)
    printf("collectVariablesFromArgs at q/perl.qon:49 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "collectVariablesFromArgs", "49" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:51");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(args)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:52");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return variables;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:54");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(stringify(first(args)), "list")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:56");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      variables = cons(second(args), variables);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:57");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return appendVariables(variables, collectVariablesFromArgs(cddr(args)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:59");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      variables = cons(second(args), variables);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:60");
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
    printf("collectVariablesFromDecls at q/perl.qon:62 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "collectVariablesFromDecls", "62" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:64");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:65");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return variables;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:67");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:68");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    variables = cons(second(decl), variables);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:69");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return appendVariables(variables, collectVariablesFromDecls(cdr(decls)));;

  };

}


list appendVariables(list vars1, list vars2) {
  
if (globalTrace)
    printf("appendVariables at q/perl.qon:71 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "appendVariables", "71" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:73");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(vars2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:75");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return vars1;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:77");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    vars1 = cons(car(vars2), vars1);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:78");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return appendVariables(vars1, cdr(vars2));;

  };

}


void perlFunctionArgs(list tree) {
  
if (globalTrace)
    printf("perlFunctionArgs at q/perl.qon:80 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlFunctionArgs", "80" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:82");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:83");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:85");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(dollar());

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:86");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(second(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:87");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:87");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:87");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(", ");

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:88");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlFunctionArgs(cddr(tree));

  };

}


void perlExpression(list tree, int indent, list variables) {
  list thing = NULL;

if (globalTrace)
    printf("perlExpression at q/perl.qon:90 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlExpression", "90" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:92");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:94");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equal(1, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:96");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(perlFuncMap(car(tree), variables));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:97");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("return"), car(tree))) {
      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:99");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("()");

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:101");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      thing = first(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:102");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxSymbol("get-struct"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:104");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("$%s->{%s}", stringify(second(tree)), stringify(third(tree)));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:108");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxSymbol("new"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:110");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("{}");

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:113");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("passthrough"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:115");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s", stringify(second(tree)));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:117");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("binop"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:119");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("(");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:120");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              perlExpression(third(tree), indent, variables);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:121");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(" %s ", stringify(second(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:122");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              perlExpression(fourth(tree), indent, variables);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:123");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:125");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s(", stringify(perlFuncMap(car(tree), variables)));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:126");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              perlRecurList(cdr(tree), indent, variables);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:127");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            };

          };

        };

      };

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:130");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("string", boxType(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:132");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("'%s'", escapeSingleQuotes(stringify(tree)));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:133");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(perlFuncMap(tree, variables));

    };

  };

}


void perlRecurList(list expr, int indent, list variables) {
  
if (globalTrace)
    printf("perlRecurList at q/perl.qon:135 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlRecurList", "135" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:137");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:138");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:140");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlExpression(car(expr), indent, variables);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:141");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:142");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:143");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(", ");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:143");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      perlRecurList(cdr(expr), indent, variables);

    };

  };

}


void perlStatement(list node, int indent, list variables) {
  
if (globalTrace)
    printf("perlStatement at q/perl.qon:145 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlStatement", "145" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:147");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("set"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:148");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlSet(node, indent, variables);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:150");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("set-struct"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:151");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      perlSetStruct(node, indent, variables);

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:153");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:154");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        perlIf(node, indent, variables);

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:156");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("return"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:158");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:159");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("return");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:160");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( greaterthan(listLength(node), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:162");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf(" ");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:163");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            perlExpression(cadr(node), indent, variables);

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:164");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("");

          };

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:166");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:167");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          perlExpression(node, indent, variables);

        };

      };

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:168");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(";\n");

}


void perlBody(list tree, int indent, list variables) {
  list code = NULL;

if (globalTrace)
    printf("perlBody at q/perl.qon:170 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlBody", "170" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:172");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:173");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:175");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    code = car(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:176");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlStatement(code, indent, variables);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:177");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlBody(cdr(tree), indent, variables);

  };

}


void perlSet(list node, int indent, list variables) {
  
if (globalTrace)
    printf("perlSet at q/perl.qon:179 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlSet", "179" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:181");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:182");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s = ", stringify(perlFuncMap(first(cdr(node)), variables)));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:183");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlExpression(third(node), indent, variables);

}


void perlSetStruct(list node, int indent, list variables) {
  
if (globalTrace)
    printf("perlSetStruct at q/perl.qon:185 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlSetStruct", "185" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:187");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:188");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->{%s} = ", stringify(perlFuncMap(second(node), variables)), stringify(third(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:191");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlExpression(fourth(node), indent, variables);

}


void perlIf(list node, int indent, list variables) {
  
if (globalTrace)
    printf("perlIf at q/perl.qon:193 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlIf", "193" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:195");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:196");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("if ( ");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:197");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlExpression(second(node), 0, variables);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:198");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(" ) {");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:199");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlBody(cdr(third(node)), add1(indent), variables);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:200");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:201");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("} else {");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:202");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlBody(cdr(fourth(node)), add1(indent), variables);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:203");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:204");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("}");

}


void perlGetStruct(list node, int indent) {
  
if (globalTrace)
    printf("perlGetStruct at q/perl.qon:208 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlGetStruct", "208" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:210");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:211");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("$%s->{%s}", stringify(first(node)), stringify(second(node)));

}


void perlDeclarations(list decls, int indent, list variables) {
  box decl = NULL;

if (globalTrace)
    printf("perlDeclarations at q/perl.qon:218 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlDeclarations", "218" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:220");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:221");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:223");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:224");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("my $%s = ", stringify(second(decl)));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:225");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlExpression(third(decl), indent, variables);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:226");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:227");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlDeclarations(cdr(decls), indent, variables);

  };

}


void perlFunction(list node) {
  box name = NULL;
list variables = NULL;
list args = NULL;
list decls = NULL;

if (globalTrace)
    printf("perlFunction at q/perl.qon:229 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlFunction", "229" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:231");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = second(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:232");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n# Function %s from line %s", stringify(name), stringify(getTag(name, boxString("line"))));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:233");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:234");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:235");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:237");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:238");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("sub %s {", stringify(second(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:239");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:240");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("my (");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:241");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlFunctionArgs(third(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:242");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(") = @_;");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:243");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:245");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    args = third(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:246");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decls = cdr(fourth(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:247");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    variables = collectVariables(args, decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:248");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlDeclarations(decls, 1, variables);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:249");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlBody(cdr(fifth(node)), 1, variables);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:250");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n");

  };

}


void perlForwardDeclaration(list node) {
  
if (globalTrace)
    printf("perlForwardDeclaration at q/perl.qon:252 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlForwardDeclaration", "252" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:254");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:255");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:257");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("sub %s;", stringify(second(node)));

  };

}


void perlForwardDeclarations(list tree) {
  
if (globalTrace)
    printf("perlForwardDeclarations at q/perl.qon:259 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlForwardDeclarations", "259" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:261");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:262");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:264");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlForwardDeclaration(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:265");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlForwardDeclarations(cdr(tree));

  };

}


void perlFunctions(list tree) {
  
if (globalTrace)
    printf("perlFunctions at q/perl.qon:267 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlFunctions", "267" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:269");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:270");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:272");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlFunction(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:273");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlFunctions(cdr(tree));

  };

}


void perlIncludes(list nodes) {
  
if (globalTrace)
    printf("perlIncludes at q/perl.qon:275 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlIncludes", "275" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:277");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("use strict;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:278");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("use warnings;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:279");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("use v5.10;\n\n");

}


box perlTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("perlTypeMap at q/perl.qon:282 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlTypeMap", "282" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:284");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("array"), alistCons(boxSymbol("string"), boxSymbol("string"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:287");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:288");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:289");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


box perlFuncMap(box aSym, list variables) {
  list symMap = NULL;

if (globalTrace)
    printf("perlFuncMap at q/perl.qon:291 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlFuncMap", "291" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:293");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:296");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(aSym, variables)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:297");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return boxSymbol(stringConcatenate(dollar(), stringify(aSym)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:299");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      symMap = alistCons(boxSymbol("sub"), boxSymbol("subtract"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("substr"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("length"), alistCons(boxSymbol("nil"), boxSymbol("undef"), NULL))))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:308");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:309");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cdr(assoc(stringify(aSym), symMap));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:310");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return aSym;;

      };

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:311");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


void perlCompile(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    printf("perlCompile at q/perl.qon:312 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlCompile", "312" );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Scanning file...%s\n", filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:315");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Building sexpr\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:317");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:318");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:319");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:320");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Printing program\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:322");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlIncludes(cdr(first(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:323");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlGlobalVariables();

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:324");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlFunctions(cdr(third(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:325");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlMainEntry();

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:326");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n");

}


list readSexpr(char* aStr, char* filename) {
  list tokens = NULL;
list as = NULL;

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

  as = sexprTree(tokens);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:9");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return car(as);;

}


list sexprTree(list l) {
  box b = NULL;

if (globalTrace)
    printf("sexprTree at q/newparser.qon:11 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "sexprTree", "11" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:13");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:14");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:16");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    b = car(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:17");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isOpenBrace(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:19");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(sexprTree(cdr(l)), sexprTree(skipList(cdr(l))));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:21");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isCloseBrace(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:22");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return emptyList();;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:24");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return setTag(boxString("line"), getTagFail(b, boxString("line"), boxInt(-1)), cons(b, sexprTree(cdr(l))));;

      };

    };

  };

}


list loadQuon(char* filename) {
  char* programStr = "";
list tree = NULL;

if (globalTrace)
    printf("loadQuon at q/newparser.qon:29 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "loadQuon", "29" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:32");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:33");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:35");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return tree;;

}


list getIncludes(list program) {
  
if (globalTrace)
    printf("getIncludes at q/newparser.qon:38 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "getIncludes", "38" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:40");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cdr(first(program));;

}


list getTypes(list program) {
  
if (globalTrace)
    printf("getTypes at q/newparser.qon:42 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "getTypes", "42" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:44");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cdr(second(program));;

}


list getFunctions(list program) {
  
if (globalTrace)
    printf("getFunctions at q/newparser.qon:46 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "getFunctions", "46" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:48");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cdr(third(program));;

}


list loadIncludes(list tree) {
  list newProg = NULL;
char* includeFile = "";
list functionsCombined = NULL;
list typesCombined = NULL;
list includeTree = NULL;

if (globalTrace)
    printf("loadIncludes at q/newparser.qon:51 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "loadIncludes", "51" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:54");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(getIncludes(tree)), 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:60");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    includeFile = stringify(first(getIncludes(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:62");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    includeTree = loadQuon(includeFile);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:64");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    functionsCombined = concatLists(getFunctions(includeTree), getFunctions(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:65");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    typesCombined = concatLists(getTypes(includeTree), getTypes(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:67");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newProg = buildProg(cdr(getIncludes(tree)), typesCombined, functionsCombined);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:68");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return loadIncludes(newProg);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:71");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return tree;;

  };

}


list buildProg(list includes, list types, list functions) {
  list program = NULL;

if (globalTrace)
    printf("buildProg at q/newparser.qon:74 (%s)\n", caller);

  StackTraceMove("in", "q/newparser.qon", "buildProg", "74" );

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:76");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  includes = cons(boxSymbol("includes"), includes);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:77");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  types = cons(boxSymbol("types"), types);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:78");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  functions = cons(boxSymbol("functions"), functions);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:79");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = cons(includes, cons(types, cons(functions, NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:82");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return program;;

}


box car(list l) {
  //Function car omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {//Function car omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Cannot call car on empty list!\n");
//Function car omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Cannot call car on empty list!\n");
//Function car omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return NULL;;

  } else {//Function car omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    assertType("list", l, 18, "q/lists.qon");
//Function car omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(l->car)) {//Function car omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return NULL;;

    } else {//Function car omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return l->car;;

    };

  };

}


list cdr(list l) {
  //Function cdr omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {//Function cdr omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Attempt to cdr an empty list!!!!\n");
//Function cdr omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Attempt to cdr an empty list!!!!\n");
//Function cdr omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return NULL;;

  } else {//Function cdr omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return l->cdr;;

  };

}


list cons(box data, list l) {
  pair p = NULL;
//Function cons omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  p = makePair();
//Function cons omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  p->cdr = l;
//Function cons omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  p->car = data;
//Function cons omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  p->typ = "list";
//Function cons omitted due to the no trace list
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
//Function isList omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {//Function isList omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return true;;

  } else {//Function isList omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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
  //Function isEmpty omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {//Function isEmpty omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return true;;

  } else {//Function isEmpty omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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


bool isInt(char* val) {
  char* firstLetter = sub_string(val, 0, 1);

if (globalTrace)
    printf("isInt at q/lists.qon:176 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "isInt", "176" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:180");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("-", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:181");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:182");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("0", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:183");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:184");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("1", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:185");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return true;;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:186");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("2", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:187");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return true;;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:188");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("3", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:189");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return true;;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:190");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalString("4", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:191");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return true;;

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:192");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              if ( equalString("5", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:193");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                StackTraceMove("out", "", "", "");

                return true;;

              } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:194");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                if ( equalString("6", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:195");
                  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                  StackTraceMove("out", "", "", "");

                  return true;;

                } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:196");
                  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                  if ( equalString("7", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:197");
                    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                    StackTraceMove("out", "", "", "");

                    return true;;

                  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:198");
                    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                    if ( equalString("8", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:199");
                      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                      StackTraceMove("out", "", "", "");

                      return true;;

                    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:200");
                      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                      if ( equalString("9", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:201");
                        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                        StackTraceMove("out", "", "", "");

                        return true;;

                      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:202");
                        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                        StackTraceMove("out", "", "", "");

                        return false;;

                      };

                    };

                  };

                };

              };

            };

          };

        };

      };

    };

  };

}


box id(box b) {
  
if (globalTrace)
    printf("id at q/lists.qon:204 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "id", "204" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:204");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return b;;

}


char* chooseBoxInterp(box b) {
  char* val = stringify(b);
char* firstLetter = sub_string(val, 0, 1);

if (globalTrace)
    printf("chooseBoxInterp at q/lists.qon:207 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "chooseBoxInterp", "207" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:211");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("string", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:212");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "boxString";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:214");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("\"", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:215");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return "boxString";;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:216");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("true", val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:217");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return "boxBool";;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:218");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("false", val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:219");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return "boxBool";;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:220");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( isInt(val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:221");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return "boxInt";;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:222");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( isInt(val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:223");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return "boxFloat";;

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:224");
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
    printf("doInterpolatedList at q/lists.qon:232 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "doInterpolatedList", "232" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:234");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:235");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxSymbol("nil"), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:237");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:238");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return NULL;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:241");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      elem = first(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:243");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      newlist = cons(boxString(chooseBoxInterp(elem)), cons(first(l), newlist));

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:244");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ret = cons(cons(boxSymbol("cons"), cons(newlist, doInterpolatedList(cdr(l)))), NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:253");
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
    printf("doStringList at q/lists.qon:256 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "doStringList", "256" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:258");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:259");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxSymbol("nil"), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:261");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newlist = cons(boxSymbol("boxString"), cons(first(l), newlist));

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:262");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ret = cons(cons(boxSymbol("cons"), cons(newlist, doStringList(cdr(l)))), NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:271");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return ret;;

  };

}


list doSymbolList(list l) {
  list newlist = NULL;
list ret = NULL;

if (globalTrace)
    printf("doSymbolList at q/lists.qon:273 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "doSymbolList", "273" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:275");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:276");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxSymbol("nil"), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:278");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newlist = cons(boxSymbol("boxSymbol"), cons(first(l), newlist));

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:279");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ret = cons(cons(boxSymbol("cons"), cons(newlist, doSymbolList(cdr(l)))), NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:288");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return ret;;

  };

}


list doBoxList(list l) {
  
if (globalTrace)
    printf("doBoxList at q/lists.qon:291 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "doBoxList", "291" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:294");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:295");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxSymbol("nil"), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:297");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(cons(boxSymbol("cons"), cons(first(l), doBoxList(cdr(l)))), NULL);;

  };

}


list concatLists(list seq1, list seq2) {
  
if (globalTrace)
    printf("concatLists at q/lists.qon:310 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "concatLists", "310" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:312");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(seq1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:313");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return seq2;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:314");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(car(seq1), concatLists(cdr(seq1), seq2));;

  };

}


list alistKeys(list alist) {
  
if (globalTrace)
    printf("alistKeys at q/lists.qon:316 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "alistKeys", "316" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:318");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(alist)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:319");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:320");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(car(car(alist)), alistKeys(cdr(alist)));;

  };

}


void display(list l) {
  //Function display omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {//Function display omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("nil ");
//Function display omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {//Function display omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {//Function display omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("[");
//Function display omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      displayList(l, 0, true);
//Function display omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("]");

    } else {//Function display omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      displayList(l, 0, true);

    };

  };

}


void displayList(list l, int indent, bool first) {
  box val = NULL;
//Function displayList omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {//Function displayList omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {//Function displayList omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {//Function displayList omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isEmpty(l)) {//Function displayList omitted due to the no trace list
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return;;

      } else {//Function displayList omitted due to the no trace list
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( first) {
        } else {//Function displayList omitted due to the no trace list
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf(" ");

        };
//Function displayList omitted due to the no trace list
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        val = car(l);
//Function displayList omitted due to the no trace list
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( isList(val)) {//Function displayList omitted due to the no trace list
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);
//Function displayList omitted due to the no trace list
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("%s", openBrace());
//Function displayList omitted due to the no trace list
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          displayList(car(l), add1(indent), true);
//Function displayList omitted due to the no trace list
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("%s", closeBrace());
//Function displayList omitted due to the no trace list
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          displayList(cdr(l), indent, false);

        } else {//Function displayList omitted due to the no trace list
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("string", val->typ)) {//Function displayList omitted due to the no trace list
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("\"%s\"", unBoxString(val));

          } else {//Function displayList omitted due to the no trace list
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s", stringify(val));

          };
//Function displayList omitted due to the no trace list
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          displayList(cdr(l), indent, false);

        };

      };

    } else {//Function displayList omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("string", l->typ)) {//Function displayList omitted due to the no trace list
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("\"%s\"", unBoxString(l));

      } else {//Function displayList omitted due to the no trace list
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s", stringify(l));

      };

    };

  };

}


char* StringListJoinRec(list l, char* sep) {
  box val = NULL;

if (globalTrace)
    printf("StringListJoinRec at q/lists.qon:362 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "StringListJoinRec", "362" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:364");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:365");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:367");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:369");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:370");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return "";;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:372");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equal(listLength(l), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:373");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return stringify(car(l));;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:375");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return stringConcatenate(stringify(car(l)), stringConcatenate(sep, StringListJoinRec(cdr(l), sep)));;

        };

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:377");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return "";;

    };

  };

}


char* StringListJoin(list l, char* sep) {
  box val = NULL;

if (globalTrace)
    printf("StringListJoin at q/lists.qon:385 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "StringListJoin", "385" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:387");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:390");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return stringConcatenate(stringify(car(l)), stringConcatenate(sep, StringListJoinRec(cdr(l), sep)));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:392");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return stringify(car(l));;

  };

}


box ListToBoxString(list l, int indent) {
  
if (globalTrace)
    printf("ListToBoxString at q/lists.qon:395 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "ListToBoxString", "395" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:397");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return boxString(ListToString(l, indent, true, false));;

}


char* ListToString(list l, int indent, bool first, bool withNewLines) {
  box val = NULL;

if (globalTrace)
    printf("ListToString at q/lists.qon:400 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "ListToString", "400" );

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

    if ( isList(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:407");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:408");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return "";;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:412");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        val = car(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:413");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( isList(val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:415");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return StringListJoin(cons(boxString(stringify(tern(withNewLines, boxString("\n"), boxString(stringIndent(indent))))), cons(boxString(openBrace()), cons(boxString(" "), cons(boxString(ListToString(car(l), add1(indent), true, withNewLines)), cons(boxString(closeBrace()), cons(boxString(" "), cons(boxString(ListToString(cdr(l), indent, false, withNewLines)), NULL))))))), "");;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:431");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return stringConcatenate(stringify(val), ListToString(cdr(l), indent, false, withNewLines));;

        };

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:433");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return stringify(l);;

    };

  };

}


list listReverse(list l) {
  
if (globalTrace)
    printf("listReverse at q/lists.qon:440 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "listReverse", "440" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:442");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:443");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:444");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(car(l), listReverse(cdr(l)));;

  };

}


bool inList(box item, list l) {
  
if (globalTrace)
    printf("inList at q/lists.qon:446 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "inList", "446" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:448");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:449");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:452");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(car(l), item)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:453");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:454");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return inList(item, cdr(l));;

    };

  };

}


bool equalList(list a, list b) {
  
if (globalTrace)
    printf("equalList at q/lists.qon:456 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "equalList", "456" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:458");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(a)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:459");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:461");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:463");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return false;;

    };

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:466");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:467");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(a)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:469");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:471");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return false;;

    };

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:474");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(car(a), car(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:475");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return equalList(cdr(a), cdr(b));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:476");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  };

}


list reverseRec(list oldL, list newL) {
  
if (globalTrace)
    printf("reverseRec at q/lists.qon:479 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "reverseRec", "479" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:481");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(oldL)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:482");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return newL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:483");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return reverseRec(cdr(oldL), cons(first(oldL), newL));;

  };

}


list reverseList(list l) {
  
if (globalTrace)
    printf("reverseList at q/lists.qon:486 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "reverseList", "486" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:488");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return reverseRec(l, NULL);;

}


list flatten(list tree) {
  
if (globalTrace)
    printf("flatten at q/lists.qon:491 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "flatten", "491" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:493");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:494");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:496");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:497");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return concatLists(flatten(car(tree)), flatten(cdr(tree)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:498");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(car(tree), flatten(cdr(tree)));;

    };

  };

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


list macrolist(list l, char* search, list replace) {
  box val = NULL;

if (globalTrace)
    printf("macrolist at q/macros.qon:82 (%s)\n", caller);

  StackTraceMove("in", "q/macros.qon", "macrolist", "82" );

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:83");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:84");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:88");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:91");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(search, stringify(car(l)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:94");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return concatLists(replace, macrolist(cdr(l), search, replace));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:97");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(macrolist(car(l), search, replace), macrolist(cdr(l), search, replace));;

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:105");
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


bool isWhiteSpace(char* s) {
  
if (globalTrace)
    printf("isWhiteSpace at q/compiler.qon:91 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "isWhiteSpace", "91" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:95");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(" ", s)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:96");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:98");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("\t", s)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:99");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:101");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("\n", s)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:102");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return true;;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:104");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("\r", s)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:105");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return true;;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:106");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return false;;

        };

      };

    };

  };

}


bool isLineBreak(char* s) {
  
if (globalTrace)
    printf("isLineBreak at q/compiler.qon:108 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "isLineBreak", "108" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:110");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("\n", s)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:111");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:113");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("\r", s)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:113");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:113");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return false;;

    };

  };

}


int incForNewLine(box token, int val) {
  
if (globalTrace)
    printf("incForNewLine at q/compiler.qon:115 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "incForNewLine", "115" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:119");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("\n", stringify(token))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:120");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return add1(val);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:121");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return val;;

  };

}


box annotateReadPosition(char* filename, int linecount, int column, int start, box newBox) {
  
if (globalTrace)
    printf("annotateReadPosition at q/compiler.qon:123 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "annotateReadPosition", "123" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:125");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return setTag(boxString("filename"), boxString(filename), setTag(boxString("column"), boxInt(column), setTag(boxString("line"), boxInt(linecount), setTag(boxString("totalCharPos"), boxInt(start), newBox))));;

}


list scan(char* prog, int start, int len, int linecount, int column, char* filename) {
  box token = NULL;
char* newString = "";
box newBox = NULL;

if (globalTrace)
    printf("scan at q/compiler.qon:135 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "scan", "135" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:138");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(string_length(prog), sub(start, sub(0, len)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:140");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token = boxSymbol(sub_string(prog, sub1(add(start, len)), 1));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:141");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token->tag = alistCons(boxString("totalCharPos"), boxInt(start), NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:142");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isOpenBrace(token)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:144");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(finish_token(prog, start, sub1(len), linecount, column, filename), cons(boxSymbol(openBrace()), scan(prog, add1(start), 1, linecount, add1(column), filename)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:148");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isCloseBrace(token)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:150");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cons(finish_token(prog, start, sub1(len), linecount, column, filename), cons(annotateReadPosition(filename, linecount, column, start, boxSymbol(closeBrace())), scan(prog, add(start, len), 1, linecount, add1(column), filename)));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:155");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( isWhiteSpace(stringify(token))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:157");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return cons(finish_token(prog, start, sub1(len), linecount, column, filename), scan(prog, add(start, len), 1, incForNewLine(token, linecount), 0, filename));;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:160");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol(";"), token)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:162");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return scan(prog, add(start, add1(add1(string_length(readComment(prog, add1(start), len))))), 1, add1(linecount), 0, filename);;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:164");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("\""), token)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:166");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              newString = readString(prog, add1(start), len);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:167");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              newBox = annotateReadPosition(filename, linecount, column, start, boxString(newString));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:169");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return cons(newBox, scan(prog, add(start, add1(add1(string_length(newString)))), 1, linecount, add1(column), filename));;

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:171");
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
    snprintf(caller, 1024, "from q/compiler.qon:172");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  };

}


bool isOpenBrace(box b) {
  
if (globalTrace)
    printf("isOpenBrace at q/compiler.qon:175 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "isOpenBrace", "175" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:177");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxSymbol(openBrace()), b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:178");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:180");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxSymbol("["), b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:181");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:182");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return false;;

    };

  };

}


bool isCloseBrace(box b) {
  
if (globalTrace)
    printf("isCloseBrace at q/compiler.qon:184 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "isCloseBrace", "184" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:188");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxSymbol(closeBrace()), b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:189");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:191");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxSymbol("]"), b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:192");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:193");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return false;;

    };

  };

}


list skipList(list l) {
  box b = NULL;

if (globalTrace)
    printf("skipList at q/compiler.qon:197 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "skipList", "197" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:199");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:200");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:202");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    b = car(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:203");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isOpenBrace(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:204");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return skipList(skipList(cdr(l)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:206");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isCloseBrace(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:207");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return cdr(l);;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:208");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return skipList(cdr(l));;

      };

    };

  };

}


list makeNode(char* name, char* subname, list code, list children) {
  
if (globalTrace)
    printf("makeNode at q/compiler.qon:219 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "makeNode", "219" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:221");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(boxSymbol("node"), alistCons(boxSymbol("line"), getTagFail(code, boxString("line"), boxInt(-1)), cons(cons(boxSymbol("name"), boxString(name)), cons(cons(boxSymbol("subname"), boxString(subname)), cons(cons(boxSymbol("code"), code), alistCons(boxSymbol("children"), children, emptyList()))))));;

}


list addToNode(box key, box val, list node) {
  
if (globalTrace)
    printf("addToNode at q/compiler.qon:235 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "addToNode", "235" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:237");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(boxSymbol("node"), alistCons(key, val, cdr(node)));;

}


list makeStatementNode(char* name, char* subname, list code, list children, box functionName) {
  
if (globalTrace)
    printf("makeStatementNode at q/compiler.qon:240 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "makeStatementNode", "240" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:242");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return addToNode(boxSymbol("functionName"), functionName, makeNode(name, subname, code, children));;

}


list astExpression(list tree) {
  
if (globalTrace)
    printf("astExpression at q/compiler.qon:245 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astExpression", "245" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:247");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:249");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return makeNode("expression", "expression", NULL, astSubExpression(tree));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:251");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return astSubExpression(tree);;

  };

}


list astSubExpression(list tree) {
  
if (globalTrace)
    printf("astSubExpression at q/compiler.qon:253 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astSubExpression", "253" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:255");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:256");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:258");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:260");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return cons(astExpression(car(tree)), astSubExpression(cdr(tree)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:262");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return makeNode("expression", "leaf", tree, NULL);;

    };

  };

}


list astIf(list tree, box fname) {
  
if (globalTrace)
    printf("astIf at q/compiler.qon:264 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astIf", "264" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:266");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("then"), car(second(tree)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:267");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nop();

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:269");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Error at %s:%s!  If statement is missing the true branch.\n\n", stringify(getTag(car(first(tree)), boxString("filename"))), stringify(getTag(car(first(tree)), boxString("line"))));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:270");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Missing true branch in if statement!  All if statements must have a true and false branch, like this:\n\n(if hungryForApples\n(then (printf \"yes!\"))\n(else (printf \"no!\")))\n\n\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:272");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("else"), car(third(tree)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:273");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nop();

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:275");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Error at %s:%s!  If statement is missing the false branch.\n\n", stringify(getTag(car(first(tree)), boxString("filename"))), stringify(getTag(car(first(tree)), boxString("line"))));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:276");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Missing false branch in if statement!  All if statements must have a true and false branch, like this:\n\n(if hungryForApples\n(then (printf \"yes!\"))\n(else (printf \"no!\")))\n\n\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:277");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return makeNode("statement", "if", tree, cons(cons(astExpression(first(tree)), NULL), cons(astBody(cdr(second(tree)), fname), cons(astBody(cdr(third(tree)), fname), NULL))));;

}


list astSetStruct(list tree) {
  
if (globalTrace)
    printf("astSetStruct at q/compiler.qon:285 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astSetStruct", "285" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:287");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return makeNode("statement", "structSetter", tree, astExpression(third(tree)));;

}


list astSet(list tree) {
  
if (globalTrace)
    printf("astSet at q/compiler.qon:290 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astSet", "290" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:292");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return makeNode("statement", "setter", tree, astExpression(second(tree)));;

}


list astGetStruct(list tree) {
  
if (globalTrace)
    printf("astGetStruct at q/compiler.qon:295 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astGetStruct", "295" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:296");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return makeNode("expression", "structGetter", tree, NULL);;

}


list astReturnVoid(box fname) {
  
if (globalTrace)
    printf("astReturnVoid at q/compiler.qon:298 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astReturnVoid", "298" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:300");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return makeStatementNode("statement", "returnvoid", NULL, NULL, fname);;

}


list astStatement(list tree, box fname) {
  
if (globalTrace)
    printf("astStatement at q/compiler.qon:302 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astStatement", "302" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:305");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:306");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nop();

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:308");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Error at %s:%s!  Statement must be a list.\n\n", stringify(getTag(car(first(tree)), boxString("filename"))), stringify(getTag(car(first(tree)), boxString("line"))));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:309");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("A statement must be a list: (printf \"Hello\")\n\n\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:312");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("if"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:313");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return astIf(cdr(tree), fname);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:315");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("set"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:316");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return astSet(cdr(tree));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:318");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("get-struct"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:320");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("Choosing get-struct statement\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:321");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return astGetStruct(cdr(tree));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:323");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("set-struct"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:324");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return astSetStruct(cdr(tree));;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:326");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxString("return"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:328");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equal(listLength(tree), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:329");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return astReturnVoid(fname);;

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:331");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return makeStatementNode("statement", "return", tree, makeNode("expression", "expression", tree, astExpression(tree)), fname);;

            };

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:335");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return makeStatementNode("statement", "statement", tree, makeNode("expression", "expression", tree, astExpression(tree)), fname);;

          };

        };

      };

    };

  };

}


list astBody(list tree, box fname) {
  
if (globalTrace)
    printf("astBody at q/compiler.qon:340 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astBody", "340" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:342");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:343");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:344");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(astStatement(car(tree), fname), astBody(cdr(tree), fname));;

  };

}


list astFunction(list tree) {
  char* file = "";
char* line = "";
box fname = NULL;

if (globalTrace)
    printf("astFunction at q/compiler.qon:348 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astFunction", "348" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:350");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fname = second(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:353");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  line = stringify(getTag(fname, boxString("line")));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:354");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  file = stringify(getTag(fname, boxString("filename")));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:355");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(1, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:355");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    locPanic(file, line, "Malformed function, seems to be empty");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:356");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(2, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:356");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    locPanic(file, line, "Malformed function, expected function name");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:357");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(3, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:357");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    locPanic(file, line, "Malformed function, expected argument list");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:358");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(4, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:358");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    locPanic(file, line, "Malformed function, expected variable declarations");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:359");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(5, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:359");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    locPanic(file, line, "Malformed function, expected body");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:360");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return alistCons(boxSymbol("file"), getTag(fname, boxString("filename")), alistCons(boxSymbol("line"), getTag(fname, boxString("line")), cons(cons(boxSymbol("name"), boxString("function")), cons(cons(boxSymbol("subname"), second(tree)), cons(cons(boxSymbol("declarations"), cdr(fourth(tree))), cons(cons(boxSymbol("intype"), third(tree)), cons(cons(boxSymbol("outtype"), car(tree)), cons(cons(boxSymbol("children"), astBody(cdr(fifth(tree)), fname)), emptyList()))))))));;

}


list astFunctionList(list tree) {
  
if (globalTrace)
    printf("astFunctionList at q/compiler.qon:381 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astFunctionList", "381" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:383");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:384");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:386");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(astFunction(car(tree)), astFunctionList(cdr(tree)));;

  };

}


list astFunctions(list tree) {
  
if (globalTrace)
    printf("astFunctions at q/compiler.qon:389 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astFunctions", "389" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:391");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("functions"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:392");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return makeNode("functions", "functions", tree, astFunctionList(cdr(tree)));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:393");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Functions section not found!  Every program must have a function section, even if you don't define any functions, although that is a rather pointless program.  Your function section should look like:'\n\n(return_type function_name (arg1 arg2 arg3 ...) (declare types) (body (statement)(statement)))\n\n\nThe function section must be directly after the types section.");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:394");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  };

}


list loadLib(char* path) {
  char* programStr = "";
list tree = NULL;
list library = NULL;

if (globalTrace)
    printf("loadLib at q/compiler.qon:397 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "loadLib", "397" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:400");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(path);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:401");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, path);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:402");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:403");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  library = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:411");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return library;;

}


list astInclude(list tree) {
  
if (globalTrace)
    printf("astInclude at q/compiler.qon:413 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astInclude", "413" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:414");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return loadLib(stringify(tree));;

}


list astIncludeList(list tree) {
  
if (globalTrace)
    printf("astIncludeList at q/compiler.qon:416 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astIncludeList", "416" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:418");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:419");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:421");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(astInclude(car(tree)), astIncludeList(cdr(tree)));;

  };

}


list astIncludes(list tree) {
  
if (globalTrace)
    printf("astIncludes at q/compiler.qon:423 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astIncludes", "423" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:426");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("includes"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:427");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return makeNode("includes", "includes", tree, astIncludeList(cdr(tree)));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:428");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Includes section not found!  Every program must have an include section, even if you don't import any libraries.  Your include section should look like:'\n\n(includes file1.qon file.qon)\n\n\nThe includes section must be the first section of the file.");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:429");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  };

}


list astStruct(list tree) {
  
if (globalTrace)
    printf("astStruct at q/compiler.qon:431 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astStruct", "431" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:432");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return makeNode("type", "struct", tree, NULL);;

}


list astType(list tree) {
  
if (globalTrace)
    printf("astType at q/compiler.qon:434 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astType", "434" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:436");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(cadr(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:437");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return astStruct(tree);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:438");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return makeNode("type", "type", tree, NULL);;

  };

}


list astTypeList(list tree) {
  
if (globalTrace)
    printf("astTypeList at q/compiler.qon:440 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astTypeList", "440" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:442");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:443");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:444");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(astType(car(tree)), astTypeList(cdr(tree)));;

  };

}


list astTypes(list tree) {
  
if (globalTrace)
    printf("astTypes at q/compiler.qon:446 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astTypes", "446" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:448");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:449");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Empty or absent types section");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:450");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return boxString("!!!Fuck");;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:452");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("types"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:453");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return makeNode("types", "types", tree, astTypeList(cdr(tree)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:455");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      panic("Types section not found!  Every program must have a types section, even if you don't define any types");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:456");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("Types section not found!  Every program must have a types section, even if you don't define any types");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:457");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return boxString("!!!Fuck");;

    };

  };

}


list declarationsof(list ass) {
  
if (globalTrace)
    printf("declarationsof at q/compiler.qon:464 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "declarationsof", "464" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:465");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cdr(assocPanic("declarations", cdr(ass), "Cons list has no declarations key"));;

}


list codeof(list ass) {
  
if (globalTrace)
    printf("codeof at q/compiler.qon:467 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "codeof", "467" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:468");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cdr(assocPanic("code", cdr(ass), "Given cons list does not contain a code key"));;

}


list functionNameof(list ass) {
  
if (globalTrace)
    printf("functionNameof at q/compiler.qon:470 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "functionNameof", "470" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:471");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cdr(assoc("functionName", cdr(ass)));;

}


list nodeof(list ass) {
  
if (globalTrace)
    printf("nodeof at q/compiler.qon:473 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "nodeof", "473" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:475");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxBool(false), assoc("node", cdr(ass)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:477");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Given list does not contain nodes");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:478");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return boxBool(false);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:479");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cdr(assoc("node", cdr(ass)));;

  };

}


list lineof(list ass) {
  
if (globalTrace)
    printf("lineof at q/compiler.qon:481 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "lineof", "481" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:483");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cdr(assocFail("line", cdr(ass), boxInt(-1)));;

}


list subnameof(list ass) {
  
if (globalTrace)
    printf("subnameof at q/compiler.qon:486 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "subnameof", "486" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:487");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cdr(assoc("subname", cdr(ass)));;

}


list nameof(list ass) {
  
if (globalTrace)
    printf("nameof at q/compiler.qon:489 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "nameof", "489" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:490");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cdr(assoc("name", cdr(ass)));;

}


list childrenof(list ass) {
  
if (globalTrace)
    printf("childrenof at q/compiler.qon:492 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "childrenof", "492" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:493");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cdr(assoc("children", cdr(ass)));;

}


bool isNode(list val) {
  
if (globalTrace)
    printf("isNode at q/compiler.qon:496 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "isNode", "496" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:500");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:501");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:503");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:505");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxSymbol("node"), car(val))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:506");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return true;;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:507");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return false;;

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:508");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return false;;

    };

  };

}


bool isLeaf(list n) {
  
if (globalTrace)
    printf("isLeaf at q/compiler.qon:512 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "isLeaf", "512" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:516");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return equalBox(boxString("leaf"), subnameof(n));;

}


list noStackTrace() {
  
if (globalTrace)
    printf("noStackTrace at q/compiler.qon:518 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "noStackTrace", "518" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:520");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(boxString("boxType"), cons(boxString("stringify"), cons(boxString("isEmpty"), cons(boxString("unBoxString"), cons(boxString("isList"), cons(boxString("unBoxBool"), cons(boxString("unBoxSymbol"), cons(boxString("equalBox"), cons(boxString("assoc"), cons(boxString("inList"), cons(boxString("unBoxInt"), cons(boxString("listLength"), cons(boxString("stroff"), cons(boxString("troff"), cons(boxString("tron"), cons(boxString("stron"), cons(boxString("car"), cons(boxString("cdr"), cons(boxString("cons"), cons(boxString("stackTracePush"), cons(boxString("stackTracePop"), cons(boxString("assertType"), cons(boxString("boxString"), cons(boxString("boxSymbol"), cons(boxString("boxInt"), NULL)))))))))))))))))))))))));;

}


list treeCompile(char* filename) {
  char* programStr = "";
list tree = NULL;

if (globalTrace)
    printf("treeCompile at q/compiler.qon:550 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "treeCompile", "550" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:552");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:553");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:554");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return tree;;

}


list astBuild(char* filename) {
  char* programStr = "";
list tree = NULL;
list program = NULL;

if (globalTrace)
    printf("astBuild at q/compiler.qon:556 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astBuild", "556" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:558");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:559");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:560");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:569");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = mergeIncludes(program);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:570");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return program;;

}


void astCompile(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    printf("astCompile at q/compiler.qon:573 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astCompile", "573" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:575");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Final program: \n");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:578");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:579");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:580");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "write-file", "luaWriteFile");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:581");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "read-file", "luaReadFile");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:582");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "string-length", "string.len");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:584");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "sub-string", "luaSubstring");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:585");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "stringLength", "string.len");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:586");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:587");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:588");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  displayList(tree, 0, true);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Transformed tree");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:593");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n");

}


list mergeIncludes(list program) {
  
if (globalTrace)
    printf("mergeIncludes at q/compiler.qon:597 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "mergeIncludes", "597" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:599");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return merge_recur(childrenof(cdr(cdr(assocPanic("includes", program, "Program lacks include section")))), program);;

}


list merge_recur(list incs, list program) {
  
if (globalTrace)
    printf("merge_recur at q/compiler.qon:604 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "merge_recur", "604" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:606");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(incs), 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:608");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return mergeInclude(car(incs), merge_recur(cdr(incs), program));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:609");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return program;;

  };

}


list mergeInclude(list inc, list program) {
  list newProgram = NULL;
list oldfunctionsnode = NULL;
list oldfunctions = NULL;
list newfunctions = NULL;
list newFunctionNode = NULL;
list functions = NULL;
list oldtypesnode = NULL;
list oldtypes = NULL;
list newtypes = NULL;
list newTypeNode = NULL;
list types = NULL;

if (globalTrace)
    printf("mergeInclude at q/compiler.qon:612 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "mergeInclude", "612" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:627");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(inc)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:628");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return program;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:630");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    functions = childrenof(cdr(assocPanic("functions", inc, "Included file has no functions section")));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:631");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    oldfunctionsnode = cdr(assocPanic("functions", program, "Current module has no functions section"));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:632");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    oldfunctions = childrenof(oldfunctionsnode);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:633");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newfunctions = concatLists(functions, oldfunctions);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:634");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newFunctionNode = cons(boxSymbol("node"), alistCons(boxSymbol("children"), newfunctions, cdr(oldfunctionsnode)));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:642");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    types = childrenof(cdr(assocPanic("types", inc, "Included file has no types section")));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:643");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    oldtypesnode = cdr(assocPanic("types", program, "Current module has no types section"));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:644");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    oldtypes = childrenof(oldtypesnode);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:645");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newtypes = concatLists(types, oldtypes);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:646");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newTypeNode = cons(boxSymbol("node"), alistCons(boxSymbol("children"), newtypes, cdr(oldtypesnode)));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:651");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newProgram = alistCons(boxString("functions"), newFunctionNode, alistCons(boxString("types"), newTypeNode, alistCons(boxString("includes"), cons(boxSymbol("includes"), NULL), newProgram)));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:663");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return newProgram;;

  };

}


int add(int a, int b) {
  
  StackTraceMove("in", "q/base.qon", "add", "19" );
//Function add omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return sub(a, sub(0, b));;

}


float addf(float a, float b) {
  
if (globalTrace)
    printf("addf at q/base.qon:20 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "addf", "20" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:20");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return subf(a, subf(0, b));;

}


int sub1(int a) {
  
  StackTraceMove("in", "q/base.qon", "sub1", "21" );
//Function sub1 omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return sub(a, 1);;

}


int add1(int a) {
  
if (globalTrace)
    printf("add1 at q/base.qon:22 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "add1", "22" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:22");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return add(a, 1);;

}


box clone(box b) {
  box newb = NULL;

if (globalTrace)
    printf("clone at q/base.qon:24 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "clone", "24" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:27");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb = makeBox();

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(newb)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:30");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("clone: newb is nil\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:31");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("clone: newb is nil");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:32");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return newb;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:34");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newb->typ = b->typ;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:35");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newb->tag = b->tag;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:36");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newb->lis = b->lis;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:37");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newb->str = b->str;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:38");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newb->i = b->i;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:39");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newb->lengt = b->lengt;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:40");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return newb;;

  };

}


box tern(bool cond, list tr, list fal) {
  
if (globalTrace)
    printf("tern at q/base.qon:42 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "tern", "42" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:44");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( cond) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:44");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return tr;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:44");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return fal;;

  };

}


char* ternString(bool cond, char* tr, char* fal) {
  
if (globalTrace)
    printf("ternString at q/base.qon:46 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "ternString", "46" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:48");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( cond) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:48");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return tr;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:48");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return fal;;

  };

}


list ternList(bool cond, list tr, list fal) {
  
if (globalTrace)
    printf("ternList at q/base.qon:50 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "ternList", "50" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:52");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( cond) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:52");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return tr;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:52");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return fal;;

  };

}


box newVoid() {
  box newb = NULL;

if (globalTrace)
    printf("newVoid at q/base.qon:55 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "newVoid", "55" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:59");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb = makeBox();

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:60");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->voi = true;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:61");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->typ = "void";

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:62");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return newb;;

}


void stackDump() {
  
if (globalTrace)
    printf("stackDump at q/base.qon:64 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stackDump", "64" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:65");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("");

}


void nop() {
  
if (globalTrace)
    printf("nop at q/base.qon:69 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "nop", "69" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:70");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("");

}


bool equalBox(box a, box b) {
  
  StackTraceMove("in", "q/base.qon", "equalBox", "72" );
//Function equalBox omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(b)) {//Function equalBox omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {//Function equalBox omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("string", boxType(a))) {//Function equalBox omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return equalString(unBoxString(a), stringify(b));;

    } else {//Function equalBox omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("bool", boxType(a))) {//Function equalBox omitted due to the no trace list
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return andBool(unBoxBool(a), unBoxBool(b));;

      } else {//Function equalBox omitted due to the no trace list
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("symbol", boxType(a))) {//Function equalBox omitted due to the no trace list
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("symbol", boxType(b))) {//Function equalBox omitted due to the no trace list
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return equalString(unBoxSymbol(a), unBoxSymbol(b));;

          } else {//Function equalBox omitted due to the no trace list
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return false;;

          };

        } else {//Function equalBox omitted due to the no trace list
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("int", boxType(a))) {//Function equalBox omitted due to the no trace list
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return equal(unBoxInt(a), unBoxInt(b));;

          } else {//Function equalBox omitted due to the no trace list
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return false;;

          };

        };

      };

    };

  };

}


char* openBrace() {
  
if (globalTrace)
    printf("openBrace at q/base.qon:93 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "openBrace", "93" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:93");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return "(";;

}


char* closeBrace() {
  
if (globalTrace)
    printf("closeBrace at q/base.qon:94 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "closeBrace", "94" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:94");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return ")";;

}


char* boxType(box b) {
  //Function boxType omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return b->typ;;

}


box makeBox() {
  box b = NULL;
//Function makeBox omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = malloc(sizeof(Box));
//Function makeBox omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {//Function makeBox omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("failed to create box!");

  } else {
  };
//Function makeBox omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->tag = NULL;
//Function makeBox omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->car = NULL;
//Function makeBox omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->cdr = NULL;
//Function makeBox omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->lis = NULL;
//Function makeBox omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "None - error!";
//Function makeBox omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return b;;

}


pair makePair() {
  //Function makePair omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return makeBox();;

}


box boxString(char* s) {
  box b = NULL;
//Function boxString omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = makeBox();
//Function boxString omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->str = s;
//Function boxString omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->lengt = string_length(s);
//Function boxString omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "string";
//Function boxString omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return b;;

}


box boxSymbol(char* s) {
  box b = NULL;

  StackTraceMove("in", "q/base.qon", "boxSymbol", "132" );
//Function boxSymbol omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = boxString(s);
//Function boxSymbol omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "symbol";
//Function boxSymbol omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return b;;

}


box boxBool(bool boo) {
  box b = NULL;

if (globalTrace)
    printf("boxBool at q/base.qon:141 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "boxBool", "141" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:145");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = makeBox();

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:146");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->boo = boo;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:147");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "bool";

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:148");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return b;;

}


box boxInt(int val) {
  box b = NULL;

if (globalTrace)
    printf("boxInt at q/base.qon:150 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "boxInt", "150" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:154");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = makeBox();

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:155");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->i = val;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:156");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "int";

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:157");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return b;;

}


void assertType(char* atype, box abox, int line, char* file) {
  //Function assertType omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(abox)) {//Function assertType omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(atype, "nil")) {//Function assertType omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return;;

    } else {//Function assertType omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return;;

    };

  } else {//Function assertType omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(atype, boxType(abox))) {//Function assertType omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return;;

    } else {//Function assertType omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("Assertion failure at line %d, in file %s: provided value is not a '%s'!  It was actually '%s'. Contents:", line, file, atype, boxType(abox));
//Function assertType omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(abox);
//Function assertType omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\n");
//Function assertType omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(cons(boxString("Token may have been read from "), cons(boxString(stringify(getTagFail(abox, boxString("filename"), boxString("source file not found")))), cons(boxString(":"), cons(boxString(stringify(getTagFail(abox, boxString("line"), boxString("source line not found")))), NULL)))));
//Function assertType omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTracePrint();
//Function assertType omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      panic("Invalid type!");

    };

  };

}


char* unBoxString(box b) {
  
if (globalTrace)
    printf("unBoxString at q/base.qon:176 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "unBoxString", "176" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:177");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assertType("string", b, 177, "q/base.qon");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:177");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return b->str;;

}


char* unBoxSymbol(box b) {
  
  StackTraceMove("in", "q/base.qon", "unBoxSymbol", "179" );
//Function unBoxSymbol omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return b->str;;

}


bool unBoxBool(box b) {
  
if (globalTrace)
    printf("unBoxBool at q/base.qon:180 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "unBoxBool", "180" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:180");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return b->boo;;

}


int unBoxInt(box b) {
  
if (globalTrace)
    printf("unBoxInt at q/base.qon:181 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "unBoxInt", "181" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:181");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return b->i;;

}


char* stringify_rec(box b) {
  
if (globalTrace)
    printf("stringify_rec at q/base.qon:183 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stringify_rec", "183" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:185");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:186");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:188");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return stringConcatenate(stringify(car(b)), stringConcatenate(" ", stringify_rec(cdr(b))));;

  };

}


char* stringify(box b) {
  
  StackTraceMove("in", "q/base.qon", "stringify", "192" );
//Function stringify omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {//Function stringify omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "()";;

  } else {//Function stringify omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("string", boxType(b))) {//Function stringify omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return unBoxString(b);;

    } else {//Function stringify omitted due to the no trace list
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("bool", boxType(b))) {//Function stringify omitted due to the no trace list
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( unBoxBool(b)) {//Function stringify omitted due to the no trace list
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return "true";;

        } else {//Function stringify omitted due to the no trace list
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return "false";;

        };

      } else {//Function stringify omitted due to the no trace list
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("int", boxType(b))) {//Function stringify omitted due to the no trace list
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          StackTraceMove("out", "", "", "");

          return intToString(unBoxInt(b));;

        } else {//Function stringify omitted due to the no trace list
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("symbol", boxType(b))) {//Function stringify omitted due to the no trace list
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            StackTraceMove("out", "", "", "");

            return unBoxSymbol(b);;

          } else {//Function stringify omitted due to the no trace list
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalString("list", boxType(b))) {//Function stringify omitted due to the no trace list
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return stringConcatenate("(", stringConcatenate(stringify(car(b)), stringConcatenate(" ", stringConcatenate(stringify_rec(cdr(b)), ")"))));;

            } else {//Function stringify omitted due to the no trace list
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              StackTraceMove("out", "", "", "");

              return stringConcatenate("Unsupported type in stringify: ", boxType(b));;

            };

          };

        };

      };

    };

  };

}


bool hasTag(box aBox, box key) {
  
if (globalTrace)
    printf("hasTag at q/base.qon:227 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "hasTag", "227" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:229");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(aBox)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:230");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:231");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return isNotFalse(assoc(stringify(key), aBox->tag));;

  };

}


box getTag(box aBox, box key) {
  
if (globalTrace)
    printf("getTag at q/base.qon:234 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "getTag", "234" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:236");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( false) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:238");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Getting %s from: ", stringify(key));

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:239");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(alistKeys(aBox->tag));

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:240");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:242");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:243");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cdr(assoc(stringify(key), aBox->tag));;

}


box getTagFail(box aBox, box key, box onFail) {
  
if (globalTrace)
    printf("getTagFail at q/base.qon:246 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "getTagFail", "246" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:248");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( hasTag(aBox, key)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:249");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return getTag(aBox, key);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:250");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return onFail;;

  };

}


bool assocExists(char* key, box aBox) {
  
if (globalTrace)
    printf("assocExists at q/base.qon:256 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "assocExists", "256" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:260");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(aBox)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:261");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:262");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return isNotFalse(assoc(key, aBox));;

  };

}


box assocFail(char* key, box aBox, box onFail) {
  
if (globalTrace)
    printf("assocFail at q/base.qon:264 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "assocFail", "264" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:267");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( assocExists(key, aBox)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:268");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return assoc(key, aBox);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:269");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString(key), onFail);;

  };

}


box assocPanic(char* key, box aBox, char* onFail) {
  
if (globalTrace)
    printf("assocPanic at q/base.qon:271 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "assocPanic", "271" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:274");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( assocExists(key, aBox)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:275");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return assoc(key, aBox);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:276");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic(onFail);

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:277");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  panic("Inconceivable");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:279");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return NULL;;

}


box setTag(box key, list val, box aStruct) {
  
if (globalTrace)
    printf("setTag at q/base.qon:282 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "setTag", "282" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:285");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  aStruct->tag = alistCons(key, val, aStruct->tag);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:286");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return aStruct;;

}


void locPanic(char* file, char* line, char* message) {
  
if (globalTrace)
    printf("locPanic at q/base.qon:288 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "locPanic", "288" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:291");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s %s:%s\n", file, line, message);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:292");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  panic(message);

}


bool truthy(box aVal) {
  
if (globalTrace)
    printf("truthy at q/base.qon:294 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "truthy", "294" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:297");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return isNotFalse(aVal);;

}


bool isNotFalse(box aVal) {
  
if (globalTrace)
    printf("isNotFalse at q/base.qon:299 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "isNotFalse", "299" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:302");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(boxType(aVal), "bool")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:303");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( unBoxBool(aVal)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:303");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:303");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return false;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:304");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return true;;

  };

}


box toStr(box thing) {
  
if (globalTrace)
    printf("toStr at q/base.qon:306 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "toStr", "306" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:308");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return boxString(stringify(thing));;

}


box listLast(list alist) {
  
if (globalTrace)
    printf("listLast at q/base.qon:310 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "listLast", "310" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:313");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(cdr(alist))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:314");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return car(alist);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:315");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return listLast(cdr(alist));;

  };

}


void newLine(int indent) {
  //Function newLine omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n");
//Function newLine omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printIndent(indent);

}


void printIndent(int ii) {
  
if (globalTrace)
    printf("printIndent at q/base.qon:321 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "printIndent", "321" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:324");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(ii, 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:325");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  ");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:325");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(sub1(ii));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:326");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return;;

  };

}


char* stringIndent(int ii) {
  
if (globalTrace)
    printf("stringIndent at q/base.qon:328 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stringIndent", "328" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:331");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(ii, 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:332");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return stringConcatenate("  ", stringIndent(sub1(ii)));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:333");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "";;

  };

}


list listIndent(int ii) {
  
if (globalTrace)
    printf("listIndent at q/base.qon:334 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "listIndent", "334" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:337");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(boxString(stringIndent(ii))), NULL);;

}


list listNewLine(int ii) {
  
if (globalTrace)
    printf("listNewLine at q/base.qon:340 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "listNewLine", "340" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:343");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(id(boxString(stringConcatenate("\n", stringIndent(ii)))), NULL);;

}


list argList(int count, int pos, char** args) {
  
if (globalTrace)
    printf("argList at q/base.qon:346 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "argList", "346" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:349");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(count, pos)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:351");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString(getStringArray(pos, args)), argList(count, add1(pos), args));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:354");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  };

}


void tron() {
  
if (globalTrace)
    printf("tron at q/base.qon:356 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "tron", "356" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:356");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalTrace = true;

}


void troff() {
  
if (globalTrace)
    printf("troff at q/base.qon:357 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "troff", "357" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:357");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalTrace = false;

}


void stron() {
  
if (globalTrace)
    printf("stron at q/base.qon:358 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stron", "358" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:358");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalStepTrace = true;

}


void stroff() {
  
if (globalTrace)
    printf("stroff at q/base.qon:359 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stroff", "359" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:359");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalStepTrace = false;

}


void StackTraceMove(char* direction, char* filename, char* fname, char* line) {
  //Function StackTraceMove omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(direction, "in")) {//Function StackTraceMove omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    globalStackTrace = cons(cons(boxString(filename), cons(boxString(line), cons(boxString(fname), NULL))), globalStackTrace);

  } else {//Function StackTraceMove omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    globalStackTrace = cdr(globalStackTrace);

  };

}


void StackTracePrint() {
  //Function StackTracePrint omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("Stack trace:\n");
//Function StackTracePrint omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(globalStackTrace)) {//Function StackTracePrint omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  <empty>\n");

  } else {//Function StackTracePrint omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTracePrintHelper(globalStackTrace);

  };

}


void StackTracePrintHelper(list stack) {
  char* file = stringify(first(car(stack)));
char* line = "";
char* func = "";
//Function StackTracePrintHelper omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(stack)) {//Function StackTracePrintHelper omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  <end>\n");
//Function StackTracePrintHelper omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {//Function StackTracePrintHelper omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    file = stringify(first(car(stack)));
//Function StackTracePrintHelper omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    line = stringify(second(car(stack)));
//Function StackTracePrintHelper omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    func = stringify(third(first(stack)));
//Function StackTracePrintHelper omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  %s:%s %s\n", file, line, func);
//Function StackTracePrintHelper omitted due to the no trace list
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTracePrintHelper(cdr(stack));

  };

}


list NoStackTrace_list() {
  //Function NoStackTrace_list omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cons(boxString("StackTraceMove"), cons(boxString("StackTracePrint"), cons(boxString("StackTracePrintHelper"), cons(boxString("NoStackTrace_list"), cons(boxString("car"), cons(boxString("cdr"), cons(boxString("cons"), cons(boxString("set"), cons(boxString("boxString"), cons(boxString("makePair"), cons(boxString("set-struct"), cons(boxString("display"), cons(boxString("list"), cons(boxString("assertType"), cons(boxString("isEmpty"), cons(boxString("isNil"), cons(boxString("get-struct"), cons(boxString("equalString"), cons(boxString("binop"), cons(boxString("strcmp"), cons(boxString("main"), cons(boxString("makeBox"), cons(boxString("string_length"), cons(boxString("boxType"), cons(boxString("displayList"), cons(boxString("newLine"), cons(boxString("panic"), NULL)))))))))))))))))))))))))));;

}


list NoTrace_list() {
  
if (globalTrace)
    printf("NoTrace_list at q/base.qon:409 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "NoTrace_list", "409" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:411");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return cons(boxString("StackTraceMove"), cons(boxString("StackTracePrint"), cons(boxString("StackTracePrintHelper"), cons(boxString("NoStackTrace_list"), cons(boxString("car"), cons(boxString("cdr"), cons(boxString("cons"), cons(boxString("set"), cons(boxString("boxString"), cons(boxString("makePair"), cons(boxString("set-struct"), cons(boxString("display"), cons(boxString("list"), cons(boxString("assertType"), cons(boxString("isEmpty"), cons(boxString("isNil"), cons(boxString("get-struct"), cons(boxString("equalString"), cons(boxString("binop"), cons(boxString("strcmp"), cons(boxString("main"), cons(boxString("makeBox"), cons(boxString("string_length"), cons(boxString("boxType"), cons(boxString("displayList"), cons(boxString("newLine"), cons(boxString("panic"), cons(boxString("boxString"), cons(boxString("boxSymbol"), cons(boxString("boxType"), cons(boxString("equalString"), cons(boxString("unBoxSymbol"), cons(boxString("isList"), cons(boxString("makeBox"), cons(boxString("equalBox"), cons(boxString("sub"), cons(boxString("sub1"), cons(boxString("stringify"), cons(boxString("add"), cons(boxString("greaterthan"), NULL))))))))))))))))))))))))))))))))))))))));;

}


int indexOfHelper(char* haystack, char* needle, int start, int current) {
  
if (globalTrace)
    printf("indexOfHelper at q/base.qon:418 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "indexOfHelper", "418" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:420");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(add(current, string_length(needle)), string_length(haystack))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:421");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return -1;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:423");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(sub_string(haystack, current, string_length(needle)), needle)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:424");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return current;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:425");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return indexOfHelper(haystack, needle, start, add1(current));;

    };

  };

}


int indexOf(char* haystack, char* needle, int start) {
  
if (globalTrace)
    printf("indexOf at q/base.qon:427 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "indexOf", "427" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:429");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(string_length(needle), 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:430");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return start;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:431");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return indexOfHelper(haystack, needle, start, start);;

  };

}


char* stringReplace(char* old, char* new, char* s) {
  
if (globalTrace)
    printf("stringReplace at q/base.qon:434 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stringReplace", "434" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:436");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return stringConcatenate(sub_string(s, 0, indexOf(s, old, 0)), stringConcatenate(new, sub_string(s, add(indexOf(s, old, 0), string_length(old)), sub(string_length(s), add(indexOf(s, old, 0), string_length(old))))));;

}


bool stringContains(char* haystack, char* needle) {
  int haystackLength = 0;
int needleLength = 0;

if (globalTrace)
    printf("stringContains at q/base.qon:445 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stringContains", "445" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:449");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  haystackLength = string_length(haystack);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:450");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  needleLength = string_length(needle);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:452");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(needleLength, haystackLength)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:455");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:458");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return stringContainsHelper(haystack, needle, 0);;

  };

}


bool stringContainsHelper(char* haystack, char* needle, int startIndex) {
  int haystackLength = 0;
int needleLength = 0;

if (globalTrace)
    printf("stringContainsHelper at q/base.qon:460 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stringContainsHelper", "460" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:465");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  haystackLength = string_length(haystack);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:466");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  needleLength = string_length(needle);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:468");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(add(startIndex, needleLength), haystackLength)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:471");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:473");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(sub_string(haystack, startIndex, needleLength), needle)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:476");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:479");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return stringContainsHelper(haystack, needle, add(startIndex, 1));;

    };

  };

}


char* stringTrim(char* s) {
  
if (globalTrace)
    printf("stringTrim at q/base.qon:481 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stringTrim", "481" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:483");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(string_length(s), 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:485");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return "";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:487");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isWhiteSpace(sub_string(s, 0, 1))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:489");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      StackTraceMove("out", "", "", "");

      return stringTrim(sub_string(s, 1, string_length(s)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:491");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isWhiteSpace(sub_string(s, sub(string_length(s), 1), string_length(s)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:493");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        StackTraceMove("out", "", "", "");

        return stringTrim(sub_string(s, 0, sub(string_length(s), 1)));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:495");
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
    printf("stringSplit at q/base.qon:497 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stringSplit", "497" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:501");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("Entering stringSplit with s: %.20s..., delimiter: %s\n", s, delimiter);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:502");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  delimiterLength = string_length(delimiter);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:503");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  end = indexOf(s, delimiter, 0);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:504");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(end, -1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:506");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("No delimiter found in stringSplit\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:507");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString(s), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:509");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Splitting string in stringSplit\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:510");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return cons(boxString(sub_string(s, 0, end)), stringSplit(sub_string(s, add(end, delimiterLength), string_length(s)), delimiter));;

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
    printf("pointerAdd at q/shims/ansi3.qon:19 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "pointerAdd", "19" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:21");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return (a + b);;

}


char* getEnv(char* key) {
  
if (globalTrace)
    printf("getEnv at q/shims/ansi3.qon:23 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "getEnv", "23" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:25");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return getenv(key);;

}


void panic(char* s) {
  //Function panic omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalStepTrace = false;
//Function panic omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTracePrint();
//Function panic omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  abort();
//Function panic omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  exit(1);

}


int sub(int a, int b) {
  
  StackTraceMove("in", "q/shims/ansi3.qon", "sub", "34" );
//Function sub omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return (a - b);;

}


float mult(int a, int b) {
  
if (globalTrace)
    printf("mult at q/shims/ansi3.qon:38 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "mult", "38" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:40");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return (a * b);;

}


int greaterthan(int a, int b) {
  
  StackTraceMove("in", "q/shims/ansi3.qon", "greaterthan", "42" );
//Function greaterthan omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return (a > b);;

}


float subf(float a, float b) {
  
if (globalTrace)
    printf("subf at q/shims/ansi3.qon:46 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "subf", "46" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:48");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return (a - b);;

}


float multf(float a, float b) {
  
if (globalTrace)
    printf("multf at q/shims/ansi3.qon:50 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "multf", "50" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:52");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return (a * b);;

}


int greaterthanf(float a, float b) {
  
if (globalTrace)
    printf("greaterthanf at q/shims/ansi3.qon:54 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "greaterthanf", "54" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:56");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return (a > b);;

}


int equal(int a, int b) {
  
if (globalTrace)
    printf("equal at q/shims/ansi3.qon:58 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "equal", "58" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:60");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return (a == b);;

}


int equalString(char* a, char* b) {
  //Function equalString omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return (0 == strcmp(a, b));;

}


int string_length(char* s) {
  //Function string_length omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return strlen(s);;

}


char* setSubString(char* target, int start, char* source) {
  
if (globalTrace)
    printf("setSubString at q/shims/ansi3.qon:70 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "setSubString", "70" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:72");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  target[start]=source[0];

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:73");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return target;;

}


char* sub_string(char* s, int start, int length) {
  char* substr = "";

if (globalTrace)
    printf("sub_string at q/shims/ansi3.qon:76 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "sub_string", "76" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:78");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  substr = calloc(add(length, 1), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:79");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  strncpy(substr, (s + start), length);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:80");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return substr;;

}


char* stringConcatenate(char* a, char* b) {
  int len = 0;
char* target = NULL;

if (globalTrace)
    printf("stringConcatenate at q/shims/ansi3.qon:83 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "stringConcatenate", "83" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:85");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  len = add(add(strlen(a), strlen(b)), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:86");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  target = calloc(len, 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:87");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  strncat(target, a, len);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:88");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  strncat(target, b, len);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:89");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return target;;

}


char* intToString(int a) {
  int len = 0;
char* target = NULL;

if (globalTrace)
    printf("intToString at q/shims/ansi3.qon:92 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "intToString", "92" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:94");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  len = 100;

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:95");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  target = calloc(len, 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:96");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  snprintf(target, 99, "%d", a);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:97");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return target;;

}


void* gc_malloc(uint size) {
  
if (globalTrace)
    printf("gc_malloc at q/shims/ansi3.qon:100 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "gc_malloc", "100" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:102");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return malloc(size);;

}


int* makeArray(int length) {
  int* array = NULL;

if (globalTrace)
    printf("makeArray at q/shims/ansi3.qon:105 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "makeArray", "105" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:107");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  array = gc_malloc(mult(length, sizeof(int)));

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:108");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return array;;

}


int at(int* arr, int index) {
  
if (globalTrace)
    printf("at at q/shims/ansi3.qon:111 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "at", "111" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:113");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return arr[index];;

}


void setAt(int* array, int index, int value) {
  
if (globalTrace)
    printf("setAt at q/shims/ansi3.qon:116 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "setAt", "116" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:118");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  array[index] = value;

}


void setCharAt(char* array, int index, int value) {
  
if (globalTrace)
    printf("setCharAt at q/shims/ansi3.qon:121 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "setCharAt", "121" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:123");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  array[index] = value;

}


char* read_file(char* filename) {
  char* buffer = NULL;
long length = 0;
FILE* f = NULL;

if (globalTrace)
    printf("read_file at q/shims/ansi3.qon:126 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "read_file", "126" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:128");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  f = fopen(filename, "rb");

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:129");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( ansi3IsNil(f)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:130");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:132");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fseek(f, 0, SEEK_END);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:133");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    length = ftell(f);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:134");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fseek(f, 0, SEEK_SET);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:135");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    buffer = calloc(add(1, length), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:137");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( ansi3IsNil(buffer)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:138");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      panic("Malloc failed!\n");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:139");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      fread(buffer, 1, length, f);

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:140");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fclose(f);

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:143");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return buffer;;

}


void write_file(char* filename, char* data) {
  char* buffer = NULL;
long length = 0;
FILE* f = NULL;

if (globalTrace)
    printf("write_file at q/shims/ansi3.qon:146 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "write_file", "146" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:148");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  f = fopen(filename, "w");

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:149");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( ansi3IsNil(f)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:150");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Error opening file!");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:152");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fprintf(f, "%s", data);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:153");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fclose(f);

  };

}


char* getStringArray(int index, char** strs) {
  
if (globalTrace)
    printf("getStringArray at q/shims/ansi3.qon:157 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "getStringArray", "157" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:159");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return strs[index];;

}


char** programArgs() {
  
if (globalTrace)
    printf("programArgs at q/shims/ansi3.qon:161 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "programArgs", "161" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:163");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return globalArgs;;

}


int programArgsCount() {
  
if (globalTrace)
    printf("programArgsCount at q/shims/ansi3.qon:166 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "programArgsCount", "166" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:168");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return globalArgsCount;;

}


int main(int argc, char** argv) {
  //Function main omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  caller = calloc(1024, 1);
//Function main omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalArgs = argv;
//Function main omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalArgsCount = argc;
//Function main omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return start();;

}


char* character(int num) {
  char* buffer = NULL;
char* str = NULL;

if (globalTrace)
    printf("character at q/shims/ansi3.qon:180 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "character", "180" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:182");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  str = malloc(2);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:183");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( ansi3IsNil(str)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:184");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return 0;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:186");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    setCharAt(str, 0, num);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:187");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    setCharAt(str, 1, 0);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:188");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    StackTraceMove("out", "", "", "");

    return str;;

  };

}


void displays(char* s) {
  
if (globalTrace)
    printf("displays at q/shims/ansi3.qon:195 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "displays", "195" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:197");
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
bool runAst = false;
bool runNode = false;
bool runNode2 = false;
bool runLua = false;
bool runIma = false;
bool runAnsi3 = false;
bool runBash = false;
bool runTree = false;

if (globalTrace)
    printf("start at compiler.qon:5 (%s)\n", caller);

  StackTraceMove("in", "compiler.qon", "start", "5" );

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:22");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  cmdLine = listReverse(argList(globalArgsCount, 0, globalArgs));

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:24");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(cmdLine), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:25");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    filenameBox = second(cmdLine);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:26");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    filenameBox = boxString("compiler.qon");

  };

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:27");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  filename = unBoxString(filenameBox);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:29");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  releaseMode = inList(boxString("--release"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:30");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runTests = inList(boxString("--test"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:31");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runJava = inList(boxString("--java"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:32");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runPerl = inList(boxString("--perl"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:33");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runAst = inList(boxString("--ast"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:34");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runTree = inList(boxString("--tree"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:35");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runNode = inList(boxString("--node"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:36");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runNode2 = inList(boxString("--node2"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:37");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runLua = inList(boxString("--lua"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:38");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runIma = inList(boxString("--ima"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:39");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runAnsi3 = inList(boxString("--ansi3"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:40");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runBash = inList(boxString("--bash"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:41");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalTrace = inList(boxString("--trace"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:42");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalStepTrace = inList(boxString("--steptrace"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:43");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( inList(boxString("--help"), cmdLine)) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:45");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Usage: quon file [options]\n\nNote the options go after the file name\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:46");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Options:\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:47");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --help      Display this help\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:48");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --release   Compile in release mode\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:49");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --test      Run the test suite\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:50");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --java      Compile to Java\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:51");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --perl      Compile to Perl\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:52");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --ast       Compile to the Abstract Syntax Tree\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:53");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --tree      Compile to an s-expression tree\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:54");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --node      Compile to Node.js\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:55");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --node2      Compile to Node.js, new outputter\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:56");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --lua       Compile to Lua\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:57");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --ima       Compile to Imaginary, the human-friendly language\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:59");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --ansi3     Compile to ANSI C (quon version 3)\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:60");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --bash      Compile to Bash\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:61");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --trace     Trace execution\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:62");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --steptrace Step trace execution\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:63");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --help      Display this help\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:64");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    exit(0);

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:68");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( runTests) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:70");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test0();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:71");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test1();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:72");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test2();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:73");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test3();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:74");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test4();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:75");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test5();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:76");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test6();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:77");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test7();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:78");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test8();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:79");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test9();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:80");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test10();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:81");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test12();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:82");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test13();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:83");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test15();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:84");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test16();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:85");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test17();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:86");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test18();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:87");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test19();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:88");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test20();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:89");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test21();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:90");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test22();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:91");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test23();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:92");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test24();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:93");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test25();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:94");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test27();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:96");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n\nAfter all that hard work, I need a beer...\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:97");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    beers(9);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:99");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( runTree) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:100");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(macrowalk(treeCompile(filename)));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:102");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( runAst) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:103");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        astCompile(filename);

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:104");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( runNode) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:106");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          nodeCompile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:106");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("\n");

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:107");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( runNode2) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:108");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            node2Compile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:108");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("\n");

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:110");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( runPerl) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:111");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              perlCompile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:111");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("\n");

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:113");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              if ( runJava) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:114");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                javaCompile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:114");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                printf("\n");

              } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:116");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                if ( runLua) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:117");
                  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                  luaCompile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:117");
                  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                  printf("\n");

                } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:119");
                  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                  if ( runAnsi3) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:120");
                    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                    ansi3Compile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:120");
                    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                    printf("\n");

                  } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:122");
                    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                    if ( runBash) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:123");
                      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                      bashCompile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:123");
                      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                      printf("\n");

                    } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:125");
                      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                      ansi3Compile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:125");
                      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                      printf("\n");

                    };

                  };

                };

              };

            };

          };

        };

      };

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:131");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  StackTraceMove("out", "", "", "");

  return 0;;

}


