package quonverter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
class MyProgram {

public String caller ="";public void panic(String s) {System.exit(1);}
public void exit(Integer s) {System.exit(s);}
public int sub(int a, int b) { return a - b; }
public Integer mult(int a, int b) { return a * b; }
public boolean greaterthan(int a, int b) { return a > b; }
public double subf(double a, double b) { return a - b; }
public double multf(double a, double b) { return a * b; }
public boolean greaterthanf(double a, double b) { return a > b; }
public boolean equal(int a, int b) { return a == b; }
public boolean equalString(String a, String b) { return a.equals(b); }
public int string_length(String s) { return s.length();}
public String stringConcatenate(String s1, String s2) { return s1 + s2; }
public int strcmp(String s1, String s2) { return s1.compareTo(s2);}
public String read_file(String filename) {try { return new String(Files.readAllBytes(Paths.get(filename)));} catch (Exception e) {panic("Could not read file");return "";}}
public void write_file(String filename, String data) {try {Files.write(Paths.get(filename), data.getBytes("UTF-8"));} catch (Exception e) {panic("Could not write file");}}
public String sub_string(String s, int start, int length) {
return s.substring(start, start+length);
}



public String intToString(int num) { char c=(char) num;  String s=Character.toString(c); return s;}public String character(int num) { char c=(char) num;  String s=Character.toString(c); return s;}public String getStringArray(int index, String[] arr) { return arr[index];}
public class Box {

public String caller ="";  Box lis;
  String str;
  Integer i;
  String typ;
  boolean voi;
  boolean boo;
  Integer lengt;
  Box car;
  Box cdr;
  Box tag;

};
public class Pair extends Box {};
public class list extends Box {};
public boolean globalStackTrace = false;
public boolean globalStepTrace = false;
public boolean globalTrace = false;
public boolean releaseMode = false;
public String FILE = null;
public Integer LINE = 0;
public static Integer globalArgsCount = 0;
public static String globalArgs[];

public boolean isNil(Box p) {
    return p == null;
}




//Building function add from line: 19

public Integer add(Integer a,Integer b) {
    
  return(sub(a, sub(0, b)));
}


//Building function addf from line: 20

public double addf(double a,double b) {
    
  return(subf(a, subf(0, b)));
}


//Building function sub1 from line: 21

public Integer sub1(Integer a) {
    
  return(sub(a, 1));
}


//Building function add1 from line: 22

public Integer add1(Integer a) {
    
  return(add(a, 1));
}


//Building function clone from line: 24

public Box clone(Box b) {
  Box newb = null;
  
  newb = makeBox();  
  newb.typ = b.typ;  
  newb.tag = b.tag;  
  newb.lis = b.lis;  
  newb.str = b.str;  
  newb.i = b.i;  
  newb.lengt = b.lengt;  
  return(newb);
}


//Building function tern from line: 38

public Box tern(boolean cond,Box tr,Box fal) {
    
  if ( cond) {    
    return(tr);
  } else {    
    return(fal);
  }
}


//Building function ternString from line: 42

public String ternString(boolean cond,String tr,String fal) {
    
  if ( cond) {    
    return(tr);
  } else {    
    return(fal);
  }
}


//Building function ternList from line: 46

public Box ternList(boolean cond,Box tr,Box fal) {
    
  if ( cond) {    
    return(tr);
  } else {    
    return(fal);
  }
}


//Building function newVoid from line: 52

public Box newVoid() {
  Box newb = null;
  
  newb = makeBox();  
  newb.voi = true;  
  newb.typ = "void";  
  return(newb);
}


//Building function stackDump from line: 62

public void stackDump() {
    
  System.out.printf("");
if (globalTrace)
   System.out. printf("Leaving stackDump\n");

}


//Building function nop from line: 67

public void nop() {
    
  System.out.printf("");
if (globalTrace)
   System.out. printf("Leaving nop\n");

}


//Building function equalBox from line: 71

public boolean equalBox(Box a,Box b) {
    
  if ( isList(b)) {    
    return(false);
  } else {    
    if ( equalString("string", boxType(a))) {      
      return(equalString(unBoxString(a), stringify(b)));
    } else {      
      if ( equalString("bool", boxType(a))) {        
        return(andBool(unBoxBool(a), unBoxBool(b)));
      } else {        
        if ( equalString("symbol", boxType(a))) {          
          if ( equalString("symbol", boxType(b))) {            
            return(equalString(unBoxSymbol(a), unBoxSymbol(b)));
          } else {            
            return(false);
          }
        } else {          
          if ( equalString("int", boxType(a))) {            
            return(equal(unBoxInt(a), unBoxInt(b)));
          } else {            
            return(false);
          }
        }
      }
    }
  }
}


//Building function display from line: 92

public void display(Box l) {
    
  if ( isEmpty(l)) {    
    System.out.printf("nil ");    
    return;
  } else {    
    if ( isList(l)) {      
      System.out.printf("[");      
      displayList(l, 0, true);      
      System.out.printf("]");
    } else {      
      displayList(l, 0, true);
    }
  }
if (globalTrace)
   System.out. printf("Leaving display\n");

}


//Building function openBrace from line: 101

public String openBrace() {
    
  return("(");
}


//Building function closeBrace from line: 102

public String closeBrace() {
    
  return(")");
}


//Building function boxType from line: 107

public String boxType(Box b) {
    
  return(b.typ);
}


//Building function makeBox from line: 110

public Box makeBox() {
  Box b = null;
  
  b = new Box();  
  if ( isNil(b)) {    
    panic("failed to create box!");
  } else {
  }  
  b.tag = null;  
  b.car = null;  
  b.cdr = null;  
  b.lis = null;  
  b.typ = "None - error!";  
  return(b);
}


//Building function makePair from line: 125

public Box makePair() {
    
  return(makeBox());
}


//Building function boxString from line: 131

public Box boxString(String s) {
  Box b = null;
  
  b = makeBox();  
  b.str = s;  
  b.lengt = string_length(s);  
  b.typ = "string";  
  return(b);
}


//Building function boxSymbol from line: 141

public Box boxSymbol(String s) {
  Box b = null;
  
  b = boxString(s);  
  b.typ = "symbol";  
  return(b);
}


//Building function boxBool from line: 150

public Box boxBool(boolean boo) {
  Box b = null;
  
  b = makeBox();  
  b.boo = boo;  
  b.typ = "bool";  
  return(b);
}


//Building function boxInt from line: 159

public Box boxInt(Integer val) {
  Box b = null;
  
  b = makeBox();  
  b.i = val;  
  b.typ = "int";  
  return(b);
}


//Building function assertType from line: 168

public void assertType(String atype,Box abox,Integer line,String file) {
    
  if ( isNil(abox)) {    
    if ( equalString(atype, "nil")) {      
      return;
    } else {      
      return;
    }
  } else {    
    if ( equalString(atype, boxType(abox))) {      
      return;
    } else {      
      System.out.printf("Assertion failure at line %d, in file %s: provided value is not a '%s'!  It was actually '%s'. Contents:", line, file, atype, boxType(abox));      
      display(abox);      
      panic("Invalid type!");
    }
  }
}


//Building function unBoxString from line: 180

public String unBoxString(Box b) {
    
  assertType("string", b, 181, "q/base.qon");  
  return(b.str);
}


//Building function unBoxSymbol from line: 183

public String unBoxSymbol(Box b) {
    
  return(b.str);
}


//Building function unBoxBool from line: 184

public boolean unBoxBool(Box b) {
    
  return(b.boo);
}


//Building function unBoxInt from line: 185

public Integer unBoxInt(Box b) {
    
  return(b.i);
}


//Building function stringify_rec from line: 187

public String stringify_rec(Box b) {
    
  if ( isNil(b)) {    
    return("");
  } else {    
    return(stringConcatenate(stringify(car(b)), stringConcatenate(" ", stringify_rec(cdr(b)))));
  }
}


//Building function stringify from line: 199

public String stringify(Box b) {
    
  if ( isNil(b)) {    
    return("()");
  } else {    
    if ( equalString("string", boxType(b))) {      
      return(unBoxString(b));
    } else {      
      if ( equalString("bool", boxType(b))) {        
        if ( unBoxBool(b)) {          
          return("true");
        } else {          
          return("false");
        }
      } else {        
        if ( equalString("int", boxType(b))) {          
          return(intToString(unBoxInt(b)));
        } else {          
          if ( equalString("symbol", boxType(b))) {            
            return(unBoxSymbol(b));
          } else {            
            if ( equalString("list", boxType(b))) {              
              return(stringConcatenate("(", stringConcatenate(stringify(car(b)), stringConcatenate(" ", stringConcatenate(stringify_rec(cdr(b)), ")")))));
            } else {              
              return(stringConcatenate("Unsupported type: ", boxType(b)));
            }
          }
        }
      }
    }
  }
}


//Building function hasTag from line: 234

public boolean hasTag(Box aBox,Box key) {
    
  if ( isNil(aBox)) {    
    return(false);
  } else {    
    return(isNotFalse(assoc(stringify(key), aBox.tag)));
  }
}


//Building function getTag from line: 241

public Box getTag(Box aBox,Box key) {
    
  if ( false) {    
    System.out.printf("Getting %s from: ", stringify(key));    
    display(alistKeys(aBox.tag));    
    System.out.printf("\n");
  } else {    
    System.out.printf("");
  }  
  return(cdr(assoc(stringify(key), aBox.tag)));
}


//Building function getTagFail from line: 253

public Box getTagFail(Box aBox,Box key,Box onFail) {
    
  if ( hasTag(aBox, key)) {    
    return(getTag(aBox, key));
  } else {    
    return(onFail);
  }
}


//Building function assocExists from line: 264

public boolean assocExists(String key,Box aBox) {
    
  if ( isNil(aBox)) {    
    return(false);
  } else {    
    return(isNotFalse(assoc(key, aBox)));
  }
}


//Building function assocFail from line: 273

public Box assocFail(String key,Box aBox,Box onFail) {
    
  if ( assocExists(key, aBox)) {    
    return(assoc(key, aBox));
  } else {    
    return(cons(boxString(key), onFail));
  }
}


//Building function assocPanic from line: 280

public Box assocPanic(String key,Box aBox,String onFail) {
    
  if ( assocExists(key, aBox)) {    
    return(assoc(key, aBox));
  } else {    
    panic(onFail);
  }  
  panic("Inconceivable");  
  return(null);
}


//Building function setTag from line: 292

public Box setTag(Box key,Box val,Box aStruct) {
    
  aStruct.tag = alistCons(key, val, aStruct.tag);  
  return(aStruct);
}


//Building function locPanic from line: 301

public void locPanic(String file,String line,String message) {
    
  System.out.printf("%s %s:%s\n", file, line, message);  
  panic(message);
if (globalTrace)
   System.out. printf("Leaving locPanic\n");

}


//Building function truthy from line: 307

public boolean truthy(Box aVal) {
    
  return(isNotFalse(aVal));
}


//Building function isNotFalse from line: 312

public boolean isNotFalse(Box aVal) {
    
  if ( equalString(boxType(aVal), "bool")) {    
    if ( unBoxBool(aVal)) {      
      return(true);
    } else {      
      return(false);
    }
  } else {    
    return(true);
  }
}


//Building function toStr from line: 321

public Box toStr(Box thing) {
    
  return(boxString(stringify(thing)));
}


//Building function listLast from line: 325

public Box listLast(Box alist) {
    
  if ( isEmpty(cdr(alist))) {    
    return(car(alist));
  } else {    
    return(listLast(cdr(alist)));
  }
}


//Building function newLine from line: 334

public void newLine(Integer indent) {
    
  System.out.printf("\n");  
  printIndent(indent);
if (globalTrace)
   System.out. printf("Leaving newLine\n");

}


//Building function printIndent from line: 338

public void printIndent(Integer ii) {
    
  if ( greaterthan(ii, 0)) {    
    System.out.printf("  ");    
    printIndent(sub1(ii));
  } else {    
    return;
  }
if (globalTrace)
   System.out. printf("Leaving printIndent\n");

}


//Building function stringIndent from line: 345

public String stringIndent(Integer ii) {
    
  if ( greaterthan(ii, 0)) {    
    return(stringConcatenate("  ", stringIndent(sub1(ii))));
  } else {    
    return("");
  }
}


//Building function argList from line: 360

public Box argList(Integer count,Integer pos,String[] args) {
    
  if ( greaterthan(count, pos)) {    
    return(cons(boxString(getStringArray(pos, args)), argList(count, add1(pos), args)));
  } else {    
    return(null);
  }
}


//Building function tron from line: 370

public void tron() {
    
  globalTrace = true;
}


//Building function troff from line: 371

public void troff() {
    
  globalTrace = false;
}


//Building function stron from line: 372

public void stron() {
    
  globalStepTrace = true;
}


//Building function stroff from line: 373

public void stroff() {
    
  globalStepTrace = false;
}


//Building function filterVoid from line: 8

public Box filterVoid(Box l) {
  Box token = null;
  
  if ( isEmpty(l)) {    
    return(emptyList());
  } else {    
    token = car(l);    
    if ( equalString("void", token.typ)) {      
      return(filterVoid(cdr(l)));
    } else {      
      return(cons(token, filterVoid(cdr(l))));
    }
  }
}


//Building function filterTokens from line: 20

public Box filterTokens(Box l) {
  Box token = null;
  
  if ( isEmpty(l)) {    
    return(emptyList());
  } else {    
    token = car(l);    
    if ( equalString(boxType(token), "symbol")) {      
      if ( equalString("__LINE__", stringify(token))) {        
        return(cons(getTagFail(token, boxString("line"), boxInt(-1)), filterTokens(cdr(l))));
      } else {        
        if ( equalString("__COLUMN__", stringify(token))) {          
          return(cons(getTagFail(token, boxString("column"), boxInt(-1)), filterTokens(cdr(l))));
        } else {          
          if ( equalString("__FILE__", stringify(token))) {            
            return(cons(getTagFail(token, boxString("filename"), boxString("Unknown file")), filterTokens(cdr(l))));
          } else {            
            return(cons(token, filterTokens(cdr(l))));
          }
        }
      }
    } else {      
      return(cons(token, filterTokens(cdr(l))));
    }
  }
}


//Building function finish_token from line: 54

public Box finish_token(String prog,Integer start,Integer len,Integer line,Integer column,String filename) {
  Box token = null;
  
  if ( greaterthan(len, 0)) {    
    token = boxSymbol(sub_string(prog, start, len));    
    token.tag = alistCons(boxString("filename"), boxString(filename), alistCons(boxString("column"), boxInt(column), alistCons(boxString("line"), boxInt(line), alistCons(boxString("totalCharPos"), boxInt(start), null))));    
    return(token);
  } else {    
    return(newVoid());
  }
}


//Building function readString from line: 69

public String readString(String prog,Integer start,Integer len) {
  String token = "";
  
  token = sub_string(prog, sub1(add(start, len)), 1);  
  if ( equalString("\"", token)) {    
    return(sub_string(prog, start, sub1(len)));
  } else {    
    if ( equalString("\\", token)) {      
      return(readString(prog, start, add(2, len)));
    } else {      
      return(readString(prog, start, add1(len)));
    }
  }
}


//Building function readComment from line: 80

public String readComment(String prog,Integer start,Integer len) {
  String token = "";
  
  if ( greaterthan(add(start, len), string_length(prog))) {    
    return("");
  } else {    
    token = sub_string(prog, sub1(add(start, len)), 1);    
    if ( isLineBreak(token)) {      
      return(sub_string(prog, start, sub1(len)));
    } else {      
      return(readComment(prog, start, add1(len)));
    }
  }
}


//Building function isWhiteSpace from line: 91

public boolean isWhiteSpace(String s) {
    
  if ( equalString(" ", s)) {    
    return(true);
  } else {    
    if ( equalString("\t", s)) {      
      return(true);
    } else {      
      if ( equalString("\n", s)) {        
        return(true);
      } else {        
        if ( equalString("\r", s)) {          
          return(true);
        } else {          
          return(false);
        }
      }
    }
  }
}


//Building function isLineBreak from line: 108

public boolean isLineBreak(String s) {
    
  if ( equalString("\n", s)) {    
    return(true);
  } else {    
    if ( equalString("\r", s)) {      
      return(true);
    } else {      
      return(false);
    }
  }
}


//Building function incForNewLine from line: 115

public Integer incForNewLine(Box token,Integer val) {
    
  if ( equalString("\n", stringify(token))) {    
    return(add1(val));
  } else {    
    return(val);
  }
}


//Building function annotateReadPosition from line: 123

public Box annotateReadPosition(String filename,Integer linecount,Integer column,Integer start,Box newBox) {
    
  return(setTag(boxString("filename"), boxString(filename), setTag(boxString("column"), boxInt(column), setTag(boxString("line"), boxInt(linecount), setTag(boxString("totalCharPos"), boxInt(start), newBox)))));
}


//Building function scan from line: 135

public Box scan(String prog,Integer start,Integer len,Integer linecount,Integer column,String filename) {
  Box token = null;
String newString = "";
Box newBox = null;
  
  if ( greaterthan(string_length(prog), sub(start, sub(0, len)))) {    
    token = boxSymbol(sub_string(prog, sub1(add(start, len)), 1));    
    token.tag = alistCons(boxString("totalCharPos"), boxInt(start), null);    
    if ( isOpenBrace(token)) {      
      return(cons(finish_token(prog, start, sub1(len), linecount, column, filename), cons(boxSymbol(openBrace()), scan(prog, add1(start), 1, linecount, add1(column), filename))));
    } else {      
      if ( isCloseBrace(token)) {        
        return(cons(finish_token(prog, start, sub1(len), linecount, column, filename), cons(annotateReadPosition(filename, linecount, column, start, boxSymbol(closeBrace())), scan(prog, add(start, len), 1, linecount, add1(column), filename))));
      } else {        
        if ( isWhiteSpace(stringify(token))) {          
          return(cons(finish_token(prog, start, sub1(len), linecount, column, filename), scan(prog, add(start, len), 1, incForNewLine(token, linecount), 0, filename)));
        } else {          
          if ( equalBox(boxSymbol(";"), token)) {            
            return(scan(prog, add(start, add1(add1(string_length(readComment(prog, add1(start), len))))), 1, add1(linecount), 0, filename));
          } else {            
            if ( equalBox(boxSymbol("\""), token)) {              
              newString = readString(prog, add1(start), len);              
              newBox = annotateReadPosition(filename, linecount, column, start, boxString(newString));              
              return(cons(newBox, scan(prog, add(start, add1(add1(string_length(newString)))), 1, linecount, add1(column), filename)));
            } else {              
              return(scan(prog, start, sub(len, -1), linecount, add1(column), filename));
            }
          }
        }
      }
    }
  } else {    
    return(emptyList());
  }
}


//Building function isOpenBrace from line: 175

public boolean isOpenBrace(Box b) {
    
  if ( equalBox(boxSymbol(openBrace()), b)) {    
    return(true);
  } else {    
    if ( equalBox(boxSymbol("["), b)) {      
      return(true);
    } else {      
      return(false);
    }
  }
}


//Building function isCloseBrace from line: 184

public boolean isCloseBrace(Box b) {
    
  if ( equalBox(boxSymbol(closeBrace()), b)) {    
    return(true);
  } else {    
    if ( equalBox(boxSymbol("]"), b)) {      
      return(true);
    } else {      
      return(false);
    }
  }
}


//Building function skipList from line: 197

public Box skipList(Box l) {
  Box b = null;
  
  if ( isEmpty(l)) {    
    return(emptyList());
  } else {    
    b = car(l);    
    if ( isOpenBrace(b)) {      
      return(skipList(skipList(cdr(l))));
    } else {      
      if ( isCloseBrace(b)) {        
        return(cdr(l));
      } else {        
        return(skipList(cdr(l)));
      }
    }
  }
}


//Building function makeNode from line: 219

public Box makeNode(String name,String subname,Box code,Box children) {
    
  return(cons(boxSymbol("node"), alistCons(boxSymbol("line"), getTagFail(code, boxString("line"), boxInt(-1)), cons(cons(boxSymbol("name"), boxString(name)), cons(cons(boxSymbol("subname"), boxString(subname)), cons(cons(boxSymbol("code"), code), alistCons(boxSymbol("children"), children, emptyList())))))));
}


//Building function addToNode from line: 235

public Box addToNode(Box key,Box val,Box node) {
    
  return(cons(boxSymbol("node"), alistCons(key, val, cdr(node))));
}


//Building function makeStatementNode from line: 240

public Box makeStatementNode(String name,String subname,Box code,Box children,Box functionName) {
    
  return(addToNode(boxSymbol("functionName"), functionName, makeNode(name, subname, code, children)));
}


//Building function astExpression from line: 245

public Box astExpression(Box tree) {
    
  if ( isList(tree)) {    
    return(makeNode("expression", "expression", null, astSubExpression(tree)));
  } else {    
    return(astSubExpression(tree));
  }
}


//Building function astSubExpression from line: 253

public Box astSubExpression(Box tree) {
    
  if ( isEmpty(tree)) {    
    return(emptyList());
  } else {    
    if ( isList(tree)) {      
      return(cons(astExpression(car(tree)), astSubExpression(cdr(tree))));
    } else {      
      return(makeNode("expression", "leaf", tree, null));
    }
  }
}


//Building function astIf from line: 264

public Box astIf(Box tree,Box fname) {
    
  if ( equalBox(boxString("then"), car(second(tree)))) {    
    nop();
  } else {    
    System.out.printf("Error at %s:%s!  If statement is missing the true branch.\n\n", stringify(getTag(car(first(tree)), boxString("filename"))), stringify(getTag(car(first(tree)), boxString("line"))));    
    panic("Missing true branch in if statement!  All if statements must have a true and false branch, like this:\n\n(if hungryForApples\n(then (printf \"yes!\"))\n(else (printf \"no!\")))\n\n\n");
  }  
  if ( equalBox(boxString("else"), car(third(tree)))) {    
    nop();
  } else {    
    System.out.printf("Error at %s:%s!  If statement is missing the false branch.\n\n", stringify(getTag(car(first(tree)), boxString("filename"))), stringify(getTag(car(first(tree)), boxString("line"))));    
    panic("Missing false branch in if statement!  All if statements must have a true and false branch, like this:\n\n(if hungryForApples\n(then (printf \"yes!\"))\n(else (printf \"no!\")))\n\n\n");
  }  
  return(makeNode("statement", "if", tree, cons(cons(astExpression(first(tree)), null), cons(astBody(cdr(second(tree)), fname), cons(astBody(cdr(third(tree)), fname), null)))));
}


//Building function astSetStruct from line: 285

public Box astSetStruct(Box tree) {
    
  return(makeNode("statement", "structSetter", tree, astExpression(third(tree))));
}


//Building function astSet from line: 290

public Box astSet(Box tree) {
    
  return(makeNode("statement", "setter", tree, astExpression(second(tree))));
}


//Building function astGetStruct from line: 295

public Box astGetStruct(Box tree) {
    
  return(makeNode("expression", "structGetter", tree, null));
}


//Building function astReturnVoid from line: 298

public Box astReturnVoid(Box fname) {
    
  return(makeStatementNode("statement", "returnvoid", null, null, fname));
}


//Building function astStatement from line: 302

public Box astStatement(Box tree,Box fname) {
    
  if ( isList(tree)) {    
    nop();
  } else {    
    System.out.printf("Error at %s:%s!  Statement must be a list.\n\n", stringify(getTag(car(first(tree)), boxString("filename"))), stringify(getTag(car(first(tree)), boxString("line"))));    
    panic("A statement must be a list: (printf \"Hello\")\n\n\n");
  }  
  if ( equalBox(boxString("if"), car(tree))) {    
    return(astIf(cdr(tree), fname));
  } else {    
    if ( equalBox(boxString("set"), car(tree))) {      
      return(astSet(cdr(tree)));
    } else {      
      if ( equalBox(boxString("get-struct"), car(tree))) {        
        System.out.printf("Choosing get-struct statement\n");        
        return(astGetStruct(cdr(tree)));
      } else {        
        if ( equalBox(boxString("set-struct"), car(tree))) {          
          return(astSetStruct(cdr(tree)));
        } else {          
          if ( equalBox(boxString("return"), car(tree))) {            
            if ( equal(listLength(tree), 1)) {              
              return(astReturnVoid(fname));
            } else {              
              return(makeStatementNode("statement", "return", tree, makeNode("expression", "expression", tree, astExpression(tree)), fname));
            }
          } else {            
            return(makeStatementNode("statement", "statement", tree, makeNode("expression", "expression", tree, astExpression(tree)), fname));
          }
        }
      }
    }
  }
}


//Building function astBody from line: 340

public Box astBody(Box tree,Box fname) {
    
  if ( isEmpty(tree)) {    
    return(emptyList());
  } else {    
    return(cons(astStatement(car(tree), fname), astBody(cdr(tree), fname)));
  }
}


//Building function astFunction from line: 348

public Box astFunction(Box tree) {
  String file = "";
String line = "";
Box fname = null;
  
  fname = second(tree);  
  line = stringify(getTag(fname, boxString("line")));  
  file = stringify(getTag(fname, boxString("filename")));  
  if ( greaterthan(1, listLength(tree))) {    
    locPanic(file, line, "Malformed function, seems to be empty");
  } else {
  }  
  if ( greaterthan(2, listLength(tree))) {    
    locPanic(file, line, "Malformed function, expected function name");
  } else {
  }  
  if ( greaterthan(3, listLength(tree))) {    
    locPanic(file, line, "Malformed function, expected argument list");
  } else {
  }  
  if ( greaterthan(4, listLength(tree))) {    
    locPanic(file, line, "Malformed function, expected variable declarations");
  } else {
  }  
  if ( greaterthan(5, listLength(tree))) {    
    locPanic(file, line, "Malformed function, expected body");
  } else {
  }  
  return(alistCons(boxSymbol("file"), getTag(fname, boxString("filename")), alistCons(boxSymbol("line"), getTag(fname, boxString("line")), cons(cons(boxSymbol("name"), boxString("function")), cons(cons(boxSymbol("subname"), second(tree)), cons(cons(boxSymbol("declarations"), cdr(fourth(tree))), cons(cons(boxSymbol("intype"), third(tree)), cons(cons(boxSymbol("outtype"), car(tree)), cons(cons(boxSymbol("children"), astBody(cdr(fifth(tree)), fname)), emptyList())))))))));
}


//Building function astFunctionList from line: 381

public Box astFunctionList(Box tree) {
    
  if ( isEmpty(tree)) {    
    return(emptyList());
  } else {    
    return(cons(astFunction(car(tree)), astFunctionList(cdr(tree))));
  }
}


//Building function astFunctions from line: 389

public Box astFunctions(Box tree) {
    
  if ( equalBox(boxString("functions"), car(tree))) {    
    return(makeNode("functions", "functions", tree, astFunctionList(cdr(tree))));
  } else {    
    panic("Functions section not found!  Every program must have a function section, even if you don't define any functions, although that is a rather pointless program.  Your function section should look like:'\n\n(return_type function_name (arg1 arg2 arg3 ...) (declare types) (body (statement)(statement)))\n\n\nThe function section must be directly after the types section.");    
    return(null);
  }
}


//Building function loadLib from line: 397

public Box loadLib(String path) {
  String programStr = "";
Box tree = null;
Box library = null;
  
  programStr = read_file(path);  
  tree = readSexpr(programStr, path);  
  tree = macrowalk(tree);  
  library = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), null)));  
  return(library);
}


