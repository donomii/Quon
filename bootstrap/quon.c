//Scanning file...compiler.qon
//Building sexpr
//Building AST
//Merging ASTs
//Printing program

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char* getEnv(char* key){return getenv(key);}
 void panic(char* s){abort();exit(1);}
int sub(int a, int b) { return a - b; }
float mult(int a, int b) { return a * b; }
int greaterthan(int a, int b) { return a > b; }
float subf(float a, float b) { return a - b; }
float multf(float a, float b) { return a * b; }
int greaterthanf(float a, float b) { return a > b; }
int equal(int a, int b) { return a == b; }
int equalString(char* a, char* b) { return !strcmp(a,b); }
int andBool(int a, int b) { return a == b;}
int string_length(char* s) { return strlen(s);}
char* setSubString(char* target, int start,char *source){target[start]=source[0]; return target;}
char* sub_string(char* s, int start, int length) {
char* substr = calloc(length+1, 1);
strncpy(substr, s+start, length);
return substr;
}



char* stringConcatenate(char* a, char* b) {
int len = strlen(a) + strlen(b) + 1;
char* target = calloc(len,1);
strncat(target, a, len);
strncat(target, b, len);
return target;
}

char* intToString(int a) {
int len = 100;
char* target = calloc(len,1);
snprintf(target, 99, "%d", a);
return target;
}

typedef int*  array;
typedef int bool;
#define true 1
#define false 0


void * gc_malloc( unsigned int size ) {
return malloc(size);
}

int* makeArray(int length) {
    int * array = gc_malloc(length*sizeof(int));
    return array;
}

int at(int* arr, int index) {
  return arr[index];
}

void setAt(int* array, int index, int value) {
    array[index] = value;
}

char * read_file(char * filename) {
char * buffer = 0;
long length;
FILE * f = fopen (filename, "rb");

if (f)
{
  fseek (f, 0, SEEK_END);
  length = ftell (f);
  fseek (f, 0, SEEK_SET);
  buffer = calloc (length+1,1);
  if (buffer == NULL) {
  printf("Malloc failed!\n");
  exit(1);
}
  if (buffer)
  {
    fread (buffer, 1, length, f);
  }
  fclose (f);
}
return buffer;
}


void write_file (char * filename, char * data) {
FILE *f = fopen(filename, "w");
if (f == NULL)
{
    printf("Error opening file!");
    exit(1);
}

fprintf(f, "%s", data);

fclose(f);
}

char* getStringArray(int index, char** strs) {
return strs[index];
}

int start();  //Forwards declare the user's main routine
char* caller;
char** globalArgs;
int globalArgsCount;
bool globalTrace = false;
bool globalStepTrace = false;

int main( int argc, char *argv[] )  {
  globalArgs = argv;
  globalArgsCount = argc;
  caller=calloc(1024,1);

  return start();

}

char * character(int num) { char *string = malloc(2); if (!string) return 0; string[0] = num; string[1] = 0; return string; }void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }
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
Box* globalStackTrace = NULL;

bool isNil(list p) {
    return p == NULL;
}


//Forward declarations

int add(int a,int b);
float addf(float a,float b);
int sub1(int a);
int add1(int a);
box clone(box b);
box newVoid();
void stackDump();
void nop();
bool equalBox(box a,box b);
void display(list l);
char* boxType(box b);
box makeBox();
pair makePair();
box boxString(char* s);
box boxSymbol(char* s);
box boxBool(bool boo);
box boxInt(int val);
void assertType(char* atype,box abox,int line,char* file);
char* unBoxString(box b);
char* unBoxSymbol(box b);
bool unBoxBool(box b);
int unBoxInt(box b);
char* stringify_rec(box b);
char* stringify(box b);
bool hasTag(box aBox,box key);
box getTag(box aBox,box key);
box getTagFail(box aBox,box key,box onFail);
bool assocExists(char* key,box aBox);
box assocFail(char* key,box aBox,box onFail);
box assocPanic(char* key,box aBox,char* onFail);
box setTag(box key,list val,box aStruct);
list filterVoid(list l);
list filterTokens(list l);
box finish_token(char* prog,int start,int len,int line,int column,char* filename);
char* readString(char* prog,int start,int len);
char* readComment(char* prog,int start,int len);
bool isWhiteSpace(char* s);
bool isLineBreak(char* s);
int incForNewLine(box token,int val);
box annotateReadPosition(char* filename,int linecount,int column,int start,box newBox);
list scan(char* prog,int start,int len,int linecount,int column,char* filename);
bool isOpenBrace(box b);
char* openBrace();
bool isCloseBrace(box b);
char* closeBrace();
list skipList(list l);
list makeNode(char* name,char* subname,list code,list children);
list addToNode(box key,box val,list node);
list makeStatementNode(char* name,char* subname,list code,list children,box functionName);
list astExpression(list tree);
list astSubExpression(list tree);
list astIf(list tree,box fname);
list astSetStruct(list tree);
list astSet(list tree);
list astGetStruct(list tree);
list astReturnVoid(box fname);
list astStatement(list tree,box fname);
list astBody(list tree,box fname);
void locPanic(char* file,char* line,char* message);
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
bool truthy(box aVal);
bool isNotFalse(box aVal);
bool isLeaf(list n);
void printIndent(int ii);
void newLine(int indent);
list noStackTrace();
box toStr(box thing);
box listLast(list alist);
list treeCompile(char* filename);
list astBuild(char* filename);
void astCompile(char* filename);
list mergeIncludes(list program);
list merge_recur(list incs,list program);
list mergeInclude(list inc,list program);
list argList(int count,int pos,char** args);
void tron();
void troff();
void stron();
void stroff();
list macrowalk(list l);
list macrosingle(list l,char* search,char* replace);
list macrolist(list l,char* search,list replace);
box car(list l);
list cdr(list l);
list cons(box data,list l);
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
list alistCons(box key,box value,list alist);
list assoc(char* searchTerm,list l);
char* chooseBox(char* aType);
box mlistLiteral(box b);
list doMultiList(list l);
list doStringList(list l);
list doSymbolList(list l);
list doBoxList(list l);
list concatLists(list seq1,list seq2);
list alistKeys(list alist);
void displayList(list l,int indent,bool first);
list listReverse(list l);
bool inList(box item,list l);
bool equalList(list a,list b);
list reverseRec(list oldL,list newL);
list reverseList(list l);
list readSexpr(char* aStr,char* filename);
list sexprTree(list l);
list loadQuon(char* filename);
list getIncludes(list program);
list getTypes(list program);
list getFunctions(list program);
list loadIncludes(list tree);
list buildProg(list includes,list types,list functions);
list numbers(int num);
char* lexType(box abox);
void perlLeaf(list thisNode,int indent);
void perlStructGetterExpression(list thisNode,int indent);
void perlExpression(list node,int indent);
void perlRecurList(list expr,int indent);
void perlSubExpression(list tree,int indent);
void perlIf(list node,int indent);
void perlSetStruct(list node,int indent);
void perlGetStruct(list node,int indent);
void perlSet(list node,int indent);
void assertNode(list node);
void perlStatement(list node,int indent);
void perlBody(list tree,int indent);
void perlDeclarations(list decls,int indent);
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
void ansiFunctionArgs(list tree);
void ansiLeaf(list thisNode,int indent);
void ansiStructGetterExpression(list thisNode,int indent);
void ansiExpression(list node,int indent);
void ansiRecurList(list expr,int indent);
void ansiSubExpression(list tree,int indent);
void ansiIf(list node,int indent);
void ansiSetStruct(list node,int indent);
void ansiGetStruct(list node,int indent);
void ansiSet(list node,int indent);
void ansiStatement(list node,int indent);
void ansiBody(list tree,int indent);
void ansiDeclarations(list decls,int indent);
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
void ansi2displays(char* s);
void ansi2FunctionArgs(list tree);
void ansi2Expression(list tree,int indent);
void ansi2RecurList(list expr,int indent);
void ansi2If(list node,int indent);
void ansi2SetStruct(list node,int indent);
void ansi2GetStruct(list node,int indent);
void ansi2Set(list node,int indent);
void ansi2Return(list node,int indent);
void ansi2Statement(list node,int indent);
void ansi2Body(list tree,int indent);
void ansi2Declarations(list decls,int indent);
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
void ansi3displays(char* s);
void ansi3FunctionArgs(list tree);
void ansi3Expression(list tree,int indent);
void ansi3RecurList(list expr,int indent);
void ansi3If(list node,int indent);
void ansi3SetStruct(list node,int indent);
void ansi3GetStruct(list node,int indent);
void ansi3Set(list node,int indent);
void ansi3Return(list node,int indent);
void ansi3Statement(list node,int indent);
void ansi3Body(list tree,int indent);
void ansi3Declarations(list decls,int indent);
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
void test0();
void test1();
void test2_do(char* message);
void test2();
void test3_do(int b,char* c);
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
list concatenateLists(list oldL,list newL);
void test20();
void test21();
void test22();
void test23();
void nodeFunctionArgs(list tree);
void nodeLeaf(list thisNode,int indent);
void nodeStructGetterExpression(list thisNode,int indent);
void nodeExpression(list node,int indent);
void nodeRecurList(list expr,int indent);
void nodeSubExpression(list tree,int indent);
void nodeIf(list node,int indent);
void nodeGetStruct(list node,int indent);
void nodeSet(list node,int indent);
void nodeSetStruct(list node,int indent);
void nodeStatement(list node,int indent);
void nodeBody(list tree,int indent);
void nodeDeclarations(list decls,int indent);
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
void javaFunctionArgs(list tree);
void javaLeaf(list thisNode,int indent);
void javaStructGetterExpression(list thisNode,int indent);
void javaExpression(list node,int indent);
void javaRecurList(list expr,int indent);
void javaSubExpression(list tree,int indent);
void javaIf(list node,int indent);
void javaSetStruct(list node,int indent);
void javaGetStruct(list node,int indent);
void javaSet(list node,int indent);
void javaStatement(list node,int indent);
void javaBody(list tree,int indent);
void javaDeclarations(list decls,int indent);
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
void luaFunctionArgs(int indent,list tree);
void luaFunction(int indent,list functionDefinition);
void luaDeclarations(int indent,list declarations);
void luaExpressionStart(int indent,list program);
void luaExpression(int indent,list program);
void luaStatement(int indent,list statement);
void luaBody(char* local_caller,int indent,list program);
void luaFunctions(int indent,list program);
void luaProgram(list program);
void luaIncludes(list nodes);
void luaCompile(char* filename);
void imaFunctionArgs(int indent,list tree);
void imaFunction(int indent,list functionDefinition);
void imaDeclarations(int indent,list declarations);
void imaExpressionStart(int indent,list program);
void imaExpression(int indent,list program);
void imaStatement(int indent,list statement);
void imaBody(char* local_caller,int indent,list program);
void imaFunctions(int indent,list program);
void imaTypeDecl(list l);
void imaStructComponents(list node);
void imaStruct(list node);
box imaTypeMap(box aSym);
void imaType(list node);
void imaTypes(int indent,list nodes);
void imaProgram(list program);
void imaIncludes(int indent,list nodes);
void imaCompile(char* filename);
int start();

//End forward declarations



//Building function add from line: 19

int add(int a,int b) {
  
if (globalTrace)
    fprintf(stderr, "add at q/base.qon:19 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:19");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(sub(a, sub(0, b)));

if (globalTrace)
    fprintf(stderr, "Leaving add\n");

}


//Building function addf from line: 20

float addf(float a,float b) {
  
if (globalTrace)
    fprintf(stderr, "addf at q/base.qon:20 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:20");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(subf(a, subf(0, b)));

if (globalTrace)
    fprintf(stderr, "Leaving addf\n");

}


//Building function sub1 from line: 21

int sub1(int a) {
  
if (globalTrace)
    fprintf(stderr, "sub1 at q/base.qon:21 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:21");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(sub(a, 1));

if (globalTrace)
    fprintf(stderr, "Leaving sub1\n");

}


//Building function add1 from line: 22

int add1(int a) {
  
if (globalTrace)
    fprintf(stderr, "add1 at q/base.qon:22 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:22");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(add(a, 1));

if (globalTrace)
    fprintf(stderr, "Leaving add1\n");

}


//Building function clone from line: 24

box clone(box b) {
  box newb = NULL;

if (globalTrace)
    fprintf(stderr, "clone at q/base.qon:24 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb = makeBox();

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:29");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->typ = b->typ;

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:30");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->tag = b->tag;

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:31");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->lis = b->lis;

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:32");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->str = b->str;

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:33");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->i = b->i;

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:34");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->lengt = b->lengt;

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:35");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(newb);

if (globalTrace)
    fprintf(stderr, "Leaving clone\n");

}


//Building function newVoid from line: 38

box newVoid() {
  box newb = NULL;

if (globalTrace)
    fprintf(stderr, "newVoid at q/base.qon:38 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:42");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb = makeBox();

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:43");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->voi = true;

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:44");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->typ = "void";

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:45");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(newb);

if (globalTrace)
    fprintf(stderr, "Leaving newVoid\n");

}


//Building function stackDump from line: 48

void stackDump() {
  
if (globalTrace)
    fprintf(stderr, "stackDump at q/base.qon:48 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:49");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("");

if (globalTrace)
    fprintf(stderr, "Leaving stackDump\n");

}


//Building function nop from line: 54

void nop() {
  
if (globalTrace)
    fprintf(stderr, "nop at q/base.qon:54 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:55");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("");

if (globalTrace)
    fprintf(stderr, "Leaving nop\n");

}


//Building function equalBox from line: 57

bool equalBox(box a,box b) {
  
  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(b)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:60");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(false);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("string", boxType(a))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:63");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(equalString(unBoxString(a), stringify(b)));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("bool", boxType(a))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:66");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(andBool(unBoxBool(a), unBoxBool(b)));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("symbol", boxType(a))) {
          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("symbol", boxType(b))) {
            if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:71");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return(equalString(unBoxSymbol(a), unBoxSymbol(b)));

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:72");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return(false);

          };

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("int", boxType(a))) {
            if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:75");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return(equal(unBoxInt(a), unBoxInt(b)));

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:76");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return(false);

          };

        };

      };

    };

  };

}


//Building function display from line: 78

void display(list l) {
  
if (globalTrace)
    fprintf(stderr, "display at q/base.qon:78 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:81");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("nil ");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:84");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("[");

      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:84");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      displayList(l, 0, true);

      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:84");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("]");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:85");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      displayList(l, 0, true);

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving display\n");

}


//Building function boxType from line: 93

char* boxType(box b) {
  
  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:95");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(b->typ);

}


//Building function makeBox from line: 96

box makeBox() {
  box b = NULL;

if (globalTrace)
    fprintf(stderr, "makeBox at q/base.qon:96 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:99");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = malloc(sizeof(Box));

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:101");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("failed to create box!");

  } else {
  };

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:103");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->tag = NULL;

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:104");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->car = NULL;

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:105");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->cdr = NULL;

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:106");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->lis = NULL;

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:107");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "None - error!";

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:108");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(b);

if (globalTrace)
    fprintf(stderr, "Leaving makeBox\n");

}


//Building function makePair from line: 111

pair makePair() {
  
if (globalTrace)
    fprintf(stderr, "makePair at q/base.qon:111 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:113");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(makeBox());

if (globalTrace)
    fprintf(stderr, "Leaving makePair\n");

}


//Building function boxString from line: 117

box boxString(char* s) {
  box b = NULL;

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:121");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = makeBox();

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:122");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->str = s;

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:123");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->lengt = string_length(s);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:124");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "string";

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:125");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(b);

}


//Building function boxSymbol from line: 127

box boxSymbol(char* s) {
  box b = NULL;

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:131");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = boxString(s);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:132");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "symbol";

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:133");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(b);

}


//Building function boxBool from line: 136

box boxBool(bool boo) {
  box b = NULL;

if (globalTrace)
    fprintf(stderr, "boxBool at q/base.qon:136 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:140");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = makeBox();

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:141");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->boo = boo;

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:142");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "bool";

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:143");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(b);

if (globalTrace)
    fprintf(stderr, "Leaving boxBool\n");

}


//Building function boxInt from line: 145

box boxInt(int val) {
  box b = NULL;

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:149");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = makeBox();

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:150");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->i = val;

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:151");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "int";

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:152");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(b);

}


//Building function assertType from line: 154

void assertType(char* atype,box abox,int line,char* file) {
  
  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(abox)) {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(atype, "nil")) {      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return;

    } else {      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return;

    };

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(atype, boxType(abox))) {      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return;

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:162");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("Assertion failure at line %d, in file %s: provided value is not a '%s'!  It was actually (%s):", line, file, atype, abox->typ);

      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:163");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(abox);

      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:164");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      panic("Invalid type!");

    };

  };

}


//Building function unBoxString from line: 166

char* unBoxString(box b) {
  
  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:167");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assertType("string", b, 167, "q/base.qon");

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:167");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(b->str);

}


//Building function unBoxSymbol from line: 169

char* unBoxSymbol(box b) {
  
  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:169");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(b->str);

}


//Building function unBoxBool from line: 170

bool unBoxBool(box b) {
  
  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:170");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(b->boo);

}


//Building function unBoxInt from line: 171

int unBoxInt(box b) {
  
  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:171");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(b->i);

}


//Building function stringify_rec from line: 173

char* stringify_rec(box b) {
  
if (globalTrace)
    fprintf(stderr, "stringify_rec at q/base.qon:173 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:176");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return("");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:178");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(stringConcatenate(stringify(car(b)), stringConcatenate(" ", stringify_rec(cdr(b)))));

  };

if (globalTrace)
    fprintf(stderr, "Leaving stringify_rec\n");

}


//Building function stringify from line: 185

char* stringify(box b) {
  
  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:188");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return("()");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("string", boxType(b))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:191");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(unBoxString(b));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("bool", boxType(b))) {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( unBoxBool(b)) {
          if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:195");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return("true");

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:195");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return("false");

        };

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("int", boxType(b))) {
          if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:198");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return(intToString(unBoxInt(b)));

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("symbol", boxType(b))) {
            if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:201");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return(unBoxSymbol(b));

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalString("list", boxType(b))) {
              if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:205");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              return(stringConcatenate("(", stringConcatenate(stringify(car(b)), stringConcatenate(" ", stringConcatenate(stringify_rec(cdr(b)), ")")))));

            } else {
              if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:211");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              return(stringConcatenate("Unsupported type: ", boxType(b)));

            };

          };

        };

      };

    };

  };

}


//Building function hasTag from line: 219

bool hasTag(box aBox,box key) {
  
if (globalTrace)
    fprintf(stderr, "hasTag at q/base.qon:219 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(aBox)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:222");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(false);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:223");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(isNotFalse(assoc(stringify(key), aBox->tag)));

  };

if (globalTrace)
    fprintf(stderr, "Leaving hasTag\n");

}


//Building function getTag from line: 225

box getTag(box aBox,box key) {
  
if (globalTrace)
    fprintf(stderr, "getTag at q/base.qon:225 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:227");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( false) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:229");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Getting %s from: ", stringify(key));

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:230");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(alistKeys(aBox->tag));

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:231");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:233");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("");

  };

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:235");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(assoc(stringify(key), aBox->tag)));

if (globalTrace)
    fprintf(stderr, "Leaving getTag\n");

}


//Building function getTagFail from line: 237

box getTagFail(box aBox,box key,box onFail) {
  
if (globalTrace)
    fprintf(stderr, "getTagFail at q/base.qon:237 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( hasTag(aBox, key)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:240");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(getTag(aBox, key));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:241");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(onFail);

  };

if (globalTrace)
    fprintf(stderr, "Leaving getTagFail\n");

}


//Building function assocExists from line: 243

bool assocExists(char* key,box aBox) {
  
if (globalTrace)
    fprintf(stderr, "assocExists at q/base.qon:243 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(aBox)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:248");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(false);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:249");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(isNotFalse(assoc(key, aBox)));

  };

if (globalTrace)
    fprintf(stderr, "Leaving assocExists\n");

}


//Building function assocFail from line: 252

box assocFail(char* key,box aBox,box onFail) {
  
if (globalTrace)
    fprintf(stderr, "assocFail at q/base.qon:252 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( assocExists(key, aBox)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:255");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(assoc(key, aBox));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:256");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(boxString(key), onFail));

  };

if (globalTrace)
    fprintf(stderr, "Leaving assocFail\n");

}


//Building function assocPanic from line: 258

box assocPanic(char* key,box aBox,char* onFail) {
  
if (globalTrace)
    fprintf(stderr, "assocPanic at q/base.qon:258 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( assocExists(key, aBox)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:261");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(assoc(key, aBox));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:262");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic(onFail);

  };

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:263");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  panic("Inconceivable");

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:266");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(NULL);

if (globalTrace)
    fprintf(stderr, "Leaving assocPanic\n");

}


//Building function setTag from line: 271

box setTag(box key,list val,box aStruct) {
  
if (globalTrace)
    fprintf(stderr, "setTag at q/base.qon:271 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:273");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  aStruct->tag = alistCons(key, val, aStruct->tag);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:274");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(aStruct);

if (globalTrace)
    fprintf(stderr, "Leaving setTag\n");

}


//Building function filterVoid from line: 284

list filterVoid(list l) {
  box token = NULL;

if (globalTrace)
    fprintf(stderr, "filterVoid at q/base.qon:284 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:289");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(emptyList());

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:291");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token = car(l);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("void", token->typ)) {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:293");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(filterVoid(cdr(l)));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:294");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cons(token, filterVoid(cdr(l))));

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving filterVoid\n");

}


//Building function filterTokens from line: 296

list filterTokens(list l) {
  box token = NULL;

if (globalTrace)
    fprintf(stderr, "filterTokens at q/base.qon:296 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:301");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(emptyList());

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:303");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token = car(l);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(boxType(token), "symbol")) {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("__LINE__", stringify(token))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:308");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(cons(getTagFail(token, boxString("line"), boxInt(-1)), filterTokens(cdr(l))));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("__COLUMN__", stringify(token))) {
          if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:315");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return(cons(getTagFail(token, boxString("column"), boxInt(-1)), filterTokens(cdr(l))));

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("__FILE__", stringify(token))) {
            if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:322");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return(cons(getTagFail(token, boxString("filename"), boxString("Unknown file")), filterTokens(cdr(l))));

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:327");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return(cons(token, filterTokens(cdr(l))));

          };

        };

      };

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:328");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cons(token, filterTokens(cdr(l))));

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving filterTokens\n");

}


//Building function finish_token from line: 330

box finish_token(char* prog,int start,int len,int line,int column,char* filename) {
  box token = NULL;

if (globalTrace)
    fprintf(stderr, "finish_token at q/base.qon:330 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(len, 0)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:334");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token = boxSymbol(sub_string(prog, start, len));

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:336");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token->tag = alistCons(boxString("filename"), boxString(filename), alistCons(boxString("column"), boxInt(column), alistCons(boxString("line"), boxInt(line), alistCons(boxString("totalCharPos"), boxInt(start), NULL))));

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:342");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(token);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:343");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(newVoid());

  };

if (globalTrace)
    fprintf(stderr, "Leaving finish_token\n");

}


//Building function readString from line: 345

char* readString(char* prog,int start,int len) {
  char* token = "";

if (globalTrace)
    fprintf(stderr, "readString at q/base.qon:345 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:347");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  token = sub_string(prog, sub1(add(start, len)), 1);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("\"", token)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:349");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(sub_string(prog, start, sub1(len)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("\\", token)) {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:352");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(readString(prog, start, add(2, len)));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:353");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(readString(prog, start, add1(len)));

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving readString\n");

}


//Building function readComment from line: 356

char* readComment(char* prog,int start,int len) {
  char* token = "";

if (globalTrace)
    fprintf(stderr, "readComment at q/base.qon:356 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:358");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  token = sub_string(prog, sub1(add(start, len)), 1);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isLineBreak(token)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:360");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(sub_string(prog, start, sub1(len)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:361");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(readComment(prog, start, add1(len)));

  };

if (globalTrace)
    fprintf(stderr, "Leaving readComment\n");

}


//Building function isWhiteSpace from line: 364

bool isWhiteSpace(char* s) {
  
if (globalTrace)
    fprintf(stderr, "isWhiteSpace at q/base.qon:364 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(" ", s)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:369");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(true);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("\t", s)) {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:372");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(true);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("\n", s)) {
        if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:375");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(true);

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("\r", s)) {
          if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:378");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return(true);

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:379");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return(false);

        };

      };

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving isWhiteSpace\n");

}


