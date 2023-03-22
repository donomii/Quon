use strict;
my $caller;
my $releaseMode;
use Carp;
use Carp::Always;
sub greaterthan { $_[0] > $_[1] };
sub qlog { warn @_ };
sub mult { $_[0] * $_[1] };
sub multf { $_[0] * $_[1] };
sub greaterthanf { $_[0] > $_[1] };
sub equalString { $_[0] eq $_[1] };
sub read_file { my $file = shift; $file || die "Empty file name!!!"; open my $fh, '<', $file or die; local $/ = undef; my $cont = <$fh>; close $fh; return $cont; }; 
sub write_file {my $file = shift; my $data = shift; $file || die "Empty file name!!!"; open my $fh, '>', $file or die; print $fh $data; close $fh; } 
sub stringConcatenate { $_[0] . $_[1]}
sub subtract { $_[0] - $_[1]}
sub subf { $_[0] - $_[1]}
sub andBool { $_[0] && $_[1]}
sub equal { $_[0] == $_[1]}
sub panic { carp @_; die "@_"}
sub intToString { return $_[0]}
sub character { return chr($_[0])}
sub getStringArray { my $index = shift; my $arr = shift; return $arr->[$index]}
use strict;
use Carp;
use Data::Dumper;
my $globalStackTrace = undef;
my $globalTrace = undef;
my $globalStepTrace = undef;
my $globalArgs = undef;
my $globalArgsCount = undef;
my $true = 1;

my $false = 0;
my $undef;

sub isNil {
    return !defined($_[0]);
}


#Forward declarations

sub add;
sub addf;
sub sub1;
sub add1;
sub clone;
sub tern;
sub ternString;
sub ternList;
sub newVoid;
sub stackDump;
sub nop;
sub equalBox;
sub openBrace;
sub closeBrace;
sub boxType;
sub makeBox;
sub makePair;
sub boxString;
sub boxSymbol;
sub boxBool;
sub boxInt;
sub assertType;
sub unBoxString;
sub unBoxSymbol;
sub unBoxBool;
sub unBoxInt;
sub stringify_rec;
sub stringify;
sub hasTag;
sub getTag;
sub getTagFail;
sub assocExists;
sub assocFail;
sub assocPanic;
sub setTag;
sub locPanic;
sub truthy;
sub isNotFalse;
sub toStr;
sub listLast;
sub newLine;
sub printIndent;
sub stringIndent;
sub argList;
sub tron;
sub troff;
sub stron;
sub stroff;
sub filterVoid;
sub filterTokens;
sub finish_token;
sub readString;
sub readComment;
sub isWhiteSpace;
sub isLineBreak;
sub incForNewLine;
sub annotateReadPosition;
sub scan;
sub isOpenBrace;
sub isCloseBrace;
sub skipList;
sub makeNode;
sub addToNode;
sub makeStatementNode;
sub astExpression;
sub astSubExpression;
sub astIf;
sub astSetStruct;
sub astSet;
sub astGetStruct;
sub astReturnVoid;
sub astStatement;
sub astBody;
sub astFunction;
sub astFunctionList;
sub astFunctions;
sub loadLib;
sub astInclude;
sub astIncludeList;
sub astIncludes;
sub astStruct;
sub astType;
sub astTypeList;
sub astTypes;
sub declarationsof;
sub codeof;
sub functionNameof;
sub nodeof;
sub lineof;
sub subnameof;
sub nameof;
sub childrenof;
sub isNode;
sub isLeaf;
sub noStackTrace;
sub treeCompile;
sub astBuild;
sub astCompile;
sub mergeIncludes;
sub merge_recur;
sub mergeInclude;
sub macrowalk;
sub macrosingle;
sub macrolist;
sub car;
sub cdr;
sub cons;
sub caar;
sub cadr;
sub caddr;
sub cadddr;
sub caddddr;
sub cddr;
sub first;
sub second;
sub third;
sub fourth;
sub fifth;
sub isList;
sub emptyList;
sub isEmpty;
sub listLength;
sub alistCons;
sub assoc;
sub chooseBox;
sub mlistLiteral;
sub doMultiList;
sub isInt;
sub id;
sub chooseBoxInterp;
sub doInterpolatedList;
sub doStringList;
sub doSymbolList;
sub doBoxList;
sub concatLists;
sub alistKeys;
sub display;
sub displayList;
sub StringListJoinRec;
sub StringListJoin;
sub ListToBoxString;
sub ListToString;
sub listReverse;
sub inList;
sub equalList;
sub reverseRec;
sub reverseList;
sub flatten;
sub readSexpr;
sub sexprTree;
sub loadQuon;
sub getIncludes;
sub getTypes;
sub getFunctions;
sub loadIncludes;
sub buildProg;
sub numbers;
sub lexType;
sub perlLeaf;
sub perlStructGetterExpression;
sub perlExpression;
sub perlRecurList;
sub perlSubExpression;
sub perlIf;
sub perlSetStruct;
sub perlGetStruct;
sub perlSet;
sub assertNode;
sub perlStatement;
sub perlBody;
sub perlDeclarations;
sub perlFunction;
sub perlForwardDeclaration;
sub perlForwardDeclarations;
sub perlFunctions;
sub dollar;
sub atSym;
sub perlIncludes;
sub perlTypeDecl;
sub perlStructComponents;
sub perlStruct;
sub perlTypeMap;
sub perlConstMap;
sub perlFuncMap;
sub perlType;
sub perlTypes;
sub perlFunctionArgs;
sub perlCompile;
sub ansiFunctionArgs;
sub ansiLeaf;
sub ansiStructGetterExpression;
sub ansiExpression;
sub ansiRecurList;
sub ansiSubExpression;
sub ansiIf;
sub ansiSetStruct;
sub ansiGetStruct;
sub ansiSet;
sub ansiStatement;
sub ansiBody;
sub ansiDeclarations;
sub ansiFunction;
sub ansiForwardDeclaration;
sub ansiForwardDeclarations;
sub ansiFunctions;
sub ansiIncludes;
sub ansiTypeDecl;
sub ansiStructComponents;
sub ansiStruct;
sub ansiTypeMap;
sub ansiFuncMap;
sub ansiType;
sub ansiTypes;
sub ansiCompile;
sub ansi2displays;
sub ansi2FunctionArgs;
sub ansi2Expression;
sub ansi2RecurList;
sub ansi2If;
sub ansi2SetStruct;
sub ansi2GetStruct;
sub ansi2Set;
sub ansi2Return;
sub ansi2Statement;
sub ansi2Body;
sub ansi2Declarations;
sub ansi2Function;
sub ansi2ForwardDeclaration;
sub ansi2ForwardDeclarations;
sub ansi2Functions;
sub ansi2Includes;
sub ansi2TypeDecl;
sub ansi2StructComponents;
sub ansi2Struct;
sub ansi2TypeMap;
sub ansi2FuncMap;
sub ansi2Type;
sub ansi2Types;
sub ansi2Compile;
sub ansi3displays;
sub ansi3FunctionArgs;
sub ansi3Expression;
sub ansi3RecurList;
sub ansi3If;
sub ansi3SetStruct;
sub ansi3GetStruct;
sub ansi3Set;
sub ansi3Return;
sub ansi3Statement;
sub ansi3Body;
sub ansi3Declarations;
sub ansi3Function;
sub ansi3ForwardDeclaration;
sub ansi3ForwardDeclarations;
sub ansi3Functions;
sub ansi3Includes;
sub ansi3TypeDecl;
sub ansi3StructComponents;
sub ansi3Struct;
sub ansi3TypeMap;
sub ansi3FuncMap;
sub ansi3Type;
sub ansi3Types;
sub ansi3Compile;
sub test0;
sub test1;
sub test2_do;
sub test2;
sub test3_do;
sub test3;
sub test4_do;
sub returnThis;
sub test4;
sub test5;
sub test6;
sub test7_do;
sub test7;
sub beer;
sub plural;
sub beers;
sub test8;
sub test9;
sub test10;
sub test12;
sub test13;
sub test15;
sub test16;
sub test17;
sub test18;
sub test19;
sub concatenateLists;
sub test20;
sub test21;
sub test22;
sub test23;
sub test24;
sub test25;
sub nodeFunctionArgs;
sub nodeLeaf;
sub nodeStructGetterExpression;
sub nodeExpression;
sub nodeRecurList;
sub nodeSubExpression;
sub nodeIf;
sub nodeGetStruct;
sub nodeSet;
sub nodeSetStruct;
sub nodeStatement;
sub nodeBody;
sub nodeDeclarations;
sub nodeFunction;
sub nodeForwardDeclaration;
sub nodeForwardDeclarations;
sub nodeFunctions;
sub nodeIncludes;
sub nodeTypeDecl;
sub nodeStructComponents;
sub nodeStruct;
sub nodeTypeMap;
sub nodeFuncMap;
sub nodeType;
sub nodeTypes;
sub nodeCompile;
sub node2Compile;
sub node2Includes;
sub node2Functions;
sub node2Function;
sub node2FunctionArgs;
sub node2Declarations;
sub javaFunctionArgs;
sub javaLeaf;
sub javaStructGetterExpression;
sub javaExpression;
sub javaRecurList;
sub javaSubExpression;
sub javaIf;
sub javaSetStruct;
sub javaGetStruct;
sub javaSet;
sub javaStatement;
sub javaBody;
sub javaDeclarations;
sub javaFunction;
sub javaFunctions;
sub javaIncludes;
sub javaTypeDecl;
sub javaStructComponents;
sub javaStruct;
sub javaTypeMap;
sub javaTypesNoDeclare;
sub javaFuncMap;
sub javaType;
sub javaTypes;
sub javaCompile;
sub luaFunctionArgs;
sub luaFunction;
sub luaDeclarations;
sub luaExpressionStart;
sub luaExpression;
sub luaStatement;
sub luaBody;
sub luaFunctions;
sub luaProgram;
sub luaIncludes;
sub luaCompile;
sub not;
sub andBool;
sub nand;
sub xor;
sub imaFunctionArgs;
sub imaFunction;
sub imaDeclarations;
sub imaExpressionStart;
sub imaExpression;
sub imaStatement;
sub imaBody;
sub imaFunctions;
sub imaTypeDecl;
sub imaStructComponents;
sub imaStruct;
sub imaTypeMap;
sub imaType;
sub imaTypes;
sub imaProgram;
sub imaIncludes;
sub imaCompile;
sub bashdisplays;
sub bashFunctionArgs;
sub bashExpression;
sub bashVarOrLit;
sub bashRecurList;
sub bashIf;
sub bashSetStruct;
sub bashGetStruct;
sub bashSet;
sub bashReturn;
sub bashStatement;
sub bashBody;
sub bashDeclarations;
sub bashFunction;
sub bashForwardDeclaration;
sub bashForwardDeclarations;
sub bashFunctions;
sub bashIncludes;
sub bashTypeDecl;
sub bashStructComponents;
sub bashStruct;
sub bashTypeMap;
sub bashFuncMap;
sub bashType;
sub bashTypes;
sub bashCompile;
sub start;

#End forward declarations



#Building function add from line: 19