//Building function astInclude from line: 413

public Box astInclude(Box tree) {
    
  return(loadLib(stringify(tree)));
}


//Building function astIncludeList from line: 416

public Box astIncludeList(Box tree) {
    
  if ( isEmpty(tree)) {    
    return(emptyList());
  } else {    
    return(cons(astInclude(car(tree)), astIncludeList(cdr(tree))));
  }
}


//Building function astIncludes from line: 423

public Box astIncludes(Box tree) {
    
  if ( equalBox(boxString("includes"), car(tree))) {    
    return(makeNode("includes", "includes", tree, astIncludeList(cdr(tree))));
  } else {    
    panic("Includes section not found!  Every program must have an include section, even if you don't import any libraries.  Your include section should look like:'\n\n(includes file1.qon file.qon)\n\n\nThe includes section must be the first section of the file.");    
    return(null);
  }
}


//Building function astStruct from line: 431

public Box astStruct(Box tree) {
    
  return(makeNode("type", "struct", tree, null));
}


//Building function astType from line: 434

public Box astType(Box tree) {
    
  if ( isList(cadr(tree))) {    
    return(astStruct(tree));
  } else {    
    return(makeNode("type", "type", tree, null));
  }
}


//Building function astTypeList from line: 440

public Box astTypeList(Box tree) {
    
  if ( isEmpty(tree)) {    
    return(emptyList());
  } else {    
    return(cons(astType(car(tree)), astTypeList(cdr(tree))));
  }
}


//Building function astTypes from line: 446

public Box astTypes(Box tree) {
    
  if ( isNil(tree)) {    
    panic("Empty or absent types section");    
    return(boxString("!!!Fuck"));
  } else {    
    if ( equalBox(boxString("types"), car(tree))) {      
      return(makeNode("types", "types", tree, astTypeList(cdr(tree))));
    } else {      
      panic("Types section not found!  Every program must have a types section, even if you don't define any types");      
      System.out.printf("Types section not found!  Every program must have a types section, even if you don't define any types");      
      return(boxString("!!!Fuck"));
    }
  }
}


//Building function declarationsof from line: 464

public Box declarationsof(Box ass) {
    
  return(cdr(assocPanic("declarations", cdr(ass), "Cons list has no declarations key")));
}


//Building function codeof from line: 467

public Box codeof(Box ass) {
    
  return(cdr(assocPanic("code", cdr(ass), "Given cons list does not contain a code key")));
}


//Building function functionNameof from line: 470

public Box functionNameof(Box ass) {
    
  return(cdr(assoc("functionName", cdr(ass))));
}


//Building function nodeof from line: 473

public Box nodeof(Box ass) {
    
  if ( equalBox(boxBool(false), assoc("node", cdr(ass)))) {    
    System.out.printf("Given list does not contain nodes");    
    return(boxBool(false));
  } else {    
    return(cdr(assoc("node", cdr(ass))));
  }
}


//Building function lineof from line: 481

public Box lineof(Box ass) {
    
  return(cdr(assocFail("line", cdr(ass), boxInt(-1))));
}


//Building function subnameof from line: 486

public Box subnameof(Box ass) {
    
  return(cdr(assoc("subname", cdr(ass))));
}


//Building function nameof from line: 489

public Box nameof(Box ass) {
    
  return(cdr(assoc("name", cdr(ass))));
}


//Building function childrenof from line: 492

public Box childrenof(Box ass) {
    
  return(cdr(assoc("children", cdr(ass))));
}


//Building function isNode from line: 496

public boolean isNode(Box val) {
    
  if ( isEmpty(val)) {    
    return(false);
  } else {    
    if ( isList(val)) {      
      if ( equalBox(boxSymbol("node"), car(val))) {        
        return(true);
      } else {        
        return(false);
      }
    } else {      
      return(false);
    }
  }
}


//Building function isLeaf from line: 512

public boolean isLeaf(Box n) {
    
  return(equalBox(boxString("leaf"), subnameof(n)));
}


//Building function noStackTrace from line: 515

public Box noStackTrace() {
    
  return(cons(boxString("boxType"), cons(boxString("stringify"), cons(boxString("isEmpty"), cons(boxString("unBoxString"), cons(boxString("isList"), cons(boxString("unBoxBool"), cons(boxString("unBoxSymbol"), cons(boxString("equalBox"), cons(boxString("assoc"), cons(boxString("inList"), cons(boxString("unBoxInt"), cons(boxString("listLength"), cons(boxString("stroff"), cons(boxString("troff"), cons(boxString("tron"), cons(boxString("stron"), cons(boxString("car"), cons(boxString("cdr"), cons(boxString("cons"), cons(boxString("stackTracePush"), cons(boxString("stackTracePop"), cons(boxString("assertType"), cons(boxString("boxString"), cons(boxString("boxSymbol"), cons(boxString("boxInt"), null))))))))))))))))))))))))));
}


//Building function treeCompile from line: 547

public Box treeCompile(String filename) {
  String programStr = "";
Box tree = null;
  
  programStr = read_file(filename);  
  tree = readSexpr(programStr, filename);  
  return(tree);
}


//Building function astBuild from line: 553

public Box astBuild(String filename) {
  String programStr = "";
Box tree = null;
Box program = null;
  
  programStr = read_file(filename);  
  tree = readSexpr(programStr, filename);  
  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), null)));  
  program = mergeIncludes(program);  
  return(program);
}


//Building function astCompile from line: 570

public void astCompile(String filename) {
  Box tree = null;
Box replace = null;
  
  tree = loadQuon(filename);  
  System.err.printf("Final program: \n");  
  tree = loadIncludes(tree);  
  tree = macrowalk(tree);  
  tree = macrosingle(tree, "write-file", "luaWriteFile");  
  tree = macrosingle(tree, "read-file", "luaReadFile");  
  tree = macrosingle(tree, "string-length", "string.len");  
  tree = macrosingle(tree, "sub-string", "luaSubstring");  
  tree = macrosingle(tree, "stringLength", "string.len");  
  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), null));  
  tree = macrolist(tree, stringConcatenate("q", "log"), replace);  
  displayList(tree, 0, true);  
  System.err.printf("Transformed tree");  
  System.out.printf("\n");
if (globalTrace)
   System.out. printf("Leaving astCompile\n");

}


//Building function mergeIncludes from line: 594

public Box mergeIncludes(Box program) {
    
  return(merge_recur(childrenof(cdr(cdr(assocPanic("includes", program, "Program lacks include section")))), program));
}


//Building function merge_recur from line: 601

public Box merge_recur(Box incs,Box program) {
    
  if ( greaterthan(listLength(incs), 0)) {    
    return(mergeInclude(car(incs), merge_recur(cdr(incs), program)));
  } else {    
    return(program);
  }
}


//Building function mergeInclude from line: 609

public Box mergeInclude(Box inc,Box program) {
  Box newProgram = null;
Box oldfunctionsnode = null;
Box oldfunctions = null;
Box newfunctions = null;
Box newFunctionNode = null;
Box functions = null;
Box oldtypesnode = null;
Box oldtypes = null;
Box newtypes = null;
Box newTypeNode = null;
Box types = null;
  
  if ( isNil(inc)) {    
    return(program);
  } else {    
    functions = childrenof(cdr(assocPanic("functions", inc, "Included file has no functions section")));    
    oldfunctionsnode = cdr(assocPanic("functions", program, "Current module has no functions section"));    
    oldfunctions = childrenof(oldfunctionsnode);    
    newfunctions = concatLists(functions, oldfunctions);    
    newFunctionNode = cons(boxSymbol("node"), alistCons(boxSymbol("children"), newfunctions, cdr(oldfunctionsnode)));    
    types = childrenof(cdr(assocPanic("types", inc, "Included file has no types section")));    
    oldtypesnode = cdr(assocPanic("types", program, "Current module has no types section"));    
    oldtypes = childrenof(oldtypesnode);    
    newtypes = concatLists(types, oldtypes);    
    newTypeNode = cons(boxSymbol("node"), alistCons(boxSymbol("children"), newtypes, cdr(oldtypesnode)));    
    newProgram = alistCons(boxString("functions"), newFunctionNode, alistCons(boxString("types"), newTypeNode, alistCons(boxString("includes"), cons(boxSymbol("includes"), null), newProgram)));    
    return(newProgram);
  }
}


//Building function macrowalk from line: 5

public Box macrowalk(Box l) {
    
  if ( isEmpty(l)) {    
    return(null);
  } else {    
    if ( isList(l)) {      
      if ( equalString(stringConcatenate("box", "List"), stringify(car(l)))) {        
        return(car(doBoxList(cdr(l))));
      } else {
      }      
      if ( equalString(stringConcatenate("string", "List"), stringify(car(l)))) {        
        return(car(doStringList(cdr(l))));
      } else {
      }      
      if ( equalString(stringConcatenate("symbol", "List"), stringify(car(l)))) {        
        return(car(doSymbolList(cdr(l))));
      } else {
      }      
      if ( equalString(stringConcatenate("multi", "List"), stringify(car(l)))) {        
        return(car(doMultiList(cdr(l))));
      } else {
      }      
      if ( equalString(stringConcatenate("makeL", "ist"), stringify(car(l)))) {        
        return(doMakeList(cdr(l)));
      } else {
      }      
      return(cons(macrowalk(car(l)), macrowalk(cdr(l))));
    } else {      
      return(l);
    }
  }
}


//Building function macrosingle from line: 56

public Box macrosingle(Box l,String search,String replace) {
  Box val = null;
  
  if ( isEmpty(l)) {    
    return(null);
  } else {    
    if ( isList(l)) {      
      return(cons(macrosingle(car(l), search, replace), macrosingle(cdr(l), search, replace)));
    } else {      
      if ( equalString(search, stringify(l))) {        
        val = clone(l);        
        val.str = replace;        
        return(val);
      } else {
      }      
      return(l);
    }
  }
}


//Building function macrolist from line: 80

public Box macrolist(Box l,String search,Box replace) {
  Box val = null;
  
  if ( isEmpty(l)) {    
    return(null);
  } else {    
    if ( isList(l)) {      
      if ( equalString(search, stringify(car(l)))) {        
        return(concatLists(replace, macrolist(cdr(l), search, replace)));
      } else {        
        return(cons(macrolist(car(l), search, replace), macrolist(cdr(l), search, replace)));
      }
    } else {      
      return(l);
    }
  }
}


//Building function car from line: 9

public Box car(Box l) {
    
  if ( isNil(l)) {    
    System.out.printf("Cannot call car on empty list!\n");    
    panic("Cannot call car on empty list!\n");    
    return(null);
  } else {    
    assertType("list", l, 18, "q/lists.qon");    
    if ( isNil(l.car)) {      
      return(null);
    } else {      
      return(l.car);
    }
  }
}


//Building function cdr from line: 23

public Box cdr(Box l) {
    
  assertType("list", l, 25, "q/lists.qon");  
  if ( isEmpty(l)) {    
    System.out.printf("Attempt to cdr an empty list!!!!\n");    
    panic("Attempt to cdr an empty list!!!!\n");    
    return(null);
  } else {    
    return(l.cdr);
  }
}


//Building function cons from line: 33

public Box cons(Box data,Box l) {
  Box p = null;
  
  p = makePair();  
  p.cdr = l;  
  p.car = data;  
  p.typ = "list";  
  return(p);
}


//Building function caar from line: 45

public Box caar(Box l) {
    
  return(car(car(l)));
}


//Building function cadr from line: 46

public Box cadr(Box l) {
    
  return(car(cdr(l)));
}


//Building function caddr from line: 47

public Box caddr(Box l) {
    
  return(car(cdr(cdr(l))));
}


//Building function cadddr from line: 48

public Box cadddr(Box l) {
    
  return(car(cdr(cdr(cdr(l)))));
}


//Building function caddddr from line: 49

public Box caddddr(Box l) {
    
  return(car(cdr(cdr(cdr(cdr(l))))));
}


//Building function cddr from line: 50

public Box cddr(Box l) {
    
  return(cdr(cdr(l)));
}


//Building function first from line: 51

public Box first(Box l) {
    
  return(car(l));
}


//Building function second from line: 52

public Box second(Box l) {
    
  return(cadr(l));
}


//Building function third from line: 53

public Box third(Box l) {
    
  return(caddr(l));
}


//Building function fourth from line: 54

public Box fourth(Box l) {
    
  return(cadddr(l));
}


//Building function fifth from line: 55

public Box fifth(Box l) {
    
  return(caddddr(l));
}


//Building function isList from line: 58

public boolean isList(Box b) {
    
  if ( isNil(b)) {    
    return(true);
  } else {    
    return(equalString("list", b.typ));
  }
}


//Building function emptyList from line: 65

public Box emptyList() {
    
  return(null);
}


//Building function isEmpty from line: 67

public boolean isEmpty(Box b) {
    
  if ( isNil(b)) {    
    return(true);
  } else {    
    return(false);
  }
}


//Building function listLength from line: 74

public Integer listLength(Box l) {
    
  if ( isEmpty(l)) {    
    return(0);
  } else {    
    return(add1(listLength(cdr(l))));
  }
}


//Building function alistCons from line: 83

public Box alistCons(Box key,Box value,Box alist) {
    
  return(cons(cons(key, value), alist));
}


//Building function assoc from line: 86

public Box assoc(String searchTerm,Box l) {
  Box elem = null;
  
  assertType("list", l, 88, "q/lists.qon");  
  if ( isEmpty(l)) {    
    return(boxBool(false));
  } else {    
    elem = car(l);    
    assertType("list", elem, 94, "q/lists.qon");    
    if ( isEmpty(elem)) {      
      return(assoc(searchTerm, cdr(l)));
    } else {      
      if ( false) {        
        System.out.printf("Comparing %s and %s\n", searchTerm, stringify(car(elem)));
      } else {        
        System.out.printf("");
      }      
      if ( equalString(searchTerm, stringify(car(elem)))) {        
        return(elem);
      } else {        
        return(assoc(searchTerm, cdr(l)));
      }
    }
  }
}


//Building function chooseBox from line: 106

public String chooseBox(String aType) {
    
  if ( equalString("string", aType)) {    
    return("boxString");
  } else {    
    if ( equalString("symbol", aType)) {      
      return("boxSymbol");
    } else {      
      if ( equalString("bool", aType)) {        
        return("boxBool");
      } else {        
        if ( equalString("int", aType)) {          
          return("boxInt");
        } else {          
          if ( equalString("float", aType)) {            
            return("boxFloat");
          } else {            
            panic("Invalid type");
          }
        }
      }
    }
  }  
  return("");
}


//Building function mlistLiteral from line: 122

public Box mlistLiteral(Box b) {
    
  if ( isNil(b)) {    
    return(null);
  } else {    
    if ( equalString("string", boxType(b))) {      
      return(b);
    } else {      
      if ( equalString("bool", boxType(b))) {        
        return(b);
      } else {        
        if ( equalString("int", boxType(b))) {          
          return(b);
        } else {          
          if ( equalString("symbol", boxType(b))) {            
            return(boxString(unBoxSymbol(b)));
          } else {            
            return(boxString(stringConcatenate("Unsupported type: ", boxType(b))));
          }
        }
      }
    }
  }
}


//Building function doMultiList from line: 144

public Box doMultiList(Box l) {
  Box newlist = null;
Box ret = null;
Box elem = null;
  
  if ( isNil(l)) {    
    return(cons(boxSymbol("nil"), null));
  } else {    
    if ( isEmpty(l)) {      
      return(null);
    } else {      
      elem = first(l);      
      newlist = cons(boxString(chooseBox(elem.typ)), cons(mlistLiteral(first(l)), newlist));      
      ret = cons(cons(boxSymbol("cons"), cons(newlist, doMultiList(cdr(l)))), null);      
      return(ret);
    }
  }
}


//Building function doMakeList from line: 166

public Box doMakeList(Box l) {
  Box newlist = null;
Box ret = null;
Box elem = null;
  
  if ( isNil(l)) {    
    return(cons(boxSymbol("nil"), null));
  } else {    
    if ( isEmpty(l)) {      
      return(null);
    } else {      
      elem = first(l);      
      newlist = cons(first(l), newlist);      
      ret = cons(cons(boxSymbol("cons"), cons(newlist, doMakeList(cdr(l)))), null);      
      return(ret);
    }
  }
}


//Building function doStringList from line: 189

public Box doStringList(Box l) {
  Box newlist = null;
Box ret = null;
  
  if ( isNil(l)) {    
    return(cons(boxSymbol("nil"), null));
  } else {    
    newlist = cons(boxSymbol("boxString"), cons(first(l), newlist));    
    ret = cons(cons(boxSymbol("cons"), cons(newlist, doStringList(cdr(l)))), null);    
    return(ret);
  }
}


//Building function doSymbolList from line: 206

public Box doSymbolList(Box l) {
  Box newlist = null;
Box ret = null;
  
  if ( isNil(l)) {    
    return(cons(boxSymbol("nil"), null));
  } else {    
    newlist = cons(boxSymbol("boxSymbol"), cons(first(l), newlist));    
    ret = cons(cons(boxSymbol("cons"), cons(newlist, doSymbolList(cdr(l)))), null);    
    return(ret);
  }
}


//Building function doBoxList from line: 224

public Box doBoxList(Box l) {
    
  if ( isNil(l)) {    
    return(cons(boxSymbol("nil"), null));
  } else {    
    return(cons(cons(boxSymbol("cons"), cons(first(l), doBoxList(cdr(l)))), null));
  }
}


//Building function concatLists from line: 243

public Box concatLists(Box seq1,Box seq2) {
    
  if ( isNil(seq1)) {    
    return(seq2);
  } else {    
    return(cons(car(seq1), concatLists(cdr(seq1), seq2)));
  }
}


//Building function alistKeys from line: 249

public Box alistKeys(Box alist) {
    
  if ( isNil(alist)) {    
    return(null);
  } else {    
    return(cons(car(car(alist)), alistKeys(cdr(alist))));
  }
}


//Building function displayList from line: 255

public void displayList(Box l,Integer indent,boolean first) {
  Box val = null;
  
  if ( isEmpty(l)) {    
    return;
  } else {    
    if ( isList(l)) {      
      if ( isEmpty(l)) {        
        return;
      } else {        
        if ( first) {
        } else {          
          System.out.printf(" ");
        }        
        val = car(l);        
        if ( isList(val)) {          
          newLine(indent);          
          System.out.printf("%s", openBrace());          
          displayList(car(l), add1(indent), true);          
          System.out.printf("%s", closeBrace());          
          displayList(cdr(l), indent, false);
        } else {          
          if ( equalString("string", val.typ)) {            
            System.out.printf("\"%s\"", unBoxString(val));
          } else {            
            System.out.printf("%s", stringify(val));
          }          
          displayList(cdr(l), indent, false);
        }
      }
    } else {      
      if ( equalString("string", l.typ)) {        
        System.out.printf("\"%s\"", unBoxString(l));
      } else {        
        System.out.printf("%s", stringify(l));
      }
    }
  }
if (globalTrace)
   System.out. printf("Leaving displayList\n");

}


//Building function StringListJoinRec from line: 286

public String StringListJoinRec(Box l,String sep) {
  Box val = null;
  
  if ( isEmpty(l)) {    
    return("");
  } else {    
    if ( isList(l)) {      
      if ( isEmpty(l)) {        
        return("");
      } else {        
        if ( equal(listLength(l), 1)) {          
          return(stringify(car(l)));
        } else {          
          return(stringConcatenate(stringify(car(l)), stringConcatenate(sep, StringListJoinRec(cdr(l), sep))));
        }
      }
    } else {      
      return("");
    }
  }
}


//Building function StringListJoin from line: 309

public String StringListJoin(Box l,String sep) {
  Box val = null;
  
  if ( greaterthan(listLength(l), 1)) {    
    return(stringConcatenate(stringify(car(l)), stringConcatenate(sep, StringListJoinRec(cdr(l), sep))));
  } else {    
    return(stringify(car(l)));
  }
}


//Building function ListToBoxString from line: 319

public Box ListToBoxString(Box l) {
    
  return(boxString(ListToString(l, 0, true, false)));
}


//Building function ListToString from line: 324

public String ListToString(Box l,Integer indent,boolean first,boolean withNewLines) {
  Box val = null;
  
  if ( isEmpty(l)) {    
    return("");
  } else {    
    if ( isList(l)) {      
      if ( isEmpty(l)) {        
        return("");
      } else {        
        val = car(l);        
        if ( isList(val)) {          
          return(StringListJoin(cons(boxString(stringify(tern(withNewLines, boxString("\n"), boxString(stringIndent(indent))))), cons(boxString(openBrace()), cons(boxString(" "), cons(boxString(ListToString(car(l), add1(indent), true, withNewLines)), cons(boxString(closeBrace()), cons(boxString(" "), cons(boxString(ListToString(cdr(l), indent, false, withNewLines)), null))))))), ""));
        } else {          
          return(stringConcatenate(stringify(val), ListToString(cdr(l), indent, false, withNewLines)));
        }
      }
    } else {      
      return(stringify(l));
    }
  }
}


//Building function listReverse from line: 364

public Box listReverse(Box l) {
    
  if ( isNil(l)) {    
    return(null);
  } else {    
    return(cons(car(l), listReverse(cdr(l))));
  }
}


//Building function inList from line: 370

public boolean inList(Box item,Box l) {
    
  if ( isNil(l)) {    
    return(false);
  } else {    
    if ( equalBox(car(l), item)) {      
      return(true);
    } else {      
      return(inList(item, cdr(l)));
    }
  }
}


//Building function equalList from line: 380

public boolean equalList(Box a,Box b) {
    
  if ( isNil(a)) {    
    if ( isNil(b)) {      
      return(true);
    } else {      
      return(false);
    }
  } else {
  }  
  if ( isNil(b)) {    
    if ( isNil(a)) {      
      return(true);
    } else {      
      return(false);
    }
  } else {
  }  
  if ( equalBox(car(a), car(b))) {    
    return(equalList(cdr(a), cdr(b)));
  } else {    
    return(false);
  }
}


//Building function reverseRec from line: 403

public Box reverseRec(Box oldL,Box newL) {
    
  if ( isEmpty(oldL)) {    
    return(newL);
  } else {    
    return(reverseRec(cdr(oldL), cons(first(oldL), newL)));
  }
}


//Building function reverseList from line: 410

public Box reverseList(Box l) {
    
  return(reverseRec(l, null));
}


//Building function readSexpr from line: 4

public Box readSexpr(String aStr,String filename) {
  Box tokens = null;
Box as = null;
  
  tokens = emptyList();  
  tokens = filterTokens(filterVoid(scan(aStr, 0, 1, 0, 0, filename)));  
  as = sexprTree(tokens);  
  return(car(as));
}


