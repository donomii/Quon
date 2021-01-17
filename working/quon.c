//Scanning file...compiler.qon
//Building sexpr
//Building AST
//Merging ASTs
//Printing program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char* getEnv(char* key){return getenv(key);}
 void panic(char* s){abort();}
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
return malloc( size);
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
  buffer = malloc (length);
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

char * character(int num) { char *string = malloc(2); if (!string) return 0; string[0] = num; string[1] = 0; return string; }
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
typedef   Box Pair;
typedef   Box* pair;
typedef   Box* box;
typedef   Box* list;

typedef struct Box2 {
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

} Box2;
Box* globalStackTrace = NULL;

bool isNil(list p) {
    return p == NULL;
}


//Forward declarations

int add(int a ,int b );
float addf(float a ,float b );
int sub1(int a );
int add1(int a );
box clone(box b );
box newVoid();
list cons(box data ,list l );
void stackDump();
void nop();
box car(list l );
list cdr(list l );
bool isList(box b );
list emptyList();
bool isEmpty(box b );
int listLength(list l );
list alistCons(box key ,box value ,list alist );
list assoc(char* searchTerm ,list l );
bool equalBox(box a ,box b );
void displayList(list l ,int indent ,bool first );
void display(list l );
char* boxType(box b );
box makeBox();
pair makePair();
box boxString(char* s );
box boxSymbol(char* s );
box boxBool(bool boo );
box boxInt(int val );
void assertType(char* atype ,box abox ,int line ,char* file );
char* unBoxString(box b );
char* unBoxSymbol(box b );
bool unBoxBool(box b );
int unBoxInt(box b );
char* stringify_rec(box b );
char* stringify(box b );
bool hasTag(box aBox ,box key );
box getTag(box aBox ,box key );
box getTagFail(box aBox ,box key ,box onFail );
bool assocExists(char* key ,box aBox );
box assocFail(char* key ,box aBox ,box onFail );
box assocPanic(char* key ,box aBox ,char* onFail );
box setTag(box key ,list val ,box aStruct );
list filterVoid(list l );
list filterTokens(list l );
box finish_token(char* prog ,int start ,int len ,int line ,int column ,char* filename );
char* readString(char* prog ,int start ,int len );
char* readComment(char* prog ,int start ,int len );
bool isWhiteSpace(char* s );
bool isLineBreak(char* s );
int incForNewLine(box token ,int val );
box annotateReadPosition(char* filename ,int linecount ,int column ,int start ,box newBox );
list scan(char* prog ,int start ,int len ,int linecount ,int column ,char* filename );
bool isOpenBrace(box b );
char* openBrace();
bool isCloseBrace(box b );
char* closeBrace();
list sexprTree(list l );
list skipList(list l );
list readSexpr(char* aStr ,char* filename );
box caar(list l );
box cadr(list l );
box caddr(list l );
box cadddr(list l );
box caddddr(list l );
box cddr(list l );
box first(list l );
box second(list l );
box third(list l );
box fourth(list l );
box fifth(list l );
list makeNode(char* name ,char* subname ,list code ,list children );
list addToNode(box key ,box val ,list node );
list makeStatementNode(char* name ,char* subname ,list code ,list children ,box functionName );
list astExpression(list tree );
list astSubExpression(list tree );
list astIf(list tree ,box fname );
list astSetStruct(list tree );
list astSet(list tree );
list astGetStruct(list tree );
list astReturnVoid(box fname );
list astStatement(list tree ,box fname );
list astBody(list tree ,box fname );
void linePanic(char* line ,char* message );
list astFunction(list tree );
list astFunctionList(list tree );
list astFunctions(list tree );
list loadLib(char* path );
list astInclude(list tree );
list astIncludeList(list tree );
list astIncludes(list tree );
list astStruct(list tree );
list astType(list tree );
list astTypeList(list tree );
list astTypes(list tree );
list declarationsof(list ass );
list codeof(list ass );
list functionNameof(list ass );
list nodeof(list ass );
list lineof(list ass );
list subnameof(list ass );
list nameof(list ass );
list childrenof(list ass );
bool isNode(list val );
bool truthy(box aVal );
bool isNotFalse(box aVal );
bool isLeaf(list n );
void printIndent(int ii );
void newLine(int indent );
list noStackTrace();
box toStr(box thing );
box listLast(list alist );
list treeCompile(char* filename );
list astBuild(char* filename );
void astCompile(char* filename );
list concatLists(list seq1 ,list seq2 );
list alistKeys(list alist );
list mergeIncludes(list program );
list merge_recur(list incs ,list program );
list mergeInclude(list inc ,list program );
list macrowalk(list l );
list macrosingle(list l ,char* search ,char* replace );
list doBoxList(list l );
list doStringList(list l );
list argList(int count ,int pos ,char** args );
list listReverse(list l );
bool inList(box item ,list l );
bool equalList(list a ,list b );
list reverseRec(list oldL ,list newL );
list reverseList(list l );
void tron();
void troff();
void stron();
void stroff();
list loadQuon(char* filename );
list getIncludes(list program );
list getTypes(list program );
list getFunctions(list program );
list loadIncludes(list tree );
list buildProg(list includes ,list types ,list functions );
list numbers(int num );
char* lexType(box abox );
void perlLeaf(list thisNode ,int indent );
void perlStructGetterExpression(list thisNode ,int indent );
void perlExpression(list node ,int indent );
void perlRecurList(list expr ,int indent );
void perlSubExpression(list tree ,int indent );
void perlIf(list node ,int indent );
void perlSetStruct(list node ,int indent );
void perlGetStruct(list node ,int indent );
void perlSet(list node ,int indent );
void assertNode(list node );
void perlStatement(list node ,int indent );
void perlBody(list tree ,int indent );
void perlDeclarations(list decls ,int indent );
void perlFunction(list node );
void perlForwardDeclaration(list node );
void perlForwardDeclarations(list tree );
void perlFunctions(list tree );
char* dollar();
char* atSym();
void perlIncludes(list nodes );
void perlTypeDecl(list l );
void perlStructComponents(list node );
void perlStruct(list node );
box perlTypeMap(box aSym );
box perlConstMap(box aSym );
box perlFuncMap(box aSym );
void perlType(list node );
void perlTypes(list nodes );
void perlFunctionArgs(list tree );
void perlCompile(char* filename );
void ansiFunctionArgs(list tree );
void ansiLeaf(list thisNode ,int indent );
void ansiStructGetterExpression(list thisNode ,int indent );
void ansiExpression(list node ,int indent );
void ansiRecurList(list expr ,int indent );
void ansiSubExpression(list tree ,int indent );
void ansiIf(list node ,int indent );
void ansiSetStruct(list node ,int indent );
void ansiGetStruct(list node ,int indent );
void ansiSet(list node ,int indent );
void ansiStatement(list node ,int indent );
void ansiBody(list tree ,int indent );
void ansiDeclarations(list decls ,int indent );
void ansiFunction(list node );
void ansiForwardDeclaration(list node );
void ansiForwardDeclarations(list tree );
void ansiFunctions(list tree );
void ansiIncludes(list nodes );
void ansiTypeDecl(list l );
void ansiStructComponents(list node );
void ansiStruct(list node );
box ansiTypeMap(box aSym );
box ansiFuncMap(box aSym );
void ansiType(list node );
void ansiTypes(list nodes );
void uniqueTarget(char* a ,char* b );
void ansiCompile(char* filename );
void test0();
void test1();
void test2_do(char* message );
void test2();
void test3_do(int b ,char* c );
void test3();
char* test4_do();
char* returnThis(char* returnMessage );
void test4();
void test5();
void test6();
int test7_do(int count );
void test7();
void beer();
char* plural(int num );
int beers(int count );
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
list concatenateLists(list oldL ,list newL );
void test20();
void test21();
void nodeFunctionArgs(list tree );
void nodeLeaf(list thisNode ,int indent );
void nodeStructGetterExpression(list thisNode ,int indent );
void nodeExpression(list node ,int indent );
void nodeRecurList(list expr ,int indent );
void nodeSubExpression(list tree ,int indent );
void nodeIf(list node ,int indent );
void nodeGetStruct(list node ,int indent );
void nodeSet(list node ,int indent );
void nodeSetStruct(list node ,int indent );
void nodeStatement(list node ,int indent );
void nodeBody(list tree ,int indent );
void nodeDeclarations(list decls ,int indent );
void nodeFunction(list node );
void nodeForwardDeclaration(list node );
void nodeForwardDeclarations(list tree );
void nodeFunctions(list tree );
void nodeIncludes(list nodes );
void nodeTypeDecl(list l );
void nodeStructComponents(list node );
void nodeStruct(list node );
box nodeTypeMap(box aSym );
box nodeFuncMap(box aSym );
void nodeType(list node );
void nodeTypes(list nodes );
void nodeCompile(char* filename );
void javaFunctionArgs(list tree );
void javaLeaf(list thisNode ,int indent );
void javaStructGetterExpression(list thisNode ,int indent );
void javaExpression(list node ,int indent );
void javaRecurList(list expr ,int indent );
void javaSubExpression(list tree ,int indent );
void javaIf(list node ,int indent );
void javaSetStruct(list node ,int indent );
void javaGetStruct(list node ,int indent );
void javaSet(list node ,int indent );
void javaStatement(list node ,int indent );
void javaBody(list tree ,int indent );
void javaDeclarations(list decls ,int indent );
void javaFunction(list node );
void javaFunctions(list tree );
void javaIncludes(list nodes );
void javaTypeDecl(list l );
void javaStructComponents(list node );
void javaStruct(list node );
box javaTypeMap(box aSym );
box javaTypesNoDeclare();
box javaFuncMap(box aSym );
void javaType(list node );
void javaTypes(list nodes );
void javaCompile(char* filename );
void luaFunctionArgs(int indent ,list tree );
void luaFunction(int indent ,list functionDefinition );
void luaDeclarations(int indent ,list declarations );
void luaExpressionStart(int indent ,list program );
void luaExpression(int indent ,list program );
void luaStatement(int indent ,list statement );
void luaBody(char* local_caller ,int indent ,list program );
void luaFunctions(int indent ,list program );
void luaProgram(list program );
void luaIncludes(list nodes );
void luaCompile(char* filename );
void imaFunctionArgs(int indent ,list tree );
void imaFunction(int indent ,list functionDefinition );
void imaDeclarations(int indent ,list declarations );
void imaExpressionStart(int indent ,list program );
void imaExpression(int indent ,list program );
void imaStatement(int indent ,list statement );
void imaBody(char* local_caller ,int indent ,list program );
void imaFunctions(int indent ,list program );
void imaTypeDecl(list l );
void imaStructComponents(list node );
void imaStruct(list node );
box imaTypeMap(box aSym );
void imaType(list node );
void imaTypes(int indent ,list nodes );
void imaProgram(list program );
void imaIncludes(int indent ,list nodes );
void imaCompile(char* filename );
int start();

//End forward declarations



//Building function add from line: 19

int add(int a ,int b ) {
  
if (globalTrace)
    printf("add at base.qon:19 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:19");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(sub(a , sub(0 , b )));

if (globalTrace)
    printf("Leaving add\n");

}


//Building function addf from line: 20

float addf(float a ,float b ) {
  
if (globalTrace)
    printf("addf at base.qon:20 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:20");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(subf(a , subf(0 , b )));

if (globalTrace)
    printf("Leaving addf\n");

}


//Building function sub1 from line: 21

int sub1(int a ) {
  
if (globalTrace)
    printf("sub1 at base.qon:21 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:21");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(sub(a , 1 ));

if (globalTrace)
    printf("Leaving sub1\n");

}


//Building function add1 from line: 22

int add1(int a ) {
  
if (globalTrace)
    printf("add1 at base.qon:22 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:22");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(add(a , 1 ));

if (globalTrace)
    printf("Leaving add1\n");

}


//Building function clone from line: 24

box clone(box b ) {
  box newb = NULL ;

if (globalTrace)
    printf("clone at base.qon:24 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb = makeBox ();

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:29");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->typ = b->typ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:30");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->tag = b->tag;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:31");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->lis = b->lis;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:32");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->str = b->str;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:33");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->i = b->i;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:34");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->lengt = b->lengt;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:35");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(newb );

if (globalTrace)
    printf("Leaving clone\n");

}


//Building function newVoid from line: 38

box newVoid() {
  box newb = NULL ;

if (globalTrace)
    printf("newVoid at base.qon:38 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:42");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb = makeBox ();

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:43");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->voi = true ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:44");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newb->typ = "void" ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:45");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(newb );

if (globalTrace)
    printf("Leaving newVoid\n");

}


//Building function cons from line: 47

list cons(box data ,list l ) {
  pair p = NULL ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:49");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  p = makePair ();

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:50");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  p->cdr = l ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:51");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  p->car = data ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:52");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  p->typ = "list" ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:53");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(p );

}


//Building function stackDump from line: 55

void stackDump() {
  
if (globalTrace)
    printf("stackDump at base.qon:55 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:56");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("" );

if (globalTrace)
    printf("Leaving stackDump\n");

}


//Building function nop from line: 60

void nop() {
  
if (globalTrace)
    printf("nop at base.qon:60 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:61");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("" );

if (globalTrace)
    printf("Leaving nop\n");

}


//Building function car from line: 63

box car(list l ) {
  
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:65");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assertType("list" , l , 65 , "base.qon" );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:68");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Cannot call car on empty list!\n" );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:69");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Cannot call car on empty list!\n" );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:70");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(NULL );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(l->car)) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:73");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(NULL );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:74");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(l->car);

    };

  };

}


//Building function cdr from line: 76

list cdr(list l ) {
  
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:78");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assertType("list" , l , 78 , "base.qon" );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:81");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Attempt to cdr an empty list!!!!\n" );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:82");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Attempt to cdr an empty list!!!!\n" );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:83");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(NULL );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:84");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(l->cdr);

  };

}


//Building function isList from line: 86

bool isList(box b ) {
  
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:90");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(true );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:91");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(equalString("list" , b->typ));

  };

}


//Building function emptyList from line: 93

list emptyList() {
  
if (globalTrace)
    printf("emptyList at base.qon:93 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:93");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(NULL );

if (globalTrace)
    printf("Leaving emptyList\n");

}


//Building function isEmpty from line: 95

bool isEmpty(box b ) {
  
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:98");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(true );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:100");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(false );

  };

}


//Building function listLength from line: 102

int listLength(list l ) {
  
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:107");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(0 );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:108");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(add1(listLength(cdr(l ))));

  };

}


//Building function alistCons from line: 111

list alistCons(box key ,box value ,list alist ) {
  
if (globalTrace)
    printf("alistCons at base.qon:111 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:112");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cons(cons(key , value ), alist ));

if (globalTrace)
    printf("Leaving alistCons\n");

}


//Building function assoc from line: 114

list assoc(char* searchTerm ,list l ) {
  list elem = NULL ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:116");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assertType("list" , l , 116 , "base.qon" );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:119");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(boxBool(false ));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:121");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    elem = car(l );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:122");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    assertType("list" , elem , 122 , "base.qon" );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isEmpty(elem )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:124");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(assoc(searchTerm , cdr(l )));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:126");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( false ) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:126");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("Comparing %s and %s\n" , searchTerm , stringify(car(elem )));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:126");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("" );

      };

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(searchTerm , stringify(car(elem )))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:130");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(elem );

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:131");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(assoc(searchTerm , cdr(l )));

      };

    };

  };

}


//Building function equalBox from line: 133

bool equalBox(box a ,box b ) {
  
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(b )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:136");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(false );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("string" , boxType(a ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:139");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(equalString(unBoxString(a ), stringify(b )));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("bool" , boxType(a ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:142");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(andBool(unBoxBool(a ), unBoxBool(b )));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("symbol" , boxType(a ))) {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("symbol" , boxType(b ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:147");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return(equalString(unBoxSymbol(a ), unBoxSymbol(b )));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:148");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return(false );

          };

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("int" , boxType(a ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:151");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return(equal(unBoxInt(a ), unBoxInt(b )));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:152");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return(false );

          };

        };

      };

    };

  };

}


//Building function displayList from line: 154

void displayList(list l ,int indent ,bool first ) {
  box val = NULL ;

if (globalTrace)
    printf("displayList at base.qon:154 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l )) {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isEmpty(l )) {        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return;

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:164");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( first ) {
        } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:166");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf(" " );

        };

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:167");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        val = car(l );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( isList(val )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:170");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:171");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("%s" , openBrace ());

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:172");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          displayList(car(l ), add1(indent ), true );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:173");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("%s" , closeBrace ());

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:174");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          displayList(cdr(l ), indent , false );

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("string" , val->typ)) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:177");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("\"%s\"" , unBoxString(val ));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:178");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s" , stringify(val ));

          };

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:179");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          displayList(cdr(l ), indent , false );

        };

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("string" , l->typ)) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:182");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("\"%s\"" , unBoxString(l ));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:183");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s" , stringify(l ));

      };

    };

  };

if (globalTrace)
    printf("Leaving displayList\n");

}


//Building function display from line: 185

void display(list l ) {
  
if (globalTrace)
    printf("display at base.qon:185 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:188");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("nil " );
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:191");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("[" );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:191");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      displayList(l , 0 , true );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:191");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("]" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:192");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      displayList(l , 0 , true );

    };

  };

if (globalTrace)
    printf("Leaving display\n");

}


//Building function boxType from line: 197

char* boxType(box b ) {
  
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:197");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(b->typ);

}


//Building function makeBox from line: 198

box makeBox() {
  box b = NULL ;

if (globalTrace)
    printf("makeBox at base.qon:198 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:200");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = malloc(sizeof(Box));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:201");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->tag = NULL ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:202");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->car = NULL ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:203");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->cdr = NULL ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:204");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->lis = NULL ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:205");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "None - error!" ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:206");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(b );

if (globalTrace)
    printf("Leaving makeBox\n");

}


//Building function makePair from line: 209

pair makePair() {
  
if (globalTrace)
    printf("makePair at base.qon:209 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:211");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(makeBox ());

if (globalTrace)
    printf("Leaving makePair\n");

}


//Building function boxString from line: 215

box boxString(char* s ) {
  box b = NULL ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:219");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = makeBox ();

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:220");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->str = s ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:221");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->lengt = string_length(s );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:222");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "string" ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:223");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(b );

}


//Building function boxSymbol from line: 225

box boxSymbol(char* s ) {
  box b = NULL ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:229");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = boxString(s );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:230");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "symbol" ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:231");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(b );

}


//Building function boxBool from line: 234

box boxBool(bool boo ) {
  box b = NULL ;

if (globalTrace)
    printf("boxBool at base.qon:234 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:238");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = makeBox ();

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:239");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->boo = boo ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:240");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "bool" ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:241");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(b );

if (globalTrace)
    printf("Leaving boxBool\n");

}


//Building function boxInt from line: 243

box boxInt(int val ) {
  box b = NULL ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:247");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = makeBox ();

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:248");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->i = val ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:249");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->typ = "int" ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:250");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(b );

}


//Building function assertType from line: 252

void assertType(char* atype ,box abox ,int line ,char* file ) {
  
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(abox )) {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(atype , "nil" )) {      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return;

    } else {      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return;

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(atype , boxType(abox ))) {      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return;

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:260");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("Assertion failure at line %d, in file %s: provided value is not a '%s'!  It was actually (%s):" , line , file , atype , abox->typ);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:261");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(abox );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:262");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      panic("Invalid type!" );

    };

  };

}


//Building function unBoxString from line: 264

char* unBoxString(box b ) {
  
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:265");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assertType("string" , b , 265 , "base.qon" );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:265");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(b->str);

}


//Building function unBoxSymbol from line: 267

char* unBoxSymbol(box b ) {
  
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:267");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(b->str);

}


//Building function unBoxBool from line: 268

bool unBoxBool(box b ) {
  
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:268");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(b->boo);

}


//Building function unBoxInt from line: 269

int unBoxInt(box b ) {
  
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:269");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(b->i);

}


//Building function stringify_rec from line: 271

char* stringify_rec(box b ) {
  
if (globalTrace)
    printf("stringify_rec at base.qon:271 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:274");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return("" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:276");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(stringConcatenate(stringify(car(b )), stringConcatenate(" " , stringify_rec(cdr(b )))));

  };

if (globalTrace)
    printf("Leaving stringify_rec\n");

}


//Building function stringify from line: 283

char* stringify(box b ) {
  
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(b )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:286");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return("()" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("string" , boxType(b ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:289");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(unBoxString(b ));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("bool" , boxType(b ))) {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( unBoxBool(b )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:293");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return("true" );

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:293");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return("false" );

        };

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("int" , boxType(b ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:296");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return(intToString(unBoxInt(b )));

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("symbol" , boxType(b ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:299");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return(unBoxSymbol(b ));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalString("list" , boxType(b ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:303");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              return(stringConcatenate("(" , stringConcatenate(stringify(car(b )), stringConcatenate(" " , stringConcatenate(stringify_rec(cdr(b )), ")" )))));

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:309");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              return(stringConcatenate("Unsupported type: " , boxType(b )));

            };

          };

        };

      };

    };

  };

}


//Building function hasTag from line: 314

bool hasTag(box aBox ,box key ) {
  
if (globalTrace)
    printf("hasTag at base.qon:314 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(aBox )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:317");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(false );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:318");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(isNotFalse(assoc(stringify(key ), aBox->tag)));

  };

