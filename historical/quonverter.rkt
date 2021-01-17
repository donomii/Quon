#lang racket
[require srfi/1]
[require srfi/13]
(require racket/pretty)
; Support functions

[define debug_expressions #f]

[define debug [lambda messages
                [when debug_expressions
                  [apply printf messages]]]]

[define annotate [lambda messages
                   [if debug_expressions
                       [format "**!!~a!!**" messages]
                       ""]]]

[define [id x] x]

[define [walk tree func]
  [if [list? tree]
      [let [[newTree [map [lambda [branch] [func branch]] [func tree]]]]
        [map [lambda [branch] [walk branch func]] [func newTree]]]
      tree
      ]]

[define uniqNum 0]
[define [unique-number]
  [set! uniqNum [add1 uniqNum]]
  uniqNum]


;Accessors
[define [typesof x]
  [if [equal? [length x] 1]
      '[]
      [cdr [assoc 'types  x]]]]


[define [codeof x]
  [if [equal? [length x] 1]
      '[]
      [cdr [assoc 'code  x]]
      ]
  ]

[define [nodeof x]
  [if [equal? [length x] 1]
      '[]
      [cdr [assoc 'node  x]]
      ]
  ]

[define [nameof x]
  [if [equal? [length x] 1]
      '[]
      [cdr [assoc 'name  x]]]]

[define [childrenof x]
  [if [equal? [length x] 1]
      '[]
      [cdr [assoc 'children  x]]
      ]
  ]
 
[define [idof x]
 
  [cdr [assoc 'id  x]]
    
  ]

(define (swap-every-2 lst)
  (if (or (null? lst) 
          (null? (cdr lst)))
      lst
      (list* (cadr lst) 
             (car lst) 
             (swap-every-2 (cddr lst)))))

(define (ndelete lst n)
  (let recur ((i 1)
              (rest lst))
    (cond ((null? rest) '())
          ((= i n) (recur 1 (cdr rest)))
          (else (cons (car rest) (recur (+ i 1) (cdr rest)))))))

(define (nth-places n lst [i 0])
  (cond
    [(null? lst) null]
    [(= i 0) (cons (car lst)
                   (nth-places n (cdr lst) (+ i 1)))]
    [(= i n) (nth-places n (cdr lst) 0)]
    [else (nth-places n (cdr lst) (+ i 1))]))

[define [make-pairs lst]
  [if [empty? lst]
      lst
      [cons [take lst 2] [make-pairs [drop lst 2]]]]]
  





; JS output functions

;output include statements
[define [js_includes tree]
  [list "//Include libraries and headers\n"
        "var util = require('util');\n"
        "var fs = require('fs');\n"
        "function equal(a,b) {return a===b}\n"
        "function equalString(a,b) {return a.toString()===b.toString() }\n"
        "function sub (a,b){return a-b}\n"
        "function subf (a,b){return a-b}\n"
        "function mult (a,b){return a*b}\n"
        "function multf (a,b){return a*b}\n"
        "function greaterthan(a,b){return a>b}\n"
        "function greaterthanf(a,b){return a>b}\n"
        "function makeArray(){return [];}\n"
        "function at(arr, index) {return arr[index];}\n"
        "function printf() {process.stdout.write(util.format.apply(this, arguments));}\n"
        "function read_file(filename) {return fs.readFileSync(filename);}\n"
        "function write_file(filename, data) {fs.writeFileSync(filename, data);}\n"
        "function string_length(str){str=''+str;return str.length;}\n"
        "function sub_string(str, start, len) {str = ''+str;return str.substring(start, start+len)};\n"
        "function isNil(b) {return b==null}\n"
        "function stringConcatenate(a,b){return a.toString()+b.toString()}\n"
        "function andBool(a,b){return a==b}\n"
        "function panic(s){console.trace(s);process.exit(1);}\n"
        "function dump(s){console.log(s)}"
        "function getStringArray(index, arr) { return arr[index]; }"
        "var globalArgs;\n"
        "var globalArgsCount\n"
        "function main() {
globalArgs=process.argv;
globalArgsCount = process.argv.length
start();
}"
        
        
        ;[map [lambda [x]  [format "#include <~s>~n" x] ] [cdr [codeof tree]]]
        "\n"]]

[define [js_struct_components tree]
  [string-join [map [lambda [x] [format "    //~a ~a;\n" [js_typemap [car x]] [cadr x]]] [cdr tree]]]
  ]
;output type definition statements
[define [js_struct tree]
  [list
   [format "var ~a = {\n~a};\n"  [car tree] [js_struct_components [cadr tree]] ]
   ]]

;output type definition statements
[define [js_typedef tree]
  [list
   [format "var ~a = ~a;\n"   [car tree] [js_typemap [cadr tree]]]
   ]]

;output type definition statements
[define [js_types tree]
  [list "//Type definitions\n"
        [map [lambda [x]
               ;[displayln [format "a type: ~a~n" [second x]]]
               ;actually all types will be a list, need to check for 'stuct
               [if [list? [second x]]
                   ;it is a struct
                   [js_struct x]
                   [js_typedef x]]] [cdr [codeof tree]]]
        "\n"]]

[define [js_detect_variable types atom]
  ;[display [format "Types: ~s    Atom: ~s~n" types atom]]
  [if [assoc atom types]
      [format "$~a"  atom ]
      atom
      ]
  ]

[define [js_subexpression node]
  ;[displayln[format  "subexpr: ~s" node]][newline]
  [if [is-leaf? node]
      [format "~s" [js_funcmap[codeof node]]]
      [js_expression node]]]

;output an expression.  Soon, recursive!
[define [js_expression tree]
  ;[displayln[format  "expression: ~s" tree]][newline]
  [when [not [is-node? tree]] [error "Not a node!"]]
  [if [is-leaf? tree]
      [begin ;[displayln "atom"]
        [format "~s" [js_funcmap [codeof tree]]]]
      [if [equal? 1 [length tree]]
          ;a function with no args
          [format "~a()" [codeof [first  tree]]]
          [begin ;[displayln [format  "definite function ~s" [childrenof tree]]]
            [string-join

             [case [codeof [car  [childrenof tree]]]
               ['get-struct  [list [format "~a.~a" [codeof [second  [childrenof tree]]] [codeof [third  [childrenof tree]]]]]]
               ['new  [list [format "Object.assign({},~a)" [codeof [third  [childrenof tree]]] ]]]
               [else
                [list [format "~a(" [js_funcmap [codeof [car  [childrenof tree]]]]]
                      [string-join [map [lambda [x] [format "~a" [js_subexpression x]  ]] [cdr  [childrenof tree]]] ", "]
                      ")"]]]

             ""]]]]
  ]

;output a statement.  This is where all the builtins go, like "if, set, for"
[define [js_statement tree]
  ;[displayln [format  "clang statement: ~s" [pretty-print tree]]][newline]
  [list
   [case [car [codeof  tree]]
     ['if [format "    if ( ~a ) {\n      ~a    } else {\n      ~a    }"
                  [js_expression   [first [childrenof tree]]]
                  [string-join [flatten [js_body  [second [childrenof tree]]]]]
                  [string-join [flatten[js_body [third [childrenof tree]]]]]
                  ]]
     ['return-void [format "return;" ]]
     ['set  [format "    ~a=~a;" [codeof [first [childrenof tree]]] [js_expression  [second [childrenof tree]]]]]
     ['setAt  [format "    ~a[~a]=~a;"  [codeof [first [childrenof tree]]] [codeof [second [childrenof tree]]] [js_subexpression [third  [childrenof tree]]]]]
     ['set-struct [format "    ~a.~a=~a;"  [codeof [second [childrenof [first [childrenof tree]]]]] [codeof [third [childrenof [first [childrenof tree]]]]] [js_subexpression [fourth  [childrenof [first [childrenof tree]]]]]]]
     [else [list [js_subexpression [first [childrenof tree]]] ";"]]]
   "\n"]]

;All variables in a function must be declared at the start in one block.  Declarations cannot reference other declarations
[define [js_declaration tree]
  [match-let [[[list type name value] [codeof tree]]]
    [format "    var ~a = ~s;\n"   name  [js_funcmap value]]]]  ;fixme don't use funcmap for this


;Print the body of the function, all statements
[define [js_body tree]
  [map js_statement  tree]]


[define [js_arguments tree]
  [list "("
        [string-join [map [lambda [x]  [format "~a"  [cadr x]]] [make-pairs [codeof tree]]] ", "]
        ")"]]


;Output the body of function
[define [js_function tree]
  [match-let [[[list type name args decs  bod] [childrenof tree]]]
    [list
     [format "function ~a" [codeof name]]
     [js_arguments args]
     [format " {~n" ]
     [js_declarations decs]
     [js_body bod]
     "}\n\n"]]]


;Turns quonverter types into C types
[define [js_typemap type]
  [case type
    ['string "char*"]
    ['Box* 'Box]
    ['Pair* 'Pair]
    [else type]]]

;Renames quonverter funcs into C funcs.
[define [js_funcmap name]
  [case name
    ['string-length 'string_length]
    ['sub-string 'sub_string]
    ['write-file 'write_file]
    ['read-file 'read_file]
    ['printf 'printf]
    ['nil 'null]
    ['= 'equal]
    ['true '1]
    ['- 'sub]
    ['> 'greaterthan]
    [else name]]]

;Print all the declarations
[define [js_declarations tree]
  [map js_declaration  [childrenof tree]]]

;All of the "top level" blocks are completely distinct
[define [js_dispatch tree]
  [case [nameof tree]
    [(functions)   [list "//Function definitions\n" [map js_function [childrenof tree]]]]
    [(includes)  [js_includes tree]]
    [(type-definitions)  [js_types tree]]
    [else [error [format "Unrecognised top level def ~a"  tree]]]]]

;The top level node
[define [js_program tree]
  [string-join [flatten
                [list "

"
                      [id [map js_dispatch  [childrenof tree]]]
                      "main();\n"]] ""]]

;Autogenerated test file
[define js_test_filename "test.js"]

;Compile and run the test program
[define js_test_commands '["/usr/local/bin/node --stack-size=99999999 test.js" "./a.out > results.js"]]








; C output functions

;output include statements
[define [clang_includes tree]
  [list "//Include libraries and headers\n"
        ;[map [lambda [x]  [format "#include <~s>~n"  x] ] [cons 'stdio.h [cdr [codeof tree]]]]
        "\n"]]



[define [clang_struct_components tree]
  [string-join [map [lambda [x] [format "     ~a ~a;\n"  [string-join [map  symbol->string [map clang_typemap [cdr x]]] " "] [first x]  ]] [cdr tree]]]
  ]
;output type definition statements
[define [clang_struct tree]
  [list
   [format "typedef struct ~a {\n~a} ~a;\n" [car tree] [clang_struct_components [cadr tree]]  [car tree]]
   ]]
[define [clang_forward_struct tree]
  [list
   [format "struct ~a; //Forward declaration\n" [car tree] ]  ;Forward declarations
   
   ]]

;output type definition statements
[define [clang_typedef tree]
  [list
   [format "typedef ~a ~a;\n"   [cadr tree] [car tree]]
   ]]

;output type definition statements
[define [clang_types tree]
  [list "//Type definitions\n"
        [map [lambda [x]
               [if [list? [second x]] [clang_forward_struct x] ""]]
             [cdr [codeof tree]]]
        [map [lambda [x]
               ;[displayln [format "a type: ~a~n" [second x]]]
               ;actually all types will be a list, need to check for 'stuct
               [if [list? [second x]]
                   ;it is a struct
                   [clang_struct x]
                   [clang_typedef x]]] [cdr [codeof tree]]]
        "\nbool isNil(list p) {
    return p == NULL;
}


Box* globalStackTrace = NULL;" ]]

[define [clang_arguments tree]
  [list "("
        [string-join [map [lambda [x]  [format "~a ~a" [clang_typemap [car x]] [cadr x]]] [make-pairs [codeof tree]]] ", "]
        ")"]]

[define [clang_detect_variable types atom]
  ;[display [format "Types: ~s    Atom: ~s~n" types atom]]
  [if [assoc atom types]
      [format "$~a"  atom ]
      atom
      ]
  ]

[define [clang_subexpression node]
  ;[displayln[format  "subexpr: ~s" node]][newline]
  [if [is-leaf? node]
      [format "~s" [clang_funcmap[codeof node]]]
      [clang_expression node]]]

;output an expression.  Soon, recursive!
[define [clang_expression tree]
  ;[displayln[format  "expression: ~s" tree]][newline]
  [when [not [is-node? tree]] [error "Not a node!"]]
  [if [is-leaf? tree]
      [begin ;[displayln "atom"]
        [format "~s" [clang_funcmap [codeof tree]]]]
      [if [equal? 1 [length tree]]
          ;a function with no args
          [format "~a()" [codeof [first  tree]]]
          [begin ;[displayln [format  "definite function ~s" [childrenof tree]]]
            [string-join

             [case [codeof [car  [childrenof tree]]]
               ['get-struct  [list [format "~a->~a" [codeof [second  [childrenof tree]]] [codeof [third  [childrenof tree]]]]]]
               ['new  [list [format "malloc(sizeof(~a))" [codeof [third  [childrenof tree]]] ]]]
               [else
                [list [format "~a(" [clang_funcmap [codeof [car  [childrenof tree]]]]]
                      [string-join [map [lambda [x] [format "~a" [clang_subexpression x]  ]] [cdr  [childrenof tree]]] ", "]
                      ")"]]]

             ""]]]]
  ]

;output a statement.  This is where all the builtins go, like "if, set, for"
[define [clang_statement tree]
  ;[displayln [format  "clang statement: ~s" [pretty-print tree]]][newline]
  [list
   [case [car [codeof  tree]]
     ['if [format "    if ( ~a ) {\n      ~a    } else {\n      ~a    }"
                  [clang_expression   [first [childrenof tree]]]
                  [string-join [flatten [clang_body  [second [childrenof tree]]]]]
                  [string-join [flatten[clang_body [third [childrenof tree]]]]]
                  ]]
     ['return-void  "return;" ]
     ['set  [format "    ~a=~a;" [codeof [first [childrenof tree]]] [clang_expression  [second [childrenof tree]]]]]
     ['setAt  [format "    ~a[~a]=~a;"  [codeof [first [childrenof tree]]] [codeof [second [childrenof tree]]] [clang_subexpression [third  [childrenof tree]]]]]
     ['set-struct [format "    ~a->~a=~a;"  [codeof [second [childrenof [first [childrenof tree]]]]] [codeof [third [childrenof [first [childrenof tree]]]]] [clang_subexpression [fourth  [childrenof [first [childrenof tree]]]]]]]
     [else [list [clang_subexpression [first [childrenof tree]]] ";"]]]
   "\n"]]

;All variables in a function must be declared at the start in one block.  Declarations cannot reference other declarations
[define [clang_declaration tree]
  [match-let [[[list type name value] [codeof tree]]]
    [format "    ~a ~a = ~s;\n"  [clang_typemap type] name  [clang_funcmap value]]]]  ;fixme don't use funcmap for this


;Print the body of the function, all statements
[define [clang_body tree]
  [map clang_statement  tree]]


;Output forward function
[define [clang_forward_function tree]
  [match-let [[[list type name args decs  bod] [childrenof tree]]]
    [list
     [format "~a ~a" [clang_typemap [codeof type]] [codeof name]]
     [clang_arguments args]
     ";\n\n"]]]

;Output the body of function
[define [clang_function tree]
  [match-let [[[list type name args decs  bod] [childrenof tree]]]
    [list
     [format "~a ~a" [clang_typemap [codeof type]] [codeof name]]
     [clang_arguments args]
     [format " {~n" ]
     [clang_declarations decs]
     [clang_body bod]
     "}\n\n"]]]


;Turns quonverter types into C types
[define [clang_typemap type]
  [case type
    ['string 'char*]
    ['stringArray 'char**]
    [else type]]]

;Renames quonverter funcs into C funcs.
[define [clang_funcmap name]
  [case name
    ['sub-string 'sub_string ]
    ['string-length 'string_length]
    ['write-file 'write_file]
    ['read-file 'read_file]
    ['nil 'NULL]
    ['= 'equal]
    ['true '1]
    ['- 'sub]
    ['> 'greaterthan]
    [else name]]]

;Print all the declarations
[define [clang_declarations tree]
  [map clang_declaration  [childrenof tree]]]

;All of the "top level" blocks are completely distinct
[define [clang_dispatch tree]
  [case [nameof tree]
    [(functions)   [list "//Function definitions\n" [map clang_forward_function [childrenof tree]] [map clang_function [childrenof tree]]]]
    [(includes)  [clang_includes tree]]
    [(type-definitions)  [clang_types tree]]
    [else [error [format "Unrecognised top level def ~a"  tree]]]]]

;The top level node
[define [clang_program tree]
  [string-join [flatten
                [list "
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void panic(char* s){abort();}
int sub(int a, int b) { return a - b; }
float subf(float a, float b) { return a - b; }
int mult(int a, int b) { return a * b; }
float multf(float a, float b) { return a * b; }
int greaterthan(int a, int b) { return a > b; }
int greaterthanf(float a, float b) { return a > b; }
int equal(int a, int b) { return a == b; }
int equalString(char* a, char* b) { return !strcmp(a,b); }
int andBool(int a, int b) { return a == b;}
int string_length(char* s) { return strlen(s);}
char* sub_string(char* s, int start, int length) {
char* substr = calloc(length+1, 1);
strncpy(substr, s+start, length);
return substr;
}

char* stringConcatenate(char* a, char* b) {
int len = strlen(a) + strlen(b)+1;
char* target = calloc(len,1);
strncat(target, a, len);
strncat(target, b, len);
return target;
}

char* intToString(int a) {
int len = 100;
char* target = calloc(len,1);
snprintf(target, 99, \"%d\", a);
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
FILE * f = fopen (filename, \"rb\");

if (f)
{
  fseek (f, 0, SEEK_END);
  length = ftell (f);
  fseek (f, 0, SEEK_SET);
  buffer = malloc (length);
  if (buffer)
  {
    fread (buffer, 1, length, f);
  }
  fclose (f);
}
return buffer;
}

void write_file (char * filename, char * data) {
FILE *f = fopen(filename, \"w\");
if (f == NULL)
{
    printf(\"Error opening file!\");
    exit(1);
}

fprintf(f, \"%s\", data);

fclose(f);
}

char* getStringArray(int index, char** strs) {
return strs[index];
}

int start();  /* Forwards declare the user's main routine */
char** globalArgs;
int globalArgsCount;
bool globalTrace = false;
bool globalStepTrace = false;

int main( int argc, char *argv[] )  {
  globalArgs = argv;
  globalArgsCount = argc;

  return start();


}
"
                      [id [map clang_dispatch  [childrenof tree]]]

                      ]]
               ""]]

;Autogenerated test file
[define clang_test_filename "test.c"]

;Compile and run the test program
[define clang_test_commands '["gcc -g -Wl,-stack_size -Wl,1000000 -O3 -ansi test.c" "./a.out > results.c"]]



; Golang output functions

[define [go_includes tree]
  [list
   [map [lambda [x]  [format "import \"~a\"~n" x] ] [cons "os" [cons "runtime/debug" [cons "io/ioutil" '[]]]]]
   "
func panic( s string) {
fmt.Println(s)
debug.PrintStack()
os.Exit(1)
}

   func sub(a, b int) int{
return a-b
}

   func mult(a, b int) int{
return a*b
}

func greaterthan(a, b int) bool {
return a>b
}


func subf(a, b float64) float64{
return a-b
}

   func multf(a, b float64) float64{
return a*b
}

func greaterthanf(a, b float64) bool {
return a>b
}

func equal(a,b int) bool {
return a==b
}

func equalString(a,b string) bool {
 return a==b
}

func andBool(a,b bool) bool{
return a==b
}

func string_length(s string) int {return len(s)}
func sub_string(s string, start, length int) string {return s[start:start+length]}
func stringConcatenate(a, b string)string{return a+b}
func intToString(a int) string { return fmt.Sprintf(\"%d\", a) }

func makeArray(length int) []int {
    arr := make([]int, length)
    return arr
}

func at(arr []int,  index int) int {
  return arr[index]
}

func setAt( arr []int,  index int, value int) {
    arr[index] = value
}

func read_file(filename string) string {
b, _ := ioutil.ReadFile(filename)
return string(b)
}

func write_file(filename string, data string) {
ioutil.WriteFile(filename, []byte(data), 0777)
}

func isNil(p *Pair) bool {
return p==nil
}

type stringArray = []string
var globalArgsCount int
var globalArgs []string
var globalTrace bool
var globalStepTrace bool
var globalStackTrace list

func getStringArray(index int, arr stringArray) string {
return arr[index]
}


func main () {
globalArgs = os.Args
globalArgsCount=len(os.Args)
  start()
}

"]
  ]

[define [go_struct_components tree]
  [string-join [map [lambda [x] [format "    ~a ~a//~a\n"  [go_typemap [car x]] [go_typemap [if [< 2 [length  x ]] [third x] [second x]]] x]] [cdr tree]]]
  ]

;output type definition statements
[define [go_struct tree]
  [list
   [format "type ~a struct {\n~a} \n" [car tree] [go_struct_components [cadr tree]]  ]
   ]]

;output type definition statements
[define [go_typedef tree]
  [list
   [format "type ~a=~a\n"  [car tree] [go_typemap [cadr tree]]]
   ]]

;output type definition statements
[define [go_types tree]
  [list "//Type definitions\n"
        [map [lambda [x]
               ;[displayln [format "a type: ~a~n" [second x]]]
               ;actually all types will be a list, need to check for 'stuct
               [if [list? [second x]]
                   ;it is a struct
                   [go_struct x]
                   [go_typedef x]]] [cdr [codeof tree]]]
        "\n"]]

[define [go_arguments tree]
  [list "("
        [string-join [map [lambda [x]  [format "~a ~a" [cadr x] [go_typemap [car x]]]] [make-pairs [codeof tree]]] ", "]
        ")"
        ]]


[define [is-node? n]
  [assoc'types n]]

[define [is-leaf? n]
  [equal? [nameof n] 'leaf]]

[define [is-expression? n]
  [equal? [nameof n] 'expression]]



[define [go_subexpression node]
  ;[displayln[format  "subexpr: ~s" node]][newline]
  [if [is-leaf? node]
      [format "~a~s" [annotate "leaf"] [codeof node]]
      [go_expression node]]]

;output an expression.  Soon, recursive!
[define [go_expression tree]
  ;[displayln[format  "expression: ~s" tree]][newline]
  [when [not [is-node? tree]] [error "Not a node!"]]
  [if [is-leaf? tree]
      [begin 
        [format "~a~s" [annotate "atom"] [go_funcmap [codeof tree]]]]
      [if [equal? 1 [length tree]]
          [begin [string-concatenate [list [annotate ]
                                           ;a function with no args
                                           [format "~a~a()" [annotate "singular function"][codeof [first  tree]]]]]]
          [begin
            
            [annotate [format  "definite function" ]]
            [string-join 
             [case [codeof [car  [childrenof tree]]]
               ['get-struct  [list [format "~a.~a" [codeof [second  [childrenof tree]]] [codeof [third  [childrenof tree]]]]]]
               ['new  [list [format "&~a{}" [codeof [third  [childrenof tree]]] ]]]
               [else
                [list
                 [format "~a(" [go_funcmap [codeof [car  [childrenof tree]]]]]
                 [string-join [map [lambda [x] [format "~a" [go_subexpression x]  ]] [cdr  [childrenof tree]]] ", "]
                 ")"]]] ""]]]]]



[define [go_statement tree]
  ;[write "go statement:"][writeln tree][newline]
  ;[write "go childrenof statement:"][writeln [childrenof tree]][newline]
  [list
   [case [car [codeof  tree]]
     ['if [format "    if ~a {\n      ~a    } else {\n      ~a    }"
                  [go_subexpression   [car [childrenof tree]]]
                  [string-join [flatten [go_body  [second [childrenof tree]]]]]
                  [string-join [flatten[go_body [third [childrenof tree]]]]]
                  ]]
     ['return-void  "return"  ]
     ['set  [format "    ~a=~a"  [codeof [first [childrenof tree]]] [go_subexpression [second  [childrenof tree]]]]]
     ['setAt  [format "    ~a[~a]=~a"  [codeof [first [childrenof tree]]] [codeof [second [childrenof tree]]] [go_subexpression [third  [childrenof tree]]]]]
     ['set-struct [let [[e [childrenof [first [childrenof tree]]]]]
                    [format "    ~a.~a = ~a" [codeof [second e]] [codeof [third e]] [go_subexpression [fourth e]]]
                    ]]
     [else [go_subexpression [first [childrenof tree]]]]]
   "\n"]]

[define [go_declaration tree]
  [match-let [[[list type name value] [codeof tree]]]
    [format "    var ~a ~a = ~s\n"  name type value]]]



[define [go_main tree]
  [match-let [[[list type name args decs  bod] [childrenof tree]]]
    [list
     "func main() {\n"
     [go_declarations decs]
     [go_body bod]
     "}\n"
     ]]]

[define [go_body tree]
  [list
   [map go_statement  tree]
   ]]



[define [go_function tree]
  [match-let [[[list type name args decs  bod] [childrenof tree]]]
    [if [equal? [codeof name] 'main]
        [go_main tree]
        [list
         [format "func ~a " [codeof name]]
         [go_arguments args]
         [format " ~a {~n" [go_typemap [codeof type]]]
         [go_declarations decs]
         [go_body bod]
         "}\n\n"]]]]


[define [go_typemap type]
  [case type
    ['float 'float64]
    ['stringArray [string->symbol "[]string"]]
    ['void ""]
    ['Box* '*Box]
    ['Pair* '*Pair]
    [else type]]]

[define [go_funcmap name]
  [case name
    ['sub-string 'sub_string]
    ['string-length 'string_length]
    ['write-file 'write_file]
    ['read-file 'read_file]
    ['nil 'nil]
    ['= 'equal]
    ['printf 'fmt.Printf]
    ['- 'sub]
    ['> 'greaterthan]
    ['true 'true]
    ['new '*new]
    [else name]]]


[define [go_declarations tree]
  [map go_declaration  [childrenof tree]]]


[define [go_functions tree]
  [map go_function [childrenof tree]]]

[define [go_dispatch tree]
  [case [nameof tree]
    [(functions)   [go_functions tree]]
    [(includes)  [go_includes tree]]
    [(type-definitions)  [go_types tree]]
    [else  '[]]]]

[define [go_program tree]
  [string-join [flatten
                [list
                 "package main\n\nimport \"fmt\"\n\n"
                 [map go_dispatch  [childrenof tree]]]] ""]]

[define go_test_filename "test.go"]

[define go_test_commands '["/Users/jeremyprice/go-git/bin/go run test.go > results.go"]]



;
;; BASH output functions

[define [bash_includes tree]
  [list "#!/bin/bash\n\n
function sub {
 let \"returnValue = $1 - $2 \"
}
function greaterthan {
 [ $1 -gt $2  ]
 let returnValue=$?
}
function equal {
 [ $1 = $2  ]
 let returnValue=$?
}
function equalString {
 [ $1 = $2  ]
 let returnValue=$?
}
function soTrue {
let returnValue=true
}
function cons {
returnValue[0]=\"$1\"
returnValue[1]=\"$2\"
}

function car {
tempVar=$1
returnValue=${tempVar[0]}
}

function makeArray {
returnValue[0]=0
}

function setAt {
$1[$2]=\"$3\"
}

function att {
local array=$1
returnValue=${array[$2]}
}
"
        [map [lambda [x]  [format "~n"] ] [cdr tree]]
        ]]

[define [bash_arguments tree]
  [list 
   [map [lambda [x i] [format "    local ~a=$~a~n" x i]] [nth-places 1 [codeof tree] 1] [iota [length tree] 1 1]]]]

[define [bash_subexpression node]
  ;[displayln[format  "subexpr: ~s" node]][newline]
  [if [is-leaf? node]
      [format "t_~a=~s" [idof node][bash_detect_variable [typesof node] [codeof node]]]
      [string-join [list [bash_expression node][format "t_~a=\"$t_~a\"\n" [idof node] [sub1 [idof node] ] ]] ""]]]

;output an expression.  Needs an "expression spiller" FIXME
[define [bash_expression tree]
  ;[displayln[format  "expression: ~s" tree]][newline]
  [when [not [is-node? tree]] [error "Not a node!"]]
  [if [is-leaf? tree]
      [begin ;[displayln "atom"]
        [format "t_~a=~s" [idof tree] [bash_funcmap [bash_detect_variable [typesof tree] [codeof tree]]]]]
      [if [equal? 1 [length tree]]
          ;a function with no args
          [format "~a " [codeof [first  tree]]]
          [begin ;[displayln [format  "definite function ~s" [childrenof tree]]]
            [string-join
             [list
              [string-join [map [lambda [x] [format "~a\n" [bash_subexpression x]   ]] [cdr  [childrenof tree]]] "\n"]
              
              [format "~a " [bash_funcmap [codeof [car  [childrenof tree]]]]]
              [string-join [map [lambda [x] [format "\"$t_~a\"" [idof x]  ]] [cdr  [childrenof tree]]] " "]
                                
              [format "\nt_~a=$returnValue\n" [sub1 [idof tree]]]] ""]]]]
  ]



[define [bash_detect_variable types atom]
  ;[display [format "Types: ~s    Atom: ~s~n" types atom]]
  [if [assoc atom types]
      [format "$~a"  atom ]
      atom
      ]
  ]

[define [bash_statement tree]
  ;[displayln "bash_statement"]
  ;[pretty-display tree]
  [list
   [case [car [codeof tree]]
     ['if [format "    ~a~n    if (( $t_~a == 0 ));\n    then\n      ~a    else\n      ~a    fi"
                  [bash_subexpression  [first [childrenof tree]]]
                  [idof [first [childrenof tree]]]
                  [string-join [flatten [bash_body [second [childrenof tree]]]] ""]
                  [string-join [flatten [bash_body [third [childrenof tree]]]]""]
                  ]]
     ['set [format "    ~a\n    ~a=$returnValue"  [bash_expression  [second [childrenof tree]]]  [codeof [first [childrenof tree]]  ]]]
     ['setAt [format "    ~a\n    ~a[~a]=$t_~a"  [bash_expression  [third [childrenof tree]]]  [codeof [first [childrenof tree]]  ]  [codeof [second [childrenof tree]]] [idof [third [childrenof tree]]]]]
     ['return [format "~a\nreturnValue=$t_~a" [bash_expression  [second [childrenof [first [childrenof tree]]]]] [sub1 [idof [first [childrenof tree]]]]]]
     [else [list
            [bash_subexpression [first [childrenof tree]]]
            ]]]
   "\n"]]

[define [bash_declaration tree]
  [match-let [[[list type name value] [codeof tree]]]
    [format "    local ~a=~a~n"   name value]]]




[define [bash_main tree]
  [match-let [[[list type name args decs  bod] [childrenof tree]]]
    [list
     "function main {\n" 
     [bash_declarations decs]
     [bash_body bod]
     "}\n"
     "main"
     ]]]

[define [bash_body tree]
  [map [lambda [x] [bash_statement x]] tree]
  ]




[define [bash_function tree]
  [match-let [[[list type name args decs  bod] [childrenof tree]]]
    [if [equal? [codeof name] 'main]
        [bash_main tree]
        [list
         [format "function ~a {\n" [codeof name]]
         [bash_arguments args]
         [format " ~a" [bash_typemap [codeof type]]]
         [bash_declarations decs]
         [bash_body bod]
         "}\n\n"
         ]]]
  ]


[define [bash_typemap type]
  ""
  ]



[define [bash_funcmap name]
  ;[displayln [format "funcmap: ~a" name]]
  [case name
    ['at 'att]
    ['= 'equal]
    ['printf 'printf]
    ['- 'sub]
    ['> 'greaterthan]
    ['true 'soTrue]
    [else name]]]


[define [bash_declarations tree]
  [map bash_declaration  [childrenof tree]]]


[define [bash_functions tree]
  [map bash_function [childrenof tree]]]

[define [bash_dispatch tree]
  [case [nameof tree]
    [(functions)   [bash_functions tree]]
    [(includes)  [bash_includes tree]]
    [else '[]]]]

[define [bash_program tree]
  [string-join [flatten [map bash_dispatch  [childrenof tree]]] ""]]

[define bash_test_filename "test.bash"]

[define bash_test_commands '["bash test.bash > results.bash"]]




;
;; BAT output functions
;
;[define [includes tree]
;  [list [format "ECHO ON~nSETLOCAL ENABLEEXTENSIONS~nCALL main~nEXIT /B 0~n"]
;  [map [lambda [x] [format "~n"] ] [cdr tree]]]]
;
;[define [arguments tree]
;  [list "\n"
;  [map [lambda [x i] [format "    SET ~a=%~a~n" x i]] [nth-places 2 tree -1] [iota [length tree] 1 1]]]
;
;  ]
;
;[define [statement tree]
;  [list
;  [case [car tree]
;    ['set  [format "    SET ~a=~a~n" [cadr tree] [caddr tree]]]
;  [else [begin [list [format "    ~a " [car tree]]
;   [map [lambda [x] [format "~s " x]] [cdr tree]]]
;   ]]]
;        "\n"]
;  ]
;
;[define [declaration tree]
;  [match-let [[[list type name value] tree]]
;    [format "    SET ~a=~a~n"  name value]]]
;
;
;[define [main tree]
;[match-let [[[list type name args decs  bod] tree]]
;  [list 
;  [format "~n~n:~a~n" name]
;    [declarations decs]
;    [map [lambda [x] [statement x]] [cdr bod]]
;    "EXIT /B 0"]
;  ]]
;
;[define [body tree]
;  [list
;  [map [lambda [x] [statement x]] [cdr tree]]
;  "EXIT /B 0"
;  "\n"]
;  ]
;
;[define [function tree]
;  [match-let [[[list type name args decs  bod] tree]]
;    [if [equal? name 'main]
;        [main tree]
;        [list
;    [format "~n~n:~a " name]
;    [arguments args]
;    [format " ~a" [typemap type]]
;    [declarations decs]
;    [body bod]
;     "EXIT /B 0"
;  ]]]
;  ]
;
;
;[define [typemap type]
;  ]


; Type functions
;
; The type functions process the s-expression tree and annotate it with type information.  They also expand it into nodes, to make it
;suitable for output.  I should split those two functions.

; Create a standard node, with all data
[define [make-node type code name children]
  [list
   [cons 'types type]
   [cons 'code code]
   [cons 'name name]
   [cons 'children children]
   [cons 'id [unique-number]]
   ]]

; Create a node without types or children
[define [default_node codetree name]
  [make-node '[] codetree name '[]]]

; Create a node to hold all the include commands
[define [type_includes tree]
  [default_node tree 'includes]]

; A node that holds the function arguments
[define [type_arguments tree]
  [when [odd? [length tree]]
    [error [format "Require type-argument pairs, received ~a" tree]]]
  [make-node   [map [lambda [x]  [cons  [cadr x] [car x]]] [make-pairs tree]]
               tree
               'function_arguments
               '[]]]

; An expression node is recursive, it can hold sub-expressions
[define [type_expression scope tree]
  ;[displayln [format "type_expr: ~s" tree]]
  [if [list? tree]
      [make-node scope tree 'expression [map [lambda [x] [type_expression scope x]] tree]]
      [make-node scope tree 'leaf '[]]]]

; Statements are where we put the "special functions", like if, set, loop, etc
; default statements just hold an expression, but don't care about the result(side effects only)
[define [type_statement scope tree]
  ;[display [format "type statement: ~s~n" tree]]
  [case [car tree]
    ['if [letrec [[condition  [type_condition scope [second tree]]]
                  [truBranch [type_body scope  [third tree]]]
                  [falseBranch [type_body scope [fourth tree] ]]]
           [make-node scope '[if] 'statement [list condition truBranch falseBranch]]]]
    ['set [make-node scope '[set] 'statement [list
                                              [default_node [second tree] [second tree]]
                                              [type_expression scope [third tree]]
                                              ] ]]
    ['return ;[displayln [format "return: ~s" tree]]
     [if [empty? [cdr tree]]
         [make-node scope '[return-void] 'statement '[]]
         
         [make-node scope tree "statement" [list [type_expression scope tree]]]]]  ;the default statement handler (fixme, dupe)
    ['setAt [make-node scope '[setAt] 'statement [list
                                                
                                                  [default_node [second tree] [second tree]]
                                                  [default_node [third tree] [third tree]]
                                                  [type_expression scope [fourth tree]]
                                                  ] ]]
    [else
     [make-node scope tree "statement" [list [type_expression scope tree]]]]]]

; Type declarations always go at the start of the function
[define [type_declaration tree]
  ;rewrite this so we can print "invalide type declaration on failure
  [match-let [[[list type name value] tree]]
    [list
     [cons 'types [list [cons name type]]]
     [cons 'code tree]]]]

; All the declarations for a function
[define [type_declarations tree]
  [if [empty? [cdr tree]]
      [default_node '[] 'variable_declarations]
        
      [make-node [map [lambda [x] [car [typesof [type_declaration x]]]] [cdr tree]]
                 tree
                 'variable_declarations
                 [map type_declaration [cdr tree]]]]]

; The condition part of if statements
[define [type_condition scope tree]
  [if [list? tree]
      [type_expression scope tree]
      [make-node scope tree 'leaf '[]]]]

; The body of a function, i.e. the statements
[define [type_body scope tree]
  [map [lambda [x] [type_statement scope x]] [cdr tree]]]

; Function.  Needs arguments, declarations, a body and a return type
[define [type_function tree]
  ;[display tree]
  [match-let [[[list type name args decs  bod] tree]]
      
    [letrec [[typeArgs [typesof [type_arguments args]]]
             [allTypes  [make-node [append [typesof  [type_declarations decs]] typeArgs ]
                                   [cons 'code '[]]
                                   "function_types"
                                   '[]]]]
      
      [make-node '[] '[] 'function
                 [list
                  [make-node type type 'function_type '[]]
                  [default_node name 'function_name]
                  [type_arguments args ]
                  [type_declarations decs ]
                  [type_body [typesof allTypes] bod ]
                  ]
                 ]]]]



; All the functions
[define [type_functions tree]
  [map type_function [cdr tree]]]

; Function.  Needs arguments, declarations, a body and a return type
[define [type_type tree]
  [default_node tree 'type-definitions]]

; All the types
[define [type_types tree]
  [map type_type [cdr tree]]]

; 
[define [type_annotate tree]
  [map type_dispatch tree]]

; Handle the top level statements in a program
[define [type_dispatch tree]
  [case [car tree]
    [(functions)   [make-node '[] "" 'functions [type_functions tree]]]
    [(includes)  [type_includes tree]]
    [(types)  [make-node '[] tree 'type-definitions [type_types tree] ]]
    [else [error "Unknown toplevel section"]]
    ]]


; Start parsing the program
[define [type_program tree]
  [make-node '[] "" 'program [map type_dispatch tree]]]




; The actual program
;
; FIXME load from a file or a string

[define prog
  [quote [
          ;[includes stdio.h stdlib.h]
          [includes]
          [types
           [Box
            [struct
              [lis struct Box* ]
              [str string ]
              [i int ]
              [typ string ]
              [voi bool ]
              [boo bool]
              [lengt int ]
              [car struct Box* ] 
              [cdr struct Box* ]
              [tag struct Box* ]
              ]]
           [box Box*]
           [Pair Box]
           [pair Box*]
           [list Box*]
           ]
    
          [functions

     
           [int add [int a int b] [declare]
                [body [return [sub a [sub 0 b]]]]]

           [float addf [float a float b] [declare]
                  [body [return [subf a [subf 0 b]]]]]

           [int sub1 [int a] [declare]
                [body [return [sub a 1]]]]

           [int add1 [int a] [declare]
                [body [return [add a 1]]]]

           [box clone [box b] [declare [box newb nil]]
                [body
                 [set newb [new newb Box]]
                 [set-struct newb typ [get-struct b typ]]
                 [set-struct newb lis [get-struct b lis]]
                 [set-struct newb str [get-struct b str]]
                 [set-struct newb i [get-struct b i]]
                 [set-struct newb lengt [get-struct b lengt]]
                 [return newb]
                 ]]
     
           [box newVoid [] [declare [box newb nil]]
                [body
                 [set newb [new newb Box]]
                 [set-struct newb voi true]
                 [set-struct newb typ "void"]
                 [return newb]
                 ]]
           
     
           [list cons [box data list l] [declare [pair p nil]]
                 [body
                  [set p [new pair Pair]]
                  (set-struct p cdr l)
                  (set-struct p car data)
                  (set-struct p typ "list")
                  (return p)]]

           [void stackDump [] [declare]
                 [body
                  [display globalStackTrace]
                  ]]
           [box car [list l] [declare]
                [body
                 (assertType "list" l)
                 [if [isNil l]
                     [body
                      [printf "Cannot call car on empty list!\n"]
                      
                      [panic "Cannot call car on empty list!\n"]
                      [return nil]]
                     [body 
                      [if [isNil [get-struct l car]]
                          [body ;[printf "Attempt to car a nil value\n"]
                           [return nil]]
                          [body [return (get-struct l car)]]]]]]]

           [list cdr [list l] [declare]
           
                 [body
                  [assertType "list" l]
                  [if [isEmpty l]
                      [body [printf "Attempt to cdr an empty list!!!!\n"]
                            [panic "Attempt to cdr an empty list!!!!\n"]
                            [return nil]]
                      [body [return  (get-struct l cdr)]]]]]

           [bool isList [box b] [declare]
                 [body
                  [if [isNil b]
                      [body [return true]]
                      [body [return [equalString "list" [get-struct b typ]]]]]]]

           [list emptyList [] [declare ]
                 [body
                  [return nil]]]

           [bool isEmpty [box b] [declare]
                 [body
                  [if [isNil b]
                      [body [return true]]
                      [body 
                       [if [isList b]
                           [body [return false]]
                           [body
                            ;[printf "Type error in isEmpty:  not a list: %s\n" [boxType b]]
                            [return false]]]]]]]

           [list alistCons [box key box value list alist] [declare]
                 [body [return [cons [cons key value] alist]]]]
     
           [list assoc [string searchTerm list l] [declare [list elem nil]]
                 [body
                  
                  (assertType "list" l)
                  [if [isEmpty l]
                      [body
                       ;[printf "Assoc on empty list!"]
                       ;[panic "Assoc on empty list!"]
                       [return [boxBool false]]]
                      [body

                       [set elem [car l]]
                       ;[printf "\nComparing '%s' and '%s'\n" [stringify [boxString searchTerm]]  [stringify [car elem]]]
                       ;[display l]
                       ;[display elem]
                       ;[printf "searchTerm: "]
                       ;[dump [stringify [boxString searchTerm]]]
                       ;[printf "key: "]
                       ;[dump[stringify [car elem]]]
                       [if [isEmpty elem]
                           [body [return [assoc searchTerm [cdr l]]]]
                           [body
                            [if [equalString [stringify [boxString searchTerm]]  [stringify [car elem]]]
                                [body
                                 ;[printf "\nFound match: "]
                                 ;[display elem]
                                 ;[printf "\n"]
                                 [return elem]]
                                [body
                                 ;[printf "\nNo match, recursing\n"]
                                 [return [assoc searchTerm [cdr l]]]]]]
                           ]]]]]

    

           [bool equalBox [box a box b] [declare]
                 [body
                  [if [isList b]
                      [body [return false]]
                      [body
                       ;[printf "Comparing: "][display a] [display b][newLine 0]
                       [if [equalString "string" [boxType a]]
                           [body [return [equalString [unBoxString a] [stringify b]]]]
                           [body [if [equalString "bool" [boxType a]]
                                     [body [return [andBool  [unBoxBool a]  [unBoxBool b]]]]
                                     [body [if [equalString "symbol" [boxType a]]
                                               [body [if [equalString "symbol" [boxType b]]
                                                         [body [return [equalString [unBoxSymbol a] [unBoxSymbol b]]]]
                                                         [body [return false]]]] ;Maybe panic?
                                               [body [if [equalString "int" [boxType a]]
                                                         [body [return [equal [unBoxInt a] [unBoxInt b]]]]
                                                         [body [return false]]]]]]]]]]]]]
                       
                
            

     
           ;;;;;;;;;;;;;;;;;;;;;;;;
           ;;  Type conversions  ;;
           ;;;;;;;;;;;;;;;;;;;;;;;;

           [string boxType [box b] [declare]
                   [body [return [get-struct b typ]]]]


           [box boxString [string s] [declare [box b nil]]
                [body  [set b [new box Box]]
                       [set-struct b str s]
                       [set-struct b lengt [string-length s]]
                       [set-struct b typ "string"]
                       [return b]]]

           [box boxSymbol [string s] [declare [box b nil]]
                [body  [set b [boxString s]]
                       [set-struct b typ "symbol"]
                       [return b]]]

           ;     [box boxList [list l] [declare [box b nil]]
           ;          [body  [set b [new box Box]]
           ;                 [set-struct b l l]
           ;                 [set-struct b typ "list"]
           ;                 [return b]]]
           [box boxBool[bool boo] [declare [box b nil]]
                [body  [set b [new box Box]]
                       [set-struct b boo boo]
                       [set-struct b typ "bool"]
                       [return b]]]
           [box boxInt[int val] [declare [box b nil]]
                [body  [set b [new box Box]]
                       [set-struct b i val]
                       [set-struct b typ "int"]
                       [return b]]]

     

                
           [void assertType [string atype box abox] [declare]
                 [body
                  [if  [isNil abox]
                       [body [if [equalString atype "nil"]
                                 [body [return ]]
                                 [body [return ]]]]
                       [body 
                
                        [if [equalString atype [boxType abox]]
                            [body [return]]
                            [body [printf "Assertion failure: provided value is not a '%s'!  It was actually:" atype]
                                  [display abox]
                                  [panic "Invalid type!"]]]]]]]

           [string unBoxString [box b] [declare]
                   [body
                    [assertType "string" b]
                    [return [get-struct b str]]]]
           [string unBoxSymbol [box b] [declare]
                   [body
                    [return [get-struct b str]]]]

           ;     [list unBoxList [box b] [declare]
           ;           [body
           ;            [return [get-struct b l]]]]

           [bool unBoxBool [box b] [declare]
                 [body
                  [return [get-struct b boo]]]]

           [int unBoxInt [box b] [declare]
                [body
                 [return [get-struct b i]]]]

           [string stringify [box b] [declare]
                   [body
                    [if [isNil b]
                        [body [return "nil"]]
                        [body 
                         [if [equalString "string" [boxType b]]
                             [body [return  [unBoxString b]]]
                             [body [if [equalString "bool" [boxType b]]
                                       [body
                                        [if [unBoxBool b]
                                            [body [return "true"]]
                                            [body [return "false"]]]]
                             
                                       [body [if [equalString "int" [boxType b]]
                                                 [then [return  [intToString [unBoxInt b]]]]

                                                 [else [if [equalString "symbol" [boxType b]]
                                                           [body [return  [unBoxSymbol b]]]

                                                           [body [return  [boxType b]]]]]]]]]]]]]]
           ;;;;;;;;;;;;;;;;;;;;;;;;;;
           ;; display boxed values ;;
           ;;;;;;;;;;;;;;;;;;;;;;;;;;
           [void displayList [list l int indent] [declare [box val nil]]
                 [body
                  [if [isEmpty l]
                      [body ;[printf "Empty!\n"]
                       [return]]
                      [body
                       [if [isList l]
                 
                           [body
                            ;[printf "List found\n"]
                            [if [isEmpty l]
                                [body ;[printf "Empty!\n"]
                                 [return]]
                                [body
                                 [set val [car l]]
                 
                                 [if [isList val]
                                     [body
                                      ;[printf "Found list in car\n"]
                                      [newLine indent]
                                      [printf "%s" [openBrace]]
                                      [displayList [car l] [add1 indent]]
                                      [printf "%s" [closeBrace]]
                                      [displayList [cdr l] [add1 indent]]
                                      ]
                                     [body
                                      [if [equalString "string" [get-struct val typ] ]
                                          [body
                                           [printf "\"%s\" " [unBoxString val]]
                                           ]
                                          [body
                                           [printf "%s "  [stringify val]]]]
                           
                                      [displayList [cdr l] indent]]]]]]
                           [body
                            [if [equalString "string" [get-struct l typ] ]
                                [body
                                 [printf "\"%s\" " [unBoxString l]]
                                 ]
                                [body
                                 [printf "%s "  [stringify l]]]]
                            ]]]]]]
           [void display [list l] [declare]
                 [body
                  [if [isEmpty l]
                      [body [printf "nil "][return]]
                      [body
                       [if [isList l]
                           [body [printf "["][displayList l 0][printf "]"]]
                           [body [displayList l 0]]]]]
                  ]]
     


           ;;;;;;;;;;;;;;;;;;;;;;;;;;
           ;;  Sexpression reader  ;;
           ;;;;;;;;;;;;;;;;;;;;;;;;;;
           [list filterVoid [list l] [declare [box token nil]]
                 [body
                  ;[displayList l]
                  [if [isEmpty l]
                      [body [return [emptyList]]]
                      [body

                       [set token [car l]]
                       [if [equalString "void" [get-struct token typ]]
                           [body [return [filterVoid [cdr l]]]]
                           [body [return [cons token [filterVoid [cdr l]]]]]]]]]]

           [list filterTokens [list l] [declare [box token nil]]
                 [body
                  ;[displayList l]
                  [if [isEmpty l]
                      [body [return [emptyList]]]
                      [body

                       [set token [car l]]
                       ;[printf "Checking %s:%s\n" [boxType token] [stringify token]]
                       ;[display token]
                       [if  [equalString [boxType token] "symbol"]
                            [then [if
                                   [equalString "__LINE__" [stringify token]]
                                   [then
                                    ;[printf "Found line marker, replacing!\n"]
                                    ;[display [get-struct token tag]]
                                    [return [cons [getTagFail token [boxString "line"] [boxInt -1]] [filterTokens [cdr l]]]]]
                                   [else [if
                                          [equalString "__COLUMN__" [stringify token]]
                                          [then
                                           ;[printf "Found line marker, replacing!\n"]
                                           ;[display [get-struct token tag]]
                                           [return [cons [getTagFail token [boxString "column"] [boxInt -1]] [filterTokens [cdr l]]]]]
                                          [else

                                           [return [cons token                             [filterTokens [cdr l]]]]]]]]]
                            [else [return [cons token                             [filterTokens [cdr l]]]]]]]]]]


           [bool hasTag [box aBox box key] [declare]
                 [body
                  [if [isNil aBox]
                      [then [return false]]
                      [else 
                       [return  [truthy [assoc [stringify key] [get-struct aBox tag]]]]]]
                  ]]

           
           [box getTag [box aBox box key] [declare]
                [body
                 [return [cdr [assoc [stringify key] [get-struct aBox tag]]]]
                 ]]

           [box getTagFail [box aBox box key box onFail] [declare]
                [body
                 [if [hasTag aBox key]
                     [then 
                      [return [cdr [assoc [stringify key] [get-struct aBox tag]]]]]
                     [else
                      [return onFail]]]
                 ]]
           
           [box setTag [box aStruct box key list val] [declare]
                [body
                 [set-struct aStruct tag
                             [alistCons key val [get-struct aStruct tag]]]  ;FIXME immutable pls
                 [return aStruct]
                 ]]

           
           [box finish_token [string prog int start int len int line int column string filename] [declare [box token nil]]
                [body
                 ;[printf "ft: %s start: %d, end %d\n" prog start len]
                 ;[printf "Finish token %s\n" [sub-string prog start   len]]

                 [if [> len 0]
                     [body ;[printf "Finish token\n"]

                     

                      [set token [boxSymbol [sub-string prog start  len]]]
                      [set-struct token tag
                                  [alistCons [boxString "filename"] [boxString filename]
                                             [alistCons [boxString "column"] [boxInt column]
                                                        [alistCons [boxString "line"] [boxInt line] [alistCons [boxString "totalCharPos"] [boxInt start] nil]]]]]
                      [return token]]
                     [body [return [newVoid]]]]
                 ]]

     

           [string readString [string prog int start int len] [declare [string token ""]]
                   [body
                    ;[printf "Start: %d, len: %d\n" start len]
                    [set token [sub-string prog [sub1 [add start len]] 1]]
                    ;[printf "Token: %s\n" token]
              
                    [if [equalString "\"" token]
                        [body [return [sub-string prog start [sub1 len]]]]
                        [body
                         [if [equalString "\\" token]
                             [body [return [readString prog start [add 2 len]]]]
                             [body [return [readString prog start [add1 len]]]]
                             ]
                         [return [readString prog start [add1 len]]]]
                        ]]]

           [string readComment [string prog int start int len] [declare [string token ""]]
                   [body
                    ;[printf "Start: %d, len: %d\n" start len]
                    [set token [sub-string prog [sub1 [add start len]] 1]]
                    ;[printf "Token: %s\n" token]
                    ;[printf "Partial comment:%s" [sub-string prog start [sub1 len]]]
              
                    [if [isLineBreak token]
                        [body
                         ;[printf "\nComplete comment is %s\n" [sub-string prog start [sub1 len]]]
                 
                         [return [sub-string prog start [sub1 len]]]]
                        [body [return [readComment prog start [add1 len]]]]
                        ]]]
                                              
           [bool isWhiteSpace [string s] [declare]
                 [body [if [equalString " " s]
                           [then [return true]]
                           [else [if [equalString "\n" s]
                                     [then [return true]]
                                     [else [if [equalString "\r" s]
                                               [then [return true]]
                                               [else [return false]]]]]]]]]

           [bool isLineBreak [string s] [declare]
                 [body [if [equalString "\n" s]
                           [then [return true]]
                           [else [if [equalString "\r" s]
                                     [then [return true]]
                                     [else [return false]]]]]]]

           [int incForNewLine [box token int val] [declare]
                [body

                 [if [equalString "\n" [stringify token]]
                     [then [return [add1 val]]]
                     [else [return val]]]]]
     
           [list scan [string prog int start int len int linecount int column string filename] [declare [box token nil]]
                 [body
                  ;[if [isNil prog]
                  ;    [then [panic "Program to parse is nill!"]]
                  ;    [else [printf ""]]]
;[if true [then [printf ""]][else
;                  [printf "\n//Start: %d, end %d, string-length %d, program: %p\n\n" start [add start len] [string-length prog] prog]]]
                  [if [> [string-length prog] [sub start [sub 0 len]]]
                      [body
                       [set token [boxSymbol [sub-string prog [sub1 [add start len]] 1]]]
                       [set-struct token tag [alistCons [boxString "totalCharPos"] [boxInt start] nil]]
                       ;[printf "\n//Start: %d, end %d, Token: %s\n\n" start [add start len] [stringify token] ]
                       [if [isOpenBrace token]
                           [body ;[printf "Start array\n"]
                            [return [cons
                                     [finish_token prog start  [sub1 len] linecount column filename]
                                     [cons [boxSymbol [openBrace] ]
                                           [scan prog [add1 start] 1 linecount [add1 column] filename]]]]]
                           [body [if [isCloseBrace token]
                                     [body ;[printf "Finish array\n"]
                                      [return [cons  [finish_token prog start  [sub1 len] linecount  column filename]
                                                     [cons [boxSymbol [closeBrace]]
                                                           [scan prog [add start  len] 1 linecount [add1 column] filename]]]]]
                                     [body [if [isWhiteSpace [stringify token]] ;FIXME this will skip strings like "   " when it shouldn't
                                               [body
                                                [return [cons
                                                         [finish_token prog start  [sub1 len] linecount column filename]
                                                         [scan prog  [add start  len] 1 [incForNewLine token linecount] 0 filename]]]
                                                ]
                                               [body [if [equalBox [boxSymbol ";" ] token]
                                                         [body
                                                          ;[printf "\nComment:%s" [readComment prog [add1 start] len]]
                                                          [return [scan prog  [add start  [add1 [add1 [string-length [readComment prog [add1 start] len]]]]] 1 linecount [add1 column] filename]
                                                                  ]]
                                                         [body [if [equalBox [boxSymbol "\""] token]
                                                                   [body ;[printf "Found string: %s\n"  [readString prog [add1 start] len]]
                                                                    [return
                                                                     
                                                                     [cons
                                                                      [boxString [readString prog [add1 start] len]]
                                                                      [scan prog  [add start  [add1 [add1 [string-length [readString prog [add1 start] len]]]]] 1 linecount [add1 column] filename]]]]
                                                                   [body ;[printf "Symbol %s\n" token]
                                                                    [return [scan prog start [sub len -1] linecount [add1 column] filename]]]]]]]]]]]]]
                      [body ;[printf "scan complete\n"]
                       [return [emptyList]]]]
                  [return [emptyList]]
                  ]]

           [bool isOpenBrace [box b] [declare]
                 [body
                  [if [equalBox [boxSymbol [openBrace]]  b]
                      [body [return true]]
                      [body [if [equalBox [boxSymbol "["]  b]
                                [body [return true]]
                                [body [return false]]]]]
                      
                  ]]

           [string openBrace [] [declare] [body [return "("]]]

           [bool isCloseBrace [box b] [declare]
                 [body
                  [if [equalBox [boxSymbol [closeBrace]]  b]
                      [body [return true]]
                      [body [if [equalBox [boxSymbol "]"]  b]
                                [body [return true]]
                                [body [return false]]]]]
                      
                  ]]
           [string closeBrace [] [declare] [body [return ")"]]]
     
           [list sexprTree [list l] [declare [box b nil]]
                 [body
                  [if [isEmpty l]
                      [body [return [emptyList]]]
                      [body
                       [set b [car l]]
                       ;[printf "Processing list with sexprTree: %s\n" [unBoxString b] ]
                       [if  [isOpenBrace b]
                            [then ;[printf "Start sublist sexprTree\n"]
                             [return [cons
                                      [sexprTree [cdr l]]
                                      [sexprTree [skipList [cdr l]]]]]]
                            [else [if [isCloseBrace b]
                                      [body ;[printf "Finish sublist sexprTree\n"]
                                       [return [emptyList]]]
                                      [body
                                       ;[printf "Add token %s\nRemaining tokens: " [stringify b]]
                                       ;[display [cdr l]]
                                       [return [setTag
                                                [cons b [sexprTree [cdr l]]]
                                                [boxString "line"]
                                                [getTagFail b [boxString "line"] [boxInt -1]]]]]]]]]
                      ]
                  [printf "AAAAAA code should never reach here!\n"]
                  [return [emptyList]]
                  ]]

           [list skipList [list l] [declare [box b nil]]
                 [body
                  [if [isEmpty l]
                      [body [return [emptyList]]]
                      [body
                       [set b [car l]]
                       ;[printf "Processing list with skiplist: %s\n" [unBoxString b] ]
                       [if [isOpenBrace b]
                           [body ;[printf "Start sublist in skiplist\n"]
                            [return [skipList [skipList [cdr l]]]]]
                           [body [if [isCloseBrace  b]
                                     [body ;[printf "Finish sublist in skiplist\n"]
                                      [return  [cdr l]]]
                                     [body
                                      ;[printf "skipping token %s\nRemaining tokens: " [unBoxString b]]
                                      ;[displayList [cdr l]]
                                      [return  [skipList [cdr l]]]]]]]]]
                  [printf "AAAAAA code should never reach here!\n"]
                  [return [emptyList]]
                  ]]

           [list readSexpr [string aStr string filename]
                 [declare
                  [list tokens nil]
                  [list as nil]
                  ]
                 [body
                  [set tokens [emptyList]]
            
            
                  [set tokens [filterTokens [filterVoid [scan aStr 0 1 0 0 filename]]]]
                  ;[printf "Displaying tokens:\n"]
                  ;[displayList tokens]
                  ;[printf "Building sexprTree\n"]
                  [set as [sexprTree tokens]]
                  ;[printf "Displaying sexprTree\n"]
                  ;[displayList as]
                  [return [car as]]
                  ]]

           ;;;;;;;;;;;;;
           ;;  Tests  ;;
           ;;;;;;;;;;;;;
           [void test0 [] [declare]
                 [body 
                  [if [equalString [stringify [boxString "hello"]]  [stringify [boxString "hello"]]]
                      [body [printf "0.  pass string compare works\n"]]
                      [body [printf "0.  pass string compare fails\n"]]]
                  [if [equalString [stringify [boxString "hello"]]  [stringify [boxSymbol "hello"]]]
                      [body [printf "0.  pass string compare works\n"]]
                      [body [printf "0.  pass string compare fails\n"]]]
                  ]]
           [void test1 [] [declare]
                 [body [printf "1.  pass Function call and print work\n"]]]

           [void test2_do [string message] [declare]
                 [body [printf "2.  pass Function call with arg works: %s\n" message]]]
           
           [void test2 [] [declare]
                 [body [test2_do "This is the argument"]]]

           [void test3_do [int b string c]
                 [declare]
                 [body 
                  [printf "3.1 pass Two arg call, first arg: %d\n" b]
                  [printf "3.2 pass Two arg call, second arg: %s\n" c]]]
     
           [void test3 [] [declare]
                 [body [test3_do 42 "Fourty-two"]]]

           [string test4_do [] [declare]
                   [body [return "pass Return works"]]]

           [string returnThis [string returnMessage] [declare]
                   [body [return returnMessage]]]

           [void test4 [] [declare [string message "fail"]]
                 [body
                  [set message [test4_do]]
                  [printf "4.  %s\n" message]]]

           [void test5 [] [declare [string message "fail"]]
                 [body
                  [set message [returnThis "pass return passthrough string"]]
                  [printf "5.  %s\n" message]]]

           [void test6 [] [declare]
                 [body
                  [if true
                      [body [printf "6.  pass If statement works\n"]]
                      [body [printf "6.  fail If statement works\n"]]]]]

           [int test7_do [int count] [declare]
                [body
                 [set count [sub count 1]]
                 ;[printf "Count: %d\n" count]
                 [if [> count 0]
                     [body [set count [test7_do count]]]
                     [body [return count]]]
                 [return count]]]
     
           [void test7 [] [declare ]
                 [body
                  [if [= 0 [test7_do 10]]
                      [body [printf "7.  pass count works\n"]]
                      [body [printf "7.  fail count fails\n"]]]]]

           [void beer [] [declare] [body
                                    [printf "%d bottle of beer on the wall, %d bottle of beer.  Take one down, pass it round, no bottles of beer on the wall\n" 1 1]]]

           [string plural [int num] [declare]
                   [body
                    [if [equal num 1]
                        [body [return ""]]
                        [body [return "s"]]]]]

     
     
           [int beers [int count] [declare [int newcount 0]]
                [body
                 [set newcount [sub count 1]]
                 [printf "%d bottle%s of beer on the wall, %d bottle%s of beer.  Take one down, pass it round, %d bottle%s of beer on the wall\n" count [plural count] count [plural count] newcount [plural newcount]]
                 [if [> count 1]
                     [body [set count [beers newcount]]]
                     [body [return count]]]
                 [return 0]
                 ]]

           [void test8 [] [declare] [body
                                     [if [equal [sub  [sub 2 1] [sub 3 1] ] -1]
                                         [body [printf "8.  pass Nested expressions work\n"]]
                                         [body [printf "8.  fail Nested expressions don't work\n"]]
                                         ]]]
           [void test9 [] [declare [int answer -999999]] [body
                                                          [set answer [sub  [sub 20 1] [sub 3 1] ]]
                                                          ;[printf "(20-1)-(3-1)=%d" answer]
                                                          [if [equal answer 17]
                                                              [body [printf "9.  pass arithmetic works\n"]]
                                                              [body [printf "9.  fail arithmetic\n"]]]
                                                          ]]
     
           [void test10 [] [declare [string testString "This is a test string"]] [body
                                                                                  [if [equalString testString [unBoxString [car [cons [boxString testString] nil]]]] 
                                                                                      [body [printf "10. pass cons and car work\n"]]
                                                                                      [body [printf "10. fail cons and car fail\n"]]]
                                                                                  ]]

           ;     [void test11 [] [declare [array testArray nil]] [body
           ;                                                      [set testArray [makeArray 100]]
           ;                                                      [setAt testArray 0 100]
           ;                                                      [setAt testArray 1 200]
           ;                                                      [printf "Element 1: %d" [at testArray 1]]
           ;                                                      ]]

           [void test12 [] [declare [box b nil]]
                 [body
                  [set b [new box Box]]
                  [set-struct b str "12. pass structure accessors\n"]
                  [printf "%s" [get-struct b str]]
                  ]]

           [void test13 []
                 [declare
                  [string testString "Hello from the filesystem!"]
                  [string contents ""]]
                 [body
                  [write-file "test.txt" testString]
                  [set contents [read-file "test.txt"]]
                  ;[printf "%s\n" contents]
                  [if [equalString testString contents]
                      [body [printf "13. pass Read and write files\n"]]
                      [body [printf "13. fail Read and write files\n"]]
                      ]]]

           [box caar [list l] [declare] [body [return [car [car l]]]]]
           [box cadr [list l] [declare] [body [return [car [cdr l]]]]]
           [box caddr [list l] [declare] [body [return [car [cdr [cdr l]]]]]]
           [box cadddr [list l] [declare] [body [return [car [cdr [cdr [cdr l]]]]]]]
           [box caddddr [list l] [declare] [body [return [car [cdr [cdr [cdr [cdr l]]]]]]]]

           [box cddr [list l] [declare] [body [return [cdr [cdr l]]]]]

           [box first [list l] [declare] [body [return  [car l]]]]
           [box second [list l] [declare] [body [return  [cadr l]]]]
           [box third [list l] [declare] [body [return  [caddr l]]]]
           [box fourth [list l] [declare] [body [return  [cadddr l]]]]
           [box fifth [list l] [declare] [body [return  [caddddr l]]]]

           [list makeNode [string name string subname list code list children] [declare]
                 [body
                  ;[display code]
                  [return
                   
                   [cons  [boxSymbol "node"]
                          [alistCons [boxSymbol "line"] [getTagFail code [boxString "line"] [boxInt -1]]
                                     [cons [cons [boxSymbol "name"] [boxString name]]
                                           [cons [cons [boxSymbol "subname"] [boxString subname]]
                                                 [cons [cons [boxSymbol "code"]  code]
                                                       [alistCons [boxSymbol "children"]  children
                                                                  [emptyList]]]]]]]]]]


           ;           [define [type_expression scope tree]
           ;  ;[displayln [format "type_expr: ~s" tree]]
           ;  [if [list? tree]
           ;      [make-node scope tree 'expression [map [lambda [x] [type_expression scope x]] tree]]
           ;      [make-node scope tree 'leaf '[]]]]
           ;
           ;           

           [list astExpression [list tree] [declare]
                 [body
                  [if [isList tree]
                      [body [return [makeNode "expression" "expression" nil [astSubExpression tree]]]]
                      [body [return [astSubExpression tree]]]]]]
           [list astSubExpression [list tree] [declare]
                 [body
                  [if [isEmpty tree]
                      [body [return [emptyList]]]
                      [body
                       ;[printf "!!!!!!!!! %s is a list? %s" [boxType tree] [stringify [boxBool [isList tree]]]][display tree]
                       [if [isList tree]
                           [body
                                 
                            ;[printf "Compound expression: "][display tree]
                            [return [cons             [astExpression [car tree]]
                                                      [astSubExpression [cdr tree]] ]]]
                                     
                                     
                           [body [return [makeNode "expression" "leaf"        tree  nil]]]]]]
                
                  ]]

           [list astIf [list tree] [declare]
                 [body
                  ;[printf "Building if node from: "][display tree][printf "\n"]
                  [return [makeNode "statement" "if" tree [cons [cons [astExpression [first tree]] nil]
                                                                [cons [astBody [cdr [second tree]]]
                                                                      [cons [astBody [cdr [third tree]]]
                                                                            nil]]]]]
                  ]]

           [list astSetStruct [list tree] [declare]
                 [body
                  ;[printf "Building setstruct node from: "][display tree][printf "\n"]
                  [return [makeNode "statement" "structSetter" tree
                                    [astExpression [third tree]]  ]]
                  ]]

           [list astSet [list tree] [declare]
                 [body
                  ;[printf "Building setstruct node from: "][display tree][printf "\n"]
                  [return [makeNode "statement" "setter" tree [astExpression [second tree]]]]
                  ]]

           [list astGetStruct [list tree] [declare]
                 [body
                  ;[printf "Building get-struct node from: "][display tree][printf "\n"]
                  [return [makeNode "expression" "structGetter" tree  nil ]]
                  ]]

           [list astReturnVoid [] [declare]
                 [body
                  [return [makeNode "statement" "returnvoid" nil nil]]
                  ]]

           [int length [list l]  [declare]
                [body
                 ;[printf "Length of: "]
                 ;[display l]
                 [if [isEmpty l]
                     [body [return 0]]
                     [body [return [add1 [length [cdr l]]]]]]
                 ]]
     
           [list astStatement [list tree] [declare]
                 [body
                  ;[printf "AstStatement: "][display tree]
                  [if [equalBox [boxString "if"] [car tree] ]
                      [body ;if statement
                       ;[printf "Choosing if statement\n"]
                       [return [astIf [cdr tree]]]]
                      [body
                       [if [equalBox [boxString "set"] [car tree] ]
                           [body ;struct setter statement
                            ;[printf "Choosing if statement\n"]
                            [return [astSet [cdr tree]]]]
                                      
                           [body
                            [if [equalBox [boxString "get-struct"] [car tree] ]
                                [body ;struct setter statement
                                 [printf "Choosing get-struct statement\n"]
                                 [return [astGetStruct [cdr tree]]]]
                                      
                                [body
                                 [if [equalBox [boxString "set-struct"] [car tree] ]
                                     [body ;struct setter statement
                                      ;[printf "Choosing if statement\n"]
                                      [return [astSetStruct [cdr tree]]]]
                                      
                                     [body
                                      [if  [equal [length tree] 1]
                                           [body
                                            [if [equalBox [car tree] [boxString "return"]]
                                                [body ;void return statement
                                                 ;[printf "Choosing returnvoid\n"]
                                                 [return [astReturnVoid]]]
                                                [body 
                                                 ;generic statement
                                                 [return [makeNode "statement" "statement" tree [makeNode "expression" "expression" tree [astExpression tree]]]]]]
                                            ]
                                           [body ;generic statement
                                            [return [makeNode "statement" "statement" tree [makeNode "expression" "expression" tree [astExpression tree]]]]]]
                                      ]]
                                 ]]
                            ]]]
                      ]]]

           [list astBody [list tree] [declare]
                 [body
                  [if [isEmpty tree]
                      [body [return [emptyList]]]
                      [body [return [cons [astStatement [car tree]] [astBody [cdr tree]]]]]]
                  ]]
     
           [list astFunction [list tree] [declare [box fname nil]]
                 [body
                  [set fname [second tree]]
                  ;[printf "Processing:"][display tree][printf "\n\n"]
                  ;[printf "Processing:"] [display [get-struct fname tag ]] [printf "\n\n"]
                  ;[printf "Building function:"][display [second tree]][printf"\n"]
                  [return
                   [alistCons [boxSymbol "line"] [getTag fname [boxString "line"] ]
                              [cons [cons [boxSymbol "name"] [boxString "function"]]
                                    [cons [cons [boxSymbol "subname"] [second tree]]
                                          [cons [cons [boxSymbol "declarations"] [cdr [fourth tree]]]
                                                [cons [cons [boxSymbol "intype"] [third tree]]
                                                      [cons  [cons [boxSymbol "outtype"] [car tree]]
                                                             [cons [cons [boxSymbol "children"] [astBody [cdr [fifth tree]]]]
                                                                   [emptyList]]]]]]]]
                   ]]]

           [list astFunctionList [list tree] [declare]
                 [body
                  [if [isEmpty tree]
                      [body [return [emptyList]]]
                      [body [return [cons [astFunction [car tree]] [astFunctionList [cdr tree]]]]]]
                  ]]

           [list astFunctions [list tree] [declare]
                 [body
                  ;[printf "Building functions AST...\n"]
                  [return [makeNode "functions" "functions" tree [astFunctionList [cdr tree]]]]
                  ]]

           [list loadLib [string path] [declare [string programStr ""] [list tree nil] [list library nil]]
                 [body
                  [printf "//Loading library %s\n" path]
                  [set programStr [read-file path]]
                  ;[printf "Read program: %s\n" programStr]
                  ;[printf "Read program.  Parsing...\n" ]
                  [set tree [readSexpr programStr path]]
                  ;[printf "Parsed program.  Building AST...\n" ]
                  ;[display  tree]

                  [set library [alistCons [boxString "includes"] [astIncludes  [first tree]]
                                          [alistCons [boxString "types"] [astTypes  [second tree]]
                                                     [alistCons [boxString "functions"] [astFunctions  [third tree]] nil]]]]
                  
                  ;[return [ansiFunctions [cdr [assoc "children" [cdr [cdr [assoc "functions" program]]]]]]]
                  [return library]
                  ]]
           [list astInclude [list tree] [declare]
                 [body
                  [return [loadLib [stringify tree]]]
                  ]]
           [list astIncludeList [list tree] [declare]
                 [body
                  [if [isEmpty tree]
                      [body [return [emptyList]]]
                      [body [return [cons [astInclude [car tree]] [astIncludeList [cdr tree]]]]]]
                  ]]

           [list astIncludes [list tree] [declare]
                 [body
                  [printf "//Building includes AST...\n"]
                  [return [makeNode "includes" "includes" tree [astIncludeList [cdr tree]]]]
                  ]]

           [list astStruct [list tree] [declare]
                 [body
                  [return [makeNode "type" "struct" tree nil]]
                  ]]
           [list astType [list tree] [declare]
                 [body
                  ;[printf "\n\nBuilding type from...."]
                  ;[display [cadr tree]]
                  [if [isList  [cadr tree]]
                      [body [return [astStruct  tree]]]
                      [body [return [makeNode "type" "type" tree nil]]]]
                  ]]
     
           [list astTypeList [list tree] [declare]
                 [body
                  [if [isEmpty tree]
                      [body [return [emptyList]]]
                      [body [return [cons [astType [car tree]] [astTypeList [cdr tree]]]]]]
                  ]]

           [list astTypes [list tree] [declare]
                 [body
                  ;[printf "Building types AST...\n"]
                  [return [makeNode "types" "types" tree [astTypeList [cdr tree]]]]
                  ]]

    
     
           [void ansiFunctionArgs [list tree] [declare]
                 [body
                  [if [isEmpty tree]
                      [body [return]]
                      [body
                 
                     
                       [display [ansiTypeMap [first tree]]]
                       [display [second tree]]
                       [if [isNil [cddr tree]]
                           [body [printf ""]]
                           [body [printf ","]]]
                       [ansiFunctionArgs [cddr tree] ]]]
                  ]]

           [list declarationsof [list ass] [declare ]
                 [body
                  ;[printf "\n\nCodeof: "]
                  ;[display ass]
                  [return
                   [cdr [assoc "declarations" [cdr ass]]]]]]
           
           [list codeof [list ass] [declare ]
                 [body
                  ;[printf "\n\nCodeof: "]
                  ;[display ass]
                  [return
                   [cdr [assoc "code" [cdr ass]]]]]]
     
           [list nodeof [list ass] [declare ]
                 [body
                  ;[printf "\n\nnodeof: "]
                  ;[display ass]
                  [if [equalBox [boxBool false] [assoc "node" [cdr ass]]]
                      [body [return [boxBool false]]]
                      [body 
                       [return
                        [cdr [assoc "node" [cdr ass]]]]]]]]

           [list lineof [list ass] [declare ]
                 [body
                  ;[printf "\n\nnodeof: "]
                  ;[display ass]
                  [if [equalBox [boxBool false] [assoc "line" [cdr ass]]]
                      [body [return [boxInt -1]]]
                      [body 
                       [return
                        [cdr [assoc "line" [cdr ass]]]]]]]]
     
           [list subnameof [list ass] [declare]
           
                 [body
                  ;[printf "\n\nsubnameof: "][display [assoc "subname" [cdr ass]]]
                  [return [cdr [assoc "subname" [cdr ass]]]]]]

      

           [list nameof [list ass] [declare]
           
                 [body
                  ;[printf "\n\nnameof: "]
                  ;[display ass]
                  [return [cdr [assoc "name" [cdr ass]]]]]]
     
           [list childrenof [list ass] [declare]
                 [body [return [cdr [assoc "children" [cdr ass]]]]]]

     
           [bool isNode [list val] [declare]
                 [body
                  [if [isEmpty val]
                      [body [return false]]
                      [body
                       [if [isList val]
                      
                           [body
                            ;[printf "val: "]
                            ;[display val]
                            [if [equalBox [boxSymbol "node"] [car val]]
                                [body [return true]]
                                [body [return false]]]
                            ]
                           [body [return false]]]]]]]

           [void ansiLeaf [list thisNode int indent  ] [declare]
                 [body
                  [display [ansiFuncMap [codeof thisNode]]]
                  ;                  [if 
                  ;                      [body
                  ;                       [printf "%s" [openBrace]]
                  ;                       [if [> [length [cdr nodes]] 1]
                  ;                           [body
                  ;                            [newLine indent]]
                  ;                           [body [printf ""]]]
                  ;                       [set indent [add1 indent]]
                  ;                       [ansiExpression [cdr nodes] false [add1 indent]]
                  ;                       [printf "%s" [closeBrace]]
                  ;                       ]
                  ;                      [body
                  ;                       [if [isNil [cdr nodes]]
                  ;                           [body [printf ""]]
                  ;                           [body
                  ;                            [printf ","]]]
                  ;                       ansiExpression [cdr nodes] false [add1 indent]]
                  ;                       ]
                  ]]

           [void ansiStructGetterExpression [list thisNode int indent  ] [declare]
                 [body
                  [if [equalBox [boxString "structGetter"] [subnameof thisNode]]
                      [body ;[printf "Expression is a structGetter: "][display thisNode][printf "\n"]
                       [ansiGetStruct thisNode indent]]
                      [body [ansiLeaf thisNode indent ]]]
                  ]]

           ;           [void ansiExpression [list nodes  int indent] [declare [list thisNode nil]]
           ;                 [body
           ;            
           ;                  [if [isEmpty nodes]
           ;                
           ;                      [body
           ;                       ;[printf "Expression is empty\n"]
           ;                       [return]]
           ;                      [body
           ;                       ;[printf "\n\nExpression: \n\n"][display nodes]
           ;                       [if [isNode nodes]
           ;                           [body  [ansiStructGetterExpression nodes indent]]
           ;                           [body
           ;                            [set thisNode [car nodes]]
           ;                       
           ;                            [if [isNode thisNode]
           ;                     
           ;                                [body
           ;                                 ;[ansiStructGetterExpression thisNode indent]
           ;                                 ;[printf "this is a node:\n"][display thisNode][printf "\n"]
           ;                                 
           ;                                 [if [equalBox [boxString "expression"] [subnameof thisNode]]
           ;                                     
           ;                                     [body ;[printf "Expression has multiple elements, recursing into children\n"]
           ;                                      ;[printf "( "]
           ;                                      ;***[newLine indent]
           ;                                                 
           ;                                      [ansiExpression [car thisNode]  [add1 indent]]
           ;                                 
           ;                                      [printf "%s" [openBrace]]
           ;                                      [ansiExpression [cdr thisNode]  [add1 indent]]
           ;                                      [printf "%s" [closeBrace]]
           ;                                           
           ;                                                 
           ;                                      ;[printf "Expression was multi, continuing processing children\n"]
           ;                                                 
           ;                                      ]
           ;                                     [body ;[printf "Expression is a leaf, printing\n"]
           ;                           
           ;                                      [ansiStructGetterExpression thisNode indent]
           ;                                      ;[printf "Expression was a leaf, continuing list\n"]
           ;                                      ]]
           ;                                            
           ;                                 [if [isNil [cdr nodes]]
           ;                                     [body [printf ""]]
           ;                                     [body
           ;                                      [printf ", "]]]
           ;                                 [ansiExpression  [cdr nodes]  indent]
           ;
           ;
           ;
           ;                                 ]
           ;                                [body
           ;                                 ;[printf "Expressions was not a node, recursing into list\n"] [display thisNode][printf "\n"]
           ;                                 ]
           ;                                     
           ;                                      
           ;                                ]]]]
           ;                      [body [ansiLeaf nodes indent ]]]
           ;                  ]]


           [void  ansiExpression [list node int indent] [declare]
                  ;[displayln[format  "subexpr: ~s" node]][newline]
                  
                  [body ;[printf "\n\nExpression: \n\n"][display node]
                   [if [isLeaf node]
                       [body [display [ansiFuncMap[codeof node]]]]
                       [body [ansiSubExpression node indent]]]]]

           [void ansiRecurList [list expr int indent] [declare]
                 [body
                  [if [isEmpty expr]
                
                      [body
                       ;[printf "Expression is empty\n"]
                       [return]]
                      [body
                       [ ansiExpression [car expr] indent]
                       [if [isNil [cdr expr]]
                           [body [printf ""]]
                           [body
                            [printf ", "]
                            [ansiRecurList [cdr expr] indent]]]
                       ]]
                  [return]
                  ]]

           [bool isLeaf [list n] [declare]
                 [body
                  ;[printf "\n\nisLeaf: \n\n"][display n]
                  [return [equalBox [boxString "leaf"] [subnameof n]]]]]

           
           ;output an expression.  Soon, recursive!
           [void ansiSubExpression [list tree int indent] [declare [box thing nil]]
                 [body
                  ;[displayln[format  "expression: ~s" tree]][newline]
                  [if [isEmpty tree]
                
                      [body
                       ;[printf "Expression is empty\n"]
                       [return]]
                      [body
                       ;[printf "\n\nSubExpression: \n\n"][display tree]
                       [if [isNode [childrenof tree]]
                           [body
                            [ansiSubExpression [childrenof tree] indent]]
                           [body
                            [if [isLeaf tree]
                                [body ;[printf "\natom\n"]
                                 [display [ansiFuncMap [codeof tree]]]]
                                [body 
                                 [if [equal 1 [length [childrenof tree]]]
                                     
                                     [body ;[printf "\na function with no args: "][display [car [childrenof tree]]]
                                      [display [codeof [car [childrenof tree]]]]
                                      [if [equalBox [boxString "return"] [codeof [car [childrenof tree]]]]
                                          [body [printf ""]
                                                ]
                                          [body                                            
                                           [printf "()"]; [stringify [codeof   [childrenof tree]]]]
                                           ]]]
                                     [body ;[printf  "definite function "] [display [childrenof tree]]
            
                                      [set thing [codeof [car  [childrenof tree]]]]
                                      [if [equalBox [boxSymbol "get-struct"] thing]
                                          [body  [printf "%s->%s" [stringify [codeof [second  [childrenof tree]]]] [stringify [codeof [third  [childrenof tree]]]]]]
                                          [body
                                           [if [equalBox [boxSymbol "new"] thing]
                                               [body  [printf "malloc(sizeof(%s))" [stringify [codeof [third  [childrenof tree]]] ]]]
                                               [body
               
                                                [printf "%s(" [stringify [ansiFuncMap [codeof [car  [childrenof tree]]]]]]
                                                [ansiRecurList  [cdr  [childrenof tree]] indent] 
                                                [printf ")"]]]]

                                          ]]]
                                 ]]]]
                       ]]]]
           
           ;output a statement.  This is where all the builtins go, like "if, set, for"
           ;[define [clang_statement tree]
           ;  ;[displayln [format  "clang statement: ~s" [pretty-print tree]]][newline]
           ;  [list
           ;   [case [car [codeof  tree]]
           ;     ['if [format "    if ( ~a ) {\n      ~a    } else {\n      ~a    }"
           ;                  [clang_expression   [first [childrenof tree]]]
           ;                  [string-join [flatten [clang_body  [second [childrenof tree]]]]]
           ;                  [string-join [flatten[clang_body [third [childrenof tree]]]]]
           ;                  ]]
           ;     ['return-void  "return;" ]
           ;     ['set  [format "    ~a=~a;" [codeof [first [childrenof tree]]] [clang_expression  [second [childrenof tree]]]]]
           ;     ['setAt  [format "    ~a[~a]=~a;"  [codeof [first [childrenof tree]]] [codeof [second [childrenof tree]]] [clang_subexpression [third  [childrenof tree]]]]]
           ;     ['set-struct [format "    ~a->~a=~a;"  [codeof [second [childrenof [first [childrenof tree]]]]] [codeof [third [childrenof [first [childrenof tree]]]]] [clang_subexpression [fourth  [childrenof [first [childrenof tree]]]]]]]
           ;     [else [list [clang_subexpression [first [childrenof tree]]] ";"]]]
           ;   "\n"]]


           [void ansiIf [list node int indent] [declare ]
                 [body
                  [newLine indent]
                  ;[newLine indent]
                  [printf "if ( "]
                       
                  [ansiExpression   [car [first [childrenof node]]]  0 ]
                        
                  [printf ") {"]
                  ;[newLine [add1 indent]]
                  [ansiBody  [second [childrenof node]] [add1 indent]]
                  [newLine indent]
                  [printf "} else {"   ]
                  ;[newLine [add1 indent]]
                  [ansiBody [third [childrenof node]] [add1 indent]]
                  [newLine  indent]
                  [printf "}"]
                  ]]

           [void ansiSetStruct [list node int indent] [declare ]
                 [body
                  [newLine indent]
                  ;[printf "setstruct statement:  "][display node]
                       
                  [printf "%s->%s = " [stringify [first [codeof node]]] [stringify [second [codeof node]]]]
                  [ansiExpression   [childrenof node]  indent]
                             
                  ]]

           [void ansiGetStruct [list node int indent] [declare ]
                 [body
                  [newLine indent]
                  ;[printf "getstruct statement:  "][display node]
                       
                  [printf "%s->%s" [stringify [first [codeof node]]] [stringify [second [codeof node]]] ]
                  
                             
                  ]]

           [void ansiSet [list node int indent] [declare ]
                 [body
                  [newLine indent]
                  ;[printf "setstruct statement:  "][display node]
                       
                  [printf "%s = " [stringify [first [codeof node]]]]
                  [ansiExpression   [childrenof node]  indent]
                             
                  ]]

                  
           [void ansiStatement [list node int indent] [declare ]
                 [body
            
                  ;[printf "\nAnsiStatement: "][display node]
                  [if [equalBox [boxString "setter"] [subnameof node]]
                      [body
                       [ansiSet node indent]
                       ]
                      [body
                       
                       [if [equalBox [boxString "structSetter"] [subnameof node]]
                           [body
                            [ansiSetStruct node indent]
                            ]
                           [body
                            [if [equalBox [boxString "if"] [subnameof node]]
                                [body
                                 [ansiIf node indent]
                                 ]
                                [body ;[printf "ExpressionStatement: (%s, %s)" [stringify [nameof node]] [stringify [subnameof node]]]
                                 [if [equalBox [boxString "returnvoid"] [subnameof node]]
                                     [body
                                      [newLine indent]
                                      [printf "return"]]
                                     [body
            
                                      ;[printf "\nGeneric expression statement\n" ]
                                      ;[display [childrenof node]]
                                      ;[printf "\n\n"]
                                      [newLine indent]
                                      [ansiExpression  [childrenof node]    indent]
                                      ]]
                                 ]]
                            ]]
                            
                       ;[printf "\n\n"]
                       ]]
                  [printf ";\n"]]]

           [void printIndent [int ii] [declare]
                 [body
                  [if [> ii 0]
                      [body
                       [printf "  "]
                       [printIndent [sub1 ii]]
                       ]
                      [body [return]]]]]

           [void newLine [int indent] [declare]
                 [body
                  [printf "\n"]
                  [printIndent indent]
                  ;[printf "%d" indent]
                  ]]
           [void ansiBody [list tree int indent] [declare]
                 [body
                  ;[display tree]
                  [if [isEmpty tree]
                      [body [return]]
                      [body
                       [printIndent indent]
                       [printf"%s"  "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n"]
                       [ansiStatement [car tree] indent]
                       
                       ;[printf ";\n"]
                       [ansiBody [cdr tree] indent]]]
                  ]]

           [void ansiDeclarations [list decls int indent] [declare [box decl nil]]
                 [body
                  ;[display tree]
                  [if [isEmpty decls]
                      [body [return]]
                      [body
                       [set decl [car decls]]
                       [printf "%s %s = " [stringify [ansiTypeMap [first decl]]] [stringify [second decl]] ]
                       [display [ansiFuncMap [third decl]]]
                       [printf ";\n"]
                       [ansiDeclarations [cdr decls] indent]
                       ]]
                  ]]
     
           [void ansiFunction [list node] [declare [box name nil][list noStackTrace nil]]
                 [body
                  ;[display tree]
                  [set name [subnameof node]]
                  [set noStackTrace [cons [boxSymbol "car"] [cons [boxSymbol "cdr"] [cons [boxSymbol "cons"] [cons [boxSymbol "stackTracePush"] [cons [boxSymbol "stackTracePop"] [cons [boxSymbol "assertType"] [cons [boxSymbol "boxString"]  [cons [boxSymbol "boxInt"]  nil]]]]]]]]]
                  [printf "\n\n//Building function %s from line: %s"  [stringify name]  [stringify [getTag name [boxString "line"]]]]
                  ;[display [get-struct name tag]]
                  [newLine 0]
                  [if [isNil node]
                      [body [return]]
                      [body
                       ;[display [assoc "name" tree]]
                       [newLine 0]
                       [printf "%s %s(" [stringify [ansiTypeMap [cdr [assoc "outtype" [cdr node]]]]] [stringify [subnameof node]]]
                       [ansiFunctionArgs [cdr [assoc "intype" [cdr node]]]]
                       [printf ") {"]
                       [newLine 1]
                       [ansiDeclarations [declarationsof node] 1]
                       [printf "\nif (globalTrace)\n    printf(\"%s at %s:%s\\n\");\n" [stringify [subnameof node]] [stringify [getTag name [boxString "filename"]]] [stringify [getTag name [boxString "line"]]]]
                       [if [inList name noStackTrace]
                           [then [printf ""]]
                           [else 
                            [printf "\n  stackTracePush(\"%s\", \"%s\", %s, %d );\n"  [stringify [getTag name [boxString "filename"]]] [stringify [subnameof node]] [stringify [getTag name [boxString "line"]]] 0]]]
                       [ansiBody [childrenof node] 1]
                       
                       [if [inList name noStackTrace]
                           [then [printf ""]]
                           [else 
                            [printf "\n  stackTracePop();\nif (globalTrace)\n    printf(\"Leaving %s\\n\");\n"   [stringify [subnameof node]]]]]
                       [printf "\n}\n"]
                       ]]]]
           [void ansiForwardDeclaration [list node] [declare]
                 [body
                  
                  [if [isNil node]
                      [body [return]]
                      [body
                       ;[display [assoc "name" tree]]
                       [printf "\n%s %s(" [stringify [ansiTypeMap [cdr [assoc "outtype" [cdr node]]]]] [stringify [subnameof node]]]
                       [ansiFunctionArgs [cdr [assoc "intype" [cdr node]]] ]
                       [printf ");" ]
                       ]]]]
     
           [void ansiForwardDeclarations [list tree] [declare]
                 [body
                  ;[display tree]
                  [if [isEmpty tree]
                      [body [return]]
                      [body
                 
                       [ansiForwardDeclaration [car tree]]
                       [ansiForwardDeclarations [cdr tree]]
                 
                 
                       ]]]]
           
           [void ansiFunctions [list tree] [declare]
                 [body
                  [if [isEmpty tree]
                      [body [return]]
                      [body
                       [ansiFunction [car tree]]
                       [ansiFunctions [cdr tree]]]]]]
                             
           [void ansiIncludes [list nodes] [declare]
                 [body
                  [printf "%s" "
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
snprintf(target, 99, \"%d\", a);
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
FILE * f = fopen (filename, \"rb\");

if (f)
{
  fseek (f, 0, SEEK_END);
  length = ftell (f);
  fseek (f, 0, SEEK_SET);
  buffer = malloc (length);
  if (buffer == NULL) {
  printf(\"Malloc failed!\\n\");
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
FILE *f = fopen(filename, \"w\");
if (f == NULL)
{
    printf(\"Error opening file!\");
    exit(1);
}

fprintf(f, \"%s\", data);

fclose(f);
}

char* getStringArray(int index, char** strs) {
return strs[index];
}

int start();  //Forwards declare the user's main routine
char** globalArgs;
int globalArgsCount;
bool globalTrace = false;
bool globalStepTrace = false;

int main( int argc, char *argv[] )  {
  globalArgs = argv;
  globalArgsCount = argc;

  return start();

}

"]
                  ]]

           [box last [list alist] [declare]
                [body
                 [if [isEmpty [cdr alist]]
                     [body [return [car alist]]]
                     [body [return [last [cdr alist]]]]]
                 ]]

           [void ansiTypeDecl [list l] [declare]
                 [body
                  [if [> [length l] 2]
                      [body
                       [printIndent 1]
                       [printf "%s %s %s;\n"   [stringify [second  l]]  [stringify [ansiTypeMap [last  l]]] [stringify [first  l]] ]]

                      [body
                       [printIndent 1]
                       [printf "%s %s;\n"     [stringify [ansiTypeMap[last  l]]] [stringify [car l]]]]
                      ]
                  ]]
           [void ansiStructComponents [list node] [declare]
                 [body
                  ;[printf "Printing component: "]
                  ;[dump node]
                  ;[display node]
                  [if [isEmpty node]
                      [body [return]]
                      [body
                       [ansiTypeDecl [car node]]
                       [ansiStructComponents [cdr node]]]]
                  ]]
     
           [void ansiStruct [list node] [declare]
                 [body
                  ;[display node]
                  ;[display  [cdr [car  node]]]
                  [ansiStructComponents [cdr [car  node]]]
            
                  [return] ]]

           [bool truthy [box aVal] [declare]
                 [body [if [equalBox [boxBool false] aVal]
                           [body [return false]]
                           [body [return true]]]]]
     
           [box ansiTypeMap [box aSym] [declare [list symMap nil]]
                [body
                 ;[printf "Typemap: '%s'\n" [stringify aSym]]
                 [set symMap
                      [alistCons [boxSymbol "stringArray"] [boxSymbol "char**"] 
                                 [alistCons [boxSymbol "string"] [boxSymbol "char*"] nil]]]
                 [if [truthy [assoc [stringify aSym] symMap]]
                     [body [return [cdr [assoc [stringify aSym] symMap]]]]
                     [body [return aSym]]
                                  
                     ]
                 ]]

           [box ansiFuncMap [box aSym] [declare [list symMap nil]]
                [body
                 ;[printf "Typemap: '%s'\n" [stringify aSym]]
                 [if [equalString "symbol" [boxType aSym]]
                     [body
                      [set symMap
                           [alistCons [boxSymbol "="] [boxSymbol "equal"]
                                      [alistCons [boxSymbol "sub-string"] [boxSymbol "sub_string"]
                                                 [alistCons [boxSymbol "read-file"] [boxSymbol "read_file"]
                                                            [alistCons [boxSymbol "write-file"] [boxSymbol "write_file"]
                                                                       [alistCons [boxSymbol ">"] [boxSymbol "greaterthan"]
                                                                                  [alistCons [boxSymbol "string-length"] [boxSymbol "string_length"]
                                                                                             [alistCons [boxSymbol "nil"] [boxSymbol "NULL"] nil]]]]]]]]
                      [if [truthy [assoc [stringify aSym] symMap]]
                          [body [return [cdr [assoc [stringify aSym] symMap]]]]
                          [body [return aSym]]
                                  
                          ]
                      ]
                     [body [return aSym]]]
                 ]]
     
           [void ansiType [list node] [declare]
                 [body
            
                  [if [equalBox [subnameof node] [boxString "struct"]]
                      [body [printf "\ntypedef struct %s {\n" [stringify [first [codeof node]]]]
                            [ansiStruct [cdr [codeof node]]]
                            [printf "\n} %s;\n" [stringify [first [codeof node]]]]]
                      [body

                       [printf "typedef "  ]
                       ;[display [codeof node]]
                       [ansiTypeDecl [codeof node]]]]
            
                  [return] ]]

           [void ansiTypes [list nodes] [declare]
                 [body
            
                  [if [isEmpty nodes]
                      [body [return]]
                      [body
                       [ansiType [car nodes]]
                       [ansiTypes [cdr nodes]]]]
                  
                  ]]

           (list concatLists (list seq1 list seq2) [declare]
                 (body
                  (if (isNil seq1)
                      [then [return 
                             seq2]]
                      (body (return (cons (car seq1) (concatLists (cdr seq1) seq2)))))))


           [list alistKeys [list alist] [declare]
                 [body
                  [if [isNil alist]
                      [then [return nil]]
                      [else [return [cons [car [car alist]] [alistKeys [cdr alist]]]]]]
                  ]]

           [list mergeIncludes [list program] [declare]
                 [body
                  ;[display [alistKeys [merge_recur [childrenof [cdr [cdr [assoc  "includes" program]]]] program]]]
                  [return [merge_recur [childrenof [cdr [cdr [assoc  "includes" program]]]] program]]
                  ]]

           [list merge_recur [list incs list program] [declare]
                 [body

                  ;[printf "Merging includes: "][display incs]
                  [if [> [length incs] 0]
                      [then [return [mergeInclude [car incs] [merge_recur [cdr incs] program]]]]
                      [else [return program]]]
                  ]]
           [list mergeInclude [list inc list program] [declare
                                                       [list newProgram nil]
                                                       [list oldfunctionsnode nil]
                                                       [list oldfunctions nil]
                                                       [list newfunctions nil]
                                                       [list newFunctionNode nil]
                                                       [list functions nil]

                                                       [list oldtypesnode nil]
                                                       [list oldtypes nil]
                                                       [list newtypes nil]
                                                       [list newTypeNode nil]
                                                       [list types nil]
                                                       ]
                 [body
                  ;[printf "Merging include: "][display [alistKeys inc]]
                  [if [isNil inc]
                      [then [return program]]
                      [else
                       [set functions  [childrenof [cdr [assoc "functions"  inc]]]]
                       [set oldfunctionsnode  [cdr [assoc  "functions" program]]]
                       [set oldfunctions [childrenof oldfunctionsnode]]
                       [set newfunctions [concatLists functions oldfunctions]]
                      

                       [set newFunctionNode [cons [boxSymbol "node"] [alistCons [boxSymbol "children"] newfunctions [cdr oldfunctionsnode]]]]


                       ;[display [assoc     "types"  [car [childrenof [cdr [cdr [assoc  "includes" program]]]]]]]
                       ;[panic "done"]
                       [set types      [childrenof [cdr [assoc     "types"  inc]]]]
                       [set oldtypesnode  [cdr [assoc  "types" program]]]
                  
                       [set oldtypes [childrenof oldtypesnode]]
                       ;[display oldtypes]
                       ;[panic "done"]
                       [set newtypes [concatLists types oldtypes]]

                       [set newTypeNode [cons [boxSymbol "node"] [alistCons [boxSymbol "children"] newtypes [cdr oldtypesnode]]]]
                       ;[display newTypeNode]
                       ;[panic "done"]
                       [set newProgram
                            [alistCons [boxString "functions"]  newFunctionNode
                                       [alistCons [boxString "types"] newTypeNode
                                                  [alistCons [boxString "includes"] [cons [boxSymbol "includes"] nil] newProgram]]]]

                       ;[printf "\noldfunctions: "]
                       ;[display [alistKeys oldfunctions]]


                       ;[printf "\nnewfunctions: "]
                       ;[display [alistKeys newfunctions]]

                       ;[printf "\noldfunctionnode: "]
                       ;[display oldFunctionNode]
                       ;[display [alistKeys [cdr oldfunctionsnode]]]
                  
                  
                       ;[printf "\nnewfunctionnode: "]
                       ;[display newFunctionNode]
                       ;[display [alistKeys [cdr newFunctionNode]]]

                  
                       ;[printf "\nNewProgram: "]
                       ;[display [alistKeys newProgram]]





                       ;[printf "\noldtypes: "]
                       ;[display [alistKeys oldtypes]]


                       ;[printf "\nnewtypes: "]
                       ;[display [alistKeys newtypes]]

                       ;[printf "\noldtypenode: "]
                       ;[display oldTypeNode]
                       ;[display [alistKeys [cdr oldtypesnode]]]
                  
                  
                       ;[printf "\nnewtypenode: "]
                       ;[display newTypeNode]
                       ;[display [alistKeys [cdr newTypeNode]]]

                  
                       ;[printf "\nNewProgram: "]
                       ;[display [alistKeys newProgram]]
                       ;[os.Exit 1]
                       [return newProgram]]
                       
                      ]

                  ]]

                 
           [void compile [string filename]
                 [declare
                  [string programStr ""]
                  [list tree nil]
                  [list program nil]
                  ]
                 [body
                  ;[printf "Reading in program...\n"]
                  [set programStr [read-file filename]]
                  ;[printf "Read program: %s\n" programStr]
                  ;[printf "Read program.  Parsing...\n" ]
                  [set tree [readSexpr programStr filename]]
                  ;[printf "Parsed program.  Building AST...\n" ]
                  ;[display  tree]

                  [set program [alistCons [boxString "includes"] [astIncludes  [first tree]]
                                          [alistCons [boxString "types"] [astTypes  [second tree]]
                                                     [alistCons [boxString "functions"] [astFunctions  [third tree]] nil]]]]
                  [set program [mergeIncludes program]]
                  ;[printf "Built AST.  Generating ansi C output...\n" ]                   
                  ;[display [astFunctions  tree]]
                  ;[printf "\n\n\nPrinting includes\n"]
                  ;[display [assoc "includes" program]]
                  ;[display program]
                  ;[printf "!!!!!!!!!!!!\n"]
                  ;[alistKeys program]
                  [ansiIncludes  [cdr [assoc "includes" program]]]
                  ;[printf "\n\n\nPrinting types\n"]
                  ;[printf "!!!\n\n\n!!!"]
                  ;[display [cdr [assoc "types" program]]]
            
                  [ansiTypes  [childrenof [cdr [assoc "types" program]]]]
                  [printf "Box* globalStackTrace = NULL;\n"]
                  ;[printf "\n\n\nPrinting functions\n"]
                  ;[display [assoc "functions" program]]
                  ;FIXME
                  [printf "
bool isNil(list p) {
    return p == NULL;
}
\n\n//Forward declarations\n"]
                  ;[display [cdr [assoc "functions" program]]]
                  [ansiForwardDeclarations [cdr [assoc "children" [cdr [cdr [assoc "functions" program]]]]]]
                  [printf "\n\n//End forward declarations\n\n"]
                  [ansiFunctions [cdr [assoc "children" [cdr [cdr [assoc "functions" program]]]]]]
                  [printf "\n"]
                  ]]

           [void test15 []
                 [declare
                  [string a "hello"]
                  [string b " world"]
                  [string c ""]
                  ]
                 [body
                  [set c [stringConcatenate a b]]
                  [if [equalString c "hello world"]
                      [body [printf "15. pass String concatenate\n"]]
                      [body [printf "15. fail String concatenate\n"]]
                      ]
                  ]]

    
           [void test16 []
                 [declare
                  [list assocCell1 nil]
                  [list assList nil]
                  [list assocCell2 nil]
                  [list assocCell3 nil]
            
                  ]
                 [body
                  [set assocCell1 [cons [boxString "Hello"] [boxString "world"]]]
                  [set assocCell2 [cons [boxString "goodnight"] [boxString "moon"]]]
                  [set assocCell3 [cons [boxSymbol "ohio"] [boxString "gozaimasu"]]]
                  [set assList [cons assocCell2 [emptyList]]]
                  [set assList [cons assocCell1 assList]]
                  [set assList [cons assocCell3 assList]]
                  ;[printf "Assoc:\n"]
                  ;[display [assoc "Hello" assList]]
                  [if 
                   [equalBox  [cdr [assoc "Hello" assList]]  [boxString "world"]]
                   [body [printf "16.1 pass Basic assoc works\n"]]
                   [body [printf "16.1 fail Basic assoc fails\n"]]]
                  [if [andBool
                       [andBool
                        [equalBox  [cdr [assoc "Hello" assList]]  [boxString "world"]]
                        [equalBox  [cdr [assoc "goodnight" assList]]  [boxString "moon"]]]
                       [equalBox  [cdr [assoc "ohio" assList]]  [boxString "gozaimasu"]]
                       ]
                      [body [printf "16.2 pass assoc list\n"]]
                      [body [printf "16.2 fail assoc list\n"]]
                      ]
                  ]]
          
           
           [list argList [int count int pos stringArray args] [declare ]
                 [body
                  [if [> count pos]
                      [body
                       [return [cons [boxString [getStringArray pos args]] [argList count [add1 pos] args]]]
                       ]
                      [body [return nil]]]
                  ]]

           [list reverse [list l] [declare ]
                 [body
                  [if [isEmpty l]
                      [body
                       [return nil]]
                      [body 
                       [return [cons [car l] [reverse [cdr l]]]]
                       ]]
                  ]]

           [bool inList [box item list l] [declare]
                 [body
                  [if [isNil l]
                      [then [return false]]
                      [else [if [equalBox [car l] item]
                                [then [return true]]
                                [else [return [inList item [cdr l]]]]]]]
                  ]]

           
           [void stackTracePush [string file string fname int line int column] [declare]
                 [body
       
                  [set globalStackTrace [cons [cons [boxString file] [cons [boxString fname] [cons [boxInt line] [cons [boxInt column] nil]]]] globalStackTrace]]
                  ]]

           [list stackTracePop [] [declare [list top nil]]
                 [body
                  [set top [car globalStackTrace]]
                  [set globalStackTrace [cdr globalStackTrace]]
                  [return top]
                  ]]
           
           [int start []
                [declare [bool runTests false]
                         ;[bool runMandel false]
                         [list cmdLine nil][box filename nil]]
                [body
                 [set cmdLine [reverse [argList globalArgsCount 0 globalArgs]]]
                 [printf "//"]
                 [display  cmdLine]
                 
                 [if [> [length cmdLine] 1]
                     [body [set filename [second cmdLine]]]
                     [body [set filename [boxString "compiler.qon"]]]]
                 [display  filename]
                 [set runTests  [inList [boxString "--test"] cmdLine ]]
                 [set globalTrace  [inList [boxString "--trace"] cmdLine ]]
                 [set globalStepTrace  [inList [boxString "--steptrace"] cmdLine ]]
                 ;[set runMandel  [equalBox [boxString "--mandelbrot"] filename ]]
                 ;                 [if runMandel
                 ;                     [then
                 ;                      [printf "Displaying asciimandlbrot\n"]
                 ;                      [newLine 0][mandelPic]]
                 ;                     [else [printf ""]]]
                 
                 [if runTests
                     [then
                      [test0]
                      [test1]
                      [test2]
                      [test3]
                      [test4]
                      [test5]
                      [test6]
                      [test7]
                      [test8]
                      [test9]
                      [test10]
                      ;[test11]
                      [test12]
                      [test13]
                      [test15]
                      [test16]
                      [printf "\n\nAfter all that hard work, I need a beer...\n"]
                      [beers 9]
                      ]
                     [else
                      [compile [unBoxString filename]]
                      [printf "\n"]
                      ;[mandelPic  ]
                      ]
                     ]
                 [return 0]
                 ;End of file!
                 ]]]]]]
;Print complete program so that the next compiler can access it.  Eventually we will incorporate this program data in the output program, so we can continue recompiling forever
[display-to-file [pretty-format prog #:mode 'write] "compiler.qon" #:exists 'truncate]




[define [macros form]
  [if [and [list? form] [> [length form] 1]]
      ;Find at calls, and replace them with at1, at2, at3...
      ;  [if [equal? 'at [first form]]
      ;      [cons [string->symbol [format "at~a" [length [cddr form]]]] [cdr form]]
      ;      form]
      form
      form]]


;Generate output and cross-check
[let [[nodes [type_program[walk  prog macros] ]]]
  ;[pretty-write nodes]
  [display-to-file [go_program  nodes] go_test_filename #:exists 'replace]
  [map system go_test_commands]
  [display-to-file [clang_program nodes] clang_test_filename #:exists 'replace]
  [map system clang_test_commands]
  [display-to-file [js_program nodes] js_test_filename #:exists 'replace]
  [map system js_test_commands]
  ;[display [go_program nodes] ]

  [let [[gout [file->string "results.go"]]
        [cout [file->string "results.c"]]
        [bout [file->string "results.js"]]
        ]
    [if [and [equal? cout gout]];[equal? gout bout]]
        [displayln "Job's a good 'un, boss"]
        [displayln "Outputs differ!"]
        ]]
  ]

;Prune all empty leafs from the tree
[define [noEmpty tree]
  [walk tree [lambda [l] [id [filter [lambda [x] [not [void? x]]] [filter id  [filter [lambda [x] [not [empty? x]]] l]]]]]]
  ]

[define nofollow '[ thing1 thing2]]
;Don't recurse through these nodes
[define [noFollow tree]
  [walk tree [lambda [l] [id [filter [lambda [x] [not [member   [first tree] nofollow streq?]]] l]]]]]

[define skipList '[thing3 thing4]]
;Skip over these child nodes
[define [skip tree]
  [walk tree [lambda [l] [id [filter [lambda [x] [not [member   [first tree] skipList streq?]]] l]]]]]


[define [streq? a b] [equal? [format "~a" a] [format "~a" b]]]


[define [traverse tree]
  [if [list? tree]
      [begin
  
        [when [not [empty? tree]]
          [if [not [member   [first tree] nofollow streq?]]
              [filter id [map [lambda [branch]
                                [if  [member branch skipList streq?] false
                                     [traverse branch]]] tree]]
              false
              ]
          ]]
      tree
      ]]