//Building function sexprTree from line: 11

public Box sexprTree(Box l) {
  Box b = null;
  
  if ( isEmpty(l)) {    
    return(emptyList());
  } else {    
    b = car(l);    
    if ( isOpenBrace(b)) {      
      return(cons(sexprTree(cdr(l)), sexprTree(skipList(cdr(l)))));
    } else {      
      if ( isCloseBrace(b)) {        
        return(emptyList());
      } else {        
        return(setTag(boxString("line"), getTagFail(b, boxString("line"), boxInt(-1)), cons(b, sexprTree(cdr(l)))));
      }
    }
  }
}


//Building function loadQuon from line: 29

public Box loadQuon(String filename) {
  String programStr = "";
Box tree = null;
  
  programStr = read_file(filename);  
  tree = readSexpr(programStr, filename);  
  return(tree);
}


//Building function getIncludes from line: 38

public Box getIncludes(Box program) {
    
  return(cdr(first(program)));
}


//Building function getTypes from line: 42

public Box getTypes(Box program) {
    
  return(cdr(second(program)));
}


//Building function getFunctions from line: 46

public Box getFunctions(Box program) {
    
  return(cdr(third(program)));
}


//Building function loadIncludes from line: 51

public Box loadIncludes(Box tree) {
  Box newProg = null;
String includeFile = "";
Box functionsCombined = null;
Box typesCombined = null;
Box includeTree = null;
  
  if ( greaterthan(listLength(getIncludes(tree)), 0)) {    
    includeFile = stringify(first(getIncludes(tree)));    
    includeTree = loadQuon(includeFile);    
    functionsCombined = concatLists(getFunctions(includeTree), getFunctions(tree));    
    typesCombined = concatLists(getTypes(includeTree), getTypes(tree));    
    newProg = buildProg(cdr(getIncludes(tree)), typesCombined, functionsCombined);    
    return(loadIncludes(newProg));
  } else {    
    return(tree);
  }
}


//Building function buildProg from line: 74

public Box buildProg(Box includes,Box types,Box functions) {
  Box program = null;
  
  includes = cons(boxSymbol("includes"), includes);  
  types = cons(boxSymbol("types"), types);  
  functions = cons(boxSymbol("functions"), functions);  
  program = cons(includes, cons(types, cons(functions, null)));  
  return(program);
}


//Building function numbers from line: 4

public Box numbers(Integer num) {
    
  if ( greaterthan(0, num)) {    
    return(cons(boxString("-"), null));
  } else {    
    return(cons(boxString(stringify(boxInt(num))), numbers(sub1(num))));
  }
}


//Building function lexType from line: 11

public String lexType(Box abox) {
    
  if ( equalString("string", boxType(abox))) {    
    return("string");
  } else {    
    if ( inList(boxString(sub_string(stringify(abox), 0, 1)), numbers(9))) {      
      return("number");
    } else {      
      return("symbol");
    }
  }
}


//Building function perlLeaf from line: 23

public void perlLeaf(Box thisNode,Integer indent) {
    
  if ( equalString("symbol", lexType(codeof(thisNode)))) {    
    System.out.printf("%s", dollar());
  } else {    
    System.out.printf("");
  }  
  display(perlFuncMap(codeof(thisNode)));
if (globalTrace)
   System.out. printf("Leaving perlLeaf\n");

}


//Building function perlStructGetterExpression from line: 32

public void perlStructGetterExpression(Box thisNode,Integer indent) {
    
  if ( equalBox(boxString("structGetter"), subnameof(thisNode))) {    
    perlGetStruct(thisNode, indent);
  } else {    
    perlLeaf(thisNode, indent);
  }
if (globalTrace)
   System.out. printf("Leaving perlStructGetterExpression\n");

}


//Building function perlExpression from line: 38

public void perlExpression(Box node,Integer indent) {
    
  if ( isLeaf(node)) {    
    perlLeaf(node, indent);
  } else {    
    perlSubExpression(node, indent);
  }
if (globalTrace)
   System.out. printf("Leaving perlExpression\n");

}


//Building function perlRecurList from line: 44

public void perlRecurList(Box expr,Integer indent) {
    
  if ( isEmpty(expr)) {    
    return;
  } else {    
    perlExpression(car(expr), indent);    
    if ( isNil(cdr(expr))) {      
      System.out.printf("");
    } else {      
      System.out.printf(", ");      
      perlRecurList(cdr(expr), indent);
    }
  }
if (globalTrace)
   System.out. printf("Leaving perlRecurList\n");

}


//Building function perlSubExpression from line: 55

public void perlSubExpression(Box tree,Integer indent) {
  Box thing = null;
  
  if ( isEmpty(tree)) {    
    return;
  } else {    
    if ( isNode(childrenof(tree))) {      
      perlSubExpression(childrenof(tree), indent);
    } else {      
      if ( isLeaf(tree)) {        
        System.out.printf("%s", dollar());        
        display(perlFuncMap(codeof(tree)));
      } else {        
        if ( equal(1, listLength(childrenof(tree)))) {          
          display(codeof(car(childrenof(tree))));          
          if ( equalBox(boxString("return"), codeof(car(childrenof(tree))))) {            
            System.out.printf("");
          } else {            
            System.out.printf("()");
          }
        } else {          
          thing = codeof(car(childrenof(tree)));          
          if ( equalBox(boxSymbol("get-struct"), thing)) {            
            System.out.printf("%s%s->{%s}", dollar(), stringify(codeof(second(childrenof(tree)))), stringify(codeof(third(childrenof(tree)))));
          } else {            
            if ( equalBox(boxSymbol("new"), thing)) {              
              System.out.printf("{}");
            } else {              
              System.out.printf("%s(", stringify(perlFuncMap(codeof(car(childrenof(tree))))));              
              perlRecurList(cdr(childrenof(tree)), indent);              
              System.out.printf(")");
            }
          }
        }
      }
    }
  }
if (globalTrace)
   System.out. printf("Leaving perlSubExpression\n");

}


//Building function perlIf from line: 93

public void perlIf(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("if ( ");  
  perlExpression(car(first(childrenof(node))), 0);  
  System.out.printf(") {");  
  perlBody(second(childrenof(node)), add1(indent));  
  newLine(indent);  
  System.out.printf("} else {");  
  perlBody(third(childrenof(node)), add1(indent));  
  newLine(indent);  
  System.out.printf("}");
if (globalTrace)
   System.out. printf("Leaving perlIf\n");

}


//Building function perlSetStruct from line: 106

public void perlSetStruct(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("%s%s->{%s} = ", dollar(), stringify(first(codeof(node))), stringify(second(codeof(node))));  
  perlExpression(childrenof(node), indent);
if (globalTrace)
   System.out. printf("Leaving perlSetStruct\n");

}


//Building function perlGetStruct from line: 113

public void perlGetStruct(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("%s%s->{%s}", dollar(), stringify(first(codeof(node))), stringify(second(codeof(node))));
if (globalTrace)
   System.out. printf("Leaving perlGetStruct\n");

}


//Building function perlSet from line: 118

public void perlSet(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("%s%s = ", dollar(), stringify(first(codeof(node))));  
  perlExpression(childrenof(node), indent);
if (globalTrace)
   System.out. printf("Leaving perlSet\n");

}


//Building function assertNode from line: 124

public void assertNode(Box node) {
    
  if ( isNode(node)) {    
    return;
  } else {    
    panic("Not a node!");
  }
if (globalTrace)
   System.out. printf("Leaving assertNode\n");

}


//Building function perlStatement from line: 131

public void perlStatement(Box node,Integer indent) {
  Box functionName = null;
  
  assertNode(node);  
  if ( equalBox(boxString("setter"), subnameof(node))) {    
    perlSet(node, indent);
  } else {    
    if ( equalBox(boxString("structSetter"), subnameof(node))) {      
      perlSetStruct(node, indent);
    } else {      
      if ( equalBox(boxString("if"), subnameof(node))) {        
        perlIf(node, indent);
      } else {        
        if ( equalBox(boxString("returnvoid"), subnameof(node))) {          
          functionName = functionNameof(node);          
          System.out.printf("\n#Returnvoid\n");          
          newLine(indent);          
          newLine(indent);          
          System.out.printf("return");
        } else {          
          if ( equalBox(boxString("return"), subnameof(node))) {            
            functionName = functionNameof(node);            
            if ( inList(functionName, noStackTrace())) {              
              System.out.printf("");
            } else {              
              System.out.printf("\n#standard return: %s\n", stringify(functionName));              
              newLine(indent);              
              System.out.printf("%s%s%s", "if (", dollar(), "globalTrace) {printf(\"Leaving \\n\")}\n");
            }            
            newLine(indent);            
            perlExpression(childrenof(node), indent);
          } else {            
            if ( inList(functionName, noStackTrace())) {              
              System.out.printf("");
            } else {              
              System.out.printf("\n#standard expression\n");
            }            
            newLine(indent);            
            perlExpression(childrenof(node), indent);            
            newLine(indent);
          }
        }
      }
    }
  }  
  System.out.printf(";\n");
if (globalTrace)
   System.out. printf("Leaving perlStatement\n");

}


//Building function perlBody from line: 180

public void perlBody(Box tree,Integer indent) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    printIndent(indent);    
    System.out.printf("%s%s%s", "if (", dollar(), "globalStepTrace) {printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__)}\n");    
    perlStatement(car(tree), indent);    
    perlBody(cdr(tree), indent);
  }
if (globalTrace)
   System.out. printf("Leaving perlBody\n");

}


//Building function perlDeclarations from line: 190

public void perlDeclarations(Box decls,Integer indent) {
  Box decl = null;
  
  if ( isEmpty(decls)) {    
    return;
  } else {    
    decl = car(decls);    
    System.out.printf("my %s%s = ", dollar(), stringify(second(decl)));    
    display(perlConstMap(third(decl)));    
    System.out.printf(";\n");    
    perlDeclarations(cdr(decls), indent);
  }
if (globalTrace)
   System.out. printf("Leaving perlDeclarations\n");

}


//Building function perlFunction from line: 201

public void perlFunction(Box node) {
  Box name = null;
  
  name = subnameof(node);  
  System.out.printf("\n\n#Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));  
  newLine(0);  
  if ( isNil(node)) {    
    return;
  } else {    
    newLine(0);    
    System.out.printf("sub %s", stringify(subnameof(node)));    
    System.out.printf(" {");    
    newLine(1);    
    perlFunctionArgs(cdr(assoc("intype", cdr(node))));    
    newLine(1);    
    perlDeclarations(declarationsof(node), 1);    
    System.out.printf("\nif (%sglobalTrace) { printf(\"%s at %s:%s\\n\") }\n", dollar(), stringify(subnameof(node)), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));    
    if ( inList(name, noStackTrace())) {      
      System.out.printf("");
    } else {      
      System.out.printf("");
    }    
    perlBody(childrenof(node), 1);    
    if ( inList(name, noStackTrace())) {      
      System.out.printf("");
    } else {      
      System.out.printf("");
    }    
    System.out.printf("\n}\n");
  }
if (globalTrace)
   System.out. printf("Leaving perlFunction\n");

}


//Building function perlForwardDeclaration from line: 233

public void perlForwardDeclaration(Box node) {
    
  if ( isNil(node)) {    
    return;
  } else {    
    System.out.printf("\nsub %s", stringify(subnameof(node)));    
    System.out.printf(";");
  }
if (globalTrace)
   System.out. printf("Leaving perlForwardDeclaration\n");

}


//Building function perlForwardDeclarations from line: 243

public void perlForwardDeclarations(Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    perlForwardDeclaration(car(tree));    
    perlForwardDeclarations(cdr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving perlForwardDeclarations\n");

}


//Building function perlFunctions from line: 251

public void perlFunctions(Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    perlFunction(car(tree));    
    perlFunctions(cdr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving perlFunctions\n");

}


//Building function dollar from line: 258

public String dollar() {
    
  return(character(36));
}


//Building function atSym from line: 261

public String atSym() {
    
  return(character(64));
}


//Building function perlIncludes from line: 265

public void perlIncludes(Box nodes) {
    
  System.out.printf("%s\n", "use strict;");  
  System.out.printf("%s%s%s", "my ", dollar(), "caller;\n");  
  System.out.printf("%s%s%s", "my ", dollar(), "releaseMode;\n");  
  System.out.printf("%s\n", "use Carp;");  
  dollar();  
  System.out.printf("%s\n", "use Carp::Always;");  
  System.out.printf("%s%s%s%s%s\n", "sub greaterthan { ", dollar(), "_[0] > ", dollar(), "_[1] };");  
  System.out.printf("%s%s%s\n", "sub qlog { warn ", "@", "_ };");  
  System.out.printf("%s%s%s%s%s\n", "sub mult { ", dollar(), "_[0] * ", dollar(), "_[1] };");  
  System.out.printf("%s%s%s%s%s\n", "sub multf { ", dollar(), "_[0] * ", dollar(), "_[1] };");  
  System.out.printf("%s%s%s%s%s\n", "sub greaterthanf { ", dollar(), "_[0] > ", dollar(), "_[1] };");  
  System.out.printf("%s%s%s%s%s\n", "sub equalString { ", dollar(), "_[0] eq ", dollar(), "_[1] };");  
  System.out.printf("sub read_file { my %sfile = shift; %sfile || die \"Empty file name!!!\"; open my %sfh, '<', %sfile or die; local %s/ = undef; my %scont = <%sfh>; close %sfh; return %scont; }; \n", dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar());  
  System.out.printf("sub write_file {my %sfile = shift; my %sdata = shift; %sfile || die \"Empty file name!!!\"; open my %sfh, '>', %sfile or die; print %sfh %sdata; close %sfh; } \n", dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar());  
  System.out.printf("%s%s%s%s%s\n", "sub stringConcatenate { ", dollar(), "_[0] . ", dollar(), "_[1]}");  
  System.out.printf("%s%s%s%s%s\n", "sub subtract { ", dollar(), "_[0] - ", dollar(), "_[1]}");  
  System.out.printf("%s%s%s%s%s\n", "sub subf { ", dollar(), "_[0] - ", dollar(), "_[1]}");  
  System.out.printf("%s%s%s%s%s\n", "sub andBool { ", dollar(), "_[0] && ", dollar(), "_[1]}");  
  System.out.printf("%s%s%s%s%s\n", "sub equal { ", dollar(), "_[0] == ", dollar(), "_[1]}");  
  System.out.printf("%s%s%s%s%s\n", "sub panic { carp ", atSym(), "_; die \"", atSym(), "_\"}");  
  System.out.printf("sub intToString { return %s_[0]}\n", dollar());  
  System.out.printf("sub character { return chr(%s_[0])}\n", dollar());  
  System.out.printf("%s%s%s%s%s%s%s%s%s\n", "sub getStringArray { my ", dollar(), "index = shift; my ", dollar(), "arr = shift; return ", dollar(), "arr->[", dollar(), "index]}");
if (globalTrace)
   System.out. printf("Leaving perlIncludes\n");

}


//Building function perlTypeDecl from line: 301

public void perlTypeDecl(Box l) {
  
if (globalTrace)
   System.out. printf("Leaving perlTypeDecl\n");

}


//Building function perlStructComponents from line: 306

public void perlStructComponents(Box node) {
    
  if ( isEmpty(node)) {    
    return;
  } else {    
    perlTypeDecl(car(node));    
    perlStructComponents(cdr(node));
  }
if (globalTrace)
   System.out. printf("Leaving perlStructComponents\n");

}


//Building function perlStruct from line: 312

public void perlStruct(Box node) {
    
  perlStructComponents(cdr(car(node)));
if (globalTrace)
   System.out. printf("Leaving perlStruct\n");

}


//Building function perlTypeMap from line: 315

public Box perlTypeMap(Box aSym) {
  Box symMap = null;
  
  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), null));  
  if ( truthy(assoc(stringify(aSym), symMap))) {    
    return(cdr(assoc(stringify(aSym), symMap)));
  } else {    
    return(aSym);
  }
}


//Building function perlConstMap from line: 327

public Box perlConstMap(Box aSym) {
  Box symMap = null;
  
  if ( equalString("symbol", boxType(aSym))) {    
    symMap = alistCons(boxSymbol("false"), boxSymbol("0"), alistCons(boxSymbol("nil"), boxSymbol("undef"), null));    
    return(cdr(assocFail(stringify(aSym), symMap, aSym)));
  } else {    
    return(aSym);
  }
}


//Building function perlFuncMap from line: 337

public Box perlFuncMap(Box aSym) {
  Box symMap = null;
  
  if ( equalString("symbol", boxType(aSym))) {    
    symMap = alistCons(boxSymbol("sub"), boxSymbol("subtract"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("substr"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("length"), alistCons(boxSymbol("nil"), boxSymbol("undef"), null))))))));    
    return(cdr(assocFail(stringify(aSym), symMap, aSym)));
  } else {    
    return(aSym);
  }
}


//Building function perlType from line: 354

public void perlType(Box node) {
  
if (globalTrace)
   System.out. printf("Leaving perlType\n");

}


//Building function perlTypes from line: 359

public void perlTypes(Box nodes) {
    
  if ( isEmpty(nodes)) {    
    return;
  } else {    
    perlType(car(nodes));    
    perlTypes(cdr(nodes));
  }
if (globalTrace)
   System.out. printf("Leaving perlTypes\n");

}


//Building function perlFunctionArgs from line: 365

public void perlFunctionArgs(Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    System.out.printf("%s%s", "my ", dollar());    
    display(second(tree));    
    System.out.printf(" = shift;\n");    
    perlFunctionArgs(cddr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving perlFunctionArgs\n");

}


//Building function perlCompile from line: 375

public void perlCompile(String filename) {
  String programStr = "";
Box tree = null;
Box program = null;
  
  programStr = read_file(filename);  
  tree = readSexpr(programStr, filename);  
  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), null)));  
  program = mergeIncludes(program);  
  perlIncludes(cdr(assoc("includes", program)));  
  perlTypes(childrenof(cdr(assoc("types", program))));  
  System.out.printf("use strict;\n");  
  System.out.printf("use Carp;\n");  
  System.out.printf("use Data::Dumper;\n");  
  System.out.printf("%s%s%s", "my ", dollar(), "globalStackTrace = undef;\n");  
  System.out.printf("%s%s%s", "my ", dollar(), "globalTrace = undef;\n");  
  System.out.printf("%s%s%s", "my ", dollar(), "globalStepTrace = undef;\n");  
  System.out.printf("%s%s%s", "my ", dollar(), "globalArgs = undef;\n");  
  System.out.printf("%s%s%s", "my ", dollar(), "globalArgsCount = undef;\n");  
  System.out.printf("%s%s%s\n", "my ", dollar(), "true = 1;\n");  
  System.out.printf("%s%s%s", "my ", dollar(), "false = 0;\n");  
  System.out.printf("%s%s%s", "my ", dollar(), "undef;\n");  
  System.out.printf("%s%s%s", "\nsub isNil {\n    return !defined(", dollar(), "_[0]);\n}\n\n\n#Forward declarations\n");  
  perlForwardDeclarations(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));  
  System.out.printf("\n\n#End forward declarations\n\n");  
  perlFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));  
  System.out.printf(";\n");  
  System.out.printf("%s%s%s%s", dollar(), "globalArgs = [ 1, ", atSym(), "ARGV];");  
  System.out.printf("%s%s%s%s", dollar(), "globalArgsCount = scalar(", atSym(), "ARGV)+1;\n");  
  System.out.printf("start();");
if (globalTrace)
   System.out. printf("Leaving perlCompile\n");

}


//Building function ansiFunctionArgs from line: 3

