
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
void imaFunctionArgs(int indent, list tree);
void imaFunction(int indent, list functionDefinition);
void imaDeclarations(int indent, list declarations);
void imaExpressionStart(int indent, list program);
void imaExpression(int indent, list program);
void imaStatement(int indent, list statement);
void imaBody(char* local_caller, int indent, list program);
void imaFunctions(int indent, list program);
void imaTypeDecl(list l);
void imaStructComponents(list node);
void imaStruct(list node);
box imaTypeMap(box aSym);
void imaType(list node);
void imaTypes(int indent, list nodes);
void imaProgram(list program);
void imaIncludes(int indent, list nodes);
void imaCompile(char* filename);
bool not(bool a);
bool andBool(bool a, bool b);
bool nand(bool a, bool b);
bool xor(bool a, bool b);
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
list node2Compile(char* filename);
list node2Includes(list nodes);
list node2Functions(list tree);
list node2Function(list node);
list node2FunctionArgs(list tree);
list node2Declarations(list decls, int indent);
void nodeFunctionArgs(list tree);
void nodeLeaf(list thisNode, int indent);
void nodeStructGetterExpression(list thisNode, int indent);
void nodeExpression(list node, int indent);
void nodeRecurList(list expr, int indent);
void nodeSubExpression(list tree, int indent);
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
void ansi2displays(char* s);
void ansi2FunctionArgs(list tree);
void ansi2Expression(list tree, int indent);
void ansi2RecurList(list expr, int indent);
void ansi2If(list node, int indent);
void ansi2SetStruct(list node, int indent);
void ansi2GetStruct(list node, int indent);
void ansi2Set(list node, int indent);
void ansi2Return(list node, int indent);
void ansi2Statement(list node, int indent);
void ansi2Body(list tree, int indent);
void ansi2Declarations(list decls, int indent);
void ansi2Function(list node);
void ansi2ForwardDeclaration(list node);
void ansi2ForwardDeclarations(list tree);
void ansi2Functions(list tree);
void ansi2Includes(list nodes);
void ansi2TypeDecl(list l);
void ansi2StructComponents(list node);
void ansi2Struct(list node);
box ansi2TypeMap(box aSym);
box ansi2FuncMap(box aSym);
void ansi2Type(list node);
void ansi2Types(list nodes);
void ansi2Compile(char* filename);
void ansiFunctionArgs(list tree);
void ansiLeaf(list thisNode, int indent);
void ansiStructGetterExpression(list thisNode, int indent);
void ansiExpression(list node, int indent);
void ansiRecurList(list expr, int indent);
void ansiSubExpression(list tree, int indent);
void ansiIf(list node, int indent);
void ansiSetStruct(list node, int indent);
void ansiGetStruct(list node, int indent);
void ansiSet(list node, int indent);
void ansiStatement(list node, int indent);
void ansiBody(list tree, int indent);
void ansiDeclarations(list decls, int indent);
void ansiFunction(list node);
void ansiForwardDeclaration(list node);
void ansiForwardDeclarations(list tree);
void ansiFunctions(list tree);
void ansiIncludes(list nodes);
void ansiTypeDecl(list l);
void ansiStructComponents(list node);
void ansiStruct(list node);
box ansiTypeMap(box aSym);
box ansiFuncMap(box aSym);
void ansiType(list node);
void ansiTypes(list nodes);
void ansiCompile(char* filename);
list numbers(int num);
char* lexType(box abox);
void perlLeaf(list thisNode, int indent);
void perlStructGetterExpression(list thisNode, int indent);
void perlExpression(list node, int indent);
void perlRecurList(list expr, int indent);
void perlSubExpression(list tree, int indent);
void perlIf(list node, int indent);
void perlSetStruct(list node, int indent);
void perlGetStruct(list node, int indent);
void perlSet(list node, int indent);
void assertNode(list node);
void perlStatement(list node, int indent);
void perlBody(list tree, int indent);
void perlDeclarations(list decls, int indent);
void perlFunction(list node);
void perlForwardDeclaration(list node);
void perlForwardDeclarations(list tree);
void perlFunctions(list tree);
char* dollar();
char* atSym();
void perlIncludes(list nodes);
void perlTypeDecl(list l);
void perlStructComponents(list node);
void perlStruct(list node);
box perlTypeMap(box aSym);
box perlConstMap(box aSym);
box perlFuncMap(box aSym);
void perlType(list node);
void perlTypes(list nodes);
void perlFunctionArgs(list tree);
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
box ListToBoxString(list l);
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

      if ( not(releaseMode)) {
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

    if ( not(releaseMode)) {
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


void imaFunctionArgs(int indent, list tree) {
  
if (globalTrace)
    printf("imaFunctionArgs at q/imaginary.qon:4 (%s)\n", caller);

  StackTraceMove("in", "q/imaginary.qon", "imaFunctionArgs", "4" );

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:6");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:7");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:9");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(second(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:10");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(": ");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:11");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(first(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:12");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:12");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:12");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(", ");

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:13");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaFunctionArgs(indent, cddr(tree));

  };

}


void imaFunction(int indent, list functionDefinition) {
  char* fname = "";

if (globalTrace)
    printf("imaFunction at q/imaginary.qon:16 (%s)\n", caller);

  StackTraceMove("in", "q/imaginary.qon", "imaFunction", "16" );

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:18");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fname = stringify(second(functionDefinition));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:21");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nfu %s(", fname);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:22");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaFunctionArgs(indent, third(functionDefinition));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:23");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(") ");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:24");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("-> %s", stringify(first(functionDefinition)));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:26");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaDeclarations(add1(indent), cdr(fourth(functionDefinition)));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:27");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(cdr(fourth(functionDefinition))), 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:29");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:30");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" ");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:31");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:32");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("in\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:34");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaBody(fname, indent, cdr(fifth(functionDefinition)));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:35");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("end function\n");

}


void imaDeclarations(int indent, list declarations) {
  list decl = NULL;

if (globalTrace)
    printf("imaDeclarations at q/imaginary.qon:37 (%s)\n", caller);

  StackTraceMove("in", "q/imaginary.qon", "imaDeclarations", "37" );

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:39");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(declarations)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:42");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:44");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = first(declarations);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:45");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:46");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:47");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s: %s ", stringify(second(decl)), stringify(first(decl)));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:48");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaExpressionStart(indent, third(decl));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:50");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaDeclarations(indent, cdr(declarations));

  };

}


void imaExpressionStart(int indent, list program) {
  
if (globalTrace)
    printf("imaExpressionStart at q/imaginary.qon:56 (%s)\n", caller);

  StackTraceMove("in", "q/imaginary.qon", "imaExpressionStart", "56" );

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:58");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:60");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:62");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:64");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringify(car(program)), "get-struct")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:66");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s.%s", stringify(second(program)), stringify(third(program)));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:69");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString(stringify(car(program)), ">")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:71");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("greaterthan(");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:72");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          imaExpression(indent, cdr(program));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:73");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf(")");

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:76");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString(stringify(car(program)), "=")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:78");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("equal(");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:79");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            imaExpression(indent, cdr(program));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:80");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf(")");

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:83");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s(", stringify(car(program)));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:84");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            imaExpression(indent, cdr(program));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:85");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf(")");

          };

        };

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:91");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      imaExpression(indent, program);

    };

  };

}


void imaExpression(int indent, list program) {
  
if (globalTrace)
    printf("imaExpression at q/imaginary.qon:98 (%s)\n", caller);

  StackTraceMove("in", "q/imaginary.qon", "imaExpression", "98" );

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:100");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:102");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:104");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:106");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isList(car(program))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:108");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        imaExpressionStart(indent, car(program));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:112");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        display(car(program));

      };

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:115");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( greaterthan(listLength(program), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:117");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf(", ");

      } else {
      };

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:119");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      imaExpression(indent, cdr(program));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:122");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(program);

    };

  };

}


void imaStatement(int indent, list statement) {
  
if (globalTrace)
    printf("imaStatement at q/imaginary.qon:126 (%s)\n", caller);

  StackTraceMove("in", "q/imaginary.qon", "imaStatement", "126" );

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:128");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(stringify(car(statement)), "if")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:131");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:132");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("if ");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:133");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    add1(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:134");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaExpressionStart(add1(indent), second(statement));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:136");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" then\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:137");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaBody(caller, add1(indent), cdr(third(statement)));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:138");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:139");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("else\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:140");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaBody(caller, add1(indent), cdr(fourth(statement)));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:141");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:142");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("end\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:145");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(stringify(car(statement)), "set")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:147");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:148");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("%s = ", stringify(second(statement)));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:149");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      imaExpressionStart(add1(indent), third(statement));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:150");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(";\n");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:153");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringify(car(statement)), "set-struct")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:155");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:156");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s.%s = ", stringify(second(statement)), stringify(third(statement)));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:157");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        imaExpressionStart(indent, fourth(statement));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:158");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf(";\n");

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:161");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString(stringify(car(statement)), "return")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:163");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:164");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("return; ");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:165");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( greaterthan(listLength(statement), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:167");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            imaExpressionStart(indent, second(statement));

          } else {
          };

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:169");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("\n");

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:172");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:173");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          imaExpressionStart(indent, statement);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:174");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf(";\n");

        };

      };

    };

  };

}


void imaBody(char* local_caller, int indent, list program) {
  list statement = NULL;

if (globalTrace)
    printf("imaBody at q/imaginary.qon:181 (%s)\n", caller);

  StackTraceMove("in", "q/imaginary.qon", "imaBody", "181" );

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:183");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:184");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:186");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    statement = car(program);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:188");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaStatement(add1(indent), statement);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:189");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaBody(local_caller, indent, cdr(program));

  };

}


void imaFunctions(int indent, list program) {
  
if (globalTrace)
    printf("imaFunctions at q/imaginary.qon:192 (%s)\n", caller);

  StackTraceMove("in", "q/imaginary.qon", "imaFunctions", "192" );

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:194");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:196");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:198");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaFunction(indent, car(program));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:199");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaFunctions(indent, cdr(program));

  };

}


void imaTypeDecl(list l) {
  char* name = "";
list body = NULL;

if (globalTrace)
    printf("imaTypeDecl at q/imaginary.qon:202 (%s)\n", caller);

  StackTraceMove("in", "q/imaginary.qon", "imaTypeDecl", "202" );

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:207");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = stringify(first(l));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:208");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  body = cdr(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:209");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:211");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:212");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s is ", name);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:216");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    displayList(body, 0, true);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:217");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:221");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:222");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s is %s;\n", name, stringify(second(l)));

  };

}


void imaStructComponents(list node) {
  
if (globalTrace)
    printf("imaStructComponents at q/imaginary.qon:227 (%s)\n", caller);

  StackTraceMove("in", "q/imaginary.qon", "imaStructComponents", "227" );

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:229");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:230");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:231");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaTypeDecl(car(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:231");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaStructComponents(cdr(node));

  };

}


void imaStruct(list node) {
  
if (globalTrace)
    printf("imaStruct at q/imaginary.qon:233 (%s)\n", caller);

  StackTraceMove("in", "q/imaginary.qon", "imaStruct", "233" );

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:234");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaStructComponents(cdr(car(node)));

}


box imaTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("imaTypeMap at q/imaginary.qon:236 (%s)\n", caller);

  StackTraceMove("in", "q/imaginary.qon", "imaTypeMap", "236" );

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:238");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:244");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:245");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:246");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


void imaType(list node) {
  char* name = "";
list body = NULL;

if (globalTrace)
    printf("imaType at q/imaginary.qon:248 (%s)\n", caller);

  StackTraceMove("in", "q/imaginary.qon", "imaType", "248" );

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:253");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = stringify(first(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:254");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  body = cdr(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:255");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(first(body))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:257");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\ntype %s is struct (\n", name);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:258");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaStruct(body);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:259");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(");\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:260");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("type");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:260");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaTypeDecl(node);

  };

}


void imaTypes(int indent, list nodes) {
  
if (globalTrace)
    printf("imaTypes at q/imaginary.qon:263 (%s)\n", caller);

  StackTraceMove("in", "q/imaginary.qon", "imaTypes", "263" );

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:266");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:267");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:268");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaType(car(nodes));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:268");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaTypes(indent, cdr(nodes));

  };

}


void imaProgram(list program) {
  
if (globalTrace)
    printf("imaProgram at q/imaginary.qon:272 (%s)\n", caller);

  StackTraceMove("in", "q/imaginary.qon", "imaProgram", "272" );

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:274");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaIncludes(0, cdr(first(program)));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:275");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nTypes:\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:276");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaTypes(0, cdr(second(program)));

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:277");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nFunctions:\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:278");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaFunctions(0, cdr(third(program)));

}


void imaIncludes(int indent, list nodes) {
  
if (globalTrace)
    printf("imaIncludes at q/imaginary.qon:282 (%s)\n", caller);

  StackTraceMove("in", "q/imaginary.qon", "imaIncludes", "282" );

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:284");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("Includes: \n");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:285");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  displayList(nodes, 0, true);

}


void imaCompile(char* filename) {
  list tree = NULL;

if (globalTrace)
    printf("imaCompile at q/imaginary.qon:289 (%s)\n", caller);

  StackTraceMove("in", "q/imaginary.qon", "imaCompile", "289" );

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:292");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon("compiler.qon");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:295");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:296");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:297");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "write-file", "imaWriteFile");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:298");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "read-file", "imaReadFile");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:299");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "string-length", "string.len");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:301");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "sub-string", "imaSubstring");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:302");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "stringLength", "string.len");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:304");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaProgram(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:305");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:306");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("function main()\nglobalArgs = arg\nglobalArgsCount = #arg\nstart()\nend\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:307");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("main()");

}


bool not(bool a) {
  
if (globalTrace)
    printf("not at q/boolean.qon:3 (%s)\n", caller);

  StackTraceMove("in", "q/boolean.qon", "not", "3" );

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

  return not(andBool(a, b));;

}


