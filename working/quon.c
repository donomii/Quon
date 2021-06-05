
//Start include block
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void bashFunctionArgs(list tree);
void bashExpression(list tree, int indent);
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
void ansi3displays(char* s);
void ansi3FunctionArgs(list tree);
void ansi3Expression(list tree, int indent);
void ansi3RecurList(list expr, int indent);
void ansi3If(list node, int indent);
void ansi3SetStruct(list node, int indent);
void ansi3GetStruct(list node, int indent);
void ansi3Set(list node, int indent);
void ansi3Return(list node, int indent);
void ansi3Statement(list node, int indent);
void ansi3Body(list tree, int indent);
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
list doStringList(list l);
list doSymbolList(list l);
list doBoxList(list l);
list concatLists(list seq1, list seq2);
list alistKeys(list alist);
void displayList(list l, int indent, bool first);
list listReverse(list l);
bool inList(box item, list l);
bool equalList(list a, list b);
list reverseRec(list oldL, list newL);
list reverseList(list l);
list macrowalk(list l);
list macrosingle(list l, char* search, char* replace);
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
box newVoid();
void stackDump();
void nop();
bool equalBox(box a, box b);
void display(list l);
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
list argList(int count, int pos, char** args);
void tron();
void troff();
void stron();
void stroff();
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



//Building function bashdisplays from line: 5

void bashdisplays(char* s) {
  
if (globalTrace)
    printf("bashdisplays at q/bash.qon:5 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:7");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", s);

if (globalTrace)
    printf("Leaving bashdisplays\n");

}


//Building function bashFunctionArgs from line: 11

void bashFunctionArgs(list tree) {
  
if (globalTrace)
    printf("bashFunctionArgs at q/bash.qon:11 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:13");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:14");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:16");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(second(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:17");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree))) {
    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:17");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      bashdisplays(", ");

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:18");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashFunctionArgs(cddr(tree));

  };

if (globalTrace)
    printf("Leaving bashFunctionArgs\n");

}


//Building function bashExpression from line: 22

void bashExpression(list tree, int indent) {
  list thing = NULL;

if (globalTrace)
    printf("bashExpression at q/bash.qon:22 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:24");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:28");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equal(1, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:31");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:33");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("return"), car(tree))) {
      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:37");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        bashdisplays("()");

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:40");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      thing = first(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:41");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxSymbol("get-struct"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:44");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s->%s", stringify(second(tree)), stringify(third(tree)));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:49");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxSymbol("new"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:52");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("malloc(sizeof(%s))", stringify(third(tree)));

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:56");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("passthrough"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:59");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s", stringify(second(tree)));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:63");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("binop"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:66");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("(");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:67");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              bashExpression(third(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:68");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(" %s ", stringify(second(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:71");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              bashExpression(fourth(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:72");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:76");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s(%s ", dollar(), stringify(bashFuncMap(car(tree))));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:81");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              bashRecurList(cdr(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:82");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            };

          };

        };

      };

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:90");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(bashVarOrLit(tree));

  };

if (globalTrace)
    printf("Leaving bashExpression\n");

}


//Building function bashVarOrLit from line: 92

box bashVarOrLit(box a) {
  
if (globalTrace)
    printf("bashVarOrLit at q/bash.qon:92 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:94");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(a))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:95");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return boxSymbol(stringConcatenate(dollar(), stringify(a)));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:96");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return a;;

  };

if (globalTrace)
    printf("Leaving bashVarOrLit\n");

}


//Building function bashRecurList from line: 101

void bashRecurList(list expr, int indent) {
  
if (globalTrace)
    printf("bashRecurList at q/bash.qon:101 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:105");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:106");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:108");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashExpression(car(expr), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:109");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:110");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      bashdisplays("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:111");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      bashdisplays(" ");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:111");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      bashRecurList(cdr(expr), indent);

    };

  };

if (globalTrace)
    printf("Leaving bashRecurList\n");

}


//Building function bashIf from line: 118

void bashIf(list node, int indent) {
  
if (globalTrace)
    printf("bashIf at q/bash.qon:118 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:120");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:121");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashdisplays("if (( ");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:122");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashExpression(second(node), 0);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:123");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashdisplays(")) ; then ");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:124");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashBody(cdr(third(node)), add1(indent));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:125");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:126");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashdisplays(" else ");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:127");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashBody(cdr(fourth(node)), add1(indent));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:128");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:129");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashdisplays("fi");

if (globalTrace)
    printf("Leaving bashIf\n");

}


//Building function bashSetStruct from line: 131

void bashSetStruct(list node, int indent) {
  
if (globalTrace)
    printf("bashSetStruct at q/bash.qon:131 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:133");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:134");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->%s = ", stringify(second(node)), stringify(third(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:138");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashExpression(fourth(node), indent);

if (globalTrace)
    printf("Leaving bashSetStruct\n");

}


//Building function bashGetStruct from line: 140

void bashGetStruct(list node, int indent) {
  
if (globalTrace)
    printf("bashGetStruct at q/bash.qon:140 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:142");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:143");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->%s", stringify(first(node)), stringify(second(node)));

if (globalTrace)
    printf("Leaving bashGetStruct\n");

}


//Building function bashSet from line: 148

void bashSet(list node, int indent) {
  
if (globalTrace)
    printf("bashSet at q/bash.qon:148 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:150");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:151");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  display(first(cdr(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:152");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("=");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:153");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashExpression(third(node), indent);

if (globalTrace)
    printf("Leaving bashSet\n");

}


//Building function bashReturn from line: 155

void bashReturn(list node, int indent) {
  
if (globalTrace)
    printf("bashReturn at q/bash.qon:155 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:157");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:158");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(listLength(node), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:159");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashdisplays("return;");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:161");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashdisplays("return ");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:162");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashExpression(cadr(node), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:163");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashdisplays(";");

  };

if (globalTrace)
    printf("Leaving bashReturn\n");

}


//Building function bashStatement from line: 166

void bashStatement(list node, int indent) {
  
if (globalTrace)
    printf("bashStatement at q/bash.qon:166 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:168");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("set"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:169");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashSet(node, indent);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:171");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("set-struct"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:172");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      bashSetStruct(node, indent);

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:174");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:175");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        bashIf(node, indent);

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:177");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("return"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:178");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          bashReturn(node, indent);

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:180");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:181");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          bashExpression(node, indent);

        };

      };

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:182");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashdisplays(";\n");

if (globalTrace)
    printf("Leaving bashStatement\n");

}


//Building function bashBody from line: 184

void bashBody(list tree, int indent) {
  list code = NULL;

if (globalTrace)
    printf("bashBody at q/bash.qon:184 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:186");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:187");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:189");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    code = tree;

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:190");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(code)) {
    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:193");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      code = car(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:194");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( not(releaseMode)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:197");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("\nif (globalTrace)\n    snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), stringify(getTagFail(car(code), boxString("line"), boxString("Line missing"))));

      } else {
      };

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:201");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( not(releaseMode)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:202");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:203");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n");

    } else {
    };

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:206");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashStatement(code, indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:207");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashBody(cdr(tree), indent);

  };

if (globalTrace)
    printf("Leaving bashBody\n");

}


//Building function bashDeclarations from line: 209

void bashDeclarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("bashDeclarations at q/bash.qon:209 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:211");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:212");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:214");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:215");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("local %s=\"", stringify(second(decl)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:218");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashExpression(third(decl), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:219");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\";\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:220");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashDeclarations(cdr(decls), indent);

  };

if (globalTrace)
    printf("Leaving bashDeclarations\n");

}


//Building function bashFunction from line: 222

void bashFunction(list node) {
  box name = NULL;

if (globalTrace)
    printf("bashFunction at q/bash.qon:222 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:224");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = second(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:225");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n#Building function %s from line:%s", stringify(name), stringify(getTag(name, boxString("line"))));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:226");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:227");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:228");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:230");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:231");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s(", stringify(second(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:232");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashFunctionArgs(third(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:233");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(") {");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:234");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:235");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashDeclarations(cdr(fourth(node)), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:236");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:237");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:239");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    printf(\"%s at %s:%s (%%s)\\n\", caller);\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:240");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:241");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
    };

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:246");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashBody(cdr(fifth(node)), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:247");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:248");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:250");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    printf(\"Leaving %s\\n\");\n", stringify(name));

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:252");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n");

  };

if (globalTrace)
    printf("Leaving bashFunction\n");

}


//Building function bashForwardDeclaration from line: 254

void bashForwardDeclaration(list node) {
  
if (globalTrace)
    printf("bashForwardDeclaration at q/bash.qon:254 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:256");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:256");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:257");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n%s %s(", stringify(bashTypeMap(first(node))), stringify(second(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:261");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashFunctionArgs(third(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:262");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashdisplays(");");

  };

if (globalTrace)
    printf("Leaving bashForwardDeclaration\n");

}


//Building function bashForwardDeclarations from line: 264

void bashForwardDeclarations(list tree) {
  
if (globalTrace)
    printf("bashForwardDeclarations at q/bash.qon:264 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:266");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:266");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:267");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashForwardDeclaration(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:268");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashForwardDeclarations(cdr(tree));

  };

if (globalTrace)
    printf("Leaving bashForwardDeclarations\n");

}


//Building function bashFunctions from line: 270

void bashFunctions(list tree) {
  
if (globalTrace)
    printf("bashFunctions at q/bash.qon:270 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:272");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:272");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:273");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashFunction(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:273");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashFunctions(cdr(tree));

  };

if (globalTrace)
    printf("Leaving bashFunctions\n");

}


//Building function bashIncludes from line: 276

void bashIncludes(list nodes) {
  
if (globalTrace)
    printf("bashIncludes at q/bash.qon:276 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:278");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\nbool releaseMode = false;\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:281");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n");

if (globalTrace)
    printf("Leaving bashIncludes\n");

}


//Building function bashTypeDecl from line: 284

void bashTypeDecl(list l) {
  
if (globalTrace)
    printf("bashTypeDecl at q/bash.qon:284 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:286");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:288");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:289");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s %s;\n", stringify(second(l)), stringify(bashTypeMap(listLast(l))), stringify(first(l)));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:295");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:296");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s;\n", stringify(bashTypeMap(listLast(l))), stringify(car(l)));

  };

if (globalTrace)
    printf("Leaving bashTypeDecl\n");

}


//Building function bashStructComponents from line: 301

void bashStructComponents(list node) {
  
if (globalTrace)
    printf("bashStructComponents at q/bash.qon:301 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:303");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:304");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:305");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashTypeDecl(car(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:305");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashStructComponents(cdr(node));

  };

if (globalTrace)
    printf("Leaving bashStructComponents\n");

}


//Building function bashStruct from line: 307

void bashStruct(list node) {
  
if (globalTrace)
    printf("bashStruct at q/bash.qon:307 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:308");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashStructComponents(cdr(node));

if (globalTrace)
    printf("Leaving bashStruct\n");

}


//Building function bashTypeMap from line: 310

box bashTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("bashTypeMap at q/bash.qon:310 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:312");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:316");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:317");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:318");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return aSym;;

  };

if (globalTrace)
    printf("Leaving bashTypeMap\n");

}


//Building function bashFuncMap from line: 320

box bashFuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("bashFuncMap at q/bash.qon:320 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:322");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:324");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), NULL)))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:346");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:347");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return cdr(assoc(stringify(aSym), symMap));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:348");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return aSym;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:349");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return aSym;;

  };

if (globalTrace)
    printf("Leaving bashFuncMap\n");

}


//Building function bashType from line: 351

void bashType(list node) {
  
if (globalTrace)
    printf("bashType at q/bash.qon:351 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:353");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(second(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:355");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\ntypedef struct %s {\n", stringify(first(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:356");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashStruct(second(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:357");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n} %s;\n", stringify(first(node)));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:358");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashdisplays("typedef ");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:358");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashTypeDecl(node);

  };

if (globalTrace)
    printf("Leaving bashType\n");

}


//Building function bashTypes from line: 361

void bashTypes(list nodes) {
  
if (globalTrace)
    printf("bashTypes at q/bash.qon:361 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:363");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:364");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:365");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashType(car(nodes));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:365");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    bashTypes(cdr(nodes));

  };

if (globalTrace)
    printf("Leaving bashTypes\n");

}


//Building function bashCompile from line: 371

void bashCompile(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    printf("bashCompile at q/bash.qon:371 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Scanning file...%s\n", filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:378");
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
    snprintf(caller, 1024, "from q/bash.qon:382");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = buildProg(cons(boxString("q/shims/bash.qon"), getIncludes(tree)), getTypes(tree), getFunctions(tree));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Loading all includes\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:384");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Applying macros\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:386");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:387");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:388");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Printing program\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:394");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashIncludes(cdr(first(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:395");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashTypes(cdr(second(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:397");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashdisplays("Box* globalStackTrace = NULL;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:398");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashdisplays("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:400");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashForwardDeclarations(cdr(third(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:401");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashdisplays("\n\n//End forward declarations\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:402");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashFunctions(cdr(third(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/bash.qon:403");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  bashdisplays("\n");

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Done printing program\n");

if (globalTrace)
    printf("Leaving bashCompile\n");

}


//Building function imaFunctionArgs from line: 4

void imaFunctionArgs(int indent, list tree) {
  
if (globalTrace)
    printf("imaFunctionArgs at q/imaginary.qon:4 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:6");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:7");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving imaFunctionArgs\n");

}


//Building function imaFunction from line: 16

void imaFunction(int indent, list functionDefinition) {
  char* fname = "";

if (globalTrace)
    printf("imaFunction at q/imaginary.qon:16 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving imaFunction\n");

}


//Building function imaDeclarations from line: 37

void imaDeclarations(int indent, list declarations) {
  list decl = NULL;

if (globalTrace)
    printf("imaDeclarations at q/imaginary.qon:37 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:39");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(declarations)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:42");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving imaDeclarations\n");

}


//Building function imaExpressionStart from line: 56

void imaExpressionStart(int indent, list program) {
  
if (globalTrace)
    printf("imaExpressionStart at q/imaginary.qon:56 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:58");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:60");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving imaExpressionStart\n");

}


//Building function imaExpression from line: 98

void imaExpression(int indent, list program) {
  
if (globalTrace)
    printf("imaExpression at q/imaginary.qon:98 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:100");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:102");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving imaExpression\n");

}


//Building function imaStatement from line: 126

void imaStatement(int indent, list statement) {
  
if (globalTrace)
    printf("imaStatement at q/imaginary.qon:126 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving imaStatement\n");

}


//Building function imaBody from line: 181

void imaBody(char* local_caller, int indent, list program) {
  list statement = NULL;

if (globalTrace)
    printf("imaBody at q/imaginary.qon:181 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:183");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:184");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving imaBody\n");

}


//Building function imaFunctions from line: 192

void imaFunctions(int indent, list program) {
  
if (globalTrace)
    printf("imaFunctions at q/imaginary.qon:192 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:194");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:196");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving imaFunctions\n");

}


//Building function imaTypeDecl from line: 202

void imaTypeDecl(list l) {
  char* name = "";
list body = NULL;

if (globalTrace)
    printf("imaTypeDecl at q/imaginary.qon:202 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving imaTypeDecl\n");

}


//Building function imaStructComponents from line: 227

void imaStructComponents(list node) {
  
if (globalTrace)
    printf("imaStructComponents at q/imaginary.qon:227 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:229");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:230");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving imaStructComponents\n");

}


//Building function imaStruct from line: 233

void imaStruct(list node) {
  
if (globalTrace)
    printf("imaStruct at q/imaginary.qon:233 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:234");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaStructComponents(cdr(car(node)));

if (globalTrace)
    printf("Leaving imaStruct\n");

}


//Building function imaTypeMap from line: 236

box imaTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("imaTypeMap at q/imaginary.qon:236 (%s)\n", caller);

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

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:246");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return aSym;;

  };

if (globalTrace)
    printf("Leaving imaTypeMap\n");

}


//Building function imaType from line: 248

void imaType(list node) {
  char* name = "";
list body = NULL;

if (globalTrace)
    printf("imaType at q/imaginary.qon:248 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving imaType\n");

}


//Building function imaTypes from line: 263

void imaTypes(int indent, list nodes) {
  
if (globalTrace)
    printf("imaTypes at q/imaginary.qon:263 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:266");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:267");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving imaTypes\n");

}


//Building function imaProgram from line: 272

void imaProgram(list program) {
  
if (globalTrace)
    printf("imaProgram at q/imaginary.qon:272 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving imaProgram\n");

}


//Building function imaIncludes from line: 282

void imaIncludes(int indent, list nodes) {
  
if (globalTrace)
    printf("imaIncludes at q/imaginary.qon:282 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:284");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("Includes: \n");

if (globalTrace)
    snprintf(caller, 1024, "from q/imaginary.qon:285");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  displayList(nodes, 0, true);

if (globalTrace)
    printf("Leaving imaIncludes\n");

}


//Building function imaCompile from line: 289

void imaCompile(char* filename) {
  list tree = NULL;

if (globalTrace)
    printf("imaCompile at q/imaginary.qon:289 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving imaCompile\n");

}


//Building function not from line: 3

bool not(bool a) {
  
if (globalTrace)
    printf("not at q/boolean.qon:3 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:5");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( a) {
if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:6");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:7");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return true;;

  };

if (globalTrace)
    printf("Leaving not\n");

}


//Building function andBool from line: 10

bool andBool(bool a, bool b) {
  
if (globalTrace)
    printf("andBool at q/boolean.qon:10 (%s)\n", caller);

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

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:16");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return false;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:17");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return false;;

  };

if (globalTrace)
    printf("Leaving andBool\n");

}


//Building function nand from line: 20

bool nand(bool a, bool b) {
  
if (globalTrace)
    printf("nand at q/boolean.qon:20 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:22");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return not(andBool(a, b));;

if (globalTrace)
    printf("Leaving nand\n");

}


//Building function xor from line: 25

bool xor(bool a, bool b) {
  
if (globalTrace)
    printf("xor at q/boolean.qon:25 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/boolean.qon:27");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return nand(nand(a, nand(a, b)), nand(b, nand(a, b)));;

if (globalTrace)
    printf("Leaving xor\n");

}


//Building function luaFunctionArgs from line: 4

void luaFunctionArgs(int indent, list tree) {
  
if (globalTrace)
    printf("luaFunctionArgs at q/lua.qon:4 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:6");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:7");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving luaFunctionArgs\n");

}


//Building function luaFunction from line: 14

void luaFunction(int indent, list functionDefinition) {
  char* fname = "";

if (globalTrace)
    printf("luaFunction at q/lua.qon:14 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving luaFunction\n");

}


//Building function luaDeclarations from line: 26

void luaDeclarations(int indent, list declarations) {
  list decl = NULL;

if (globalTrace)
    printf("luaDeclarations at q/lua.qon:26 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(declarations)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:30");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving luaDeclarations\n");

}


//Building function luaExpressionStart from line: 42