//Building function isLineBreak from line: 381

bool isLineBreak(char* s) {
  
if (globalTrace)
    fprintf(stderr, "isLineBreak at q/base.qon:381 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("\n", s)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:384");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(true);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("\r", s)) {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:386");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(true);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:386");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(false);

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving isLineBreak\n");

}


//Building function incForNewLine from line: 388

int incForNewLine(box token,int val) {
  
if (globalTrace)
    fprintf(stderr, "incForNewLine at q/base.qon:388 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("\n", stringify(token))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:393");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(add1(val));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:394");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(val);

  };

if (globalTrace)
    fprintf(stderr, "Leaving incForNewLine\n");

}


//Building function annotateReadPosition from line: 396

box annotateReadPosition(char* filename,int linecount,int column,int start,box newBox) {
  
if (globalTrace)
    fprintf(stderr, "annotateReadPosition at q/base.qon:396 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:398");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(setTag(boxString("filename"), boxString(filename), setTag(boxString("column"), boxInt(column), setTag(boxString("line"), boxInt(linecount), setTag(boxString("totalCharPos"), boxInt(start), newBox)))));

if (globalTrace)
    fprintf(stderr, "Leaving annotateReadPosition\n");

}


//Building function scan from line: 408

list scan(char* prog,int start,int len,int linecount,int column,char* filename) {
  box token = NULL;
char* newString = "";
box newBox = NULL;

if (globalTrace)
    fprintf(stderr, "scan at q/base.qon:408 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(string_length(prog), sub(start, sub(0, len)))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:414");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token = boxSymbol(sub_string(prog, sub1(add(start, len)), 1));

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:415");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token->tag = alistCons(boxString("totalCharPos"), boxInt(start), NULL);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isOpenBrace(token)) {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:418");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cons(finish_token(prog, start, sub1(len), linecount, column, filename), cons(boxSymbol(openBrace()), scan(prog, add1(start), 1, linecount, add1(column), filename))));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isCloseBrace(token)) {
        if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:424");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(cons(finish_token(prog, start, sub1(len), linecount, column, filename), cons(annotateReadPosition(filename, linecount, column, start, boxSymbol(closeBrace())), scan(prog, add(start, len), 1, linecount, add1(column), filename))));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( isWhiteSpace(stringify(token))) {
          if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:431");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return(cons(finish_token(prog, start, sub1(len), linecount, column, filename), scan(prog, add(start, len), 1, incForNewLine(token, linecount), 0, filename)));

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol(";"), token)) {
            if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:436");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return(scan(prog, add(start, add1(add1(string_length(readComment(prog, add1(start), len))))), 1, add1(linecount), 0, filename));

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("\""), token)) {
              if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:440");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              newString = readString(prog, add1(start), len);

              if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:441");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              newBox = annotateReadPosition(filename, linecount, column, start, boxString(newString));

              if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:443");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              return(cons(newBox, scan(prog, add(start, add1(add1(string_length(newString)))), 1, linecount, add1(column), filename)));

            } else {
              if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:445");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              return(scan(prog, start, sub(len, -1), linecount, add1(column), filename));

            };

          };

        };

      };

    };

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:446");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(emptyList());

  };

if (globalTrace)
    fprintf(stderr, "Leaving scan\n");

}


//Building function isOpenBrace from line: 449

bool isOpenBrace(box b) {
  
if (globalTrace)
    fprintf(stderr, "isOpenBrace at q/base.qon:449 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxSymbol(openBrace()), b)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:452");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(true);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxSymbol("["), b)) {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:455");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(true);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:456");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(false);

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving isOpenBrace\n");

}


//Building function openBrace from line: 457

char* openBrace() {
  
if (globalTrace)
    fprintf(stderr, "openBrace at q/base.qon:457 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:457");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return("(");

if (globalTrace)
    fprintf(stderr, "Leaving openBrace\n");

}


//Building function isCloseBrace from line: 459

bool isCloseBrace(box b) {
  
if (globalTrace)
    fprintf(stderr, "isCloseBrace at q/base.qon:459 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxSymbol(closeBrace()), b)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:464");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(true);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxSymbol("]"), b)) {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:467");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(true);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:468");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(false);

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving isCloseBrace\n");

}


//Building function closeBrace from line: 469

char* closeBrace() {
  
if (globalTrace)
    fprintf(stderr, "closeBrace at q/base.qon:469 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:469");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(")");

if (globalTrace)
    fprintf(stderr, "Leaving closeBrace\n");

}


//Building function skipList from line: 473

list skipList(list l) {
  box b = NULL;

if (globalTrace)
    fprintf(stderr, "skipList at q/base.qon:473 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:476");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(emptyList());

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:478");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    b = car(l);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isOpenBrace(b)) {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:480");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(skipList(skipList(cdr(l))));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isCloseBrace(b)) {
        if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:483");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(cdr(l));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:484");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(skipList(cdr(l)));

      };

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving skipList\n");

}


//Building function makeNode from line: 497

list makeNode(char* name,char* subname,list code,list children) {
  
if (globalTrace)
    fprintf(stderr, "makeNode at q/base.qon:497 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:499");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cons(boxSymbol("node"), alistCons(boxSymbol("line"), getTagFail(code, boxString("line"), boxInt(-1)), cons(cons(boxSymbol("name"), boxString(name)), cons(cons(boxSymbol("subname"), boxString(subname)), cons(cons(boxSymbol("code"), code), alistCons(boxSymbol("children"), children, emptyList())))))));

if (globalTrace)
    fprintf(stderr, "Leaving makeNode\n");

}


//Building function addToNode from line: 513

list addToNode(box key,box val,list node) {
  
if (globalTrace)
    fprintf(stderr, "addToNode at q/base.qon:513 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:515");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cons(boxSymbol("node"), alistCons(key, val, cdr(node))));

if (globalTrace)
    fprintf(stderr, "Leaving addToNode\n");

}


//Building function makeStatementNode from line: 518

list makeStatementNode(char* name,char* subname,list code,list children,box functionName) {
  
if (globalTrace)
    fprintf(stderr, "makeStatementNode at q/base.qon:518 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:520");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(addToNode(boxSymbol("functionName"), functionName, makeNode(name, subname, code, children)));

if (globalTrace)
    fprintf(stderr, "Leaving makeStatementNode\n");

}


//Building function astExpression from line: 523

list astExpression(list tree) {
  
if (globalTrace)
    fprintf(stderr, "astExpression at q/base.qon:523 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(tree)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:527");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(makeNode("expression", "expression", NULL, astSubExpression(tree)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:529");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(astSubExpression(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving astExpression\n");

}


//Building function astSubExpression from line: 531

list astSubExpression(list tree) {
  
if (globalTrace)
    fprintf(stderr, "astSubExpression at q/base.qon:531 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:534");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(emptyList());

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(tree)) {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:538");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cons(astExpression(car(tree)), astSubExpression(cdr(tree))));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:540");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(makeNode("expression", "leaf", tree, NULL));

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving astSubExpression\n");

}


//Building function astIf from line: 542

list astIf(list tree,box fname) {
  
if (globalTrace)
    fprintf(stderr, "astIf at q/base.qon:542 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("then"), car(second(tree)))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:545");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nop();

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:547");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Error at %s:%s!  If statement is missing the true branch.\n\n", stringify(getTag(car(first(tree)), boxString("filename"))), stringify(getTag(car(first(tree)), boxString("line"))));

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:548");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Missing true branch in if statement!  All if statements must have a true and false branch, like this:\n\n(if hungryForApples\n(then (printf \"yes!\"))\n(else (printf \"no!\")))\n\n\n");

  };

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("else"), car(third(tree)))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:551");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nop();

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:553");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Error at %s:%s!  If statement is missing the false branch.\n\n", stringify(getTag(car(first(tree)), boxString("filename"))), stringify(getTag(car(first(tree)), boxString("line"))));

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:554");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Missing false branch in if statement!  All if statements must have a true and false branch, like this:\n\n(if hungryForApples\n(then (printf \"yes!\"))\n(else (printf \"no!\")))\n\n\n");

  };

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:555");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(makeNode("statement", "if", tree, cons(cons(astExpression(first(tree)), NULL), cons(astBody(cdr(second(tree)), fname), cons(astBody(cdr(third(tree)), fname), NULL)))));

if (globalTrace)
    fprintf(stderr, "Leaving astIf\n");

}


//Building function astSetStruct from line: 563

list astSetStruct(list tree) {
  
if (globalTrace)
    fprintf(stderr, "astSetStruct at q/base.qon:563 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:565");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(makeNode("statement", "structSetter", tree, astExpression(third(tree))));

if (globalTrace)
    fprintf(stderr, "Leaving astSetStruct\n");

}


//Building function astSet from line: 568

list astSet(list tree) {
  
if (globalTrace)
    fprintf(stderr, "astSet at q/base.qon:568 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:570");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(makeNode("statement", "setter", tree, astExpression(second(tree))));

if (globalTrace)
    fprintf(stderr, "Leaving astSet\n");

}


//Building function astGetStruct from line: 573

list astGetStruct(list tree) {
  
if (globalTrace)
    fprintf(stderr, "astGetStruct at q/base.qon:573 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:574");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(makeNode("expression", "structGetter", tree, NULL));

if (globalTrace)
    fprintf(stderr, "Leaving astGetStruct\n");

}


//Building function astReturnVoid from line: 576

list astReturnVoid(box fname) {
  
if (globalTrace)
    fprintf(stderr, "astReturnVoid at q/base.qon:576 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:578");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(makeStatementNode("statement", "returnvoid", NULL, NULL, fname));

if (globalTrace)
    fprintf(stderr, "Leaving astReturnVoid\n");

}


//Building function astStatement from line: 580

list astStatement(list tree,box fname) {
  
if (globalTrace)
    fprintf(stderr, "astStatement at q/base.qon:580 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(tree)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:584");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nop();

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:586");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Error at %s:%s!  Statement must be a list.\n\n", stringify(getTag(car(first(tree)), boxString("filename"))), stringify(getTag(car(first(tree)), boxString("line"))));

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:587");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("A statement must be a list: (printf \"Hello\")\n\n\n");

  };

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("if"), car(tree))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:591");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(astIf(cdr(tree), fname));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("set"), car(tree))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:594");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(astSet(cdr(tree)));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("get-struct"), car(tree))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:598");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("Choosing get-struct statement\n");

        if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:599");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(astGetStruct(cdr(tree)));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("set-struct"), car(tree))) {
          if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:602");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return(astSetStruct(cdr(tree)));

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxString("return"), car(tree))) {
            if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equal(listLength(tree), 1)) {
              if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:607");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              return(astReturnVoid(fname));

            } else {
              if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:609");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              return(makeStatementNode("statement", "return", tree, makeNode("expression", "expression", tree, astExpression(tree)), fname));

            };

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:613");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return(makeStatementNode("statement", "statement", tree, makeNode("expression", "expression", tree, astExpression(tree)), fname));

          };

        };

      };

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving astStatement\n");

}


//Building function astBody from line: 618

list astBody(list tree,box fname) {
  
if (globalTrace)
    fprintf(stderr, "astBody at q/base.qon:618 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:621");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(emptyList());

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:622");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(astStatement(car(tree), fname), astBody(cdr(tree), fname)));

  };

if (globalTrace)
    fprintf(stderr, "Leaving astBody\n");

}


//Building function locPanic from line: 624

void locPanic(char* file,char* line,char* message) {
  
if (globalTrace)
    fprintf(stderr, "locPanic at q/base.qon:624 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:626");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s %s:%s\n", file, line, message);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:627");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  panic(message);

if (globalTrace)
    fprintf(stderr, "Leaving locPanic\n");

}


//Building function astFunction from line: 630

list astFunction(list tree) {
  char* file = "";
char* line = "";
box fname = NULL;

if (globalTrace)
    fprintf(stderr, "astFunction at q/base.qon:630 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:632");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fname = second(tree);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:637");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  line = stringify(getTag(fname, boxString("line")));

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:638");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  file = stringify(getTag(fname, boxString("filename")));

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(1, listLength(tree))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:639");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    locPanic(file, line, "Malformed function, seems to be empty");

  } else {
  };

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(2, listLength(tree))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:640");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    locPanic(file, line, "Malformed function, expected function name");

  } else {
  };

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(3, listLength(tree))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:641");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    locPanic(file, line, "Malformed function, expected argument list");

  } else {
  };

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(4, listLength(tree))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:642");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    locPanic(file, line, "Malformed function, expected variable declarations");

  } else {
  };

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(5, listLength(tree))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:643");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    locPanic(file, line, "Malformed function, expected body");

  } else {
  };

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:644");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(alistCons(boxSymbol("file"), getTag(fname, boxString("filename")), alistCons(boxSymbol("line"), getTag(fname, boxString("line")), cons(cons(boxSymbol("name"), boxString("function")), cons(cons(boxSymbol("subname"), second(tree)), cons(cons(boxSymbol("declarations"), cdr(fourth(tree))), cons(cons(boxSymbol("intype"), third(tree)), cons(cons(boxSymbol("outtype"), car(tree)), cons(cons(boxSymbol("children"), astBody(cdr(fifth(tree)), fname)), emptyList())))))))));

if (globalTrace)
    fprintf(stderr, "Leaving astFunction\n");

}


//Building function astFunctionList from line: 665

list astFunctionList(list tree) {
  
if (globalTrace)
    fprintf(stderr, "astFunctionList at q/base.qon:665 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:668");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(emptyList());

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:670");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(astFunction(car(tree)), astFunctionList(cdr(tree))));

  };

if (globalTrace)
    fprintf(stderr, "Leaving astFunctionList\n");

}


//Building function astFunctions from line: 673

list astFunctions(list tree) {
  
if (globalTrace)
    fprintf(stderr, "astFunctions at q/base.qon:673 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("functions"), car(tree))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:676");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(makeNode("functions", "functions", tree, astFunctionList(cdr(tree))));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:677");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Functions section not found!  Every program must have a function section, even if you don't define any functions, although that is a rather pointless program.  Your function section should look like:'\n\n(return_type function_name (arg1 arg2 arg3 ...) (declare types) (body (statement)(statement)))\n\n\nThe function section must be directly after the types section.");

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:678");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(NULL);

  };

if (globalTrace)
    fprintf(stderr, "Leaving astFunctions\n");

}


//Building function loadLib from line: 681

list loadLib(char* path) {
  char* programStr = "";
list tree = NULL;
list library = NULL;

if (globalTrace)
    fprintf(stderr, "loadLib at q/base.qon:681 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:683");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  qlog("Loading library %s\n", path);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:684");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(path);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:685");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, path);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:686");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:687");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  library = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:695");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(library);

if (globalTrace)
    fprintf(stderr, "Leaving loadLib\n");

}


//Building function astInclude from line: 697

list astInclude(list tree) {
  
if (globalTrace)
    fprintf(stderr, "astInclude at q/base.qon:697 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:698");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(loadLib(stringify(tree)));

if (globalTrace)
    fprintf(stderr, "Leaving astInclude\n");

}


//Building function astIncludeList from line: 700

list astIncludeList(list tree) {
  
if (globalTrace)
    fprintf(stderr, "astIncludeList at q/base.qon:700 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:703");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(emptyList());

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:705");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(astInclude(car(tree)), astIncludeList(cdr(tree))));

  };

if (globalTrace)
    fprintf(stderr, "Leaving astIncludeList\n");

}


//Building function astIncludes from line: 707

list astIncludes(list tree) {
  
if (globalTrace)
    fprintf(stderr, "astIncludes at q/base.qon:707 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("includes"), car(tree))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:712");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(makeNode("includes", "includes", tree, astIncludeList(cdr(tree))));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:713");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Includes section not found!  Every program must have an include section, even if you don't import any libraries.  Your include section should look like:'\n\n(includes file1.qon file.qon)\n\n\nThe includes section must be the first section of the file.");

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:714");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(NULL);

  };

if (globalTrace)
    fprintf(stderr, "Leaving astIncludes\n");

}


//Building function astStruct from line: 716

list astStruct(list tree) {
  
if (globalTrace)
    fprintf(stderr, "astStruct at q/base.qon:716 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:717");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(makeNode("type", "struct", tree, NULL));

if (globalTrace)
    fprintf(stderr, "Leaving astStruct\n");

}


//Building function astType from line: 719

list astType(list tree) {
  
if (globalTrace)
    fprintf(stderr, "astType at q/base.qon:719 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(cadr(tree))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:722");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(astStruct(tree));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:723");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(makeNode("type", "type", tree, NULL));

  };

if (globalTrace)
    fprintf(stderr, "Leaving astType\n");

}


//Building function astTypeList from line: 725

list astTypeList(list tree) {
  
if (globalTrace)
    fprintf(stderr, "astTypeList at q/base.qon:725 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:728");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(emptyList());

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:729");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(astType(car(tree)), astTypeList(cdr(tree))));

  };

if (globalTrace)
    fprintf(stderr, "Leaving astTypeList\n");

}


//Building function astTypes from line: 731

list astTypes(list tree) {
  
if (globalTrace)
    fprintf(stderr, "astTypes at q/base.qon:731 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(tree)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:734");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Empty or absent types section");

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:735");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(boxString("!!!Fuck"));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("types"), car(tree))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:738");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(makeNode("types", "types", tree, astTypeList(cdr(tree))));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:740");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      panic("Types section not found!  Every program must have a types section, even if you don't define any types");

      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:741");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("Types section not found!  Every program must have a types section, even if you don't define any types");

      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:742");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(boxString("!!!Fuck"));

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving astTypes\n");

}


//Building function declarationsof from line: 749

list declarationsof(list ass) {
  
if (globalTrace)
    fprintf(stderr, "declarationsof at q/base.qon:749 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:750");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(assocPanic("declarations", cdr(ass), "Cons list has no declarations key")));

if (globalTrace)
    fprintf(stderr, "Leaving declarationsof\n");

}


//Building function codeof from line: 752

list codeof(list ass) {
  
if (globalTrace)
    fprintf(stderr, "codeof at q/base.qon:752 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:753");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(assocPanic("code", cdr(ass), "Given cons list does not contain a code key")));

if (globalTrace)
    fprintf(stderr, "Leaving codeof\n");

}


//Building function functionNameof from line: 755

list functionNameof(list ass) {
  
if (globalTrace)
    fprintf(stderr, "functionNameof at q/base.qon:755 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:756");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(assoc("functionName", cdr(ass))));

if (globalTrace)
    fprintf(stderr, "Leaving functionNameof\n");

}


//Building function nodeof from line: 758

list nodeof(list ass) {
  
if (globalTrace)
    fprintf(stderr, "nodeof at q/base.qon:758 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxBool(false), assoc("node", cdr(ass)))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:762");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Given list does not contain nodes");

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:763");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(boxBool(false));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:764");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cdr(assoc("node", cdr(ass))));

  };

if (globalTrace)
    fprintf(stderr, "Leaving nodeof\n");

}


//Building function lineof from line: 766

list lineof(list ass) {
  
if (globalTrace)
    fprintf(stderr, "lineof at q/base.qon:766 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:768");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(assocFail("line", cdr(ass), boxInt(-1))));

if (globalTrace)
    fprintf(stderr, "Leaving lineof\n");

}


//Building function subnameof from line: 771

list subnameof(list ass) {
  
if (globalTrace)
    fprintf(stderr, "subnameof at q/base.qon:771 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:772");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(assoc("subname", cdr(ass))));

if (globalTrace)
    fprintf(stderr, "Leaving subnameof\n");

}


//Building function nameof from line: 774

list nameof(list ass) {
  
if (globalTrace)
    fprintf(stderr, "nameof at q/base.qon:774 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:775");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(assoc("name", cdr(ass))));

if (globalTrace)
    fprintf(stderr, "Leaving nameof\n");

}


//Building function childrenof from line: 777

list childrenof(list ass) {
  
if (globalTrace)
    fprintf(stderr, "childrenof at q/base.qon:777 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:778");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(assoc("children", cdr(ass))));

if (globalTrace)
    fprintf(stderr, "Leaving childrenof\n");

}


//Building function isNode from line: 781

bool isNode(list val) {
  
if (globalTrace)
    fprintf(stderr, "isNode at q/base.qon:781 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(val)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:786");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(false);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(val)) {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxSymbol("node"), car(val))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:791");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(true);

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:792");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(false);

      };

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:793");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(false);

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving isNode\n");

}


//Building function truthy from line: 795

bool truthy(box aVal) {
  
if (globalTrace)
    fprintf(stderr, "truthy at q/base.qon:795 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:797");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(isNotFalse(aVal));

if (globalTrace)
    fprintf(stderr, "Leaving truthy\n");

}


//Building function isNotFalse from line: 799

bool isNotFalse(box aVal) {
  
if (globalTrace)
    fprintf(stderr, "isNotFalse at q/base.qon:799 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(boxType(aVal), "bool")) {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( unBoxBool(aVal)) {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:802");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(true);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:802");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(false);

    };

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:803");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(true);

  };

if (globalTrace)
    fprintf(stderr, "Leaving isNotFalse\n");

}


//Building function isLeaf from line: 805

bool isLeaf(list n) {
  
if (globalTrace)
    fprintf(stderr, "isLeaf at q/base.qon:805 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:806");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(equalBox(boxString("leaf"), subnameof(n)));

if (globalTrace)
    fprintf(stderr, "Leaving isLeaf\n");

}


//Building function printIndent from line: 809

void printIndent(int ii) {
  
if (globalTrace)
    fprintf(stderr, "printIndent at q/base.qon:809 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(ii, 0)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:814");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  ");

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:814");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(sub1(ii));

  } else {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  };

if (globalTrace)
    fprintf(stderr, "Leaving printIndent\n");

}


//Building function newLine from line: 817

void newLine(int indent) {
  
if (globalTrace)
    fprintf(stderr, "newLine at q/base.qon:817 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:820");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:820");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printIndent(indent);

if (globalTrace)
    fprintf(stderr, "Leaving newLine\n");

}


//Building function noStackTrace from line: 821

list noStackTrace() {
  
if (globalTrace)
    fprintf(stderr, "noStackTrace at q/base.qon:821 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:823");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cons(boxString("boxType"), cons(boxString("stringify"), cons(boxString("isEmpty"), cons(boxString("unBoxString"), cons(boxString("isList"), cons(boxString("unBoxBool"), cons(boxString("unBoxSymbol"), cons(boxString("equalBox"), cons(boxString("assoc"), cons(boxString("inList"), cons(boxString("unBoxInt"), cons(boxString("listLength"), cons(boxString("stroff"), cons(boxString("troff"), cons(boxString("tron"), cons(boxString("stron"), cons(boxString("car"), cons(boxString("cdr"), cons(boxString("cons"), cons(boxString("stackTracePush"), cons(boxString("stackTracePop"), cons(boxString("assertType"), cons(boxString("boxString"), cons(boxString("boxSymbol"), cons(boxString("boxInt"), NULL))))))))))))))))))))))))));

if (globalTrace)
    fprintf(stderr, "Leaving noStackTrace\n");

}


//Building function toStr from line: 850

box toStr(box thing) {
  
if (globalTrace)
    fprintf(stderr, "toStr at q/base.qon:850 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:851");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(boxString(stringify(thing)));

if (globalTrace)
    fprintf(stderr, "Leaving toStr\n");

}


//Building function listLast from line: 853

box listLast(list alist) {
  
if (globalTrace)
    fprintf(stderr, "listLast at q/base.qon:853 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(cdr(alist))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:856");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(car(alist));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:857");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(listLast(cdr(alist)));

  };

if (globalTrace)
    fprintf(stderr, "Leaving listLast\n");

}


//Building function treeCompile from line: 860

list treeCompile(char* filename) {
  char* programStr = "";
list tree = NULL;

if (globalTrace)
    fprintf(stderr, "treeCompile at q/base.qon:860 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:862");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:863");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:864");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(tree);

if (globalTrace)
    fprintf(stderr, "Leaving treeCompile\n");

}


//Building function astBuild from line: 866

list astBuild(char* filename) {
  char* programStr = "";
list tree = NULL;
list program = NULL;

if (globalTrace)
    fprintf(stderr, "astBuild at q/base.qon:866 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:868");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:869");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:871");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:879");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = mergeIncludes(program);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:880");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(program);