bool xor(bool a, bool b) {
  
if (globalTrace)
    printf("xor at q/boolean.qon:25 (%s)\n", caller);

  StackTraceMove("in", "q/boolean.qon", "xor", "25" );

if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:27");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return nand(nand(a, nand(a, b)), nand(b, nand(a, b)));;

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


list node2Compile(char* filename) {
  char* programStr = "";
list tree = NULL;
list program = NULL;

if (globalTrace)
    printf("node2Compile at q/node2.qon:4 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Compile", "4" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:7");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:8");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:9");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), emptyList())));

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:17");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = mergeIncludes(program);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Loading shim node2\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:19");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = buildProg(cons(boxString("q/shims/node2.qon"), getIncludes(program)), getTypes(program), getFunctions(program));

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:21");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return cons(node2Includes(cdr(assoc("includes", program))), cons(boxString("\nvar globalStackTrace = NULL;\n"), cons(boxString("\nvar caller = \"\";\n"), cons(boxString("\nfunction isNil(p) {\n    return p == NULL;\n}\n\n"), cons(node2Functions(cdr(assoc("children", cdr(cdr(assoc("functions", program)))))), cons(boxString("\n"), cons(boxString("const [asfdasdf, ...qwerqwer] = process.argv;"), cons(boxString("globalArgs = qwerqwer;"), cons(boxString("globalArgsCount = qwerqwer.length;"), cons(boxString("start();\n"), emptyList()))))))))));;

}


list node2Includes(list nodes) {
  
if (globalTrace)
    printf("node2Includes at q/node2.qon:35 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Includes", "35" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:37");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return cons(boxString("function read_file(filename) {return fs.readFileSync(filename);}\n"), cons(boxString("function write_file(filename, data) {fs.writeFileSync(filename, data);}\n"), cons(boxString("var util = require('util');\n"), cons(boxString("function printf() {process.stdout.write(util.format.apply(this, arguments));}\n"), cons(boxString("function qlog()   {process.stderr.write(util.format.apply(this, arguments));}\n"), cons(boxString("var fs = require('fs');\n"), cons(boxString("function equalString(a,b) {if (a==null) {return false;}if (b==null) {return false;}return a.toString()===b.toString() }\n"), cons(boxString("function panic(s){console.trace(s);process.exit(1);}\n"), cons(boxString("function dump(s){console.log(s)}"), cons(boxString("function sub(a, b) { return a - b; }\n"), cons(boxString("function mult(a, b) { return a * b; }\n"), cons(boxString("function greaterthan(a, b) { return a > b; }\n"), cons(boxString("function subf(a, b) { return a - b; }\n"), cons(boxString("function multf(a, b) { return a * b; }\n"), cons(boxString("function greaterthanf(a, b) { return a > b; }\n"), cons(boxString("function equal(a, b) { return a == b; }\n"), cons(boxString("function andBool(a, b) { return a == b;}\n"), cons(boxString("function string_length(s) { return s.length;}\n"), cons(boxString("function sub_string(str, start, len) {str = ''+str;return str.substring(start, start+len)};\n"), cons(boxString("function stringConcatenate(a, b) { return a + b}\n"), cons(boxString("function intToString(a) {}\n\n\n"), cons(boxString("function gc_malloc( size ) {\nreturn {};\n}\n\n"), cons(boxString("function makeArray(length) {\n   return [];\n}\n\n"), cons(boxString("function at(arr, index) {\n  return arr[index];\n}\n\n"), cons(boxString("function setAt(array, index, value) {\n    array[index] = value;\n}\n\n"), cons(boxString("function getStringArray(index, strs) {\nreturn strs[index];\n}\n\n"), cons(boxString("var NULL = null;"), cons(boxString("var globalArgs;\nvar globalArgsCount;\nvar globalTrace = false;\nvar globalStepTrace = false;\nvar releaseMode = false;\n"), cons(boxString("function character(num) {}"), NULL)))))))))))))))))))))))))))));;

}


list node2Functions(list tree) {
  
if (globalTrace)
    printf("node2Functions at q/node2.qon:70 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Functions", "70" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:73");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:74");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:75");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cons(node2Function(car(tree)), node2Functions(cdr(tree)));;

  };

}


list node2Function(list node) {
  box name = NULL;

if (globalTrace)
    printf("node2Function at q/node2.qon:78 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Function", "78" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:80");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:81");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:83");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    name = subnameof(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:84");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cons(boxString("\n\n//Building function "), cons(boxString(stringify(name)), cons(boxString(" from line: "), cons(boxString(stringify(getTag(name, boxString("line")))), NULL))));;

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:109");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return emptyList();;

}


list node2FunctionArgs(list tree) {
  
if (globalTrace)
    printf("node2FunctionArgs at q/node2.qon:111 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2FunctionArgs", "111" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:113");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:114");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:116");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cons(second(tree), cons(tern(isNil(cddr(tree)), boxString(""), boxString(",")), cons(node2FunctionArgs(cddr(tree)), emptyList())));;

  };

}


list node2Declarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("node2Declarations at q/node2.qon:122 (%s)\n", caller);

  StackTraceMove("in", "q/node2.qon", "node2Declarations", "122" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:124");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:125");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:127");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/node2.qon:128");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cons(boxString("var %s = "), cons(second(decl), cons(nodeFuncMap(third(decl)), cons(boxString(";\n"), node2Declarations(cdr(decls), indent)))));;

  };

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


void nodeExpression(list node, int indent) {
  
if (globalTrace)
    printf("nodeExpression at q/node.qon:22 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeExpression", "22" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:24");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isLeaf(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:25");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(nodeFuncMap(codeof(node)));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:26");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeSubExpression(node, indent);

  };

}


void nodeRecurList(list expr, int indent) {
  
if (globalTrace)
    printf("nodeRecurList at q/node.qon:28 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeRecurList", "28" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:32");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:33");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:35");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeExpression(car(expr), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:36");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:37");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:38");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(", ");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:38");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      nodeRecurList(cdr(expr), indent);

    };

  };

}


void nodeSubExpression(list tree, int indent) {
  box thing = NULL;

if (globalTrace)
    printf("nodeSubExpression at q/node.qon:41 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeSubExpression", "41" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:43");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:44");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:46");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNode(childrenof(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:47");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      nodeSubExpression(childrenof(tree), indent);

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:49");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isLeaf(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:50");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        display(nodeFuncMap(codeof(tree)));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:52");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equal(1, listLength(childrenof(tree)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:54");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          display(codeof(car(childrenof(tree))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:55");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxString("return"), codeof(car(childrenof(tree))))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:58");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("");

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:59");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("()");

          };

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:61");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          thing = codeof(car(childrenof(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:62");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("get-struct"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:64");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s.%s", stringify(codeof(second(childrenof(tree)))), stringify(codeof(third(childrenof(tree)))));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:69");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("new"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:71");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("{}");

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:75");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s(", stringify(nodeFuncMap(codeof(car(childrenof(tree))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:79");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              nodeRecurList(cdr(childrenof(tree)), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:80");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            };

          };

        };

      };

    };

  };

}


void nodeIf(list node, int indent) {
  
if (globalTrace)
    printf("nodeIf at q/node.qon:82 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeIf", "82" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:84");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:85");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("if ( ");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:86");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeExpression(car(first(childrenof(node))), 0);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:87");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(") {");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:88");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeBody(second(childrenof(node)), add1(indent));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:89");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:90");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("} else {");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:91");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeBody(third(childrenof(node)), add1(indent));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:92");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:93");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("}");

}


void nodeGetStruct(list node, int indent) {
  
if (globalTrace)
    printf("nodeGetStruct at q/node.qon:96 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeGetStruct", "96" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:98");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:99");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s.%s", stringify(first(codeof(node))), stringify(second(codeof(node))));

}


void nodeSet(list node, int indent) {
  
if (globalTrace)
    printf("nodeSet at q/node.qon:104 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeSet", "104" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:106");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:107");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s = ", stringify(first(codeof(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:108");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeExpression(childrenof(node), indent);

}


void nodeSetStruct(list node, int indent) {
  
if (globalTrace)
    printf("nodeSetStruct at q/node.qon:110 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeSetStruct", "110" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:112");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:113");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s.%s = ", stringify(first(codeof(node))), stringify(second(codeof(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:114");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeExpression(childrenof(node), indent);

}


void nodeStatement(list node, int indent) {
  
if (globalTrace)
    printf("nodeStatement at q/node.qon:118 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeStatement", "118" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:120");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("setter"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:121");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeSet(node, indent);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:123");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("structSetter"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:124");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      nodeSetStruct(node, indent);

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:126");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:127");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        nodeIf(node, indent);

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:129");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("returnvoid"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:130");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:130");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("return");

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:132");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:133");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          nodeExpression(childrenof(node), indent);

        };

      };

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:134");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(";\n");

}


void nodeBody(list tree, int indent) {
  
if (globalTrace)
    printf("nodeBody at q/node.qon:137 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeBody", "137" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:141");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:142");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:144");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:145");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s", "if (globalStepTrace) {console.log(new Error(\"StepTrace \\n\"));}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:148");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeStatement(car(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:149");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeBody(cdr(tree), indent);

  };

}


void nodeDeclarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("nodeDeclarations at q/node.qon:151 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeDeclarations", "151" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:153");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:154");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:156");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:157");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("var %s = ", stringify(second(decl)));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:160");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(nodeFuncMap(third(decl)));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:161");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:162");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeDeclarations(cdr(decls), indent);

  };

}


void nodeFunction(list node) {
  box name = NULL;

if (globalTrace)
    printf("nodeFunction at q/node.qon:166 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeFunction", "166" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:168");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = subnameof(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:169");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:170");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:171");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:172");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:174");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:175");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("function %s(", stringify(subnameof(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:178");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeFunctionArgs(cdr(assoc("intype", cdr(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:179");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(") {");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:180");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:181");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeDeclarations(declarationsof(node), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:182");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:183");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:185");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    {printf(\"%s at %s:%s\\n\");}\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:186");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:187");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
    };

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:191");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeBody(childrenof(node), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:192");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:193");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:195");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    {printf(\"Leaving %s\\n\");}\n", stringify(name));

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:197");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n");

  };

}


void nodeForwardDeclaration(list node) {
  
if (globalTrace)
    printf("nodeForwardDeclaration at q/node.qon:199 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeForwardDeclaration", "199" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:201");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:202");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:204");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n%s %s(", stringify(nodeTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:208");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeFunctionArgs(cdr(assoc("intype", cdr(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:209");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(");");

  };

}


void nodeForwardDeclarations(list tree) {
  
if (globalTrace)
    printf("nodeForwardDeclarations at q/node.qon:211 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeForwardDeclarations", "211" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:215");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:216");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:218");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeForwardDeclaration(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:219");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeForwardDeclarations(cdr(tree));

  };

}


void nodeFunctions(list tree) {
  
if (globalTrace)
    printf("nodeFunctions at q/node.qon:221 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeFunctions", "221" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:225");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:226");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:227");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeFunction(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:227");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeFunctions(cdr(tree));

  };

}


void nodeIncludes(list nodes) {
  
if (globalTrace)
    printf("nodeIncludes at q/node.qon:229 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeIncludes", "229" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:231");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function read_file(filename) {return fs.readFileSync(filename);}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:232");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function write_file(filename, data) {fs.writeFileSync(filename, data);}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:233");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "var util = require('util');\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:234");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function printf() {process.stdout.write(util.format.apply(this, arguments));}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:235");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function qlog()   {process.stderr.write(util.format.apply(this, arguments));}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:236");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "var fs = require('fs');\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:237");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function equalString(a,b) {if (a==null) {return false;}if (b==null) {return false;}return a.toString()===b.toString() }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:238");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function panic(s){console.trace(s);process.exit(1);}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:239");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function dump(s){console.log(s)}");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:240");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function sub(a, b) { return a - b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:241");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function mult(a, b) { return a * b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:242");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function greaterthan(a, b) { return a > b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:243");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function subf(a, b) { return a - b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:244");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function multf(a, b) { return a * b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:245");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function greaterthanf(a, b) { return a > b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:246");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function equal(a, b) { return a == b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:247");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function andBool(a, b) { return a == b;}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:248");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function string_length(s) { return s.length;}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:249");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function sub_string(str, start, len) {str = ''+str;return str.substring(start, start+len)};\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:250");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function stringConcatenate(a, b) { return a + b}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:251");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function intToString(a) {}\n\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:252");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function gc_malloc( size ) {\nreturn {};\n}\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:253");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function makeArray(length) {\n   return [];\n}\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:254");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function at(arr, index) {\n  return arr[index];\n}\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:255");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function setAt(array, index, value) {\n    array[index] = value;\n}\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:256");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function getStringArray(index, strs) {\nreturn strs[index];\n}\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:257");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "var NULL = null;");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:258");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "var globalArgs;\nvar globalArgsCount;\nvar globalTrace = false;\nvar globalStepTrace = false;\nvar releaseMode = false;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:259");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function character(num) {}");

}


void nodeTypeDecl(list l) {
  
if (globalTrace)
    printf("nodeTypeDecl at q/node.qon:263 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeTypeDecl", "263" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:265");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:267");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:268");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s %s;\n", stringify(second(l)), stringify(nodeTypeMap(listLast(l))), stringify(first(l)));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:274");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:275");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s;\n", stringify(nodeTypeMap(listLast(l))), stringify(car(l)));

  };

}


void nodeStructComponents(list node) {
  
if (globalTrace)
    printf("nodeStructComponents at q/node.qon:280 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeStructComponents", "280" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:284");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:285");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:286");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeTypeDecl(car(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:286");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeStructComponents(cdr(node));

  };

}


void nodeStruct(list node) {
  
if (globalTrace)
    printf("nodeStruct at q/node.qon:288 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeStruct", "288" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:291");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeStructComponents(cdr(car(node)));

}


box nodeTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("nodeTypeMap at q/node.qon:293 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeTypeMap", "293" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:297");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:303");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:304");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:305");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


box nodeFuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("nodeFuncMap at q/node.qon:308 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeFuncMap", "308" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:311");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:313");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), NULL)))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:335");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:336");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return cdr(assoc(stringify(aSym), symMap));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:337");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return aSym;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:338");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


void nodeType(list node) {
  
if (globalTrace)
    printf("nodeType at q/node.qon:339 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeType", "339" );

}