if (globalTrace)
    printf("Leaving hasTag\n");

}


//Building function getTag from line: 320

box getTag(box aBox ,box key ) {
  
if (globalTrace)
    printf("getTag at base.qon:320 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:322");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( false ) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:324");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Getting %s from: " , stringify(key ));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:325");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(alistKeys(aBox->tag));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:326");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:328");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("" );

  };

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:330");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(assoc(stringify(key ), aBox->tag)));

if (globalTrace)
    printf("Leaving getTag\n");

}


//Building function getTagFail from line: 332

box getTagFail(box aBox ,box key ,box onFail ) {
  
if (globalTrace)
    printf("getTagFail at base.qon:332 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( hasTag(aBox , key )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:335");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(getTag(aBox , key ));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:336");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(onFail );

  };

if (globalTrace)
    printf("Leaving getTagFail\n");

}


//Building function assocExists from line: 338

bool assocExists(char* key ,box aBox ) {
  
if (globalTrace)
    printf("assocExists at base.qon:338 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(aBox )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:342");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(false );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:343");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(isNotFalse(assoc(key , aBox )));

  };

if (globalTrace)
    printf("Leaving assocExists\n");

}


//Building function assocFail from line: 346

box assocFail(char* key ,box aBox ,box onFail ) {
  
if (globalTrace)
    printf("assocFail at base.qon:346 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( assocExists(key , aBox )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:349");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(assoc(key , aBox ));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:350");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(boxString(key ), onFail ));

  };

if (globalTrace)
    printf("Leaving assocFail\n");

}


//Building function assocPanic from line: 352

box assocPanic(char* key ,box aBox ,char* onFail ) {
  
if (globalTrace)
    printf("assocPanic at base.qon:352 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( assocExists(key , aBox )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:355");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(assoc(key , aBox ));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:356");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic(onFail );

  };

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:357");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  panic("Inconceivable" );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:359");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(NULL );

if (globalTrace)
    printf("Leaving assocPanic\n");

}


//Building function setTag from line: 365

box setTag(box key ,list val ,box aStruct ) {
  
if (globalTrace)
    printf("setTag at base.qon:365 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:367");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  aStruct->tag = alistCons(key , val , aStruct->tag);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:368");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(aStruct );

if (globalTrace)
    printf("Leaving setTag\n");

}


//Building function filterVoid from line: 375

list filterVoid(list l ) {
  box token = NULL ;

if (globalTrace)
    printf("filterVoid at base.qon:375 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:380");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(emptyList ());

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:382");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token = car(l );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("void" , token->typ)) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:384");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(filterVoid(cdr(l )));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:385");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cons(token , filterVoid(cdr(l ))));

    };

  };

if (globalTrace)
    printf("Leaving filterVoid\n");

}


//Building function filterTokens from line: 387

list filterTokens(list l ) {
  box token = NULL ;

if (globalTrace)
    printf("filterTokens at base.qon:387 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:392");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(emptyList ());

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:394");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token = car(l );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(boxType(token ), "symbol" )) {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("__LINE__" , stringify(token ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:399");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(cons(getTagFail(token , boxString("line" ), boxInt(-1 )), filterTokens(cdr(l ))));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("__COLUMN__" , stringify(token ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:406");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return(cons(getTagFail(token , boxString("column" ), boxInt(-1 )), filterTokens(cdr(l ))));

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString("__FILE__" , stringify(token ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:413");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return(cons(getTagFail(token , boxString("filename" ), boxString("Unknown file" )), filterTokens(cdr(l ))));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:418");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return(cons(token , filterTokens(cdr(l ))));

          };

        };

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:419");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cons(token , filterTokens(cdr(l ))));

    };

  };

if (globalTrace)
    printf("Leaving filterTokens\n");

}


//Building function finish_token from line: 421

box finish_token(char* prog ,int start ,int len ,int line ,int column ,char* filename ) {
  box token = NULL ;

if (globalTrace)
    printf("finish_token at base.qon:421 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(len , 0 )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:425");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token = boxSymbol(sub_string(prog , start , len ));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:427");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token->tag = alistCons(boxString("filename" ), boxString(filename ), alistCons(boxString("column" ), boxInt(column ), alistCons(boxString("line" ), boxInt(line ), alistCons(boxString("totalCharPos" ), boxInt(start ), NULL ))));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:433");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(token );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:434");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(newVoid ());

  };

if (globalTrace)
    printf("Leaving finish_token\n");

}


//Building function readString from line: 436

char* readString(char* prog ,int start ,int len ) {
  char* token = "" ;

if (globalTrace)
    printf("readString at base.qon:436 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:438");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  token = sub_string(prog , sub1(add(start , len )), 1 );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("\"" , token )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:440");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(sub_string(prog , start , sub1(len )));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("\\" , token )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:443");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(readString(prog , start , add(2 , len )));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:444");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(readString(prog , start , add1(len )));

    };

  };

if (globalTrace)
    printf("Leaving readString\n");

}


//Building function readComment from line: 447

char* readComment(char* prog ,int start ,int len ) {
  char* token = "" ;

if (globalTrace)
    printf("readComment at base.qon:447 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:449");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  token = sub_string(prog , sub1(add(start , len )), 1 );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isLineBreak(token )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:451");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(sub_string(prog , start , sub1(len )));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:452");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(readComment(prog , start , add1(len )));

  };

if (globalTrace)
    printf("Leaving readComment\n");

}


//Building function isWhiteSpace from line: 455

bool isWhiteSpace(char* s ) {
  
if (globalTrace)
    printf("isWhiteSpace at base.qon:455 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(" " , s )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:460");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(true );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("\t" , s )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:463");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(true );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("\n" , s )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:466");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(true );

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString("\r" , s )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:469");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return(true );

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:470");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return(false );

        };

      };

    };

  };

if (globalTrace)
    printf("Leaving isWhiteSpace\n");

}


//Building function isLineBreak from line: 472

bool isLineBreak(char* s ) {
  
if (globalTrace)
    printf("isLineBreak at base.qon:472 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("\n" , s )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:475");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(true );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString("\r" , s )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:477");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(true );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:477");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(false );

    };

  };

if (globalTrace)
    printf("Leaving isLineBreak\n");

}


//Building function incForNewLine from line: 479

int incForNewLine(box token ,int val ) {
  
if (globalTrace)
    printf("incForNewLine at base.qon:479 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("\n" , stringify(token ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:484");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(add1(val ));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:485");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(val );

  };

if (globalTrace)
    printf("Leaving incForNewLine\n");

}


//Building function annotateReadPosition from line: 486

box annotateReadPosition(char* filename ,int linecount ,int column ,int start ,box newBox ) {
  
if (globalTrace)
    printf("annotateReadPosition at base.qon:486 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:488");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(setTag(boxString("filename" ), boxString(filename ), setTag(boxString("column" ), boxInt(column ), setTag(boxString("line" ), boxInt(linecount ), setTag(boxString("totalCharPos" ), boxInt(start ), newBox )))));

if (globalTrace)
    printf("Leaving annotateReadPosition\n");

}


//Building function scan from line: 498

list scan(char* prog ,int start ,int len ,int linecount ,int column ,char* filename ) {
  box token = NULL ;
char* newString = "" ;
box newBox = NULL ;

if (globalTrace)
    printf("scan at base.qon:498 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:500");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( false ) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:500");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Scanning: line %d:%d\n" , linecount , column );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:500");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("" );

  };

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(string_length(prog ), sub(start , sub(0 , len )))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:503");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token = boxSymbol(sub_string(prog , sub1(add(start , len )), 1 ));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:504");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    token->tag = alistCons(boxString("totalCharPos" ), boxInt(start ), NULL );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isOpenBrace(token )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:507");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cons(finish_token(prog , start , sub1(len ), linecount , column , filename ), cons(boxSymbol(openBrace ()), scan(prog , add1(start ), 1 , linecount , add1(column ), filename ))));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isCloseBrace(token )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:513");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(cons(finish_token(prog , start , sub1(len ), linecount , column , filename ), cons(annotateReadPosition(filename , linecount , column , start , boxSymbol(closeBrace ())), scan(prog , add(start , len ), 1 , linecount , add1(column ), filename ))));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( isWhiteSpace(stringify(token ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:520");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return(cons(finish_token(prog , start , sub1(len ), linecount , column , filename ), scan(prog , add(start , len ), 1 , incForNewLine(token , linecount ), 0 , filename )));

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol(";" ), token )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:525");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return(scan(prog , add(start , add1(add1(string_length(readComment(prog , add1(start ), len ))))), 1 , add1(linecount ), 0 , filename ));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("\"" ), token )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:529");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              newString = readString(prog , add1(start ), len );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:530");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              newBox = annotateReadPosition(filename , linecount , column , start , boxString(newString ));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:532");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              return(cons(newBox , scan(prog , add(start , add1(add1(string_length(newString )))), 1 , linecount , add1(column ), filename )));

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:534");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              return(scan(prog , start , sub(len , -1 ), linecount , add1(column ), filename ));

            };

          };

        };

      };

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:535");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(emptyList ());

  };

if (globalTrace)
    printf("Leaving scan\n");

}


//Building function isOpenBrace from line: 538

bool isOpenBrace(box b ) {
  
if (globalTrace)
    printf("isOpenBrace at base.qon:538 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxSymbol(openBrace ()), b )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:541");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(true );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxSymbol("[" ), b )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:544");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(true );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:545");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(false );

    };

  };

if (globalTrace)
    printf("Leaving isOpenBrace\n");

}


//Building function openBrace from line: 546

char* openBrace() {
  
if (globalTrace)
    printf("openBrace at base.qon:546 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:546");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return("(" );

if (globalTrace)
    printf("Leaving openBrace\n");

}


//Building function isCloseBrace from line: 548

bool isCloseBrace(box b ) {
  
if (globalTrace)
    printf("isCloseBrace at base.qon:548 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxSymbol(closeBrace ()), b )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:553");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(true );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxSymbol("]" ), b )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:556");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(true );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:557");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(false );

    };

  };

if (globalTrace)
    printf("Leaving isCloseBrace\n");

}


//Building function closeBrace from line: 558

char* closeBrace() {
  
if (globalTrace)
    printf("closeBrace at base.qon:558 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:558");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(")" );

if (globalTrace)
    printf("Leaving closeBrace\n");

}


//Building function sexprTree from line: 560

list sexprTree(list l ) {
  box b = NULL ;

if (globalTrace)
    printf("sexprTree at base.qon:560 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:563");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(emptyList ());

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:565");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    b = car(l );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isOpenBrace(b )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:568");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cons(sexprTree(cdr(l )), sexprTree(skipList(cdr(l )))));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isCloseBrace(b )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:571");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(emptyList ());

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:573");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(setTag(boxString("line" ), getTagFail(b , boxString("line" ), boxInt(-1 )), cons(b , sexprTree(cdr(l )))));

      };

    };

  };

if (globalTrace)
    printf("Leaving sexprTree\n");

}


//Building function skipList from line: 579

list skipList(list l ) {
  box b = NULL ;

if (globalTrace)
    printf("skipList at base.qon:579 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:582");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(emptyList ());

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:584");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    b = car(l );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isOpenBrace(b )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:586");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(skipList(skipList(cdr(l ))));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isCloseBrace(b )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:589");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(cdr(l ));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:590");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(skipList(cdr(l )));

      };

    };

  };

if (globalTrace)
    printf("Leaving skipList\n");

}


//Building function readSexpr from line: 594

list readSexpr(char* aStr ,char* filename ) {
  list tokens = NULL ;
list as = NULL ;

if (globalTrace)
    printf("readSexpr at base.qon:594 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:596");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tokens = emptyList ();

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:597");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tokens = filterTokens(filterVoid(scan(aStr , 0 , 1 , 0 , 0 , filename )));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:598");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  as = sexprTree(tokens );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:599");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(car(as ));

if (globalTrace)
    printf("Leaving readSexpr\n");

}


//Building function caar from line: 604

box caar(list l ) {
  
if (globalTrace)
    printf("caar at base.qon:604 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:604");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(car(car(l )));

if (globalTrace)
    printf("Leaving caar\n");

}


//Building function cadr from line: 605

box cadr(list l ) {
  
if (globalTrace)
    printf("cadr at base.qon:605 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:605");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(car(cdr(l )));

if (globalTrace)
    printf("Leaving cadr\n");

}


//Building function caddr from line: 606

box caddr(list l ) {
  
if (globalTrace)
    printf("caddr at base.qon:606 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:606");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(car(cdr(cdr(l ))));

if (globalTrace)
    printf("Leaving caddr\n");

}


//Building function cadddr from line: 607

box cadddr(list l ) {
  
if (globalTrace)
    printf("cadddr at base.qon:607 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:607");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(car(cdr(cdr(cdr(l )))));

if (globalTrace)
    printf("Leaving cadddr\n");

}


//Building function caddddr from line: 608

box caddddr(list l ) {
  
if (globalTrace)
    printf("caddddr at base.qon:608 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:608");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(car(cdr(cdr(cdr(cdr(l ))))));

if (globalTrace)
    printf("Leaving caddddr\n");

}


//Building function cddr from line: 609

box cddr(list l ) {
  
if (globalTrace)
    printf("cddr at base.qon:609 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:609");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(cdr(l )));

if (globalTrace)
    printf("Leaving cddr\n");

}


//Building function first from line: 610

box first(list l ) {
  
if (globalTrace)
    printf("first at base.qon:610 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:610");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(car(l ));

if (globalTrace)
    printf("Leaving first\n");

}


//Building function second from line: 611

box second(list l ) {
  
if (globalTrace)
    printf("second at base.qon:611 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:611");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cadr(l ));

if (globalTrace)
    printf("Leaving second\n");

}


//Building function third from line: 612

box third(list l ) {
  
if (globalTrace)
    printf("third at base.qon:612 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:612");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(caddr(l ));

if (globalTrace)
    printf("Leaving third\n");

}


//Building function fourth from line: 613

box fourth(list l ) {
  
if (globalTrace)
    printf("fourth at base.qon:613 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:613");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cadddr(l ));

if (globalTrace)
    printf("Leaving fourth\n");

}


//Building function fifth from line: 614

box fifth(list l ) {
  
if (globalTrace)
    printf("fifth at base.qon:614 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:614");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(caddddr(l ));

if (globalTrace)
    printf("Leaving fifth\n");

}


//Building function makeNode from line: 620

list makeNode(char* name ,char* subname ,list code ,list children ) {
  
if (globalTrace)
    printf("makeNode at base.qon:620 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:622");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cons(boxSymbol("node" ), alistCons(boxSymbol("line" ), getTagFail(code , boxString("line" ), boxInt(-1 )), cons(cons(boxSymbol("name" ), boxString(name )), cons(cons(boxSymbol("subname" ), boxString(subname )), cons(cons(boxSymbol("code" ), code ), alistCons(boxSymbol("children" ), children , emptyList ())))))));

if (globalTrace)
    printf("Leaving makeNode\n");

}


//Building function addToNode from line: 636

list addToNode(box key ,box val ,list node ) {
  
if (globalTrace)
    printf("addToNode at base.qon:636 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:638");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cons(boxSymbol("node" ), alistCons(key , val , cdr(node ))));

if (globalTrace)
    printf("Leaving addToNode\n");

}


//Building function makeStatementNode from line: 641

list makeStatementNode(char* name ,char* subname ,list code ,list children ,box functionName ) {
  
if (globalTrace)
    printf("makeStatementNode at base.qon:641 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:643");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(addToNode(boxSymbol("functionName" ), functionName , makeNode(name , subname , code , children )));

if (globalTrace)
    printf("Leaving makeStatementNode\n");

}


//Building function astExpression from line: 646

list astExpression(list tree ) {
  
if (globalTrace)
    printf("astExpression at base.qon:646 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(tree )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:650");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(makeNode("expression" , "expression" , NULL , astSubExpression(tree )));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:652");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(astSubExpression(tree ));

  };

if (globalTrace)
    printf("Leaving astExpression\n");

}


//Building function astSubExpression from line: 654

list astSubExpression(list tree ) {
  
if (globalTrace)
    printf("astSubExpression at base.qon:654 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:657");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(emptyList ());

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(tree )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:661");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cons(astExpression(car(tree )), astSubExpression(cdr(tree ))));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:663");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(makeNode("expression" , "leaf" , tree , NULL ));

    };

  };

if (globalTrace)
    printf("Leaving astSubExpression\n");

}


//Building function astIf from line: 665

list astIf(list tree ,box fname ) {
  
if (globalTrace)
    printf("astIf at base.qon:665 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("then" ), car(second(tree )))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:668");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nop ();

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:670");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Error at %s:%s!  If statement is missing the true branch.\n\n" , stringify(getTag(car(first(tree )), boxString("filename" ))), stringify(getTag(car(first(tree )), boxString("line" ))));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:671");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Missing true branch in if statement!  All if statements must have a true and false branch, like this:\n\n(if hungryForApples\n(then (printf \"yes!\"))\n(else (printf \"no!\")))\n\n\n" );

  };

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("else" ), car(third(tree )))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:674");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nop ();

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:676");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Error at %s:%s!  If statement is missing the false branch.\n\n" , stringify(getTag(car(first(tree )), boxString("filename" ))), stringify(getTag(car(first(tree )), boxString("line" ))));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:677");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Missing false branch in if statement!  All if statements must have a true and false branch, like this:\n\n(if hungryForApples\n(then (printf \"yes!\"))\n(else (printf \"no!\")))\n\n\n" );

  };

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:678");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(makeNode("statement" , "if" , tree , cons(cons(astExpression(first(tree )), NULL ), cons(astBody(cdr(second(tree )), fname ), cons(astBody(cdr(third(tree )), fname ), NULL )))));

if (globalTrace)
    printf("Leaving astIf\n");

}


//Building function astSetStruct from line: 686

list astSetStruct(list tree ) {
  
if (globalTrace)
    printf("astSetStruct at base.qon:686 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:688");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(makeNode("statement" , "structSetter" , tree , astExpression(third(tree ))));

if (globalTrace)
    printf("Leaving astSetStruct\n");

}


//Building function astSet from line: 691

list astSet(list tree ) {
  
if (globalTrace)
    printf("astSet at base.qon:691 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:693");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(makeNode("statement" , "setter" , tree , astExpression(second(tree ))));

if (globalTrace)
    printf("Leaving astSet\n");

}


//Building function astGetStruct from line: 696

list astGetStruct(list tree ) {
  
if (globalTrace)
    printf("astGetStruct at base.qon:696 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:697");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(makeNode("expression" , "structGetter" , tree , NULL ));

if (globalTrace)
    printf("Leaving astGetStruct\n");

}


//Building function astReturnVoid from line: 699

list astReturnVoid(box fname ) {
  
if (globalTrace)
    printf("astReturnVoid at base.qon:699 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:701");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(makeStatementNode("statement" , "returnvoid" , NULL , NULL , fname ));

if (globalTrace)
    printf("Leaving astReturnVoid\n");

}


//Building function astStatement from line: 703

list astStatement(list tree ,box fname ) {
  
if (globalTrace)
    printf("astStatement at base.qon:703 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("if" ), car(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:706");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(astIf(cdr(tree ), fname ));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("set" ), car(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:709");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(astSet(cdr(tree )));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("get-struct" ), car(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:713");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("Choosing get-struct statement\n" );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:714");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(astGetStruct(cdr(tree )));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("set-struct" ), car(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:717");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          return(astSetStruct(cdr(tree )));

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxString("return" ), car(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equal(listLength(tree ), 1 )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:722");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              return(astReturnVoid(fname ));

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:724");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              return(makeStatementNode("statement" , "return" , tree , makeNode("expression" , "expression" , tree , astExpression(tree )), fname ));

            };

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:728");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            return(makeStatementNode("statement" , "statement" , tree , makeNode("expression" , "expression" , tree , astExpression(tree )), fname ));

          };

        };

      };

    };

  };

if (globalTrace)
    printf("Leaving astStatement\n");

}


//Building function astBody from line: 733

list astBody(list tree ,box fname ) {
  
if (globalTrace)
    printf("astBody at base.qon:733 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:736");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(emptyList ());

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:737");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(astStatement(car(tree ), fname ), astBody(cdr(tree ), fname )));

  };

if (globalTrace)
    printf("Leaving astBody\n");

}


//Building function linePanic from line: 739

void linePanic(char* line ,char* message ) {
  
if (globalTrace)
    printf("linePanic at base.qon:739 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:741");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("line %s: %s\n" , line , message );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:742");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  panic(message );

if (globalTrace)
    printf("Leaving linePanic\n");

}


//Building function astFunction from line: 745