if (globalTrace)
    fprintf(stderr, "Leaving astBuild\n");

}


//Building function astCompile from line: 883

void astCompile(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    fprintf(stderr, "astCompile at q/base.qon:883 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:885");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:887");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("Final program: \n");

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:888");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:889");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:890");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "write-file", "luaWriteFile");

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:891");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "read-file", "luaReadFile");

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:892");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "string-length", "string.len");

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:894");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "sub-string", "luaSubstring");

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:895");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "stringLength", "string.len");

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:896");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:897");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:898");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  displayList(tree, 0, true);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:906");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n");

if (globalTrace)
    fprintf(stderr, "Leaving astCompile\n");

}


//Building function mergeIncludes from line: 910

list mergeIncludes(list program) {
  
if (globalTrace)
    fprintf(stderr, "mergeIncludes at q/base.qon:910 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:912");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(merge_recur(childrenof(cdr(cdr(assocPanic("includes", program, "Program lacks include section")))), program));

if (globalTrace)
    fprintf(stderr, "Leaving mergeIncludes\n");

}


//Building function merge_recur from line: 917

list merge_recur(list incs,list program) {
  
if (globalTrace)
    fprintf(stderr, "merge_recur at q/base.qon:917 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(incs), 0)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:921");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(mergeInclude(car(incs), merge_recur(cdr(incs), program)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:922");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(program);

  };

if (globalTrace)
    fprintf(stderr, "Leaving merge_recur\n");

}


//Building function mergeInclude from line: 925

list mergeInclude(list inc,list program) {
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
    fprintf(stderr, "mergeInclude at q/base.qon:925 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(inc)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:941");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(program);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:943");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    functions = childrenof(cdr(assocPanic("functions", inc, "Included file has no functions section")));

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:944");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    oldfunctionsnode = cdr(assocPanic("functions", program, "Current module has no functions section"));

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:945");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    oldfunctions = childrenof(oldfunctionsnode);

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:946");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newfunctions = concatLists(functions, oldfunctions);

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:948");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newFunctionNode = cons(boxSymbol("node"), alistCons(boxSymbol("children"), newfunctions, cdr(oldfunctionsnode)));

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:955");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    types = childrenof(cdr(assocPanic("types", inc, "Included file has no types section")));

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:956");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    oldtypesnode = cdr(assocPanic("types", program, "Current module has no types section"));

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:957");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    oldtypes = childrenof(oldtypesnode);

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:958");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newtypes = concatLists(types, oldtypes);

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:960");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newTypeNode = cons(boxSymbol("node"), alistCons(boxSymbol("children"), newtypes, cdr(oldtypesnode)));

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:965");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newProgram = alistCons(boxString("functions"), newFunctionNode, alistCons(boxString("types"), newTypeNode, alistCons(boxString("includes"), cons(boxSymbol("includes"), NULL), newProgram)));

    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:976");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(newProgram);

  };

if (globalTrace)
    fprintf(stderr, "Leaving mergeInclude\n");

}


//Building function argList from line: 986

list argList(int count,int pos,char** args) {
  
if (globalTrace)
    fprintf(stderr, "argList at q/base.qon:986 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(count, pos)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:992");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(boxString(getStringArray(pos, args)), argList(count, add1(pos), args)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:996");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(NULL);

  };

if (globalTrace)
    fprintf(stderr, "Leaving argList\n");

}


//Building function tron from line: 997

void tron() {
  
  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:997");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalTrace = true;

}


//Building function troff from line: 998

void troff() {
  
  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:998");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalTrace = false;

}


//Building function stron from line: 999

void stron() {
  
  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:999");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalStepTrace = true;

}


//Building function stroff from line: 1000

void stroff() {
  
  if (globalTrace)   snprintf(caller, 1024, "from q/base.qon:1000");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalStepTrace = false;

}


//Building function macrowalk from line: 5

list macrowalk(list l) {
  
if (globalTrace)
    fprintf(stderr, "macrowalk at q/macros.qon:5 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/macros.qon:7");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(NULL);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringConcatenate("box", "List"), stringify(car(l)))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/macros.qon:27");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(car(doBoxList(cdr(l))));

      } else {
      };

      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringConcatenate("string", "List"), stringify(car(l)))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/macros.qon:36");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(car(doStringList(cdr(l))));

      } else {
      };

      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringConcatenate("symbol", "List"), stringify(car(l)))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/macros.qon:43");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(car(doSymbolList(cdr(l))));

      } else {
      };

      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringConcatenate("multi", "List"), stringify(car(l)))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/macros.qon:49");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(car(doMultiList(cdr(l))));

      } else {
      };

      if (globalTrace)   snprintf(caller, 1024, "from q/macros.qon:52");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cons(macrowalk(car(l)), macrowalk(cdr(l))));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/macros.qon:54");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(l);

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving macrowalk\n");

}


//Building function macrosingle from line: 59

list macrosingle(list l,char* search,char* replace) {
  box val = NULL;

if (globalTrace)
    fprintf(stderr, "macrosingle at q/macros.qon:59 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/macros.qon:61");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(NULL);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {
      if (globalTrace)   snprintf(caller, 1024, "from q/macros.qon:68");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cons(macrosingle(car(l), search, replace), macrosingle(cdr(l), search, replace)));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(search, stringify(l))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/macros.qon:79");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        val = clone(l);

        if (globalTrace)   snprintf(caller, 1024, "from q/macros.qon:80");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        val->str = replace;

        if (globalTrace)   snprintf(caller, 1024, "from q/macros.qon:81");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(val);

      } else {
      };

      if (globalTrace)   snprintf(caller, 1024, "from q/macros.qon:83");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(l);

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving macrosingle\n");

}


//Building function macrolist from line: 88

list macrolist(list l,char* search,list replace) {
  box val = NULL;

if (globalTrace)
    fprintf(stderr, "macrolist at q/macros.qon:88 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/macros.qon:90");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(NULL);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(search, stringify(car(l)))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/macros.qon:103");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(concatLists(replace, macrolist(cdr(l), search, replace)));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from q/macros.qon:107");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(cons(macrolist(car(l), search, replace), macrolist(cdr(l), search, replace)));

      };

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/macros.qon:117");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(l);

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving macrolist\n");

}


//Building function car from line: 9

box car(list l) {
  
  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:14");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Cannot call car on empty list!\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:15");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Cannot call car on empty list!\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:16");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(NULL);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:18");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    assertType("list", l, 18, "q/lists.qon");

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(l->car)) {
      if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:20");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(NULL);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:21");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(l->car);

    };

  };

}


//Building function cdr from line: 23

list cdr(list l) {
  
  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:25");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assertType("list", l, 25, "q/lists.qon");

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:28");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Attempt to cdr an empty list!!!!\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:29");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Attempt to cdr an empty list!!!!\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:30");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(NULL);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:31");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(l->cdr);

  };

}


//Building function cons from line: 33

list cons(box data,list l) {
  pair p = NULL;

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:35");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  p = makePair();

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:36");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  p->cdr = l;

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:37");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  p->car = data;

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:38");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  p->typ = "list";

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:39");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(p);

}


//Building function caar from line: 48

box caar(list l) {
  
if (globalTrace)
    fprintf(stderr, "caar at q/lists.qon:48 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:48");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(car(car(l)));

if (globalTrace)
    fprintf(stderr, "Leaving caar\n");

}


//Building function cadr from line: 49

box cadr(list l) {
  
if (globalTrace)
    fprintf(stderr, "cadr at q/lists.qon:49 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:49");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(car(cdr(l)));

if (globalTrace)
    fprintf(stderr, "Leaving cadr\n");

}


//Building function caddr from line: 50

box caddr(list l) {
  
if (globalTrace)
    fprintf(stderr, "caddr at q/lists.qon:50 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:50");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(car(cdr(cdr(l))));

if (globalTrace)
    fprintf(stderr, "Leaving caddr\n");

}


//Building function cadddr from line: 51

box cadddr(list l) {
  
if (globalTrace)
    fprintf(stderr, "cadddr at q/lists.qon:51 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:51");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(car(cdr(cdr(cdr(l)))));

if (globalTrace)
    fprintf(stderr, "Leaving cadddr\n");

}


//Building function caddddr from line: 52

box caddddr(list l) {
  
if (globalTrace)
    fprintf(stderr, "caddddr at q/lists.qon:52 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:52");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(car(cdr(cdr(cdr(cdr(l))))));

if (globalTrace)
    fprintf(stderr, "Leaving caddddr\n");

}


//Building function cddr from line: 53

box cddr(list l) {
  
if (globalTrace)
    fprintf(stderr, "cddr at q/lists.qon:53 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:53");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(cdr(l)));

if (globalTrace)
    fprintf(stderr, "Leaving cddr\n");

}


//Building function first from line: 54

box first(list l) {
  
if (globalTrace)
    fprintf(stderr, "first at q/lists.qon:54 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:54");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(car(l));

if (globalTrace)
    fprintf(stderr, "Leaving first\n");

}


//Building function second from line: 55

box second(list l) {
  
if (globalTrace)
    fprintf(stderr, "second at q/lists.qon:55 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:55");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cadr(l));

if (globalTrace)
    fprintf(stderr, "Leaving second\n");

}


//Building function third from line: 56

box third(list l) {
  
if (globalTrace)
    fprintf(stderr, "third at q/lists.qon:56 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:56");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(caddr(l));

if (globalTrace)
    fprintf(stderr, "Leaving third\n");

}


//Building function fourth from line: 57

box fourth(list l) {
  
if (globalTrace)
    fprintf(stderr, "fourth at q/lists.qon:57 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:57");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cadddr(l));

if (globalTrace)
    fprintf(stderr, "Leaving fourth\n");

}


//Building function fifth from line: 58

box fifth(list l) {
  
if (globalTrace)
    fprintf(stderr, "fifth at q/lists.qon:58 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:58");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(caddddr(l));

if (globalTrace)
    fprintf(stderr, "Leaving fifth\n");

}


//Building function isList from line: 61

bool isList(box b) {
  
  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:65");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(true);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:66");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(equalString("list", b->typ));

  };

}


//Building function emptyList from line: 68

list emptyList() {
  
if (globalTrace)
    fprintf(stderr, "emptyList at q/lists.qon:68 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:68");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(NULL);

if (globalTrace)
    fprintf(stderr, "Leaving emptyList\n");

}


//Building function isEmpty from line: 70

bool isEmpty(box b) {
  
  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:73");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(true);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:75");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(false);

  };

}


//Building function listLength from line: 77

int listLength(list l) {
  
  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:82");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(0);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:83");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(add1(listLength(cdr(l))));

  };

}


//Building function alistCons from line: 86

list alistCons(box key,box value,list alist) {
  
if (globalTrace)
    fprintf(stderr, "alistCons at q/lists.qon:86 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:87");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cons(cons(key, value), alist));

if (globalTrace)
    fprintf(stderr, "Leaving alistCons\n");

}


//Building function assoc from line: 89

list assoc(char* searchTerm,list l) {
  list elem = NULL;

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:91");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assertType("list", l, 91, "q/lists.qon");

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:94");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(boxBool(false));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:96");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    elem = car(l);

    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:97");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    assertType("list", elem, 97, "q/lists.qon");

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isEmpty(elem)) {
      if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:99");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(assoc(searchTerm, cdr(l)));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:101");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( false) {
        if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:101");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("Comparing %s and %s\n", searchTerm, stringify(car(elem)));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:101");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("");

      };

      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(searchTerm, stringify(car(elem)))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:105");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(elem);

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:106");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(assoc(searchTerm, cdr(l)));

      };

    };

  };

}


//Building function chooseBox from line: 110

char* chooseBox(char* aType) {
  
if (globalTrace)
    fprintf(stderr, "chooseBox at q/lists.qon:110 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("string", aType)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:113");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return("boxString");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("symbol", aType)) {
      if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:115");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return("boxSymbol");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("bool", aType)) {
        if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:117");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return("boxBool");

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("int", aType)) {
          if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:119");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return("boxInt");

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("float", aType)) {
            if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:121");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return("boxFloat");

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:122");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            panic("Invalid type");

          };

        };

      };

    };

  };

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:123");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return("");

if (globalTrace)
    fprintf(stderr, "Leaving chooseBox\n");

}


//Building function mlistLiteral from line: 126

box mlistLiteral(box b) {
  
if (globalTrace)
    fprintf(stderr, "mlistLiteral at q/lists.qon:126 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:129");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(NULL);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("string", boxType(b))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:132");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(b);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("bool", boxType(b))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:136");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(b);

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("int", boxType(b))) {
          if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:139");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return(b);

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("symbol", boxType(b))) {
            if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:142");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return(boxString(unBoxSymbol(b)));

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:146");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return(boxString(stringConcatenate("Unsupported type: ", boxType(b))));

          };

        };

      };

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving mlistLiteral\n");

}


//Building function doMultiList from line: 148

list doMultiList(list l) {
  list newlist = NULL;
list ret = NULL;
box elem = NULL;

if (globalTrace)
    fprintf(stderr, "doMultiList at q/lists.qon:148 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:151");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(boxSymbol("nil"), NULL));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isEmpty(l)) {
      if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:154");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(NULL);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:157");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      elem = first(l);

      if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:158");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      newlist = cons(boxString(chooseBox(elem->typ)), cons(mlistLiteral(first(l)), newlist));

      if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:159");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ret = cons(cons(boxSymbol("cons"), cons(newlist, doMultiList(cdr(l)))), NULL);

      if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:168");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(ret);

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving doMultiList\n");

}


//Building function doStringList from line: 171

list doStringList(list l) {
  list newlist = NULL;
list ret = NULL;

if (globalTrace)
    fprintf(stderr, "doStringList at q/lists.qon:171 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:174");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(boxSymbol("nil"), NULL));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:176");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newlist = cons(boxSymbol("boxString"), cons(first(l), newlist));

    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:177");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ret = cons(cons(boxSymbol("cons"), cons(newlist, doStringList(cdr(l)))), NULL);

    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:186");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(ret);

  };

if (globalTrace)
    fprintf(stderr, "Leaving doStringList\n");

}


//Building function doSymbolList from line: 188

list doSymbolList(list l) {
  list newlist = NULL;
list ret = NULL;

if (globalTrace)
    fprintf(stderr, "doSymbolList at q/lists.qon:188 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:191");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(boxSymbol("nil"), NULL));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:193");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newlist = cons(boxSymbol("boxSymbol"), cons(first(l), newlist));

    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:194");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ret = cons(cons(boxSymbol("cons"), cons(newlist, doSymbolList(cdr(l)))), NULL);

    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:203");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(ret);

  };

if (globalTrace)
    fprintf(stderr, "Leaving doSymbolList\n");

}


//Building function doBoxList from line: 206

list doBoxList(list l) {
  
if (globalTrace)
    fprintf(stderr, "doBoxList at q/lists.qon:206 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:211");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(boxSymbol("nil"), NULL));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:213");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(cons(boxSymbol("cons"), cons(first(l), doBoxList(cdr(l)))), NULL));

  };

if (globalTrace)
    fprintf(stderr, "Leaving doBoxList\n");

}


//Building function concatLists from line: 226

list concatLists(list seq1,list seq2) {
  
if (globalTrace)
    fprintf(stderr, "concatLists at q/lists.qon:226 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(seq1)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:229");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(seq2);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:230");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(car(seq1), concatLists(cdr(seq1), seq2)));

  };

if (globalTrace)
    fprintf(stderr, "Leaving concatLists\n");

}


//Building function alistKeys from line: 232

list alistKeys(list alist) {
  
if (globalTrace)
    fprintf(stderr, "alistKeys at q/lists.qon:232 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(alist)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:235");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(NULL);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:236");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(car(car(alist)), alistKeys(cdr(alist))));

  };

if (globalTrace)
    fprintf(stderr, "Leaving alistKeys\n");

}


//Building function displayList from line: 238

void displayList(list l,int indent,bool first) {
  box val = NULL;

if (globalTrace)
    fprintf(stderr, "displayList at q/lists.qon:238 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l)) {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isEmpty(l)) {        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return;

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:248");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( first) {
        } else {
          if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:250");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf(" ");

        };

        if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:251");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        val = car(l);

        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( isList(val)) {
          if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:254");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

          if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:255");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("%s", openBrace());

          if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:256");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          displayList(car(l), add1(indent), true);

          if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:257");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("%s", closeBrace());

          if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:258");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          displayList(cdr(l), indent, false);

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("string", val->typ)) {
            if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:261");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("\"%s\"", unBoxString(val));

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:262");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s", stringify(val));

          };

          if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:263");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          displayList(cdr(l), indent, false);

        };

      };

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("string", l->typ)) {
        if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:266");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("\"%s\"", unBoxString(l));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:267");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s", stringify(l));

      };

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving displayList\n");

}


//Building function listReverse from line: 270

list listReverse(list l) {
  
if (globalTrace)
    fprintf(stderr, "listReverse at q/lists.qon:270 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:273");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(NULL);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:274");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(car(l), listReverse(cdr(l))));

  };

if (globalTrace)
    fprintf(stderr, "Leaving listReverse\n");

}


//Building function inList from line: 276

bool inList(box item,list l) {
  
  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:279");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(false);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(car(l), item)) {
      if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:284");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(true);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:285");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(inList(item, cdr(l)));

    };

  };

}


//Building function equalList from line: 287

bool equalList(list a,list b) {
  
if (globalTrace)
    fprintf(stderr, "equalList at q/lists.qon:287 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(a)) {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(b)) {
      if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:292");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(true);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:294");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(false);

    };

  } else {
  };

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b)) {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(a)) {
      if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:300");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(true);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:302");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(false);

    };

  } else {
  };

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(car(a), car(b))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:306");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(equalList(cdr(a), cdr(b)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:307");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(false);

  };

if (globalTrace)
    fprintf(stderr, "Leaving equalList\n");

}


//Building function reverseRec from line: 310

list reverseRec(list oldL,list newL) {
  
if (globalTrace)
    fprintf(stderr, "reverseRec at q/lists.qon:310 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(oldL)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:313");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(newL);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:314");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(reverseRec(cdr(oldL), cons(first(oldL), newL)));

  };

if (globalTrace)
    fprintf(stderr, "Leaving reverseRec\n");

}


//Building function reverseList from line: 317

list reverseList(list l) {
  
if (globalTrace)
    fprintf(stderr, "reverseList at q/lists.qon:317 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/lists.qon:319");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(reverseRec(l, NULL));

if (globalTrace)
    fprintf(stderr, "Leaving reverseList\n");

}


//Building function readSexpr from line: 4

list readSexpr(char* aStr,char* filename) {
  list tokens = NULL;
list as = NULL;

if (globalTrace)
    fprintf(stderr, "readSexpr at q/newparser.qon:4 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:6");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tokens = emptyList();

  if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:7");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tokens = filterTokens(filterVoid(scan(aStr, 0, 1, 0, 0, filename)));

  if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:8");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  as = sexprTree(tokens);

  if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:9");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(car(as));

if (globalTrace)
    fprintf(stderr, "Leaving readSexpr\n");

}


//Building function sexprTree from line: 11

list sexprTree(list l) {
  box b = NULL;

if (globalTrace)
    fprintf(stderr, "sexprTree at q/newparser.qon:11 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:14");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(emptyList());

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:16");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    b = car(l);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isOpenBrace(b)) {
      if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:19");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cons(sexprTree(cdr(l)), sexprTree(skipList(cdr(l)))));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isCloseBrace(b)) {
        if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:22");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(emptyList());

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:24");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(setTag(boxString("line"), getTagFail(b, boxString("line"), boxInt(-1)), cons(b, sexprTree(cdr(l)))));

      };

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving sexprTree\n");

}


//Building function loadQuon from line: 29

list loadQuon(char* filename) {
  char* programStr = "";
list tree = NULL;

if (globalTrace)
    fprintf(stderr, "loadQuon at q/newparser.qon:29 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:32");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:33");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:35");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(tree);

if (globalTrace)
    fprintf(stderr, "Leaving loadQuon\n");

}


//Building function getIncludes from line: 38

list getIncludes(list program) {
  
if (globalTrace)
    fprintf(stderr, "getIncludes at q/newparser.qon:38 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:40");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(first(program)));

if (globalTrace)
    fprintf(stderr, "Leaving getIncludes\n");

}


//Building function getTypes from line: 42

list getTypes(list program) {
  
if (globalTrace)
    fprintf(stderr, "getTypes at q/newparser.qon:42 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:44");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(second(program)));

if (globalTrace)
    fprintf(stderr, "Leaving getTypes\n");

}


//Building function getFunctions from line: 46

list getFunctions(list program) {
  
if (globalTrace)
    fprintf(stderr, "getFunctions at q/newparser.qon:46 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:48");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(third(program)));

if (globalTrace)
    fprintf(stderr, "Leaving getFunctions\n");

}


//Building function loadIncludes from line: 51

list loadIncludes(list tree) {
  list newProg = NULL;
char* includeFile = "";
list functionsCombined = NULL;
list typesCombined = NULL;
list includeTree = NULL;

if (globalTrace)
    fprintf(stderr, "loadIncludes at q/newparser.qon:51 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(getIncludes(tree)), 0)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:63");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    includeFile = stringify(first(getIncludes(tree)));

    if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:66");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    includeTree = loadQuon(includeFile);

    if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:69");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    functionsCombined = concatLists(getFunctions(includeTree), getFunctions(tree));

    if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:70");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    typesCombined = concatLists(getTypes(includeTree), getTypes(tree));

    if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:73");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newProg = buildProg(cdr(getIncludes(tree)), typesCombined, functionsCombined);

    if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:75");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(loadIncludes(newProg));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:78");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(tree);

  };

if (globalTrace)
    fprintf(stderr, "Leaving loadIncludes\n");

}


//Building function buildProg from line: 81

list buildProg(list includes,list types,list functions) {
  list program = NULL;

if (globalTrace)
    fprintf(stderr, "buildProg at q/newparser.qon:81 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:83");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  includes = cons(boxSymbol("includes"), includes);

  if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:84");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  types = cons(boxSymbol("types"), types);

  if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:85");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  functions = cons(boxSymbol("functions"), functions);

  if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:86");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = cons(includes, cons(types, cons(functions, NULL)));

  if (globalTrace)   snprintf(caller, 1024, "from q/newparser.qon:89");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(program);

if (globalTrace)
    fprintf(stderr, "Leaving buildProg\n");

}


//Building function numbers from line: 4

list numbers(int num) {
  
if (globalTrace)
    fprintf(stderr, "numbers at q/perl.qon:4 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(0, num)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:7");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(boxString("-"), NULL));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:8");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(boxString(stringify(boxInt(num))), numbers(sub1(num))));

  };

if (globalTrace)
    fprintf(stderr, "Leaving numbers\n");

}


//Building function lexType from line: 11

char* lexType(box abox) {
  
if (globalTrace)
    fprintf(stderr, "lexType at q/perl.qon:11 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("string", boxType(abox))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:16");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return("string");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(boxString(sub_string(stringify(abox), 0, 1)), numbers(9))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:19");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return("number");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:20");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return("symbol");

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving lexType\n");

}


//Building function perlLeaf from line: 24

void perlLeaf(list thisNode,int indent) {
  
if (globalTrace)
    fprintf(stderr, "perlLeaf at q/perl.qon:24 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", lexType(codeof(thisNode)))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:27");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s", dollar());

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:28");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("");

  };

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:30");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  display(perlFuncMap(codeof(thisNode)));

if (globalTrace)
    fprintf(stderr, "Leaving perlLeaf\n");

}


//Building function perlStructGetterExpression from line: 33

void perlStructGetterExpression(list thisNode,int indent) {
  
if (globalTrace)
    fprintf(stderr, "perlStructGetterExpression at q/perl.qon:33 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("structGetter"), subnameof(thisNode))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:36");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlGetStruct(thisNode, indent);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:37");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlLeaf(thisNode, indent);

  };

if (globalTrace)
    fprintf(stderr, "Leaving perlStructGetterExpression\n");

}


//Building function perlExpression from line: 39

void perlExpression(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "perlExpression at q/perl.qon:39 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isLeaf(node)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:42");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlLeaf(node, indent);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:43");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlSubExpression(node, indent);

  };

if (globalTrace)
    fprintf(stderr, "Leaving perlExpression\n");

}


//Building function perlRecurList from line: 45