void nodeTypes(list nodes) {
  
if (globalTrace)
    printf("nodeTypes at q/node.qon:343 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeTypes", "343" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:347");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:348");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:349");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeType(car(nodes));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:349");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeTypes(cdr(nodes));

  };

}


void nodeCompile(char* filename) {
  char* programStr = "";
list tree = NULL;
list program = NULL;

if (globalTrace)
    printf("nodeCompile at q/node.qon:351 (%s)\n", caller);

  StackTraceMove("in", "q/node.qon", "nodeCompile", "351" );

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:355");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:356");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:357");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:366");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = mergeIncludes(program);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:367");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeIncludes(cdr(assoc("includes", program)));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:368");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeTypes(childrenof(cdr(assoc("types", program))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:369");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nvar globalStackTrace = NULL;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:370");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nvar caller = \"\";\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:371");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nfunction isNil(p) {\n    return p == NULL;\n}\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:372");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:374");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:375");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("const [asfdasdf, ...qwerqwer] = process.argv;");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:376");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("globalArgs = qwerqwer;");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:377");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("globalArgsCount = qwerqwer.length;");

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:378");
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

            printf("\nStackTraceMove(\"out\", \"\", \"\", \"\");\n");

          };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:184");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          ansi3Return(node, indent);

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:186");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:187");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          ansi3Expression(node, indent);

        };

      };

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:188");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays(";\n");

}


void ansi3Body(list tree, int indent, char* functionName) {
  list code = NULL;

if (globalTrace)
    printf("ansi3Body at q/ansi3.qon:190 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Body", "190" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:192");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:193");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:195");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    code = tree;

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:196");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(code)) {
    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:199");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      code = car(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:200");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( not(releaseMode)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:203");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( inList(boxString(functionName), NoTrace_list())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:205");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("//Function %s omitted due to the no trace list\n", functionName);

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:206");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("\nif (globalTrace)\n    snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), stringify(getTagFail(car(code), boxString("line"), boxString("Line missing"))));

        };

      } else {
      };

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:211");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( not(releaseMode)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:212");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:213");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n");

    } else {
    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:216");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Statement(code, indent, functionName);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:217");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Body(cdr(tree), indent, functionName);

  };

}


void ansi3Declarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("ansi3Declarations at q/ansi3.qon:219 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Declarations", "219" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:221");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:222");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:224");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:225");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s = ", stringify(ansi3TypeMap(first(decl))), stringify(second(decl)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:229");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Expression(third(decl), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:230");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:231");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Declarations(cdr(decls), indent);

  };

}


void ansi3Function(list node) {
  box name = NULL;

if (globalTrace)
    printf("ansi3Function at q/ansi3.qon:233 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Function", "233" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:235");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = second(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:237");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:238");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:239");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:241");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:242");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s(", stringify(ansi3TypeMap(first(node))), stringify(second(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:246");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3FunctionArgs(third(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:247");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(") {");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:248");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:249");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Declarations(cdr(fourth(node)), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:250");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:251");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:254");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( inList(name, NoTrace_list())) {
      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:259");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("\nif (globalTrace)\n    printf(\"%s at %s:%s (%%s)\\n\", caller);\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

      };

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:260");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:261");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:263");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( inList(name, NoStackTrace_list())) {
      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:266");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("\n  StackTraceMove(\"in\", \"%s\", \"%s\", \"%s\" );\n", stringify(getTag(name, boxString("filename"))), stringify(name), stringify(getTag(name, boxString("line"))));

      };

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:269");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Body(cdr(fifth(node)), 1, stringify(name));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:271");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n");

  };

}


void ansi3ForwardDeclaration(list node) {
  
if (globalTrace)
    printf("ansi3ForwardDeclaration at q/ansi3.qon:273 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3ForwardDeclaration", "273" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:275");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:275");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:276");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n%s %s(", stringify(ansi3TypeMap(first(node))), stringify(second(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:280");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3FunctionArgs(third(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:281");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3displays(");");

  };

}


void ansi3ForwardDeclarations(list tree) {
  
if (globalTrace)
    printf("ansi3ForwardDeclarations at q/ansi3.qon:283 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3ForwardDeclarations", "283" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:285");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:285");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:286");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3ForwardDeclaration(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:287");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3ForwardDeclarations(cdr(tree));

  };

}


void ansi3Functions(list tree) {
  
if (globalTrace)
    printf("ansi3Functions at q/ansi3.qon:289 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Functions", "289" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:291");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:291");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:292");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Function(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:292");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Functions(cdr(tree));

  };

}


void ansi3Includes(list nodes) {
  
if (globalTrace)
    printf("ansi3Includes at q/ansi3.qon:295 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Includes", "295" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:297");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\n#include <unistd.h>\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\nbool releaseMode = false;\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:300");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n");

}


void ansi3TypeDecl(list l) {
  
if (globalTrace)
    printf("ansi3TypeDecl at q/ansi3.qon:303 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3TypeDecl", "303" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:305");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:307");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:308");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s %s;\n", stringify(second(l)), stringify(ansi3TypeMap(listLast(l))), stringify(first(l)));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:314");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:315");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s;\n", stringify(ansi3TypeMap(listLast(l))), stringify(car(l)));

  };

}


void ansi3StructComponents(list node) {
  
if (globalTrace)
    printf("ansi3StructComponents at q/ansi3.qon:320 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3StructComponents", "320" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:322");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:323");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:324");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3TypeDecl(car(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:324");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3StructComponents(cdr(node));

  };

}


void ansi3Struct(list node) {
  
if (globalTrace)
    printf("ansi3Struct at q/ansi3.qon:326 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Struct", "326" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:327");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3StructComponents(cdr(node));

}


box ansi3TypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("ansi3TypeMap at q/ansi3.qon:329 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3TypeMap", "329" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:331");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:335");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:336");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:337");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


box ansi3FuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("ansi3FuncMap at q/ansi3.qon:339 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3FuncMap", "339" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:341");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:343");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), NULL)))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:365");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:366");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return cdr(assoc(stringify(aSym), symMap));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:367");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return aSym;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:368");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


void ansi3Type(list node) {
  
if (globalTrace)
    printf("ansi3Type at q/ansi3.qon:370 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Type", "370" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:372");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(second(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:374");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\ntypedef struct %s {\n", stringify(first(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:375");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Struct(second(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:376");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n} %s;\n", stringify(first(node)));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:377");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3displays("typedef ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:377");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3TypeDecl(node);

  };

}


void ansi3Types(list nodes) {
  
if (globalTrace)
    printf("ansi3Types at q/ansi3.qon:380 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Types", "380" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:382");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:383");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:384");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Type(car(nodes));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:384");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Types(cdr(nodes));

  };

}


void ansi3Compile(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    printf("ansi3Compile at q/ansi3.qon:390 (%s)\n", caller);

  StackTraceMove("in", "q/ansi3.qon", "ansi3Compile", "390" );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Scanning file...%s\n", filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:397");
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
    snprintf(caller, 1024, "from q/ansi3.qon:401");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = buildProg(cons(boxString("q/shims/ansi3.qon"), getIncludes(tree)), getTypes(tree), getFunctions(tree));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Loading all includes\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:403");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Applying macros\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:405");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:406");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:407");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Printing program\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:413");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Includes(cdr(first(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:414");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Types(cdr(second(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:416");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("Box* globalStackTrace = NULL;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:417");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:419");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3ForwardDeclarations(cdr(third(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:420");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("\n\n//End forward declarations\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:421");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Functions(cdr(third(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:422");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("\n");

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Done printing program\n");

}


void ansi2displays(char* s) {
  
if (globalTrace)
    printf("ansi2displays at q/ansi2.qon:5 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2displays", "5" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:7");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", s);

}


void ansi2FunctionArgs(list tree) {
  
if (globalTrace)
    printf("ansi2FunctionArgs at q/ansi2.qon:11 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2FunctionArgs", "11" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:13");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:14");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:16");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(stringify(first(tree)), "...")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:17");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("...");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:19");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(ansi2TypeMap(first(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:20");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi2displays(" ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:21");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(second(tree));

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:23");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree))) {
    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:23");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi2displays(", ");

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:24");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2FunctionArgs(cddr(tree));

  };

}


void ansi2Expression(list tree, int indent) {
  list thing = NULL;

if (globalTrace)
    printf("ansi2Expression at q/ansi2.qon:28 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2Expression", "28" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:30");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:34");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equal(1, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:37");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:39");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("return"), car(tree))) {
      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:43");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        ansi2displays("()");

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:46");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      thing = first(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:47");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxSymbol("get-struct"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:50");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s->%s", stringify(second(tree)), stringify(third(tree)));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:55");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxSymbol("new"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:58");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("malloc(sizeof(%s))", stringify(third(tree)));

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:62");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("passthrough"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:65");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s", stringify(second(tree)));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:69");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("binop"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:72");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("(");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:73");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              ansi2Expression(third(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:74");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(" %s ", stringify(second(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:77");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              ansi2Expression(fourth(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:78");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:82");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s(", stringify(ansi2FuncMap(car(tree))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:86");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              ansi2RecurList(cdr(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:87");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            };

          };

        };

      };

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:95");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(ansi2FuncMap(tree));

  };

}


void ansi2RecurList(list expr, int indent) {
  
if (globalTrace)
    printf("ansi2RecurList at q/ansi2.qon:98 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2RecurList", "98" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:102");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:103");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:105");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Expression(car(expr), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:106");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:107");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi2displays("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:108");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi2displays(", ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:108");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi2RecurList(cdr(expr), indent);

    };

  };

}


void ansi2If(list node, int indent) {
  
if (globalTrace)
    printf("ansi2If at q/ansi2.qon:115 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2If", "115" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:117");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:118");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2displays("if ( ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:119");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2Expression(second(node), 0);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:120");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2displays(") {");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:121");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2Body(cdr(third(node)), add1(indent));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:122");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:123");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2displays("} else {");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:124");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2Body(cdr(fourth(node)), add1(indent));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:125");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:126");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2displays("}");

}


void ansi2SetStruct(list node, int indent) {
  
if (globalTrace)
    printf("ansi2SetStruct at q/ansi2.qon:128 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2SetStruct", "128" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:130");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:131");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->%s = ", stringify(second(node)), stringify(third(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:135");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2Expression(fourth(node), indent);

}


void ansi2GetStruct(list node, int indent) {
  
if (globalTrace)
    printf("ansi2GetStruct at q/ansi2.qon:137 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2GetStruct", "137" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:139");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:140");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->%s", stringify(first(node)), stringify(second(node)));

}


void ansi2Set(list node, int indent) {
  
if (globalTrace)
    printf("ansi2Set at q/ansi2.qon:145 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2Set", "145" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:147");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:148");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2Expression(first(cdr(node)), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:149");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(" = ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:150");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2Expression(third(node), indent);

}


void ansi2Return(list node, int indent) {
  
if (globalTrace)
    printf("ansi2Return at q/ansi2.qon:152 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2Return", "152" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:154");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:155");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(listLength(node), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:156");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2displays("return;");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:158");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2displays("return ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:159");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Expression(cadr(node), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:160");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2displays(";");

  };

}


void ansi2Statement(list node, int indent) {
  
if (globalTrace)
    printf("ansi2Statement at q/ansi2.qon:163 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2Statement", "163" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:165");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("set"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:166");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Set(node, indent);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:168");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("set-struct"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:169");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi2SetStruct(node, indent);

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:171");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:172");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        ansi2If(node, indent);

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:174");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("return"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:175");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          ansi2Return(node, indent);

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:177");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:178");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          ansi2Expression(node, indent);

        };

      };

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:179");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2displays(";\n");

}


void ansi2Body(list tree, int indent) {
  list code = NULL;

if (globalTrace)
    printf("ansi2Body at q/ansi2.qon:181 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2Body", "181" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:183");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:184");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:186");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    code = tree;

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:187");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(code)) {
    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:190");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      code = car(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:191");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), stringify(getTagFail(car(code), boxString("line"), boxString("Line missing"))));

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:192");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:193");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:196");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Statement(code, indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:197");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Body(cdr(tree), indent);

  };

}


void ansi2Declarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("ansi2Declarations at q/ansi2.qon:199 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2Declarations", "199" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:201");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:202");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:204");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:205");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s = ", stringify(ansi2TypeMap(first(decl))), stringify(second(decl)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:209");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Expression(third(decl), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:210");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:211");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Declarations(cdr(decls), indent);

  };

}


void ansi2Function(list node) {
  box name = NULL;

if (globalTrace)
    printf("ansi2Function at q/ansi2.qon:213 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2Function", "213" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:215");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = second(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:216");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:217");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:218");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:219");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:221");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:222");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s(", stringify(ansi2TypeMap(first(node))), stringify(second(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:226");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2FunctionArgs(third(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:227");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(") {");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:228");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:229");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Declarations(cdr(fourth(node)), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:230");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:231");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:233");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    printf(\"%s at %s:%s (%%s)\\n\", caller);\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:234");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:235");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:240");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Body(cdr(fifth(node)), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:241");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:242");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:244");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    printf(\"Leaving %s\\n\");\n", stringify(name));

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:246");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n");

  };

}


void ansi2ForwardDeclaration(list node) {
  
if (globalTrace)
    printf("ansi2ForwardDeclaration at q/ansi2.qon:248 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2ForwardDeclaration", "248" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:250");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:250");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:251");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n%s %s(", stringify(ansi2TypeMap(first(node))), stringify(second(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:255");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2FunctionArgs(third(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:256");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2displays(");");

  };

}


void ansi2ForwardDeclarations(list tree) {
  
if (globalTrace)
    printf("ansi2ForwardDeclarations at q/ansi2.qon:258 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2ForwardDeclarations", "258" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:260");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:260");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:261");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2ForwardDeclaration(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:262");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2ForwardDeclarations(cdr(tree));

  };

}


void ansi2Functions(list tree) {
  
if (globalTrace)
    printf("ansi2Functions at q/ansi2.qon:264 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2Functions", "264" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:266");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:266");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:267");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Function(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:267");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Functions(cdr(tree));

  };

}