list astFunction(list tree ) {
  char* line = "" ;
char* file = "" ;
box fname = NULL ;

if (globalTrace)
    printf("astFunction at base.qon:745 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:747");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fname = second(tree );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:750");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  line = stringify(getTag(fname , boxString("line" )));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:751");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  file = stringify(getTag(fname , boxString("filename" )));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(1 , listLength(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:752");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    linePanic(line , "Malformed function, seems to be empty" );

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(2 , listLength(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:753");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    linePanic(line , "Malformed function, expected function name" );

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(3 , listLength(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:754");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    linePanic(line , "Malformed function, expected argument list" );

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(4 , listLength(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:755");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    linePanic(line , "Malformed function, expected variable declarations" );

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(5 , listLength(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:756");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    linePanic(line , "Malformed function, expected body" );

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:757");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(alistCons(boxSymbol("line" ), getTag(fname , boxString("line" )), cons(cons(boxSymbol("name" ), boxString("function" )), cons(cons(boxSymbol("subname" ), second(tree )), cons(cons(boxSymbol("declarations" ), cdr(fourth(tree ))), cons(cons(boxSymbol("intype" ), third(tree )), cons(cons(boxSymbol("outtype" ), car(tree )), cons(cons(boxSymbol("children" ), astBody(cdr(fifth(tree )), fname )), emptyList ()))))))));

if (globalTrace)
    printf("Leaving astFunction\n");

}


//Building function astFunctionList from line: 775

list astFunctionList(list tree ) {
  
if (globalTrace)
    printf("astFunctionList at base.qon:775 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:778");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(emptyList ());

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:780");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(astFunction(car(tree )), astFunctionList(cdr(tree ))));

  };

if (globalTrace)
    printf("Leaving astFunctionList\n");

}


//Building function astFunctions from line: 783

list astFunctions(list tree ) {
  
if (globalTrace)
    printf("astFunctions at base.qon:783 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("functions" ), car(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:786");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(makeNode("functions" , "functions" , tree , astFunctionList(cdr(tree ))));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:787");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Functions section not found!  Every program must have a function section, even if you don't define any functions, although that is a rather pointless program.  Your function section should look like:'\n\n(return_type function_name (arg1 arg2 arg3 ...) (declare types) (body (statement)(statement)))\n\n\nThe function section must be directly after the types section." );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:788");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(NULL );

  };

if (globalTrace)
    printf("Leaving astFunctions\n");

}


//Building function loadLib from line: 791

list loadLib(char* path ) {
  char* programStr = "" ;
list tree = NULL ;
list library = NULL ;

if (globalTrace)
    printf("loadLib at base.qon:791 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:794");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(path );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:795");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr , path );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:796");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:797");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  library = alistCons(boxString("includes" ), astIncludes(first(tree )), alistCons(boxString("types" ), astTypes(second(tree )), alistCons(boxString("functions" ), astFunctions(third(tree )), NULL )));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:805");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(library );

if (globalTrace)
    printf("Leaving loadLib\n");

}


//Building function astInclude from line: 807

list astInclude(list tree ) {
  
if (globalTrace)
    printf("astInclude at base.qon:807 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:808");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(loadLib(stringify(tree )));

if (globalTrace)
    printf("Leaving astInclude\n");

}


//Building function astIncludeList from line: 810

list astIncludeList(list tree ) {
  
if (globalTrace)
    printf("astIncludeList at base.qon:810 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:813");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(emptyList ());

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:815");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(astInclude(car(tree )), astIncludeList(cdr(tree ))));

  };

if (globalTrace)
    printf("Leaving astIncludeList\n");

}


//Building function astIncludes from line: 817

list astIncludes(list tree ) {
  
if (globalTrace)
    printf("astIncludes at base.qon:817 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("includes" ), car(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:821");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(makeNode("includes" , "includes" , tree , astIncludeList(cdr(tree ))));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:822");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Includes section not found!  Every program must have an include section, even if you don't import any libraries.  Your include section should look like:'\n\n(includes file1.qon file.qon)\n\n\nThe includes section must be the first section of the file." );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:823");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(NULL );

  };

if (globalTrace)
    printf("Leaving astIncludes\n");

}


//Building function astStruct from line: 825

list astStruct(list tree ) {
  
if (globalTrace)
    printf("astStruct at base.qon:825 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:826");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(makeNode("type" , "struct" , tree , NULL ));

if (globalTrace)
    printf("Leaving astStruct\n");

}


//Building function astType from line: 828

list astType(list tree ) {
  
if (globalTrace)
    printf("astType at base.qon:828 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(cadr(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:831");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(astStruct(tree ));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:832");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(makeNode("type" , "type" , tree , NULL ));

  };

if (globalTrace)
    printf("Leaving astType\n");

}


//Building function astTypeList from line: 834

list astTypeList(list tree ) {
  
if (globalTrace)
    printf("astTypeList at base.qon:834 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:837");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(emptyList ());

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:838");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(astType(car(tree )), astTypeList(cdr(tree ))));

  };

if (globalTrace)
    printf("Leaving astTypeList\n");

}


//Building function astTypes from line: 840

list astTypes(list tree ) {
  
if (globalTrace)
    printf("astTypes at base.qon:840 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("types" ), car(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:843");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(makeNode("types" , "types" , tree , astTypeList(cdr(tree ))));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:845");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Types section not found!  Every program must have a types section, even if you don't define any types" );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:846");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Types section not found!  Every program must have a types section, even if you don't define any types" );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:847");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(boxString("!!!Fuck java" ));

  };

if (globalTrace)
    printf("Leaving astTypes\n");

}


//Building function declarationsof from line: 852

list declarationsof(list ass ) {
  
if (globalTrace)
    printf("declarationsof at base.qon:852 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:853");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(assocPanic("declarations" , cdr(ass ), "Cons list has no declarations key" )));

if (globalTrace)
    printf("Leaving declarationsof\n");

}


//Building function codeof from line: 855

list codeof(list ass ) {
  
if (globalTrace)
    printf("codeof at base.qon:855 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:856");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(assocPanic("code" , cdr(ass ), "Given cons list does not contain a code key" )));

if (globalTrace)
    printf("Leaving codeof\n");

}


//Building function functionNameof from line: 858

list functionNameof(list ass ) {
  
if (globalTrace)
    printf("functionNameof at base.qon:858 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:859");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(assoc("functionName" , cdr(ass ))));

if (globalTrace)
    printf("Leaving functionNameof\n");

}


//Building function nodeof from line: 861

list nodeof(list ass ) {
  
if (globalTrace)
    printf("nodeof at base.qon:861 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxBool(false ), assoc("node" , cdr(ass )))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:865");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Given list does not contain nodes" );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:866");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(boxBool(false ));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:867");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cdr(assoc("node" , cdr(ass ))));

  };

if (globalTrace)
    printf("Leaving nodeof\n");

}


//Building function lineof from line: 869

list lineof(list ass ) {
  
if (globalTrace)
    printf("lineof at base.qon:869 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:871");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(assocFail("line" , cdr(ass ), boxInt(-1 ))));

if (globalTrace)
    printf("Leaving lineof\n");

}


//Building function subnameof from line: 874

list subnameof(list ass ) {
  
if (globalTrace)
    printf("subnameof at base.qon:874 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:875");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(assoc("subname" , cdr(ass ))));

if (globalTrace)
    printf("Leaving subnameof\n");

}


//Building function nameof from line: 877

list nameof(list ass ) {
  
if (globalTrace)
    printf("nameof at base.qon:877 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:878");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(assoc("name" , cdr(ass ))));

if (globalTrace)
    printf("Leaving nameof\n");

}


//Building function childrenof from line: 880

list childrenof(list ass ) {
  
if (globalTrace)
    printf("childrenof at base.qon:880 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:881");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(assoc("children" , cdr(ass ))));

if (globalTrace)
    printf("Leaving childrenof\n");

}


//Building function isNode from line: 884

bool isNode(list val ) {
  
if (globalTrace)
    printf("isNode at base.qon:884 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(val )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:889");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(false );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(val )) {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxSymbol("node" ), car(val ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:894");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(true );

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:895");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(false );

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:896");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(false );

    };

  };

if (globalTrace)
    printf("Leaving isNode\n");

}


//Building function truthy from line: 898

bool truthy(box aVal ) {
  
if (globalTrace)
    printf("truthy at base.qon:898 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:900");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(isNotFalse(aVal ));

if (globalTrace)
    printf("Leaving truthy\n");

}


//Building function isNotFalse from line: 902

bool isNotFalse(box aVal ) {
  
if (globalTrace)
    printf("isNotFalse at base.qon:902 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(boxType(aVal ), "bool" )) {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( unBoxBool(aVal )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:905");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(true );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:905");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(false );

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:906");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(true );

  };

if (globalTrace)
    printf("Leaving isNotFalse\n");

}


//Building function isLeaf from line: 909

bool isLeaf(list n ) {
  
if (globalTrace)
    printf("isLeaf at base.qon:909 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:912");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(equalBox(boxString("leaf" ), subnameof(n )));

if (globalTrace)
    printf("Leaving isLeaf\n");

}


//Building function printIndent from line: 914

void printIndent(int ii ) {
  
if (globalTrace)
    printf("printIndent at base.qon:914 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(ii , 0 )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:919");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("  " );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:919");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(sub1(ii ));

  } else {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  };

if (globalTrace)
    printf("Leaving printIndent\n");

}


//Building function newLine from line: 922

void newLine(int indent ) {
  
if (globalTrace)
    printf("newLine at base.qon:922 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:925");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n" );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:925");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printIndent(indent );

if (globalTrace)
    printf("Leaving newLine\n");

}


//Building function noStackTrace from line: 926

list noStackTrace() {
  
if (globalTrace)
    printf("noStackTrace at base.qon:926 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:928");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cons(boxString("boxType" ), cons(boxString("stringify" ), cons(boxString("isEmpty" ), cons(boxString("unBoxString" ), cons(boxString("isList" ), cons(boxString("unBoxBool" ), cons(boxString("unBoxSymbol" ), cons(boxString("equalBox" ), cons(boxString("assoc" ), cons(boxString("inList" ), cons(boxString("unBoxInt" ), cons(boxString("listLength" ), cons(boxString("stroff" ), cons(boxString("troff" ), cons(boxString("tron" ), cons(boxString("stron" ), cons(boxString("car" ), cons(boxString("cdr" ), cons(boxString("cons" ), cons(boxString("stackTracePush" ), cons(boxString("stackTracePop" ), cons(boxString("assertType" ), cons(boxString("boxString" ), cons(boxString("boxSymbol" ), cons(boxString("boxInt" ), NULL ))))))))))))))))))))))))));

if (globalTrace)
    printf("Leaving noStackTrace\n");

}


//Building function toStr from line: 955

box toStr(box thing ) {
  
if (globalTrace)
    printf("toStr at base.qon:955 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:956");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(boxString(stringify(thing )));

if (globalTrace)
    printf("Leaving toStr\n");

}


//Building function listLast from line: 958

box listLast(list alist ) {
  
if (globalTrace)
    printf("listLast at base.qon:958 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(cdr(alist ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:961");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(car(alist ));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:962");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(listLast(cdr(alist )));

  };

if (globalTrace)
    printf("Leaving listLast\n");

}


//Building function treeCompile from line: 965

list treeCompile(char* filename ) {
  char* programStr = "" ;
list tree = NULL ;
list program = NULL ;

if (globalTrace)
    printf("treeCompile at base.qon:965 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:967");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:968");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr , filename );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:969");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(tree );

if (globalTrace)
    printf("Leaving treeCompile\n");

}


//Building function astBuild from line: 971

list astBuild(char* filename ) {
  char* programStr = "" ;
list tree = NULL ;
list program = NULL ;

if (globalTrace)
    printf("astBuild at base.qon:971 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:973");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:974");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr , filename );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:976");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = alistCons(boxString("includes" ), astIncludes(first(tree )), alistCons(boxString("types" ), astTypes(second(tree )), alistCons(boxString("functions" ), astFunctions(third(tree )), NULL )));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:984");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = mergeIncludes(program );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:985");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(program );

if (globalTrace)
    printf("Leaving astBuild\n");

}


//Building function astCompile from line: 988

void astCompile(char* filename ) {
  char* programStr = "" ;
list tree = NULL ;
list program = NULL ;

if (globalTrace)
    printf("astCompile at base.qon:988 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:990");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = astBuild(filename );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:991");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  display(program );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:992");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n" );

if (globalTrace)
    printf("Leaving astCompile\n");

}


//Building function concatLists from line: 995

list concatLists(list seq1 ,list seq2 ) {
  
if (globalTrace)
    printf("concatLists at base.qon:995 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(seq1 )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:998");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(seq2 );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:999");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(car(seq1 ), concatLists(cdr(seq1 ), seq2 )));

  };

if (globalTrace)
    printf("Leaving concatLists\n");

}


//Building function alistKeys from line: 1001

list alistKeys(list alist ) {
  
if (globalTrace)
    printf("alistKeys at base.qon:1001 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(alist )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1004");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(NULL );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1005");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(car(car(alist )), alistKeys(cdr(alist ))));

  };

if (globalTrace)
    printf("Leaving alistKeys\n");

}


//Building function mergeIncludes from line: 1007

list mergeIncludes(list program ) {
  
if (globalTrace)
    printf("mergeIncludes at base.qon:1007 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1009");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(merge_recur(childrenof(cdr(cdr(assocPanic("includes" , program , "Program lacks include section" )))), program ));

if (globalTrace)
    printf("Leaving mergeIncludes\n");

}


//Building function merge_recur from line: 1014

list merge_recur(list incs ,list program ) {
  
if (globalTrace)
    printf("merge_recur at base.qon:1014 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(incs ), 0 )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1018");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(mergeInclude(car(incs ), merge_recur(cdr(incs ), program )));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1019");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(program );

  };

if (globalTrace)
    printf("Leaving merge_recur\n");

}


//Building function mergeInclude from line: 1022

list mergeInclude(list inc ,list program ) {
  list newProgram = NULL ;
list oldfunctionsnode = NULL ;
list oldfunctions = NULL ;
list newfunctions = NULL ;
list newFunctionNode = NULL ;
list functions = NULL ;
list oldtypesnode = NULL ;
list oldtypes = NULL ;
list newtypes = NULL ;
list newTypeNode = NULL ;
list types = NULL ;

if (globalTrace)
    printf("mergeInclude at base.qon:1022 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(inc )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1038");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(program );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1040");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    functions = childrenof(cdr(assocPanic("functions" , inc , "Included file has no functions section" )));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1041");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    oldfunctionsnode = cdr(assocPanic("functions" , program , "Current module has no functions section" ));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1042");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    oldfunctions = childrenof(oldfunctionsnode );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1043");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newfunctions = concatLists(functions , oldfunctions );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1045");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newFunctionNode = cons(boxSymbol("node" ), alistCons(boxSymbol("children" ), newfunctions , cdr(oldfunctionsnode )));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1052");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    types = childrenof(cdr(assocPanic("types" , inc , "Included file has no types section" )));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1053");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    oldtypesnode = cdr(assocPanic("types" , program , "Current module has no types section" ));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1054");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    oldtypes = childrenof(oldtypesnode );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1055");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newtypes = concatLists(types , oldtypes );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1057");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newTypeNode = cons(boxSymbol("node" ), alistCons(boxSymbol("children" ), newtypes , cdr(oldtypesnode )));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1062");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newProgram = alistCons(boxString("functions" ), newFunctionNode , alistCons(boxString("types" ), newTypeNode , alistCons(boxString("includes" ), cons(boxSymbol("includes" ), NULL ), newProgram )));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1073");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(newProgram );

  };

if (globalTrace)
    printf("Leaving mergeInclude\n");

}


//Building function macrowalk from line: 1076

list macrowalk(list l ) {
  box val = NULL ;

if (globalTrace)
    printf("macrowalk at base.qon:1076 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1078");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(NULL );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l )) {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringConcatenate("box" , "List" ), stringify(car(l )))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1092");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(car(doBoxList(cdr(l ))));

      } else {
      };

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringConcatenate("string" , "List" ), stringify(car(l )))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1099");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(car(doStringList(cdr(l ))));

      } else {
      };

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1101");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cons(macrowalk(car(l )), macrowalk(cdr(l ))));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1103");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(l );

    };

  };

if (globalTrace)
    printf("Leaving macrowalk\n");

}


//Building function macrosingle from line: 1108

list macrosingle(list l ,char* search ,char* replace ) {
  box val = NULL ;

if (globalTrace)
    printf("macrosingle at base.qon:1108 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(l )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1110");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(NULL );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(l )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1116");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cons(macrosingle(car(l ), search , replace ), macrosingle(cdr(l ), search , replace )));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(search , stringify(l ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1124");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        val = clone(l );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1125");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        val->str = replace ;

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1126");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        return(val );

      } else {
      };

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1128");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(l );

    };

  };

if (globalTrace)
    printf("Leaving macrosingle\n");

}


//Building function doBoxList from line: 1131

list doBoxList(list l ) {
  
if (globalTrace)
    printf("doBoxList at base.qon:1131 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1135");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(boxSymbol("nil" ), NULL ));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1137");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(cons(boxSymbol("cons" ), cons(first(l ), doBoxList(cdr(l )))), NULL ));

  };

if (globalTrace)
    printf("Leaving doBoxList\n");

}


//Building function doStringList from line: 1147

list doStringList(list l ) {
  list newlist = NULL ;
list ret = NULL ;

if (globalTrace)
    printf("doStringList at base.qon:1147 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1151");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(boxSymbol("nil" ), NULL ));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1153");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newlist = cons(boxSymbol("boxString" ), cons(first(l ), newlist ));

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1154");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ret = cons(cons(boxSymbol("cons" ), cons(newlist , doStringList(cdr(l )))), NULL );

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1164");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(ret );

  };

if (globalTrace)
    printf("Leaving doStringList\n");

}


//Building function argList from line: 1171

list argList(int count ,int pos ,char** args ) {
  
if (globalTrace)
    printf("argList at base.qon:1171 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(count , pos )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1177");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(boxString(getStringArray(pos , args )), argList(count , add1(pos ), args )));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1181");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(NULL );

  };

if (globalTrace)
    printf("Leaving argList\n");

}


//Building function listReverse from line: 1183

list listReverse(list l ) {
  
if (globalTrace)
    printf("listReverse at base.qon:1183 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1186");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(NULL );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1187");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(car(l ), listReverse(cdr(l ))));

  };

if (globalTrace)
    printf("Leaving listReverse\n");

}


//Building function inList from line: 1189

bool inList(box item ,list l ) {
  
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(l )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1192");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(false );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(car(l ), item )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1196");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(true );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1197");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(inList(item , cdr(l )));

    };

  };

}


//Building function equalList from line: 1199

bool equalList(list a ,list b ) {
  
if (globalTrace)
    printf("equalList at base.qon:1199 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(a )) {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(b )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1204");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(true );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1206");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(true );

    };

  } else {
  };

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(car(a ), car(b ))) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1209");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(equalList(cdr(a ), cdr(b )));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1210");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(false );

  };

if (globalTrace)
    printf("Leaving equalList\n");

}


//Building function reverseRec from line: 1213

list reverseRec(list oldL ,list newL ) {
  
if (globalTrace)
    printf("reverseRec at base.qon:1213 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(oldL )) {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1216");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(newL );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1217");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(reverseRec(cdr(oldL ), cons(first(oldL ), newL )));

  };

if (globalTrace)
    printf("Leaving reverseRec\n");

}


//Building function reverseList from line: 1220

list reverseList(list l ) {
  
if (globalTrace)
    printf("reverseList at base.qon:1220 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1222");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(reverseRec(l , NULL ));

if (globalTrace)
    printf("Leaving reverseList\n");

}


//Building function tron from line: 1227

void tron() {
  
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1227");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalTrace = true ;

}


//Building function troff from line: 1228

void troff() {
  
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1228");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalTrace = false ;

}


//Building function stron from line: 1229

void stron() {
  
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1229");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalStepTrace = true ;

}


//Building function stroff from line: 1230

void stroff() {
  
if (globalTrace)
    snprintf(caller, 1024, "from base.qon:1230");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalStepTrace = false ;

}


//Building function loadQuon from line: 3

list loadQuon(char* filename ) {
  list foundationFuncs = NULL ;
list foundation = NULL ;
char* programStr = "" ;
list tree = NULL ;

if (globalTrace)
    printf("loadQuon at astaccessors.qon:3 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from astaccessors.qon:5");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  foundation = readSexpr(read_file(filename ), filename );

if (globalTrace)
    snprintf(caller, 1024, "from astaccessors.qon:6");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  foundationFuncs = cdr(third(foundation ));

if (globalTrace)
    snprintf(caller, 1024, "from astaccessors.qon:10");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename );

if (globalTrace)
    snprintf(caller, 1024, "from astaccessors.qon:13");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr , filename );

if (globalTrace)
    snprintf(caller, 1024, "from astaccessors.qon:15");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(tree );

if (globalTrace)
    printf("Leaving loadQuon\n");

}


//Building function getIncludes from line: 18

list getIncludes(list program ) {
  
if (globalTrace)
    printf("getIncludes at astaccessors.qon:18 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from astaccessors.qon:20");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(first(program )));

if (globalTrace)
    printf("Leaving getIncludes\n");

}


//Building function getTypes from line: 22

list getTypes(list program ) {
  
if (globalTrace)
    printf("getTypes at astaccessors.qon:22 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from astaccessors.qon:24");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(second(program )));

if (globalTrace)
    printf("Leaving getTypes\n");

}


//Building function getFunctions from line: 26