void perlRecurList(list expr,int indent) {
  
if (globalTrace)
    fprintf(stderr, "perlRecurList at q/perl.qon:45 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:50");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlExpression(car(expr), indent);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:52");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:53");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(", ");

      if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:53");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      perlRecurList(cdr(expr), indent);

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving perlRecurList\n");

}


//Building function perlSubExpression from line: 56

void perlSubExpression(list tree,int indent) {
  box thing = NULL;

if (globalTrace)
    fprintf(stderr, "perlSubExpression at q/perl.qon:56 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNode(childrenof(tree))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:62");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      perlSubExpression(childrenof(tree), indent);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isLeaf(tree)) {
        if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:66");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s", dollar());

        if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:67");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        display(perlFuncMap(codeof(tree)));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equal(1, listLength(childrenof(tree)))) {
          if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:71");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          display(codeof(car(childrenof(tree))));

          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxString("return"), codeof(car(childrenof(tree))))) {
            if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:75");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("");

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:76");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("()");

          };

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:78");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          thing = codeof(car(childrenof(tree)));

          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("get-struct"), thing)) {
            if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:81");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s%s->{%s}", dollar(), stringify(codeof(second(childrenof(tree)))), stringify(codeof(third(childrenof(tree)))));

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("new"), thing)) {
              if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:85");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("{}");

            } else {
              if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:87");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s(", stringify(perlFuncMap(codeof(car(childrenof(tree))))));

              if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:91");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              perlRecurList(cdr(childrenof(tree)), indent);

              if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:92");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            };

          };

        };

      };

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving perlSubExpression\n");

}


//Building function perlIf from line: 94

void perlIf(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "perlIf at q/perl.qon:94 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:96");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:97");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("if ( ");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:98");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlExpression(car(first(childrenof(node))), 0);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:99");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(") {");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:100");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlBody(second(childrenof(node)), add1(indent));

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:101");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:102");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("} else {");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:103");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlBody(third(childrenof(node)), add1(indent));

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:104");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:105");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("}");

if (globalTrace)
    fprintf(stderr, "Leaving perlIf\n");

}


//Building function perlSetStruct from line: 107

void perlSetStruct(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "perlSetStruct at q/perl.qon:107 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:110");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:111");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s->{%s} = ", dollar(), stringify(first(codeof(node))), stringify(second(codeof(node))));

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:112");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlExpression(childrenof(node), indent);

if (globalTrace)
    fprintf(stderr, "Leaving perlSetStruct\n");

}


//Building function perlGetStruct from line: 114

void perlGetStruct(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "perlGetStruct at q/perl.qon:114 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:116");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:117");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s->{%s}", dollar(), stringify(first(codeof(node))), stringify(second(codeof(node))));

if (globalTrace)
    fprintf(stderr, "Leaving perlGetStruct\n");

}


//Building function perlSet from line: 119

void perlSet(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "perlSet at q/perl.qon:119 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:121");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:122");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s = ", dollar(), stringify(first(codeof(node))));

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:123");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlExpression(childrenof(node), indent);

if (globalTrace)
    fprintf(stderr, "Leaving perlSet\n");

}


//Building function assertNode from line: 125

void assertNode(list node) {
  
if (globalTrace)
    fprintf(stderr, "assertNode at q/perl.qon:125 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNode(node)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:129");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Not a node!");

  };

if (globalTrace)
    fprintf(stderr, "Leaving assertNode\n");

}


//Building function perlStatement from line: 132

void perlStatement(list node,int indent) {
  box functionName = NULL;

if (globalTrace)
    fprintf(stderr, "perlStatement at q/perl.qon:132 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:138");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assertNode(node);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("setter"), subnameof(node))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:140");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlSet(node, indent);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("structSetter"), subnameof(node))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:143");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      perlSetStruct(node, indent);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), subnameof(node))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:146");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        perlIf(node, indent);

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("returnvoid"), subnameof(node))) {
          if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:150");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          functionName = functionNameof(node);

          if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:151");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("\n#Returnvoid\n");

          if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:152");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

          if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:155");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

          if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:155");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("return");

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxString("return"), subnameof(node))) {
            if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:159");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            functionName = functionNameof(node);

            if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( inList(functionName, noStackTrace())) {
              if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:161");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("");

            } else {
              if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:163");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("\n#standard return: %s\n", stringify(functionName));

              if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:164");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              newLine(indent);

              if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:165");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s%s%s", "if (", dollar(), "globalTrace) {printf(\"Leaving \\n\")}\n");

            };

            if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:167");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            newLine(indent);

            if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:168");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            perlExpression(childrenof(node), indent);

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( inList(functionName, noStackTrace())) {
              if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:172");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("");

            } else {
              if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:174");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("\n#standard expression\n");

            };

            if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:178");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            newLine(indent);

            if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:179");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            perlExpression(childrenof(node), indent);

            if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:180");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            newLine(indent);

          };

        };

      };

    };

  };

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:183");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(";\n");

if (globalTrace)
    fprintf(stderr, "Leaving perlStatement\n");

}


//Building function perlBody from line: 185

void perlBody(list tree,int indent) {
  
if (globalTrace)
    fprintf(stderr, "perlBody at q/perl.qon:185 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:190");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:191");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s%s%s", "if (", dollar(), "globalStepTrace) {printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__)}\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:192");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlStatement(car(tree), indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:193");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlBody(cdr(tree), indent);

  };

if (globalTrace)
    fprintf(stderr, "Leaving perlBody\n");

}


//Building function perlDeclarations from line: 195

void perlDeclarations(list decls,int indent) {
  box decl = NULL;

if (globalTrace)
    fprintf(stderr, "perlDeclarations at q/perl.qon:195 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:200");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:201");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("my %s%s = ", dollar(), stringify(second(decl)));

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:202");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(perlConstMap(third(decl)));

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:203");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:204");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlDeclarations(cdr(decls), indent);

  };

if (globalTrace)
    fprintf(stderr, "Leaving perlDeclarations\n");

}


//Building function perlFunction from line: 206

void perlFunction(list node) {
  box name = NULL;

if (globalTrace)
    fprintf(stderr, "perlFunction at q/perl.qon:206 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:208");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = subnameof(node);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:209");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n#Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:213");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:217");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0);

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:218");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("sub %s", stringify(subnameof(node)));

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:219");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" {");

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:220");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:221");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlFunctionArgs(cdr(assoc("intype", cdr(node))));

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:222");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:223");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlDeclarations(declarationsof(node), 1);

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:224");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\nif (%sglobalTrace) { printf(\"%s at %s:%s\\n\") }\n", dollar(), stringify(subnameof(node)), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(name, noStackTrace())) {
      if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:226");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:228");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    };

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:230");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlBody(childrenof(node), 1);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(name, noStackTrace())) {
      if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:232");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:234");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    };

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:236");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n");

  };

if (globalTrace)
    fprintf(stderr, "Leaving perlFunction\n");

}


//Building function perlForwardDeclaration from line: 238

void perlForwardDeclaration(list node) {
  
if (globalTrace)
    fprintf(stderr, "perlForwardDeclaration at q/perl.qon:238 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:243");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\nsub %s", stringify(subnameof(node)));

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:246");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";");

  };

if (globalTrace)
    fprintf(stderr, "Leaving perlForwardDeclaration\n");

}


//Building function perlForwardDeclarations from line: 248

void perlForwardDeclarations(list tree) {
  
if (globalTrace)
    fprintf(stderr, "perlForwardDeclarations at q/perl.qon:248 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:253");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlForwardDeclaration(car(tree));

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:254");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlForwardDeclarations(cdr(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving perlForwardDeclarations\n");

}


//Building function perlFunctions from line: 256

void perlFunctions(list tree) {
  
if (globalTrace)
    fprintf(stderr, "perlFunctions at q/perl.qon:256 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:260");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlFunction(car(tree));

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:260");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlFunctions(cdr(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving perlFunctions\n");

}


//Building function dollar from line: 263

char* dollar() {
  
if (globalTrace)
    fprintf(stderr, "dollar at q/perl.qon:263 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:264");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(character(36));

if (globalTrace)
    fprintf(stderr, "Leaving dollar\n");

}


//Building function atSym from line: 266

char* atSym() {
  
if (globalTrace)
    fprintf(stderr, "atSym at q/perl.qon:266 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:267");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(character(64));

if (globalTrace)
    fprintf(stderr, "Leaving atSym\n");

}


//Building function perlIncludes from line: 270

void perlIncludes(list nodes) {
  
if (globalTrace)
    fprintf(stderr, "perlIncludes at q/perl.qon:270 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:272");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s\n", "use strict;");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:273");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s", "my ", dollar(), "caller;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:274");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s\n", "use Carp;");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:275");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  dollar();

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:276");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s\n", "use Carp::Always;");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:277");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub greaterthan { ", dollar(), "_[0] > ", dollar(), "_[1] };");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:278");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s\n", "sub qlog { warn ", "@", "_ };");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:279");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub mult { ", dollar(), "_[0] * ", dollar(), "_[1] };");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:280");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub multf { ", dollar(), "_[0] * ", dollar(), "_[1] };");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:281");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub greaterthanf { ", dollar(), "_[0] > ", dollar(), "_[1] };");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:282");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub equalString { ", dollar(), "_[0] eq ", dollar(), "_[1] };");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:289");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("sub read_file { my %sfile = shift; %sfile || die \"Empty file name!!!\"; open my %sfh, '<', %sfile or die; local %s/ = undef; my %scont = <%sfh>; close %sfh; return %scont; }; \n", dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar());

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:291");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("sub write_file {my %sfile = shift; my %sdata = shift; %sfile || die \"Empty file name!!!\"; open my %sfh, '>', %sfile or die; print %sfh %sdata; close %sfh; } \n", dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar());

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:293");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub stringConcatenate { ", dollar(), "_[0] . ", dollar(), "_[1]}");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:294");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub subtract { ", dollar(), "_[0] - ", dollar(), "_[1]}");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:295");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub subf { ", dollar(), "_[0] - ", dollar(), "_[1]}");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:296");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub andBool { ", dollar(), "_[0] && ", dollar(), "_[1]}");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:297");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub equal { ", dollar(), "_[0] == ", dollar(), "_[1]}");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:298");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n", "sub panic { carp ", atSym(), "_; die \"", atSym(), "_\"}");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:299");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("sub intToString { return %s_[0]}\n", dollar());

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:300");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("sub character { return chr(%s_[0])}\n", dollar());

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:301");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s%s%s%s%s\n", "sub getStringArray { my ", dollar(), "index = shift; my ", dollar(), "arr = shift; return ", dollar(), "arr->[", dollar(), "index]}");

if (globalTrace)
    fprintf(stderr, "Leaving perlIncludes\n");

}


//Building function perlTypeDecl from line: 305

void perlTypeDecl(list l) {
  
if (globalTrace)
    fprintf(stderr, "perlTypeDecl at q/perl.qon:305 (%s)\n", caller);

if (globalTrace)
    fprintf(stderr, "Leaving perlTypeDecl\n");

}


//Building function perlStructComponents from line: 310

void perlStructComponents(list node) {
  
if (globalTrace)
    fprintf(stderr, "perlStructComponents at q/perl.qon:310 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:314");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlTypeDecl(car(node));

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:314");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlStructComponents(cdr(node));

  };

if (globalTrace)
    fprintf(stderr, "Leaving perlStructComponents\n");

}


//Building function perlStruct from line: 316

void perlStruct(list node) {
  
if (globalTrace)
    fprintf(stderr, "perlStruct at q/perl.qon:316 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:317");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlStructComponents(cdr(car(node)));

if (globalTrace)
    fprintf(stderr, "Leaving perlStruct\n");

}


//Building function perlTypeMap from line: 319

box perlTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    fprintf(stderr, "perlTypeMap at q/perl.qon:319 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:322");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:328");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cdr(assoc(stringify(aSym), symMap)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:329");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym);

  };

if (globalTrace)
    fprintf(stderr, "Leaving perlTypeMap\n");

}


//Building function perlConstMap from line: 331

box perlConstMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    fprintf(stderr, "perlConstMap at q/perl.qon:331 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:336");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("false"), boxSymbol("0"), alistCons(boxSymbol("nil"), boxSymbol("undef"), NULL));

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:338");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cdr(assocFail(stringify(aSym), symMap, aSym)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:339");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym);

  };

if (globalTrace)
    fprintf(stderr, "Leaving perlConstMap\n");

}


//Building function perlFuncMap from line: 341

box perlFuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    fprintf(stderr, "perlFuncMap at q/perl.qon:341 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:346");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("sub"), boxSymbol("subtract"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("substr"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("length"), alistCons(boxSymbol("nil"), boxSymbol("undef"), NULL))))))));

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:355");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cdr(assocFail(stringify(aSym), symMap, aSym)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:356");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym);

  };

if (globalTrace)
    fprintf(stderr, "Leaving perlFuncMap\n");

}


//Building function perlType from line: 358

void perlType(list node) {
  
if (globalTrace)
    fprintf(stderr, "perlType at q/perl.qon:358 (%s)\n", caller);

if (globalTrace)
    fprintf(stderr, "Leaving perlType\n");

}


//Building function perlTypes from line: 363

void perlTypes(list nodes) {
  
if (globalTrace)
    fprintf(stderr, "perlTypes at q/perl.qon:363 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:367");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlType(car(nodes));

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:367");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlTypes(cdr(nodes));

  };

if (globalTrace)
    fprintf(stderr, "Leaving perlTypes\n");

}


//Building function perlFunctionArgs from line: 369

void perlFunctionArgs(list tree) {
  
if (globalTrace)
    fprintf(stderr, "perlFunctionArgs at q/perl.qon:369 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:374");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s%s", "my ", dollar());

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:375");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(second(tree));

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:376");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" = shift;\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:377");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlFunctionArgs(cddr(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving perlFunctionArgs\n");

}


//Building function perlCompile from line: 379

void perlCompile(char* filename) {
  char* programStr = "";
list tree = NULL;
list program = NULL;

if (globalTrace)
    fprintf(stderr, "perlCompile at q/perl.qon:379 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:381");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:382");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:383");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:391");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = mergeIncludes(program);

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:392");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlIncludes(cdr(assoc("includes", program)));

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:393");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlTypes(childrenof(cdr(assoc("types", program))));

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:395");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("use strict;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:396");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("use Carp;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:397");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("use Data::Dumper;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:398");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s", "my ", dollar(), "globalStackTrace = undef;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:399");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s", "my ", dollar(), "globalTrace = undef;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:400");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s", "my ", dollar(), "globalStepTrace = undef;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:401");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s", "my ", dollar(), "globalArgs = undef;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:402");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s", "my ", dollar(), "globalArgsCount = undef;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:403");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s\n", "my ", dollar(), "true = 1;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:404");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s", "my ", dollar(), "false = 0;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:405");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s", "my ", dollar(), "undef;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:406");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s", "\nsub isNil {\n    return !defined(", dollar(), "_[0]);\n}\n\n\n#Forward declarations\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:408");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlForwardDeclarations(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:410");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n#End forward declarations\n\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:411");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:413");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(";\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:414");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s", dollar(), "globalArgs = [ 1, ", atSym(), "ARGV];");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:415");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s", dollar(), "globalArgsCount = scalar(", atSym(), "ARGV)+1;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/perl.qon:416");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("start();");

if (globalTrace)
    fprintf(stderr, "Leaving perlCompile\n");

}


//Building function ansiFunctionArgs from line: 3

void ansiFunctionArgs(list tree) {
  
if (globalTrace)
    fprintf(stderr, "ansiFunctionArgs at q/ansi.qon:3 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:8");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(ansiTypeMap(first(tree)));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:9");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" ");

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:10");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(second(tree));

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:11");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:11");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(",");

    };

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:12");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiFunctionArgs(cddr(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansiFunctionArgs\n");

}


//Building function ansiLeaf from line: 14

void ansiLeaf(list thisNode,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansiLeaf at q/ansi.qon:14 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:15");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  display(ansiFuncMap(codeof(thisNode)));

if (globalTrace)
    fprintf(stderr, "Leaving ansiLeaf\n");

}


//Building function ansiStructGetterExpression from line: 17

void ansiStructGetterExpression(list thisNode,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansiStructGetterExpression at q/ansi.qon:17 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("structGetter"), subnameof(thisNode))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:20");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiGetStruct(thisNode, indent);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:21");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiLeaf(thisNode, indent);

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansiStructGetterExpression\n");

}


//Building function ansiExpression from line: 23

void ansiExpression(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansiExpression at q/ansi.qon:23 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isLeaf(node)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:26");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(ansiFuncMap(codeof(node)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:27");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiSubExpression(node, indent);

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansiExpression\n");

}


//Building function ansiRecurList from line: 29

void ansiRecurList(list expr,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansiRecurList at q/ansi.qon:29 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:36");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiExpression(car(expr), indent);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:38");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:39");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(", ");

      if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:39");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansiRecurList(cdr(expr), indent);

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansiRecurList\n");

}


//Building function ansiSubExpression from line: 41

void ansiSubExpression(list tree,int indent) {
  box thing = NULL;

if (globalTrace)
    fprintf(stderr, "ansiSubExpression at q/ansi.qon:41 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNode(childrenof(tree))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:47");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansiSubExpression(childrenof(tree), indent);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isLeaf(tree)) {
        if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:50");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        display(ansiFuncMap(codeof(tree)));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equal(1, listLength(childrenof(tree)))) {
          if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:54");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          display(codeof(car(childrenof(tree))));

          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxString("return"), codeof(car(childrenof(tree))))) {
            if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:58");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("");

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:59");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("()");

          };

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:61");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          thing = codeof(car(childrenof(tree)));

          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("get-struct"), thing)) {
            if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:64");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s->%s", stringify(codeof(second(childrenof(tree)))), stringify(codeof(third(childrenof(tree)))));

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("new"), thing)) {
              if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:71");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("malloc(sizeof(%s))", stringify(codeof(third(childrenof(tree)))));

            } else {
              if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:75");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s(", stringify(ansiFuncMap(codeof(car(childrenof(tree))))));

              if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:79");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              ansiRecurList(cdr(childrenof(tree)), indent);

              if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:80");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            };

          };

        };

      };

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansiSubExpression\n");

}


//Building function ansiIf from line: 81

void ansiIf(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansiIf at q/ansi.qon:81 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:83");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:84");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("if ( ");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:85");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiExpression(car(first(childrenof(node))), 0);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:86");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(") {");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:87");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiBody(second(childrenof(node)), add1(indent));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:88");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:89");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("} else {");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:90");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiBody(third(childrenof(node)), add1(indent));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:91");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:92");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("}");

if (globalTrace)
    fprintf(stderr, "Leaving ansiIf\n");

}


//Building function ansiSetStruct from line: 94

void ansiSetStruct(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansiSetStruct at q/ansi.qon:94 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:96");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:97");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->%s = ", stringify(first(codeof(node))), stringify(second(codeof(node))));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:101");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiExpression(childrenof(node), indent);

if (globalTrace)
    fprintf(stderr, "Leaving ansiSetStruct\n");

}


//Building function ansiGetStruct from line: 103

void ansiGetStruct(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansiGetStruct at q/ansi.qon:103 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:105");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:106");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->%s", stringify(first(codeof(node))), stringify(second(codeof(node))));

if (globalTrace)
    fprintf(stderr, "Leaving ansiGetStruct\n");

}


//Building function ansiSet from line: 111

void ansiSet(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansiSet at q/ansi.qon:111 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:113");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:114");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s = ", stringify(first(codeof(node))));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:115");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiExpression(childrenof(node), indent);

if (globalTrace)
    fprintf(stderr, "Leaving ansiSet\n");

}


//Building function ansiStatement from line: 117

void ansiStatement(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansiStatement at q/ansi.qon:117 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("setter"), subnameof(node))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:120");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiSet(node, indent);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("structSetter"), subnameof(node))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:123");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansiSetStruct(node, indent);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), subnameof(node))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:126");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        ansiIf(node, indent);

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("returnvoid"), subnameof(node))) {
          if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:129");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

          if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:129");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("return");

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:131");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

          if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:132");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          ansiExpression(childrenof(node), indent);

        };

      };

    };

  };

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:133");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(";\n");

if (globalTrace)
    fprintf(stderr, "Leaving ansiStatement\n");

}


//Building function ansiBody from line: 135

void ansiBody(list tree,int indent) {
  list code = NULL;

if (globalTrace)
    fprintf(stderr, "ansiBody at q/ansi.qon:135 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:142");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    code = codeof(car(tree));

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(code)) {
    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:146");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      code = car(codeof(car(tree)));

      if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:147");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\n");

      if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:148");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printIndent(indent);

      if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:149");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("if (globalTrace)   snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail(code, boxString("filename"), boxString("Unknown"))), stringify(getTagFail(code, boxString("line"), boxString("Unknown"))));

    };

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:150");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:151");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:154");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiStatement(car(tree), indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:155");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiBody(cdr(tree), indent);

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansiBody\n");

}


//Building function ansiDeclarations from line: 157

void ansiDeclarations(list decls,int indent) {
  box decl = NULL;

if (globalTrace)
    fprintf(stderr, "ansiDeclarations at q/ansi.qon:157 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:162");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:163");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s = ", stringify(ansiTypeMap(first(decl))), stringify(second(decl)));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:167");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(ansiFuncMap(third(decl)));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:168");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:169");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiDeclarations(cdr(decls), indent);

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansiDeclarations\n");

}


//Building function ansiFunction from line: 171

void ansiFunction(list node) {
  box name = NULL;

if (globalTrace)
    fprintf(stderr, "ansiFunction at q/ansi.qon:171 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:173");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = subnameof(node);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:174");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:175");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:179");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:180");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s(", stringify(ansiTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:184");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiFunctionArgs(cdr(assoc("intype", cdr(node))));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:185");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(") {");

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:186");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:187");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiDeclarations(declarationsof(node), 1);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:189");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:191");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    fprintf(stderr, \"%s at %s:%s (%%s)\\n\", caller);\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

    };

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:193");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
    };

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:198");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiBody(childrenof(node), 1);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:200");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:202");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    fprintf(stderr, \"Leaving %s\\n\");\n", stringify(name));

    };

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:204");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n");

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansiFunction\n");

}


//Building function ansiForwardDeclaration from line: 206

void ansiForwardDeclaration(list node) {
  
if (globalTrace)
    fprintf(stderr, "ansiForwardDeclaration at q/ansi.qon:206 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:211");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n%s %s(", stringify(ansiTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:215");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiFunctionArgs(cdr(assoc("intype", cdr(node))));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:216");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(");");

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansiForwardDeclaration\n");

}


//Building function ansiForwardDeclarations from line: 218

void ansiForwardDeclarations(list tree) {
  
if (globalTrace)
    fprintf(stderr, "ansiForwardDeclarations at q/ansi.qon:218 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:223");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiForwardDeclaration(car(tree));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:224");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiForwardDeclarations(cdr(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansiForwardDeclarations\n");

}


//Building function ansiFunctions from line: 226

void ansiFunctions(list tree) {
  
if (globalTrace)
    fprintf(stderr, "ansiFunctions at q/ansi.qon:226 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:230");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiFunction(car(tree));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:230");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiFunctions(cdr(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansiFunctions\n");

}


//Building function ansiIncludes from line: 231

