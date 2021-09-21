

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
Box* globalStackTrace = NULL;

bool isNil(list p) {
    return p == NULL;
}


//Forward declarations


//End forward declarations



#Building function add from line:19

add() {
  local a="$1" ;
local b="$2" ;

  return $(sub $a $(sub $0 $b)); 

}


#Building function addf from line:20

addf() {
  local a="$1" ;
local b="$2" ;

  return $(subf $a $(subf $0 $b)); 

}


#Building function sub1 from line:21

sub1() {
  local a="$1" ;

  return $(sub $a $1); 

}


#Building function add1 from line:22

add1() {
  local a="$1" ;

  return $(add $a $1); 

}


#Building function clone from line:24

clone() {
  local b="$1" ;
local newb="$nil";

  newb=makeBox() 

  $newb_$typ=b->typ 

  $newb_$tag=b->tag 

  $newb_$lis=b->lis 

  $newb_$str=b->str 

  $newb_$i=b->i 

  $newb_$lengt=b->lengt 

  return $newb; 

}


#Building function newVoid from line:38

newVoid() {
  local newb="$nil";

  newb=makeBox() 

  $newb_$voi=$true 

  $newb_$typ="void" 

  return $newb; 

}


#Building function stackDump from line:48

stackDump() {
  
  printf "" 

}


#Building function nop from line:53

nop() {
  
  printf "" 

}


#Building function equalBox from line:57

equalBox() {
  local a="$1" ;
local b="$2" ;

  if (( $(isList $b) )) ; then 
    return $false; 

   else 
    if (( $(equalString "string" $(boxType $a)) )) ; then 
      return $(equalString $(unBoxString $a) $(stringify $b)); 

     else 
      if (( $(equalString "bool" $(boxType $a)) )) ; then 
        return $(andBool $(unBoxBool $a) $(unBoxBool $b)); 

       else 
        if (( $(equalString "symbol" $(boxType $a)) )) ; then 
          if (( $(equalString "symbol" $(boxType $b)) )) ; then 
            return $(equalString $(unBoxSymbol $a) $(unBoxSymbol $b)); 

           else 
            return $false; 

          fi 

         else 
          if (( $(equalString "int" $(boxType $a)) )) ; then 
            return $(equal $(unBoxInt $a) $(unBoxInt $b)); 

           else 
            return $false; 

          fi 

        fi 

      fi 

    fi 

  fi 

}


#Building function display from line:78

display() {
  local l="$1" ;

  if (( $(isEmpty $l) )) ; then 
    printf "nil " 

    return; 

   else 
    if (( $(isList $l) )) ; then 
      printf "[" 

      displayList $l $0 $true 

      printf "]" 

     else 
      displayList $l $0 $true 

    fi 

  fi 

}


#Building function openBrace from line:87

openBrace() {
  
  return "("; 

}


#Building function closeBrace from line:88

closeBrace() {
  
  return ")"; 

}


#Building function boxType from line:93

boxType() {
  local b="$1" ;

  return b->typ; 

}


#Building function makeBox from line:96

makeBox() {
  local b="$nil";

  b=malloc(sizeof(Box)) 

  if (( $(isNil $b) )) ; then 
    panic "failed to create box!" 

   else 
  fi 

  $b_$tag=$nil 

  $b_$car=$nil 

  $b_$cdr=$nil 

  $b_$lis=$nil 

  $b_$typ="None - error!" 

  return $b; 

}


#Building function makePair from line:111

makePair() {
  
  return makeBox(); 

}


#Building function boxString from line:117

boxString() {
  local s="$1" ;
local b="$nil";

  b=makeBox() 

  $b_$str=$s 

  $b_$lengt=$(string_length $s) 

  $b_$typ="string" 

  return $b; 

}


#Building function boxSymbol from line:127

boxSymbol() {
  local s="$1" ;
local b="$nil";

  b=$(boxString $s) 

  $b_$typ="symbol" 

  return $b; 

}


#Building function boxBool from line:136

boxBool() {
  local boo="$1" ;
local b="$nil";

  b=makeBox() 

  $b_$boo=$boo 

  $b_$typ="bool" 

  return $b; 

}


#Building function boxInt from line:145