void ansi2Includes(list nodes) {
  
if (globalTrace)
    printf("ansi2Includes at q/ansi2.qon:270 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2Includes", "270" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:272");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\nconst char* getEnv(char* key){return getenv(key);}\n void panic(char* s){abort();exit(1);}\nint sub(int a, int b) { return a - b; }\nfloat mult(int a, int b) { return a * b; }\nint greaterthan(int a, int b) { return a > b; }\nfloat subf(float a, float b) { return a - b; }\nfloat multf(float a, float b) { return a * b; }\nint greaterthanf(float a, float b) { return a > b; }\nint equal(int a, int b) { return a == b; }\nint equalString(char* a, char* b) { return !strcmp(a,b); }\nint andBool(int a, int b) { return a && b;}\nint string_length(char* s) { return strlen(s);}\nchar* setSubString(char* target, int start,char *source){target[start]=source[0]; return target;}\nchar* sub_string(char* s, int start, int length) {\nchar* substr = calloc(length+1, 1);\nstrncpy(substr, s+start, length);\nreturn substr;\n}\n\n\n\nchar* stringConcatenate(char* a, char* b) {\nint len = strlen(a) + strlen(b) + 1;\nchar* target = calloc(len,1);\nstrncat(target, a, len);\nstrncat(target, b, len);\nreturn target;\n}\n\nchar* intToString(int a) {\nint len = 100;\nchar* target = calloc(len,1);\nsnprintf(target, 99, \"%d\", a);\nreturn target;\n}\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\nvoid * gc_malloc( unsigned int size ) {\nreturn malloc( size);\n}\n\nint* makeArray(int length) {\n    int * array = gc_malloc(length*sizeof(int));\n    return array;\n}\n\nint at(int* arr, int index) {\n  return arr[index];\n}\n\nvoid setAt(int* array, int index, int value) {\n    array[index] = value;\n}\n\nchar * read_file(char * filename) {\nchar * buffer = 0;\nlong length;\nFILE * f = fopen (filename, \"rb\");\n\nif (f)\n{\n  fseek (f, 0, SEEK_END);\n  length = ftell (f);\n  fseek (f, 0, SEEK_SET);\n  buffer = calloc (length+1,1);\n  if (buffer == NULL) {\n  printf(\"Malloc failed!\\n\");\n  exit(1);\n}\n  if (buffer)\n  {\n    fread (buffer, 1, length, f);\n  }\n  fclose (f);\n}\nreturn buffer;\n}\n\n\nvoid write_file (char * filename, char * data) {\nFILE *f = fopen(filename, \"w\");\nif (f == NULL)\n{\n    printf(\"Error opening file!\");\n    exit(1);\n}\n\nfprintf(f, \"%s\", data);\n\nfclose(f);\n}\n\nchar* getStringArray(int index, char** strs) {\nreturn strs[index];\n}\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\n\nint main( int argc, char *argv[] )  {\n  globalArgs = argv;\n  globalArgsCount = argc;\n  caller=calloc(1024,1);\n\n  return start();\n\n}\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:275");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "char * character(int num) { char *string = malloc(2); if (!string) return 0; string[0] = num; string[1] = 0; return string; }");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:275");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:276");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "bool nand(bool a, bool b) { return !(a&&b); }\n//End include block\n");

}


void ansi2TypeDecl(list l) {
  
if (globalTrace)
    printf("ansi2TypeDecl at q/ansi2.qon:279 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2TypeDecl", "279" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:281");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:283");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:284");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s %s;\n", stringify(second(l)), stringify(ansi2TypeMap(listLast(l))), stringify(first(l)));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:290");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:291");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s;\n", stringify(ansi2TypeMap(listLast(l))), stringify(car(l)));

  };

}


void ansi2StructComponents(list node) {
  
if (globalTrace)
    printf("ansi2StructComponents at q/ansi2.qon:296 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2StructComponents", "296" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:298");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:299");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:300");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2TypeDecl(car(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:300");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2StructComponents(cdr(node));

  };

}


void ansi2Struct(list node) {
  
if (globalTrace)
    printf("ansi2Struct at q/ansi2.qon:302 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2Struct", "302" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:303");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2StructComponents(cdr(node));

}


box ansi2TypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("ansi2TypeMap at q/ansi2.qon:305 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2TypeMap", "305" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:307");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:313");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:314");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:315");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


box ansi2FuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("ansi2FuncMap at q/ansi2.qon:317 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2FuncMap", "317" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:319");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:321");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), NULL)))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:343");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:344");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return cdr(assoc(stringify(aSym), symMap));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:345");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return aSym;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:346");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


void ansi2Type(list node) {
  
if (globalTrace)
    printf("ansi2Type at q/ansi2.qon:348 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2Type", "348" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:350");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(second(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:352");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\ntypedef struct %s {\n", stringify(first(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:353");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Struct(second(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:354");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n} %s;\n", stringify(first(node)));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:355");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2displays("typedef ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:355");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2TypeDecl(node);

  };

}


void ansi2Types(list nodes) {
  
if (globalTrace)
    printf("ansi2Types at q/ansi2.qon:358 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2Types", "358" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:360");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:361");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:362");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Type(car(nodes));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:362");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Types(cdr(nodes));

  };

}


void ansi2Compile(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    printf("ansi2Compile at q/ansi2.qon:368 (%s)\n", caller);

  StackTraceMove("in", "q/ansi2.qon", "ansi2Compile", "368" );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Scanning file...%s\n", filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:375");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Building sexpr\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:378");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:379");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:380");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:381");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Printing program\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:387");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2Includes(cdr(first(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:388");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2Types(cdr(second(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:390");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2displays("Box* globalStackTrace = NULL;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:391");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2displays("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:393");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2ForwardDeclarations(cdr(third(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:394");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2displays("\n\n//End forward declarations\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:395");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2Functions(cdr(third(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:396");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2displays("\n");

}


void ansiFunctionArgs(list tree) {
  
if (globalTrace)
    printf("ansiFunctionArgs at q/ansi.qon:3 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiFunctionArgs", "3" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:5");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:6");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:8");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(ansiTypeMap(first(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:9");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:10");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(second(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:11");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:11");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:11");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(",");

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:12");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiFunctionArgs(cddr(tree));

  };

}


void ansiLeaf(list thisNode, int indent) {
  
if (globalTrace)
    printf("ansiLeaf at q/ansi.qon:14 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiLeaf", "14" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:15");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  display(ansiFuncMap(codeof(thisNode)));

}


void ansiStructGetterExpression(list thisNode, int indent) {
  
if (globalTrace)
    printf("ansiStructGetterExpression at q/ansi.qon:17 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiStructGetterExpression", "17" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:19");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("structGetter"), subnameof(thisNode))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:20");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiGetStruct(thisNode, indent);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:21");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiLeaf(thisNode, indent);

  };

}


void ansiExpression(list node, int indent) {
  
if (globalTrace)
    printf("ansiExpression at q/ansi.qon:23 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiExpression", "23" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:25");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isLeaf(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:26");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(ansiFuncMap(codeof(node)));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:27");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiSubExpression(node, indent);

  };

}


void ansiRecurList(list expr, int indent) {
  
if (globalTrace)
    printf("ansiRecurList at q/ansi.qon:29 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiRecurList", "29" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:33");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:34");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:36");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiExpression(car(expr), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:37");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:38");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:39");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(", ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:39");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansiRecurList(cdr(expr), indent);

    };

  };

}


void ansiSubExpression(list tree, int indent) {
  box thing = NULL;

if (globalTrace)
    printf("ansiSubExpression at q/ansi.qon:41 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiSubExpression", "41" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:43");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:44");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:46");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNode(childrenof(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:47");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansiSubExpression(childrenof(tree), indent);

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:49");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isLeaf(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:50");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        display(ansiFuncMap(codeof(tree)));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:52");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equal(1, listLength(childrenof(tree)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:54");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          display(codeof(car(childrenof(tree))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:55");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxString("return"), codeof(car(childrenof(tree))))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:58");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("");

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:59");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("()");

          };

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:61");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          thing = codeof(car(childrenof(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:62");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("get-struct"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:64");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s->%s", stringify(codeof(second(childrenof(tree)))), stringify(codeof(third(childrenof(tree)))));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:69");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("new"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:71");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("malloc(sizeof(%s))", stringify(codeof(third(childrenof(tree)))));

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:75");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s(", stringify(ansiFuncMap(codeof(car(childrenof(tree))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:79");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              ansiRecurList(cdr(childrenof(tree)), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:80");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            };

          };

        };

      };

    };

  };

}


void ansiIf(list node, int indent) {
  
if (globalTrace)
    printf("ansiIf at q/ansi.qon:81 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiIf", "81" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:83");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:84");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("if ( ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:85");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiExpression(car(first(childrenof(node))), 0);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:86");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(") {");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:87");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiBody(second(childrenof(node)), add1(indent));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:88");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:89");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("} else {");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:90");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiBody(third(childrenof(node)), add1(indent));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:91");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:92");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("}");

}


void ansiSetStruct(list node, int indent) {
  
if (globalTrace)
    printf("ansiSetStruct at q/ansi.qon:94 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiSetStruct", "94" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:96");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:97");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->%s = ", stringify(first(codeof(node))), stringify(second(codeof(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:101");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiExpression(childrenof(node), indent);

}


void ansiGetStruct(list node, int indent) {
  
if (globalTrace)
    printf("ansiGetStruct at q/ansi.qon:103 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiGetStruct", "103" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:105");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:106");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->%s", stringify(first(codeof(node))), stringify(second(codeof(node))));

}


void ansiSet(list node, int indent) {
  
if (globalTrace)
    printf("ansiSet at q/ansi.qon:111 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiSet", "111" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:113");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:114");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s = ", stringify(first(codeof(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:115");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiExpression(childrenof(node), indent);

}


void ansiStatement(list node, int indent) {
  
if (globalTrace)
    printf("ansiStatement at q/ansi.qon:117 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiStatement", "117" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:119");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("setter"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:120");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiSet(node, indent);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:122");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("structSetter"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:123");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansiSetStruct(node, indent);

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:125");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:126");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        ansiIf(node, indent);

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:128");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("returnvoid"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:129");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:129");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("return");

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:131");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:132");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          ansiExpression(childrenof(node), indent);

        };

      };

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:133");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(";\n");

}


void ansiBody(list tree, int indent) {
  list code = NULL;

if (globalTrace)
    printf("ansiBody at q/ansi.qon:135 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiBody", "135" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:137");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:138");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:141");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    code = codeof(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:142");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(code)) {
    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:145");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      code = car(codeof(car(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:146");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:147");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:148");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("if (globalTrace)   snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail(code, boxString("filename"), boxString("Unknown"))), stringify(getTagFail(code, boxString("line"), boxString("Unknown"))));

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:149");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:150");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:153");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiStatement(car(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:154");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiBody(cdr(tree), indent);

  };

}


void ansiDeclarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("ansiDeclarations at q/ansi.qon:156 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiDeclarations", "156" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:158");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:159");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:161");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:162");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s = ", stringify(ansiTypeMap(first(decl))), stringify(second(decl)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:166");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(ansiFuncMap(third(decl)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:167");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:168");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiDeclarations(cdr(decls), indent);

  };

}


void ansiFunction(list node) {
  box name = NULL;

if (globalTrace)
    printf("ansiFunction at q/ansi.qon:170 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiFunction", "170" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:172");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = subnameof(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:173");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:174");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:175");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:176");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:178");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:179");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s(", stringify(ansiTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:183");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiFunctionArgs(cdr(assoc("intype", cdr(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:184");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(") {");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:185");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:186");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiDeclarations(declarationsof(node), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:187");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:188");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:190");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    fprintf(stderr, \"%s at %s:%s (%%s)\\n\", caller);\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:191");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:192");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:196");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiBody(childrenof(node), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:197");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:198");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:200");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    fprintf(stderr, \"Leaving %s\\n\");\n", stringify(name));

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:202");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n");

  };

}


void ansiForwardDeclaration(list node) {
  
if (globalTrace)
    printf("ansiForwardDeclaration at q/ansi.qon:204 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiForwardDeclaration", "204" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:206");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:207");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:209");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n%s %s(", stringify(ansiTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:213");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiFunctionArgs(cdr(assoc("intype", cdr(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:214");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(");");

  };

}


void ansiForwardDeclarations(list tree) {
  
if (globalTrace)
    printf("ansiForwardDeclarations at q/ansi.qon:216 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiForwardDeclarations", "216" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:218");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:219");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:221");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiForwardDeclaration(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:222");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiForwardDeclarations(cdr(tree));

  };

}


void ansiFunctions(list tree) {
  
if (globalTrace)
    printf("ansiFunctions at q/ansi.qon:224 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiFunctions", "224" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:226");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:227");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:228");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiFunction(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:228");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiFunctions(cdr(tree));

  };

}