sub add {
  my $a = shift;
my $b = shift;

  
if ($globalTrace) { printf("add at q/base.qon:19\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: add

  if ($globalTrace) {printf("Leaving \n")}

  return(subtract($a, subtract(0, $b)));

}


#Building function addf from line: 20

sub addf {
  my $a = shift;
my $b = shift;

  
if ($globalTrace) { printf("addf at q/base.qon:20\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: addf

  if ($globalTrace) {printf("Leaving \n")}

  return(subf($a, subf(0, $b)));

}


#Building function sub1 from line: 21

sub sub1 {
  my $a = shift;

  
if ($globalTrace) { printf("sub1 at q/base.qon:21\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: sub1

  if ($globalTrace) {printf("Leaving \n")}

  return(subtract($a, 1));

}


#Building function add1 from line: 22

sub add1 {
  my $a = shift;

  
if ($globalTrace) { printf("add1 at q/base.qon:22\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: add1

  if ($globalTrace) {printf("Leaving \n")}

  return(add($a, 1));

}


#Building function clone from line: 24

sub clone {
  my $b = shift;

  my $newb = undef;

if ($globalTrace) { printf("clone at q/base.qon:24\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $newb = makeBox();
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $newb->{typ} = $b->{typ};
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $newb->{tag} = $b->{tag};
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $newb->{lis} = $b->{lis};
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $newb->{str} = $b->{str};
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $newb->{i} = $b->{i};
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $newb->{lengt} = $b->{lengt};
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: clone

  if ($globalTrace) {printf("Leaving \n")}

  return($newb);

}


#Building function tern from line: 37

sub tern {
  my $cond = shift;
my $tr = shift;
my $fal = shift;

  
if ($globalTrace) { printf("tern at q/base.qon:37\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( $cond) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: tern

    if ($globalTrace) {printf("Leaving \n")}

    return($tr);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: tern

    if ($globalTrace) {printf("Leaving \n")}

    return($fal);

  };

}


#Building function ternString from line: 41

sub ternString {
  my $cond = shift;
my $tr = shift;
my $fal = shift;

  
if ($globalTrace) { printf("ternString at q/base.qon:41\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( $cond) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ternString

    if ($globalTrace) {printf("Leaving \n")}

    return($tr);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ternString

    if ($globalTrace) {printf("Leaving \n")}

    return($fal);

  };

}


#Building function ternList from line: 45

sub ternList {
  my $cond = shift;
my $tr = shift;
my $fal = shift;

  
if ($globalTrace) { printf("ternList at q/base.qon:45\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( $cond) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ternList

    if ($globalTrace) {printf("Leaving \n")}

    return($tr);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ternList

    if ($globalTrace) {printf("Leaving \n")}

    return($fal);

  };

}


#Building function newVoid from line: 50

sub newVoid {
  
  my $newb = undef;

if ($globalTrace) { printf("newVoid at q/base.qon:50\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $newb = makeBox();
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $newb->{voi} = $true;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $newb->{typ} = "void";
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: newVoid

  if ($globalTrace) {printf("Leaving \n")}

  return($newb);

}


#Building function stackDump from line: 59

sub stackDump {
  
  
if ($globalTrace) { printf("stackDump at q/base.qon:59\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("")
  ;

}


#Building function nop from line: 64

sub nop {
  
  
if ($globalTrace) { printf("nop at q/base.qon:64\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("")
  ;

}


#Building function equalBox from line: 67

sub equalBox {
  my $a = shift;
my $b = shift;

  
if ($globalTrace) { printf("equalBox at q/base.qon:67\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isList($b)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    return($false);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalString("string", boxType($a))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      return(equalString(unBoxString($a), stringify($b)));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString("bool", boxType($a))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        return(andBool(unBoxBool($a), unBoxBool($b)));

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalString("symbol", boxType($a))) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalString("symbol", boxType($b))) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            return(equalString(unBoxSymbol($a), unBoxSymbol($b)));

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            return($false);

          };

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalString("int", boxType($a))) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            return(equal(unBoxInt($a), unBoxInt($b)));

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            return($false);

          };

        };

      };

    };

  };

}


#Building function openBrace from line: 88

sub openBrace {
  
  
if ($globalTrace) { printf("openBrace at q/base.qon:88\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: openBrace

  if ($globalTrace) {printf("Leaving \n")}

  return("(");

}


#Building function closeBrace from line: 89

sub closeBrace {
  
  
if ($globalTrace) { printf("closeBrace at q/base.qon:89\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: closeBrace

  if ($globalTrace) {printf("Leaving \n")}

  return(")");

}


#Building function boxType from line: 94

sub boxType {
  my $b = shift;

  
if ($globalTrace) { printf("boxType at q/base.qon:94\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  return($b->{typ});

}


#Building function makeBox from line: 98

sub makeBox {
  
  my $b = undef;

if ($globalTrace) { printf("makeBox at q/base.qon:98\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $b = {};
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($b)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    panic("failed to create box!")
    ;

  } else {
  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $b->{tag} = $undef;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $b->{car} = $undef;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $b->{cdr} = $undef;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $b->{lis} = $undef;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $b->{typ} = "None - error!";
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: makeBox

  if ($globalTrace) {printf("Leaving \n")}

  return($b);

}


#Building function makePair from line: 112

sub makePair {
  
  
if ($globalTrace) { printf("makePair at q/base.qon:112\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: makePair

  if ($globalTrace) {printf("Leaving \n")}

  return(makeBox());

}


#Building function boxString from line: 117

sub boxString {
  my $s = shift;

  my $b = undef;

if ($globalTrace) { printf("boxString at q/base.qon:117\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $b = makeBox();
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $b->{str} = $s;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $b->{lengt} = length($s);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $b->{typ} = "string";
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  return($b);

}


#Building function boxSymbol from line: 127

sub boxSymbol {
  my $s = shift;

  my $b = undef;

if ($globalTrace) { printf("boxSymbol at q/base.qon:127\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $b = boxString($s);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $b->{typ} = "symbol";
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  return($b);

}


#Building function boxBool from line: 136

sub boxBool {
  my $boo = shift;

  my $b = undef;

if ($globalTrace) { printf("boxBool at q/base.qon:136\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $b = makeBox();
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $b->{boo} = $boo;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $b->{typ} = "bool";
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: boxBool

  if ($globalTrace) {printf("Leaving \n")}

  return($b);

}


#Building function boxInt from line: 145

sub boxInt {
  my $val = shift;

  my $b = undef;

if ($globalTrace) { printf("boxInt at q/base.qon:145\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $b = makeBox();
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $b->{i} = $val;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $b->{typ} = "int";
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  return($b);

}


#Building function assertType from line: 154

sub assertType {
  my $atype = shift;
my $abox = shift;
my $line = shift;
my $file = shift;

  
if ($globalTrace) { printf("assertType at q/base.qon:154\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($abox)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalString($atype, "nil")) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

      
      return;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

      
      return;

    };

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalString($atype, boxType($abox))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

      
      return;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("Assertion failure at line %d, in file %s: provided value is not a '%s'!  It was actually '%s'. Contents:", $line, $file, $atype, boxType($abox))
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      display($abox)
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      display(cons(boxString("\nToken may have been read from "), cons(boxString(stringify(getTagFail($abox, boxString("filename"), boxString("source file not found")))), cons(boxString(":"), cons(boxString(stringify(getTagFail($abox, boxString("line"), boxString("source line not found")))), $undef)))))
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      panic("Invalid type!")
      ;

    };

  };

}


#Building function unBoxString from line: 167

sub unBoxString {
  my $b = shift;

  
if ($globalTrace) { printf("unBoxString at q/base.qon:167\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  assertType("string", $b, 168, "q/base.qon")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  return($b->{str});

}


#Building function unBoxSymbol from line: 170

sub unBoxSymbol {
  my $b = shift;

  
if ($globalTrace) { printf("unBoxSymbol at q/base.qon:170\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  return($b->{str});

}


#Building function unBoxBool from line: 171

sub unBoxBool {
  my $b = shift;

  
if ($globalTrace) { printf("unBoxBool at q/base.qon:171\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  return($b->{boo});

}


#Building function unBoxInt from line: 172

sub unBoxInt {
  my $b = shift;

  
if ($globalTrace) { printf("unBoxInt at q/base.qon:172\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  return($b->{i});

}


#Building function stringify_rec from line: 174

sub stringify_rec {
  my $b = shift;

  
if ($globalTrace) { printf("stringify_rec at q/base.qon:174\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($b)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: stringify_rec

    if ($globalTrace) {printf("Leaving \n")}

    return("");

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: stringify_rec

    if ($globalTrace) {printf("Leaving \n")}

    return(stringConcatenate(stringify(car($b)), stringConcatenate(" ", stringify_rec(cdr($b)))));

  };

}


#Building function stringify from line: 183

sub stringify {
  my $b = shift;

  
if ($globalTrace) { printf("stringify at q/base.qon:183\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($b)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    return("()");

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalString("string", boxType($b))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      return(unBoxString($b));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString("bool", boxType($b))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( unBoxBool($b)) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          return("true");

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          return("false");

        };

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalString("int", boxType($b))) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          return(intToString(unBoxInt($b)));

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalString("symbol", boxType($b))) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            return(unBoxSymbol($b));

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            if ( equalString("list", boxType($b))) {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

              return(stringConcatenate("(", stringConcatenate(stringify(car($b)), stringConcatenate(" ", stringConcatenate(stringify_rec(cdr($b)), ")")))));

            } else {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

              return(stringConcatenate("Unsupported type: ", boxType($b)));

            };

          };

        };

      };

    };

  };

}


#Building function hasTag from line: 218

sub hasTag {
  my $aBox = shift;
my $key = shift;

  
if ($globalTrace) { printf("hasTag at q/base.qon:218\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($aBox)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: hasTag

    if ($globalTrace) {printf("Leaving \n")}

    return($false);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: hasTag

    if ($globalTrace) {printf("Leaving \n")}

    return(isNotFalse(assoc(stringify($key), $aBox->{tag})));

  };

}


#Building function getTag from line: 225

sub getTag {
  my $aBox = shift;
my $key = shift;

  
if ($globalTrace) { printf("getTag at q/base.qon:225\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( $false) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("Getting %s from: ", stringify($key))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    display(alistKeys($aBox->{tag}))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: getTag

  if ($globalTrace) {printf("Leaving \n")}

  return(cdr(assoc(stringify($key), $aBox->{tag})));

}


#Building function getTagFail from line: 237

sub getTagFail {
  my $aBox = shift;
my $key = shift;
my $onFail = shift;

  
if ($globalTrace) { printf("getTagFail at q/base.qon:237\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( hasTag($aBox, $key)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: getTagFail

    if ($globalTrace) {printf("Leaving \n")}

    return(getTag($aBox, $key));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: getTagFail

    if ($globalTrace) {printf("Leaving \n")}

    return($onFail);

  };

}


#Building function assocExists from line: 247

sub assocExists {
  my $key = shift;
my $aBox = shift;

  
if ($globalTrace) { printf("assocExists at q/base.qon:247\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($aBox)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: assocExists

    if ($globalTrace) {printf("Leaving \n")}

    return($false);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: assocExists

    if ($globalTrace) {printf("Leaving \n")}

    return(isNotFalse(assoc($key, $aBox)));

  };

}


#Building function assocFail from line: 255

sub assocFail {
  my $key = shift;
my $aBox = shift;
my $onFail = shift;

  
if ($globalTrace) { printf("assocFail at q/base.qon:255\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( assocExists($key, $aBox)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: assocFail

    if ($globalTrace) {printf("Leaving \n")}

    return(assoc($key, $aBox));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: assocFail

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(boxString($key), $onFail));

  };

}


#Building function assocPanic from line: 262

sub assocPanic {
  my $key = shift;
my $aBox = shift;
my $onFail = shift;

  
if ($globalTrace) { printf("assocPanic at q/base.qon:262\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( assocExists($key, $aBox)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: assocPanic

    if ($globalTrace) {printf("Leaving \n")}

    return(assoc($key, $aBox));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    panic($onFail)
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  panic("Inconceivable")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: assocPanic

  if ($globalTrace) {printf("Leaving \n")}

  return($undef);

}


#Building function setTag from line: 273

sub setTag {
  my $key = shift;
my $val = shift;
my $aStruct = shift;

  
if ($globalTrace) { printf("setTag at q/base.qon:273\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $aStruct->{tag} = alistCons($key, $val, $aStruct->{tag});
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: setTag

  if ($globalTrace) {printf("Leaving \n")}

  return($aStruct);

}


#Building function locPanic from line: 279

sub locPanic {
  my $file = shift;
my $line = shift;
my $message = shift;

  
if ($globalTrace) { printf("locPanic at q/base.qon:279\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s %s:%s\n", $file, $line, $message)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  panic($message)
  ;

}


#Building function truthy from line: 285

sub truthy {
  my $aVal = shift;

  
if ($globalTrace) { printf("truthy at q/base.qon:285\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: truthy

  if ($globalTrace) {printf("Leaving \n")}

  return(isNotFalse($aVal));

}


#Building function isNotFalse from line: 290

sub isNotFalse {
  my $aVal = shift;

  
if ($globalTrace) { printf("isNotFalse at q/base.qon:290\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString(boxType($aVal), "bool")) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( unBoxBool($aVal)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isNotFalse

      if ($globalTrace) {printf("Leaving \n")}

      return($true);

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isNotFalse

      if ($globalTrace) {printf("Leaving \n")}

      return($false);

    };

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isNotFalse

    if ($globalTrace) {printf("Leaving \n")}

    return($true);

  };

}


#Building function toStr from line: 297

sub toStr {
  my $thing = shift;

  
if ($globalTrace) { printf("toStr at q/base.qon:297\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: toStr

  if ($globalTrace) {printf("Leaving \n")}

  return(boxString(stringify($thing)));

}


#Building function listLast from line: 301

sub listLast {
  my $alist = shift;

  
if ($globalTrace) { printf("listLast at q/base.qon:301\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty(cdr($alist))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: listLast

    if ($globalTrace) {printf("Leaving \n")}

    return(car($alist));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: listLast

    if ($globalTrace) {printf("Leaving \n")}

    return(listLast(cdr($alist)));

  };

}


#Building function newLine from line: 308

sub newLine {
  my $indent = shift;

  
if ($globalTrace) { printf("newLine at q/base.qon:308\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printIndent($indent)
  ;

}


#Building function printIndent from line: 312

sub printIndent {
  my $ii = shift;

  
if ($globalTrace) { printf("printIndent at q/base.qon:312\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan($ii, 0)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("  ")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent(sub1($ii))
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  };

}


#Building function stringIndent from line: 319

sub stringIndent {
  my $ii = shift;

  
if ($globalTrace) { printf("stringIndent at q/base.qon:319\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan($ii, 0)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: stringIndent

    if ($globalTrace) {printf("Leaving \n")}

    return(stringConcatenate("  ", stringIndent(sub1($ii))));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: stringIndent

    if ($globalTrace) {printf("Leaving \n")}

    return("");

  };

}


#Building function argList from line: 327

sub argList {
  my $count = shift;
my $pos = shift;
my $args = shift;

  
if ($globalTrace) { printf("argList at q/base.qon:327\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan($count, $pos)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: argList

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(boxString(getStringArray($pos, $args)), argList($count, add1($pos), $args)));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: argList

    if ($globalTrace) {printf("Leaving \n")}

    return($undef);

  };

}


#Building function tron from line: 337

sub tron {
  
  
if ($globalTrace) { printf("tron at q/base.qon:337\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $globalTrace = $true;

}


#Building function troff from line: 338

sub troff {
  
  
if ($globalTrace) { printf("troff at q/base.qon:338\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $globalTrace = $false;

}


#Building function stron from line: 339

sub stron {
  
  
if ($globalTrace) { printf("stron at q/base.qon:339\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $globalStepTrace = $true;

}


#Building function stroff from line: 340

sub stroff {
  
  
if ($globalTrace) { printf("stroff at q/base.qon:340\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $globalStepTrace = $false;

}


#Building function filterVoid from line: 8

sub filterVoid {
  my $l = shift;

  my $token = undef;

if ($globalTrace) { printf("filterVoid at q/compiler.qon:8\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: filterVoid

    if ($globalTrace) {printf("Leaving \n")}

    return(emptyList());

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $token = car($l);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalString("void", $token->{typ})) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: filterVoid

      if ($globalTrace) {printf("Leaving \n")}

      return(filterVoid(cdr($l)));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: filterVoid

      if ($globalTrace) {printf("Leaving \n")}

      return(cons($token, filterVoid(cdr($l))));

    };

  };

}


#Building function filterTokens from line: 20

sub filterTokens {
  my $l = shift;

  my $token = undef;

if ($globalTrace) { printf("filterTokens at q/compiler.qon:20\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: filterTokens

    if ($globalTrace) {printf("Leaving \n")}

    return(emptyList());

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $token = car($l);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalString(boxType($token), "symbol")) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString("__LINE__", stringify($token))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: filterTokens

        if ($globalTrace) {printf("Leaving \n")}

        return(cons(getTagFail($token, boxString("line"), boxInt(-1)), filterTokens(cdr($l))));

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalString("__COLUMN__", stringify($token))) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: filterTokens

          if ($globalTrace) {printf("Leaving \n")}

          return(cons(getTagFail($token, boxString("column"), boxInt(-1)), filterTokens(cdr($l))));

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalString("__FILE__", stringify($token))) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: filterTokens

            if ($globalTrace) {printf("Leaving \n")}

            return(cons(getTagFail($token, boxString("filename"), boxString("Unknown file")), filterTokens(cdr($l))));

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: filterTokens

            if ($globalTrace) {printf("Leaving \n")}

            return(cons($token, filterTokens(cdr($l))));

          };

        };

      };

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: filterTokens

      if ($globalTrace) {printf("Leaving \n")}

      return(cons($token, filterTokens(cdr($l))));

    };

  };

}


#Building function finish_token from line: 54

sub finish_token {
  my $prog = shift;
my $start = shift;
my $len = shift;
my $line = shift;
my $column = shift;
my $filename = shift;

  my $token = undef;

if ($globalTrace) { printf("finish_token at q/compiler.qon:54\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan($len, 0)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $token = boxSymbol(substr($prog, $start, $len));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $token->{tag} = alistCons(boxString("filename"), boxString($filename), alistCons(boxString("column"), boxInt($column), alistCons(boxString("line"), boxInt($line), alistCons(boxString("totalCharPos"), boxInt($start), $undef))));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: finish_token

    if ($globalTrace) {printf("Leaving \n")}

    return($token);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: finish_token

    if ($globalTrace) {printf("Leaving \n")}

    return(newVoid());

  };

}


#Building function readString from line: 69

sub readString {
  my $prog = shift;
my $start = shift;
my $len = shift;

  my $token = "";

if ($globalTrace) { printf("readString at q/compiler.qon:69\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $token = substr($prog, sub1(add($start, $len)), 1);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("\"", $token)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: readString

    if ($globalTrace) {printf("Leaving \n")}

    return(substr($prog, $start, sub1($len)));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalString("\\", $token)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: readString

      if ($globalTrace) {printf("Leaving \n")}

      return(readString($prog, $start, add(2, $len)));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: readString

      if ($globalTrace) {printf("Leaving \n")}

      return(readString($prog, $start, add1($len)));

    };

  };

}


#Building function readComment from line: 80

sub readComment {
  my $prog = shift;
my $start = shift;
my $len = shift;

  my $token = "";

if ($globalTrace) { printf("readComment at q/compiler.qon:80\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan(add($start, $len), length($prog))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: readComment

    if ($globalTrace) {printf("Leaving \n")}

    return("");

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $token = substr($prog, sub1(add($start, $len)), 1);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isLineBreak($token)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: readComment

      if ($globalTrace) {printf("Leaving \n")}

      return(substr($prog, $start, sub1($len)));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: readComment

      if ($globalTrace) {printf("Leaving \n")}

      return(readComment($prog, $start, add1($len)));

    };

  };

}


#Building function isWhiteSpace from line: 91

sub isWhiteSpace {
  my $s = shift;

  
if ($globalTrace) { printf("isWhiteSpace at q/compiler.qon:91\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString(" ", $s)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isWhiteSpace

    if ($globalTrace) {printf("Leaving \n")}

    return($true);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalString("\t", $s)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isWhiteSpace

      if ($globalTrace) {printf("Leaving \n")}

      return($true);

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString("\n", $s)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isWhiteSpace

        if ($globalTrace) {printf("Leaving \n")}

        return($true);

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalString("\r", $s)) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isWhiteSpace

          if ($globalTrace) {printf("Leaving \n")}

          return($true);

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isWhiteSpace

          if ($globalTrace) {printf("Leaving \n")}

          return($false);

        };

      };

    };

  };

}


#Building function isLineBreak from line: 108

sub isLineBreak {
  my $s = shift;

  
if ($globalTrace) { printf("isLineBreak at q/compiler.qon:108\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("\n", $s)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isLineBreak

    if ($globalTrace) {printf("Leaving \n")}

    return($true);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalString("\r", $s)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isLineBreak

      if ($globalTrace) {printf("Leaving \n")}

      return($true);

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isLineBreak

      if ($globalTrace) {printf("Leaving \n")}

      return($false);

    };

  };

}


#Building function incForNewLine from line: 115

sub incForNewLine {
  my $token = shift;
my $val = shift;

  
if ($globalTrace) { printf("incForNewLine at q/compiler.qon:115\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("\n", stringify($token))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: incForNewLine

    if ($globalTrace) {printf("Leaving \n")}

    return(add1($val));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: incForNewLine

    if ($globalTrace) {printf("Leaving \n")}

    return($val);

  };

}


#Building function annotateReadPosition from line: 123

sub annotateReadPosition {
  my $filename = shift;
my $linecount = shift;
my $column = shift;
my $start = shift;
my $newBox = shift;

  
if ($globalTrace) { printf("annotateReadPosition at q/compiler.qon:123\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: annotateReadPosition

  if ($globalTrace) {printf("Leaving \n")}

  return(setTag(boxString("filename"), boxString($filename), setTag(boxString("column"), boxInt($column), setTag(boxString("line"), boxInt($linecount), setTag(boxString("totalCharPos"), boxInt($start), $newBox)))));

}


#Building function scan from line: 135

sub scan {
  my $prog = shift;
my $start = shift;
my $len = shift;
my $linecount = shift;
my $column = shift;
my $filename = shift;

  my $token = undef;
my $newString = "";
my $newBox = undef;

if ($globalTrace) { printf("scan at q/compiler.qon:135\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan(length($prog), subtract($start, subtract(0, $len)))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $token = boxSymbol(substr($prog, sub1(add($start, $len)), 1));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $token->{tag} = alistCons(boxString("totalCharPos"), boxInt($start), $undef);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isOpenBrace($token)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: scan

      if ($globalTrace) {printf("Leaving \n")}

      return(cons(finish_token($prog, $start, sub1($len), $linecount, $column, $filename), cons(boxSymbol(openBrace()), scan($prog, add1($start), 1, $linecount, add1($column), $filename))));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( isCloseBrace($token)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: scan

        if ($globalTrace) {printf("Leaving \n")}

        return(cons(finish_token($prog, $start, sub1($len), $linecount, $column, $filename), cons(annotateReadPosition($filename, $linecount, $column, $start, boxSymbol(closeBrace())), scan($prog, add($start, $len), 1, $linecount, add1($column), $filename))));

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( isWhiteSpace(stringify($token))) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: scan

          if ($globalTrace) {printf("Leaving \n")}

          return(cons(finish_token($prog, $start, sub1($len), $linecount, $column, $filename), scan($prog, add($start, $len), 1, incForNewLine($token, $linecount), 0, $filename)));

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalBox(boxSymbol(";"), $token)) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: scan

            if ($globalTrace) {printf("Leaving \n")}

            return(scan($prog, add($start, add1(add1(length(readComment($prog, add1($start), $len))))), 1, add1($linecount), 0, $filename));

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            if ( equalBox(boxSymbol("\""), $token)) {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

              $newString = readString($prog, add1($start), $len);
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

              $newBox = annotateReadPosition($filename, $linecount, $column, $start, boxString($newString));
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: scan

              if ($globalTrace) {printf("Leaving \n")}

              return(cons($newBox, scan($prog, add($start, add1(add1(length($newString)))), 1, $linecount, add1($column), $filename)));

            } else {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: scan

              if ($globalTrace) {printf("Leaving \n")}

              return(scan($prog, $start, subtract($len, -1), $linecount, add1($column), $filename));

            };

          };

        };

      };

    };

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: scan

    if ($globalTrace) {printf("Leaving \n")}

    return(emptyList());

  };

}


#Building function isOpenBrace from line: 175

sub isOpenBrace {
  my $b = shift;

  
if ($globalTrace) { printf("isOpenBrace at q/compiler.qon:175\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(boxSymbol(openBrace()), $b)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isOpenBrace

    if ($globalTrace) {printf("Leaving \n")}

    return($true);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalBox(boxSymbol("["), $b)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isOpenBrace

      if ($globalTrace) {printf("Leaving \n")}

      return($true);

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isOpenBrace

      if ($globalTrace) {printf("Leaving \n")}

      return($false);

    };

  };

}


#Building function isCloseBrace from line: 184

sub isCloseBrace {
  my $b = shift;

  
if ($globalTrace) { printf("isCloseBrace at q/compiler.qon:184\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(boxSymbol(closeBrace()), $b)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isCloseBrace

    if ($globalTrace) {printf("Leaving \n")}

    return($true);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalBox(boxSymbol("]"), $b)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isCloseBrace

      if ($globalTrace) {printf("Leaving \n")}

      return($true);

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isCloseBrace

      if ($globalTrace) {printf("Leaving \n")}

      return($false);

    };

  };

}


#Building function skipList from line: 197

sub skipList {
  my $l = shift;

  my $b = undef;

if ($globalTrace) { printf("skipList at q/compiler.qon:197\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: skipList

    if ($globalTrace) {printf("Leaving \n")}

    return(emptyList());

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $b = car($l);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isOpenBrace($b)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: skipList

      if ($globalTrace) {printf("Leaving \n")}

      return(skipList(skipList(cdr($l))));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( isCloseBrace($b)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: skipList

        if ($globalTrace) {printf("Leaving \n")}

        return(cdr($l));

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: skipList

        if ($globalTrace) {printf("Leaving \n")}

        return(skipList(cdr($l)));

      };

    };

  };

}


#Building function makeNode from line: 219

sub makeNode {
  my $name = shift;
my $subname = shift;
my $code = shift;
my $children = shift;

  
if ($globalTrace) { printf("makeNode at q/compiler.qon:219\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: makeNode

  if ($globalTrace) {printf("Leaving \n")}

  return(cons(boxSymbol("node"), alistCons(boxSymbol("line"), getTagFail($code, boxString("line"), boxInt(-1)), cons(cons(boxSymbol("name"), boxString($name)), cons(cons(boxSymbol("subname"), boxString($subname)), cons(cons(boxSymbol("code"), $code), alistCons(boxSymbol("children"), $children, emptyList())))))));

}


#Building function addToNode from line: 235

sub addToNode {
  my $key = shift;
my $val = shift;
my $node = shift;

  
if ($globalTrace) { printf("addToNode at q/compiler.qon:235\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: addToNode

  if ($globalTrace) {printf("Leaving \n")}

  return(cons(boxSymbol("node"), alistCons($key, $val, cdr($node))));

}


#Building function makeStatementNode from line: 240

sub makeStatementNode {
  my $name = shift;
my $subname = shift;
my $code = shift;
my $children = shift;
my $functionName = shift;

  
if ($globalTrace) { printf("makeStatementNode at q/compiler.qon:240\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: makeStatementNode

  if ($globalTrace) {printf("Leaving \n")}

  return(addToNode(boxSymbol("functionName"), $functionName, makeNode($name, $subname, $code, $children)));

}


#Building function astExpression from line: 245

sub astExpression {
  my $tree = shift;

  
if ($globalTrace) { printf("astExpression at q/compiler.qon:245\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isList($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astExpression

    if ($globalTrace) {printf("Leaving \n")}

    return(makeNode("expression", "expression", $undef, astSubExpression($tree)));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astExpression

    if ($globalTrace) {printf("Leaving \n")}

    return(astSubExpression($tree));

  };

}


#Building function astSubExpression from line: 253

sub astSubExpression {
  my $tree = shift;

  
if ($globalTrace) { printf("astSubExpression at q/compiler.qon:253\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astSubExpression

    if ($globalTrace) {printf("Leaving \n")}

    return(emptyList());

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isList($tree)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astSubExpression

      if ($globalTrace) {printf("Leaving \n")}

      return(cons(astExpression(car($tree)), astSubExpression(cdr($tree))));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astSubExpression

      if ($globalTrace) {printf("Leaving \n")}

      return(makeNode("expression", "leaf", $tree, $undef));

    };

  };

}


#Building function astIf from line: 264

sub astIf {
  my $tree = shift;
my $fname = shift;

  
if ($globalTrace) { printf("astIf at q/compiler.qon:264\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(boxString("then"), car(second($tree)))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nop()
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("Error at %s:%s!  If statement is missing the true branch.\n\n", stringify(getTag(car(first($tree)), boxString("filename"))), stringify(getTag(car(first($tree)), boxString("line"))))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    panic("Missing true branch in if statement!  All if statements must have a true and false branch, like this:\n\n(if hungryForApples\n(then (printf \"yes!\"))\n(else (printf \"no!\")))\n\n\n")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(boxString("else"), car(third($tree)))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nop()
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("Error at %s:%s!  If statement is missing the false branch.\n\n", stringify(getTag(car(first($tree)), boxString("filename"))), stringify(getTag(car(first($tree)), boxString("line"))))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    panic("Missing false branch in if statement!  All if statements must have a true and false branch, like this:\n\n(if hungryForApples\n(then (printf \"yes!\"))\n(else (printf \"no!\")))\n\n\n")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astIf

  if ($globalTrace) {printf("Leaving \n")}

  return(makeNode("statement", "if", $tree, cons(cons(astExpression(first($tree)), $undef), cons(astBody(cdr(second($tree)), $fname), cons(astBody(cdr(third($tree)), $fname), $undef)))));

}


#Building function astSetStruct from line: 285

sub astSetStruct {
  my $tree = shift;

  
if ($globalTrace) { printf("astSetStruct at q/compiler.qon:285\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astSetStruct

  if ($globalTrace) {printf("Leaving \n")}

  return(makeNode("statement", "structSetter", $tree, astExpression(third($tree))));

}


#Building function astSet from line: 290

sub astSet {
  my $tree = shift;

  
if ($globalTrace) { printf("astSet at q/compiler.qon:290\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astSet

  if ($globalTrace) {printf("Leaving \n")}

  return(makeNode("statement", "setter", $tree, astExpression(second($tree))));

}


#Building function astGetStruct from line: 295

sub astGetStruct {
  my $tree = shift;

  
if ($globalTrace) { printf("astGetStruct at q/compiler.qon:295\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astGetStruct

  if ($globalTrace) {printf("Leaving \n")}

  return(makeNode("expression", "structGetter", $tree, $undef));

}


#Building function astReturnVoid from line: 298

sub astReturnVoid {
  my $fname = shift;

  
if ($globalTrace) { printf("astReturnVoid at q/compiler.qon:298\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astReturnVoid

  if ($globalTrace) {printf("Leaving \n")}

  return(makeStatementNode("statement", "returnvoid", $undef, $undef, $fname));

}


#Building function astStatement from line: 302

sub astStatement {
  my $tree = shift;
my $fname = shift;

  
if ($globalTrace) { printf("astStatement at q/compiler.qon:302\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isList($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nop()
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("Error at %s:%s!  Statement must be a list.\n\n", stringify(getTag(car(first($tree)), boxString("filename"))), stringify(getTag(car(first($tree)), boxString("line"))))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    panic("A statement must be a list: (printf \"Hello\")\n\n\n")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(boxString("if"), car($tree))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astStatement

    if ($globalTrace) {printf("Leaving \n")}

    return(astIf(cdr($tree), $fname));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalBox(boxString("set"), car($tree))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astStatement

      if ($globalTrace) {printf("Leaving \n")}

      return(astSet(cdr($tree)));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalBox(boxString("get-struct"), car($tree))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printf("Choosing get-struct statement\n")
        ;
        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astStatement

        if ($globalTrace) {printf("Leaving \n")}

        return(astGetStruct(cdr($tree)));

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalBox(boxString("set-struct"), car($tree))) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astStatement

          if ($globalTrace) {printf("Leaving \n")}

          return(astSetStruct(cdr($tree)));

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalBox(boxString("return"), car($tree))) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            if ( equal(listLength($tree), 1)) {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astStatement

              if ($globalTrace) {printf("Leaving \n")}

              return(astReturnVoid($fname));

            } else {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astStatement

              if ($globalTrace) {printf("Leaving \n")}

              return(makeStatementNode("statement", "return", $tree, makeNode("expression", "expression", $tree, astExpression($tree)), $fname));

            };

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astStatement

            if ($globalTrace) {printf("Leaving \n")}

            return(makeStatementNode("statement", "statement", $tree, makeNode("expression", "expression", $tree, astExpression($tree)), $fname));

          };

        };

      };

    };

  };

}


#Building function astBody from line: 340

sub astBody {
  my $tree = shift;
my $fname = shift;

  
if ($globalTrace) { printf("astBody at q/compiler.qon:340\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astBody

    if ($globalTrace) {printf("Leaving \n")}

    return(emptyList());

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astBody

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(astStatement(car($tree), $fname), astBody(cdr($tree), $fname)));

  };

}


#Building function astFunction from line: 348

sub astFunction {
  my $tree = shift;

  my $file = "";
my $line = "";
my $fname = undef;

if ($globalTrace) { printf("astFunction at q/compiler.qon:348\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $fname = second($tree);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $line = stringify(getTag($fname, boxString("line")));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $file = stringify(getTag($fname, boxString("filename")));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan(1, listLength($tree))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    locPanic($file, $line, "Malformed function, seems to be empty")
    ;

  } else {
  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan(2, listLength($tree))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    locPanic($file, $line, "Malformed function, expected function name")
    ;

  } else {
  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan(3, listLength($tree))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    locPanic($file, $line, "Malformed function, expected argument list")
    ;

  } else {
  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan(4, listLength($tree))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    locPanic($file, $line, "Malformed function, expected variable declarations")
    ;

  } else {
  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan(5, listLength($tree))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    locPanic($file, $line, "Malformed function, expected body")
    ;

  } else {
  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astFunction

  if ($globalTrace) {printf("Leaving \n")}

  return(alistCons(boxSymbol("file"), getTag($fname, boxString("filename")), alistCons(boxSymbol("line"), getTag($fname, boxString("line")), cons(cons(boxSymbol("name"), boxString("function")), cons(cons(boxSymbol("subname"), second($tree)), cons(cons(boxSymbol("declarations"), cdr(fourth($tree))), cons(cons(boxSymbol("intype"), third($tree)), cons(cons(boxSymbol("outtype"), car($tree)), cons(cons(boxSymbol("children"), astBody(cdr(fifth($tree)), $fname)), emptyList())))))))));

}


#Building function astFunctionList from line: 381

sub astFunctionList {
  my $tree = shift;

  
if ($globalTrace) { printf("astFunctionList at q/compiler.qon:381\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astFunctionList

    if ($globalTrace) {printf("Leaving \n")}

    return(emptyList());

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astFunctionList

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(astFunction(car($tree)), astFunctionList(cdr($tree))));

  };

}


#Building function astFunctions from line: 389

sub astFunctions {
  my $tree = shift;

  
if ($globalTrace) { printf("astFunctions at q/compiler.qon:389\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(boxString("functions"), car($tree))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astFunctions

    if ($globalTrace) {printf("Leaving \n")}

    return(makeNode("functions", "functions", $tree, astFunctionList(cdr($tree))));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    panic("Functions section not found!  Every program must have a function section, even if you don't define any functions, although that is a rather pointless program.  Your function section should look like:'\n\n(return_type function_name (arg1 arg2 arg3 ...) (declare types) (body (statement)(statement)))\n\n\nThe function section must be directly after the types section.")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astFunctions

    if ($globalTrace) {printf("Leaving \n")}

    return($undef);

  };

}


#Building function loadLib from line: 397

sub loadLib {
  my $path = shift;

  my $programStr = "";
my $tree = undef;
my $library = undef;

if ($globalTrace) { printf("loadLib at q/compiler.qon:397\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $programStr = read_file($path);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = readSexpr($programStr, $path);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrowalk($tree);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $library = alistCons(boxString("includes"), astIncludes(first($tree)), alistCons(boxString("types"), astTypes(second($tree)), alistCons(boxString("functions"), astFunctions(third($tree)), $undef)));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: loadLib

  if ($globalTrace) {printf("Leaving \n")}

  return($library);

}


#Building function astInclude from line: 413

sub astInclude {
  my $tree = shift;

  
if ($globalTrace) { printf("astInclude at q/compiler.qon:413\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astInclude

  if ($globalTrace) {printf("Leaving \n")}

  return(loadLib(stringify($tree)));

}


#Building function astIncludeList from line: 416

sub astIncludeList {
  my $tree = shift;

  
if ($globalTrace) { printf("astIncludeList at q/compiler.qon:416\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astIncludeList

    if ($globalTrace) {printf("Leaving \n")}

    return(emptyList());

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astIncludeList

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(astInclude(car($tree)), astIncludeList(cdr($tree))));

  };

}


#Building function astIncludes from line: 423

sub astIncludes {
  my $tree = shift;

  
if ($globalTrace) { printf("astIncludes at q/compiler.qon:423\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(boxString("includes"), car($tree))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astIncludes

    if ($globalTrace) {printf("Leaving \n")}

    return(makeNode("includes", "includes", $tree, astIncludeList(cdr($tree))));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    panic("Includes section not found!  Every program must have an include section, even if you don't import any libraries.  Your include section should look like:'\n\n(includes file1.qon file.qon)\n\n\nThe includes section must be the first section of the file.")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astIncludes

    if ($globalTrace) {printf("Leaving \n")}

    return($undef);

  };

}


#Building function astStruct from line: 431

sub astStruct {
  my $tree = shift;

  
if ($globalTrace) { printf("astStruct at q/compiler.qon:431\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astStruct

  if ($globalTrace) {printf("Leaving \n")}

  return(makeNode("type", "struct", $tree, $undef));

}


#Building function astType from line: 434

sub astType {
  my $tree = shift;

  
if ($globalTrace) { printf("astType at q/compiler.qon:434\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isList(cadr($tree))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astType

    if ($globalTrace) {printf("Leaving \n")}

    return(astStruct($tree));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astType

    if ($globalTrace) {printf("Leaving \n")}

    return(makeNode("type", "type", $tree, $undef));

  };

}


#Building function astTypeList from line: 440

sub astTypeList {
  my $tree = shift;

  
if ($globalTrace) { printf("astTypeList at q/compiler.qon:440\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astTypeList

    if ($globalTrace) {printf("Leaving \n")}

    return(emptyList());

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astTypeList

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(astType(car($tree)), astTypeList(cdr($tree))));

  };

}


#Building function astTypes from line: 446

sub astTypes {
  my $tree = shift;

  
if ($globalTrace) { printf("astTypes at q/compiler.qon:446\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    panic("Empty or absent types section")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astTypes

    if ($globalTrace) {printf("Leaving \n")}

    return(boxString("!!!Fuck"));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalBox(boxString("types"), car($tree))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astTypes

      if ($globalTrace) {printf("Leaving \n")}

      return(makeNode("types", "types", $tree, astTypeList(cdr($tree))));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      panic("Types section not found!  Every program must have a types section, even if you don't define any types")
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("Types section not found!  Every program must have a types section, even if you don't define any types")
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astTypes

      if ($globalTrace) {printf("Leaving \n")}

      return(boxString("!!!Fuck"));

    };

  };

}


#Building function declarationsof from line: 464

sub declarationsof {
  my $ass = shift;

  
if ($globalTrace) { printf("declarationsof at q/compiler.qon:464\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: declarationsof

  if ($globalTrace) {printf("Leaving \n")}

  return(cdr(assocPanic("declarations", cdr($ass), "Cons list has no declarations key")));

}


#Building function codeof from line: 467

sub codeof {
  my $ass = shift;

  
if ($globalTrace) { printf("codeof at q/compiler.qon:467\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: codeof

  if ($globalTrace) {printf("Leaving \n")}

  return(cdr(assocPanic("code", cdr($ass), "Given cons list does not contain a code key")));

}


#Building function functionNameof from line: 470

sub functionNameof {
  my $ass = shift;

  
if ($globalTrace) { printf("functionNameof at q/compiler.qon:470\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: functionNameof

  if ($globalTrace) {printf("Leaving \n")}

  return(cdr(assoc("functionName", cdr($ass))));

}


#Building function nodeof from line: 473

sub nodeof {
  my $ass = shift;

  
if ($globalTrace) { printf("nodeof at q/compiler.qon:473\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(boxBool($false), assoc("node", cdr($ass)))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("Given list does not contain nodes")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: nodeof

    if ($globalTrace) {printf("Leaving \n")}

    return(boxBool($false));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: nodeof

    if ($globalTrace) {printf("Leaving \n")}

    return(cdr(assoc("node", cdr($ass))));

  };

}


#Building function lineof from line: 481

sub lineof {
  my $ass = shift;

  
if ($globalTrace) { printf("lineof at q/compiler.qon:481\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: lineof

  if ($globalTrace) {printf("Leaving \n")}

  return(cdr(assocFail("line", cdr($ass), boxInt(-1))));

}


#Building function subnameof from line: 486

sub subnameof {
  my $ass = shift;

  
if ($globalTrace) { printf("subnameof at q/compiler.qon:486\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: subnameof

  if ($globalTrace) {printf("Leaving \n")}

  return(cdr(assoc("subname", cdr($ass))));

}


#Building function nameof from line: 489

sub nameof {
  my $ass = shift;

  
if ($globalTrace) { printf("nameof at q/compiler.qon:489\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: nameof

  if ($globalTrace) {printf("Leaving \n")}

  return(cdr(assoc("name", cdr($ass))));

}


#Building function childrenof from line: 492

sub childrenof {
  my $ass = shift;

  
if ($globalTrace) { printf("childrenof at q/compiler.qon:492\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: childrenof

  if ($globalTrace) {printf("Leaving \n")}

  return(cdr(assoc("children", cdr($ass))));

}


#Building function isNode from line: 496

sub isNode {
  my $val = shift;

  
if ($globalTrace) { printf("isNode at q/compiler.qon:496\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($val)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isNode

    if ($globalTrace) {printf("Leaving \n")}

    return($false);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isList($val)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalBox(boxSymbol("node"), car($val))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isNode

        if ($globalTrace) {printf("Leaving \n")}

        return($true);

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isNode

        if ($globalTrace) {printf("Leaving \n")}

        return($false);

      };

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isNode

      if ($globalTrace) {printf("Leaving \n")}

      return($false);

    };

  };

}


#Building function isLeaf from line: 512

sub isLeaf {
  my $n = shift;

  
if ($globalTrace) { printf("isLeaf at q/compiler.qon:512\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isLeaf

  if ($globalTrace) {printf("Leaving \n")}

  return(equalBox(boxString("leaf"), subnameof($n)));

}


#Building function noStackTrace from line: 515

sub noStackTrace {
  
  
if ($globalTrace) { printf("noStackTrace at q/compiler.qon:515\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: noStackTrace

  if ($globalTrace) {printf("Leaving \n")}

  return(cons(boxString("boxType"), cons(boxString("stringify"), cons(boxString("isEmpty"), cons(boxString("unBoxString"), cons(boxString("isList"), cons(boxString("unBoxBool"), cons(boxString("unBoxSymbol"), cons(boxString("equalBox"), cons(boxString("assoc"), cons(boxString("inList"), cons(boxString("unBoxInt"), cons(boxString("listLength"), cons(boxString("stroff"), cons(boxString("troff"), cons(boxString("tron"), cons(boxString("stron"), cons(boxString("car"), cons(boxString("cdr"), cons(boxString("cons"), cons(boxString("stackTracePush"), cons(boxString("stackTracePop"), cons(boxString("assertType"), cons(boxString("boxString"), cons(boxString("boxSymbol"), cons(boxString("boxInt"), $undef))))))))))))))))))))))))));

}


#Building function treeCompile from line: 547

sub treeCompile {
  my $filename = shift;

  my $programStr = "";
my $tree = undef;

if ($globalTrace) { printf("treeCompile at q/compiler.qon:547\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $programStr = read_file($filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = readSexpr($programStr, $filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: treeCompile

  if ($globalTrace) {printf("Leaving \n")}

  return($tree);

}


#Building function astBuild from line: 553

sub astBuild {
  my $filename = shift;

  my $programStr = "";
my $tree = undef;
my $program = undef;

if ($globalTrace) { printf("astBuild at q/compiler.qon:553\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $programStr = read_file($filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = readSexpr($programStr, $filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $program = alistCons(boxString("includes"), astIncludes(first($tree)), alistCons(boxString("types"), astTypes(second($tree)), alistCons(boxString("functions"), astFunctions(third($tree)), $undef)));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $program = mergeIncludes($program);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: astBuild

  if ($globalTrace) {printf("Leaving \n")}

  return($program);

}


#Building function astCompile from line: 570

sub astCompile {
  my $filename = shift;

  my $tree = undef;
my $replace = undef;

if ($globalTrace) { printf("astCompile at q/compiler.qon:570\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = loadQuon($filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  qlog("Final program: \n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = loadIncludes($tree);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrowalk($tree);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrosingle($tree, "write-file", "luaWriteFile");
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrosingle($tree, "read-file", "luaReadFile");
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrosingle($tree, "string-length", "string.len");
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrosingle($tree, "sub-string", "luaSubstring");
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrosingle($tree, "stringLength", "string.len");
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), $undef));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrolist($tree, stringConcatenate("q", "log"), $replace);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  displayList($tree, 0, $true)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  qlog("Transformed tree")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\n")
  ;

}


#Building function mergeIncludes from line: 594

sub mergeIncludes {
  my $program = shift;

  
if ($globalTrace) { printf("mergeIncludes at q/compiler.qon:594\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: mergeIncludes

  if ($globalTrace) {printf("Leaving \n")}

  return(merge_recur(childrenof(cdr(cdr(assocPanic("includes", $program, "Program lacks include section")))), $program));

}


#Building function merge_recur from line: 601

sub merge_recur {
  my $incs = shift;
my $program = shift;

  
if ($globalTrace) { printf("merge_recur at q/compiler.qon:601\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan(listLength($incs), 0)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: merge_recur

    if ($globalTrace) {printf("Leaving \n")}

    return(mergeInclude(car($incs), merge_recur(cdr($incs), $program)));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: merge_recur

    if ($globalTrace) {printf("Leaving \n")}

    return($program);

  };

}


#Building function mergeInclude from line: 609

sub mergeInclude {
  my $inc = shift;
my $program = shift;

  my $newProgram = undef;
my $oldfunctionsnode = undef;
my $oldfunctions = undef;
my $newfunctions = undef;
my $newFunctionNode = undef;
my $functions = undef;
my $oldtypesnode = undef;
my $oldtypes = undef;
my $newtypes = undef;
my $newTypeNode = undef;
my $types = undef;

if ($globalTrace) { printf("mergeInclude at q/compiler.qon:609\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($inc)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: mergeInclude

    if ($globalTrace) {printf("Leaving \n")}

    return($program);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $functions = childrenof(cdr(assocPanic("functions", $inc, "Included file has no functions section")));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $oldfunctionsnode = cdr(assocPanic("functions", $program, "Current module has no functions section"));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $oldfunctions = childrenof($oldfunctionsnode);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $newfunctions = concatLists($functions, $oldfunctions);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $newFunctionNode = cons(boxSymbol("node"), alistCons(boxSymbol("children"), $newfunctions, cdr($oldfunctionsnode)));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $types = childrenof(cdr(assocPanic("types", $inc, "Included file has no types section")));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $oldtypesnode = cdr(assocPanic("types", $program, "Current module has no types section"));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $oldtypes = childrenof($oldtypesnode);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $newtypes = concatLists($types, $oldtypes);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $newTypeNode = cons(boxSymbol("node"), alistCons(boxSymbol("children"), $newtypes, cdr($oldtypesnode)));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $newProgram = alistCons(boxString("functions"), $newFunctionNode, alistCons(boxString("types"), $newTypeNode, alistCons(boxString("includes"), cons(boxSymbol("includes"), $undef), $newProgram)));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: mergeInclude

    if ($globalTrace) {printf("Leaving \n")}

    return($newProgram);

  };

}


#Building function macrowalk from line: 5

sub macrowalk {
  my $l = shift;

  
if ($globalTrace) { printf("macrowalk at q/macros.qon:5\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: macrowalk

    if ($globalTrace) {printf("Leaving \n")}

    return($undef);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isList($l)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString(stringConcatenate("box", "List"), stringify(car($l)))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: macrowalk

        if ($globalTrace) {printf("Leaving \n")}

        return(car(doBoxList(cdr($l))));

      } else {
      };
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString(stringConcatenate("string", "List"), stringify(car($l)))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: macrowalk

        if ($globalTrace) {printf("Leaving \n")}

        return(car(doStringList(cdr($l))));

      } else {
      };
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString(stringConcatenate("symbol", "List"), stringify(car($l)))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: macrowalk

        if ($globalTrace) {printf("Leaving \n")}

        return(car(doSymbolList(cdr($l))));

      } else {
      };
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString(stringConcatenate("multi", "List"), stringify(car($l)))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: macrowalk

        if ($globalTrace) {printf("Leaving \n")}

        return(car(doMultiList(cdr($l))));

      } else {
      };
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString(stringConcatenate("makeL", "ist"), stringify(car($l)))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: macrowalk

        if ($globalTrace) {printf("Leaving \n")}

        return(car(doInterpolatedList(cdr($l))));

      } else {
      };
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: macrowalk

      if ($globalTrace) {printf("Leaving \n")}

      return(cons(macrowalk(car($l)), macrowalk(cdr($l))));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: macrowalk

      if ($globalTrace) {printf("Leaving \n")}

      return($l);

    };

  };

}


#Building function macrosingle from line: 56

sub macrosingle {
  my $l = shift;
my $search = shift;
my $replace = shift;

  my $val = undef;

if ($globalTrace) { printf("macrosingle at q/macros.qon:56\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: macrosingle

    if ($globalTrace) {printf("Leaving \n")}

    return($undef);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isList($l)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: macrosingle

      if ($globalTrace) {printf("Leaving \n")}

      return(cons(macrosingle(car($l), $search, $replace), macrosingle(cdr($l), $search, $replace)));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString($search, stringify($l))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        $val = clone($l);
        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        $val->{str} = $replace;
        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: macrosingle

        if ($globalTrace) {printf("Leaving \n")}

        return($val);

      } else {
      };
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: macrosingle

      if ($globalTrace) {printf("Leaving \n")}

      return($l);

    };

  };

}


#Building function macrolist from line: 80

sub macrolist {
  my $l = shift;
my $search = shift;
my $replace = shift;

  my $val = undef;

if ($globalTrace) { printf("macrolist at q/macros.qon:80\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: macrolist

    if ($globalTrace) {printf("Leaving \n")}

    return($undef);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isList($l)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString($search, stringify(car($l)))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: macrolist

        if ($globalTrace) {printf("Leaving \n")}

        return(concatLists($replace, macrolist(cdr($l), $search, $replace)));

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: macrolist

        if ($globalTrace) {printf("Leaving \n")}

        return(cons(macrolist(car($l), $search, $replace), macrolist(cdr($l), $search, $replace)));

      };

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: macrolist

      if ($globalTrace) {printf("Leaving \n")}

      return($l);

    };

  };

}


#Building function car from line: 9

sub car {
  my $l = shift;

  
if ($globalTrace) { printf("car at q/lists.qon:9\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("Cannot call car on empty list!\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    panic("Cannot call car on empty list!\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    return($undef);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    assertType("list", $l, 18, "q/lists.qon")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil($l->{car})) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      return($undef);

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      return($l->{car});

    };

  };

}


#Building function cdr from line: 23

sub cdr {
  my $l = shift;

  
if ($globalTrace) { printf("cdr at q/lists.qon:23\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  assertType("list", $l, 25, "q/lists.qon")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("Attempt to cdr an empty list!!!!\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    panic("Attempt to cdr an empty list!!!!\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    return($undef);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    return($l->{cdr});

  };

}


#Building function cons from line: 33

sub cons {
  my $data = shift;
my $l = shift;

  my $p = undef;

if ($globalTrace) { printf("cons at q/lists.qon:33\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $p = makePair();
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $p->{cdr} = $l;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $p->{car} = $data;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $p->{typ} = "list";
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  return($p);

}


#Building function caar from line: 45

sub caar {
  my $l = shift;

  
if ($globalTrace) { printf("caar at q/lists.qon:45\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: caar

  if ($globalTrace) {printf("Leaving \n")}

  return(car(car($l)));

}


#Building function cadr from line: 46

sub cadr {
  my $l = shift;

  
if ($globalTrace) { printf("cadr at q/lists.qon:46\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: cadr

  if ($globalTrace) {printf("Leaving \n")}

  return(car(cdr($l)));

}


#Building function caddr from line: 47

sub caddr {
  my $l = shift;

  
if ($globalTrace) { printf("caddr at q/lists.qon:47\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: caddr

  if ($globalTrace) {printf("Leaving \n")}

  return(car(cdr(cdr($l))));

}


#Building function cadddr from line: 48

sub cadddr {
  my $l = shift;

  
if ($globalTrace) { printf("cadddr at q/lists.qon:48\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: cadddr

  if ($globalTrace) {printf("Leaving \n")}

  return(car(cdr(cdr(cdr($l)))));

}


#Building function caddddr from line: 49

sub caddddr {
  my $l = shift;

  
if ($globalTrace) { printf("caddddr at q/lists.qon:49\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: caddddr

  if ($globalTrace) {printf("Leaving \n")}

  return(car(cdr(cdr(cdr(cdr($l))))));

}


#Building function cddr from line: 50

sub cddr {
  my $l = shift;

  
if ($globalTrace) { printf("cddr at q/lists.qon:50\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: cddr

  if ($globalTrace) {printf("Leaving \n")}

  return(cdr(cdr($l)));

}


#Building function first from line: 51

sub first {
  my $l = shift;

  
if ($globalTrace) { printf("first at q/lists.qon:51\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: first

  if ($globalTrace) {printf("Leaving \n")}

  return(car($l));

}


#Building function second from line: 52

sub second {
  my $l = shift;

  
if ($globalTrace) { printf("second at q/lists.qon:52\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: second

  if ($globalTrace) {printf("Leaving \n")}

  return(cadr($l));

}


#Building function third from line: 53

sub third {
  my $l = shift;

  
if ($globalTrace) { printf("third at q/lists.qon:53\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: third

  if ($globalTrace) {printf("Leaving \n")}

  return(caddr($l));

}


#Building function fourth from line: 54

sub fourth {
  my $l = shift;

  
if ($globalTrace) { printf("fourth at q/lists.qon:54\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: fourth

  if ($globalTrace) {printf("Leaving \n")}

  return(cadddr($l));

}


#Building function fifth from line: 55

sub fifth {
  my $l = shift;

  
if ($globalTrace) { printf("fifth at q/lists.qon:55\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: fifth

  if ($globalTrace) {printf("Leaving \n")}

  return(caddddr($l));

}


#Building function isList from line: 58

sub isList {
  my $b = shift;

  
if ($globalTrace) { printf("isList at q/lists.qon:58\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($b)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    return($true);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    return(equalString("list", $b->{typ}));

  };

}


#Building function emptyList from line: 65

sub emptyList {
  
  
if ($globalTrace) { printf("emptyList at q/lists.qon:65\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: emptyList

  if ($globalTrace) {printf("Leaving \n")}

  return($undef);

}


#Building function isEmpty from line: 67

sub isEmpty {
  my $b = shift;

  
if ($globalTrace) { printf("isEmpty at q/lists.qon:67\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($b)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    return($true);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    return($false);

  };

}


#Building function listLength from line: 74

sub listLength {
  my $l = shift;

  
if ($globalTrace) { printf("listLength at q/lists.qon:74\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    return(0);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    return(add1(listLength(cdr($l))));

  };

}


#Building function alistCons from line: 83

sub alistCons {
  my $key = shift;
my $value = shift;
my $alist = shift;

  
if ($globalTrace) { printf("alistCons at q/lists.qon:83\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: alistCons

  if ($globalTrace) {printf("Leaving \n")}

  return(cons(cons($key, $value), $alist));

}


#Building function assoc from line: 86

sub assoc {
  my $searchTerm = shift;
my $l = shift;

  my $elem = undef;

if ($globalTrace) { printf("assoc at q/lists.qon:86\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  assertType("list", $l, 88, "q/lists.qon")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    return(boxBool($false));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $elem = car($l);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    assertType("list", $elem, 94, "q/lists.qon")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isEmpty($elem)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      return(assoc($searchTerm, cdr($l)));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( $false) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printf("Comparing %s and %s\n", $searchTerm, stringify(car($elem)))
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printf("")
        ;

      };
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString($searchTerm, stringify(car($elem)))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        return($elem);

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        return(assoc($searchTerm, cdr($l)));

      };

    };

  };

}


#Building function chooseBox from line: 106

sub chooseBox {
  my $aType = shift;

  
if ($globalTrace) { printf("chooseBox at q/lists.qon:106\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("string", $aType)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: chooseBox

    if ($globalTrace) {printf("Leaving \n")}

    return("boxString");

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalString("symbol", $aType)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: chooseBox

      if ($globalTrace) {printf("Leaving \n")}

      return("boxSymbol");

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString("bool", $aType)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: chooseBox

        if ($globalTrace) {printf("Leaving \n")}

        return("boxBool");

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalString("int", $aType)) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: chooseBox

          if ($globalTrace) {printf("Leaving \n")}

          return("boxInt");

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalString("float", $aType)) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: chooseBox

            if ($globalTrace) {printf("Leaving \n")}

            return("boxFloat");

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            panic("Invalid type")
            ;

          };

        };

      };

    };

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: chooseBox

  if ($globalTrace) {printf("Leaving \n")}

  return("");

}


#Building function mlistLiteral from line: 122

sub mlistLiteral {
  my $b = shift;

  
if ($globalTrace) { printf("mlistLiteral at q/lists.qon:122\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($b)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: mlistLiteral

    if ($globalTrace) {printf("Leaving \n")}

    return($undef);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalString("string", boxType($b))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: mlistLiteral

      if ($globalTrace) {printf("Leaving \n")}

      return($b);

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString("bool", boxType($b))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: mlistLiteral

        if ($globalTrace) {printf("Leaving \n")}

        return($b);

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalString("int", boxType($b))) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: mlistLiteral

          if ($globalTrace) {printf("Leaving \n")}

          return($b);

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalString("symbol", boxType($b))) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: mlistLiteral

            if ($globalTrace) {printf("Leaving \n")}

            return(boxString(unBoxSymbol($b)));

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: mlistLiteral

            if ($globalTrace) {printf("Leaving \n")}

            return(boxString(stringConcatenate("Unsupported type: ", boxType($b))));

          };

        };

      };

    };

  };

}


#Building function doMultiList from line: 146

sub doMultiList {
  my $l = shift;

  my $newlist = undef;
my $ret = undef;
my $elem = undef;

if ($globalTrace) { printf("doMultiList at q/lists.qon:146\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: doMultiList

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(boxSymbol("nil"), $undef));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isEmpty($l)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: doMultiList

      if ($globalTrace) {printf("Leaving \n")}

      return($undef);

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      $elem = first($l);
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      $newlist = cons(boxString(chooseBox($elem->{typ})), cons(mlistLiteral(first($l)), $newlist));
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      $ret = cons(cons(boxSymbol("cons"), cons($newlist, doMultiList(cdr($l)))), $undef);
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: doMultiList

      if ($globalTrace) {printf("Leaving \n")}

      return($ret);

    };

  };

}


#Building function isInt from line: 168

sub isInt {
  my $val = shift;

  my $firstLetter = [sub-string val 0 1];

if ($globalTrace) { printf("isInt at q/lists.qon:168\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("-", $firstLetter)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isInt

    if ($globalTrace) {printf("Leaving \n")}

    return($true);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalString("0", $firstLetter)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isInt

      if ($globalTrace) {printf("Leaving \n")}

      return($true);

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString("1", $firstLetter)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isInt

        if ($globalTrace) {printf("Leaving \n")}

        return($true);

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalString("2", $firstLetter)) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isInt

          if ($globalTrace) {printf("Leaving \n")}

          return($true);

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalString("3", $firstLetter)) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isInt

            if ($globalTrace) {printf("Leaving \n")}

            return($true);

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            if ( equalString("4", $firstLetter)) {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isInt

              if ($globalTrace) {printf("Leaving \n")}

              return($true);

            } else {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

              if ( equalString("5", $firstLetter)) {                if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isInt

                if ($globalTrace) {printf("Leaving \n")}

                return($true);

              } else {                if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

                if ( equalString("6", $firstLetter)) {                  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isInt

                  if ($globalTrace) {printf("Leaving \n")}

                  return($true);

                } else {                  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

                  if ( equalString("7", $firstLetter)) {                    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isInt

                    if ($globalTrace) {printf("Leaving \n")}

                    return($true);

                  } else {                    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

                    if ( equalString("8", $firstLetter)) {                      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isInt

                      if ($globalTrace) {printf("Leaving \n")}

                      return($true);

                    } else {                      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

                      if ( equalString("9", $firstLetter)) {                        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isInt

                        if ($globalTrace) {printf("Leaving \n")}

                        return($true);

                      } else {                        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: isInt

                        if ($globalTrace) {printf("Leaving \n")}

                        return($false);

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


#Building function id from line: 196

sub id {
  my $b = shift;

  
if ($globalTrace) { printf("id at q/lists.qon:196\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: id

  if ($globalTrace) {printf("Leaving \n")}

  return($b);

}


#Building function chooseBoxInterp from line: 199

sub chooseBoxInterp {
  my $b = shift;

  my $val = [stringify b];
my $firstLetter = [sub-string val 0 1];

if ($globalTrace) { printf("chooseBoxInterp at q/lists.qon:199\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("string", boxType($b))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: chooseBoxInterp

    if ($globalTrace) {printf("Leaving \n")}

    return("boxString");

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalString("\"", $firstLetter)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: chooseBoxInterp

      if ($globalTrace) {printf("Leaving \n")}

      return("boxString");

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString("true", $val)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: chooseBoxInterp

        if ($globalTrace) {printf("Leaving \n")}

        return("boxBool");

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalString("false", $val)) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: chooseBoxInterp

          if ($globalTrace) {printf("Leaving \n")}

          return("boxBool");

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( isInt($val)) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: chooseBoxInterp

            if ($globalTrace) {printf("Leaving \n")}

            return("boxInt");

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            if ( isInt($val)) {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: chooseBoxInterp

              if ($globalTrace) {printf("Leaving \n")}

              return("boxFloat");

            } else {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: chooseBoxInterp

              if ($globalTrace) {printf("Leaving \n")}

              return("id");

            };

          };

        };

      };

    };

  };

}


#Building function doInterpolatedList from line: 224

sub doInterpolatedList {
  my $l = shift;

  my $newlist = undef;
my $ret = undef;
my $elem = undef;

if ($globalTrace) { printf("doInterpolatedList at q/lists.qon:224\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: doInterpolatedList

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(boxSymbol("nil"), $undef));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isEmpty($l)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: doInterpolatedList

      if ($globalTrace) {printf("Leaving \n")}

      return($undef);

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      $elem = first($l);
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      $newlist = cons(boxString(chooseBoxInterp($elem)), cons(first($l), $newlist));
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      $ret = cons(cons(boxSymbol("cons"), cons($newlist, doInterpolatedList(cdr($l)))), $undef);
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: doInterpolatedList

      if ($globalTrace) {printf("Leaving \n")}

      return($ret);

    };

  };

}


#Building function doStringList from line: 248

sub doStringList {
  my $l = shift;

  my $newlist = undef;
my $ret = undef;

if ($globalTrace) { printf("doStringList at q/lists.qon:248\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: doStringList

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(boxSymbol("nil"), $undef));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $newlist = cons(boxSymbol("boxString"), cons(first($l), $newlist));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $ret = cons(cons(boxSymbol("cons"), cons($newlist, doStringList(cdr($l)))), $undef);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: doStringList

    if ($globalTrace) {printf("Leaving \n")}

    return($ret);

  };

}


#Building function doSymbolList from line: 265

sub doSymbolList {
  my $l = shift;

  my $newlist = undef;
my $ret = undef;

if ($globalTrace) { printf("doSymbolList at q/lists.qon:265\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: doSymbolList

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(boxSymbol("nil"), $undef));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $newlist = cons(boxSymbol("boxSymbol"), cons(first($l), $newlist));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $ret = cons(cons(boxSymbol("cons"), cons($newlist, doSymbolList(cdr($l)))), $undef);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: doSymbolList

    if ($globalTrace) {printf("Leaving \n")}

    return($ret);

  };

}


#Building function doBoxList from line: 283

sub doBoxList {
  my $l = shift;

  
if ($globalTrace) { printf("doBoxList at q/lists.qon:283\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: doBoxList

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(boxSymbol("nil"), $undef));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: doBoxList

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(cons(boxSymbol("cons"), cons(first($l), doBoxList(cdr($l)))), $undef));

  };

}


#Building function concatLists from line: 302

sub concatLists {
  my $seq1 = shift;
my $seq2 = shift;

  
if ($globalTrace) { printf("concatLists at q/lists.qon:302\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($seq1)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: concatLists

    if ($globalTrace) {printf("Leaving \n")}

    return($seq2);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: concatLists

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(car($seq1), concatLists(cdr($seq1), $seq2)));

  };

}


#Building function alistKeys from line: 308

sub alistKeys {
  my $alist = shift;

  
if ($globalTrace) { printf("alistKeys at q/lists.qon:308\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($alist)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: alistKeys

    if ($globalTrace) {printf("Leaving \n")}

    return($undef);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: alistKeys

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(car(car($alist)), alistKeys(cdr($alist))));

  };

}


#Building function display from line: 314

sub display {
  my $l = shift;

  
if ($globalTrace) { printf("display at q/lists.qon:314\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("nil ")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isList($l)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("[")
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      displayList($l, 0, $true)
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("]")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      displayList($l, 0, $true)
      ;

    };

  };

}


#Building function displayList from line: 323

sub displayList {
  my $l = shift;
my $indent = shift;
my $first = shift;

  my $val = undef;

if ($globalTrace) { printf("displayList at q/lists.qon:323\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isList($l)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( isEmpty($l)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

        
        return;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( $first) {
        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf(" ")
          ;

        };
        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        $val = car($l);
        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( isList($val)) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          newLine($indent)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf("%s", openBrace())
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          displayList(car($l), add1($indent), $true)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf("%s", closeBrace())
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          displayList(cdr($l), $indent, $false)
          ;

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalString("string", $val->{typ})) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("\"%s\"", unBoxString($val))
            ;

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("%s", stringify($val))
            ;

          };
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          displayList(cdr($l), $indent, $false)
          ;

        };

      };

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString("string", $l->{typ})) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printf("\"%s\"", unBoxString($l))
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printf("%s", stringify($l))
        ;

      };

    };

  };

}


#Building function StringListJoinRec from line: 354

sub StringListJoinRec {
  my $l = shift;
my $sep = shift;

  my $val = undef;

if ($globalTrace) { printf("StringListJoinRec at q/lists.qon:354\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: StringListJoinRec

    if ($globalTrace) {printf("Leaving \n")}

    return("");

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isList($l)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( isEmpty($l)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: StringListJoinRec

        if ($globalTrace) {printf("Leaving \n")}

        return("");

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equal(listLength($l), 1)) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: StringListJoinRec

          if ($globalTrace) {printf("Leaving \n")}

          return(stringify(car($l)));

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: StringListJoinRec

          if ($globalTrace) {printf("Leaving \n")}

          return(stringConcatenate(stringify(car($l)), stringConcatenate($sep, StringListJoinRec(cdr($l), $sep))));

        };

      };

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: StringListJoinRec

      if ($globalTrace) {printf("Leaving \n")}

      return("");

    };

  };

}


#Building function StringListJoin from line: 377

sub StringListJoin {
  my $l = shift;
my $sep = shift;

  my $val = undef;

if ($globalTrace) { printf("StringListJoin at q/lists.qon:377\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan(listLength($l), 1)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: StringListJoin

    if ($globalTrace) {printf("Leaving \n")}

    return(stringConcatenate(stringify(car($l)), stringConcatenate($sep, StringListJoinRec(cdr($l), $sep))));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: StringListJoin

    if ($globalTrace) {printf("Leaving \n")}

    return(stringify(car($l)));

  };

}


#Building function ListToBoxString from line: 387

sub ListToBoxString {
  my $l = shift;

  
if ($globalTrace) { printf("ListToBoxString at q/lists.qon:387\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ListToBoxString

  if ($globalTrace) {printf("Leaving \n")}

  return(boxString(ListToString($l, 0, $true, $false)));

}


#Building function ListToString from line: 392

sub ListToString {
  my $l = shift;
my $indent = shift;
my $first = shift;
my $withNewLines = shift;

  my $val = undef;

if ($globalTrace) { printf("ListToString at q/lists.qon:392\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ListToString

    if ($globalTrace) {printf("Leaving \n")}

    return("");

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isList($l)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( isEmpty($l)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ListToString

        if ($globalTrace) {printf("Leaving \n")}

        return("");

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        $val = car($l);
        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( isList($val)) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ListToString

          if ($globalTrace) {printf("Leaving \n")}

          return(StringListJoin(cons(boxString(stringify(tern($withNewLines, boxString("\n"), boxString(stringIndent($indent))))), cons(boxString(openBrace()), cons(boxString(" "), cons(boxString(ListToString(car($l), add1($indent), $true, $withNewLines)), cons(boxString(closeBrace()), cons(boxString(" "), cons(boxString(ListToString(cdr($l), $indent, $false, $withNewLines)), $undef))))))), ""));

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ListToString

          if ($globalTrace) {printf("Leaving \n")}

          return(stringConcatenate(stringify($val), ListToString(cdr($l), $indent, $false, $withNewLines)));

        };

      };

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ListToString

      if ($globalTrace) {printf("Leaving \n")}

      return(stringify($l));

    };

  };

}


#Building function listReverse from line: 432

sub listReverse {
  my $l = shift;

  
if ($globalTrace) { printf("listReverse at q/lists.qon:432\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: listReverse

    if ($globalTrace) {printf("Leaving \n")}

    return($undef);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: listReverse

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(car($l), listReverse(cdr($l))));

  };

}


#Building function inList from line: 438

sub inList {
  my $item = shift;
my $l = shift;

  
if ($globalTrace) { printf("inList at q/lists.qon:438\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    return($false);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalBox(car($l), $item)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      return($true);

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      return(inList($item, cdr($l)));

    };

  };

}


#Building function equalList from line: 448

sub equalList {
  my $a = shift;
my $b = shift;

  
if ($globalTrace) { printf("equalList at q/lists.qon:448\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($a)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil($b)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: equalList

      if ($globalTrace) {printf("Leaving \n")}

      return($true);

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: equalList

      if ($globalTrace) {printf("Leaving \n")}

      return($false);

    };

  } else {
  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($b)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil($a)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: equalList

      if ($globalTrace) {printf("Leaving \n")}

      return($true);

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: equalList

      if ($globalTrace) {printf("Leaving \n")}

      return($false);

    };

  } else {
  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(car($a), car($b))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: equalList

    if ($globalTrace) {printf("Leaving \n")}

    return(equalList(cdr($a), cdr($b)));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: equalList

    if ($globalTrace) {printf("Leaving \n")}

    return($false);

  };

}


#Building function reverseRec from line: 471

sub reverseRec {
  my $oldL = shift;
my $newL = shift;

  
if ($globalTrace) { printf("reverseRec at q/lists.qon:471\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($oldL)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: reverseRec

    if ($globalTrace) {printf("Leaving \n")}

    return($newL);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: reverseRec

    if ($globalTrace) {printf("Leaving \n")}

    return(reverseRec(cdr($oldL), cons(first($oldL), $newL)));

  };

}


#Building function reverseList from line: 478

sub reverseList {
  my $l = shift;

  
if ($globalTrace) { printf("reverseList at q/lists.qon:478\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: reverseList

  if ($globalTrace) {printf("Leaving \n")}

  return(reverseRec($l, $undef));

}


#Building function flatten from line: 483

sub flatten {
  my $tree = shift;

  
if ($globalTrace) { printf("flatten at q/lists.qon:483\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: flatten

    if ($globalTrace) {printf("Leaving \n")}

    return(emptyList());

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isList(car($tree))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: flatten

      if ($globalTrace) {printf("Leaving \n")}

      return(concatLists(flatten(car($tree)), flatten(cdr($tree))));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: flatten

      if ($globalTrace) {printf("Leaving \n")}

      return(cons(car($tree), flatten(cdr($tree))));

    };

  };

}


#Building function readSexpr from line: 4

sub readSexpr {
  my $aStr = shift;
my $filename = shift;

  my $tokens = undef;
my $as = undef;

if ($globalTrace) { printf("readSexpr at q/newparser.qon:4\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tokens = emptyList();
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tokens = filterTokens(filterVoid(scan($aStr, 0, 1, 0, 0, $filename)));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $as = sexprTree($tokens);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: readSexpr

  if ($globalTrace) {printf("Leaving \n")}

  return(car($as));

}


#Building function sexprTree from line: 11

sub sexprTree {
  my $l = shift;

  my $b = undef;

if ($globalTrace) { printf("sexprTree at q/newparser.qon:11\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($l)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: sexprTree

    if ($globalTrace) {printf("Leaving \n")}

    return(emptyList());

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $b = car($l);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isOpenBrace($b)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: sexprTree

      if ($globalTrace) {printf("Leaving \n")}

      return(cons(sexprTree(cdr($l)), sexprTree(skipList(cdr($l)))));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( isCloseBrace($b)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: sexprTree

        if ($globalTrace) {printf("Leaving \n")}

        return(emptyList());

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: sexprTree

        if ($globalTrace) {printf("Leaving \n")}

        return(setTag(boxString("line"), getTagFail($b, boxString("line"), boxInt(-1)), cons($b, sexprTree(cdr($l)))));

      };

    };

  };

}


#Building function loadQuon from line: 29

sub loadQuon {
  my $filename = shift;

  my $programStr = "";
my $tree = undef;

if ($globalTrace) { printf("loadQuon at q/newparser.qon:29\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $programStr = read_file($filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = readSexpr($programStr, $filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: loadQuon

  if ($globalTrace) {printf("Leaving \n")}

  return($tree);

}


#Building function getIncludes from line: 38

sub getIncludes {
  my $program = shift;

  
if ($globalTrace) { printf("getIncludes at q/newparser.qon:38\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: getIncludes

  if ($globalTrace) {printf("Leaving \n")}

  return(cdr(first($program)));

}


#Building function getTypes from line: 42

sub getTypes {
  my $program = shift;

  
if ($globalTrace) { printf("getTypes at q/newparser.qon:42\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: getTypes

  if ($globalTrace) {printf("Leaving \n")}

  return(cdr(second($program)));

}


#Building function getFunctions from line: 46

sub getFunctions {
  my $program = shift;

  
if ($globalTrace) { printf("getFunctions at q/newparser.qon:46\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: getFunctions

  if ($globalTrace) {printf("Leaving \n")}

  return(cdr(third($program)));

}


#Building function loadIncludes from line: 51

sub loadIncludes {
  my $tree = shift;

  my $newProg = undef;
my $includeFile = "";
my $functionsCombined = undef;
my $typesCombined = undef;
my $includeTree = undef;

if ($globalTrace) { printf("loadIncludes at q/newparser.qon:51\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan(listLength(getIncludes($tree)), 0)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $includeFile = stringify(first(getIncludes($tree)));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $includeTree = loadQuon($includeFile);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $functionsCombined = concatLists(getFunctions($includeTree), getFunctions($tree));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $typesCombined = concatLists(getTypes($includeTree), getTypes($tree));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $newProg = buildProg(cdr(getIncludes($tree)), $typesCombined, $functionsCombined);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: loadIncludes

    if ($globalTrace) {printf("Leaving \n")}

    return(loadIncludes($newProg));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: loadIncludes

    if ($globalTrace) {printf("Leaving \n")}

    return($tree);

  };

}


#Building function buildProg from line: 74

sub buildProg {
  my $includes = shift;
my $types = shift;
my $functions = shift;

  my $program = undef;

if ($globalTrace) { printf("buildProg at q/newparser.qon:74\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $includes = cons(boxSymbol("includes"), $includes);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $types = cons(boxSymbol("types"), $types);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $functions = cons(boxSymbol("functions"), $functions);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $program = cons($includes, cons($types, cons($functions, $undef)));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: buildProg

  if ($globalTrace) {printf("Leaving \n")}

  return($program);

}


#Building function numbers from line: 4

sub numbers {
  my $num = shift;

  
if ($globalTrace) { printf("numbers at q/perl.qon:4\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan(0, $num)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: numbers

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(boxString("-"), $undef));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: numbers

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(boxString(stringify(boxInt($num))), numbers(sub1($num))));

  };

}


#Building function lexType from line: 11

sub lexType {
  my $abox = shift;

  
if ($globalTrace) { printf("lexType at q/perl.qon:11\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("string", boxType($abox))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: lexType

    if ($globalTrace) {printf("Leaving \n")}

    return("string");

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( inList(boxString(substr(stringify($abox), 0, 1)), numbers(9))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: lexType

      if ($globalTrace) {printf("Leaving \n")}

      return("number");

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: lexType

      if ($globalTrace) {printf("Leaving \n")}

      return("symbol");

    };

  };

}


#Building function perlLeaf from line: 23

sub perlLeaf {
  my $thisNode = shift;
my $indent = shift;

  
if ($globalTrace) { printf("perlLeaf at q/perl.qon:23\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("symbol", lexType(codeof($thisNode)))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s", dollar())
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  display(perlFuncMap(codeof($thisNode)))
  ;

}


#Building function perlStructGetterExpression from line: 32

sub perlStructGetterExpression {
  my $thisNode = shift;
my $indent = shift;

  
if ($globalTrace) { printf("perlStructGetterExpression at q/perl.qon:32\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(boxString("structGetter"), subnameof($thisNode))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlGetStruct($thisNode, $indent)
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlLeaf($thisNode, $indent)
    ;

  };

}


#Building function perlExpression from line: 38

sub perlExpression {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("perlExpression at q/perl.qon:38\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isLeaf($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlLeaf($node, $indent)
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlSubExpression($node, $indent)
    ;

  };

}


#Building function perlRecurList from line: 44

sub perlRecurList {
  my $expr = shift;
my $indent = shift;

  
if ($globalTrace) { printf("perlRecurList at q/perl.qon:44\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($expr)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlExpression(car($expr), $indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil(cdr($expr))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf(", ")
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      perlRecurList(cdr($expr), $indent)
      ;

    };

  };

}


#Building function perlSubExpression from line: 55

sub perlSubExpression {
  my $tree = shift;
my $indent = shift;

  my $thing = undef;

if ($globalTrace) { printf("perlSubExpression at q/perl.qon:55\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNode(childrenof($tree))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      perlSubExpression(childrenof($tree), $indent)
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( isLeaf($tree)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printf("%s", dollar())
        ;
        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        display(perlFuncMap(codeof($tree)))
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equal(1, listLength(childrenof($tree)))) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          display(codeof(car(childrenof($tree))))
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalBox(boxString("return"), codeof(car(childrenof($tree))))) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("")
            ;

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("()")
            ;

          };

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          $thing = codeof(car(childrenof($tree)));
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalBox(boxSymbol("get-struct"), $thing)) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("%s%s->{%s}", dollar(), stringify(codeof(second(childrenof($tree)))), stringify(codeof(third(childrenof($tree)))))
            ;

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            if ( equalBox(boxSymbol("new"), $thing)) {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf("{}")
              ;

            } else {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf("%s(", stringify(perlFuncMap(codeof(car(childrenof($tree))))))
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              perlRecurList(cdr(childrenof($tree)), $indent)
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf(")")
              ;

            };

          };

        };

      };

    };

  };

}


#Building function perlIf from line: 93

sub perlIf {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("perlIf at q/perl.qon:93\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("if ( ")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  perlExpression(car(first(childrenof($node))), 0)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf(") {")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  perlBody(second(childrenof($node)), add1($indent))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("} else {")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  perlBody(third(childrenof($node)), add1($indent))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("}")
  ;

}


#Building function perlSetStruct from line: 106

sub perlSetStruct {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("perlSetStruct at q/perl.qon:106\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s->{%s} = ", dollar(), stringify(first(codeof($node))), stringify(second(codeof($node))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  perlExpression(childrenof($node), $indent)
  ;

}


#Building function perlGetStruct from line: 113

sub perlGetStruct {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("perlGetStruct at q/perl.qon:113\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s->{%s}", dollar(), stringify(first(codeof($node))), stringify(second(codeof($node))))
  ;

}


#Building function perlSet from line: 118

sub perlSet {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("perlSet at q/perl.qon:118\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s = ", dollar(), stringify(first(codeof($node))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  perlExpression(childrenof($node), $indent)
  ;

}


#Building function assertNode from line: 124

sub assertNode {
  my $node = shift;

  
if ($globalTrace) { printf("assertNode at q/perl.qon:124\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNode($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    panic("Not a node!")
    ;

  };

}


#Building function perlStatement from line: 131

sub perlStatement {
  my $node = shift;
my $indent = shift;

  my $functionName = undef;

if ($globalTrace) { printf("perlStatement at q/perl.qon:131\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  assertNode($node)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(boxString("setter"), subnameof($node))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlSet($node, $indent)
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalBox(boxString("structSetter"), subnameof($node))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      perlSetStruct($node, $indent)
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalBox(boxString("if"), subnameof($node))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        perlIf($node, $indent)
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalBox(boxString("returnvoid"), subnameof($node))) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          $functionName = functionNameof($node);
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf("\n#Returnvoid\n")
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          newLine($indent)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          newLine($indent)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf("return")
          ;

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalBox(boxString("return"), subnameof($node))) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            $functionName = functionNameof($node);
            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            if ( inList($functionName, noStackTrace())) {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf("")
              ;

            } else {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf("\n#standard return: %s\n", stringify($functionName))
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              newLine($indent)
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf("%s%s%s", "if (", dollar(), "globalTrace) {printf(\"Leaving \\n\")}\n")
              ;

            };
            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            newLine($indent)
            ;
            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            perlExpression(childrenof($node), $indent)
            ;

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            if ( inList($functionName, noStackTrace())) {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf("")
              ;

            } else {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf("\n#standard expression\n")
              ;

            };
            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            newLine($indent)
            ;
            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            perlExpression(childrenof($node), $indent)
            ;
            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            newLine($indent)
            ;

          };

        };

      };

    };

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf(";\n")
  ;

}


#Building function perlBody from line: 180

sub perlBody {
  my $tree = shift;
my $indent = shift;

  
if ($globalTrace) { printf("perlBody at q/perl.qon:180\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent($indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s%s%s", "if (", dollar(), "globalStepTrace) {printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__)}\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlStatement(car($tree), $indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlBody(cdr($tree), $indent)
    ;

  };

}


#Building function perlDeclarations from line: 190

sub perlDeclarations {
  my $decls = shift;
my $indent = shift;

  my $decl = undef;

if ($globalTrace) { printf("perlDeclarations at q/perl.qon:190\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($decls)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $decl = car($decls);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("my %s%s = ", dollar(), stringify(second($decl)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    display(perlConstMap(third($decl)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(";\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlDeclarations(cdr($decls), $indent)
    ;

  };

}


#Building function perlFunction from line: 201

sub perlFunction {
  my $node = shift;

  my $name = undef;

if ($globalTrace) { printf("perlFunction at q/perl.qon:201\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $name = subnameof($node);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\n\n#Building function %s from line: %s", stringify($name), stringify(getTag($name, boxString("line"))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine(0)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    newLine(0)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("sub %s", stringify(subnameof($node)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(" {")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    newLine(1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlFunctionArgs(cdr(assoc("intype", cdr($node))))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    newLine(1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlDeclarations(declarationsof($node), 1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\nif (%sglobalTrace) { printf(\"%s at %s:%s\\n\") }\n", dollar(), stringify(subnameof($node)), stringify(getTag($name, boxString("filename"))), stringify(getTag($name, boxString("line"))))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( inList($name, noStackTrace())) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlBody(childrenof($node), 1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( inList($name, noStackTrace())) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n}\n")
    ;

  };

}


#Building function perlForwardDeclaration from line: 233

sub perlForwardDeclaration {
  my $node = shift;

  
if ($globalTrace) { printf("perlForwardDeclaration at q/perl.qon:233\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\nsub %s", stringify(subnameof($node)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(";")
    ;

  };

}


#Building function perlForwardDeclarations from line: 243

sub perlForwardDeclarations {
  my $tree = shift;

  
if ($globalTrace) { printf("perlForwardDeclarations at q/perl.qon:243\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlForwardDeclaration(car($tree))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlForwardDeclarations(cdr($tree))
    ;

  };

}


#Building function perlFunctions from line: 251

sub perlFunctions {
  my $tree = shift;

  
if ($globalTrace) { printf("perlFunctions at q/perl.qon:251\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlFunction(car($tree))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlFunctions(cdr($tree))
    ;

  };

}


#Building function dollar from line: 258

sub dollar {
  
  
if ($globalTrace) { printf("dollar at q/perl.qon:258\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: dollar

  if ($globalTrace) {printf("Leaving \n")}

  return(character(36));

}


#Building function atSym from line: 261

sub atSym {
  
  
if ($globalTrace) { printf("atSym at q/perl.qon:261\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: atSym

  if ($globalTrace) {printf("Leaving \n")}

  return(character(64));

}


#Building function perlIncludes from line: 265

sub perlIncludes {
  my $nodes = shift;

  
if ($globalTrace) { printf("perlIncludes at q/perl.qon:265\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s\n", "use strict;")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s", "my ", dollar(), "caller;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s", "my ", dollar(), "releaseMode;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s\n", "use Carp;")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  dollar()
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s\n", "use Carp::Always;")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s%s%s\n", "sub greaterthan { ", dollar(), "_[0] > ", dollar(), "_[1] };")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s\n", "sub qlog { warn ", "@", "_ };")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s%s%s\n", "sub mult { ", dollar(), "_[0] * ", dollar(), "_[1] };")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s%s%s\n", "sub multf { ", dollar(), "_[0] * ", dollar(), "_[1] };")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s%s%s\n", "sub greaterthanf { ", dollar(), "_[0] > ", dollar(), "_[1] };")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s%s%s\n", "sub equalString { ", dollar(), "_[0] eq ", dollar(), "_[1] };")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("sub read_file { my %sfile = shift; %sfile || die \"Empty file name!!!\"; open my %sfh, '<', %sfile or die; local %s/ = undef; my %scont = <%sfh>; close %sfh; return %scont; }; \n", dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar())
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("sub write_file {my %sfile = shift; my %sdata = shift; %sfile || die \"Empty file name!!!\"; open my %sfh, '>', %sfile or die; print %sfh %sdata; close %sfh; } \n", dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar())
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s%s%s\n", "sub stringConcatenate { ", dollar(), "_[0] . ", dollar(), "_[1]}")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s%s%s\n", "sub subtract { ", dollar(), "_[0] - ", dollar(), "_[1]}")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s%s%s\n", "sub subf { ", dollar(), "_[0] - ", dollar(), "_[1]}")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s%s%s\n", "sub andBool { ", dollar(), "_[0] && ", dollar(), "_[1]}")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s%s%s\n", "sub equal { ", dollar(), "_[0] == ", dollar(), "_[1]}")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s%s%s\n", "sub panic { carp ", atSym(), "_; die \"", atSym(), "_\"}")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("sub intToString { return %s_[0]}\n", dollar())
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("sub character { return chr(%s_[0])}\n", dollar())
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s%s%s%s%s%s%s\n", "sub getStringArray { my ", dollar(), "index = shift; my ", dollar(), "arr = shift; return ", dollar(), "arr->[", dollar(), "index]}")
  ;

}


#Building function perlTypeDecl from line: 301

sub perlTypeDecl {
  my $l = shift;

  
if ($globalTrace) { printf("perlTypeDecl at q/perl.qon:301\n") }

}


#Building function perlStructComponents from line: 306

sub perlStructComponents {
  my $node = shift;

  
if ($globalTrace) { printf("perlStructComponents at q/perl.qon:306\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlTypeDecl(car($node))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlStructComponents(cdr($node))
    ;

  };

}


#Building function perlStruct from line: 312

sub perlStruct {
  my $node = shift;

  
if ($globalTrace) { printf("perlStruct at q/perl.qon:312\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  perlStructComponents(cdr(car($node)))
  ;

}


#Building function perlTypeMap from line: 315

sub perlTypeMap {
  my $aSym = shift;

  my $symMap = undef;

if ($globalTrace) { printf("perlTypeMap at q/perl.qon:315\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), $undef));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( truthy(assoc(stringify($aSym), $symMap))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: perlTypeMap

    if ($globalTrace) {printf("Leaving \n")}

    return(cdr(assoc(stringify($aSym), $symMap)));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: perlTypeMap

    if ($globalTrace) {printf("Leaving \n")}

    return($aSym);

  };

}


#Building function perlConstMap from line: 327

sub perlConstMap {
  my $aSym = shift;

  my $symMap = undef;

if ($globalTrace) { printf("perlConstMap at q/perl.qon:327\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("symbol", boxType($aSym))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $symMap = alistCons(boxSymbol("false"), boxSymbol("0"), alistCons(boxSymbol("nil"), boxSymbol("undef"), $undef));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: perlConstMap

    if ($globalTrace) {printf("Leaving \n")}

    return(cdr(assocFail(stringify($aSym), $symMap, $aSym)));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: perlConstMap

    if ($globalTrace) {printf("Leaving \n")}

    return($aSym);

  };

}


#Building function perlFuncMap from line: 337

sub perlFuncMap {
  my $aSym = shift;

  my $symMap = undef;

if ($globalTrace) { printf("perlFuncMap at q/perl.qon:337\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("symbol", boxType($aSym))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $symMap = alistCons(boxSymbol("sub"), boxSymbol("subtract"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("substr"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("length"), alistCons(boxSymbol("nil"), boxSymbol("undef"), $undef))))))));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: perlFuncMap

    if ($globalTrace) {printf("Leaving \n")}

    return(cdr(assocFail(stringify($aSym), $symMap, $aSym)));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: perlFuncMap

    if ($globalTrace) {printf("Leaving \n")}

    return($aSym);

  };

}


#Building function perlType from line: 354

sub perlType {
  my $node = shift;

  
if ($globalTrace) { printf("perlType at q/perl.qon:354\n") }

}


#Building function perlTypes from line: 359

sub perlTypes {
  my $nodes = shift;

  
if ($globalTrace) { printf("perlTypes at q/perl.qon:359\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($nodes)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlType(car($nodes))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlTypes(cdr($nodes))
    ;

  };

}


#Building function perlFunctionArgs from line: 365

sub perlFunctionArgs {
  my $tree = shift;

  
if ($globalTrace) { printf("perlFunctionArgs at q/perl.qon:365\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s%s", "my ", dollar())
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    display(second($tree))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(" = shift;\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    perlFunctionArgs(cddr($tree))
    ;

  };

}


#Building function perlCompile from line: 375

sub perlCompile {
  my $filename = shift;

  my $programStr = "";
my $tree = undef;
my $program = undef;

if ($globalTrace) { printf("perlCompile at q/perl.qon:375\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $programStr = read_file($filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = readSexpr($programStr, $filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $program = alistCons(boxString("includes"), astIncludes(first($tree)), alistCons(boxString("types"), astTypes(second($tree)), alistCons(boxString("functions"), astFunctions(third($tree)), $undef)));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $program = mergeIncludes($program);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  perlIncludes(cdr(assoc("includes", $program)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  perlTypes(childrenof(cdr(assoc("types", $program))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("use strict;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("use Carp;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("use Data::Dumper;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s", "my ", dollar(), "globalStackTrace = undef;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s", "my ", dollar(), "globalTrace = undef;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s", "my ", dollar(), "globalStepTrace = undef;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s", "my ", dollar(), "globalArgs = undef;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s", "my ", dollar(), "globalArgsCount = undef;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s\n", "my ", dollar(), "true = 1;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s", "my ", dollar(), "false = 0;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s", "my ", dollar(), "undef;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s", "\nsub isNil {\n    return !defined(", dollar(), "_[0]);\n}\n\n\n#Forward declarations\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  perlForwardDeclarations(cdr(assoc("children", cdr(cdr(assoc("functions", $program))))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\n\n#End forward declarations\n\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  perlFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", $program))))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf(";\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s%s", dollar(), "globalArgs = [ 1, ", atSym(), "ARGV];")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s%s%s", dollar(), "globalArgsCount = scalar(", atSym(), "ARGV)+1;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("start();")
  ;

}


#Building function ansiFunctionArgs from line: 3

sub ansiFunctionArgs {
  my $tree = shift;

  
if ($globalTrace) { printf("ansiFunctionArgs at q/ansi.qon:3\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    display(ansiTypeMap(first($tree)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(" ")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    display(second($tree))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil(cddr($tree))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf(",")
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiFunctionArgs(cddr($tree))
    ;

  };

}


#Building function ansiLeaf from line: 14

sub ansiLeaf {
  my $thisNode = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansiLeaf at q/ansi.qon:14\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  display(ansiFuncMap(codeof($thisNode)))
  ;

}


#Building function ansiStructGetterExpression from line: 17

sub ansiStructGetterExpression {
  my $thisNode = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansiStructGetterExpression at q/ansi.qon:17\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(boxString("structGetter"), subnameof($thisNode))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiGetStruct($thisNode, $indent)
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiLeaf($thisNode, $indent)
    ;

  };

}


#Building function ansiExpression from line: 23

sub ansiExpression {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansiExpression at q/ansi.qon:23\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isLeaf($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    display(ansiFuncMap(codeof($node)))
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiSubExpression($node, $indent)
    ;

  };

}


#Building function ansiRecurList from line: 29

sub ansiRecurList {
  my $expr = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansiRecurList at q/ansi.qon:29\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($expr)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiExpression(car($expr), $indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil(cdr($expr))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf(", ")
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      ansiRecurList(cdr($expr), $indent)
      ;

    };

  };

}


#Building function ansiSubExpression from line: 41

sub ansiSubExpression {
  my $tree = shift;
my $indent = shift;

  my $thing = undef;

if ($globalTrace) { printf("ansiSubExpression at q/ansi.qon:41\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNode(childrenof($tree))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      ansiSubExpression(childrenof($tree), $indent)
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( isLeaf($tree)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        display(ansiFuncMap(codeof($tree)))
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equal(1, listLength(childrenof($tree)))) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          display(codeof(car(childrenof($tree))))
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalBox(boxString("return"), codeof(car(childrenof($tree))))) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("")
            ;

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("()")
            ;

          };

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          $thing = codeof(car(childrenof($tree)));
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalBox(boxSymbol("get-struct"), $thing)) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("%s->%s", stringify(codeof(second(childrenof($tree)))), stringify(codeof(third(childrenof($tree)))))
            ;

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            if ( equalBox(boxSymbol("new"), $thing)) {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf("malloc(sizeof(%s))", stringify(codeof(third(childrenof($tree)))))
              ;

            } else {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf("%s(", stringify(ansiFuncMap(codeof(car(childrenof($tree))))))
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              ansiRecurList(cdr(childrenof($tree)), $indent)
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf(")")
              ;

            };

          };

        };

      };

    };

  };

}


#Building function ansiIf from line: 81

sub ansiIf {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansiIf at q/ansi.qon:81\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("if ( ")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansiExpression(car(first(childrenof($node))), 0)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf(") {")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansiBody(second(childrenof($node)), add1($indent))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("} else {")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansiBody(third(childrenof($node)), add1($indent))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("}")
  ;

}


#Building function ansiSetStruct from line: 94

sub ansiSetStruct {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansiSetStruct at q/ansi.qon:94\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s->%s = ", stringify(first(codeof($node))), stringify(second(codeof($node))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansiExpression(childrenof($node), $indent)
  ;

}


#Building function ansiGetStruct from line: 103

sub ansiGetStruct {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansiGetStruct at q/ansi.qon:103\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s->%s", stringify(first(codeof($node))), stringify(second(codeof($node))))
  ;

}


#Building function ansiSet from line: 111

sub ansiSet {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansiSet at q/ansi.qon:111\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s = ", stringify(first(codeof($node))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansiExpression(childrenof($node), $indent)
  ;

}


#Building function ansiStatement from line: 117

sub ansiStatement {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansiStatement at q/ansi.qon:117\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(boxString("setter"), subnameof($node))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiSet($node, $indent)
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalBox(boxString("structSetter"), subnameof($node))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      ansiSetStruct($node, $indent)
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalBox(boxString("if"), subnameof($node))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        ansiIf($node, $indent)
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalBox(boxString("returnvoid"), subnameof($node))) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          newLine($indent)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf("return")
          ;

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          newLine($indent)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          ansiExpression(childrenof($node), $indent)
          ;

        };

      };

    };

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf(";\n")
  ;

}


#Building function ansiBody from line: 135

sub ansiBody {
  my $tree = shift;
my $indent = shift;

  my $code = undef;

if ($globalTrace) { printf("ansiBody at q/ansi.qon:135\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $code = codeof(car($tree));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil($code)) {
    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      $code = car(codeof(car($tree)));
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("\n")
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printIndent($indent)
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("if (globalTrace)   snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail($code, boxString("filename"), boxString("Unknown"))), stringify(getTagFail($code, boxString("line"), boxString("Unknown"))))
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent($indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiStatement(car($tree), $indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiBody(cdr($tree), $indent)
    ;

  };

}


#Building function ansiDeclarations from line: 156

sub ansiDeclarations {
  my $decls = shift;
my $indent = shift;

  my $decl = undef;

if ($globalTrace) { printf("ansiDeclarations at q/ansi.qon:156\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($decls)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $decl = car($decls);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s %s = ", stringify(ansiTypeMap(first($decl))), stringify(second($decl)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    display(ansiFuncMap(third($decl)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(";\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiDeclarations(cdr($decls), $indent)
    ;

  };

}


#Building function ansiFunction from line: 170

sub ansiFunction {
  my $node = shift;

  my $name = undef;

if ($globalTrace) { printf("ansiFunction at q/ansi.qon:170\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $name = subnameof($node);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\n\n//Building function %s from line: %s", stringify($name), stringify(getTag($name, boxString("line"))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine(0)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    newLine(0)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s %s(", stringify(ansiTypeMap(cdr(assoc("outtype", cdr($node))))), stringify(subnameof($node)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiFunctionArgs(cdr(assoc("intype", cdr($node))))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(") {")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    newLine(1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiDeclarations(declarationsof($node), 1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( inList(toStr($name), noStackTrace())) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("\nif (globalTrace)\n    fprintf(stderr, \"%s at %s:%s (%%s)\\n\", caller);\n", stringify($name), stringify(getTag($name, boxString("filename"))), stringify(getTag($name, boxString("line"))))
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( inList(toStr($name), noStackTrace())) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {
    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiBody(childrenof($node), 1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( inList(toStr($name), noStackTrace())) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("\nif (globalTrace)\n    fprintf(stderr, \"Leaving %s\\n\");\n", stringify($name))
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n}\n")
    ;

  };

}


#Building function ansiForwardDeclaration from line: 204

sub ansiForwardDeclaration {
  my $node = shift;

  
if ($globalTrace) { printf("ansiForwardDeclaration at q/ansi.qon:204\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n%s %s(", stringify(ansiTypeMap(cdr(assoc("outtype", cdr($node))))), stringify(subnameof($node)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiFunctionArgs(cdr(assoc("intype", cdr($node))))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(");")
    ;

  };

}


#Building function ansiForwardDeclarations from line: 216

sub ansiForwardDeclarations {
  my $tree = shift;

  
if ($globalTrace) { printf("ansiForwardDeclarations at q/ansi.qon:216\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiForwardDeclaration(car($tree))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiForwardDeclarations(cdr($tree))
    ;

  };

}


#Building function ansiFunctions from line: 224

sub ansiFunctions {
  my $tree = shift;

  
if ($globalTrace) { printf("ansiFunctions at q/ansi.qon:224\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiFunction(car($tree))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiFunctions(cdr($tree))
    ;

  };

}


#Building function ansiIncludes from line: 229

sub ansiIncludes {
  my $nodes = shift;

  
if ($globalTrace) { printf("ansiIncludes at q/ansi.qon:229\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\nconst char* getEnv(char* key){return getenv(key);}\n void panic(char* s){abort();exit(1);}\nint not(int a){return !a;}\nint sub(int a, int b) { return a - b; }\nfloat mult(int a, int b) { return a * b; }\nint greaterthan(int a, int b) { return a > b; }\nfloat subf(float a, float b) { return a - b; }\nfloat multf(float a, float b) { return a * b; }\nint greaterthanf(float a, float b) { return a > b; }\nint equal(int a, int b) { return a == b; }\nint equalString(char* a, char* b) { return !strcmp(a,b); }\nint andBool(int a, int b) { return a && b;}\nint string_length(char* s) { return strlen(s);}\nchar* setSubString(char* target, int start,char *source){target[start]=source[0]; return target;}\nchar* sub_string(char* s, int start, int length) {\nchar* substr = calloc(length+1, 1);\nstrncpy(substr, s+start, length);\nreturn substr;\n}\n\n\n\nchar* stringConcatenate(char* a, char* b) {\nint len = strlen(a) + strlen(b) + 1;\nchar* target = calloc(len,1);\nstrncat(target, a, len);\nstrncat(target, b, len);\nreturn target;\n}\n\nchar* intToString(int a) {\nint len = 100;\nchar* target = calloc(len,1);\nsnprintf(target, 99, \"%d\", a);\nreturn target;\n}\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\nvoid * gc_malloc( unsigned int size ) {\nreturn malloc(size);\n}\n\nint* makeArray(int length) {\n    int * array = gc_malloc(length*sizeof(int));\n    return array;\n}\n\nint at(int* arr, int index) {\n  return arr[index];\n}\n\nvoid setAt(int* array, int index, int value) {\n    array[index] = value;\n}\n\nchar * read_file(char * filename) {\nchar * buffer = 0;\nlong length;\nFILE * f = fopen (filename, \"rb\");\n\nif (f)\n{\n  fseek (f, 0, SEEK_END);\n  length = ftell (f);\n  fseek (f, 0, SEEK_SET);\n  buffer = calloc (length+1,1);\n  if (buffer == NULL) {\n  printf(\"Malloc failed!\\n\");\n  exit(1);\n}\n  if (buffer)\n  {\n    fread (buffer, 1, length, f);\n  }\n  fclose (f);\n}\nreturn buffer;\n}\n\n\nvoid write_file (char * filename, char * data) {\nFILE *f = fopen(filename, \"w\");\nif (f == NULL)\n{\n    printf(\"Error opening file!\");\n    exit(1);\n}\n\nfprintf(f, \"%s\", data);\n\nfclose(f);\n}\n\nchar* getStringArray(int index, char** strs) {\nreturn strs[index];\n}\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\n\nint main( int argc, char *argv[] )  {\n  globalArgs = argv;\n  globalArgsCount = argc;\n  caller=calloc(1024,1);\n\n  return start();\n\n}\n\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "char * character(int num) { char *string = malloc(2); if (!string) return 0; string[0] = num; string[1] = 0; return string; }")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "bool nand(bool a, bool b) { return !(a&&b); }\n//End include block\n")
  ;

}


#Building function ansiTypeDecl from line: 239

sub ansiTypeDecl {
  my $l = shift;

  
if ($globalTrace) { printf("ansiTypeDecl at q/ansi.qon:239\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan(listLength($l), 2)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent(1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s %s %s;\n", stringify(second($l)), stringify(ansiTypeMap(listLast($l))), stringify(first($l)))
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent(1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s %s;\n", stringify(ansiTypeMap(listLast($l))), stringify(car($l)))
    ;

  };

}


#Building function ansiStructComponents from line: 256

sub ansiStructComponents {
  my $node = shift;

  
if ($globalTrace) { printf("ansiStructComponents at q/ansi.qon:256\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiTypeDecl(car($node))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiStructComponents(cdr($node))
    ;

  };

}


#Building function ansiStruct from line: 262

sub ansiStruct {
  my $node = shift;

  
if ($globalTrace) { printf("ansiStruct at q/ansi.qon:262\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansiStructComponents(cdr(car($node)))
  ;

}


#Building function ansiTypeMap from line: 265

sub ansiTypeMap {
  my $aSym = shift;

  my $symMap = undef;

if ($globalTrace) { printf("ansiTypeMap at q/ansi.qon:265\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), $undef));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( truthy(assoc(stringify($aSym), $symMap))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ansiTypeMap

    if ($globalTrace) {printf("Leaving \n")}

    return(cdr(assoc(stringify($aSym), $symMap)));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ansiTypeMap

    if ($globalTrace) {printf("Leaving \n")}

    return($aSym);

  };

}


#Building function ansiFuncMap from line: 277

sub ansiFuncMap {
  my $aSym = shift;

  my $symMap = undef;

if ($globalTrace) { printf("ansiFuncMap at q/ansi.qon:277\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("symbol", boxType($aSym))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), $undef)))))));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( truthy(assoc(stringify($aSym), $symMap))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ansiFuncMap

      if ($globalTrace) {printf("Leaving \n")}

      return(cdr(assoc(stringify($aSym), $symMap)));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ansiFuncMap

      if ($globalTrace) {printf("Leaving \n")}

      return($aSym);

    };

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ansiFuncMap

    if ($globalTrace) {printf("Leaving \n")}

    return($aSym);

  };

}


#Building function ansiType from line: 308

sub ansiType {
  my $node = shift;

  
if ($globalTrace) { printf("ansiType at q/ansi.qon:308\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(subnameof($node), boxString("struct"))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\ntypedef struct %s {\n", stringify(first(codeof($node))))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiStruct(cdr(codeof($node)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n} %s;\n", stringify(first(codeof($node))))
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("typedef ")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiTypeDecl(codeof($node))
    ;

  };

}


#Building function ansiTypes from line: 318

sub ansiTypes {
  my $nodes = shift;

  
if ($globalTrace) { printf("ansiTypes at q/ansi.qon:318\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($nodes)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiType(car($nodes))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansiTypes(cdr($nodes))
    ;

  };

}


#Building function ansiCompile from line: 328

sub ansiCompile {
  my $filename = shift;

  my $programStr = "";
my $tree = undef;
my $program = undef;

if ($globalTrace) { printf("ansiCompile at q/ansi.qon:328\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("//Scanning file...%s\n", $filename)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $programStr = read_file($filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("//Building sexpr\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = readSexpr($programStr, $filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrowalk($tree);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), $undef)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("//Building AST\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $program = alistCons(boxString("includes"), astIncludes(first($tree)), alistCons(boxString("types"), astTypes(second($tree)), alistCons(boxString("functions"), astFunctions(third($tree)), $undef)));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("//Merging ASTs\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $program = mergeIncludes($program);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("//Printing program\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansiIncludes(cdr(assoc("includes", $program)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansiTypes(childrenof(cdr(assoc("types", $program))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("Box* globalStackTrace = NULL;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansiForwardDeclarations(cdr(assoc("children", cdr(cdr(assoc("functions", $program))))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\n\n//End forward declarations\n\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansiFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", $program))))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\n")
  ;

}


#Building function ansi2displays from line: 5

sub ansi2displays {
  my $s = shift;

  
if ($globalTrace) { printf("ansi2displays at q/ansi2.qon:5\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", $s)
  ;

}


#Building function ansi2FunctionArgs from line: 11

sub ansi2FunctionArgs {
  my $tree = shift;

  
if ($globalTrace) { printf("ansi2FunctionArgs at q/ansi2.qon:11\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalString(stringify(first($tree)), "...")) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("...")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      display(ansi2TypeMap(first($tree)))
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      ansi2displays(" ")
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      display(second($tree))
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil(cddr($tree))) {
    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      ansi2displays(", ")
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2FunctionArgs(cddr($tree))
    ;

  };

}


#Building function ansi2Expression from line: 28

sub ansi2Expression {
  my $tree = shift;
my $indent = shift;

  my $thing = undef;

if ($globalTrace) { printf("ansi2Expression at q/ansi2.qon:28\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isList($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equal(1, listLength($tree))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      display(car($tree))
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalBox(boxString("return"), car($tree))) {
      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        ansi2displays("()")
        ;

      };

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      $thing = first($tree);
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalBox(boxSymbol("get-struct"), $thing)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printf("%s->%s", stringify(second($tree)), stringify(third($tree)))
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalBox(boxSymbol("new"), $thing)) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf("malloc(sizeof(%s))", stringify(third($tree)))
          ;

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalBox(boxSymbol("passthrough"), $thing)) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("%s", stringify(second($tree)))
            ;

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            if ( equalBox(boxSymbol("binop"), $thing)) {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf("(")
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              ansi2Expression(third($tree), $indent)
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf(" %s ", stringify(second($tree)))
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              ansi2Expression(fourth($tree), $indent)
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf(")")
              ;

            } else {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf("%s(", stringify(ansi2FuncMap(car($tree))))
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              ansi2RecurList(cdr($tree), $indent)
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf(")")
              ;

            };

          };

        };

      };

    };

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    display(ansi2FuncMap($tree))
    ;

  };

}


#Building function ansi2RecurList from line: 98

sub ansi2RecurList {
  my $expr = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansi2RecurList at q/ansi2.qon:98\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($expr)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2Expression(car($expr), $indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil(cdr($expr))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      ansi2displays("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      ansi2displays(", ")
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      ansi2RecurList(cdr($expr), $indent)
      ;

    };

  };

}


#Building function ansi2If from line: 115

sub ansi2If {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansi2If at q/ansi2.qon:115\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi2displays("if ( ")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi2Expression(second($node), 0)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi2displays(") {")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi2Body(cdr(third($node)), add1($indent))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi2displays("} else {")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi2Body(cdr(fourth($node)), add1($indent))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi2displays("}")
  ;

}


#Building function ansi2SetStruct from line: 128

sub ansi2SetStruct {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansi2SetStruct at q/ansi2.qon:128\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s->%s = ", stringify(second($node)), stringify(third($node)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi2Expression(fourth($node), $indent)
  ;

}


#Building function ansi2GetStruct from line: 137

sub ansi2GetStruct {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansi2GetStruct at q/ansi2.qon:137\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s->%s", stringify(first($node)), stringify(second($node)))
  ;

}


#Building function ansi2Set from line: 145

sub ansi2Set {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansi2Set at q/ansi2.qon:145\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi2Expression(first(cdr($node)), $indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf(" = ")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi2Expression(third($node), $indent)
  ;

}


#Building function ansi2Return from line: 152

sub ansi2Return {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansi2Return at q/ansi2.qon:152\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equal(listLength($node), 1)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2displays("return;")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2displays("return ")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2Expression(cadr($node), $indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2displays(";")
    ;

  };

}


#Building function ansi2Statement from line: 163

sub ansi2Statement {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansi2Statement at q/ansi2.qon:163\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(boxString("set"), first($node))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2Set($node, $indent)
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalBox(boxString("set-struct"), first($node))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      ansi2SetStruct($node, $indent)
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalBox(boxString("if"), first($node))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        ansi2If($node, $indent)
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalBox(boxString("return"), first($node))) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          ansi2Return($node, $indent)
          ;

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          newLine($indent)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          ansi2Expression($node, $indent)
          ;

        };

      };

    };

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi2displays(";\n")
  ;

}


#Building function ansi2Body from line: 181

sub ansi2Body {
  my $tree = shift;
my $indent = shift;

  my $code = undef;

if ($globalTrace) { printf("ansi2Body at q/ansi2.qon:181\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $code = $tree;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil($code)) {
    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      $code = car($tree);
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("\nif (globalTrace)\n    snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail(car($code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), stringify(getTagFail(car($code), boxString("line"), boxString("Line missing"))))
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent($indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2Statement($code, $indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2Body(cdr($tree), $indent)
    ;

  };

}


#Building function ansi2Declarations from line: 199

sub ansi2Declarations {
  my $decls = shift;
my $indent = shift;

  my $decl = undef;

if ($globalTrace) { printf("ansi2Declarations at q/ansi2.qon:199\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($decls)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $decl = car($decls);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s %s = ", stringify(ansi2TypeMap(first($decl))), stringify(second($decl)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2Expression(third($decl), $indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(";\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2Declarations(cdr($decls), $indent)
    ;

  };

}


#Building function ansi2Function from line: 213

sub ansi2Function {
  my $node = shift;

  my $name = undef;

if ($globalTrace) { printf("ansi2Function at q/ansi2.qon:213\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $name = second($node);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\n\n//Building function %s from line: %s", stringify($name), stringify(getTag($name, boxString("line"))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine(0)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    newLine(0)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s %s(", stringify(ansi2TypeMap(first($node))), stringify(second($node)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2FunctionArgs(third($node))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(") {")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    newLine(1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2Declarations(cdr(fourth($node)), 1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( inList(toStr($name), noStackTrace())) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("\nif (globalTrace)\n    printf(\"%s at %s:%s (%%s)\\n\", caller);\n", stringify($name), stringify(getTag($name, boxString("filename"))), stringify(getTag($name, boxString("line"))))
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( inList(toStr($name), noStackTrace())) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {
    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2Body(cdr(fifth($node)), 1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( inList(toStr($name), noStackTrace())) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("\nif (globalTrace)\n    printf(\"Leaving %s\\n\");\n", stringify($name))
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n}\n")
    ;

  };

}


#Building function ansi2ForwardDeclaration from line: 248

sub ansi2ForwardDeclaration {
  my $node = shift;

  
if ($globalTrace) { printf("ansi2ForwardDeclaration at q/ansi2.qon:248\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n%s %s(", stringify(ansi2TypeMap(first($node))), stringify(second($node)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2FunctionArgs(third($node))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2displays(");")
    ;

  };

}


#Building function ansi2ForwardDeclarations from line: 258

sub ansi2ForwardDeclarations {
  my $tree = shift;

  
if ($globalTrace) { printf("ansi2ForwardDeclarations at q/ansi2.qon:258\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2ForwardDeclaration(car($tree))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2ForwardDeclarations(cdr($tree))
    ;

  };

}


#Building function ansi2Functions from line: 264

sub ansi2Functions {
  my $tree = shift;

  
if ($globalTrace) { printf("ansi2Functions at q/ansi2.qon:264\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2Function(car($tree))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2Functions(cdr($tree))
    ;

  };

}


#Building function ansi2Includes from line: 270

sub ansi2Includes {
  my $nodes = shift;

  
if ($globalTrace) { printf("ansi2Includes at q/ansi2.qon:270\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\nconst char* getEnv(char* key){return getenv(key);}\n void panic(char* s){abort();exit(1);}\nint sub(int a, int b) { return a - b; }\nfloat mult(int a, int b) { return a * b; }\nint greaterthan(int a, int b) { return a > b; }\nfloat subf(float a, float b) { return a - b; }\nfloat multf(float a, float b) { return a * b; }\nint greaterthanf(float a, float b) { return a > b; }\nint equal(int a, int b) { return a == b; }\nint equalString(char* a, char* b) { return !strcmp(a,b); }\nint andBool(int a, int b) { return a && b;}\nint string_length(char* s) { return strlen(s);}\nchar* setSubString(char* target, int start,char *source){target[start]=source[0]; return target;}\nchar* sub_string(char* s, int start, int length) {\nchar* substr = calloc(length+1, 1);\nstrncpy(substr, s+start, length);\nreturn substr;\n}\n\n\n\nchar* stringConcatenate(char* a, char* b) {\nint len = strlen(a) + strlen(b) + 1;\nchar* target = calloc(len,1);\nstrncat(target, a, len);\nstrncat(target, b, len);\nreturn target;\n}\n\nchar* intToString(int a) {\nint len = 100;\nchar* target = calloc(len,1);\nsnprintf(target, 99, \"%d\", a);\nreturn target;\n}\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\nvoid * gc_malloc( unsigned int size ) {\nreturn malloc( size);\n}\n\nint* makeArray(int length) {\n    int * array = gc_malloc(length*sizeof(int));\n    return array;\n}\n\nint at(int* arr, int index) {\n  return arr[index];\n}\n\nvoid setAt(int* array, int index, int value) {\n    array[index] = value;\n}\n\nchar * read_file(char * filename) {\nchar * buffer = 0;\nlong length;\nFILE * f = fopen (filename, \"rb\");\n\nif (f)\n{\n  fseek (f, 0, SEEK_END);\n  length = ftell (f);\n  fseek (f, 0, SEEK_SET);\n  buffer = calloc (length+1,1);\n  if (buffer == NULL) {\n  printf(\"Malloc failed!\\n\");\n  exit(1);\n}\n  if (buffer)\n  {\n    fread (buffer, 1, length, f);\n  }\n  fclose (f);\n}\nreturn buffer;\n}\n\n\nvoid write_file (char * filename, char * data) {\nFILE *f = fopen(filename, \"w\");\nif (f == NULL)\n{\n    printf(\"Error opening file!\");\n    exit(1);\n}\n\nfprintf(f, \"%s\", data);\n\nfclose(f);\n}\n\nchar* getStringArray(int index, char** strs) {\nreturn strs[index];\n}\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\n\nint main( int argc, char *argv[] )  {\n  globalArgs = argv;\n  globalArgsCount = argc;\n  caller=calloc(1024,1);\n\n  return start();\n\n}\n\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "char * character(int num) { char *string = malloc(2); if (!string) return 0; string[0] = num; string[1] = 0; return string; }")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "bool nand(bool a, bool b) { return !(a&&b); }\n//End include block\n")
  ;

}


#Building function ansi2TypeDecl from line: 279

sub ansi2TypeDecl {
  my $l = shift;

  
if ($globalTrace) { printf("ansi2TypeDecl at q/ansi2.qon:279\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan(listLength($l), 2)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent(1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s %s %s;\n", stringify(second($l)), stringify(ansi2TypeMap(listLast($l))), stringify(first($l)))
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent(1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s %s;\n", stringify(ansi2TypeMap(listLast($l))), stringify(car($l)))
    ;

  };

}


#Building function ansi2StructComponents from line: 296

sub ansi2StructComponents {
  my $node = shift;

  
if ($globalTrace) { printf("ansi2StructComponents at q/ansi2.qon:296\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2TypeDecl(car($node))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2StructComponents(cdr($node))
    ;

  };

}


#Building function ansi2Struct from line: 302

sub ansi2Struct {
  my $node = shift;

  
if ($globalTrace) { printf("ansi2Struct at q/ansi2.qon:302\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi2StructComponents(cdr($node))
  ;

}


#Building function ansi2TypeMap from line: 305

sub ansi2TypeMap {
  my $aSym = shift;

  my $symMap = undef;

if ($globalTrace) { printf("ansi2TypeMap at q/ansi2.qon:305\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), $undef));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( truthy(assoc(stringify($aSym), $symMap))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ansi2TypeMap

    if ($globalTrace) {printf("Leaving \n")}

    return(cdr(assoc(stringify($aSym), $symMap)));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ansi2TypeMap

    if ($globalTrace) {printf("Leaving \n")}

    return($aSym);

  };

}


#Building function ansi2FuncMap from line: 317

sub ansi2FuncMap {
  my $aSym = shift;

  my $symMap = undef;

if ($globalTrace) { printf("ansi2FuncMap at q/ansi2.qon:317\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("symbol", boxType($aSym))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), $undef)))))));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( truthy(assoc(stringify($aSym), $symMap))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ansi2FuncMap

      if ($globalTrace) {printf("Leaving \n")}

      return(cdr(assoc(stringify($aSym), $symMap)));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ansi2FuncMap

      if ($globalTrace) {printf("Leaving \n")}

      return($aSym);

    };

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ansi2FuncMap

    if ($globalTrace) {printf("Leaving \n")}

    return($aSym);

  };

}


#Building function ansi2Type from line: 348

sub ansi2Type {
  my $node = shift;

  
if ($globalTrace) { printf("ansi2Type at q/ansi2.qon:348\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isList(second($node))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\ntypedef struct %s {\n", stringify(first($node)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2Struct(second($node))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n} %s;\n", stringify(first($node)))
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2displays("typedef ")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2TypeDecl($node)
    ;

  };

}


#Building function ansi2Types from line: 358

sub ansi2Types {
  my $nodes = shift;

  
if ($globalTrace) { printf("ansi2Types at q/ansi2.qon:358\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($nodes)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2Type(car($nodes))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi2Types(cdr($nodes))
    ;

  };

}


#Building function ansi2Compile from line: 368

sub ansi2Compile {
  my $filename = shift;

  my $tree = undef;
my $replace = undef;

if ($globalTrace) { printf("ansi2Compile at q/ansi2.qon:368\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  qlog("//Scanning file...%s\n", $filename)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = loadQuon($filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  qlog("//Building sexpr\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = loadIncludes($tree);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrowalk($tree);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), $undef));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrolist($tree, stringConcatenate("q", "log"), $replace);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  qlog("//Printing program\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi2Includes(cdr(first($tree)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi2Types(cdr(second($tree)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi2displays("Box* globalStackTrace = NULL;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi2displays("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi2ForwardDeclarations(cdr(third($tree)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi2displays("\n\n//End forward declarations\n\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi2Functions(cdr(third($tree)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi2displays("\n")
  ;

}


#Building function ansi3displays from line: 5

sub ansi3displays {
  my $s = shift;

  
if ($globalTrace) { printf("ansi3displays at q/ansi3.qon:5\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", $s)
  ;

}


#Building function ansi3FunctionArgs from line: 11

sub ansi3FunctionArgs {
  my $tree = shift;

  
if ($globalTrace) { printf("ansi3FunctionArgs at q/ansi3.qon:11\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalString(stringify(first($tree)), "...")) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("...")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      display(ansi3TypeMap(first($tree)))
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      ansi3displays(" ")
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      display(second($tree))
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil(cddr($tree))) {
    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      ansi3displays(", ")
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3FunctionArgs(cddr($tree))
    ;

  };

}


#Building function ansi3Expression from line: 28

sub ansi3Expression {
  my $tree = shift;
my $indent = shift;

  my $thing = undef;

if ($globalTrace) { printf("ansi3Expression at q/ansi3.qon:28\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isList($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equal(1, listLength($tree))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      display(car($tree))
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalBox(boxString("return"), car($tree))) {
      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        ansi3displays("()")
        ;

      };

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      $thing = first($tree);
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalBox(boxSymbol("get-struct"), $thing)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printf("%s->%s", stringify(second($tree)), stringify(third($tree)))
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalBox(boxSymbol("new"), $thing)) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf("malloc(sizeof(%s))", stringify(third($tree)))
          ;

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalBox(boxSymbol("passthrough"), $thing)) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("%s", stringify(second($tree)))
            ;

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            if ( equalBox(boxSymbol("binop"), $thing)) {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf("(")
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              ansi3Expression(third($tree), $indent)
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf(" %s ", stringify(second($tree)))
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              ansi3Expression(fourth($tree), $indent)
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf(")")
              ;

            } else {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf("%s(", stringify(ansi3FuncMap(car($tree))))
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              ansi3RecurList(cdr($tree), $indent)
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf(")")
              ;

            };

          };

        };

      };

    };

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    display(ansi3FuncMap($tree))
    ;

  };

}


#Building function ansi3RecurList from line: 98

sub ansi3RecurList {
  my $expr = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansi3RecurList at q/ansi3.qon:98\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($expr)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3Expression(car($expr), $indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil(cdr($expr))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      ansi3displays("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      ansi3displays(", ")
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      ansi3RecurList(cdr($expr), $indent)
      ;

    };

  };

}


#Building function ansi3If from line: 115

sub ansi3If {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansi3If at q/ansi3.qon:115\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi3displays("if ( ")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi3Expression(second($node), 0)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi3displays(") {")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi3Body(cdr(third($node)), add1($indent))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi3displays("} else {")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi3Body(cdr(fourth($node)), add1($indent))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi3displays("}")
  ;

}


#Building function ansi3SetStruct from line: 128

sub ansi3SetStruct {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansi3SetStruct at q/ansi3.qon:128\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s->%s = ", stringify(second($node)), stringify(third($node)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi3Expression(fourth($node), $indent)
  ;

}


#Building function ansi3GetStruct from line: 137

sub ansi3GetStruct {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansi3GetStruct at q/ansi3.qon:137\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s->%s", stringify(first($node)), stringify(second($node)))
  ;

}


#Building function ansi3Set from line: 145

sub ansi3Set {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansi3Set at q/ansi3.qon:145\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi3Expression(first(cdr($node)), $indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf(" = ")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi3Expression(third($node), $indent)
  ;

}


#Building function ansi3Return from line: 152

sub ansi3Return {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansi3Return at q/ansi3.qon:152\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equal(listLength($node), 1)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3displays("return;")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3displays("return ")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3Expression(cadr($node), $indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3displays(";")
    ;

  };

}


#Building function ansi3Statement from line: 163

sub ansi3Statement {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("ansi3Statement at q/ansi3.qon:163\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(boxString("set"), first($node))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3Set($node, $indent)
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalBox(boxString("set-struct"), first($node))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      ansi3SetStruct($node, $indent)
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalBox(boxString("if"), first($node))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        ansi3If($node, $indent)
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalBox(boxString("return"), first($node))) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          ansi3Return($node, $indent)
          ;

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          newLine($indent)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          ansi3Expression($node, $indent)
          ;

        };

      };

    };

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi3displays(";\n")
  ;

}


#Building function ansi3Body from line: 181

sub ansi3Body {
  my $tree = shift;
my $indent = shift;

  my $code = undef;

if ($globalTrace) { printf("ansi3Body at q/ansi3.qon:181\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $code = $tree;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil($code)) {
    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      $code = car($tree);
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( not($releaseMode)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printf("\nif (globalTrace)\n    snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail(car($code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), stringify(getTagFail(car($code), boxString("line"), boxString("Line missing"))))
        ;

      } else {
      };

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( not($releaseMode)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printIndent($indent)
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n")
      ;

    } else {
    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3Statement($code, $indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3Body(cdr($tree), $indent)
    ;

  };

}


#Building function ansi3Declarations from line: 206

sub ansi3Declarations {
  my $decls = shift;
my $indent = shift;

  my $decl = undef;

if ($globalTrace) { printf("ansi3Declarations at q/ansi3.qon:206\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($decls)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $decl = car($decls);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s %s = ", stringify(ansi3TypeMap(first($decl))), stringify(second($decl)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3Expression(third($decl), $indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(";\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3Declarations(cdr($decls), $indent)
    ;

  };

}


#Building function ansi3Function from line: 220

sub ansi3Function {
  my $node = shift;

  my $name = undef;

if ($globalTrace) { printf("ansi3Function at q/ansi3.qon:220\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $name = second($node);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\n\n//Building function %s from file %s, line: %s", stringify($name), stringify(getTag($name, boxString("filename"))), stringify(getTag($name, boxString("line"))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine(0)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    newLine(0)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s %s(", stringify(ansi3TypeMap(first($node))), stringify(second($node)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3FunctionArgs(third($node))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(") {")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    newLine(1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3Declarations(cdr(fourth($node)), 1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( $releaseMode) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("\nif (globalTrace)\n    printf(\"%s at %s:%s (%%s)\\n\", caller);\n", stringify($name), stringify(getTag($name, boxString("filename"))), stringify(getTag($name, boxString("line"))))
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( $releaseMode) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {
    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3Body(cdr(fifth($node)), 1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( $releaseMode) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("\nif (globalTrace)\n    printf(\"Leaving %s\\n\");\n", stringify($name))
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n}\n")
    ;

  };

}


#Building function ansi3ForwardDeclaration from line: 255

sub ansi3ForwardDeclaration {
  my $node = shift;

  
if ($globalTrace) { printf("ansi3ForwardDeclaration at q/ansi3.qon:255\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n%s %s(", stringify(ansi3TypeMap(first($node))), stringify(second($node)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3FunctionArgs(third($node))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3displays(");")
    ;

  };

}


#Building function ansi3ForwardDeclarations from line: 265

sub ansi3ForwardDeclarations {
  my $tree = shift;

  
if ($globalTrace) { printf("ansi3ForwardDeclarations at q/ansi3.qon:265\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3ForwardDeclaration(car($tree))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3ForwardDeclarations(cdr($tree))
    ;

  };

}


#Building function ansi3Functions from line: 271

sub ansi3Functions {
  my $tree = shift;

  
if ($globalTrace) { printf("ansi3Functions at q/ansi3.qon:271\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3Function(car($tree))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3Functions(cdr($tree))
    ;

  };

}


#Building function ansi3Includes from line: 277

sub ansi3Includes {
  my $nodes = shift;

  
if ($globalTrace) { printf("ansi3Includes at q/ansi3.qon:277\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\n#include <unistd.h>\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\nbool releaseMode = false;\n\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n")
  ;

}


#Building function ansi3TypeDecl from line: 285

sub ansi3TypeDecl {
  my $l = shift;

  
if ($globalTrace) { printf("ansi3TypeDecl at q/ansi3.qon:285\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan(listLength($l), 2)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent(1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s %s %s;\n", stringify(second($l)), stringify(ansi3TypeMap(listLast($l))), stringify(first($l)))
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent(1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s %s;\n", stringify(ansi3TypeMap(listLast($l))), stringify(car($l)))
    ;

  };

}


#Building function ansi3StructComponents from line: 302

sub ansi3StructComponents {
  my $node = shift;

  
if ($globalTrace) { printf("ansi3StructComponents at q/ansi3.qon:302\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3TypeDecl(car($node))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3StructComponents(cdr($node))
    ;

  };

}


#Building function ansi3Struct from line: 308

sub ansi3Struct {
  my $node = shift;

  
if ($globalTrace) { printf("ansi3Struct at q/ansi3.qon:308\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi3StructComponents(cdr($node))
  ;

}


#Building function ansi3TypeMap from line: 311

sub ansi3TypeMap {
  my $aSym = shift;

  my $symMap = undef;

if ($globalTrace) { printf("ansi3TypeMap at q/ansi3.qon:311\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), $undef));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( truthy(assoc(stringify($aSym), $symMap))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ansi3TypeMap

    if ($globalTrace) {printf("Leaving \n")}

    return(cdr(assoc(stringify($aSym), $symMap)));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ansi3TypeMap

    if ($globalTrace) {printf("Leaving \n")}

    return($aSym);

  };

}


#Building function ansi3FuncMap from line: 321

sub ansi3FuncMap {
  my $aSym = shift;

  my $symMap = undef;

if ($globalTrace) { printf("ansi3FuncMap at q/ansi3.qon:321\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("symbol", boxType($aSym))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), $undef)))))));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( truthy(assoc(stringify($aSym), $symMap))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ansi3FuncMap

      if ($globalTrace) {printf("Leaving \n")}

      return(cdr(assoc(stringify($aSym), $symMap)));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ansi3FuncMap

      if ($globalTrace) {printf("Leaving \n")}

      return($aSym);

    };

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: ansi3FuncMap

    if ($globalTrace) {printf("Leaving \n")}

    return($aSym);

  };

}


#Building function ansi3Type from line: 352

sub ansi3Type {
  my $node = shift;

  
if ($globalTrace) { printf("ansi3Type at q/ansi3.qon:352\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isList(second($node))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\ntypedef struct %s {\n", stringify(first($node)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3Struct(second($node))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n} %s;\n", stringify(first($node)))
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3displays("typedef ")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3TypeDecl($node)
    ;

  };

}


#Building function ansi3Types from line: 362

sub ansi3Types {
  my $nodes = shift;

  
if ($globalTrace) { printf("ansi3Types at q/ansi3.qon:362\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($nodes)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3Type(car($nodes))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    ansi3Types(cdr($nodes))
    ;

  };

}


#Building function ansi3Compile from line: 372

sub ansi3Compile {
  my $filename = shift;

  my $tree = undef;
my $replace = undef;

if ($globalTrace) { printf("ansi3Compile at q/ansi3.qon:372\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  qlog("//Scanning file...%s\n", $filename)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = loadQuon($filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  qlog("//Building sexpr\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  qlog("Loading shim ansi3\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = buildProg(cons(boxString("q/shims/ansi3.qon"), getIncludes($tree)), getTypes($tree), getFunctions($tree));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  qlog("Loading all includes\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = loadIncludes($tree);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  qlog("Applying macros\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrowalk($tree);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), $undef));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrolist($tree, stringConcatenate("q", "log"), $replace);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  qlog("//Printing program\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi3Includes(cdr(first($tree)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi3Types(cdr(second($tree)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi3displays("Box* globalStackTrace = NULL;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi3displays("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi3ForwardDeclarations(cdr(third($tree)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi3displays("\n\n//End forward declarations\n\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi3Functions(cdr(third($tree)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  ansi3displays("\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  qlog("//Done printing program\n")
  ;

}


#Building function test0 from line: 7

sub test0 {
  
  
if ($globalTrace) { printf("test0 at q/tests.qon:7\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString(stringify(boxString("hello")), stringify(boxString("hello")))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("0.  pass string compare works\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("0.  pass string compare fails\n")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString(stringify(boxString("hello")), stringify(boxSymbol("hello")))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("0.  pass string compare works\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("0.  pass string compare fails\n")
    ;

  };

}


#Building function test1 from line: 20

sub test1 {
  
  
if ($globalTrace) { printf("test1 at q/tests.qon:20\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("1.  pass Function call and print work\n")
  ;

}


#Building function test2_do from line: 24

sub test2_do {
  my $message = shift;

  
if ($globalTrace) { printf("test2_do at q/tests.qon:24\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("2.  pass Function call with arg works: %s\n", $message)
  ;

}


#Building function test2 from line: 28

sub test2 {
  
  
if ($globalTrace) { printf("test2 at q/tests.qon:28\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  test2_do("This is the argument")
  ;

}


#Building function test3_do from line: 30

sub test3_do {
  my $b = shift;
my $c = shift;

  
if ($globalTrace) { printf("test3_do at q/tests.qon:30\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("3.1 pass Two arg call, first arg: %d\n", $b)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("3.2 pass Two arg call, second arg: %s\n", $c)
  ;

}


#Building function test3 from line: 36

sub test3 {
  
  
if ($globalTrace) { printf("test3 at q/tests.qon:36\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  test3_do(42, "Fourty-two")
  ;

}


#Building function test4_do from line: 37

sub test4_do {
  
  
if ($globalTrace) { printf("test4_do at q/tests.qon:37\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: test4_do

  if ($globalTrace) {printf("Leaving \n")}

  return("pass Return works");

}


#Building function returnThis from line: 39

sub returnThis {
  my $returnMessage = shift;

  
if ($globalTrace) { printf("returnThis at q/tests.qon:39\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: returnThis

  if ($globalTrace) {printf("Leaving \n")}

  return($returnMessage);

}


#Building function test4 from line: 42

sub test4 {
  
  my $message = "fail";

if ($globalTrace) { printf("test4 at q/tests.qon:42\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $message = test4_do();
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("4.  %s\n", $message)
  ;

}


#Building function test5 from line: 45

sub test5 {
  
  my $message = "fail";

if ($globalTrace) { printf("test5 at q/tests.qon:45\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $message = returnThis("pass return passthrough string");
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("5.  %s\n", $message)
  ;

}


#Building function test6 from line: 50

sub test6 {
  
  
if ($globalTrace) { printf("test6 at q/tests.qon:50\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( $true) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("6.  pass If statement works\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("6.  fail If statement works\n")
    ;

  };

}


#Building function test7_do from line: 58

sub test7_do {
  my $count = shift;

  
if ($globalTrace) { printf("test7_do at q/tests.qon:58\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $count = subtract($count, 1);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan($count, 0)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $count = test7_do($count);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: test7_do

    if ($globalTrace) {printf("Leaving \n")}

    return($count);

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: test7_do

  if ($globalTrace) {printf("Leaving \n")}

  return($count);

}


#Building function test7 from line: 66

sub test7 {
  
  
if ($globalTrace) { printf("test7 at q/tests.qon:66\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equal(0, test7_do(10))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("7.  pass count works\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("7.  fail count fails\n")
    ;

  };

}


#Building function beer from line: 74

sub beer {
  
  
if ($globalTrace) { printf("beer at q/tests.qon:74\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%d bottle of beer on the wall, %d bottle of beer.  Take one down, pass it round, no bottles of beer on the wall\n", 1, 1)
  ;

}


#Building function plural from line: 83

sub plural {
  my $num = shift;

  
if ($globalTrace) { printf("plural at q/tests.qon:83\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equal($num, 1)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: plural

    if ($globalTrace) {printf("Leaving \n")}

    return("");

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: plural

    if ($globalTrace) {printf("Leaving \n")}

    return("s");

  };

}


#Building function beers from line: 88

sub beers {
  my $count = shift;

  my $newcount = 0;

if ($globalTrace) { printf("beers at q/tests.qon:88\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $newcount = subtract($count, 1);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%d bottle%s of beer on the wall, %d bottle%s of beer.  Take one down, pass it round, %d bottle%s of beer on the wall\n", $count, plural($count), $count, plural($count), $newcount, plural($newcount))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan($count, 1)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $count = beers($newcount);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: beers

    if ($globalTrace) {printf("Leaving \n")}

    return($count);

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: beers

  if ($globalTrace) {printf("Leaving \n")}

  return(0);

}


#Building function test8 from line: 104

sub test8 {
  
  
if ($globalTrace) { printf("test8 at q/tests.qon:104\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equal(subtract(subtract(2, 1), subtract(3, 1)), -1)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("8.  pass Nested expressions work\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("8.  fail Nested expressions don't work\n")
    ;

  };

}


#Building function test9 from line: 112

sub test9 {
  
  my $answer = -999999;
my $a = 2;
my $b = 3;

if ($globalTrace) { printf("test9 at q/tests.qon:112\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $answer = subtract(subtract(20, 1), subtract(3, 1));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equal($answer, 17)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.1  pass sub works\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.1  fail sub\n")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $answer = add(2, 3);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equal($answer, 5)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.2  pass add works\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.2  fail add\n")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $answer = mult($a, $b);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equal($answer, 6)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.3  pass mult works\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.3  fail mult\n")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan(2, 1)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.4  pass greaterthan works\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.4  fail greaterthan\n")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equal(1, 1)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.5  pass integer equal works\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.5  fail integer equal\n")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("hello", "hello")) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.6  pass string equal works\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.6  fail string equal\n")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("hello", "world")) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.7  fail string equal\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.7  pass string equal\n")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( andBool($false, $false)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.8  fail andBool\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.8  pass andBool works\n")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( andBool($true, $true)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.9  pass andBool works\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.9  fail andBool\n")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( andBool($true, $false)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.10  fail andBool\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.10  pass andBool works\n")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("hello", "hello")) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.11  pass string equal\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.11  fail string equal\n")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("!", character(33))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.12  pass character\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.12  fail character\n")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("33", intToString(33))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.13  pass intToString\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.13  fail intToString\n")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("llo", substr("hello", $a, $b))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.14  pass sub-string\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("9.14  fail sub-string: %s\n", substr("hello", $a, $b))
    ;

  };

}


#Building function test10 from line: 170

sub test10 {
  
  my $testString = "This is a test string";

if ($globalTrace) { printf("test10 at q/tests.qon:170\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString($testString, unBoxString(car(cons(boxString($testString), $undef))))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("10. pass cons and car work\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("10. fail cons and car fail\n")
    ;

  };

}


#Building function test12 from line: 180

sub test12 {
  
  my $b = undef;

if ($globalTrace) { printf("test12 at q/tests.qon:180\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $b = {};
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $b->{str} = "12. pass structure accessors\n";
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", $b->{str})
  ;

}


#Building function test13 from line: 188

sub test13 {
  
  my $testString = "Hello from the filesystem!";
my $contents = "";

if ($globalTrace) { printf("test13 at q/tests.qon:188\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  write_file("test.txt", $testString)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $contents = read_file("test.txt");
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString($testString, $contents)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("13. pass Read and write files\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("13. fail Read and write files\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("Expected: %s\n", $testString)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("Got: %s\n", $contents)
    ;

  };

}


#Building function test15 from line: 204

sub test15 {
  
  my $a = "hello";
my $b = " world";
my $c = "";

if ($globalTrace) { printf("test15 at q/tests.qon:204\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $c = stringConcatenate($a, $b);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString($c, "hello world")) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("15. pass String concatenate\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("15. fail String concatenate\n")
    ;

  };

}


#Building function test16 from line: 212

sub test16 {
  
  my $assocCell1 = undef;
my $assList = undef;
my $assocCell2 = undef;
my $assocCell3 = undef;

if ($globalTrace) { printf("test16 at q/tests.qon:212\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $assocCell1 = cons(boxString("Hello"), boxString("world"));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $assocCell2 = cons(boxString("goodnight"), boxString("moon"));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $assocCell3 = cons(boxSymbol("ohio"), boxString("gozaimasu"));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $assList = cons($assocCell2, emptyList());
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $assList = cons($assocCell1, $assList);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $assList = cons($assocCell3, $assList);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(cdr(assoc("Hello", $assList)), boxString("world"))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("16.1 pass Basic assoc works\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("16.1 fail Basic assoc fails\n")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( andBool(andBool(equalBox(cdr(assoc("Hello", $assList)), boxString("world")), equalBox(cdr(assoc("goodnight", $assList)), boxString("moon"))), equalBox(cdr(assoc("ohio", $assList)), boxString("gozaimasu")))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("16.2 pass assoc list\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("16.2 fail assoc list\n")
    ;

  };

}


#Building function test17 from line: 236

sub test17 {
  
  my $l = undef;

if ($globalTrace) { printf("test17 at q/tests.qon:236\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $l = cons(boxInt(1), cons(boxInt(2), cons(boxInt(3), $undef)));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(car($l), boxInt(1))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("17. pass list literal works\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("17. fail list literal failed\n")
    ;

  };

}


#Building function test18 from line: 247

sub test18 {
  
  my $val1 = "a";
my $val2 = "b";
my $l = undef;

if ($globalTrace) { printf("test18 at q/tests.qon:247\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $l = cons(boxString($val1), cons(boxString($val2), cons(boxString("c"), $undef)));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalList($l, cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), $undef))))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("18. pass string list constructor works\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("18. fail string list constructor failed\n")
    ;

  };

}


#Building function test19 from line: 261

sub test19 {
  
  my $val1 = "a";
my $val2 = "b";
my $l = undef;
my $revlist = undef;
my $answer = undef;

if ($globalTrace) { printf("test19 at q/tests.qon:261\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $l = cons(boxString($val1), cons(boxString($val2), cons(boxString("c"), $undef)));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $answer = cons(boxString("c"), cons(boxString($val2), cons(boxString($val1), $undef)));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $revlist = reverseList($l);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalList($answer, $revlist)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("19. pass reverseList\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("19. fail reverseList\n")
    ;

  };

}


#Building function concatenateLists from line: 279

sub concatenateLists {
  my $oldL = shift;
my $newL = shift;

  
if ($globalTrace) { printf("concatenateLists at q/tests.qon:279\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: concatenateLists

  if ($globalTrace) {printf("Leaving \n")}

  return(reverseRec(reverseList($oldL), $newL));

}


#Building function test20 from line: 284

sub test20 {
  
  my $val1 = "a";
my $val2 = "b";
my $val3 = "c";
my $l = undef;
my $l2 = undef;
my $l3 = undef;
my $combined = undef;

if ($globalTrace) { printf("test20 at q/tests.qon:284\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $l = cons(boxString($val1), cons(boxString($val2), cons(boxString("c"), $undef)));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $l2 = cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), $undef)));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $l3 = cons(boxString($val1), cons(boxString($val2), cons(boxString($val3), cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), $undef))))));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $combined = concatenateLists($l, $l2);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalList($l3, $combined)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("21. pass concatenateLists\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("21. fail concatenateLists\n")
    ;

  };

}


#Building function test21 from line: 304

sub test21 {
  
  my $val1 = "a";
my $val2 = "b";
my $val3 = "c";
my $l = undef;
my $l2 = undef;

if ($globalTrace) { printf("test21 at q/tests.qon:304\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $l = cons(boxString($val1), cons(boxString($val2), cons(boxString($val3), $undef)));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $l2 = cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), $undef)));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalList($l, $l2)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("21. pass equalList\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("21. fail equalList\n")
    ;

  };

}


#Building function test22 from line: 320

sub test22 {
  
  my $original = undef;
my $out = undef;
my $replace = undef;
my $correct = undef;

if ($globalTrace) { printf("test22 at q/tests.qon:320\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), $undef)));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $replace = cons(boxString("fprintf"), cons(boxString("stderr"), $undef));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $out = macrolist($original, stringConcatenate("q", "log"), $replace);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $correct = cons(boxString("fprintf"), cons(boxString("stderr"), cons(boxString("%s"), cons(boxString("hello"), $undef))));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalList($out, $correct)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("22. pass macroList\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("22. fail macroList\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("In: ")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    displayList($original, 0, $true)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\nOut: ")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    displayList($out, 0, $true)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n")
    ;

  };

}


#Building function test23 from line: 343

sub test23 {
  
  my $original = undef;
my $out = undef;
my $replace = undef;
my $correct = undef;

if ($globalTrace) { printf("test23 at q/tests.qon:343\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), $undef)));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $replace = cons(boxString("fprintf"), cons(boxString("stderr"), $undef));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $out = concatLists($original, $replace);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $correct = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), cons(boxString("fprintf"), cons(boxString("stderr"), $undef)))));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalList($out, $correct)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("23. pass concatLists\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("23. fail concatLists\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("In: ")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    displayList($original, 0, $true)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\nOut: ")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    displayList($out, 0, $true)
    ;

  };

}


#Building function test24 from line: 366

sub test24 {
  
  my $expected = "a b c";
my $res = "";

if ($globalTrace) { printf("test24 at q/tests.qon:366\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $res = StringListJoin(cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), $undef))), " ");
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString($expected, $res)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("24. pass StringListJoin\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("24. fail StringListJoin.  expected '%s', got '%s'\n", $expected, $res)
    ;

  };

}


#Building function test25 from line: 380

sub test25 {
  
  my $expected = "( a b ) c d e";
my $res = "";
my $testsubstr = [cons 
(boxString "c ") 
(cons 
  (boxString "d ") 
  (cons 
    (boxString "e") nil))];
my $input = undef;

if ($globalTrace) { printf("test25 at q/tests.qon:380\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $input = cons(boxString("a "), cons(boxString("b "), $undef));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $input = cons($input, $testsubstr);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $res = ListToString($input, 0, $true, $false);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString($expected, $res)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("25. pass ListToString\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("25. fail ListToString.  expected '%s', got '%s'\n", $expected, $res)
    ;

  };

}


#Building function nodeFunctionArgs from line: 4

sub nodeFunctionArgs {
  my $tree = shift;

  
if ($globalTrace) { printf("nodeFunctionArgs at q/node.qon:4\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    display(second($tree))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil(cddr($tree))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf(",")
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeFunctionArgs(cddr($tree))
    ;

  };

}


#Building function nodeLeaf from line: 13

sub nodeLeaf {
  my $thisNode = shift;
my $indent = shift;

  
if ($globalTrace) { printf("nodeLeaf at q/node.qon:13\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  display(nodeFuncMap(codeof($thisNode)))
  ;

}


#Building function nodeStructGetterExpression from line: 16

sub nodeStructGetterExpression {
  my $thisNode = shift;
my $indent = shift;

  
if ($globalTrace) { printf("nodeStructGetterExpression at q/node.qon:16\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(boxString("structGetter"), subnameof($thisNode))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeGetStruct($thisNode, $indent)
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeLeaf($thisNode, $indent)
    ;

  };

}


#Building function nodeExpression from line: 22

sub nodeExpression {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("nodeExpression at q/node.qon:22\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isLeaf($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    display(nodeFuncMap(codeof($node)))
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeSubExpression($node, $indent)
    ;

  };

}


#Building function nodeRecurList from line: 28

sub nodeRecurList {
  my $expr = shift;
my $indent = shift;

  
if ($globalTrace) { printf("nodeRecurList at q/node.qon:28\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($expr)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeExpression(car($expr), $indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil(cdr($expr))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf(", ")
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      nodeRecurList(cdr($expr), $indent)
      ;

    };

  };

}


#Building function nodeSubExpression from line: 41

sub nodeSubExpression {
  my $tree = shift;
my $indent = shift;

  my $thing = undef;

if ($globalTrace) { printf("nodeSubExpression at q/node.qon:41\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNode(childrenof($tree))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      nodeSubExpression(childrenof($tree), $indent)
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( isLeaf($tree)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        display(nodeFuncMap(codeof($tree)))
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equal(1, listLength(childrenof($tree)))) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          display(codeof(car(childrenof($tree))))
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalBox(boxString("return"), codeof(car(childrenof($tree))))) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("")
            ;

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("()")
            ;

          };

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          $thing = codeof(car(childrenof($tree)));
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalBox(boxSymbol("get-struct"), $thing)) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("%s.%s", stringify(codeof(second(childrenof($tree)))), stringify(codeof(third(childrenof($tree)))))
            ;

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            if ( equalBox(boxSymbol("new"), $thing)) {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf("{}")
              ;

            } else {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf("%s(", stringify(nodeFuncMap(codeof(car(childrenof($tree))))))
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              nodeRecurList(cdr(childrenof($tree)), $indent)
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf(")")
              ;

            };

          };

        };

      };

    };

  };

}


#Building function nodeIf from line: 82

sub nodeIf {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("nodeIf at q/node.qon:82\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("if ( ")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  nodeExpression(car(first(childrenof($node))), 0)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf(") {")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  nodeBody(second(childrenof($node)), add1($indent))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("} else {")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  nodeBody(third(childrenof($node)), add1($indent))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("}")
  ;

}


#Building function nodeGetStruct from line: 96

sub nodeGetStruct {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("nodeGetStruct at q/node.qon:96\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s.%s", stringify(first(codeof($node))), stringify(second(codeof($node))))
  ;

}


#Building function nodeSet from line: 104

sub nodeSet {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("nodeSet at q/node.qon:104\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s = ", stringify(first(codeof($node))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  nodeExpression(childrenof($node), $indent)
  ;

}


#Building function nodeSetStruct from line: 110

sub nodeSetStruct {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("nodeSetStruct at q/node.qon:110\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s.%s = ", stringify(first(codeof($node))), stringify(second(codeof($node))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  nodeExpression(childrenof($node), $indent)
  ;

}


#Building function nodeStatement from line: 118

sub nodeStatement {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("nodeStatement at q/node.qon:118\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(boxString("setter"), subnameof($node))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeSet($node, $indent)
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalBox(boxString("structSetter"), subnameof($node))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      nodeSetStruct($node, $indent)
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalBox(boxString("if"), subnameof($node))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        nodeIf($node, $indent)
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalBox(boxString("returnvoid"), subnameof($node))) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          newLine($indent)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf("return")
          ;

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          newLine($indent)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          nodeExpression(childrenof($node), $indent)
          ;

        };

      };

    };

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf(";\n")
  ;

}


#Building function nodeBody from line: 137

sub nodeBody {
  my $tree = shift;
my $indent = shift;

  
if ($globalTrace) { printf("nodeBody at q/node.qon:137\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent($indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s", "if (globalStepTrace) {console.log(new Error(\"StepTrace \\n\"));}\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeStatement(car($tree), $indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeBody(cdr($tree), $indent)
    ;

  };

}


#Building function nodeDeclarations from line: 151

sub nodeDeclarations {
  my $decls = shift;
my $indent = shift;

  my $decl = undef;

if ($globalTrace) { printf("nodeDeclarations at q/node.qon:151\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($decls)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $decl = car($decls);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("var %s = ", stringify(second($decl)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    display(nodeFuncMap(third($decl)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(";\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeDeclarations(cdr($decls), $indent)
    ;

  };

}


#Building function nodeFunction from line: 166

sub nodeFunction {
  my $node = shift;

  my $name = undef;

if ($globalTrace) { printf("nodeFunction at q/node.qon:166\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $name = subnameof($node);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\n\n//Building function %s from line: %s", stringify($name), stringify(getTag($name, boxString("line"))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine(0)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    newLine(0)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("function %s(", stringify(subnameof($node)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeFunctionArgs(cdr(assoc("intype", cdr($node))))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(") {")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    newLine(1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeDeclarations(declarationsof($node), 1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( $releaseMode) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("\nif (globalTrace)\n    {printf(\"%s at %s:%s\\n\");}\n", stringify($name), stringify(getTag($name, boxString("filename"))), stringify(getTag($name, boxString("line"))))
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( $releaseMode) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {
    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeBody(childrenof($node), 1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( $releaseMode) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("\nif (globalTrace)\n    {printf(\"Leaving %s\\n\");}\n", stringify($name))
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n}\n")
    ;

  };

}


#Building function nodeForwardDeclaration from line: 199

sub nodeForwardDeclaration {
  my $node = shift;

  
if ($globalTrace) { printf("nodeForwardDeclaration at q/node.qon:199\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n%s %s(", stringify(nodeTypeMap(cdr(assoc("outtype", cdr($node))))), stringify(subnameof($node)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeFunctionArgs(cdr(assoc("intype", cdr($node))))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(");")
    ;

  };

}


#Building function nodeForwardDeclarations from line: 211

sub nodeForwardDeclarations {
  my $tree = shift;

  
if ($globalTrace) { printf("nodeForwardDeclarations at q/node.qon:211\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeForwardDeclaration(car($tree))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeForwardDeclarations(cdr($tree))
    ;

  };

}


#Building function nodeFunctions from line: 221

sub nodeFunctions {
  my $tree = shift;

  
if ($globalTrace) { printf("nodeFunctions at q/node.qon:221\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeFunction(car($tree))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeFunctions(cdr($tree))
    ;

  };

}


#Building function nodeIncludes from line: 229

sub nodeIncludes {
  my $nodes = shift;

  
if ($globalTrace) { printf("nodeIncludes at q/node.qon:229\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function read_file(filename) {return fs.readFileSync(filename);}\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function write_file(filename, data) {fs.writeFileSync(filename, data);}\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "var util = require('util');\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function printf() {process.stdout.write(util.format.apply(this, arguments));}\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function qlog()   {process.stderr.write(util.format.apply(this, arguments));}\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "var fs = require('fs');\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function equalString(a,b) {if (a==null) {return false;}if (b==null) {return false;}return a.toString()===b.toString() }\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function panic(s){console.trace(s);process.exit(1);}\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function dump(s){console.log(s)}")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function sub(a, b) { return a - b; }\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function mult(a, b) { return a * b; }\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function greaterthan(a, b) { return a > b; }\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function subf(a, b) { return a - b; }\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function multf(a, b) { return a * b; }\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function greaterthanf(a, b) { return a > b; }\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function equal(a, b) { return a == b; }\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function andBool(a, b) { return a == b;}\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function string_length(s) { return s.length;}\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function sub_string(str, start, len) {str = ''+str;return str.substring(start, start+len)};\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function stringConcatenate(a, b) { return a + b}\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function intToString(a) {}\n\n\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function gc_malloc( size ) {\nreturn {};\n}\n\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function makeArray(length) {\n   return [];\n}\n\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function at(arr, index) {\n  return arr[index];\n}\n\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function setAt(array, index, value) {\n    array[index] = value;\n}\n\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function getStringArray(index, strs) {\nreturn strs[index];\n}\n\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "var NULL = null;")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "var globalArgs;\nvar globalArgsCount;\nvar globalTrace = false;\nvar globalStepTrace = false;\nvar releaseMode = false;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "function character(num) {}")
  ;

}


#Building function nodeTypeDecl from line: 263

sub nodeTypeDecl {
  my $l = shift;

  
if ($globalTrace) { printf("nodeTypeDecl at q/node.qon:263\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan(listLength($l), 2)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent(1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s %s %s;\n", stringify(second($l)), stringify(nodeTypeMap(listLast($l))), stringify(first($l)))
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent(1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s %s;\n", stringify(nodeTypeMap(listLast($l))), stringify(car($l)))
    ;

  };

}


#Building function nodeStructComponents from line: 280

sub nodeStructComponents {
  my $node = shift;

  
if ($globalTrace) { printf("nodeStructComponents at q/node.qon:280\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeTypeDecl(car($node))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeStructComponents(cdr($node))
    ;

  };

}


#Building function nodeStruct from line: 288

sub nodeStruct {
  my $node = shift;

  
if ($globalTrace) { printf("nodeStruct at q/node.qon:288\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  nodeStructComponents(cdr(car($node)))
  ;

}


#Building function nodeTypeMap from line: 293

sub nodeTypeMap {
  my $aSym = shift;

  my $symMap = undef;

if ($globalTrace) { printf("nodeTypeMap at q/node.qon:293\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), $undef));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( truthy(assoc(stringify($aSym), $symMap))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: nodeTypeMap

    if ($globalTrace) {printf("Leaving \n")}

    return(cdr(assoc(stringify($aSym), $symMap)));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: nodeTypeMap

    if ($globalTrace) {printf("Leaving \n")}

    return($aSym);

  };

}


#Building function nodeFuncMap from line: 308

sub nodeFuncMap {
  my $aSym = shift;

  my $symMap = undef;

if ($globalTrace) { printf("nodeFuncMap at q/node.qon:308\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("symbol", boxType($aSym))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), $undef)))))));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( truthy(assoc(stringify($aSym), $symMap))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: nodeFuncMap

      if ($globalTrace) {printf("Leaving \n")}

      return(cdr(assoc(stringify($aSym), $symMap)));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: nodeFuncMap

      if ($globalTrace) {printf("Leaving \n")}

      return($aSym);

    };

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: nodeFuncMap

    if ($globalTrace) {printf("Leaving \n")}

    return($aSym);

  };

}


#Building function nodeType from line: 339

sub nodeType {
  my $node = shift;

  
if ($globalTrace) { printf("nodeType at q/node.qon:339\n") }

}


#Building function nodeTypes from line: 343

sub nodeTypes {
  my $nodes = shift;

  
if ($globalTrace) { printf("nodeTypes at q/node.qon:343\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($nodes)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeType(car($nodes))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    nodeTypes(cdr($nodes))
    ;

  };

}


#Building function nodeCompile from line: 351

sub nodeCompile {
  my $filename = shift;

  my $programStr = "";
my $tree = undef;
my $program = undef;

if ($globalTrace) { printf("nodeCompile at q/node.qon:351\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $programStr = read_file($filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = readSexpr($programStr, $filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $program = alistCons(boxString("includes"), astIncludes(first($tree)), alistCons(boxString("types"), astTypes(second($tree)), alistCons(boxString("functions"), astFunctions(third($tree)), $undef)));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $program = mergeIncludes($program);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  nodeIncludes(cdr(assoc("includes", $program)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  nodeTypes(childrenof(cdr(assoc("types", $program))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\nvar globalStackTrace = NULL;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\nvar caller = \"\";\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\nfunction isNil(p) {\n    return p == NULL;\n}\n\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  nodeFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", $program))))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("const [asfdasdf, ...qwerqwer] = process.argv;")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("globalArgs = qwerqwer;")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("globalArgsCount = qwerqwer.length;")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "start();\n")
  ;

}


#Building function node2Compile from line: 4

sub node2Compile {
  my $filename = shift;

  my $programStr = "";
my $tree = undef;
my $program = undef;

if ($globalTrace) { printf("node2Compile at q/node2.qon:4\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $programStr = read_file($filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = readSexpr($programStr, $filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $program = alistCons(boxString("includes"), astIncludes(first($tree)), alistCons(boxString("types"), astTypes(second($tree)), alistCons(boxString("functions"), astFunctions(third($tree)), emptyList())));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $program = mergeIncludes($program);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  qlog("Loading shim node2\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $program = buildProg(cons(boxString("q/shims/node2.qon"), getIncludes($program)), getTypes($program), getFunctions($program));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: node2Compile

  if ($globalTrace) {printf("Leaving \n")}

  return(cons(node2Includes(cdr(assoc("includes", $program))), cons(boxString("\nvar globalStackTrace = NULL;\n"), cons(boxString("\nvar caller = \"\";\n"), cons(boxString("\nfunction isNil(p) {\n    return p == NULL;\n}\n\n"), cons(node2Functions(cdr(assoc("children", cdr(cdr(assoc("functions", $program)))))), cons(boxString("\n"), cons(boxString("const [asfdasdf, ...qwerqwer] = process.argv;"), cons(boxString("globalArgs = qwerqwer;"), cons(boxString("globalArgsCount = qwerqwer.length;"), cons(boxString("start();\n"), emptyList())))))))))));

}


#Building function node2Includes from line: 35

sub node2Includes {
  my $nodes = shift;

  
if ($globalTrace) { printf("node2Includes at q/node2.qon:35\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: node2Includes

  if ($globalTrace) {printf("Leaving \n")}

  return(cons(boxString("function read_file(filename) {return fs.readFileSync(filename);}\n"), cons(boxString("function write_file(filename, data) {fs.writeFileSync(filename, data);}\n"), cons(boxString("var util = require('util');\n"), cons(boxString("function printf() {process.stdout.write(util.format.apply(this, arguments));}\n"), cons(boxString("function qlog()   {process.stderr.write(util.format.apply(this, arguments));}\n"), cons(boxString("var fs = require('fs');\n"), cons(boxString("function equalString(a,b) {if (a==null) {return false;}if (b==null) {return false;}return a.toString()===b.toString() }\n"), cons(boxString("function panic(s){console.trace(s);process.exit(1);}\n"), cons(boxString("function dump(s){console.log(s)}"), cons(boxString("function sub(a, b) { return a - b; }\n"), cons(boxString("function mult(a, b) { return a * b; }\n"), cons(boxString("function greaterthan(a, b) { return a > b; }\n"), cons(boxString("function subf(a, b) { return a - b; }\n"), cons(boxString("function multf(a, b) { return a * b; }\n"), cons(boxString("function greaterthanf(a, b) { return a > b; }\n"), cons(boxString("function equal(a, b) { return a == b; }\n"), cons(boxString("function andBool(a, b) { return a == b;}\n"), cons(boxString("function string_length(s) { return s.length;}\n"), cons(boxString("function sub_string(str, start, len) {str = ''+str;return str.substring(start, start+len)};\n"), cons(boxString("function stringConcatenate(a, b) { return a + b}\n"), cons(boxString("function intToString(a) {}\n\n\n"), cons(boxString("function gc_malloc( size ) {\nreturn {};\n}\n\n"), cons(boxString("function makeArray(length) {\n   return [];\n}\n\n"), cons(boxString("function at(arr, index) {\n  return arr[index];\n}\n\n"), cons(boxString("function setAt(array, index, value) {\n    array[index] = value;\n}\n\n"), cons(boxString("function getStringArray(index, strs) {\nreturn strs[index];\n}\n\n"), cons(boxString("var NULL = null;"), cons(boxString("var globalArgs;\nvar globalArgsCount;\nvar globalTrace = false;\nvar globalStepTrace = false;\nvar releaseMode = false;\n"), cons(boxString("function character(num) {}"), $undef))))))))))))))))))))))))))))));

}


#Building function node2Functions from line: 70

sub node2Functions {
  my $tree = shift;

  
if ($globalTrace) { printf("node2Functions at q/node2.qon:70\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: node2Functions

    if ($globalTrace) {printf("Leaving \n")}

    return(emptyList());

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: node2Functions

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(node2Function(car($tree)), node2Functions(cdr($tree))));

  };

}


#Building function node2Function from line: 78

sub node2Function {
  my $node = shift;

  my $name = undef;

if ($globalTrace) { printf("node2Function at q/node2.qon:78\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: node2Function

    if ($globalTrace) {printf("Leaving \n")}

    return(emptyList());

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $name = subnameof($node);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: node2Function

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(boxString("\n\n//Building function "), cons(boxString(stringify($name)), cons(boxString(" from line: "), cons(boxString(stringify(getTag($name, boxString("line")))), $undef)))), "\n", "\n", "function ", stringify(subnameof($node)), "(", node2FunctionArgs(cdr(assoc("intype", cdr($node)))), ") {", "\n", stringIndent(1), node2Declarations(declarationsof($node), 1), ListToString(flatten(ternList($releaseMode, boxString(""), cons(boxString("\nif (globalTrace)\n    {printf(\""), cons(boxString(stringify($name)), cons(boxString(" at "), cons(boxString(stringify(getTag($name, boxString("filename")))), cons(boxString(":"), cons(boxString(stringify(getTag($name, boxString("line")))), cons(boxString("\\n\");}\n"), $undef)))))))))), ListToString(flatten(node2Body(childrenof($node), 1))), ternString($releaseMode, "", ListToString("\nif (globalTrace)\n    {printf(\"Leaving ", stringify($name), "\\n\");}\n")), "\n}\n");

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: node2Function

  if ($globalTrace) {printf("Leaving \n")}

  return(emptyList());

}


#Building function node2FunctionArgs from line: 111

sub node2FunctionArgs {
  my $tree = shift;

  
if ($globalTrace) { printf("node2FunctionArgs at q/node2.qon:111\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: node2FunctionArgs

    if ($globalTrace) {printf("Leaving \n")}

    return(emptyList());

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: node2FunctionArgs

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(second($tree), cons(tern(isNil(cddr($tree)), boxString(""), boxString(",")), cons(node2FunctionArgs(cddr($tree)), emptyList()))));

  };

}


#Building function node2Declarations from line: 122

sub node2Declarations {
  my $decls = shift;
my $indent = shift;

  my $decl = undef;

if ($globalTrace) { printf("node2Declarations at q/node2.qon:122\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($decls)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: node2Declarations

    if ($globalTrace) {printf("Leaving \n")}

    return(emptyList());

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $decl = car($decls);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: node2Declarations

    if ($globalTrace) {printf("Leaving \n")}

    return(cons(boxString("var %s = "), cons(second($decl), cons(nodeFuncMap(third($decl)), cons(boxString(";\n"), node2Declarations(cdr($decls), $indent))))));

  };

}


#Building function javaFunctionArgs from line: 3

sub javaFunctionArgs {
  my $tree = shift;

  
if ($globalTrace) { printf("javaFunctionArgs at q/java.qon:3\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    display(javaTypeMap(first($tree)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(" ")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    display(second($tree))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil(cddr($tree))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf(",")
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    javaFunctionArgs(cddr($tree))
    ;

  };

}


#Building function javaLeaf from line: 14

sub javaLeaf {
  my $thisNode = shift;
my $indent = shift;

  
if ($globalTrace) { printf("javaLeaf at q/java.qon:14\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  display(javaFuncMap(codeof($thisNode)))
  ;

}


#Building function javaStructGetterExpression from line: 17

sub javaStructGetterExpression {
  my $thisNode = shift;
my $indent = shift;

  
if ($globalTrace) { printf("javaStructGetterExpression at q/java.qon:17\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(boxString("structGetter"), subnameof($thisNode))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    javaGetStruct($thisNode, $indent)
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    javaLeaf($thisNode, $indent)
    ;

  };

}


#Building function javaExpression from line: 23

sub javaExpression {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("javaExpression at q/java.qon:23\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isLeaf($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    display(javaFuncMap(codeof($node)))
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    javaSubExpression($node, $indent)
    ;

  };

}


#Building function javaRecurList from line: 29

sub javaRecurList {
  my $expr = shift;
my $indent = shift;

  
if ($globalTrace) { printf("javaRecurList at q/java.qon:29\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($expr)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    javaExpression(car($expr), $indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil(cdr($expr))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf(", ")
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      javaRecurList(cdr($expr), $indent)
      ;

    };

  };

}


#Building function javaSubExpression from line: 41

sub javaSubExpression {
  my $tree = shift;
my $indent = shift;

  my $thing = undef;

if ($globalTrace) { printf("javaSubExpression at q/java.qon:41\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNode(childrenof($tree))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      javaSubExpression(childrenof($tree), $indent)
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( isLeaf($tree)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        display(javaFuncMap(codeof($tree)))
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equal(1, listLength(childrenof($tree)))) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          display(codeof(car(childrenof($tree))))
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalBox(boxString("return"), codeof(car(childrenof($tree))))) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("")
            ;

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("()")
            ;

          };

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          $thing = codeof(car(childrenof($tree)));
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalBox(boxSymbol("get-struct"), $thing)) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("%s.%s", stringify(codeof(second(childrenof($tree)))), stringify(codeof(third(childrenof($tree)))))
            ;

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            if ( equalBox(boxSymbol("new"), $thing)) {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf("new %s()", stringify(codeof(third(childrenof($tree)))))
              ;

            } else {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf("%s(", stringify(javaFuncMap(codeof(car(childrenof($tree))))))
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              javaRecurList(cdr(childrenof($tree)), $indent)
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf(")")
              ;

            };

          };

        };

      };

    };

  };

}


#Building function javaIf from line: 81

sub javaIf {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("javaIf at q/java.qon:81\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("if ( ")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  javaExpression(car(first(childrenof($node))), 0)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf(") {")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  javaBody(second(childrenof($node)), add1($indent))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("} else {")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  javaBody(third(childrenof($node)), add1($indent))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("}")
  ;

}


#Building function javaSetStruct from line: 94

sub javaSetStruct {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("javaSetStruct at q/java.qon:94\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s.%s = ", stringify(first(codeof($node))), stringify(second(codeof($node))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  javaExpression(childrenof($node), $indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf(";")
  ;

}


#Building function javaGetStruct from line: 105

sub javaGetStruct {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("javaGetStruct at q/java.qon:105\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s.%s", stringify(first(codeof($node))), stringify(second(codeof($node))))
  ;

}


#Building function javaSet from line: 113

sub javaSet {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("javaSet at q/java.qon:113\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s = ", stringify(first(codeof($node))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  javaExpression(childrenof($node), $indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf(";")
  ;

}


#Building function javaStatement from line: 121

sub javaStatement {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("javaStatement at q/java.qon:121\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(boxString("setter"), subnameof($node))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    javaSet($node, $indent)
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalBox(boxString("structSetter"), subnameof($node))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      javaSetStruct($node, $indent)
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalBox(boxString("if"), subnameof($node))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        javaIf($node, $indent)
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalBox(boxString("returnvoid"), subnameof($node))) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          newLine($indent)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf("return;")
          ;

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          newLine($indent)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          javaExpression(childrenof($node), $indent)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf(";")
          ;

        };

      };

    };

  };

}


#Building function javaBody from line: 141

sub javaBody {
  my $tree = shift;
my $indent = shift;

  
if ($globalTrace) { printf("javaBody at q/java.qon:141\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent($indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    javaStatement(car($tree), $indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    javaBody(cdr($tree), $indent)
    ;

  };

}


#Building function javaDeclarations from line: 151

sub javaDeclarations {
  my $decls = shift;
my $indent = shift;

  my $decl = undef;

if ($globalTrace) { printf("javaDeclarations at q/java.qon:151\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($decls)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $decl = car($decls);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s %s = ", stringify(javaTypeMap(first($decl))), stringify(second($decl)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    display(javaFuncMap(third($decl)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(";\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    javaDeclarations(cdr($decls), $indent)
    ;

  };

}


#Building function javaFunction from line: 165

sub javaFunction {
  my $node = shift;

  my $name = undef;

if ($globalTrace) { printf("javaFunction at q/java.qon:165\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $name = subnameof($node);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\n\n//Building function %s from line: %s", stringify($name), stringify(getTag($name, boxString("line"))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine(0)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    newLine(0)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("public %s %s(", stringify(javaTypeMap(cdr(assoc("outtype", cdr($node))))), stringify(subnameof($node)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    javaFunctionArgs(cdr(assoc("intype", cdr($node))))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(") {")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    newLine(1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    javaDeclarations(declarationsof($node), 1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( inList(toStr($name), noStackTrace())) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( inList(toStr($name), noStackTrace())) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {
    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    javaBody(childrenof($node), 1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( inList(toStr($name), noStackTrace())) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString("void", stringify(javaTypeMap(cdr(assoc("outtype", cdr($node))))))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printf("\nif (globalTrace)\n   System.out. printf(\"Leaving %s\\n\");\n", stringify($name))
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printf("")
        ;

      };

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n}\n")
    ;

  };

}


#Building function javaFunctions from line: 204

sub javaFunctions {
  my $tree = shift;

  
if ($globalTrace) { printf("javaFunctions at q/java.qon:204\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    javaFunction(car($tree))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    javaFunctions(cdr($tree))
    ;

  };

}


#Building function javaIncludes from line: 210

sub javaIncludes {
  my $nodes = shift;

  
if ($globalTrace) { printf("javaIncludes at q/java.qon:210\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "public void panic(String s) {System.exit(1);}\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "public void exit(Integer s) {System.exit(s);}\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "public int sub(int a, int b) { return a - b; }\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "public Integer mult(int a, int b) { return a * b; }\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "public boolean greaterthan(int a, int b) { return a > b; }\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "public double subf(double a, double b) { return a - b; }\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "public double multf(double a, double b) { return a * b; }\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "public boolean greaterthanf(double a, double b) { return a > b; }\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "public boolean equal(int a, int b) { return a == b; }\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "public boolean equalString(String a, String b) { return a.equals(b); }\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "public int string_length(String s) { return s.length();}\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "public String stringConcatenate(String s1, String s2) { return s1 + s2; }\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "public int strcmp(String s1, String s2) { return s1.compareTo(s2);}\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "public String read_file(String filename) {try { return new String(Files.readAllBytes(Paths.get(filename)));} catch (Exception e) {panic(\"Could not read file\");return \"\";}}\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "public void write_file(String filename, String data) {try {Files.write(Paths.get(filename), data.getBytes(\"UTF-8\"));} catch (Exception e) {panic(\"Could not write file\");}}\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "public String sub_string(String s, int start, int length) {\nreturn s.substring(start, start+length);\n}\n\n\n\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "public String intToString(int num) { char c=(char) num;  String s=Character.toString(c); return s;}")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "public String character(int num) { char c=(char) num;  String s=Character.toString(c); return s;}")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "public String getStringArray(int index, String[] arr) { return arr[index];}")
  ;

}


#Building function javaTypeDecl from line: 233

sub javaTypeDecl {
  my $l = shift;

  
if ($globalTrace) { printf("javaTypeDecl at q/java.qon:233\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan(listLength($l), 2)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent(1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s %s;\n", stringify(javaTypeMap(listLast($l))), stringify(first($l)))
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent(1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s %s;\n", stringify(javaTypeMap(listLast($l))), stringify(car($l)))
    ;

  };

}


#Building function javaStructComponents from line: 250

sub javaStructComponents {
  my $node = shift;

  
if ($globalTrace) { printf("javaStructComponents at q/java.qon:250\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    javaTypeDecl(car($node))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    javaStructComponents(cdr($node))
    ;

  };

}


#Building function javaStruct from line: 256

sub javaStruct {
  my $node = shift;

  
if ($globalTrace) { printf("javaStruct at q/java.qon:256\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  javaStructComponents(cdr(car($node)))
  ;

}


#Building function javaTypeMap from line: 259

sub javaTypeMap {
  my $aSym = shift;

  my $symMap = undef;

if ($globalTrace) { printf("javaTypeMap at q/java.qon:259\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $symMap = alistCons(boxSymbol("pair"), boxSymbol("Box"), alistCons(boxSymbol("bool"), boxSymbol("boolean"), alistCons(boxSymbol("box"), boxSymbol("Box"), alistCons(boxSymbol("list"), boxSymbol("Box"), alistCons(boxSymbol("Box*"), boxSymbol("Box"), alistCons(boxSymbol("struct"), boxSymbol(""), alistCons(boxSymbol("int"), boxSymbol("Integer"), alistCons(boxSymbol("float"), boxSymbol("double"), alistCons(boxSymbol("stringArray"), boxSymbol("String[]"), alistCons(boxSymbol("string"), boxSymbol("String"), $undef))))))))));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( truthy(assoc(stringify($aSym), $symMap))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: javaTypeMap

    if ($globalTrace) {printf("Leaving \n")}

    return(cdr(assoc(stringify($aSym), $symMap)));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: javaTypeMap

    if ($globalTrace) {printf("Leaving \n")}

    return($aSym);

  };

}


#Building function javaTypesNoDeclare from line: 277

sub javaTypesNoDeclare {
  
  my $syms = undef;

if ($globalTrace) { printf("javaTypesNoDeclare at q/java.qon:277\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $syms = cons(boxString("pair"), cons(boxString("box"), $undef));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: javaTypesNoDeclare

  if ($globalTrace) {printf("Leaving \n")}

  return($syms);

}


#Building function javaFuncMap from line: 286

sub javaFuncMap {
  my $aSym = shift;

  my $symMap = undef;

if ($globalTrace) { printf("javaFuncMap at q/java.qon:286\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("symbol", boxType($aSym))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $symMap = alistCons(boxSymbol("printf"), boxSymbol("System.out.printf"), alistCons(boxSymbol(stringConcatenate("q", "log")), boxSymbol("System.err.printf"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("null"), $undef)))))))));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( truthy(assoc(stringify($aSym), $symMap))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: javaFuncMap

      if ($globalTrace) {printf("Leaving \n")}

      return(cdr(assoc(stringify($aSym), $symMap)));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: javaFuncMap

      if ($globalTrace) {printf("Leaving \n")}

      return($aSym);

    };

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: javaFuncMap

    if ($globalTrace) {printf("Leaving \n")}

    return($aSym);

  };

}


#Building function javaType from line: 307

sub javaType {
  my $node = shift;

  
if ($globalTrace) { printf("javaType at q/java.qon:307\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(subnameof($node), boxString("struct"))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\npublic class %s {\n", stringify(first(codeof($node))))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\npublic String caller =\"\";")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    javaStruct(cdr(codeof($node)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n};\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( inList(boxString(stringify(first(codeof($node)))), javaTypesNoDeclare())) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("public class %s extends %s {};\n", stringify(first(codeof($node))), stringify(javaTypeMap(listLast(codeof($node)))))
      ;

    };

  };

}


#Building function javaTypes from line: 324

sub javaTypes {
  my $nodes = shift;

  
if ($globalTrace) { printf("javaTypes at q/java.qon:324\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($nodes)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    javaType(car($nodes))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    javaTypes(cdr($nodes))
    ;

  };

}


#Building function javaCompile from line: 330

sub javaCompile {
  my $filename = shift;

  my $programStr = "";
my $tree = undef;
my $program = undef;

if ($globalTrace) { printf("javaCompile at q/java.qon:330\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "package quonverter;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "import java.nio.file.Files;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "import java.nio.file.Paths;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "import java.io.IOException;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "import java.io.UnsupportedEncodingException;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("class MyProgram {\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\npublic String caller =\"\";")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $programStr = read_file($filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = readSexpr($programStr, $filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $program = alistCons(boxString("includes"), astIncludes(first($tree)), alistCons(boxString("types"), astTypes(second($tree)), alistCons(boxString("functions"), astFunctions(third($tree)), $undef)));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $program = mergeIncludes($program);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  javaIncludes(cdr(assoc("includes", $program)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  javaTypes(childrenof(cdr(assoc("types", $program))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("public boolean globalStackTrace = false;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("public boolean globalStepTrace = false;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("public boolean globalTrace = false;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("public boolean releaseMode = false;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("public String FILE = null;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("public Integer LINE = 0;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("public static Integer globalArgsCount = 0;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("public static String globalArgs[];\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\npublic boolean isNil(Box p) {\n    return p == null;\n}\n\n\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  javaFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", $program))))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "public static void main(String args[]) {\nglobalArgs = args;\nglobalArgsCount = args.length;MyProgram mp = new MyProgram(); mp.start();\n}")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("}\n")
  ;

}


#Building function luaFunctionArgs from line: 4

sub luaFunctionArgs {
  my $indent = shift;
my $tree = shift;

  
if ($globalTrace) { printf("luaFunctionArgs at q/lua.qon:4\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    display(second($tree))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil(cddr($tree))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf(",")
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    luaFunctionArgs($indent, cddr($tree))
    ;

  };

}


#Building function luaFunction from line: 14

sub luaFunction {
  my $indent = shift;
my $functionDefinition = shift;

  my $fname = "";

if ($globalTrace) { printf("luaFunction at q/lua.qon:14\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $fname = stringify(second($functionDefinition));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("-- Chose function name %s", $fname)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\nfunction %s(", $fname)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  luaFunctionArgs($indent, third($functionDefinition))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf(")\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("print(\"caller: \", caller, \"-> %s\")\n", $fname)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  luaDeclarations(add1($indent), cdr(fourth($functionDefinition)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  luaBody($fname, $indent, cdr(fifth($functionDefinition)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("end\n")
  ;

}


#Building function luaDeclarations from line: 26

sub luaDeclarations {
  my $indent = shift;
my $declarations = shift;

  my $decl = undef;

if ($globalTrace) { printf("luaDeclarations at q/lua.qon:26\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($declarations)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $decl = first($declarations);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("local %s =", stringify(second($decl)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    luaExpressionStart($indent, third($decl))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    luaDeclarations($indent, cdr($declarations))
    ;

  };

}


#Building function luaExpressionStart from line: 42

sub luaExpressionStart {
  my $indent = shift;
my $program = shift;

  
if ($globalTrace) { printf("luaExpressionStart at q/lua.qon:42\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($program)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isList($program)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString(stringify(car($program)), "get-struct")) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printf("%s.%s", stringify(second($program)), stringify(third($program)))
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalString(stringify(car($program)), ">")) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf("greaterthan(")
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          luaExpression($indent, cdr($program))
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf(")")
          ;

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalString(stringify(car($program)), "=")) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("equal(")
            ;
            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            luaExpression($indent, cdr($program))
            ;
            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf(")")
            ;

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("%s(", stringify(car($program)))
            ;
            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            luaExpression($indent, cdr($program))
            ;
            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf(")")
            ;

          };

        };

      };

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      luaExpression($indent, $program)
      ;

    };

  };

}


#Building function luaExpression from line: 84

sub luaExpression {
  my $indent = shift;
my $program = shift;

  
if ($globalTrace) { printf("luaExpression at q/lua.qon:84\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($program)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isList($program)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( isList(car($program))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        luaExpressionStart($indent, car($program))
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        display(car($program))
        ;

      };
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( greaterthan(listLength($program), 1)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printf(", ")
        ;

      } else {
      };
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      luaExpression($indent, cdr($program))
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      display($program)
      ;

    };

  };

}


#Building function luaStatement from line: 112

sub luaStatement {
  my $indent = shift;
my $statement = shift;

  
if ($globalTrace) { printf("luaStatement at q/lua.qon:112\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString(stringify(car($statement)), "if")) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent($indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("if ")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    add1($indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    luaExpressionStart(add1($indent), second($statement))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(" then\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    luaBody($caller, add1($indent), cdr(third($statement)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent($indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("else\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    luaBody($caller, add1($indent), cdr(fourth($statement)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent($indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("end\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalString(stringify(car($statement)), "set")) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printIndent($indent)
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("%s = ", stringify(second($statement)))
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      luaExpressionStart(add1($indent), third($statement))
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString(stringify(car($statement)), "set-struct")) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printf("%s.%s = ", stringify(second($statement)), stringify(third($statement)))
        ;
        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        luaExpressionStart($indent, fourth($statement))
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalString(stringify(car($statement)), "return")) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printIndent($indent)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf("return ")
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( greaterthan(listLength($statement), 1)) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            luaExpressionStart($indent, second($statement))
            ;

          } else {
          };
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf("\n")
          ;

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printIndent($indent)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          luaExpressionStart($indent, $statement)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf(";\n")
          ;

        };

      };

    };

  };

}


#Building function luaBody from line: 164

sub luaBody {
  my $local_caller = shift;
my $indent = shift;
my $program = shift;

  my $statement = undef;

if ($globalTrace) { printf("luaBody at q/lua.qon:164\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($program)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $statement = car($program);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("caller = \"%s:%s:%d\"\n", $local_caller, unBoxString(getTagFail($statement, boxString("filename"), boxString("Unknown file"))), unBoxInt(getTagFail($statement, boxString("line"), boxInt(-1))))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    luaStatement(add1($indent), $statement)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    luaBody($local_caller, $indent, cdr($program))
    ;

  };

}


#Building function luaFunctions from line: 176

sub luaFunctions {
  my $indent = shift;
my $program = shift;

  
if ($globalTrace) { printf("luaFunctions at q/lua.qon:176\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($program)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    luaFunction($indent, car($program))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    luaFunctions($indent, cdr($program))
    ;

  };

}


#Building function luaProgram from line: 188

sub luaProgram {
  my $program = shift;

  
if ($globalTrace) { printf("luaProgram at q/lua.qon:188\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  luaIncludes($undef)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  luaFunctions(0, cdr(third($program)))
  ;

}


#Building function luaIncludes from line: 195

sub luaIncludes {
  my $nodes = shift;

  
if ($globalTrace) { printf("luaIncludes at q/lua.qon:195\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "\nfunction luaDump(o)\n   if type(o) == 'table' then\n      local s = '{ '\n      for k,v in pairs(o) do\n         if type(k) ~= 'number' then k = '\"'..k..'\"' end\n         s = s .. '['..k..'] = ' .. luaDump(v) .. ','\n      end\n      return s .. '} '\n   else\n      return tostring(o)\n   end\nend\nprintf = function(s,...)\nreturn io.write(s:format(...))\nend -- function\n    \nfunction stringConcatenate(a,b)\nreturn a..b\nend\n    \nfunction getStringArray(index, arr)\nreturn arr[index]\nend\n       \nfunction luaWriteFile(name, data)  \nlocal file = io.open(name, \"w\")\nfile:write(data)\nfile:close(file)\nend\n    function luaSubstring(s, start, length)\nreturn string.sub(s, start, start+length)\nend\n    \n    function luaReadFile(file)\n      local f = assert(io.open(file, \"rb\"))\n      local content = f:read(\"*all\")      f:close()\n      return content\n    end\n     \nfunction equalString(a,b)\n        return a==b;\n     end\n    \n     function new()\n        return {};\n     end\n    \n     function isNil(val)\n        return val == nil;\n     end\n    \n     function getEnv(key)\n        return os.getenv(key);\n     end\n    \n    function panic(s)\n      print(s);\n    os.exit()\n    end\n    \n    function sub(a, b) \n      return a - b; \n    end\n\n    function mult(a, b) \n      return a * b;\n    end\n    \n    function greaterthan(a, b)\n      return a > b;\n    end\n    \n    function subf(a, b) \n      return a - b;\n    end\n    \n    function multf(a, b)\n      return a * b;\n    end\n    \n    function greaterthanf(a, b)\n      return a > b;\n    end\n    \n    function equal(a, b)\n      return a == b;\n    end\n    \n    function andBool(a, b)\n      return a == b;\n    end\n    \n    function string_length(s)\n      return strlen(s);\n    end\n    \n    function setSubString(target, start, source)\n      panic(\"stub\");\n      end\n    \n    function sub_string(s, start, length)\n      panic(\"stub\");\n    end\n    \n    function intToString(a)\n      panic(\"stub\")\n return a\n    end\n\n    function gc_malloc(size)\n      return \"\"\n    end\n    \n    function makeArray(length)\n      return {}\n    end\n    \n    function at(arr, index)\n      return arr[index+1];\n    end\n    \n    function setAt(array, index, value)\n      array[index+1] = value;\n    end\n    \n    function read_file(file)\n      local f = io.open(file, \"r\")\n      local content = \"\"\n      local length = 0\n\n      while f:read(0) ~= \"\" do\n          local current = f:read(\"*all\")\n\n          print(#current, length)\n          length = length + #current\n\n          content = content .. current\n      end\n\n      return content\n    end\n    \n    function write_file(filename, data)\n      local file = io.open(filename,'w')\n      file:write(tostring(data))\n      file:close()\n    end\n    \n    caller=\"main\";\n    \n    globalArgs={};\n    globalArgsCount=0;\n    globalTrace = false;\n    globalStepTrace = false;\n\n    function main()\n      globalArgs = arg;\n      globalArgsCount = #arg + 1;\n      return start();\n    end\n    \n")
  ;

}


#Building function luaCompile from line: 203

sub luaCompile {
  my $filename = shift;

  my $tree = undef;

if ($globalTrace) { printf("luaCompile at q/lua.qon:203\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = loadQuon($filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = loadIncludes($tree);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrowalk($tree);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrosingle($tree, "write-file", "luaWriteFile");
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrosingle($tree, "read-file", "luaReadFile");
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrosingle($tree, "string-length", "string.len");
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrosingle($tree, "sub-string", "luaSubstring");
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrosingle($tree, "stringLength", "string.len");
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  luaProgram($tree)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("function main()\nglobalArgs = arg\nglobalArgsCount = #arg\nstart()\nend\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("main()")
  ;

}


#Building function not from line: 3

sub not {
  my $a = shift;

  
if ($globalTrace) { printf("not at q/boolean.qon:3\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( $a) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: not

    if ($globalTrace) {printf("Leaving \n")}

    return($false);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: not

    if ($globalTrace) {printf("Leaving \n")}

    return($true);

  };

}


#Building function andBool from line: 10

sub andBool {
  my $a = shift;
my $b = shift;

  
if ($globalTrace) { printf("andBool at q/boolean.qon:10\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( $a) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( $b) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: andBool

      if ($globalTrace) {printf("Leaving \n")}

      return($true);

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: andBool

      if ($globalTrace) {printf("Leaving \n")}

      return($false);

    };

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: andBool

    if ($globalTrace) {printf("Leaving \n")}

    return($false);

  };

}


#Building function nand from line: 20

sub nand {
  my $a = shift;
my $b = shift;

  
if ($globalTrace) { printf("nand at q/boolean.qon:20\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: nand

  if ($globalTrace) {printf("Leaving \n")}

  return(not(andBool($a, $b)));

}


#Building function xor from line: 25

sub xor {
  my $a = shift;
my $b = shift;

  
if ($globalTrace) { printf("xor at q/boolean.qon:25\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: xor

  if ($globalTrace) {printf("Leaving \n")}

  return(nand(nand($a, nand($a, $b)), nand($b, nand($a, $b))));

}


#Building function imaFunctionArgs from line: 4

sub imaFunctionArgs {
  my $indent = shift;
my $tree = shift;

  
if ($globalTrace) { printf("imaFunctionArgs at q/imaginary.qon:4\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    display(second($tree))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(": ")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    display(first($tree))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil(cddr($tree))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf(", ")
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    imaFunctionArgs($indent, cddr($tree))
    ;

  };

}


#Building function imaFunction from line: 16

sub imaFunction {
  my $indent = shift;
my $functionDefinition = shift;

  my $fname = "";

if ($globalTrace) { printf("imaFunction at q/imaginary.qon:16\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $fname = stringify(second($functionDefinition));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\nfu %s(", $fname)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  imaFunctionArgs($indent, third($functionDefinition))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf(") ")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("-> %s", stringify(first($functionDefinition)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  imaDeclarations(add1($indent), cdr(fourth($functionDefinition)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan(listLength(cdr(fourth($functionDefinition))), 0)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(" ")
    ;

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printIndent($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("in\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  imaBody($fname, $indent, cdr(fifth($functionDefinition)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("end function\n")
  ;

}


#Building function imaDeclarations from line: 37

sub imaDeclarations {
  my $indent = shift;
my $declarations = shift;

  my $decl = undef;

if ($globalTrace) { printf("imaDeclarations at q/imaginary.qon:37\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($declarations)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $decl = first($declarations);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent($indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s: %s ", stringify(second($decl)), stringify(first($decl)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    imaExpressionStart($indent, third($decl))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    imaDeclarations($indent, cdr($declarations))
    ;

  };

}


#Building function imaExpressionStart from line: 56

sub imaExpressionStart {
  my $indent = shift;
my $program = shift;

  
if ($globalTrace) { printf("imaExpressionStart at q/imaginary.qon:56\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($program)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isList($program)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString(stringify(car($program)), "get-struct")) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printf("%s.%s", stringify(second($program)), stringify(third($program)))
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalString(stringify(car($program)), ">")) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf("greaterthan(")
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          imaExpression($indent, cdr($program))
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf(")")
          ;

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalString(stringify(car($program)), "=")) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("equal(")
            ;
            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            imaExpression($indent, cdr($program))
            ;
            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf(")")
            ;

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("%s(", stringify(car($program)))
            ;
            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            imaExpression($indent, cdr($program))
            ;
            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf(")")
            ;

          };

        };

      };

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      imaExpression($indent, $program)
      ;

    };

  };

}


#Building function imaExpression from line: 98

sub imaExpression {
  my $indent = shift;
my $program = shift;

  
if ($globalTrace) { printf("imaExpression at q/imaginary.qon:98\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($program)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isList($program)) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( isList(car($program))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        imaExpressionStart($indent, car($program))
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        display(car($program))
        ;

      };
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( greaterthan(listLength($program), 1)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printf(", ")
        ;

      } else {
      };
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      imaExpression($indent, cdr($program))
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      display($program)
      ;

    };

  };

}


#Building function imaStatement from line: 126

sub imaStatement {
  my $indent = shift;
my $statement = shift;

  
if ($globalTrace) { printf("imaStatement at q/imaginary.qon:126\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString(stringify(car($statement)), "if")) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent($indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("if ")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    add1($indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    imaExpressionStart(add1($indent), second($statement))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(" then\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    imaBody($caller, add1($indent), cdr(third($statement)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent($indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("else\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    imaBody($caller, add1($indent), cdr(fourth($statement)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent($indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("end\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalString(stringify(car($statement)), "set")) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printIndent($indent)
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("%s = ", stringify(second($statement)))
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      imaExpressionStart(add1($indent), third($statement))
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf(";\n")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalString(stringify(car($statement)), "set-struct")) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printIndent($indent)
        ;
        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printf("%s.%s = ", stringify(second($statement)), stringify(third($statement)))
        ;
        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        imaExpressionStart($indent, fourth($statement))
        ;
        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printf(";\n")
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalString(stringify(car($statement)), "return")) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printIndent($indent)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf("return; ")
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( greaterthan(listLength($statement), 1)) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            imaExpressionStart($indent, second($statement))
            ;

          } else {
          };
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf("\n")
          ;

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printIndent($indent)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          imaExpressionStart($indent, $statement)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf(";\n")
          ;

        };

      };

    };

  };

}


#Building function imaBody from line: 181

sub imaBody {
  my $local_caller = shift;
my $indent = shift;
my $program = shift;

  my $statement = undef;

if ($globalTrace) { printf("imaBody at q/imaginary.qon:181\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($program)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $statement = car($program);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    imaStatement(add1($indent), $statement)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    imaBody($local_caller, $indent, cdr($program))
    ;

  };

}


#Building function imaFunctions from line: 192

sub imaFunctions {
  my $indent = shift;
my $program = shift;

  
if ($globalTrace) { printf("imaFunctions at q/imaginary.qon:192\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($program)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    imaFunction($indent, car($program))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    imaFunctions($indent, cdr($program))
    ;

  };

}


#Building function imaTypeDecl from line: 202

sub imaTypeDecl {
  my $l = shift;

  my $name = "";
my $body = undef;

if ($globalTrace) { printf("imaTypeDecl at q/imaginary.qon:202\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $name = stringify(first($l));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $body = cdr($l);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan(listLength($l), 2)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent(1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s is ", $name)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    displayList($body, 0, $true)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(";\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printIndent(1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s is %s;\n", $name, stringify(second($l)))
    ;

  };

}


#Building function imaStructComponents from line: 227

sub imaStructComponents {
  my $node = shift;

  
if ($globalTrace) { printf("imaStructComponents at q/imaginary.qon:227\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    imaTypeDecl(car($node))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    imaStructComponents(cdr($node))
    ;

  };

}


#Building function imaStruct from line: 233

sub imaStruct {
  my $node = shift;

  
if ($globalTrace) { printf("imaStruct at q/imaginary.qon:233\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  imaStructComponents(cdr(car($node)))
  ;

}


#Building function imaTypeMap from line: 236

sub imaTypeMap {
  my $aSym = shift;

  my $symMap = undef;

if ($globalTrace) { printf("imaTypeMap at q/imaginary.qon:236\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), $undef));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( truthy(assoc(stringify($aSym), $symMap))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: imaTypeMap

    if ($globalTrace) {printf("Leaving \n")}

    return(cdr(assoc(stringify($aSym), $symMap)));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: imaTypeMap

    if ($globalTrace) {printf("Leaving \n")}

    return($aSym);

  };

}


#Building function imaType from line: 248

sub imaType {
  my $node = shift;

  my $name = "";
my $body = undef;

if ($globalTrace) { printf("imaType at q/imaginary.qon:248\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $name = stringify(first($node));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $body = cdr($node);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isList(first($body))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\ntype %s is struct (\n", $name)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    imaStruct($body)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(");\n")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("type")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    imaTypeDecl($node)
    ;

  };

}


#Building function imaTypes from line: 263

sub imaTypes {
  my $indent = shift;
my $nodes = shift;

  
if ($globalTrace) { printf("imaTypes at q/imaginary.qon:263\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($nodes)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    imaType(car($nodes))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    imaTypes($indent, cdr($nodes))
    ;

  };

}


#Building function imaProgram from line: 272

sub imaProgram {
  my $program = shift;

  
if ($globalTrace) { printf("imaProgram at q/imaginary.qon:272\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  imaIncludes(0, cdr(first($program)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\nTypes:\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  imaTypes(0, cdr(second($program)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\nFunctions:\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  imaFunctions(0, cdr(third($program)))
  ;

}


#Building function imaIncludes from line: 282

sub imaIncludes {
  my $indent = shift;
my $nodes = shift;

  
if ($globalTrace) { printf("imaIncludes at q/imaginary.qon:282\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("Includes: \n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  displayList($nodes, 0, $true)
  ;

}


#Building function imaCompile from line: 289

sub imaCompile {
  my $filename = shift;

  my $tree = undef;

if ($globalTrace) { printf("imaCompile at q/imaginary.qon:289\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = loadQuon("compiler.qon");
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = loadIncludes($tree);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrowalk($tree);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrosingle($tree, "write-file", "imaWriteFile");
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrosingle($tree, "read-file", "imaReadFile");
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrosingle($tree, "string-length", "string.len");
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrosingle($tree, "sub-string", "imaSubstring");
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrosingle($tree, "stringLength", "string.len");
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  imaProgram($tree)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("function main()\nglobalArgs = arg\nglobalArgsCount = #arg\nstart()\nend\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("main()")
  ;

}


#Building function bashdisplays from line: 5

sub bashdisplays {
  my $s = shift;

  
if ($globalTrace) { printf("bashdisplays at q/bash.qon:5\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", $s)
  ;

}


#Building function bashFunctionArgs from line: 11

sub bashFunctionArgs {
  my $decls = shift;
my $argNum = shift;
my $indent = shift;

  
if ($globalTrace) { printf("bashFunctionArgs at q/bash.qon:11\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($decls)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("local %s=\"%s%s", stringify(second($decls)), dollar(), stringify(boxInt($argNum)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\" ;\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashFunctionArgs(cdr(cdr($decls)), add(1, $argNum), $indent)
    ;

  };

}


#Building function bashExpression from line: 26

sub bashExpression {
  my $tree = shift;
my $indent = shift;
my $statement = shift;

  my $thing = undef;

if ($globalTrace) { printf("bashExpression at q/bash.qon:26\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isList($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equal(1, listLength($tree))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      display(car($tree))
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalBox(boxString("return"), car($tree))) {
      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        bashdisplays("()")
        ;

      };

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      $thing = first($tree);
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalBox(boxSymbol("get-struct"), $thing)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printf("%s->%s", stringify(second($tree)), stringify(third($tree)))
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalBox(boxSymbol("new"), $thing)) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf("malloc(sizeof(%s))", stringify(third($tree)))
          ;

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( equalBox(boxSymbol("passthrough"), $thing)) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf("%s", stringify(second($tree)))
            ;

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            if ( equalBox(boxSymbol("binop"), $thing)) {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf("(")
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              bashExpression(third($tree), $indent, $false)
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf(" %s ", stringify(second($tree)))
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              bashExpression(fourth($tree), $indent, $false)
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf(")")
              ;

            } else {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

              if ( $statement) {                if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

                printf("%s ", stringify(bashFuncMap(car($tree))))
                ;
                if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

                bashRecurList(cdr($tree), $indent)
                ;

              } else {                if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

                printf("%s(%s ", dollar(), stringify(bashFuncMap(car($tree))))
                ;
                if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

                bashRecurList(cdr($tree), $indent)
                ;
                if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

                printf(")")
                ;

              };

            };

          };

        };

      };

    };

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    display(bashVarOrLit($tree))
    ;

  };

}


#Building function bashVarOrLit from line: 102

sub bashVarOrLit {
  my $a = shift;

  
if ($globalTrace) { printf("bashVarOrLit at q/bash.qon:102\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("symbol", boxType($a))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: bashVarOrLit

    if ($globalTrace) {printf("Leaving \n")}

    return(boxSymbol(stringConcatenate(dollar(), stringify($a))));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: bashVarOrLit

    if ($globalTrace) {printf("Leaving \n")}

    return($a);

  };

}


#Building function bashRecurList from line: 111

sub bashRecurList {
  my $expr = shift;
my $indent = shift;

  
if ($globalTrace) { printf("bashRecurList at q/bash.qon:111\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($expr)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashExpression(car($expr), $indent, $false)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil(cdr($expr))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      bashdisplays("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      bashdisplays(" ")
      ;
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      bashRecurList(cdr($expr), $indent)
      ;

    };

  };

}


#Building function bashIf from line: 128

sub bashIf {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("bashIf at q/bash.qon:128\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  bashdisplays("if (( ")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  bashExpression(second($node), 0, $false)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  bashdisplays(" )) ; then ")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  bashBody(cdr(third($node)), add1($indent))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  bashdisplays(" else ")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  bashBody(cdr(fourth($node)), add1($indent))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  bashdisplays("fi")
  ;

}


#Building function bashSetStruct from line: 141

sub bashSetStruct {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("bashSetStruct at q/bash.qon:141\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s_%s%s=", dollar(), stringify(second($node)), dollar(), stringify(third($node)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  bashExpression(fourth($node), $indent, $false)
  ;

}


#Building function bashGetStruct from line: 152

sub bashGetStruct {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("bashGetStruct at q/bash.qon:152\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s%s_%s%s", dollar(), stringify(first($node)), dollar(), stringify(second($node)))
  ;

}


#Building function bashSet from line: 162

sub bashSet {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("bashSet at q/bash.qon:162\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  display(first(cdr($node)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("=")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  bashExpression(third($node), $indent, $false)
  ;

}


#Building function bashReturn from line: 169

sub bashReturn {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("bashReturn at q/bash.qon:169\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine($indent)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equal(listLength($node), 1)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashdisplays("return;")
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashdisplays("return ")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashExpression(cadr($node), $indent, $false)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashdisplays(";")
    ;

  };

}


#Building function bashStatement from line: 180

sub bashStatement {
  my $node = shift;
my $indent = shift;

  
if ($globalTrace) { printf("bashStatement at q/bash.qon:180\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalBox(boxString("set"), first($node))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashSet($node, $indent)
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( equalBox(boxString("set-struct"), first($node))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      bashSetStruct($node, $indent)
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( equalBox(boxString("if"), first($node))) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        bashIf($node, $indent)
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( equalBox(boxString("return"), first($node))) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          bashReturn($node, $indent)
          ;

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          newLine($indent)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          bashExpression($node, $indent, $true)
          ;

        };

      };

    };

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  bashdisplays(" \n")
  ;

}


#Building function bashBody from line: 198

sub bashBody {
  my $tree = shift;
my $indent = shift;

  my $code = undef;

if ($globalTrace) { printf("bashBody at q/bash.qon:198\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $code = $tree;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( isNil($code)) {
    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      $code = car($tree);
      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( not($releaseMode)) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        printf("\nif (( $globalTrace )) ; then\n    caller=\"from %s:%s\"\nfi", stringify(getTagFail(car($code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), stringify(getTagFail(car($code), boxString("line"), boxString("Line missing"))))
        ;

      } else {
      };

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( not($releaseMode)) {
    } else {
    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashStatement($code, $indent)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashBody(cdr($tree), $indent)
    ;

  };

}


#Building function bashDeclarations from line: 221

sub bashDeclarations {
  my $decls = shift;
my $indent = shift;

  my $decl = undef;

if ($globalTrace) { printf("bashDeclarations at q/bash.qon:221\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($decls)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $decl = car($decls);
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("local %s=\"", stringify(second($decl)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashExpression(third($decl), $indent, $false)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\";\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashDeclarations(cdr($decls), $indent)
    ;

  };

}


#Building function bashFunction from line: 234

sub bashFunction {
  my $node = shift;

  my $name = undef;

if ($globalTrace) { printf("bashFunction at q/bash.qon:234\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $name = second($node);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("\n\n#Building function %s from line:%s", stringify($name), stringify(getTag($name, boxString("line"))))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  newLine(0)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isNil($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    newLine(0)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("%s(", stringify(second($node)))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf(") {")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    newLine(1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashFunctionArgs(third($node), 1, 1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashDeclarations(cdr(fourth($node)), 1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( $releaseMode) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("\nif (( $globalTrace )) ; then\n    echo \"%s at %s:%s \" $caller\nfi", stringify($name), stringify(getTag($name, boxString("filename"))), stringify(getTag($name, boxString("line"))))
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( $releaseMode) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {
    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashBody(cdr(fifth($node)), 1)
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( $releaseMode) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("")
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      printf("\nif (( $globalTrace ))\n    echo \"Leaving %s\\n\"\n", stringify($name))
      ;

    };
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n}\n")
    ;

  };

}


#Building function bashForwardDeclaration from line: 267

sub bashForwardDeclaration {
  my $node = shift;

  
if ($globalTrace) { printf("bashForwardDeclaration at q/bash.qon:267\n") }

}


#Building function bashForwardDeclarations from line: 270

sub bashForwardDeclarations {
  my $tree = shift;

  
if ($globalTrace) { printf("bashForwardDeclarations at q/bash.qon:270\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashForwardDeclaration(car($tree))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashForwardDeclarations(cdr($tree))
    ;

  };

}


#Building function bashFunctions from line: 276

sub bashFunctions {
  my $tree = shift;

  
if ($globalTrace) { printf("bashFunctions at q/bash.qon:276\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($tree)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashFunction(car($tree))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashFunctions(cdr($tree))
    ;

  };

}


#Building function bashIncludes from line: 282

sub bashIncludes {
  my $nodes = shift;

  
if ($globalTrace) { printf("bashIncludes at q/bash.qon:282\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "\n\n#define true 1\n#define false 0\n\n\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\nbool releaseMode = false;\n\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n")
  ;

}


#Building function bashTypeDecl from line: 290

sub bashTypeDecl {
  my $l = shift;

  
if ($globalTrace) { printf("bashTypeDecl at q/bash.qon:290\n") }

}


#Building function bashStructComponents from line: 294

sub bashStructComponents {
  my $node = shift;

  
if ($globalTrace) { printf("bashStructComponents at q/bash.qon:294\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($node)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashTypeDecl(car($node))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashStructComponents(cdr($node))
    ;

  };

}


#Building function bashStruct from line: 300

sub bashStruct {
  my $node = shift;

  
if ($globalTrace) { printf("bashStruct at q/bash.qon:300\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  bashStructComponents(cdr($node))
  ;

}


#Building function bashTypeMap from line: 303

sub bashTypeMap {
  my $aSym = shift;

  my $symMap = undef;

if ($globalTrace) { printf("bashTypeMap at q/bash.qon:303\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), $undef));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( truthy(assoc(stringify($aSym), $symMap))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: bashTypeMap

    if ($globalTrace) {printf("Leaving \n")}

    return(cdr(assoc(stringify($aSym), $symMap)));

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: bashTypeMap

    if ($globalTrace) {printf("Leaving \n")}

    return($aSym);

  };

}


#Building function bashFuncMap from line: 313

sub bashFuncMap {
  my $aSym = shift;

  my $symMap = undef;

if ($globalTrace) { printf("bashFuncMap at q/bash.qon:313\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( equalString("symbol", boxType($aSym))) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), $undef)))))));
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( truthy(assoc(stringify($aSym), $symMap))) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: bashFuncMap

      if ($globalTrace) {printf("Leaving \n")}

      return(cdr(assoc(stringify($aSym), $symMap)));

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: bashFuncMap

      if ($globalTrace) {printf("Leaving \n")}

      return($aSym);

    };

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: bashFuncMap

    if ($globalTrace) {printf("Leaving \n")}

    return($aSym);

  };

}


#Building function bashType from line: 344

sub bashType {
  my $node = shift;

  
if ($globalTrace) { printf("bashType at q/bash.qon:344\n") }

}


#Building function bashTypes from line: 349

sub bashTypes {
  my $nodes = shift;

  
if ($globalTrace) { printf("bashTypes at q/bash.qon:349\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( isEmpty($nodes)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#Returnvoid

    
    return;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashType(car($nodes))
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    bashTypes(cdr($nodes))
    ;

  };

}


#Building function bashCompile from line: 359

sub bashCompile {
  my $filename = shift;

  my $tree = undef;
my $replace = undef;

if ($globalTrace) { printf("bashCompile at q/bash.qon:359\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  qlog("//Scanning file...%s\n", $filename)
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = loadQuon($filename);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  qlog("//Building sexpr\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  qlog("Loading shim bash\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = buildProg(cons(boxString("q/shims/bash.qon"), getIncludes($tree)), getTypes($tree), getFunctions($tree));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  qlog("Loading all includes\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = loadIncludes($tree);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  qlog("Applying macros\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrowalk($tree);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), $undef));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $tree = macrolist($tree, stringConcatenate("q", "log"), $replace);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  qlog("//Printing program\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  bashIncludes(cdr(first($tree)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  bashTypes(cdr(second($tree)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  bashdisplays("Box* globalStackTrace = NULL;\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  bashdisplays("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  bashForwardDeclarations(cdr(third($tree)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  bashdisplays("\n\n//End forward declarations\n\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  bashFunctions(cdr(third($tree)))
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  bashdisplays("\n")
  ;
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

  qlog("//Done printing program\n")
  ;

}


#Building function start from line: 5

sub start {
  
  my $runTests = 0;
my $cmdLine = undef;
my $filenameBox = undef;
my $filename = "";
my $runPerl = 0;
my $runJava = 0;
my $runAst = 0;
my $runNode = 0;
my $runNode2 = 0;
my $runLua = 0;
my $runIma = 0;
my $runAnsi2 = 0;
my $runAnsi3 = 0;
my $runBash = 0;
my $runTree = 0;

if ($globalTrace) { printf("start at compiler.qon:5\n") }
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $cmdLine = listReverse(argList($globalArgsCount, 0, $globalArgs));
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( greaterthan(listLength($cmdLine), 1)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $filenameBox = second($cmdLine);

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    $filenameBox = boxString("compiler.qon");

  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $filename = unBoxString($filenameBox);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $releaseMode = inList(boxString("--release"), $cmdLine);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $runTests = inList(boxString("--test"), $cmdLine);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $runJava = inList(boxString("--java"), $cmdLine);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $runPerl = inList(boxString("--perl"), $cmdLine);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $runAst = inList(boxString("--ast"), $cmdLine);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $runTree = inList(boxString("--tree"), $cmdLine);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $runNode = inList(boxString("--node"), $cmdLine);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $runNode2 = inList(boxString("--node2"), $cmdLine);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $runLua = inList(boxString("--lua"), $cmdLine);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $runIma = inList(boxString("--ima"), $cmdLine);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $runAnsi2 = inList(boxString("--ansi2"), $cmdLine);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $runAnsi3 = inList(boxString("--ansi3"), $cmdLine);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $runBash = inList(boxString("--bash"), $cmdLine);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $globalTrace = inList(boxString("--trace"), $cmdLine);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  $globalStepTrace = inList(boxString("--steptrace"), $cmdLine);
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( inList(boxString("--help"), $cmdLine)) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("Usage: quon file [options]\n\nNote the options go after the file name\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("Options:\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("  --help      Display this help\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("  --release   Compile in release mode\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("  --test      Run the test suite\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("  --java      Compile to Java\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("  --perl      Compile to Perl\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("  --ast       Compile to the Abstract Syntax Tree\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("  --tree      Compile to an s-expression tree\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("  --node      Compile to Node.js\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("  --node2      Compile to Node.js, new outputter\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("  --lua       Compile to Lua\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("  --ima       Compile to Imaginary, the human-friendly language\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("  --ansi2     Compile to ANSI C, (quon version 2)\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("  --ansi3     Compile to ANSI C (quon version 3)\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("  --bash      Compile to Bash\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("  --trace     Trace execution\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("  --steptrace Step trace execution\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("  --help      Display this help\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    exit(0)
    ;

  } else {
  };
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

  if ( $runTests) {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test0()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test1()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test2()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test3()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test4()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test5()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test6()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test7()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test8()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test9()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test10()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test12()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test13()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test15()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test16()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test17()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test18()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test19()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test20()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test21()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test22()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test23()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test24()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    test25()
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    printf("\n\nAfter all that hard work, I need a beer...\n")
    ;
    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

    beers(9)
    ;

  } else {    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

    if ( $runTree) {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

      display(macrowalk(treeCompile($filename)))
      ;

    } else {      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

      if ( $runAst) {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

        astCompile($filename)
        ;

      } else {        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

        if ( $runNode) {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          nodeCompile($filename)
          ;
          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

          printf("\n")
          ;

        } else {          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

          if ( $runNode2) {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

            printf(StringListJoin(flatten(node2Compile($filename)), " "))
            ;

          } else {            if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

            if ( $runPerl) {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              perlCompile($filename)
              ;
              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

              printf("\n")
              ;

            } else {              if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

              if ( $runJava) {                if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

                javaCompile($filename)
                ;
                if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

                printf("\n")
                ;

              } else {                if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

                if ( $runLua) {                  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

                  luaCompile($filename)
                  ;
                  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

                  printf("\n")
                  ;

                } else {                  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

                  if ( $runIma) {                    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

                    imaCompile($filename)
                    ;
                    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

                    printf("\n")
                    ;

                  } else {                    if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

                    if ( $runAnsi2) {                      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

                      ansi2Compile($filename)
                      ;
                      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

                      printf("\n")
                      ;

                    } else {                      if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

                      if ( $runAnsi3) {                        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

                        ansi3Compile($filename)
                        ;
                        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

                        printf("\n")
                        ;

                      } else {                        if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

                        if ( $runBash) {                          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

                          bashCompile($filename)
                          ;
                          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

                          printf("\n")
                          ;

                        } else {                          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

                          ansi3Compile($filename)
                          ;
                          if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard expression

                          printf("\n")
                          ;

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
  if ($globalStepTrace) {printf("StepTrace %s:%d\n", __FILE__, __LINE__)}

#standard return: start

  if ($globalTrace) {printf("Leaving \n")}

  return(0);

}
;
$globalArgs = [ 1, @ARGV];$globalArgsCount = scalar(@ARGV)+1;
start();