list getFunctions(list program ) {
  
if (globalTrace)
    printf("getFunctions at astaccessors.qon:26 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from astaccessors.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(cdr(third(program )));

if (globalTrace)
    printf("Leaving getFunctions\n");

}


//Building function loadIncludes from line: 31

list loadIncludes(list tree ) {
  list newProg = NULL ;
char* includeFile = "" ;
list functionsCombined = NULL ;
list typesCombined = NULL ;
list includeTree = NULL ;
list program = NULL ;

if (globalTrace)
    printf("loadIncludes at astaccessors.qon:31 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(getIncludes(tree )), 0 )) {
if (globalTrace)
    snprintf(caller, 1024, "from astaccessors.qon:43");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    includeFile = stringify(first(getIncludes(tree )));

if (globalTrace)
    snprintf(caller, 1024, "from astaccessors.qon:46");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    includeTree = loadQuon(includeFile );

if (globalTrace)
    snprintf(caller, 1024, "from astaccessors.qon:49");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    functionsCombined = concatLists(getFunctions(includeTree ), getFunctions(tree ));

if (globalTrace)
    snprintf(caller, 1024, "from astaccessors.qon:50");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    typesCombined = concatLists(getTypes(includeTree ), getTypes(tree ));

if (globalTrace)
    snprintf(caller, 1024, "from astaccessors.qon:53");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newProg = buildProg(cdr(getIncludes(tree )), typesCombined , functionsCombined );

if (globalTrace)
    snprintf(caller, 1024, "from astaccessors.qon:55");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(loadIncludes(newProg ));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from astaccessors.qon:58");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(tree );

  };

if (globalTrace)
    printf("Leaving loadIncludes\n");

}


//Building function buildProg from line: 61

list buildProg(list includes ,list types ,list functions ) {
  list program = NULL ;

if (globalTrace)
    printf("buildProg at astaccessors.qon:61 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from astaccessors.qon:63");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  includes = cons(boxSymbol("includes" ), includes );

if (globalTrace)
    snprintf(caller, 1024, "from astaccessors.qon:64");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  types = cons(boxSymbol("types" ), types );

if (globalTrace)
    snprintf(caller, 1024, "from astaccessors.qon:65");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  functions = cons(boxSymbol("functions" ), functions );

if (globalTrace)
    snprintf(caller, 1024, "from astaccessors.qon:66");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = cons(includes , cons(types , cons(functions , NULL )));

if (globalTrace)
    snprintf(caller, 1024, "from astaccessors.qon:69");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(program );

if (globalTrace)
    printf("Leaving buildProg\n");

}


//Building function numbers from line: 4

list numbers(int num ) {
  
if (globalTrace)
    printf("numbers at perl.qon:4 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(0 , num )) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:7");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(boxString("-" ), NULL ));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:8");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cons(boxString(stringify(boxInt(num ))), numbers(sub1(num ))));

  };

if (globalTrace)
    printf("Leaving numbers\n");

}


//Building function lexType from line: 11

char* lexType(box abox ) {
  
if (globalTrace)
    printf("lexType at perl.qon:11 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("string" , boxType(abox ))) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:15");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return("string" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(boxString(sub_string(stringify(abox ), 0 , 1 )), numbers(9 ))) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:18");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return("number" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:19");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return("symbol" );

    };

  };

if (globalTrace)
    printf("Leaving lexType\n");

}


//Building function perlLeaf from line: 23

void perlLeaf(list thisNode ,int indent ) {
  
if (globalTrace)
    printf("perlLeaf at perl.qon:23 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol" , lexType(codeof(thisNode )))) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:26");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s" , dollar ());

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:27");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("" );

  };

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:29");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  display(perlFuncMap(codeof(thisNode )));

if (globalTrace)
    printf("Leaving perlLeaf\n");

}


//Building function perlStructGetterExpression from line: 32

void perlStructGetterExpression(list thisNode ,int indent ) {
  
if (globalTrace)
    printf("perlStructGetterExpression at perl.qon:32 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("structGetter" ), subnameof(thisNode ))) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:35");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlGetStruct(thisNode , indent );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:36");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlLeaf(thisNode , indent );

  };

if (globalTrace)
    printf("Leaving perlStructGetterExpression\n");

}


//Building function perlExpression from line: 38

void perlExpression(list node ,int indent ) {
  
if (globalTrace)
    printf("perlExpression at perl.qon:38 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isLeaf(node )) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:41");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlLeaf(node , indent );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:42");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlSubExpression(node , indent );

  };

if (globalTrace)
    printf("Leaving perlExpression\n");

}


//Building function perlRecurList from line: 44

void perlRecurList(list expr ,int indent ) {
  
if (globalTrace)
    printf("perlRecurList at perl.qon:44 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:49");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlExpression(car(expr ), indent );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr ))) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:51");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:52");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(", " );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:52");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      perlRecurList(cdr(expr ), indent );

    };

  };

if (globalTrace)
    printf("Leaving perlRecurList\n");

}


//Building function perlSubExpression from line: 55

void perlSubExpression(list tree ,int indent ) {
  box thing = NULL ;

if (globalTrace)
    printf("perlSubExpression at perl.qon:55 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNode(childrenof(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:61");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      perlSubExpression(childrenof(tree ), indent );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isLeaf(tree )) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:65");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s" , dollar ());

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:66");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        display(perlFuncMap(codeof(tree )));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equal(1 , listLength(childrenof(tree )))) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:70");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          display(codeof(car(childrenof(tree ))));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxString("return" ), codeof(car(childrenof(tree ))))) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:74");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("" );

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:75");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("()" );

          };

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:77");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          thing = codeof(car(childrenof(tree )));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("get-struct" ), thing )) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:80");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s%s->{%s}" , dollar (), stringify(codeof(second(childrenof(tree )))), stringify(codeof(third(childrenof(tree )))));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("new" ), thing )) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:84");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("{}" );

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:86");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s(" , stringify(perlFuncMap(codeof(car(childrenof(tree ))))));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:90");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              perlRecurList(cdr(childrenof(tree )), indent );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:91");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")" );

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

void perlIf(list node ,int indent ) {
  
if (globalTrace)
    printf("perlIf at perl.qon:93 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:95");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:96");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("if ( " );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:97");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlExpression(car(first(childrenof(node ))), 0 );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:98");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(") {" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:99");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlBody(second(childrenof(node )), add1(indent ));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:100");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:101");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("} else {" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:102");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlBody(third(childrenof(node )), add1(indent ));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:103");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:104");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("}" );

if (globalTrace)
    printf("Leaving perlIf\n");

}


//Building function perlSetStruct from line: 106

void perlSetStruct(list node ,int indent ) {
  
if (globalTrace)
    printf("perlSetStruct at perl.qon:106 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:109");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:110");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s->{%s} = " , dollar (), stringify(first(codeof(node ))), stringify(second(codeof(node ))));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:111");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlExpression(childrenof(node ), indent );

if (globalTrace)
    printf("Leaving perlSetStruct\n");

}


//Building function perlGetStruct from line: 113

void perlGetStruct(list node ,int indent ) {
  
if (globalTrace)
    printf("perlGetStruct at perl.qon:113 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:115");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:116");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s->{%s}" , dollar (), stringify(first(codeof(node ))), stringify(second(codeof(node ))));

if (globalTrace)
    printf("Leaving perlGetStruct\n");

}


//Building function perlSet from line: 118

void perlSet(list node ,int indent ) {
  
if (globalTrace)
    printf("perlSet at perl.qon:118 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:120");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:121");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s = " , dollar (), stringify(first(codeof(node ))));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:122");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlExpression(childrenof(node ), indent );

if (globalTrace)
    printf("Leaving perlSet\n");

}


//Building function assertNode from line: 124

void assertNode(list node ) {
  
if (globalTrace)
    printf("assertNode at perl.qon:124 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNode(node )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:128");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    panic("Not a node!" );

  };

if (globalTrace)
    printf("Leaving assertNode\n");

}


//Building function perlStatement from line: 131

void perlStatement(list node ,int indent ) {
  box functionName = NULL ;

if (globalTrace)
    printf("perlStatement at perl.qon:131 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:135");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assertNode(node );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("setter" ), subnameof(node ))) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:137");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlSet(node , indent );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("structSetter" ), subnameof(node ))) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:140");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      perlSetStruct(node , indent );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if" ), subnameof(node ))) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:143");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        perlIf(node , indent );

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("returnvoid" ), subnameof(node ))) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:147");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          functionName = functionNameof(node );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:148");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("\n#Returnvoid\n" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:149");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:151");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:151");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("return" );

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxString("return" ), subnameof(node ))) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:155");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            functionName = functionNameof(node );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( inList(functionName , noStackTrace ())) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:157");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("" );

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:159");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("\n#standard return: %s\n" , stringify(functionName ));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:160");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:161");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s%s%s" , "if (" , dollar (), "globalTrace) {printf(\"Leaving \\n\")}\n" );

            };

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:163");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:164");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            perlExpression(childrenof(node ), indent );

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( inList(functionName , noStackTrace ())) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:168");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("" );

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:170");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("\n#standard expression\n" );

            };

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:173");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:174");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            perlExpression(childrenof(node ), indent );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:175");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            newLine(indent );

          };

        };

      };

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:178");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(";\n" );

if (globalTrace)
    printf("Leaving perlStatement\n");

}


//Building function perlBody from line: 180

void perlBody(list tree ,int indent ) {
  
if (globalTrace)
    printf("perlBody at perl.qon:180 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:185");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:186");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s%s%s" , "if (" , dollar (), "globalStepTrace) {printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__)}\n" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:187");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlStatement(car(tree ), indent );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:188");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlBody(cdr(tree ), indent );

  };

if (globalTrace)
    printf("Leaving perlBody\n");

}


//Building function perlDeclarations from line: 190

void perlDeclarations(list decls ,int indent ) {
  box decl = NULL ;

if (globalTrace)
    printf("perlDeclarations at perl.qon:190 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:195");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:196");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("my %s%s = " , dollar (), stringify(second(decl )));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:197");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(perlConstMap(third(decl )));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:198");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:199");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlDeclarations(cdr(decls ), indent );

  };

if (globalTrace)
    printf("Leaving perlDeclarations\n");

}


//Building function perlFunction from line: 201

void perlFunction(list node ) {
  box name = NULL ;

if (globalTrace)
    printf("perlFunction at perl.qon:201 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:203");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = subnameof(node );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:204");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n#Building function %s from line: %s" , stringify(name ), stringify(getTag(name , boxString("line" ))));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:208");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0 );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:212");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0 );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:213");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("sub %s" , stringify(subnameof(node )));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:214");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" {" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:215");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1 );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:216");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlFunctionArgs(cdr(assoc("intype" , cdr(node ))));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:217");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1 );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:218");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlDeclarations(declarationsof(node ), 1 );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:219");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\nif (%sglobalTrace) { printf(\"%s at %s:%s\\n\") }\n" , dollar (), stringify(subnameof(node )), stringify(getTag(name , boxString("filename" ))), stringify(getTag(name , boxString("line" ))));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(name , noStackTrace ())) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:221");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:223");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    };

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:225");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlBody(childrenof(node ), 1 );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(name , noStackTrace ())) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:227");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:229");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    };

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:231");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n" );

  };

if (globalTrace)
    printf("Leaving perlFunction\n");

}


//Building function perlForwardDeclaration from line: 233

void perlForwardDeclaration(list node ) {
  
if (globalTrace)
    printf("perlForwardDeclaration at perl.qon:233 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:238");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\nsub %s" , stringify(subnameof(node )));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:241");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";" );

  };

if (globalTrace)
    printf("Leaving perlForwardDeclaration\n");

}


//Building function perlForwardDeclarations from line: 243

void perlForwardDeclarations(list tree ) {
  
if (globalTrace)
    printf("perlForwardDeclarations at perl.qon:243 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:248");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlForwardDeclaration(car(tree ));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:249");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlForwardDeclarations(cdr(tree ));

  };

if (globalTrace)
    printf("Leaving perlForwardDeclarations\n");

}


//Building function perlFunctions from line: 251

void perlFunctions(list tree ) {
  
if (globalTrace)
    printf("perlFunctions at perl.qon:251 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:255");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlFunction(car(tree ));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:255");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlFunctions(cdr(tree ));

  };

if (globalTrace)
    printf("Leaving perlFunctions\n");

}


//Building function dollar from line: 258

char* dollar() {
  
if (globalTrace)
    printf("dollar at perl.qon:258 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:259");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(character(36 ));

if (globalTrace)
    printf("Leaving dollar\n");

}


//Building function atSym from line: 261

char* atSym() {
  
if (globalTrace)
    printf("atSym at perl.qon:261 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:262");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(character(64 ));

if (globalTrace)
    printf("Leaving atSym\n");

}


//Building function perlIncludes from line: 265

void perlIncludes(list nodes ) {
  
if (globalTrace)
    printf("perlIncludes at perl.qon:265 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:267");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s\n" , "use strict;" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:268");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s\n" , "my $caller;" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:269");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s\n" , "use Carp;" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:270");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  dollar ();

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:271");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s\n" , "use Carp::Always;" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:272");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n" , "sub greaterthan { " , dollar (), "_[0] > " , dollar (), "_[1] };" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:273");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n" , "sub mult { " , dollar (), "_[0] * " , dollar (), "_[1] };" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:274");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n" , "sub multf { " , dollar (), "_[0] * " , dollar (), "_[1] };" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:275");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n" , "sub greaterthanf { " , dollar (), "_[0] > " , dollar (), "_[1] };" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:276");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n" , "sub equalString { " , dollar (), "_[0] eq " , dollar (), "_[1] };" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:283");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("sub read_file { my %sfile = shift; %sfile || die \"Empty file name!!!\"; open my %sfh, '<', %sfile or die; local %s/ = undef; my %scont = <%sfh>; close %sfh; return %scont; }; \n" , dollar (), dollar (), dollar (), dollar (), dollar (), dollar (), dollar (), dollar (), dollar ());

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:285");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("sub write_file {my %sfile = shift; my %sdata = shift; %sfile || die \"Empty file name!!!\"; open my %sfh, '<', %sfile or die; print %sfh %sdata; close %sfh; } \n" , dollar (), dollar (), dollar (), dollar (), dollar (), dollar (), dollar (), dollar ());

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:287");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n" , "sub stringConcatenate { " , dollar (), "_[0] . " , dollar (), "_[1]}" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:288");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n" , "sub subtract { " , dollar (), "_[0] - " , dollar (), "_[1]}" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:289");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n" , "sub subf { " , dollar (), "_[0] - " , dollar (), "_[1]}" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:290");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n" , "sub andBool { " , dollar (), "_[0] && " , dollar (), "_[1]}" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:291");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n" , "sub equal { " , dollar (), "_[0] == " , dollar (), "_[1]}" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:292");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s\n" , "sub panic { carp " , atSym (), "_; die \"" , atSym (), "_\"}" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:293");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("sub intToString { return %s_[0]}\n" , dollar ());

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:294");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("sub character { return chr(%s_[0])}\n" , dollar ());

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:295");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s%s%s%s%s%s\n" , "sub getStringArray { my " , dollar (), "index = shift; my " , dollar (), "arr = shift; return " , dollar (), "arr->[" , dollar (), "index]}" );

if (globalTrace)
    printf("Leaving perlIncludes\n");

}


//Building function perlTypeDecl from line: 299

void perlTypeDecl(list l ) {
  
if (globalTrace)
    printf("perlTypeDecl at perl.qon:299 (%s)\n", caller);

if (globalTrace)
    printf("Leaving perlTypeDecl\n");

}


//Building function perlStructComponents from line: 304

void perlStructComponents(list node ) {
  
if (globalTrace)
    printf("perlStructComponents at perl.qon:304 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:308");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlTypeDecl(car(node ));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:308");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlStructComponents(cdr(node ));

  };

if (globalTrace)
    printf("Leaving perlStructComponents\n");

}


//Building function perlStruct from line: 310

void perlStruct(list node ) {
  
if (globalTrace)
    printf("perlStruct at perl.qon:310 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:311");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlStructComponents(cdr(car(node )));

if (globalTrace)
    printf("Leaving perlStruct\n");

}


//Building function perlTypeMap from line: 313

box perlTypeMap(box aSym ) {
  list symMap = NULL ;

if (globalTrace)
    printf("perlTypeMap at perl.qon:313 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:316");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray" ), boxSymbol("char**" ), alistCons(boxSymbol("string" ), boxSymbol("char*" ), NULL ));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym ), symMap ))) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:322");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cdr(assoc(stringify(aSym ), symMap )));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:323");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym );

  };

if (globalTrace)
    printf("Leaving perlTypeMap\n");

}


//Building function perlConstMap from line: 325

box perlConstMap(box aSym ) {
  list symMap = NULL ;

if (globalTrace)
    printf("perlConstMap at perl.qon:325 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol" , boxType(aSym ))) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:330");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("false" ), boxSymbol("0" ), alistCons(boxSymbol("nil" ), boxSymbol("undef" ), NULL ));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:332");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cdr(assocFail(stringify(aSym ), symMap , aSym )));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:333");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym );

  };

if (globalTrace)
    printf("Leaving perlConstMap\n");

}


//Building function perlFuncMap from line: 335

box perlFuncMap(box aSym ) {
  list symMap = NULL ;

if (globalTrace)
    printf("perlFuncMap at perl.qon:335 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol" , boxType(aSym ))) {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:340");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("sub" ), boxSymbol("subtract" ), alistCons(boxSymbol("=" ), boxSymbol("equal" ), alistCons(boxSymbol("sub-string" ), boxSymbol("substr" ), alistCons(boxSymbol("read-file" ), boxSymbol("read_file" ), alistCons(boxSymbol("write-file" ), boxSymbol("write_file" ), alistCons(boxSymbol(">" ), boxSymbol("greaterthan" ), alistCons(boxSymbol("string-length" ), boxSymbol("length" ), alistCons(boxSymbol("nil" ), boxSymbol("undef" ), NULL ))))))));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:349");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cdr(assocFail(stringify(aSym ), symMap , aSym )));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:350");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym );

  };

if (globalTrace)
    printf("Leaving perlFuncMap\n");

}


//Building function perlType from line: 352

void perlType(list node ) {
  
if (globalTrace)
    printf("perlType at perl.qon:352 (%s)\n", caller);

if (globalTrace)
    printf("Leaving perlType\n");

}


//Building function perlTypes from line: 357

void perlTypes(list nodes ) {
  
if (globalTrace)
    printf("perlTypes at perl.qon:357 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:361");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlType(car(nodes ));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:361");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlTypes(cdr(nodes ));

  };

if (globalTrace)
    printf("Leaving perlTypes\n");

}


//Building function perlFunctionArgs from line: 363

void perlFunctionArgs(list tree ) {
  
if (globalTrace)
    printf("perlFunctionArgs at perl.qon:363 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:368");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s%s" , "my " , dollar ());

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:369");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(second(tree ));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:370");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" = shift;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:371");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    perlFunctionArgs(cddr(tree ));

  };

if (globalTrace)
    printf("Leaving perlFunctionArgs\n");

}


//Building function perlCompile from line: 373

void perlCompile(char* filename ) {
  char* programStr = "" ;
list tree = NULL ;
list program = NULL ;

if (globalTrace)
    printf("perlCompile at perl.qon:373 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:375");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:376");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr , filename );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:377");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = alistCons(boxString("includes" ), astIncludes(first(tree )), alistCons(boxString("types" ), astTypes(second(tree )), alistCons(boxString("functions" ), astFunctions(third(tree )), NULL )));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:385");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = mergeIncludes(program );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:386");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlIncludes(cdr(assoc("includes" , program )));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:387");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlTypes(childrenof(cdr(assoc("types" , program ))));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:389");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("use strict;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:390");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("use Carp;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:391");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("use Data::Dumper;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:392");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s" , "my " , dollar (), "globalStackTrace = undef;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:393");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s" , "my " , dollar (), "globalTrace = undef;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:394");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s" , "my " , dollar (), "globalStepTrace = undef;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:395");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s" , "my " , dollar (), "globalArgs = undef;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:396");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s" , "my " , dollar (), "globalArgsCount = undef;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:397");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s\n" , "my " , dollar (), "true = 1;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:398");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s" , "my " , dollar (), "false = 0;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:399");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s" , "my " , dollar (), "undef;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:400");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s" , "\nsub isNil {\n    return !defined(" , dollar (), "_[0]);\n}\n\n\n#Forward declarations\n" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:402");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlForwardDeclarations(cdr(assoc("children" , cdr(cdr(assoc("functions" , program ))))));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:404");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n#End forward declarations\n\n" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:405");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  perlFunctions(cdr(assoc("children" , cdr(cdr(assoc("functions" , program ))))));

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:407");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(";\n" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:408");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s" , dollar (), "globalArgs = [ 1, " , atSym (), "ARGV];" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:409");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s%s%s%s" , dollar (), "globalArgsCount = scalar(" , atSym (), "ARGV)+1;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from perl.qon:410");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("start();" );

if (globalTrace)
    printf("Leaving perlCompile\n");

}


//Building function ansiFunctionArgs from line: 3

void ansiFunctionArgs(list tree ) {
  
if (globalTrace)
    printf("ansiFunctionArgs at ansi.qon:3 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:8");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(ansiTypeMap(first(tree )));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:9");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" " );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:10");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(second(tree ));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:11");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:11");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("," );

    };

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:12");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiFunctionArgs(cddr(tree ));

  };

if (globalTrace)
    printf("Leaving ansiFunctionArgs\n");

}