void ansiIncludes(list nodes) {
  
if (globalTrace)
    printf("ansiIncludes at q/ansi.qon:229 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiIncludes", "229" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:231");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\nconst char* getEnv(char* key){return getenv(key);}\n void panic(char* s){abort();exit(1);}\nint not(int a){return !a;}\nint sub(int a, int b) { return a - b; }\nfloat mult(int a, int b) { return a * b; }\nint greaterthan(int a, int b) { return a > b; }\nfloat subf(float a, float b) { return a - b; }\nfloat multf(float a, float b) { return a * b; }\nint greaterthanf(float a, float b) { return a > b; }\nint equal(int a, int b) { return a == b; }\nint equalString(char* a, char* b) { return !strcmp(a,b); }\nint andBool(int a, int b) { return a && b;}\nint string_length(char* s) { return strlen(s);}\nchar* setSubString(char* target, int start,char *source){target[start]=source[0]; return target;}\nchar* sub_string(char* s, int start, int length) {\nchar* substr = calloc(length+1, 1);\nstrncpy(substr, s+start, length);\nreturn substr;\n}\n\n\n\nchar* stringConcatenate(char* a, char* b) {\nint len = strlen(a) + strlen(b) + 1;\nchar* target = calloc(len,1);\nstrncat(target, a, len);\nstrncat(target, b, len);\nreturn target;\n}\n\nchar* intToString(int a) {\nint len = 100;\nchar* target = calloc(len,1);\nsnprintf(target, 99, \"%d\", a);\nreturn target;\n}\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\nvoid * gc_malloc( unsigned int size ) {\nreturn malloc(size);\n}\n\nint* makeArray(int length) {\n    int * array = gc_malloc(length*sizeof(int));\n    return array;\n}\n\nint at(int* arr, int index) {\n  return arr[index];\n}\n\nvoid setAt(int* array, int index, int value) {\n    array[index] = value;\n}\n\nchar * read_file(char * filename) {\nchar * buffer = 0;\nlong length;\nFILE * f = fopen (filename, \"rb\");\n\nif (f)\n{\n  fseek (f, 0, SEEK_END);\n  length = ftell (f);\n  fseek (f, 0, SEEK_SET);\n  buffer = calloc (length+1,1);\n  if (buffer == NULL) {\n  printf(\"Malloc failed!\\n\");\n  exit(1);\n}\n  if (buffer)\n  {\n    fread (buffer, 1, length, f);\n  }\n  fclose (f);\n}\nreturn buffer;\n}\n\n\nvoid write_file (char * filename, char * data) {\nFILE *f = fopen(filename, \"w\");\nif (f == NULL)\n{\n    printf(\"Error opening file!\");\n    exit(1);\n}\n\nfprintf(f, \"%s\", data);\n\nfclose(f);\n}\n\nchar* getStringArray(int index, char** strs) {\nreturn strs[index];\n}\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\n\nint main( int argc, char *argv[] )  {\n  globalArgs = argv;\n  globalArgsCount = argc;\n  caller=calloc(1024,1);\n\n  return start();\n\n}\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:234");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "char * character(int num) { char *string = malloc(2); if (!string) return 0; string[0] = num; string[1] = 0; return string; }");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:235");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:236");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "bool nand(bool a, bool b) { return !(a&&b); }\n//End include block\n");

}


void ansiTypeDecl(list l) {
  
if (globalTrace)
    printf("ansiTypeDecl at q/ansi.qon:239 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiTypeDecl", "239" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:241");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:243");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:244");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s %s;\n", stringify(second(l)), stringify(ansiTypeMap(listLast(l))), stringify(first(l)));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:250");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:251");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s;\n", stringify(ansiTypeMap(listLast(l))), stringify(car(l)));

  };

}


void ansiStructComponents(list node) {
  
if (globalTrace)
    printf("ansiStructComponents at q/ansi.qon:256 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiStructComponents", "256" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:258");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:259");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:260");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiTypeDecl(car(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:260");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiStructComponents(cdr(node));

  };

}


void ansiStruct(list node) {
  
if (globalTrace)
    printf("ansiStruct at q/ansi.qon:262 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiStruct", "262" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:263");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiStructComponents(cdr(car(node)));

}


box ansiTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("ansiTypeMap at q/ansi.qon:265 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiTypeMap", "265" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:267");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:273");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:274");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:275");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


box ansiFuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("ansiFuncMap at q/ansi.qon:277 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiFuncMap", "277" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:279");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:281");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), NULL)))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:303");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:304");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return cdr(assoc(stringify(aSym), symMap));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:305");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return aSym;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:306");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


void ansiType(list node) {
  
if (globalTrace)
    printf("ansiType at q/ansi.qon:308 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiType", "308" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:310");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(subnameof(node), boxString("struct"))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:312");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\ntypedef struct %s {\n", stringify(first(codeof(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:313");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiStruct(cdr(codeof(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:314");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n} %s;\n", stringify(first(codeof(node))));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:315");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("typedef ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:315");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiTypeDecl(codeof(node));

  };

}


void ansiTypes(list nodes) {
  
if (globalTrace)
    printf("ansiTypes at q/ansi.qon:318 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiTypes", "318" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:320");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:321");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:322");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiType(car(nodes));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:322");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiTypes(cdr(nodes));

  };

}


void ansiCompile(char* filename) {
  char* programStr = "";
list tree = NULL;
list program = NULL;

if (globalTrace)
    printf("ansiCompile at q/ansi.qon:328 (%s)\n", caller);

  StackTraceMove("in", "q/ansi.qon", "ansiCompile", "328" );

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:332");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("//Scanning file...%s\n", filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:333");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:334");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("//Building sexpr\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:335");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:336");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:339");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("//Building AST\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:340");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:350");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("//Merging ASTs\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:351");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = mergeIncludes(program);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:352");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("//Printing program\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:353");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiIncludes(cdr(assoc("includes", program)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:354");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiTypes(childrenof(cdr(assoc("types", program))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:355");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("Box* globalStackTrace = NULL;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:356");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:358");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiForwardDeclarations(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:360");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n//End forward declarations\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:361");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:363");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n");

}


list numbers(int num) {
  
if (globalTrace)
    printf("numbers at q/perl.qon:4 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "numbers", "4" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:6");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(0, num)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:7");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cons(boxString("-"), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:8");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cons(boxString(stringify(boxInt(num))), numbers(sub1(num)));;

  };

}


char* lexType(box abox) {
  
if (globalTrace)
    printf("lexType at q/perl.qon:11 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "lexType", "11" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:14");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("string", boxType(abox))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:15");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return "string";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:17");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(boxString(sub_string(stringify(abox), 0, 1)), numbers(9))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:18");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return "number";;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:19");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return "symbol";;

    };

  };

}


void perlLeaf(list thisNode, int indent) {
  
if (globalTrace)
    printf("perlLeaf at q/perl.qon:23 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlLeaf", "23" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:25");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", lexType(codeof(thisNode)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:26");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s", dollar());

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:27");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:29");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  display(perlFuncMap(codeof(thisNode)));

}


void perlStructGetterExpression(list thisNode, int indent) {
  
if (globalTrace)
    printf("perlStructGetterExpression at q/perl.qon:32 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlStructGetterExpression", "32" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:34");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("structGetter"), subnameof(thisNode))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:35");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlGetStruct(thisNode, indent);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:36");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlLeaf(thisNode, indent);

  };

}


void perlExpression(list node, int indent) {
  
if (globalTrace)
    printf("perlExpression at q/perl.qon:38 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlExpression", "38" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:40");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isLeaf(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:41");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlLeaf(node, indent);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:42");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlSubExpression(node, indent);

  };

}


void perlRecurList(list expr, int indent) {
  
if (globalTrace)
    printf("perlRecurList at q/perl.qon:44 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlRecurList", "44" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:46");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:47");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:49");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlExpression(car(expr), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:50");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:51");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:52");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(", ");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:52");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      perlRecurList(cdr(expr), indent);

    };

  };

}


void perlSubExpression(list tree, int indent) {
  box thing = NULL;

if (globalTrace)
    printf("perlSubExpression at q/perl.qon:55 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlSubExpression", "55" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:57");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:58");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:60");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNode(childrenof(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:61");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      perlSubExpression(childrenof(tree), indent);

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:63");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isLeaf(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:65");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s", dollar());

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:66");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        display(perlFuncMap(codeof(tree)));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:68");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equal(1, listLength(childrenof(tree)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:70");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          display(codeof(car(childrenof(tree))));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:71");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxString("return"), codeof(car(childrenof(tree))))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:74");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("");

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:75");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("()");

          };

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:77");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          thing = codeof(car(childrenof(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:78");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("get-struct"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:80");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s%s->{%s}", dollar(), stringify(codeof(second(childrenof(tree)))), stringify(codeof(third(childrenof(tree)))));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:82");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("new"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:84");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("{}");

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:86");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s(", stringify(perlFuncMap(codeof(car(childrenof(tree))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:90");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              perlRecurList(cdr(childrenof(tree)), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:91");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            };

          };

        };

      };

    };

  };

}


void perlIf(list node, int indent) {
  
if (globalTrace)
    printf("perlIf at q/perl.qon:93 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlIf", "93" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:95");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:96");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("if ( ");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:97");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlExpression(car(first(childrenof(node))), 0);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:98");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(") {");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:99");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlBody(second(childrenof(node)), add1(indent));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:100");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:101");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("} else {");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:102");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlBody(third(childrenof(node)), add1(indent));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:103");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:104");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("}");

}


void perlSetStruct(list node, int indent) {
  
if (globalTrace)
    printf("perlSetStruct at q/perl.qon:106 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlSetStruct", "106" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:109");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:110");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s->{%s} = ", dollar(), stringify(first(codeof(node))), stringify(second(codeof(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:111");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlExpression(childrenof(node), indent);

}


void perlGetStruct(list node, int indent) {
  
if (globalTrace)
    printf("perlGetStruct at q/perl.qon:113 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlGetStruct", "113" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:115");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:116");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s->{%s}", dollar(), stringify(first(codeof(node))), stringify(second(codeof(node))));

}


void perlSet(list node, int indent) {
  
if (globalTrace)
    printf("perlSet at q/perl.qon:118 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlSet", "118" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:120");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:121");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s = ", dollar(), stringify(first(codeof(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:122");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlExpression(childrenof(node), indent);

}


void assertNode(list node) {
  
if (globalTrace)
    printf("assertNode at q/perl.qon:124 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "assertNode", "124" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:126");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNode(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:127");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:128");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Not a node!");

  };

}


void perlStatement(list node, int indent) {
  box functionName = NULL;

if (globalTrace)
    printf("perlStatement at q/perl.qon:131 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlStatement", "131" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:135");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assertNode(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:136");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("setter"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:137");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlSet(node, indent);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:139");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("structSetter"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:140");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      perlSetStruct(node, indent);

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:142");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:143");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        perlIf(node, indent);

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:145");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("returnvoid"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:147");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          functionName = functionNameof(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:148");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("\n#Returnvoid\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:149");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:151");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:151");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("return");

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:153");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxString("return"), subnameof(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:155");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            functionName = functionNameof(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:156");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( inList(functionName, noStackTrace())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:157");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("");

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:159");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("\n#standard return: %s\n", stringify(functionName));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:160");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:161");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s%s%s", "if (", dollar(), "globalTrace) {printf(\"Leaving \\n\")}\n");

            };

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:163");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:164");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            perlExpression(childrenof(node), indent);

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:167");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( inList(functionName, noStackTrace())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:168");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("");

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:170");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("\n#standard expression\n");

            };

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:173");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:174");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            perlExpression(childrenof(node), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:175");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            newLine(indent);

          };

        };

      };

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:178");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(";\n");

}


void perlBody(list tree, int indent) {
  
if (globalTrace)
    printf("perlBody at q/perl.qon:180 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlBody", "180" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:182");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:183");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:185");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:186");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s%s%s", "if (", dollar(), "globalStepTrace) {printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__)}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:187");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlStatement(car(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:188");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlBody(cdr(tree), indent);

  };

}


void perlDeclarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("perlDeclarations at q/perl.qon:190 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlDeclarations", "190" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:192");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:193");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:195");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:196");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("my %s%s = ", dollar(), stringify(second(decl)));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:197");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(perlConstMap(third(decl)));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:198");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:199");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlDeclarations(cdr(decls), indent);

  };

}


void perlFunction(list node) {
  box name = NULL;

if (globalTrace)
    printf("perlFunction at q/perl.qon:201 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlFunction", "201" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:203");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = subnameof(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:204");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n#Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:208");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:209");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:210");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:212");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:213");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("sub %s", stringify(subnameof(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:214");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" {");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:215");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:216");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlFunctionArgs(cdr(assoc("intype", cdr(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:217");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:218");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlDeclarations(declarationsof(node), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:219");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\nif (%sglobalTrace) { printf(\"%s at %s:%s\\n\") }\n", dollar(), stringify(subnameof(node)), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:220");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(name, noStackTrace())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:221");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:223");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:225");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlBody(childrenof(node), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:226");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(name, noStackTrace())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:227");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:229");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:231");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n");

  };

}


void perlForwardDeclaration(list node) {
  
if (globalTrace)
    printf("perlForwardDeclaration at q/perl.qon:233 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlForwardDeclaration", "233" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:235");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:236");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:238");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\nsub %s", stringify(subnameof(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:241");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";");

  };

}


void perlForwardDeclarations(list tree) {
  
if (globalTrace)
    printf("perlForwardDeclarations at q/perl.qon:243 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlForwardDeclarations", "243" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:245");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:246");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:248");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlForwardDeclaration(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:249");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlForwardDeclarations(cdr(tree));

  };

}


void perlFunctions(list tree) {
  
if (globalTrace)
    printf("perlFunctions at q/perl.qon:251 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlFunctions", "251" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:253");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:254");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:255");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlFunction(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:255");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlFunctions(cdr(tree));

  };

}


char* dollar() {
  
if (globalTrace)
    printf("dollar at q/perl.qon:258 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "dollar", "258" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:259");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return character(36);;

}


char* atSym() {
  
if (globalTrace)
    printf("atSym at q/perl.qon:261 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "atSym", "261" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:262");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return character(64);;

}


void perlIncludes(list nodes) {
  
if (globalTrace)
    printf("perlIncludes at q/perl.qon:265 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlIncludes", "265" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:267");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s\n", "use strict;");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:268");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s", "my ", dollar(), "caller;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:269");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s", "my ", dollar(), "releaseMode;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:270");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s\n", "use Carp;");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:271");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  dollar();

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:272");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s\n", "use Carp::Always;");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:273");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub greaterthan { ", dollar(), "_[0] > ", dollar(), "_[1] };");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:274");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s\n", "sub qlog { warn ", "@", "_ };");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:275");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub mult { ", dollar(), "_[0] * ", dollar(), "_[1] };");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:276");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub multf { ", dollar(), "_[0] * ", dollar(), "_[1] };");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:277");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub greaterthanf { ", dollar(), "_[0] > ", dollar(), "_[1] };");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:278");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub equalString { ", dollar(), "_[0] eq ", dollar(), "_[1] };");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:285");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("sub read_file { my %sfile = shift; %sfile || die \"Empty file name!!!\"; open my %sfh, '<', %sfile or die; local %s/ = undef; my %scont = <%sfh>; close %sfh; return %scont; }; \n", dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar());

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:287");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("sub write_file {my %sfile = shift; my %sdata = shift; %sfile || die \"Empty file name!!!\"; open my %sfh, '>', %sfile or die; print %sfh %sdata; close %sfh; } \n", dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar());

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:289");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub stringConcatenate { ", dollar(), "_[0] . ", dollar(), "_[1]}");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:290");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub subtract { ", dollar(), "_[0] - ", dollar(), "_[1]}");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:291");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub subf { ", dollar(), "_[0] - ", dollar(), "_[1]}");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:292");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub andBool { ", dollar(), "_[0] && ", dollar(), "_[1]}");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:293");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub equal { ", dollar(), "_[0] == ", dollar(), "_[1]}");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:294");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub panic { carp ", atSym(), "_; die \"", atSym(), "_\"}");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:295");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("sub intToString { return %s_[0]}\n", dollar());

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:296");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("sub character { return chr(%s_[0])}\n", dollar());

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:297");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s%s%s%s%s\n", "sub getStringArray { my ", dollar(), "index = shift; my ", dollar(), "arr = shift; return ", dollar(), "arr->[", dollar(), "index]}");

}


