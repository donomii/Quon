function read_file(filename) {return fs.readFileSync(filename);}
function write_file(filename, data) {fs.writeFileSync(filename, data);}
var util = require('util');
function printf() {process.stdout.write(util.format.apply(this, arguments));}
function qlog()   {process.stderr.write(util.format.apply(this, arguments));}
var fs = require('fs');
function equalString(a,b) {if (a==null) {return false;}if (b==null) {return false;}return a.toString()===b.toString() }
function panic(s){console.trace(s);process.exit(1);}
function dump(s){console.log(s)}function sub(a, b) { return a - b; }
function mult(a, b) { return a * b; }
function greaterthan(a, b) { return a > b; }
function subf(a, b) { return a - b; }
function multf(a, b) { return a * b; }
function greaterthanf(a, b) { return a > b; }
function equal(a, b) { return a == b; }
function andBool(a, b) { return a == b;}
function string_length(s) { return s.length;}
function sub_string(str, start, len) {str = ''+str;return str.substring(start, start+len)};
function stringConcatenate(a, b) { return a + b}
function intToString(a) {}


function gc_malloc( size ) {
return {};
}

function makeArray(length) {
   return [];
}

function at(arr, index) {
  return arr[index];
}

function setAt(array, index, value) {
    array[index] = value;
}

function getStringArray(index, strs) {
return strs[index];
}

var NULL = null;var globalArgs;
var globalArgsCount;
var globalTrace = false;
var globalStepTrace = false;
var releaseMode = false;
function character(num) {}
var globalStackTrace = NULL;

var caller = "";

function isNil(p) {
    return p == NULL;
}



//Building function add from line: 19