void ansiIncludes(list nodes) {
  
if (globalTrace)
    fprintf(stderr, "ansiIncludes at q/ansi.qon:231 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:233");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\nconst char* getEnv(char* key){return getenv(key);}\n void panic(char* s){abort();exit(1);}\nint sub(int a, int b) { return a - b; }\nfloat mult(int a, int b) { return a * b; }\nint greaterthan(int a, int b) { return a > b; }\nfloat subf(float a, float b) { return a - b; }\nfloat multf(float a, float b) { return a * b; }\nint greaterthanf(float a, float b) { return a > b; }\nint equal(int a, int b) { return a == b; }\nint equalString(char* a, char* b) { return !strcmp(a,b); }\nint andBool(int a, int b) { return a == b;}\nint string_length(char* s) { return strlen(s);}\nchar* setSubString(char* target, int start,char *source){target[start]=source[0]; return target;}\nchar* sub_string(char* s, int start, int length) {\nchar* substr = calloc(length+1, 1);\nstrncpy(substr, s+start, length);\nreturn substr;\n}\n\n\n\nchar* stringConcatenate(char* a, char* b) {\nint len = strlen(a) + strlen(b) + 1;\nchar* target = calloc(len,1);\nstrncat(target, a, len);\nstrncat(target, b, len);\nreturn target;\n}\n\nchar* intToString(int a) {\nint len = 100;\nchar* target = calloc(len,1);\nsnprintf(target, 99, \"%d\", a);\nreturn target;\n}\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\nvoid * gc_malloc( unsigned int size ) {\nreturn malloc(size);\n}\n\nint* makeArray(int length) {\n    int * array = gc_malloc(length*sizeof(int));\n    return array;\n}\n\nint at(int* arr, int index) {\n  return arr[index];\n}\n\nvoid setAt(int* array, int index, int value) {\n    array[index] = value;\n}\n\nchar * read_file(char * filename) {\nchar * buffer = 0;\nlong length;\nFILE * f = fopen (filename, \"rb\");\n\nif (f)\n{\n  fseek (f, 0, SEEK_END);\n  length = ftell (f);\n  fseek (f, 0, SEEK_SET);\n  buffer = calloc (length+1,1);\n  if (buffer == NULL) {\n  printf(\"Malloc failed!\\n\");\n  exit(1);\n}\n  if (buffer)\n  {\n    fread (buffer, 1, length, f);\n  }\n  fclose (f);\n}\nreturn buffer;\n}\n\n\nvoid write_file (char * filename, char * data) {\nFILE *f = fopen(filename, \"w\");\nif (f == NULL)\n{\n    printf(\"Error opening file!\");\n    exit(1);\n}\n\nfprintf(f, \"%s\", data);\n\nfclose(f);\n}\n\nchar* getStringArray(int index, char** strs) {\nreturn strs[index];\n}\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\n\nint main( int argc, char *argv[] )  {\n  globalArgs = argv;\n  globalArgsCount = argc;\n  caller=calloc(1024,1);\n\n  return start();\n\n}\n\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:236");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "char * character(int num) { char *string = malloc(2); if (!string) return 0; string[0] = num; string[1] = 0; return string; }");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:237");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }");

if (globalTrace)
    fprintf(stderr, "Leaving ansiIncludes\n");

}


//Building function ansiTypeDecl from line: 240

void ansiTypeDecl(list l) {
  
if (globalTrace)
    fprintf(stderr, "ansiTypeDecl at q/ansi.qon:240 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 2)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:244");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:245");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s %s;\n", stringify(second(l)), stringify(ansiTypeMap(listLast(l))), stringify(first(l)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:251");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:252");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s;\n", stringify(ansiTypeMap(listLast(l))), stringify(car(l)));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansiTypeDecl\n");

}


//Building function ansiStructComponents from line: 257

void ansiStructComponents(list node) {
  
if (globalTrace)
    fprintf(stderr, "ansiStructComponents at q/ansi.qon:257 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:261");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiTypeDecl(car(node));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:261");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiStructComponents(cdr(node));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansiStructComponents\n");

}


//Building function ansiStruct from line: 263

void ansiStruct(list node) {
  
if (globalTrace)
    fprintf(stderr, "ansiStruct at q/ansi.qon:263 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:264");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiStructComponents(cdr(car(node)));

if (globalTrace)
    fprintf(stderr, "Leaving ansiStruct\n");

}


//Building function ansiTypeMap from line: 266

box ansiTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    fprintf(stderr, "ansiTypeMap at q/ansi.qon:266 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:269");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:275");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cdr(assoc(stringify(aSym), symMap)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:276");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym);

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansiTypeMap\n");

}


//Building function ansiFuncMap from line: 278

box ansiFuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    fprintf(stderr, "ansiFuncMap at q/ansi.qon:278 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:283");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), NULL)))))));

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym), symMap))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:305");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cdr(assoc(stringify(aSym), symMap)));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:306");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(aSym);

    };

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:307");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym);

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansiFuncMap\n");

}


//Building function ansiType from line: 309

void ansiType(list node) {
  
if (globalTrace)
    fprintf(stderr, "ansiType at q/ansi.qon:309 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(subnameof(node), boxString("struct"))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:313");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\ntypedef struct %s {\n", stringify(first(codeof(node))));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:314");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiStruct(cdr(codeof(node)));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:315");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n} %s;\n", stringify(first(codeof(node))));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:316");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("typedef ");

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:316");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiTypeDecl(codeof(node));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansiType\n");

}


//Building function ansiTypes from line: 319

void ansiTypes(list nodes) {
  
if (globalTrace)
    fprintf(stderr, "ansiTypes at q/ansi.qon:319 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:323");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiType(car(nodes));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:323");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiTypes(cdr(nodes));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansiTypes\n");

}


//Building function ansiCompile from line: 329

void ansiCompile(char* filename) {
  char* programStr = "";
list tree = NULL;
list program = NULL;

if (globalTrace)
    fprintf(stderr, "ansiCompile at q/ansi.qon:329 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:333");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("//Scanning file...%s\n", filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:334");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:335");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("//Building sexpr\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:336");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:337");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), NULL)));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:341");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("//Building AST\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:343");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:352");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("//Merging ASTs\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:353");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = mergeIncludes(program);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:354");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("//Printing program\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:355");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiIncludes(cdr(assoc("includes", program)));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:356");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiTypes(childrenof(cdr(assoc("types", program))));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:357");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("Box* globalStackTrace = NULL;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:358");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:360");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiForwardDeclarations(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:362");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n//End forward declarations\n\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:363");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi.qon:365");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n");

if (globalTrace)
    fprintf(stderr, "Leaving ansiCompile\n");

}


//Building function ansi2displays from line: 5

void ansi2displays(char* s) {
  
if (globalTrace)
    fprintf(stderr, "ansi2displays at q/ansi2.qon:5 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:7");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", s);

if (globalTrace)
    fprintf(stderr, "Leaving ansi2displays\n");

}


//Building function ansi2FunctionArgs from line: 11

void ansi2FunctionArgs(list tree) {
  
if (globalTrace)
    fprintf(stderr, "ansi2FunctionArgs at q/ansi2.qon:11 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(stringify(first(tree)), "...")) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:17");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("...");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:19");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(ansi2TypeMap(first(tree)));

      if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:20");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi2displays(" ");

      if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:21");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(second(tree));

    };

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree))) {
    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:23");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi2displays(", ");

    };

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:24");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2FunctionArgs(cddr(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi2FunctionArgs\n");

}


//Building function ansi2Expression from line: 28

void ansi2Expression(list tree,int indent) {
  list thing = NULL;

if (globalTrace)
    fprintf(stderr, "ansi2Expression at q/ansi2.qon:28 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(tree)) {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equal(1, listLength(tree))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:39");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(car(tree));

      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("return"), car(tree))) {
      } else {
        if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:46");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        ansi2displays("()");

      };

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:50");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      thing = first(tree);

      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxSymbol("get-struct"), thing)) {
        if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:55");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s->%s", stringify(second(tree)), stringify(third(tree)));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxSymbol("new"), thing)) {
          if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:64");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("malloc(sizeof(%s))", stringify(third(tree)));

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("passthrough"), thing)) {
            if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:72");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s", stringify(second(tree)));

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("binop"), thing)) {
              if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:80");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("(");

              if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:81");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              ansi2Expression(third(tree), indent);

              if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:82");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(" %s ", stringify(second(tree)));

              if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:85");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              ansi2Expression(fourth(tree), indent);

              if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:86");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            } else {
              if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:91");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s(", stringify(ansi2FuncMap(car(tree))));

              if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:95");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              ansi2RecurList(cdr(tree), indent);

              if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:96");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            };

          };

        };

      };

    };

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:105");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(ansi2FuncMap(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi2Expression\n");

}


//Building function ansi2RecurList from line: 108

void ansi2RecurList(list expr,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansi2RecurList at q/ansi2.qon:108 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:115");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Expression(car(expr), indent);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:117");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi2displays("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:118");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi2displays(", ");

      if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:118");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi2RecurList(cdr(expr), indent);

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi2RecurList\n");

}


//Building function ansi2If from line: 125

void ansi2If(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansi2If at q/ansi2.qon:125 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:127");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:128");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2displays("if ( ");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:129");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2Expression(second(node), 0);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:130");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2displays(") {");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:131");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2Body(cdr(third(node)), add1(indent));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:132");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:133");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2displays("} else {");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:134");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2Body(cdr(fourth(node)), add1(indent));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:135");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:136");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2displays("}");

if (globalTrace)
    fprintf(stderr, "Leaving ansi2If\n");

}


//Building function ansi2SetStruct from line: 138

void ansi2SetStruct(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansi2SetStruct at q/ansi2.qon:138 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:140");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:141");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->%s = ", stringify(second(node)), stringify(third(node)));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:145");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2Expression(fourth(node), indent);

if (globalTrace)
    fprintf(stderr, "Leaving ansi2SetStruct\n");

}


//Building function ansi2GetStruct from line: 147

void ansi2GetStruct(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansi2GetStruct at q/ansi2.qon:147 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:149");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:150");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->%s", stringify(first(node)), stringify(second(node)));

if (globalTrace)
    fprintf(stderr, "Leaving ansi2GetStruct\n");

}


//Building function ansi2Set from line: 155

void ansi2Set(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansi2Set at q/ansi2.qon:155 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:157");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:158");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2Expression(first(cdr(node)), indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:159");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(" = ");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:160");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2Expression(third(node), indent);

if (globalTrace)
    fprintf(stderr, "Leaving ansi2Set\n");

}


//Building function ansi2Return from line: 162

void ansi2Return(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansi2Return at q/ansi2.qon:162 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:164");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(listLength(node), 1)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:166");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2displays("return;");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:168");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2displays("return ");

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:169");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Expression(cadr(node), indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:170");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2displays(";");

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi2Return\n");

}


//Building function ansi2Statement from line: 173

void ansi2Statement(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansi2Statement at q/ansi2.qon:173 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("set"), first(node))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:176");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Set(node, indent);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("set-struct"), first(node))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:179");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi2SetStruct(node, indent);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), first(node))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:182");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        ansi2If(node, indent);

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("return"), first(node))) {
          if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:185");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          ansi2Return(node, indent);

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:187");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

          if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:188");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          ansi2Expression(node, indent);

        };

      };

    };

  };

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:189");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2displays(";\n");

if (globalTrace)
    fprintf(stderr, "Leaving ansi2Statement\n");

}


//Building function ansi2Body from line: 191

void ansi2Body(list tree,int indent) {
  list code = NULL;

if (globalTrace)
    fprintf(stderr, "ansi2Body at q/ansi2.qon:191 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:196");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    code = tree;

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(code)) {
    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:200");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      code = car(tree);

      if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:201");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), stringify(getTagFail(car(code), boxString("line"), boxString("Line missing"))));

    };

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:202");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:203");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:206");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Statement(code, indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:207");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Body(cdr(tree), indent);

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi2Body\n");

}


//Building function ansi2Declarations from line: 209

void ansi2Declarations(list decls,int indent) {
  box decl = NULL;

if (globalTrace)
    fprintf(stderr, "ansi2Declarations at q/ansi2.qon:209 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:214");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:215");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s = ", stringify(ansi2TypeMap(first(decl))), stringify(second(decl)));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:219");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Expression(third(decl), indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:220");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:221");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Declarations(cdr(decls), indent);

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi2Declarations\n");

}


//Building function ansi2Function from line: 223

void ansi2Function(list node) {
  box name = NULL;

if (globalTrace)
    fprintf(stderr, "ansi2Function at q/ansi2.qon:223 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:225");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = second(node);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:226");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:227");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:231");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:232");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s(", stringify(ansi2TypeMap(first(node))), stringify(second(node)));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:236");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2FunctionArgs(third(node));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:237");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(") {");

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:238");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:239");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Declarations(cdr(fourth(node)), 1);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:241");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:243");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    printf(\"%s at %s:%s (%%s)\\n\", caller);\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

    };

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:245");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
    };

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:252");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Body(cdr(fifth(node)), 1);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:254");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:256");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    printf(\"Leaving %s\\n\");\n", stringify(name));

    };

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:258");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n");

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi2Function\n");

}


//Building function ansi2ForwardDeclaration from line: 260

void ansi2ForwardDeclaration(list node) {
  
if (globalTrace)
    fprintf(stderr, "ansi2ForwardDeclaration at q/ansi2.qon:260 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:263");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n%s %s(", stringify(ansi2TypeMap(first(node))), stringify(second(node)));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:267");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2FunctionArgs(third(node));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:268");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2displays(");");

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi2ForwardDeclaration\n");

}


//Building function ansi2ForwardDeclarations from line: 270

void ansi2ForwardDeclarations(list tree) {
  
if (globalTrace)
    fprintf(stderr, "ansi2ForwardDeclarations at q/ansi2.qon:270 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:273");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2ForwardDeclaration(car(tree));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:274");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2ForwardDeclarations(cdr(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi2ForwardDeclarations\n");

}


//Building function ansi2Functions from line: 276

void ansi2Functions(list tree) {
  
if (globalTrace)
    fprintf(stderr, "ansi2Functions at q/ansi2.qon:276 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:279");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Function(car(tree));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:279");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Functions(cdr(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi2Functions\n");

}


//Building function ansi2Includes from line: 282

void ansi2Includes(list nodes) {
  
if (globalTrace)
    fprintf(stderr, "ansi2Includes at q/ansi2.qon:282 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:284");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\nconst char* getEnv(char* key){return getenv(key);}\n void panic(char* s){abort();exit(1);}\nint sub(int a, int b) { return a - b; }\nfloat mult(int a, int b) { return a * b; }\nint greaterthan(int a, int b) { return a > b; }\nfloat subf(float a, float b) { return a - b; }\nfloat multf(float a, float b) { return a * b; }\nint greaterthanf(float a, float b) { return a > b; }\nint equal(int a, int b) { return a == b; }\nint equalString(char* a, char* b) { return !strcmp(a,b); }\nint andBool(int a, int b) { return a == b;}\nint string_length(char* s) { return strlen(s);}\nchar* setSubString(char* target, int start,char *source){target[start]=source[0]; return target;}\nchar* sub_string(char* s, int start, int length) {\nchar* substr = calloc(length+1, 1);\nstrncpy(substr, s+start, length);\nreturn substr;\n}\n\n\n\nchar* stringConcatenate(char* a, char* b) {\nint len = strlen(a) + strlen(b) + 1;\nchar* target = calloc(len,1);\nstrncat(target, a, len);\nstrncat(target, b, len);\nreturn target;\n}\n\nchar* intToString(int a) {\nint len = 100;\nchar* target = calloc(len,1);\nsnprintf(target, 99, \"%d\", a);\nreturn target;\n}\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\nvoid * gc_malloc( unsigned int size ) {\nreturn malloc( size);\n}\n\nint* makeArray(int length) {\n    int * array = gc_malloc(length*sizeof(int));\n    return array;\n}\n\nint at(int* arr, int index) {\n  return arr[index];\n}\n\nvoid setAt(int* array, int index, int value) {\n    array[index] = value;\n}\n\nchar * read_file(char * filename) {\nchar * buffer = 0;\nlong length;\nFILE * f = fopen (filename, \"rb\");\n\nif (f)\n{\n  fseek (f, 0, SEEK_END);\n  length = ftell (f);\n  fseek (f, 0, SEEK_SET);\n  buffer = malloc (length);\n  if (buffer == NULL) {\n  printf(\"Malloc failed!\\n\");\n  exit(1);\n}\n  if (buffer)\n  {\n    fread (buffer, 1, length, f);\n  }\n  fclose (f);\n}\nreturn buffer;\n}\n\n\nvoid write_file (char * filename, char * data) {\nFILE *f = fopen(filename, \"w\");\nif (f == NULL)\n{\n    printf(\"Error opening file!\");\n    exit(1);\n}\n\nfprintf(f, \"%s\", data);\n\nfclose(f);\n}\n\nchar* getStringArray(int index, char** strs) {\nreturn strs[index];\n}\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\n\nint main( int argc, char *argv[] )  {\n  globalArgs = argv;\n  globalArgsCount = argc;\n  caller=calloc(1024,1);\n\n  return start();\n\n}\n\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:287");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "char * character(int num) { char *string = malloc(2); if (!string) return 0; string[0] = num; string[1] = 0; return string; }");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:287");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n");

if (globalTrace)
    fprintf(stderr, "Leaving ansi2Includes\n");

}


//Building function ansi2TypeDecl from line: 290

void ansi2TypeDecl(list l) {
  
if (globalTrace)
    fprintf(stderr, "ansi2TypeDecl at q/ansi2.qon:290 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 2)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:294");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:295");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s %s;\n", stringify(second(l)), stringify(ansi2TypeMap(listLast(l))), stringify(first(l)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:301");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:302");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s;\n", stringify(ansi2TypeMap(listLast(l))), stringify(car(l)));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi2TypeDecl\n");

}


//Building function ansi2StructComponents from line: 307

void ansi2StructComponents(list node) {
  
if (globalTrace)
    fprintf(stderr, "ansi2StructComponents at q/ansi2.qon:307 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:311");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2TypeDecl(car(node));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:311");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2StructComponents(cdr(node));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi2StructComponents\n");

}


//Building function ansi2Struct from line: 313

void ansi2Struct(list node) {
  
if (globalTrace)
    fprintf(stderr, "ansi2Struct at q/ansi2.qon:313 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:314");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2StructComponents(cdr(node));

if (globalTrace)
    fprintf(stderr, "Leaving ansi2Struct\n");

}


//Building function ansi2TypeMap from line: 316

box ansi2TypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    fprintf(stderr, "ansi2TypeMap at q/ansi2.qon:316 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:319");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:325");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cdr(assoc(stringify(aSym), symMap)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:326");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym);

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi2TypeMap\n");

}


//Building function ansi2FuncMap from line: 328

box ansi2FuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    fprintf(stderr, "ansi2FuncMap at q/ansi2.qon:328 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:333");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), NULL)))))));

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym), symMap))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:355");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cdr(assoc(stringify(aSym), symMap)));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:356");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(aSym);

    };

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:357");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym);

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi2FuncMap\n");

}


//Building function ansi2Type from line: 359

void ansi2Type(list node) {
  
if (globalTrace)
    fprintf(stderr, "ansi2Type at q/ansi2.qon:359 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(second(node))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:363");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\ntypedef struct %s {\n", stringify(first(node)));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:364");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Struct(second(node));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:365");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n} %s;\n", stringify(first(node)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:366");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2displays("typedef ");

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:366");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2TypeDecl(node);

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi2Type\n");

}


//Building function ansi2Types from line: 369

void ansi2Types(list nodes) {
  
if (globalTrace)
    fprintf(stderr, "ansi2Types at q/ansi2.qon:369 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:373");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Type(car(nodes));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:373");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi2Types(cdr(nodes));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi2Types\n");

}


//Building function ansi2Compile from line: 379

void ansi2Compile(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    fprintf(stderr, "ansi2Compile at q/ansi2.qon:379 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:384");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  qlog("//Scanning file...%s\n", filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:386");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:387");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  qlog("//Building sexpr\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:389");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:390");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:391");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:392");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:396");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  qlog("//Printing program\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:398");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2Includes(cdr(first(tree)));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:399");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2Types(cdr(second(tree)));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:402");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2displays("Box* globalStackTrace = NULL;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:403");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2displays("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:405");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2ForwardDeclarations(cdr(third(tree)));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:406");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2displays("\n\n//End forward declarations\n\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:407");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2Functions(cdr(third(tree)));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi2.qon:408");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi2displays("\n");

if (globalTrace)
    fprintf(stderr, "Leaving ansi2Compile\n");

}


//Building function ansi3displays from line: 5

void ansi3displays(char* s) {
  
if (globalTrace)
    fprintf(stderr, "ansi3displays at q/ansi3.qon:5 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:7");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", s);

if (globalTrace)
    fprintf(stderr, "Leaving ansi3displays\n");

}


//Building function ansi3FunctionArgs from line: 11

void ansi3FunctionArgs(list tree) {
  
if (globalTrace)
    fprintf(stderr, "ansi3FunctionArgs at q/ansi3.qon:11 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(stringify(first(tree)), "...")) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:17");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("...");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:19");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(ansi3TypeMap(first(tree)));

      if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:20");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi3displays(" ");

      if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:21");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(second(tree));

    };

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree))) {
    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:23");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi3displays(", ");

    };

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:24");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3FunctionArgs(cddr(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi3FunctionArgs\n");

}


//Building function ansi3Expression from line: 28

void ansi3Expression(list tree,int indent) {
  list thing = NULL;

if (globalTrace)
    fprintf(stderr, "ansi3Expression at q/ansi3.qon:28 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(tree)) {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equal(1, listLength(tree))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:39");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(car(tree));

      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("return"), car(tree))) {
      } else {
        if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:46");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        ansi3displays("()");

      };

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:50");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      thing = first(tree);

      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxSymbol("get-struct"), thing)) {
        if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:55");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s->%s", stringify(second(tree)), stringify(third(tree)));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxSymbol("new"), thing)) {
          if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:64");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("malloc(sizeof(%s))", stringify(third(tree)));

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("passthrough"), thing)) {
            if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:72");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s", stringify(second(tree)));

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("binop"), thing)) {
              if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:80");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("(");

              if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:81");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              ansi3Expression(third(tree), indent);

              if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:82");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(" %s ", stringify(second(tree)));

              if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:85");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              ansi3Expression(fourth(tree), indent);

              if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:86");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            } else {
              if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:91");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s(", stringify(ansi3FuncMap(car(tree))));

              if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:95");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              ansi3RecurList(cdr(tree), indent);

              if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:96");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            };

          };

        };

      };

    };

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:105");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(ansi3FuncMap(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi3Expression\n");

}


//Building function ansi3RecurList from line: 108

void ansi3RecurList(list expr,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansi3RecurList at q/ansi3.qon:108 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:115");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Expression(car(expr), indent);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:117");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi3displays("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:118");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi3displays(", ");

      if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:118");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi3RecurList(cdr(expr), indent);

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi3RecurList\n");

}


//Building function ansi3If from line: 125

void ansi3If(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansi3If at q/ansi3.qon:125 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:127");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:128");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("if ( ");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:129");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Expression(second(node), 0);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:130");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays(") {");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:131");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Body(cdr(third(node)), add1(indent));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:132");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:133");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("} else {");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:134");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Body(cdr(fourth(node)), add1(indent));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:135");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:136");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("}");

if (globalTrace)
    fprintf(stderr, "Leaving ansi3If\n");

}


//Building function ansi3SetStruct from line: 138

void ansi3SetStruct(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansi3SetStruct at q/ansi3.qon:138 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:140");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:141");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->%s = ", stringify(second(node)), stringify(third(node)));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:145");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Expression(fourth(node), indent);

if (globalTrace)
    fprintf(stderr, "Leaving ansi3SetStruct\n");

}


//Building function ansi3GetStruct from line: 147

void ansi3GetStruct(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansi3GetStruct at q/ansi3.qon:147 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:149");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:150");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->%s", stringify(first(node)), stringify(second(node)));

if (globalTrace)
    fprintf(stderr, "Leaving ansi3GetStruct\n");

}


//Building function ansi3Set from line: 155

void ansi3Set(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansi3Set at q/ansi3.qon:155 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:157");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:158");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Expression(first(cdr(node)), indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:159");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(" = ");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:160");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Expression(third(node), indent);

if (globalTrace)
    fprintf(stderr, "Leaving ansi3Set\n");

}


//Building function ansi3Return from line: 162

void ansi3Return(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansi3Return at q/ansi3.qon:162 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:164");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(listLength(node), 1)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:166");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3displays("return;");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:168");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3displays("return ");

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:169");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Expression(cadr(node), indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:170");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3displays(";");

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi3Return\n");

}


//Building function ansi3Statement from line: 173

void ansi3Statement(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "ansi3Statement at q/ansi3.qon:173 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("set"), first(node))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:176");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Set(node, indent);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("set-struct"), first(node))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:179");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansi3SetStruct(node, indent);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), first(node))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:182");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        ansi3If(node, indent);

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("return"), first(node))) {
          if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:185");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          ansi3Return(node, indent);

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:187");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

          if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:188");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          ansi3Expression(node, indent);

        };

      };

    };

  };

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:189");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays(";\n");

if (globalTrace)
    fprintf(stderr, "Leaving ansi3Statement\n");

}