void perlTypeDecl(list l) {
  
if (globalTrace)
    printf("perlTypeDecl at q/perl.qon:301 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlTypeDecl", "301" );

}


void perlStructComponents(list node) {
  
if (globalTrace)
    printf("perlStructComponents at q/perl.qon:306 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlStructComponents", "306" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:308");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:309");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:310");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlTypeDecl(car(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:310");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlStructComponents(cdr(node));

  };

}


void perlStruct(list node) {
  
if (globalTrace)
    printf("perlStruct at q/perl.qon:312 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlStruct", "312" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:313");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlStructComponents(cdr(car(node)));

}


box perlTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("perlTypeMap at q/perl.qon:315 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlTypeMap", "315" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:317");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:323");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:324");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:325");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


box perlConstMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("perlConstMap at q/perl.qon:327 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlConstMap", "327" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:329");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:331");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("false"), boxSymbol("0"), alistCons(boxSymbol("nil"), boxSymbol("undef"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:334");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cdr(assocFail(stringify(aSym), symMap, aSym));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:335");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


box perlFuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("perlFuncMap at q/perl.qon:337 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlFuncMap", "337" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:339");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:341");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("sub"), boxSymbol("subtract"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("substr"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("length"), alistCons(boxSymbol("nil"), boxSymbol("undef"), NULL))))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:351");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cdr(assocFail(stringify(aSym), symMap, aSym));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:352");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return aSym;;

  };

}


void perlType(list node) {
  
if (globalTrace)
    printf("perlType at q/perl.qon:354 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlType", "354" );

}


void perlTypes(list nodes) {
  
if (globalTrace)
    printf("perlTypes at q/perl.qon:359 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlTypes", "359" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:361");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:362");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:363");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlType(car(nodes));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:363");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlTypes(cdr(nodes));

  };

}


void perlFunctionArgs(list tree) {
  
if (globalTrace)
    printf("perlFunctionArgs at q/perl.qon:365 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlFunctionArgs", "365" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:367");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:368");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:370");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s%s", "my ", dollar());

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:371");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(second(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:372");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" = shift;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:373");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlFunctionArgs(cddr(tree));

  };

}


void perlCompile(char* filename) {
  char* programStr = "";
list tree = NULL;
list program = NULL;

if (globalTrace)
    printf("perlCompile at q/perl.qon:375 (%s)\n", caller);

  StackTraceMove("in", "q/perl.qon", "perlCompile", "375" );

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:377");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:378");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:379");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:387");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = mergeIncludes(program);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:388");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlIncludes(cdr(assoc("includes", program)));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:389");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlTypes(childrenof(cdr(assoc("types", program))));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:391");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("use strict;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:392");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("use Carp;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:393");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("use Data::Dumper;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:394");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s", "my ", dollar(), "globalStackTrace = undef;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:395");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s", "my ", dollar(), "globalTrace = undef;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:396");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s", "my ", dollar(), "globalStepTrace = undef;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:397");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s", "my ", dollar(), "globalArgs = undef;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:398");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s", "my ", dollar(), "globalArgsCount = undef;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:399");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s\n", "my ", dollar(), "true = 1;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:400");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s", "my ", dollar(), "false = 0;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:401");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s", "my ", dollar(), "undef;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:402");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s", "\nsub isNil {\n    return !defined(", dollar(), "_[0]);\n}\n\n\n#Forward declarations\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:404");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlForwardDeclarations(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:406");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n#End forward declarations\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:407");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:409");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(";\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:410");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s", dollar(), "globalArgs = [ 1, ", atSym(), "ARGV];");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:411");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s", dollar(), "globalArgsCount = scalar(", atSym(), "ARGV)+1;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:412");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("start();");

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
  //Function car omitted due to no trace list
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
  //Function cdr omitted due to no trace list
//Function cdr omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assertType("list", l, 25, "q/lists.qon");
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
//Function cons omitted due to no trace list
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


bool isList(box b) {
  //Function isList omitted due to no trace list

  StackTraceMove("in", "q/lists.qon", "isList", "58" );
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
    printf("emptyList at q/lists.qon:65 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "emptyList", "65" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:65");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return NULL;;

}


bool isEmpty(box b) {
  //Function isEmpty omitted due to no trace list
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
    printf("listLength at q/lists.qon:74 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "listLength", "74" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:78");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:79");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return 0;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:80");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return add1(listLength(cdr(l)));;

  };

}


list alistCons(box key, box value, list alist) {
  
if (globalTrace)
    printf("alistCons at q/lists.qon:83 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "alistCons", "83" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:84");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return cons(cons(key, value), alist);;

}


list assoc(char* searchTerm, list l) {
  list elem = NULL;

if (globalTrace)
    printf("assoc at q/lists.qon:86 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "assoc", "86" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:88");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assertType("list", l, 88, "q/lists.qon");

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:90");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:91");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return boxBool(false);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:93");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    elem = car(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:94");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    assertType("list", elem, 94, "q/lists.qon");

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:95");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isEmpty(elem)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:96");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return assoc(searchTerm, cdr(l));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:98");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( false) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:98");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("Comparing %s and %s\n", searchTerm, stringify(car(elem)));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:98");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("");

      };

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:99");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(searchTerm, stringify(car(elem)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:102");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

        return elem;;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:103");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

        return assoc(searchTerm, cdr(l));;

      };

    };

  };

}


char* chooseBox(char* aType) {
  
if (globalTrace)
    printf("chooseBox at q/lists.qon:106 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "chooseBox", "106" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:108");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("string", aType)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:109");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return "boxString";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:110");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("symbol", aType)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:111");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return "boxSymbol";;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:112");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("bool", aType)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:113");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

        return "boxBool";;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:114");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("int", aType)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:115");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

          return "boxInt";;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:116");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("float", aType)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:117");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

            return "boxFloat";;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:118");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            panic("Invalid type");

          };

        };

      };

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:119");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return "";;

}


box mlistLiteral(box b) {
  
if (globalTrace)
    printf("mlistLiteral at q/lists.qon:122 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "mlistLiteral", "122" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:124");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:125");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:127");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("string", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:128");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return b;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:130");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("bool", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:132");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

        return b;;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:134");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("int", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:135");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

          return b;;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:137");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("symbol", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:138");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

            return boxString(unBoxSymbol(b));;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:142");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

            return boxString(stringConcatenate("Unsupported type: ", boxType(b)));;

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
    printf("doMultiList at q/lists.qon:146 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "doMultiList", "146" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:148");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:149");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cons(boxSymbol("nil"), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:151");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:152");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return NULL;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:155");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      elem = first(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:156");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      newlist = cons(boxString(chooseBox(elem->typ)), cons(mlistLiteral(first(l)), newlist));

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:157");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ret = cons(cons(boxSymbol("cons"), cons(newlist, doMultiList(cdr(l)))), NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:166");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return ret;;

    };

  };

}


bool isInt(char* val) {
  char* firstLetter = sub_string(val, 0, 1);

if (globalTrace)
    printf("isInt at q/lists.qon:168 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "isInt", "168" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:172");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("-", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:173");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:174");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("0", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:175");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:176");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("1", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:177");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

        return true;;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:178");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("2", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:179");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

          return true;;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:180");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("3", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:181");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

            return true;;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:182");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalString("4", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:183");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

              return true;;

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:184");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              if ( equalString("5", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:185");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

                return true;;

              } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:186");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                if ( equalString("6", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:187");
                  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

                  return true;;

                } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:188");
                  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                  if ( equalString("7", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:189");
                    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

                    return true;;

                  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:190");
                    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                    if ( equalString("8", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:191");
                      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

                      return true;;

                    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:192");
                      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                      if ( equalString("9", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:193");
                        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

                        return true;;

                      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:194");
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
    printf("id at q/lists.qon:196 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "id", "196" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:196");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return b;;

}


char* chooseBoxInterp(box b) {
  char* val = stringify(b);
char* firstLetter = sub_string(val, 0, 1);

if (globalTrace)
    printf("chooseBoxInterp at q/lists.qon:199 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "chooseBoxInterp", "199" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:203");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("string", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:204");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return "boxString";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:206");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("\"", firstLetter)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:207");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return "boxString";;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:208");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("true", val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:209");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

        return "boxBool";;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:210");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("false", val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:211");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

          return "boxBool";;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:212");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( isInt(val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:213");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

            return "boxInt";;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:214");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( isInt(val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:215");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

              return "boxFloat";;

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:216");
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
    printf("doInterpolatedList at q/lists.qon:224 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "doInterpolatedList", "224" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:226");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:227");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cons(boxSymbol("nil"), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:229");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:230");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return NULL;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:233");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      elem = first(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:235");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      newlist = cons(boxString(chooseBoxInterp(elem)), cons(first(l), newlist));

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:236");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ret = cons(cons(boxSymbol("cons"), cons(newlist, doInterpolatedList(cdr(l)))), NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:245");
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
    printf("doStringList at q/lists.qon:248 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "doStringList", "248" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:250");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:251");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cons(boxSymbol("nil"), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:253");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newlist = cons(boxSymbol("boxString"), cons(first(l), newlist));

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:254");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ret = cons(cons(boxSymbol("cons"), cons(newlist, doStringList(cdr(l)))), NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:263");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return ret;;

  };

}


list doSymbolList(list l) {
  list newlist = NULL;
list ret = NULL;

if (globalTrace)
    printf("doSymbolList at q/lists.qon:265 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "doSymbolList", "265" );

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

    newlist = cons(boxSymbol("boxSymbol"), cons(first(l), newlist));

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:271");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ret = cons(cons(boxSymbol("cons"), cons(newlist, doSymbolList(cdr(l)))), NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:280");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return ret;;

  };

}


list doBoxList(list l) {
  
if (globalTrace)
    printf("doBoxList at q/lists.qon:283 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "doBoxList", "283" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:286");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:287");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cons(boxSymbol("nil"), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:289");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cons(cons(boxSymbol("cons"), cons(first(l), doBoxList(cdr(l)))), NULL);;

  };

}


list concatLists(list seq1, list seq2) {
  
if (globalTrace)
    printf("concatLists at q/lists.qon:302 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "concatLists", "302" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:304");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(seq1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:305");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return seq2;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:306");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cons(car(seq1), concatLists(cdr(seq1), seq2));;

  };

}


list alistKeys(list alist) {
  
if (globalTrace)
    printf("alistKeys at q/lists.qon:308 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "alistKeys", "308" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:310");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(alist)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:311");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:312");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cons(car(car(alist)), alistKeys(cdr(alist)));;

  };

}


void display(list l) {
  //Function display omitted due to no trace list
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
//Function displayList omitted due to no trace list
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
    printf("StringListJoinRec at q/lists.qon:354 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "StringListJoinRec", "354" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:356");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:357");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return "";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:359");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:361");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:362");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

        return "";;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:364");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equal(listLength(l), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:365");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

          return stringify(car(l));;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:367");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

          return stringConcatenate(stringify(car(l)), stringConcatenate(sep, StringListJoinRec(cdr(l), sep)));;

        };

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:369");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return "";;

    };

  };

}


char* StringListJoin(list l, char* sep) {
  box val = NULL;

if (globalTrace)
    printf("StringListJoin at q/lists.qon:377 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "StringListJoin", "377" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:379");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:382");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return stringConcatenate(stringify(car(l)), stringConcatenate(sep, StringListJoinRec(cdr(l), sep)));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:384");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return stringify(car(l));;

  };

}


box ListToBoxString(list l) {
  
if (globalTrace)
    printf("ListToBoxString at q/lists.qon:387 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "ListToBoxString", "387" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:389");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return boxString(ListToString(l, 0, true, false));;

}


char* ListToString(list l, int indent, bool first, bool withNewLines) {
  box val = NULL;

if (globalTrace)
    printf("ListToString at q/lists.qon:392 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "ListToString", "392" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:394");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:395");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return "";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:397");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:399");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:400");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

        return "";;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:404");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        val = car(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:405");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( isList(val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:407");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

          return StringListJoin(cons(boxString(stringify(tern(withNewLines, boxString("\n"), boxString(stringIndent(indent))))), cons(boxString(openBrace()), cons(boxString(" "), cons(boxString(ListToString(car(l), add1(indent), true, withNewLines)), cons(boxString(closeBrace()), cons(boxString(" "), cons(boxString(ListToString(cdr(l), indent, false, withNewLines)), NULL))))))), "");;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:423");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

          return stringConcatenate(stringify(val), ListToString(cdr(l), indent, false, withNewLines));;

        };

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:425");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return stringify(l);;

    };

  };

}


list listReverse(list l) {
  
if (globalTrace)
    printf("listReverse at q/lists.qon:432 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "listReverse", "432" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:434");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:435");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:436");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cons(car(l), listReverse(cdr(l)));;

  };

}


bool inList(box item, list l) {
  
if (globalTrace)
    printf("inList at q/lists.qon:438 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "inList", "438" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:440");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:441");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:444");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(car(l), item)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:445");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:446");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return inList(item, cdr(l));;

    };

  };

}


bool equalList(list a, list b) {
  
if (globalTrace)
    printf("equalList at q/lists.qon:448 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "equalList", "448" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:450");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(a)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:451");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:453");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:455");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return false;;

    };

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:458");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:459");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(a)) {
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

  if ( equalBox(car(a), car(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:467");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return equalList(cdr(a), cdr(b));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:468");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return false;;

  };

}


list reverseRec(list oldL, list newL) {
  
if (globalTrace)
    printf("reverseRec at q/lists.qon:471 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "reverseRec", "471" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:473");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(oldL)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:474");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return newL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:475");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return reverseRec(cdr(oldL), cons(first(oldL), newL));;

  };

}