//Building function ansiLeaf from line: 14

void ansiLeaf(list thisNode ,int indent ) {
  
if (globalTrace)
    printf("ansiLeaf at ansi.qon:14 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:15");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  display(ansiFuncMap(codeof(thisNode )));

if (globalTrace)
    printf("Leaving ansiLeaf\n");

}


//Building function ansiStructGetterExpression from line: 17

void ansiStructGetterExpression(list thisNode ,int indent ) {
  
if (globalTrace)
    printf("ansiStructGetterExpression at ansi.qon:17 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("structGetter" ), subnameof(thisNode ))) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:20");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiGetStruct(thisNode , indent );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:21");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiLeaf(thisNode , indent );

  };

if (globalTrace)
    printf("Leaving ansiStructGetterExpression\n");

}


//Building function ansiExpression from line: 23

void ansiExpression(list node ,int indent ) {
  
if (globalTrace)
    printf("ansiExpression at ansi.qon:23 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isLeaf(node )) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:26");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(ansiFuncMap(codeof(node )));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:27");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiSubExpression(node , indent );

  };

if (globalTrace)
    printf("Leaving ansiExpression\n");

}


//Building function ansiRecurList from line: 29

void ansiRecurList(list expr ,int indent ) {
  
if (globalTrace)
    printf("ansiRecurList at ansi.qon:29 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:36");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiExpression(car(expr ), indent );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr ))) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:38");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:39");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(", " );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:39");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansiRecurList(cdr(expr ), indent );

    };

  };

if (globalTrace)
    printf("Leaving ansiRecurList\n");

}


//Building function ansiSubExpression from line: 41

void ansiSubExpression(list tree ,int indent ) {
  box thing = NULL ;

if (globalTrace)
    printf("ansiSubExpression at ansi.qon:41 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNode(childrenof(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:47");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansiSubExpression(childrenof(tree ), indent );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isLeaf(tree )) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:50");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        display(ansiFuncMap(codeof(tree )));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equal(1 , listLength(childrenof(tree )))) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:54");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          display(codeof(car(childrenof(tree ))));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxString("return" ), codeof(car(childrenof(tree ))))) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:58");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("" );

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:59");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("()" );

          };

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:61");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          thing = codeof(car(childrenof(tree )));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("get-struct" ), thing )) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:64");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s->%s" , stringify(codeof(second(childrenof(tree )))), stringify(codeof(third(childrenof(tree )))));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("new" ), thing )) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:71");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("malloc(sizeof(%s))" , stringify(codeof(third(childrenof(tree )))));

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:75");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s(" , stringify(ansiFuncMap(codeof(car(childrenof(tree ))))));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:79");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              ansiRecurList(cdr(childrenof(tree )), indent );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:80");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")" );

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

void ansiIf(list node ,int indent ) {
  
if (globalTrace)
    printf("ansiIf at ansi.qon:81 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:83");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:84");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("if ( " );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:85");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiExpression(car(first(childrenof(node ))), 0 );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:86");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(") {" );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:87");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiBody(second(childrenof(node )), add1(indent ));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:88");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:89");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("} else {" );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:90");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiBody(third(childrenof(node )), add1(indent ));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:91");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:92");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("}" );

if (globalTrace)
    printf("Leaving ansiIf\n");

}


//Building function ansiSetStruct from line: 94

void ansiSetStruct(list node ,int indent ) {
  
if (globalTrace)
    printf("ansiSetStruct at ansi.qon:94 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:96");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:97");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->%s = " , stringify(first(codeof(node ))), stringify(second(codeof(node ))));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:101");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiExpression(childrenof(node ), indent );

if (globalTrace)
    printf("Leaving ansiSetStruct\n");

}


//Building function ansiGetStruct from line: 103

void ansiGetStruct(list node ,int indent ) {
  
if (globalTrace)
    printf("ansiGetStruct at ansi.qon:103 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:105");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:106");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s->%s" , stringify(first(codeof(node ))), stringify(second(codeof(node ))));

if (globalTrace)
    printf("Leaving ansiGetStruct\n");

}


//Building function ansiSet from line: 111

void ansiSet(list node ,int indent ) {
  
if (globalTrace)
    printf("ansiSet at ansi.qon:111 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:113");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:114");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s = " , stringify(first(codeof(node ))));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:115");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiExpression(childrenof(node ), indent );

if (globalTrace)
    printf("Leaving ansiSet\n");

}


//Building function ansiStatement from line: 117

void ansiStatement(list node ,int indent ) {
  
if (globalTrace)
    printf("ansiStatement at ansi.qon:117 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("setter" ), subnameof(node ))) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:120");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiSet(node , indent );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("structSetter" ), subnameof(node ))) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:123");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      ansiSetStruct(node , indent );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if" ), subnameof(node ))) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:126");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        ansiIf(node , indent );

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("returnvoid" ), subnameof(node ))) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:129");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:129");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("return" );

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:131");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:132");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          ansiExpression(childrenof(node ), indent );

        };

      };

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:133");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(";\n" );

if (globalTrace)
    printf("Leaving ansiStatement\n");

}


//Building function ansiBody from line: 135

void ansiBody(list tree ,int indent ) {
  list code = NULL ;

if (globalTrace)
    printf("ansiBody at ansi.qon:135 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:141");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    code = codeof(car(tree ));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(code )) {
    } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:145");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      code = car(codeof(car(tree )));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:146");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    snprintf(caller, 1024, \"from %s:%s\");\n" , stringify(getTagFail(code , boxString("filename" ), boxString("Unknown" ))), stringify(getTagFail(code , boxString("line" ), boxString("Unknown" ))));

    };

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:147");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:148");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s" , "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n" );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:151");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiStatement(car(tree ), indent );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:152");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiBody(cdr(tree ), indent );

  };

if (globalTrace)
    printf("Leaving ansiBody\n");

}


//Building function ansiDeclarations from line: 154

void ansiDeclarations(list decls ,int indent ) {
  box decl = NULL ;

if (globalTrace)
    printf("ansiDeclarations at ansi.qon:154 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:159");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:160");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s = " , stringify(ansiTypeMap(first(decl ))), stringify(second(decl )));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:164");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(ansiFuncMap(third(decl )));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:165");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n" );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:166");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiDeclarations(cdr(decls ), indent );

  };

if (globalTrace)
    printf("Leaving ansiDeclarations\n");

}


//Building function ansiFunction from line: 168

void ansiFunction(list node ) {
  box name = NULL ;

if (globalTrace)
    printf("ansiFunction at ansi.qon:168 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:170");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = subnameof(node );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:171");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n//Building function %s from line: %s" , stringify(name ), stringify(getTag(name , boxString("line" ))));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:172");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0 );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:176");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0 );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:177");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s(" , stringify(ansiTypeMap(cdr(assoc("outtype" , cdr(node ))))), stringify(subnameof(node )));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:181");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiFunctionArgs(cdr(assoc("intype" , cdr(node ))));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:182");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(") {" );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:183");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1 );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:184");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiDeclarations(declarationsof(node ), 1 );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name ), noStackTrace ())) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:186");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:188");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    printf(\"%s at %s:%s (%%s)\\n\", caller);\n" , stringify(name ), stringify(getTag(name , boxString("filename" ))), stringify(getTag(name , boxString("line" ))));

    };

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name ), noStackTrace ())) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:190");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
    };

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:194");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiBody(childrenof(node ), 1 );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name ), noStackTrace ())) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:196");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:198");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    printf(\"Leaving %s\\n\");\n" , stringify(name ));

    };

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:200");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n" );

  };

if (globalTrace)
    printf("Leaving ansiFunction\n");

}


//Building function ansiForwardDeclaration from line: 202

void ansiForwardDeclaration(list node ) {
  
if (globalTrace)
    printf("ansiForwardDeclaration at ansi.qon:202 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:207");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n%s %s(" , stringify(ansiTypeMap(cdr(assoc("outtype" , cdr(node ))))), stringify(subnameof(node )));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:211");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiFunctionArgs(cdr(assoc("intype" , cdr(node ))));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:212");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(");" );

  };

if (globalTrace)
    printf("Leaving ansiForwardDeclaration\n");

}


//Building function ansiForwardDeclarations from line: 214

void ansiForwardDeclarations(list tree ) {
  
if (globalTrace)
    printf("ansiForwardDeclarations at ansi.qon:214 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:219");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiForwardDeclaration(car(tree ));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:220");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiForwardDeclarations(cdr(tree ));

  };

if (globalTrace)
    printf("Leaving ansiForwardDeclarations\n");

}


//Building function ansiFunctions from line: 222

void ansiFunctions(list tree ) {
  
if (globalTrace)
    printf("ansiFunctions at ansi.qon:222 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:226");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiFunction(car(tree ));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:226");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiFunctions(cdr(tree ));

  };

if (globalTrace)
    printf("Leaving ansiFunctions\n");

}


//Building function ansiIncludes from line: 227

void ansiIncludes(list nodes ) {
  
if (globalTrace)
    printf("ansiIncludes at ansi.qon:227 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:229");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\nconst char* getEnv(char* key){return getenv(key);}\n void panic(char* s){abort();exit(1);}\nint sub(int a, int b) { return a - b; }\nfloat mult(int a, int b) { return a * b; }\nint greaterthan(int a, int b) { return a > b; }\nfloat subf(float a, float b) { return a - b; }\nfloat multf(float a, float b) { return a * b; }\nint greaterthanf(float a, float b) { return a > b; }\nint equal(int a, int b) { return a == b; }\nint equalString(char* a, char* b) { return !strcmp(a,b); }\nint andBool(int a, int b) { return a == b;}\nint string_length(char* s) { return strlen(s);}\nchar* setSubString(char* target, int start,char *source){target[start]=source[0]; return target;}\nchar* sub_string(char* s, int start, int length) {\nchar* substr = calloc(length+1, 1);\nstrncpy(substr, s+start, length);\nreturn substr;\n}\n\n\n\nchar* stringConcatenate(char* a, char* b) {\nint len = strlen(a) + strlen(b) + 1;\nchar* target = calloc(len,1);\nstrncat(target, a, len);\nstrncat(target, b, len);\nreturn target;\n}\n\nchar* intToString(int a) {\nint len = 100;\nchar* target = calloc(len,1);\nsnprintf(target, 99, \"%d\", a);\nreturn target;\n}\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\nvoid * gc_malloc( unsigned int size ) {\nreturn malloc( size);\n}\n\nint* makeArray(int length) {\n    int * array = gc_malloc(length*sizeof(int));\n    return array;\n}\n\nint at(int* arr, int index) {\n  return arr[index];\n}\n\nvoid setAt(int* array, int index, int value) {\n    array[index] = value;\n}\n\nchar * read_file(char * filename) {\nchar * buffer = 0;\nlong length;\nFILE * f = fopen (filename, \"rb\");\n\nif (f)\n{\n  fseek (f, 0, SEEK_END);\n  length = ftell (f);\n  fseek (f, 0, SEEK_SET);\n  buffer = malloc (length);\n  if (buffer == NULL) {\n  printf(\"Malloc failed!\\n\");\n  exit(1);\n}\n  if (buffer)\n  {\n    fread (buffer, 1, length, f);\n  }\n  fclose (f);\n}\nreturn buffer;\n}\n\n\nvoid write_file (char * filename, char * data) {\nFILE *f = fopen(filename, \"w\");\nif (f == NULL)\n{\n    printf(\"Error opening file!\");\n    exit(1);\n}\n\nfprintf(f, \"%s\", data);\n\nfclose(f);\n}\n\nchar* getStringArray(int index, char** strs) {\nreturn strs[index];\n}\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\n\nint main( int argc, char *argv[] )  {\n  globalArgs = argv;\n  globalArgsCount = argc;\n  caller=calloc(1024,1);\n\n  return start();\n\n}\n\n" );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:232");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "char * character(int num) { char *string = malloc(2); if (!string) return 0; string[0] = num; string[1] = 0; return string; }" );

if (globalTrace)
    printf("Leaving ansiIncludes\n");

}


//Building function ansiTypeDecl from line: 235

void ansiTypeDecl(list l ) {
  
if (globalTrace)
    printf("ansiTypeDecl at ansi.qon:235 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l ), 2 )) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:239");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1 );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:240");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s %s;\n" , stringify(second(l )), stringify(ansiTypeMap(listLast(l ))), stringify(first(l )));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:246");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1 );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:247");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s;\n" , stringify(ansiTypeMap(listLast(l ))), stringify(car(l )));

  };

if (globalTrace)
    printf("Leaving ansiTypeDecl\n");

}


//Building function ansiStructComponents from line: 252

void ansiStructComponents(list node ) {
  
if (globalTrace)
    printf("ansiStructComponents at ansi.qon:252 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:256");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiTypeDecl(car(node ));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:256");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiStructComponents(cdr(node ));

  };

if (globalTrace)
    printf("Leaving ansiStructComponents\n");

}


//Building function ansiStruct from line: 258

void ansiStruct(list node ) {
  
if (globalTrace)
    printf("ansiStruct at ansi.qon:258 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:259");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiStructComponents(cdr(car(node )));

if (globalTrace)
    printf("Leaving ansiStruct\n");

}


//Building function ansiTypeMap from line: 261

box ansiTypeMap(box aSym ) {
  list symMap = NULL ;

if (globalTrace)
    printf("ansiTypeMap at ansi.qon:261 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:264");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray" ), boxSymbol("char**" ), alistCons(boxSymbol("string" ), boxSymbol("char*" ), NULL ));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym ), symMap ))) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:270");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cdr(assoc(stringify(aSym ), symMap )));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:271");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym );

  };

if (globalTrace)
    printf("Leaving ansiTypeMap\n");

}


//Building function ansiFuncMap from line: 273

box ansiFuncMap(box aSym ) {
  list symMap = NULL ;

if (globalTrace)
    printf("ansiFuncMap at ansi.qon:273 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol" , boxType(aSym ))) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:278");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("=" ), boxSymbol("equal" ), alistCons(boxSymbol("sub-string" ), boxSymbol("sub_string" ), alistCons(boxSymbol("read-file" ), boxSymbol("read_file" ), alistCons(boxSymbol("write-file" ), boxSymbol("write_file" ), alistCons(boxSymbol(">" ), boxSymbol("greaterthan" ), alistCons(boxSymbol("string-length" ), boxSymbol("string_length" ), alistCons(boxSymbol("nil" ), boxSymbol("NULL" ), NULL )))))));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym ), symMap ))) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:300");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cdr(assoc(stringify(aSym ), symMap )));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:301");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(aSym );

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:302");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym );

  };

if (globalTrace)
    printf("Leaving ansiFuncMap\n");

}


//Building function ansiType from line: 304

void ansiType(list node ) {
  
if (globalTrace)
    printf("ansiType at ansi.qon:304 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(subnameof(node ), boxString("struct" ))) {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:308");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\ntypedef struct %s {\n" , stringify(first(codeof(node ))));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:309");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiStruct(cdr(codeof(node )));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:310");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n} %s;\n" , stringify(first(codeof(node ))));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:311");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("typedef " );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:311");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiTypeDecl(codeof(node ));

  };

if (globalTrace)
    printf("Leaving ansiType\n");

}


//Building function ansiTypes from line: 314

void ansiTypes(list nodes ) {
  
if (globalTrace)
    printf("ansiTypes at ansi.qon:314 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:318");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiType(car(nodes ));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:318");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    ansiTypes(cdr(nodes ));

  };

if (globalTrace)
    printf("Leaving ansiTypes\n");

}


//Building function uniqueTarget from line: 322

void uniqueTarget(char* a ,char* b ) {
  
if (globalTrace)
    printf("uniqueTarget at ansi.qon:322 (%s)\n", caller);

if (globalTrace)
    printf("Leaving uniqueTarget\n");

}


//Building function ansiCompile from line: 325

void ansiCompile(char* filename ) {
  list foundationFuncs = NULL ;
list foundation = NULL ;
char* programStr = "" ;
list tree = NULL ;
list program = NULL ;

if (globalTrace)
    printf("ansiCompile at ansi.qon:325 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:327");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  foundation = readSexpr(read_file("ansi.qon" ), "ansi.qon" );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:331");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  foundationFuncs = cdr(third(foundation ));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:335");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("//Scanning file...%s\n" , filename );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:336");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:337");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("//Building sexpr\n" );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:338");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr , filename );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:339");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  cons(boxString("a" ), cons(boxString("b" ), cons(boxString("c" ), NULL )));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:343");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("//Building AST\n" );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:345");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = alistCons(boxString("includes" ), astIncludes(first(tree )), alistCons(boxString("types" ), astTypes(second(tree )), alistCons(boxString("functions" ), astFunctions(third(tree )), NULL )));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:354");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("//Merging ASTs\n" );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:355");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = mergeIncludes(program );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:356");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("//Printing program\n" );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:357");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiIncludes(cdr(assoc("includes" , program )));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:358");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiTypes(childrenof(cdr(assoc("types" , program ))));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:359");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("Box* globalStackTrace = NULL;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:360");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n" );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:362");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiForwardDeclarations(cdr(assoc("children" , cdr(cdr(assoc("functions" , program ))))));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:364");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n//End forward declarations\n\n" );

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:365");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  ansiFunctions(cdr(assoc("children" , cdr(cdr(assoc("functions" , program ))))));

if (globalTrace)
    snprintf(caller, 1024, "from ansi.qon:367");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n" );

if (globalTrace)
    printf("Leaving ansiCompile\n");

}


//Building function test0 from line: 7

void test0() {
  
if (globalTrace)
    printf("test0 at tests.qon:7 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(stringify(boxString("hello" )), stringify(boxString("hello" )))) {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:12");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("0.  pass string compare works\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:13");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("0.  pass string compare fails\n" );

  };

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(stringify(boxString("hello" )), stringify(boxSymbol("hello" )))) {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:17");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("0.  pass string compare works\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:18");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("0.  pass string compare fails\n" );

  };

if (globalTrace)
    printf("Leaving test0\n");

}


//Building function test1 from line: 20

void test1() {
  
if (globalTrace)
    printf("test1 at tests.qon:20 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:21");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("1.  pass Function call and print work\n" );

if (globalTrace)
    printf("Leaving test1\n");

}


//Building function test2_do from line: 24

void test2_do(char* message ) {
  
if (globalTrace)
    printf("test2_do at tests.qon:24 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:27");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("2.  pass Function call with arg works: %s\n" , message );

if (globalTrace)
    printf("Leaving test2_do\n");

}


//Building function test2 from line: 28

void test2() {
  
if (globalTrace)
    printf("test2 at tests.qon:28 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  test2_do("This is the argument" );

if (globalTrace)
    printf("Leaving test2\n");

}


//Building function test3_do from line: 30

void test3_do(int b ,char* c ) {
  
if (globalTrace)
    printf("test3_do at tests.qon:30 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:34");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("3.1 pass Two arg call, first arg: %d\n" , b );

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:35");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("3.2 pass Two arg call, second arg: %s\n" , c );

if (globalTrace)
    printf("Leaving test3_do\n");

}


//Building function test3 from line: 36

void test3() {
  
if (globalTrace)
    printf("test3 at tests.qon:36 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:36");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  test3_do(42 , "Fourty-two" );

if (globalTrace)
    printf("Leaving test3\n");

}


//Building function test4_do from line: 37

char* test4_do() {
  
if (globalTrace)
    printf("test4_do at tests.qon:37 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:37");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return("pass Return works" );

if (globalTrace)
    printf("Leaving test4_do\n");

}


//Building function returnThis from line: 39

char* returnThis(char* returnMessage ) {
  
if (globalTrace)
    printf("returnThis at tests.qon:39 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:42");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(returnMessage );

if (globalTrace)
    printf("Leaving returnThis\n");

}


//Building function test4 from line: 44

void test4() {
  char* message = "fail" ;

if (globalTrace)
    printf("test4 at tests.qon:44 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:47");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  message = test4_do ();

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:47");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("4.  %s\n" , message );

if (globalTrace)
    printf("Leaving test4\n");

}


//Building function test5 from line: 49

void test5() {
  char* message = "fail" ;

if (globalTrace)
    printf("test5 at tests.qon:49 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:53");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  message = returnThis("pass return passthrough string" );

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:54");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("5.  %s\n" , message );

if (globalTrace)
    printf("Leaving test5\n");

}


//Building function test6 from line: 56

void test6() {
  
if (globalTrace)
    printf("test6 at tests.qon:56 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:60");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( true ) {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:61");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("6.  pass If statement works\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:62");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("6.  fail If statement works\n" );

  };

if (globalTrace)
    printf("Leaving test6\n");

}


//Building function test7_do from line: 64

int test7_do(int count ) {
  
if (globalTrace)
    printf("test7_do at tests.qon:64 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:68");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  count = sub(count , 1 );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(count , 0 )) {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:69");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    count = test7_do(count );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:69");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(count );

  };

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:70");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(count );

if (globalTrace)
    printf("Leaving test7_do\n");

}


//Building function test7 from line: 72

void test7() {
  
if (globalTrace)
    printf("test7 at tests.qon:72 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(0 , test7_do(10 ))) {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:77");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("7.  pass count works\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:78");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("7.  fail count fails\n" );

  };

if (globalTrace)
    printf("Leaving test7\n");

}


//Building function beer from line: 80