void luaExpressionStart(int indent, list program) {
  
if (globalTrace)
    printf("luaExpressionStart at q/lua.qon:42 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:44");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:46");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving luaExpressionStart\n");

}


//Building function luaExpression from line: 84

void luaExpression(int indent, list program) {
  
if (globalTrace)
    printf("luaExpression at q/lua.qon:84 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:86");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:88");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving luaExpression\n");

}


//Building function luaStatement from line: 112

void luaStatement(int indent, list statement) {
  
if (globalTrace)
    printf("luaStatement at q/lua.qon:112 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving luaStatement\n");

}


//Building function luaBody from line: 164

void luaBody(char* local_caller, int indent, list program) {
  list statement = NULL;

if (globalTrace)
    printf("luaBody at q/lua.qon:164 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:166");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:167");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving luaBody\n");

}


//Building function luaFunctions from line: 176

void luaFunctions(int indent, list program) {
  
if (globalTrace)
    printf("luaFunctions at q/lua.qon:176 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:178");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:180");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving luaFunctions\n");

}


//Building function luaProgram from line: 188

void luaProgram(list program) {
  
if (globalTrace)
    printf("luaProgram at q/lua.qon:188 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:190");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  luaIncludes(NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:191");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  luaFunctions(0, cdr(third(program)));

if (globalTrace)
    printf("Leaving luaProgram\n");

}


//Building function luaIncludes from line: 195

void luaIncludes(list nodes) {
  
if (globalTrace)
    printf("luaIncludes at q/lua.qon:195 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lua.qon:197");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "\nfunction luaDump(o)\n   if type(o) == 'table' then\n      local s = '{ '\n      for k,v in pairs(o) do\n         if type(k) ~= 'number' then k = '\"'..k..'\"' end\n         s = s .. '['..k..'] = ' .. luaDump(v) .. ','\n      end\n      return s .. '} '\n   else\n      return tostring(o)\n   end\nend\nprintf = function(s,...)\nreturn io.write(s:format(...))\nend -- function\n    \nfunction stringConcatenate(a,b)\nreturn a..b\nend\n    \nfunction getStringArray(index, arr)\nreturn arr[index]\nend\n       \nfunction luaWriteFile(name, data)  \nlocal file = io.open(name, \"w\")\nfile:write(data)\nfile:close(file)\nend\n    function luaSubstring(s, start, length)\nreturn string.sub(s, start, start+length)\nend\n    \n    function luaReadFile(file)\n      local f = assert(io.open(file, \"rb\"))\n      local content = f:read(\"*all\")      f:close()\n      return content\n    end\n     \nfunction equalString(a,b)\n        return a==b;\n     end\n    \n     function new()\n        return {};\n     end\n    \n     function isNil(val)\n        return val == nil;\n     end\n    \n     function getEnv(key)\n        return os.getenv(key);\n     end\n    \n    function panic(s)\n      print(s);\n    os.exit()\n    end\n    \n    function sub(a, b) \n      return a - b; \n    end\n\n    function mult(a, b) \n      return a * b;\n    end\n    \n    function greaterthan(a, b)\n      return a > b;\n    end\n    \n    function subf(a, b) \n      return a - b;\n    end\n    \n    function multf(a, b)\n      return a * b;\n    end\n    \n    function greaterthanf(a, b)\n      return a > b;\n    end\n    \n    function equal(a, b)\n      return a == b;\n    end\n    \n    function andBool(a, b)\n      return a == b;\n    end\n    \n    function string_length(s)\n      return strlen(s);\n    end\n    \n    function setSubString(target, start, source)\n      panic(\"stub\");\n      end\n    \n    function sub_string(s, start, length)\n      panic(\"stub\");\n    end\n    \n    function intToString(a)\n      panic(\"stub\")\n return a\n    end\n\n    function gc_malloc(size)\n      return \"\"\n    end\n    \n    function makeArray(length)\n      return {}\n    end\n    \n    function at(arr, index)\n      return arr[index+1];\n    end\n    \n    function setAt(array, index, value)\n      array[index+1] = value;\n    end\n    \n    function read_file(file)\n      local f = io.open(file, \"r\")\n      local content = \"\"\n      local length = 0\n\n      while f:read(0) ~= \"\" do\n          local current = f:read(\"*all\")\n\n          print(#current, length)\n          length = length + #current\n\n          content = content .. current\n      end\n\n      return content\n    end\n    \n    function write_file(filename, data)\n      local file = io.open(filename,'w')\n      file:write(tostring(data))\n      file:close()\n    end\n    \n    caller=\"main\";\n    \n    globalArgs={};\n    globalArgsCount=0;\n    globalTrace = false;\n    globalStepTrace = false;\n\n    function main()\n      globalArgs = arg;\n      globalArgsCount = #arg + 1;\n      return start();\n    end\n    \n");

if (globalTrace)
    printf("Leaving luaIncludes\n");

}


//Building function luaCompile from line: 203

void luaCompile(char* filename) {
  list tree = NULL;

if (globalTrace)
    printf("luaCompile at q/lua.qon:203 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving luaCompile\n");

}


//Building function javaFunctionArgs from line: 3

void javaFunctionArgs(list tree) {
  
if (globalTrace)
    printf("javaFunctionArgs at q/java.qon:3 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:5");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:6");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving javaFunctionArgs\n");

}


//Building function javaLeaf from line: 14

void javaLeaf(list thisNode, int indent) {
  
if (globalTrace)
    printf("javaLeaf at q/java.qon:14 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:15");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  display(javaFuncMap(codeof(thisNode)));

if (globalTrace)
    printf("Leaving javaLeaf\n");

}


//Building function javaStructGetterExpression from line: 17

void javaStructGetterExpression(list thisNode, int indent) {
  
if (globalTrace)
    printf("javaStructGetterExpression at q/java.qon:17 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving javaStructGetterExpression\n");

}


//Building function javaExpression from line: 23

void javaExpression(list node, int indent) {
  
if (globalTrace)
    printf("javaExpression at q/java.qon:23 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving javaExpression\n");

}


//Building function javaRecurList from line: 29

void javaRecurList(list expr, int indent) {
  
if (globalTrace)
    printf("javaRecurList at q/java.qon:29 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:33");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:34");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving javaRecurList\n");

}


//Building function javaSubExpression from line: 41

void javaSubExpression(list tree, int indent) {
  box thing = NULL;

if (globalTrace)
    printf("javaSubExpression at q/java.qon:41 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:43");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:44");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving javaSubExpression\n");

}


//Building function javaIf from line: 81

void javaIf(list node, int indent) {
  
if (globalTrace)
    printf("javaIf at q/java.qon:81 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving javaIf\n");

}


//Building function javaSetStruct from line: 94

void javaSetStruct(list node, int indent) {
  
if (globalTrace)
    printf("javaSetStruct at q/java.qon:94 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving javaSetStruct\n");

}


//Building function javaGetStruct from line: 105

void javaGetStruct(list node, int indent) {
  
if (globalTrace)
    printf("javaGetStruct at q/java.qon:105 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:107");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:108");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s.%s", stringify(first(codeof(node))), stringify(second(codeof(node))));

if (globalTrace)
    printf("Leaving javaGetStruct\n");

}


//Building function javaSet from line: 113

void javaSet(list node, int indent) {
  
if (globalTrace)
    printf("javaSet at q/java.qon:113 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving javaSet\n");

}


//Building function javaStatement from line: 121

void javaStatement(list node, int indent) {
  
if (globalTrace)
    printf("javaStatement at q/java.qon:121 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving javaStatement\n");

}


//Building function javaBody from line: 141

void javaBody(list tree, int indent) {
  
if (globalTrace)
    printf("javaBody at q/java.qon:141 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:143");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:144");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving javaBody\n");

}


//Building function javaDeclarations from line: 151

void javaDeclarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("javaDeclarations at q/java.qon:151 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:153");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:154");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving javaDeclarations\n");

}


//Building function javaFunction from line: 165

void javaFunction(list node) {
  box name = NULL;

if (globalTrace)
    printf("javaFunction at q/java.qon:165 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving javaFunction\n");

}


//Building function javaFunctions from line: 204

void javaFunctions(list tree) {
  
if (globalTrace)
    printf("javaFunctions at q/java.qon:204 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:206");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:207");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving javaFunctions\n");

}


//Building function javaIncludes from line: 210

void javaIncludes(list nodes) {
  
if (globalTrace)
    printf("javaIncludes at q/java.qon:210 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:212");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public void panic(String s) {System.exit(1);}\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:213");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public int sub(int a, int b) { return a - b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:214");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public double mult(int a, int b) { return a * b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:215");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public boolean greaterthan(int a, int b) { return a > b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:216");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public double subf(double a, double b) { return a - b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:217");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public double multf(double a, double b) { return a * b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:218");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public boolean greaterthanf(double a, double b) { return a > b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:219");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public boolean equal(int a, int b) { return a == b; }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:220");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public boolean equalString(String a, String b) { return a.equals(b); }\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:221");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public boolean andBool(boolean a, boolean b) { return a == b;}\n");

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

if (globalTrace)
    printf("Leaving javaIncludes\n");

}


//Building function javaTypeDecl from line: 233

void javaTypeDecl(list l) {
  
if (globalTrace)
    printf("javaTypeDecl at q/java.qon:233 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving javaTypeDecl\n");

}


//Building function javaStructComponents from line: 250

void javaStructComponents(list node) {
  
if (globalTrace)
    printf("javaStructComponents at q/java.qon:250 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:252");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:253");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving javaStructComponents\n");

}


//Building function javaStruct from line: 256

void javaStruct(list node) {
  
if (globalTrace)
    printf("javaStruct at q/java.qon:256 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:257");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaStructComponents(cdr(car(node)));

if (globalTrace)
    printf("Leaving javaStruct\n");

}


//Building function javaTypeMap from line: 259

box javaTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("javaTypeMap at q/java.qon:259 (%s)\n", caller);

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

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:275");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return aSym;;

  };

if (globalTrace)
    printf("Leaving javaTypeMap\n");

}


//Building function javaTypesNoDeclare from line: 277

box javaTypesNoDeclare() {
  list syms = NULL;

if (globalTrace)
    printf("javaTypesNoDeclare at q/java.qon:277 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:279");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  syms = cons(boxString("pair"), cons(boxString("box"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:284");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return syms;;

if (globalTrace)
    printf("Leaving javaTypesNoDeclare\n");

}


//Building function javaFuncMap from line: 286

box javaFuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("javaFuncMap at q/java.qon:286 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:288");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:290");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("printf"), boxSymbol("System.out.printf"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("null"), NULL))))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:311");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:312");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return cdr(assoc(stringify(aSym), symMap));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:313");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return aSym;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:314");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return aSym;;

  };

if (globalTrace)
    printf("Leaving javaFuncMap\n");

}


//Building function javaType from line: 316

void javaType(list node) {
  
if (globalTrace)
    printf("javaType at q/java.qon:316 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:318");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(subnameof(node), boxString("struct"))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:320");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\npublic class %s {\n", stringify(first(codeof(node))));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:321");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\npublic String caller =\"\";");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:323");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaStruct(cdr(codeof(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:324");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n};\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:326");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(boxString(stringify(first(codeof(node)))), javaTypesNoDeclare())) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:327");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:329");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("public class %s extends %s {};\n", stringify(first(codeof(node))), stringify(javaTypeMap(listLast(codeof(node)))));

    };

  };

if (globalTrace)
    printf("Leaving javaType\n");

}


//Building function javaTypes from line: 333

void javaTypes(list nodes) {
  
if (globalTrace)
    printf("javaTypes at q/java.qon:333 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:335");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:336");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:337");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaType(car(nodes));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:337");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaTypes(cdr(nodes));

  };

if (globalTrace)
    printf("Leaving javaTypes\n");

}


//Building function javaCompile from line: 339

void javaCompile(char* filename) {
  char* programStr = "";
list tree = NULL;
list program = NULL;

if (globalTrace)
    printf("javaCompile at q/java.qon:339 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:341");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "package quonverter;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:342");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "import java.nio.file.Files;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:343");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "import java.nio.file.Paths;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:344");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "import java.io.IOException;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:345");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "import java.io.UnsupportedEncodingException;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:346");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("class MyProgram {\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:347");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\npublic String caller =\"\";");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:348");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:349");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:350");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:360");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = mergeIncludes(program);

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:361");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaIncludes(cdr(assoc("includes", program)));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:362");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaTypes(childrenof(cdr(assoc("types", program))));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:363");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public boolean globalStackTrace = false;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:364");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public boolean globalStepTrace = false;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:365");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public boolean globalTrace = false;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:366");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public boolean releaseMode = false;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:367");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public String FILE = null;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:368");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public Integer LINE = 0;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:369");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public static Integer globalArgsCount = 0;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:370");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public static String globalArgs[];\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:371");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\npublic boolean isNil(Box p) {\n    return p == null;\n}\n\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:373");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:375");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public static void main(String args[]) {\nglobalArgs = args;\nglobalArgsCount = args.length;MyProgram mp = new MyProgram(); mp.start();\n}");

if (globalTrace)
    snprintf(caller, 1024, "from q/java.qon:376");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("}\n");

if (globalTrace)
    printf("Leaving javaCompile\n");

}


//Building function nodeFunctionArgs from line: 4

void nodeFunctionArgs(list tree) {
  
if (globalTrace)
    printf("nodeFunctionArgs at q/node.qon:4 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:6");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:7");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving nodeFunctionArgs\n");

}


//Building function nodeLeaf from line: 13

void nodeLeaf(list thisNode, int indent) {
  
if (globalTrace)
    printf("nodeLeaf at q/node.qon:13 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:14");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  display(nodeFuncMap(codeof(thisNode)));

if (globalTrace)
    printf("Leaving nodeLeaf\n");

}


//Building function nodeStructGetterExpression from line: 16

void nodeStructGetterExpression(list thisNode, int indent) {
  
if (globalTrace)
    printf("nodeStructGetterExpression at q/node.qon:16 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving nodeStructGetterExpression\n");

}


//Building function nodeExpression from line: 22

void nodeExpression(list node, int indent) {
  
if (globalTrace)
    printf("nodeExpression at q/node.qon:22 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving nodeExpression\n");

}


//Building function nodeRecurList from line: 28

void nodeRecurList(list expr, int indent) {
  
if (globalTrace)
    printf("nodeRecurList at q/node.qon:28 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:32");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:33");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving nodeRecurList\n");

}


//Building function nodeSubExpression from line: 41

void nodeSubExpression(list tree, int indent) {
  box thing = NULL;

if (globalTrace)
    printf("nodeSubExpression at q/node.qon:41 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:43");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:44");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving nodeSubExpression\n");

}


//Building function nodeIf from line: 82

void nodeIf(list node, int indent) {
  
if (globalTrace)
    printf("nodeIf at q/node.qon:82 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving nodeIf\n");

}


//Building function nodeGetStruct from line: 96

void nodeGetStruct(list node, int indent) {
  
if (globalTrace)
    printf("nodeGetStruct at q/node.qon:96 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:98");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:99");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s.%s", stringify(first(codeof(node))), stringify(second(codeof(node))));

if (globalTrace)
    printf("Leaving nodeGetStruct\n");

}


//Building function nodeSet from line: 104

void nodeSet(list node, int indent) {
  
if (globalTrace)
    printf("nodeSet at q/node.qon:104 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving nodeSet\n");

}


//Building function nodeSetStruct from line: 110

void nodeSetStruct(list node, int indent) {
  
if (globalTrace)
    printf("nodeSetStruct at q/node.qon:110 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving nodeSetStruct\n");

}


//Building function nodeStatement from line: 118

void nodeStatement(list node, int indent) {
  
if (globalTrace)
    printf("nodeStatement at q/node.qon:118 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving nodeStatement\n");

}


//Building function nodeBody from line: 137

void nodeBody(list tree, int indent) {
  
if (globalTrace)
    printf("nodeBody at q/node.qon:137 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:141");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:142");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving nodeBody\n");

}


//Building function nodeDeclarations from line: 151

void nodeDeclarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("nodeDeclarations at q/node.qon:151 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:153");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:154");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving nodeDeclarations\n");

}


//Building function nodeFunction from line: 166

void nodeFunction(list node) {
  box name = NULL;

if (globalTrace)
    printf("nodeFunction at q/node.qon:166 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving nodeFunction\n");

}


//Building function nodeForwardDeclaration from line: 199

void nodeForwardDeclaration(list node) {
  
if (globalTrace)
    printf("nodeForwardDeclaration at q/node.qon:199 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:201");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:202");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving nodeForwardDeclaration\n");

}


//Building function nodeForwardDeclarations from line: 211

void nodeForwardDeclarations(list tree) {
  
if (globalTrace)
    printf("nodeForwardDeclarations at q/node.qon:211 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:215");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:216");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving nodeForwardDeclarations\n");

}


//Building function nodeFunctions from line: 221

void nodeFunctions(list tree) {
  
if (globalTrace)
    printf("nodeFunctions at q/node.qon:221 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:225");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:226");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving nodeFunctions\n");

}


//Building function nodeIncludes from line: 229

void nodeIncludes(list nodes) {
  
if (globalTrace)
    printf("nodeIncludes at q/node.qon:229 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving nodeIncludes\n");

}


//Building function nodeTypeDecl from line: 263

void nodeTypeDecl(list l) {
  
if (globalTrace)
    printf("nodeTypeDecl at q/node.qon:263 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving nodeTypeDecl\n");

}


//Building function nodeStructComponents from line: 280

void nodeStructComponents(list node) {
  
if (globalTrace)
    printf("nodeStructComponents at q/node.qon:280 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:284");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:285");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving nodeStructComponents\n");

}


//Building function nodeStruct from line: 288

void nodeStruct(list node) {
  
if (globalTrace)
    printf("nodeStruct at q/node.qon:288 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:291");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeStructComponents(cdr(car(node)));

if (globalTrace)
    printf("Leaving nodeStruct\n");

}


//Building function nodeTypeMap from line: 293

box nodeTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("nodeTypeMap at q/node.qon:293 (%s)\n", caller);

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

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:305");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return aSym;;

  };

if (globalTrace)
    printf("Leaving nodeTypeMap\n");

}


//Building function nodeFuncMap from line: 308

box nodeFuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("nodeFuncMap at q/node.qon:308 (%s)\n", caller);

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

      return cdr(assoc(stringify(aSym), symMap));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:337");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return aSym;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:338");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return aSym;;

  };

if (globalTrace)
    printf("Leaving nodeFuncMap\n");

}


//Building function nodeType from line: 339

void nodeType(list node) {
  
if (globalTrace)
    printf("nodeType at q/node.qon:339 (%s)\n", caller);

if (globalTrace)
    printf("Leaving nodeType\n");

}


//Building function nodeTypes from line: 343

void nodeTypes(list nodes) {
  
if (globalTrace)
    printf("nodeTypes at q/node.qon:343 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:347");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/node.qon:348");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving nodeTypes\n");

}