list reverseList(list l) {
  
if (globalTrace)
    printf("reverseList at q/lists.qon:478 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "reverseList", "478" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:480");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return reverseRec(l, NULL);;

}


list flatten(list tree) {
  
if (globalTrace)
    printf("flatten at q/lists.qon:483 (%s)\n", caller);

  StackTraceMove("in", "q/lists.qon", "flatten", "483" );

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:485");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:486");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:488");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:489");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return concatLists(flatten(car(tree)), flatten(cdr(tree)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:490");
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
    snprintf(caller, 1024, "from q/macros.qon:46");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

        return car(doInterpolatedList(cdr(l)));;

      } else {
      };

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:49");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return cons(macrowalk(car(l)), macrowalk(cdr(l)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:51");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return l;;

    };

  };

}


list macrosingle(list tree, char* search, char* replace) {
  box val = NULL;

if (globalTrace)
    printf("macrosingle at q/macros.qon:56 (%s)\n", caller);

  StackTraceMove("in", "q/macros.qon", "macrosingle", "56" );

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:57");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:59");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:63");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:66");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return cons(macrosingle(car(tree), search, replace), macrosingle(cdr(tree), search, replace));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:72");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(search, stringify(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:75");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        val = clone(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:76");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        val->str = replace;

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:77");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

        return val;;

      } else {
      };

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:79");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return tree;;

    };

  };

}


list macrolist(list l, char* search, list replace) {
  box val = NULL;

if (globalTrace)
    printf("macrolist at q/macros.qon:83 (%s)\n", caller);

  StackTraceMove("in", "q/macros.qon", "macrolist", "83" );

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:84");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:85");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:89");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:92");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(search, stringify(car(l)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:95");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

        return concatLists(replace, macrolist(cdr(l), search, replace));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:98");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

        return cons(macrolist(car(l), search, replace), macrolist(cdr(l), search, replace));;

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:106");
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
    snprintf(caller, 1024, "from q/compiler.qon:513");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return equalBox(boxString("leaf"), subnameof(n));;

}


list noStackTrace() {
  
if (globalTrace)
    printf("noStackTrace at q/compiler.qon:515 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "noStackTrace", "515" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:517");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return cons(boxString("boxType"), cons(boxString("stringify"), cons(boxString("isEmpty"), cons(boxString("unBoxString"), cons(boxString("isList"), cons(boxString("unBoxBool"), cons(boxString("unBoxSymbol"), cons(boxString("equalBox"), cons(boxString("assoc"), cons(boxString("inList"), cons(boxString("unBoxInt"), cons(boxString("listLength"), cons(boxString("stroff"), cons(boxString("troff"), cons(boxString("tron"), cons(boxString("stron"), cons(boxString("car"), cons(boxString("cdr"), cons(boxString("cons"), cons(boxString("stackTracePush"), cons(boxString("stackTracePop"), cons(boxString("assertType"), cons(boxString("boxString"), cons(boxString("boxSymbol"), cons(boxString("boxInt"), NULL)))))))))))))))))))))))));;

}


list treeCompile(char* filename) {
  char* programStr = "";
list tree = NULL;

if (globalTrace)
    printf("treeCompile at q/compiler.qon:547 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "treeCompile", "547" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:549");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:550");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:551");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return tree;;

}


list astBuild(char* filename) {
  char* programStr = "";
list tree = NULL;
list program = NULL;

if (globalTrace)
    printf("astBuild at q/compiler.qon:553 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astBuild", "553" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:555");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:556");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:557");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:566");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = mergeIncludes(program);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:567");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return program;;

}


void astCompile(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    printf("astCompile at q/compiler.qon:570 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "astCompile", "570" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:572");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Final program: \n");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:575");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:576");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:577");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "write-file", "luaWriteFile");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:578");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "read-file", "luaReadFile");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:579");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "string-length", "string.len");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:581");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "sub-string", "luaSubstring");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:582");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "stringLength", "string.len");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:583");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:584");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:585");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  displayList(tree, 0, true);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Transformed tree");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:590");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n");

}


list mergeIncludes(list program) {
  
if (globalTrace)
    printf("mergeIncludes at q/compiler.qon:594 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "mergeIncludes", "594" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:596");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return merge_recur(childrenof(cdr(cdr(assocPanic("includes", program, "Program lacks include section")))), program);;

}


list merge_recur(list incs, list program) {
  
if (globalTrace)
    printf("merge_recur at q/compiler.qon:601 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "merge_recur", "601" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:603");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(incs), 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:605");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return mergeInclude(car(incs), merge_recur(cdr(incs), program));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:606");
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
    printf("mergeInclude at q/compiler.qon:609 (%s)\n", caller);

  StackTraceMove("in", "q/compiler.qon", "mergeInclude", "609" );

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:624");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(inc)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:625");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return program;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:627");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    functions = childrenof(cdr(assocPanic("functions", inc, "Included file has no functions section")));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:628");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    oldfunctionsnode = cdr(assocPanic("functions", program, "Current module has no functions section"));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:629");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    oldfunctions = childrenof(oldfunctionsnode);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:630");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newfunctions = concatLists(functions, oldfunctions);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:631");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newFunctionNode = cons(boxSymbol("node"), alistCons(boxSymbol("children"), newfunctions, cdr(oldfunctionsnode)));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:639");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    types = childrenof(cdr(assocPanic("types", inc, "Included file has no types section")));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:640");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    oldtypesnode = cdr(assocPanic("types", program, "Current module has no types section"));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:641");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    oldtypes = childrenof(oldtypesnode);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:642");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newtypes = concatLists(types, oldtypes);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:643");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newTypeNode = cons(boxSymbol("node"), alistCons(boxSymbol("children"), newtypes, cdr(oldtypesnode)));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:648");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newProgram = alistCons(boxString("functions"), newFunctionNode, alistCons(boxString("types"), newTypeNode, alistCons(boxString("includes"), cons(boxSymbol("includes"), NULL), newProgram)));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:660");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return newProgram;;

  };

}


int add(int a, int b) {
  //Function add omitted due to no trace list

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
  //Function sub1 omitted due to no trace list

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
    snprintf(caller, 1024, "from q/base.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb = makeBox();

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:29");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->typ = b->typ;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:30");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->tag = b->tag;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:31");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->lis = b->lis;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:32");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->str = b->str;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:33");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->i = b->i;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:34");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->lengt = b->lengt;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:35");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return newb;;

}


box tern(bool cond, list tr, list fal) {
  
if (globalTrace)
    printf("tern at q/base.qon:37 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "tern", "37" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:39");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( cond) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:39");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return tr;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:39");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return fal;;

  };

}


char* ternString(bool cond, char* tr, char* fal) {
  
if (globalTrace)
    printf("ternString at q/base.qon:41 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "ternString", "41" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:43");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( cond) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:43");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return tr;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:43");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return fal;;

  };

}


list ternList(bool cond, list tr, list fal) {
  
if (globalTrace)
    printf("ternList at q/base.qon:45 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "ternList", "45" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:47");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( cond) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:47");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return tr;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:47");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return fal;;

  };

}


box newVoid() {
  box newb = NULL;

if (globalTrace)
    printf("newVoid at q/base.qon:50 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "newVoid", "50" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:54");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb = makeBox();

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:55");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->voi = true;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:56");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->typ = "void";

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:57");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return newb;;

}


void stackDump() {
  
if (globalTrace)
    printf("stackDump at q/base.qon:59 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stackDump", "59" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:60");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("");

}


void nop() {
  
if (globalTrace)
    printf("nop at q/base.qon:64 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "nop", "64" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:65");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("");

}


bool equalBox(box a, box b) {
  //Function equalBox omitted due to no trace list

  StackTraceMove("in", "q/base.qon", "equalBox", "67" );
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
    printf("openBrace at q/base.qon:88 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "openBrace", "88" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:88");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return "(";;

}


char* closeBrace() {
  
if (globalTrace)
    printf("closeBrace at q/base.qon:89 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "closeBrace", "89" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:89");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return ")";;

}


char* boxType(box b) {
  //Function boxType omitted due to no trace list
//Function boxType omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return b->typ;;

}


box makeBox() {
  box b = NULL;
//Function makeBox omitted due to no trace list
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
  //Function makePair omitted due to no trace list
//Function makePair omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return makeBox();;

}


box boxString(char* s) {
  box b = NULL;
//Function boxString omitted due to no trace list
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
//Function boxSymbol omitted due to no trace list

  StackTraceMove("in", "q/base.qon", "boxSymbol", "127" );
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
    printf("boxBool at q/base.qon:136 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "boxBool", "136" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:140");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = makeBox();

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:141");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->boo = boo;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:142");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "bool";

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:143");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return b;;

}


box boxInt(int val) {
  box b = NULL;

if (globalTrace)
    printf("boxInt at q/base.qon:145 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "boxInt", "145" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:149");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = makeBox();

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:150");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->i = val;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:151");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "int";

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:152");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return b;;

}


void assertType(char* atype, box abox, int line, char* file) {
  //Function assertType omitted due to no trace list
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
    printf("unBoxString at q/base.qon:169 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "unBoxString", "169" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:170");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assertType("string", b, 170, "q/base.qon");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:170");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return b->str;;

}


char* unBoxSymbol(box b) {
  //Function unBoxSymbol omitted due to no trace list

  StackTraceMove("in", "q/base.qon", "unBoxSymbol", "172" );
//Function unBoxSymbol omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return b->str;;

}


bool unBoxBool(box b) {
  
if (globalTrace)
    printf("unBoxBool at q/base.qon:173 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "unBoxBool", "173" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:173");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return b->boo;;

}


int unBoxInt(box b) {
  
if (globalTrace)
    printf("unBoxInt at q/base.qon:174 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "unBoxInt", "174" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:174");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return b->i;;

}


char* stringify_rec(box b) {
  
if (globalTrace)
    printf("stringify_rec at q/base.qon:176 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stringify_rec", "176" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:178");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:179");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return "";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:181");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return stringConcatenate(stringify(car(b)), stringConcatenate(" ", stringify_rec(cdr(b))));;

  };

}


char* stringify(box b) {
  //Function stringify omitted due to no trace list

  StackTraceMove("in", "q/base.qon", "stringify", "185" );
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

              return stringConcatenate("Unsupported type: ", boxType(b));;

            };

          };

        };

      };

    };

  };

}


bool hasTag(box aBox, box key) {
  
if (globalTrace)
    printf("hasTag at q/base.qon:220 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "hasTag", "220" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:222");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(aBox)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:223");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:224");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return isNotFalse(assoc(stringify(key), aBox->tag));;

  };

}


box getTag(box aBox, box key) {
  
if (globalTrace)
    printf("getTag at q/base.qon:227 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "getTag", "227" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:229");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( false) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:231");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Getting %s from: ", stringify(key));

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:232");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(alistKeys(aBox->tag));

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:233");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:235");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:236");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return cdr(assoc(stringify(key), aBox->tag));;

}


box getTagFail(box aBox, box key, box onFail) {
  
if (globalTrace)
    printf("getTagFail at q/base.qon:239 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "getTagFail", "239" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:241");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( hasTag(aBox, key)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:242");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return getTag(aBox, key);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:243");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return onFail;;

  };

}


bool assocExists(char* key, box aBox) {
  
if (globalTrace)
    printf("assocExists at q/base.qon:249 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "assocExists", "249" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:253");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(aBox)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:254");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:255");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return isNotFalse(assoc(key, aBox));;

  };

}


box assocFail(char* key, box aBox, box onFail) {
  
if (globalTrace)
    printf("assocFail at q/base.qon:257 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "assocFail", "257" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:260");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( assocExists(key, aBox)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:261");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return assoc(key, aBox);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:262");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cons(boxString(key), onFail);;

  };

}


box assocPanic(char* key, box aBox, char* onFail) {
  
if (globalTrace)
    printf("assocPanic at q/base.qon:264 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "assocPanic", "264" );

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

    panic(onFail);

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:270");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  panic("Inconceivable");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:272");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return NULL;;

}


box setTag(box key, list val, box aStruct) {
  
if (globalTrace)
    printf("setTag at q/base.qon:275 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "setTag", "275" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:278");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  aStruct->tag = alistCons(key, val, aStruct->tag);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:279");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return aStruct;;

}


void locPanic(char* file, char* line, char* message) {
  
if (globalTrace)
    printf("locPanic at q/base.qon:281 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "locPanic", "281" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:284");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s %s:%s\n", file, line, message);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:285");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  panic(message);

}


bool truthy(box aVal) {
  
if (globalTrace)
    printf("truthy at q/base.qon:287 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "truthy", "287" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:290");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return isNotFalse(aVal);;

}


bool isNotFalse(box aVal) {
  
if (globalTrace)
    printf("isNotFalse at q/base.qon:292 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "isNotFalse", "292" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:295");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(boxType(aVal), "bool")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:296");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( unBoxBool(aVal)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:296");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:296");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

      return false;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:297");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return true;;

  };

}


box toStr(box thing) {
  
if (globalTrace)
    printf("toStr at q/base.qon:299 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "toStr", "299" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:301");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return boxString(stringify(thing));;

}


box listLast(list alist) {
  
if (globalTrace)
    printf("listLast at q/base.qon:303 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "listLast", "303" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:306");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(cdr(alist))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:307");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return car(alist);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:308");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return listLast(cdr(alist));;

  };

}


void newLine(int indent) {
  //Function newLine omitted due to no trace list
//Function newLine omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n");
//Function newLine omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printIndent(indent);

}


void printIndent(int ii) {
  
if (globalTrace)
    printf("printIndent at q/base.qon:314 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "printIndent", "314" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:317");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(ii, 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:318");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  ");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:318");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(sub1(ii));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:319");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return;;

  };

}


char* stringIndent(int ii) {
  
if (globalTrace)
    printf("stringIndent at q/base.qon:321 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stringIndent", "321" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:324");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(ii, 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:325");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return stringConcatenate("  ", stringIndent(sub1(ii)));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:326");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return "";;

  };

}