public void ansiFunctionArgs(Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    display(ansiTypeMap(first(tree)));    
    System.out.printf(" ");    
    display(second(tree));    
    if ( isNil(cddr(tree))) {      
      System.out.printf("");
    } else {      
      System.out.printf(",");
    }    
    ansiFunctionArgs(cddr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving ansiFunctionArgs\n");

}


//Building function ansiLeaf from line: 14

public void ansiLeaf(Box thisNode,Integer indent) {
    
  display(ansiFuncMap(codeof(thisNode)));
if (globalTrace)
   System.out. printf("Leaving ansiLeaf\n");

}


//Building function ansiStructGetterExpression from line: 17

public void ansiStructGetterExpression(Box thisNode,Integer indent) {
    
  if ( equalBox(boxString("structGetter"), subnameof(thisNode))) {    
    ansiGetStruct(thisNode, indent);
  } else {    
    ansiLeaf(thisNode, indent);
  }
if (globalTrace)
   System.out. printf("Leaving ansiStructGetterExpression\n");

}


//Building function ansiExpression from line: 23

public void ansiExpression(Box node,Integer indent) {
    
  if ( isLeaf(node)) {    
    display(ansiFuncMap(codeof(node)));
  } else {    
    ansiSubExpression(node, indent);
  }
if (globalTrace)
   System.out. printf("Leaving ansiExpression\n");

}


//Building function ansiRecurList from line: 29

public void ansiRecurList(Box expr,Integer indent) {
    
  if ( isEmpty(expr)) {    
    return;
  } else {    
    ansiExpression(car(expr), indent);    
    if ( isNil(cdr(expr))) {      
      System.out.printf("");
    } else {      
      System.out.printf(", ");      
      ansiRecurList(cdr(expr), indent);
    }
  }
if (globalTrace)
   System.out. printf("Leaving ansiRecurList\n");

}


//Building function ansiSubExpression from line: 41

public void ansiSubExpression(Box tree,Integer indent) {
  Box thing = null;
  
  if ( isEmpty(tree)) {    
    return;
  } else {    
    if ( isNode(childrenof(tree))) {      
      ansiSubExpression(childrenof(tree), indent);
    } else {      
      if ( isLeaf(tree)) {        
        display(ansiFuncMap(codeof(tree)));
      } else {        
        if ( equal(1, listLength(childrenof(tree)))) {          
          display(codeof(car(childrenof(tree))));          
          if ( equalBox(boxString("return"), codeof(car(childrenof(tree))))) {            
            System.out.printf("");
          } else {            
            System.out.printf("()");
          }
        } else {          
          thing = codeof(car(childrenof(tree)));          
          if ( equalBox(boxSymbol("get-struct"), thing)) {            
            System.out.printf("%s->%s", stringify(codeof(second(childrenof(tree)))), stringify(codeof(third(childrenof(tree)))));
          } else {            
            if ( equalBox(boxSymbol("new"), thing)) {              
              System.out.printf("malloc(sizeof(%s))", stringify(codeof(third(childrenof(tree)))));
            } else {              
              System.out.printf("%s(", stringify(ansiFuncMap(codeof(car(childrenof(tree))))));              
              ansiRecurList(cdr(childrenof(tree)), indent);              
              System.out.printf(")");
            }
          }
        }
      }
    }
  }
if (globalTrace)
   System.out. printf("Leaving ansiSubExpression\n");

}


//Building function ansiIf from line: 81

public void ansiIf(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("if ( ");  
  ansiExpression(car(first(childrenof(node))), 0);  
  System.out.printf(") {");  
  ansiBody(second(childrenof(node)), add1(indent));  
  newLine(indent);  
  System.out.printf("} else {");  
  ansiBody(third(childrenof(node)), add1(indent));  
  newLine(indent);  
  System.out.printf("}");
if (globalTrace)
   System.out. printf("Leaving ansiIf\n");

}


//Building function ansiSetStruct from line: 94

public void ansiSetStruct(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("%s->%s = ", stringify(first(codeof(node))), stringify(second(codeof(node))));  
  ansiExpression(childrenof(node), indent);
if (globalTrace)
   System.out. printf("Leaving ansiSetStruct\n");

}


//Building function ansiGetStruct from line: 103

public void ansiGetStruct(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("%s->%s", stringify(first(codeof(node))), stringify(second(codeof(node))));
if (globalTrace)
   System.out. printf("Leaving ansiGetStruct\n");

}


//Building function ansiSet from line: 111

public void ansiSet(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("%s = ", stringify(first(codeof(node))));  
  ansiExpression(childrenof(node), indent);
if (globalTrace)
   System.out. printf("Leaving ansiSet\n");

}


//Building function ansiStatement from line: 117

public void ansiStatement(Box node,Integer indent) {
    
  if ( equalBox(boxString("setter"), subnameof(node))) {    
    ansiSet(node, indent);
  } else {    
    if ( equalBox(boxString("structSetter"), subnameof(node))) {      
      ansiSetStruct(node, indent);
    } else {      
      if ( equalBox(boxString("if"), subnameof(node))) {        
        ansiIf(node, indent);
      } else {        
        if ( equalBox(boxString("returnvoid"), subnameof(node))) {          
          newLine(indent);          
          System.out.printf("return");
        } else {          
          newLine(indent);          
          ansiExpression(childrenof(node), indent);
        }
      }
    }
  }  
  System.out.printf(";\n");
if (globalTrace)
   System.out. printf("Leaving ansiStatement\n");

}


//Building function ansiBody from line: 135

public void ansiBody(Box tree,Integer indent) {
  Box code = null;
  
  if ( isEmpty(tree)) {    
    return;
  } else {    
    code = codeof(car(tree));    
    if ( isNil(code)) {
    } else {      
      code = car(codeof(car(tree)));      
      System.out.printf("\n");      
      printIndent(indent);      
      System.out.printf("if (globalTrace)   snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail(code, boxString("filename"), boxString("Unknown"))), stringify(getTagFail(code, boxString("line"), boxString("Unknown"))));
    }    
    printIndent(indent);    
    System.out.printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n");    
    ansiStatement(car(tree), indent);    
    ansiBody(cdr(tree), indent);
  }
if (globalTrace)
   System.out. printf("Leaving ansiBody\n");

}


//Building function ansiDeclarations from line: 156

public void ansiDeclarations(Box decls,Integer indent) {
  Box decl = null;
  
  if ( isEmpty(decls)) {    
    return;
  } else {    
    decl = car(decls);    
    System.out.printf("%s %s = ", stringify(ansiTypeMap(first(decl))), stringify(second(decl)));    
    display(ansiFuncMap(third(decl)));    
    System.out.printf(";\n");    
    ansiDeclarations(cdr(decls), indent);
  }
if (globalTrace)
   System.out. printf("Leaving ansiDeclarations\n");

}


//Building function ansiFunction from line: 170

public void ansiFunction(Box node) {
  Box name = null;
  
  name = subnameof(node);  
  System.out.printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));  
  newLine(0);  
  if ( isNil(node)) {    
    return;
  } else {    
    newLine(0);    
    System.out.printf("%s %s(", stringify(ansiTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));    
    ansiFunctionArgs(cdr(assoc("intype", cdr(node))));    
    System.out.printf(") {");    
    newLine(1);    
    ansiDeclarations(declarationsof(node), 1);    
    if ( inList(toStr(name), noStackTrace())) {      
      System.out.printf("");
    } else {      
      System.out.printf("\nif (globalTrace)\n    fprintf(stderr, \"%s at %s:%s (%%s)\\n\", caller);\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));
    }    
    if ( inList(toStr(name), noStackTrace())) {      
      System.out.printf("");
    } else {
    }    
    ansiBody(childrenof(node), 1);    
    if ( inList(toStr(name), noStackTrace())) {      
      System.out.printf("");
    } else {      
      System.out.printf("\nif (globalTrace)\n    fprintf(stderr, \"Leaving %s\\n\");\n", stringify(name));
    }    
    System.out.printf("\n}\n");
  }
if (globalTrace)
   System.out. printf("Leaving ansiFunction\n");

}


//Building function ansiForwardDeclaration from line: 204

public void ansiForwardDeclaration(Box node) {
    
  if ( isNil(node)) {    
    return;
  } else {    
    System.out.printf("\n%s %s(", stringify(ansiTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));    
    ansiFunctionArgs(cdr(assoc("intype", cdr(node))));    
    System.out.printf(");");
  }
if (globalTrace)
   System.out. printf("Leaving ansiForwardDeclaration\n");

}


//Building function ansiForwardDeclarations from line: 216

public void ansiForwardDeclarations(Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    ansiForwardDeclaration(car(tree));    
    ansiForwardDeclarations(cdr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving ansiForwardDeclarations\n");

}


//Building function ansiFunctions from line: 224

public void ansiFunctions(Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    ansiFunction(car(tree));    
    ansiFunctions(cdr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving ansiFunctions\n");

}


//Building function ansiIncludes from line: 229

public void ansiIncludes(Box nodes) {
    
  System.out.printf("%s", "\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\nconst char* getEnv(char* key){return getenv(key);}\n void panic(char* s){abort();exit(1);}\nint not(int a){return !a;}\nint sub(int a, int b) { return a - b; }\nfloat mult(int a, int b) { return a * b; }\nint greaterthan(int a, int b) { return a > b; }\nfloat subf(float a, float b) { return a - b; }\nfloat multf(float a, float b) { return a * b; }\nint greaterthanf(float a, float b) { return a > b; }\nint equal(int a, int b) { return a == b; }\nint equalString(char* a, char* b) { return !strcmp(a,b); }\nint andBool(int a, int b) { return a && b;}\nint string_length(char* s) { return strlen(s);}\nchar* setSubString(char* target, int start,char *source){target[start]=source[0]; return target;}\nchar* sub_string(char* s, int start, int length) {\nchar* substr = calloc(length+1, 1);\nstrncpy(substr, s+start, length);\nreturn substr;\n}\n\n\n\nchar* stringConcatenate(char* a, char* b) {\nint len = strlen(a) + strlen(b) + 1;\nchar* target = calloc(len,1);\nstrncat(target, a, len);\nstrncat(target, b, len);\nreturn target;\n}\n\nchar* intToString(int a) {\nint len = 100;\nchar* target = calloc(len,1);\nsnprintf(target, 99, \"%d\", a);\nreturn target;\n}\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\nvoid * gc_malloc( unsigned int size ) {\nreturn malloc(size);\n}\n\nint* makeArray(int length) {\n    int * array = gc_malloc(length*sizeof(int));\n    return array;\n}\n\nint at(int* arr, int index) {\n  return arr[index];\n}\n\nvoid setAt(int* array, int index, int value) {\n    array[index] = value;\n}\n\nchar * read_file(char * filename) {\nchar * buffer = 0;\nlong length;\nFILE * f = fopen (filename, \"rb\");\n\nif (f)\n{\n  fseek (f, 0, SEEK_END);\n  length = ftell (f);\n  fseek (f, 0, SEEK_SET);\n  buffer = calloc (length+1,1);\n  if (buffer == NULL) {\n  printf(\"Malloc failed!\\n\");\n  exit(1);\n}\n  if (buffer)\n  {\n    fread (buffer, 1, length, f);\n  }\n  fclose (f);\n}\nreturn buffer;\n}\n\n\nvoid write_file (char * filename, char * data) {\nFILE *f = fopen(filename, \"w\");\nif (f == NULL)\n{\n    printf(\"Error opening file!\");\n    exit(1);\n}\n\nfprintf(f, \"%s\", data);\n\nfclose(f);\n}\n\nchar* getStringArray(int index, char** strs) {\nreturn strs[index];\n}\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\n\nint main( int argc, char *argv[] )  {\n  globalArgs = argv;\n  globalArgsCount = argc;\n  caller=calloc(1024,1);\n\n  return start();\n\n}\n\n");  
  System.out.printf("%s", "char * character(int num) { char *string = malloc(2); if (!string) return 0; string[0] = num; string[1] = 0; return string; }");  
  System.out.printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }");  
  System.out.printf("%s", "bool nand(bool a, bool b) { return !(a&&b); }\n//End include block\n");
if (globalTrace)
   System.out. printf("Leaving ansiIncludes\n");

}


//Building function ansiTypeDecl from line: 239

public void ansiTypeDecl(Box l) {
    
  if ( greaterthan(listLength(l), 2)) {    
    printIndent(1);    
    System.out.printf("%s %s %s;\n", stringify(second(l)), stringify(ansiTypeMap(listLast(l))), stringify(first(l)));
  } else {    
    printIndent(1);    
    System.out.printf("%s %s;\n", stringify(ansiTypeMap(listLast(l))), stringify(car(l)));
  }
if (globalTrace)
   System.out. printf("Leaving ansiTypeDecl\n");

}


//Building function ansiStructComponents from line: 256

public void ansiStructComponents(Box node) {
    
  if ( isEmpty(node)) {    
    return;
  } else {    
    ansiTypeDecl(car(node));    
    ansiStructComponents(cdr(node));
  }
if (globalTrace)
   System.out. printf("Leaving ansiStructComponents\n");

}


//Building function ansiStruct from line: 262

public void ansiStruct(Box node) {
    
  ansiStructComponents(cdr(car(node)));
if (globalTrace)
   System.out. printf("Leaving ansiStruct\n");

}


//Building function ansiTypeMap from line: 265

public Box ansiTypeMap(Box aSym) {
  Box symMap = null;
  
  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), null));  
  if ( truthy(assoc(stringify(aSym), symMap))) {    
    return(cdr(assoc(stringify(aSym), symMap)));
  } else {    
    return(aSym);
  }
}


//Building function ansiFuncMap from line: 277

public Box ansiFuncMap(Box aSym) {
  Box symMap = null;
  
  if ( equalString("symbol", boxType(aSym))) {    
    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), null)))))));    
    if ( truthy(assoc(stringify(aSym), symMap))) {      
      return(cdr(assoc(stringify(aSym), symMap)));
    } else {      
      return(aSym);
    }
  } else {    
    return(aSym);
  }
}


//Building function ansiType from line: 308

public void ansiType(Box node) {
    
  if ( equalBox(subnameof(node), boxString("struct"))) {    
    System.out.printf("\ntypedef struct %s {\n", stringify(first(codeof(node))));    
    ansiStruct(cdr(codeof(node)));    
    System.out.printf("\n} %s;\n", stringify(first(codeof(node))));
  } else {    
    System.out.printf("typedef ");    
    ansiTypeDecl(codeof(node));
  }
if (globalTrace)
   System.out. printf("Leaving ansiType\n");

}


//Building function ansiTypes from line: 318

public void ansiTypes(Box nodes) {
    
  if ( isEmpty(nodes)) {    
    return;
  } else {    
    ansiType(car(nodes));    
    ansiTypes(cdr(nodes));
  }
if (globalTrace)
   System.out. printf("Leaving ansiTypes\n");

}


//Building function ansiCompile from line: 328

public void ansiCompile(String filename) {
  String programStr = "";
Box tree = null;
Box program = null;
  
  System.out.printf("//Scanning file...%s\n", filename);  
  programStr = read_file(filename);  
  System.out.printf("//Building sexpr\n");  
  tree = readSexpr(programStr, filename);  
  tree = macrowalk(tree);  
  cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), null)));  
  System.out.printf("//Building AST\n");  
  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), null)));  
  System.out.printf("//Merging ASTs\n");  
  program = mergeIncludes(program);  
  System.out.printf("//Printing program\n");  
  ansiIncludes(cdr(assoc("includes", program)));  
  ansiTypes(childrenof(cdr(assoc("types", program))));  
  System.out.printf("Box* globalStackTrace = NULL;\n");  
  System.out.printf("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");  
  ansiForwardDeclarations(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));  
  System.out.printf("\n\n//End forward declarations\n\n");  
  ansiFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));  
  System.out.printf("\n");
if (globalTrace)
   System.out. printf("Leaving ansiCompile\n");

}


//Building function ansi2displays from line: 5

public void ansi2displays(String s) {
    
  System.out.printf("%s", s);
if (globalTrace)
   System.out. printf("Leaving ansi2displays\n");

}


//Building function ansi2FunctionArgs from line: 11

public void ansi2FunctionArgs(Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    if ( equalString(stringify(first(tree)), "...")) {      
      System.out.printf("...");
    } else {      
      display(ansi2TypeMap(first(tree)));      
      ansi2displays(" ");      
      display(second(tree));
    }    
    if ( isNil(cddr(tree))) {
    } else {      
      ansi2displays(", ");
    }    
    ansi2FunctionArgs(cddr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving ansi2FunctionArgs\n");

}


//Building function ansi2Expression from line: 28

public void ansi2Expression(Box tree,Integer indent) {
  Box thing = null;
  
  if ( isList(tree)) {    
    if ( equal(1, listLength(tree))) {      
      display(car(tree));      
      if ( equalBox(boxString("return"), car(tree))) {
      } else {        
        ansi2displays("()");
      }
    } else {      
      thing = first(tree);      
      if ( equalBox(boxSymbol("get-struct"), thing)) {        
        System.out.printf("%s->%s", stringify(second(tree)), stringify(third(tree)));
      } else {        
        if ( equalBox(boxSymbol("new"), thing)) {          
          System.out.printf("malloc(sizeof(%s))", stringify(third(tree)));
        } else {          
          if ( equalBox(boxSymbol("passthrough"), thing)) {            
            System.out.printf("%s", stringify(second(tree)));
          } else {            
            if ( equalBox(boxSymbol("binop"), thing)) {              
              System.out.printf("(");              
              ansi2Expression(third(tree), indent);              
              System.out.printf(" %s ", stringify(second(tree)));              
              ansi2Expression(fourth(tree), indent);              
              System.out.printf(")");
            } else {              
              System.out.printf("%s(", stringify(ansi2FuncMap(car(tree))));              
              ansi2RecurList(cdr(tree), indent);              
              System.out.printf(")");
            }
          }
        }
      }
    }
  } else {    
    display(ansi2FuncMap(tree));
  }
if (globalTrace)
   System.out. printf("Leaving ansi2Expression\n");

}


//Building function ansi2RecurList from line: 98

public void ansi2RecurList(Box expr,Integer indent) {
    
  if ( isEmpty(expr)) {    
    return;
  } else {    
    ansi2Expression(car(expr), indent);    
    if ( isNil(cdr(expr))) {      
      ansi2displays("");
    } else {      
      ansi2displays(", ");      
      ansi2RecurList(cdr(expr), indent);
    }
  }
if (globalTrace)
   System.out. printf("Leaving ansi2RecurList\n");

}


//Building function ansi2If from line: 115

public void ansi2If(Box node,Integer indent) {
    
  newLine(indent);  
  ansi2displays("if ( ");  
  ansi2Expression(second(node), 0);  
  ansi2displays(") {");  
  ansi2Body(cdr(third(node)), add1(indent));  
  newLine(indent);  
  ansi2displays("} else {");  
  ansi2Body(cdr(fourth(node)), add1(indent));  
  newLine(indent);  
  ansi2displays("}");
if (globalTrace)
   System.out. printf("Leaving ansi2If\n");

}


//Building function ansi2SetStruct from line: 128

public void ansi2SetStruct(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("%s->%s = ", stringify(second(node)), stringify(third(node)));  
  ansi2Expression(fourth(node), indent);
if (globalTrace)
   System.out. printf("Leaving ansi2SetStruct\n");

}


//Building function ansi2GetStruct from line: 137

public void ansi2GetStruct(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("%s->%s", stringify(first(node)), stringify(second(node)));
if (globalTrace)
   System.out. printf("Leaving ansi2GetStruct\n");

}


//Building function ansi2Set from line: 145

public void ansi2Set(Box node,Integer indent) {
    
  newLine(indent);  
  ansi2Expression(first(cdr(node)), indent);  
  System.out.printf(" = ");  
  ansi2Expression(third(node), indent);
if (globalTrace)
   System.out. printf("Leaving ansi2Set\n");

}


//Building function ansi2Return from line: 152

public void ansi2Return(Box node,Integer indent) {
    
  newLine(indent);  
  if ( equal(listLength(node), 1)) {    
    ansi2displays("return;");
  } else {    
    ansi2displays("return ");    
    ansi2Expression(cadr(node), indent);    
    ansi2displays(";");
  }
if (globalTrace)
   System.out. printf("Leaving ansi2Return\n");

}


//Building function ansi2Statement from line: 163

public void ansi2Statement(Box node,Integer indent) {
    
  if ( equalBox(boxString("set"), first(node))) {    
    ansi2Set(node, indent);
  } else {    
    if ( equalBox(boxString("set-struct"), first(node))) {      
      ansi2SetStruct(node, indent);
    } else {      
      if ( equalBox(boxString("if"), first(node))) {        
        ansi2If(node, indent);
      } else {        
        if ( equalBox(boxString("return"), first(node))) {          
          ansi2Return(node, indent);
        } else {          
          newLine(indent);          
          ansi2Expression(node, indent);
        }
      }
    }
  }  
  ansi2displays(";\n");
if (globalTrace)
   System.out. printf("Leaving ansi2Statement\n");

}


//Building function ansi2Body from line: 181

public void ansi2Body(Box tree,Integer indent) {
  Box code = null;
  
  if ( isEmpty(tree)) {    
    return;
  } else {    
    code = tree;    
    if ( isNil(code)) {
    } else {      
      code = car(tree);      
      System.out.printf("\nif (globalTrace)\n    snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), stringify(getTagFail(car(code), boxString("line"), boxString("Line missing"))));
    }    
    printIndent(indent);    
    System.out.printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n");    
    ansi2Statement(code, indent);    
    ansi2Body(cdr(tree), indent);
  }
if (globalTrace)
   System.out. printf("Leaving ansi2Body\n");

}


//Building function ansi2Declarations from line: 199

public void ansi2Declarations(Box decls,Integer indent) {
  Box decl = null;
  
  if ( isEmpty(decls)) {    
    return;
  } else {    
    decl = car(decls);    
    System.out.printf("%s %s = ", stringify(ansi2TypeMap(first(decl))), stringify(second(decl)));    
    ansi2Expression(third(decl), indent);    
    System.out.printf(";\n");    
    ansi2Declarations(cdr(decls), indent);
  }
if (globalTrace)
   System.out. printf("Leaving ansi2Declarations\n");

}


//Building function ansi2Function from line: 213

public void ansi2Function(Box node) {
  Box name = null;
  
  name = second(node);  
  System.out.printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));  
  newLine(0);  
  if ( isNil(node)) {    
    return;
  } else {    
    newLine(0);    
    System.out.printf("%s %s(", stringify(ansi2TypeMap(first(node))), stringify(second(node)));    
    ansi2FunctionArgs(third(node));    
    System.out.printf(") {");    
    newLine(1);    
    ansi2Declarations(cdr(fourth(node)), 1);    
    if ( inList(toStr(name), noStackTrace())) {      
      System.out.printf("");
    } else {      
      System.out.printf("\nif (globalTrace)\n    printf(\"%s at %s:%s (%%s)\\n\", caller);\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));
    }    
    if ( inList(toStr(name), noStackTrace())) {      
      System.out.printf("");
    } else {
    }    
    ansi2Body(cdr(fifth(node)), 1);    
    if ( inList(toStr(name), noStackTrace())) {      
      System.out.printf("");
    } else {      
      System.out.printf("\nif (globalTrace)\n    printf(\"Leaving %s\\n\");\n", stringify(name));
    }    
    System.out.printf("\n}\n");
  }
if (globalTrace)
   System.out. printf("Leaving ansi2Function\n");

}


//Building function ansi2ForwardDeclaration from line: 248

public void ansi2ForwardDeclaration(Box node) {
    
  if ( isNil(node)) {    
    return;
  } else {    
    System.out.printf("\n%s %s(", stringify(ansi2TypeMap(first(node))), stringify(second(node)));    
    ansi2FunctionArgs(third(node));    
    ansi2displays(");");
  }
if (globalTrace)
   System.out. printf("Leaving ansi2ForwardDeclaration\n");

}


//Building function ansi2ForwardDeclarations from line: 258

public void ansi2ForwardDeclarations(Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    ansi2ForwardDeclaration(car(tree));    
    ansi2ForwardDeclarations(cdr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving ansi2ForwardDeclarations\n");

}


//Building function ansi2Functions from line: 264

public void ansi2Functions(Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    ansi2Function(car(tree));    
    ansi2Functions(cdr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving ansi2Functions\n");

}


//Building function ansi2Includes from line: 270

public void ansi2Includes(Box nodes) {
    
  System.out.printf("%s", "\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\nconst char* getEnv(char* key){return getenv(key);}\n void panic(char* s){abort();exit(1);}\nint sub(int a, int b) { return a - b; }\nfloat mult(int a, int b) { return a * b; }\nint greaterthan(int a, int b) { return a > b; }\nfloat subf(float a, float b) { return a - b; }\nfloat multf(float a, float b) { return a * b; }\nint greaterthanf(float a, float b) { return a > b; }\nint equal(int a, int b) { return a == b; }\nint equalString(char* a, char* b) { return !strcmp(a,b); }\nint andBool(int a, int b) { return a && b;}\nint string_length(char* s) { return strlen(s);}\nchar* setSubString(char* target, int start,char *source){target[start]=source[0]; return target;}\nchar* sub_string(char* s, int start, int length) {\nchar* substr = calloc(length+1, 1);\nstrncpy(substr, s+start, length);\nreturn substr;\n}\n\n\n\nchar* stringConcatenate(char* a, char* b) {\nint len = strlen(a) + strlen(b) + 1;\nchar* target = calloc(len,1);\nstrncat(target, a, len);\nstrncat(target, b, len);\nreturn target;\n}\n\nchar* intToString(int a) {\nint len = 100;\nchar* target = calloc(len,1);\nsnprintf(target, 99, \"%d\", a);\nreturn target;\n}\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\nvoid * gc_malloc( unsigned int size ) {\nreturn malloc( size);\n}\n\nint* makeArray(int length) {\n    int * array = gc_malloc(length*sizeof(int));\n    return array;\n}\n\nint at(int* arr, int index) {\n  return arr[index];\n}\n\nvoid setAt(int* array, int index, int value) {\n    array[index] = value;\n}\n\nchar * read_file(char * filename) {\nchar * buffer = 0;\nlong length;\nFILE * f = fopen (filename, \"rb\");\n\nif (f)\n{\n  fseek (f, 0, SEEK_END);\n  length = ftell (f);\n  fseek (f, 0, SEEK_SET);\n  buffer = calloc (length+1,1);\n  if (buffer == NULL) {\n  printf(\"Malloc failed!\\n\");\n  exit(1);\n}\n  if (buffer)\n  {\n    fread (buffer, 1, length, f);\n  }\n  fclose (f);\n}\nreturn buffer;\n}\n\n\nvoid write_file (char * filename, char * data) {\nFILE *f = fopen(filename, \"w\");\nif (f == NULL)\n{\n    printf(\"Error opening file!\");\n    exit(1);\n}\n\nfprintf(f, \"%s\", data);\n\nfclose(f);\n}\n\nchar* getStringArray(int index, char** strs) {\nreturn strs[index];\n}\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\n\nint main( int argc, char *argv[] )  {\n  globalArgs = argv;\n  globalArgsCount = argc;\n  caller=calloc(1024,1);\n\n  return start();\n\n}\n\n");  
  System.out.printf("%s", "char * character(int num) { char *string = malloc(2); if (!string) return 0; string[0] = num; string[1] = 0; return string; }");  
  System.out.printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n\n");  
  System.out.printf("%s", "bool nand(bool a, bool b) { return !(a&&b); }\n//End include block\n");
if (globalTrace)
   System.out. printf("Leaving ansi2Includes\n");

}


//Building function ansi2TypeDecl from line: 279

public void ansi2TypeDecl(Box l) {
    
  if ( greaterthan(listLength(l), 2)) {    
    printIndent(1);    
    System.out.printf("%s %s %s;\n", stringify(second(l)), stringify(ansi2TypeMap(listLast(l))), stringify(first(l)));
  } else {    
    printIndent(1);    
    System.out.printf("%s %s;\n", stringify(ansi2TypeMap(listLast(l))), stringify(car(l)));
  }
if (globalTrace)
   System.out. printf("Leaving ansi2TypeDecl\n");

}


//Building function ansi2StructComponents from line: 296

public void ansi2StructComponents(Box node) {
    
  if ( isEmpty(node)) {    
    return;
  } else {    
    ansi2TypeDecl(car(node));    
    ansi2StructComponents(cdr(node));
  }
if (globalTrace)
   System.out. printf("Leaving ansi2StructComponents\n");

}


//Building function ansi2Struct from line: 302

public void ansi2Struct(Box node) {
    
  ansi2StructComponents(cdr(node));
if (globalTrace)
   System.out. printf("Leaving ansi2Struct\n");

}


//Building function ansi2TypeMap from line: 305

public Box ansi2TypeMap(Box aSym) {
  Box symMap = null;
  
  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), null));  
  if ( truthy(assoc(stringify(aSym), symMap))) {    
    return(cdr(assoc(stringify(aSym), symMap)));
  } else {    
    return(aSym);
  }
}


//Building function ansi2FuncMap from line: 317

public Box ansi2FuncMap(Box aSym) {
  Box symMap = null;
  
  if ( equalString("symbol", boxType(aSym))) {    
    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), null)))))));    
    if ( truthy(assoc(stringify(aSym), symMap))) {      
      return(cdr(assoc(stringify(aSym), symMap)));
    } else {      
      return(aSym);
    }
  } else {    
    return(aSym);
  }
}


//Building function ansi2Type from line: 348

public void ansi2Type(Box node) {
    
  if ( isList(second(node))) {    
    System.out.printf("\ntypedef struct %s {\n", stringify(first(node)));    
    ansi2Struct(second(node));    
    System.out.printf("\n} %s;\n", stringify(first(node)));
  } else {    
    ansi2displays("typedef ");    
    ansi2TypeDecl(node);
  }
if (globalTrace)
   System.out. printf("Leaving ansi2Type\n");

}


//Building function ansi2Types from line: 358

public void ansi2Types(Box nodes) {
    
  if ( isEmpty(nodes)) {    
    return;
  } else {    
    ansi2Type(car(nodes));    
    ansi2Types(cdr(nodes));
  }
if (globalTrace)
   System.out. printf("Leaving ansi2Types\n");

}


//Building function ansi2Compile from line: 368