//Building function nodeCompile from line: 351

void nodeCompile(char* filename) {
  char* programStr = "";
list tree = NULL;
list program = NULL;

if (globalTrace)
    printf("nodeCompile at q/node.qon:351 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving nodeCompile\n");

}


//Building function test0 from line: 7

void test0() {
  
if (globalTrace)
    printf("test0 at q/tests.qon:7 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving test0\n");

}


//Building function test1 from line: 20

void test1() {
  
if (globalTrace)
    printf("test1 at q/tests.qon:20 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:21");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("1.  pass Function call and print work\n");

if (globalTrace)
    printf("Leaving test1\n");

}


//Building function test2_do from line: 24

void test2_do(char* message) {
  
if (globalTrace)
    printf("test2_do at q/tests.qon:24 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:27");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("2.  pass Function call with arg works: %s\n", message);

if (globalTrace)
    printf("Leaving test2_do\n");

}


//Building function test2 from line: 28

void test2() {
  
if (globalTrace)
    printf("test2 at q/tests.qon:28 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  test2_do("This is the argument");

if (globalTrace)
    printf("Leaving test2\n");

}


//Building function test3_do from line: 30

void test3_do(int b, char* c) {
  
if (globalTrace)
    printf("test3_do at q/tests.qon:30 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:34");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("3.1 pass Two arg call, first arg: %d\n", b);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:35");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("3.2 pass Two arg call, second arg: %s\n", c);

if (globalTrace)
    printf("Leaving test3_do\n");

}


//Building function test3 from line: 36

void test3() {
  
if (globalTrace)
    printf("test3 at q/tests.qon:36 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:36");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  test3_do(42, "Fourty-two");

if (globalTrace)
    printf("Leaving test3\n");

}


//Building function test4_do from line: 37

char* test4_do() {
  
if (globalTrace)
    printf("test4_do at q/tests.qon:37 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:37");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return "pass Return works";;

if (globalTrace)
    printf("Leaving test4_do\n");

}


//Building function returnThis from line: 39

char* returnThis(char* returnMessage) {
  
if (globalTrace)
    printf("returnThis at q/tests.qon:39 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:40");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return returnMessage;;

if (globalTrace)
    printf("Leaving returnThis\n");

}


//Building function test4 from line: 42

void test4() {
  char* message = "fail";

if (globalTrace)
    printf("test4 at q/tests.qon:42 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:43");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  message = test4_do();

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:43");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("4.  %s\n", message);

if (globalTrace)
    printf("Leaving test4\n");

}


//Building function test5 from line: 45

void test5() {
  char* message = "fail";

if (globalTrace)
    printf("test5 at q/tests.qon:45 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:47");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  message = returnThis("pass return passthrough string");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:48");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("5.  %s\n", message);

if (globalTrace)
    printf("Leaving test5\n");

}


//Building function test6 from line: 50

void test6() {
  
if (globalTrace)
    printf("test6 at q/tests.qon:50 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving test6\n");

}


//Building function test7_do from line: 58

int test7_do(int count) {
  
if (globalTrace)
    printf("test7_do at q/tests.qon:58 (%s)\n", caller);

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

    return count;;

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:64");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return count;;

if (globalTrace)
    printf("Leaving test7_do\n");

}


//Building function test7 from line: 66

void test7() {
  
if (globalTrace)
    printf("test7 at q/tests.qon:66 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving test7\n");

}


//Building function beer from line: 74

void beer() {
  
if (globalTrace)
    printf("beer at q/tests.qon:74 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:78");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%d bottle of beer on the wall, %d bottle of beer.  Take one down, pass it round, no bottles of beer on the wall\n", 1, 1);

if (globalTrace)
    printf("Leaving beer\n");

}


//Building function plural from line: 83

char* plural(int num) {
  
if (globalTrace)
    printf("plural at q/tests.qon:83 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:86");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(num, 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:86");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return "";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:86");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return "s";;

  };

if (globalTrace)
    printf("Leaving plural\n");

}


//Building function beers from line: 88

int beers(int count) {
  int newcount = 0;

if (globalTrace)
    printf("beers at q/tests.qon:88 (%s)\n", caller);

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

    return count;;

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:102");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return 0;;

if (globalTrace)
    printf("Leaving beers\n");

}


//Building function test8 from line: 104

void test8() {
  
if (globalTrace)
    printf("test8 at q/tests.qon:104 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving test8\n");

}


//Building function test9 from line: 112

void test9() {
  int answer = -999999;

if (globalTrace)
    printf("test9 at q/tests.qon:112 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:116");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  answer = sub(sub(20, 1), sub(3, 1));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:117");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(answer, 17)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:118");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.1  pass sub works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:119");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.1  fail sub\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:120");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  answer = add(2, 3);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:121");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(answer, 5)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:122");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.2  pass add works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:123");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.2  fail add\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:124");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  answer = mult(2, 3);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:125");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(answer, 6)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:126");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.3  pass mult works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:127");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.3  fail mult\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:128");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(2, 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:129");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.4  pass greaterthan works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:130");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.4  fail greaterthan\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:131");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(1, 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:132");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.5  pass integer equal works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:133");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.5  fail integer equal\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:134");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("hello", "hello")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:135");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.6  pass string equal works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:136");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.6  fail string equal\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:137");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("hello", "world")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:138");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.7  fail string equal\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:139");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.7  pass string equal\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:140");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( andBool(false, false)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:141");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.8  fail andBool\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:142");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.8  pass andBool works\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:143");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( andBool(true, true)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:144");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.9  pass andBool works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:145");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.9  fail andBool\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:146");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( andBool(true, false)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:147");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.10  fail andBool\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:148");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.10  pass andBool works\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:149");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("hello", "hello")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:150");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.11  pass string equal\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:151");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.11  fail string equal\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:152");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("!", character(33))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:153");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.12  pass character\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:154");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.12  fail character\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:155");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("33", intToString(33))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:156");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.13  pass intToString\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:157");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.13  fail intToString\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:161");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("llo", sub_string("hello", 2, 3))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:162");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.14  pass sub-string\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:163");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.14  fail sub-string: %s\n", sub_string("hello", 2, 3));

  };

if (globalTrace)
    printf("Leaving test9\n");

}


//Building function test10 from line: 167

void test10() {
  char* testString = "This is a test string";

if (globalTrace)
    printf("test10 at q/tests.qon:167 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:171");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(testString, unBoxString(car(cons(boxString(testString), NULL))))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:174");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("10. pass cons and car work\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:175");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("10. fail cons and car fail\n");

  };

if (globalTrace)
    printf("Leaving test10\n");

}


//Building function test12 from line: 177

void test12() {
  box b = NULL;

if (globalTrace)
    printf("test12 at q/tests.qon:177 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:181");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = malloc(sizeof(Box));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:182");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->str = "12. pass structure accessors\n";

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:183");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", b->str);

if (globalTrace)
    printf("Leaving test12\n");

}


//Building function test13 from line: 185

void test13() {
  char* testString = "Hello from the filesystem!";
char* contents = "";

if (globalTrace)
    printf("test13 at q/tests.qon:185 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:191");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  write_file("test.txt", testString);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:192");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  contents = read_file("test.txt");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:193");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(testString, contents)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:194");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("13. pass Read and write files\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:196");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("13. fail Read and write files\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:197");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Expected: %s\n", testString);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:198");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Got: %s\n", contents);

  };

if (globalTrace)
    printf("Leaving test13\n");

}


//Building function test15 from line: 201

void test15() {
  char* a = "hello";
char* b = " world";
char* c = "";

if (globalTrace)
    printf("test15 at q/tests.qon:201 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:204");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  c = stringConcatenate(a, b);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:205");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(c, "hello world")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:206");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("15. pass String concatenate\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:207");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("15. fail String concatenate\n");

  };

if (globalTrace)
    printf("Leaving test15\n");

}


//Building function test16 from line: 209

void test16() {
  list assocCell1 = NULL;
list assList = NULL;
list assocCell2 = NULL;
list assocCell3 = NULL;

if (globalTrace)
    printf("test16 at q/tests.qon:209 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:216");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assocCell1 = cons(boxString("Hello"), boxString("world"));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:217");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assocCell2 = cons(boxString("goodnight"), boxString("moon"));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:218");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assocCell3 = cons(boxSymbol("ohio"), boxString("gozaimasu"));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:219");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assList = cons(assocCell2, emptyList());

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:220");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assList = cons(assocCell1, assList);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:221");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assList = cons(assocCell3, assList);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:222");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(cdr(assoc("Hello", assList)), boxString("world"))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:223");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("16.1 pass Basic assoc works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:224");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("16.1 fail Basic assoc fails\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:225");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( andBool(andBool(equalBox(cdr(assoc("Hello", assList)), boxString("world")), equalBox(cdr(assoc("goodnight", assList)), boxString("moon"))), equalBox(cdr(assoc("ohio", assList)), boxString("gozaimasu")))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:230");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("16.2 pass assoc list\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:231");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("16.2 fail assoc list\n");

  };

if (globalTrace)
    printf("Leaving test16\n");

}


//Building function test17 from line: 233

void test17() {
  list l = NULL;

if (globalTrace)
    printf("test17 at q/tests.qon:233 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:235");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxInt(1), cons(boxInt(2), cons(boxInt(3), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:236");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(car(l), boxInt(1))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:237");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("17. pass list literal works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:238");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("17. fail list literal failed\n");

  };

if (globalTrace)
    printf("Leaving test17\n");

}


//Building function test18 from line: 244

void test18() {
  char* val1 = "a";
char* val2 = "b";
list l = NULL;

if (globalTrace)
    printf("test18 at q/tests.qon:244 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:250");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:251");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(l, cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), NULL))))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:252");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("18. pass string list constructor works\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:253");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("18. fail string list constructor failed\n");

  };

if (globalTrace)
    printf("Leaving test18\n");

}


//Building function test19 from line: 258

void test19() {
  char* val1 = "a";
char* val2 = "b";
list l = NULL;
list revlist = NULL;
list answer = NULL;

if (globalTrace)
    printf("test19 at q/tests.qon:258 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:267");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:268");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  answer = cons(boxString("c"), cons(boxString(val2), cons(boxString(val1), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:269");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  revlist = reverseList(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:270");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(answer, revlist)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:271");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("19. pass reverseList\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:272");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("19. fail reverseList\n");

  };

if (globalTrace)
    printf("Leaving test19\n");

}


//Building function concatenateLists from line: 276

list concatenateLists(list oldL, list newL) {
  
if (globalTrace)
    printf("concatenateLists at q/tests.qon:276 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:278");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return reverseRec(reverseList(oldL), newL);;

if (globalTrace)
    printf("Leaving concatenateLists\n");

}


//Building function test20 from line: 281

void test20() {
  char* val1 = "a";
char* val2 = "b";
char* val3 = "c";
list l = NULL;
list l2 = NULL;
list l3 = NULL;
list combined = NULL;

if (globalTrace)
    printf("test20 at q/tests.qon:281 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:291");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:292");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l2 = cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:293");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l3 = cons(boxString(val1), cons(boxString(val2), cons(boxString(val3), cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), NULL))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:294");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  combined = concatenateLists(l, l2);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:295");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(l3, combined)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:296");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("21. pass concatenateLists\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:297");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("21. fail concatenateLists\n");

  };

if (globalTrace)
    printf("Leaving test20\n");

}


//Building function test21 from line: 301

void test21() {
  char* val1 = "a";
char* val2 = "b";
char* val3 = "c";
list l = NULL;
list l2 = NULL;

if (globalTrace)
    printf("test21 at q/tests.qon:301 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:309");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString(val3), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:310");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l2 = cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:311");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(l, l2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:312");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("21. pass equalList\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:313");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("21. fail equalList\n");

  };

if (globalTrace)
    printf("Leaving test21\n");

}


//Building function test22 from line: 317

void test22() {
  list original = NULL;
list out = NULL;
list replace = NULL;
list correct = NULL;

if (globalTrace)
    printf("test22 at q/tests.qon:317 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:324");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:325");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxString("fprintf"), cons(boxString("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:326");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  out = macrolist(original, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:328");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  correct = cons(boxString("fprintf"), cons(boxString("stderr"), cons(boxString("%s"), cons(boxString("hello"), NULL))));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:329");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(out, correct)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:330");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("22. pass macroList\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:331");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("22. fail macroList\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:332");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("In: ");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:333");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    displayList(original, 0, true);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:334");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\nOut: ");

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:335");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    displayList(out, 0, true);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:336");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n");

  };

if (globalTrace)
    printf("Leaving test22\n");

}


//Building function test23 from line: 340

void test23() {
  list original = NULL;
list out = NULL;
list replace = NULL;
list correct = NULL;

if (globalTrace)
    printf("test23 at q/tests.qon:340 (%s)\n", caller);

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

  out = concatLists(original, replace);

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:351");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  correct = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), cons(boxString("fprintf"), cons(boxString("stderr"), NULL)))));

if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:352");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(out, correct)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:353");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("23. pass concatLists\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/tests.qon:354");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("23. fail concatLists\n");

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

  };

if (globalTrace)
    printf("Leaving test23\n");

}


//Building function ansi3displays from line: 5

void ansi3displays(char* s) {
  
if (globalTrace)
    printf("ansi3displays at q/ansi3.qon:5 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:7");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", s);

if (globalTrace)
    printf("Leaving ansi3displays\n");

}


//Building function ansi3FunctionArgs from line: 11

void ansi3FunctionArgs(list tree) {
  
if (globalTrace)
    printf("ansi3FunctionArgs at q/ansi3.qon:11 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:13");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:14");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving ansi3FunctionArgs\n");

}


//Building function ansi3Expression from line: 28

void ansi3Expression(list tree, int indent) {
  list thing = NULL;

if (globalTrace)
    printf("ansi3Expression at q/ansi3.qon:28 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:30");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:34");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equal(1, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:37");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:39");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("return"), car(tree))) {
      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:43");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        ansi3displays("()");

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:46");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      thing = first(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:47");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxSymbol("get-struct"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:50");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s->%s", stringify(second(tree)), stringify(third(tree)));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:55");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxSymbol("new"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:58");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("malloc(sizeof(%s))", stringify(third(tree)));

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:62");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("passthrough"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:65");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s", stringify(second(tree)));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:69");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("binop"), thing)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:72");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("(");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:73");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              ansi3Expression(third(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:74");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(" %s ", stringify(second(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:77");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              ansi3Expression(fourth(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:78");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:82");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s(", stringify(ansi3FuncMap(car(tree))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:86");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              ansi3RecurList(cdr(tree), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:87");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            };

          };

        };

      };

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:95");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(ansi3FuncMap(tree));

  };

if (globalTrace)
    printf("Leaving ansi3Expression\n");

}


//Building function ansi3RecurList from line: 98

void ansi3RecurList(list expr, int indent) {
  
if (globalTrace)
    printf("ansi3RecurList at q/ansi3.qon:98 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:102");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:103");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:105");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Expression(car(expr), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:106");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:107");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi3displays("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:108");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi3displays(", ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:108");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi3RecurList(cdr(expr), indent);

    };

  };

if (globalTrace)
    printf("Leaving ansi3RecurList\n");

}


//Building function ansi3If from line: 115

void ansi3If(list node, int indent) {
  
if (globalTrace)
    printf("ansi3If at q/ansi3.qon:115 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:117");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:118");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("if ( ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:119");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Expression(second(node), 0);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:120");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays(") {");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:121");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Body(cdr(third(node)), add1(indent));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:122");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:123");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("} else {");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:124");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Body(cdr(fourth(node)), add1(indent));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:125");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:126");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("}");

if (globalTrace)
    printf("Leaving ansi3If\n");

}


//Building function ansi3SetStruct from line: 128

void ansi3SetStruct(list node, int indent) {
  
if (globalTrace)
    printf("ansi3SetStruct at q/ansi3.qon:128 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:130");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:131");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->%s = ", stringify(second(node)), stringify(third(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:135");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Expression(fourth(node), indent);

if (globalTrace)
    printf("Leaving ansi3SetStruct\n");

}


//Building function ansi3GetStruct from line: 137

void ansi3GetStruct(list node, int indent) {
  
if (globalTrace)
    printf("ansi3GetStruct at q/ansi3.qon:137 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:139");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:140");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->%s", stringify(first(node)), stringify(second(node)));

if (globalTrace)
    printf("Leaving ansi3GetStruct\n");

}


//Building function ansi3Set from line: 145

void ansi3Set(list node, int indent) {
  
if (globalTrace)
    printf("ansi3Set at q/ansi3.qon:145 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:147");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:148");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Expression(first(cdr(node)), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:149");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(" = ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:150");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Expression(third(node), indent);

if (globalTrace)
    printf("Leaving ansi3Set\n");

}


//Building function ansi3Return from line: 152

void ansi3Return(list node, int indent) {
  
if (globalTrace)
    printf("ansi3Return at q/ansi3.qon:152 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:154");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:155");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(listLength(node), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:156");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3displays("return;");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:158");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3displays("return ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:159");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Expression(cadr(node), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:160");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3displays(";");

  };

if (globalTrace)
    printf("Leaving ansi3Return\n");

}


//Building function ansi3Statement from line: 163

void ansi3Statement(list node, int indent) {
  
if (globalTrace)
    printf("ansi3Statement at q/ansi3.qon:163 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:165");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("set"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:166");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Set(node, indent);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:168");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("set-struct"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:169");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi3SetStruct(node, indent);

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:171");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:172");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        ansi3If(node, indent);

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:174");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("return"), first(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:175");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          ansi3Return(node, indent);

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:177");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:178");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          ansi3Expression(node, indent);

        };

      };

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:179");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays(";\n");

if (globalTrace)
    printf("Leaving ansi3Statement\n");

}


//Building function ansi3Body from line: 181

void ansi3Body(list tree, int indent) {
  list code = NULL;

if (globalTrace)
    printf("ansi3Body at q/ansi3.qon:181 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:183");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:184");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:186");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    code = tree;

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:187");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(code)) {
    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:190");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      code = car(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:191");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( not(releaseMode)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:194");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("\nif (globalTrace)\n    snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), stringify(getTagFail(car(code), boxString("line"), boxString("Line missing"))));

      } else {
      };

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:198");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( not(releaseMode)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:199");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printIndent(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:200");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n");

    } else {
    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:203");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Statement(code, indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:204");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Body(cdr(tree), indent);

  };

if (globalTrace)
    printf("Leaving ansi3Body\n");

}


//Building function ansi3Declarations from line: 206

void ansi3Declarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("ansi3Declarations at q/ansi3.qon:206 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:208");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:209");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:211");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:212");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s = ", stringify(ansi3TypeMap(first(decl))), stringify(second(decl)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:216");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Expression(third(decl), indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:217");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:218");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Declarations(cdr(decls), indent);

  };

if (globalTrace)
    printf("Leaving ansi3Declarations\n");

}


//Building function ansi3Function from line: 220