list argList(int count, int pos, char** args) {
  
if (globalTrace)
    printf("argList at q/base.qon:329 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "argList", "329" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:332");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(count, pos)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:334");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return cons(boxString(getStringArray(pos, args)), argList(count, add1(pos), args));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:337");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return NULL;;

  };

}


void tron() {
  
if (globalTrace)
    printf("tron at q/base.qon:339 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "tron", "339" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:339");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalTrace = true;

}


void troff() {
  
if (globalTrace)
    printf("troff at q/base.qon:340 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "troff", "340" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:340");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalTrace = false;

}


void stron() {
  
if (globalTrace)
    printf("stron at q/base.qon:341 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stron", "341" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:341");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalStepTrace = true;

}


void stroff() {
  
if (globalTrace)
    printf("stroff at q/base.qon:342 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "stroff", "342" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:342");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalStepTrace = false;

}


void StackTraceMove(char* direction, char* filename, char* fname, char* line) {
  //Function StackTraceMove omitted due to no trace list
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
  //Function StackTracePrint omitted due to no trace list
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
//Function StackTracePrintHelper omitted due to no trace list
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
  //Function NoStackTrace_list omitted due to no trace list
//Function NoStackTrace_list omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cons(boxString("StackTraceMove"), cons(boxString("StackTracePrint"), cons(boxString("StackTracePrintHelper"), cons(boxString("NoStackTrace_list"), cons(boxString("car"), cons(boxString("cdr"), cons(boxString("cons"), cons(boxString("set"), cons(boxString("boxString"), cons(boxString("makePair"), cons(boxString("set-struct"), cons(boxString("display"), cons(boxString("list"), cons(boxString("assertType"), cons(boxString("isEmpty"), cons(boxString("isNil"), cons(boxString("get-struct"), cons(boxString("equalString"), cons(boxString("binop"), cons(boxString("strcmp"), cons(boxString("main"), cons(boxString("makeBox"), cons(boxString("string_length"), cons(boxString("boxType"), cons(boxString("displayList"), cons(boxString("newLine"), cons(boxString("panic"), NULL)))))))))))))))))))))))))));;

}


list NoTrace_list() {
  
if (globalTrace)
    printf("NoTrace_list at q/base.qon:392 (%s)\n", caller);

  StackTraceMove("in", "q/base.qon", "NoTrace_list", "392" );

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:394");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return cons(boxString("StackTraceMove"), cons(boxString("StackTracePrint"), cons(boxString("StackTracePrintHelper"), cons(boxString("NoStackTrace_list"), cons(boxString("car"), cons(boxString("cdr"), cons(boxString("cons"), cons(boxString("set"), cons(boxString("boxString"), cons(boxString("makePair"), cons(boxString("set-struct"), cons(boxString("display"), cons(boxString("list"), cons(boxString("assertType"), cons(boxString("isEmpty"), cons(boxString("isNil"), cons(boxString("get-struct"), cons(boxString("equalString"), cons(boxString("binop"), cons(boxString("strcmp"), cons(boxString("main"), cons(boxString("makeBox"), cons(boxString("string_length"), cons(boxString("boxType"), cons(boxString("displayList"), cons(boxString("newLine"), cons(boxString("panic"), cons(boxString("boxString"), cons(boxString("boxSymbol"), cons(boxString("boxType"), cons(boxString("equalString"), cons(boxString("unBoxSymbol"), cons(boxString("isList"), cons(boxString("makeBox"), cons(boxString("equalBox"), cons(boxString("sub"), cons(boxString("sub1"), cons(boxString("stringify"), cons(boxString("add"), cons(boxString("greaterthan"), NULL))))))))))))))))))))))))))))))))))))))));;

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
  //Function panic omitted due to no trace list
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
  //Function sub omitted due to no trace list

  StackTraceMove("in", "q/shims/ansi3.qon", "sub", "33" );
//Function sub omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return (a - b);;

}


float mult(int a, int b) {
  
if (globalTrace)
    printf("mult at q/shims/ansi3.qon:37 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "mult", "37" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:39");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return (a * b);;

}


int greaterthan(int a, int b) {
  //Function greaterthan omitted due to no trace list

  StackTraceMove("in", "q/shims/ansi3.qon", "greaterthan", "41" );
//Function greaterthan omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return (a > b);;

}


float subf(float a, float b) {
  
if (globalTrace)
    printf("subf at q/shims/ansi3.qon:45 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "subf", "45" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:47");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return (a - b);;

}


float multf(float a, float b) {
  
if (globalTrace)
    printf("multf at q/shims/ansi3.qon:49 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "multf", "49" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:51");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return (a * b);;

}


int greaterthanf(float a, float b) {
  
if (globalTrace)
    printf("greaterthanf at q/shims/ansi3.qon:53 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "greaterthanf", "53" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:55");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return (a > b);;

}


int equal(int a, int b) {
  
if (globalTrace)
    printf("equal at q/shims/ansi3.qon:57 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "equal", "57" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:59");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return (a == b);;

}


int equalString(char* a, char* b) {
  //Function equalString omitted due to no trace list
//Function equalString omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return (0 == strcmp(a, b));;

}


int string_length(char* s) {
  //Function string_length omitted due to no trace list
//Function string_length omitted due to the no trace list
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return strlen(s);;

}


char* setSubString(char* target, int start, char* source) {
  
if (globalTrace)
    printf("setSubString at q/shims/ansi3.qon:69 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "setSubString", "69" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:71");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  target[start]=source[0];

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:72");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return target;;

}


char* sub_string(char* s, int start, int length) {
  char* substr = "";

if (globalTrace)
    printf("sub_string at q/shims/ansi3.qon:75 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "sub_string", "75" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:77");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  substr = calloc(add(length, 1), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:78");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  strncpy(substr, (s + start), length);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:79");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return substr;;

}


char* stringConcatenate(char* a, char* b) {
  int len = 0;
char* target = NULL;

if (globalTrace)
    printf("stringConcatenate at q/shims/ansi3.qon:82 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "stringConcatenate", "82" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:84");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  len = add(add(strlen(a), strlen(b)), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:85");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  target = calloc(len, 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:86");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  strncat(target, a, len);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:87");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  strncat(target, b, len);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:88");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return target;;

}


char* intToString(int a) {
  int len = 0;
char* target = NULL;

if (globalTrace)
    printf("intToString at q/shims/ansi3.qon:91 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "intToString", "91" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:93");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  len = 100;

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:94");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  target = calloc(len, 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:95");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  snprintf(target, 99, "%d", a);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:96");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return target;;

}


void* gc_malloc(uint size) {
  
if (globalTrace)
    printf("gc_malloc at q/shims/ansi3.qon:99 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "gc_malloc", "99" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:101");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return malloc(size);;

}


int* makeArray(int length) {
  int* array = NULL;

if (globalTrace)
    printf("makeArray at q/shims/ansi3.qon:104 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "makeArray", "104" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:106");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  array = gc_malloc(mult(length, sizeof(int)));

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:107");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return array;;

}


int at(int* arr, int index) {
  
if (globalTrace)
    printf("at at q/shims/ansi3.qon:110 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "at", "110" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:112");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return arr[index];;

}


void setAt(int* array, int index, int value) {
  
if (globalTrace)
    printf("setAt at q/shims/ansi3.qon:115 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "setAt", "115" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:117");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  array[index] = value;

}


void setCharAt(char* array, int index, int value) {
  
if (globalTrace)
    printf("setCharAt at q/shims/ansi3.qon:120 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "setCharAt", "120" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:122");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  array[index] = value;

}


char* read_file(char* filename) {
  char* buffer = NULL;
long length = 0;
FILE* f = NULL;

if (globalTrace)
    printf("read_file at q/shims/ansi3.qon:125 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "read_file", "125" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:127");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  f = fopen(filename, "rb");

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:128");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( ansi3IsNil(f)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:129");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:131");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fseek(f, 0, SEEK_END);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:132");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    length = ftell(f);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:133");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fseek(f, 0, SEEK_SET);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:134");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    buffer = calloc(add(1, length), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:136");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( ansi3IsNil(buffer)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:137");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      panic("Malloc failed!\n");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:138");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      fread(buffer, 1, length, f);

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:139");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fclose(f);

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:142");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return buffer;;

}


void write_file(char* filename, char* data) {
  char* buffer = NULL;
long length = 0;
FILE* f = NULL;

if (globalTrace)
    printf("write_file at q/shims/ansi3.qon:145 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "write_file", "145" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:147");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  f = fopen(filename, "w");

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:148");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( ansi3IsNil(f)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:149");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Error opening file!");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:151");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fprintf(f, "%s", data);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:152");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fclose(f);

  };

}


char* getStringArray(int index, char** strs) {
  
if (globalTrace)
    printf("getStringArray at q/shims/ansi3.qon:156 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "getStringArray", "156" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:158");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return strs[index];;

}


char** programArgs() {
  
if (globalTrace)
    printf("programArgs at q/shims/ansi3.qon:160 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "programArgs", "160" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:162");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return globalArgs;;

}


int programArgsCount() {
  
if (globalTrace)
    printf("programArgsCount at q/shims/ansi3.qon:165 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "programArgsCount", "165" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:167");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return globalArgsCount;;

}


int main(int argc, char** argv) {
  //Function main omitted due to no trace list
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

  return start(argc, argv);;

}


char* character(int num) {
  char* buffer = NULL;
char* str = NULL;

if (globalTrace)
    printf("character at q/shims/ansi3.qon:179 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "character", "179" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:181");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  str = malloc(2);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:182");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( ansi3IsNil(str)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:183");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return 0;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:185");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    setCharAt(str, 0, num);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:186");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    setCharAt(str, 1, 0);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:187");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

    return str;;

  };

}


void displays(char* s) {
  
if (globalTrace)
    printf("displays at q/shims/ansi3.qon:194 (%s)\n", caller);

  StackTraceMove("in", "q/shims/ansi3.qon", "displays", "194" );

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:196");
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
bool runAnsi2 = false;
bool runAnsi3 = false;
bool runBash = false;
bool runTree = false;

if (globalTrace)
    printf("start at compiler.qon:5 (%s)\n", caller);

  StackTraceMove("in", "compiler.qon", "start", "5" );

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:23");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  cmdLine = listReverse(argList(globalArgsCount, 0, globalArgs));

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:25");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(cmdLine), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:26");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    filenameBox = second(cmdLine);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:27");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    filenameBox = boxString("compiler.qon");

  };

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  filename = unBoxString(filenameBox);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:30");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  releaseMode = inList(boxString("--release"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:31");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runTests = inList(boxString("--test"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:32");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runJava = inList(boxString("--java"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:33");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runPerl = inList(boxString("--perl"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:34");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runAst = inList(boxString("--ast"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:35");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runTree = inList(boxString("--tree"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:36");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runNode = inList(boxString("--node"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:37");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runNode2 = inList(boxString("--node2"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:38");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runLua = inList(boxString("--lua"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:39");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runIma = inList(boxString("--ima"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:40");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runAnsi2 = inList(boxString("--ansi2"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:41");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runAnsi3 = inList(boxString("--ansi3"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:42");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runBash = inList(boxString("--bash"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:43");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalTrace = inList(boxString("--trace"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:44");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalStepTrace = inList(boxString("--steptrace"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:45");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( inList(boxString("--help"), cmdLine)) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:47");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Usage: quon file [options]\n\nNote the options go after the file name\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:48");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Options:\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:49");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --help      Display this help\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:50");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --release   Compile in release mode\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:51");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --test      Run the test suite\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:52");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --java      Compile to Java\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:53");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --perl      Compile to Perl\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:54");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --ast       Compile to the Abstract Syntax Tree\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:55");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --tree      Compile to an s-expression tree\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:56");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --node      Compile to Node.js\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:57");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --node2      Compile to Node.js, new outputter\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:58");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --lua       Compile to Lua\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:59");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --ima       Compile to Imaginary, the human-friendly language\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:60");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --ansi2     Compile to ANSI C, (quon version 2)\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:61");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --ansi3     Compile to ANSI C (quon version 3)\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:62");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --bash      Compile to Bash\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:63");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --trace     Trace execution\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:64");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --steptrace Step trace execution\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:65");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  --help      Display this help\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:66");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    exit(0);

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:70");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( runTests) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:72");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test0();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:73");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test1();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:74");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test2();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:75");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test3();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:76");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test4();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:77");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test5();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:78");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test6();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:79");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test7();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:80");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test8();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:81");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test9();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:82");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test10();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:83");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test12();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:84");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test13();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:85");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test15();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:86");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test16();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:87");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test17();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:88");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test18();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:89");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test19();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:90");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test20();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:91");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test21();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:92");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test22();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:93");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test23();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:94");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test24();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:95");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test25();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:96");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test27();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:98");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n\nAfter all that hard work, I need a beer...\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:99");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    beers(9);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:101");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( runTree) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:102");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(macrowalk(treeCompile(filename)));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:104");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( runAst) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:105");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        astCompile(filename);

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:106");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( runNode) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:108");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          nodeCompile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:108");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("\n");

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:109");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( runNode2) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:111");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf(StringListJoin(flatten(node2Compile(filename)), " "));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:113");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( runPerl) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:114");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              perlCompile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:114");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("\n");

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:116");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              if ( runJava) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:117");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                javaCompile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:117");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                printf("\n");

              } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:119");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                if ( runLua) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:120");
                  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                  luaCompile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:120");
                  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                  printf("\n");

                } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:122");
                  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                  if ( runIma) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:123");
                    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                    imaCompile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:123");
                    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                    printf("\n");

                  } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:125");
                    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                    if ( runAnsi2) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:126");
                      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                      ansi2Compile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:126");
                      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                      printf("\n");

                    } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:128");
                      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                      if ( runAnsi3) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:129");
                        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                        ansi3Compile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:129");
                        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                        printf("\n");

                      } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:131");
                        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                        if ( runBash) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:132");
                          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                          bashCompile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:132");
                          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                          printf("\n");

                        } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:134");
                          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                          ansi3Compile(filename);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:134");
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

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:140");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

StackTraceMove("out", "", "", "");

  return 0;;

}