//Building function ansi3Body from line: 191

void ansi3Body(list tree,int indent) {
  list code = NULL;

if (globalTrace)
    fprintf(stderr, "ansi3Body at q/ansi3.qon:191 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:196");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    code = tree;

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(code)) {
    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:200");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      code = car(tree);

      if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:201");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), stringify(getTagFail(car(code), boxString("line"), boxString("Line missing"))));

    };

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:202");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:203");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:206");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Statement(code, indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:207");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Body(cdr(tree), indent);

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi3Body\n");

}


//Building function ansi3Declarations from line: 209

void ansi3Declarations(list decls,int indent) {
  box decl = NULL;

if (globalTrace)
    fprintf(stderr, "ansi3Declarations at q/ansi3.qon:209 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:214");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:215");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s = ", stringify(ansi3TypeMap(first(decl))), stringify(second(decl)));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:219");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Expression(third(decl), indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:220");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:221");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Declarations(cdr(decls), indent);

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi3Declarations\n");

}


//Building function ansi3Function from line: 223

void ansi3Function(list node) {
  box name = NULL;

if (globalTrace)
    fprintf(stderr, "ansi3Function at q/ansi3.qon:223 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:225");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = second(node);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:226");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:227");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:231");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:232");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s(", stringify(ansi3TypeMap(first(node))), stringify(second(node)));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:236");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3FunctionArgs(third(node));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:237");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(") {");

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:238");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:239");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Declarations(cdr(fourth(node)), 1);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:241");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:243");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    printf(\"%s at %s:%s (%%s)\\n\", caller);\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

    };

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:245");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
    };

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:252");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Body(cdr(fifth(node)), 1);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:254");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:256");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    printf(\"Leaving %s\\n\");\n", stringify(name));

    };

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:258");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n");

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi3Function\n");

}


//Building function ansi3ForwardDeclaration from line: 260

void ansi3ForwardDeclaration(list node) {
  
if (globalTrace)
    fprintf(stderr, "ansi3ForwardDeclaration at q/ansi3.qon:260 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:263");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n%s %s(", stringify(ansi3TypeMap(first(node))), stringify(second(node)));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:267");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3FunctionArgs(third(node));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:268");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3displays(");");

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi3ForwardDeclaration\n");

}


//Building function ansi3ForwardDeclarations from line: 270

void ansi3ForwardDeclarations(list tree) {
  
if (globalTrace)
    fprintf(stderr, "ansi3ForwardDeclarations at q/ansi3.qon:270 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:273");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3ForwardDeclaration(car(tree));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:274");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3ForwardDeclarations(cdr(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi3ForwardDeclarations\n");

}


//Building function ansi3Functions from line: 276

void ansi3Functions(list tree) {
  
if (globalTrace)
    fprintf(stderr, "ansi3Functions at q/ansi3.qon:276 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:279");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Function(car(tree));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:279");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Functions(cdr(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi3Functions\n");

}


//Building function ansi3Includes from line: 282

void ansi3Includes(list nodes) {
  
if (globalTrace)
    fprintf(stderr, "ansi3Includes at q/ansi3.qon:282 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:284");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\n\nvoid setAt(int* array, int index, int value) {\n    array[index] = value;\n}\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\n\nint main( int argc, char *argv[] )  {\n  globalArgs = argv;\n  globalArgsCount = argc;\n  caller=calloc(1024,1);\n\n  return start();\n\n}\n\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:287");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n");

if (globalTrace)
    fprintf(stderr, "Leaving ansi3Includes\n");

}


//Building function ansi3TypeDecl from line: 290

void ansi3TypeDecl(list l) {
  
if (globalTrace)
    fprintf(stderr, "ansi3TypeDecl at q/ansi3.qon:290 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 2)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:294");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:295");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s %s;\n", stringify(second(l)), stringify(ansi3TypeMap(listLast(l))), stringify(first(l)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:301");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:302");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s;\n", stringify(ansi3TypeMap(listLast(l))), stringify(car(l)));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi3TypeDecl\n");

}


//Building function ansi3StructComponents from line: 307

void ansi3StructComponents(list node) {
  
if (globalTrace)
    fprintf(stderr, "ansi3StructComponents at q/ansi3.qon:307 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:311");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3TypeDecl(car(node));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:311");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3StructComponents(cdr(node));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi3StructComponents\n");

}


//Building function ansi3Struct from line: 313

void ansi3Struct(list node) {
  
if (globalTrace)
    fprintf(stderr, "ansi3Struct at q/ansi3.qon:313 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:314");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3StructComponents(cdr(node));

if (globalTrace)
    fprintf(stderr, "Leaving ansi3Struct\n");

}


//Building function ansi3TypeMap from line: 316

box ansi3TypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    fprintf(stderr, "ansi3TypeMap at q/ansi3.qon:316 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:319");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:325");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cdr(assoc(stringify(aSym), symMap)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:326");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym);

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi3TypeMap\n");

}


//Building function ansi3FuncMap from line: 328

box ansi3FuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    fprintf(stderr, "ansi3FuncMap at q/ansi3.qon:328 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:333");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), NULL)))))));

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym), symMap))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:355");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cdr(assoc(stringify(aSym), symMap)));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:356");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(aSym);

    };

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:357");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym);

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi3FuncMap\n");

}


//Building function ansi3Type from line: 359

void ansi3Type(list node) {
  
if (globalTrace)
    fprintf(stderr, "ansi3Type at q/ansi3.qon:359 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(second(node))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:363");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\ntypedef struct %s {\n", stringify(first(node)));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:364");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Struct(second(node));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:365");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n} %s;\n", stringify(first(node)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:366");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3displays("typedef ");

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:366");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3TypeDecl(node);

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi3Type\n");

}


//Building function ansi3Types from line: 369

void ansi3Types(list nodes) {
  
if (globalTrace)
    fprintf(stderr, "ansi3Types at q/ansi3.qon:369 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:373");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Type(car(nodes));

    if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:373");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansi3Types(cdr(nodes));

  };

if (globalTrace)
    fprintf(stderr, "Leaving ansi3Types\n");

}


//Building function ansi3Compile from line: 379

void ansi3Compile(char* filename) {
  list tree = NULL;
list replace = NULL;

if (globalTrace)
    fprintf(stderr, "ansi3Compile at q/ansi3.qon:379 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:384");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  qlog("//Scanning file...%s\n", filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:386");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:387");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  qlog("//Building sexpr\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:389");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:390");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:391");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:392");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:396");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  qlog("//Printing program\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:398");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Includes(cdr(first(tree)));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:399");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Types(cdr(second(tree)));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:402");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("Box* globalStackTrace = NULL;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:403");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:405");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3ForwardDeclarations(cdr(third(tree)));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:406");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("\n\n//End forward declarations\n\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:407");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3Functions(cdr(third(tree)));

  if (globalTrace)   snprintf(caller, 1024, "from q/ansi3.qon:408");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansi3displays("\n");

if (globalTrace)
    fprintf(stderr, "Leaving ansi3Compile\n");

}


//Building function test0 from line: 10

void test0() {
  
if (globalTrace)
    fprintf(stderr, "test0 at q/tests.qon:10 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(stringify(boxString("hello")), stringify(boxString("hello")))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:15");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("0.  pass string compare works\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:16");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("0.  pass string compare fails\n");

  };

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(stringify(boxString("hello")), stringify(boxSymbol("hello")))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:20");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("0.  pass string compare works\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:21");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("0.  pass string compare fails\n");

  };

if (globalTrace)
    fprintf(stderr, "Leaving test0\n");

}


//Building function test1 from line: 23

void test1() {
  
if (globalTrace)
    fprintf(stderr, "test1 at q/tests.qon:23 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:24");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("1.  pass Function call and print work\n");

if (globalTrace)
    fprintf(stderr, "Leaving test1\n");

}


//Building function test2_do from line: 27

void test2_do(char* message) {
  
if (globalTrace)
    fprintf(stderr, "test2_do at q/tests.qon:27 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:30");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("2.  pass Function call with arg works: %s\n", message);

if (globalTrace)
    fprintf(stderr, "Leaving test2_do\n");

}


//Building function test2 from line: 31

void test2() {
  
if (globalTrace)
    fprintf(stderr, "test2 at q/tests.qon:31 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:31");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  test2_do("This is the argument");

if (globalTrace)
    fprintf(stderr, "Leaving test2\n");

}


//Building function test3_do from line: 33

void test3_do(int b,char* c) {
  
if (globalTrace)
    fprintf(stderr, "test3_do at q/tests.qon:33 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:37");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("3.1 pass Two arg call, first arg: %d\n", b);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:38");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("3.2 pass Two arg call, second arg: %s\n", c);

if (globalTrace)
    fprintf(stderr, "Leaving test3_do\n");

}


//Building function test3 from line: 39

void test3() {
  
if (globalTrace)
    fprintf(stderr, "test3 at q/tests.qon:39 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:39");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  test3_do(42, "Fourty-two");

if (globalTrace)
    fprintf(stderr, "Leaving test3\n");

}


//Building function test4_do from line: 40

char* test4_do() {
  
if (globalTrace)
    fprintf(stderr, "test4_do at q/tests.qon:40 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:40");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return("pass Return works");

if (globalTrace)
    fprintf(stderr, "Leaving test4_do\n");

}


//Building function returnThis from line: 42

char* returnThis(char* returnMessage) {
  
if (globalTrace)
    fprintf(stderr, "returnThis at q/tests.qon:42 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:45");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(returnMessage);

if (globalTrace)
    fprintf(stderr, "Leaving returnThis\n");

}


//Building function test4 from line: 47

void test4() {
  char* message = "fail";

if (globalTrace)
    fprintf(stderr, "test4 at q/tests.qon:47 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:50");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  message = test4_do();

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:50");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("4.  %s\n", message);

if (globalTrace)
    fprintf(stderr, "Leaving test4\n");

}


//Building function test5 from line: 52

void test5() {
  char* message = "fail";

if (globalTrace)
    fprintf(stderr, "test5 at q/tests.qon:52 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:56");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  message = returnThis("pass return passthrough string");

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:57");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("5.  %s\n", message);

if (globalTrace)
    fprintf(stderr, "Leaving test5\n");

}


//Building function test6 from line: 59

void test6() {
  
if (globalTrace)
    fprintf(stderr, "test6 at q/tests.qon:59 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:63");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( true) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:64");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("6.  pass If statement works\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:65");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("6.  fail If statement works\n");

  };

if (globalTrace)
    fprintf(stderr, "Leaving test6\n");

}


//Building function test7_do from line: 67

int test7_do(int count) {
  
if (globalTrace)
    fprintf(stderr, "test7_do at q/tests.qon:67 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:71");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  count = sub(count, 1);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(count, 0)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:72");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    count = test7_do(count);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:72");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(count);

  };

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:73");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(count);

if (globalTrace)
    fprintf(stderr, "Leaving test7_do\n");

}


//Building function test7 from line: 75

void test7() {
  
if (globalTrace)
    fprintf(stderr, "test7 at q/tests.qon:75 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(0, test7_do(10))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:80");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("7.  pass count works\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:81");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("7.  fail count fails\n");

  };

if (globalTrace)
    fprintf(stderr, "Leaving test7\n");

}


//Building function beer from line: 83

void beer() {
  
if (globalTrace)
    fprintf(stderr, "beer at q/tests.qon:83 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:87");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%d bottle of beer on the wall, %d bottle of beer.  Take one down, pass it round, no bottles of beer on the wall\n", 1, 1);

if (globalTrace)
    fprintf(stderr, "Leaving beer\n");

}


//Building function plural from line: 92

char* plural(int num) {
  
if (globalTrace)
    fprintf(stderr, "plural at q/tests.qon:92 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(num, 1)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:95");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return("");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:95");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return("s");

  };

if (globalTrace)
    fprintf(stderr, "Leaving plural\n");

}


//Building function beers from line: 97

int beers(int count) {
  int newcount = 0;

if (globalTrace)
    fprintf(stderr, "beers at q/tests.qon:97 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:101");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newcount = sub(count, 1);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:102");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%d bottle%s of beer on the wall, %d bottle%s of beer.  Take one down, pass it round, %d bottle%s of beer on the wall\n", count, plural(count), count, plural(count), newcount, plural(newcount));

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(count, 1)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:110");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    count = beers(newcount);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:110");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(count);

  };

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:111");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(0);

if (globalTrace)
    fprintf(stderr, "Leaving beers\n");

}


//Building function test8 from line: 113

void test8() {
  
if (globalTrace)
    fprintf(stderr, "test8 at q/tests.qon:113 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(sub(sub(2, 1), sub(3, 1)), -1)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:118");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("8.  pass Nested expressions work\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:119");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("8.  fail Nested expressions don't work\n");

  };

if (globalTrace)
    fprintf(stderr, "Leaving test8\n");

}


//Building function test9 from line: 121

void test9() {
  int answer = -999999;

if (globalTrace)
    fprintf(stderr, "test9 at q/tests.qon:121 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:125");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  answer = sub(sub(20, 1), sub(3, 1));

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(answer, 17)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:127");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.  pass arithmetic works\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:128");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.  fail arithmetic\n");

  };

if (globalTrace)
    fprintf(stderr, "Leaving test9\n");

}


//Building function test10 from line: 130

void test10() {
  char* testString = "This is a test string";

if (globalTrace)
    fprintf(stderr, "test10 at q/tests.qon:130 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(testString, unBoxString(car(cons(boxString(testString), NULL))))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:137");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("10. pass cons and car work\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:138");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("10. fail cons and car fail\n");

  };

if (globalTrace)
    fprintf(stderr, "Leaving test10\n");

}


//Building function test12 from line: 140

void test12() {
  box b = NULL;

if (globalTrace)
    fprintf(stderr, "test12 at q/tests.qon:140 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:144");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = malloc(sizeof(Box));

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:145");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->str = "12. pass structure accessors\n";

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:146");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", b->str);

if (globalTrace)
    fprintf(stderr, "Leaving test12\n");

}


//Building function test13 from line: 148

void test13() {
  char* testString = "Hello from the filesystem!";
char* contents = "";

if (globalTrace)
    fprintf(stderr, "test13 at q/tests.qon:148 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:154");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  write_file("test.txt", testString);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:155");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  contents = read_file("test.txt");

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(testString, contents)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:157");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("13. pass Read and write files\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:159");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("13. fail Read and write files\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:160");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Expected: %s\n", testString);

    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:161");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Got: %s\n", contents);

  };

if (globalTrace)
    fprintf(stderr, "Leaving test13\n");

}


//Building function test15 from line: 164

void test15() {
  char* a = "hello";
char* b = " world";
char* c = "";

if (globalTrace)
    fprintf(stderr, "test15 at q/tests.qon:164 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:167");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  c = stringConcatenate(a, b);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(c, "hello world")) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:169");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("15. pass String concatenate\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:170");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("15. fail String concatenate\n");

  };

if (globalTrace)
    fprintf(stderr, "Leaving test15\n");

}


//Building function test16 from line: 172

void test16() {
  list assocCell1 = NULL;
list assList = NULL;
list assocCell2 = NULL;
list assocCell3 = NULL;

if (globalTrace)
    fprintf(stderr, "test16 at q/tests.qon:172 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:179");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assocCell1 = cons(boxString("Hello"), boxString("world"));

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:180");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assocCell2 = cons(boxString("goodnight"), boxString("moon"));

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:181");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assocCell3 = cons(boxSymbol("ohio"), boxString("gozaimasu"));

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:182");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assList = cons(assocCell2, emptyList());

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:183");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assList = cons(assocCell1, assList);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:184");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assList = cons(assocCell3, assList);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(cdr(assoc("Hello", assList)), boxString("world"))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:186");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("16.1 pass Basic assoc works\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:187");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("16.1 fail Basic assoc fails\n");

  };

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( andBool(andBool(equalBox(cdr(assoc("Hello", assList)), boxString("world")), equalBox(cdr(assoc("goodnight", assList)), boxString("moon"))), equalBox(cdr(assoc("ohio", assList)), boxString("gozaimasu")))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:193");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("16.2 pass assoc list\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:194");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("16.2 fail assoc list\n");

  };

if (globalTrace)
    fprintf(stderr, "Leaving test16\n");

}


//Building function test17 from line: 196

void test17() {
  list l = NULL;

if (globalTrace)
    fprintf(stderr, "test17 at q/tests.qon:196 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:198");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxInt(1), cons(boxInt(2), cons(boxInt(3), NULL)));

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(car(l), boxInt(1))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:200");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("17. pass list literal works\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:201");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("17. fail list literal failed\n");

  };

if (globalTrace)
    fprintf(stderr, "Leaving test17\n");

}


//Building function test18 from line: 207

void test18() {
  char* val1 = "a";
char* val2 = "b";
list l = NULL;

if (globalTrace)
    fprintf(stderr, "test18 at q/tests.qon:207 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:213");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), NULL)));

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(l, cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), NULL))))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:215");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("18. pass string list constructor works\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:216");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("18. fail string list constructor failed\n");

  };

if (globalTrace)
    fprintf(stderr, "Leaving test18\n");

}


//Building function test19 from line: 221

void test19() {
  char* val1 = "a";
char* val2 = "b";
list l = NULL;
list revlist = NULL;
list answer = NULL;

if (globalTrace)
    fprintf(stderr, "test19 at q/tests.qon:221 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:230");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), NULL)));

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:231");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  answer = cons(boxString("c"), cons(boxString(val2), cons(boxString(val1), NULL)));

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:232");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  revlist = reverseList(l);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(answer, revlist)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:234");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("19. pass reverseList\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:235");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("19. fail reverseList\n");

  };

if (globalTrace)
    fprintf(stderr, "Leaving test19\n");

}


//Building function concatenateLists from line: 239

list concatenateLists(list oldL,list newL) {
  
if (globalTrace)
    fprintf(stderr, "concatenateLists at q/tests.qon:239 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:241");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(reverseRec(reverseList(oldL), newL));

if (globalTrace)
    fprintf(stderr, "Leaving concatenateLists\n");

}


//Building function test20 from line: 244

void test20() {
  char* val1 = "a";
char* val2 = "b";
char* val3 = "c";
list l = NULL;
list l2 = NULL;
list l3 = NULL;
list combined = NULL;

if (globalTrace)
    fprintf(stderr, "test20 at q/tests.qon:244 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:254");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), NULL)));

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:255");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l2 = cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), NULL)));

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:256");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l3 = cons(boxString(val1), cons(boxString(val2), cons(boxString(val3), cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), NULL))))));

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:257");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  combined = concatenateLists(l, l2);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(l3, combined)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:259");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("21. pass concatenateLists\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:260");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("21. fail concatenateLists\n");

  };

if (globalTrace)
    fprintf(stderr, "Leaving test20\n");

}


//Building function test21 from line: 264

void test21() {
  char* val1 = "a";
char* val2 = "b";
char* val3 = "c";
list l = NULL;
list l2 = NULL;

if (globalTrace)
    fprintf(stderr, "test21 at q/tests.qon:264 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:272");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString(val3), NULL)));

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:273");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l2 = cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), NULL)));

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(l, l2)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:275");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("21. pass equalList\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:276");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("21. fail equalList\n");

  };

if (globalTrace)
    fprintf(stderr, "Leaving test21\n");

}


//Building function test22 from line: 280

void test22() {
  list original = NULL;
list out = NULL;
list replace = NULL;
list correct = NULL;

if (globalTrace)
    fprintf(stderr, "test22 at q/tests.qon:280 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:287");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), NULL)));

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:288");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxString("fprintf"), cons(boxString("stderr"), NULL));

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:289");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  out = macrolist(original, stringConcatenate("q", "log"), replace);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:291");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  correct = cons(boxString("fprintf"), cons(boxString("stderr"), cons(boxString("%s"), cons(boxString("hello"), NULL))));

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(out, correct)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:293");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("22. pass macroList\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:294");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("22. fail macroList\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:295");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("In: ");

    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:296");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    displayList(original, 0, true);

    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:297");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\nOut: ");

    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:298");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    displayList(out, 0, true);

    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:299");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n");

  };

if (globalTrace)
    fprintf(stderr, "Leaving test22\n");

}


//Building function test23 from line: 303

void test23() {
  list original = NULL;
list out = NULL;
list replace = NULL;
list correct = NULL;

if (globalTrace)
    fprintf(stderr, "test23 at q/tests.qon:303 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:310");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), NULL)));

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:311");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  replace = cons(boxString("fprintf"), cons(boxString("stderr"), NULL));

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:312");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  out = concatLists(original, replace);

  if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:314");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  correct = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), cons(boxString("fprintf"), cons(boxString("stderr"), NULL)))));

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(out, correct)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:316");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("23. pass concatLists\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:317");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("23. fail concatLists\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:318");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("In: ");

    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:319");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    displayList(original, 0, true);

    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:320");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\nOut: ");

    if (globalTrace)   snprintf(caller, 1024, "from q/tests.qon:321");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    displayList(out, 0, true);

  };

if (globalTrace)
    fprintf(stderr, "Leaving test23\n");

}


//Building function nodeFunctionArgs from line: 4

void nodeFunctionArgs(list tree) {
  
if (globalTrace)
    fprintf(stderr, "nodeFunctionArgs at q/node.qon:4 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:9");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(second(tree));

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:10");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:10");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(",");

    };

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:11");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeFunctionArgs(cddr(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving nodeFunctionArgs\n");

}


//Building function nodeLeaf from line: 13

void nodeLeaf(list thisNode,int indent) {
  
if (globalTrace)
    fprintf(stderr, "nodeLeaf at q/node.qon:13 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:14");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  display(nodeFuncMap(codeof(thisNode)));

if (globalTrace)
    fprintf(stderr, "Leaving nodeLeaf\n");

}


//Building function nodeStructGetterExpression from line: 16

void nodeStructGetterExpression(list thisNode,int indent) {
  
if (globalTrace)
    fprintf(stderr, "nodeStructGetterExpression at q/node.qon:16 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("structGetter"), subnameof(thisNode))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:19");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeGetStruct(thisNode, indent);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:20");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeLeaf(thisNode, indent);

  };

if (globalTrace)
    fprintf(stderr, "Leaving nodeStructGetterExpression\n");

}


//Building function nodeExpression from line: 22

void nodeExpression(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "nodeExpression at q/node.qon:22 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isLeaf(node)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:25");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(nodeFuncMap(codeof(node)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:26");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeSubExpression(node, indent);

  };

if (globalTrace)
    fprintf(stderr, "Leaving nodeExpression\n");

}


//Building function nodeRecurList from line: 28

void nodeRecurList(list expr,int indent) {
  
if (globalTrace)
    fprintf(stderr, "nodeRecurList at q/node.qon:28 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:35");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeExpression(car(expr), indent);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:37");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:38");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(", ");

      if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:38");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      nodeRecurList(cdr(expr), indent);

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving nodeRecurList\n");

}


//Building function nodeSubExpression from line: 41

void nodeSubExpression(list tree,int indent) {
  box thing = NULL;

if (globalTrace)
    fprintf(stderr, "nodeSubExpression at q/node.qon:41 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNode(childrenof(tree))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:47");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      nodeSubExpression(childrenof(tree), indent);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isLeaf(tree)) {
        if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:50");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        display(nodeFuncMap(codeof(tree)));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equal(1, listLength(childrenof(tree)))) {
          if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:54");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          display(codeof(car(childrenof(tree))));

          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxString("return"), codeof(car(childrenof(tree))))) {
            if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:58");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("");

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:59");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("()");

          };

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:61");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          thing = codeof(car(childrenof(tree)));

          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("get-struct"), thing)) {
            if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:64");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s.%s", stringify(codeof(second(childrenof(tree)))), stringify(codeof(third(childrenof(tree)))));

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("new"), thing)) {
              if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:71");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("{}");

            } else {
              if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:75");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s(", stringify(nodeFuncMap(codeof(car(childrenof(tree))))));

              if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:79");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              nodeRecurList(cdr(childrenof(tree)), indent);

              if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:80");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            };

          };

        };

      };

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving nodeSubExpression\n");

}


//Building function nodeIf from line: 82

void nodeIf(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "nodeIf at q/node.qon:82 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:84");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:85");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("if ( ");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:86");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeExpression(car(first(childrenof(node))), 0);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:87");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(") {");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:88");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeBody(second(childrenof(node)), add1(indent));

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:89");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:90");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("} else {");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:91");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeBody(third(childrenof(node)), add1(indent));

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:92");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:93");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("}");