void beer() {
  
if (globalTrace)
    printf("beer at tests.qon:80 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:84");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%d bottle of beer on the wall, %d bottle of beer.  Take one down, pass it round, no bottles of beer on the wall\n" , 1 , 1 );

if (globalTrace)
    printf("Leaving beer\n");

}


//Building function plural from line: 89

char* plural(int num ) {
  
if (globalTrace)
    printf("plural at tests.qon:89 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(num , 1 )) {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:92");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return("" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:92");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return("s" );

  };

if (globalTrace)
    printf("Leaving plural\n");

}


//Building function beers from line: 94

int beers(int count ) {
  int newcount = 0 ;

if (globalTrace)
    printf("beers at tests.qon:94 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:98");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newcount = sub(count , 1 );

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:99");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%d bottle%s of beer on the wall, %d bottle%s of beer.  Take one down, pass it round, %d bottle%s of beer on the wall\n" , count , plural(count ), count , plural(count ), newcount , plural(newcount ));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(count , 1 )) {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:107");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    count = beers(newcount );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:107");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(count );

  };

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:108");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(0 );

if (globalTrace)
    printf("Leaving beers\n");

}


//Building function test8 from line: 110

void test8() {
  
if (globalTrace)
    printf("test8 at tests.qon:110 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(sub(sub(2 , 1 ), sub(3 , 1 )), -1 )) {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:115");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("8.  pass Nested expressions work\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:116");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("8.  fail Nested expressions don't work\n" );

  };

if (globalTrace)
    printf("Leaving test8\n");

}


//Building function test9 from line: 118

void test9() {
  int answer = -999999 ;

if (globalTrace)
    printf("test9 at tests.qon:118 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:122");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  answer = sub(sub(20 , 1 ), sub(3 , 1 ));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equal(answer , 17 )) {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:124");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.  pass arithmetic works\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:125");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("9.  fail arithmetic\n" );

  };

if (globalTrace)
    printf("Leaving test9\n");

}


//Building function test10 from line: 127

void test10() {
  char* testString = "This is a test string" ;

if (globalTrace)
    printf("test10 at tests.qon:127 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(testString , unBoxString(car(cons(boxString(testString ), NULL ))))) {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:134");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("10. pass cons and car work\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:135");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("10. fail cons and car fail\n" );

  };

if (globalTrace)
    printf("Leaving test10\n");

}


//Building function test12 from line: 137

void test12() {
  box b = NULL ;

if (globalTrace)
    printf("test12 at tests.qon:137 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:141");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b = malloc(sizeof(Box));

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:142");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  b->str = "12. pass structure accessors\n" ;

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:143");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , b->str);

if (globalTrace)
    printf("Leaving test12\n");

}


//Building function test13 from line: 145

void test13() {
  char* testString = "Hello from the filesystem!" ;
char* contents = "" ;

if (globalTrace)
    printf("test13 at tests.qon:145 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:151");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  write_file("test.txt" , testString );

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:152");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  contents = read_file("test.txt" );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(testString , contents )) {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:154");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("13. pass Read and write files\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:156");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("13. fail Read and write files\n" );

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:157");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Expected: %s\n" , testString );

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:158");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("Got: %s\n" , contents );

  };

if (globalTrace)
    printf("Leaving test13\n");

}


//Building function test15 from line: 161

void test15() {
  char* a = "hello" ;
char* b = " world" ;
char* c = "" ;

if (globalTrace)
    printf("test15 at tests.qon:161 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:164");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  c = stringConcatenate(a , b );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(c , "hello world" )) {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:166");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("15. pass String concatenate\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:167");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("15. fail String concatenate\n" );

  };

if (globalTrace)
    printf("Leaving test15\n");

}


//Building function test16 from line: 169

void test16() {
  list assocCell1 = NULL ;
list assList = NULL ;
list assocCell2 = NULL ;
list assocCell3 = NULL ;

if (globalTrace)
    printf("test16 at tests.qon:169 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:176");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assocCell1 = cons(boxString("Hello" ), boxString("world" ));

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:177");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assocCell2 = cons(boxString("goodnight" ), boxString("moon" ));

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:178");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assocCell3 = cons(boxSymbol("ohio" ), boxString("gozaimasu" ));

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:179");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assList = cons(assocCell2 , emptyList ());

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:180");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assList = cons(assocCell1 , assList );

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:181");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  assList = cons(assocCell3 , assList );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(cdr(assoc("Hello" , assList )), boxString("world" ))) {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:183");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("16.1 pass Basic assoc works\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:184");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("16.1 fail Basic assoc fails\n" );

  };

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( andBool(andBool(equalBox(cdr(assoc("Hello" , assList )), boxString("world" )), equalBox(cdr(assoc("goodnight" , assList )), boxString("moon" ))), equalBox(cdr(assoc("ohio" , assList )), boxString("gozaimasu" )))) {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:190");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("16.2 pass assoc list\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:191");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("16.2 fail assoc list\n" );

  };

if (globalTrace)
    printf("Leaving test16\n");

}


//Building function test17 from line: 193

void test17() {
  list l = NULL ;

if (globalTrace)
    printf("test17 at tests.qon:193 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:195");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxInt(1 ), cons(boxInt(2 ), cons(boxInt(3 ), NULL )));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(car(l ), boxInt(1 ))) {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:197");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("17. pass list literal works\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:198");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("17. fail list literal failed\n" );

  };

if (globalTrace)
    printf("Leaving test17\n");

}


//Building function test18 from line: 204

void test18() {
  char* val1 = "a" ;
char* val2 = "b" ;
char* val3 = "c" ;
list l = NULL ;

if (globalTrace)
    printf("test18 at tests.qon:204 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:211");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxString(val1 ), cons(boxString(val2 ), cons(boxString("c" ), NULL )));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(l , cons(boxString("a" ), cons(boxString("b" ), cons(boxString("c" ), NULL ))))) {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:213");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("18. pass string list constructor works\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:214");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("18. fail string list constructor failed\n" );

  };

if (globalTrace)
    printf("Leaving test18\n");

}


//Building function test19 from line: 219

void test19() {
  char* val1 = "a" ;
char* val2 = "b" ;
char* val3 = "c" ;
list l = NULL ;
list revlist = NULL ;
list answer = NULL ;

if (globalTrace)
    printf("test19 at tests.qon:219 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:229");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxString(val1 ), cons(boxString(val2 ), cons(boxString("c" ), NULL )));

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:230");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  answer = cons(boxString("c" ), cons(boxString(val2 ), cons(boxString(val1 ), NULL )));

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:231");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  revlist = reverseList(l );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(answer , revlist )) {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:233");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("19. pass reverseList\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:234");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("19. fail reverseList\n" );

  };

if (globalTrace)
    printf("Leaving test19\n");

}


//Building function concatenateLists from line: 238

list concatenateLists(list oldL ,list newL ) {
  
if (globalTrace)
    printf("concatenateLists at tests.qon:238 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:240");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(reverseRec(reverseList(oldL ), newL ));

if (globalTrace)
    printf("Leaving concatenateLists\n");

}


//Building function test20 from line: 243

void test20() {
  char* val1 = "a" ;
char* val2 = "b" ;
char* val3 = "c" ;
list l = NULL ;
list l2 = NULL ;
list l3 = NULL ;
list combined = NULL ;
list revlist = NULL ;

if (globalTrace)
    printf("test20 at tests.qon:243 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:254");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxString(val1 ), cons(boxString(val2 ), cons(boxString("c" ), NULL )));

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:255");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l2 = cons(boxString("d" ), cons(boxString("e" ), cons(boxString("f" ), NULL )));

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:256");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l3 = cons(boxString(val1 ), cons(boxString(val2 ), cons(boxString("c" ), cons(boxString("d" ), cons(boxString("e" ), cons(boxString("f" ), NULL ))))));

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:257");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  combined = concatenateLists(l , l2 );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(l3 , combined )) {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:259");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("21. pass concatenateLists\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:260");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("21. fail concatenateLists\n" );

  };

if (globalTrace)
    printf("Leaving test20\n");

}


//Building function test21 from line: 264

void test21() {
  char* val1 = "a" ;
char* val2 = "b" ;
char* val3 = "c" ;
list l = NULL ;
list l2 = NULL ;

if (globalTrace)
    printf("test21 at tests.qon:264 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:272");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l = cons(boxString(val1 ), cons(boxString(val2 ), cons(boxString(val3 ), NULL )));

if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:273");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  l2 = cons(boxString("a" ), cons(boxString("b" ), cons(boxString("c" ), NULL )));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalList(l , l2 )) {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:275");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("21. pass equalList\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from tests.qon:276");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("21. fail equalList\n" );

  };

if (globalTrace)
    printf("Leaving test21\n");

}


//Building function nodeFunctionArgs from line: 4

void nodeFunctionArgs(list tree ) {
  
if (globalTrace)
    printf("nodeFunctionArgs at node.qon:4 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:9");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(second(tree ));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:10");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:10");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("," );

    };

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:11");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeFunctionArgs(cddr(tree ));

  };

if (globalTrace)
    printf("Leaving nodeFunctionArgs\n");

}


//Building function nodeLeaf from line: 13

void nodeLeaf(list thisNode ,int indent ) {
  
if (globalTrace)
    printf("nodeLeaf at node.qon:13 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:14");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  display(nodeFuncMap(codeof(thisNode )));

if (globalTrace)
    printf("Leaving nodeLeaf\n");

}


//Building function nodeStructGetterExpression from line: 16

void nodeStructGetterExpression(list thisNode ,int indent ) {
  
if (globalTrace)
    printf("nodeStructGetterExpression at node.qon:16 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("structGetter" ), subnameof(thisNode ))) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:19");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeGetStruct(thisNode , indent );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:20");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeLeaf(thisNode , indent );

  };

if (globalTrace)
    printf("Leaving nodeStructGetterExpression\n");

}


//Building function nodeExpression from line: 22

void nodeExpression(list node ,int indent ) {
  
if (globalTrace)
    printf("nodeExpression at node.qon:22 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isLeaf(node )) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:25");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(nodeFuncMap(codeof(node )));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:26");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeSubExpression(node , indent );

  };

if (globalTrace)
    printf("Leaving nodeExpression\n");

}


//Building function nodeRecurList from line: 28

void nodeRecurList(list expr ,int indent ) {
  
if (globalTrace)
    printf("nodeRecurList at node.qon:28 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:35");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeExpression(car(expr ), indent );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr ))) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:37");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:38");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(", " );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:38");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      nodeRecurList(cdr(expr ), indent );

    };

  };

if (globalTrace)
    printf("Leaving nodeRecurList\n");

}


//Building function nodeSubExpression from line: 41

void nodeSubExpression(list tree ,int indent ) {
  box thing = NULL ;

if (globalTrace)
    printf("nodeSubExpression at node.qon:41 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNode(childrenof(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:47");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      nodeSubExpression(childrenof(tree ), indent );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isLeaf(tree )) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:50");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        display(nodeFuncMap(codeof(tree )));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equal(1 , listLength(childrenof(tree )))) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:54");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          display(codeof(car(childrenof(tree ))));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxString("return" ), codeof(car(childrenof(tree ))))) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:58");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("" );

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:59");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("()" );

          };

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:61");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          thing = codeof(car(childrenof(tree )));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("get-struct" ), thing )) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:64");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s.%s" , stringify(codeof(second(childrenof(tree )))), stringify(codeof(third(childrenof(tree )))));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("new" ), thing )) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:71");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("{}" );

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:75");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s(" , stringify(nodeFuncMap(codeof(car(childrenof(tree ))))));

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:79");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              nodeRecurList(cdr(childrenof(tree )), indent );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:80");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")" );

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

void nodeIf(list node ,int indent ) {
  
if (globalTrace)
    printf("nodeIf at node.qon:82 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:84");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:85");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("if ( " );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:86");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeExpression(car(first(childrenof(node ))), 0 );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:87");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(") {" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:88");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeBody(second(childrenof(node )), add1(indent ));

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:89");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:90");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("} else {" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:91");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeBody(third(childrenof(node )), add1(indent ));

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:92");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:93");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("}" );

if (globalTrace)
    printf("Leaving nodeIf\n");

}


//Building function nodeGetStruct from line: 96

void nodeGetStruct(list node ,int indent ) {
  
if (globalTrace)
    printf("nodeGetStruct at node.qon:96 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:98");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:99");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s.%s" , stringify(first(codeof(node ))), stringify(second(codeof(node ))));

if (globalTrace)
    printf("Leaving nodeGetStruct\n");

}


//Building function nodeSet from line: 104

void nodeSet(list node ,int indent ) {
  
if (globalTrace)
    printf("nodeSet at node.qon:104 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:106");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:107");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s = " , stringify(first(codeof(node ))));

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:108");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeExpression(childrenof(node ), indent );

if (globalTrace)
    printf("Leaving nodeSet\n");

}


//Building function nodeSetStruct from line: 110

void nodeSetStruct(list node ,int indent ) {
  
if (globalTrace)
    printf("nodeSetStruct at node.qon:110 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:112");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:113");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s.%s = " , stringify(first(codeof(node ))), stringify(second(codeof(node ))));

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:114");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeExpression(childrenof(node ), indent );

if (globalTrace)
    printf("Leaving nodeSetStruct\n");

}


//Building function nodeStatement from line: 118

void nodeStatement(list node ,int indent ) {
  
if (globalTrace)
    printf("nodeStatement at node.qon:118 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("setter" ), subnameof(node ))) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:121");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeSet(node , indent );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("structSetter" ), subnameof(node ))) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:124");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      nodeSetStruct(node , indent );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if" ), subnameof(node ))) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:127");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        nodeIf(node , indent );

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("returnvoid" ), subnameof(node ))) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:130");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:130");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("return" );

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:132");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:133");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          nodeExpression(childrenof(node ), indent );

        };

      };

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:134");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(";\n" );

if (globalTrace)
    printf("Leaving nodeStatement\n");

}


//Building function nodeBody from line: 137

void nodeBody(list tree ,int indent ) {
  
if (globalTrace)
    printf("nodeBody at node.qon:137 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:144");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:145");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s" , "if (globalStepTrace) {console.log(new Error(\"StepTrace \\n\"));}\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:148");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeStatement(car(tree ), indent );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:149");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeBody(cdr(tree ), indent );

  };

if (globalTrace)
    printf("Leaving nodeBody\n");

}


//Building function nodeDeclarations from line: 151

void nodeDeclarations(list decls ,int indent ) {
  box decl = NULL ;

if (globalTrace)
    printf("nodeDeclarations at node.qon:151 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:156");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:157");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("var %s = " , stringify(second(decl )));

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:160");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(nodeFuncMap(third(decl )));

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:161");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:162");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeDeclarations(cdr(decls ), indent );

  };

if (globalTrace)
    printf("Leaving nodeDeclarations\n");

}


//Building function nodeFunction from line: 166

void nodeFunction(list node ) {
  box name = NULL ;

if (globalTrace)
    printf("nodeFunction at node.qon:166 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:168");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = subnameof(node );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:169");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n//Building function %s from line: %s" , stringify(name ), stringify(getTag(name , boxString("line" ))));

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:170");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0 );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:174");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0 );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:175");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("function %s(" , stringify(subnameof(node )));

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:178");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeFunctionArgs(cdr(assoc("intype" , cdr(node ))));

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:179");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(") {" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:180");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1 );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:181");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeDeclarations(declarationsof(node ), 1 );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name ), noStackTrace ())) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:183");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:185");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    {printf(\"%s at %s:%s\\n\");}\n" , stringify(name ), stringify(getTag(name , boxString("filename" ))), stringify(getTag(name , boxString("line" ))));

    };

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name ), noStackTrace ())) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:187");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
    };

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:191");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeBody(childrenof(node ), 1 );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name ), noStackTrace ())) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:193");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:195");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("\nif (globalTrace)\n    {printf(\"Leaving %s\\n\");}\n" , stringify(name ));

    };

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:197");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n" );

  };

if (globalTrace)
    printf("Leaving nodeFunction\n");

}


//Building function nodeForwardDeclaration from line: 199

void nodeForwardDeclaration(list node ) {
  
if (globalTrace)
    printf("nodeForwardDeclaration at node.qon:199 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:204");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n%s %s(" , stringify(nodeTypeMap(cdr(assoc("outtype" , cdr(node ))))), stringify(subnameof(node )));

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:208");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeFunctionArgs(cdr(assoc("intype" , cdr(node ))));

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:209");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(");" );

  };

if (globalTrace)
    printf("Leaving nodeForwardDeclaration\n");

}


//Building function nodeForwardDeclarations from line: 211

void nodeForwardDeclarations(list tree ) {
  
if (globalTrace)
    printf("nodeForwardDeclarations at node.qon:211 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:218");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeForwardDeclaration(car(tree ));

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:219");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeForwardDeclarations(cdr(tree ));

  };

if (globalTrace)
    printf("Leaving nodeForwardDeclarations\n");

}


//Building function nodeFunctions from line: 221

void nodeFunctions(list tree ) {
  
if (globalTrace)
    printf("nodeFunctions at node.qon:221 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:227");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeFunction(car(tree ));

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:227");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeFunctions(cdr(tree ));

  };

if (globalTrace)
    printf("Leaving nodeFunctions\n");

}


//Building function nodeIncludes from line: 229

void nodeIncludes(list nodes ) {
  
if (globalTrace)
    printf("nodeIncludes at node.qon:229 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:231");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function read_file(filename) {return fs.readFileSync(filename);}\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:232");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function write_file(filename, data) {fs.writeFileSync(filename, data);}\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:233");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "var util = require('util');\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:234");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function printf() {process.stdout.write(util.format.apply(this, arguments));}\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:235");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "var fs = require('fs');\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:236");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function equalString(a,b) {return a.toString()===b.toString() }\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:237");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function panic(s){console.trace(s);process.exit(1);}\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:238");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function dump(s){console.log(s)}" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:239");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function sub(a, b) { return a - b; }\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:240");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function mult(a, b) { return a * b; }\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:241");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function greaterthan(a, b) { return a > b; }\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:242");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function subf(a, b) { return a - b; }\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:243");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function multf(a, b) { return a * b; }\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:244");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function greaterthanf(a, b) { return a > b; }\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:245");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function equal(a, b) { return a == b; }\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:246");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function andBool(a, b) { return a == b;}\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:247");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function string_length(s) { return s.length;}\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:248");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function sub_string(str, start, len) {str = ''+str;return str.substring(start, start+len)};\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:249");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function stringConcatenate(a, b) { return a + b}\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:250");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function intToString(a) {}\n\n\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:251");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function gc_malloc( size ) {\nreturn {};\n}\n\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:252");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function makeArray(length) {\n   return [];\n}\n\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:253");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function at(arr, index) {\n  return arr[index];\n}\n\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:254");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function setAt(array, index, value) {\n    array[index] = value;\n}\n\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:255");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function getStringArray(index, strs) {\nreturn strs[index];\n}\n\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:256");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "var NULL = null;" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:257");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "var globalArgs;\nvar globalArgsCount;\nvar globalTrace = false;\nvar globalStepTrace = false;" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:258");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "function character(num) {}" );

if (globalTrace)
    printf("Leaving nodeIncludes\n");

}


//Building function nodeTypeDecl from line: 262

void nodeTypeDecl(list l ) {
  
if (globalTrace)
    printf("nodeTypeDecl at node.qon:262 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l ), 2 )) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:266");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1 );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:267");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s %s;\n" , stringify(second(l )), stringify(nodeTypeMap(listLast(l ))), stringify(first(l )));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:273");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1 );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:274");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s;\n" , stringify(nodeTypeMap(listLast(l ))), stringify(car(l )));

  };

if (globalTrace)
    printf("Leaving nodeTypeDecl\n");

}


//Building function nodeStructComponents from line: 279

void nodeStructComponents(list node ) {
  
if (globalTrace)
    printf("nodeStructComponents at node.qon:279 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:285");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeTypeDecl(car(node ));

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:285");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeStructComponents(cdr(node ));

  };

if (globalTrace)
    printf("Leaving nodeStructComponents\n");

}


//Building function nodeStruct from line: 287

void nodeStruct(list node ) {
  
if (globalTrace)
    printf("nodeStruct at node.qon:287 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:290");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeStructComponents(cdr(car(node )));

if (globalTrace)
    printf("Leaving nodeStruct\n");

}


//Building function nodeTypeMap from line: 292

box nodeTypeMap(box aSym ) {
  list symMap = NULL ;

if (globalTrace)
    printf("nodeTypeMap at node.qon:292 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:297");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray" ), boxSymbol("char**" ), alistCons(boxSymbol("string" ), boxSymbol("char*" ), NULL ));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym ), symMap ))) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:303");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cdr(assoc(stringify(aSym ), symMap )));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:304");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym );

  };

if (globalTrace)
    printf("Leaving nodeTypeMap\n");

}


//Building function nodeFuncMap from line: 307