public void ansi2Compile(String filename) {
  Box tree = null;
Box replace = null;
  
  System.err.printf("//Scanning file...%s\n", filename);  
  tree = loadQuon(filename);  
  System.err.printf("//Building sexpr\n");  
  tree = loadIncludes(tree);  
  tree = macrowalk(tree);  
  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), null));  
  tree = macrolist(tree, stringConcatenate("q", "log"), replace);  
  System.err.printf("//Printing program\n");  
  ansi2Includes(cdr(first(tree)));  
  ansi2Types(cdr(second(tree)));  
  ansi2displays("Box* globalStackTrace = NULL;\n");  
  ansi2displays("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");  
  ansi2ForwardDeclarations(cdr(third(tree)));  
  ansi2displays("\n\n//End forward declarations\n\n");  
  ansi2Functions(cdr(third(tree)));  
  ansi2displays("\n");
if (globalTrace)
   System.out. printf("Leaving ansi2Compile\n");

}


//Building function ansi3displays from line: 5

public void ansi3displays(String s) {
    
  System.out.printf("%s", s);
if (globalTrace)
   System.out. printf("Leaving ansi3displays\n");

}


//Building function ansi3FunctionArgs from line: 11

public void ansi3FunctionArgs(Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    if ( equalString(stringify(first(tree)), "...")) {      
      System.out.printf("...");
    } else {      
      display(ansi3TypeMap(first(tree)));      
      ansi3displays(" ");      
      display(second(tree));
    }    
    if ( isNil(cddr(tree))) {
    } else {      
      ansi3displays(", ");
    }    
    ansi3FunctionArgs(cddr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving ansi3FunctionArgs\n");

}


//Building function ansi3Expression from line: 28

public void ansi3Expression(Box tree,Integer indent) {
  Box thing = null;
  
  if ( isList(tree)) {    
    if ( equal(1, listLength(tree))) {      
      display(car(tree));      
      if ( equalBox(boxString("return"), car(tree))) {
      } else {        
        ansi3displays("()");
      }
    } else {      
      thing = first(tree);      
      if ( equalBox(boxSymbol("get-struct"), thing)) {        
        System.out.printf("%s->%s", stringify(second(tree)), stringify(third(tree)));
      } else {        
        if ( equalBox(boxSymbol("new"), thing)) {          
          System.out.printf("malloc(sizeof(%s))", stringify(third(tree)));
        } else {          
          if ( equalBox(boxSymbol("passthrough"), thing)) {            
            System.out.printf("%s", stringify(second(tree)));
          } else {            
            if ( equalBox(boxSymbol("binop"), thing)) {              
              System.out.printf("(");              
              ansi3Expression(third(tree), indent);              
              System.out.printf(" %s ", stringify(second(tree)));              
              ansi3Expression(fourth(tree), indent);              
              System.out.printf(")");
            } else {              
              System.out.printf("%s(", stringify(ansi3FuncMap(car(tree))));              
              ansi3RecurList(cdr(tree), indent);              
              System.out.printf(")");
            }
          }
        }
      }
    }
  } else {    
    display(ansi3FuncMap(tree));
  }
if (globalTrace)
   System.out. printf("Leaving ansi3Expression\n");

}


//Building function ansi3RecurList from line: 98

public void ansi3RecurList(Box expr,Integer indent) {
    
  if ( isEmpty(expr)) {    
    return;
  } else {    
    ansi3Expression(car(expr), indent);    
    if ( isNil(cdr(expr))) {      
      ansi3displays("");
    } else {      
      ansi3displays(", ");      
      ansi3RecurList(cdr(expr), indent);
    }
  }
if (globalTrace)
   System.out. printf("Leaving ansi3RecurList\n");

}


//Building function ansi3If from line: 115

public void ansi3If(Box node,Integer indent) {
    
  newLine(indent);  
  ansi3displays("if ( ");  
  ansi3Expression(second(node), 0);  
  ansi3displays(") {");  
  ansi3Body(cdr(third(node)), add1(indent));  
  newLine(indent);  
  ansi3displays("} else {");  
  ansi3Body(cdr(fourth(node)), add1(indent));  
  newLine(indent);  
  ansi3displays("}");
if (globalTrace)
   System.out. printf("Leaving ansi3If\n");

}


//Building function ansi3SetStruct from line: 128

public void ansi3SetStruct(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("%s->%s = ", stringify(second(node)), stringify(third(node)));  
  ansi3Expression(fourth(node), indent);
if (globalTrace)
   System.out. printf("Leaving ansi3SetStruct\n");

}


//Building function ansi3GetStruct from line: 137

public void ansi3GetStruct(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("%s->%s", stringify(first(node)), stringify(second(node)));
if (globalTrace)
   System.out. printf("Leaving ansi3GetStruct\n");

}


//Building function ansi3Set from line: 145

public void ansi3Set(Box node,Integer indent) {
    
  newLine(indent);  
  ansi3Expression(first(cdr(node)), indent);  
  System.out.printf(" = ");  
  ansi3Expression(third(node), indent);
if (globalTrace)
   System.out. printf("Leaving ansi3Set\n");

}


//Building function ansi3Return from line: 152

public void ansi3Return(Box node,Integer indent) {
    
  newLine(indent);  
  if ( equal(listLength(node), 1)) {    
    ansi3displays("return;");
  } else {    
    ansi3displays("return ");    
    ansi3Expression(cadr(node), indent);    
    ansi3displays(";");
  }
if (globalTrace)
   System.out. printf("Leaving ansi3Return\n");

}


//Building function ansi3Statement from line: 163

public void ansi3Statement(Box node,Integer indent) {
    
  if ( equalBox(boxString("set"), first(node))) {    
    ansi3Set(node, indent);
  } else {    
    if ( equalBox(boxString("set-struct"), first(node))) {      
      ansi3SetStruct(node, indent);
    } else {      
      if ( equalBox(boxString("if"), first(node))) {        
        ansi3If(node, indent);
      } else {        
        if ( equalBox(boxString("return"), first(node))) {          
          ansi3Return(node, indent);
        } else {          
          newLine(indent);          
          ansi3Expression(node, indent);
        }
      }
    }
  }  
  ansi3displays(";\n");
if (globalTrace)
   System.out. printf("Leaving ansi3Statement\n");

}


//Building function ansi3Body from line: 181

public void ansi3Body(Box tree,Integer indent) {
  Box code = null;
  
  if ( isEmpty(tree)) {    
    return;
  } else {    
    code = tree;    
    if ( isNil(code)) {
    } else {      
      code = car(tree);      
      if ( not(releaseMode)) {        
        System.out.printf("\nif (globalTrace)\n    snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), stringify(getTagFail(car(code), boxString("line"), boxString("Line missing"))));
      } else {
      }
    }    
    if ( not(releaseMode)) {      
      printIndent(indent);      
      System.out.printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n");
    } else {
    }    
    ansi3Statement(code, indent);    
    ansi3Body(cdr(tree), indent);
  }
if (globalTrace)
   System.out. printf("Leaving ansi3Body\n");

}


//Building function ansi3Declarations from line: 206

public void ansi3Declarations(Box decls,Integer indent) {
  Box decl = null;
  
  if ( isEmpty(decls)) {    
    return;
  } else {    
    decl = car(decls);    
    System.out.printf("%s %s = ", stringify(ansi3TypeMap(first(decl))), stringify(second(decl)));    
    ansi3Expression(third(decl), indent);    
    System.out.printf(";\n");    
    ansi3Declarations(cdr(decls), indent);
  }
if (globalTrace)
   System.out. printf("Leaving ansi3Declarations\n");

}


//Building function ansi3Function from line: 220

public void ansi3Function(Box node) {
  Box name = null;
  
  name = second(node);  
  System.out.printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));  
  newLine(0);  
  if ( isNil(node)) {    
    return;
  } else {    
    newLine(0);    
    System.out.printf("%s %s(", stringify(ansi3TypeMap(first(node))), stringify(second(node)));    
    ansi3FunctionArgs(third(node));    
    System.out.printf(") {");    
    newLine(1);    
    ansi3Declarations(cdr(fourth(node)), 1);    
    if ( releaseMode) {      
      System.out.printf("");
    } else {      
      System.out.printf("\nif (globalTrace)\n    printf(\"%s at %s:%s (%%s)\\n\", caller);\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));
    }    
    if ( releaseMode) {      
      System.out.printf("");
    } else {
    }    
    ansi3Body(cdr(fifth(node)), 1);    
    if ( releaseMode) {      
      System.out.printf("");
    } else {      
      System.out.printf("\nif (globalTrace)\n    printf(\"Leaving %s\\n\");\n", stringify(name));
    }    
    System.out.printf("\n}\n");
  }
if (globalTrace)
   System.out. printf("Leaving ansi3Function\n");

}


//Building function ansi3ForwardDeclaration from line: 255

public void ansi3ForwardDeclaration(Box node) {
    
  if ( isNil(node)) {    
    return;
  } else {    
    System.out.printf("\n%s %s(", stringify(ansi3TypeMap(first(node))), stringify(second(node)));    
    ansi3FunctionArgs(third(node));    
    ansi3displays(");");
  }
if (globalTrace)
   System.out. printf("Leaving ansi3ForwardDeclaration\n");

}


//Building function ansi3ForwardDeclarations from line: 265

public void ansi3ForwardDeclarations(Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    ansi3ForwardDeclaration(car(tree));    
    ansi3ForwardDeclarations(cdr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving ansi3ForwardDeclarations\n");

}


//Building function ansi3Functions from line: 271

public void ansi3Functions(Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    ansi3Function(car(tree));    
    ansi3Functions(cdr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving ansi3Functions\n");

}


//Building function ansi3Includes from line: 277

public void ansi3Includes(Box nodes) {
    
  System.out.printf("%s", "\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\n#include <unistd.h>\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\nbool releaseMode = false;\n\n");  
  System.out.printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n");
if (globalTrace)
   System.out. printf("Leaving ansi3Includes\n");

}


//Building function ansi3TypeDecl from line: 285

public void ansi3TypeDecl(Box l) {
    
  if ( greaterthan(listLength(l), 2)) {    
    printIndent(1);    
    System.out.printf("%s %s %s;\n", stringify(second(l)), stringify(ansi3TypeMap(listLast(l))), stringify(first(l)));
  } else {    
    printIndent(1);    
    System.out.printf("%s %s;\n", stringify(ansi3TypeMap(listLast(l))), stringify(car(l)));
  }
if (globalTrace)
   System.out. printf("Leaving ansi3TypeDecl\n");

}


//Building function ansi3StructComponents from line: 302

public void ansi3StructComponents(Box node) {
    
  if ( isEmpty(node)) {    
    return;
  } else {    
    ansi3TypeDecl(car(node));    
    ansi3StructComponents(cdr(node));
  }
if (globalTrace)
   System.out. printf("Leaving ansi3StructComponents\n");

}


//Building function ansi3Struct from line: 308

public void ansi3Struct(Box node) {
    
  ansi3StructComponents(cdr(node));
if (globalTrace)
   System.out. printf("Leaving ansi3Struct\n");

}


//Building function ansi3TypeMap from line: 311

public Box ansi3TypeMap(Box aSym) {
  Box symMap = null;
  
  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), null));  
  if ( truthy(assoc(stringify(aSym), symMap))) {    
    return(cdr(assoc(stringify(aSym), symMap)));
  } else {    
    return(aSym);
  }
}


//Building function ansi3FuncMap from line: 321

public Box ansi3FuncMap(Box aSym) {
  Box symMap = null;
  
  if ( equalString("symbol", boxType(aSym))) {    
    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), null)))))));    
    if ( truthy(assoc(stringify(aSym), symMap))) {      
      return(cdr(assoc(stringify(aSym), symMap)));
    } else {      
      return(aSym);
    }
  } else {    
    return(aSym);
  }
}


//Building function ansi3Type from line: 352

public void ansi3Type(Box node) {
    
  if ( isList(second(node))) {    
    System.out.printf("\ntypedef struct %s {\n", stringify(first(node)));    
    ansi3Struct(second(node));    
    System.out.printf("\n} %s;\n", stringify(first(node)));
  } else {    
    ansi3displays("typedef ");    
    ansi3TypeDecl(node);
  }
if (globalTrace)
   System.out. printf("Leaving ansi3Type\n");

}


//Building function ansi3Types from line: 362

public void ansi3Types(Box nodes) {
    
  if ( isEmpty(nodes)) {    
    return;
  } else {    
    ansi3Type(car(nodes));    
    ansi3Types(cdr(nodes));
  }
if (globalTrace)
   System.out. printf("Leaving ansi3Types\n");

}


//Building function ansi3Compile from line: 372

public void ansi3Compile(String filename) {
  Box tree = null;
Box replace = null;
  
  System.err.printf("//Scanning file...%s\n", filename);  
  tree = loadQuon(filename);  
  System.err.printf("//Building sexpr\n");  
  System.err.printf("Loading shim ansi3\n");  
  tree = buildProg(cons(boxString("q/shims/ansi3.qon"), getIncludes(tree)), getTypes(tree), getFunctions(tree));  
  System.err.printf("Loading all includes\n");  
  tree = loadIncludes(tree);  
  System.err.printf("Applying macros\n");  
  tree = macrowalk(tree);  
  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), null));  
  tree = macrolist(tree, stringConcatenate("q", "log"), replace);  
  System.err.printf("//Printing program\n");  
  ansi3Includes(cdr(first(tree)));  
  ansi3Types(cdr(second(tree)));  
  ansi3displays("Box* globalStackTrace = NULL;\n");  
  ansi3displays("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");  
  ansi3ForwardDeclarations(cdr(third(tree)));  
  ansi3displays("\n\n//End forward declarations\n\n");  
  ansi3Functions(cdr(third(tree)));  
  ansi3displays("\n");  
  System.err.printf("//Done printing program\n");
if (globalTrace)
   System.out. printf("Leaving ansi3Compile\n");

}


//Building function test0 from line: 7

public void test0() {
    
  if ( equalString(stringify(boxString("hello")), stringify(boxString("hello")))) {    
    System.out.printf("0.  pass string compare works\n");
  } else {    
    System.out.printf("0.  pass string compare fails\n");
  }  
  if ( equalString(stringify(boxString("hello")), stringify(boxSymbol("hello")))) {    
    System.out.printf("0.  pass string compare works\n");
  } else {    
    System.out.printf("0.  pass string compare fails\n");
  }
if (globalTrace)
   System.out. printf("Leaving test0\n");

}


//Building function test1 from line: 20

public void test1() {
    
  System.out.printf("1.  pass Function call and print work\n");
if (globalTrace)
   System.out. printf("Leaving test1\n");

}


//Building function test2_do from line: 24

public void test2_do(String message) {
    
  System.out.printf("2.  pass Function call with arg works: %s\n", message);
if (globalTrace)
   System.out. printf("Leaving test2_do\n");

}


//Building function test2 from line: 28

public void test2() {
    
  test2_do("This is the argument");
if (globalTrace)
   System.out. printf("Leaving test2\n");

}


//Building function test3_do from line: 30

public void test3_do(Integer b,String c) {
    
  System.out.printf("3.1 pass Two arg call, first arg: %d\n", b);  
  System.out.printf("3.2 pass Two arg call, second arg: %s\n", c);
if (globalTrace)
   System.out. printf("Leaving test3_do\n");

}


//Building function test3 from line: 36

public void test3() {
    
  test3_do(42, "Fourty-two");
if (globalTrace)
   System.out. printf("Leaving test3\n");

}


//Building function test4_do from line: 37

public String test4_do() {
    
  return("pass Return works");
}


//Building function returnThis from line: 39

public String returnThis(String returnMessage) {
    
  return(returnMessage);
}


//Building function test4 from line: 42

public void test4() {
  String message = "fail";
  
  message = test4_do();  
  System.out.printf("4.  %s\n", message);
if (globalTrace)
   System.out. printf("Leaving test4\n");

}


//Building function test5 from line: 45

public void test5() {
  String message = "fail";
  
  message = returnThis("pass return passthrough string");  
  System.out.printf("5.  %s\n", message);
if (globalTrace)
   System.out. printf("Leaving test5\n");

}


//Building function test6 from line: 50

public void test6() {
    
  if ( true) {    
    System.out.printf("6.  pass If statement works\n");
  } else {    
    System.out.printf("6.  fail If statement works\n");
  }
if (globalTrace)
   System.out. printf("Leaving test6\n");

}


//Building function test7_do from line: 58

public Integer test7_do(Integer count) {
    
  count = sub(count, 1);  
  if ( greaterthan(count, 0)) {    
    count = test7_do(count);
  } else {    
    return(count);
  }  
  return(count);
}


//Building function test7 from line: 66

public void test7() {
    
  if ( equal(0, test7_do(10))) {    
    System.out.printf("7.  pass count works\n");
  } else {    
    System.out.printf("7.  fail count fails\n");
  }
if (globalTrace)
   System.out. printf("Leaving test7\n");

}


//Building function beer from line: 74

public void beer() {
    
  System.out.printf("%d bottle of beer on the wall, %d bottle of beer.  Take one down, pass it round, no bottles of beer on the wall\n", 1, 1);
if (globalTrace)
   System.out. printf("Leaving beer\n");

}


//Building function plural from line: 83

public String plural(Integer num) {
    
  if ( equal(num, 1)) {    
    return("");
  } else {    
    return("s");
  }
}


//Building function beers from line: 88

public Integer beers(Integer count) {
  Integer newcount = 0;
  
  newcount = sub(count, 1);  
  System.out.printf("%d bottle%s of beer on the wall, %d bottle%s of beer.  Take one down, pass it round, %d bottle%s of beer on the wall\n", count, plural(count), count, plural(count), newcount, plural(newcount));  
  if ( greaterthan(count, 1)) {    
    count = beers(newcount);
  } else {    
    return(count);
  }  
  return(0);
}


//Building function test8 from line: 104

public void test8() {
    
  if ( equal(sub(sub(2, 1), sub(3, 1)), -1)) {    
    System.out.printf("8.  pass Nested expressions work\n");
  } else {    
    System.out.printf("8.  fail Nested expressions don't work\n");
  }
if (globalTrace)
   System.out. printf("Leaving test8\n");

}


//Building function test9 from line: 112

public void test9() {
  Integer answer = -999999;
Integer a = 2;
Integer b = 3;
  
  answer = sub(sub(20, 1), sub(3, 1));  
  if ( equal(answer, 17)) {    
    System.out.printf("9.1  pass sub works\n");
  } else {    
    System.out.printf("9.1  fail sub\n");
  }  
  answer = add(2, 3);  
  if ( equal(answer, 5)) {    
    System.out.printf("9.2  pass add works\n");
  } else {    
    System.out.printf("9.2  fail add\n");
  }  
  answer = mult(a, b);  
  if ( equal(answer, 6)) {    
    System.out.printf("9.3  pass mult works\n");
  } else {    
    System.out.printf("9.3  fail mult\n");
  }  
  if ( greaterthan(2, 1)) {    
    System.out.printf("9.4  pass greaterthan works\n");
  } else {    
    System.out.printf("9.4  fail greaterthan\n");
  }  
  if ( equal(1, 1)) {    
    System.out.printf("9.5  pass integer equal works\n");
  } else {    
    System.out.printf("9.5  fail integer equal\n");
  }  
  if ( equalString("hello", "hello")) {    
    System.out.printf("9.6  pass string equal works\n");
  } else {    
    System.out.printf("9.6  fail string equal\n");
  }  
  if ( equalString("hello", "world")) {    
    System.out.printf("9.7  fail string equal\n");
  } else {    
    System.out.printf("9.7  pass string equal\n");
  }  
  if ( andBool(false, false)) {    
    System.out.printf("9.8  fail andBool\n");
  } else {    
    System.out.printf("9.8  pass andBool works\n");
  }  
  if ( andBool(true, true)) {    
    System.out.printf("9.9  pass andBool works\n");
  } else {    
    System.out.printf("9.9  fail andBool\n");
  }  
  if ( andBool(true, false)) {    
    System.out.printf("9.10  fail andBool\n");
  } else {    
    System.out.printf("9.10  pass andBool works\n");
  }  
  if ( equalString("hello", "hello")) {    
    System.out.printf("9.11  pass string equal\n");
  } else {    
    System.out.printf("9.11  fail string equal\n");
  }  
  if ( equalString("!", character(33))) {    
    System.out.printf("9.12  pass character\n");
  } else {    
    System.out.printf("9.12  fail character\n");
  }  
  if ( equalString("33", intToString(33))) {    
    System.out.printf("9.13  pass intToString\n");
  } else {    
    System.out.printf("9.13  fail intToString\n");
  }  
  if ( equalString("llo", sub_string("hello", a, b))) {    
    System.out.printf("9.14  pass sub-string\n");
  } else {    
    System.out.printf("9.14  fail sub-string: %s\n", sub_string("hello", a, b));
  }
if (globalTrace)
   System.out. printf("Leaving test9\n");

}


//Building function test10 from line: 170

public void test10() {
  String testString = "This is a test string";
  
  if ( equalString(testString, unBoxString(car(cons(boxString(testString), null))))) {    
    System.out.printf("10. pass cons and car work\n");
  } else {    
    System.out.printf("10. fail cons and car fail\n");
  }
if (globalTrace)
   System.out. printf("Leaving test10\n");

}


//Building function test12 from line: 180

public void test12() {
  Box b = null;
  
  b = new Box();  
  b.str = "12. pass structure accessors\n";  
  System.out.printf("%s", b.str);
if (globalTrace)
   System.out. printf("Leaving test12\n");

}


//Building function test13 from line: 188

public void test13() {
  String testString = "Hello from the filesystem!";
String contents = "";
  
  write_file("test.txt", testString);  
  contents = read_file("test.txt");  
  if ( equalString(testString, contents)) {    
    System.out.printf("13. pass Read and write files\n");
  } else {    
    System.out.printf("13. fail Read and write files\n");    
    System.out.printf("Expected: %s\n", testString);    
    System.out.printf("Got: %s\n", contents);
  }
if (globalTrace)
   System.out. printf("Leaving test13\n");

}


//Building function test15 from line: 204

public void test15() {
  String a = "hello";
String b = " world";
String c = "";
  
  c = stringConcatenate(a, b);  
  if ( equalString(c, "hello world")) {    
    System.out.printf("15. pass String concatenate\n");
  } else {    
    System.out.printf("15. fail String concatenate\n");
  }
if (globalTrace)
   System.out. printf("Leaving test15\n");

}


//Building function test16 from line: 212

public void test16() {
  Box assocCell1 = null;
Box assList = null;
Box assocCell2 = null;
Box assocCell3 = null;
  
  assocCell1 = cons(boxString("Hello"), boxString("world"));  
  assocCell2 = cons(boxString("goodnight"), boxString("moon"));  
  assocCell3 = cons(boxSymbol("ohio"), boxString("gozaimasu"));  
  assList = cons(assocCell2, emptyList());  
  assList = cons(assocCell1, assList);  
  assList = cons(assocCell3, assList);  
  if ( equalBox(cdr(assoc("Hello", assList)), boxString("world"))) {    
    System.out.printf("16.1 pass Basic assoc works\n");
  } else {    
    System.out.printf("16.1 fail Basic assoc fails\n");
  }  
  if ( andBool(andBool(equalBox(cdr(assoc("Hello", assList)), boxString("world")), equalBox(cdr(assoc("goodnight", assList)), boxString("moon"))), equalBox(cdr(assoc("ohio", assList)), boxString("gozaimasu")))) {    
    System.out.printf("16.2 pass assoc list\n");
  } else {    
    System.out.printf("16.2 fail assoc list\n");
  }
if (globalTrace)
   System.out. printf("Leaving test16\n");

}


//Building function test17 from line: 236

public void test17() {
  Box l = null;
  
  l = cons(boxInt(1), cons(boxInt(2), cons(boxInt(3), null)));  
  if ( equalBox(car(l), boxInt(1))) {    
    System.out.printf("17. pass list literal works\n");
  } else {    
    System.out.printf("17. fail list literal failed\n");
  }
if (globalTrace)
   System.out. printf("Leaving test17\n");

}


//Building function test18 from line: 247

public void test18() {
  String val1 = "a";
String val2 = "b";
Box l = null;
  
  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), null)));  
  if ( equalList(l, cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), null))))) {    
    System.out.printf("18. pass string list constructor works\n");
  } else {    
    System.out.printf("18. fail string list constructor failed\n");
  }
if (globalTrace)
   System.out. printf("Leaving test18\n");

}


//Building function test19 from line: 261

public void test19() {
  String val1 = "a";
String val2 = "b";
Box l = null;
Box revlist = null;
Box answer = null;
  
  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), null)));  
  answer = cons(boxString("c"), cons(boxString(val2), cons(boxString(val1), null)));  
  revlist = reverseList(l);  
  if ( equalList(answer, revlist)) {    
    System.out.printf("19. pass reverseList\n");
  } else {    
    System.out.printf("19. fail reverseList\n");
  }
if (globalTrace)
   System.out. printf("Leaving test19\n");

}


//Building function concatenateLists from line: 279

public Box concatenateLists(Box oldL,Box newL) {
    
  return(reverseRec(reverseList(oldL), newL));
}


//Building function test20 from line: 284