function add(a,b) {
  
if (globalTrace)
    {printf("add at q/base.qon:19\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(sub(a, sub(0, b)));

if (globalTrace)
    {printf("Leaving add\n");}

}


//Building function addf from line: 20

function addf(a,b) {
  
if (globalTrace)
    {printf("addf at q/base.qon:20\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(subf(a, subf(0, b)));

if (globalTrace)
    {printf("Leaving addf\n");}

}


//Building function sub1 from line: 21

function sub1(a) {
  
if (globalTrace)
    {printf("sub1 at q/base.qon:21\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(sub(a, 1));

if (globalTrace)
    {printf("Leaving sub1\n");}

}


//Building function add1 from line: 22

function add1(a) {
  
if (globalTrace)
    {printf("add1 at q/base.qon:22\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(add(a, 1));

if (globalTrace)
    {printf("Leaving add1\n");}

}


//Building function clone from line: 24

function clone(b) {
  var newb = NULL;

if (globalTrace)
    {printf("clone at q/base.qon:24\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newb = makeBox();
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newb.typ = b.typ;
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newb.tag = b.tag;
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newb.lis = b.lis;
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newb.str = b.str;
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newb.i = b.i;
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newb.lengt = b.lengt;
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(newb);

if (globalTrace)
    {printf("Leaving clone\n");}

}


//Building function newVoid from line: 38

function newVoid() {
  var newb = NULL;

if (globalTrace)
    {printf("newVoid at q/base.qon:38\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newb = makeBox();
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newb.voi = true;
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newb.typ = "void";
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(newb);

if (globalTrace)
    {printf("Leaving newVoid\n");}

}


//Building function stackDump from line: 48

function stackDump() {
  
if (globalTrace)
    {printf("stackDump at q/base.qon:48\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("");

if (globalTrace)
    {printf("Leaving stackDump\n");}

}


//Building function nop from line: 53

function nop() {
  
if (globalTrace)
    {printf("nop at q/base.qon:53\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("");

if (globalTrace)
    {printf("Leaving nop\n");}

}


//Building function equalBox from line: 57

function equalBox(a,b) {
  
if (globalTrace)
    {printf("equalBox at q/base.qon:57\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isList(b)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(false);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalString("string", boxType(a))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(equalString(unBoxString(a), stringify(b)));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalString("bool", boxType(a))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(andBool(unBoxBool(a), unBoxBool(b)));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalString("symbol", boxType(a))) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalString("symbol", boxType(b))) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            return(equalString(unBoxSymbol(a), unBoxSymbol(b)));

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            return(false);

          };

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalString("int", boxType(a))) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            return(equal(unBoxInt(a), unBoxInt(b)));

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            return(false);

          };

        };

      };

    };

  };

if (globalTrace)
    {printf("Leaving equalBox\n");}

}


//Building function display from line: 78

function display(l) {
  
if (globalTrace)
    {printf("display at q/base.qon:78\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(l)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("nil ");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isList(l)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("[");
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      displayList(l, 0, true);
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("]");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      displayList(l, 0, true);

    };

  };

if (globalTrace)
    {printf("Leaving display\n");}

}


//Building function openBrace from line: 87

function openBrace() {
  
if (globalTrace)
    {printf("openBrace at q/base.qon:87\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return("(");

if (globalTrace)
    {printf("Leaving openBrace\n");}

}


//Building function closeBrace from line: 88

function closeBrace() {
  
if (globalTrace)
    {printf("closeBrace at q/base.qon:88\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(")");

if (globalTrace)
    {printf("Leaving closeBrace\n");}

}


//Building function boxType from line: 93

function boxType(b) {
  
if (globalTrace)
    {printf("boxType at q/base.qon:93\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(b.typ);

if (globalTrace)
    {printf("Leaving boxType\n");}

}


//Building function makeBox from line: 96

function makeBox() {
  var b = NULL;

if (globalTrace)
    {printf("makeBox at q/base.qon:96\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  b = {};
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(b)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    panic("failed to create box!");

  } else {
  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  b.tag = NULL;
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  b.car = NULL;
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  b.cdr = NULL;
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  b.lis = NULL;
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  b.typ = "None - error!";
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(b);

if (globalTrace)
    {printf("Leaving makeBox\n");}

}


//Building function makePair from line: 111

function makePair() {
  
if (globalTrace)
    {printf("makePair at q/base.qon:111\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(makeBox());

if (globalTrace)
    {printf("Leaving makePair\n");}

}


//Building function boxString from line: 117

function boxString(s) {
  var b = NULL;

if (globalTrace)
    {printf("boxString at q/base.qon:117\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  b = makeBox();
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  b.str = s;
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  b.lengt = string_length(s);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  b.typ = "string";
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(b);

if (globalTrace)
    {printf("Leaving boxString\n");}

}


//Building function boxSymbol from line: 127

function boxSymbol(s) {
  var b = NULL;

if (globalTrace)
    {printf("boxSymbol at q/base.qon:127\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  b = boxString(s);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  b.typ = "symbol";
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(b);

if (globalTrace)
    {printf("Leaving boxSymbol\n");}

}


//Building function boxBool from line: 136

function boxBool(boo) {
  var b = NULL;

if (globalTrace)
    {printf("boxBool at q/base.qon:136\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  b = makeBox();
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  b.boo = boo;
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  b.typ = "bool";
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(b);

if (globalTrace)
    {printf("Leaving boxBool\n");}

}


//Building function boxInt from line: 145

function boxInt(val) {
  var b = NULL;

if (globalTrace)
    {printf("boxInt at q/base.qon:145\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  b = makeBox();
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  b.i = val;
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  b.typ = "int";
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(b);

if (globalTrace)
    {printf("Leaving boxInt\n");}

}


//Building function assertType from line: 154

function assertType(atype,abox,line,file) {
  
if (globalTrace)
    {printf("assertType at q/base.qon:154\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(abox)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalString(atype, "nil")) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return;

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return;

    };

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalString(atype, boxType(abox))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return;

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("Assertion failure at line %d, in file %s: provided value is not a '%s'!  It was actually '%s'. Contents:", line, file, atype, boxType(abox));
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      display(abox);
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      panic("Invalid type!");

    };

  };

if (globalTrace)
    {printf("Leaving assertType\n");}

}


//Building function unBoxString from line: 166

function unBoxString(b) {
  
if (globalTrace)
    {printf("unBoxString at q/base.qon:166\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  assertType("string", b, 167, "q/base.qon");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(b.str);

if (globalTrace)
    {printf("Leaving unBoxString\n");}

}


//Building function unBoxSymbol from line: 169

function unBoxSymbol(b) {
  
if (globalTrace)
    {printf("unBoxSymbol at q/base.qon:169\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(b.str);

if (globalTrace)
    {printf("Leaving unBoxSymbol\n");}

}


//Building function unBoxBool from line: 170

function unBoxBool(b) {
  
if (globalTrace)
    {printf("unBoxBool at q/base.qon:170\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(b.boo);

if (globalTrace)
    {printf("Leaving unBoxBool\n");}

}


//Building function unBoxInt from line: 171

function unBoxInt(b) {
  
if (globalTrace)
    {printf("unBoxInt at q/base.qon:171\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(b.i);

if (globalTrace)
    {printf("Leaving unBoxInt\n");}

}


//Building function stringify_rec from line: 173

function stringify_rec(b) {
  
if (globalTrace)
    {printf("stringify_rec at q/base.qon:173\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(b)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return("");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(stringConcatenate(stringify(car(b)), stringConcatenate(" ", stringify_rec(cdr(b)))));

  };

if (globalTrace)
    {printf("Leaving stringify_rec\n");}

}


//Building function stringify from line: 185

function stringify(b) {
  
if (globalTrace)
    {printf("stringify at q/base.qon:185\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(b)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return("()");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalString("string", boxType(b))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(unBoxString(b));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalString("bool", boxType(b))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( unBoxBool(b)) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          return("true");

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          return("false");

        };

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalString("int", boxType(b))) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          return(intToString(unBoxInt(b)));

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalString("symbol", boxType(b))) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            return(unBoxSymbol(b));

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            if ( equalString("list", boxType(b))) {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              return(stringConcatenate("(", stringConcatenate(stringify(car(b)), stringConcatenate(" ", stringConcatenate(stringify_rec(cdr(b)), ")")))));

            } else {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              return(stringConcatenate("Unsupported type: ", boxType(b)));

            };

          };

        };

      };

    };

  };

if (globalTrace)
    {printf("Leaving stringify\n");}

}


//Building function hasTag from line: 216

function hasTag(aBox,key) {
  
if (globalTrace)
    {printf("hasTag at q/base.qon:216\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(aBox)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(false);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(isNotFalse(assoc(stringify(key), aBox.tag)));

  };

if (globalTrace)
    {printf("Leaving hasTag\n");}

}


//Building function getTag from line: 222

function getTag(aBox,key) {
  
if (globalTrace)
    {printf("getTag at q/base.qon:222\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( false) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("Getting %s from: ", stringify(key));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    display(alistKeys(aBox.tag));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(cdr(assoc(stringify(key), aBox.tag)));

if (globalTrace)
    {printf("Leaving getTag\n");}

}


//Building function getTagFail from line: 234

function getTagFail(aBox,key,onFail) {
  
if (globalTrace)
    {printf("getTagFail at q/base.qon:234\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( hasTag(aBox, key)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(getTag(aBox, key));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(onFail);

  };

if (globalTrace)
    {printf("Leaving getTagFail\n");}

}


//Building function assocExists from line: 240

function assocExists(key,aBox) {
  
if (globalTrace)
    {printf("assocExists at q/base.qon:240\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(aBox)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(false);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(isNotFalse(assoc(key, aBox)));

  };

if (globalTrace)
    {printf("Leaving assocExists\n");}

}


//Building function assocFail from line: 248

function assocFail(key,aBox,onFail) {
  
if (globalTrace)
    {printf("assocFail at q/base.qon:248\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( assocExists(key, aBox)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(assoc(key, aBox));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cons(boxString(key), onFail));

  };

if (globalTrace)
    {printf("Leaving assocFail\n");}

}


//Building function assocPanic from line: 254

function assocPanic(key,aBox,onFail) {
  
if (globalTrace)
    {printf("assocPanic at q/base.qon:254\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( assocExists(key, aBox)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(assoc(key, aBox));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    panic(onFail);

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  panic("Inconceivable");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(NULL);

if (globalTrace)
    {printf("Leaving assocPanic\n");}

}


//Building function setTag from line: 265

function setTag(key,val,aStruct) {
  
if (globalTrace)
    {printf("setTag at q/base.qon:265\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  aStruct.tag = alistCons(key, val, aStruct.tag);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(aStruct);

if (globalTrace)
    {printf("Leaving setTag\n");}

}


//Building function locPanic from line: 282

function locPanic(file,line,message) {
  
if (globalTrace)
    {printf("locPanic at q/base.qon:282\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s %s:%s\n", file, line, message);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  panic(message);

if (globalTrace)
    {printf("Leaving locPanic\n");}

}


//Building function truthy from line: 308

function truthy(aVal) {
  
if (globalTrace)
    {printf("truthy at q/base.qon:308\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(isNotFalse(aVal));

if (globalTrace)
    {printf("Leaving truthy\n");}

}


//Building function isNotFalse from line: 312

function isNotFalse(aVal) {
  
if (globalTrace)
    {printf("isNotFalse at q/base.qon:312\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString(boxType(aVal), "bool")) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( unBoxBool(aVal)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(true);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(false);

    };

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(true);

  };

if (globalTrace)
    {printf("Leaving isNotFalse\n");}

}


//Building function toStr from line: 320

function toStr(thing) {
  
if (globalTrace)
    {printf("toStr at q/base.qon:320\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(boxString(stringify(thing)));

if (globalTrace)
    {printf("Leaving toStr\n");}

}


//Building function listLast from line: 323

function listLast(alist) {
  
if (globalTrace)
    {printf("listLast at q/base.qon:323\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(cdr(alist))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(car(alist));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(listLast(cdr(alist)));

  };

if (globalTrace)
    {printf("Leaving listLast\n");}

}


//Building function newLine from line: 331

function newLine(indent) {
  
if (globalTrace)
    {printf("newLine at q/base.qon:331\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printIndent(indent);

if (globalTrace)
    {printf("Leaving newLine\n");}

}


//Building function printIndent from line: 337

function printIndent(ii) {
  
if (globalTrace)
    {printf("printIndent at q/base.qon:337\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(ii, 0)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("  ");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(sub1(ii));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  };

if (globalTrace)
    {printf("Leaving printIndent\n");}

}


//Building function argList from line: 353

function argList(count,pos,args) {
  
if (globalTrace)
    {printf("argList at q/base.qon:353\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(count, pos)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cons(boxString(getStringArray(pos, args)), argList(count, add1(pos), args)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(NULL);

  };

if (globalTrace)
    {printf("Leaving argList\n");}

}


//Building function tron from line: 363

function tron() {
  
if (globalTrace)
    {printf("tron at q/base.qon:363\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  globalTrace = true;

if (globalTrace)
    {printf("Leaving tron\n");}

}


//Building function troff from line: 364

function troff() {
  
if (globalTrace)
    {printf("troff at q/base.qon:364\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  globalTrace = false;

if (globalTrace)
    {printf("Leaving troff\n");}

}


//Building function stron from line: 365

function stron() {
  
if (globalTrace)
    {printf("stron at q/base.qon:365\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  globalStepTrace = true;

if (globalTrace)
    {printf("Leaving stron\n");}

}


//Building function stroff from line: 366

function stroff() {
  
if (globalTrace)
    {printf("stroff at q/base.qon:366\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  globalStepTrace = false;

if (globalTrace)
    {printf("Leaving stroff\n");}

}


//Building function filterVoid from line: 8

function filterVoid(l) {
  var token = NULL;

if (globalTrace)
    {printf("filterVoid at q/compiler.qon:8\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(l)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(emptyList());

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    token = car(l);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalString("void", token.typ)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(filterVoid(cdr(l)));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(cons(token, filterVoid(cdr(l))));

    };

  };

if (globalTrace)
    {printf("Leaving filterVoid\n");}

}


//Building function filterTokens from line: 20

function filterTokens(l) {
  var token = NULL;

if (globalTrace)
    {printf("filterTokens at q/compiler.qon:20\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(l)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(emptyList());

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    token = car(l);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalString(boxType(token), "symbol")) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalString("__LINE__", stringify(token))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(cons(getTagFail(token, boxString("line"), boxInt(-1)), filterTokens(cdr(l))));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalString("__COLUMN__", stringify(token))) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          return(cons(getTagFail(token, boxString("column"), boxInt(-1)), filterTokens(cdr(l))));

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalString("__FILE__", stringify(token))) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            return(cons(getTagFail(token, boxString("filename"), boxString("Unknown file")), filterTokens(cdr(l))));

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            return(cons(token, filterTokens(cdr(l))));

          };

        };

      };

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(cons(token, filterTokens(cdr(l))));

    };

  };

if (globalTrace)
    {printf("Leaving filterTokens\n");}

}


//Building function finish_token from line: 54

function finish_token(prog,start,len,line,column,filename) {
  var token = NULL;

if (globalTrace)
    {printf("finish_token at q/compiler.qon:54\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(len, 0)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    token = boxSymbol(sub_string(prog, start, len));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    token.tag = alistCons(boxString("filename"), boxString(filename), alistCons(boxString("column"), boxInt(column), alistCons(boxString("line"), boxInt(line), alistCons(boxString("totalCharPos"), boxInt(start), NULL))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(token);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(newVoid());

  };

if (globalTrace)
    {printf("Leaving finish_token\n");}

}


//Building function readString from line: 69

function readString(prog,start,len) {
  var token = "";

if (globalTrace)
    {printf("readString at q/compiler.qon:69\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  token = sub_string(prog, sub1(add(start, len)), 1);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("\"", token)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(sub_string(prog, start, sub1(len)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalString("\\", token)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(readString(prog, start, add(2, len)));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(readString(prog, start, add1(len)));

    };

  };

if (globalTrace)
    {printf("Leaving readString\n");}

}


//Building function readComment from line: 80

function readComment(prog,start,len) {
  var token = "";

if (globalTrace)
    {printf("readComment at q/compiler.qon:80\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  token = sub_string(prog, sub1(add(start, len)), 1);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isLineBreak(token)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(sub_string(prog, start, sub1(len)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(readComment(prog, start, add1(len)));

  };

if (globalTrace)
    {printf("Leaving readComment\n");}

}


//Building function isWhiteSpace from line: 88

function isWhiteSpace(s) {
  
if (globalTrace)
    {printf("isWhiteSpace at q/compiler.qon:88\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString(" ", s)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(true);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalString("\t", s)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(true);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalString("\n", s)) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(true);

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalString("\r", s)) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          return(true);

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          return(false);

        };

      };

    };

  };

if (globalTrace)
    {printf("Leaving isWhiteSpace\n");}

}


//Building function isLineBreak from line: 105

function isLineBreak(s) {
  
if (globalTrace)
    {printf("isLineBreak at q/compiler.qon:105\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("\n", s)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(true);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalString("\r", s)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(true);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(false);

    };

  };

if (globalTrace)
    {printf("Leaving isLineBreak\n");}

}


//Building function incForNewLine from line: 112

function incForNewLine(token,val) {
  
if (globalTrace)
    {printf("incForNewLine at q/compiler.qon:112\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("\n", stringify(token))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(add1(val));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(val);

  };

if (globalTrace)
    {printf("Leaving incForNewLine\n");}

}


//Building function annotateReadPosition from line: 120

function annotateReadPosition(filename,linecount,column,start,newBox) {
  
if (globalTrace)
    {printf("annotateReadPosition at q/compiler.qon:120\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(setTag(boxString("filename"), boxString(filename), setTag(boxString("column"), boxInt(column), setTag(boxString("line"), boxInt(linecount), setTag(boxString("totalCharPos"), boxInt(start), newBox)))));

if (globalTrace)
    {printf("Leaving annotateReadPosition\n");}

}


//Building function scan from line: 132

function scan(prog,start,len,linecount,column,filename) {
  var token = NULL;
var newString = "";
var newBox = NULL;

if (globalTrace)
    {printf("scan at q/compiler.qon:132\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(string_length(prog), sub(start, sub(0, len)))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    token = boxSymbol(sub_string(prog, sub1(add(start, len)), 1));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    token.tag = alistCons(boxString("totalCharPos"), boxInt(start), NULL);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isOpenBrace(token)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(cons(finish_token(prog, start, sub1(len), linecount, column, filename), cons(boxSymbol(openBrace()), scan(prog, add1(start), 1, linecount, add1(column), filename))));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( isCloseBrace(token)) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(cons(finish_token(prog, start, sub1(len), linecount, column, filename), cons(annotateReadPosition(filename, linecount, column, start, boxSymbol(closeBrace())), scan(prog, add(start, len), 1, linecount, add1(column), filename))));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( isWhiteSpace(stringify(token))) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          return(cons(finish_token(prog, start, sub1(len), linecount, column, filename), scan(prog, add(start, len), 1, incForNewLine(token, linecount), 0, filename)));

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalBox(boxSymbol(";"), token)) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            return(scan(prog, add(start, add1(add1(string_length(readComment(prog, add1(start), len))))), 1, add1(linecount), 0, filename));

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            if ( equalBox(boxSymbol("\""), token)) {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              newString = readString(prog, add1(start), len);
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              newBox = annotateReadPosition(filename, linecount, column, start, boxString(newString));
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              return(cons(newBox, scan(prog, add(start, add1(add1(string_length(newString)))), 1, linecount, add1(column), filename)));

            } else {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              return(scan(prog, start, sub(len, -1), linecount, add1(column), filename));

            };

          };

        };

      };

    };

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(emptyList());

  };

if (globalTrace)
    {printf("Leaving scan\n");}

}


//Building function isOpenBrace from line: 172

function isOpenBrace(b) {
  
if (globalTrace)
    {printf("isOpenBrace at q/compiler.qon:172\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(boxSymbol(openBrace()), b)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(true);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalBox(boxSymbol("["), b)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(true);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(false);

    };

  };

if (globalTrace)
    {printf("Leaving isOpenBrace\n");}

}


//Building function isCloseBrace from line: 181

function isCloseBrace(b) {
  
if (globalTrace)
    {printf("isCloseBrace at q/compiler.qon:181\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(boxSymbol(closeBrace()), b)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(true);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalBox(boxSymbol("]"), b)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(true);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(false);

    };

  };

if (globalTrace)
    {printf("Leaving isCloseBrace\n");}

}


//Building function skipList from line: 194

function skipList(l) {
  var b = NULL;

if (globalTrace)
    {printf("skipList at q/compiler.qon:194\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(l)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(emptyList());

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    b = car(l);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isOpenBrace(b)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(skipList(skipList(cdr(l))));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( isCloseBrace(b)) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(cdr(l));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(skipList(cdr(l)));

      };

    };

  };

if (globalTrace)
    {printf("Leaving skipList\n");}

}


//Building function makeNode from line: 216

function makeNode(name,subname,code,children) {
  
if (globalTrace)
    {printf("makeNode at q/compiler.qon:216\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(cons(boxSymbol("node"), alistCons(boxSymbol("line"), getTagFail(code, boxString("line"), boxInt(-1)), cons(cons(boxSymbol("name"), boxString(name)), cons(cons(boxSymbol("subname"), boxString(subname)), cons(cons(boxSymbol("code"), code), alistCons(boxSymbol("children"), children, emptyList())))))));

if (globalTrace)
    {printf("Leaving makeNode\n");}

}


//Building function addToNode from line: 232

function addToNode(key,val,node) {
  
if (globalTrace)
    {printf("addToNode at q/compiler.qon:232\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(cons(boxSymbol("node"), alistCons(key, val, cdr(node))));

if (globalTrace)
    {printf("Leaving addToNode\n");}

}


//Building function makeStatementNode from line: 237

function makeStatementNode(name,subname,code,children,functionName) {
  
if (globalTrace)
    {printf("makeStatementNode at q/compiler.qon:237\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(addToNode(boxSymbol("functionName"), functionName, makeNode(name, subname, code, children)));

if (globalTrace)
    {printf("Leaving makeStatementNode\n");}

}


//Building function astExpression from line: 242

function astExpression(tree) {
  
if (globalTrace)
    {printf("astExpression at q/compiler.qon:242\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isList(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(makeNode("expression", "expression", NULL, astSubExpression(tree)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(astSubExpression(tree));

  };

if (globalTrace)
    {printf("Leaving astExpression\n");}

}


//Building function astSubExpression from line: 250

function astSubExpression(tree) {
  
if (globalTrace)
    {printf("astSubExpression at q/compiler.qon:250\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(emptyList());

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isList(tree)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(cons(astExpression(car(tree)), astSubExpression(cdr(tree))));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(makeNode("expression", "leaf", tree, NULL));

    };

  };

if (globalTrace)
    {printf("Leaving astSubExpression\n");}

}


//Building function astIf from line: 261

function astIf(tree,fname) {
  
if (globalTrace)
    {printf("astIf at q/compiler.qon:261\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(boxString("then"), car(second(tree)))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nop();

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("Error at %s:%s!  If statement is missing the true branch.\n\n", stringify(getTag(car(first(tree)), boxString("filename"))), stringify(getTag(car(first(tree)), boxString("line"))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    panic("Missing true branch in if statement!  All if statements must have a true and false branch, like this:\n\n(if hungryForApples\n(then (printf \"yes!\"))\n(else (printf \"no!\")))\n\n\n");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(boxString("else"), car(third(tree)))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nop();

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("Error at %s:%s!  If statement is missing the false branch.\n\n", stringify(getTag(car(first(tree)), boxString("filename"))), stringify(getTag(car(first(tree)), boxString("line"))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    panic("Missing false branch in if statement!  All if statements must have a true and false branch, like this:\n\n(if hungryForApples\n(then (printf \"yes!\"))\n(else (printf \"no!\")))\n\n\n");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(makeNode("statement", "if", tree, cons(cons(astExpression(first(tree)), NULL), cons(astBody(cdr(second(tree)), fname), cons(astBody(cdr(third(tree)), fname), NULL)))));

if (globalTrace)
    {printf("Leaving astIf\n");}

}


//Building function astSetStruct from line: 282

function astSetStruct(tree) {
  
if (globalTrace)
    {printf("astSetStruct at q/compiler.qon:282\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(makeNode("statement", "structSetter", tree, astExpression(third(tree))));

if (globalTrace)
    {printf("Leaving astSetStruct\n");}

}


//Building function astSet from line: 287

function astSet(tree) {
  
if (globalTrace)
    {printf("astSet at q/compiler.qon:287\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(makeNode("statement", "setter", tree, astExpression(second(tree))));

if (globalTrace)
    {printf("Leaving astSet\n");}

}


//Building function astGetStruct from line: 292

function astGetStruct(tree) {
  
if (globalTrace)
    {printf("astGetStruct at q/compiler.qon:292\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(makeNode("expression", "structGetter", tree, NULL));

if (globalTrace)
    {printf("Leaving astGetStruct\n");}

}


//Building function astReturnVoid from line: 295

function astReturnVoid(fname) {
  
if (globalTrace)
    {printf("astReturnVoid at q/compiler.qon:295\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(makeStatementNode("statement", "returnvoid", NULL, NULL, fname));

if (globalTrace)
    {printf("Leaving astReturnVoid\n");}

}


//Building function astStatement from line: 299

function astStatement(tree,fname) {
  
if (globalTrace)
    {printf("astStatement at q/compiler.qon:299\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isList(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nop();

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("Error at %s:%s!  Statement must be a list.\n\n", stringify(getTag(car(first(tree)), boxString("filename"))), stringify(getTag(car(first(tree)), boxString("line"))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    panic("A statement must be a list: (printf \"Hello\")\n\n\n");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(boxString("if"), car(tree))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(astIf(cdr(tree), fname));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalBox(boxString("set"), car(tree))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(astSet(cdr(tree)));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalBox(boxString("get-struct"), car(tree))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printf("Choosing get-struct statement\n");
        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(astGetStruct(cdr(tree)));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalBox(boxString("set-struct"), car(tree))) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          return(astSetStruct(cdr(tree)));

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalBox(boxString("return"), car(tree))) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            if ( equal(listLength(tree), 1)) {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              return(astReturnVoid(fname));

            } else {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              return(makeStatementNode("statement", "return", tree, makeNode("expression", "expression", tree, astExpression(tree)), fname));

            };

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            return(makeStatementNode("statement", "statement", tree, makeNode("expression", "expression", tree, astExpression(tree)), fname));

          };

        };

      };

    };

  };

if (globalTrace)
    {printf("Leaving astStatement\n");}

}


//Building function astBody from line: 337

function astBody(tree,fname) {
  
if (globalTrace)
    {printf("astBody at q/compiler.qon:337\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(emptyList());

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cons(astStatement(car(tree), fname), astBody(cdr(tree), fname)));

  };

if (globalTrace)
    {printf("Leaving astBody\n");}

}


//Building function astFunction from line: 345

function astFunction(tree) {
  var file = "";
var line = "";
var fname = NULL;

if (globalTrace)
    {printf("astFunction at q/compiler.qon:345\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  fname = second(tree);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  line = stringify(getTag(fname, boxString("line")));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  file = stringify(getTag(fname, boxString("filename")));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(1, listLength(tree))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    locPanic(file, line, "Malformed function, seems to be empty");

  } else {
  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(2, listLength(tree))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    locPanic(file, line, "Malformed function, expected function name");

  } else {
  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(3, listLength(tree))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    locPanic(file, line, "Malformed function, expected argument list");

  } else {
  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(4, listLength(tree))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    locPanic(file, line, "Malformed function, expected variable declarations");

  } else {
  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(5, listLength(tree))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    locPanic(file, line, "Malformed function, expected body");

  } else {
  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(alistCons(boxSymbol("file"), getTag(fname, boxString("filename")), alistCons(boxSymbol("line"), getTag(fname, boxString("line")), cons(cons(boxSymbol("name"), boxString("function")), cons(cons(boxSymbol("subname"), second(tree)), cons(cons(boxSymbol("declarations"), cdr(fourth(tree))), cons(cons(boxSymbol("intype"), third(tree)), cons(cons(boxSymbol("outtype"), car(tree)), cons(cons(boxSymbol("children"), astBody(cdr(fifth(tree)), fname)), emptyList())))))))));

if (globalTrace)
    {printf("Leaving astFunction\n");}

}


//Building function astFunctionList from line: 378

function astFunctionList(tree) {
  
if (globalTrace)
    {printf("astFunctionList at q/compiler.qon:378\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(emptyList());

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cons(astFunction(car(tree)), astFunctionList(cdr(tree))));

  };

if (globalTrace)
    {printf("Leaving astFunctionList\n");}

}


//Building function astFunctions from line: 386

function astFunctions(tree) {
  
if (globalTrace)
    {printf("astFunctions at q/compiler.qon:386\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(boxString("functions"), car(tree))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(makeNode("functions", "functions", tree, astFunctionList(cdr(tree))));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    panic("Functions section not found!  Every program must have a function section, even if you don't define any functions, although that is a rather pointless program.  Your function section should look like:'\n\n(return_type function_name (arg1 arg2 arg3 ...) (declare types) (body (statement)(statement)))\n\n\nThe function section must be directly after the types section.");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(NULL);

  };

if (globalTrace)
    {printf("Leaving astFunctions\n");}

}


//Building function loadLib from line: 394

function loadLib(path) {
  var programStr = "";
var tree = NULL;
var library = NULL;

if (globalTrace)
    {printf("loadLib at q/compiler.qon:394\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  programStr = read_file(path);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = readSexpr(programStr, path);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrowalk(tree);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  library = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(library);

if (globalTrace)
    {printf("Leaving loadLib\n");}

}


//Building function astInclude from line: 410

function astInclude(tree) {
  
if (globalTrace)
    {printf("astInclude at q/compiler.qon:410\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(loadLib(stringify(tree)));

if (globalTrace)
    {printf("Leaving astInclude\n");}

}


//Building function astIncludeList from line: 413

function astIncludeList(tree) {
  
if (globalTrace)
    {printf("astIncludeList at q/compiler.qon:413\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(emptyList());

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cons(astInclude(car(tree)), astIncludeList(cdr(tree))));

  };

if (globalTrace)
    {printf("Leaving astIncludeList\n");}

}


//Building function astIncludes from line: 420

function astIncludes(tree) {
  
if (globalTrace)
    {printf("astIncludes at q/compiler.qon:420\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(boxString("includes"), car(tree))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(makeNode("includes", "includes", tree, astIncludeList(cdr(tree))));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    panic("Includes section not found!  Every program must have an include section, even if you don't import any libraries.  Your include section should look like:'\n\n(includes file1.qon file.qon)\n\n\nThe includes section must be the first section of the file.");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(NULL);

  };

if (globalTrace)
    {printf("Leaving astIncludes\n");}

}


//Building function astStruct from line: 428

function astStruct(tree) {
  
if (globalTrace)
    {printf("astStruct at q/compiler.qon:428\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(makeNode("type", "struct", tree, NULL));

if (globalTrace)
    {printf("Leaving astStruct\n");}

}


//Building function astType from line: 431

function astType(tree) {
  
if (globalTrace)
    {printf("astType at q/compiler.qon:431\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isList(cadr(tree))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(astStruct(tree));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(makeNode("type", "type", tree, NULL));

  };

if (globalTrace)
    {printf("Leaving astType\n");}

}


//Building function astTypeList from line: 437

function astTypeList(tree) {
  
if (globalTrace)
    {printf("astTypeList at q/compiler.qon:437\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(emptyList());

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cons(astType(car(tree)), astTypeList(cdr(tree))));

  };

if (globalTrace)
    {printf("Leaving astTypeList\n");}

}


//Building function astTypes from line: 443

function astTypes(tree) {
  
if (globalTrace)
    {printf("astTypes at q/compiler.qon:443\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    panic("Empty or absent types section");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(boxString("!!!Fuck"));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalBox(boxString("types"), car(tree))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(makeNode("types", "types", tree, astTypeList(cdr(tree))));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      panic("Types section not found!  Every program must have a types section, even if you don't define any types");
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("Types section not found!  Every program must have a types section, even if you don't define any types");
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(boxString("!!!Fuck"));

    };

  };

if (globalTrace)
    {printf("Leaving astTypes\n");}

}


//Building function declarationsof from line: 461

function declarationsof(ass) {
  
if (globalTrace)
    {printf("declarationsof at q/compiler.qon:461\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(cdr(assocPanic("declarations", cdr(ass), "Cons list has no declarations key")));

if (globalTrace)
    {printf("Leaving declarationsof\n");}

}


//Building function codeof from line: 464

function codeof(ass) {
  
if (globalTrace)
    {printf("codeof at q/compiler.qon:464\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(cdr(assocPanic("code", cdr(ass), "Given cons list does not contain a code key")));

if (globalTrace)
    {printf("Leaving codeof\n");}

}


//Building function functionNameof from line: 467

function functionNameof(ass) {
  
if (globalTrace)
    {printf("functionNameof at q/compiler.qon:467\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(cdr(assoc("functionName", cdr(ass))));

if (globalTrace)
    {printf("Leaving functionNameof\n");}

}


//Building function nodeof from line: 470

function nodeof(ass) {
  
if (globalTrace)
    {printf("nodeof at q/compiler.qon:470\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(boxBool(false), assoc("node", cdr(ass)))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("Given list does not contain nodes");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(boxBool(false));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cdr(assoc("node", cdr(ass))));

  };

if (globalTrace)
    {printf("Leaving nodeof\n");}

}


//Building function lineof from line: 478

function lineof(ass) {
  
if (globalTrace)
    {printf("lineof at q/compiler.qon:478\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(cdr(assocFail("line", cdr(ass), boxInt(-1))));

if (globalTrace)
    {printf("Leaving lineof\n");}

}


//Building function subnameof from line: 483

function subnameof(ass) {
  
if (globalTrace)
    {printf("subnameof at q/compiler.qon:483\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(cdr(assoc("subname", cdr(ass))));

if (globalTrace)
    {printf("Leaving subnameof\n");}

}


//Building function nameof from line: 486

function nameof(ass) {
  
if (globalTrace)
    {printf("nameof at q/compiler.qon:486\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(cdr(assoc("name", cdr(ass))));

if (globalTrace)
    {printf("Leaving nameof\n");}

}


//Building function childrenof from line: 489

function childrenof(ass) {
  
if (globalTrace)
    {printf("childrenof at q/compiler.qon:489\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(cdr(assoc("children", cdr(ass))));

if (globalTrace)
    {printf("Leaving childrenof\n");}

}


//Building function isNode from line: 493

function isNode(val) {
  
if (globalTrace)
    {printf("isNode at q/compiler.qon:493\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(val)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(false);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isList(val)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalBox(boxSymbol("node"), car(val))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(true);

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(false);

      };

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(false);

    };

  };

if (globalTrace)
    {printf("Leaving isNode\n");}

}


//Building function isLeaf from line: 509

function isLeaf(n) {
  
if (globalTrace)
    {printf("isLeaf at q/compiler.qon:509\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(equalBox(boxString("leaf"), subnameof(n)));

if (globalTrace)
    {printf("Leaving isLeaf\n");}

}


//Building function noStackTrace from line: 512

function noStackTrace() {
  
if (globalTrace)
    {printf("noStackTrace at q/compiler.qon:512\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(cons(boxString("boxType"), cons(boxString("stringify"), cons(boxString("isEmpty"), cons(boxString("unBoxString"), cons(boxString("isList"), cons(boxString("unBoxBool"), cons(boxString("unBoxSymbol"), cons(boxString("equalBox"), cons(boxString("assoc"), cons(boxString("inList"), cons(boxString("unBoxInt"), cons(boxString("listLength"), cons(boxString("stroff"), cons(boxString("troff"), cons(boxString("tron"), cons(boxString("stron"), cons(boxString("car"), cons(boxString("cdr"), cons(boxString("cons"), cons(boxString("stackTracePush"), cons(boxString("stackTracePop"), cons(boxString("assertType"), cons(boxString("boxString"), cons(boxString("boxSymbol"), cons(boxString("boxInt"), NULL))))))))))))))))))))))))));

if (globalTrace)
    {printf("Leaving noStackTrace\n");}

}


//Building function treeCompile from line: 544

function treeCompile(filename) {
  var programStr = "";
var tree = NULL;

if (globalTrace)
    {printf("treeCompile at q/compiler.qon:544\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  programStr = read_file(filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = readSexpr(programStr, filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(tree);

if (globalTrace)
    {printf("Leaving treeCompile\n");}

}


//Building function astBuild from line: 550

function astBuild(filename) {
  var programStr = "";
var tree = NULL;
var program = NULL;

if (globalTrace)
    {printf("astBuild at q/compiler.qon:550\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  programStr = read_file(filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = readSexpr(programStr, filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  program = mergeIncludes(program);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(program);

if (globalTrace)
    {printf("Leaving astBuild\n");}

}


//Building function astCompile from line: 567

function astCompile(filename) {
  var tree = NULL;
var replace = NULL;

if (globalTrace)
    {printf("astCompile at q/compiler.qon:567\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = loadQuon(filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  qlog("Final program: \n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = loadIncludes(tree);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrowalk(tree);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrosingle(tree, "write-file", "luaWriteFile");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrosingle(tree, "read-file", "luaReadFile");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrosingle(tree, "string-length", "string.len");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrosingle(tree, "sub-string", "luaSubstring");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrosingle(tree, "stringLength", "string.len");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  displayList(tree, 0, true);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  qlog("Transformed tree");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\n");

if (globalTrace)
    {printf("Leaving astCompile\n");}

}


//Building function mergeIncludes from line: 591

function mergeIncludes(program) {
  
if (globalTrace)
    {printf("mergeIncludes at q/compiler.qon:591\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(merge_recur(childrenof(cdr(cdr(assocPanic("includes", program, "Program lacks include section")))), program));

if (globalTrace)
    {printf("Leaving mergeIncludes\n");}

}


//Building function merge_recur from line: 598

function merge_recur(incs,program) {
  
if (globalTrace)
    {printf("merge_recur at q/compiler.qon:598\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(listLength(incs), 0)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(mergeInclude(car(incs), merge_recur(cdr(incs), program)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(program);

  };

if (globalTrace)
    {printf("Leaving merge_recur\n");}

}


//Building function mergeInclude from line: 606

function mergeInclude(inc,program) {
  var newProgram = NULL;
var oldfunctionsnode = NULL;
var oldfunctions = NULL;
var newfunctions = NULL;
var newFunctionNode = NULL;
var functions = NULL;
var oldtypesnode = NULL;
var oldtypes = NULL;
var newtypes = NULL;
var newTypeNode = NULL;
var types = NULL;

if (globalTrace)
    {printf("mergeInclude at q/compiler.qon:606\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(inc)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(program);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    functions = childrenof(cdr(assocPanic("functions", inc, "Included file has no functions section")));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    oldfunctionsnode = cdr(assocPanic("functions", program, "Current module has no functions section"));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    oldfunctions = childrenof(oldfunctionsnode);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newfunctions = concatLists(functions, oldfunctions);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newFunctionNode = cons(boxSymbol("node"), alistCons(boxSymbol("children"), newfunctions, cdr(oldfunctionsnode)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    types = childrenof(cdr(assocPanic("types", inc, "Included file has no types section")));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    oldtypesnode = cdr(assocPanic("types", program, "Current module has no types section"));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    oldtypes = childrenof(oldtypesnode);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newtypes = concatLists(types, oldtypes);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newTypeNode = cons(boxSymbol("node"), alistCons(boxSymbol("children"), newtypes, cdr(oldtypesnode)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newProgram = alistCons(boxString("functions"), newFunctionNode, alistCons(boxString("types"), newTypeNode, alistCons(boxString("includes"), cons(boxSymbol("includes"), NULL), newProgram)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(newProgram);

  };

if (globalTrace)
    {printf("Leaving mergeInclude\n");}

}


//Building function macrowalk from line: 5

function macrowalk(l) {
  
if (globalTrace)
    {printf("macrowalk at q/macros.qon:5\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(l)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(NULL);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isList(l)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalString(stringConcatenate("box", "List"), stringify(car(l)))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(car(doBoxList(cdr(l))));

      } else {
      };
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalString(stringConcatenate("string", "List"), stringify(car(l)))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(car(doStringList(cdr(l))));

      } else {
      };
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalString(stringConcatenate("symbol", "List"), stringify(car(l)))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(car(doSymbolList(cdr(l))));

      } else {
      };
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalString(stringConcatenate("multi", "List"), stringify(car(l)))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(car(doMultiList(cdr(l))));

      } else {
      };
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(cons(macrowalk(car(l)), macrowalk(cdr(l))));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(l);

    };

  };

if (globalTrace)
    {printf("Leaving macrowalk\n");}

}


//Building function macrosingle from line: 49

function macrosingle(l,search,replace) {
  var val = NULL;

if (globalTrace)
    {printf("macrosingle at q/macros.qon:49\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(l)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(NULL);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isList(l)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(cons(macrosingle(car(l), search, replace), macrosingle(cdr(l), search, replace)));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalString(search, stringify(l))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        val = clone(l);
        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        val.str = replace;
        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(val);

      } else {
      };
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(l);

    };

  };

if (globalTrace)
    {printf("Leaving macrosingle\n");}

}


//Building function macrolist from line: 73

function macrolist(l,search,replace) {
  var val = NULL;

if (globalTrace)
    {printf("macrolist at q/macros.qon:73\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(l)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(NULL);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isList(l)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalString(search, stringify(car(l)))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(concatLists(replace, macrolist(cdr(l), search, replace)));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(cons(macrolist(car(l), search, replace), macrolist(cdr(l), search, replace)));

      };

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(l);

    };

  };

if (globalTrace)
    {printf("Leaving macrolist\n");}

}


//Building function car from line: 9

function car(l) {
  
if (globalTrace)
    {printf("car at q/lists.qon:9\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(l)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("Cannot call car on empty list!\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    panic("Cannot call car on empty list!\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(NULL);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    assertType("list", l, 18, "q/lists.qon");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(l.car)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(NULL);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(l.car);

    };

  };

if (globalTrace)
    {printf("Leaving car\n");}

}


//Building function cdr from line: 23

function cdr(l) {
  
if (globalTrace)
    {printf("cdr at q/lists.qon:23\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  assertType("list", l, 25, "q/lists.qon");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(l)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("Attempt to cdr an empty list!!!!\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    panic("Attempt to cdr an empty list!!!!\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(NULL);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(l.cdr);

  };

if (globalTrace)
    {printf("Leaving cdr\n");}

}


//Building function cons from line: 33

function cons(data,l) {
  var p = NULL;

if (globalTrace)
    {printf("cons at q/lists.qon:33\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  p = makePair();
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  p.cdr = l;
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  p.car = data;
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  p.typ = "list";
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(p);

if (globalTrace)
    {printf("Leaving cons\n");}

}


//Building function caar from line: 45

function caar(l) {
  
if (globalTrace)
    {printf("caar at q/lists.qon:45\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(car(car(l)));

if (globalTrace)
    {printf("Leaving caar\n");}

}


//Building function cadr from line: 46

function cadr(l) {
  
if (globalTrace)
    {printf("cadr at q/lists.qon:46\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(car(cdr(l)));

if (globalTrace)
    {printf("Leaving cadr\n");}

}


//Building function caddr from line: 47

function caddr(l) {
  
if (globalTrace)
    {printf("caddr at q/lists.qon:47\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(car(cdr(cdr(l))));

if (globalTrace)
    {printf("Leaving caddr\n");}

}


//Building function cadddr from line: 48

function cadddr(l) {
  
if (globalTrace)
    {printf("cadddr at q/lists.qon:48\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(car(cdr(cdr(cdr(l)))));

if (globalTrace)
    {printf("Leaving cadddr\n");}

}


//Building function caddddr from line: 49

function caddddr(l) {
  
if (globalTrace)
    {printf("caddddr at q/lists.qon:49\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(car(cdr(cdr(cdr(cdr(l))))));

if (globalTrace)
    {printf("Leaving caddddr\n");}

}


//Building function cddr from line: 50

function cddr(l) {
  
if (globalTrace)
    {printf("cddr at q/lists.qon:50\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(cdr(cdr(l)));

if (globalTrace)
    {printf("Leaving cddr\n");}

}


//Building function first from line: 51

function first(l) {
  
if (globalTrace)
    {printf("first at q/lists.qon:51\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(car(l));

if (globalTrace)
    {printf("Leaving first\n");}

}


//Building function second from line: 52

function second(l) {
  
if (globalTrace)
    {printf("second at q/lists.qon:52\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(cadr(l));

if (globalTrace)
    {printf("Leaving second\n");}

}


//Building function third from line: 53

function third(l) {
  
if (globalTrace)
    {printf("third at q/lists.qon:53\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(caddr(l));

if (globalTrace)
    {printf("Leaving third\n");}

}


//Building function fourth from line: 54

function fourth(l) {
  
if (globalTrace)
    {printf("fourth at q/lists.qon:54\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(cadddr(l));

if (globalTrace)
    {printf("Leaving fourth\n");}

}


//Building function fifth from line: 55

function fifth(l) {
  
if (globalTrace)
    {printf("fifth at q/lists.qon:55\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(caddddr(l));

if (globalTrace)
    {printf("Leaving fifth\n");}

}


//Building function isList from line: 58

function isList(b) {
  
if (globalTrace)
    {printf("isList at q/lists.qon:58\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(b)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(true);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(equalString("list", b.typ));

  };

if (globalTrace)
    {printf("Leaving isList\n");}

}


//Building function emptyList from line: 65

function emptyList() {
  
if (globalTrace)
    {printf("emptyList at q/lists.qon:65\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(NULL);

if (globalTrace)
    {printf("Leaving emptyList\n");}

}


//Building function isEmpty from line: 67

function isEmpty(b) {
  
if (globalTrace)
    {printf("isEmpty at q/lists.qon:67\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(b)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(true);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(false);

  };

if (globalTrace)
    {printf("Leaving isEmpty\n");}

}


//Building function listLength from line: 74

function listLength(l) {
  
if (globalTrace)
    {printf("listLength at q/lists.qon:74\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(l)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(0);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(add1(listLength(cdr(l))));

  };

if (globalTrace)
    {printf("Leaving listLength\n");}

}


//Building function alistCons from line: 83

function alistCons(key,value,alist) {
  
if (globalTrace)
    {printf("alistCons at q/lists.qon:83\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(cons(cons(key, value), alist));

if (globalTrace)
    {printf("Leaving alistCons\n");}

}


//Building function assoc from line: 86

function assoc(searchTerm,l) {
  var elem = NULL;

if (globalTrace)
    {printf("assoc at q/lists.qon:86\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  assertType("list", l, 88, "q/lists.qon");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(l)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(boxBool(false));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    elem = car(l);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    assertType("list", elem, 94, "q/lists.qon");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isEmpty(elem)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(assoc(searchTerm, cdr(l)));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( false) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printf("Comparing %s and %s\n", searchTerm, stringify(car(elem)));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printf("");

      };
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalString(searchTerm, stringify(car(elem)))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(elem);

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(assoc(searchTerm, cdr(l)));

      };

    };

  };

if (globalTrace)
    {printf("Leaving assoc\n");}

}


//Building function chooseBox from line: 106

function chooseBox(aType) {
  
if (globalTrace)
    {printf("chooseBox at q/lists.qon:106\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("string", aType)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return("boxString");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalString("symbol", aType)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return("boxSymbol");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalString("bool", aType)) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return("boxBool");

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalString("int", aType)) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          return("boxInt");

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalString("float", aType)) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            return("boxFloat");

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            panic("Invalid type");

          };

        };

      };

    };

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return("");

if (globalTrace)
    {printf("Leaving chooseBox\n");}

}


//Building function mlistLiteral from line: 122

function mlistLiteral(b) {
  
if (globalTrace)
    {printf("mlistLiteral at q/lists.qon:122\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(b)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(NULL);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalString("string", boxType(b))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(b);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalString("bool", boxType(b))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(b);

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalString("int", boxType(b))) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          return(b);

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalString("symbol", boxType(b))) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            return(boxString(unBoxSymbol(b)));

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            return(boxString(stringConcatenate("Unsupported type: ", boxType(b))));

          };

        };

      };

    };

  };

if (globalTrace)
    {printf("Leaving mlistLiteral\n");}

}


//Building function doMultiList from line: 144

function doMultiList(l) {
  var newlist = NULL;
var ret = NULL;
var elem = NULL;

if (globalTrace)
    {printf("doMultiList at q/lists.qon:144\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(l)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cons(boxSymbol("nil"), NULL));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isEmpty(l)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(NULL);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      elem = first(l);
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      newlist = cons(boxString(chooseBox(elem.typ)), cons(mlistLiteral(first(l)), newlist));
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      ret = cons(cons(boxSymbol("cons"), cons(newlist, doMultiList(cdr(l)))), NULL);
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(ret);

    };

  };

if (globalTrace)
    {printf("Leaving doMultiList\n");}

}


//Building function doStringList from line: 167

function doStringList(l) {
  var newlist = NULL;
var ret = NULL;

if (globalTrace)
    {printf("doStringList at q/lists.qon:167\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(l)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cons(boxSymbol("nil"), NULL));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newlist = cons(boxSymbol("boxString"), cons(first(l), newlist));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ret = cons(cons(boxSymbol("cons"), cons(newlist, doStringList(cdr(l)))), NULL);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(ret);

  };

if (globalTrace)
    {printf("Leaving doStringList\n");}

}


//Building function doSymbolList from line: 184

function doSymbolList(l) {
  var newlist = NULL;
var ret = NULL;

if (globalTrace)
    {printf("doSymbolList at q/lists.qon:184\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(l)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cons(boxSymbol("nil"), NULL));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newlist = cons(boxSymbol("boxSymbol"), cons(first(l), newlist));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ret = cons(cons(boxSymbol("cons"), cons(newlist, doSymbolList(cdr(l)))), NULL);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(ret);

  };

if (globalTrace)
    {printf("Leaving doSymbolList\n");}

}


//Building function doBoxList from line: 202

function doBoxList(l) {
  
if (globalTrace)
    {printf("doBoxList at q/lists.qon:202\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(l)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cons(boxSymbol("nil"), NULL));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cons(cons(boxSymbol("cons"), cons(first(l), doBoxList(cdr(l)))), NULL));

  };

if (globalTrace)
    {printf("Leaving doBoxList\n");}

}


//Building function concatLists from line: 221

function concatLists(seq1,seq2) {
  
if (globalTrace)
    {printf("concatLists at q/lists.qon:221\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(seq1)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(seq2);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cons(car(seq1), concatLists(cdr(seq1), seq2)));

  };

if (globalTrace)
    {printf("Leaving concatLists\n");}

}


//Building function alistKeys from line: 227

function alistKeys(alist) {
  
if (globalTrace)
    {printf("alistKeys at q/lists.qon:227\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(alist)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(NULL);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cons(car(car(alist)), alistKeys(cdr(alist))));

  };

if (globalTrace)
    {printf("Leaving alistKeys\n");}

}


//Building function displayList from line: 233

function displayList(l,indent,first) {
  var val = NULL;

if (globalTrace)
    {printf("displayList at q/lists.qon:233\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(l)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isList(l)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( isEmpty(l)) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return;

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( first) {
        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf(" ");

        };
        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        val = car(l);
        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( isList(val)) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          newLine(indent);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf("%s", openBrace());
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          displayList(car(l), add1(indent), true);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf("%s", closeBrace());
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          displayList(cdr(l), indent, false);

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalString("string", val.typ)) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("\"%s\"", unBoxString(val));

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("%s", stringify(val));

          };
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          displayList(cdr(l), indent, false);

        };

      };

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalString("string", l.typ)) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printf("\"%s\"", unBoxString(l));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printf("%s", stringify(l));

      };

    };

  };

if (globalTrace)
    {printf("Leaving displayList\n");}

}


//Building function listReverse from line: 265

function listReverse(l) {
  
if (globalTrace)
    {printf("listReverse at q/lists.qon:265\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(l)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(NULL);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cons(car(l), listReverse(cdr(l))));

  };

if (globalTrace)
    {printf("Leaving listReverse\n");}

}


//Building function inList from line: 271

function inList(item,l) {
  
if (globalTrace)
    {printf("inList at q/lists.qon:271\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(l)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(false);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalBox(car(l), item)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(true);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(inList(item, cdr(l)));

    };

  };

if (globalTrace)
    {printf("Leaving inList\n");}

}


//Building function equalList from line: 281

function equalList(a,b) {
  
if (globalTrace)
    {printf("equalList at q/lists.qon:281\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(a)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(b)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(true);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(false);

    };

  } else {
  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(b)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(a)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(true);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(false);

    };

  } else {
  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(car(a), car(b))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(equalList(cdr(a), cdr(b)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(false);

  };

if (globalTrace)
    {printf("Leaving equalList\n");}

}


//Building function reverseRec from line: 304

function reverseRec(oldL,newL) {
  
if (globalTrace)
    {printf("reverseRec at q/lists.qon:304\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(oldL)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(newL);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(reverseRec(cdr(oldL), cons(first(oldL), newL)));

  };

if (globalTrace)
    {printf("Leaving reverseRec\n");}

}


//Building function reverseList from line: 311

function reverseList(l) {
  
if (globalTrace)
    {printf("reverseList at q/lists.qon:311\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(reverseRec(l, NULL));

if (globalTrace)
    {printf("Leaving reverseList\n");}

}


//Building function readSexpr from line: 4

function readSexpr(aStr,filename) {
  var tokens = NULL;
var as = NULL;

if (globalTrace)
    {printf("readSexpr at q/newparser.qon:4\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tokens = emptyList();
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tokens = filterTokens(filterVoid(scan(aStr, 0, 1, 0, 0, filename)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  as = sexprTree(tokens);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(car(as));

if (globalTrace)
    {printf("Leaving readSexpr\n");}

}


//Building function sexprTree from line: 11

function sexprTree(l) {
  var b = NULL;

if (globalTrace)
    {printf("sexprTree at q/newparser.qon:11\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(l)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(emptyList());

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    b = car(l);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isOpenBrace(b)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(cons(sexprTree(cdr(l)), sexprTree(skipList(cdr(l)))));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( isCloseBrace(b)) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(emptyList());

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        return(setTag(boxString("line"), getTagFail(b, boxString("line"), boxInt(-1)), cons(b, sexprTree(cdr(l)))));

      };

    };

  };

if (globalTrace)
    {printf("Leaving sexprTree\n");}

}


//Building function loadQuon from line: 29

function loadQuon(filename) {
  var programStr = "";
var tree = NULL;

if (globalTrace)
    {printf("loadQuon at q/newparser.qon:29\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  programStr = read_file(filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = readSexpr(programStr, filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(tree);

if (globalTrace)
    {printf("Leaving loadQuon\n");}

}


//Building function getIncludes from line: 38

function getIncludes(program) {
  
if (globalTrace)
    {printf("getIncludes at q/newparser.qon:38\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(cdr(first(program)));

if (globalTrace)
    {printf("Leaving getIncludes\n");}

}


//Building function getTypes from line: 42

function getTypes(program) {
  
if (globalTrace)
    {printf("getTypes at q/newparser.qon:42\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(cdr(second(program)));

if (globalTrace)
    {printf("Leaving getTypes\n");}

}


//Building function getFunctions from line: 46

function getFunctions(program) {
  
if (globalTrace)
    {printf("getFunctions at q/newparser.qon:46\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(cdr(third(program)));

if (globalTrace)
    {printf("Leaving getFunctions\n");}

}


//Building function loadIncludes from line: 51

function loadIncludes(tree) {
  var newProg = NULL;
var includeFile = "";
var functionsCombined = NULL;
var typesCombined = NULL;
var includeTree = NULL;

if (globalTrace)
    {printf("loadIncludes at q/newparser.qon:51\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(listLength(getIncludes(tree)), 0)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    includeFile = stringify(first(getIncludes(tree)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    includeTree = loadQuon(includeFile);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    functionsCombined = concatLists(getFunctions(includeTree), getFunctions(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    typesCombined = concatLists(getTypes(includeTree), getTypes(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newProg = buildProg(cdr(getIncludes(tree)), typesCombined, functionsCombined);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(loadIncludes(newProg));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(tree);

  };

if (globalTrace)
    {printf("Leaving loadIncludes\n");}

}


//Building function buildProg from line: 74

function buildProg(includes,types,functions) {
  var program = NULL;

if (globalTrace)
    {printf("buildProg at q/newparser.qon:74\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  includes = cons(boxSymbol("includes"), includes);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  types = cons(boxSymbol("types"), types);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  functions = cons(boxSymbol("functions"), functions);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  program = cons(includes, cons(types, cons(functions, NULL)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(program);

if (globalTrace)
    {printf("Leaving buildProg\n");}

}


//Building function numbers from line: 4

function numbers(num) {
  
if (globalTrace)
    {printf("numbers at q/perl.qon:4\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(0, num)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cons(boxString("-"), NULL));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cons(boxString(stringify(boxInt(num))), numbers(sub1(num))));

  };

if (globalTrace)
    {printf("Leaving numbers\n");}

}


//Building function lexType from line: 11

function lexType(abox) {
  
if (globalTrace)
    {printf("lexType at q/perl.qon:11\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("string", boxType(abox))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return("string");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( inList(boxString(sub_string(stringify(abox), 0, 1)), numbers(9))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return("number");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return("symbol");

    };

  };

if (globalTrace)
    {printf("Leaving lexType\n");}

}


//Building function perlLeaf from line: 23

function perlLeaf(thisNode,indent) {
  
if (globalTrace)
    {printf("perlLeaf at q/perl.qon:23\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("symbol", lexType(codeof(thisNode)))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s", dollar());

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  display(perlFuncMap(codeof(thisNode)));

if (globalTrace)
    {printf("Leaving perlLeaf\n");}

}


//Building function perlStructGetterExpression from line: 32

function perlStructGetterExpression(thisNode,indent) {
  
if (globalTrace)
    {printf("perlStructGetterExpression at q/perl.qon:32\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(boxString("structGetter"), subnameof(thisNode))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlGetStruct(thisNode, indent);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlLeaf(thisNode, indent);

  };

if (globalTrace)
    {printf("Leaving perlStructGetterExpression\n");}

}


//Building function perlExpression from line: 38

function perlExpression(node,indent) {
  
if (globalTrace)
    {printf("perlExpression at q/perl.qon:38\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isLeaf(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlLeaf(node, indent);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlSubExpression(node, indent);

  };

if (globalTrace)
    {printf("Leaving perlExpression\n");}

}


//Building function perlRecurList from line: 44

function perlRecurList(expr,indent) {
  
if (globalTrace)
    {printf("perlRecurList at q/perl.qon:44\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(expr)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlExpression(car(expr), indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(cdr(expr))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf(", ");
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      perlRecurList(cdr(expr), indent);

    };

  };

if (globalTrace)
    {printf("Leaving perlRecurList\n");}

}


//Building function perlSubExpression from line: 55

function perlSubExpression(tree,indent) {
  var thing = NULL;

if (globalTrace)
    {printf("perlSubExpression at q/perl.qon:55\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNode(childrenof(tree))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      perlSubExpression(childrenof(tree), indent);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( isLeaf(tree)) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printf("%s", dollar());
        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        display(perlFuncMap(codeof(tree)));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equal(1, listLength(childrenof(tree)))) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          display(codeof(car(childrenof(tree))));
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalBox(boxString("return"), codeof(car(childrenof(tree))))) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("");

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("()");

          };

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          thing = codeof(car(childrenof(tree)));
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalBox(boxSymbol("get-struct"), thing)) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("%s%s->{%s}", dollar(), stringify(codeof(second(childrenof(tree)))), stringify(codeof(third(childrenof(tree)))));

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            if ( equalBox(boxSymbol("new"), thing)) {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf("{}");

            } else {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf("%s(", stringify(perlFuncMap(codeof(car(childrenof(tree))))));
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              perlRecurList(cdr(childrenof(tree)), indent);
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf(")");

            };

          };

        };

      };

    };

  };

if (globalTrace)
    {printf("Leaving perlSubExpression\n");}

}


//Building function perlIf from line: 93

function perlIf(node,indent) {
  
if (globalTrace)
    {printf("perlIf at q/perl.qon:93\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("if ( ");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  perlExpression(car(first(childrenof(node))), 0);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf(") {");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  perlBody(second(childrenof(node)), add1(indent));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("} else {");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  perlBody(third(childrenof(node)), add1(indent));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("}");

if (globalTrace)
    {printf("Leaving perlIf\n");}

}


//Building function perlSetStruct from line: 106

function perlSetStruct(node,indent) {
  
if (globalTrace)
    {printf("perlSetStruct at q/perl.qon:106\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s->{%s} = ", dollar(), stringify(first(codeof(node))), stringify(second(codeof(node))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  perlExpression(childrenof(node), indent);

if (globalTrace)
    {printf("Leaving perlSetStruct\n");}

}


//Building function perlGetStruct from line: 113

function perlGetStruct(node,indent) {
  
if (globalTrace)
    {printf("perlGetStruct at q/perl.qon:113\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s->{%s}", dollar(), stringify(first(codeof(node))), stringify(second(codeof(node))));

if (globalTrace)
    {printf("Leaving perlGetStruct\n");}

}


//Building function perlSet from line: 118

function perlSet(node,indent) {
  
if (globalTrace)
    {printf("perlSet at q/perl.qon:118\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s = ", dollar(), stringify(first(codeof(node))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  perlExpression(childrenof(node), indent);

if (globalTrace)
    {printf("Leaving perlSet\n");}

}


//Building function assertNode from line: 124

function assertNode(node) {
  
if (globalTrace)
    {printf("assertNode at q/perl.qon:124\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNode(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    panic("Not a node!");

  };

if (globalTrace)
    {printf("Leaving assertNode\n");}

}


//Building function perlStatement from line: 131

function perlStatement(node,indent) {
  var functionName = NULL;

if (globalTrace)
    {printf("perlStatement at q/perl.qon:131\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  assertNode(node);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(boxString("setter"), subnameof(node))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlSet(node, indent);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalBox(boxString("structSetter"), subnameof(node))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      perlSetStruct(node, indent);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalBox(boxString("if"), subnameof(node))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        perlIf(node, indent);

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalBox(boxString("returnvoid"), subnameof(node))) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          functionName = functionNameof(node);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf("\n#Returnvoid\n");
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          newLine(indent);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          newLine(indent);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf("return");

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalBox(boxString("return"), subnameof(node))) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            functionName = functionNameof(node);
            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            if ( inList(functionName, noStackTrace())) {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf("");

            } else {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf("\n#standard return: %s\n", stringify(functionName));
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              newLine(indent);
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf("%s%s%s", "if (", dollar(), "globalTrace) {printf(\"Leaving \\n\")}\n");

            };
            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            newLine(indent);
            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            perlExpression(childrenof(node), indent);

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            if ( inList(functionName, noStackTrace())) {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf("");

            } else {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf("\n#standard expression\n");

            };
            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            newLine(indent);
            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            perlExpression(childrenof(node), indent);
            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            newLine(indent);

          };

        };

      };

    };

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf(";\n");

if (globalTrace)
    {printf("Leaving perlStatement\n");}

}


//Building function perlBody from line: 180

function perlBody(tree,indent) {
  
if (globalTrace)
    {printf("perlBody at q/perl.qon:180\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s%s%s", "if (", dollar(), "globalStepTrace) {printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__)}\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlStatement(car(tree), indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlBody(cdr(tree), indent);

  };

if (globalTrace)
    {printf("Leaving perlBody\n");}

}


//Building function perlDeclarations from line: 190

function perlDeclarations(decls,indent) {
  var decl = NULL;

if (globalTrace)
    {printf("perlDeclarations at q/perl.qon:190\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(decls)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    decl = car(decls);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("my %s%s = ", dollar(), stringify(second(decl)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    display(perlConstMap(third(decl)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(";\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlDeclarations(cdr(decls), indent);

  };

if (globalTrace)
    {printf("Leaving perlDeclarations\n");}

}


//Building function perlFunction from line: 201

function perlFunction(node) {
  var name = NULL;

if (globalTrace)
    {printf("perlFunction at q/perl.qon:201\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  name = subnameof(node);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\n\n#Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(0);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newLine(0);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("sub %s", stringify(subnameof(node)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(" {");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newLine(1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlFunctionArgs(cdr(assoc("intype", cdr(node))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newLine(1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlDeclarations(declarationsof(node), 1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\nif (%sglobalTrace) { printf(\"%s at %s:%s\\n\") }\n", dollar(), stringify(subnameof(node)), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( inList(name, noStackTrace())) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlBody(childrenof(node), 1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( inList(name, noStackTrace())) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n}\n");

  };

if (globalTrace)
    {printf("Leaving perlFunction\n");}

}


//Building function perlForwardDeclaration from line: 233

function perlForwardDeclaration(node) {
  
if (globalTrace)
    {printf("perlForwardDeclaration at q/perl.qon:233\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\nsub %s", stringify(subnameof(node)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(";");

  };

if (globalTrace)
    {printf("Leaving perlForwardDeclaration\n");}

}


//Building function perlForwardDeclarations from line: 243

function perlForwardDeclarations(tree) {
  
if (globalTrace)
    {printf("perlForwardDeclarations at q/perl.qon:243\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlForwardDeclaration(car(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlForwardDeclarations(cdr(tree));

  };

if (globalTrace)
    {printf("Leaving perlForwardDeclarations\n");}

}


//Building function perlFunctions from line: 251

function perlFunctions(tree) {
  
if (globalTrace)
    {printf("perlFunctions at q/perl.qon:251\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlFunction(car(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlFunctions(cdr(tree));

  };

if (globalTrace)
    {printf("Leaving perlFunctions\n");}

}


//Building function dollar from line: 258

function dollar() {
  
if (globalTrace)
    {printf("dollar at q/perl.qon:258\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(character(36));

if (globalTrace)
    {printf("Leaving dollar\n");}

}


//Building function atSym from line: 261

function atSym() {
  
if (globalTrace)
    {printf("atSym at q/perl.qon:261\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(character(64));

if (globalTrace)
    {printf("Leaving atSym\n");}

}


//Building function perlIncludes from line: 265

function perlIncludes(nodes) {
  
if (globalTrace)
    {printf("perlIncludes at q/perl.qon:265\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s\n", "use strict;");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s", "my ", dollar(), "caller;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s", "my ", dollar(), "releaseMode;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s\n", "use Carp;");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  dollar();
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s\n", "use Carp::Always;");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s%s%s\n", "sub greaterthan { ", dollar(), "_[0] > ", dollar(), "_[1] };");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s\n", "sub qlog { warn ", "@", "_ };");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s%s%s\n", "sub mult { ", dollar(), "_[0] * ", dollar(), "_[1] };");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s%s%s\n", "sub multf { ", dollar(), "_[0] * ", dollar(), "_[1] };");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s%s%s\n", "sub greaterthanf { ", dollar(), "_[0] > ", dollar(), "_[1] };");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s%s%s\n", "sub equalString { ", dollar(), "_[0] eq ", dollar(), "_[1] };");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("sub read_file { my %sfile = shift; %sfile || die \"Empty file name!!!\"; open my %sfh, '<', %sfile or die; local %s/ = undef; my %scont = <%sfh>; close %sfh; return %scont; }; \n", dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar());
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("sub write_file {my %sfile = shift; my %sdata = shift; %sfile || die \"Empty file name!!!\"; open my %sfh, '>', %sfile or die; print %sfh %sdata; close %sfh; } \n", dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar());
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s%s%s\n", "sub stringConcatenate { ", dollar(), "_[0] . ", dollar(), "_[1]}");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s%s%s\n", "sub subtract { ", dollar(), "_[0] - ", dollar(), "_[1]}");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s%s%s\n", "sub subf { ", dollar(), "_[0] - ", dollar(), "_[1]}");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s%s%s\n", "sub andBool { ", dollar(), "_[0] && ", dollar(), "_[1]}");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s%s%s\n", "sub equal { ", dollar(), "_[0] == ", dollar(), "_[1]}");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s%s%s\n", "sub panic { carp ", atSym(), "_; die \"", atSym(), "_\"}");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("sub intToString { return %s_[0]}\n", dollar());
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("sub character { return chr(%s_[0])}\n", dollar());
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s%s%s%s%s%s%s\n", "sub getStringArray { my ", dollar(), "index = shift; my ", dollar(), "arr = shift; return ", dollar(), "arr->[", dollar(), "index]}");

if (globalTrace)
    {printf("Leaving perlIncludes\n");}

}


//Building function perlTypeDecl from line: 301

function perlTypeDecl(l) {
  
if (globalTrace)
    {printf("perlTypeDecl at q/perl.qon:301\n");}

if (globalTrace)
    {printf("Leaving perlTypeDecl\n");}

}


//Building function perlStructComponents from line: 306

function perlStructComponents(node) {
  
if (globalTrace)
    {printf("perlStructComponents at q/perl.qon:306\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlTypeDecl(car(node));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlStructComponents(cdr(node));

  };

if (globalTrace)
    {printf("Leaving perlStructComponents\n");}

}


//Building function perlStruct from line: 312

function perlStruct(node) {
  
if (globalTrace)
    {printf("perlStruct at q/perl.qon:312\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  perlStructComponents(cdr(car(node)));

if (globalTrace)
    {printf("Leaving perlStruct\n");}

}


//Building function perlTypeMap from line: 315

function perlTypeMap(aSym) {
  var symMap = NULL;

if (globalTrace)
    {printf("perlTypeMap at q/perl.qon:315\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( truthy(assoc(stringify(aSym), symMap))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cdr(assoc(stringify(aSym), symMap)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(aSym);

  };

if (globalTrace)
    {printf("Leaving perlTypeMap\n");}

}


//Building function perlConstMap from line: 327

function perlConstMap(aSym) {
  var symMap = NULL;

if (globalTrace)
    {printf("perlConstMap at q/perl.qon:327\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("symbol", boxType(aSym))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    symMap = alistCons(boxSymbol("false"), boxSymbol("0"), alistCons(boxSymbol("nil"), boxSymbol("undef"), NULL));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cdr(assocFail(stringify(aSym), symMap, aSym)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(aSym);

  };

if (globalTrace)
    {printf("Leaving perlConstMap\n");}

}


//Building function perlFuncMap from line: 337

function perlFuncMap(aSym) {
  var symMap = NULL;

if (globalTrace)
    {printf("perlFuncMap at q/perl.qon:337\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("symbol", boxType(aSym))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    symMap = alistCons(boxSymbol("sub"), boxSymbol("subtract"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("substr"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("length"), alistCons(boxSymbol("nil"), boxSymbol("undef"), NULL))))))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cdr(assocFail(stringify(aSym), symMap, aSym)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(aSym);

  };

if (globalTrace)
    {printf("Leaving perlFuncMap\n");}

}


//Building function perlType from line: 354

function perlType(node) {
  
if (globalTrace)
    {printf("perlType at q/perl.qon:354\n");}

if (globalTrace)
    {printf("Leaving perlType\n");}

}


//Building function perlTypes from line: 359

function perlTypes(nodes) {
  
if (globalTrace)
    {printf("perlTypes at q/perl.qon:359\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(nodes)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlType(car(nodes));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlTypes(cdr(nodes));

  };

if (globalTrace)
    {printf("Leaving perlTypes\n");}

}


//Building function perlFunctionArgs from line: 365

function perlFunctionArgs(tree) {
  
if (globalTrace)
    {printf("perlFunctionArgs at q/perl.qon:365\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s%s", "my ", dollar());
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    display(second(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(" = shift;\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    perlFunctionArgs(cddr(tree));

  };

if (globalTrace)
    {printf("Leaving perlFunctionArgs\n");}

}


//Building function perlCompile from line: 375

function perlCompile(filename) {
  var programStr = "";
var tree = NULL;
var program = NULL;

if (globalTrace)
    {printf("perlCompile at q/perl.qon:375\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  programStr = read_file(filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = readSexpr(programStr, filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  program = mergeIncludes(program);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  perlIncludes(cdr(assoc("includes", program)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  perlTypes(childrenof(cdr(assoc("types", program))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("use strict;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("use Carp;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("use Data::Dumper;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s", "my ", dollar(), "globalStackTrace = undef;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s", "my ", dollar(), "globalTrace = undef;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s", "my ", dollar(), "globalStepTrace = undef;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s", "my ", dollar(), "globalArgs = undef;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s", "my ", dollar(), "globalArgsCount = undef;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s\n", "my ", dollar(), "true = 1;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s", "my ", dollar(), "false = 0;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s", "my ", dollar(), "undef;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s", "\nsub isNil {\n    return !defined(", dollar(), "_[0]);\n}\n\n\n#Forward declarations\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  perlForwardDeclarations(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\n\n#End forward declarations\n\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  perlFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf(";\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s%s", dollar(), "globalArgs = [ 1, ", atSym(), "ARGV];");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s%s%s", dollar(), "globalArgsCount = scalar(", atSym(), "ARGV)+1;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("start();");

if (globalTrace)
    {printf("Leaving perlCompile\n");}

}


//Building function ansiFunctionArgs from line: 3

function ansiFunctionArgs(tree) {
  
if (globalTrace)
    {printf("ansiFunctionArgs at q/ansi.qon:3\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    display(ansiTypeMap(first(tree)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(" ");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    display(second(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(cddr(tree))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf(",");

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiFunctionArgs(cddr(tree));

  };

if (globalTrace)
    {printf("Leaving ansiFunctionArgs\n");}

}


//Building function ansiLeaf from line: 14

function ansiLeaf(thisNode,indent) {
  
if (globalTrace)
    {printf("ansiLeaf at q/ansi.qon:14\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  display(ansiFuncMap(codeof(thisNode)));

if (globalTrace)
    {printf("Leaving ansiLeaf\n");}

}


//Building function ansiStructGetterExpression from line: 17

function ansiStructGetterExpression(thisNode,indent) {
  
if (globalTrace)
    {printf("ansiStructGetterExpression at q/ansi.qon:17\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(boxString("structGetter"), subnameof(thisNode))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiGetStruct(thisNode, indent);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiLeaf(thisNode, indent);

  };

if (globalTrace)
    {printf("Leaving ansiStructGetterExpression\n");}

}


//Building function ansiExpression from line: 23

function ansiExpression(node,indent) {
  
if (globalTrace)
    {printf("ansiExpression at q/ansi.qon:23\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isLeaf(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    display(ansiFuncMap(codeof(node)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiSubExpression(node, indent);

  };

if (globalTrace)
    {printf("Leaving ansiExpression\n");}

}


//Building function ansiRecurList from line: 29

function ansiRecurList(expr,indent) {
  
if (globalTrace)
    {printf("ansiRecurList at q/ansi.qon:29\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(expr)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiExpression(car(expr), indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(cdr(expr))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf(", ");
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      ansiRecurList(cdr(expr), indent);

    };

  };

if (globalTrace)
    {printf("Leaving ansiRecurList\n");}

}


//Building function ansiSubExpression from line: 41

function ansiSubExpression(tree,indent) {
  var thing = NULL;

if (globalTrace)
    {printf("ansiSubExpression at q/ansi.qon:41\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNode(childrenof(tree))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      ansiSubExpression(childrenof(tree), indent);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( isLeaf(tree)) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        display(ansiFuncMap(codeof(tree)));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equal(1, listLength(childrenof(tree)))) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          display(codeof(car(childrenof(tree))));
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalBox(boxString("return"), codeof(car(childrenof(tree))))) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("");

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("()");

          };

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          thing = codeof(car(childrenof(tree)));
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalBox(boxSymbol("get-struct"), thing)) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("%s->%s", stringify(codeof(second(childrenof(tree)))), stringify(codeof(third(childrenof(tree)))));

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            if ( equalBox(boxSymbol("new"), thing)) {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf("malloc(sizeof(%s))", stringify(codeof(third(childrenof(tree)))));

            } else {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf("%s(", stringify(ansiFuncMap(codeof(car(childrenof(tree))))));
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              ansiRecurList(cdr(childrenof(tree)), indent);
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf(")");

            };

          };

        };

      };

    };

  };

if (globalTrace)
    {printf("Leaving ansiSubExpression\n");}

}


//Building function ansiIf from line: 81

function ansiIf(node,indent) {
  
if (globalTrace)
    {printf("ansiIf at q/ansi.qon:81\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("if ( ");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansiExpression(car(first(childrenof(node))), 0);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf(") {");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansiBody(second(childrenof(node)), add1(indent));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("} else {");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansiBody(third(childrenof(node)), add1(indent));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("}");

if (globalTrace)
    {printf("Leaving ansiIf\n");}

}


//Building function ansiSetStruct from line: 94

function ansiSetStruct(node,indent) {
  
if (globalTrace)
    {printf("ansiSetStruct at q/ansi.qon:94\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s->%s = ", stringify(first(codeof(node))), stringify(second(codeof(node))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansiExpression(childrenof(node), indent);

if (globalTrace)
    {printf("Leaving ansiSetStruct\n");}

}


//Building function ansiGetStruct from line: 103

function ansiGetStruct(node,indent) {
  
if (globalTrace)
    {printf("ansiGetStruct at q/ansi.qon:103\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s->%s", stringify(first(codeof(node))), stringify(second(codeof(node))));

if (globalTrace)
    {printf("Leaving ansiGetStruct\n");}

}


//Building function ansiSet from line: 111

function ansiSet(node,indent) {
  
if (globalTrace)
    {printf("ansiSet at q/ansi.qon:111\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s = ", stringify(first(codeof(node))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansiExpression(childrenof(node), indent);

if (globalTrace)
    {printf("Leaving ansiSet\n");}

}


//Building function ansiStatement from line: 117

function ansiStatement(node,indent) {
  
if (globalTrace)
    {printf("ansiStatement at q/ansi.qon:117\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(boxString("setter"), subnameof(node))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiSet(node, indent);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalBox(boxString("structSetter"), subnameof(node))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      ansiSetStruct(node, indent);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalBox(boxString("if"), subnameof(node))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        ansiIf(node, indent);

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalBox(boxString("returnvoid"), subnameof(node))) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          newLine(indent);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf("return");

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          newLine(indent);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          ansiExpression(childrenof(node), indent);

        };

      };

    };

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf(";\n");

if (globalTrace)
    {printf("Leaving ansiStatement\n");}

}


//Building function ansiBody from line: 135

function ansiBody(tree,indent) {
  var code = NULL;

if (globalTrace)
    {printf("ansiBody at q/ansi.qon:135\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    code = codeof(car(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(code)) {
    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      code = car(codeof(car(tree)));
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("\n");
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printIndent(indent);
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("if (globalTrace)   snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail(code, boxString("filename"), boxString("Unknown"))), stringify(getTagFail(code, boxString("line"), boxString("Unknown"))));

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiStatement(car(tree), indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiBody(cdr(tree), indent);

  };

if (globalTrace)
    {printf("Leaving ansiBody\n");}

}


//Building function ansiDeclarations from line: 156

function ansiDeclarations(decls,indent) {
  var decl = NULL;

if (globalTrace)
    {printf("ansiDeclarations at q/ansi.qon:156\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(decls)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    decl = car(decls);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s %s = ", stringify(ansiTypeMap(first(decl))), stringify(second(decl)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    display(ansiFuncMap(third(decl)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(";\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiDeclarations(cdr(decls), indent);

  };

if (globalTrace)
    {printf("Leaving ansiDeclarations\n");}

}


//Building function ansiFunction from line: 170

function ansiFunction(node) {
  var name = NULL;

if (globalTrace)
    {printf("ansiFunction at q/ansi.qon:170\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  name = subnameof(node);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(0);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newLine(0);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s %s(", stringify(ansiTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiFunctionArgs(cdr(assoc("intype", cdr(node))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(") {");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newLine(1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiDeclarations(declarationsof(node), 1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( inList(toStr(name), noStackTrace())) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("\nif (globalTrace)\n    fprintf(stderr, \"%s at %s:%s (%%s)\\n\", caller);\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( inList(toStr(name), noStackTrace())) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {
    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiBody(childrenof(node), 1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( inList(toStr(name), noStackTrace())) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("\nif (globalTrace)\n    fprintf(stderr, \"Leaving %s\\n\");\n", stringify(name));

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n}\n");

  };

if (globalTrace)
    {printf("Leaving ansiFunction\n");}

}


//Building function ansiForwardDeclaration from line: 204

function ansiForwardDeclaration(node) {
  
if (globalTrace)
    {printf("ansiForwardDeclaration at q/ansi.qon:204\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n%s %s(", stringify(ansiTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiFunctionArgs(cdr(assoc("intype", cdr(node))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(");");

  };

if (globalTrace)
    {printf("Leaving ansiForwardDeclaration\n");}

}


//Building function ansiForwardDeclarations from line: 216

function ansiForwardDeclarations(tree) {
  
if (globalTrace)
    {printf("ansiForwardDeclarations at q/ansi.qon:216\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiForwardDeclaration(car(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiForwardDeclarations(cdr(tree));

  };

if (globalTrace)
    {printf("Leaving ansiForwardDeclarations\n");}

}


//Building function ansiFunctions from line: 224

function ansiFunctions(tree) {
  
if (globalTrace)
    {printf("ansiFunctions at q/ansi.qon:224\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiFunction(car(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiFunctions(cdr(tree));

  };

if (globalTrace)
    {printf("Leaving ansiFunctions\n");}

}


//Building function ansiIncludes from line: 229

function ansiIncludes(nodes) {
  
if (globalTrace)
    {printf("ansiIncludes at q/ansi.qon:229\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\nconst char* getEnv(char* key){return getenv(key);}\n void panic(char* s){abort();exit(1);}\nint not(int a){return !a;}\nint sub(int a, int b) { return a - b; }\nfloat mult(int a, int b) { return a * b; }\nint greaterthan(int a, int b) { return a > b; }\nfloat subf(float a, float b) { return a - b; }\nfloat multf(float a, float b) { return a * b; }\nint greaterthanf(float a, float b) { return a > b; }\nint equal(int a, int b) { return a == b; }\nint equalString(char* a, char* b) { return !strcmp(a,b); }\nint andBool(int a, int b) { return a && b;}\nint string_length(char* s) { return strlen(s);}\nchar* setSubString(char* target, int start,char *source){target[start]=source[0]; return target;}\nchar* sub_string(char* s, int start, int length) {\nchar* substr = calloc(length+1, 1);\nstrncpy(substr, s+start, length);\nreturn substr;\n}\n\n\n\nchar* stringConcatenate(char* a, char* b) {\nint len = strlen(a) + strlen(b) + 1;\nchar* target = calloc(len,1);\nstrncat(target, a, len);\nstrncat(target, b, len);\nreturn target;\n}\n\nchar* intToString(int a) {\nint len = 100;\nchar* target = calloc(len,1);\nsnprintf(target, 99, \"%d\", a);\nreturn target;\n}\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\nvoid * gc_malloc( unsigned int size ) {\nreturn malloc(size);\n}\n\nint* makeArray(int length) {\n    int * array = gc_malloc(length*sizeof(int));\n    return array;\n}\n\nint at(int* arr, int index) {\n  return arr[index];\n}\n\nvoid setAt(int* array, int index, int value) {\n    array[index] = value;\n}\n\nchar * read_file(char * filename) {\nchar * buffer = 0;\nlong length;\nFILE * f = fopen (filename, \"rb\");\n\nif (f)\n{\n  fseek (f, 0, SEEK_END);\n  length = ftell (f);\n  fseek (f, 0, SEEK_SET);\n  buffer = calloc (length+1,1);\n  if (buffer == NULL) {\n  printf(\"Malloc failed!\\n\");\n  exit(1);\n}\n  if (buffer)\n  {\n    fread (buffer, 1, length, f);\n  }\n  fclose (f);\n}\nreturn buffer;\n}\n\n\nvoid write_file (char * filename, char * data) {\nFILE *f = fopen(filename, \"w\");\nif (f == NULL)\n{\n    printf(\"Error opening file!\");\n    exit(1);\n}\n\nfprintf(f, \"%s\", data);\n\nfclose(f);\n}\n\nchar* getStringArray(int index, char** strs) {\nreturn strs[index];\n}\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\n\nint main( int argc, char *argv[] )  {\n  globalArgs = argv;\n  globalArgsCount = argc;\n  caller=calloc(1024,1);\n\n  return start();\n\n}\n\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "char * character(int num) { char *string = malloc(2); if (!string) return 0; string[0] = num; string[1] = 0; return string; }");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "bool nand(bool a, bool b) { return !(a&&b); }\n//End include block\n");

if (globalTrace)
    {printf("Leaving ansiIncludes\n");}

}


//Building function ansiTypeDecl from line: 239

function ansiTypeDecl(l) {
  
if (globalTrace)
    {printf("ansiTypeDecl at q/ansi.qon:239\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(listLength(l), 2)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s %s %s;\n", stringify(second(l)), stringify(ansiTypeMap(listLast(l))), stringify(first(l)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s %s;\n", stringify(ansiTypeMap(listLast(l))), stringify(car(l)));

  };

if (globalTrace)
    {printf("Leaving ansiTypeDecl\n");}

}


//Building function ansiStructComponents from line: 256

function ansiStructComponents(node) {
  
if (globalTrace)
    {printf("ansiStructComponents at q/ansi.qon:256\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiTypeDecl(car(node));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiStructComponents(cdr(node));

  };

if (globalTrace)
    {printf("Leaving ansiStructComponents\n");}

}


//Building function ansiStruct from line: 262

function ansiStruct(node) {
  
if (globalTrace)
    {printf("ansiStruct at q/ansi.qon:262\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansiStructComponents(cdr(car(node)));

if (globalTrace)
    {printf("Leaving ansiStruct\n");}

}


//Building function ansiTypeMap from line: 265

function ansiTypeMap(aSym) {
  var symMap = NULL;

if (globalTrace)
    {printf("ansiTypeMap at q/ansi.qon:265\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( truthy(assoc(stringify(aSym), symMap))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cdr(assoc(stringify(aSym), symMap)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(aSym);

  };

if (globalTrace)
    {printf("Leaving ansiTypeMap\n");}

}


//Building function ansiFuncMap from line: 277

function ansiFuncMap(aSym) {
  var symMap = NULL;

if (globalTrace)
    {printf("ansiFuncMap at q/ansi.qon:277\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("symbol", boxType(aSym))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), NULL)))))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( truthy(assoc(stringify(aSym), symMap))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(cdr(assoc(stringify(aSym), symMap)));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(aSym);

    };

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(aSym);

  };

if (globalTrace)
    {printf("Leaving ansiFuncMap\n");}

}


//Building function ansiType from line: 308

function ansiType(node) {
  
if (globalTrace)
    {printf("ansiType at q/ansi.qon:308\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(subnameof(node), boxString("struct"))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\ntypedef struct %s {\n", stringify(first(codeof(node))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiStruct(cdr(codeof(node)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n} %s;\n", stringify(first(codeof(node))));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("typedef ");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiTypeDecl(codeof(node));

  };

if (globalTrace)
    {printf("Leaving ansiType\n");}

}


//Building function ansiTypes from line: 318

function ansiTypes(nodes) {
  
if (globalTrace)
    {printf("ansiTypes at q/ansi.qon:318\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(nodes)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiType(car(nodes));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansiTypes(cdr(nodes));

  };

if (globalTrace)
    {printf("Leaving ansiTypes\n");}

}


//Building function ansiCompile from line: 328

function ansiCompile(filename) {
  var programStr = "";
var tree = NULL;
var program = NULL;

if (globalTrace)
    {printf("ansiCompile at q/ansi.qon:328\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("//Scanning file...%s\n", filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  programStr = read_file(filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("//Building sexpr\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = readSexpr(programStr, filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrowalk(tree);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), NULL)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("//Building AST\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("//Merging ASTs\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  program = mergeIncludes(program);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("//Printing program\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansiIncludes(cdr(assoc("includes", program)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansiTypes(childrenof(cdr(assoc("types", program))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("Box* globalStackTrace = NULL;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansiForwardDeclarations(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\n\n//End forward declarations\n\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansiFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\n");

if (globalTrace)
    {printf("Leaving ansiCompile\n");}

}


//Building function ansi2displays from line: 5

function ansi2displays(s) {
  
if (globalTrace)
    {printf("ansi2displays at q/ansi2.qon:5\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", s);

if (globalTrace)
    {printf("Leaving ansi2displays\n");}

}


//Building function ansi2FunctionArgs from line: 11

function ansi2FunctionArgs(tree) {
  
if (globalTrace)
    {printf("ansi2FunctionArgs at q/ansi2.qon:11\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalString(stringify(first(tree)), "...")) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("...");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      display(ansi2TypeMap(first(tree)));
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      ansi2displays(" ");
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      display(second(tree));

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(cddr(tree))) {
    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      ansi2displays(", ");

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2FunctionArgs(cddr(tree));

  };

if (globalTrace)
    {printf("Leaving ansi2FunctionArgs\n");}

}


//Building function ansi2Expression from line: 28

function ansi2Expression(tree,indent) {
  var thing = NULL;

if (globalTrace)
    {printf("ansi2Expression at q/ansi2.qon:28\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isList(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equal(1, listLength(tree))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      display(car(tree));
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalBox(boxString("return"), car(tree))) {
      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        ansi2displays("()");

      };

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      thing = first(tree);
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalBox(boxSymbol("get-struct"), thing)) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printf("%s->%s", stringify(second(tree)), stringify(third(tree)));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalBox(boxSymbol("new"), thing)) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf("malloc(sizeof(%s))", stringify(third(tree)));

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalBox(boxSymbol("passthrough"), thing)) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("%s", stringify(second(tree)));

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            if ( equalBox(boxSymbol("binop"), thing)) {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf("(");
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              ansi2Expression(third(tree), indent);
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf(" %s ", stringify(second(tree)));
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              ansi2Expression(fourth(tree), indent);
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf(")");

            } else {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf("%s(", stringify(ansi2FuncMap(car(tree))));
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              ansi2RecurList(cdr(tree), indent);
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf(")");

            };

          };

        };

      };

    };

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    display(ansi2FuncMap(tree));

  };

if (globalTrace)
    {printf("Leaving ansi2Expression\n");}

}


//Building function ansi2RecurList from line: 98

function ansi2RecurList(expr,indent) {
  
if (globalTrace)
    {printf("ansi2RecurList at q/ansi2.qon:98\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(expr)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2Expression(car(expr), indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(cdr(expr))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      ansi2displays("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      ansi2displays(", ");
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      ansi2RecurList(cdr(expr), indent);

    };

  };

if (globalTrace)
    {printf("Leaving ansi2RecurList\n");}

}


//Building function ansi2If from line: 115

function ansi2If(node,indent) {
  
if (globalTrace)
    {printf("ansi2If at q/ansi2.qon:115\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi2displays("if ( ");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi2Expression(second(node), 0);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi2displays(") {");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi2Body(cdr(third(node)), add1(indent));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi2displays("} else {");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi2Body(cdr(fourth(node)), add1(indent));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi2displays("}");

if (globalTrace)
    {printf("Leaving ansi2If\n");}

}


//Building function ansi2SetStruct from line: 128

function ansi2SetStruct(node,indent) {
  
if (globalTrace)
    {printf("ansi2SetStruct at q/ansi2.qon:128\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s->%s = ", stringify(second(node)), stringify(third(node)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi2Expression(fourth(node), indent);

if (globalTrace)
    {printf("Leaving ansi2SetStruct\n");}

}


//Building function ansi2GetStruct from line: 137

function ansi2GetStruct(node,indent) {
  
if (globalTrace)
    {printf("ansi2GetStruct at q/ansi2.qon:137\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s->%s", stringify(first(node)), stringify(second(node)));

if (globalTrace)
    {printf("Leaving ansi2GetStruct\n");}

}


//Building function ansi2Set from line: 145

function ansi2Set(node,indent) {
  
if (globalTrace)
    {printf("ansi2Set at q/ansi2.qon:145\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi2Expression(first(cdr(node)), indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf(" = ");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi2Expression(third(node), indent);

if (globalTrace)
    {printf("Leaving ansi2Set\n");}

}


//Building function ansi2Return from line: 152

function ansi2Return(node,indent) {
  
if (globalTrace)
    {printf("ansi2Return at q/ansi2.qon:152\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equal(listLength(node), 1)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2displays("return;");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2displays("return ");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2Expression(cadr(node), indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2displays(";");

  };

if (globalTrace)
    {printf("Leaving ansi2Return\n");}

}


//Building function ansi2Statement from line: 163

function ansi2Statement(node,indent) {
  
if (globalTrace)
    {printf("ansi2Statement at q/ansi2.qon:163\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(boxString("set"), first(node))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2Set(node, indent);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalBox(boxString("set-struct"), first(node))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      ansi2SetStruct(node, indent);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalBox(boxString("if"), first(node))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        ansi2If(node, indent);

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalBox(boxString("return"), first(node))) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          ansi2Return(node, indent);

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          newLine(indent);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          ansi2Expression(node, indent);

        };

      };

    };

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi2displays(";\n");

if (globalTrace)
    {printf("Leaving ansi2Statement\n");}

}


//Building function ansi2Body from line: 181

function ansi2Body(tree,indent) {
  var code = NULL;

if (globalTrace)
    {printf("ansi2Body at q/ansi2.qon:181\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    code = tree;
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(code)) {
    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      code = car(tree);
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("\nif (globalTrace)\n    snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), stringify(getTagFail(car(code), boxString("line"), boxString("Line missing"))));

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2Statement(code, indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2Body(cdr(tree), indent);

  };

if (globalTrace)
    {printf("Leaving ansi2Body\n");}

}


//Building function ansi2Declarations from line: 199

function ansi2Declarations(decls,indent) {
  var decl = NULL;

if (globalTrace)
    {printf("ansi2Declarations at q/ansi2.qon:199\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(decls)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    decl = car(decls);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s %s = ", stringify(ansi2TypeMap(first(decl))), stringify(second(decl)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2Expression(third(decl), indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(";\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2Declarations(cdr(decls), indent);

  };

if (globalTrace)
    {printf("Leaving ansi2Declarations\n");}

}


//Building function ansi2Function from line: 213

function ansi2Function(node) {
  var name = NULL;

if (globalTrace)
    {printf("ansi2Function at q/ansi2.qon:213\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  name = second(node);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(0);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newLine(0);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s %s(", stringify(ansi2TypeMap(first(node))), stringify(second(node)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2FunctionArgs(third(node));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(") {");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newLine(1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2Declarations(cdr(fourth(node)), 1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( inList(toStr(name), noStackTrace())) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("\nif (globalTrace)\n    printf(\"%s at %s:%s (%%s)\\n\", caller);\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( inList(toStr(name), noStackTrace())) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {
    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2Body(cdr(fifth(node)), 1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( inList(toStr(name), noStackTrace())) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("\nif (globalTrace)\n    printf(\"Leaving %s\\n\");\n", stringify(name));

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n}\n");

  };

if (globalTrace)
    {printf("Leaving ansi2Function\n");}

}


//Building function ansi2ForwardDeclaration from line: 248

function ansi2ForwardDeclaration(node) {
  
if (globalTrace)
    {printf("ansi2ForwardDeclaration at q/ansi2.qon:248\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n%s %s(", stringify(ansi2TypeMap(first(node))), stringify(second(node)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2FunctionArgs(third(node));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2displays(");");

  };

if (globalTrace)
    {printf("Leaving ansi2ForwardDeclaration\n");}

}


//Building function ansi2ForwardDeclarations from line: 258

function ansi2ForwardDeclarations(tree) {
  
if (globalTrace)
    {printf("ansi2ForwardDeclarations at q/ansi2.qon:258\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2ForwardDeclaration(car(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2ForwardDeclarations(cdr(tree));

  };

if (globalTrace)
    {printf("Leaving ansi2ForwardDeclarations\n");}

}


//Building function ansi2Functions from line: 264

function ansi2Functions(tree) {
  
if (globalTrace)
    {printf("ansi2Functions at q/ansi2.qon:264\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2Function(car(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2Functions(cdr(tree));

  };

if (globalTrace)
    {printf("Leaving ansi2Functions\n");}

}


//Building function ansi2Includes from line: 270

function ansi2Includes(nodes) {
  
if (globalTrace)
    {printf("ansi2Includes at q/ansi2.qon:270\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\nconst char* getEnv(char* key){return getenv(key);}\n void panic(char* s){abort();exit(1);}\nint sub(int a, int b) { return a - b; }\nfloat mult(int a, int b) { return a * b; }\nint greaterthan(int a, int b) { return a > b; }\nfloat subf(float a, float b) { return a - b; }\nfloat multf(float a, float b) { return a * b; }\nint greaterthanf(float a, float b) { return a > b; }\nint equal(int a, int b) { return a == b; }\nint equalString(char* a, char* b) { return !strcmp(a,b); }\nint andBool(int a, int b) { return a && b;}\nint string_length(char* s) { return strlen(s);}\nchar* setSubString(char* target, int start,char *source){target[start]=source[0]; return target;}\nchar* sub_string(char* s, int start, int length) {\nchar* substr = calloc(length+1, 1);\nstrncpy(substr, s+start, length);\nreturn substr;\n}\n\n\n\nchar* stringConcatenate(char* a, char* b) {\nint len = strlen(a) + strlen(b) + 1;\nchar* target = calloc(len,1);\nstrncat(target, a, len);\nstrncat(target, b, len);\nreturn target;\n}\n\nchar* intToString(int a) {\nint len = 100;\nchar* target = calloc(len,1);\nsnprintf(target, 99, \"%d\", a);\nreturn target;\n}\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\nvoid * gc_malloc( unsigned int size ) {\nreturn malloc( size);\n}\n\nint* makeArray(int length) {\n    int * array = gc_malloc(length*sizeof(int));\n    return array;\n}\n\nint at(int* arr, int index) {\n  return arr[index];\n}\n\nvoid setAt(int* array, int index, int value) {\n    array[index] = value;\n}\n\nchar * read_file(char * filename) {\nchar * buffer = 0;\nlong length;\nFILE * f = fopen (filename, \"rb\");\n\nif (f)\n{\n  fseek (f, 0, SEEK_END);\n  length = ftell (f);\n  fseek (f, 0, SEEK_SET);\n  buffer = calloc (length+1,1);\n  if (buffer == NULL) {\n  printf(\"Malloc failed!\\n\");\n  exit(1);\n}\n  if (buffer)\n  {\n    fread (buffer, 1, length, f);\n  }\n  fclose (f);\n}\nreturn buffer;\n}\n\n\nvoid write_file (char * filename, char * data) {\nFILE *f = fopen(filename, \"w\");\nif (f == NULL)\n{\n    printf(\"Error opening file!\");\n    exit(1);\n}\n\nfprintf(f, \"%s\", data);\n\nfclose(f);\n}\n\nchar* getStringArray(int index, char** strs) {\nreturn strs[index];\n}\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\n\nint main( int argc, char *argv[] )  {\n  globalArgs = argv;\n  globalArgsCount = argc;\n  caller=calloc(1024,1);\n\n  return start();\n\n}\n\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "char * character(int num) { char *string = malloc(2); if (!string) return 0; string[0] = num; string[1] = 0; return string; }");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "bool nand(bool a, bool b) { return !(a&&b); }\n//End include block\n");

if (globalTrace)
    {printf("Leaving ansi2Includes\n");}

}


//Building function ansi2TypeDecl from line: 279

function ansi2TypeDecl(l) {
  
if (globalTrace)
    {printf("ansi2TypeDecl at q/ansi2.qon:279\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(listLength(l), 2)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s %s %s;\n", stringify(second(l)), stringify(ansi2TypeMap(listLast(l))), stringify(first(l)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s %s;\n", stringify(ansi2TypeMap(listLast(l))), stringify(car(l)));

  };

if (globalTrace)
    {printf("Leaving ansi2TypeDecl\n");}

}


//Building function ansi2StructComponents from line: 296

function ansi2StructComponents(node) {
  
if (globalTrace)
    {printf("ansi2StructComponents at q/ansi2.qon:296\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2TypeDecl(car(node));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2StructComponents(cdr(node));

  };

if (globalTrace)
    {printf("Leaving ansi2StructComponents\n");}

}


//Building function ansi2Struct from line: 302

function ansi2Struct(node) {
  
if (globalTrace)
    {printf("ansi2Struct at q/ansi2.qon:302\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi2StructComponents(cdr(node));

if (globalTrace)
    {printf("Leaving ansi2Struct\n");}

}


//Building function ansi2TypeMap from line: 305

function ansi2TypeMap(aSym) {
  var symMap = NULL;

if (globalTrace)
    {printf("ansi2TypeMap at q/ansi2.qon:305\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( truthy(assoc(stringify(aSym), symMap))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cdr(assoc(stringify(aSym), symMap)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(aSym);

  };

if (globalTrace)
    {printf("Leaving ansi2TypeMap\n");}

}


//Building function ansi2FuncMap from line: 317

function ansi2FuncMap(aSym) {
  var symMap = NULL;

if (globalTrace)
    {printf("ansi2FuncMap at q/ansi2.qon:317\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("symbol", boxType(aSym))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), NULL)))))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( truthy(assoc(stringify(aSym), symMap))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(cdr(assoc(stringify(aSym), symMap)));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(aSym);

    };

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(aSym);

  };

if (globalTrace)
    {printf("Leaving ansi2FuncMap\n");}

}


//Building function ansi2Type from line: 348

function ansi2Type(node) {
  
if (globalTrace)
    {printf("ansi2Type at q/ansi2.qon:348\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isList(second(node))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\ntypedef struct %s {\n", stringify(first(node)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2Struct(second(node));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n} %s;\n", stringify(first(node)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2displays("typedef ");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2TypeDecl(node);

  };

if (globalTrace)
    {printf("Leaving ansi2Type\n");}

}


//Building function ansi2Types from line: 358

function ansi2Types(nodes) {
  
if (globalTrace)
    {printf("ansi2Types at q/ansi2.qon:358\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(nodes)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2Type(car(nodes));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi2Types(cdr(nodes));

  };

if (globalTrace)
    {printf("Leaving ansi2Types\n");}

}


//Building function ansi2Compile from line: 368

function ansi2Compile(filename) {
  var tree = NULL;
var replace = NULL;

if (globalTrace)
    {printf("ansi2Compile at q/ansi2.qon:368\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  qlog("//Scanning file...%s\n", filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = loadQuon(filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  qlog("//Building sexpr\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = loadIncludes(tree);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrowalk(tree);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  qlog("//Printing program\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi2Includes(cdr(first(tree)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi2Types(cdr(second(tree)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi2displays("Box* globalStackTrace = NULL;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi2displays("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi2ForwardDeclarations(cdr(third(tree)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi2displays("\n\n//End forward declarations\n\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi2Functions(cdr(third(tree)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi2displays("\n");

if (globalTrace)
    {printf("Leaving ansi2Compile\n");}

}


//Building function ansi3displays from line: 5

function ansi3displays(s) {
  
if (globalTrace)
    {printf("ansi3displays at q/ansi3.qon:5\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", s);

if (globalTrace)
    {printf("Leaving ansi3displays\n");}

}


//Building function ansi3FunctionArgs from line: 11

function ansi3FunctionArgs(tree) {
  
if (globalTrace)
    {printf("ansi3FunctionArgs at q/ansi3.qon:11\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalString(stringify(first(tree)), "...")) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("...");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      display(ansi3TypeMap(first(tree)));
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      ansi3displays(" ");
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      display(second(tree));

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(cddr(tree))) {
    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      ansi3displays(", ");

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3FunctionArgs(cddr(tree));

  };

if (globalTrace)
    {printf("Leaving ansi3FunctionArgs\n");}

}


//Building function ansi3Expression from line: 28

function ansi3Expression(tree,indent) {
  var thing = NULL;

if (globalTrace)
    {printf("ansi3Expression at q/ansi3.qon:28\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isList(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equal(1, listLength(tree))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      display(car(tree));
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalBox(boxString("return"), car(tree))) {
      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        ansi3displays("()");

      };

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      thing = first(tree);
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalBox(boxSymbol("get-struct"), thing)) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printf("%s->%s", stringify(second(tree)), stringify(third(tree)));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalBox(boxSymbol("new"), thing)) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf("malloc(sizeof(%s))", stringify(third(tree)));

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalBox(boxSymbol("passthrough"), thing)) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("%s", stringify(second(tree)));

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            if ( equalBox(boxSymbol("binop"), thing)) {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf("(");
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              ansi3Expression(third(tree), indent);
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf(" %s ", stringify(second(tree)));
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              ansi3Expression(fourth(tree), indent);
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf(")");

            } else {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf("%s(", stringify(ansi3FuncMap(car(tree))));
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              ansi3RecurList(cdr(tree), indent);
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf(")");

            };

          };

        };

      };

    };

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    display(ansi3FuncMap(tree));

  };

if (globalTrace)
    {printf("Leaving ansi3Expression\n");}

}


//Building function ansi3RecurList from line: 98

function ansi3RecurList(expr,indent) {
  
if (globalTrace)
    {printf("ansi3RecurList at q/ansi3.qon:98\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(expr)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3Expression(car(expr), indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(cdr(expr))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      ansi3displays("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      ansi3displays(", ");
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      ansi3RecurList(cdr(expr), indent);

    };

  };

if (globalTrace)
    {printf("Leaving ansi3RecurList\n");}

}


//Building function ansi3If from line: 115

function ansi3If(node,indent) {
  
if (globalTrace)
    {printf("ansi3If at q/ansi3.qon:115\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi3displays("if ( ");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi3Expression(second(node), 0);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi3displays(") {");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi3Body(cdr(third(node)), add1(indent));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi3displays("} else {");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi3Body(cdr(fourth(node)), add1(indent));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi3displays("}");

if (globalTrace)
    {printf("Leaving ansi3If\n");}

}


//Building function ansi3SetStruct from line: 128

function ansi3SetStruct(node,indent) {
  
if (globalTrace)
    {printf("ansi3SetStruct at q/ansi3.qon:128\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s->%s = ", stringify(second(node)), stringify(third(node)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi3Expression(fourth(node), indent);

if (globalTrace)
    {printf("Leaving ansi3SetStruct\n");}

}


//Building function ansi3GetStruct from line: 137

function ansi3GetStruct(node,indent) {
  
if (globalTrace)
    {printf("ansi3GetStruct at q/ansi3.qon:137\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s->%s", stringify(first(node)), stringify(second(node)));

if (globalTrace)
    {printf("Leaving ansi3GetStruct\n");}

}


//Building function ansi3Set from line: 145

function ansi3Set(node,indent) {
  
if (globalTrace)
    {printf("ansi3Set at q/ansi3.qon:145\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi3Expression(first(cdr(node)), indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf(" = ");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi3Expression(third(node), indent);

if (globalTrace)
    {printf("Leaving ansi3Set\n");}

}


//Building function ansi3Return from line: 152

function ansi3Return(node,indent) {
  
if (globalTrace)
    {printf("ansi3Return at q/ansi3.qon:152\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equal(listLength(node), 1)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3displays("return;");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3displays("return ");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3Expression(cadr(node), indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3displays(";");

  };

if (globalTrace)
    {printf("Leaving ansi3Return\n");}

}


//Building function ansi3Statement from line: 163

function ansi3Statement(node,indent) {
  
if (globalTrace)
    {printf("ansi3Statement at q/ansi3.qon:163\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(boxString("set"), first(node))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3Set(node, indent);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalBox(boxString("set-struct"), first(node))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      ansi3SetStruct(node, indent);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalBox(boxString("if"), first(node))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        ansi3If(node, indent);

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalBox(boxString("return"), first(node))) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          ansi3Return(node, indent);

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          newLine(indent);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          ansi3Expression(node, indent);

        };

      };

    };

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi3displays(";\n");

if (globalTrace)
    {printf("Leaving ansi3Statement\n");}

}


//Building function ansi3Body from line: 181

function ansi3Body(tree,indent) {
  var code = NULL;

if (globalTrace)
    {printf("ansi3Body at q/ansi3.qon:181\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    code = tree;
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(code)) {
    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      code = car(tree);
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( not(releaseMode)) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printf("\nif (globalTrace)\n    snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), stringify(getTagFail(car(code), boxString("line"), boxString("Line missing"))));

      } else {
      };

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( not(releaseMode)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printIndent(indent);
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n");

    } else {
    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3Statement(code, indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3Body(cdr(tree), indent);

  };

if (globalTrace)
    {printf("Leaving ansi3Body\n");}

}


//Building function ansi3Declarations from line: 206

function ansi3Declarations(decls,indent) {
  var decl = NULL;

if (globalTrace)
    {printf("ansi3Declarations at q/ansi3.qon:206\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(decls)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    decl = car(decls);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s %s = ", stringify(ansi3TypeMap(first(decl))), stringify(second(decl)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3Expression(third(decl), indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(";\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3Declarations(cdr(decls), indent);

  };

if (globalTrace)
    {printf("Leaving ansi3Declarations\n");}

}


//Building function ansi3Function from line: 220

function ansi3Function(node) {
  var name = NULL;

if (globalTrace)
    {printf("ansi3Function at q/ansi3.qon:220\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  name = second(node);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(0);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newLine(0);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s %s(", stringify(ansi3TypeMap(first(node))), stringify(second(node)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3FunctionArgs(third(node));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(") {");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newLine(1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3Declarations(cdr(fourth(node)), 1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( releaseMode) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("\nif (globalTrace)\n    printf(\"%s at %s:%s (%%s)\\n\", caller);\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( releaseMode) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {
    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3Body(cdr(fifth(node)), 1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( releaseMode) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("\nif (globalTrace)\n    printf(\"Leaving %s\\n\");\n", stringify(name));

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n}\n");

  };

if (globalTrace)
    {printf("Leaving ansi3Function\n");}

}


//Building function ansi3ForwardDeclaration from line: 255

function ansi3ForwardDeclaration(node) {
  
if (globalTrace)
    {printf("ansi3ForwardDeclaration at q/ansi3.qon:255\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n%s %s(", stringify(ansi3TypeMap(first(node))), stringify(second(node)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3FunctionArgs(third(node));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3displays(");");

  };

if (globalTrace)
    {printf("Leaving ansi3ForwardDeclaration\n");}

}


//Building function ansi3ForwardDeclarations from line: 265

function ansi3ForwardDeclarations(tree) {
  
if (globalTrace)
    {printf("ansi3ForwardDeclarations at q/ansi3.qon:265\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3ForwardDeclaration(car(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3ForwardDeclarations(cdr(tree));

  };

if (globalTrace)
    {printf("Leaving ansi3ForwardDeclarations\n");}

}


//Building function ansi3Functions from line: 271

function ansi3Functions(tree) {
  
if (globalTrace)
    {printf("ansi3Functions at q/ansi3.qon:271\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3Function(car(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3Functions(cdr(tree));

  };

if (globalTrace)
    {printf("Leaving ansi3Functions\n");}

}


//Building function ansi3Includes from line: 277

function ansi3Includes(nodes) {
  
if (globalTrace)
    {printf("ansi3Includes at q/ansi3.qon:277\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\n#include <unistd.h>\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\nbool releaseMode = false;\n\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n");

if (globalTrace)
    {printf("Leaving ansi3Includes\n");}

}


//Building function ansi3TypeDecl from line: 285

function ansi3TypeDecl(l) {
  
if (globalTrace)
    {printf("ansi3TypeDecl at q/ansi3.qon:285\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(listLength(l), 2)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s %s %s;\n", stringify(second(l)), stringify(ansi3TypeMap(listLast(l))), stringify(first(l)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s %s;\n", stringify(ansi3TypeMap(listLast(l))), stringify(car(l)));

  };

if (globalTrace)
    {printf("Leaving ansi3TypeDecl\n");}

}


//Building function ansi3StructComponents from line: 302

function ansi3StructComponents(node) {
  
if (globalTrace)
    {printf("ansi3StructComponents at q/ansi3.qon:302\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3TypeDecl(car(node));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3StructComponents(cdr(node));

  };

if (globalTrace)
    {printf("Leaving ansi3StructComponents\n");}

}


//Building function ansi3Struct from line: 308

function ansi3Struct(node) {
  
if (globalTrace)
    {printf("ansi3Struct at q/ansi3.qon:308\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi3StructComponents(cdr(node));

if (globalTrace)
    {printf("Leaving ansi3Struct\n");}

}


//Building function ansi3TypeMap from line: 311

function ansi3TypeMap(aSym) {
  var symMap = NULL;

if (globalTrace)
    {printf("ansi3TypeMap at q/ansi3.qon:311\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( truthy(assoc(stringify(aSym), symMap))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cdr(assoc(stringify(aSym), symMap)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(aSym);

  };

if (globalTrace)
    {printf("Leaving ansi3TypeMap\n");}

}


//Building function ansi3FuncMap from line: 321

function ansi3FuncMap(aSym) {
  var symMap = NULL;

if (globalTrace)
    {printf("ansi3FuncMap at q/ansi3.qon:321\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("symbol", boxType(aSym))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), NULL)))))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( truthy(assoc(stringify(aSym), symMap))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(cdr(assoc(stringify(aSym), symMap)));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(aSym);

    };

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(aSym);

  };

if (globalTrace)
    {printf("Leaving ansi3FuncMap\n");}

}


//Building function ansi3Type from line: 352

function ansi3Type(node) {
  
if (globalTrace)
    {printf("ansi3Type at q/ansi3.qon:352\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isList(second(node))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\ntypedef struct %s {\n", stringify(first(node)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3Struct(second(node));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n} %s;\n", stringify(first(node)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3displays("typedef ");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3TypeDecl(node);

  };

if (globalTrace)
    {printf("Leaving ansi3Type\n");}

}


//Building function ansi3Types from line: 362

function ansi3Types(nodes) {
  
if (globalTrace)
    {printf("ansi3Types at q/ansi3.qon:362\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(nodes)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3Type(car(nodes));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    ansi3Types(cdr(nodes));

  };

if (globalTrace)
    {printf("Leaving ansi3Types\n");}

}


//Building function ansi3Compile from line: 372

function ansi3Compile(filename) {
  var tree = NULL;
var replace = NULL;

if (globalTrace)
    {printf("ansi3Compile at q/ansi3.qon:372\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  qlog("//Scanning file...%s\n", filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = loadQuon(filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  qlog("//Building sexpr\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  qlog("Loading shim ansi3\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = buildProg(cons(boxString("q/shims/ansi3.qon"), getIncludes(tree)), getTypes(tree), getFunctions(tree));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  qlog("Loading all includes\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = loadIncludes(tree);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  qlog("Applying macros\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrowalk(tree);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  qlog("//Printing program\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi3Includes(cdr(first(tree)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi3Types(cdr(second(tree)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi3displays("Box* globalStackTrace = NULL;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi3displays("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi3ForwardDeclarations(cdr(third(tree)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi3displays("\n\n//End forward declarations\n\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi3Functions(cdr(third(tree)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  ansi3displays("\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  qlog("//Done printing program\n");

if (globalTrace)
    {printf("Leaving ansi3Compile\n");}

}


//Building function test0 from line: 7

function test0() {
  
if (globalTrace)
    {printf("test0 at q/tests.qon:7\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString(stringify(boxString("hello")), stringify(boxString("hello")))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("0.  pass string compare works\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("0.  pass string compare fails\n");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString(stringify(boxString("hello")), stringify(boxSymbol("hello")))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("0.  pass string compare works\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("0.  pass string compare fails\n");

  };

if (globalTrace)
    {printf("Leaving test0\n");}

}


//Building function test1 from line: 20

function test1() {
  
if (globalTrace)
    {printf("test1 at q/tests.qon:20\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("1.  pass Function call and print work\n");

if (globalTrace)
    {printf("Leaving test1\n");}

}


//Building function test2_do from line: 24

function test2_do(message) {
  
if (globalTrace)
    {printf("test2_do at q/tests.qon:24\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("2.  pass Function call with arg works: %s\n", message);

if (globalTrace)
    {printf("Leaving test2_do\n");}

}


//Building function test2 from line: 28

function test2() {
  
if (globalTrace)
    {printf("test2 at q/tests.qon:28\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  test2_do("This is the argument");

if (globalTrace)
    {printf("Leaving test2\n");}

}


//Building function test3_do from line: 30

function test3_do(b,c) {
  
if (globalTrace)
    {printf("test3_do at q/tests.qon:30\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("3.1 pass Two arg call, first arg: %d\n", b);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("3.2 pass Two arg call, second arg: %s\n", c);

if (globalTrace)
    {printf("Leaving test3_do\n");}

}


//Building function test3 from line: 36

function test3() {
  
if (globalTrace)
    {printf("test3 at q/tests.qon:36\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  test3_do(42, "Fourty-two");

if (globalTrace)
    {printf("Leaving test3\n");}

}


//Building function test4_do from line: 37

function test4_do() {
  
if (globalTrace)
    {printf("test4_do at q/tests.qon:37\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return("pass Return works");

if (globalTrace)
    {printf("Leaving test4_do\n");}

}


//Building function returnThis from line: 39

function returnThis(returnMessage) {
  
if (globalTrace)
    {printf("returnThis at q/tests.qon:39\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(returnMessage);

if (globalTrace)
    {printf("Leaving returnThis\n");}

}


//Building function test4 from line: 42

function test4() {
  var message = "fail";

if (globalTrace)
    {printf("test4 at q/tests.qon:42\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  message = test4_do();
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("4.  %s\n", message);

if (globalTrace)
    {printf("Leaving test4\n");}

}


//Building function test5 from line: 45

function test5() {
  var message = "fail";

if (globalTrace)
    {printf("test5 at q/tests.qon:45\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  message = returnThis("pass return passthrough string");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("5.  %s\n", message);

if (globalTrace)
    {printf("Leaving test5\n");}

}


//Building function test6 from line: 50

function test6() {
  
if (globalTrace)
    {printf("test6 at q/tests.qon:50\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( true) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("6.  pass If statement works\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("6.  fail If statement works\n");

  };

if (globalTrace)
    {printf("Leaving test6\n");}

}


//Building function test7_do from line: 58

function test7_do(count) {
  
if (globalTrace)
    {printf("test7_do at q/tests.qon:58\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  count = sub(count, 1);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(count, 0)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    count = test7_do(count);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(count);

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(count);

if (globalTrace)
    {printf("Leaving test7_do\n");}

}


//Building function test7 from line: 66

function test7() {
  
if (globalTrace)
    {printf("test7 at q/tests.qon:66\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equal(0, test7_do(10))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("7.  pass count works\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("7.  fail count fails\n");

  };

if (globalTrace)
    {printf("Leaving test7\n");}

}


//Building function beer from line: 74

function beer() {
  
if (globalTrace)
    {printf("beer at q/tests.qon:74\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%d bottle of beer on the wall, %d bottle of beer.  Take one down, pass it round, no bottles of beer on the wall\n", 1, 1);

if (globalTrace)
    {printf("Leaving beer\n");}

}


//Building function plural from line: 83

function plural(num) {
  
if (globalTrace)
    {printf("plural at q/tests.qon:83\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equal(num, 1)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return("");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return("s");

  };

if (globalTrace)
    {printf("Leaving plural\n");}

}


//Building function beers from line: 88

function beers(count) {
  var newcount = 0;

if (globalTrace)
    {printf("beers at q/tests.qon:88\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newcount = sub(count, 1);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%d bottle%s of beer on the wall, %d bottle%s of beer.  Take one down, pass it round, %d bottle%s of beer on the wall\n", count, plural(count), count, plural(count), newcount, plural(newcount));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(count, 1)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    count = beers(newcount);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(count);

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(0);

if (globalTrace)
    {printf("Leaving beers\n");}

}


//Building function test8 from line: 104

function test8() {
  
if (globalTrace)
    {printf("test8 at q/tests.qon:104\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equal(sub(sub(2, 1), sub(3, 1)), -1)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("8.  pass Nested expressions work\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("8.  fail Nested expressions don't work\n");

  };

if (globalTrace)
    {printf("Leaving test8\n");}

}


//Building function test9 from line: 112

function test9() {
  var answer = -999999;
var a = 2;
var b = 3;

if (globalTrace)
    {printf("test9 at q/tests.qon:112\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  answer = sub(sub(20, 1), sub(3, 1));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equal(answer, 17)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.1  pass sub works\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.1  fail sub\n");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  answer = add(2, 3);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equal(answer, 5)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.2  pass add works\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.2  fail add\n");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  answer = mult(a, b);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equal(answer, 6)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.3  pass mult works\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.3  fail mult\n");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(2, 1)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.4  pass greaterthan works\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.4  fail greaterthan\n");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equal(1, 1)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.5  pass integer equal works\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.5  fail integer equal\n");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("hello", "hello")) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.6  pass string equal works\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.6  fail string equal\n");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("hello", "world")) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.7  fail string equal\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.7  pass string equal\n");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( andBool(false, false)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.8  fail andBool\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.8  pass andBool works\n");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( andBool(true, true)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.9  pass andBool works\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.9  fail andBool\n");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( andBool(true, false)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.10  fail andBool\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.10  pass andBool works\n");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("hello", "hello")) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.11  pass string equal\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.11  fail string equal\n");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("!", character(33))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.12  pass character\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.12  fail character\n");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("33", intToString(33))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.13  pass intToString\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.13  fail intToString\n");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("llo", sub_string("hello", a, b))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.14  pass sub-string\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("9.14  fail sub-string: %s\n", sub_string("hello", a, b));

  };

if (globalTrace)
    {printf("Leaving test9\n");}

}


//Building function test10 from line: 170

function test10() {
  var testString = "This is a test string";

if (globalTrace)
    {printf("test10 at q/tests.qon:170\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString(testString, unBoxString(car(cons(boxString(testString), NULL))))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("10. pass cons and car work\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("10. fail cons and car fail\n");

  };

if (globalTrace)
    {printf("Leaving test10\n");}

}


//Building function test12 from line: 180

function test12() {
  var b = NULL;

if (globalTrace)
    {printf("test12 at q/tests.qon:180\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  b = {};
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  b.str = "12. pass structure accessors\n";
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", b.str);

if (globalTrace)
    {printf("Leaving test12\n");}

}


//Building function test13 from line: 188

function test13() {
  var testString = "Hello from the filesystem!";
var contents = "";

if (globalTrace)
    {printf("test13 at q/tests.qon:188\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  write_file("test.txt", testString);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  contents = read_file("test.txt");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString(testString, contents)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("13. pass Read and write files\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("13. fail Read and write files\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("Expected: %s\n", testString);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("Got: %s\n", contents);

  };

if (globalTrace)
    {printf("Leaving test13\n");}

}


//Building function test15 from line: 204

function test15() {
  var a = "hello";
var b = " world";
var c = "";

if (globalTrace)
    {printf("test15 at q/tests.qon:204\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  c = stringConcatenate(a, b);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString(c, "hello world")) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("15. pass String concatenate\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("15. fail String concatenate\n");

  };

if (globalTrace)
    {printf("Leaving test15\n");}

}


//Building function test16 from line: 212

function test16() {
  var assocCell1 = NULL;
var assList = NULL;
var assocCell2 = NULL;
var assocCell3 = NULL;

if (globalTrace)
    {printf("test16 at q/tests.qon:212\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  assocCell1 = cons(boxString("Hello"), boxString("world"));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  assocCell2 = cons(boxString("goodnight"), boxString("moon"));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  assocCell3 = cons(boxSymbol("ohio"), boxString("gozaimasu"));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  assList = cons(assocCell2, emptyList());
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  assList = cons(assocCell1, assList);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  assList = cons(assocCell3, assList);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(cdr(assoc("Hello", assList)), boxString("world"))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("16.1 pass Basic assoc works\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("16.1 fail Basic assoc fails\n");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( andBool(andBool(equalBox(cdr(assoc("Hello", assList)), boxString("world")), equalBox(cdr(assoc("goodnight", assList)), boxString("moon"))), equalBox(cdr(assoc("ohio", assList)), boxString("gozaimasu")))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("16.2 pass assoc list\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("16.2 fail assoc list\n");

  };

if (globalTrace)
    {printf("Leaving test16\n");}

}


//Building function test17 from line: 236

function test17() {
  var l = NULL;

if (globalTrace)
    {printf("test17 at q/tests.qon:236\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  l = cons(boxInt(1), cons(boxInt(2), cons(boxInt(3), NULL)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(car(l), boxInt(1))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("17. pass list literal works\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("17. fail list literal failed\n");

  };

if (globalTrace)
    {printf("Leaving test17\n");}

}


//Building function test18 from line: 247

function test18() {
  var val1 = "a";
var val2 = "b";
var l = NULL;

if (globalTrace)
    {printf("test18 at q/tests.qon:247\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), NULL)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalList(l, cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), NULL))))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("18. pass string list constructor works\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("18. fail string list constructor failed\n");

  };

if (globalTrace)
    {printf("Leaving test18\n");}

}


//Building function test19 from line: 261

function test19() {
  var val1 = "a";
var val2 = "b";
var l = NULL;
var revlist = NULL;
var answer = NULL;

if (globalTrace)
    {printf("test19 at q/tests.qon:261\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), NULL)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  answer = cons(boxString("c"), cons(boxString(val2), cons(boxString(val1), NULL)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  revlist = reverseList(l);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalList(answer, revlist)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("19. pass reverseList\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("19. fail reverseList\n");

  };

if (globalTrace)
    {printf("Leaving test19\n");}

}


//Building function concatenateLists from line: 279

function concatenateLists(oldL,newL) {
  
if (globalTrace)
    {printf("concatenateLists at q/tests.qon:279\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(reverseRec(reverseList(oldL), newL));

if (globalTrace)
    {printf("Leaving concatenateLists\n");}

}


//Building function test20 from line: 284

function test20() {
  var val1 = "a";
var val2 = "b";
var val3 = "c";
var l = NULL;
var l2 = NULL;
var l3 = NULL;
var combined = NULL;

if (globalTrace)
    {printf("test20 at q/tests.qon:284\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), NULL)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  l2 = cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), NULL)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  l3 = cons(boxString(val1), cons(boxString(val2), cons(boxString(val3), cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), NULL))))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  combined = concatenateLists(l, l2);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalList(l3, combined)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("21. pass concatenateLists\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("21. fail concatenateLists\n");

  };

if (globalTrace)
    {printf("Leaving test20\n");}

}


//Building function test21 from line: 304

function test21() {
  var val1 = "a";
var val2 = "b";
var val3 = "c";
var l = NULL;
var l2 = NULL;

if (globalTrace)
    {printf("test21 at q/tests.qon:304\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  l = cons(boxString(val1), cons(boxString(val2), cons(boxString(val3), NULL)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  l2 = cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), NULL)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalList(l, l2)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("21. pass equalList\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("21. fail equalList\n");

  };

if (globalTrace)
    {printf("Leaving test21\n");}

}


//Building function test22 from line: 320

function test22() {
  var original = NULL;
var out = NULL;
var replace = NULL;
var correct = NULL;

if (globalTrace)
    {printf("test22 at q/tests.qon:320\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), NULL)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  replace = cons(boxString("fprintf"), cons(boxString("stderr"), NULL));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  out = macrolist(original, stringConcatenate("q", "log"), replace);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  correct = cons(boxString("fprintf"), cons(boxString("stderr"), cons(boxString("%s"), cons(boxString("hello"), NULL))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalList(out, correct)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("22. pass macroList\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("22. fail macroList\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("In: ");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    displayList(original, 0, true);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\nOut: ");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    displayList(out, 0, true);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n");

  };

if (globalTrace)
    {printf("Leaving test22\n");}

}


//Building function test23 from line: 343

function test23() {
  var original = NULL;
var out = NULL;
var replace = NULL;
var correct = NULL;

if (globalTrace)
    {printf("test23 at q/tests.qon:343\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), NULL)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  replace = cons(boxString("fprintf"), cons(boxString("stderr"), NULL));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  out = concatLists(original, replace);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  correct = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), cons(boxString("fprintf"), cons(boxString("stderr"), NULL)))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalList(out, correct)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("23. pass concatLists\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("23. fail concatLists\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("In: ");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    displayList(original, 0, true);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\nOut: ");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    displayList(out, 0, true);

  };

if (globalTrace)
    {printf("Leaving test23\n");}

}


//Building function nodeFunctionArgs from line: 4

function nodeFunctionArgs(tree) {
  
if (globalTrace)
    {printf("nodeFunctionArgs at q/node.qon:4\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    display(second(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(cddr(tree))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf(",");

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeFunctionArgs(cddr(tree));

  };

if (globalTrace)
    {printf("Leaving nodeFunctionArgs\n");}

}


//Building function nodeLeaf from line: 13

function nodeLeaf(thisNode,indent) {
  
if (globalTrace)
    {printf("nodeLeaf at q/node.qon:13\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  display(nodeFuncMap(codeof(thisNode)));

if (globalTrace)
    {printf("Leaving nodeLeaf\n");}

}


//Building function nodeStructGetterExpression from line: 16

function nodeStructGetterExpression(thisNode,indent) {
  
if (globalTrace)
    {printf("nodeStructGetterExpression at q/node.qon:16\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(boxString("structGetter"), subnameof(thisNode))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeGetStruct(thisNode, indent);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeLeaf(thisNode, indent);

  };

if (globalTrace)
    {printf("Leaving nodeStructGetterExpression\n");}

}


//Building function nodeExpression from line: 22

function nodeExpression(node,indent) {
  
if (globalTrace)
    {printf("nodeExpression at q/node.qon:22\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isLeaf(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    display(nodeFuncMap(codeof(node)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeSubExpression(node, indent);

  };

if (globalTrace)
    {printf("Leaving nodeExpression\n");}

}


//Building function nodeRecurList from line: 28

function nodeRecurList(expr,indent) {
  
if (globalTrace)
    {printf("nodeRecurList at q/node.qon:28\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(expr)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeExpression(car(expr), indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(cdr(expr))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf(", ");
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      nodeRecurList(cdr(expr), indent);

    };

  };

if (globalTrace)
    {printf("Leaving nodeRecurList\n");}

}


//Building function nodeSubExpression from line: 41

function nodeSubExpression(tree,indent) {
  var thing = NULL;

if (globalTrace)
    {printf("nodeSubExpression at q/node.qon:41\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNode(childrenof(tree))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      nodeSubExpression(childrenof(tree), indent);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( isLeaf(tree)) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        display(nodeFuncMap(codeof(tree)));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equal(1, listLength(childrenof(tree)))) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          display(codeof(car(childrenof(tree))));
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalBox(boxString("return"), codeof(car(childrenof(tree))))) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("");

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("()");

          };

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          thing = codeof(car(childrenof(tree)));
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalBox(boxSymbol("get-struct"), thing)) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("%s.%s", stringify(codeof(second(childrenof(tree)))), stringify(codeof(third(childrenof(tree)))));

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            if ( equalBox(boxSymbol("new"), thing)) {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf("{}");

            } else {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf("%s(", stringify(nodeFuncMap(codeof(car(childrenof(tree))))));
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              nodeRecurList(cdr(childrenof(tree)), indent);
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf(")");

            };

          };

        };

      };

    };

  };

if (globalTrace)
    {printf("Leaving nodeSubExpression\n");}

}


//Building function nodeIf from line: 82

function nodeIf(node,indent) {
  
if (globalTrace)
    {printf("nodeIf at q/node.qon:82\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("if ( ");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  nodeExpression(car(first(childrenof(node))), 0);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf(") {");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  nodeBody(second(childrenof(node)), add1(indent));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("} else {");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  nodeBody(third(childrenof(node)), add1(indent));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("}");

if (globalTrace)
    {printf("Leaving nodeIf\n");}

}


//Building function nodeGetStruct from line: 96

function nodeGetStruct(node,indent) {
  
if (globalTrace)
    {printf("nodeGetStruct at q/node.qon:96\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s.%s", stringify(first(codeof(node))), stringify(second(codeof(node))));

if (globalTrace)
    {printf("Leaving nodeGetStruct\n");}

}


//Building function nodeSet from line: 104

function nodeSet(node,indent) {
  
if (globalTrace)
    {printf("nodeSet at q/node.qon:104\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s = ", stringify(first(codeof(node))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  nodeExpression(childrenof(node), indent);

if (globalTrace)
    {printf("Leaving nodeSet\n");}

}


//Building function nodeSetStruct from line: 110

function nodeSetStruct(node,indent) {
  
if (globalTrace)
    {printf("nodeSetStruct at q/node.qon:110\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s.%s = ", stringify(first(codeof(node))), stringify(second(codeof(node))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  nodeExpression(childrenof(node), indent);

if (globalTrace)
    {printf("Leaving nodeSetStruct\n");}

}


//Building function nodeStatement from line: 118

function nodeStatement(node,indent) {
  
if (globalTrace)
    {printf("nodeStatement at q/node.qon:118\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(boxString("setter"), subnameof(node))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeSet(node, indent);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalBox(boxString("structSetter"), subnameof(node))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      nodeSetStruct(node, indent);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalBox(boxString("if"), subnameof(node))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        nodeIf(node, indent);

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalBox(boxString("returnvoid"), subnameof(node))) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          newLine(indent);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf("return");

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          newLine(indent);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          nodeExpression(childrenof(node), indent);

        };

      };

    };

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf(";\n");

if (globalTrace)
    {printf("Leaving nodeStatement\n");}

}


//Building function nodeBody from line: 137

function nodeBody(tree,indent) {
  
if (globalTrace)
    {printf("nodeBody at q/node.qon:137\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s", "if (globalStepTrace) {console.log(new Error(\"StepTrace \\n\"));}\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeStatement(car(tree), indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeBody(cdr(tree), indent);

  };

if (globalTrace)
    {printf("Leaving nodeBody\n");}

}


//Building function nodeDeclarations from line: 151

function nodeDeclarations(decls,indent) {
  var decl = NULL;

if (globalTrace)
    {printf("nodeDeclarations at q/node.qon:151\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(decls)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    decl = car(decls);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("var %s = ", stringify(second(decl)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    display(nodeFuncMap(third(decl)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(";\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeDeclarations(cdr(decls), indent);

  };

if (globalTrace)
    {printf("Leaving nodeDeclarations\n");}

}


//Building function nodeFunction from line: 166

function nodeFunction(node) {
  var name = NULL;

if (globalTrace)
    {printf("nodeFunction at q/node.qon:166\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  name = subnameof(node);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(0);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newLine(0);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("function %s(", stringify(subnameof(node)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeFunctionArgs(cdr(assoc("intype", cdr(node))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(") {");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newLine(1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeDeclarations(declarationsof(node), 1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( releaseMode) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("\nif (globalTrace)\n    {printf(\"%s at %s:%s\\n\");}\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( releaseMode) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {
    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeBody(childrenof(node), 1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( releaseMode) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("\nif (globalTrace)\n    {printf(\"Leaving %s\\n\");}\n", stringify(name));

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n}\n");

  };

if (globalTrace)
    {printf("Leaving nodeFunction\n");}

}


//Building function nodeForwardDeclaration from line: 199

function nodeForwardDeclaration(node) {
  
if (globalTrace)
    {printf("nodeForwardDeclaration at q/node.qon:199\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n%s %s(", stringify(nodeTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeFunctionArgs(cdr(assoc("intype", cdr(node))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(");");

  };

if (globalTrace)
    {printf("Leaving nodeForwardDeclaration\n");}

}


//Building function nodeForwardDeclarations from line: 211

function nodeForwardDeclarations(tree) {
  
if (globalTrace)
    {printf("nodeForwardDeclarations at q/node.qon:211\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeForwardDeclaration(car(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeForwardDeclarations(cdr(tree));

  };

if (globalTrace)
    {printf("Leaving nodeForwardDeclarations\n");}

}


//Building function nodeFunctions from line: 221

function nodeFunctions(tree) {
  
if (globalTrace)
    {printf("nodeFunctions at q/node.qon:221\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeFunction(car(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeFunctions(cdr(tree));

  };

if (globalTrace)
    {printf("Leaving nodeFunctions\n");}

}


//Building function nodeIncludes from line: 229

function nodeIncludes(nodes) {
  
if (globalTrace)
    {printf("nodeIncludes at q/node.qon:229\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function read_file(filename) {return fs.readFileSync(filename);}\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function write_file(filename, data) {fs.writeFileSync(filename, data);}\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "var util = require('util');\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function printf() {process.stdout.write(util.format.apply(this, arguments));}\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function qlog()   {process.stderr.write(util.format.apply(this, arguments));}\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "var fs = require('fs');\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function equalString(a,b) {if (a==null) {return false;}if (b==null) {return false;}return a.toString()===b.toString() }\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function panic(s){console.trace(s);process.exit(1);}\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function dump(s){console.log(s)}");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function sub(a, b) { return a - b; }\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function mult(a, b) { return a * b; }\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function greaterthan(a, b) { return a > b; }\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function subf(a, b) { return a - b; }\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function multf(a, b) { return a * b; }\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function greaterthanf(a, b) { return a > b; }\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function equal(a, b) { return a == b; }\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function andBool(a, b) { return a == b;}\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function string_length(s) { return s.length;}\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function sub_string(str, start, len) {str = ''+str;return str.substring(start, start+len)};\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function stringConcatenate(a, b) { return a + b}\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function intToString(a) {}\n\n\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function gc_malloc( size ) {\nreturn {};\n}\n\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function makeArray(length) {\n   return [];\n}\n\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function at(arr, index) {\n  return arr[index];\n}\n\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function setAt(array, index, value) {\n    array[index] = value;\n}\n\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function getStringArray(index, strs) {\nreturn strs[index];\n}\n\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "var NULL = null;");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "var globalArgs;\nvar globalArgsCount;\nvar globalTrace = false;\nvar globalStepTrace = false;\nvar releaseMode = false;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "function character(num) {}");

if (globalTrace)
    {printf("Leaving nodeIncludes\n");}

}


//Building function nodeTypeDecl from line: 263

function nodeTypeDecl(l) {
  
if (globalTrace)
    {printf("nodeTypeDecl at q/node.qon:263\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(listLength(l), 2)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s %s %s;\n", stringify(second(l)), stringify(nodeTypeMap(listLast(l))), stringify(first(l)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s %s;\n", stringify(nodeTypeMap(listLast(l))), stringify(car(l)));

  };

if (globalTrace)
    {printf("Leaving nodeTypeDecl\n");}

}


//Building function nodeStructComponents from line: 280

function nodeStructComponents(node) {
  
if (globalTrace)
    {printf("nodeStructComponents at q/node.qon:280\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeTypeDecl(car(node));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeStructComponents(cdr(node));

  };

if (globalTrace)
    {printf("Leaving nodeStructComponents\n");}

}


//Building function nodeStruct from line: 288

function nodeStruct(node) {
  
if (globalTrace)
    {printf("nodeStruct at q/node.qon:288\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  nodeStructComponents(cdr(car(node)));

if (globalTrace)
    {printf("Leaving nodeStruct\n");}

}


//Building function nodeTypeMap from line: 293

function nodeTypeMap(aSym) {
  var symMap = NULL;

if (globalTrace)
    {printf("nodeTypeMap at q/node.qon:293\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( truthy(assoc(stringify(aSym), symMap))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cdr(assoc(stringify(aSym), symMap)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(aSym);

  };

if (globalTrace)
    {printf("Leaving nodeTypeMap\n");}

}


//Building function nodeFuncMap from line: 308

function nodeFuncMap(aSym) {
  var symMap = NULL;

if (globalTrace)
    {printf("nodeFuncMap at q/node.qon:308\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("symbol", boxType(aSym))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), NULL)))))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( truthy(assoc(stringify(aSym), symMap))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(cdr(assoc(stringify(aSym), symMap)));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(aSym);

    };

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(aSym);

  };

if (globalTrace)
    {printf("Leaving nodeFuncMap\n");}

}


//Building function nodeType from line: 339

function nodeType(node) {
  
if (globalTrace)
    {printf("nodeType at q/node.qon:339\n");}

if (globalTrace)
    {printf("Leaving nodeType\n");}

}


//Building function nodeTypes from line: 343

function nodeTypes(nodes) {
  
if (globalTrace)
    {printf("nodeTypes at q/node.qon:343\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(nodes)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeType(car(nodes));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    nodeTypes(cdr(nodes));

  };

if (globalTrace)
    {printf("Leaving nodeTypes\n");}

}


//Building function nodeCompile from line: 351

function nodeCompile(filename) {
  var programStr = "";
var tree = NULL;
var program = NULL;

if (globalTrace)
    {printf("nodeCompile at q/node.qon:351\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  programStr = read_file(filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = readSexpr(programStr, filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  program = mergeIncludes(program);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  nodeIncludes(cdr(assoc("includes", program)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  nodeTypes(childrenof(cdr(assoc("types", program))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\nvar globalStackTrace = NULL;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\nvar caller = \"\";\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\nfunction isNil(p) {\n    return p == NULL;\n}\n\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  nodeFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("const [asfdasdf, ...qwerqwer] = process.argv;");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("globalArgs = qwerqwer;");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("globalArgsCount = qwerqwer.length;");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "start();\n");

if (globalTrace)
    {printf("Leaving nodeCompile\n");}

}


//Building function javaFunctionArgs from line: 3

function javaFunctionArgs(tree) {
  
if (globalTrace)
    {printf("javaFunctionArgs at q/java.qon:3\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    display(javaTypeMap(first(tree)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(" ");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    display(second(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(cddr(tree))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf(",");

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    javaFunctionArgs(cddr(tree));

  };

if (globalTrace)
    {printf("Leaving javaFunctionArgs\n");}

}


//Building function javaLeaf from line: 14

function javaLeaf(thisNode,indent) {
  
if (globalTrace)
    {printf("javaLeaf at q/java.qon:14\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  display(javaFuncMap(codeof(thisNode)));

if (globalTrace)
    {printf("Leaving javaLeaf\n");}

}


//Building function javaStructGetterExpression from line: 17

function javaStructGetterExpression(thisNode,indent) {
  
if (globalTrace)
    {printf("javaStructGetterExpression at q/java.qon:17\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(boxString("structGetter"), subnameof(thisNode))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    javaGetStruct(thisNode, indent);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    javaLeaf(thisNode, indent);

  };

if (globalTrace)
    {printf("Leaving javaStructGetterExpression\n");}

}


//Building function javaExpression from line: 23

function javaExpression(node,indent) {
  
if (globalTrace)
    {printf("javaExpression at q/java.qon:23\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isLeaf(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    display(javaFuncMap(codeof(node)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    javaSubExpression(node, indent);

  };

if (globalTrace)
    {printf("Leaving javaExpression\n");}

}


//Building function javaRecurList from line: 29

function javaRecurList(expr,indent) {
  
if (globalTrace)
    {printf("javaRecurList at q/java.qon:29\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(expr)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    javaExpression(car(expr), indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(cdr(expr))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf(", ");
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      javaRecurList(cdr(expr), indent);

    };

  };

if (globalTrace)
    {printf("Leaving javaRecurList\n");}

}


//Building function javaSubExpression from line: 41

function javaSubExpression(tree,indent) {
  var thing = NULL;

if (globalTrace)
    {printf("javaSubExpression at q/java.qon:41\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNode(childrenof(tree))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      javaSubExpression(childrenof(tree), indent);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( isLeaf(tree)) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        display(javaFuncMap(codeof(tree)));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equal(1, listLength(childrenof(tree)))) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          display(codeof(car(childrenof(tree))));
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalBox(boxString("return"), codeof(car(childrenof(tree))))) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("");

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("()");

          };

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          thing = codeof(car(childrenof(tree)));
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalBox(boxSymbol("get-struct"), thing)) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("%s.%s", stringify(codeof(second(childrenof(tree)))), stringify(codeof(third(childrenof(tree)))));

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            if ( equalBox(boxSymbol("new"), thing)) {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf("new %s()", stringify(codeof(third(childrenof(tree)))));

            } else {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf("%s(", stringify(javaFuncMap(codeof(car(childrenof(tree))))));
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              javaRecurList(cdr(childrenof(tree)), indent);
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf(")");

            };

          };

        };

      };

    };

  };

if (globalTrace)
    {printf("Leaving javaSubExpression\n");}

}


//Building function javaIf from line: 81

function javaIf(node,indent) {
  
if (globalTrace)
    {printf("javaIf at q/java.qon:81\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("if ( ");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  javaExpression(car(first(childrenof(node))), 0);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf(") {");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  javaBody(second(childrenof(node)), add1(indent));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("} else {");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  javaBody(third(childrenof(node)), add1(indent));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("}");

if (globalTrace)
    {printf("Leaving javaIf\n");}

}


//Building function javaSetStruct from line: 94

function javaSetStruct(node,indent) {
  
if (globalTrace)
    {printf("javaSetStruct at q/java.qon:94\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s.%s = ", stringify(first(codeof(node))), stringify(second(codeof(node))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  javaExpression(childrenof(node), indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf(";");

if (globalTrace)
    {printf("Leaving javaSetStruct\n");}

}


//Building function javaGetStruct from line: 105

function javaGetStruct(node,indent) {
  
if (globalTrace)
    {printf("javaGetStruct at q/java.qon:105\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s.%s", stringify(first(codeof(node))), stringify(second(codeof(node))));

if (globalTrace)
    {printf("Leaving javaGetStruct\n");}

}


//Building function javaSet from line: 113

function javaSet(node,indent) {
  
if (globalTrace)
    {printf("javaSet at q/java.qon:113\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s = ", stringify(first(codeof(node))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  javaExpression(childrenof(node), indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf(";");

if (globalTrace)
    {printf("Leaving javaSet\n");}

}


//Building function javaStatement from line: 121

function javaStatement(node,indent) {
  
if (globalTrace)
    {printf("javaStatement at q/java.qon:121\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(boxString("setter"), subnameof(node))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    javaSet(node, indent);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalBox(boxString("structSetter"), subnameof(node))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      javaSetStruct(node, indent);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalBox(boxString("if"), subnameof(node))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        javaIf(node, indent);

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalBox(boxString("returnvoid"), subnameof(node))) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          newLine(indent);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf("return;");

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          newLine(indent);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          javaExpression(childrenof(node), indent);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf(";");

        };

      };

    };

  };

if (globalTrace)
    {printf("Leaving javaStatement\n");}

}


//Building function javaBody from line: 141

function javaBody(tree,indent) {
  
if (globalTrace)
    {printf("javaBody at q/java.qon:141\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    javaStatement(car(tree), indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    javaBody(cdr(tree), indent);

  };

if (globalTrace)
    {printf("Leaving javaBody\n");}

}


//Building function javaDeclarations from line: 151

function javaDeclarations(decls,indent) {
  var decl = NULL;

if (globalTrace)
    {printf("javaDeclarations at q/java.qon:151\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(decls)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    decl = car(decls);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s %s = ", stringify(javaTypeMap(first(decl))), stringify(second(decl)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    display(javaFuncMap(third(decl)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(";\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    javaDeclarations(cdr(decls), indent);

  };

if (globalTrace)
    {printf("Leaving javaDeclarations\n");}

}


//Building function javaFunction from line: 165

function javaFunction(node) {
  var name = NULL;

if (globalTrace)
    {printf("javaFunction at q/java.qon:165\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  name = subnameof(node);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(0);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newLine(0);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("public %s %s(", stringify(javaTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    javaFunctionArgs(cdr(assoc("intype", cdr(node))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(") {");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newLine(1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    javaDeclarations(declarationsof(node), 1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( inList(toStr(name), noStackTrace())) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( inList(toStr(name), noStackTrace())) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {
    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    javaBody(childrenof(node), 1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( inList(toStr(name), noStackTrace())) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalString("void", stringify(javaTypeMap(cdr(assoc("outtype", cdr(node))))))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printf("\nif (globalTrace)\n   System.out. printf(\"Leaving %s\\n\");\n", stringify(name));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printf("");

      };

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n}\n");

  };

if (globalTrace)
    {printf("Leaving javaFunction\n");}

}


//Building function javaFunctions from line: 204

function javaFunctions(tree) {
  
if (globalTrace)
    {printf("javaFunctions at q/java.qon:204\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    javaFunction(car(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    javaFunctions(cdr(tree));

  };

if (globalTrace)
    {printf("Leaving javaFunctions\n");}

}


//Building function javaIncludes from line: 210

function javaIncludes(nodes) {
  
if (globalTrace)
    {printf("javaIncludes at q/java.qon:210\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "public void panic(String s) {System.exit(1);}\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "public int sub(int a, int b) { return a - b; }\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "public double mult(int a, int b) { return a * b; }\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "public boolean greaterthan(int a, int b) { return a > b; }\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "public double subf(double a, double b) { return a - b; }\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "public double multf(double a, double b) { return a * b; }\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "public boolean greaterthanf(double a, double b) { return a > b; }\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "public boolean equal(int a, int b) { return a == b; }\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "public boolean equalString(String a, String b) { return a.equals(b); }\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "public boolean andBool(boolean a, boolean b) { return a == b;}\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "public int string_length(String s) { return s.length();}\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "public String stringConcatenate(String s1, String s2) { return s1 + s2; }\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "public int strcmp(String s1, String s2) { return s1.compareTo(s2);}\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "public String read_file(String filename) {try { return new String(Files.readAllBytes(Paths.get(filename)));} catch (Exception e) {panic(\"Could not read file\");return \"\";}}\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "public void write_file(String filename, String data) {try {Files.write(Paths.get(filename), data.getBytes(\"UTF-8\"));} catch (Exception e) {panic(\"Could not write file\");}}\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "public String sub_string(String s, int start, int length) {\nreturn s.substring(start, start+length);\n}\n\n\n\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "public String intToString(int num) { char c=(char) num;  String s=Character.toString(c); return s;}");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "public String character(int num) { char c=(char) num;  String s=Character.toString(c); return s;}");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "public String getStringArray(int index, String[] arr) { return arr[index];}");

if (globalTrace)
    {printf("Leaving javaIncludes\n");}

}


//Building function javaTypeDecl from line: 233

function javaTypeDecl(l) {
  
if (globalTrace)
    {printf("javaTypeDecl at q/java.qon:233\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(listLength(l), 2)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s %s;\n", stringify(javaTypeMap(listLast(l))), stringify(first(l)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s %s;\n", stringify(javaTypeMap(listLast(l))), stringify(car(l)));

  };

if (globalTrace)
    {printf("Leaving javaTypeDecl\n");}

}


//Building function javaStructComponents from line: 250

function javaStructComponents(node) {
  
if (globalTrace)
    {printf("javaStructComponents at q/java.qon:250\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    javaTypeDecl(car(node));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    javaStructComponents(cdr(node));

  };

if (globalTrace)
    {printf("Leaving javaStructComponents\n");}

}


//Building function javaStruct from line: 256

function javaStruct(node) {
  
if (globalTrace)
    {printf("javaStruct at q/java.qon:256\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  javaStructComponents(cdr(car(node)));

if (globalTrace)
    {printf("Leaving javaStruct\n");}

}


//Building function javaTypeMap from line: 259

function javaTypeMap(aSym) {
  var symMap = NULL;

if (globalTrace)
    {printf("javaTypeMap at q/java.qon:259\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  symMap = alistCons(boxSymbol("pair"), boxSymbol("Box"), alistCons(boxSymbol("bool"), boxSymbol("boolean"), alistCons(boxSymbol("box"), boxSymbol("Box"), alistCons(boxSymbol("list"), boxSymbol("Box"), alistCons(boxSymbol("Box*"), boxSymbol("Box"), alistCons(boxSymbol("struct"), boxSymbol(""), alistCons(boxSymbol("int"), boxSymbol("Integer"), alistCons(boxSymbol("float"), boxSymbol("double"), alistCons(boxSymbol("stringArray"), boxSymbol("String[]"), alistCons(boxSymbol("string"), boxSymbol("String"), NULL))))))))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( truthy(assoc(stringify(aSym), symMap))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cdr(assoc(stringify(aSym), symMap)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(aSym);

  };

if (globalTrace)
    {printf("Leaving javaTypeMap\n");}

}


//Building function javaTypesNoDeclare from line: 277

function javaTypesNoDeclare() {
  var syms = NULL;

if (globalTrace)
    {printf("javaTypesNoDeclare at q/java.qon:277\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  syms = cons(boxString("pair"), cons(boxString("box"), NULL));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(syms);

if (globalTrace)
    {printf("Leaving javaTypesNoDeclare\n");}

}


//Building function javaFuncMap from line: 286

function javaFuncMap(aSym) {
  var symMap = NULL;

if (globalTrace)
    {printf("javaFuncMap at q/java.qon:286\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("symbol", boxType(aSym))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    symMap = alistCons(boxSymbol("printf"), boxSymbol("System.out.printf"), alistCons(boxSymbol(stringConcatenate("q", "log")), boxSymbol("System.err.printf"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("null"), NULL)))))))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( truthy(assoc(stringify(aSym), symMap))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(cdr(assoc(stringify(aSym), symMap)));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(aSym);

    };

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(aSym);

  };

if (globalTrace)
    {printf("Leaving javaFuncMap\n");}

}


//Building function javaType from line: 307

function javaType(node) {
  
if (globalTrace)
    {printf("javaType at q/java.qon:307\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(subnameof(node), boxString("struct"))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\npublic class %s {\n", stringify(first(codeof(node))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\npublic String caller =\"\";");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    javaStruct(cdr(codeof(node)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n};\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( inList(boxString(stringify(first(codeof(node)))), javaTypesNoDeclare())) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("public class %s extends %s {};\n", stringify(first(codeof(node))), stringify(javaTypeMap(listLast(codeof(node)))));

    };

  };

if (globalTrace)
    {printf("Leaving javaType\n");}

}


//Building function javaTypes from line: 324

function javaTypes(nodes) {
  
if (globalTrace)
    {printf("javaTypes at q/java.qon:324\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(nodes)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    javaType(car(nodes));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    javaTypes(cdr(nodes));

  };

if (globalTrace)
    {printf("Leaving javaTypes\n");}

}


//Building function javaCompile from line: 330

function javaCompile(filename) {
  var programStr = "";
var tree = NULL;
var program = NULL;

if (globalTrace)
    {printf("javaCompile at q/java.qon:330\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "package quonverter;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "import java.nio.file.Files;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "import java.nio.file.Paths;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "import java.io.IOException;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "import java.io.UnsupportedEncodingException;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("class MyProgram {\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\npublic String caller =\"\";");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  programStr = read_file(filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = readSexpr(programStr, filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), NULL)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  program = mergeIncludes(program);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  javaIncludes(cdr(assoc("includes", program)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  javaTypes(childrenof(cdr(assoc("types", program))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("public boolean globalStackTrace = false;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("public boolean globalStepTrace = false;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("public boolean globalTrace = false;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("public boolean releaseMode = false;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("public String FILE = null;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("public Integer LINE = 0;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("public static Integer globalArgsCount = 0;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("public static String globalArgs[];\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\npublic boolean isNil(Box p) {\n    return p == null;\n}\n\n\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  javaFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "public static void main(String args[]) {\nglobalArgs = args;\nglobalArgsCount = args.length;MyProgram mp = new MyProgram(); mp.start();\n}");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("}\n");

if (globalTrace)
    {printf("Leaving javaCompile\n");}

}


//Building function luaFunctionArgs from line: 4

function luaFunctionArgs(indent,tree) {
  
if (globalTrace)
    {printf("luaFunctionArgs at q/lua.qon:4\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    display(second(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(cddr(tree))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf(",");

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    luaFunctionArgs(indent, cddr(tree));

  };

if (globalTrace)
    {printf("Leaving luaFunctionArgs\n");}

}


//Building function luaFunction from line: 14

function luaFunction(indent,functionDefinition) {
  var fname = "";

if (globalTrace)
    {printf("luaFunction at q/lua.qon:14\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  fname = stringify(second(functionDefinition));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("-- Chose function name %s", fname);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\nfunction %s(", fname);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  luaFunctionArgs(indent, third(functionDefinition));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf(")\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("print(\"caller: \", caller, \"-> %s\")\n", fname);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  luaDeclarations(add1(indent), cdr(fourth(functionDefinition)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  luaBody(fname, indent, cdr(fifth(functionDefinition)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("end\n");

if (globalTrace)
    {printf("Leaving luaFunction\n");}

}


//Building function luaDeclarations from line: 26

function luaDeclarations(indent,declarations) {
  var decl = NULL;

if (globalTrace)
    {printf("luaDeclarations at q/lua.qon:26\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(declarations)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    decl = first(declarations);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("local %s =", stringify(second(decl)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    luaExpressionStart(indent, third(decl));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    luaDeclarations(indent, cdr(declarations));

  };

if (globalTrace)
    {printf("Leaving luaDeclarations\n");}

}


//Building function luaExpressionStart from line: 42

function luaExpressionStart(indent,program) {
  
if (globalTrace)
    {printf("luaExpressionStart at q/lua.qon:42\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(program)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isList(program)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalString(stringify(car(program)), "get-struct")) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printf("%s.%s", stringify(second(program)), stringify(third(program)));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalString(stringify(car(program)), ">")) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf("greaterthan(");
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          luaExpression(indent, cdr(program));
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf(")");

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalString(stringify(car(program)), "=")) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("equal(");
            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            luaExpression(indent, cdr(program));
            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf(")");

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("%s(", stringify(car(program)));
            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            luaExpression(indent, cdr(program));
            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf(")");

          };

        };

      };

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      luaExpression(indent, program);

    };

  };

if (globalTrace)
    {printf("Leaving luaExpressionStart\n");}

}


//Building function luaExpression from line: 84

function luaExpression(indent,program) {
  
if (globalTrace)
    {printf("luaExpression at q/lua.qon:84\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(program)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isList(program)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( isList(car(program))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        luaExpressionStart(indent, car(program));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        display(car(program));

      };
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( greaterthan(listLength(program), 1)) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printf(", ");

      } else {
      };
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      luaExpression(indent, cdr(program));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      display(program);

    };

  };

if (globalTrace)
    {printf("Leaving luaExpression\n");}

}


//Building function luaStatement from line: 112

function luaStatement(indent,statement) {
  
if (globalTrace)
    {printf("luaStatement at q/lua.qon:112\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString(stringify(car(statement)), "if")) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("if ");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    add1(indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    luaExpressionStart(add1(indent), second(statement));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(" then\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    luaBody(caller, add1(indent), cdr(third(statement)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("else\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    luaBody(caller, add1(indent), cdr(fourth(statement)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("end\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalString(stringify(car(statement)), "set")) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printIndent(indent);
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("%s = ", stringify(second(statement)));
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      luaExpressionStart(add1(indent), third(statement));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalString(stringify(car(statement)), "set-struct")) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printf("%s.%s = ", stringify(second(statement)), stringify(third(statement)));
        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        luaExpressionStart(indent, fourth(statement));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalString(stringify(car(statement)), "return")) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printIndent(indent);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf("return ");
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( greaterthan(listLength(statement), 1)) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            luaExpressionStart(indent, second(statement));

          } else {
          };
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf("\n");

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printIndent(indent);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          luaExpressionStart(indent, statement);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf(";\n");

        };

      };

    };

  };

if (globalTrace)
    {printf("Leaving luaStatement\n");}

}


//Building function luaBody from line: 164

function luaBody(local_caller,indent,program) {
  var statement = NULL;

if (globalTrace)
    {printf("luaBody at q/lua.qon:164\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(program)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    statement = car(program);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("caller = \"%s:%s:%d\"\n", local_caller, unBoxString(getTagFail(statement, boxString("filename"), boxString("Unknown file"))), unBoxInt(getTagFail(statement, boxString("line"), boxInt(-1))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    luaStatement(add1(indent), statement);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    luaBody(local_caller, indent, cdr(program));

  };

if (globalTrace)
    {printf("Leaving luaBody\n");}

}


//Building function luaFunctions from line: 176

function luaFunctions(indent,program) {
  
if (globalTrace)
    {printf("luaFunctions at q/lua.qon:176\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(program)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    luaFunction(indent, car(program));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    luaFunctions(indent, cdr(program));

  };

if (globalTrace)
    {printf("Leaving luaFunctions\n");}

}


//Building function luaProgram from line: 188

function luaProgram(program) {
  
if (globalTrace)
    {printf("luaProgram at q/lua.qon:188\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  luaIncludes(NULL);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  luaFunctions(0, cdr(third(program)));

if (globalTrace)
    {printf("Leaving luaProgram\n");}

}


//Building function luaIncludes from line: 195

function luaIncludes(nodes) {
  
if (globalTrace)
    {printf("luaIncludes at q/lua.qon:195\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "\nfunction luaDump(o)\n   if type(o) == 'table' then\n      local s = '{ '\n      for k,v in pairs(o) do\n         if type(k) ~= 'number' then k = '\"'..k..'\"' end\n         s = s .. '['..k..'] = ' .. luaDump(v) .. ','\n      end\n      return s .. '} '\n   else\n      return tostring(o)\n   end\nend\nprintf = function(s,...)\nreturn io.write(s:format(...))\nend -- function\n    \nfunction stringConcatenate(a,b)\nreturn a..b\nend\n    \nfunction getStringArray(index, arr)\nreturn arr[index]\nend\n       \nfunction luaWriteFile(name, data)  \nlocal file = io.open(name, \"w\")\nfile:write(data)\nfile:close(file)\nend\n    function luaSubstring(s, start, length)\nreturn string.sub(s, start, start+length)\nend\n    \n    function luaReadFile(file)\n      local f = assert(io.open(file, \"rb\"))\n      local content = f:read(\"*all\")      f:close()\n      return content\n    end\n     \nfunction equalString(a,b)\n        return a==b;\n     end\n    \n     function new()\n        return {};\n     end\n    \n     function isNil(val)\n        return val == nil;\n     end\n    \n     function getEnv(key)\n        return os.getenv(key);\n     end\n    \n    function panic(s)\n      print(s);\n    os.exit()\n    end\n    \n    function sub(a, b) \n      return a - b; \n    end\n\n    function mult(a, b) \n      return a * b;\n    end\n    \n    function greaterthan(a, b)\n      return a > b;\n    end\n    \n    function subf(a, b) \n      return a - b;\n    end\n    \n    function multf(a, b)\n      return a * b;\n    end\n    \n    function greaterthanf(a, b)\n      return a > b;\n    end\n    \n    function equal(a, b)\n      return a == b;\n    end\n    \n    function andBool(a, b)\n      return a == b;\n    end\n    \n    function string_length(s)\n      return strlen(s);\n    end\n    \n    function setSubString(target, start, source)\n      panic(\"stub\");\n      end\n    \n    function sub_string(s, start, length)\n      panic(\"stub\");\n    end\n    \n    function intToString(a)\n      panic(\"stub\")\n return a\n    end\n\n    function gc_malloc(size)\n      return \"\"\n    end\n    \n    function makeArray(length)\n      return {}\n    end\n    \n    function at(arr, index)\n      return arr[index+1];\n    end\n    \n    function setAt(array, index, value)\n      array[index+1] = value;\n    end\n    \n    function read_file(file)\n      local f = io.open(file, \"r\")\n      local content = \"\"\n      local length = 0\n\n      while f:read(0) ~= \"\" do\n          local current = f:read(\"*all\")\n\n          print(#current, length)\n          length = length + #current\n\n          content = content .. current\n      end\n\n      return content\n    end\n    \n    function write_file(filename, data)\n      local file = io.open(filename,'w')\n      file:write(tostring(data))\n      file:close()\n    end\n    \n    caller=\"main\";\n    \n    globalArgs={};\n    globalArgsCount=0;\n    globalTrace = false;\n    globalStepTrace = false;\n\n    function main()\n      globalArgs = arg;\n      globalArgsCount = #arg + 1;\n      return start();\n    end\n    \n");

if (globalTrace)
    {printf("Leaving luaIncludes\n");}

}


//Building function luaCompile from line: 203

function luaCompile(filename) {
  var tree = NULL;

if (globalTrace)
    {printf("luaCompile at q/lua.qon:203\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = loadQuon(filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = loadIncludes(tree);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrowalk(tree);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrosingle(tree, "write-file", "luaWriteFile");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrosingle(tree, "read-file", "luaReadFile");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrosingle(tree, "string-length", "string.len");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrosingle(tree, "sub-string", "luaSubstring");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrosingle(tree, "stringLength", "string.len");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  luaProgram(tree);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("function main()\nglobalArgs = arg\nglobalArgsCount = #arg\nstart()\nend\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("main()");

if (globalTrace)
    {printf("Leaving luaCompile\n");}

}


//Building function not from line: 3

function not(a) {
  
if (globalTrace)
    {printf("not at q/boolean.qon:3\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( a) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(false);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(true);

  };

if (globalTrace)
    {printf("Leaving not\n");}

}


//Building function andBool from line: 10

function andBool(a,b) {
  
if (globalTrace)
    {printf("andBool at q/boolean.qon:10\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( a) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( b) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(true);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(false);

    };

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(false);

  };

if (globalTrace)
    {printf("Leaving andBool\n");}

}


//Building function nand from line: 20

function nand(a,b) {
  
if (globalTrace)
    {printf("nand at q/boolean.qon:20\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(not(andBool(a, b)));

if (globalTrace)
    {printf("Leaving nand\n");}

}


//Building function xor from line: 25

function xor(a,b) {
  
if (globalTrace)
    {printf("xor at q/boolean.qon:25\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(nand(nand(a, nand(a, b)), nand(b, nand(a, b))));

if (globalTrace)
    {printf("Leaving xor\n");}

}


//Building function imaFunctionArgs from line: 4

function imaFunctionArgs(indent,tree) {
  
if (globalTrace)
    {printf("imaFunctionArgs at q/imaginary.qon:4\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    display(second(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(": ");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    display(first(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(cddr(tree))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf(", ");

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    imaFunctionArgs(indent, cddr(tree));

  };

if (globalTrace)
    {printf("Leaving imaFunctionArgs\n");}

}


//Building function imaFunction from line: 16

function imaFunction(indent,functionDefinition) {
  var fname = "";

if (globalTrace)
    {printf("imaFunction at q/imaginary.qon:16\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  fname = stringify(second(functionDefinition));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\nfu %s(", fname);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  imaFunctionArgs(indent, third(functionDefinition));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf(") ");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("-> %s", stringify(first(functionDefinition)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  imaDeclarations(add1(indent), cdr(fourth(functionDefinition)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(listLength(cdr(fourth(functionDefinition))), 0)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(" ");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printIndent(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("in\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  imaBody(fname, indent, cdr(fifth(functionDefinition)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("end function\n");

if (globalTrace)
    {printf("Leaving imaFunction\n");}

}


//Building function imaDeclarations from line: 37

function imaDeclarations(indent,declarations) {
  var decl = NULL;

if (globalTrace)
    {printf("imaDeclarations at q/imaginary.qon:37\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(declarations)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    decl = first(declarations);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s: %s ", stringify(second(decl)), stringify(first(decl)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    imaExpressionStart(indent, third(decl));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    imaDeclarations(indent, cdr(declarations));

  };

if (globalTrace)
    {printf("Leaving imaDeclarations\n");}

}


//Building function imaExpressionStart from line: 56

function imaExpressionStart(indent,program) {
  
if (globalTrace)
    {printf("imaExpressionStart at q/imaginary.qon:56\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(program)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isList(program)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalString(stringify(car(program)), "get-struct")) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printf("%s.%s", stringify(second(program)), stringify(third(program)));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalString(stringify(car(program)), ">")) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf("greaterthan(");
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          imaExpression(indent, cdr(program));
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf(")");

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalString(stringify(car(program)), "=")) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("equal(");
            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            imaExpression(indent, cdr(program));
            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf(")");

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("%s(", stringify(car(program)));
            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            imaExpression(indent, cdr(program));
            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf(")");

          };

        };

      };

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      imaExpression(indent, program);

    };

  };

if (globalTrace)
    {printf("Leaving imaExpressionStart\n");}

}


//Building function imaExpression from line: 98

function imaExpression(indent,program) {
  
if (globalTrace)
    {printf("imaExpression at q/imaginary.qon:98\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(program)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isList(program)) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( isList(car(program))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        imaExpressionStart(indent, car(program));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        display(car(program));

      };
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( greaterthan(listLength(program), 1)) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printf(", ");

      } else {
      };
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      imaExpression(indent, cdr(program));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      display(program);

    };

  };

if (globalTrace)
    {printf("Leaving imaExpression\n");}

}


//Building function imaStatement from line: 126

function imaStatement(indent,statement) {
  
if (globalTrace)
    {printf("imaStatement at q/imaginary.qon:126\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString(stringify(car(statement)), "if")) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("if ");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    add1(indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    imaExpressionStart(add1(indent), second(statement));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(" then\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    imaBody(caller, add1(indent), cdr(third(statement)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("else\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    imaBody(caller, add1(indent), cdr(fourth(statement)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("end\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalString(stringify(car(statement)), "set")) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printIndent(indent);
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("%s = ", stringify(second(statement)));
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      imaExpressionStart(add1(indent), third(statement));
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf(";\n");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalString(stringify(car(statement)), "set-struct")) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printIndent(indent);
        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printf("%s.%s = ", stringify(second(statement)), stringify(third(statement)));
        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        imaExpressionStart(indent, fourth(statement));
        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printf(";\n");

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalString(stringify(car(statement)), "return")) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printIndent(indent);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf("return; ");
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( greaterthan(listLength(statement), 1)) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            imaExpressionStart(indent, second(statement));

          } else {
          };
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf("\n");

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printIndent(indent);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          imaExpressionStart(indent, statement);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf(";\n");

        };

      };

    };

  };

if (globalTrace)
    {printf("Leaving imaStatement\n");}

}


//Building function imaBody from line: 181

function imaBody(local_caller,indent,program) {
  var statement = NULL;

if (globalTrace)
    {printf("imaBody at q/imaginary.qon:181\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(program)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    statement = car(program);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    imaStatement(add1(indent), statement);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    imaBody(local_caller, indent, cdr(program));

  };

if (globalTrace)
    {printf("Leaving imaBody\n");}

}


//Building function imaFunctions from line: 192

function imaFunctions(indent,program) {
  
if (globalTrace)
    {printf("imaFunctions at q/imaginary.qon:192\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(program)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    imaFunction(indent, car(program));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    imaFunctions(indent, cdr(program));

  };

if (globalTrace)
    {printf("Leaving imaFunctions\n");}

}


//Building function imaTypeDecl from line: 202

function imaTypeDecl(l) {
  var name = "";
var body = NULL;

if (globalTrace)
    {printf("imaTypeDecl at q/imaginary.qon:202\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  name = stringify(first(l));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  body = cdr(l);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(listLength(l), 2)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s is ", name);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    displayList(body, 0, true);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(";\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printIndent(1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s is %s;\n", name, stringify(second(l)));

  };

if (globalTrace)
    {printf("Leaving imaTypeDecl\n");}

}


//Building function imaStructComponents from line: 227

function imaStructComponents(node) {
  
if (globalTrace)
    {printf("imaStructComponents at q/imaginary.qon:227\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    imaTypeDecl(car(node));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    imaStructComponents(cdr(node));

  };

if (globalTrace)
    {printf("Leaving imaStructComponents\n");}

}


//Building function imaStruct from line: 233

function imaStruct(node) {
  
if (globalTrace)
    {printf("imaStruct at q/imaginary.qon:233\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  imaStructComponents(cdr(car(node)));

if (globalTrace)
    {printf("Leaving imaStruct\n");}

}


//Building function imaTypeMap from line: 236

function imaTypeMap(aSym) {
  var symMap = NULL;

if (globalTrace)
    {printf("imaTypeMap at q/imaginary.qon:236\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( truthy(assoc(stringify(aSym), symMap))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cdr(assoc(stringify(aSym), symMap)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(aSym);

  };

if (globalTrace)
    {printf("Leaving imaTypeMap\n");}

}


//Building function imaType from line: 248

function imaType(node) {
  var name = "";
var body = NULL;

if (globalTrace)
    {printf("imaType at q/imaginary.qon:248\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  name = stringify(first(node));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  body = cdr(node);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isList(first(body))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\ntype %s is struct (\n", name);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    imaStruct(body);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(");\n");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("type");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    imaTypeDecl(node);

  };

if (globalTrace)
    {printf("Leaving imaType\n");}

}


//Building function imaTypes from line: 263

function imaTypes(indent,nodes) {
  
if (globalTrace)
    {printf("imaTypes at q/imaginary.qon:263\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(nodes)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    imaType(car(nodes));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    imaTypes(indent, cdr(nodes));

  };

if (globalTrace)
    {printf("Leaving imaTypes\n");}

}


//Building function imaProgram from line: 272

function imaProgram(program) {
  
if (globalTrace)
    {printf("imaProgram at q/imaginary.qon:272\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  imaIncludes(0, cdr(first(program)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\nTypes:\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  imaTypes(0, cdr(second(program)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\nFunctions:\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  imaFunctions(0, cdr(third(program)));

if (globalTrace)
    {printf("Leaving imaProgram\n");}

}


//Building function imaIncludes from line: 282

function imaIncludes(indent,nodes) {
  
if (globalTrace)
    {printf("imaIncludes at q/imaginary.qon:282\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("Includes: \n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  displayList(nodes, 0, true);

if (globalTrace)
    {printf("Leaving imaIncludes\n");}

}


//Building function imaCompile from line: 289

function imaCompile(filename) {
  var tree = NULL;

if (globalTrace)
    {printf("imaCompile at q/imaginary.qon:289\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = loadQuon("compiler.qon");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = loadIncludes(tree);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrowalk(tree);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrosingle(tree, "write-file", "imaWriteFile");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrosingle(tree, "read-file", "imaReadFile");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrosingle(tree, "string-length", "string.len");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrosingle(tree, "sub-string", "imaSubstring");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrosingle(tree, "stringLength", "string.len");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  imaProgram(tree);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("function main()\nglobalArgs = arg\nglobalArgsCount = #arg\nstart()\nend\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("main()");

if (globalTrace)
    {printf("Leaving imaCompile\n");}

}


//Building function bashdisplays from line: 5

function bashdisplays(s) {
  
if (globalTrace)
    {printf("bashdisplays at q/bash.qon:5\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", s);

if (globalTrace)
    {printf("Leaving bashdisplays\n");}

}


//Building function bashFunctionArgs from line: 11

function bashFunctionArgs(decls,argNum,indent) {
  
if (globalTrace)
    {printf("bashFunctionArgs at q/bash.qon:11\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(decls)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("local %s=\"%s%s", stringify(second(decls)), dollar(), stringify(boxInt(argNum)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\" ;\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashFunctionArgs(cdr(cdr(decls)), add(1, argNum), indent);

  };

if (globalTrace)
    {printf("Leaving bashFunctionArgs\n");}

}


//Building function bashExpression from line: 26

function bashExpression(tree,indent,statement) {
  var thing = NULL;

if (globalTrace)
    {printf("bashExpression at q/bash.qon:26\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isList(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equal(1, listLength(tree))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      display(car(tree));
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalBox(boxString("return"), car(tree))) {
      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        bashdisplays("()");

      };

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      thing = first(tree);
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalBox(boxSymbol("get-struct"), thing)) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printf("%s->%s", stringify(second(tree)), stringify(third(tree)));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalBox(boxSymbol("new"), thing)) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf("malloc(sizeof(%s))", stringify(third(tree)));

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( equalBox(boxSymbol("passthrough"), thing)) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("%s", stringify(second(tree)));

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            if ( equalBox(boxSymbol("binop"), thing)) {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf("(");
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              bashExpression(third(tree), indent, false);
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf(" %s ", stringify(second(tree)));
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              bashExpression(fourth(tree), indent, false);
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf(")");

            } else {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              if ( statement) {                if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

                printf("%s ", stringify(bashFuncMap(car(tree))));
                if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

                bashRecurList(cdr(tree), indent);

              } else {                if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

                printf("%s(%s ", dollar(), stringify(bashFuncMap(car(tree))));
                if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

                bashRecurList(cdr(tree), indent);
                if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

                printf(")");

              };

            };

          };

        };

      };

    };

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    display(bashVarOrLit(tree));

  };

if (globalTrace)
    {printf("Leaving bashExpression\n");}

}


//Building function bashVarOrLit from line: 102

function bashVarOrLit(a) {
  
if (globalTrace)
    {printf("bashVarOrLit at q/bash.qon:102\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("symbol", boxType(a))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(boxSymbol(stringConcatenate(dollar(), stringify(a))));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(a);

  };

if (globalTrace)
    {printf("Leaving bashVarOrLit\n");}

}


//Building function bashRecurList from line: 111

function bashRecurList(expr,indent) {
  
if (globalTrace)
    {printf("bashRecurList at q/bash.qon:111\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(expr)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashExpression(car(expr), indent, false);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(cdr(expr))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      bashdisplays("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      bashdisplays(" ");
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      bashRecurList(cdr(expr), indent);

    };

  };

if (globalTrace)
    {printf("Leaving bashRecurList\n");}

}


//Building function bashIf from line: 128

function bashIf(node,indent) {
  
if (globalTrace)
    {printf("bashIf at q/bash.qon:128\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  bashdisplays("if (( ");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  bashExpression(second(node), 0, false);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  bashdisplays(" )) ; then ");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  bashBody(cdr(third(node)), add1(indent));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  bashdisplays(" else ");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  bashBody(cdr(fourth(node)), add1(indent));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  bashdisplays("fi");

if (globalTrace)
    {printf("Leaving bashIf\n");}

}


//Building function bashSetStruct from line: 141

function bashSetStruct(node,indent) {
  
if (globalTrace)
    {printf("bashSetStruct at q/bash.qon:141\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s_%s%s=", dollar(), stringify(second(node)), dollar(), stringify(third(node)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  bashExpression(fourth(node), indent, false);

if (globalTrace)
    {printf("Leaving bashSetStruct\n");}

}


//Building function bashGetStruct from line: 152

function bashGetStruct(node,indent) {
  
if (globalTrace)
    {printf("bashGetStruct at q/bash.qon:152\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s%s_%s%s", dollar(), stringify(first(node)), dollar(), stringify(second(node)));

if (globalTrace)
    {printf("Leaving bashGetStruct\n");}

}


//Building function bashSet from line: 162

function bashSet(node,indent) {
  
if (globalTrace)
    {printf("bashSet at q/bash.qon:162\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  display(first(cdr(node)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("=");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  bashExpression(third(node), indent, false);

if (globalTrace)
    {printf("Leaving bashSet\n");}

}


//Building function bashReturn from line: 169

function bashReturn(node,indent) {
  
if (globalTrace)
    {printf("bashReturn at q/bash.qon:169\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(indent);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equal(listLength(node), 1)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashdisplays("return;");

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashdisplays("return ");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashExpression(cadr(node), indent, false);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashdisplays(";");

  };

if (globalTrace)
    {printf("Leaving bashReturn\n");}

}


//Building function bashStatement from line: 180

function bashStatement(node,indent) {
  
if (globalTrace)
    {printf("bashStatement at q/bash.qon:180\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalBox(boxString("set"), first(node))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashSet(node, indent);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( equalBox(boxString("set-struct"), first(node))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      bashSetStruct(node, indent);

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( equalBox(boxString("if"), first(node))) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        bashIf(node, indent);

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( equalBox(boxString("return"), first(node))) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          bashReturn(node, indent);

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          newLine(indent);
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          bashExpression(node, indent, true);

        };

      };

    };

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  bashdisplays(" \n");

if (globalTrace)
    {printf("Leaving bashStatement\n");}

}


//Building function bashBody from line: 198

function bashBody(tree,indent) {
  var code = NULL;

if (globalTrace)
    {printf("bashBody at q/bash.qon:198\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    code = tree;
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( isNil(code)) {
    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      code = car(tree);
      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( not(releaseMode)) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        printf("\nif (( $globalTrace )) ; then\n    caller=\"from %s:%s\"\nfi", stringify(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), stringify(getTagFail(car(code), boxString("line"), boxString("Line missing"))));

      } else {
      };

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( not(releaseMode)) {
    } else {
    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashStatement(code, indent);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashBody(cdr(tree), indent);

  };

if (globalTrace)
    {printf("Leaving bashBody\n");}

}


//Building function bashDeclarations from line: 221

function bashDeclarations(decls,indent) {
  var decl = NULL;

if (globalTrace)
    {printf("bashDeclarations at q/bash.qon:221\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(decls)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    decl = car(decls);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("local %s=\"", stringify(second(decl)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashExpression(third(decl), indent, false);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\";\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashDeclarations(cdr(decls), indent);

  };

if (globalTrace)
    {printf("Leaving bashDeclarations\n");}

}


//Building function bashFunction from line: 234

function bashFunction(node) {
  var name = NULL;

if (globalTrace)
    {printf("bashFunction at q/bash.qon:234\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  name = second(node);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("\n\n#Building function %s from line:%s", stringify(name), stringify(getTag(name, boxString("line"))));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  newLine(0);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isNil(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newLine(0);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("%s(", stringify(second(node)));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf(") {");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    newLine(1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashFunctionArgs(third(node), 1, 1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashDeclarations(cdr(fourth(node)), 1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( releaseMode) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("\nif (( $globalTrace )) ; then\n    echo \"%s at %s:%s \" $caller\nfi", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( releaseMode) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {
    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashBody(cdr(fifth(node)), 1);
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( releaseMode) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("");

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      printf("\nif (( $globalTrace ))\n    echo \"Leaving %s\\n\"\n", stringify(name));

    };
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n}\n");

  };

if (globalTrace)
    {printf("Leaving bashFunction\n");}

}


//Building function bashForwardDeclaration from line: 267

function bashForwardDeclaration(node) {
  
if (globalTrace)
    {printf("bashForwardDeclaration at q/bash.qon:267\n");}

if (globalTrace)
    {printf("Leaving bashForwardDeclaration\n");}

}


//Building function bashForwardDeclarations from line: 270

function bashForwardDeclarations(tree) {
  
if (globalTrace)
    {printf("bashForwardDeclarations at q/bash.qon:270\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashForwardDeclaration(car(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashForwardDeclarations(cdr(tree));

  };

if (globalTrace)
    {printf("Leaving bashForwardDeclarations\n");}

}


//Building function bashFunctions from line: 276

function bashFunctions(tree) {
  
if (globalTrace)
    {printf("bashFunctions at q/bash.qon:276\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(tree)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashFunction(car(tree));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashFunctions(cdr(tree));

  };

if (globalTrace)
    {printf("Leaving bashFunctions\n");}

}


//Building function bashIncludes from line: 282

function bashIncludes(nodes) {
  
if (globalTrace)
    {printf("bashIncludes at q/bash.qon:282\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "\n\n#define true 1\n#define false 0\n\n\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\nbool releaseMode = false;\n\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n");

if (globalTrace)
    {printf("Leaving bashIncludes\n");}

}


//Building function bashTypeDecl from line: 290

function bashTypeDecl(l) {
  
if (globalTrace)
    {printf("bashTypeDecl at q/bash.qon:290\n");}

if (globalTrace)
    {printf("Leaving bashTypeDecl\n");}

}


//Building function bashStructComponents from line: 294

function bashStructComponents(node) {
  
if (globalTrace)
    {printf("bashStructComponents at q/bash.qon:294\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(node)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashTypeDecl(car(node));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashStructComponents(cdr(node));

  };

if (globalTrace)
    {printf("Leaving bashStructComponents\n");}

}


//Building function bashStruct from line: 300

function bashStruct(node) {
  
if (globalTrace)
    {printf("bashStruct at q/bash.qon:300\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  bashStructComponents(cdr(node));

if (globalTrace)
    {printf("Leaving bashStruct\n");}

}


//Building function bashTypeMap from line: 303

function bashTypeMap(aSym) {
  var symMap = NULL;

if (globalTrace)
    {printf("bashTypeMap at q/bash.qon:303\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), NULL));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( truthy(assoc(stringify(aSym), symMap))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(cdr(assoc(stringify(aSym), symMap)));

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(aSym);

  };

if (globalTrace)
    {printf("Leaving bashTypeMap\n");}

}


//Building function bashFuncMap from line: 313

function bashFuncMap(aSym) {
  var symMap = NULL;

if (globalTrace)
    {printf("bashFuncMap at q/bash.qon:313\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( equalString("symbol", boxType(aSym))) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), NULL)))))));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( truthy(assoc(stringify(aSym), symMap))) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(cdr(assoc(stringify(aSym), symMap)));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      return(aSym);

    };

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return(aSym);

  };

if (globalTrace)
    {printf("Leaving bashFuncMap\n");}

}


//Building function bashType from line: 344

function bashType(node) {
  
if (globalTrace)
    {printf("bashType at q/bash.qon:344\n");}

if (globalTrace)
    {printf("Leaving bashType\n");}

}


//Building function bashTypes from line: 349

function bashTypes(nodes) {
  
if (globalTrace)
    {printf("bashTypes at q/bash.qon:349\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( isEmpty(nodes)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    return;

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashType(car(nodes));
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    bashTypes(cdr(nodes));

  };

if (globalTrace)
    {printf("Leaving bashTypes\n");}

}


//Building function bashCompile from line: 359

function bashCompile(filename) {
  var tree = NULL;
var replace = NULL;

if (globalTrace)
    {printf("bashCompile at q/bash.qon:359\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  qlog("//Scanning file...%s\n", filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = loadQuon(filename);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  qlog("//Building sexpr\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  qlog("Loading shim bash\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = buildProg(cons(boxString("q/shims/bash.qon"), getIncludes(tree)), getTypes(tree), getFunctions(tree));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  qlog("Loading all includes\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = loadIncludes(tree);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  qlog("Applying macros\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrowalk(tree);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), NULL));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  tree = macrolist(tree, stringConcatenate("q", "log"), replace);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  qlog("//Printing program\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  bashIncludes(cdr(first(tree)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  bashTypes(cdr(second(tree)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  bashdisplays("Box* globalStackTrace = NULL;\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  bashdisplays("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  bashForwardDeclarations(cdr(third(tree)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  bashdisplays("\n\n//End forward declarations\n\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  bashFunctions(cdr(third(tree)));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  bashdisplays("\n");
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  qlog("//Done printing program\n");

if (globalTrace)
    {printf("Leaving bashCompile\n");}

}


//Building function start from line: 4

function start() {
  var runTests = false;
var cmdLine = NULL;
var filename = NULL;
var runPerl = false;
var runJava = false;
var runAst = false;
var runNode = false;
var runLua = false;
var runIma = false;
var runAnsi2 = false;
var runAnsi3 = false;
var runBash = false;
var runTree = false;

if (globalTrace)
    {printf("start at compiler.qon:4\n");}
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  cmdLine = listReverse(argList(globalArgsCount, 0, globalArgs));
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( greaterthan(listLength(cmdLine), 1)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    filename = second(cmdLine);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    filename = boxString("compiler.qon");

  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  releaseMode = inList(boxString("--release"), cmdLine);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  runTests = inList(boxString("--test"), cmdLine);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  runJava = inList(boxString("--java"), cmdLine);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  runPerl = inList(boxString("--perl"), cmdLine);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  runAst = inList(boxString("--ast"), cmdLine);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  runTree = inList(boxString("--tree"), cmdLine);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  runNode = inList(boxString("--node"), cmdLine);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  runLua = inList(boxString("--lua"), cmdLine);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  runIma = inList(boxString("--ima"), cmdLine);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  runAnsi2 = inList(boxString("--ansi2"), cmdLine);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  runAnsi3 = inList(boxString("--ansi3"), cmdLine);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  runBash = inList(boxString("--bash"), cmdLine);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  globalTrace = inList(boxString("--trace"), cmdLine);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  globalStepTrace = inList(boxString("--steptrace"), cmdLine);
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( inList(boxString("--help"), cmdLine)) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("Usage: quon file [options]\n\nNote the options go after the file name\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("Options:\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("  --help      Display this help\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("  --release   Compile in release mode\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("  --test      Run the test suite\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("  --java      Compile to Java\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("  --perl      Compile to Perl\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("  --ast       Compile to the Abstract Syntax Tree\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("  --tree      Compile to an s-expression tree\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("  --node      Compile to Node.js\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("  --lua       Compile to Lua\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("  --ima       Compile to Imaginary, the human-friendly language\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("  --ansi2     Compile to ANSI C, (quon version 2)\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("  --ansi3     Compile to ANSI C (quon version 3)\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("  --bash      Compile to Bash\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("  --trace     Trace execution\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("  --steptrace Step trace execution\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("  --help      Display this help\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    exit(0);

  } else {
  };
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  if ( runTests) {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test0();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test1();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test2();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test3();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test4();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test5();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test6();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test7();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test8();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test9();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test10();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test12();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test13();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test15();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test16();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test17();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test18();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test19();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test20();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test21();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test22();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    test23();
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    printf("\n\nAfter all that hard work, I need a beer...\n");
    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    beers(9);

  } else {    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

    if ( runTree) {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      display(macrowalk(treeCompile(unBoxString(filename))));

    } else {      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

      if ( runAst) {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        astCompile(unBoxString(filename));

      } else {        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

        if ( runNode) {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          nodeCompile(unBoxString(filename));
          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          printf("\n");

        } else {          if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

          if ( runPerl) {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            perlCompile(unBoxString(filename));
            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            printf("\n");

          } else {            if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

            if ( runJava) {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              javaCompile(unBoxString(filename));
              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              printf("\n");

            } else {              if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

              if ( runLua) {                if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

                luaCompile(unBoxString(filename));
                if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

                printf("\n");

              } else {                if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

                if ( runIma) {                  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

                  imaCompile(unBoxString(filename));
                  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

                  printf("\n");

                } else {                  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

                  if ( runAnsi2) {                    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

                    ansi2Compile(unBoxString(filename));
                    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

                    printf("\n");

                  } else {                    if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

                    if ( runAnsi3) {                      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

                      ansi3Compile(unBoxString(filename));
                      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

                      printf("\n");

                    } else {                      if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

                      if ( runBash) {                        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

                        bashCompile(unBoxString(filename));
                        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

                        printf("\n");

                      } else {                        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

                        ansi3Compile(unBoxString(filename));
                        if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

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
  if (globalStepTrace) {console.log(new Error("StepTrace \n"));}

  return(0);

if (globalTrace)
    {printf("Leaving start\n");}

}

const [asfdasdf, ...qwerqwer] = process.argv;globalArgs = qwerqwer;globalArgsCount = qwerqwer.length;start();