void ansi3Function(list node) {
  box name = NULL;

if (globalTrace)
    printf("ansi3Function at q/ansi3.qon:220 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:222");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = second(node);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:223");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:224");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:225");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:226");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:228");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:229");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s(", stringify(ansi3TypeMap(first(node))), stringify(second(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:233");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3FunctionArgs(third(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:234");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(") {");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:235");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:236");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Declarations(cdr(fourth(node)), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:237");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:238");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:240");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    printf(\"%s at %s:%s (%%s)\\n\", caller);\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:241");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:242");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:247");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Body(cdr(fifth(node)), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:248");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( releaseMode) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:249");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:251");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    printf(\"Leaving %s\\n\");\n", stringify(name));

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:253");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n");

  };

if (globalTrace)
    printf("Leaving ansi3Function\n");

}


//Building function ansi3ForwardDeclaration from line: 255

void ansi3ForwardDeclaration(list node) {
  
if (globalTrace)
    printf("ansi3ForwardDeclaration at q/ansi3.qon:255 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:257");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:257");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:258");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n%s %s(", stringify(ansi3TypeMap(first(node))), stringify(second(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:262");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3FunctionArgs(third(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:263");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3displays(");");

  };

if (globalTrace)
    printf("Leaving ansi3ForwardDeclaration\n");

}


//Building function ansi3ForwardDeclarations from line: 265

void ansi3ForwardDeclarations(list tree) {
  
if (globalTrace)
    printf("ansi3ForwardDeclarations at q/ansi3.qon:265 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:267");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:267");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:268");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3ForwardDeclaration(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:269");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3ForwardDeclarations(cdr(tree));

  };

if (globalTrace)
    printf("Leaving ansi3ForwardDeclarations\n");

}


//Building function ansi3Functions from line: 271

void ansi3Functions(list tree) {
  
if (globalTrace)
    printf("ansi3Functions at q/ansi3.qon:271 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:273");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:273");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:274");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Function(car(tree));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:274");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Functions(cdr(tree));

  };

if (globalTrace)
    printf("Leaving ansi3Functions\n");

}


//Building function ansi3Includes from line: 277

void ansi3Includes(list nodes) {
  
if (globalTrace)
    printf("ansi3Includes at q/ansi3.qon:277 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:279");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\nbool releaseMode = false;\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:282");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n");

if (globalTrace)
    printf("Leaving ansi3Includes\n");

}


//Building function ansi3TypeDecl from line: 285

void ansi3TypeDecl(list l) {
  
if (globalTrace)
    printf("ansi3TypeDecl at q/ansi3.qon:285 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:287");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 2)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:289");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:290");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s %s;\n", stringify(second(l)), stringify(ansi3TypeMap(listLast(l))), stringify(first(l)));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:296");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:297");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s;\n", stringify(ansi3TypeMap(listLast(l))), stringify(car(l)));

  };

if (globalTrace)
    printf("Leaving ansi3TypeDecl\n");

}


//Building function ansi3StructComponents from line: 302

void ansi3StructComponents(list node) {
  
if (globalTrace)
    printf("ansi3StructComponents at q/ansi3.qon:302 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:304");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:305");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:306");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3TypeDecl(car(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:306");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3StructComponents(cdr(node));

  };

if (globalTrace)
    printf("Leaving ansi3StructComponents\n");

}


//Building function ansi3Struct from line: 308

void ansi3Struct(list node) {
  
if (globalTrace)
    printf("ansi3Struct at q/ansi3.qon:308 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:309");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3StructComponents(cdr(node));

if (globalTrace)
    printf("Leaving ansi3Struct\n");

}


//Building function ansi3TypeMap from line: 311

box ansi3TypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("ansi3TypeMap at q/ansi3.qon:311 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:313");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:317");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:318");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:319");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return aSym;;

  };

if (globalTrace)
    printf("Leaving ansi3TypeMap\n");

}


//Building function ansi3FuncMap from line: 321

box ansi3FuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("ansi3FuncMap at q/ansi3.qon:321 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:323");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:325");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), NULL)))))));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:347");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym), symMap))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:348");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return cdr(assoc(stringify(aSym), symMap));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:349");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return aSym;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:350");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return aSym;;

  };

if (globalTrace)
    printf("Leaving ansi3FuncMap\n");

}


//Building function ansi3Type from line: 352

void ansi3Type(list node) {
  
if (globalTrace)
    printf("ansi3Type at q/ansi3.qon:352 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:354");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(second(node))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:356");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\ntypedef struct %s {\n", stringify(first(node)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:357");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Struct(second(node));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:358");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n} %s;\n", stringify(first(node)));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:359");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3displays("typedef ");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:359");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3TypeDecl(node);

  };

if (globalTrace)
    printf("Leaving ansi3Type\n");

}


//Building function ansi3Types from line: 362

void ansi3Types(list nodes) {
  
if (globalTrace)
    printf("ansi3Types at q/ansi3.qon:362 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:364");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:365");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:366");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Type(car(nodes));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:366");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Types(cdr(nodes));

  };

if (globalTrace)
    printf("Leaving ansi3Types\n");

}


//Building function ansi3Compile from line: 372

void ansi3Compile(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    printf("ansi3Compile at q/ansi3.qon:372 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Scanning file...%s\n", filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:379");
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
    snprintf(caller, 1024, "from q/ansi3.qon:383");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = buildProg(cons(boxString("q/shims/ansi3.qon"), getIncludes(tree)), getTypes(tree), getFunctions(tree));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Loading all includes\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:385");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Applying macros\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:387");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:388");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:389");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Printing program\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:395");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Includes(cdr(first(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:396");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Types(cdr(second(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:398");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("Box* globalStackTrace = NULL;\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:399");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:401");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3ForwardDeclarations(cdr(third(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:402");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("\n\n//End forward declarations\n\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:403");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Functions(cdr(third(tree)));

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi3.qon:404");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("\n");

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "//Done printing program\n");

if (globalTrace)
    printf("Leaving ansi3Compile\n");

}


//Building function ansi2displays from line: 5

void ansi2displays(char* s) {
  
if (globalTrace)
    printf("ansi2displays at q/ansi2.qon:5 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:7");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", s);

if (globalTrace)
    printf("Leaving ansi2displays\n");

}


//Building function ansi2FunctionArgs from line: 11

void ansi2FunctionArgs(list tree) {
  
if (globalTrace)
    printf("ansi2FunctionArgs at q/ansi2.qon:11 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:13");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:14");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving ansi2FunctionArgs\n");

}


//Building function ansi2Expression from line: 28

void ansi2Expression(list tree, int indent) {
  list thing = NULL;

if (globalTrace)
    printf("ansi2Expression at q/ansi2.qon:28 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansi2Expression\n");

}


//Building function ansi2RecurList from line: 98

void ansi2RecurList(list expr, int indent) {
  
if (globalTrace)
    printf("ansi2RecurList at q/ansi2.qon:98 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:102");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:103");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving ansi2RecurList\n");

}


//Building function ansi2If from line: 115

void ansi2If(list node, int indent) {
  
if (globalTrace)
    printf("ansi2If at q/ansi2.qon:115 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansi2If\n");

}


//Building function ansi2SetStruct from line: 128

void ansi2SetStruct(list node, int indent) {
  
if (globalTrace)
    printf("ansi2SetStruct at q/ansi2.qon:128 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansi2SetStruct\n");

}


//Building function ansi2GetStruct from line: 137

void ansi2GetStruct(list node, int indent) {
  
if (globalTrace)
    printf("ansi2GetStruct at q/ansi2.qon:137 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:139");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:140");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->%s", stringify(first(node)), stringify(second(node)));

if (globalTrace)
    printf("Leaving ansi2GetStruct\n");

}


//Building function ansi2Set from line: 145

void ansi2Set(list node, int indent) {
  
if (globalTrace)
    printf("ansi2Set at q/ansi2.qon:145 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansi2Set\n");

}


//Building function ansi2Return from line: 152

void ansi2Return(list node, int indent) {
  
if (globalTrace)
    printf("ansi2Return at q/ansi2.qon:152 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansi2Return\n");

}


//Building function ansi2Statement from line: 163

void ansi2Statement(list node, int indent) {
  
if (globalTrace)
    printf("ansi2Statement at q/ansi2.qon:163 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansi2Statement\n");

}


//Building function ansi2Body from line: 181

void ansi2Body(list tree, int indent) {
  list code = NULL;

if (globalTrace)
    printf("ansi2Body at q/ansi2.qon:181 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:183");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:184");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving ansi2Body\n");

}


//Building function ansi2Declarations from line: 199

void ansi2Declarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("ansi2Declarations at q/ansi2.qon:199 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:201");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:202");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving ansi2Declarations\n");

}


//Building function ansi2Function from line: 213

void ansi2Function(list node) {
  box name = NULL;

if (globalTrace)
    printf("ansi2Function at q/ansi2.qon:213 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansi2Function\n");

}


//Building function ansi2ForwardDeclaration from line: 248

void ansi2ForwardDeclaration(list node) {
  
if (globalTrace)
    printf("ansi2ForwardDeclaration at q/ansi2.qon:248 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:250");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:250");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving ansi2ForwardDeclaration\n");

}


//Building function ansi2ForwardDeclarations from line: 258

void ansi2ForwardDeclarations(list tree) {
  
if (globalTrace)
    printf("ansi2ForwardDeclarations at q/ansi2.qon:258 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:260");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:260");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving ansi2ForwardDeclarations\n");

}


//Building function ansi2Functions from line: 264

void ansi2Functions(list tree) {
  
if (globalTrace)
    printf("ansi2Functions at q/ansi2.qon:264 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:266");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:266");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving ansi2Functions\n");

}


//Building function ansi2Includes from line: 270

void ansi2Includes(list nodes) {
  
if (globalTrace)
    printf("ansi2Includes at q/ansi2.qon:270 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansi2Includes\n");

}


//Building function ansi2TypeDecl from line: 279

void ansi2TypeDecl(list l) {
  
if (globalTrace)
    printf("ansi2TypeDecl at q/ansi2.qon:279 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansi2TypeDecl\n");

}


//Building function ansi2StructComponents from line: 296

void ansi2StructComponents(list node) {
  
if (globalTrace)
    printf("ansi2StructComponents at q/ansi2.qon:296 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:298");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:299");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving ansi2StructComponents\n");

}


//Building function ansi2Struct from line: 302

void ansi2Struct(list node) {
  
if (globalTrace)
    printf("ansi2Struct at q/ansi2.qon:302 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:303");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2StructComponents(cdr(node));

if (globalTrace)
    printf("Leaving ansi2Struct\n");

}


//Building function ansi2TypeMap from line: 305

box ansi2TypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("ansi2TypeMap at q/ansi2.qon:305 (%s)\n", caller);

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

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:315");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return aSym;;

  };

if (globalTrace)
    printf("Leaving ansi2TypeMap\n");

}


//Building function ansi2FuncMap from line: 317

box ansi2FuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("ansi2FuncMap at q/ansi2.qon:317 (%s)\n", caller);

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

      return cdr(assoc(stringify(aSym), symMap));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:345");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return aSym;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:346");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return aSym;;

  };

if (globalTrace)
    printf("Leaving ansi2FuncMap\n");

}


//Building function ansi2Type from line: 348

void ansi2Type(list node) {
  
if (globalTrace)
    printf("ansi2Type at q/ansi2.qon:348 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansi2Type\n");

}


//Building function ansi2Types from line: 358

void ansi2Types(list nodes) {
  
if (globalTrace)
    printf("ansi2Types at q/ansi2.qon:358 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:360");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi2.qon:361");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving ansi2Types\n");

}


//Building function ansi2Compile from line: 368

void ansi2Compile(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    printf("ansi2Compile at q/ansi2.qon:368 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansi2Compile\n");

}


//Building function ansiFunctionArgs from line: 3

void ansiFunctionArgs(list tree) {
  
if (globalTrace)
    printf("ansiFunctionArgs at q/ansi.qon:3 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:5");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:6");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving ansiFunctionArgs\n");

}


//Building function ansiLeaf from line: 14

void ansiLeaf(list thisNode, int indent) {
  
if (globalTrace)
    printf("ansiLeaf at q/ansi.qon:14 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:15");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  display(ansiFuncMap(codeof(thisNode)));

if (globalTrace)
    printf("Leaving ansiLeaf\n");

}


//Building function ansiStructGetterExpression from line: 17

void ansiStructGetterExpression(list thisNode, int indent) {
  
if (globalTrace)
    printf("ansiStructGetterExpression at q/ansi.qon:17 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansiStructGetterExpression\n");

}


//Building function ansiExpression from line: 23

void ansiExpression(list node, int indent) {
  
if (globalTrace)
    printf("ansiExpression at q/ansi.qon:23 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansiExpression\n");

}


//Building function ansiRecurList from line: 29

void ansiRecurList(list expr, int indent) {
  
if (globalTrace)
    printf("ansiRecurList at q/ansi.qon:29 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:33");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:34");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving ansiRecurList\n");

}


//Building function ansiSubExpression from line: 41

void ansiSubExpression(list tree, int indent) {
  box thing = NULL;

if (globalTrace)
    printf("ansiSubExpression at q/ansi.qon:41 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:43");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:44");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving ansiSubExpression\n");

}


//Building function ansiIf from line: 81

void ansiIf(list node, int indent) {
  
if (globalTrace)
    printf("ansiIf at q/ansi.qon:81 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansiIf\n");

}


//Building function ansiSetStruct from line: 94

void ansiSetStruct(list node, int indent) {
  
if (globalTrace)
    printf("ansiSetStruct at q/ansi.qon:94 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansiSetStruct\n");

}


//Building function ansiGetStruct from line: 103

void ansiGetStruct(list node, int indent) {
  
if (globalTrace)
    printf("ansiGetStruct at q/ansi.qon:103 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:105");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:106");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->%s", stringify(first(codeof(node))), stringify(second(codeof(node))));

if (globalTrace)
    printf("Leaving ansiGetStruct\n");

}


//Building function ansiSet from line: 111

void ansiSet(list node, int indent) {
  
if (globalTrace)
    printf("ansiSet at q/ansi.qon:111 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansiSet\n");

}


//Building function ansiStatement from line: 117

void ansiStatement(list node, int indent) {
  
if (globalTrace)
    printf("ansiStatement at q/ansi.qon:117 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansiStatement\n");

}


//Building function ansiBody from line: 135

void ansiBody(list tree, int indent) {
  list code = NULL;

if (globalTrace)
    printf("ansiBody at q/ansi.qon:135 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:137");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:138");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving ansiBody\n");

}


//Building function ansiDeclarations from line: 156

void ansiDeclarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("ansiDeclarations at q/ansi.qon:156 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:158");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:159");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving ansiDeclarations\n");

}


//Building function ansiFunction from line: 170

void ansiFunction(list node) {
  box name = NULL;

if (globalTrace)
    printf("ansiFunction at q/ansi.qon:170 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansiFunction\n");

}


//Building function ansiForwardDeclaration from line: 204

void ansiForwardDeclaration(list node) {
  
if (globalTrace)
    printf("ansiForwardDeclaration at q/ansi.qon:204 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:206");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:207");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving ansiForwardDeclaration\n");

}


//Building function ansiForwardDeclarations from line: 216

void ansiForwardDeclarations(list tree) {
  
if (globalTrace)
    printf("ansiForwardDeclarations at q/ansi.qon:216 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:218");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:219");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving ansiForwardDeclarations\n");

}


//Building function ansiFunctions from line: 224

void ansiFunctions(list tree) {
  
if (globalTrace)
    printf("ansiFunctions at q/ansi.qon:224 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:226");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:227");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving ansiFunctions\n");

}


//Building function ansiIncludes from line: 229

void ansiIncludes(list nodes) {
  
if (globalTrace)
    printf("ansiIncludes at q/ansi.qon:229 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansiIncludes\n");

}


//Building function ansiTypeDecl from line: 239

void ansiTypeDecl(list l) {
  
if (globalTrace)
    printf("ansiTypeDecl at q/ansi.qon:239 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansiTypeDecl\n");

}


//Building function ansiStructComponents from line: 256

void ansiStructComponents(list node) {
  
if (globalTrace)
    printf("ansiStructComponents at q/ansi.qon:256 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:258");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:259");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving ansiStructComponents\n");

}


//Building function ansiStruct from line: 262

void ansiStruct(list node) {
  
if (globalTrace)
    printf("ansiStruct at q/ansi.qon:262 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:263");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiStructComponents(cdr(car(node)));

if (globalTrace)
    printf("Leaving ansiStruct\n");

}


//Building function ansiTypeMap from line: 265

box ansiTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("ansiTypeMap at q/ansi.qon:265 (%s)\n", caller);

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

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:275");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return aSym;;

  };

if (globalTrace)
    printf("Leaving ansiTypeMap\n");

}


//Building function ansiFuncMap from line: 277

box ansiFuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("ansiFuncMap at q/ansi.qon:277 (%s)\n", caller);

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

      return cdr(assoc(stringify(aSym), symMap));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:305");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return aSym;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:306");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return aSym;;

  };

if (globalTrace)
    printf("Leaving ansiFuncMap\n");

}


//Building function ansiType from line: 308

void ansiType(list node) {
  
if (globalTrace)
    printf("ansiType at q/ansi.qon:308 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansiType\n");

}


//Building function ansiTypes from line: 318

void ansiTypes(list nodes) {
  
if (globalTrace)
    printf("ansiTypes at q/ansi.qon:318 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:320");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/ansi.qon:321");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving ansiTypes\n");

}


//Building function ansiCompile from line: 328

void ansiCompile(char* filename) {
  char* programStr = "";
list tree = NULL;
list program = NULL;

if (globalTrace)
    printf("ansiCompile at q/ansi.qon:328 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving ansiCompile\n");

}


//Building function numbers from line: 4

list numbers(int num) {
  
if (globalTrace)
    printf("numbers at q/perl.qon:4 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:6");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(0, num)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:7");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return cons(boxString("-"), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:8");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return cons(boxString(stringify(boxInt(num))), numbers(sub1(num)));;

  };

if (globalTrace)
    printf("Leaving numbers\n");

}


//Building function lexType from line: 11

char* lexType(box abox) {
  
if (globalTrace)
    printf("lexType at q/perl.qon:11 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:14");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("string", boxType(abox))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:15");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return "string";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:17");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(boxString(sub_string(stringify(abox), 0, 1)), numbers(9))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:18");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return "number";;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:19");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return "symbol";;

    };

  };

if (globalTrace)
    printf("Leaving lexType\n");

}


//Building function perlLeaf from line: 23

void perlLeaf(list thisNode, int indent) {
  
if (globalTrace)
    printf("perlLeaf at q/perl.qon:23 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving perlLeaf\n");

}


//Building function perlStructGetterExpression from line: 32

void perlStructGetterExpression(list thisNode, int indent) {
  
if (globalTrace)
    printf("perlStructGetterExpression at q/perl.qon:32 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving perlStructGetterExpression\n");

}


//Building function perlExpression from line: 38

void perlExpression(list node, int indent) {
  
if (globalTrace)
    printf("perlExpression at q/perl.qon:38 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving perlExpression\n");

}