public void test20() {
  String val1 = "a";
String val2 = "b";
String val3 = "c";
Box l = null;
Box l2 = null;
Box l3 = null;
Box combined = null;
  
  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), null)));  
  l2 = cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), null)));  
  l3 = cons(boxString(val1), cons(boxString(val2), cons(boxString(val3), cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), null))))));  
  combined = concatenateLists(l, l2);  
  if ( equalList(l3, combined)) {    
    System.out.printf("21. pass concatenateLists\n");
  } else {    
    System.out.printf("21. fail concatenateLists\n");
  }
if (globalTrace)
   System.out. printf("Leaving test20\n");

}


//Building function test21 from line: 304

public void test21() {
  String val1 = "a";
String val2 = "b";
String val3 = "c";
Box l = null;
Box l2 = null;
  
  l = cons(boxString(val1), cons(boxString(val2), cons(boxString(val3), null)));  
  l2 = cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), null)));  
  if ( equalList(l, l2)) {    
    System.out.printf("21. pass equalList\n");
  } else {    
    System.out.printf("21. fail equalList\n");
  }
if (globalTrace)
   System.out. printf("Leaving test21\n");

}


//Building function test22 from line: 320

public void test22() {
  Box original = null;
Box out = null;
Box replace = null;
Box correct = null;
  
  original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), null)));  
  replace = cons(boxString("fprintf"), cons(boxString("stderr"), null));  
  out = macrolist(original, stringConcatenate("q", "log"), replace);  
  correct = cons(boxString("fprintf"), cons(boxString("stderr"), cons(boxString("%s"), cons(boxString("hello"), null))));  
  if ( equalList(out, correct)) {    
    System.out.printf("22. pass macroList\n");
  } else {    
    System.out.printf("22. fail macroList\n");    
    System.out.printf("In: ");    
    displayList(original, 0, true);    
    System.out.printf("\nOut: ");    
    displayList(out, 0, true);    
    System.out.printf("\n");
  }
if (globalTrace)
   System.out. printf("Leaving test22\n");

}


//Building function test23 from line: 343

public void test23() {
  Box original = null;
Box out = null;
Box replace = null;
Box correct = null;
  
  original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), null)));  
  replace = cons(boxString("fprintf"), cons(boxString("stderr"), null));  
  out = concatLists(original, replace);  
  correct = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), cons(boxString("fprintf"), cons(boxString("stderr"), null)))));  
  if ( equalList(out, correct)) {    
    System.out.printf("23. pass concatLists\n");
  } else {    
    System.out.printf("23. fail concatLists\n");    
    System.out.printf("In: ");    
    displayList(original, 0, true);    
    System.out.printf("\nOut: ");    
    displayList(out, 0, true);
  }
if (globalTrace)
   System.out. printf("Leaving test23\n");

}


//Building function test24 from line: 366

public void test24() {
  String expected = "a b c";
String res = "";
  
  res = StringListJoin(cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), null))), " ");  
  if ( equalString(expected, res)) {    
    System.out.printf("24. pass StringListJoin\n");
  } else {    
    System.out.printf("24. fail StringListJoin.  expected '%s', got '%s'\n", expected, res);
  }
if (globalTrace)
   System.out. printf("Leaving test24\n");

}


//Building function test25 from line: 380

public void test25() {
  String expected = "( a b ) c d e";
String res = "";
Box testsubstr = [cons 
(boxString "c ") 
(cons 
  (boxString "d ") 
  (cons 
    (boxString "e") nil))];
Box input = null;
  
  input = cons(boxString("a "), cons(boxString("b "), null));  
  input = cons(input, testsubstr);  
  res = ListToString(input, 0, true, false);  
  if ( equalString(expected, res)) {    
    System.out.printf("25. pass ListToString\n");
  } else {    
    System.out.printf("25. fail ListToString.  expected '%s', got '%s'\n", expected, res);
  }
if (globalTrace)
   System.out. printf("Leaving test25\n");

}


//Building function nodeFunctionArgs from line: 4

public void nodeFunctionArgs(Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    display(second(tree));    
    if ( isNil(cddr(tree))) {      
      System.out.printf("");
    } else {      
      System.out.printf(",");
    }    
    nodeFunctionArgs(cddr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving nodeFunctionArgs\n");

}


//Building function nodeLeaf from line: 13

public void nodeLeaf(Box thisNode,Integer indent) {
    
  display(nodeFuncMap(codeof(thisNode)));
if (globalTrace)
   System.out. printf("Leaving nodeLeaf\n");

}


//Building function nodeStructGetterExpression from line: 16

public void nodeStructGetterExpression(Box thisNode,Integer indent) {
    
  if ( equalBox(boxString("structGetter"), subnameof(thisNode))) {    
    nodeGetStruct(thisNode, indent);
  } else {    
    nodeLeaf(thisNode, indent);
  }
if (globalTrace)
   System.out. printf("Leaving nodeStructGetterExpression\n");

}


//Building function nodeExpression from line: 22

public void nodeExpression(Box node,Integer indent) {
    
  if ( isLeaf(node)) {    
    display(nodeFuncMap(codeof(node)));
  } else {    
    nodeSubExpression(node, indent);
  }
if (globalTrace)
   System.out. printf("Leaving nodeExpression\n");

}


//Building function nodeRecurList from line: 28

public void nodeRecurList(Box expr,Integer indent) {
    
  if ( isEmpty(expr)) {    
    return;
  } else {    
    nodeExpression(car(expr), indent);    
    if ( isNil(cdr(expr))) {      
      System.out.printf("");
    } else {      
      System.out.printf(", ");      
      nodeRecurList(cdr(expr), indent);
    }
  }
if (globalTrace)
   System.out. printf("Leaving nodeRecurList\n");

}


//Building function nodeSubExpression from line: 41

public void nodeSubExpression(Box tree,Integer indent) {
  Box thing = null;
  
  if ( isEmpty(tree)) {    
    return;
  } else {    
    if ( isNode(childrenof(tree))) {      
      nodeSubExpression(childrenof(tree), indent);
    } else {      
      if ( isLeaf(tree)) {        
        display(nodeFuncMap(codeof(tree)));
      } else {        
        if ( equal(1, listLength(childrenof(tree)))) {          
          display(codeof(car(childrenof(tree))));          
          if ( equalBox(boxString("return"), codeof(car(childrenof(tree))))) {            
            System.out.printf("");
          } else {            
            System.out.printf("()");
          }
        } else {          
          thing = codeof(car(childrenof(tree)));          
          if ( equalBox(boxSymbol("get-struct"), thing)) {            
            System.out.printf("%s.%s", stringify(codeof(second(childrenof(tree)))), stringify(codeof(third(childrenof(tree)))));
          } else {            
            if ( equalBox(boxSymbol("new"), thing)) {              
              System.out.printf("{}");
            } else {              
              System.out.printf("%s(", stringify(nodeFuncMap(codeof(car(childrenof(tree))))));              
              nodeRecurList(cdr(childrenof(tree)), indent);              
              System.out.printf(")");
            }
          }
        }
      }
    }
  }
if (globalTrace)
   System.out. printf("Leaving nodeSubExpression\n");

}


//Building function nodeIf from line: 82

public void nodeIf(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("if ( ");  
  nodeExpression(car(first(childrenof(node))), 0);  
  System.out.printf(") {");  
  nodeBody(second(childrenof(node)), add1(indent));  
  newLine(indent);  
  System.out.printf("} else {");  
  nodeBody(third(childrenof(node)), add1(indent));  
  newLine(indent);  
  System.out.printf("}");
if (globalTrace)
   System.out. printf("Leaving nodeIf\n");

}


//Building function nodeGetStruct from line: 96

public void nodeGetStruct(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("%s.%s", stringify(first(codeof(node))), stringify(second(codeof(node))));
if (globalTrace)
   System.out. printf("Leaving nodeGetStruct\n");

}


//Building function nodeSet from line: 104

public void nodeSet(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("%s = ", stringify(first(codeof(node))));  
  nodeExpression(childrenof(node), indent);
if (globalTrace)
   System.out. printf("Leaving nodeSet\n");

}


//Building function nodeSetStruct from line: 110

public void nodeSetStruct(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("%s.%s = ", stringify(first(codeof(node))), stringify(second(codeof(node))));  
  nodeExpression(childrenof(node), indent);
if (globalTrace)
   System.out. printf("Leaving nodeSetStruct\n");

}


//Building function nodeStatement from line: 118

public void nodeStatement(Box node,Integer indent) {
    
  if ( equalBox(boxString("setter"), subnameof(node))) {    
    nodeSet(node, indent);
  } else {    
    if ( equalBox(boxString("structSetter"), subnameof(node))) {      
      nodeSetStruct(node, indent);
    } else {      
      if ( equalBox(boxString("if"), subnameof(node))) {        
        nodeIf(node, indent);
      } else {        
        if ( equalBox(boxString("returnvoid"), subnameof(node))) {          
          newLine(indent);          
          System.out.printf("return");
        } else {          
          newLine(indent);          
          nodeExpression(childrenof(node), indent);
        }
      }
    }
  }  
  System.out.printf(";\n");
if (globalTrace)
   System.out. printf("Leaving nodeStatement\n");

}


//Building function nodeBody from line: 137

public void nodeBody(Box tree,Integer indent) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    printIndent(indent);    
    System.out.printf("%s", "if (globalStepTrace) {console.log(new Error(\"StepTrace \\n\"));}\n");    
    nodeStatement(car(tree), indent);    
    nodeBody(cdr(tree), indent);
  }
if (globalTrace)
   System.out. printf("Leaving nodeBody\n");

}


//Building function nodeDeclarations from line: 151

public void nodeDeclarations(Box decls,Integer indent) {
  Box decl = null;
  
  if ( isEmpty(decls)) {    
    return;
  } else {    
    decl = car(decls);    
    System.out.printf("var %s = ", stringify(second(decl)));    
    display(nodeFuncMap(third(decl)));    
    System.out.printf(";\n");    
    nodeDeclarations(cdr(decls), indent);
  }
if (globalTrace)
   System.out. printf("Leaving nodeDeclarations\n");

}


//Building function nodeFunction from line: 166

public void nodeFunction(Box node) {
  Box name = null;
  
  name = subnameof(node);  
  System.out.printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));  
  newLine(0);  
  if ( isNil(node)) {    
    return;
  } else {    
    newLine(0);    
    System.out.printf("function %s(", stringify(subnameof(node)));    
    nodeFunctionArgs(cdr(assoc("intype", cdr(node))));    
    System.out.printf(") {");    
    newLine(1);    
    nodeDeclarations(declarationsof(node), 1);    
    if ( releaseMode) {      
      System.out.printf("");
    } else {      
      System.out.printf("\nif (globalTrace)\n    {printf(\"%s at %s:%s\\n\");}\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));
    }    
    if ( releaseMode) {      
      System.out.printf("");
    } else {
    }    
    nodeBody(childrenof(node), 1);    
    if ( releaseMode) {      
      System.out.printf("");
    } else {      
      System.out.printf("\nif (globalTrace)\n    {printf(\"Leaving %s\\n\");}\n", stringify(name));
    }    
    System.out.printf("\n}\n");
  }
if (globalTrace)
   System.out. printf("Leaving nodeFunction\n");

}


//Building function nodeForwardDeclaration from line: 199

public void nodeForwardDeclaration(Box node) {
    
  if ( isNil(node)) {    
    return;
  } else {    
    System.out.printf("\n%s %s(", stringify(nodeTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));    
    nodeFunctionArgs(cdr(assoc("intype", cdr(node))));    
    System.out.printf(");");
  }
if (globalTrace)
   System.out. printf("Leaving nodeForwardDeclaration\n");

}


//Building function nodeForwardDeclarations from line: 211

public void nodeForwardDeclarations(Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    nodeForwardDeclaration(car(tree));    
    nodeForwardDeclarations(cdr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving nodeForwardDeclarations\n");

}


//Building function nodeFunctions from line: 221

public void nodeFunctions(Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    nodeFunction(car(tree));    
    nodeFunctions(cdr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving nodeFunctions\n");

}


//Building function nodeIncludes from line: 229

public void nodeIncludes(Box nodes) {
    
  System.out.printf("%s", "function read_file(filename) {return fs.readFileSync(filename);}\n");  
  System.out.printf("%s", "function write_file(filename, data) {fs.writeFileSync(filename, data);}\n");  
  System.out.printf("%s", "var util = require('util');\n");  
  System.out.printf("%s", "function printf() {process.stdout.write(util.format.apply(this, arguments));}\n");  
  System.out.printf("%s", "function qlog()   {process.stderr.write(util.format.apply(this, arguments));}\n");  
  System.out.printf("%s", "var fs = require('fs');\n");  
  System.out.printf("%s", "function equalString(a,b) {if (a==null) {return false;}if (b==null) {return false;}return a.toString()===b.toString() }\n");  
  System.out.printf("%s", "function panic(s){console.trace(s);process.exit(1);}\n");  
  System.out.printf("%s", "function dump(s){console.log(s)}");  
  System.out.printf("%s", "function sub(a, b) { return a - b; }\n");  
  System.out.printf("%s", "function mult(a, b) { return a * b; }\n");  
  System.out.printf("%s", "function greaterthan(a, b) { return a > b; }\n");  
  System.out.printf("%s", "function subf(a, b) { return a - b; }\n");  
  System.out.printf("%s", "function multf(a, b) { return a * b; }\n");  
  System.out.printf("%s", "function greaterthanf(a, b) { return a > b; }\n");  
  System.out.printf("%s", "function equal(a, b) { return a == b; }\n");  
  System.out.printf("%s", "function andBool(a, b) { return a == b;}\n");  
  System.out.printf("%s", "function string_length(s) { return s.length;}\n");  
  System.out.printf("%s", "function sub_string(str, start, len) {str = ''+str;return str.substring(start, start+len)};\n");  
  System.out.printf("%s", "function stringConcatenate(a, b) { return a + b}\n");  
  System.out.printf("%s", "function intToString(a) {}\n\n\n");  
  System.out.printf("%s", "function gc_malloc( size ) {\nreturn {};\n}\n\n");  
  System.out.printf("%s", "function makeArray(length) {\n   return [];\n}\n\n");  
  System.out.printf("%s", "function at(arr, index) {\n  return arr[index];\n}\n\n");  
  System.out.printf("%s", "function setAt(array, index, value) {\n    array[index] = value;\n}\n\n");  
  System.out.printf("%s", "function getStringArray(index, strs) {\nreturn strs[index];\n}\n\n");  
  System.out.printf("%s", "var NULL = null;");  
  System.out.printf("%s", "var globalArgs;\nvar globalArgsCount;\nvar globalTrace = false;\nvar globalStepTrace = false;\nvar releaseMode = false;\n");  
  System.out.printf("%s", "function character(num) {}");
if (globalTrace)
   System.out. printf("Leaving nodeIncludes\n");

}


//Building function nodeTypeDecl from line: 263

public void nodeTypeDecl(Box l) {
    
  if ( greaterthan(listLength(l), 2)) {    
    printIndent(1);    
    System.out.printf("%s %s %s;\n", stringify(second(l)), stringify(nodeTypeMap(listLast(l))), stringify(first(l)));
  } else {    
    printIndent(1);    
    System.out.printf("%s %s;\n", stringify(nodeTypeMap(listLast(l))), stringify(car(l)));
  }
if (globalTrace)
   System.out. printf("Leaving nodeTypeDecl\n");

}


//Building function nodeStructComponents from line: 280

public void nodeStructComponents(Box node) {
    
  if ( isEmpty(node)) {    
    return;
  } else {    
    nodeTypeDecl(car(node));    
    nodeStructComponents(cdr(node));
  }
if (globalTrace)
   System.out. printf("Leaving nodeStructComponents\n");

}


//Building function nodeStruct from line: 288

public void nodeStruct(Box node) {
    
  nodeStructComponents(cdr(car(node)));
if (globalTrace)
   System.out. printf("Leaving nodeStruct\n");

}


//Building function nodeTypeMap from line: 293

public Box nodeTypeMap(Box aSym) {
  Box symMap = null;
  
  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), null));  
  if ( truthy(assoc(stringify(aSym), symMap))) {    
    return(cdr(assoc(stringify(aSym), symMap)));
  } else {    
    return(aSym);
  }
}


//Building function nodeFuncMap from line: 308

public Box nodeFuncMap(Box aSym) {
  Box symMap = null;
  
  if ( equalString("symbol", boxType(aSym))) {    
    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), null)))))));    
    if ( truthy(assoc(stringify(aSym), symMap))) {      
      return(cdr(assoc(stringify(aSym), symMap)));
    } else {      
      return(aSym);
    }
  } else {    
    return(aSym);
  }
}


//Building function nodeType from line: 339

public void nodeType(Box node) {
  
if (globalTrace)
   System.out. printf("Leaving nodeType\n");

}


//Building function nodeTypes from line: 343

public void nodeTypes(Box nodes) {
    
  if ( isEmpty(nodes)) {    
    return;
  } else {    
    nodeType(car(nodes));    
    nodeTypes(cdr(nodes));
  }
if (globalTrace)
   System.out. printf("Leaving nodeTypes\n");

}


//Building function nodeCompile from line: 351

public void nodeCompile(String filename) {
  String programStr = "";
Box tree = null;
Box program = null;
  
  programStr = read_file(filename);  
  tree = readSexpr(programStr, filename);  
  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), null)));  
  program = mergeIncludes(program);  
  nodeIncludes(cdr(assoc("includes", program)));  
  nodeTypes(childrenof(cdr(assoc("types", program))));  
  System.out.printf("\nvar globalStackTrace = NULL;\n");  
  System.out.printf("\nvar caller = \"\";\n");  
  System.out.printf("\nfunction isNil(p) {\n    return p == NULL;\n}\n\n");  
  nodeFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));  
  System.out.printf("\n");  
  System.out.printf("const [asfdasdf, ...qwerqwer] = process.argv;");  
  System.out.printf("globalArgs = qwerqwer;");  
  System.out.printf("globalArgsCount = qwerqwer.length;");  
  System.out.printf("%s", "start();\n");
if (globalTrace)
   System.out. printf("Leaving nodeCompile\n");

}


//Building function node2Compile from line: 4

public Box node2Compile(String filename) {
  String programStr = "";
Box tree = null;
Box program = null;
  
  programStr = read_file(filename);  
  tree = readSexpr(programStr, filename);  
  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), emptyList())));  
  program = mergeIncludes(program);  
  return(cons(node2Includes(cdr(assoc("includes", program))), cons(boxString("\nvar globalStackTrace = NULL;\n"), cons(boxString("\nvar caller = \"\";\n"), cons(boxString("\nfunction isNil(p) {\n    return p == NULL;\n}\n\n"), cons(node2Functions(cdr(assoc("children", cdr(cdr(assoc("functions", program)))))), cons(boxString("\n"), cons(boxString("const [asfdasdf, ...qwerqwer] = process.argv;"), cons(boxString("globalArgs = qwerqwer;"), cons(boxString("globalArgsCount = qwerqwer.length;"), cons(boxString("start();\n"), emptyList())))))))))));
}


//Building function node2Includes from line: 33

public Box node2Includes(Box nodes) {
    
  return(cons(boxString("function read_file(filename) {return fs.readFileSync(filename);}\n"), cons(boxString("function write_file(filename, data) {fs.writeFileSync(filename, data);}\n"), cons(boxString("var util = require('util');\n"), cons(boxString("function printf() {process.stdout.write(util.format.apply(this, arguments));}\n"), cons(boxString("function qlog()   {process.stderr.write(util.format.apply(this, arguments));}\n"), cons(boxString("var fs = require('fs');\n"), cons(boxString("function equalString(a,b) {if (a==null) {return false;}if (b==null) {return false;}return a.toString()===b.toString() }\n"), cons(boxString("function panic(s){console.trace(s);process.exit(1);}\n"), cons(boxString("function dump(s){console.log(s)}"), cons(boxString("function sub(a, b) { return a - b; }\n"), cons(boxString("function mult(a, b) { return a * b; }\n"), cons(boxString("function greaterthan(a, b) { return a > b; }\n"), cons(boxString("function subf(a, b) { return a - b; }\n"), cons(boxString("function multf(a, b) { return a * b; }\n"), cons(boxString("function greaterthanf(a, b) { return a > b; }\n"), cons(boxString("function equal(a, b) { return a == b; }\n"), cons(boxString("function andBool(a, b) { return a == b;}\n"), cons(boxString("function string_length(s) { return s.length;}\n"), cons(boxString("function sub_string(str, start, len) {str = ''+str;return str.substring(start, start+len)};\n"), cons(boxString("function stringConcatenate(a, b) { return a + b}\n"), cons(boxString("function intToString(a) {}\n\n\n"), cons(boxString("function gc_malloc( size ) {\nreturn {};\n}\n\n"), cons(boxString("function makeArray(length) {\n   return [];\n}\n\n"), cons(boxString("function at(arr, index) {\n  return arr[index];\n}\n\n"), cons(boxString("function setAt(array, index, value) {\n    array[index] = value;\n}\n\n"), cons(boxString("function getStringArray(index, strs) {\nreturn strs[index];\n}\n\n"), cons(boxString("var NULL = null;"), cons(boxString("var globalArgs;\nvar globalArgsCount;\nvar globalTrace = false;\nvar globalStepTrace = false;\nvar releaseMode = false;\n"), cons(boxString("function character(num) {}"), null))))))))))))))))))))))))))))));
}


//Building function node2Functions from line: 68

public Box node2Functions(Box tree) {
    
  if ( isEmpty(tree)) {    
    return(emptyList());
  } else {    
    node2Function(car(tree));    
    node2Functions(cdr(tree));
  }
}


//Building function node2Function from line: 76

public Box node2Function(Box node) {
  Box name = null;
  
  if ( isNil(node)) {    
    return(emptyList());
  } else {    
    name = subnameof(node);    
    return(cons(boxString("\n\n//Building function "), cons(boxString(stringify(name)), cons(boxString(" from line: "), cons(boxString(stringify(getTag(name, boxString("line")))), null)))), "\n", "\n", "function ", stringify(subnameof(node)), "(", ") {", "\n", stringIndent(1), ListToString(flatten(ternList(releaseMode, boxString(""), cons(boxString("\nif (globalTrace)\n    {printf(\""), cons(boxString(stringify(name)), cons(boxString(" at "), cons(boxString(stringify(getTag(name, boxString("filename")))), cons(boxString(":"), cons(boxString(stringify(getTag(name, boxString("line")))), cons(boxString("\\n\");}\n"), null)))))))))), ListToString(flatten(nodeBody(childrenof(node), 1))), ternString(releaseMode, "", ListToString("\nif (globalTrace)\n    {printf(\"Leaving ", stringify(name), "\\n\");}\n")), "\n}\n");
  }  
  return(emptyList());
}


//Building function javaFunctionArgs from line: 3