boxInt() {
  local val="$1" ;
local b="$nil";

  b=makeBox() 

  $b_$i=$val 

  $b_$typ="int" 

  return $b; 

}


#Building function assertType from line:154

assertType() {
  local atype="$1" ;
local abox="$2" ;
local line="$3" ;
local file="$4" ;

  if (( $(isNil $abox) )) ; then 
    if (( $(equalString $atype "nil") )) ; then 
      return; 

     else 
      return; 

    fi 

   else 
    if (( $(equalString $atype $(boxType $abox)) )) ; then 
      return; 

     else 
      printf "Assertion failure at line %d, in file %s: provided value is not a '%s'!  It was actually '%s'. Contents:" $line $file $atype $(boxType $abox) 

      display $abox 

      panic "Invalid type!" 

    fi 

  fi 

}


#Building function unBoxString from line:166

unBoxString() {
  local b="$1" ;

  assertType "string" $b 167 "q/base.qon" 

  return b->str; 

}


#Building function unBoxSymbol from line:169

unBoxSymbol() {
  local b="$1" ;

  return b->str; 

}


#Building function unBoxBool from line:170

unBoxBool() {
  local b="$1" ;

  return b->boo; 

}


#Building function unBoxInt from line:171

unBoxInt() {
  local b="$1" ;

  return b->i; 

}


#Building function stringify_rec from line:173

stringify_rec() {
  local b="$1" ;

  if (( $(isNil $b) )) ; then 
    return ""; 

   else 
    return $(stringConcatenate $(stringify $(car $b)) $(stringConcatenate " " $(stringify_rec $(cdr $b)))); 

  fi 

}


#Building function stringify from line:185

stringify() {
  local b="$1" ;

  if (( $(isNil $b) )) ; then 
    return "()"; 

   else 
    if (( $(equalString "string" $(boxType $b)) )) ; then 
      return $(unBoxString $b); 

     else 
      if (( $(equalString "bool" $(boxType $b)) )) ; then 
        if (( $(unBoxBool $b) )) ; then 
          return "true"; 

         else 
          return "false"; 

        fi 

       else 
        if (( $(equalString "int" $(boxType $b)) )) ; then 
          return $(intToString $(unBoxInt $b)); 

         else 
          if (( $(equalString "symbol" $(boxType $b)) )) ; then 
            return $(unBoxSymbol $b); 

           else 
            if (( $(equalString "list" $(boxType $b)) )) ; then 
              return $(stringConcatenate "(" $(stringConcatenate $(stringify $(car $b)) $(stringConcatenate " " $(stringConcatenate $(stringify_rec $(cdr $b)) ")")))); 

             else 
              return $(stringConcatenate "Unsupported type: " $(boxType $b)); 

            fi 

          fi 

        fi 

      fi 

    fi 

  fi 

}


#Building function hasTag from line:216

hasTag() {
  local aBox="$1" ;
local key="$2" ;

  if (( $(isNil $aBox) )) ; then 
    return $false; 

   else 
    return $(isNotFalse $(assoc $(stringify $key) aBox->tag)); 

  fi 

}


#Building function getTag from line:222

getTag() {
  local aBox="$1" ;
local key="$2" ;

  if (( $false )) ; then 
    printf "Getting %s from: " $(stringify $key) 

    display $(alistKeys aBox->tag) 

    printf "\n" 

   else 
    printf "" 

  fi 

  return $(cdr $(assoc $(stringify $key) aBox->tag)); 

}


#Building function getTagFail from line:234

getTagFail() {
  local aBox="$1" ;
local key="$2" ;
local onFail="$3" ;

  if (( $(hasTag $aBox $key) )) ; then 
    return $(getTag $aBox $key); 

   else 
    return $onFail; 

  fi 

}


#Building function assocExists from line:240

assocExists() {
  local key="$1" ;
local aBox="$2" ;

  if (( $(isNil $aBox) )) ; then 
    return $false; 

   else 
    return $(isNotFalse $(assoc $key $aBox)); 

  fi 

}


#Building function assocFail from line:248

assocFail() {
  local key="$1" ;
local aBox="$2" ;
local onFail="$3" ;

  if (( $(assocExists $key $aBox) )) ; then 
    return $(assoc $key $aBox); 

   else 
    return $(cons $(boxString $key) $onFail); 

  fi 

}


#Building function assocPanic from line:254