box nodeFuncMap(box aSym ) {
  list symMap = NULL ;

if (globalTrace)
    printf("nodeFuncMap at node.qon:307 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol" , boxType(aSym ))) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:313");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("=" ), boxSymbol("equal" ), alistCons(boxSymbol("sub-string" ), boxSymbol("sub_string" ), alistCons(boxSymbol("read-file" ), boxSymbol("read_file" ), alistCons(boxSymbol("write-file" ), boxSymbol("write_file" ), alistCons(boxSymbol(">" ), boxSymbol("greaterthan" ), alistCons(boxSymbol("string-length" ), boxSymbol("string_length" ), alistCons(boxSymbol("nil" ), boxSymbol("NULL" ), NULL )))))));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym ), symMap ))) {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:335");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cdr(assoc(stringify(aSym ), symMap )));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:336");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(aSym );

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:337");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym );

  };

if (globalTrace)
    printf("Leaving nodeFuncMap\n");

}


//Building function nodeType from line: 338

void nodeType(list node ) {
  
if (globalTrace)
    printf("nodeType at node.qon:338 (%s)\n", caller);

if (globalTrace)
    printf("Leaving nodeType\n");

}


//Building function nodeTypes from line: 342

void nodeTypes(list nodes ) {
  
if (globalTrace)
    printf("nodeTypes at node.qon:342 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from node.qon:348");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeType(car(nodes ));

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:348");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    nodeTypes(cdr(nodes ));

  };

if (globalTrace)
    printf("Leaving nodeTypes\n");

}


//Building function nodeCompile from line: 350

void nodeCompile(char* filename ) {
  char* programStr = "" ;
list tree = NULL ;
list program = NULL ;

if (globalTrace)
    printf("nodeCompile at node.qon:350 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:354");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:355");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr , filename );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:357");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = alistCons(boxString("includes" ), astIncludes(first(tree )), alistCons(boxString("types" ), astTypes(second(tree )), alistCons(boxString("functions" ), astFunctions(third(tree )), NULL )));

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:365");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = mergeIncludes(program );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:366");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeIncludes(cdr(assoc("includes" , program )));

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:367");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeTypes(childrenof(cdr(assoc("types" , program ))));

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:368");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nvar globalStackTrace = NULL;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:369");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nvar caller = \"\";\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:370");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nfunction isNil(p) {\n    return p == NULL;\n}\n\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:371");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  nodeFunctions(cdr(assoc("children" , cdr(cdr(assoc("functions" , program ))))));

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:373");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:374");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("const [asfdasdf, ...qwerqwer] = process.argv;" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:375");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("globalArgs = qwerqwer;" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:376");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("globalArgsCount = qwerqwer.length;" );

if (globalTrace)
    snprintf(caller, 1024, "from node.qon:377");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "start();\n" );

if (globalTrace)
    printf("Leaving nodeCompile\n");

}


//Building function javaFunctionArgs from line: 3

void javaFunctionArgs(list tree ) {
  
if (globalTrace)
    printf("javaFunctionArgs at java.qon:3 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:8");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(javaTypeMap(first(tree )));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:9");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" " );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:10");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(second(tree ));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:11");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:11");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("," );

    };

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:12");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaFunctionArgs(cddr(tree ));

  };

if (globalTrace)
    printf("Leaving javaFunctionArgs\n");

}


//Building function javaLeaf from line: 14

void javaLeaf(list thisNode ,int indent ) {
  
if (globalTrace)
    printf("javaLeaf at java.qon:14 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:15");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  display(javaFuncMap(codeof(thisNode )));

if (globalTrace)
    printf("Leaving javaLeaf\n");

}


//Building function javaStructGetterExpression from line: 17

void javaStructGetterExpression(list thisNode ,int indent ) {
  
if (globalTrace)
    printf("javaStructGetterExpression at java.qon:17 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("structGetter" ), subnameof(thisNode ))) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:20");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaGetStruct(thisNode , indent );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:21");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaLeaf(thisNode , indent );

  };

if (globalTrace)
    printf("Leaving javaStructGetterExpression\n");

}


//Building function javaExpression from line: 23

void javaExpression(list node ,int indent ) {
  
if (globalTrace)
    printf("javaExpression at java.qon:23 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isLeaf(node )) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:26");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(javaFuncMap(codeof(node )));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:27");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaSubExpression(node , indent );

  };

if (globalTrace)
    printf("Leaving javaExpression\n");

}


//Building function javaRecurList from line: 29

void javaRecurList(list expr ,int indent ) {
  
if (globalTrace)
    printf("javaRecurList at java.qon:29 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(expr )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:36");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaExpression(car(expr ), indent );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cdr(expr ))) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:38");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:39");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(", " );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:39");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      javaRecurList(cdr(expr ), indent );

    };

  };

if (globalTrace)
    printf("Leaving javaRecurList\n");

}


//Building function javaSubExpression from line: 41

void javaSubExpression(list tree ,int indent ) {
  box thing = NULL ;

if (globalTrace)
    printf("javaSubExpression at java.qon:41 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNode(childrenof(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:47");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      javaSubExpression(childrenof(tree ), indent );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isLeaf(tree )) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:50");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        display(javaFuncMap(codeof(tree )));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equal(1 , listLength(childrenof(tree )))) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:54");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          display(codeof(car(childrenof(tree ))));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxString("return" ), codeof(car(childrenof(tree ))))) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:58");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("" );

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:59");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("()" );

          };

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:61");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          thing = codeof(car(childrenof(tree )));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalBox(boxSymbol("get-struct" ), thing )) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:64");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s.%s" , stringify(codeof(second(childrenof(tree )))), stringify(codeof(third(childrenof(tree )))));

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( equalBox(boxSymbol("new" ), thing )) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:71");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("new %s()" , stringify(codeof(third(childrenof(tree )))));

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:75");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("%s(" , stringify(javaFuncMap(codeof(car(childrenof(tree ))))));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:79");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              javaRecurList(cdr(childrenof(tree )), indent );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:80");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf(")" );

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

void javaIf(list node ,int indent ) {
  
if (globalTrace)
    printf("javaIf at java.qon:81 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:83");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:84");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("if ( " );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:85");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaExpression(car(first(childrenof(node ))), 0 );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:86");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(") {" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:87");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaBody(second(childrenof(node )), add1(indent ));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:88");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:89");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("} else {" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:90");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaBody(third(childrenof(node )), add1(indent ));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:91");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:92");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("}" );

if (globalTrace)
    printf("Leaving javaIf\n");

}


//Building function javaSetStruct from line: 94

void javaSetStruct(list node ,int indent ) {
  
if (globalTrace)
    printf("javaSetStruct at java.qon:94 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:96");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:97");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s.%s = " , stringify(first(codeof(node ))), stringify(second(codeof(node ))));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:101");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaExpression(childrenof(node ), indent );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:102");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(";" );

if (globalTrace)
    printf("Leaving javaSetStruct\n");

}


//Building function javaGetStruct from line: 105

void javaGetStruct(list node ,int indent ) {
  
if (globalTrace)
    printf("javaGetStruct at java.qon:105 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:107");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:108");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s.%s" , stringify(first(codeof(node ))), stringify(second(codeof(node ))));

if (globalTrace)
    printf("Leaving javaGetStruct\n");

}


//Building function javaSet from line: 113

void javaSet(list node ,int indent ) {
  
if (globalTrace)
    printf("javaSet at java.qon:113 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:115");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:116");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s = " , stringify(first(codeof(node ))));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:117");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaExpression(childrenof(node ), indent );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:118");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(";" );

if (globalTrace)
    printf("Leaving javaSet\n");

}


//Building function javaStatement from line: 121

void javaStatement(list node ,int indent ) {
  
if (globalTrace)
    printf("javaStatement at java.qon:121 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(boxString("setter" ), subnameof(node ))) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:124");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaSet(node , indent );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalBox(boxString("structSetter" ), subnameof(node ))) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:127");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      javaSetStruct(node , indent );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalBox(boxString("if" ), subnameof(node ))) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:130");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        javaIf(node , indent );

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalBox(boxString("returnvoid" ), subnameof(node ))) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:133");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:133");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("return;" );

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:135");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          newLine(indent );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:136");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          javaExpression(childrenof(node ), indent );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:137");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf(";" );

        };

      };

    };

  };

if (globalTrace)
    printf("Leaving javaStatement\n");

}


//Building function javaBody from line: 141

void javaBody(list tree ,int indent ) {
  
if (globalTrace)
    printf("javaBody at java.qon:141 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:146");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:147");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:148");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaStatement(car(tree ), indent );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:149");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaBody(cdr(tree ), indent );

  };

if (globalTrace)
    printf("Leaving javaBody\n");

}


//Building function javaDeclarations from line: 151

void javaDeclarations(list decls ,int indent ) {
  box decl = NULL ;

if (globalTrace)
    printf("javaDeclarations at java.qon:151 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(decls )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:156");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = car(decls );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:157");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s = " , stringify(javaTypeMap(first(decl ))), stringify(second(decl )));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:161");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(javaFuncMap(third(decl )));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:162");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:163");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaDeclarations(cdr(decls ), indent );

  };

if (globalTrace)
    printf("Leaving javaDeclarations\n");

}


//Building function javaFunction from line: 165

void javaFunction(list node ) {
  box name = NULL ;

if (globalTrace)
    printf("javaFunction at java.qon:165 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:167");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = subnameof(node );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:168");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n\n//Building function %s from line: %s" , stringify(name ), stringify(getTag(name , boxString("line" ))));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:169");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  newLine(0 );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(node )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:173");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(0 );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:174");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("public %s %s(" , stringify(javaTypeMap(cdr(assoc("outtype" , cdr(node ))))), stringify(subnameof(node )));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:178");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaFunctionArgs(cdr(assoc("intype" , cdr(node ))));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:179");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(") {" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:180");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    newLine(1 );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:181");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaDeclarations(declarationsof(node ), 1 );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name ), noStackTrace ())) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:183");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:185");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    };

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name ), noStackTrace ())) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:187");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
    };

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:191");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaBody(childrenof(node ), 1 );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(toStr(name ), noStackTrace ())) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:193");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString("void" , stringify(javaTypeMap(cdr(assoc("outtype" , cdr(node ))))))) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:197");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("\nif (globalTrace)\n   System.out. printf(\"Leaving %s\\n\");\n" , stringify(name ));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:198");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("" );

      };

    };

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:200");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n}\n" );

  };

if (globalTrace)
    printf("Leaving javaFunction\n");

}


//Building function javaFunctions from line: 204

void javaFunctions(list tree ) {
  
if (globalTrace)
    printf("javaFunctions at java.qon:204 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:208");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaFunction(car(tree ));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:208");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaFunctions(cdr(tree ));

  };

if (globalTrace)
    printf("Leaving javaFunctions\n");

}


//Building function javaIncludes from line: 210

void javaIncludes(list nodes ) {
  
if (globalTrace)
    printf("javaIncludes at java.qon:210 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:212");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "public void panic(String s) {System.exit(1);}\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:213");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "public int sub(int a, int b) { return a - b; }\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:214");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "public double mult(int a, int b) { return a * b; }\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:215");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "public boolean greaterthan(int a, int b) { return a > b; }\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:216");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "public double subf(double a, double b) { return a - b; }\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:217");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "public double multf(double a, double b) { return a * b; }\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:218");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "public boolean greaterthanf(double a, double b) { return a > b; }\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:219");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "public boolean equal(int a, int b) { return a == b; }\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:220");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "public boolean equalString(String a, String b) { return a.equals(b); }\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:221");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "public boolean andBool(boolean a, boolean b) { return a == b;}\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:222");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "public int string_length(String s) { return s.length();}\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:223");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "public String stringConcatenate(String s1, String s2) { return s1 + s2; }\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:224");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "public int strcmp(String s1, String s2) { return s1.compareTo(s2);}\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:225");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "public String read_file(String filename) {try { return new String(Files.readAllBytes(Paths.get(filename)));} catch (Exception e) {panic(\"Could not read file\");return \"\";}}\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:226");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "public void write_file(String filename, String data) {try {Files.write(Paths.get(filename), data.getBytes(\"UTF-8\"));} catch (Exception e) {panic(\"Could not write file\");}}\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:227");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "public String sub_string(String s, int start, int length) {\nreturn s.substring(start, start+length);\n}\n\n\n\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:228");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "public String intToString(int num) { char c=(char) num;  String s=Character.toString(c); return s;}" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:229");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "public String character(int num) { char c=(char) num;  String s=Character.toString(c); return s;}" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:230");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "public String getStringArray(int index, String[] arr) { return arr[index];}" );

if (globalTrace)
    printf("Leaving javaIncludes\n");

}


//Building function javaTypeDecl from line: 233

void javaTypeDecl(list l ) {
  
if (globalTrace)
    printf("javaTypeDecl at java.qon:233 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l ), 2 )) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:237");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1 );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:238");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s;\n" , stringify(javaTypeMap(listLast(l ))), stringify(first(l )));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:244");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1 );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:245");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s %s;\n" , stringify(javaTypeMap(listLast(l ))), stringify(car(l )));

  };

if (globalTrace)
    printf("Leaving javaTypeDecl\n");

}


//Building function javaStructComponents from line: 250

void javaStructComponents(list node ) {
  
if (globalTrace)
    printf("javaStructComponents at java.qon:250 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:254");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaTypeDecl(car(node ));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:254");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaStructComponents(cdr(node ));

  };

if (globalTrace)
    printf("Leaving javaStructComponents\n");

}


//Building function javaStruct from line: 256

void javaStruct(list node ) {
  
if (globalTrace)
    printf("javaStruct at java.qon:256 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:257");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaStructComponents(cdr(car(node )));

if (globalTrace)
    printf("Leaving javaStruct\n");

}


//Building function javaTypeMap from line: 259

box javaTypeMap(box aSym ) {
  list symMap = NULL ;

if (globalTrace)
    printf("javaTypeMap at java.qon:259 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:262");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("pair" ), boxSymbol("Box" ), alistCons(boxSymbol("bool" ), boxSymbol("boolean" ), alistCons(boxSymbol("box" ), boxSymbol("Box" ), alistCons(boxSymbol("list" ), boxSymbol("Box" ), alistCons(boxSymbol("Box*" ), boxSymbol("Box" ), alistCons(boxSymbol("struct" ), boxSymbol("" ), alistCons(boxSymbol("int" ), boxSymbol("Integer" ), alistCons(boxSymbol("float" ), boxSymbol("double" ), alistCons(boxSymbol("stringArray" ), boxSymbol("String[]" ), alistCons(boxSymbol("string" ), boxSymbol("String" ), NULL ))))))))));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym ), symMap ))) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:274");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cdr(assoc(stringify(aSym ), symMap )));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:275");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym );

  };

if (globalTrace)
    printf("Leaving javaTypeMap\n");

}


//Building function javaTypesNoDeclare from line: 277

box javaTypesNoDeclare() {
  list syms = NULL ;

if (globalTrace)
    printf("javaTypesNoDeclare at java.qon:277 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:280");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  syms = cons(boxString("pair" ), cons(boxString("box" ), NULL ));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:284");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(syms );

if (globalTrace)
    printf("Leaving javaTypesNoDeclare\n");

}


//Building function javaFuncMap from line: 286

box javaFuncMap(box aSym ) {
  list symMap = NULL ;

if (globalTrace)
    printf("javaFuncMap at java.qon:286 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString("symbol" , boxType(aSym ))) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:291");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    symMap = alistCons(boxSymbol("printf" ), boxSymbol("System.out.printf" ), alistCons(boxSymbol("=" ), boxSymbol("equal" ), alistCons(boxSymbol("sub-string" ), boxSymbol("sub_string" ), alistCons(boxSymbol("read-file" ), boxSymbol("read_file" ), alistCons(boxSymbol("write-file" ), boxSymbol("write_file" ), alistCons(boxSymbol(">" ), boxSymbol("greaterthan" ), alistCons(boxSymbol("string-length" ), boxSymbol("string_length" ), alistCons(boxSymbol("nil" ), boxSymbol("null" ), NULL ))))))));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( truthy(assoc(stringify(aSym ), symMap ))) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:312");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(cdr(assoc(stringify(aSym ), symMap )));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:313");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      return(aSym );

    };

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:314");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym );

  };

if (globalTrace)
    printf("Leaving javaFuncMap\n");

}


//Building function javaType from line: 316

void javaType(list node ) {
  
if (globalTrace)
    printf("javaType at java.qon:316 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalBox(subnameof(node ), boxString("struct" ))) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:320");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\npublic class %s {\n" , stringify(first(codeof(node ))));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:321");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\npublic String caller =\"\";" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:322");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaStruct(cdr(codeof(node )));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:323");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n};\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( inList(boxString(stringify(first(codeof(node )))), javaTypesNoDeclare ())) {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:326");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:328");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("public class %s extends %s {};\n" , stringify(first(codeof(node ))), stringify(javaTypeMap(listLast(codeof(node )))));

    };

  };

if (globalTrace)
    printf("Leaving javaType\n");

}


//Building function javaTypes from line: 332

void javaTypes(list nodes ) {
  
if (globalTrace)
    printf("javaTypes at java.qon:332 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from java.qon:336");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaType(car(nodes ));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:336");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    javaTypes(cdr(nodes ));

  };

if (globalTrace)
    printf("Leaving javaTypes\n");

}


//Building function javaCompile from line: 338

void javaCompile(char* filename ) {
  char* programStr = "" ;
list tree = NULL ;
list program = NULL ;

if (globalTrace)
    printf("javaCompile at java.qon:338 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:340");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "package quonverter;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:341");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "import java.nio.file.Files;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:342");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "import java.nio.file.Paths;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:343");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "import java.io.IOException;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:344");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "import java.io.UnsupportedEncodingException;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:345");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("class MyProgram {\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:346");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\npublic String caller =\"\";" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:347");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  programStr = read_file(filename );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:348");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = readSexpr(programStr , filename );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:350");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = alistCons(boxString("includes" ), astIncludes(first(tree )), alistCons(boxString("types" ), astTypes(second(tree )), alistCons(boxString("functions" ), astFunctions(third(tree )), NULL )));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:359");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  program = mergeIncludes(program );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:360");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaIncludes(cdr(assoc("includes" , program )));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:361");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaTypes(childrenof(cdr(assoc("types" , program ))));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:362");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public boolean globalStackTrace = false;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:363");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public boolean globalStepTrace = false;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:364");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public boolean globalTrace = false;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:365");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public String FILE = null;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:366");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public Integer LINE = 0;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:367");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public static Integer globalArgsCount = 0;\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:368");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("public static String globalArgs[];\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:369");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\npublic boolean isNil(Box p) {\n    return p == null;\n}\n\n\n" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:371");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  javaFunctions(cdr(assoc("children" , cdr(cdr(assoc("functions" , program ))))));

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:373");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "public static void main(String args[]) {\nglobalArgs = args;\nglobalArgsCount = args.length;MyProgram mp = new MyProgram(); mp.start();\n}" );

if (globalTrace)
    snprintf(caller, 1024, "from java.qon:374");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("}\n" );

if (globalTrace)
    printf("Leaving javaCompile\n");

}


//Building function luaFunctionArgs from line: 4

void luaFunctionArgs(int indent ,list tree ) {
  
if (globalTrace)
    printf("luaFunctionArgs at lua.qon:4 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:9");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(second(tree ));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:10");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:10");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("," );

    };

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:11");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaFunctionArgs(indent , cddr(tree ));

  };

if (globalTrace)
    printf("Leaving luaFunctionArgs\n");

}


//Building function luaFunction from line: 14

void luaFunction(int indent ,list functionDefinition ) {
  char* fname = "" ;

if (globalTrace)
    printf("luaFunction at lua.qon:14 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:16");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fname = stringify(second(functionDefinition ));

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:17");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("-- Chose function name %s" , fname );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:18");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nfunction %s(" , fname );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:19");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  luaFunctionArgs(indent , third(functionDefinition ));

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:20");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(")\n" );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:21");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("print(\"caller: \", caller, \"-> %s\")\n" , fname );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:22");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  luaDeclarations(add1(indent ), cdr(fourth(functionDefinition )));

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:23");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  luaBody(fname , indent , cdr(fifth(functionDefinition )));

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:24");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("end\n" );

if (globalTrace)
    printf("Leaving luaFunction\n");

}


//Building function luaDeclarations from line: 26

void luaDeclarations(int indent ,list declarations ) {
  list decl = NULL ;

if (globalTrace)
    printf("luaDeclarations at lua.qon:26 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(declarations )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:32");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = first(declarations );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:33");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("local %s =" , stringify(second(decl )));

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:34");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaExpressionStart(indent , third(decl ));

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:35");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n" );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:36");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaDeclarations(indent , cdr(declarations ));

  };

if (globalTrace)
    printf("Leaving luaDeclarations\n");

}


//Building function luaExpressionStart from line: 42

void luaExpressionStart(int indent ,list program ) {
  
if (globalTrace)
    printf("luaExpressionStart at lua.qon:42 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(program )) {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringify(car(program )), "get-struct" )) {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:52");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s.%s" , stringify(second(program )), stringify(third(program )));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString(stringify(car(program )), ">" )) {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:57");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("greaterthan(" );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:58");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          luaExpression(indent , cdr(program ));

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:59");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf(")" );

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString(stringify(car(program )), "=" )) {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:64");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("equal(" );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:65");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            luaExpression(indent , cdr(program ));

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:66");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf(")" );

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:69");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s(" , stringify(car(program )));

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:70");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            luaExpression(indent , cdr(program ));

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:71");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf(")" );

          };

        };

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:77");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      luaExpression(indent , program );

    };

  };

if (globalTrace)
    printf("Leaving luaExpressionStart\n");

}