//Building function perlRecurList from line: 44

void perlRecurList(list expr, int indent) {
  
if (globalTrace)
    printf("perlRecurList at q/perl.qon:44 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:46");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:47");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving perlRecurList\n");

}


//Building function perlSubExpression from line: 55

void perlSubExpression(list tree, int indent) {
  box thing = NULL;

if (globalTrace)
    printf("perlSubExpression at q/perl.qon:55 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:57");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:58");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving perlSubExpression\n");

}


//Building function perlIf from line: 93

void perlIf(list node, int indent) {
  
if (globalTrace)
    printf("perlIf at q/perl.qon:93 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving perlIf\n");

}


//Building function perlSetStruct from line: 106

void perlSetStruct(list node, int indent) {
  
if (globalTrace)
    printf("perlSetStruct at q/perl.qon:106 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving perlSetStruct\n");

}


//Building function perlGetStruct from line: 113

void perlGetStruct(list node, int indent) {
  
if (globalTrace)
    printf("perlGetStruct at q/perl.qon:113 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:115");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:116");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s->{%s}", dollar(), stringify(first(codeof(node))), stringify(second(codeof(node))));

if (globalTrace)
    printf("Leaving perlGetStruct\n");

}


//Building function perlSet from line: 118

void perlSet(list node, int indent) {
  
if (globalTrace)
    printf("perlSet at q/perl.qon:118 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving perlSet\n");

}


//Building function assertNode from line: 124

void assertNode(list node) {
  
if (globalTrace)
    printf("assertNode at q/perl.qon:124 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:126");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNode(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:127");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:128");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Not a node!");

  };

if (globalTrace)
    printf("Leaving assertNode\n");

}


//Building function perlStatement from line: 131

void perlStatement(list node, int indent) {
  box functionName = NULL;

if (globalTrace)
    printf("perlStatement at q/perl.qon:131 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving perlStatement\n");

}


//Building function perlBody from line: 180

void perlBody(list tree, int indent) {
  
if (globalTrace)
    printf("perlBody at q/perl.qon:180 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:182");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:183");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving perlBody\n");

}


//Building function perlDeclarations from line: 190

void perlDeclarations(list decls, int indent) {
  box decl = NULL;

if (globalTrace)
    printf("perlDeclarations at q/perl.qon:190 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:192");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:193");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving perlDeclarations\n");

}


//Building function perlFunction from line: 201

void perlFunction(list node) {
  box name = NULL;

if (globalTrace)
    printf("perlFunction at q/perl.qon:201 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving perlFunction\n");

}


//Building function perlForwardDeclaration from line: 233

void perlForwardDeclaration(list node) {
  
if (globalTrace)
    printf("perlForwardDeclaration at q/perl.qon:233 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:235");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:236");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving perlForwardDeclaration\n");

}


//Building function perlForwardDeclarations from line: 243

void perlForwardDeclarations(list tree) {
  
if (globalTrace)
    printf("perlForwardDeclarations at q/perl.qon:243 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:245");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:246");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving perlForwardDeclarations\n");

}


//Building function perlFunctions from line: 251

void perlFunctions(list tree) {
  
if (globalTrace)
    printf("perlFunctions at q/perl.qon:251 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:253");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:254");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving perlFunctions\n");

}


//Building function dollar from line: 258

char* dollar() {
  
if (globalTrace)
    printf("dollar at q/perl.qon:258 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:259");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return character(36);;

if (globalTrace)
    printf("Leaving dollar\n");

}


//Building function atSym from line: 261

char* atSym() {
  
if (globalTrace)
    printf("atSym at q/perl.qon:261 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:262");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return character(64);;

if (globalTrace)
    printf("Leaving atSym\n");

}


//Building function perlIncludes from line: 265

void perlIncludes(list nodes) {
  
if (globalTrace)
    printf("perlIncludes at q/perl.qon:265 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving perlIncludes\n");

}


//Building function perlTypeDecl from line: 301

void perlTypeDecl(list l) {
  
if (globalTrace)
    printf("perlTypeDecl at q/perl.qon:301 (%s)\n", caller);

if (globalTrace)
    printf("Leaving perlTypeDecl\n");

}


//Building function perlStructComponents from line: 306

void perlStructComponents(list node) {
  
if (globalTrace)
    printf("perlStructComponents at q/perl.qon:306 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:308");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:309");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving perlStructComponents\n");

}


//Building function perlStruct from line: 312

void perlStruct(list node) {
  
if (globalTrace)
    printf("perlStruct at q/perl.qon:312 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:313");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlStructComponents(cdr(car(node)));

if (globalTrace)
    printf("Leaving perlStruct\n");

}


//Building function perlTypeMap from line: 315

box perlTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("perlTypeMap at q/perl.qon:315 (%s)\n", caller);

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

    return cdr(assoc(stringify(aSym), symMap));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:325");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return aSym;;

  };

if (globalTrace)
    printf("Leaving perlTypeMap\n");

}


//Building function perlConstMap from line: 327

box perlConstMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("perlConstMap at q/perl.qon:327 (%s)\n", caller);

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

    return cdr(assocFail(stringify(aSym), symMap, aSym));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:335");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return aSym;;

  };

if (globalTrace)
    printf("Leaving perlConstMap\n");

}


//Building function perlFuncMap from line: 337

box perlFuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    printf("perlFuncMap at q/perl.qon:337 (%s)\n", caller);

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

    return cdr(assocFail(stringify(aSym), symMap, aSym));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:352");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return aSym;;

  };

if (globalTrace)
    printf("Leaving perlFuncMap\n");

}


//Building function perlType from line: 354

void perlType(list node) {
  
if (globalTrace)
    printf("perlType at q/perl.qon:354 (%s)\n", caller);

if (globalTrace)
    printf("Leaving perlType\n");

}


//Building function perlTypes from line: 359

void perlTypes(list nodes) {
  
if (globalTrace)
    printf("perlTypes at q/perl.qon:359 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:361");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:362");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving perlTypes\n");

}


//Building function perlFunctionArgs from line: 365

void perlFunctionArgs(list tree) {
  
if (globalTrace)
    printf("perlFunctionArgs at q/perl.qon:365 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:367");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/perl.qon:368");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

if (globalTrace)
    printf("Leaving perlFunctionArgs\n");

}


//Building function perlCompile from line: 375

void perlCompile(char* filename) {
  char* programStr = "";
list tree = NULL;
list program = NULL;

if (globalTrace)
    printf("perlCompile at q/perl.qon:375 (%s)\n", caller);

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

if (globalTrace)
    printf("Leaving perlCompile\n");

}


//Building function readSexpr from line: 4

list readSexpr(char* aStr, char* filename) {
  list tokens = NULL;
list as = NULL;

if (globalTrace)
    printf("readSexpr at q/newparser.qon:4 (%s)\n", caller);

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

  return car(as);;

if (globalTrace)
    printf("Leaving readSexpr\n");

}


//Building function sexprTree from line: 11

list sexprTree(list l) {
  box b = NULL;

if (globalTrace)
    printf("sexprTree at q/newparser.qon:11 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:13");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:14");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

      return cons(sexprTree(cdr(l)), sexprTree(skipList(cdr(l))));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:21");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isCloseBrace(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:22");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return emptyList();;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:24");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return setTag(boxString("line"), getTagFail(b, boxString("line"), boxInt(-1)), cons(b, sexprTree(cdr(l))));;

      };

    };

  };

if (globalTrace)
    printf("Leaving sexprTree\n");

}


//Building function loadQuon from line: 29

list loadQuon(char* filename) {
  char* programStr = "";
list tree = NULL;

if (globalTrace)
    printf("loadQuon at q/newparser.qon:29 (%s)\n", caller);

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

  return tree;;

if (globalTrace)
    printf("Leaving loadQuon\n");

}


//Building function getIncludes from line: 38

list getIncludes(list program) {
  
if (globalTrace)
    printf("getIncludes at q/newparser.qon:38 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:40");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cdr(first(program));;

if (globalTrace)
    printf("Leaving getIncludes\n");

}


//Building function getTypes from line: 42

list getTypes(list program) {
  
if (globalTrace)
    printf("getTypes at q/newparser.qon:42 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:44");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cdr(second(program));;

if (globalTrace)
    printf("Leaving getTypes\n");

}


//Building function getFunctions from line: 46

list getFunctions(list program) {
  
if (globalTrace)
    printf("getFunctions at q/newparser.qon:46 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:48");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cdr(third(program));;

if (globalTrace)
    printf("Leaving getFunctions\n");

}


//Building function loadIncludes from line: 51

list loadIncludes(list tree) {
  list newProg = NULL;
char* includeFile = "";
list functionsCombined = NULL;
list typesCombined = NULL;
list includeTree = NULL;

if (globalTrace)
    printf("loadIncludes at q/newparser.qon:51 (%s)\n", caller);

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

    return loadIncludes(newProg);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/newparser.qon:71");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return tree;;

  };

if (globalTrace)
    printf("Leaving loadIncludes\n");

}


//Building function buildProg from line: 74

list buildProg(list includes, list types, list functions) {
  list program = NULL;

if (globalTrace)
    printf("buildProg at q/newparser.qon:74 (%s)\n", caller);

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

  return program;;

if (globalTrace)
    printf("Leaving buildProg\n");

}


//Building function car from line: 9

box car(list l) {
  
if (globalTrace)
    printf("car at q/lists.qon:9 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:12");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:14");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Cannot call car on empty list!\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:15");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Cannot call car on empty list!\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:16");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:18");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    assertType("list", l, 18, "q/lists.qon");

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:19");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(l->car)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:20");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return NULL;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:21");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return l->car;;

    };

  };

if (globalTrace)
    printf("Leaving car\n");

}


//Building function cdr from line: 23

list cdr(list l) {
  
if (globalTrace)
    printf("cdr at q/lists.qon:23 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:25");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assertType("list", l, 25, "q/lists.qon");

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:26");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:28");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Attempt to cdr an empty list!!!!\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:29");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Attempt to cdr an empty list!!!!\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:30");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:31");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return l->cdr;;

  };

if (globalTrace)
    printf("Leaving cdr\n");

}


//Building function cons from line: 33

list cons(box data, list l) {
  pair p = NULL;

if (globalTrace)
    printf("cons at q/lists.qon:33 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:35");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  p = makePair();

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:36");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  p->cdr = l;

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:37");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  p->car = data;

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:38");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  p->typ = "list";

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:39");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return p;;

if (globalTrace)
    printf("Leaving cons\n");

}


//Building function caar from line: 45

box caar(list l) {
  
if (globalTrace)
    printf("caar at q/lists.qon:45 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:45");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return car(car(l));;

if (globalTrace)
    printf("Leaving caar\n");

}


//Building function cadr from line: 46

box cadr(list l) {
  
if (globalTrace)
    printf("cadr at q/lists.qon:46 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:46");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return car(cdr(l));;

if (globalTrace)
    printf("Leaving cadr\n");

}


//Building function caddr from line: 47

box caddr(list l) {
  
if (globalTrace)
    printf("caddr at q/lists.qon:47 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:47");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return car(cdr(cdr(l)));;

if (globalTrace)
    printf("Leaving caddr\n");

}


//Building function cadddr from line: 48

box cadddr(list l) {
  
if (globalTrace)
    printf("cadddr at q/lists.qon:48 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:48");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return car(cdr(cdr(cdr(l))));;

if (globalTrace)
    printf("Leaving cadddr\n");

}


//Building function caddddr from line: 49

box caddddr(list l) {
  
if (globalTrace)
    printf("caddddr at q/lists.qon:49 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:49");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return car(cdr(cdr(cdr(cdr(l)))));;

if (globalTrace)
    printf("Leaving caddddr\n");

}


//Building function cddr from line: 50

box cddr(list l) {
  
if (globalTrace)
    printf("cddr at q/lists.qon:50 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:50");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cdr(cdr(l));;

if (globalTrace)
    printf("Leaving cddr\n");

}


//Building function first from line: 51

box first(list l) {
  
if (globalTrace)
    printf("first at q/lists.qon:51 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:51");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return car(l);;

if (globalTrace)
    printf("Leaving first\n");

}


//Building function second from line: 52

box second(list l) {
  
if (globalTrace)
    printf("second at q/lists.qon:52 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:52");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cadr(l);;

if (globalTrace)
    printf("Leaving second\n");

}


//Building function third from line: 53

box third(list l) {
  
if (globalTrace)
    printf("third at q/lists.qon:53 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:53");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return caddr(l);;

if (globalTrace)
    printf("Leaving third\n");

}


//Building function fourth from line: 54

box fourth(list l) {
  
if (globalTrace)
    printf("fourth at q/lists.qon:54 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:54");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cadddr(l);;

if (globalTrace)
    printf("Leaving fourth\n");

}


//Building function fifth from line: 55

box fifth(list l) {
  
if (globalTrace)
    printf("fifth at q/lists.qon:55 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:55");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return caddddr(l);;

if (globalTrace)
    printf("Leaving fifth\n");

}


//Building function isList from line: 58

bool isList(box b) {
  
if (globalTrace)
    printf("isList at q/lists.qon:58 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:61");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:62");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:63");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return equalString("list", b->typ);;

  };

if (globalTrace)
    printf("Leaving isList\n");

}


//Building function emptyList from line: 65

list emptyList() {
  
if (globalTrace)
    printf("emptyList at q/lists.qon:65 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:65");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return NULL;;

if (globalTrace)
    printf("Leaving emptyList\n");

}


//Building function isEmpty from line: 67

bool isEmpty(box b) {
  
if (globalTrace)
    printf("isEmpty at q/lists.qon:67 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:69");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:70");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:72");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return false;;

  };

if (globalTrace)
    printf("Leaving isEmpty\n");

}


//Building function listLength from line: 74

int listLength(list l) {
  
if (globalTrace)
    printf("listLength at q/lists.qon:74 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:78");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:79");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return 0;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:80");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return add1(listLength(cdr(l)));;

  };

if (globalTrace)
    printf("Leaving listLength\n");

}


//Building function alistCons from line: 83

list alistCons(box key, box value, list alist) {
  
if (globalTrace)
    printf("alistCons at q/lists.qon:83 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:84");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cons(cons(key, value), alist);;

if (globalTrace)
    printf("Leaving alistCons\n");

}


//Building function assoc from line: 86

list assoc(char* searchTerm, list l) {
  list elem = NULL;

if (globalTrace)
    printf("assoc at q/lists.qon:86 (%s)\n", caller);

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

        return elem;;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:103");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return assoc(searchTerm, cdr(l));;

      };

    };

  };

if (globalTrace)
    printf("Leaving assoc\n");

}


//Building function chooseBox from line: 106

char* chooseBox(char* aType) {
  
if (globalTrace)
    printf("chooseBox at q/lists.qon:106 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:108");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("string", aType)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:109");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return "boxString";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:110");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("symbol", aType)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:111");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return "boxSymbol";;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:112");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("bool", aType)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:113");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return "boxBool";;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:114");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("int", aType)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:115");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return "boxInt";;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:116");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("float", aType)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:117");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

  return "";;

if (globalTrace)
    printf("Leaving chooseBox\n");

}


//Building function mlistLiteral from line: 122

box mlistLiteral(box b) {
  
if (globalTrace)
    printf("mlistLiteral at q/lists.qon:122 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:124");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:125");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:127");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("string", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:128");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return b;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:130");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("bool", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:132");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return b;;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:134");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("int", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:135");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return b;;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:137");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("symbol", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:138");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return boxString(unBoxSymbol(b));;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:142");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return boxString(stringConcatenate("Unsupported type: ", boxType(b)));;

          };

        };

      };

    };

  };

if (globalTrace)
    printf("Leaving mlistLiteral\n");

}


//Building function doMultiList from line: 144

list doMultiList(list l) {
  list newlist = NULL;
list ret = NULL;
box elem = NULL;

if (globalTrace)
    printf("doMultiList at q/lists.qon:144 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:146");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:147");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return cons(boxSymbol("nil"), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:149");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:150");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return NULL;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:153");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      elem = first(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:154");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      newlist = cons(boxString(chooseBox(elem->typ)), cons(mlistLiteral(first(l)), newlist));

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:155");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ret = cons(cons(boxSymbol("cons"), cons(newlist, doMultiList(cdr(l)))), NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:164");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return ret;;

    };

  };

if (globalTrace)
    printf("Leaving doMultiList\n");

}


//Building function doStringList from line: 167

list doStringList(list l) {
  list newlist = NULL;
list ret = NULL;

if (globalTrace)
    printf("doStringList at q/lists.qon:167 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:169");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:170");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return cons(boxSymbol("nil"), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:172");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newlist = cons(boxSymbol("boxString"), cons(first(l), newlist));

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:173");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ret = cons(cons(boxSymbol("cons"), cons(newlist, doStringList(cdr(l)))), NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:182");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return ret;;

  };

if (globalTrace)
    printf("Leaving doStringList\n");

}


//Building function doSymbolList from line: 184

list doSymbolList(list l) {
  list newlist = NULL;
list ret = NULL;

if (globalTrace)
    printf("doSymbolList at q/lists.qon:184 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:186");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:187");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return cons(boxSymbol("nil"), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:189");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newlist = cons(boxSymbol("boxSymbol"), cons(first(l), newlist));

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:190");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ret = cons(cons(boxSymbol("cons"), cons(newlist, doSymbolList(cdr(l)))), NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:199");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return ret;;

  };

if (globalTrace)
    printf("Leaving doSymbolList\n");

}


//Building function doBoxList from line: 202

list doBoxList(list l) {
  
if (globalTrace)
    printf("doBoxList at q/lists.qon:202 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:205");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:206");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return cons(boxSymbol("nil"), NULL);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:208");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return cons(cons(boxSymbol("cons"), cons(first(l), doBoxList(cdr(l)))), NULL);;

  };

if (globalTrace)
    printf("Leaving doBoxList\n");

}


//Building function concatLists from line: 221

list concatLists(list seq1, list seq2) {
  
if (globalTrace)
    printf("concatLists at q/lists.qon:221 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:223");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(seq1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:224");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return seq2;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:225");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return cons(car(seq1), concatLists(cdr(seq1), seq2));;

  };

if (globalTrace)
    printf("Leaving concatLists\n");

}


//Building function alistKeys from line: 227

list alistKeys(list alist) {
  
if (globalTrace)
    printf("alistKeys at q/lists.qon:227 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:229");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(alist)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:230");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:231");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return cons(car(car(alist)), alistKeys(cdr(alist)));;

  };

if (globalTrace)
    printf("Leaving alistKeys\n");

}


//Building function displayList from line: 233