assocPanic() {
  local key="$1" ;
local aBox="$2" ;
local onFail="$3" ;

  if (( $(assocExists $key $aBox) )) ; then 
    return $(assoc $key $aBox); 

   else 
    panic $onFail 

  fi 

  panic "Inconceivable" 

  return $nil; 

}


#Building function setTag from line:265

setTag() {
  local key="$1" ;
local val="$2" ;
local aStruct="$3" ;

  $aStruct_$tag=$(alistCons $key $val aStruct->tag) 

  return $aStruct; 

}


#Building function locPanic from line:282

locPanic() {
  local file="$1" ;
local line="$2" ;
local message="$3" ;

  printf "%s %s:%s\n" $file $line $message 

  panic $message 

}


#Building function truthy from line:308

truthy() {
  local aVal="$1" ;

  return $(isNotFalse $aVal); 

}


#Building function isNotFalse from line:312

isNotFalse() {
  local aVal="$1" ;

  if (( $(equalString $(boxType $aVal) "bool") )) ; then 
    if (( $(unBoxBool $aVal) )) ; then 
      return $true; 

     else 
      return $false; 

    fi 

   else 
    return $true; 

  fi 

}


#Building function toStr from line:320

toStr() {
  local thing="$1" ;

  return $(boxString $(stringify $thing)); 

}


#Building function listLast from line:323

listLast() {
  local alist="$1" ;

  if (( $(isEmpty $(cdr $alist)) )) ; then 
    return $(car $alist); 

   else 
    return $(listLast $(cdr $alist)); 

  fi 

}


#Building function newLine from line:331

newLine() {
  local indent="$1" ;

  printf "\n" 

  printIndent $indent 

}


#Building function printIndent from line:337

printIndent() {
  local ii="$1" ;

  if (( $(greaterthan $ii $0) )) ; then 
    printf "  " 

    printIndent $(sub1 $ii) 

   else 
    return; 

  fi 

}


#Building function argList from line:353

argList() {
  local count="$1" ;
local pos="$2" ;
local args="$3" ;

  if (( $(greaterthan $count $pos) )) ; then 
    return $(cons $(boxString $(getStringArray $pos $args)) $(argList $count $(add1 $pos) $args)); 

   else 
    return $nil; 

  fi 

}


#Building function tron from line:363

tron() {
  
  globalTrace=$true 

}


#Building function troff from line:364

troff() {
  
  globalTrace=$false 

}


#Building function stron from line:365

stron() {
  
  globalStepTrace=$true 

}


#Building function stroff from line:366

stroff() {
  
  globalStepTrace=$false 

}


#Building function ansi3IsNil from line:12

ansi3IsNil() {
  local a="$1" ;

  if (( ($a == $NULL) )) ; then 
    return $true; 

   else 
    return $false; 

  fi 

}


#Building function pointerAdd from line:18

pointerAdd() {
  local a="$1" ;
local b="$2" ;

  return ($a + $b); 

}


#Building function getEnv from line:22

getEnv() {
  local key="$1" ;

  return $(getenv $key); 

}


#Building function panic from line:26

panic() {
  local s="$1" ;

  abort() 

  exit $1 

}


#Building function sub from line:31

sub() {
  local a="$1" ;
local b="$2" ;

  return ($a - $b); 

}


#Building function mult from line:35

mult() {
  local a="$1" ;
local b="$2" ;

  return ($a * $b); 

}


#Building function greaterthan from line:39

greaterthan() {
  local a="$1" ;
local b="$2" ;

  return ($a > $b); 

}


#Building function subf from line:43

subf() {
  local a="$1" ;
local b="$2" ;

  return ($a - $b); 

}


#Building function multf from line:47

multf() {
  local a="$1" ;
local b="$2" ;

  return ($a * $b); 

}


#Building function greaterthanf from line:51

greaterthanf() {
  local a="$1" ;
local b="$2" ;

  return ($a > $b); 

}


#Building function equal from line:55

equal() {
  local a="$1" ;
local b="$2" ;

  return ($a == $b); 

}


#Building function equalString from line:59

equalString() {
  local a="$1" ;
local b="$2" ;

  return ($0 == $(strcmp $a $b)); 

}


#Building function string_length from line:63