//Building function luaExpression from line: 84

void luaExpression(int indent ,list program ) {
  
if (globalTrace)
    printf("luaExpression at lua.qon:84 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(program )) {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isList(car(program ))) {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:94");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        luaExpressionStart(indent , car(program ));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:98");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        display(car(program ));

      };

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( greaterthan(listLength(program ), 1 )) {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:103");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf(", " );

      } else {
      };

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:105");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      luaExpression(indent , cdr(program ));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:108");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(program );

    };

  };

if (globalTrace)
    printf("Leaving luaExpression\n");

}


//Building function luaStatement from line: 112

void luaStatement(int indent ,list statement ) {
  
if (globalTrace)
    printf("luaStatement at lua.qon:112 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(stringify(car(statement )), "if" )) {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:117");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:118");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("if " );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:119");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    add1(indent );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:120");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaExpressionStart(add1(indent ), second(statement ));

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:122");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" then\n" );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:123");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaBody(caller , add1(indent ), cdr(third(statement )));

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:124");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:125");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("else\n" );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:126");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaBody(caller , add1(indent ), cdr(fourth(statement )));

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:127");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:128");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("end\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(stringify(car(statement )), "set" )) {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:133");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printIndent(indent );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:134");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("%s = " , stringify(second(statement )));

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:135");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      luaExpressionStart(add1(indent ), third(statement ));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringify(car(statement )), "set-struct" )) {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:140");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s.%s = " , stringify(second(statement )), stringify(third(statement )));

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:141");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        luaExpressionStart(indent , fourth(statement ));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString(stringify(car(statement )), "return" )) {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:146");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printIndent(indent );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:147");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("return " );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( greaterthan(listLength(statement ), 1 )) {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:150");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            luaExpressionStart(indent , second(statement ));

          } else {
          };

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:152");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("\n" );

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:155");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printIndent(indent );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:156");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          luaExpressionStart(indent , statement );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:157");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf(";\n" );

        };

      };

    };

  };

if (globalTrace)
    printf("Leaving luaStatement\n");

}


//Building function luaBody from line: 164

void luaBody(char* local_caller ,int indent ,list program ) {
  list statement = NULL ;

if (globalTrace)
    printf("luaBody at lua.qon:164 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:169");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    statement = car(program );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:170");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("caller = \"%s:%s:%d\"\n" , local_caller , unBoxString(getTagFail(statement , boxString("filename" ), boxString("Unknown file" ))), unBoxInt(getTagFail(statement , boxString("line" ), boxInt(-1 ))));

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:171");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaStatement(add1(indent ), statement );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:172");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n" );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:173");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaBody(local_caller , indent , cdr(program ));

  };

if (globalTrace)
    printf("Leaving luaBody\n");

}


//Building function luaFunctions from line: 176

void luaFunctions(int indent ,list program ) {
  
if (globalTrace)
    printf("luaFunctions at lua.qon:176 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:182");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaFunction(indent , car(program ));

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:183");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    luaFunctions(indent , cdr(program ));

  };

if (globalTrace)
    printf("Leaving luaFunctions\n");

}


//Building function luaProgram from line: 188

void luaProgram(list program ) {
  
if (globalTrace)
    printf("luaProgram at lua.qon:188 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:190");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  luaIncludes(NULL );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:191");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  luaFunctions(0 , cdr(third(program )));

if (globalTrace)
    printf("Leaving luaProgram\n");

}


//Building function luaIncludes from line: 195

void luaIncludes(list nodes ) {
  
if (globalTrace)
    printf("luaIncludes at lua.qon:195 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:197");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("%s" , "\nfunction luaDump(o)\n   if type(o) == 'table' then\n      local s = '{ '\n      for k,v in pairs(o) do\n         if type(k) ~= 'number' then k = '\"'..k..'\"' end\n         s = s .. '['..k..'] = ' .. luaDump(v) .. ','\n      end\n      return s .. '} '\n   else\n      return tostring(o)\n   end\nend\nprintf = function(s,...)\nreturn io.write(s:format(...))\nend -- function\n    \nfunction stringConcatenate(a,b)\nreturn a..b\nend\n    \nfunction getStringArray(index, arr)\nreturn arr[index]\nend\n       \nfunction luaWriteFile(name, data)  \nlocal file = io.open(name, \"w\")\nfile:write(data)\nfile:close(file)\nend\n    function luaSubstring(s, start, length)\nreturn string.sub(s, start, start+length)\nend\n    \n    function luaReadFile(file)\n      local f = assert(io.open(file, \"rb\"))\n      local content = f:read(\"*all\")      f:close()\n      return content\n    end\n     \nfunction equalString(a,b)\n        return a==b;\n     end\n    \n     function new()\n        return {};\n     end\n    \n     function isNil(val)\n        return val == nil;\n     end\n    \n     function getEnv(key)\n        return os.getenv(key);\n     end\n    \n    function panic(s)\n      print(s);\n    os.exit()\n    end\n    \n    function sub(a, b) \n      return a - b; \n    end\n\n    function mult(a, b) \n      return a * b;\n    end\n    \n    function greaterthan(a, b)\n      return a > b;\n    end\n    \n    function subf(a, b) \n      return a - b;\n    end\n    \n    function multf(a, b)\n      return a * b;\n    end\n    \n    function greaterthanf(a, b)\n      return a > b;\n    end\n    \n    function equal(a, b)\n      return a == b;\n    end\n    \n    function andBool(a, b)\n      return a == b;\n    end\n    \n    function string_length(s)\n      return strlen(s);\n    end\n    \n    function setSubString(target, start, source)\n      panic(\"stub\");\n      end\n    \n    function sub_string(s, start, length)\n      panic(\"stub\");\n    end\n    \n    function intToString(a)\n      panic(\"stub\")\n return a\n    end\n\n    function gc_malloc(size)\n      return \"\"\n    end\n    \n    function makeArray(length)\n      return {}\n    end\n    \n    function at(arr, index)\n      return arr[index+1];\n    end\n    \n    function setAt(array, index, value)\n      array[index+1] = value;\n    end\n    \n    function read_file(file)\n      local f = io.open(file, \"r\")\n      local content = \"\"\n      local length = 0\n\n      while f:read(0) ~= \"\" do\n          local current = f:read(\"*all\")\n\n          print(#current, length)\n          length = length + #current\n\n          content = content .. current\n      end\n\n      return content\n    end\n    \n    function write_file(filename, data)\n      local file = io.open(filename,'w')\n      file:write(tostring(data))\n      file:close()\n    end\n    \n    caller=\"main\";\n    \n    globalArgs={};\n    globalArgsCount=0;\n    globalTrace = false;\n    globalStepTrace = false;\n\n    function main()\n      globalArgs = arg;\n      globalArgsCount = #arg + 1;\n      return start();\n    end\n    \n" );

if (globalTrace)
    printf("Leaving luaIncludes\n");

}


//Building function luaCompile from line: 203

void luaCompile(char* filename ) {
  list tree = NULL ;

if (globalTrace)
    printf("luaCompile at lua.qon:203 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:206");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon("compiler.qon" );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:209");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:210");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:211");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree , "write-file" , "luaWriteFile" );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:212");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree , "read-file" , "luaReadFile" );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:213");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree , "string-length" , "string.len" );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:215");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree , "sub-string" , "luaSubstring" );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:216");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree , "stringLength" , "string.len" );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:218");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  luaProgram(tree );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:219");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n" );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:220");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("function main()\nglobalArgs = arg\nglobalArgsCount = #arg\nstart()\nend\n" );

if (globalTrace)
    snprintf(caller, 1024, "from lua.qon:221");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("main()" );

if (globalTrace)
    printf("Leaving luaCompile\n");

}


//Building function imaFunctionArgs from line: 20

void imaFunctionArgs(int indent ,list tree ) {
  
if (globalTrace)
    printf("imaFunctionArgs at imaginary.qon:20 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(tree )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:25");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(second(tree ));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:26");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(": " );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:27");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    display(first(tree ));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isNil(cddr(tree ))) {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:28");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:28");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(", " );

    };

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:29");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaFunctionArgs(indent , cddr(tree ));

  };

if (globalTrace)
    printf("Leaving imaFunctionArgs\n");

}


//Building function imaFunction from line: 32

void imaFunction(int indent ,list functionDefinition ) {
  char* fname = "" ;

if (globalTrace)
    printf("imaFunction at imaginary.qon:32 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:34");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  fname = stringify(second(functionDefinition ));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:37");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nfu %s(" , fname );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:38");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaFunctionArgs(indent , third(functionDefinition ));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:39");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf(") " );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:40");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("-> %s" , stringify(first(functionDefinition )));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:42");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaDeclarations(add1(indent ), cdr(fourth(functionDefinition )));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(cdr(fourth(functionDefinition ))), 0 )) {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:45");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:46");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" " );

  };

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:47");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printIndent(indent );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:48");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("in\n" );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:50");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaBody(fname , indent , cdr(fifth(functionDefinition )));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:51");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("end function\n" );

if (globalTrace)
    printf("Leaving imaFunction\n");

}


//Building function imaDeclarations from line: 53

void imaDeclarations(int indent ,list declarations ) {
  list decl = NULL ;

if (globalTrace)
    printf("imaDeclarations at imaginary.qon:53 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(declarations )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:60");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    decl = first(declarations );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:61");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n" );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:62");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:63");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s: %s " , stringify(second(decl )), stringify(first(decl )));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:64");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaExpressionStart(indent , third(decl ));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:66");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaDeclarations(indent , cdr(declarations ));

  };

if (globalTrace)
    printf("Leaving imaDeclarations\n");

}


//Building function imaExpressionStart from line: 72

void imaExpressionStart(int indent ,list program ) {
  
if (globalTrace)
    printf("imaExpressionStart at imaginary.qon:72 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(program )) {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringify(car(program )), "get-struct" )) {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:82");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s.%s" , stringify(second(program )), stringify(third(program )));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString(stringify(car(program )), ">" )) {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:87");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("greaterthan(" );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:88");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          imaExpression(indent , cdr(program ));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:89");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf(")" );

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( equalString(stringify(car(program )), "=" )) {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:94");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("equal(" );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:95");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            imaExpression(indent , cdr(program ));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:96");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf(")" );

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:99");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("%s(" , stringify(car(program )));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:100");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            imaExpression(indent , cdr(program ));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:101");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf(")" );

          };

        };

      };

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:107");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      imaExpression(indent , program );

    };

  };

if (globalTrace)
    printf("Leaving imaExpressionStart\n");

}


//Building function imaExpression from line: 114

void imaExpression(int indent ,list program ) {
  
if (globalTrace)
    printf("imaExpression at imaginary.qon:114 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( isList(program )) {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( isList(car(program ))) {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:124");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        imaExpressionStart(indent , car(program ));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:128");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        display(car(program ));

      };

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( greaterthan(listLength(program ), 1 )) {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:133");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf(", " );

      } else {
      };

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:135");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      imaExpression(indent , cdr(program ));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:138");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(program );

    };

  };

if (globalTrace)
    printf("Leaving imaExpression\n");

}


//Building function imaStatement from line: 142

void imaStatement(int indent ,list statement ) {
  
if (globalTrace)
    printf("imaStatement at imaginary.qon:142 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( equalString(stringify(car(statement )), "if" )) {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:147");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:148");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("if " );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:149");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    add1(indent );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:150");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaExpressionStart(add1(indent ), second(statement ));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:152");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(" then\n" );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:153");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaBody(caller , add1(indent ), cdr(third(statement )));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:154");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:155");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("else\n" );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:156");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaBody(caller , add1(indent ), cdr(fourth(statement )));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:157");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(indent );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:158");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("end\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( equalString(stringify(car(statement )), "set" )) {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:163");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printIndent(indent );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:164");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf("%s = " , stringify(second(statement )));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:165");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      imaExpressionStart(add1(indent ), third(statement ));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:166");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      printf(";\n" );

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( equalString(stringify(car(statement )), "set-struct" )) {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:171");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printIndent(indent );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:172");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf("%s.%s = " , stringify(second(statement )), stringify(third(statement )));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:173");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        imaExpressionStart(indent , fourth(statement ));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:174");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        printf(";\n" );

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( equalString(stringify(car(statement )), "return" )) {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:179");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printIndent(indent );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:180");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("return; " );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( greaterthan(listLength(statement ), 1 )) {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:183");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            imaExpressionStart(indent , second(statement ));

          } else {
          };

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:185");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("\n" );

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:188");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printIndent(indent );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:189");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          imaExpressionStart(indent , statement );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:190");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf(";\n" );

        };

      };

    };

  };

if (globalTrace)
    printf("Leaving imaStatement\n");

}


//Building function imaBody from line: 197

void imaBody(char* local_caller ,int indent ,list program ) {
  list statement = NULL ;

if (globalTrace)
    printf("imaBody at imaginary.qon:197 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:202");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    statement = car(program );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:204");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaStatement(add1(indent ), statement );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:205");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaBody(local_caller , indent , cdr(program ));

  };

if (globalTrace)
    printf("Leaving imaBody\n");

}


//Building function imaFunctions from line: 208

void imaFunctions(int indent ,list program ) {
  
if (globalTrace)
    printf("imaFunctions at imaginary.qon:208 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isNil(program )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:214");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaFunction(indent , car(program ));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:215");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaFunctions(indent , cdr(program ));

  };

if (globalTrace)
    printf("Leaving imaFunctions\n");

}


//Building function imaTypeDecl from line: 218

void imaTypeDecl(list l ) {
  char* name = "" ;
list body = NULL ;

if (globalTrace)
    printf("imaTypeDecl at imaginary.qon:218 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:223");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = stringify(first(l ));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:224");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  body = cdr(l );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(l ), 2 )) {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:227");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1 );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:228");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s is " , name );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:232");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    displayList(body , 0 , true );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:233");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf(";\n" );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:237");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printIndent(1 );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:238");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("%s is %s;\n" , name , stringify(second(l )));

  };

if (globalTrace)
    printf("Leaving imaTypeDecl\n");

}


//Building function imaStructComponents from line: 243

void imaStructComponents(list node ) {
  
if (globalTrace)
    printf("imaStructComponents at imaginary.qon:243 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(node )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:247");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaTypeDecl(car(node ));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:247");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaStructComponents(cdr(node ));

  };

if (globalTrace)
    printf("Leaving imaStructComponents\n");

}


//Building function imaStruct from line: 249

void imaStruct(list node ) {
  
if (globalTrace)
    printf("imaStruct at imaginary.qon:249 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:250");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaStructComponents(cdr(car(node )));

if (globalTrace)
    printf("Leaving imaStruct\n");

}


//Building function imaTypeMap from line: 252

box imaTypeMap(box aSym ) {
  list symMap = NULL ;

if (globalTrace)
    printf("imaTypeMap at imaginary.qon:252 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:255");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  symMap = alistCons(boxSymbol("stringArray" ), boxSymbol("char**" ), alistCons(boxSymbol("string" ), boxSymbol("char*" ), NULL ));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( truthy(assoc(stringify(aSym ), symMap ))) {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:261");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(cdr(assoc(stringify(aSym ), symMap )));

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:262");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return(aSym );

  };

if (globalTrace)
    printf("Leaving imaTypeMap\n");

}


//Building function imaType from line: 264

void imaType(list node ) {
  char* name = "" ;
list body = NULL ;

if (globalTrace)
    printf("imaType at imaginary.qon:264 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:269");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  name = stringify(first(node ));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:270");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  body = cdr(node );

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isList(first(body ))) {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:273");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\ntype %s is struct (\n" , name );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:274");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaStruct(body );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:275");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n);\n" , name );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:276");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("type" );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:276");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaTypeDecl(node );

  };

if (globalTrace)
    printf("Leaving imaType\n");

}


//Building function imaTypes from line: 279

void imaTypes(int indent ,list nodes ) {
  
if (globalTrace)
    printf("imaTypes at imaginary.qon:279 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( isEmpty(nodes )) {    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    return;

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:284");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaType(car(nodes ));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:284");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    imaTypes(indent , cdr(nodes ));

  };

if (globalTrace)
    printf("Leaving imaTypes\n");

}


//Building function imaProgram from line: 288

void imaProgram(list program ) {
  
if (globalTrace)
    printf("imaProgram at imaginary.qon:288 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:290");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaIncludes(0 , cdr(first(program )));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:291");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nTypes:\n" );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:292");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaTypes(0 , cdr(second(program )));

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:293");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\nFunctions:\n" );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:294");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaFunctions(0 , cdr(third(program )));

if (globalTrace)
    printf("Leaving imaProgram\n");

}


//Building function imaIncludes from line: 298

void imaIncludes(int indent ,list nodes ) {
  
if (globalTrace)
    printf("imaIncludes at imaginary.qon:298 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:300");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("Includes: \n" );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:301");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  displayList(nodes , 0 , true );

if (globalTrace)
    printf("Leaving imaIncludes\n");

}


//Building function imaCompile from line: 305

void imaCompile(char* filename ) {
  list tree = NULL ;

if (globalTrace)
    printf("imaCompile at imaginary.qon:305 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:308");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadQuon("compiler.qon" );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:311");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = loadIncludes(tree );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:312");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrowalk(tree );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:313");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree , "write-file" , "imaWriteFile" );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:314");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree , "read-file" , "imaReadFile" );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:315");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree , "string-length" , "string.len" );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:317");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree , "sub-string" , "imaSubstring" );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:318");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  tree = macrosingle(tree , "stringLength" , "string.len" );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:320");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  imaProgram(tree );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:321");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("\n" );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:322");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("function main()\nglobalArgs = arg\nglobalArgsCount = #arg\nstart()\nend\n" );

if (globalTrace)
    snprintf(caller, 1024, "from imaginary.qon:323");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  printf("main()" );

if (globalTrace)
    printf("Leaving imaCompile\n");

}


//Building function start from line: 4

int start() {
  bool runTests = false ;
list cmdLine = NULL ;
box filename = NULL ;
bool runPerl = false ;
bool runJava = false ;
bool runAst = false ;
bool runNode = false ;
bool runLua = false ;
bool runIma = false ;
bool runTree = false ;

if (globalTrace)
    printf("start at compiler.qon:4 (%s)\n", caller);

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:17");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  cmdLine = listReverse(argList(globalArgsCount , 0 , globalArgs ));

if (globalTrace)
    snprintf(caller, 1024, "from Unknown:Unknown");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( greaterthan(listLength(cmdLine ), 1 )) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:20");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    filename = second(cmdLine );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:21");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    filename = boxString("compiler.qon" );

  };

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:23");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runTests = inList(boxString("--test" ), cmdLine );

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:24");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runJava = inList(boxString("--java" ), cmdLine );

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:25");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runPerl = inList(boxString("--perl" ), cmdLine );

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:26");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runAst = inList(boxString("--ast" ), cmdLine );

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:27");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runTree = inList(boxString("--tree" ), cmdLine );

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:28");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runNode = inList(boxString("--node" ), cmdLine );

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:29");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runLua = inList(boxString("--lua" ), cmdLine );

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:30");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  runIma = inList(boxString("--ima" ), cmdLine );

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:31");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalTrace = inList(boxString("--trace" ), cmdLine );

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:32");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  globalStepTrace = inList(boxString("--steptrace" ), cmdLine );

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:33");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  if ( runTests ) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:35");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test0 ();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:36");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test1 ();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:37");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test2 ();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:38");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test3 ();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:39");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test4 ();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:40");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test5 ();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:41");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test6 ();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:42");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test7 ();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:43");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test8 ();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:44");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test9 ();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:45");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test10 ();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:46");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test12 ();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:47");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test13 ();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:48");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test15 ();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:49");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test16 ();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:50");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test17 ();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:51");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test18 ();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:52");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test19 ();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:53");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test20 ();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:54");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    test21 ();

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:55");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    printf("\n\nAfter all that hard work, I need a beer...\n" );

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:56");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    beers(9 );

  } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:58");
    if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

    if ( runTree ) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:59");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      display(macrowalk(treeCompile(unBoxString(filename ))));

    } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:61");
      if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

      if ( runAst ) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:62");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        astCompile(unBoxString(filename ));

      } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:63");
        if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

        if ( runNode ) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:65");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          nodeCompile(unBoxString(filename ));

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:65");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          printf("\n" );

        } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:68");
          if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

          if ( runPerl ) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:69");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            perlCompile(unBoxString(filename ));

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:69");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            printf("\n" );

          } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:71");
            if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

            if ( runJava ) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:72");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              javaCompile(unBoxString(filename ));

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:72");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              printf("\n" );

            } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:74");
              if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

              if ( runLua ) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:75");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                luaCompile(unBoxString(filename ));

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:75");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                printf("\n" );

              } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:77");
                if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                if ( runIma ) {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:78");
                  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                  imaCompile(unBoxString(filename ));

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:78");
                  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                  printf("\n" );

                } else {
if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:80");
                  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                  ansiCompile(unBoxString(filename ));

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:80");
                  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

                  printf("\n" );

                };

              };

            };

          };

        };

      };

    };

  };

if (globalTrace)
    snprintf(caller, 1024, "from compiler.qon:82");
  if (globalStepTrace) printf("StepTrace %s:%d\n", __FILE__, __LINE__);

  return(0 );

if (globalTrace)
    printf("Leaving start\n");

}