public void javaFunctionArgs(Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    display(javaTypeMap(first(tree)));    
    System.out.printf(" ");    
    display(second(tree));    
    if ( isNil(cddr(tree))) {      
      System.out.printf("");
    } else {      
      System.out.printf(",");
    }    
    javaFunctionArgs(cddr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving javaFunctionArgs\n");

}


//Building function javaLeaf from line: 14

public void javaLeaf(Box thisNode,Integer indent) {
    
  display(javaFuncMap(codeof(thisNode)));
if (globalTrace)
   System.out. printf("Leaving javaLeaf\n");

}


//Building function javaStructGetterExpression from line: 17

public void javaStructGetterExpression(Box thisNode,Integer indent) {
    
  if ( equalBox(boxString("structGetter"), subnameof(thisNode))) {    
    javaGetStruct(thisNode, indent);
  } else {    
    javaLeaf(thisNode, indent);
  }
if (globalTrace)
   System.out. printf("Leaving javaStructGetterExpression\n");

}


//Building function javaExpression from line: 23

public void javaExpression(Box node,Integer indent) {
    
  if ( isLeaf(node)) {    
    display(javaFuncMap(codeof(node)));
  } else {    
    javaSubExpression(node, indent);
  }
if (globalTrace)
   System.out. printf("Leaving javaExpression\n");

}


//Building function javaRecurList from line: 29

public void javaRecurList(Box expr,Integer indent) {
    
  if ( isEmpty(expr)) {    
    return;
  } else {    
    javaExpression(car(expr), indent);    
    if ( isNil(cdr(expr))) {      
      System.out.printf("");
    } else {      
      System.out.printf(", ");      
      javaRecurList(cdr(expr), indent);
    }
  }
if (globalTrace)
   System.out. printf("Leaving javaRecurList\n");

}


//Building function javaSubExpression from line: 41

public void javaSubExpression(Box tree,Integer indent) {
  Box thing = null;
  
  if ( isEmpty(tree)) {    
    return;
  } else {    
    if ( isNode(childrenof(tree))) {      
      javaSubExpression(childrenof(tree), indent);
    } else {      
      if ( isLeaf(tree)) {        
        display(javaFuncMap(codeof(tree)));
      } else {        
        if ( equal(1, listLength(childrenof(tree)))) {          
          display(codeof(car(childrenof(tree))));          
          if ( equalBox(boxString("return"), codeof(car(childrenof(tree))))) {            
            System.out.printf("");
          } else {            
            System.out.printf("()");
          }
        } else {          
          thing = codeof(car(childrenof(tree)));          
          if ( equalBox(boxSymbol("get-struct"), thing)) {            
            System.out.printf("%s.%s", stringify(codeof(second(childrenof(tree)))), stringify(codeof(third(childrenof(tree)))));
          } else {            
            if ( equalBox(boxSymbol("new"), thing)) {              
              System.out.printf("new %s()", stringify(codeof(third(childrenof(tree)))));
            } else {              
              System.out.printf("%s(", stringify(javaFuncMap(codeof(car(childrenof(tree))))));              
              javaRecurList(cdr(childrenof(tree)), indent);              
              System.out.printf(")");
            }
          }
        }
      }
    }
  }
if (globalTrace)
   System.out. printf("Leaving javaSubExpression\n");

}


//Building function javaIf from line: 81

public void javaIf(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("if ( ");  
  javaExpression(car(first(childrenof(node))), 0);  
  System.out.printf(") {");  
  javaBody(second(childrenof(node)), add1(indent));  
  newLine(indent);  
  System.out.printf("} else {");  
  javaBody(third(childrenof(node)), add1(indent));  
  newLine(indent);  
  System.out.printf("}");
if (globalTrace)
   System.out. printf("Leaving javaIf\n");

}


//Building function javaSetStruct from line: 94

public void javaSetStruct(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("%s.%s = ", stringify(first(codeof(node))), stringify(second(codeof(node))));  
  javaExpression(childrenof(node), indent);  
  System.out.printf(";");
if (globalTrace)
   System.out. printf("Leaving javaSetStruct\n");

}


//Building function javaGetStruct from line: 105

public void javaGetStruct(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("%s.%s", stringify(first(codeof(node))), stringify(second(codeof(node))));
if (globalTrace)
   System.out. printf("Leaving javaGetStruct\n");

}


//Building function javaSet from line: 113

public void javaSet(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("%s = ", stringify(first(codeof(node))));  
  javaExpression(childrenof(node), indent);  
  System.out.printf(";");
if (globalTrace)
   System.out. printf("Leaving javaSet\n");

}


//Building function javaStatement from line: 121

public void javaStatement(Box node,Integer indent) {
    
  if ( equalBox(boxString("setter"), subnameof(node))) {    
    javaSet(node, indent);
  } else {    
    if ( equalBox(boxString("structSetter"), subnameof(node))) {      
      javaSetStruct(node, indent);
    } else {      
      if ( equalBox(boxString("if"), subnameof(node))) {        
        javaIf(node, indent);
      } else {        
        if ( equalBox(boxString("returnvoid"), subnameof(node))) {          
          newLine(indent);          
          System.out.printf("return;");
        } else {          
          newLine(indent);          
          javaExpression(childrenof(node), indent);          
          System.out.printf(";");
        }
      }
    }
  }
if (globalTrace)
   System.out. printf("Leaving javaStatement\n");

}


//Building function javaBody from line: 141

public void javaBody(Box tree,Integer indent) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    printIndent(indent);    
    System.out.printf("");    
    javaStatement(car(tree), indent);    
    javaBody(cdr(tree), indent);
  }
if (globalTrace)
   System.out. printf("Leaving javaBody\n");

}


//Building function javaDeclarations from line: 151

public void javaDeclarations(Box decls,Integer indent) {
  Box decl = null;
  
  if ( isEmpty(decls)) {    
    return;
  } else {    
    decl = car(decls);    
    System.out.printf("%s %s = ", stringify(javaTypeMap(first(decl))), stringify(second(decl)));    
    display(javaFuncMap(third(decl)));    
    System.out.printf(";\n");    
    javaDeclarations(cdr(decls), indent);
  }
if (globalTrace)
   System.out. printf("Leaving javaDeclarations\n");

}


//Building function javaFunction from line: 165

public void javaFunction(Box node) {
  Box name = null;
  
  name = subnameof(node);  
  System.out.printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));  
  newLine(0);  
  if ( isNil(node)) {    
    return;
  } else {    
    newLine(0);    
    System.out.printf("public %s %s(", stringify(javaTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));    
    javaFunctionArgs(cdr(assoc("intype", cdr(node))));    
    System.out.printf(") {");    
    newLine(1);    
    javaDeclarations(declarationsof(node), 1);    
    if ( inList(toStr(name), noStackTrace())) {      
      System.out.printf("");
    } else {      
      System.out.printf("");
    }    
    if ( inList(toStr(name), noStackTrace())) {      
      System.out.printf("");
    } else {
    }    
    javaBody(childrenof(node), 1);    
    if ( inList(toStr(name), noStackTrace())) {      
      System.out.printf("");
    } else {      
      if ( equalString("void", stringify(javaTypeMap(cdr(assoc("outtype", cdr(node))))))) {        
        System.out.printf("\nif (globalTrace)\n   System.out. printf(\"Leaving %s\\n\");\n", stringify(name));
      } else {        
        System.out.printf("");
      }
    }    
    System.out.printf("\n}\n");
  }
if (globalTrace)
   System.out. printf("Leaving javaFunction\n");

}


//Building function javaFunctions from line: 204

public void javaFunctions(Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    javaFunction(car(tree));    
    javaFunctions(cdr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving javaFunctions\n");

}


//Building function javaIncludes from line: 210

public void javaIncludes(Box nodes) {
    
  System.out.printf("%s", "public void panic(String s) {System.exit(1);}\n");  
  System.out.printf("%s", "public void exit(Integer s) {System.exit(s);}\n");  
  System.out.printf("%s", "public int sub(int a, int b) { return a - b; }\n");  
  System.out.printf("%s", "public Integer mult(int a, int b) { return a * b; }\n");  
  System.out.printf("%s", "public boolean greaterthan(int a, int b) { return a > b; }\n");  
  System.out.printf("%s", "public double subf(double a, double b) { return a - b; }\n");  
  System.out.printf("%s", "public double multf(double a, double b) { return a * b; }\n");  
  System.out.printf("%s", "public boolean greaterthanf(double a, double b) { return a > b; }\n");  
  System.out.printf("%s", "public boolean equal(int a, int b) { return a == b; }\n");  
  System.out.printf("%s", "public boolean equalString(String a, String b) { return a.equals(b); }\n");  
  System.out.printf("%s", "public int string_length(String s) { return s.length();}\n");  
  System.out.printf("%s", "public String stringConcatenate(String s1, String s2) { return s1 + s2; }\n");  
  System.out.printf("%s", "public int strcmp(String s1, String s2) { return s1.compareTo(s2);}\n");  
  System.out.printf("%s", "public String read_file(String filename) {try { return new String(Files.readAllBytes(Paths.get(filename)));} catch (Exception e) {panic(\"Could not read file\");return \"\";}}\n");  
  System.out.printf("%s", "public void write_file(String filename, String data) {try {Files.write(Paths.get(filename), data.getBytes(\"UTF-8\"));} catch (Exception e) {panic(\"Could not write file\");}}\n");  
  System.out.printf("%s", "public String sub_string(String s, int start, int length) {\nreturn s.substring(start, start+length);\n}\n\n\n\n");  
  System.out.printf("%s", "public String intToString(int num) { char c=(char) num;  String s=Character.toString(c); return s;}");  
  System.out.printf("%s", "public String character(int num) { char c=(char) num;  String s=Character.toString(c); return s;}");  
  System.out.printf("%s", "public String getStringArray(int index, String[] arr) { return arr[index];}");
if (globalTrace)
   System.out. printf("Leaving javaIncludes\n");

}


//Building function javaTypeDecl from line: 233

public void javaTypeDecl(Box l) {
    
  if ( greaterthan(listLength(l), 2)) {    
    printIndent(1);    
    System.out.printf("%s %s;\n", stringify(javaTypeMap(listLast(l))), stringify(first(l)));
  } else {    
    printIndent(1);    
    System.out.printf("%s %s;\n", stringify(javaTypeMap(listLast(l))), stringify(car(l)));
  }
if (globalTrace)
   System.out. printf("Leaving javaTypeDecl\n");

}


//Building function javaStructComponents from line: 250

public void javaStructComponents(Box node) {
    
  if ( isEmpty(node)) {    
    return;
  } else {    
    javaTypeDecl(car(node));    
    javaStructComponents(cdr(node));
  }
if (globalTrace)
   System.out. printf("Leaving javaStructComponents\n");

}


//Building function javaStruct from line: 256

public void javaStruct(Box node) {
    
  javaStructComponents(cdr(car(node)));
if (globalTrace)
   System.out. printf("Leaving javaStruct\n");

}


//Building function javaTypeMap from line: 259

public Box javaTypeMap(Box aSym) {
  Box symMap = null;
  
  symMap = alistCons(boxSymbol("pair"), boxSymbol("Box"), alistCons(boxSymbol("bool"), boxSymbol("boolean"), alistCons(boxSymbol("box"), boxSymbol("Box"), alistCons(boxSymbol("list"), boxSymbol("Box"), alistCons(boxSymbol("Box*"), boxSymbol("Box"), alistCons(boxSymbol("struct"), boxSymbol(""), alistCons(boxSymbol("int"), boxSymbol("Integer"), alistCons(boxSymbol("float"), boxSymbol("double"), alistCons(boxSymbol("stringArray"), boxSymbol("String[]"), alistCons(boxSymbol("string"), boxSymbol("String"), null))))))))));  
  if ( truthy(assoc(stringify(aSym), symMap))) {    
    return(cdr(assoc(stringify(aSym), symMap)));
  } else {    
    return(aSym);
  }
}


//Building function javaTypesNoDeclare from line: 277

public Box javaTypesNoDeclare() {
  Box syms = null;
  
  syms = cons(boxString("pair"), cons(boxString("box"), null));  
  return(syms);
}


//Building function javaFuncMap from line: 286

public Box javaFuncMap(Box aSym) {
  Box symMap = null;
  
  if ( equalString("symbol", boxType(aSym))) {    
    symMap = alistCons(boxSymbol("printf"), boxSymbol("System.out.printf"), alistCons(boxSymbol(stringConcatenate("q", "log")), boxSymbol("System.err.printf"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("null"), null)))))))));    
    if ( truthy(assoc(stringify(aSym), symMap))) {      
      return(cdr(assoc(stringify(aSym), symMap)));
    } else {      
      return(aSym);
    }
  } else {    
    return(aSym);
  }
}


//Building function javaType from line: 307

public void javaType(Box node) {
    
  if ( equalBox(subnameof(node), boxString("struct"))) {    
    System.out.printf("\npublic class %s {\n", stringify(first(codeof(node))));    
    System.out.printf("\npublic String caller =\"\";");    
    javaStruct(cdr(codeof(node)));    
    System.out.printf("\n};\n");
  } else {    
    if ( inList(boxString(stringify(first(codeof(node)))), javaTypesNoDeclare())) {      
      System.out.printf("");
    } else {      
      System.out.printf("public class %s extends %s {};\n", stringify(first(codeof(node))), stringify(javaTypeMap(listLast(codeof(node)))));
    }
  }
if (globalTrace)
   System.out. printf("Leaving javaType\n");

}


//Building function javaTypes from line: 324

public void javaTypes(Box nodes) {
    
  if ( isEmpty(nodes)) {    
    return;
  } else {    
    javaType(car(nodes));    
    javaTypes(cdr(nodes));
  }
if (globalTrace)
   System.out. printf("Leaving javaTypes\n");

}


//Building function javaCompile from line: 330

public void javaCompile(String filename) {
  String programStr = "";
Box tree = null;
Box program = null;
  
  System.out.printf("%s", "package quonverter;\n");  
  System.out.printf("%s", "import java.nio.file.Files;\n");  
  System.out.printf("%s", "import java.nio.file.Paths;\n");  
  System.out.printf("%s", "import java.io.IOException;\n");  
  System.out.printf("%s", "import java.io.UnsupportedEncodingException;\n");  
  System.out.printf("class MyProgram {\n");  
  System.out.printf("\npublic String caller =\"\";");  
  programStr = read_file(filename);  
  tree = readSexpr(programStr, filename);  
  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), null)));  
  program = mergeIncludes(program);  
  javaIncludes(cdr(assoc("includes", program)));  
  javaTypes(childrenof(cdr(assoc("types", program))));  
  System.out.printf("public boolean globalStackTrace = false;\n");  
  System.out.printf("public boolean globalStepTrace = false;\n");  
  System.out.printf("public boolean globalTrace = false;\n");  
  System.out.printf("public boolean releaseMode = false;\n");  
  System.out.printf("public String FILE = null;\n");  
  System.out.printf("public Integer LINE = 0;\n");  
  System.out.printf("public static Integer globalArgsCount = 0;\n");  
  System.out.printf("public static String globalArgs[];\n");  
  System.out.printf("\npublic boolean isNil(Box p) {\n    return p == null;\n}\n\n\n");  
  javaFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));  
  System.out.printf("%s", "public static void main(String args[]) {\nglobalArgs = args;\nglobalArgsCount = args.length;MyProgram mp = new MyProgram(); mp.start();\n}");  
  System.out.printf("}\n");
if (globalTrace)
   System.out. printf("Leaving javaCompile\n");

}


//Building function luaFunctionArgs from line: 4

public void luaFunctionArgs(Integer indent,Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    display(second(tree));    
    if ( isNil(cddr(tree))) {      
      System.out.printf("");
    } else {      
      System.out.printf(",");
    }    
    luaFunctionArgs(indent, cddr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving luaFunctionArgs\n");

}


//Building function luaFunction from line: 14

public void luaFunction(Integer indent,Box functionDefinition) {
  String fname = "";
  
  fname = stringify(second(functionDefinition));  
  System.out.printf("-- Chose function name %s", fname);  
  System.out.printf("\nfunction %s(", fname);  
  luaFunctionArgs(indent, third(functionDefinition));  
  System.out.printf(")\n");  
  System.out.printf("print(\"caller: \", caller, \"-> %s\")\n", fname);  
  luaDeclarations(add1(indent), cdr(fourth(functionDefinition)));  
  luaBody(fname, indent, cdr(fifth(functionDefinition)));  
  System.out.printf("end\n");
if (globalTrace)
   System.out. printf("Leaving luaFunction\n");

}


//Building function luaDeclarations from line: 26

public void luaDeclarations(Integer indent,Box declarations) {
  Box decl = null;
  
  if ( isNil(declarations)) {    
    return;
  } else {    
    decl = first(declarations);    
    System.out.printf("local %s =", stringify(second(decl)));    
    luaExpressionStart(indent, third(decl));    
    System.out.printf("\n");    
    luaDeclarations(indent, cdr(declarations));
  }
if (globalTrace)
   System.out. printf("Leaving luaDeclarations\n");

}


//Building function luaExpressionStart from line: 42

public void luaExpressionStart(Integer indent,Box program) {
    
  if ( isNil(program)) {    
    return;
  } else {    
    if ( isList(program)) {      
      if ( equalString(stringify(car(program)), "get-struct")) {        
        System.out.printf("%s.%s", stringify(second(program)), stringify(third(program)));
      } else {        
        if ( equalString(stringify(car(program)), ">")) {          
          System.out.printf("greaterthan(");          
          luaExpression(indent, cdr(program));          
          System.out.printf(")");
        } else {          
          if ( equalString(stringify(car(program)), "=")) {            
            System.out.printf("equal(");            
            luaExpression(indent, cdr(program));            
            System.out.printf(")");
          } else {            
            System.out.printf("%s(", stringify(car(program)));            
            luaExpression(indent, cdr(program));            
            System.out.printf(")");
          }
        }
      }
    } else {      
      luaExpression(indent, program);
    }
  }
if (globalTrace)
   System.out. printf("Leaving luaExpressionStart\n");

}


//Building function luaExpression from line: 84

public void luaExpression(Integer indent,Box program) {
    
  if ( isNil(program)) {    
    return;
  } else {    
    if ( isList(program)) {      
      if ( isList(car(program))) {        
        luaExpressionStart(indent, car(program));
      } else {        
        display(car(program));
      }      
      if ( greaterthan(listLength(program), 1)) {        
        System.out.printf(", ");
      } else {
      }      
      luaExpression(indent, cdr(program));
    } else {      
      display(program);
    }
  }
if (globalTrace)
   System.out. printf("Leaving luaExpression\n");

}


//Building function luaStatement from line: 112

public void luaStatement(Integer indent,Box statement) {
    
  if ( equalString(stringify(car(statement)), "if")) {    
    printIndent(indent);    
    System.out.printf("if ");    
    add1(indent);    
    luaExpressionStart(add1(indent), second(statement));    
    System.out.printf(" then\n");    
    luaBody(caller, add1(indent), cdr(third(statement)));    
    printIndent(indent);    
    System.out.printf("else\n");    
    luaBody(caller, add1(indent), cdr(fourth(statement)));    
    printIndent(indent);    
    System.out.printf("end\n");
  } else {    
    if ( equalString(stringify(car(statement)), "set")) {      
      printIndent(indent);      
      System.out.printf("%s = ", stringify(second(statement)));      
      luaExpressionStart(add1(indent), third(statement));
    } else {      
      if ( equalString(stringify(car(statement)), "set-struct")) {        
        System.out.printf("%s.%s = ", stringify(second(statement)), stringify(third(statement)));        
        luaExpressionStart(indent, fourth(statement));
      } else {        
        if ( equalString(stringify(car(statement)), "return")) {          
          printIndent(indent);          
          System.out.printf("return ");          
          if ( greaterthan(listLength(statement), 1)) {            
            luaExpressionStart(indent, second(statement));
          } else {
          }          
          System.out.printf("\n");
        } else {          
          printIndent(indent);          
          luaExpressionStart(indent, statement);          
          System.out.printf(";\n");
        }
      }
    }
  }
if (globalTrace)
   System.out. printf("Leaving luaStatement\n");

}


//Building function luaBody from line: 164

public void luaBody(String local_caller,Integer indent,Box program) {
  Box statement = null;
  
  if ( isNil(program)) {    
    return;
  } else {    
    statement = car(program);    
    System.out.printf("caller = \"%s:%s:%d\"\n", local_caller, unBoxString(getTagFail(statement, boxString("filename"), boxString("Unknown file"))), unBoxInt(getTagFail(statement, boxString("line"), boxInt(-1))));    
    luaStatement(add1(indent), statement);    
    System.out.printf("\n");    
    luaBody(local_caller, indent, cdr(program));
  }
if (globalTrace)
   System.out. printf("Leaving luaBody\n");

}


//Building function luaFunctions from line: 176

public void luaFunctions(Integer indent,Box program) {
    
  if ( isNil(program)) {    
    return;
  } else {    
    luaFunction(indent, car(program));    
    luaFunctions(indent, cdr(program));
  }
if (globalTrace)
   System.out. printf("Leaving luaFunctions\n");

}


//Building function luaProgram from line: 188

public void luaProgram(Box program) {
    
  luaIncludes(null);  
  luaFunctions(0, cdr(third(program)));
if (globalTrace)
   System.out. printf("Leaving luaProgram\n");

}


//Building function luaIncludes from line: 195

public void luaIncludes(Box nodes) {
    
  System.out.printf("%s", "\nfunction luaDump(o)\n   if type(o) == 'table' then\n      local s = '{ '\n      for k,v in pairs(o) do\n         if type(k) ~= 'number' then k = '\"'..k..'\"' end\n         s = s .. '['..k..'] = ' .. luaDump(v) .. ','\n      end\n      return s .. '} '\n   else\n      return tostring(o)\n   end\nend\nprintf = function(s,...)\nreturn io.write(s:format(...))\nend -- function\n    \nfunction stringConcatenate(a,b)\nreturn a..b\nend\n    \nfunction getStringArray(index, arr)\nreturn arr[index]\nend\n       \nfunction luaWriteFile(name, data)  \nlocal file = io.open(name, \"w\")\nfile:write(data)\nfile:close(file)\nend\n    function luaSubstring(s, start, length)\nreturn string.sub(s, start, start+length)\nend\n    \n    function luaReadFile(file)\n      local f = assert(io.open(file, \"rb\"))\n      local content = f:read(\"*all\")      f:close()\n      return content\n    end\n     \nfunction equalString(a,b)\n        return a==b;\n     end\n    \n     function new()\n        return {};\n     end\n    \n     function isNil(val)\n        return val == nil;\n     end\n    \n     function getEnv(key)\n        return os.getenv(key);\n     end\n    \n    function panic(s)\n      print(s);\n    os.exit()\n    end\n    \n    function sub(a, b) \n      return a - b; \n    end\n\n    function mult(a, b) \n      return a * b;\n    end\n    \n    function greaterthan(a, b)\n      return a > b;\n    end\n    \n    function subf(a, b) \n      return a - b;\n    end\n    \n    function multf(a, b)\n      return a * b;\n    end\n    \n    function greaterthanf(a, b)\n      return a > b;\n    end\n    \n    function equal(a, b)\n      return a == b;\n    end\n    \n    function andBool(a, b)\n      return a == b;\n    end\n    \n    function string_length(s)\n      return strlen(s);\n    end\n    \n    function setSubString(target, start, source)\n      panic(\"stub\");\n      end\n    \n    function sub_string(s, start, length)\n      panic(\"stub\");\n    end\n    \n    function intToString(a)\n      panic(\"stub\")\n return a\n    end\n\n    function gc_malloc(size)\n      return \"\"\n    end\n    \n    function makeArray(length)\n      return {}\n    end\n    \n    function at(arr, index)\n      return arr[index+1];\n    end\n    \n    function setAt(array, index, value)\n      array[index+1] = value;\n    end\n    \n    function read_file(file)\n      local f = io.open(file, \"r\")\n      local content = \"\"\n      local length = 0\n\n      while f:read(0) ~= \"\" do\n          local current = f:read(\"*all\")\n\n          print(#current, length)\n          length = length + #current\n\n          content = content .. current\n      end\n\n      return content\n    end\n    \n    function write_file(filename, data)\n      local file = io.open(filename,'w')\n      file:write(tostring(data))\n      file:close()\n    end\n    \n    caller=\"main\";\n    \n    globalArgs={};\n    globalArgsCount=0;\n    globalTrace = false;\n    globalStepTrace = false;\n\n    function main()\n      globalArgs = arg;\n      globalArgsCount = #arg + 1;\n      return start();\n    end\n    \n");
if (globalTrace)
   System.out. printf("Leaving luaIncludes\n");

}


//Building function luaCompile from line: 203

public void luaCompile(String filename) {
  Box tree = null;
  
  tree = loadQuon(filename);  
  tree = loadIncludes(tree);  
  tree = macrowalk(tree);  
  tree = macrosingle(tree, "write-file", "luaWriteFile");  
  tree = macrosingle(tree, "read-file", "luaReadFile");  
  tree = macrosingle(tree, "string-length", "string.len");  
  tree = macrosingle(tree, "sub-string", "luaSubstring");  
  tree = macrosingle(tree, "stringLength", "string.len");  
  luaProgram(tree);  
  System.out.printf("\n");  
  System.out.printf("function main()\nglobalArgs = arg\nglobalArgsCount = #arg\nstart()\nend\n");  
  System.out.printf("main()");
if (globalTrace)
   System.out. printf("Leaving luaCompile\n");

}


//Building function not from line: 3

public boolean not(boolean a) {
    
  if ( a) {    
    return(false);
  } else {    
    return(true);
  }
}


//Building function andBool from line: 10

public boolean andBool(boolean a,boolean b) {
    
  if ( a) {    
    if ( b) {      
      return(true);
    } else {      
      return(false);
    }
  } else {    
    return(false);
  }
}


//Building function nand from line: 20

public boolean nand(boolean a,boolean b) {
    
  return(not(andBool(a, b)));
}


//Building function xor from line: 25

public boolean xor(boolean a,boolean b) {
    
  return(nand(nand(a, nand(a, b)), nand(b, nand(a, b))));
}


//Building function imaFunctionArgs from line: 4

public void imaFunctionArgs(Integer indent,Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    display(second(tree));    
    System.out.printf(": ");    
    display(first(tree));    
    if ( isNil(cddr(tree))) {      
      System.out.printf("");
    } else {      
      System.out.printf(", ");
    }    
    imaFunctionArgs(indent, cddr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving imaFunctionArgs\n");

}


//Building function imaFunction from line: 16

public void imaFunction(Integer indent,Box functionDefinition) {
  String fname = "";
  
  fname = stringify(second(functionDefinition));  
  System.out.printf("\nfu %s(", fname);  
  imaFunctionArgs(indent, third(functionDefinition));  
  System.out.printf(") ");  
  System.out.printf("-> %s", stringify(first(functionDefinition)));  
  imaDeclarations(add1(indent), cdr(fourth(functionDefinition)));  
  if ( greaterthan(listLength(cdr(fourth(functionDefinition))), 0)) {    
    System.out.printf("\n");
  } else {    
    System.out.printf(" ");
  }  
  printIndent(indent);  
  System.out.printf("in\n");  
  imaBody(fname, indent, cdr(fifth(functionDefinition)));  
  System.out.printf("end function\n");
if (globalTrace)
   System.out. printf("Leaving imaFunction\n");

}


//Building function imaDeclarations from line: 37

public void imaDeclarations(Integer indent,Box declarations) {
  Box decl = null;
  
  if ( isNil(declarations)) {    
    return;
  } else {    
    decl = first(declarations);    
    System.out.printf("\n");    
    printIndent(indent);    
    System.out.printf("%s: %s ", stringify(second(decl)), stringify(first(decl)));    
    imaExpressionStart(indent, third(decl));    
    imaDeclarations(indent, cdr(declarations));
  }
if (globalTrace)
   System.out. printf("Leaving imaDeclarations\n");

}


//Building function imaExpressionStart from line: 56

public void imaExpressionStart(Integer indent,Box program) {
    
  if ( isNil(program)) {    
    return;
  } else {    
    if ( isList(program)) {      
      if ( equalString(stringify(car(program)), "get-struct")) {        
        System.out.printf("%s.%s", stringify(second(program)), stringify(third(program)));
      } else {        
        if ( equalString(stringify(car(program)), ">")) {          
          System.out.printf("greaterthan(");          
          imaExpression(indent, cdr(program));          
          System.out.printf(")");
        } else {          
          if ( equalString(stringify(car(program)), "=")) {            
            System.out.printf("equal(");            
            imaExpression(indent, cdr(program));            
            System.out.printf(")");
          } else {            
            System.out.printf("%s(", stringify(car(program)));            
            imaExpression(indent, cdr(program));            
            System.out.printf(")");
          }
        }
      }
    } else {      
      imaExpression(indent, program);
    }
  }
if (globalTrace)
   System.out. printf("Leaving imaExpressionStart\n");

}


//Building function imaExpression from line: 98

public void imaExpression(Integer indent,Box program) {
    
  if ( isNil(program)) {    
    return;
  } else {    
    if ( isList(program)) {      
      if ( isList(car(program))) {        
        imaExpressionStart(indent, car(program));
      } else {        
        display(car(program));
      }      
      if ( greaterthan(listLength(program), 1)) {        
        System.out.printf(", ");
      } else {
      }      
      imaExpression(indent, cdr(program));
    } else {      
      display(program);
    }
  }
if (globalTrace)
   System.out. printf("Leaving imaExpression\n");

}


//Building function imaStatement from line: 126

public void imaStatement(Integer indent,Box statement) {
    
  if ( equalString(stringify(car(statement)), "if")) {    
    printIndent(indent);    
    System.out.printf("if ");    
    add1(indent);    
    imaExpressionStart(add1(indent), second(statement));    
    System.out.printf(" then\n");    
    imaBody(caller, add1(indent), cdr(third(statement)));    
    printIndent(indent);    
    System.out.printf("else\n");    
    imaBody(caller, add1(indent), cdr(fourth(statement)));    
    printIndent(indent);    
    System.out.printf("end\n");
  } else {    
    if ( equalString(stringify(car(statement)), "set")) {      
      printIndent(indent);      
      System.out.printf("%s = ", stringify(second(statement)));      
      imaExpressionStart(add1(indent), third(statement));      
      System.out.printf(";\n");
    } else {      
      if ( equalString(stringify(car(statement)), "set-struct")) {        
        printIndent(indent);        
        System.out.printf("%s.%s = ", stringify(second(statement)), stringify(third(statement)));        
        imaExpressionStart(indent, fourth(statement));        
        System.out.printf(";\n");
      } else {        
        if ( equalString(stringify(car(statement)), "return")) {          
          printIndent(indent);          
          System.out.printf("return; ");          
          if ( greaterthan(listLength(statement), 1)) {            
            imaExpressionStart(indent, second(statement));
          } else {
          }          
          System.out.printf("\n");
        } else {          
          printIndent(indent);          
          imaExpressionStart(indent, statement);          
          System.out.printf(";\n");
        }
      }
    }
  }
if (globalTrace)
   System.out. printf("Leaving imaStatement\n");

}


//Building function imaBody from line: 181

public void imaBody(String local_caller,Integer indent,Box program) {
  Box statement = null;
  
  if ( isNil(program)) {    
    return;
  } else {    
    statement = car(program);    
    imaStatement(add1(indent), statement);    
    imaBody(local_caller, indent, cdr(program));
  }
if (globalTrace)
   System.out. printf("Leaving imaBody\n");

}


//Building function imaFunctions from line: 192

public void imaFunctions(Integer indent,Box program) {
    
  if ( isNil(program)) {    
    return;
  } else {    
    imaFunction(indent, car(program));    
    imaFunctions(indent, cdr(program));
  }
if (globalTrace)
   System.out. printf("Leaving imaFunctions\n");

}


//Building function imaTypeDecl from line: 202

public void imaTypeDecl(Box l) {
  String name = "";
Box body = null;
  
  name = stringify(first(l));  
  body = cdr(l);  
  if ( greaterthan(listLength(l), 2)) {    
    printIndent(1);    
    System.out.printf("%s is ", name);    
    displayList(body, 0, true);    
    System.out.printf(";\n");
  } else {    
    printIndent(1);    
    System.out.printf("%s is %s;\n", name, stringify(second(l)));
  }
if (globalTrace)
   System.out. printf("Leaving imaTypeDecl\n");

}


//Building function imaStructComponents from line: 227

public void imaStructComponents(Box node) {
    
  if ( isEmpty(node)) {    
    return;
  } else {    
    imaTypeDecl(car(node));    
    imaStructComponents(cdr(node));
  }
if (globalTrace)
   System.out. printf("Leaving imaStructComponents\n");

}


//Building function imaStruct from line: 233

public void imaStruct(Box node) {
    
  imaStructComponents(cdr(car(node)));
if (globalTrace)
   System.out. printf("Leaving imaStruct\n");

}


//Building function imaTypeMap from line: 236

public Box imaTypeMap(Box aSym) {
  Box symMap = null;
  
  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), null));  
  if ( truthy(assoc(stringify(aSym), symMap))) {    
    return(cdr(assoc(stringify(aSym), symMap)));
  } else {    
    return(aSym);
  }
}