if (globalTrace)
    fprintf(stderr, "Leaving nodeIf\n");

}


//Building function nodeGetStruct from line: 96

void nodeGetStruct(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "nodeGetStruct at q/node.qon:96 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:98");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:99");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s.%s", stringify(first(codeof(node))), stringify(second(codeof(node))));

if (globalTrace)
    fprintf(stderr, "Leaving nodeGetStruct\n");

}


//Building function nodeSet from line: 104

void nodeSet(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "nodeSet at q/node.qon:104 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:106");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:107");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s = ", stringify(first(codeof(node))));

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:108");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeExpression(childrenof(node), indent);

if (globalTrace)
    fprintf(stderr, "Leaving nodeSet\n");

}


//Building function nodeSetStruct from line: 110

void nodeSetStruct(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "nodeSetStruct at q/node.qon:110 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:112");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:113");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s.%s = ", stringify(first(codeof(node))), stringify(second(codeof(node))));

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:114");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeExpression(childrenof(node), indent);

if (globalTrace)
    fprintf(stderr, "Leaving nodeSetStruct\n");

}


//Building function nodeStatement from line: 118

void nodeStatement(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "nodeStatement at q/node.qon:118 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("setter"), subnameof(node))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:121");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeSet(node, indent);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("structSetter"), subnameof(node))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:124");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      nodeSetStruct(node, indent);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), subnameof(node))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:127");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        nodeIf(node, indent);

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("returnvoid"), subnameof(node))) {
          if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:130");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

          if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:130");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("return");

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:132");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

          if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:133");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          nodeExpression(childrenof(node), indent);

        };

      };

    };

  };

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:134");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(";\n");

if (globalTrace)
    fprintf(stderr, "Leaving nodeStatement\n");

}


//Building function nodeBody from line: 137

void nodeBody(list tree,int indent) {
  
if (globalTrace)
    fprintf(stderr, "nodeBody at q/node.qon:137 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:144");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:145");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s", "if (globalStepTrace) {console.log(new Error(\"StepTrace \\n\"));}\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:148");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeStatement(car(tree), indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:149");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeBody(cdr(tree), indent);

  };

if (globalTrace)
    fprintf(stderr, "Leaving nodeBody\n");

}


//Building function nodeDeclarations from line: 151

void nodeDeclarations(list decls,int indent) {
  box decl = NULL;

if (globalTrace)
    fprintf(stderr, "nodeDeclarations at q/node.qon:151 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:156");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:157");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("var %s = ", stringify(second(decl)));

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:160");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(nodeFuncMap(third(decl)));

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:161");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:162");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeDeclarations(cdr(decls), indent);

  };

if (globalTrace)
    fprintf(stderr, "Leaving nodeDeclarations\n");

}


//Building function nodeFunction from line: 166

void nodeFunction(list node) {
  box name = NULL;

if (globalTrace)
    fprintf(stderr, "nodeFunction at q/node.qon:166 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:168");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = subnameof(node);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:169");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:170");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:174");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0);

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:175");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("function %s(", stringify(subnameof(node)));

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:178");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeFunctionArgs(cdr(assoc("intype", cdr(node))));

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:179");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(") {");

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:180");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:181");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeDeclarations(declarationsof(node), 1);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
      if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:183");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:185");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    {printf(\"%s at %s:%s\\n\");}\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

    };

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
      if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:187");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
    };

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:192");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeBody(childrenof(node), 1);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
      if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:194");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:196");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    {printf(\"Leaving %s\\n\");}\n", stringify(name));

    };

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:198");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n");

  };

if (globalTrace)
    fprintf(stderr, "Leaving nodeFunction\n");

}


//Building function nodeForwardDeclaration from line: 200

void nodeForwardDeclaration(list node) {
  
if (globalTrace)
    fprintf(stderr, "nodeForwardDeclaration at q/node.qon:200 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:205");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n%s %s(", stringify(nodeTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:209");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeFunctionArgs(cdr(assoc("intype", cdr(node))));

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:210");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(");");

  };

if (globalTrace)
    fprintf(stderr, "Leaving nodeForwardDeclaration\n");

}


//Building function nodeForwardDeclarations from line: 212

void nodeForwardDeclarations(list tree) {
  
if (globalTrace)
    fprintf(stderr, "nodeForwardDeclarations at q/node.qon:212 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:219");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeForwardDeclaration(car(tree));

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:220");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeForwardDeclarations(cdr(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving nodeForwardDeclarations\n");

}


//Building function nodeFunctions from line: 222

void nodeFunctions(list tree) {
  
if (globalTrace)
    fprintf(stderr, "nodeFunctions at q/node.qon:222 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:228");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeFunction(car(tree));

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:228");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeFunctions(cdr(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving nodeFunctions\n");

}


//Building function nodeIncludes from line: 230

void nodeIncludes(list nodes) {
  
if (globalTrace)
    fprintf(stderr, "nodeIncludes at q/node.qon:230 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:232");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function read_file(filename) {return fs.readFileSync(filename);}\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:233");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function write_file(filename, data) {fs.writeFileSync(filename, data);}\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:234");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "var util = require('util');\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:235");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function printf() {process.stdout.write(util.format.apply(this, arguments));}\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:236");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function qlog()   {process.stderr.write(util.format.apply(this, arguments));}\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:237");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "var fs = require('fs');\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:238");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function equalString(a,b) {if (a==null) {return false;}if (b==null) {return false;}return a.toString()===b.toString() }\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:239");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function panic(s){console.trace(s);process.exit(1);}\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:240");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function dump(s){console.log(s)}");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:241");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function sub(a, b) { return a - b; }\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:242");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function mult(a, b) { return a * b; }\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:243");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function greaterthan(a, b) { return a > b; }\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:244");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function subf(a, b) { return a - b; }\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:245");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function multf(a, b) { return a * b; }\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:246");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function greaterthanf(a, b) { return a > b; }\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:247");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function equal(a, b) { return a == b; }\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:248");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function andBool(a, b) { return a == b;}\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:249");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function string_length(s) { return s.length;}\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:250");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function sub_string(str, start, len) {str = ''+str;return str.substring(start, start+len)};\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:251");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function stringConcatenate(a, b) { return a + b}\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:252");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function intToString(a) {}\n\n\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:253");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function gc_malloc( size ) {\nreturn {};\n}\n\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:254");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function makeArray(length) {\n   return [];\n}\n\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:255");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function at(arr, index) {\n  return arr[index];\n}\n\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:256");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function setAt(array, index, value) {\n    array[index] = value;\n}\n\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:257");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function getStringArray(index, strs) {\nreturn strs[index];\n}\n\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:258");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "var NULL = null;");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:259");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "var globalArgs;\nvar globalArgsCount;\nvar globalTrace = false;\nvar globalStepTrace = false;");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:260");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "function character(num) {}");

if (globalTrace)
    fprintf(stderr, "Leaving nodeIncludes\n");

}


//Building function nodeTypeDecl from line: 264

void nodeTypeDecl(list l) {
  
if (globalTrace)
    fprintf(stderr, "nodeTypeDecl at q/node.qon:264 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 2)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:268");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:269");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s %s;\n", stringify(second(l)), stringify(nodeTypeMap(listLast(l))), stringify(first(l)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:275");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:276");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s;\n", stringify(nodeTypeMap(listLast(l))), stringify(car(l)));

  };

if (globalTrace)
    fprintf(stderr, "Leaving nodeTypeDecl\n");

}


//Building function nodeStructComponents from line: 281

void nodeStructComponents(list node) {
  
if (globalTrace)
    fprintf(stderr, "nodeStructComponents at q/node.qon:281 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:287");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeTypeDecl(car(node));

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:287");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeStructComponents(cdr(node));

  };

if (globalTrace)
    fprintf(stderr, "Leaving nodeStructComponents\n");

}


//Building function nodeStruct from line: 289

void nodeStruct(list node) {
  
if (globalTrace)
    fprintf(stderr, "nodeStruct at q/node.qon:289 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:292");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeStructComponents(cdr(car(node)));

if (globalTrace)
    fprintf(stderr, "Leaving nodeStruct\n");

}


//Building function nodeTypeMap from line: 294

box nodeTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    fprintf(stderr, "nodeTypeMap at q/node.qon:294 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:299");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:305");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cdr(assoc(stringify(aSym), symMap)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:306");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym);

  };

if (globalTrace)
    fprintf(stderr, "Leaving nodeTypeMap\n");

}


//Building function nodeFuncMap from line: 309

box nodeFuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    fprintf(stderr, "nodeFuncMap at q/node.qon:309 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:315");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), NULL)))))));

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym), symMap))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:337");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cdr(assoc(stringify(aSym), symMap)));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:338");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(aSym);

    };

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:339");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym);

  };

if (globalTrace)
    fprintf(stderr, "Leaving nodeFuncMap\n");

}


//Building function nodeType from line: 340

void nodeType(list node) {
  
if (globalTrace)
    fprintf(stderr, "nodeType at q/node.qon:340 (%s)\n", caller);

if (globalTrace)
    fprintf(stderr, "Leaving nodeType\n");

}


//Building function nodeTypes from line: 344

void nodeTypes(list nodes) {
  
if (globalTrace)
    fprintf(stderr, "nodeTypes at q/node.qon:344 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:350");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeType(car(nodes));

    if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:350");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeTypes(cdr(nodes));

  };

if (globalTrace)
    fprintf(stderr, "Leaving nodeTypes\n");

}


//Building function nodeCompile from line: 352

void nodeCompile(char* filename) {
  char* programStr = "";
list tree = NULL;
list program = NULL;

if (globalTrace)
    fprintf(stderr, "nodeCompile at q/node.qon:352 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:356");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:357");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:359");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:367");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = mergeIncludes(program);

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:368");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeIncludes(cdr(assoc("includes", program)));

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:369");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeTypes(childrenof(cdr(assoc("types", program))));

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:370");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nvar globalStackTrace = NULL;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:371");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nvar caller = \"\";\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:372");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nfunction isNil(p) {\n    return p == NULL;\n}\n\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:373");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:375");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:376");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("const [asfdasdf, ...qwerqwer] = process.argv;");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:377");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("globalArgs = qwerqwer;");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:378");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("globalArgsCount = qwerqwer.length;");

  if (globalTrace)   snprintf(caller, 1024, "from q/node.qon:379");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "start();\n");

if (globalTrace)
    fprintf(stderr, "Leaving nodeCompile\n");

}


//Building function javaFunctionArgs from line: 3

void javaFunctionArgs(list tree) {
  
if (globalTrace)
    fprintf(stderr, "javaFunctionArgs at q/java.qon:3 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:8");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(javaTypeMap(first(tree)));

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:9");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" ");

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:10");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(second(tree));

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:11");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:11");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(",");

    };

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:12");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaFunctionArgs(cddr(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving javaFunctionArgs\n");

}


//Building function javaLeaf from line: 14

void javaLeaf(list thisNode,int indent) {
  
if (globalTrace)
    fprintf(stderr, "javaLeaf at q/java.qon:14 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:15");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  display(javaFuncMap(codeof(thisNode)));

if (globalTrace)
    fprintf(stderr, "Leaving javaLeaf\n");

}


//Building function javaStructGetterExpression from line: 17

void javaStructGetterExpression(list thisNode,int indent) {
  
if (globalTrace)
    fprintf(stderr, "javaStructGetterExpression at q/java.qon:17 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("structGetter"), subnameof(thisNode))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:20");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaGetStruct(thisNode, indent);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:21");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaLeaf(thisNode, indent);

  };

if (globalTrace)
    fprintf(stderr, "Leaving javaStructGetterExpression\n");

}


//Building function javaExpression from line: 23

void javaExpression(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "javaExpression at q/java.qon:23 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isLeaf(node)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:26");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(javaFuncMap(codeof(node)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:27");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaSubExpression(node, indent);

  };

if (globalTrace)
    fprintf(stderr, "Leaving javaExpression\n");

}


//Building function javaRecurList from line: 29

void javaRecurList(list expr,int indent) {
  
if (globalTrace)
    fprintf(stderr, "javaRecurList at q/java.qon:29 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:36");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaExpression(car(expr), indent);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:38");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:39");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(", ");

      if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:39");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      javaRecurList(cdr(expr), indent);

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving javaRecurList\n");

}


//Building function javaSubExpression from line: 41

void javaSubExpression(list tree,int indent) {
  box thing = NULL;

if (globalTrace)
    fprintf(stderr, "javaSubExpression at q/java.qon:41 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNode(childrenof(tree))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:47");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      javaSubExpression(childrenof(tree), indent);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isLeaf(tree)) {
        if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:50");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        display(javaFuncMap(codeof(tree)));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equal(1, listLength(childrenof(tree)))) {
          if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:54");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          display(codeof(car(childrenof(tree))));

          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxString("return"), codeof(car(childrenof(tree))))) {
            if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:58");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("");

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:59");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("()");

          };

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:61");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          thing = codeof(car(childrenof(tree)));

          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("get-struct"), thing)) {
            if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:64");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s.%s", stringify(codeof(second(childrenof(tree)))), stringify(codeof(third(childrenof(tree)))));

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("new"), thing)) {
              if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:71");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("new %s()", stringify(codeof(third(childrenof(tree)))));

            } else {
              if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:75");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s(", stringify(javaFuncMap(codeof(car(childrenof(tree))))));

              if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:79");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              javaRecurList(cdr(childrenof(tree)), indent);

              if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:80");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")");

            };

          };

        };

      };

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving javaSubExpression\n");

}


//Building function javaIf from line: 81

void javaIf(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "javaIf at q/java.qon:81 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:83");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:84");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("if ( ");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:85");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaExpression(car(first(childrenof(node))), 0);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:86");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(") {");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:87");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaBody(second(childrenof(node)), add1(indent));

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:88");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:89");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("} else {");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:90");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaBody(third(childrenof(node)), add1(indent));

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:91");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:92");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("}");

if (globalTrace)
    fprintf(stderr, "Leaving javaIf\n");

}


//Building function javaSetStruct from line: 94

void javaSetStruct(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "javaSetStruct at q/java.qon:94 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:96");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:97");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s.%s = ", stringify(first(codeof(node))), stringify(second(codeof(node))));

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:101");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaExpression(childrenof(node), indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:102");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(";");

if (globalTrace)
    fprintf(stderr, "Leaving javaSetStruct\n");

}


//Building function javaGetStruct from line: 105

void javaGetStruct(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "javaGetStruct at q/java.qon:105 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:107");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:108");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s.%s", stringify(first(codeof(node))), stringify(second(codeof(node))));

if (globalTrace)
    fprintf(stderr, "Leaving javaGetStruct\n");

}


//Building function javaSet from line: 113

void javaSet(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "javaSet at q/java.qon:113 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:115");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:116");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s = ", stringify(first(codeof(node))));

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:117");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaExpression(childrenof(node), indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:118");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(";");

if (globalTrace)
    fprintf(stderr, "Leaving javaSet\n");

}


//Building function javaStatement from line: 121

void javaStatement(list node,int indent) {
  
if (globalTrace)
    fprintf(stderr, "javaStatement at q/java.qon:121 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("setter"), subnameof(node))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:124");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaSet(node, indent);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("structSetter"), subnameof(node))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:127");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      javaSetStruct(node, indent);

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if"), subnameof(node))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:130");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        javaIf(node, indent);

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("returnvoid"), subnameof(node))) {
          if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:133");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

          if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:133");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("return;");

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:135");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent);

          if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:136");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          javaExpression(childrenof(node), indent);

          if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:137");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf(";");

        };

      };

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving javaStatement\n");

}


//Building function javaBody from line: 141

void javaBody(list tree,int indent) {
  
if (globalTrace)
    fprintf(stderr, "javaBody at q/java.qon:141 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:146");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:147");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("");

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:149");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaStatement(car(tree), indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:150");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaBody(cdr(tree), indent);

  };

if (globalTrace)
    fprintf(stderr, "Leaving javaBody\n");

}


//Building function javaDeclarations from line: 152

void javaDeclarations(list decls,int indent) {
  box decl = NULL;

if (globalTrace)
    fprintf(stderr, "javaDeclarations at q/java.qon:152 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:157");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls);

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:158");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s = ", stringify(javaTypeMap(first(decl))), stringify(second(decl)));

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:162");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(javaFuncMap(third(decl)));

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:163");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:164");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaDeclarations(cdr(decls), indent);

  };

if (globalTrace)
    fprintf(stderr, "Leaving javaDeclarations\n");

}


//Building function javaFunction from line: 166

void javaFunction(list node) {
  box name = NULL;

if (globalTrace)
    fprintf(stderr, "javaFunction at q/java.qon:166 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:168");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = subnameof(node);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:169");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:170");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:174");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0);

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:175");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("public %s %s(", stringify(javaTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:179");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaFunctionArgs(cdr(assoc("intype", cdr(node))));

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:180");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(") {");

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:181");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1);

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:182");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaDeclarations(declarationsof(node), 1);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
      if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:184");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:186");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    };

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
      if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:188");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
    };

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:193");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaBody(childrenof(node), 1);

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name), noStackTrace())) {
      if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:195");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("void", stringify(javaTypeMap(cdr(assoc("outtype", cdr(node))))))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:199");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("\nif (globalTrace)\n   System.out. printf(\"Leaving %s\\n\");\n", stringify(name));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:200");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("");

      };

    };

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:202");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n");

  };

if (globalTrace)
    fprintf(stderr, "Leaving javaFunction\n");

}


//Building function javaFunctions from line: 206

void javaFunctions(list tree) {
  
if (globalTrace)
    fprintf(stderr, "javaFunctions at q/java.qon:206 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:210");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaFunction(car(tree));

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:210");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaFunctions(cdr(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving javaFunctions\n");

}


//Building function javaIncludes from line: 212

void javaIncludes(list nodes) {
  
if (globalTrace)
    fprintf(stderr, "javaIncludes at q/java.qon:212 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:214");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public void panic(String s) {System.exit(1);}\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:215");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public int sub(int a, int b) { return a - b; }\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:216");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public double mult(int a, int b) { return a * b; }\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:217");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public boolean greaterthan(int a, int b) { return a > b; }\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:218");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public double subf(double a, double b) { return a - b; }\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:219");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public double multf(double a, double b) { return a * b; }\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:220");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public boolean greaterthanf(double a, double b) { return a > b; }\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:221");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public boolean equal(int a, int b) { return a == b; }\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:222");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public boolean equalString(String a, String b) { return a.equals(b); }\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:223");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public boolean andBool(boolean a, boolean b) { return a == b;}\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:224");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public int string_length(String s) { return s.length();}\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:225");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public String stringConcatenate(String s1, String s2) { return s1 + s2; }\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:226");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public int strcmp(String s1, String s2) { return s1.compareTo(s2);}\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:227");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public String read_file(String filename) {try { return new String(Files.readAllBytes(Paths.get(filename)));} catch (Exception e) {panic(\"Could not read file\");return \"\";}}\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:228");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public void write_file(String filename, String data) {try {Files.write(Paths.get(filename), data.getBytes(\"UTF-8\"));} catch (Exception e) {panic(\"Could not write file\");}}\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:229");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public String sub_string(String s, int start, int length) {\nreturn s.substring(start, start+length);\n}\n\n\n\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:230");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public String intToString(int num) { char c=(char) num;  String s=Character.toString(c); return s;}");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:231");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public String character(int num) { char c=(char) num;  String s=Character.toString(c); return s;}");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:232");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public String getStringArray(int index, String[] arr) { return arr[index];}");

if (globalTrace)
    fprintf(stderr, "Leaving javaIncludes\n");

}


//Building function javaTypeDecl from line: 235

void javaTypeDecl(list l) {
  
if (globalTrace)
    fprintf(stderr, "javaTypeDecl at q/java.qon:235 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 2)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:239");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:240");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s;\n", stringify(javaTypeMap(listLast(l))), stringify(first(l)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:246");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:247");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s;\n", stringify(javaTypeMap(listLast(l))), stringify(car(l)));

  };

if (globalTrace)
    fprintf(stderr, "Leaving javaTypeDecl\n");

}


//Building function javaStructComponents from line: 252

void javaStructComponents(list node) {
  
if (globalTrace)
    fprintf(stderr, "javaStructComponents at q/java.qon:252 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:256");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaTypeDecl(car(node));

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:256");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaStructComponents(cdr(node));

  };

if (globalTrace)
    fprintf(stderr, "Leaving javaStructComponents\n");

}


//Building function javaStruct from line: 258

void javaStruct(list node) {
  
if (globalTrace)
    fprintf(stderr, "javaStruct at q/java.qon:258 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:259");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaStructComponents(cdr(car(node)));

if (globalTrace)
    fprintf(stderr, "Leaving javaStruct\n");

}


//Building function javaTypeMap from line: 261

box javaTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    fprintf(stderr, "javaTypeMap at q/java.qon:261 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:264");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("pair"), boxSymbol("Box"), alistCons(boxSymbol("bool"), boxSymbol("boolean"), alistCons(boxSymbol("box"), boxSymbol("Box"), alistCons(boxSymbol("list"), boxSymbol("Box"), alistCons(boxSymbol("Box*"), boxSymbol("Box"), alistCons(boxSymbol("struct"), boxSymbol(""), alistCons(boxSymbol("int"), boxSymbol("Integer"), alistCons(boxSymbol("float"), boxSymbol("double"), alistCons(boxSymbol("stringArray"), boxSymbol("String[]"), alistCons(boxSymbol("string"), boxSymbol("String"), NULL))))))))));

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:276");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cdr(assoc(stringify(aSym), symMap)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:277");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym);

  };

if (globalTrace)
    fprintf(stderr, "Leaving javaTypeMap\n");

}


//Building function javaTypesNoDeclare from line: 279

box javaTypesNoDeclare() {
  list syms = NULL;

if (globalTrace)
    fprintf(stderr, "javaTypesNoDeclare at q/java.qon:279 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:282");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  syms = cons(boxString("pair"), cons(boxString("box"), NULL));

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:286");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(syms);

if (globalTrace)
    fprintf(stderr, "Leaving javaTypesNoDeclare\n");

}


//Building function javaFuncMap from line: 288

box javaFuncMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    fprintf(stderr, "javaFuncMap at q/java.qon:288 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol", boxType(aSym))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:293");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("printf"), boxSymbol("System.out.printf"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("null"), NULL))))))));

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym), symMap))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:314");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cdr(assoc(stringify(aSym), symMap)));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:315");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(aSym);

    };

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:316");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym);

  };

if (globalTrace)
    fprintf(stderr, "Leaving javaFuncMap\n");

}


//Building function javaType from line: 318

void javaType(list node) {
  
if (globalTrace)
    fprintf(stderr, "javaType at q/java.qon:318 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(subnameof(node), boxString("struct"))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:322");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\npublic class %s {\n", stringify(first(codeof(node))));

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:323");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\npublic String caller =\"\";");

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:324");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaStruct(cdr(codeof(node)));

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:325");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n};\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(boxString(stringify(first(codeof(node)))), javaTypesNoDeclare())) {
      if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:328");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:330");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("public class %s extends %s {};\n", stringify(first(codeof(node))), stringify(javaTypeMap(listLast(codeof(node)))));

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving javaType\n");

}


//Building function javaTypes from line: 334

void javaTypes(list nodes) {
  
if (globalTrace)
    fprintf(stderr, "javaTypes at q/java.qon:334 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:338");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaType(car(nodes));

    if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:338");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaTypes(cdr(nodes));

  };

if (globalTrace)
    fprintf(stderr, "Leaving javaTypes\n");

}


//Building function javaCompile from line: 340

void javaCompile(char* filename) {
  char* programStr = "";
list tree = NULL;
list program = NULL;

if (globalTrace)
    fprintf(stderr, "javaCompile at q/java.qon:340 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:342");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "package quonverter;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:343");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "import java.nio.file.Files;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:344");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "import java.nio.file.Paths;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:345");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "import java.io.IOException;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:346");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "import java.io.UnsupportedEncodingException;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:347");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("class MyProgram {\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:348");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\npublic String caller =\"\";");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:349");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:350");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr, filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:352");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:361");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = mergeIncludes(program);

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:362");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaIncludes(cdr(assoc("includes", program)));

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:363");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaTypes(childrenof(cdr(assoc("types", program))));

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:364");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public boolean globalStackTrace = false;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:365");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public boolean globalStepTrace = false;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:366");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public boolean globalTrace = false;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:367");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public String FILE = null;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:368");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public Integer LINE = 0;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:369");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public static Integer globalArgsCount = 0;\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:370");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public static String globalArgs[];\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:371");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\npublic boolean isNil(Box p) {\n    return p == null;\n}\n\n\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:373");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:375");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "public static void main(String args[]) {\nglobalArgs = args;\nglobalArgsCount = args.length;MyProgram mp = new MyProgram(); mp.start();\n}");

  if (globalTrace)   snprintf(caller, 1024, "from q/java.qon:376");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("}\n");