string_length() {
  local s="$1" ;

  return $(strlen $s); 

}


#Building function setSubString from line:67

setSubString() {
  local target="$1" ;
local start="$2" ;
local source="$3" ;

  target[start]=source[0] 

  return $target; 

}


#Building function sub_string from line:73

sub_string() {
  local s="$1" ;
local start="$2" ;
local length="$3" ;
local substr="""";

  substr=$(calloc $(add $length $1) $1) 

  strncpy $substr ($s + $start) $length 

  return $substr; 

}


#Building function stringConcatenate from line:80

stringConcatenate() {
  local a="$1" ;
local b="$2" ;
local len="$0";
local target="$nil";

  len=$(add $(add $(strlen $a) $(strlen $b)) $1) 

  target=$(calloc $len $1) 

  strncat $target $a $len 

  strncat $target $b $len 

  return $target; 

}


#Building function intToString from line:89

intToString() {
  local a="$1" ;
local len="$0";
local target="$nil";

  len=$100 

  target=$(calloc $len $1) 

  snprintf $target $99 "%d" $a 

  return $target; 

}


#Building function gc_malloc from line:97

gc_malloc() {
  local size="$1" ;

  return $(malloc $size); 

}


#Building function makeArray from line:102

makeArray() {
  local length="$1" ;
local array="$nil";

  array=$(gc_malloc $(mult $length $(sizeof $int))) 

  return $array; 

}


#Building function at from line:108

at() {
  local arr="$1" ;
local index="$2" ;

  return arr[index]; 

}


#Building function setAt from line:113

setAt() {
  local array="$1" ;
local index="$2" ;
local value="$3" ;

  [passthrough "array[index]"]=$value 

}


#Building function setCharAt from line:118

setCharAt() {
  local array="$1" ;
local index="$2" ;
local value="$3" ;

  [passthrough "array[index]"]=$value 

}


#Building function read_file from line:123

read_file() {
  local filename="$1" ;
local buffer="$nil";
local length="$0";
local f="$nil";

  f=$(fopen $filename "rb") 

  if (( $(ansi3IsNil $f) )) ; then 
    return $nil; 

   else 
    fseek $f $0 $SEEK_END 

    length=$(ftell $f) 

    fseek $f $0 $SEEK_SET 

    buffer=$(calloc $(add $1 $length) $1) 

    if (( $(ansi3IsNil $buffer) )) ; then 
      panic "Malloc failed!\n" 

     else 
      fread $buffer $1 $length $f 

    fi 

    fclose $f 

  fi 

  return $buffer; 

}


#Building function write_file from line:143

write_file() {
  local filename="$1" ;
local data="$2" ;
local buffer="$nil";
local length="$0";
local f="$nil";

  f=$(fopen $filename "w") 

  if (( $(ansi3IsNil $f) )) ; then 
    panic "Error opening file!" 

   else 
    fprintf $f "%s" $data 

    fclose $f 

  fi 

}


#Building function getStringArray from line:154

getStringArray() {
  local index="$1" ;
local strs="$2" ;

  return strs[index]; 

}


#Building function programArgs from line:158

programArgs() {
  
  return $globalArgs; 

}


#Building function programArgsCount from line:163

programArgsCount() {
  
  return $globalArgsCount; 

}


#Building function main from line:169

main() {
  local argc="$1" ;
local argv="$2" ;

  caller=$(calloc $1024 $1) 

  globalArgs=$argv 

  globalArgsCount=$argc 

  return $(start $argc $argv); 

}


#Building function character from line:177

character() {
  local num="$1" ;
local buffer="$nil";
local str="$NULL";

  str=$(malloc $2) 

  if (( $(ansi3IsNil $str) )) ; then 
    return $0; 

   else 
    setCharAt $str $0 $num 

    setCharAt $str $1 $0 

    return $str; 

  fi 

}


#Building function displays from line:192

displays() {
  local s="$1" ;

  printf "%s" $s 

}


#Building function say from line:6

say() {
  local greeting="$1" ;
local count="$2" ;

  if (( $(greaterthan $count $0) )) ; then 
    printf "%s" $greeting 

    say $greeting $(sub1 $count) 

   else 
    return; 

  fi 

}


#Building function start from line:16

start() {
  
  say "Hello world\n" $3 

  return $0; 

}