//Building function imaType from line: 248

public void imaType(Box node) {
  String name = "";
Box body = null;
  
  name = stringify(first(node));  
  body = cdr(node);  
  if ( isList(first(body))) {    
    System.out.printf("\ntype %s is struct (\n", name);    
    imaStruct(body);    
    System.out.printf(");\n");
  } else {    
    System.out.printf("type");    
    imaTypeDecl(node);
  }
if (globalTrace)
   System.out. printf("Leaving imaType\n");

}


//Building function imaTypes from line: 263

public void imaTypes(Integer indent,Box nodes) {
    
  if ( isEmpty(nodes)) {    
    return;
  } else {    
    imaType(car(nodes));    
    imaTypes(indent, cdr(nodes));
  }
if (globalTrace)
   System.out. printf("Leaving imaTypes\n");

}


//Building function imaProgram from line: 272

public void imaProgram(Box program) {
    
  imaIncludes(0, cdr(first(program)));  
  System.out.printf("\nTypes:\n");  
  imaTypes(0, cdr(second(program)));  
  System.out.printf("\nFunctions:\n");  
  imaFunctions(0, cdr(third(program)));
if (globalTrace)
   System.out. printf("Leaving imaProgram\n");

}


//Building function imaIncludes from line: 282

public void imaIncludes(Integer indent,Box nodes) {
    
  System.out.printf("Includes: \n");  
  displayList(nodes, 0, true);
if (globalTrace)
   System.out. printf("Leaving imaIncludes\n");

}


//Building function imaCompile from line: 289

public void imaCompile(String filename) {
  Box tree = null;
  
  tree = loadQuon("compiler.qon");  
  tree = loadIncludes(tree);  
  tree = macrowalk(tree);  
  tree = macrosingle(tree, "write-file", "imaWriteFile");  
  tree = macrosingle(tree, "read-file", "imaReadFile");  
  tree = macrosingle(tree, "string-length", "string.len");  
  tree = macrosingle(tree, "sub-string", "imaSubstring");  
  tree = macrosingle(tree, "stringLength", "string.len");  
  imaProgram(tree);  
  System.out.printf("\n");  
  System.out.printf("function main()\nglobalArgs = arg\nglobalArgsCount = #arg\nstart()\nend\n");  
  System.out.printf("main()");
if (globalTrace)
   System.out. printf("Leaving imaCompile\n");

}


//Building function bashdisplays from line: 5

public void bashdisplays(String s) {
    
  System.out.printf("%s", s);
if (globalTrace)
   System.out. printf("Leaving bashdisplays\n");

}


//Building function bashFunctionArgs from line: 11

public void bashFunctionArgs(Box decls,Integer argNum,Integer indent) {
    
  if ( isEmpty(decls)) {    
    return;
  } else {    
    System.out.printf("local %s=\"%s%s", stringify(second(decls)), dollar(), stringify(boxInt(argNum)));    
    System.out.printf("\" ;\n");    
    bashFunctionArgs(cdr(cdr(decls)), add(1, argNum), indent);
  }
if (globalTrace)
   System.out. printf("Leaving bashFunctionArgs\n");

}


//Building function bashExpression from line: 26

public void bashExpression(Box tree,Integer indent,boolean statement) {
  Box thing = null;
  
  if ( isList(tree)) {    
    if ( equal(1, listLength(tree))) {      
      display(car(tree));      
      if ( equalBox(boxString("return"), car(tree))) {
      } else {        
        bashdisplays("()");
      }
    } else {      
      thing = first(tree);      
      if ( equalBox(boxSymbol("get-struct"), thing)) {        
        System.out.printf("%s->%s", stringify(second(tree)), stringify(third(tree)));
      } else {        
        if ( equalBox(boxSymbol("new"), thing)) {          
          System.out.printf("malloc(sizeof(%s))", stringify(third(tree)));
        } else {          
          if ( equalBox(boxSymbol("passthrough"), thing)) {            
            System.out.printf("%s", stringify(second(tree)));
          } else {            
            if ( equalBox(boxSymbol("binop"), thing)) {              
              System.out.printf("(");              
              bashExpression(third(tree), indent, false);              
              System.out.printf(" %s ", stringify(second(tree)));              
              bashExpression(fourth(tree), indent, false);              
              System.out.printf(")");
            } else {              
              if ( statement) {                
                System.out.printf("%s ", stringify(bashFuncMap(car(tree))));                
                bashRecurList(cdr(tree), indent);
              } else {                
                System.out.printf("%s(%s ", dollar(), stringify(bashFuncMap(car(tree))));                
                bashRecurList(cdr(tree), indent);                
                System.out.printf(")");
              }
            }
          }
        }
      }
    }
  } else {    
    display(bashVarOrLit(tree));
  }
if (globalTrace)
   System.out. printf("Leaving bashExpression\n");

}


//Building function bashVarOrLit from line: 102

public Box bashVarOrLit(Box a) {
    
  if ( equalString("symbol", boxType(a))) {    
    return(boxSymbol(stringConcatenate(dollar(), stringify(a))));
  } else {    
    return(a);
  }
}


//Building function bashRecurList from line: 111

public void bashRecurList(Box expr,Integer indent) {
    
  if ( isEmpty(expr)) {    
    return;
  } else {    
    bashExpression(car(expr), indent, false);    
    if ( isNil(cdr(expr))) {      
      bashdisplays("");
    } else {      
      bashdisplays(" ");      
      bashRecurList(cdr(expr), indent);
    }
  }
if (globalTrace)
   System.out. printf("Leaving bashRecurList\n");

}


//Building function bashIf from line: 128

public void bashIf(Box node,Integer indent) {
    
  newLine(indent);  
  bashdisplays("if (( ");  
  bashExpression(second(node), 0, false);  
  bashdisplays(" )) ; then ");  
  bashBody(cdr(third(node)), add1(indent));  
  newLine(indent);  
  bashdisplays(" else ");  
  bashBody(cdr(fourth(node)), add1(indent));  
  newLine(indent);  
  bashdisplays("fi");
if (globalTrace)
   System.out. printf("Leaving bashIf\n");

}


//Building function bashSetStruct from line: 141

public void bashSetStruct(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("%s%s_%s%s=", dollar(), stringify(second(node)), dollar(), stringify(third(node)));  
  bashExpression(fourth(node), indent, false);
if (globalTrace)
   System.out. printf("Leaving bashSetStruct\n");

}


//Building function bashGetStruct from line: 152

public void bashGetStruct(Box node,Integer indent) {
    
  newLine(indent);  
  System.out.printf("%s%s_%s%s", dollar(), stringify(first(node)), dollar(), stringify(second(node)));
if (globalTrace)
   System.out. printf("Leaving bashGetStruct\n");

}


//Building function bashSet from line: 162

public void bashSet(Box node,Integer indent) {
    
  newLine(indent);  
  display(first(cdr(node)));  
  System.out.printf("=");  
  bashExpression(third(node), indent, false);
if (globalTrace)
   System.out. printf("Leaving bashSet\n");

}


//Building function bashReturn from line: 169

public void bashReturn(Box node,Integer indent) {
    
  newLine(indent);  
  if ( equal(listLength(node), 1)) {    
    bashdisplays("return;");
  } else {    
    bashdisplays("return ");    
    bashExpression(cadr(node), indent, false);    
    bashdisplays(";");
  }
if (globalTrace)
   System.out. printf("Leaving bashReturn\n");

}


//Building function bashStatement from line: 180

public void bashStatement(Box node,Integer indent) {
    
  if ( equalBox(boxString("set"), first(node))) {    
    bashSet(node, indent);
  } else {    
    if ( equalBox(boxString("set-struct"), first(node))) {      
      bashSetStruct(node, indent);
    } else {      
      if ( equalBox(boxString("if"), first(node))) {        
        bashIf(node, indent);
      } else {        
        if ( equalBox(boxString("return"), first(node))) {          
          bashReturn(node, indent);
        } else {          
          newLine(indent);          
          bashExpression(node, indent, true);
        }
      }
    }
  }  
  bashdisplays(" \n");
if (globalTrace)
   System.out. printf("Leaving bashStatement\n");

}


//Building function bashBody from line: 198

public void bashBody(Box tree,Integer indent) {
  Box code = null;
  
  if ( isEmpty(tree)) {    
    return;
  } else {    
    code = tree;    
    if ( isNil(code)) {
    } else {      
      code = car(tree);      
      if ( not(releaseMode)) {        
        System.out.printf("\nif (( $globalTrace )) ; then\n    caller=\"from %s:%s\"\nfi", stringify(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), stringify(getTagFail(car(code), boxString("line"), boxString("Line missing"))));
      } else {
      }
    }    
    if ( not(releaseMode)) {
    } else {
    }    
    bashStatement(code, indent);    
    bashBody(cdr(tree), indent);
  }
if (globalTrace)
   System.out. printf("Leaving bashBody\n");

}


//Building function bashDeclarations from line: 221

public void bashDeclarations(Box decls,Integer indent) {
  Box decl = null;
  
  if ( isEmpty(decls)) {    
    return;
  } else {    
    decl = car(decls);    
    System.out.printf("local %s=\"", stringify(second(decl)));    
    bashExpression(third(decl), indent, false);    
    System.out.printf("\";\n");    
    bashDeclarations(cdr(decls), indent);
  }
if (globalTrace)
   System.out. printf("Leaving bashDeclarations\n");

}


//Building function bashFunction from line: 234

public void bashFunction(Box node) {
  Box name = null;
  
  name = second(node);  
  System.out.printf("\n\n#Building function %s from line:%s", stringify(name), stringify(getTag(name, boxString("line"))));  
  newLine(0);  
  if ( isNil(node)) {    
    return;
  } else {    
    newLine(0);    
    System.out.printf("%s(", stringify(second(node)));    
    System.out.printf(") {");    
    newLine(1);    
    bashFunctionArgs(third(node), 1, 1);    
    bashDeclarations(cdr(fourth(node)), 1);    
    if ( releaseMode) {      
      System.out.printf("");
    } else {      
      System.out.printf("\nif (( $globalTrace )) ; then\n    echo \"%s at %s:%s \" $caller\nfi", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));
    }    
    if ( releaseMode) {      
      System.out.printf("");
    } else {
    }    
    bashBody(cdr(fifth(node)), 1);    
    if ( releaseMode) {      
      System.out.printf("");
    } else {      
      System.out.printf("\nif (( $globalTrace ))\n    echo \"Leaving %s\\n\"\n", stringify(name));
    }    
    System.out.printf("\n}\n");
  }
if (globalTrace)
   System.out. printf("Leaving bashFunction\n");

}


//Building function bashForwardDeclaration from line: 267

public void bashForwardDeclaration(Box node) {
  
if (globalTrace)
   System.out. printf("Leaving bashForwardDeclaration\n");

}


//Building function bashForwardDeclarations from line: 270

public void bashForwardDeclarations(Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    bashForwardDeclaration(car(tree));    
    bashForwardDeclarations(cdr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving bashForwardDeclarations\n");

}


//Building function bashFunctions from line: 276

public void bashFunctions(Box tree) {
    
  if ( isEmpty(tree)) {    
    return;
  } else {    
    bashFunction(car(tree));    
    bashFunctions(cdr(tree));
  }
if (globalTrace)
   System.out. printf("Leaving bashFunctions\n");

}


//Building function bashIncludes from line: 282

public void bashIncludes(Box nodes) {
    
  System.out.printf("%s", "\n\n#define true 1\n#define false 0\n\n\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\nbool releaseMode = false;\n\n");  
  System.out.printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n");
if (globalTrace)
   System.out. printf("Leaving bashIncludes\n");

}


//Building function bashTypeDecl from line: 290

public void bashTypeDecl(Box l) {
  
if (globalTrace)
   System.out. printf("Leaving bashTypeDecl\n");

}


//Building function bashStructComponents from line: 294

public void bashStructComponents(Box node) {
    
  if ( isEmpty(node)) {    
    return;
  } else {    
    bashTypeDecl(car(node));    
    bashStructComponents(cdr(node));
  }
if (globalTrace)
   System.out. printf("Leaving bashStructComponents\n");

}


//Building function bashStruct from line: 300

public void bashStruct(Box node) {
    
  bashStructComponents(cdr(node));
if (globalTrace)
   System.out. printf("Leaving bashStruct\n");

}


//Building function bashTypeMap from line: 303

public Box bashTypeMap(Box aSym) {
  Box symMap = null;
  
  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), null));  
  if ( truthy(assoc(stringify(aSym), symMap))) {    
    return(cdr(assoc(stringify(aSym), symMap)));
  } else {    
    return(aSym);
  }
}


//Building function bashFuncMap from line: 313

public Box bashFuncMap(Box aSym) {
  Box symMap = null;
  
  if ( equalString("symbol", boxType(aSym))) {    
    symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), null)))))));    
    if ( truthy(assoc(stringify(aSym), symMap))) {      
      return(cdr(assoc(stringify(aSym), symMap)));
    } else {      
      return(aSym);
    }
  } else {    
    return(aSym);
  }
}


//Building function bashType from line: 344

public void bashType(Box node) {
  
if (globalTrace)
   System.out. printf("Leaving bashType\n");

}


//Building function bashTypes from line: 349

public void bashTypes(Box nodes) {
    
  if ( isEmpty(nodes)) {    
    return;
  } else {    
    bashType(car(nodes));    
    bashTypes(cdr(nodes));
  }
if (globalTrace)
   System.out. printf("Leaving bashTypes\n");

}


//Building function bashCompile from line: 359

public void bashCompile(String filename) {
  Box tree = null;
Box replace = null;
  
  System.err.printf("//Scanning file...%s\n", filename);  
  tree = loadQuon(filename);  
  System.err.printf("//Building sexpr\n");  
  System.err.printf("Loading shim bash\n");  
  tree = buildProg(cons(boxString("q/shims/bash.qon"), getIncludes(tree)), getTypes(tree), getFunctions(tree));  
  System.err.printf("Loading all includes\n");  
  tree = loadIncludes(tree);  
  System.err.printf("Applying macros\n");  
  tree = macrowalk(tree);  
  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), null));  
  tree = macrolist(tree, stringConcatenate("q", "log"), replace);  
  System.err.printf("//Printing program\n");  
  bashIncludes(cdr(first(tree)));  
  bashTypes(cdr(second(tree)));  
  bashdisplays("Box* globalStackTrace = NULL;\n");  
  bashdisplays("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");  
  bashForwardDeclarations(cdr(third(tree)));  
  bashdisplays("\n\n//End forward declarations\n\n");  
  bashFunctions(cdr(third(tree)));  
  bashdisplays("\n");  
  System.err.printf("//Done printing program\n");
if (globalTrace)
   System.out. printf("Leaving bashCompile\n");

}


//Building function start from line: 4

public Integer start() {
  boolean runTests = false;
Box cmdLine = null;
Box filename = null;
boolean runPerl = false;
boolean runJava = false;
boolean runAst = false;
boolean runNode = false;
boolean runNode2 = false;
boolean runLua = false;
boolean runIma = false;
boolean runAnsi2 = false;
boolean runAnsi3 = false;
boolean runBash = false;
boolean runTree = false;
  
  cmdLine = listReverse(argList(globalArgsCount, 0, globalArgs));  
  if ( greaterthan(listLength(cmdLine), 1)) {    
    filename = second(cmdLine);
  } else {    
    filename = boxString("compiler.qon");
  }  
  releaseMode = inList(boxString("--release"), cmdLine);  
  runTests = inList(boxString("--test"), cmdLine);  
  runJava = inList(boxString("--java"), cmdLine);  
  runPerl = inList(boxString("--perl"), cmdLine);  
  runAst = inList(boxString("--ast"), cmdLine);  
  runTree = inList(boxString("--tree"), cmdLine);  
  runNode = inList(boxString("--node"), cmdLine);  
  runNode2 = inList(boxString("--node2"), cmdLine);  
  runLua = inList(boxString("--lua"), cmdLine);  
  runIma = inList(boxString("--ima"), cmdLine);  
  runAnsi2 = inList(boxString("--ansi2"), cmdLine);  
  runAnsi3 = inList(boxString("--ansi3"), cmdLine);  
  runBash = inList(boxString("--bash"), cmdLine);  
  globalTrace = inList(boxString("--trace"), cmdLine);  
  globalStepTrace = inList(boxString("--steptrace"), cmdLine);  
  if ( inList(boxString("--help"), cmdLine)) {    
    System.out.printf("Usage: quon file [options]\n\nNote the options go after the file name\n");    
    System.out.printf("Options:\n");    
    System.out.printf("  --help      Display this help\n");    
    System.out.printf("  --release   Compile in release mode\n");    
    System.out.printf("  --test      Run the test suite\n");    
    System.out.printf("  --java      Compile to Java\n");    
    System.out.printf("  --perl      Compile to Perl\n");    
    System.out.printf("  --ast       Compile to the Abstract Syntax Tree\n");    
    System.out.printf("  --tree      Compile to an s-expression tree\n");    
    System.out.printf("  --node      Compile to Node.js\n");    
    System.out.printf("  --node2      Compile to Node.js, new outputter\n");    
    System.out.printf("  --lua       Compile to Lua\n");    
    System.out.printf("  --ima       Compile to Imaginary, the human-friendly language\n");    
    System.out.printf("  --ansi2     Compile to ANSI C, (quon version 2)\n");    
    System.out.printf("  --ansi3     Compile to ANSI C (quon version 3)\n");    
    System.out.printf("  --bash      Compile to Bash\n");    
    System.out.printf("  --trace     Trace execution\n");    
    System.out.printf("  --steptrace Step trace execution\n");    
    System.out.printf("  --help      Display this help\n");    
    exit(0);
  } else {
  }  
  if ( runTests) {    
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
    System.out.printf("\n\nAfter all that hard work, I need a beer...\n");    
    beers(9);
  } else {    
    if ( runTree) {      
      display(macrowalk(treeCompile(unBoxString(filename))));
    } else {      
      if ( runAst) {        
        astCompile(unBoxString(filename));
      } else {        
        if ( runNode) {          
          nodeCompile(unBoxString(filename));          
          System.out.printf("\n");
        } else {          
          if ( runNode2) {            
            node2Compile(unBoxString(filename));            
            System.out.printf("\n");
          } else {            
            if ( runPerl) {              
              perlCompile(unBoxString(filename));              
              System.out.printf("\n");
            } else {              
              if ( runJava) {                
                javaCompile(unBoxString(filename));                
                System.out.printf("\n");
              } else {                
                if ( runLua) {                  
                  luaCompile(unBoxString(filename));                  
                  System.out.printf("\n");
                } else {                  
                  if ( runIma) {                    
                    imaCompile(unBoxString(filename));                    
                    System.out.printf("\n");
                  } else {                    
                    if ( runAnsi2) {                      
                      ansi2Compile(unBoxString(filename));                      
                      System.out.printf("\n");
                    } else {                      
                      if ( runAnsi3) {                        
                        ansi3Compile(unBoxString(filename));                        
                        System.out.printf("\n");
                      } else {                        
                        if ( runBash) {                          
                          bashCompile(unBoxString(filename));                          
                          System.out.printf("\n");
                        } else {                          
                          ansi3Compile(unBoxString(filename));                          
                          System.out.printf("\n");
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
public static void main(String args[]) {
globalArgs = args;
globalArgsCount = args.length;MyProgram mp = new MyProgram(); mp.start();
}}