if (globalTrace)
    fprintf(stderr, "Leaving javaCompile\n");

}


//Building function luaFunctionArgs from line: 4

void luaFunctionArgs(int indent,list tree) {
  
if (globalTrace)
    fprintf(stderr, "luaFunctionArgs at q/lua.qon:4 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:9");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(second(tree));

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:10");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:10");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(",");

    };

    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:11");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaFunctionArgs(indent, cddr(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving luaFunctionArgs\n");

}


//Building function luaFunction from line: 14

void luaFunction(int indent,list functionDefinition) {
  char* fname = "";

if (globalTrace)
    fprintf(stderr, "luaFunction at q/lua.qon:14 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:16");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fname = stringify(second(functionDefinition));

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:17");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("-- Chose function name %s", fname);

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:18");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nfunction %s(", fname);

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:19");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  luaFunctionArgs(indent, third(functionDefinition));

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:20");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(")\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:21");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("print(\"caller: \", caller, \"-> %s\")\n", fname);

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:22");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  luaDeclarations(add1(indent), cdr(fourth(functionDefinition)));

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:23");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  luaBody(fname, indent, cdr(fifth(functionDefinition)));

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:24");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("end\n");

if (globalTrace)
    fprintf(stderr, "Leaving luaFunction\n");

}


//Building function luaDeclarations from line: 26

void luaDeclarations(int indent,list declarations) {
  list decl = NULL;

if (globalTrace)
    fprintf(stderr, "luaDeclarations at q/lua.qon:26 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(declarations)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:32");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = first(declarations);

    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:33");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("local %s =", stringify(second(decl)));

    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:34");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaExpressionStart(indent, third(decl));

    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:35");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:36");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaDeclarations(indent, cdr(declarations));

  };

if (globalTrace)
    fprintf(stderr, "Leaving luaDeclarations\n");

}


//Building function luaExpressionStart from line: 42

void luaExpressionStart(int indent,list program) {
  
if (globalTrace)
    fprintf(stderr, "luaExpressionStart at q/lua.qon:42 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(program)) {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringify(car(program)), "get-struct")) {
        if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:52");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s.%s", stringify(second(program)), stringify(third(program)));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString(stringify(car(program)), ">")) {
          if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:57");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("greaterthan(");

          if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:58");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          luaExpression(indent, cdr(program));

          if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:59");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf(")");

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString(stringify(car(program)), "=")) {
            if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:64");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("equal(");

            if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:65");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            luaExpression(indent, cdr(program));

            if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:66");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf(")");

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:69");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s(", stringify(car(program)));

            if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:70");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            luaExpression(indent, cdr(program));

            if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:71");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf(")");

          };

        };

      };

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:77");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      luaExpression(indent, program);

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving luaExpressionStart\n");

}


//Building function luaExpression from line: 84

void luaExpression(int indent,list program) {
  
if (globalTrace)
    fprintf(stderr, "luaExpression at q/lua.qon:84 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(program)) {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isList(car(program))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:94");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        luaExpressionStart(indent, car(program));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:99");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        display(car(program));

      };

      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( greaterthan(listLength(program), 1)) {
        if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:104");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf(", ");

      } else {
      };

      if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:106");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      luaExpression(indent, cdr(program));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:109");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(program);

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving luaExpression\n");

}


//Building function luaStatement from line: 113

void luaStatement(int indent,list statement) {
  
if (globalTrace)
    fprintf(stderr, "luaStatement at q/lua.qon:113 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(stringify(car(statement)), "if")) {
    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:119");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:120");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("if ");

    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:121");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    add1(indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:122");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaExpressionStart(add1(indent), second(statement));

    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:124");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" then\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:125");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaBody(caller, add1(indent), cdr(third(statement)));

    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:126");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:127");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("else\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:128");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaBody(caller, add1(indent), cdr(fourth(statement)));

    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:129");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:130");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("end\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(stringify(car(statement)), "set")) {
      if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:135");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printIndent(indent);

      if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:136");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("%s = ", stringify(second(statement)));

      if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:137");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      luaExpressionStart(add1(indent), third(statement));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringify(car(statement)), "set-struct")) {
        if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:142");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s.%s = ", stringify(second(statement)), stringify(third(statement)));

        if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:143");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        luaExpressionStart(indent, fourth(statement));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString(stringify(car(statement)), "return")) {
          if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:148");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printIndent(indent);

          if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:149");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("return ");

          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( greaterthan(listLength(statement), 1)) {
            if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:152");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            luaExpressionStart(indent, second(statement));

          } else {
          };

          if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:154");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("\n");

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:157");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printIndent(indent);

          if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:158");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          luaExpressionStart(indent, statement);

          if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:159");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf(";\n");

        };

      };

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving luaStatement\n");

}


//Building function luaBody from line: 166

void luaBody(char* local_caller,int indent,list program) {
  list statement = NULL;

if (globalTrace)
    fprintf(stderr, "luaBody at q/lua.qon:166 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:171");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    statement = car(program);

    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:172");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("caller = \"%s:%s:%d\"\n", local_caller, unBoxString(getTagFail(statement, boxString("filename"), boxString("Unknown file"))), unBoxInt(getTagFail(statement, boxString("line"), boxInt(-1))));

    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:173");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaStatement(add1(indent), statement);

    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:174");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:175");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaBody(local_caller, indent, cdr(program));

  };

if (globalTrace)
    fprintf(stderr, "Leaving luaBody\n");

}


//Building function luaFunctions from line: 178

void luaFunctions(int indent,list program) {
  
if (globalTrace)
    fprintf(stderr, "luaFunctions at q/lua.qon:178 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:184");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaFunction(indent, car(program));

    if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:185");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaFunctions(indent, cdr(program));

  };

if (globalTrace)
    fprintf(stderr, "Leaving luaFunctions\n");

}


//Building function luaProgram from line: 190

void luaProgram(list program) {
  
if (globalTrace)
    fprintf(stderr, "luaProgram at q/lua.qon:190 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:192");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  luaIncludes(NULL);

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:193");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  luaFunctions(0, cdr(third(program)));

if (globalTrace)
    fprintf(stderr, "Leaving luaProgram\n");

}


//Building function luaIncludes from line: 197

void luaIncludes(list nodes) {
  
if (globalTrace)
    fprintf(stderr, "luaIncludes at q/lua.qon:197 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:199");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s", "\nfunction luaDump(o)\n   if type(o) == 'table' then\n      local s = '{ '\n      for k,v in pairs(o) do\n         if type(k) ~= 'number' then k = '\"'..k..'\"' end\n         s = s .. '['..k..'] = ' .. luaDump(v) .. ','\n      end\n      return s .. '} '\n   else\n      return tostring(o)\n   end\nend\nprintf = function(s,...)\nreturn io.write(s:format(...))\nend -- function\n    \nfunction stringConcatenate(a,b)\nreturn a..b\nend\n    \nfunction getStringArray(index, arr)\nreturn arr[index]\nend\n       \nfunction luaWriteFile(name, data)  \nlocal file = io.open(name, \"w\")\nfile:write(data)\nfile:close(file)\nend\n    function luaSubstring(s, start, length)\nreturn string.sub(s, start, start+length)\nend\n    \n    function luaReadFile(file)\n      local f = assert(io.open(file, \"rb\"))\n      local content = f:read(\"*all\")      f:close()\n      return content\n    end\n     \nfunction equalString(a,b)\n        return a==b;\n     end\n    \n     function new()\n        return {};\n     end\n    \n     function isNil(val)\n        return val == nil;\n     end\n    \n     function getEnv(key)\n        return os.getenv(key);\n     end\n    \n    function panic(s)\n      print(s);\n    os.exit()\n    end\n    \n    function sub(a, b) \n      return a - b; \n    end\n\n    function mult(a, b) \n      return a * b;\n    end\n    \n    function greaterthan(a, b)\n      return a > b;\n    end\n    \n    function subf(a, b) \n      return a - b;\n    end\n    \n    function multf(a, b)\n      return a * b;\n    end\n    \n    function greaterthanf(a, b)\n      return a > b;\n    end\n    \n    function equal(a, b)\n      return a == b;\n    end\n    \n    function andBool(a, b)\n      return a == b;\n    end\n    \n    function string_length(s)\n      return strlen(s);\n    end\n    \n    function setSubString(target, start, source)\n      panic(\"stub\");\n      end\n    \n    function sub_string(s, start, length)\n      panic(\"stub\");\n    end\n    \n    function intToString(a)\n      panic(\"stub\")\n return a\n    end\n\n    function gc_malloc(size)\n      return \"\"\n    end\n    \n    function makeArray(length)\n      return {}\n    end\n    \n    function at(arr, index)\n      return arr[index+1];\n    end\n    \n    function setAt(array, index, value)\n      array[index+1] = value;\n    end\n    \n    function read_file(file)\n      local f = io.open(file, \"r\")\n      local content = \"\"\n      local length = 0\n\n      while f:read(0) ~= \"\" do\n          local current = f:read(\"*all\")\n\n          print(#current, length)\n          length = length + #current\n\n          content = content .. current\n      end\n\n      return content\n    end\n    \n    function write_file(filename, data)\n      local file = io.open(filename,'w')\n      file:write(tostring(data))\n      file:close()\n    end\n    \n    caller=\"main\";\n    \n    globalArgs={};\n    globalArgsCount=0;\n    globalTrace = false;\n    globalStepTrace = false;\n\n    function main()\n      globalArgs = arg;\n      globalArgsCount = #arg + 1;\n      return start();\n    end\n    \n");

if (globalTrace)
    fprintf(stderr, "Leaving luaIncludes\n");

}


//Building function luaCompile from line: 205

void luaCompile(char* filename) {
  list tree = NULL;

if (globalTrace)
    fprintf(stderr, "luaCompile at q/lua.qon:205 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:208");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon(filename);

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:212");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree);

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:213");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:214");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "write-file", "luaWriteFile");

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:215");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "read-file", "luaReadFile");

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:216");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "string-length", "string.len");

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:218");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "sub-string", "luaSubstring");

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:219");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "stringLength", "string.len");

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:222");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  luaProgram(tree);

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:223");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:224");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("function main()\nglobalArgs = arg\nglobalArgsCount = #arg\nstart()\nend\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/lua.qon:225");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("main()");

if (globalTrace)
    fprintf(stderr, "Leaving luaCompile\n");

}


//Building function imaFunctionArgs from line: 4

void imaFunctionArgs(int indent,list tree) {
  
if (globalTrace)
    fprintf(stderr, "imaFunctionArgs at q/imaginary.qon:4 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:9");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(second(tree));

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:10");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(": ");

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:11");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(first(tree));

    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree))) {
      if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:12");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:12");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(", ");

    };

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:13");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaFunctionArgs(indent, cddr(tree));

  };

if (globalTrace)
    fprintf(stderr, "Leaving imaFunctionArgs\n");

}


//Building function imaFunction from line: 16

void imaFunction(int indent,list functionDefinition) {
  char* fname = "";

if (globalTrace)
    fprintf(stderr, "imaFunction at q/imaginary.qon:16 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:18");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fname = stringify(second(functionDefinition));

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:23");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nfu %s(", fname);

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:24");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaFunctionArgs(indent, third(functionDefinition));

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:25");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(") ");

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:26");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("-> %s", stringify(first(functionDefinition)));

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:29");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaDeclarations(add1(indent), cdr(fourth(functionDefinition)));

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(cdr(fourth(functionDefinition))), 0)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:32");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:33");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" ");

  };

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:34");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printIndent(indent);

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:35");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("in\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:37");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaBody(fname, indent, cdr(fifth(functionDefinition)));

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:38");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("end function\n");

if (globalTrace)
    fprintf(stderr, "Leaving imaFunction\n");

}


//Building function imaDeclarations from line: 40

void imaDeclarations(int indent,list declarations) {
  list decl = NULL;

if (globalTrace)
    fprintf(stderr, "imaDeclarations at q/imaginary.qon:40 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(declarations)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:47");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = first(declarations);

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:48");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:49");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:50");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s: %s ", stringify(second(decl)), stringify(first(decl)));

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:51");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaExpressionStart(indent, third(decl));

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:53");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaDeclarations(indent, cdr(declarations));

  };

if (globalTrace)
    fprintf(stderr, "Leaving imaDeclarations\n");

}


//Building function imaExpressionStart from line: 59

void imaExpressionStart(int indent,list program) {
  
if (globalTrace)
    fprintf(stderr, "imaExpressionStart at q/imaginary.qon:59 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(program)) {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringify(car(program)), "get-struct")) {
        if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:69");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s.%s", stringify(second(program)), stringify(third(program)));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString(stringify(car(program)), ">")) {
          if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:74");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("greaterthan(");

          if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:75");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          imaExpression(indent, cdr(program));

          if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:76");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf(")");

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString(stringify(car(program)), "=")) {
            if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:81");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("equal(");

            if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:82");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            imaExpression(indent, cdr(program));

            if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:83");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf(")");

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:86");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s(", stringify(car(program)));

            if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:87");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            imaExpression(indent, cdr(program));

            if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:88");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf(")");

          };

        };

      };

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:94");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      imaExpression(indent, program);

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving imaExpressionStart\n");

}


//Building function imaExpression from line: 101

void imaExpression(int indent,list program) {
  
if (globalTrace)
    fprintf(stderr, "imaExpression at q/imaginary.qon:101 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(program)) {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isList(car(program))) {
        if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:111");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        imaExpressionStart(indent, car(program));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:116");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        display(car(program));

      };

      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( greaterthan(listLength(program), 1)) {
        if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:121");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf(", ");

      } else {
      };

      if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:123");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      imaExpression(indent, cdr(program));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:126");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(program);

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving imaExpression\n");

}


//Building function imaStatement from line: 130

void imaStatement(int indent,list statement) {
  
if (globalTrace)
    fprintf(stderr, "imaStatement at q/imaginary.qon:130 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(stringify(car(statement)), "if")) {
    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:136");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:137");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("if ");

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:138");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    add1(indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:139");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaExpressionStart(add1(indent), second(statement));

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:141");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" then\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:142");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaBody(caller, add1(indent), cdr(third(statement)));

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:143");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:144");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("else\n");

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:145");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaBody(caller, add1(indent), cdr(fourth(statement)));

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:146");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent);

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:147");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("end\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(stringify(car(statement)), "set")) {
      if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:152");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printIndent(indent);

      if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:153");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("%s = ", stringify(second(statement)));

      if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:154");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      imaExpressionStart(add1(indent), third(statement));

      if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:155");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(";\n");

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringify(car(statement)), "set-struct")) {
        if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:160");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printIndent(indent);

        if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:161");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s.%s = ", stringify(second(statement)), stringify(third(statement)));

        if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:162");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        imaExpressionStart(indent, fourth(statement));

        if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:163");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf(";\n");

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString(stringify(car(statement)), "return")) {
          if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:168");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printIndent(indent);

          if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:169");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("return; ");

          if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( greaterthan(listLength(statement), 1)) {
            if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:172");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            imaExpressionStart(indent, second(statement));

          } else {
          };

          if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:174");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("\n");

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:177");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printIndent(indent);

          if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:178");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          imaExpressionStart(indent, statement);

          if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:179");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf(";\n");

        };

      };

    };

  };

if (globalTrace)
    fprintf(stderr, "Leaving imaStatement\n");

}


//Building function imaBody from line: 186

void imaBody(char* local_caller,int indent,list program) {
  list statement = NULL;

if (globalTrace)
    fprintf(stderr, "imaBody at q/imaginary.qon:186 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:191");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    statement = car(program);

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:194");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaStatement(add1(indent), statement);

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:195");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaBody(local_caller, indent, cdr(program));

  };

if (globalTrace)
    fprintf(stderr, "Leaving imaBody\n");

}


//Building function imaFunctions from line: 198

void imaFunctions(int indent,list program) {
  
if (globalTrace)
    fprintf(stderr, "imaFunctions at q/imaginary.qon:198 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:204");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaFunction(indent, car(program));

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:205");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaFunctions(indent, cdr(program));

  };

if (globalTrace)
    fprintf(stderr, "Leaving imaFunctions\n");

}


//Building function imaTypeDecl from line: 208

void imaTypeDecl(list l) {
  char* name = "";
list body = NULL;

if (globalTrace)
    fprintf(stderr, "imaTypeDecl at q/imaginary.qon:208 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:213");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = stringify(first(l));

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:214");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  body = cdr(l);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l), 2)) {
    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:217");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:218");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s is ", name);

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:222");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    displayList(body, 0, true);

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:223");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:227");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1);

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:228");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s is %s;\n", name, stringify(second(l)));

  };

if (globalTrace)
    fprintf(stderr, "Leaving imaTypeDecl\n");

}


//Building function imaStructComponents from line: 233

void imaStructComponents(list node) {
  
if (globalTrace)
    fprintf(stderr, "imaStructComponents at q/imaginary.qon:233 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:237");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaTypeDecl(car(node));

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:237");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaStructComponents(cdr(node));

  };

if (globalTrace)
    fprintf(stderr, "Leaving imaStructComponents\n");

}


//Building function imaStruct from line: 239

void imaStruct(list node) {
  
if (globalTrace)
    fprintf(stderr, "imaStruct at q/imaginary.qon:239 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:240");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaStructComponents(cdr(car(node)));

if (globalTrace)
    fprintf(stderr, "Leaving imaStruct\n");

}


//Building function imaTypeMap from line: 242

box imaTypeMap(box aSym) {
  list symMap = NULL;

if (globalTrace)
    fprintf(stderr, "imaTypeMap at q/imaginary.qon:242 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:245");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym), symMap))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:251");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cdr(assoc(stringify(aSym), symMap)));

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:252");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym);

  };

if (globalTrace)
    fprintf(stderr, "Leaving imaTypeMap\n");

}


//Building function imaType from line: 254

void imaType(list node) {
  char* name = "";
list body = NULL;

if (globalTrace)
    fprintf(stderr, "imaType at q/imaginary.qon:254 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:259");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = stringify(first(node));

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:260");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  body = cdr(node);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(first(body))) {
    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:263");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\ntype %s is struct (\n", name);

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:264");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaStruct(body);

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:265");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(");\n");

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:266");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("type");

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:266");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaTypeDecl(node);

  };

if (globalTrace)
    fprintf(stderr, "Leaving imaType\n");

}


//Building function imaTypes from line: 269

void imaTypes(int indent,list nodes) {
  
if (globalTrace)
    fprintf(stderr, "imaTypes at q/imaginary.qon:269 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes)) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:275");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaType(car(nodes));

    if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:275");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaTypes(indent, cdr(nodes));

  };

if (globalTrace)
    fprintf(stderr, "Leaving imaTypes\n");

}


//Building function imaProgram from line: 279

void imaProgram(list program) {
  
if (globalTrace)
    fprintf(stderr, "imaProgram at q/imaginary.qon:279 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:281");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaIncludes(0, cdr(first(program)));

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:282");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nTypes:\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:283");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaTypes(0, cdr(second(program)));

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:284");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nFunctions:\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:285");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaFunctions(0, cdr(third(program)));

if (globalTrace)
    fprintf(stderr, "Leaving imaProgram\n");

}


//Building function imaIncludes from line: 289

void imaIncludes(int indent,list nodes) {
  
if (globalTrace)
    fprintf(stderr, "imaIncludes at q/imaginary.qon:289 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:291");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("Includes: \n");

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:292");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  displayList(nodes, 0, true);

if (globalTrace)
    fprintf(stderr, "Leaving imaIncludes\n");

}


//Building function imaCompile from line: 296

void imaCompile(char* filename) {
  list tree = NULL;

if (globalTrace)
    fprintf(stderr, "imaCompile at q/imaginary.qon:296 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:299");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon("compiler.qon");

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:303");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree);

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:304");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree);

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:305");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "write-file", "imaWriteFile");

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:306");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "read-file", "imaReadFile");

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:307");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "string-length", "string.len");

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:309");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "sub-string", "imaSubstring");

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:310");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree, "stringLength", "string.len");

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:313");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaProgram(tree);

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:314");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:315");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("function main()\nglobalArgs = arg\nglobalArgsCount = #arg\nstart()\nend\n");

  if (globalTrace)   snprintf(caller, 1024, "from q/imaginary.qon:316");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("main()");

if (globalTrace)
    fprintf(stderr, "Leaving imaCompile\n");

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
bool runTree = false;

if (globalTrace)
    fprintf(stderr, "start at compiler.qon:4 (%s)\n", caller);

  if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:19");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  cmdLine = listReverse(argList(globalArgsCount, 0, globalArgs));

  if (globalTrace)   snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(cmdLine), 1)) {
    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:23");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    filename = second(cmdLine);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:24");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    filename = boxString("compiler.qon");

  };

  if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:27");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runTests = inList(boxString("--test"), cmdLine);

  if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runJava = inList(boxString("--java"), cmdLine);

  if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:29");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runPerl = inList(boxString("--perl"), cmdLine);

  if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:30");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runAst = inList(boxString("--ast"), cmdLine);

  if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:31");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runTree = inList(boxString("--tree"), cmdLine);

  if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:32");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runNode = inList(boxString("--node"), cmdLine);

  if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:33");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runLua = inList(boxString("--lua"), cmdLine);

  if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:34");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runIma = inList(boxString("--ima"), cmdLine);

  if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:35");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runAnsi2 = inList(boxString("--ansi2"), cmdLine);

  if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:36");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runAnsi3 = inList(boxString("--ansi3"), cmdLine);

  if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:37");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalTrace = inList(boxString("--trace"), cmdLine);

  if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:38");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalStepTrace = inList(boxString("--steptrace"), cmdLine);

  if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:39");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( runTests) {
    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:41");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test0();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:42");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test1();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:43");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test2();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:44");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test3();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:45");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test4();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:46");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test5();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:47");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test6();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:48");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test7();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:49");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test8();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:50");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test9();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:51");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test10();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:52");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test12();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:53");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test13();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:54");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test15();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:55");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test16();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:56");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test17();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:57");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test18();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:58");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test19();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:59");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test20();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:60");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test21();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:61");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test22();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:62");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test23();

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:65");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n\nAfter all that hard work, I need a beer...\n");

    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:66");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    beers(9);

  } else {
    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:68");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( runTree) {
      if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:69");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(macrowalk(treeCompile(unBoxString(filename))));

    } else {
      if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:71");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( runAst) {
        if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:72");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        astCompile(unBoxString(filename));

      } else {
        if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:73");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( runNode) {
          if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:75");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          nodeCompile(unBoxString(filename));

          if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:75");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("\n");

        } else {
          if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:77");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( runPerl) {
            if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:78");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            perlCompile(unBoxString(filename));

            if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:78");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("\n");

          } else {
            if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:80");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( runJava) {
              if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:81");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              javaCompile(unBoxString(filename));

              if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:81");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("\n");

            } else {
              if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:83");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              if ( runLua) {
                if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:84");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                luaCompile(unBoxString(filename));

                if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:84");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                printf("\n");

              } else {
                if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:86");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                if ( runIma) {
                  if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:87");
                  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                  imaCompile(unBoxString(filename));

                  if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:87");
                  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                  printf("\n");

                } else {
                  if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:89");
                  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                  if ( runAnsi2) {
                    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:90");
                    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                    ansi2Compile(unBoxString(filename));

                    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:90");
                    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                    printf("\n");

                  } else {
                    if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:92");
                    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                    if ( runAnsi3) {
                      if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:93");
                      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                      ansi3Compile(unBoxString(filename));

                      if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:93");
                      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                      printf("\n");

                    } else {
                      if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:95");
                      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                      ansiCompile(unBoxString(filename));

                      if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:95");
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

  if (globalTrace)   snprintf(caller, 1024, "from compiler.qon:97");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(0);

if (globalTrace)
    fprintf(stderr, "Leaving start\n");

}