void displayList(list l, int indent, bool first) {
  box val = NULL;

if (globalTrace)
    printf("displayList at q/lists.qon:233 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:235");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:236");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:238");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:240");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:241");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return;;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:243");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( first) {
        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:245");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf(" ");

        };

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:246");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        val = car(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:247");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( isList(val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:249");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:250");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("%s", openBrace());

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:251");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          displayList(car(l), add1(indent), true);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:252");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("%s", closeBrace());

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:253");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          displayList(cdr(l), indent, false);

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:255");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("string", val->typ)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:256");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("\"%s\"", unBoxString(val));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:257");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s", stringify(val));

          };

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:258");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          displayList(cdr(l), indent, false);

        };

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:260");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("string", l->typ)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:261");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("\"%s\"", unBoxString(l));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:262");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s", stringify(l));

      };

    };

  };

if (globalTrace)
    printf("Leaving displayList\n");

}


//Building function listReverse from line: 265

list listReverse(list l) {
  
if (globalTrace)
    printf("listReverse at q/lists.qon:265 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:267");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:268");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:269");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return cons(car(l), listReverse(cdr(l)));;

  };

if (globalTrace)
    printf("Leaving listReverse\n");

}


//Building function inList from line: 271

bool inList(box item, list l) {
  
if (globalTrace)
    printf("inList at q/lists.qon:271 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:273");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:274");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:277");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(car(l), item)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:278");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:279");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return inList(item, cdr(l));;

    };

  };

if (globalTrace)
    printf("Leaving inList\n");

}


//Building function equalList from line: 281

bool equalList(list a, list b) {
  
if (globalTrace)
    printf("equalList at q/lists.qon:281 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:283");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(a)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:284");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:286");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:288");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return false;;

    };

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:291");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:292");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(a)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:294");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:296");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return false;;

    };

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:299");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(car(a), car(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:300");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return equalList(cdr(a), cdr(b));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:301");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return false;;

  };

if (globalTrace)
    printf("Leaving equalList\n");

}


//Building function reverseRec from line: 304

list reverseRec(list oldL, list newL) {
  
if (globalTrace)
    printf("reverseRec at q/lists.qon:304 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:306");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(oldL)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:307");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return newL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:308");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return reverseRec(cdr(oldL), cons(first(oldL), newL));;

  };

if (globalTrace)
    printf("Leaving reverseRec\n");

}


//Building function reverseList from line: 311

list reverseList(list l) {
  
if (globalTrace)
    printf("reverseList at q/lists.qon:311 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/lists.qon:313");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return reverseRec(l, NULL);;

if (globalTrace)
    printf("Leaving reverseList\n");

}


//Building function macrowalk from line: 5

list macrowalk(list l) {
  
if (globalTrace)
    printf("macrowalk at q/macros.qon:5 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:6");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:7");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

        return car(doStringList(cdr(l)));;

      } else {
      };

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:31");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringConcatenate("symbol", "List"), stringify(car(l)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:34");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return car(doSymbolList(cdr(l)));;

      } else {
      };

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:36");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringConcatenate("multi", "List"), stringify(car(l)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:39");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return car(doMultiList(cdr(l)));;

      } else {
      };

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:42");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return cons(macrowalk(car(l)), macrowalk(cdr(l)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:44");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return l;;

    };

  };

if (globalTrace)
    printf("Leaving macrowalk\n");

}


//Building function macrosingle from line: 49

list macrosingle(list l, char* search, char* replace) {
  box val = NULL;

if (globalTrace)
    printf("macrosingle at q/macros.qon:49 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:50");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:51");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:55");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:57");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return cons(macrosingle(car(l), search, replace), macrosingle(cdr(l), search, replace));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:62");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(search, stringify(l))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:65");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        val = clone(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:66");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        val->str = replace;

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:67");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return val;;

      } else {
      };

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:69");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return l;;

    };

  };

if (globalTrace)
    printf("Leaving macrosingle\n");

}


//Building function macrolist from line: 73

list macrolist(list l, char* search, list replace) {
  box val = NULL;

if (globalTrace)
    printf("macrolist at q/macros.qon:73 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:74");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:75");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:79");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:82");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(search, stringify(car(l)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:85");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return concatLists(replace, macrolist(cdr(l), search, replace));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:88");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return cons(macrolist(car(l), search, replace), macrolist(cdr(l), search, replace));;

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/macros.qon:96");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return l;;

    };

  };

if (globalTrace)
    printf("Leaving macrolist\n");

}


//Building function filterVoid from line: 8

list filterVoid(list l) {
  box token = NULL;

if (globalTrace)
    printf("filterVoid at q/compiler.qon:8 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:12");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:13");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

      return filterVoid(cdr(l));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:18");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return cons(token, filterVoid(cdr(l)));;

    };

  };

if (globalTrace)
    printf("Leaving filterVoid\n");

}


//Building function filterTokens from line: 20

list filterTokens(list l) {
  box token = NULL;

if (globalTrace)
    printf("filterTokens at q/compiler.qon:20 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:24");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:25");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

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

        return cons(getTagFail(token, boxString("line"), boxInt(-1)), filterTokens(cdr(l)));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:37");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("__COLUMN__", stringify(token))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:39");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return cons(getTagFail(token, boxString("column"), boxInt(-1)), filterTokens(cdr(l)));;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:44");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("__FILE__", stringify(token))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:46");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return cons(getTagFail(token, boxString("filename"), boxString("Unknown file")), filterTokens(cdr(l)));;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:51");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return cons(token, filterTokens(cdr(l)));;

          };

        };

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:52");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return cons(token, filterTokens(cdr(l)));;

    };

  };

if (globalTrace)
    printf("Leaving filterTokens\n");

}


//Building function finish_token from line: 54

box finish_token(char* prog, int start, int len, int line, int column, char* filename) {
  box token = NULL;

if (globalTrace)
    printf("finish_token at q/compiler.qon:54 (%s)\n", caller);

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

    return token;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:67");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return newVoid();;

  };

if (globalTrace)
    printf("Leaving finish_token\n");

}


//Building function readString from line: 69

char* readString(char* prog, int start, int len) {
  char* token = "";

if (globalTrace)
    printf("readString at q/compiler.qon:69 (%s)\n", caller);

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

    return sub_string(prog, start, sub1(len));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:75");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("\\", token)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:76");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return readString(prog, start, add(2, len));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:77");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return readString(prog, start, add1(len));;

    };

  };

if (globalTrace)
    printf("Leaving readString\n");

}


//Building function readComment from line: 80

char* readComment(char* prog, int start, int len) {
  char* token = "";

if (globalTrace)
    printf("readComment at q/compiler.qon:80 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:82");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  token = sub_string(prog, sub1(add(start, len)), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:83");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isLineBreak(token)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:84");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return sub_string(prog, start, sub1(len));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:85");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return readComment(prog, start, add1(len));;

  };

if (globalTrace)
    printf("Leaving readComment\n");

}


//Building function isWhiteSpace from line: 88

bool isWhiteSpace(char* s) {
  
if (globalTrace)
    printf("isWhiteSpace at q/compiler.qon:88 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:92");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(" ", s)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:93");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:95");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("\t", s)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:96");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:98");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("\n", s)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:99");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return true;;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:101");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("\r", s)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:102");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return true;;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:103");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return false;;

        };

      };

    };

  };

if (globalTrace)
    printf("Leaving isWhiteSpace\n");

}


//Building function isLineBreak from line: 105

bool isLineBreak(char* s) {
  
if (globalTrace)
    printf("isLineBreak at q/compiler.qon:105 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:107");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("\n", s)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:108");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:110");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("\r", s)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:110");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:110");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return false;;

    };

  };

if (globalTrace)
    printf("Leaving isLineBreak\n");

}


//Building function incForNewLine from line: 112

int incForNewLine(box token, int val) {
  
if (globalTrace)
    printf("incForNewLine at q/compiler.qon:112 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:116");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("\n", stringify(token))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:117");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return add1(val);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:118");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return val;;

  };

if (globalTrace)
    printf("Leaving incForNewLine\n");

}


//Building function annotateReadPosition from line: 120

box annotateReadPosition(char* filename, int linecount, int column, int start, box newBox) {
  
if (globalTrace)
    printf("annotateReadPosition at q/compiler.qon:120 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:122");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return setTag(boxString("filename"), boxString(filename), setTag(boxString("column"), boxInt(column), setTag(boxString("line"), boxInt(linecount), setTag(boxString("totalCharPos"), boxInt(start), newBox))));;

if (globalTrace)
    printf("Leaving annotateReadPosition\n");

}


//Building function scan from line: 132

list scan(char* prog, int start, int len, int linecount, int column, char* filename) {
  box token = NULL;
char* newString = "";
box newBox = NULL;

if (globalTrace)
    printf("scan at q/compiler.qon:132 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:135");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(string_length(prog), sub(start, sub(0, len)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:137");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token = boxSymbol(sub_string(prog, sub1(add(start, len)), 1));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:138");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token->tag = alistCons(boxString("totalCharPos"), boxInt(start), NULL);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:139");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isOpenBrace(token)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:141");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return cons(finish_token(prog, start, sub1(len), linecount, column, filename), cons(boxSymbol(openBrace()), scan(prog, add1(start), 1, linecount, add1(column), filename)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:145");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isCloseBrace(token)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:147");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return cons(finish_token(prog, start, sub1(len), linecount, column, filename), cons(annotateReadPosition(filename, linecount, column, start, boxSymbol(closeBrace())), scan(prog, add(start, len), 1, linecount, add1(column), filename)));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:152");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( isWhiteSpace(stringify(token))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:154");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return cons(finish_token(prog, start, sub1(len), linecount, column, filename), scan(prog, add(start, len), 1, incForNewLine(token, linecount), 0, filename));;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:157");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol(";"), token)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:159");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return scan(prog, add(start, add1(add1(string_length(readComment(prog, add1(start), len))))), 1, add1(linecount), 0, filename);;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:161");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("\""), token)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:163");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              newString = readString(prog, add1(start), len);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:164");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              newBox = annotateReadPosition(filename, linecount, column, start, boxString(newString));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:166");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              return cons(newBox, scan(prog, add(start, add1(add1(string_length(newString)))), 1, linecount, add1(column), filename));;

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:168");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              return scan(prog, start, sub(len, -1), linecount, add1(column), filename);;

            };

          };

        };

      };

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:169");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return emptyList();;

  };

if (globalTrace)
    printf("Leaving scan\n");

}


//Building function isOpenBrace from line: 172

bool isOpenBrace(box b) {
  
if (globalTrace)
    printf("isOpenBrace at q/compiler.qon:172 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:174");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxSymbol(openBrace()), b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:175");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:177");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxSymbol("["), b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:178");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:179");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return false;;

    };

  };

if (globalTrace)
    printf("Leaving isOpenBrace\n");

}


//Building function isCloseBrace from line: 181

bool isCloseBrace(box b) {
  
if (globalTrace)
    printf("isCloseBrace at q/compiler.qon:181 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:185");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxSymbol(closeBrace()), b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:186");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:188");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxSymbol("]"), b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:189");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:190");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return false;;

    };

  };

if (globalTrace)
    printf("Leaving isCloseBrace\n");

}


//Building function skipList from line: 194

list skipList(list l) {
  box b = NULL;

if (globalTrace)
    printf("skipList at q/compiler.qon:194 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:196");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:197");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:199");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    b = car(l);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:200");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isOpenBrace(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:201");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return skipList(skipList(cdr(l)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:203");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isCloseBrace(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:204");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return cdr(l);;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:205");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return skipList(cdr(l));;

      };

    };

  };

if (globalTrace)
    printf("Leaving skipList\n");

}


//Building function makeNode from line: 216

list makeNode(char* name, char* subname, list code, list children) {
  
if (globalTrace)
    printf("makeNode at q/compiler.qon:216 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:218");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cons(boxSymbol("node"), alistCons(boxSymbol("line"), getTagFail(code, boxString("line"), boxInt(-1)), cons(cons(boxSymbol("name"), boxString(name)), cons(cons(boxSymbol("subname"), boxString(subname)), cons(cons(boxSymbol("code"), code), alistCons(boxSymbol("children"), children, emptyList()))))));;

if (globalTrace)
    printf("Leaving makeNode\n");

}


//Building function addToNode from line: 232

list addToNode(box key, box val, list node) {
  
if (globalTrace)
    printf("addToNode at q/compiler.qon:232 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:234");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cons(boxSymbol("node"), alistCons(key, val, cdr(node)));;

if (globalTrace)
    printf("Leaving addToNode\n");

}


//Building function makeStatementNode from line: 237

list makeStatementNode(char* name, char* subname, list code, list children, box functionName) {
  
if (globalTrace)
    printf("makeStatementNode at q/compiler.qon:237 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:239");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return addToNode(boxSymbol("functionName"), functionName, makeNode(name, subname, code, children));;

if (globalTrace)
    printf("Leaving makeStatementNode\n");

}


//Building function astExpression from line: 242

list astExpression(list tree) {
  
if (globalTrace)
    printf("astExpression at q/compiler.qon:242 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:244");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:246");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return makeNode("expression", "expression", NULL, astSubExpression(tree));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:248");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return astSubExpression(tree);;

  };

if (globalTrace)
    printf("Leaving astExpression\n");

}


//Building function astSubExpression from line: 250

list astSubExpression(list tree) {
  
if (globalTrace)
    printf("astSubExpression at q/compiler.qon:250 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:252");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:253");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:255");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:257");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return cons(astExpression(car(tree)), astSubExpression(cdr(tree)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:259");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return makeNode("expression", "leaf", tree, NULL);;

    };

  };

if (globalTrace)
    printf("Leaving astSubExpression\n");

}


//Building function astIf from line: 261

list astIf(list tree, box fname) {
  
if (globalTrace)
    printf("astIf at q/compiler.qon:261 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:263");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("then"), car(second(tree)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:264");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nop();

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:266");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Error at %s:%s!  If statement is missing the true branch.\n\n", stringify(getTag(car(first(tree)), boxString("filename"))), stringify(getTag(car(first(tree)), boxString("line"))));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:267");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Missing true branch in if statement!  All if statements must have a true and false branch, like this:\n\n(if hungryForApples\n(then (printf \"yes!\"))\n(else (printf \"no!\")))\n\n\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:269");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("else"), car(third(tree)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:270");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nop();

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:272");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Error at %s:%s!  If statement is missing the false branch.\n\n", stringify(getTag(car(first(tree)), boxString("filename"))), stringify(getTag(car(first(tree)), boxString("line"))));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:273");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Missing false branch in if statement!  All if statements must have a true and false branch, like this:\n\n(if hungryForApples\n(then (printf \"yes!\"))\n(else (printf \"no!\")))\n\n\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:274");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return makeNode("statement", "if", tree, cons(cons(astExpression(first(tree)), NULL), cons(astBody(cdr(second(tree)), fname), cons(astBody(cdr(third(tree)), fname), NULL))));;

if (globalTrace)
    printf("Leaving astIf\n");

}


//Building function astSetStruct from line: 282

list astSetStruct(list tree) {
  
if (globalTrace)
    printf("astSetStruct at q/compiler.qon:282 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:284");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return makeNode("statement", "structSetter", tree, astExpression(third(tree)));;

if (globalTrace)
    printf("Leaving astSetStruct\n");

}


//Building function astSet from line: 287

list astSet(list tree) {
  
if (globalTrace)
    printf("astSet at q/compiler.qon:287 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:289");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return makeNode("statement", "setter", tree, astExpression(second(tree)));;

if (globalTrace)
    printf("Leaving astSet\n");

}


//Building function astGetStruct from line: 292

list astGetStruct(list tree) {
  
if (globalTrace)
    printf("astGetStruct at q/compiler.qon:292 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:293");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return makeNode("expression", "structGetter", tree, NULL);;

if (globalTrace)
    printf("Leaving astGetStruct\n");

}


//Building function astReturnVoid from line: 295

list astReturnVoid(box fname) {
  
if (globalTrace)
    printf("astReturnVoid at q/compiler.qon:295 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:297");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return makeStatementNode("statement", "returnvoid", NULL, NULL, fname);;

if (globalTrace)
    printf("Leaving astReturnVoid\n");

}


//Building function astStatement from line: 299

list astStatement(list tree, box fname) {
  
if (globalTrace)
    printf("astStatement at q/compiler.qon:299 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:302");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:303");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nop();

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:305");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Error at %s:%s!  Statement must be a list.\n\n", stringify(getTag(car(first(tree)), boxString("filename"))), stringify(getTag(car(first(tree)), boxString("line"))));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:306");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("A statement must be a list: (printf \"Hello\")\n\n\n");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:309");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("if"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:310");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return astIf(cdr(tree), fname);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:312");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("set"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:313");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return astSet(cdr(tree));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:315");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("get-struct"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:317");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("Choosing get-struct statement\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:318");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return astGetStruct(cdr(tree));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:320");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("set-struct"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:321");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return astSetStruct(cdr(tree));;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:323");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxString("return"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:325");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equal(listLength(tree), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:326");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              return astReturnVoid(fname);;

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:328");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              return makeStatementNode("statement", "return", tree, makeNode("expression", "expression", tree, astExpression(tree)), fname);;

            };

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:332");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return makeStatementNode("statement", "statement", tree, makeNode("expression", "expression", tree, astExpression(tree)), fname);;

          };

        };

      };

    };

  };

if (globalTrace)
    printf("Leaving astStatement\n");

}


//Building function astBody from line: 337

list astBody(list tree, box fname) {
  
if (globalTrace)
    printf("astBody at q/compiler.qon:337 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:339");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:340");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:341");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return cons(astStatement(car(tree), fname), astBody(cdr(tree), fname));;

  };

if (globalTrace)
    printf("Leaving astBody\n");

}


//Building function astFunction from line: 345

list astFunction(list tree) {
  char* file = "";
char* line = "";
box fname = NULL;

if (globalTrace)
    printf("astFunction at q/compiler.qon:345 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:347");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fname = second(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:350");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  line = stringify(getTag(fname, boxString("line")));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:351");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  file = stringify(getTag(fname, boxString("filename")));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:352");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(1, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:352");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    locPanic(file, line, "Malformed function, seems to be empty");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:353");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(2, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:353");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    locPanic(file, line, "Malformed function, expected function name");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:354");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(3, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:354");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    locPanic(file, line, "Malformed function, expected argument list");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:355");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(4, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:355");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    locPanic(file, line, "Malformed function, expected variable declarations");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:356");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(5, listLength(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:356");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    locPanic(file, line, "Malformed function, expected body");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:357");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return alistCons(boxSymbol("file"), getTag(fname, boxString("filename")), alistCons(boxSymbol("line"), getTag(fname, boxString("line")), cons(cons(boxSymbol("name"), boxString("function")), cons(cons(boxSymbol("subname"), second(tree)), cons(cons(boxSymbol("declarations"), cdr(fourth(tree))), cons(cons(boxSymbol("intype"), third(tree)), cons(cons(boxSymbol("outtype"), car(tree)), cons(cons(boxSymbol("children"), astBody(cdr(fifth(tree)), fname)), emptyList()))))))));;

if (globalTrace)
    printf("Leaving astFunction\n");

}


//Building function astFunctionList from line: 378

list astFunctionList(list tree) {
  
if (globalTrace)
    printf("astFunctionList at q/compiler.qon:378 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:380");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:381");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:383");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return cons(astFunction(car(tree)), astFunctionList(cdr(tree)));;

  };

if (globalTrace)
    printf("Leaving astFunctionList\n");

}


//Building function astFunctions from line: 386

list astFunctions(list tree) {
  
if (globalTrace)
    printf("astFunctions at q/compiler.qon:386 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:388");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("functions"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:389");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return makeNode("functions", "functions", tree, astFunctionList(cdr(tree)));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:390");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Functions section not found!  Every program must have a function section, even if you don't define any functions, although that is a rather pointless program.  Your function section should look like:'\n\n(return_type function_name (arg1 arg2 arg3 ...) (declare types) (body (statement)(statement)))\n\n\nThe function section must be directly after the types section.");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:391");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return NULL;;

  };

if (globalTrace)
    printf("Leaving astFunctions\n");

}


//Building function loadLib from line: 394

list loadLib(char* path) {
  char* programStr = "";
list tree = NULL;
list library = NULL;

if (globalTrace)
    printf("loadLib at q/compiler.qon:394 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:397");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(path);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:398");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, path);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:399");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:400");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  library = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:408");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return library;;

if (globalTrace)
    printf("Leaving loadLib\n");

}


//Building function astInclude from line: 410

list astInclude(list tree) {
  
if (globalTrace)
    printf("astInclude at q/compiler.qon:410 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:411");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return loadLib(stringify(tree));;

if (globalTrace)
    printf("Leaving astInclude\n");

}


//Building function astIncludeList from line: 413

list astIncludeList(list tree) {
  
if (globalTrace)
    printf("astIncludeList at q/compiler.qon:413 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:415");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:416");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:418");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return cons(astInclude(car(tree)), astIncludeList(cdr(tree)));;

  };

if (globalTrace)
    printf("Leaving astIncludeList\n");

}


//Building function astIncludes from line: 420

list astIncludes(list tree) {
  
if (globalTrace)
    printf("astIncludes at q/compiler.qon:420 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:423");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("includes"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:424");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return makeNode("includes", "includes", tree, astIncludeList(cdr(tree)));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:425");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Includes section not found!  Every program must have an include section, even if you don't import any libraries.  Your include section should look like:'\n\n(includes file1.qon file.qon)\n\n\nThe includes section must be the first section of the file.");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:426");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return NULL;;

  };

if (globalTrace)
    printf("Leaving astIncludes\n");

}


//Building function astStruct from line: 428

list astStruct(list tree) {
  
if (globalTrace)
    printf("astStruct at q/compiler.qon:428 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:429");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return makeNode("type", "struct", tree, NULL);;

if (globalTrace)
    printf("Leaving astStruct\n");

}


//Building function astType from line: 431

list astType(list tree) {
  
if (globalTrace)
    printf("astType at q/compiler.qon:431 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:433");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(cadr(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:434");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return astStruct(tree);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:435");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return makeNode("type", "type", tree, NULL);;

  };

if (globalTrace)
    printf("Leaving astType\n");

}


//Building function astTypeList from line: 437

list astTypeList(list tree) {
  
if (globalTrace)
    printf("astTypeList at q/compiler.qon:437 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:439");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:440");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return emptyList();;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:441");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return cons(astType(car(tree)), astTypeList(cdr(tree)));;

  };

if (globalTrace)
    printf("Leaving astTypeList\n");

}


//Building function astTypes from line: 443

list astTypes(list tree) {
  
if (globalTrace)
    printf("astTypes at q/compiler.qon:443 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:445");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(tree)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:446");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Empty or absent types section");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:447");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return boxString("!!!Fuck");;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:449");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("types"), car(tree))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:450");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return makeNode("types", "types", tree, astTypeList(cdr(tree)));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:452");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      panic("Types section not found!  Every program must have a types section, even if you don't define any types");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:453");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("Types section not found!  Every program must have a types section, even if you don't define any types");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:454");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return boxString("!!!Fuck");;

    };

  };

if (globalTrace)
    printf("Leaving astTypes\n");

}


//Building function declarationsof from line: 461

list declarationsof(list ass) {
  
if (globalTrace)
    printf("declarationsof at q/compiler.qon:461 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:462");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cdr(assocPanic("declarations", cdr(ass), "Cons list has no declarations key"));;

if (globalTrace)
    printf("Leaving declarationsof\n");

}


//Building function codeof from line: 464

list codeof(list ass) {
  
if (globalTrace)
    printf("codeof at q/compiler.qon:464 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:465");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cdr(assocPanic("code", cdr(ass), "Given cons list does not contain a code key"));;

if (globalTrace)
    printf("Leaving codeof\n");

}


//Building function functionNameof from line: 467

list functionNameof(list ass) {
  
if (globalTrace)
    printf("functionNameof at q/compiler.qon:467 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:468");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cdr(assoc("functionName", cdr(ass)));;

if (globalTrace)
    printf("Leaving functionNameof\n");

}


//Building function nodeof from line: 470

list nodeof(list ass) {
  
if (globalTrace)
    printf("nodeof at q/compiler.qon:470 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:472");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxBool(false), assoc("node", cdr(ass)))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:474");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Given list does not contain nodes");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:475");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return boxBool(false);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:476");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return cdr(assoc("node", cdr(ass)));;

  };

if (globalTrace)
    printf("Leaving nodeof\n");

}


//Building function lineof from line: 478

list lineof(list ass) {
  
if (globalTrace)
    printf("lineof at q/compiler.qon:478 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:480");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cdr(assocFail("line", cdr(ass), boxInt(-1)));;

if (globalTrace)
    printf("Leaving lineof\n");

}


//Building function subnameof from line: 483

list subnameof(list ass) {
  
if (globalTrace)
    printf("subnameof at q/compiler.qon:483 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:484");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cdr(assoc("subname", cdr(ass)));;

if (globalTrace)
    printf("Leaving subnameof\n");

}


//Building function nameof from line: 486

list nameof(list ass) {
  
if (globalTrace)
    printf("nameof at q/compiler.qon:486 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:487");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cdr(assoc("name", cdr(ass)));;

if (globalTrace)
    printf("Leaving nameof\n");

}


//Building function childrenof from line: 489

list childrenof(list ass) {
  
if (globalTrace)
    printf("childrenof at q/compiler.qon:489 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:490");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cdr(assoc("children", cdr(ass)));;

if (globalTrace)
    printf("Leaving childrenof\n");

}


//Building function isNode from line: 493

bool isNode(list val) {
  
if (globalTrace)
    printf("isNode at q/compiler.qon:493 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:497");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:498");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:500");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(val)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:502");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxSymbol("node"), car(val))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:503");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return true;;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:504");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return false;;

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:505");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return false;;

    };

  };

if (globalTrace)
    printf("Leaving isNode\n");

}


//Building function isLeaf from line: 509

bool isLeaf(list n) {
  
if (globalTrace)
    printf("isLeaf at q/compiler.qon:509 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:510");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return equalBox(boxString("leaf"), subnameof(n));;

if (globalTrace)
    printf("Leaving isLeaf\n");

}


//Building function noStackTrace from line: 512

list noStackTrace() {
  
if (globalTrace)
    printf("noStackTrace at q/compiler.qon:512 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:514");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cons(boxString("boxType"), cons(boxString("stringify"), cons(boxString("isEmpty"), cons(boxString("unBoxString"), cons(boxString("isList"), cons(boxString("unBoxBool"), cons(boxString("unBoxSymbol"), cons(boxString("equalBox"), cons(boxString("assoc"), cons(boxString("inList"), cons(boxString("unBoxInt"), cons(boxString("listLength"), cons(boxString("stroff"), cons(boxString("troff"), cons(boxString("tron"), cons(boxString("stron"), cons(boxString("car"), cons(boxString("cdr"), cons(boxString("cons"), cons(boxString("stackTracePush"), cons(boxString("stackTracePop"), cons(boxString("assertType"), cons(boxString("boxString"), cons(boxString("boxSymbol"), cons(boxString("boxInt"), NULL)))))))))))))))))))))))));;

if (globalTrace)
    printf("Leaving noStackTrace\n");

}


//Building function treeCompile from line: 544

list treeCompile(char* filename) {
  char* programStr = "";
list tree = NULL;

if (globalTrace)
    printf("treeCompile at q/compiler.qon:544 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:546");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:547");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:548");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return tree;;

if (globalTrace)
    printf("Leaving treeCompile\n");

}


//Building function astBuild from line: 550

list astBuild(char* filename) {
  char* programStr = "";
list tree = NULL;
list program = NULL;

if (globalTrace)
    printf("astBuild at q/compiler.qon:550 (%s)\n", caller);

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

  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:563");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = mergeIncludes(program);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:564");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return program;;

if (globalTrace)
    printf("Leaving astBuild\n");

}


//Building function astCompile from line: 567

void astCompile(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    printf("astCompile at q/compiler.qon:567 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:569");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Final program: \n");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:572");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:573");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:574");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "write-file", "luaWriteFile");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:575");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "read-file", "luaReadFile");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:576");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "string-length", "string.len");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:578");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "sub-string", "luaSubstring");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:579");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "stringLength", "string.len");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:580");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:581");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:582");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  displayList(tree, 0, true);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown file (not provided by parser):Line missing");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fprintf(stderr, "Transformed tree");

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:587");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n");

if (globalTrace)
    printf("Leaving astCompile\n");

}


//Building function mergeIncludes from line: 591

list mergeIncludes(list program) {
  
if (globalTrace)
    printf("mergeIncludes at q/compiler.qon:591 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:593");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return merge_recur(childrenof(cdr(cdr(assocPanic("includes", program, "Program lacks include section")))), program);;

if (globalTrace)
    printf("Leaving mergeIncludes\n");

}


//Building function merge_recur from line: 598

list merge_recur(list incs, list program) {
  
if (globalTrace)
    printf("merge_recur at q/compiler.qon:598 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:600");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(incs), 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:602");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return mergeInclude(car(incs), merge_recur(cdr(incs), program));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:603");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return program;;

  };

if (globalTrace)
    printf("Leaving merge_recur\n");

}


//Building function mergeInclude from line: 606

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
    printf("mergeInclude at q/compiler.qon:606 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:621");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(inc)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:622");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return program;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:624");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    functions = childrenof(cdr(assocPanic("functions", inc, "Included file has no functions section")));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:625");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    oldfunctionsnode = cdr(assocPanic("functions", program, "Current module has no functions section"));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:626");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    oldfunctions = childrenof(oldfunctionsnode);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:627");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newfunctions = concatLists(functions, oldfunctions);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:628");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newFunctionNode = cons(boxSymbol("node"), alistCons(boxSymbol("children"), newfunctions, cdr(oldfunctionsnode)));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:636");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    types = childrenof(cdr(assocPanic("types", inc, "Included file has no types section")));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:637");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    oldtypesnode = cdr(assocPanic("types", program, "Current module has no types section"));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:638");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    oldtypes = childrenof(oldtypesnode);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:639");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newtypes = concatLists(types, oldtypes);

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:640");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newTypeNode = cons(boxSymbol("node"), alistCons(boxSymbol("children"), newtypes, cdr(oldtypesnode)));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:645");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newProgram = alistCons(boxString("functions"), newFunctionNode, alistCons(boxString("types"), newTypeNode, alistCons(boxString("includes"), cons(boxSymbol("includes"), NULL), newProgram)));

if (globalTrace)
    snprintf(caller, 1024, "from q/compiler.qon:657");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return newProgram;;

  };

if (globalTrace)
    printf("Leaving mergeInclude\n");

}


//Building function add from line: 19

int add(int a, int b) {
  
if (globalTrace)
    printf("add at q/base.qon:19 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:19");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return sub(a, sub(0, b));;

if (globalTrace)
    printf("Leaving add\n");

}


//Building function addf from line: 20

float addf(float a, float b) {
  
if (globalTrace)
    printf("addf at q/base.qon:20 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:20");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return subf(a, subf(0, b));;

if (globalTrace)
    printf("Leaving addf\n");

}


//Building function sub1 from line: 21

int sub1(int a) {
  
if (globalTrace)
    printf("sub1 at q/base.qon:21 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:21");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return sub(a, 1);;

if (globalTrace)
    printf("Leaving sub1\n");

}


//Building function add1 from line: 22

int add1(int a) {
  
if (globalTrace)
    printf("add1 at q/base.qon:22 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:22");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return add(a, 1);;

if (globalTrace)
    printf("Leaving add1\n");

}


//Building function clone from line: 24

box clone(box b) {
  box newb = NULL;

if (globalTrace)
    printf("clone at q/base.qon:24 (%s)\n", caller);

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

  return newb;;

if (globalTrace)
    printf("Leaving clone\n");

}


//Building function newVoid from line: 38

box newVoid() {
  box newb = NULL;

if (globalTrace)
    printf("newVoid at q/base.qon:38 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:42");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb = makeBox();

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:43");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->voi = true;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:44");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->typ = "void";

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:45");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return newb;;

if (globalTrace)
    printf("Leaving newVoid\n");

}


//Building function stackDump from line: 48

void stackDump() {
  
if (globalTrace)
    printf("stackDump at q/base.qon:48 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:49");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("");

if (globalTrace)
    printf("Leaving stackDump\n");

}


//Building function nop from line: 53

void nop() {
  
if (globalTrace)
    printf("nop at q/base.qon:53 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:54");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("");

if (globalTrace)
    printf("Leaving nop\n");

}


//Building function equalBox from line: 57

bool equalBox(box a, box b) {
  
if (globalTrace)
    printf("equalBox at q/base.qon:57 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:59");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:60");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:62");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("string", boxType(a))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:63");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return equalString(unBoxString(a), stringify(b));;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:65");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("bool", boxType(a))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:66");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return andBool(unBoxBool(a), unBoxBool(b));;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:68");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("symbol", boxType(a))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:70");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("symbol", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:71");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return equalString(unBoxSymbol(a), unBoxSymbol(b));;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:72");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return false;;

          };

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:74");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("int", boxType(a))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:75");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return equal(unBoxInt(a), unBoxInt(b));;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:76");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return false;;

          };

        };

      };

    };

  };

if (globalTrace)
    printf("Leaving equalBox\n");

}


//Building function display from line: 78

void display(list l) {
  
if (globalTrace)
    printf("display at q/base.qon:78 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:80");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:81");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("nil ");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:81");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:83");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:84");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("[");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:84");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      displayList(l, 0, true);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:84");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("]");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:85");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      displayList(l, 0, true);

    };

  };

if (globalTrace)
    printf("Leaving display\n");

}


//Building function openBrace from line: 87

char* openBrace() {
  
if (globalTrace)
    printf("openBrace at q/base.qon:87 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:87");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return "(";;

if (globalTrace)
    printf("Leaving openBrace\n");

}


//Building function closeBrace from line: 88

char* closeBrace() {
  
if (globalTrace)
    printf("closeBrace at q/base.qon:88 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:88");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return ")";;

if (globalTrace)
    printf("Leaving closeBrace\n");

}


//Building function boxType from line: 93

char* boxType(box b) {
  
if (globalTrace)
    printf("boxType at q/base.qon:93 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:95");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return b->typ;;

if (globalTrace)
    printf("Leaving boxType\n");

}


//Building function makeBox from line: 96

box makeBox() {
  box b = NULL;

if (globalTrace)
    printf("makeBox at q/base.qon:96 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:99");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = malloc(sizeof(Box));

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:100");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:101");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("failed to create box!");

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:103");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->tag = NULL;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:104");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->car = NULL;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:105");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->cdr = NULL;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:106");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->lis = NULL;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:107");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "None - error!";

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:108");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return b;;

if (globalTrace)
    printf("Leaving makeBox\n");

}


//Building function makePair from line: 111

pair makePair() {
  
if (globalTrace)
    printf("makePair at q/base.qon:111 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:113");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return makeBox();;

if (globalTrace)
    printf("Leaving makePair\n");

}


//Building function boxString from line: 117

box boxString(char* s) {
  box b = NULL;

if (globalTrace)
    printf("boxString at q/base.qon:117 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:121");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = makeBox();

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:122");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->str = s;

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:123");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->lengt = string_length(s);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:124");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "string";

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:125");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return b;;

if (globalTrace)
    printf("Leaving boxString\n");

}


//Building function boxSymbol from line: 127

box boxSymbol(char* s) {
  box b = NULL;

if (globalTrace)
    printf("boxSymbol at q/base.qon:127 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:131");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = boxString(s);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:132");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "symbol";

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:133");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return b;;

if (globalTrace)
    printf("Leaving boxSymbol\n");

}


//Building function boxBool from line: 136

box boxBool(bool boo) {
  box b = NULL;

if (globalTrace)
    printf("boxBool at q/base.qon:136 (%s)\n", caller);

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

  return b;;

if (globalTrace)
    printf("Leaving boxBool\n");

}


//Building function boxInt from line: 145

box boxInt(int val) {
  box b = NULL;

if (globalTrace)
    printf("boxInt at q/base.qon:145 (%s)\n", caller);

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

  return b;;

if (globalTrace)
    printf("Leaving boxInt\n");

}


//Building function assertType from line: 154

void assertType(char* atype, box abox, int line, char* file) {
  
if (globalTrace)
    printf("assertType at q/base.qon:154 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:156");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(abox)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:157");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(atype, "nil")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:157");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:157");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:159");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(atype, boxType(abox))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:160");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:162");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("Assertion failure at line %d, in file %s: provided value is not a '%s'!  It was actually '%s'. Contents:", line, file, atype, boxType(abox));

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:163");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(abox);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:164");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      panic("Invalid type!");

    };

  };

if (globalTrace)
    printf("Leaving assertType\n");

}


//Building function unBoxString from line: 166

char* unBoxString(box b) {
  
if (globalTrace)
    printf("unBoxString at q/base.qon:166 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:167");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assertType("string", b, 167, "q/base.qon");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:167");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return b->str;;

if (globalTrace)
    printf("Leaving unBoxString\n");

}


//Building function unBoxSymbol from line: 169

char* unBoxSymbol(box b) {
  
if (globalTrace)
    printf("unBoxSymbol at q/base.qon:169 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:169");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return b->str;;

if (globalTrace)
    printf("Leaving unBoxSymbol\n");

}


//Building function unBoxBool from line: 170

bool unBoxBool(box b) {
  
if (globalTrace)
    printf("unBoxBool at q/base.qon:170 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:170");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return b->boo;;

if (globalTrace)
    printf("Leaving unBoxBool\n");

}


//Building function unBoxInt from line: 171

int unBoxInt(box b) {
  
if (globalTrace)
    printf("unBoxInt at q/base.qon:171 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:171");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return b->i;;

if (globalTrace)
    printf("Leaving unBoxInt\n");

}


//Building function stringify_rec from line: 173

char* stringify_rec(box b) {
  
if (globalTrace)
    printf("stringify_rec at q/base.qon:173 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:175");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:176");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return "";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:178");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return stringConcatenate(stringify(car(b)), stringConcatenate(" ", stringify_rec(cdr(b))));;

  };

if (globalTrace)
    printf("Leaving stringify_rec\n");

}


//Building function stringify from line: 185

char* stringify(box b) {
  
if (globalTrace)
    printf("stringify at q/base.qon:185 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:187");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:188");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return "()";;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:190");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("string", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:191");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return unBoxString(b);;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:193");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("bool", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:195");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( unBoxBool(b)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:195");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return "true";;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:195");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return "false";;

        };

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:197");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("int", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:198");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return intToString(unBoxInt(b));;

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:200");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("symbol", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:201");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return unBoxSymbol(b);;

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:203");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalString("list", boxType(b))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:205");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              return stringConcatenate("(", stringConcatenate(stringify(car(b)), stringConcatenate(" ", stringConcatenate(stringify_rec(cdr(b)), ")"))));;

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:211");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              return stringConcatenate("Unsupported type: ", boxType(b));;

            };

          };

        };

      };

    };

  };

if (globalTrace)
    printf("Leaving stringify\n");

}


//Building function hasTag from line: 216

bool hasTag(box aBox, box key) {
  
if (globalTrace)
    printf("hasTag at q/base.qon:216 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:218");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(aBox)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:219");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:220");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return isNotFalse(assoc(stringify(key), aBox->tag));;

  };

if (globalTrace)
    printf("Leaving hasTag\n");

}


//Building function getTag from line: 222

box getTag(box aBox, box key) {
  
if (globalTrace)
    printf("getTag at q/base.qon:222 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:224");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( false) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:226");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Getting %s from: ", stringify(key));

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:227");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(alistKeys(aBox->tag));

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:228");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:230");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("");

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:232");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return cdr(assoc(stringify(key), aBox->tag));;

if (globalTrace)
    printf("Leaving getTag\n");

}


//Building function getTagFail from line: 234

box getTagFail(box aBox, box key, box onFail) {
  
if (globalTrace)
    printf("getTagFail at q/base.qon:234 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:236");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( hasTag(aBox, key)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:237");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return getTag(aBox, key);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:238");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return onFail;;

  };

if (globalTrace)
    printf("Leaving getTagFail\n");

}


//Building function assocExists from line: 240

bool assocExists(char* key, box aBox) {
  
if (globalTrace)
    printf("assocExists at q/base.qon:240 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:243");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(aBox)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:244");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return false;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:245");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return isNotFalse(assoc(key, aBox));;

  };

if (globalTrace)
    printf("Leaving assocExists\n");

}


//Building function assocFail from line: 248

box assocFail(char* key, box aBox, box onFail) {
  
if (globalTrace)
    printf("assocFail at q/base.qon:248 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:250");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( assocExists(key, aBox)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:251");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return assoc(key, aBox);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:252");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return cons(boxString(key), onFail);;

  };

if (globalTrace)
    printf("Leaving assocFail\n");

}


//Building function assocPanic from line: 254

box assocPanic(char* key, box aBox, char* onFail) {
  
if (globalTrace)
    printf("assocPanic at q/base.qon:254 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:256");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( assocExists(key, aBox)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:257");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return assoc(key, aBox);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:258");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic(onFail);

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:259");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  panic("Inconceivable");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:261");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return NULL;;

if (globalTrace)
    printf("Leaving assocPanic\n");

}


//Building function setTag from line: 265

box setTag(box key, list val, box aStruct) {
  
if (globalTrace)
    printf("setTag at q/base.qon:265 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:267");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  aStruct->tag = alistCons(key, val, aStruct->tag);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:268");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return aStruct;;

if (globalTrace)
    printf("Leaving setTag\n");

}


//Building function locPanic from line: 282

void locPanic(char* file, char* line, char* message) {
  
if (globalTrace)
    printf("locPanic at q/base.qon:282 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:284");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s %s:%s\n", file, line, message);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:285");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  panic(message);

if (globalTrace)
    printf("Leaving locPanic\n");

}


//Building function truthy from line: 308

bool truthy(box aVal) {
  
if (globalTrace)
    printf("truthy at q/base.qon:308 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:310");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return isNotFalse(aVal);;

if (globalTrace)
    printf("Leaving truthy\n");

}


//Building function isNotFalse from line: 312

bool isNotFalse(box aVal) {
  
if (globalTrace)
    printf("isNotFalse at q/base.qon:312 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:314");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(boxType(aVal), "bool")) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:315");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( unBoxBool(aVal)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:315");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return true;;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:315");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return false;;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:316");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return true;;

  };

if (globalTrace)
    printf("Leaving isNotFalse\n");

}


//Building function toStr from line: 320

box toStr(box thing) {
  
if (globalTrace)
    printf("toStr at q/base.qon:320 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:321");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return boxString(stringify(thing));;

if (globalTrace)
    printf("Leaving toStr\n");

}


//Building function listLast from line: 323

box listLast(list alist) {
  
if (globalTrace)
    printf("listLast at q/base.qon:323 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:325");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(cdr(alist))) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:326");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return car(alist);;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:327");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return listLast(cdr(alist));;

  };

if (globalTrace)
    printf("Leaving listLast\n");

}


//Building function newLine from line: 331

void newLine(int indent) {
  
if (globalTrace)
    printf("newLine at q/base.qon:331 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:332");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:332");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printIndent(indent);

if (globalTrace)
    printf("Leaving newLine\n");

}


//Building function printIndent from line: 337

void printIndent(int ii) {
  
if (globalTrace)
    printf("printIndent at q/base.qon:337 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:341");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(ii, 0)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:342");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  ");

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:342");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(sub1(ii));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:343");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;;

  };

if (globalTrace)
    printf("Leaving printIndent\n");

}


//Building function argList from line: 353

list argList(int count, int pos, char** args) {
  
if (globalTrace)
    printf("argList at q/base.qon:353 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:356");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(count, pos)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:358");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return cons(boxString(getStringArray(pos, args)), argList(count, add1(pos), args));;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:361");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return NULL;;

  };

if (globalTrace)
    printf("Leaving argList\n");

}


//Building function tron from line: 363

void tron() {
  
if (globalTrace)
    printf("tron at q/base.qon:363 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:363");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalTrace = true;

if (globalTrace)
    printf("Leaving tron\n");

}


//Building function troff from line: 364

void troff() {
  
if (globalTrace)
    printf("troff at q/base.qon:364 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:364");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalTrace = false;

if (globalTrace)
    printf("Leaving troff\n");

}


//Building function stron from line: 365

void stron() {
  
if (globalTrace)
    printf("stron at q/base.qon:365 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:365");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalStepTrace = true;

if (globalTrace)
    printf("Leaving stron\n");

}


//Building function stroff from line: 366

void stroff() {
  
if (globalTrace)
    printf("stroff at q/base.qon:366 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/base.qon:366");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalStepTrace = false;

if (globalTrace)
    printf("Leaving stroff\n");

}


//Building function ansi3IsNil from line: 12

bool ansi3IsNil(void* a) {
  
if (globalTrace)
    printf("ansi3IsNil at q/shims/ansi3.qon:12 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:14");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( (a == NULL)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:15");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return true;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:16");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return false;;

  };

if (globalTrace)
    printf("Leaving ansi3IsNil\n");

}


//Building function pointerAdd from line: 18

void* pointerAdd(void* a, int b) {
  
if (globalTrace)
    printf("pointerAdd at q/shims/ansi3.qon:18 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:20");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return (a + b);;

if (globalTrace)
    printf("Leaving pointerAdd\n");

}


//Building function getEnv from line: 22

char* getEnv(char* key) {
  
if (globalTrace)
    printf("getEnv at q/shims/ansi3.qon:22 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:24");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return getenv(key);;

if (globalTrace)
    printf("Leaving getEnv\n");

}


//Building function panic from line: 26

void panic(char* s) {
  
if (globalTrace)
    printf("panic at q/shims/ansi3.qon:26 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  abort();

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:29");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  exit(1);

if (globalTrace)
    printf("Leaving panic\n");

}


//Building function sub from line: 31

int sub(int a, int b) {
  
if (globalTrace)
    printf("sub at q/shims/ansi3.qon:31 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:33");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return (a - b);;

if (globalTrace)
    printf("Leaving sub\n");

}


//Building function mult from line: 35

float mult(int a, int b) {
  
if (globalTrace)
    printf("mult at q/shims/ansi3.qon:35 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:37");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return (a * b);;

if (globalTrace)
    printf("Leaving mult\n");

}


//Building function greaterthan from line: 39

int greaterthan(int a, int b) {
  
if (globalTrace)
    printf("greaterthan at q/shims/ansi3.qon:39 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:41");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return (a > b);;

if (globalTrace)
    printf("Leaving greaterthan\n");

}


//Building function subf from line: 43

float subf(float a, float b) {
  
if (globalTrace)
    printf("subf at q/shims/ansi3.qon:43 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:45");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return (a - b);;

if (globalTrace)
    printf("Leaving subf\n");

}


//Building function multf from line: 47

float multf(float a, float b) {
  
if (globalTrace)
    printf("multf at q/shims/ansi3.qon:47 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:49");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return (a * b);;

if (globalTrace)
    printf("Leaving multf\n");

}


//Building function greaterthanf from line: 51

int greaterthanf(float a, float b) {
  
if (globalTrace)
    printf("greaterthanf at q/shims/ansi3.qon:51 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:53");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return (a > b);;

if (globalTrace)
    printf("Leaving greaterthanf\n");

}


//Building function equal from line: 55

int equal(int a, int b) {
  
if (globalTrace)
    printf("equal at q/shims/ansi3.qon:55 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:57");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return (a == b);;

if (globalTrace)
    printf("Leaving equal\n");

}


//Building function equalString from line: 59

int equalString(char* a, char* b) {
  
if (globalTrace)
    printf("equalString at q/shims/ansi3.qon:59 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:61");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return (0 == strcmp(a, b));;

if (globalTrace)
    printf("Leaving equalString\n");

}


//Building function string_length from line: 63

int string_length(char* s) {
  
if (globalTrace)
    printf("string_length at q/shims/ansi3.qon:63 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:65");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return strlen(s);;

if (globalTrace)
    printf("Leaving string_length\n");

}


//Building function setSubString from line: 67

char* setSubString(char* target, int start, char* source) {
  
if (globalTrace)
    printf("setSubString at q/shims/ansi3.qon:67 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:69");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  target[start]=source[0];

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:70");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return target;;

if (globalTrace)
    printf("Leaving setSubString\n");

}


//Building function sub_string from line: 73

char* sub_string(char* s, int start, int length) {
  char* substr = "";

if (globalTrace)
    printf("sub_string at q/shims/ansi3.qon:73 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:75");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  substr = calloc(add(length, 1), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:76");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  strncpy(substr, (s + start), length);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:77");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return substr;;

if (globalTrace)
    printf("Leaving sub_string\n");

}


//Building function stringConcatenate from line: 80

char* stringConcatenate(char* a, char* b) {
  int len = 0;
char* target = NULL;

if (globalTrace)
    printf("stringConcatenate at q/shims/ansi3.qon:80 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:82");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  len = add(add(strlen(a), strlen(b)), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:83");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  target = calloc(len, 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:84");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  strncat(target, a, len);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:85");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  strncat(target, b, len);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:86");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return target;;

if (globalTrace)
    printf("Leaving stringConcatenate\n");

}


//Building function intToString from line: 89

char* intToString(int a) {
  int len = 0;
char* target = NULL;

if (globalTrace)
    printf("intToString at q/shims/ansi3.qon:89 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:91");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  len = 100;

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:92");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  target = calloc(len, 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:93");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  snprintf(target, 99, "%d", a);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:94");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return target;;

if (globalTrace)
    printf("Leaving intToString\n");

}


//Building function gc_malloc from line: 97

void* gc_malloc(uint size) {
  
if (globalTrace)
    printf("gc_malloc at q/shims/ansi3.qon:97 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:99");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return malloc(size);;

if (globalTrace)
    printf("Leaving gc_malloc\n");

}


//Building function makeArray from line: 102

int* makeArray(int length) {
  int* array = NULL;

if (globalTrace)
    printf("makeArray at q/shims/ansi3.qon:102 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:104");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  array = gc_malloc(mult(length, sizeof(int)));

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:105");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return array;;

if (globalTrace)
    printf("Leaving makeArray\n");

}


//Building function at from line: 108

int at(int* arr, int index) {
  
if (globalTrace)
    printf("at at q/shims/ansi3.qon:108 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:110");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return arr[index];;

if (globalTrace)
    printf("Leaving at\n");

}


//Building function setAt from line: 113

void setAt(int* array, int index, int value) {
  
if (globalTrace)
    printf("setAt at q/shims/ansi3.qon:113 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:115");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  array[index] = value;

if (globalTrace)
    printf("Leaving setAt\n");

}


//Building function setCharAt from line: 118

void setCharAt(char* array, int index, int value) {
  
if (globalTrace)
    printf("setCharAt at q/shims/ansi3.qon:118 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:120");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  array[index] = value;

if (globalTrace)
    printf("Leaving setCharAt\n");

}


//Building function read_file from line: 123

char* read_file(char* filename) {
  char* buffer = NULL;
long length = 0;
FILE* f = NULL;

if (globalTrace)
    printf("read_file at q/shims/ansi3.qon:123 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:125");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  f = fopen(filename, "rb");

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:126");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( ansi3IsNil(f)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:127");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return NULL;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:129");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fseek(f, 0, SEEK_END);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:130");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    length = ftell(f);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:131");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fseek(f, 0, SEEK_SET);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:132");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    buffer = calloc(add(1, length), 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:134");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( ansi3IsNil(buffer)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:135");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      panic("Malloc failed!\n");

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:136");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      fread(buffer, 1, length, f);

    };

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:137");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fclose(f);

  };

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:140");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return buffer;;

if (globalTrace)
    printf("Leaving read_file\n");

}


//Building function write_file from line: 143

void write_file(char* filename, char* data) {
  char* buffer = NULL;
long length = 0;
FILE* f = NULL;

if (globalTrace)
    printf("write_file at q/shims/ansi3.qon:143 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:145");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  f = fopen(filename, "w");

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:146");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( ansi3IsNil(f)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:147");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Error opening file!");

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:149");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fprintf(f, "%s", data);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:150");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    fclose(f);

  };

if (globalTrace)
    printf("Leaving write_file\n");

}


//Building function getStringArray from line: 154

char* getStringArray(int index, char** strs) {
  
if (globalTrace)
    printf("getStringArray at q/shims/ansi3.qon:154 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:156");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return strs[index];;

if (globalTrace)
    printf("Leaving getStringArray\n");

}


//Building function programArgs from line: 158

char** programArgs() {
  
if (globalTrace)
    printf("programArgs at q/shims/ansi3.qon:158 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:160");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return globalArgs;;

if (globalTrace)
    printf("Leaving programArgs\n");

}


//Building function programArgsCount from line: 163

int programArgsCount() {
  
if (globalTrace)
    printf("programArgsCount at q/shims/ansi3.qon:163 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:165");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return globalArgsCount;;

if (globalTrace)
    printf("Leaving programArgsCount\n");

}


//Building function main from line: 169

int main(int argc, char** argv) {
  
if (globalTrace)
    printf("main at q/shims/ansi3.qon:169 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:171");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  caller = calloc(1024, 1);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:172");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalArgs = argv;

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:173");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalArgsCount = argc;

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:174");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return start(argc, argv);;

if (globalTrace)
    printf("Leaving main\n");

}


//Building function character from line: 177

char* character(int num) {
  char* buffer = NULL;
char* str = NULL;

if (globalTrace)
    printf("character at q/shims/ansi3.qon:177 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:179");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  str = malloc(2);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:180");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( ansi3IsNil(str)) {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:181");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return 0;;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:183");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    setCharAt(str, 0, num);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:184");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    setCharAt(str, 1, 0);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:185");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return str;;

  };

if (globalTrace)
    printf("Leaving character\n");

}


//Building function displays from line: 192

void displays(char* s) {
  
if (globalTrace)
    printf("displays at q/shims/ansi3.qon:192 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from q/shims/ansi3.qon:194");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", s);

if (globalTrace)
    printf("Leaving displays\n");

}


//Building function start from line: 4

int start() {
  bool runTests = false;
list cmdLine = NULL;
box filename = NULL;
bool runPerl = false;
bool runJava = false;
bool runAst = false;
bool runNode = false;
bool runLua = false;
bool runIma = false;
bool runAnsi2 = false;
bool runAnsi3 = false;
bool runBash = false;
bool runTree = false;

if (globalTrace)
    printf("start at compiler.qon:4 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:20");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  cmdLine = listReverse(argList(globalArgsCount, 0, globalArgs));

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:22");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(cmdLine), 1)) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:23");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    filename = second(cmdLine);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:24");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    filename = boxString("compiler.qon");

  };

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

  runAst = inList(boxString("--ast"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:31");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runTree = inList(boxString("--tree"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:32");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runNode = inList(boxString("--node"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:33");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runLua = inList(boxString("--lua"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:34");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runIma = inList(boxString("--ima"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:35");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runAnsi2 = inList(boxString("--ansi2"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:36");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runAnsi3 = inList(boxString("--ansi3"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:37");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runBash = inList(boxString("--bash"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:38");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalTrace = inList(boxString("--trace"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:39");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalStepTrace = inList(boxString("--steptrace"), cmdLine);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:40");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( runTests) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:42");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test0();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:43");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test1();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:44");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test2();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:45");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test3();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:46");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test4();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:47");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test5();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:48");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test6();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:49");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test7();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:50");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test8();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:51");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test9();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:52");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test10();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:53");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test12();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:54");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test13();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:55");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test15();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:56");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test16();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:57");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test17();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:58");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test18();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:59");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test19();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:60");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test20();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:61");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test21();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:62");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test22();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:63");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test23();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:65");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n\nAfter all that hard work, I need a beer...\n");

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:66");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    beers(9);

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:68");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( runTree) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:69");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(macrowalk(treeCompile(unBoxString(filename))));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:71");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( runAst) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:72");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        astCompile(unBoxString(filename));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:73");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( runNode) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:75");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          nodeCompile(unBoxString(filename));

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:75");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("\n");

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:77");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( runPerl) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:78");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            perlCompile(unBoxString(filename));

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:78");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("\n");

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:80");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( runJava) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:81");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              javaCompile(unBoxString(filename));

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:81");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("\n");

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:83");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              if ( runLua) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:84");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                luaCompile(unBoxString(filename));

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:84");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                printf("\n");

              } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:86");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                if ( runIma) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:87");
                  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                  imaCompile(unBoxString(filename));

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:87");
                  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                  printf("\n");

                } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:89");
                  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                  if ( runAnsi2) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:90");
                    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                    ansi2Compile(unBoxString(filename));

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:90");
                    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                    printf("\n");

                  } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:92");
                    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                    if ( runAnsi3) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:93");
                      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                      ansi3Compile(unBoxString(filename));

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:93");
                      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                      printf("\n");

                    } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:95");
                      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                      if ( runBash) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:96");
                        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                        bashCompile(unBoxString(filename));

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:96");
                        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                        printf("\n");

                      } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:98");
                        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                        ansi3Compile(unBoxString(filename));

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:98");
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

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:100");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return 0;;

if (globalTrace)
    printf("Leaving start\n");

}


