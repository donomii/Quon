use strict;
use warnings;
use v5.10;

no warnings 'recursion';
our $^M = 10_000;
our $globalArgsCount;
our $globalArgs;
our $releaseMode;
our $globalTrace;
our $globalStepTrace;
our $globalStackTrace;
our $caller;
our $false = 0;
our $true = 1;
my $stderr = \*STDERR;
our $quonGlobalArgs;

# Forward declarations
sub notBool;
sub andBool;
sub orBool;
sub nand;
sub xor;
sub lessThan;
sub parserValidateBodyForm;
sub readBodySexpr;
sub readSingleSexpr;
sub readBodyFragment;
sub readFunctionsSexpr;
sub readFunctionsFragment;
sub readTypesSexpr;
sub readTypesFragment;
sub bodyTreeToString;
sub compileBodySectionString;
sub compileBodyString;
sub compileBodyForm;
sub compileFunctionsSectionString;
sub compileFunctionsString;
sub compileFunctionsSection;
sub compileTypesSectionString;
sub compileTypesString;
sub compileTypesSection;
sub compileProgramBareString;
sub node2FunctionArgs;
sub node2Atom;
sub node2Expression;
sub node2RecurList;
sub node2If;
sub node2SetStruct;
sub node2Set;
sub node2Return;
sub node2Statement;
sub node2Body;
sub node2Declarations;
sub node2Function;
sub node2Functions;
sub node2Includes;
sub node2Types;
sub node2FuncMap;
sub node2MainEntry;
sub node2LoadProgram;
sub node2ProgramTree;
sub node2Program;
sub node2CompileString;
sub node2Compile;
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
sub test14;
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
sub test27;
sub test28;
sub haskellBackslash;
sub haskellDoubleQuote;
sub haskellEscapedBackslash;
sub haskellEscapedDoubleQuote;
sub haskellEscapeString;
sub haskellSafeNameString;
sub haskellSafeName;
sub haskellFieldName;
sub haskellNewName;
sub haskellStringEndsWith;
sub haskellStringStartsWith;
sub haskellPointerBase;
sub haskellTypeIsPointer;
sub haskellTypeMap;
sub haskellDefaultValue;
sub haskellRefType;
sub haskellGlobalVariables;
sub haskellCollectVariablesFromArgs;
sub haskellCollectVariablesFromDecls;
sub haskellCollectVariables;
sub haskellFuncMap;
sub haskellNumberAtom;
sub haskellAtom;
sub haskellArgNames;
sub haskellBindArgs;
sub haskellCall;
sub haskellBinop;
sub haskellGetStruct;
sub haskellNewExpression;
sub haskellExpression;
sub haskellSet;
sub haskellSetStruct;
sub haskellReturn;
sub haskellIf;
sub haskellStatement;
sub haskellBody;
sub haskellFunctionArgsSignature;
sub haskellFunctionArgs;
sub haskellArgRefs;
sub haskellDeclarations;
sub haskellFunction;
sub haskellFunctions;
sub haskellTypeDecl;
sub haskellStructFields;
sub haskellNewStructField;
sub haskellNewStructFields;
sub haskellStructCtorFields;
sub haskellType;
sub haskellTypes;
sub haskellIncludes;
sub haskellMainEntry;
sub haskellApplyTypeAliases;
sub haskellLoadProgram;
sub haskellProgramTree;
sub haskellProgram;
sub haskellCompileString;
sub haskellCompile;
sub javaFunctionArgs;
sub javaAtom;
sub javaExpression;
sub javaRecurList;
sub javaIf;
sub javaSetStruct;
sub javaSet;
sub javaReturn;
sub javaStatement;
sub javaBody;
sub javaDeclarations;
sub javaFunction;
sub javaFunctions;
sub javaIncludes;
sub javaTypeMap;
sub javaPointerBase;
sub javaFuncMap;
sub javaTypeDecl;
sub javaStructComponents;
sub javaStruct;
sub javaType;
sub javaTypes;
sub javaApplyTypeAliases;
sub javaMainEntry;
sub javaLoadProgram;
sub javaProgramTree;
sub javaProgram;
sub javaCompileString;
sub javaCompile;
sub ansi3FunctionArgs;
sub ansi3Atom;
sub ansi3Expression;
sub ansi3RecurList;
sub ansi3If;
sub ansi3SetStruct;
sub ansi3Set;
sub ansi3Return;
sub ansi3TraceReturn;
sub ansi3Statement;
sub ansi3StatementTrace;
sub ansi3StepTrace;
sub ansi3Body;
sub ansi3Declarations;
sub ansi3FunctionTrace;
sub ansi3FunctionStackTrace;
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
sub ansi3LoadProgram;
sub ansi3ProgramTree;
sub ansi3Program;
sub ansi3CompileString;
sub ansi3Compile;
sub dollar;
sub atsymbol;
sub singleQuote;
sub escapedSingleQuote;
sub backslash;
sub escapedDollar;
sub escapedAtSign;
sub escapeSingleQuotes;
sub escapePerlString;
sub getGlobalVariables;
sub collectVariables;
sub perlGlobalVariables;
sub perlMainEntry;
sub collectVariablesFromArgs;
sub collectVariablesFromDecls;
sub appendVariables;
sub perlFunctionArgs;
sub perlAtom;
sub perlExpression;
sub perlRecurList;
sub perlSet;
sub perlSetStruct;
sub perlReturn;
sub perlIf;
sub perlStatement;
sub perlBody;
sub perlGetStruct;
sub perlDeclarations;
sub perlFunction;
sub perlForwardDeclaration;
sub perlForwardDeclarations;
sub perlFunctions;
sub perlIncludes;
sub perlTypes;
sub perlTypeMap;
sub perlFuncMap;
sub perlLoadProgram;
sub perlProgramTree;
sub perlProgram;
sub perlCompileString;
sub perlCompile;
sub readSexpr;
sub parserPanicAt;
sub parserPanicAtNode;
sub parserSymbolIs;
sub parserListStartsWith;
sub parserValidateParens;
sub parserValidateRoot;
sub parserValidateSection;
sub parserIsFunctionDefinition;
sub parserRejectFunctionDefinitions;
sub parserRejectFunctionDefinitionsList;
sub parserValidateProgram;
sub parserValidateFunctions;
sub parserValidateFunction;
sub parserValidateBody;
sub parserValidateStatement;
sub parserValidateReturn;
sub parserValidateSet;
sub parserValidateSetStruct;
sub parserValidateIf;
sub parserValidateBranch;
sub parserValidateExpression;
sub parserValidateExpressionList;
sub sexprTree;
sub loadQuon;
sub getIncludes;
sub getTypes;
sub getFunctions;
sub insertInclude;
sub stringInList;
sub appendMissingIncludes;
sub loadIncludes;
sub buildProg;
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
sub sixth;
sub seventh;
sub eighth;
sub ninth;
sub tenth;
sub eleventh;
sub twelfth;
sub rest;
sub isList;
sub emptyList;
sub isEmpty;
sub listLength;
sub alistCons;
sub assoc;
sub chooseBox;
sub mlistLiteral;
sub doMultiList;
sub isDigit;
sub isUnsignedIntFrom;
sub isInt;
sub isFloatFrom;
sub isFloat;
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
sub printStringTree;
sub macrowalk;
sub macrosingle;
sub macroSymbolSingle;
sub macrolist;
sub filterVoid;
sub filterTokens;
sub finish_token;
sub readString;
sub readComment;
sub isLineBreak;
sub incForNewLine;
sub annotateReadPosition;
sub scan;
sub isOpenBrace;
sub isCloseBrace;
sub skipList;
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
sub boxFloat;
sub assertType;
sub unBoxString;
sub unBoxSymbol;
sub unBoxBool;
sub unBoxInt;
sub unBoxFloat;
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
sub listIndent;
sub listNewLine;
sub argList;
sub tron;
sub troff;
sub stron;
sub stroff;
sub StackTraceMove;
sub StackTracePrint;
sub StackTracePrintHelper;
sub NoStackTrace_list;
sub NoTrace_list;
sub indexOfHelper;
sub indexOf;
sub stringReplace;
sub stringContains;
sub stringContainsHelper;
sub isWhiteSpace;
sub stringTrim;
sub stringSplit;
sub perlIsNil;
sub getEnv;
sub panic;
sub subtract;
sub mult;
sub greaterthan;
sub subf;
sub multf;
sub greaterthanf;
sub equalf;
sub equal;
sub equalString;
sub string_length;
sub setSubString;
sub sub_string;
sub stringConcatenate;
sub intToString;
sub floatToString;
sub read_file;
sub write_file;
sub getStringArray;
sub programArgs;
sub programArgsCount;
sub character;
sub displays;
sub remainder;
sub or;
sub max;
sub min;
sub makeHash;
sub setHash;
sub getHash;
sub inHash;
sub makeArray;
sub setArray;
sub getArray;
sub isNil;
sub start;

# End forward declarations


# Function notBool from line 3

sub notBool {
  my ($a) = @_;
  
  if ( $a ) {
    return $false;

  } else {
    return $true;

  };

}


# Function andBool from line 10

sub andBool {
  my ($a, $b) = @_;
  
  if ( $a ) {
    if ( $b ) {
      return $true;

    } else {
      return $false;

    };

  } else {
    return $false;

  };

}


# Function orBool from line 20

sub orBool {
  my ($a, $b) = @_;
  
  if ( $a ) {
    return $true;

  } else {
    if ( $b ) {
      return $true;

    } else {
      return $false;

    };

  };

}


# Function nand from line 31

sub nand {
  my ($a, $b) = @_;
  
  return notBool(andBool($a, $b));

}


# Function xor from line 35

sub xor {
  my ($a, $b) = @_;
  
  return nand(nand($a, nand($a, $b)), nand($b, nand($a, $b)));

}


# Function lessThan from line 39

sub lessThan {
  my ($a, $b) = @_;
  
  return andBool(notBool(equal($a, $b)), notBool(greaterthan($a, $b)));

}


# Function parserValidateBodyForm from line 4

sub parserValidateBodyForm {
  my ($bodyForm, $filename) = @_;
  
  if ( isNil($bodyForm) ) {
    parserPanicAt($filename, undef, "empty body fragment");

  } else {
  };

  if ( isList($bodyForm) ) {
  } else {
    parserPanicAtNode($filename, $bodyForm, "body fragment must be a list");

  };

  if ( parserListStartsWith($bodyForm, "body") ) {
    parserValidateBody(cdr($bodyForm), $filename);

  } else {
    parserPanicAtNode($filename, $bodyForm, "expected body fragment");

  };

}


# Function readBodySexpr from line 16

sub readBodySexpr {
  my ($aStr, $filename) = @_;
  my $tokens = undef;
my $as = undef;
my $bodyForm = undef;

  $bodyForm = readSingleSexpr($aStr, $filename);

  parserValidateBodyForm($bodyForm, $filename);

  return $bodyForm;

}


# Function readSingleSexpr from line 22

sub readSingleSexpr {
  my ($aStr, $filename) = @_;
  my $tokens = undef;
my $as = undef;

  $tokens = emptyList();

  $tokens = filterTokens(filterVoid(scan($aStr, 0, 1, 0, 0, $filename)));

  parserValidateParens($tokens, undef, $filename);

  $as = sexprTree($tokens);

  parserValidateRoot($as, $filename);

  return car($as);

}


# Function readBodyFragment from line 31

sub readBodyFragment {
  my ($source, $filename) = @_;
  my $wrapped = "";

  $wrapped = stringConcatenate("(body\n", stringConcatenate($source, "\n)"));

  return readBodySexpr($wrapped, $filename);

}


# Function readFunctionsSexpr from line 36

sub readFunctionsSexpr {
  my ($aStr, $filename) = @_;
  my $section = undef;

  $section = readSingleSexpr($aStr, $filename);

  parserValidateSection($section, "functions", $filename);

  parserValidateFunctions(cdr($section), $filename);

  return $section;

}


# Function readFunctionsFragment from line 43

sub readFunctionsFragment {
  my ($source, $filename) = @_;
  my $wrapped = "";

  $wrapped = stringConcatenate("(functions\n", stringConcatenate($source, "\n)"));

  return readFunctionsSexpr($wrapped, $filename);

}


# Function readTypesSexpr from line 48

sub readTypesSexpr {
  my ($aStr, $filename) = @_;
  my $section = undef;

  $section = readSingleSexpr($aStr, $filename);

  parserValidateSection($section, "types", $filename);

  parserRejectFunctionDefinitions(cdr($section), $filename);

  return $section;

}


# Function readTypesFragment from line 55

sub readTypesFragment {
  my ($source, $filename) = @_;
  my $wrapped = "";

  $wrapped = stringConcatenate("(types\n", stringConcatenate($source, "\n)"));

  return readTypesSexpr($wrapped, $filename);

}


# Function bodyTreeToString from line 60

sub bodyTreeToString {
  my ($tree) = @_;
  
  return ListToString(flatten($tree), 0, $true, $false);

}


# Function compileBodySectionString from line 64

sub compileBodySectionString {
  my ($source, $filename, $target) = @_;
  my $bodyForm = undef;

  $bodyForm = readBodySexpr($source, $filename);

  return compileBodyForm($bodyForm, $target);

}


# Function compileBodyString from line 69

sub compileBodyString {
  my ($source, $filename, $target) = @_;
  my $bodyForm = undef;

  $bodyForm = readBodyFragment($source, $filename);

  return compileBodyForm($bodyForm, $target);

}


# Function compileBodyForm from line 74

sub compileBodyForm {
  my ($bodyForm, $target) = @_;
  my $variables = undef;

  if ( equalString($target, "node2") ) {
    return bodyTreeToString(node2Body(cdr($bodyForm), 0, "snippet"));

  } else {
  };

  if ( equalString($target, "perl") ) {
    $variables = getGlobalVariables();

    return bodyTreeToString(perlBody(cdr($bodyForm), 0, $variables));

  } else {
  };

  if ( equalString($target, "java") ) {
    return bodyTreeToString(javaBody(cdr($bodyForm), 0));

  } else {
  };

  if ( equalString($target, "haskell") ) {
    $variables = haskellGlobalVariables();

    return bodyTreeToString(haskellBody(cdr($bodyForm), 0, $variables));

  } else {
  };

  if ( orBool(equalString($target, "ansi3"), equalString($target, "ansi3-release")) ) {
    $releaseMode = $true;

    return bodyTreeToString(ansi3Body(cdr($bodyForm), 0, "snippet"));

  } else {
  };

  panic(stringConcatenate("unknown body target: ", $target));

  return "";

}


# Function compileFunctionsSectionString from line 100

sub compileFunctionsSectionString {
  my ($source, $filename, $target) = @_;
  my $section = undef;

  $section = readFunctionsSexpr($source, $filename);

  return compileFunctionsSection($section, $target);

}


# Function compileFunctionsString from line 105

sub compileFunctionsString {
  my ($source, $filename, $target) = @_;
  my $section = undef;

  $section = readFunctionsFragment($source, $filename);

  return compileFunctionsSection($section, $target);

}


# Function compileFunctionsSection from line 110

sub compileFunctionsSection {
  my ($section, $target) = @_;
  
  if ( equalString($target, "node2") ) {
    return bodyTreeToString(node2Functions(cdr($section)));

  } else {
  };

  if ( equalString($target, "perl") ) {
    return bodyTreeToString(perlFunctions(cdr($section)));

  } else {
  };

  if ( equalString($target, "java") ) {
    return bodyTreeToString(javaFunctions(cdr($section)));

  } else {
  };

  if ( equalString($target, "haskell") ) {
    return bodyTreeToString(haskellFunctions(cdr($section)));

  } else {
  };

  if ( orBool(equalString($target, "ansi3"), equalString($target, "ansi3-release")) ) {
    $releaseMode = $true;

    return bodyTreeToString(ansi3Functions(cdr($section)));

  } else {
  };

  panic(stringConcatenate("unknown functions target: ", $target));

  return "";

}


# Function compileTypesSectionString from line 132

sub compileTypesSectionString {
  my ($source, $filename, $target) = @_;
  my $section = undef;

  $section = readTypesSexpr($source, $filename);

  return compileTypesSection($section, $target);

}


# Function compileTypesString from line 137

sub compileTypesString {
  my ($source, $filename, $target) = @_;
  my $section = undef;

  $section = readTypesFragment($source, $filename);

  return compileTypesSection($section, $target);

}


# Function compileTypesSection from line 142

sub compileTypesSection {
  my ($section, $target) = @_;
  
  if ( equalString($target, "node2") ) {
    return bodyTreeToString(node2Types(cdr($section)));

  } else {
  };

  if ( equalString($target, "perl") ) {
    return bodyTreeToString(perlTypes(cdr($section)));

  } else {
  };

  if ( equalString($target, "java") ) {
    return bodyTreeToString(javaTypes(cdr($section)));

  } else {
  };

  if ( equalString($target, "haskell") ) {
    return bodyTreeToString(haskellTypes(cdr($section)));

  } else {
  };

  if ( orBool(equalString($target, "ansi3"), equalString($target, "ansi3-release")) ) {
    return bodyTreeToString(ansi3Types(cdr($section)));

  } else {
  };

  panic(stringConcatenate("unknown types target: ", $target));

  return "";

}


# Function compileProgramBareString from line 162

sub compileProgramBareString {
  my ($source, $filename, $target) = @_;
  my $tree = undef;

  $tree = readSexpr($source, $filename);

  $tree = macrowalk($tree);

  if ( equalString($target, "java") ) {
    $tree = javaApplyTypeAliases($tree, cdr(getTypes($tree)));

  } else {
  };

  if ( equalString($target, "haskell") ) {
    $tree = haskellApplyTypeAliases($tree, cdr(getTypes($tree)));

  } else {
  };

  if ( equalString($target, "node2") ) {
    return bodyTreeToString(cons(id(node2Types(getTypes($tree))), cons(id(node2Functions(getFunctions($tree))), undef)));

  } else {
  };

  if ( equalString($target, "perl") ) {
    return bodyTreeToString(cons(id(perlTypes(getTypes($tree))), cons(id(perlFunctions(getFunctions($tree))), undef)));

  } else {
  };

  if ( equalString($target, "java") ) {
    return bodyTreeToString(cons(id(javaTypes(getTypes($tree))), cons(id(javaFunctions(getFunctions($tree))), undef)));

  } else {
  };

  if ( equalString($target, "haskell") ) {
    return bodyTreeToString(cons(id(haskellTypes(getTypes($tree))), cons(id(haskellFunctions(getFunctions($tree))), undef)));

  } else {
  };

  if ( orBool(equalString($target, "ansi3"), equalString($target, "ansi3-release")) ) {
    $releaseMode = $true;

    return bodyTreeToString(cons(id(ansi3Types(getTypes($tree))), cons(id(ansi3Functions(getFunctions($tree))), undef)));

  } else {
  };

  panic(stringConcatenate("unknown program target: ", $target));

  return "";

}


# Function node2FunctionArgs from line 5

sub node2FunctionArgs {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return emptyList();

  } else {
    if ( equalString(stringify(first($tree)), "...") ) {
      if ( isNil(cddr($tree)) ) {
        return cons(boxString("..."), undef);

      } else {
        return cons(boxString("..."), cons(boxString(", "), cons(id(node2FunctionArgs(cddr($tree))), undef)));

      };

    } else {
      if ( isNil(cddr($tree)) ) {
        return cons(id(node2FuncMap(second($tree))), undef);

      } else {
        return cons(id(node2FuncMap(second($tree))), cons(boxString(", "), cons(id(node2FunctionArgs(cddr($tree))), undef)));

      };

    };

  };

}


# Function node2Atom from line 20

sub node2Atom {
  my ($tree) = @_;
  
  if ( equalString("string", boxType($tree)) ) {
    return cons(boxString("\""), cons(id(boxString(stringify($tree))), cons(boxString("\""), undef)));

  } else {
    return cons(id(node2FuncMap($tree)), undef);

  };

}


# Function node2Expression from line 26

sub node2Expression {
  my ($tree, $indent) = @_;
  my $thing = undef;

  if ( notBool(isList($tree)) ) {
    return node2Atom($tree);

  } else {
    if ( equal(1, listLength($tree)) ) {
      if ( equalBox(boxString("return"), car($tree)) ) {
        return cons(id(node2FuncMap(car($tree))), undef);

      } else {
        return cons(id(node2FuncMap(car($tree))), cons(boxString("()"), undef));

      };

    } else {
      $thing = first($tree);

      if ( equalBox(boxSymbol("get-struct"), $thing) ) {
        return cons(id(node2Expression(second($tree), $indent)), cons(boxString("."), cons(id(third($tree)), undef)));

      } else {
        if ( equalBox(boxSymbol("new"), $thing) ) {
          return cons(boxString("{}"), undef);

        } else {
          if ( equalBox(boxSymbol("passthrough"), $thing) ) {
            return cons(id(second($tree)), undef);

          } else {
            if ( equalBox(boxSymbol("binop"), $thing) ) {
              return cons(boxString("("), cons(id(node2Expression(third($tree), $indent)), cons(boxString(" "), cons(id(second($tree)), cons(boxString(" "), cons(id(node2Expression(fourth($tree), $indent)), cons(boxString(")"), undef)))))));

            } else {
              return cons(id(node2FuncMap(car($tree))), cons(boxString("("), cons(id(node2RecurList(cdr($tree), $indent)), cons(boxString(")"), undef))));

            };

          };

        };

      };

    };

  };

}


# Function node2RecurList from line 68

sub node2RecurList {
  my ($expr, $indent) = @_;
  
  if ( isEmpty($expr) ) {
    return emptyList();

  } else {
    if ( isNil(cdr($expr)) ) {
      return node2Expression(car($expr), $indent);

    } else {
      return cons(id(node2Expression(car($expr), $indent)), cons(boxString(", "), cons(id(node2RecurList(cdr($expr), $indent)), undef)));

    };

  };

}


# Function node2If from line 80

sub node2If {
  my ($node, $indent, $functionName) = @_;
  
  return cons(id(listNewLine($indent)), cons(boxString("if ("), cons(id(node2Expression(second($node), 0)), cons(boxString(") {"), cons(id(node2Body(cdr(third($node)), add1($indent), $functionName)), cons(id(listNewLine($indent)), cons(boxString("} else {"), cons(id(node2Body(cdr(fourth($node)), add1($indent), $functionName)), cons(id(listNewLine($indent)), cons(boxString("}"), undef))))))))));

}


# Function node2SetStruct from line 94

sub node2SetStruct {
  my ($node, $indent) = @_;
  
  return cons(id(listNewLine($indent)), cons(id(node2Expression(second($node), $indent)), cons(boxString("."), cons(id(third($node)), cons(boxString(" = "), cons(id(node2Expression(fourth($node), $indent)), undef))))));

}


# Function node2Set from line 104

sub node2Set {
  my ($node, $indent) = @_;
  
  return cons(id(listNewLine($indent)), cons(id(node2Expression(second($node), $indent)), cons(boxString(" = "), cons(id(node2Expression(third($node), $indent)), undef))));

}


# Function node2Return from line 112

sub node2Return {
  my ($node, $indent) = @_;
  
  if ( equal(listLength($node), 1) ) {
    return cons(id(listNewLine($indent)), cons(boxString("return"), undef));

  } else {
    return cons(id(listNewLine($indent)), cons(boxString("return "), cons(id(node2Expression(cadr($node), $indent)), undef)));

  };

}


# Function node2Statement from line 122

sub node2Statement {
  my ($node, $indent, $functionName) = @_;
  
  if ( equalBox(boxString("set"), first($node)) ) {
    return cons(id(node2Set($node, $indent)), cons(boxString(";\n"), undef));

  } else {
    if ( equalBox(boxString("set-struct"), first($node)) ) {
      return cons(id(node2SetStruct($node, $indent)), cons(boxString(";\n"), undef));

    } else {
      if ( equalBox(boxString("if"), first($node)) ) {
        return cons(id(node2If($node, $indent, $functionName)), cons(boxString(";\n"), undef));

      } else {
        if ( equalBox(boxString("return"), first($node)) ) {
          return cons(id(node2Return($node, $indent)), cons(boxString(";\n"), undef));

        } else {
          return cons(id(listNewLine($indent)), cons(id(node2Expression($node, $indent)), cons(boxString(";\n"), undef)));

        };

      };

    };

  };

}


# Function node2Body from line 141

sub node2Body {
  my ($tree, $indent, $functionName) = @_;
  my $code = undef;

  if ( isEmpty($tree) ) {
    return emptyList();

  } else {
    $code = car($tree);

    return cons(id(node2Statement($code, $indent, $functionName)), cons(id(node2Body(cdr($tree), $indent, $functionName)), undef));

  };

}


# Function node2Declarations from line 151

sub node2Declarations {
  my ($decls, $indent) = @_;
  my $decl = undef;

  if ( isEmpty($decls) ) {
    return emptyList();

  } else {
    $decl = car($decls);

    return cons(id(boxString(stringIndent($indent))), cons(boxString("let "), cons(id(node2FuncMap(second($decl))), cons(boxString(" = "), cons(id(node2Expression(third($decl), $indent)), cons(boxString(";\n"), cons(id(node2Declarations(cdr($decls), $indent)), undef)))))));

  };

}


# Function node2Function from line 166

sub node2Function {
  my ($node) = @_;
  my $name = undef;

  $name = second($node);

  if ( isNil($node) ) {
    return emptyList();

  } else {
    return cons(id(listNewLine(0)), cons(id(listNewLine(0)), cons(boxString("function "), cons(id(node2FuncMap(second($node))), cons(boxString("("), cons(id(node2FunctionArgs(third($node))), cons(boxString(") {"), cons(id(listNewLine(1)), cons(id(node2Declarations(cdr(fourth($node)), 1)), cons(id(node2Body(cdr(fifth($node)), 1, stringify($name))), cons(boxString("\n}\n"), undef)))))))))));

  };

}


# Function node2Functions from line 185

sub node2Functions {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return emptyList();

  } else {
    return cons(id(node2Function(car($tree))), cons(id(node2Functions(cdr($tree))), undef));

  };

}


# Function node2Includes from line 194

sub node2Includes {
  my ($nodes) = @_;
  
  return cons(boxString("\"use strict\";\n"), cons(boxString("const fs = (typeof require === \"function\") ? require(\"fs\") : null;\n"), cons(boxString("let globalArgsCount = 0;\n"), cons(boxString("let globalArgs = [];\n"), cons(boxString("let releaseMode = false;\n"), cons(boxString("let globalTrace = false;\n"), cons(boxString("let globalStepTrace = false;\n"), cons(boxString("let globalStackTrace = null;\n"), cons(boxString("let caller = \"\";\n"), cons(boxString("let quonIO = makeDefaultQuonIO();\n"), cons(boxString("let stderr = { write: function(s) { quonIO.error(String(s)); } };\n"), cons(boxString("function makeDefaultQuonIO() {\n"), cons(boxString("  return {\n"), cons(boxString("    write: function(s) {\n"), cons(boxString("      if (typeof process !== \"undefined\" && process.stdout) process.stdout.write(String(s));\n"), cons(boxString("    },\n"), cons(boxString("    error: function(s) {\n"), cons(boxString("      if (typeof process !== \"undefined\" && process.stderr) process.stderr.write(String(s));\n"), cons(boxString("      else if (typeof console !== \"undefined\" && console.error) console.error(String(s));\n"), cons(boxString("    },\n"), cons(boxString("    readFile: null,\n"), cons(boxString("    writeFile: null,\n"), cons(boxString("    exit: null,\n"), cons(boxString("    env: (typeof process !== \"undefined\" && process.env) ? process.env : {}\n"), cons(boxString("  };\n"), cons(boxString("}\n"), cons(boxString("function configureQuonIO(io) {\n"), cons(boxString("  const defaults = makeDefaultQuonIO();\n"), cons(boxString("  quonIO = Object.assign(defaults, io || {});\n"), cons(boxString("  if (!quonIO.error) quonIO.error = defaults.error;\n"), cons(boxString("  if (!quonIO.write) quonIO.write = defaults.write;\n"), cons(boxString("  return quonIO;\n"), cons(boxString("}\n"), cons(boxString("function qreadFile(filename) {\n"), cons(boxString("  if (quonIO.readFile) {\n"), cons(boxString("    const data = quonIO.readFile(filename);\n"), cons(boxString("    if (data === null || data === undefined) return null;\n"), cons(boxString("    return boxString(String(data));\n"), cons(boxString("  }\n"), cons(boxString("  if (fs) {\n"), cons(boxString("    try { return boxString(fs.readFileSync(filename, \"utf8\")); } catch (e) { return null; }\n"), cons(boxString("  }\n"), cons(boxString("  return null;\n"), cons(boxString("}\n"), cons(boxString("function qwriteFile(filename, data) {\n"), cons(boxString("  if (quonIO.writeFile) return quonIO.writeFile(filename, data);\n"), cons(boxString("  if (fs) return fs.writeFileSync(filename, data);\n"), cons(boxString("  throw new Error(\"write-file is not available in this environment\");\n"), cons(boxString("}\n"), cons(boxString("function qexit(status) {\n"), cons(boxString("  if (quonIO.exit) return quonIO.exit(status);\n"), cons(boxString("  if (typeof process !== \"undefined\" && process.exit) return process.exit(status);\n"), cons(boxString("  throw new Error(\"Quon exit \" + status);\n"), cons(boxString("}\n"), cons(boxString("function cformat(fmt, ...args) {\n"), cons(boxString("  fmt = String(fmt);\n"), cons(boxString("  let out = '';\n"), cons(boxString("  let argi = 0;\n"), cons(boxString("  for (let pos = 0; pos < fmt.length; pos++) {\n"), cons(boxString("    let ch = fmt[pos];\n"), cons(boxString("    if (ch !== '%') { out += ch; continue; }\n"), cons(boxString("    if (fmt[pos + 1] === '%') { out += '%'; pos++; continue; }\n"), cons(boxString("    let precision = null;\n"), cons(boxString("    if (fmt[pos + 1] === '.') {\n"), cons(boxString("      let end = pos + 2;\n"), cons(boxString("      while (end < fmt.length && fmt[end] >= '0' && fmt[end] <= '9') end++;\n"), cons(boxString("      precision = Number(fmt.slice(pos + 2, end));\n"), cons(boxString("      pos = end - 1;\n"), cons(boxString("    }\n"), cons(boxString("    let spec = fmt[pos + 1];\n"), cons(boxString("    if (spec === 's' || spec === 'd') {\n"), cons(boxString("      let value = String(args[argi++]);\n"), cons(boxString("      if (precision !== null) value = value.slice(0, precision);\n"), cons(boxString("      out += value;\n"), cons(boxString("      pos++;\n"), cons(boxString("    } else {\n"), cons(boxString("      out += ch;\n"), cons(boxString("    }\n"), cons(boxString("  }\n"), cons(boxString("  return out;\n"), cons(boxString("}\n"), cons(boxString("function printf(fmt, ...args) { quonIO.write(cformat(fmt, ...args)); }\n"), cons(boxString("function fprintf(stream, fmt, ...args) { stream.write(cformat(fmt, ...args)); }\n"), undef)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));

}


# Function node2Types from line 281

sub node2Types {
  my ($nodes) = @_;
  
  return emptyList();

}


# Function node2FuncMap from line 285

sub node2FuncMap {
  my ($aSym) = @_;
  my $symMap = undef;

  if ( equalString("symbol", boxType($aSym)) ) {
    $symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("new"), boxSymbol("new_"), alistCons(boxSymbol("nil"), boxSymbol("null"), undef))))))));

    if ( truthy(assoc(stringify($aSym), $symMap)) ) {
      return cdr(assoc(stringify($aSym), $symMap));

    } else {
      return $aSym;

    };

  } else {
    return $aSym;

  };

}


# Function node2MainEntry from line 303

sub node2MainEntry {
  my () = @_;
  
  return cons(boxString("\n// Main entry point\n"), cons(boxString("function runQuon(args = [], io = {}) {\n"), cons(boxString("  configureQuonIO(io);\n"), cons(boxString("  globalArgs = [\"fixmeprogname\", ...args];\n"), cons(boxString("  globalArgsCount = globalArgs.length;\n"), cons(boxString("  return start();\n"), cons(boxString("}\n"), cons(boxString("const __quonProgramApi = { runQuon, configureQuonIO, cformat, start };\n"), cons(boxString("if (typeof compileBodyString === \"function\") __quonProgramApi.compileBodyString = compileBodyString;\n"), cons(boxString("if (typeof compileBodySectionString === \"function\") __quonProgramApi.compileBodySectionString = compileBodySectionString;\n"), cons(boxString("if (typeof compileFunctionsString === \"function\") __quonProgramApi.compileFunctionsString = compileFunctionsString;\n"), cons(boxString("if (typeof compileFunctionsSectionString === \"function\") __quonProgramApi.compileFunctionsSectionString = compileFunctionsSectionString;\n"), cons(boxString("if (typeof compileTypesString === \"function\") __quonProgramApi.compileTypesString = compileTypesString;\n"), cons(boxString("if (typeof compileTypesSectionString === \"function\") __quonProgramApi.compileTypesSectionString = compileTypesSectionString;\n"), cons(boxString("if (typeof compileProgramBareString === \"function\") __quonProgramApi.compileProgramBareString = compileProgramBareString;\n"), cons(boxString("if (typeof readBodyFragment === \"function\") __quonProgramApi.readBodyFragment = readBodyFragment;\n"), cons(boxString("if (typeof module !== \"undefined\" && module.exports) module.exports = __quonProgramApi;\n"), cons(boxString("if (typeof globalThis !== \"undefined\") globalThis.QuonProgram = __quonProgramApi;\n"), cons(boxString("if (typeof require === \"function\" && typeof module !== \"undefined\" && require.main === module) {\n"), cons(boxString("  runQuon((typeof process !== \"undefined\" && process.argv) ? process.argv.slice(2) : []);\n"), cons(boxString("}\n"), undef)))))))))))))))))))));

}


# Function node2LoadProgram from line 328

sub node2LoadProgram {
  my ($filename) = @_;
  my $tree = undef;
my $replace = undef;

  $tree = loadQuon($filename);

  $tree = insertInclude($tree, "q/shims/node2.qon");

  $tree = loadIncludes($tree, undef);

  $tree = macrowalk($tree);

  $replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), undef));

  $tree = macrolist($tree, stringConcatenate("q", "log"), $replace);

  return $tree;

}


# Function node2ProgramTree from line 338

sub node2ProgramTree {
  my ($tree) = @_;
  
  return cons(id(node2Includes(cdr(first($tree)))), cons(id(node2Types(cdr(second($tree)))), cons(id(node2Functions(cdr(third($tree)))), cons(id(node2MainEntry()), cons(boxString("\n"), undef)))));

}


# Function node2Program from line 347

sub node2Program {
  my ($tree) = @_;
  
  return ListToString(flatten(node2ProgramTree($tree)), 0, $true, $false);

}


# Function node2CompileString from line 351

sub node2CompileString {
  my ($filename) = @_;
  
  return node2Program(node2LoadProgram($filename));

}


# Function node2Compile from line 355

sub node2Compile {
  my ($filename) = @_;
  my $tree = undef;
my $replace = undef;

  fprintf($stderr, "//Scanning file...%s\n", $filename);

  $tree = loadQuon($filename);

  fprintf($stderr, "Loading shim node2\n");

  $tree = insertInclude($tree, "q/shims/node2.qon");

  fprintf($stderr, "Loading all includes\n");

  $tree = loadIncludes($tree, undef);

  fprintf($stderr, "Applying macros\n");

  $tree = macrowalk($tree);

  $replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), undef));

  $tree = macrolist($tree, stringConcatenate("q", "log"), $replace);

  fprintf($stderr, "//Printing program\n");

  printStringTree(node2ProgramTree($tree));

  fprintf($stderr, "//Done printing program\n");

}


# Function test0 from line 7

sub test0 {
  my () = @_;
  
  if ( equalString(stringify(boxString("hello")), stringify(boxString("hello"))) ) {
    printf("0.  pass string compare works\n");

  } else {
    printf("0.  pass string compare fails\n");

  };

  if ( equalString(stringify(boxString("hello")), stringify(boxSymbol("hello"))) ) {
    printf("0.  pass string compare works\n");

  } else {
    printf("0.  pass string compare fails\n");

  };

}


# Function test1 from line 20

sub test1 {
  my () = @_;
  
  printf("1.  pass Function call and print work\n");

}


# Function test2_do from line 24

sub test2_do {
  my ($message) = @_;
  
  printf("2.  pass Function call with arg works: %s\n", $message);

}


# Function test2 from line 28

sub test2 {
  my () = @_;
  
  test2_do("This is the argument");

}


# Function test3_do from line 30

sub test3_do {
  my ($b, $c) = @_;
  
  printf("3.1 pass Two arg call, first arg: %d\n", $b);

  printf("3.2 pass Two arg call, second arg: %s\n", $c);

}


# Function test3 from line 36

sub test3 {
  my () = @_;
  
  test3_do(42, "Fourty-two");

}


# Function test4_do from line 37

sub test4_do {
  my () = @_;
  
  return "pass Return works";

}


# Function returnThis from line 39

sub returnThis {
  my ($returnMessage) = @_;
  
  return $returnMessage;

}


# Function test4 from line 42

sub test4 {
  my () = @_;
  my $message = "fail";

  $message = test4_do();

  printf("4.  %s\n", $message);

}


# Function test5 from line 45

sub test5 {
  my () = @_;
  my $message = "fail";

  $message = returnThis("pass return passthrough string");

  printf("5.  %s\n", $message);

}


# Function test6 from line 50

sub test6 {
  my () = @_;
  
  if ( $true ) {
    printf("6.  pass If statement works\n");

  } else {
    printf("6.  fail If statement works\n");

  };

}


# Function test7_do from line 58

sub test7_do {
  my ($count) = @_;
  
  $count = subtract($count, 1);

  if ( greaterthan($count, 0) ) {
    $count = test7_do($count);

  } else {
    return $count;

  };

  return $count;

}


# Function test7 from line 66

sub test7 {
  my () = @_;
  
  if ( equal(0, test7_do(10)) ) {
    printf("7.  pass count works\n");

  } else {
    printf("7.  fail count fails\n");

  };

}


# Function beer from line 74

sub beer {
  my () = @_;
  
  printf("%d bottle of beer on the wall, %d bottle of beer.  Take one down, pass it round, no bottles of beer on the wall\n", 1, 1);

}


# Function plural from line 83

sub plural {
  my ($num) = @_;
  
  if ( equal($num, 1) ) {
    return "";

  } else {
    return "s";

  };

}


# Function beers from line 88

sub beers {
  my ($count) = @_;
  my $newcount = 0;

  $newcount = subtract($count, 1);

  printf("%d bottle%s of beer on the wall, %d bottle%s of beer.  Take one down, pass it round, %d bottle%s of beer on the wall\n", $count, plural($count), $count, plural($count), $newcount, plural($newcount));

  if ( greaterthan($count, 1) ) {
    $count = beers($newcount);

  } else {
    return $count;

  };

  return 0;

}


# Function test8 from line 104

sub test8 {
  my () = @_;
  
  if ( equal(subtract(subtract(2, 1), subtract(3, 1)), -1) ) {
    printf("8.  pass Nested expressions work\n");

  } else {
    printf("8.  fail Nested expressions don't work\n");

  };

}


# Function test9 from line 112

sub test9 {
  my () = @_;
  my $answer = -999999;
my $a = 2;
my $b = 3;

  $answer = subtract(subtract(20, 1), subtract(3, 1));

  if ( equal($answer, 17) ) {
    printf("9.1  pass sub works\n");

  } else {
    printf("9.1  fail sub\n");

  };

  $answer = add(2, 3);

  if ( equal($answer, 5) ) {
    printf("9.2  pass add works\n");

  } else {
    printf("9.2  fail add\n");

  };

  $answer = mult($a, $b);

  if ( equal($answer, 6) ) {
    printf("9.3  pass mult works\n");

  } else {
    printf("9.3  fail mult\n");

  };

  if ( greaterthan(2, 1) ) {
    printf("9.4  pass greaterthan works\n");

  } else {
    printf("9.4  fail greaterthan\n");

  };

  if ( equal(1, 1) ) {
    printf("9.5  pass integer equal works\n");

  } else {
    printf("9.5  fail integer equal\n");

  };

  if ( equalString("hello", "hello") ) {
    printf("9.6  pass string equal works\n");

  } else {
    printf("9.6  fail string equal\n");

  };

  if ( equalString("hello", "world") ) {
    printf("9.7  fail string equal\n");

  } else {
    printf("9.7  pass string equal\n");

  };

  if ( andBool($false, $false) ) {
    printf("9.8  fail andBool\n");

  } else {
    printf("9.8  pass andBool works\n");

  };

  if ( andBool($true, $true) ) {
    printf("9.9  pass andBool works\n");

  } else {
    printf("9.9  fail andBool\n");

  };

  if ( andBool($true, $false) ) {
    printf("9.10  fail andBool\n");

  } else {
    printf("9.10  pass andBool works\n");

  };

  if ( equalString("hello", "hello") ) {
    printf("9.11  pass string equal\n");

  } else {
    printf("9.11  fail string equal\n");

  };

  if ( equalString("!", character(33)) ) {
    printf("9.12  pass character\n");

  } else {
    printf("9.12  fail character\n");

  };

  if ( equalString("33", intToString(33)) ) {
    printf("9.13  pass intToString\n");

  } else {
    printf("9.13  fail intToString\n");

  };

  if ( equalString("llo", substr("hello", $a, $b)) ) {
    printf("9.14  pass sub-string\n");

  } else {
    printf("9.14  fail sub-string: %s\n", substr("hello", $a, $b));

  };

}


# Function test10 from line 170

sub test10 {
  my () = @_;
  my $testString = "This is a test string";

  if ( equalString($testString, unBoxString(car(cons(boxString($testString), undef)))) ) {
    printf("10. pass cons and car work\n");

  } else {
    printf("10. fail cons and car fail\n");

  };

}


# Function test12 from line 180

sub test12 {
  my () = @_;
  my $b = undef;

  $b = {};

  $b->{str} = "12. pass structure accessors\n";

  printf("%s", $b->{str});

}


# Function test13 from line 188

sub test13 {
  my () = @_;
  my $testString = "Hello from the filesystem!";
my $contentsBox = undef;
my $contents = "";

  write_file("test.txt", $testString);

  $contentsBox = read_file("test.txt");

  if ( isNil($contentsBox) ) {
    printf("13. fail Read and write files\n");

    printf("Expected: %s\n", $testString);

    printf("Got: nil\n");

  } else {
    $contents = unBoxString($contentsBox);

    if ( equalString($testString, $contents) ) {
      printf("13. pass Read and write files\n");

    } else {
      printf("13. fail Read and write files\n");

      printf("Expected: %s\n", $testString);

      printf("Got: %s\n", $contents);

    };

  };

}


# Function test14 from line 213

sub test14 {
  my () = @_;
  my $contentsBox = undef;

  $contentsBox = read_file("q/this-file-should-not-exist.qon");

  if ( isNil($contentsBox) ) {
    printf("14. pass Missing read-file returns nil\n");

  } else {
    printf("14. fail Missing read-file returns nil\n");

    printf("Got: %s\n", unBoxString($contentsBox));

  };

}


# Function test15 from line 224

sub test15 {
  my () = @_;
  my $a = "hello";
my $b = " world";
my $c = "";

  $c = stringConcatenate($a, $b);

  if ( equalString($c, "hello world") ) {
    printf("15. pass String concatenate\n");

  } else {
    printf("15. fail String concatenate\n");

  };

}


# Function test16 from line 232

sub test16 {
  my () = @_;
  my $assocCell1 = undef;
my $assList = undef;
my $assocCell2 = undef;
my $assocCell3 = undef;

  $assocCell1 = cons(boxString("Hello"), boxString("world"));

  $assocCell2 = cons(boxString("goodnight"), boxString("moon"));

  $assocCell3 = cons(boxSymbol("ohio"), boxString("gozaimasu"));

  $assList = cons($assocCell2, emptyList());

  $assList = cons($assocCell1, $assList);

  $assList = cons($assocCell3, $assList);

  if ( equalBox(cdr(assoc("Hello", $assList)), boxString("world")) ) {
    printf("16.1 pass Basic assoc works\n");

  } else {
    printf("16.1 fail Basic assoc fails\n");

  };

  if ( andBool(andBool(equalBox(cdr(assoc("Hello", $assList)), boxString("world")), equalBox(cdr(assoc("goodnight", $assList)), boxString("moon"))), equalBox(cdr(assoc("ohio", $assList)), boxString("gozaimasu"))) ) {
    printf("16.2 pass assoc list\n");

  } else {
    printf("16.2 fail assoc list\n");

  };

}


# Function test17 from line 256

sub test17 {
  my () = @_;
  my $l = undef;

  $l = cons(boxInt(1), cons(boxInt(2), cons(boxInt(3), undef)));

  if ( equalBox(car($l), boxInt(1)) ) {
    printf("17. pass list literal works\n");

  } else {
    printf("17. fail list literal failed\n");

  };

}


# Function test18 from line 267

sub test18 {
  my () = @_;
  my $val1 = "a";
my $val2 = "b";
my $l = undef;

  $l = cons(boxString($val1), cons(boxString($val2), cons(boxString("c"), undef)));

  if ( equalList($l, cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), undef)))) ) {
    printf("18. pass string list constructor works\n");

  } else {
    printf("18. fail string list constructor failed\n");

  };

}


# Function test19 from line 281

sub test19 {
  my () = @_;
  my $val1 = "a";
my $val2 = "b";
my $l = undef;
my $revlist = undef;
my $answer = undef;

  $l = cons(boxString($val1), cons(boxString($val2), cons(boxString("c"), undef)));

  $answer = cons(boxString("c"), cons(boxString($val2), cons(boxString($val1), undef)));

  $revlist = reverseList($l);

  if ( equalList($answer, $revlist) ) {
    printf("19. pass reverseList\n");

  } else {
    printf("19. fail reverseList\n");

  };

}


# Function concatenateLists from line 299

sub concatenateLists {
  my ($oldL, $newL) = @_;
  
  return reverseRec(reverseList($oldL), $newL);

}


# Function test20 from line 304

sub test20 {
  my () = @_;
  my $val1 = "a";
my $val2 = "b";
my $val3 = "c";
my $l = undef;
my $l2 = undef;
my $l3 = undef;
my $combined = undef;

  $l = cons(boxString($val1), cons(boxString($val2), cons(boxString("c"), undef)));

  $l2 = cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), undef)));

  $l3 = cons(boxString($val1), cons(boxString($val2), cons(boxString($val3), cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), undef))))));

  $combined = concatenateLists($l, $l2);

  if ( equalList($l3, $combined) ) {
    printf("21. pass concatenateLists\n");

  } else {
    printf("21. fail concatenateLists\n");

  };

}


# Function test21 from line 324

sub test21 {
  my () = @_;
  my $val1 = "a";
my $val2 = "b";
my $val3 = "c";
my $l = undef;
my $l2 = undef;

  $l = cons(boxString($val1), cons(boxString($val2), cons(boxString($val3), undef)));

  $l2 = cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), undef)));

  if ( equalList($l, $l2) ) {
    printf("21. pass equalList\n");

  } else {
    printf("21. fail equalList\n");

  };

}


# Function test22 from line 340

sub test22 {
  my () = @_;
  my $original = undef;
my $out = undef;
my $replace = undef;
my $correct = undef;

  $original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), undef)));

  $replace = cons(boxString("fprintf"), cons(boxString("stderr"), undef));

  $out = macrolist($original, stringConcatenate("q", "log"), $replace);

  $correct = cons(boxString("fprintf"), cons(boxString("stderr"), cons(boxString("%s"), cons(boxString("hello"), undef))));

  if ( equalList($out, $correct) ) {
    printf("22. pass macroList\n");

  } else {
    printf("22. fail macroList\n");

    printf("In: ");

    displayList($original, 0, $true);

    printf("\nOut: ");

    displayList($out, 0, $true);

    printf("\n");

  };

}


# Function test23 from line 363

sub test23 {
  my () = @_;
  my $original = undef;
my $out = undef;
my $replace = undef;
my $correct = undef;

  $original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), undef)));

  $replace = cons(boxString("fprintf"), cons(boxString("stderr"), undef));

  $out = concatLists($original, $replace);

  $correct = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), cons(boxString("fprintf"), cons(boxString("stderr"), undef)))));

  if ( equalList($out, $correct) ) {
    printf("23. pass concatLists\n");

  } else {
    printf("23. fail concatLists\n");

    printf("In: ");

    displayList($original, 0, $true);

    printf("\nOut: ");

    displayList($out, 0, $true);

  };

}


# Function test24 from line 386

sub test24 {
  my () = @_;
  my $expected = "a b c";
my $res = "";

  $res = StringListJoin(cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), undef))), " ");

  if ( equalString($expected, $res) ) {
    printf("24. pass StringListJoin\n");

  } else {
    printf("24. fail StringListJoin.  expected %s, got %s\n", $expected, $res);

  };

}


# Function test25 from line 400

sub test25 {
  my () = @_;
  my $expected = "( a b ) c d e";
my $res = "";
my $testsubstr = cons(boxString("c "), cons(boxString("d "), cons(boxString("e"), undef)));
my $input = undef;

  $input = cons(boxString("a "), cons(boxString("b "), undef));

  $input = cons($input, $testsubstr);

  $res = ListToString($input, 0, $true, $false);

  if ( equalString($expected, $res) ) {
    printf("25. pass ListToString\n");

  } else {
    printf("25. fail ListToString.  expected %s, got %s\n", $expected, $res);

  };

}


# Function test27 from line 436

sub test27 {
  my () = @_;
  my $expected = "a b c d e";
my $floatExpected = "6.5";
my $floatResult = "";
my $res = "";
my $floatBox = undef;
my $variable = cons(boxString("c "), cons(boxString("d "), undef));
my $input = undef;

  $input = cons(boxString("a "), cons(boxString("b "), cons(id($variable), cons(boxString("e"), undef))));

  $res = ListToString(flatten($input), 0, $true, $false);

  if ( equalString($expected, $res) ) {
    printf("27. pass Interpolated List\n");

  } else {
    printf("27. fail Interpolated List.  expected %s, got %s\n", $expected, $res);

  };

  $floatBox = boxFloat(6.5);

  $floatResult = stringify($floatBox);

  if ( equalString($floatExpected, $floatResult) ) {
    printf("27. pass Float box stringify\n");

  } else {
    printf("27. fail Float box stringify.  expected %s, got %s\n", $floatExpected, $floatResult);

  };

}


# Function test28 from line 462

sub test28 {
  my () = @_;
  my $splitExpected = undef;
my $splitResult = undef;

  if ( equalString("aXYZc", stringReplace("b", "XYZ", "abc")) ) {
    printf("28.1 pass stringReplace\n");

  } else {
    printf("28.1 fail stringReplace\n");

  };

  if ( equalString("abc", stringTrim(" abc ")) ) {
    printf("28.2 pass stringTrim\n");

  } else {
    printf("28.2 fail stringTrim\n");

  };

  $splitExpected = cons(boxString("a"), cons(boxString("b"), undef));

  $splitResult = stringSplit("a,b", ",");

  if ( equalList($splitExpected, $splitResult) ) {
    printf("28.3 pass stringSplit\n");

  } else {
    printf("28.3 fail stringSplit\n");

  };

}


# Function haskellBackslash from line 5

sub haskellBackslash {
  my () = @_;
  
  return character(92);

}


# Function haskellDoubleQuote from line 8

sub haskellDoubleQuote {
  my () = @_;
  
  return character(34);

}


# Function haskellEscapedBackslash from line 11

sub haskellEscapedBackslash {
  my () = @_;
  
  return stringConcatenate(haskellBackslash(), haskellBackslash());

}


# Function haskellEscapedDoubleQuote from line 14

sub haskellEscapedDoubleQuote {
  my () = @_;
  
  return stringConcatenate(haskellBackslash(), haskellDoubleQuote());

}


# Function haskellEscapeString from line 17

sub haskellEscapeString {
  my ($s) = @_;
  
  $s = stringReplace(character(10), stringConcatenate(haskellBackslash(), "n"), $s);

  $s = stringReplace(character(13), stringConcatenate(haskellBackslash(), "r"), $s);

  $s = stringReplace(character(9), stringConcatenate(haskellBackslash(), "t"), $s);

  return $s;

}


# Function haskellSafeNameString from line 24

sub haskellSafeNameString {
  my ($name) = @_;
  
  if ( equalString($name, "case") ) {
    return "caseValue";

  } else {
  };

  if ( equalString($name, "class") ) {
    return "classValue";

  } else {
  };

  if ( equalString($name, "data") ) {
    return "dataValue";

  } else {
  };

  if ( equalString($name, "default") ) {
    return "defaultValue";

  } else {
  };

  if ( equalString($name, "deriving") ) {
    return "derivingValue";

  } else {
  };

  if ( equalString($name, "do") ) {
    return "doValue";

  } else {
  };

  if ( equalString($name, "else") ) {
    return "elseValue";

  } else {
  };

  if ( equalString($name, "foreign") ) {
    return "foreignValue";

  } else {
  };

  if ( equalString($name, "if") ) {
    return "ifValue";

  } else {
  };

  if ( equalString($name, "import") ) {
    return "importValue";

  } else {
  };

  if ( equalString($name, "in") ) {
    return "inValue";

  } else {
  };

  if ( equalString($name, "infix") ) {
    return "infixValue";

  } else {
  };

  if ( equalString($name, "infixl") ) {
    return "infixlValue";

  } else {
  };

  if ( equalString($name, "infixr") ) {
    return "infixrValue";

  } else {
  };

  if ( equalString($name, "instance") ) {
    return "instanceValue";

  } else {
  };

  if ( equalString($name, "let") ) {
    return "letValue";

  } else {
  };

  if ( equalString($name, "module") ) {
    return "moduleValue";

  } else {
  };

  if ( equalString($name, "newtype") ) {
    return "newtypeValue";

  } else {
  };

  if ( equalString($name, "of") ) {
    return "ofValue";

  } else {
  };

  if ( equalString($name, "then") ) {
    return "thenValue";

  } else {
  };

  if ( equalString($name, "type") ) {
    return "typeValue";

  } else {
  };

  if ( equalString($name, "where") ) {
    return "whereValue";

  } else {
  };

  if ( equalString($name, "id") ) {
    return "qid";

  } else {
  };

  if ( equalString($name, "old") ) {
    return "oldValue";

  } else {
  };

  if ( equalString($name, "new") ) {
    return "newValue";

  } else {
  };

  if ( haskellStringStartsWith($name, "-") ) {
    return $name;

  } else {
  };

  if ( equalString($name, "StringListJoinRec") ) {
    return "stringListJoinRec";

  } else {
  };

  if ( equalString($name, "StringListJoin") ) {
    return "stringListJoin";

  } else {
  };

  if ( equalString($name, "ListToBoxString") ) {
    return "listToBoxString";

  } else {
  };

  if ( equalString($name, "ListToString") ) {
    return "listToString";

  } else {
  };

  if ( equalString($name, "StackTraceMove") ) {
    return "stackTraceMove";

  } else {
  };

  if ( equalString($name, "StackTracePrint") ) {
    return "stackTracePrint";

  } else {
  };

  if ( equalString($name, "StackTracePrintHelper") ) {
    return "stackTracePrintHelper";

  } else {
  };

  if ( equalString($name, "NoStackTrace_list") ) {
    return "noStackTrace_list";

  } else {
  };

  if ( equalString($name, "NoTrace_list") ) {
    return "noTrace_list";

  } else {
  };

  $name = stringReplace("-", "_", $name);

  $name = stringReplace("?", "_q", $name);

  $name = stringReplace("!", "_bang", $name);

  return $name;

}


# Function haskellSafeName from line 66

sub haskellSafeName {
  my ($aSym) = @_;
  
  return boxSymbol(haskellSafeNameString(stringify($aSym)));

}


# Function haskellFieldName from line 70

sub haskellFieldName {
  my ($aSym) = @_;
  
  return stringConcatenate("qf_", haskellSafeNameString(stringify($aSym)));

}


# Function haskellNewName from line 74

sub haskellNewName {
  my ($aSym) = @_;
  
  return stringConcatenate("new", stringify($aSym));

}


# Function haskellStringEndsWith from line 78

sub haskellStringEndsWith {
  my ($s, $suffix) = @_;
  my $start = 0;

  if ( greaterthan(length($suffix), length($s)) ) {
    return $false;

  } else {
    $start = subtract(length($s), length($suffix));

    return equalString(substr($s, $start, length($suffix)), $suffix);

  };

}


# Function haskellStringStartsWith from line 86

sub haskellStringStartsWith {
  my ($s, $prefix) = @_;
  
  if ( greaterthan(length($prefix), length($s)) ) {
    return $false;

  } else {
    return equalString(substr($s, 0, length($prefix)), $prefix);

  };

}


# Function haskellPointerBase from line 92

sub haskellPointerBase {
  my ($aSym) = @_;
  my $name = "";

  $name = stringify($aSym);

  if ( haskellStringEndsWith($name, "*") ) {
    return boxSymbol(substr($name, 0, sub1(length($name))));

  } else {
    return $aSym;

  };

}


# Function haskellTypeIsPointer from line 99

sub haskellTypeIsPointer {
  my ($aSym) = @_;
  my $mapped = "";

  $mapped = stringify(haskellTypeMap($aSym));

  return haskellStringStartsWith($mapped, "Maybe ");

}


# Function haskellTypeMap from line 104

sub haskellTypeMap {
  my ($aSym) = @_;
  my $symMap = undef;
my $name = "";

  $symMap = alistCons(boxSymbol("pair"), boxSymbol("Maybe Box"), alistCons(boxSymbol("box"), boxSymbol("Maybe Box"), alistCons(boxSymbol("list"), boxSymbol("Maybe Box"), alistCons(boxSymbol("Box*"), boxSymbol("Maybe Box"), alistCons(boxSymbol("Pair"), boxSymbol("Box"), alistCons(boxSymbol("struct"), boxSymbol(""), alistCons(boxSymbol("bool"), boxSymbol("Bool"), alistCons(boxSymbol("uint"), boxSymbol("Int"), alistCons(boxSymbol("int"), boxSymbol("Int"), alistCons(boxSymbol("float"), boxSymbol("Double"), alistCons(boxSymbol("void"), boxSymbol("()"), alistCons(boxSymbol("stringArray"), boxSymbol("[String]"), alistCons(boxSymbol("array"), boxSymbol("[String]"), alistCons(boxSymbol("hashmap"), boxSymbol("IORef [(String, String)]"), alistCons(boxSymbol("string"), boxSymbol("String"), undef)))))))))))))));

  if ( truthy(assoc(stringify($aSym), $symMap)) ) {
    return cdr(assoc(stringify($aSym), $symMap));

  } else {
    $name = stringify($aSym);

    if ( haskellStringEndsWith($name, "*") ) {
      return boxSymbol(stringConcatenate("Maybe ", stringify(haskellPointerBase($aSym))));

    } else {
      return $aSym;

    };

  };

}


# Function haskellDefaultValue from line 130

sub haskellDefaultValue {
  my ($typeSym) = @_;
  my $typ = "";

  $typ = stringify(haskellTypeMap($typeSym));

  if ( equalString($typ, "()") ) {
    return "()";

  } else {
  };

  if ( equalString($typ, "Bool") ) {
    return "False";

  } else {
  };

  if ( equalString($typ, "Int") ) {
    return "0";

  } else {
  };

  if ( equalString($typ, "Double") ) {
    return "0.0";

  } else {
  };

  if ( equalString($typ, "String") ) {
    return "\"\"";

  } else {
  };

  if ( equalString($typ, "[String]") ) {
    return "[]";

  } else {
  };

  if ( haskellStringStartsWith($typ, "Maybe ") ) {
    return "Nothing";

  } else {
  };

  return stringConcatenate("(error \"no default value for ", stringConcatenate($typ, "\")"));

}


# Function haskellRefType from line 142

sub haskellRefType {
  my ($typeSym) = @_;
  
  return stringConcatenate("(", stringConcatenate(stringify(haskellTypeMap($typeSym)), ")"));

}


# Function haskellGlobalVariables from line 146

sub haskellGlobalVariables {
  my () = @_;
  
  return cons(id(boxSymbol("globalArgsCount")), cons(id(boxSymbol("globalArgs")), cons(id(boxSymbol("releaseMode")), cons(id(boxSymbol("caller")), cons(id(boxSymbol("globalTrace")), cons(id(boxSymbol("globalStepTrace")), cons(id(boxSymbol("globalStackTrace")), undef)))))));

}


# Function haskellCollectVariablesFromArgs from line 157

sub haskellCollectVariablesFromArgs {
  my ($args) = @_;
  my $variables = undef;

  if ( isNil($args) ) {
    return $variables;

  } else {
    $variables = cons(second($args), $variables);

    return appendVariables($variables, haskellCollectVariablesFromArgs(cddr($args)));

  };

}


# Function haskellCollectVariablesFromDecls from line 165

sub haskellCollectVariablesFromDecls {
  my ($decls) = @_;
  my $variables = undef;
my $decl = undef;

  if ( isNil($decls) ) {
    return $variables;

  } else {
    $decl = car($decls);

    $variables = cons(second($decl), $variables);

    return appendVariables($variables, haskellCollectVariablesFromDecls(cdr($decls)));

  };

}


# Function haskellCollectVariables from line 174

sub haskellCollectVariables {
  my ($args, $decls) = @_;
  my $variables = undef;

  $variables = haskellCollectVariablesFromArgs($args);

  $variables = appendVariables($variables, haskellCollectVariablesFromDecls($decls));

  $variables = appendVariables($variables, haskellGlobalVariables());

  return $variables;

}


# Function haskellFuncMap from line 181

sub haskellFuncMap {
  my ($aSym, $variables) = @_;
  my $symMap = undef;

  if ( orBool(equalString("symbol", boxType($aSym)), equalString("string", boxType($aSym))) ) {
    if ( inList($aSym, $variables) ) {
      return haskellSafeName($aSym);

    } else {
      $symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("Nothing"), alistCons(boxSymbol("true"), boxSymbol("True"), alistCons(boxSymbol("false"), boxSymbol("False"), alistCons(boxSymbol("old"), boxSymbol("oldValue"), alistCons(boxSymbol("new"), boxSymbol("newValue"), undef)))))))))));

      if ( truthy(assoc(stringify($aSym), $symMap)) ) {
        return cdr(assoc(stringify($aSym), $symMap));

      } else {
        return haskellSafeName($aSym);

      };

    };

  } else {
    return $aSym;

  };

}


# Function haskellNumberAtom from line 205

sub haskellNumberAtom {
  my ($tree) = @_;
  my $val = "";

  $val = stringify($tree);

  if ( haskellStringStartsWith($val, "-") ) {
    return cons(boxString("pure ("), cons(id(boxString($val)), cons(boxString(")"), undef)));

  } else {
    return cons(boxString("pure "), cons(id(boxString($val)), undef));

  };

}


# Function haskellAtom from line 212

sub haskellAtom {
  my ($tree, $variables) = @_;
  
  if ( equalString("int", boxType($tree)) ) {
    return haskellNumberAtom($tree);

  } else {
    if ( equalString("float", boxType($tree)) ) {
      return haskellNumberAtom($tree);

    } else {
      if ( equalString("string", boxType($tree)) ) {
        return cons(boxString("pure \""), cons(id(boxString(haskellEscapeString(stringify($tree)))), cons(boxString("\""), undef)));

      } else {
        if ( isInt(stringify($tree)) ) {
          return haskellNumberAtom($tree);

        } else {
          if ( isFloat(stringify($tree)) ) {
            return haskellNumberAtom($tree);

          } else {
            if ( haskellStringStartsWith(stringify($tree), "-") ) {
              return cons(boxString("pure ("), cons(id(haskellFuncMap($tree, $variables)), cons(boxString(")"), undef)));

            } else {
              if ( inList($tree, $variables) ) {
                return cons(boxString("liftIO (readIORef "), cons(id(haskellFuncMap($tree, $variables)), cons(boxString(")"), undef)));

              } else {
                return cons(boxString("pure "), cons(id(haskellFuncMap($tree, $variables)), undef));

              };

            };

          };

        };

      };

    };

  };

}


# Function haskellArgNames from line 236

sub haskellArgNames {
  my ($expr, $pos) = @_;
  
  if ( isEmpty($expr) ) {
    return emptyList();

  } else {
    if ( isNil(cdr($expr)) ) {
      return cons(boxString(" arg"), cons(id(boxString(intToString($pos))), undef));

    } else {
      return cons(boxString(" arg"), cons(id(boxString(intToString($pos))), cons(id(haskellArgNames(cdr($expr), add1($pos))), undef)));

    };

  };

}


# Function haskellBindArgs from line 245

sub haskellBindArgs {
  my ($expr, $indent, $variables, $pos) = @_;
  
  if ( isEmpty($expr) ) {
    return emptyList();

  } else {
    return cons(id(listNewLine($indent)), cons(boxString("arg"), cons(id(boxString(intToString($pos))), cons(boxString(" <- "), cons(id(haskellExpression(car($expr), $indent, $variables)), cons(id(haskellBindArgs(cdr($expr), $indent, $variables, add1($pos))), undef))))));

  };

}


# Function haskellCall from line 257

sub haskellCall {
  my ($name, $args, $indent, $variables) = @_;
  
  if ( isEmpty($args) ) {
    return cons(boxString("liftIO "), cons(id(haskellFuncMap($name, undef)), undef));

  } else {
    return cons(boxString("do"), cons(id(haskellBindArgs($args, add1($indent), $variables, 0)), cons(id(listNewLine(add1($indent))), cons(boxString("liftIO ("), cons(id(haskellFuncMap($name, undef)), cons(id(haskellArgNames($args, 0)), cons(boxString(")"), undef)))))));

  };

}


# Function haskellBinop from line 270

sub haskellBinop {
  my ($tree, $indent, $variables) = @_;
  
  return cons(boxString("do"), cons(id(listNewLine(add1($indent))), cons(boxString("arg0 <- "), cons(id(haskellExpression(third($tree), add1($indent), $variables)), cons(id(listNewLine(add1($indent))), cons(boxString("arg1 <- "), cons(id(haskellExpression(fourth($tree), add1($indent), $variables)), cons(id(listNewLine(add1($indent))), cons(boxString("pure (arg0 "), cons(id(second($tree)), cons(boxString(" arg1)"), undef)))))))))));

}


# Function haskellGetStruct from line 285

sub haskellGetStruct {
  my ($tree, $indent, $variables) = @_;
  
  return cons(boxString("do"), cons(id(listNewLine(add1($indent))), cons(boxString("hobj <- "), cons(id(haskellExpression(second($tree), add1($indent), $variables)), cons(id(listNewLine(add1($indent))), cons(boxString("liftIO (readIORef ("), cons(boxString("getField \@\""), cons(id(boxString(haskellFieldName(third($tree)))), cons(boxString("\" (expect hobj)))"), undef)))))))));

}


# Function haskellNewExpression from line 298

sub haskellNewExpression {
  my ($tree) = @_;
  
  if ( haskellTypeIsPointer(second($tree)) ) {
    return cons(boxString("liftIO (Just <\$> "), cons(id(boxString(haskellNewName(third($tree)))), cons(boxString(")"), undef)));

  } else {
    return cons(boxString("liftIO "), cons(id(boxString(haskellNewName(third($tree)))), undef));

  };

}


# Function haskellExpression from line 304

sub haskellExpression {
  my ($tree, $indent, $variables) = @_;
  my $thing = undef;

  if ( notBool(isList($tree)) ) {
    return haskellAtom($tree, $variables);

  } else {
    if ( equal(1, listLength($tree)) ) {
      if ( equalBox(boxString("return"), car($tree)) ) {
        return cons(boxString("pure "), cons(id(haskellFuncMap(car($tree), $variables)), undef));

      } else {
        return haskellCall(car($tree), undef, $indent, $variables);

      };

    } else {
      $thing = first($tree);

      if ( equalBox(boxSymbol("get-struct"), $thing) ) {
        return haskellGetStruct($tree, $indent, $variables);

      } else {
        if ( equalBox(boxSymbol("new"), $thing) ) {
          return haskellNewExpression($tree);

        } else {
          if ( equalBox(boxSymbol("passthrough"), $thing) ) {
            return cons(boxString("pure ("), cons(id(second($tree)), cons(boxString(")"), undef)));

          } else {
            if ( equalBox(boxSymbol("binop"), $thing) ) {
              return haskellBinop($tree, $indent, $variables);

            } else {
              return haskellCall(car($tree), cdr($tree), $indent, $variables);

            };

          };

        };

      };

    };

  };

}


# Function haskellSet from line 329

sub haskellSet {
  my ($node, $indent, $variables) = @_;
  
  return cons(id(listNewLine($indent)), cons(boxString("qset <- "), cons(id(haskellExpression(third($node), $indent, $variables)), cons(id(listNewLine($indent)), cons(boxString("liftIO (writeIORef "), cons(id(haskellFuncMap(second($node), $variables)), cons(boxString(" qset)"), undef)))))));

}


# Function haskellSetStruct from line 340

sub haskellSetStruct {
  my ($node, $indent, $variables) = @_;
  
  return cons(id(listNewLine($indent)), cons(boxString("hobj <- "), cons(id(haskellExpression(second($node), $indent, $variables)), cons(id(listNewLine($indent)), cons(boxString("qset <- "), cons(id(haskellExpression(fourth($node), $indent, $variables)), cons(id(listNewLine($indent)), cons(boxString("liftIO (writeIORef ("), cons(boxString("getField \@\""), cons(id(boxString(haskellFieldName(third($node)))), cons(boxString("\" (expect hobj)) qset)"), undef)))))))))));

}


# Function haskellReturn from line 355

sub haskellReturn {
  my ($node, $indent, $variables) = @_;
  
  if ( greaterthan(listLength($node), 1) ) {
    return cons(id(listNewLine($indent)), cons(boxString("hret <- "), cons(id(haskellExpression(cadr($node), $indent, $variables)), cons(id(listNewLine($indent)), cons(boxString("qreturn hret"), undef)))));

  } else {
    return cons(id(listNewLine($indent)), cons(boxString("qreturn ()"), undef));

  };

}


# Function haskellIf from line 366

sub haskellIf {
  my ($node, $indent, $variables) = @_;
  
  return cons(id(listNewLine($indent)), cons(boxString("hcond <- "), cons(id(haskellExpression(second($node), $indent, $variables)), cons(id(listNewLine($indent)), cons(boxString("if hcond"), cons(id(listNewLine($indent)), cons(boxString("  then do"), cons(id(haskellBody(cdr(third($node)), add($indent, 2), $variables)), cons(id(listNewLine(add($indent, 2))), cons(boxString("pure ()"), cons(id(listNewLine($indent)), cons(boxString("  else do"), cons(id(haskellBody(cdr(fourth($node)), add($indent, 2), $variables)), cons(id(listNewLine(add($indent, 2))), cons(boxString("pure ()"), undef)))))))))))))));

}


# Function haskellStatement from line 385

sub haskellStatement {
  my ($node, $indent, $variables) = @_;
  
  if ( equalBox(boxString("set"), first($node)) ) {
    return haskellSet($node, $indent, $variables);

  } else {
    if ( equalBox(boxString("set-struct"), first($node)) ) {
      return haskellSetStruct($node, $indent, $variables);

    } else {
      if ( equalBox(boxString("if"), first($node)) ) {
        return haskellIf($node, $indent, $variables);

      } else {
        if ( equalBox(boxString("return"), first($node)) ) {
          return haskellReturn($node, $indent, $variables);

        } else {
          return cons(id(listNewLine($indent)), cons(boxString("_ <- "), cons(id(haskellExpression($node, $indent, $variables)), undef)));

        };

      };

    };

  };

}


# Function haskellBody from line 403

sub haskellBody {
  my ($tree, $indent, $variables) = @_;
  
  if ( isEmpty($tree) ) {
    return emptyList();

  } else {
    return cons(id(haskellStatement(car($tree), $indent, $variables)), cons(id(haskellBody(cdr($tree), $indent, $variables)), undef));

  };

}


# Function haskellFunctionArgsSignature from line 411

sub haskellFunctionArgsSignature {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return emptyList();

  } else {
    if ( isNil(cddr($tree)) ) {
      return cons(id(haskellTypeMap(first($tree))), cons(boxString(" -> "), undef));

    } else {
      return cons(id(haskellTypeMap(first($tree))), cons(boxString(" -> "), cons(id(haskellFunctionArgsSignature(cddr($tree))), undef)));

    };

  };

}


# Function haskellFunctionArgs from line 420

sub haskellFunctionArgs {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return emptyList();

  } else {
    if ( isNil(cddr($tree)) ) {
      return cons(boxString(" "), cons(id(haskellFuncMap(second($tree), undef)), cons(boxString("_arg"), undef)));

    } else {
      return cons(boxString(" "), cons(id(haskellFuncMap(second($tree), undef)), cons(boxString("_arg"), cons(id(haskellFunctionArgs(cddr($tree))), undef))));

    };

  };

}


# Function haskellArgRefs from line 429

sub haskellArgRefs {
  my ($args, $indent) = @_;
  
  if ( isEmpty($args) ) {
    return emptyList();

  } else {
    return cons(id(listNewLine($indent)), cons(id(haskellFuncMap(second($args), undef)), cons(boxString(" <- liftIO (newIORef "), cons(id(haskellFuncMap(second($args), undef)), cons(boxString("_arg)"), cons(id(haskellArgRefs(cddr($args), $indent)), undef))))));

  };

}


# Function haskellDeclarations from line 441

sub haskellDeclarations {
  my ($decls, $indent, $variables) = @_;
  my $decl = undef;

  if ( isEmpty($decls) ) {
    return emptyList();

  } else {
    $decl = car($decls);

    return cons(id(listNewLine($indent)), cons(boxString("qinit <- "), cons(id(haskellExpression(third($decl), $indent, $variables)), cons(id(listNewLine($indent)), cons(id(haskellFuncMap(second($decl), undef)), cons(boxString(" <- liftIO (newIORef qinit)"), cons(id(haskellDeclarations(cdr($decls), $indent, $variables)), undef)))))));

  };

}


# Function haskellFunction from line 456

sub haskellFunction {
  my ($node) = @_;
  my $variables = undef;
my $args = undef;
my $decls = undef;

  if ( isNil($node) ) {
    return emptyList();

  } else {
    $args = third($node);

    $decls = cdr(fourth($node));

    $variables = haskellCollectVariables($args, $decls);

    return cons(id(listNewLine(0)), cons(id(haskellFuncMap(second($node), undef)), cons(boxString(" :: "), cons(id(haskellFunctionArgsSignature($args)), cons(boxString("IO "), cons(id(boxString(haskellRefType(first($node)))), cons(id(listNewLine(0)), cons(id(haskellFuncMap(second($node), undef)), cons(id(haskellFunctionArgs($args)), cons(boxString(" = evalContT \$ callCC \$ \\qreturn -> do"), cons(id(haskellArgRefs($args, 1)), cons(id(haskellDeclarations($decls, 1, $variables)), cons(id(haskellBody(cdr(fifth($node)), 1, $variables)), cons(id(listNewLine(1)), cons(boxString("pure "), cons(id(boxString(haskellDefaultValue(first($node)))), cons(boxString("\n"), undef)))))))))))))))));

  };

}


# Function haskellFunctions from line 483

sub haskellFunctions {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return emptyList();

  } else {
    return cons(id(haskellFunction(car($tree))), cons(id(haskellFunctions(cdr($tree))), undef));

  };

}


# Function haskellTypeDecl from line 491

sub haskellTypeDecl {
  my ($l) = @_;
  my $fieldType = undef;

  if ( greaterthan(listLength($l), 2) ) {
    $fieldType = listLast($l);

  } else {
    $fieldType = second($l);

  };

  return cons(boxString("  "), cons(id(boxString(haskellFieldName(first($l)))), cons(boxString(" :: IORef "), cons(id(boxString(haskellRefType($fieldType))), undef))));

}


# Function haskellStructFields from line 502

sub haskellStructFields {
  my ($node) = @_;
  
  if ( isEmpty($node) ) {
    return emptyList();

  } else {
    if ( isNil(cdr($node)) ) {
      return haskellTypeDecl(car($node));

    } else {
      return cons(id(haskellTypeDecl(car($node))), cons(boxString("\n, "), cons(id(haskellStructFields(cdr($node))), undef)));

    };

  };

}


# Function haskellNewStructField from line 514

sub haskellNewStructField {
  my ($l, $indent) = @_;
  my $fieldType = undef;

  if ( greaterthan(listLength($l), 2) ) {
    $fieldType = listLast($l);

  } else {
    $fieldType = second($l);

  };

  return cons(id(listNewLine($indent)), cons(boxString("v_"), cons(id(boxString(haskellFieldName(first($l)))), cons(boxString(" <- newIORef "), cons(id(boxString(haskellDefaultValue($fieldType))), undef)))));

}


# Function haskellNewStructFields from line 526

sub haskellNewStructFields {
  my ($fields, $indent) = @_;
  
  if ( isEmpty($fields) ) {
    return emptyList();

  } else {
    return cons(id(haskellNewStructField(car($fields), $indent)), cons(id(haskellNewStructFields(cdr($fields), $indent)), undef));

  };

}


# Function haskellStructCtorFields from line 534

sub haskellStructCtorFields {
  my ($fields) = @_;
  
  if ( isEmpty($fields) ) {
    return emptyList();

  } else {
    if ( isNil(cdr($fields)) ) {
      return cons(id(boxString(haskellFieldName(first(car($fields))))), cons(boxString(" = v_"), cons(id(boxString(haskellFieldName(first(car($fields))))), undef)));

    } else {
      return cons(id(boxString(haskellFieldName(first(car($fields))))), cons(boxString(" = v_"), cons(id(boxString(haskellFieldName(first(car($fields))))), cons(boxString(", "), cons(id(haskellStructCtorFields(cdr($fields))), undef)))));

    };

  };

}


# Function haskellType from line 548

sub haskellType {
  my ($node) = @_;
  my $fields = undef;

  if ( isList(second($node)) ) {
    $fields = cdr(second($node));

    return cons(boxString("\ndata "), cons(id(first($node)), cons(boxString(" = "), cons(id(first($node)), cons(boxString(" { "), cons(id(haskellStructFields($fields)), cons(boxString("\n}\n\n"), cons(id(boxString(haskellNewName(first($node)))), cons(boxString(" :: IO "), cons(id(first($node)), cons(boxString("\n"), cons(id(boxString(haskellNewName(first($node)))), cons(boxString(" = do"), cons(id(haskellNewStructFields($fields, 1)), cons(id(listNewLine(1)), cons(boxString("pure "), cons(id(first($node)), cons(boxString(" { "), cons(id(haskellStructCtorFields($fields)), cons(boxString(" }\n"), undef))))))))))))))))))));

  } else {
    return emptyList();

  };

}


# Function haskellTypes from line 576

sub haskellTypes {
  my ($nodes) = @_;
  
  if ( isEmpty($nodes) ) {
    return emptyList();

  } else {
    return cons(id(haskellType(car($nodes))), cons(id(haskellTypes(cdr($nodes))), undef));

  };

}


# Function haskellIncludes from line 584

sub haskellIncludes {
  my ($nodes) = @_;
  
  return cons(boxString("{-# LANGUAGE DataKinds #-}\n"), cons(boxString("{-# LANGUAGE DuplicateRecordFields #-}\n"), cons(boxString("{-# LANGUAGE ExtendedDefaultRules #-}\n"), cons(boxString("{-# LANGUAGE TypeApplications #-}\n"), cons(boxString("import Control.Monad.Trans.Cont\n"), cons(boxString("import Control.Monad.IO.Class\n"), cons(boxString("import Data.Char (chr)\n"), cons(boxString("import Data.IORef\n"), cons(boxString("import Data.Maybe (isNothing)\n"), cons(boxString("import GHC.Records (getField)\n"), cons(boxString("import System.Directory (doesFileExist)\n"), cons(boxString("import System.Environment (getArgs, lookupEnv)\n"), cons(boxString("import System.Exit (ExitCode(..), exitWith)\n"), cons(boxString("import System.IO (Handle, stderr, hPutStr, hFlush)\n"), cons(boxString("import System.IO.Unsafe (unsafePerformIO)\n"), cons(boxString("import Text.Printf (printf, hPrintf)\n\n"), cons(boxString("default (Int, Double)\n\n"), cons(boxString("expect :: Maybe a -> a\n"), cons(boxString("expect (Just x) = x\n"), cons(boxString("expect Nothing = error \"Quon nil dereference\"\n\n"), cons(boxString("globalTrace :: IORef Bool\n"), cons(boxString("globalTrace = unsafePerformIO (newIORef False)\n"), cons(boxString("{-# NOINLINE globalTrace #-}\n\n"), cons(boxString("globalStepTrace :: IORef Bool\n"), cons(boxString("globalStepTrace = unsafePerformIO (newIORef False)\n"), cons(boxString("{-# NOINLINE globalStepTrace #-}\n\n"), cons(boxString("releaseMode :: IORef Bool\n"), cons(boxString("releaseMode = unsafePerformIO (newIORef False)\n"), cons(boxString("{-# NOINLINE releaseMode #-}\n\n"), cons(boxString("caller :: IORef String\n"), cons(boxString("caller = unsafePerformIO (newIORef \"\")\n"), cons(boxString("{-# NOINLINE caller #-}\n\n"), cons(boxString("globalArgs :: IORef [String]\n"), cons(boxString("globalArgs = unsafePerformIO (newIORef [])\n"), cons(boxString("{-# NOINLINE globalArgs #-}\n\n"), cons(boxString("globalArgsCount :: IORef Int\n"), cons(boxString("globalArgsCount = unsafePerformIO (newIORef 0)\n"), cons(boxString("{-# NOINLINE globalArgsCount #-}\n\n"), cons(boxString("globalStackTrace :: IORef (Maybe Box)\n"), cons(boxString("globalStackTrace = unsafePerformIO (newIORef Nothing)\n"), cons(boxString("{-# NOINLINE globalStackTrace #-}\n\n"), cons(boxString("hsIsNil :: Maybe a -> IO Bool\n"), cons(boxString("hsIsNil = pure . isNothing\n\n"), cons(boxString("hsGetEnv :: String -> IO String\n"), cons(boxString("hsGetEnv key = do\n"), cons(boxString("  value <- lookupEnv key\n"), cons(boxString("  pure (maybe \"\" (\\x -> x) value)\n\n"), cons(boxString("hsPanic :: String -> IO ()\n"), cons(boxString("hsPanic = error\n\n"), cons(boxString("hsExit :: Int -> IO ()\n"), cons(boxString("hsExit 0 = exitWith ExitSuccess\n"), cons(boxString("hsExit n = exitWith (ExitFailure n)\n\n"), cons(boxString("hsStringLength :: String -> IO Int\n"), cons(boxString("hsStringLength = pure . length\n\n"), cons(boxString("hsSubString :: String -> Int -> Int -> IO String\n"), cons(boxString("hsSubString s start len = pure (take len (drop start s))\n\n"), cons(boxString("hsSetSubString :: String -> Int -> String -> IO String\n"), cons(boxString("hsSetSubString target start source = pure (take start target ++ source ++ drop (start + 1) target)\n\n"), cons(boxString("hsShowInt :: Int -> IO String\n"), cons(boxString("hsShowInt = pure . show\n\n"), cons(boxString("hsShowFloat :: Double -> IO String\n"), cons(boxString("hsShowFloat = pure . show\n\n"), cons(boxString("hsReadFile :: String -> IO (Maybe Box)\n"), cons(boxString("hsReadFile filename = do\n"), cons(boxString("  exists <- doesFileExist filename\n"), cons(boxString("  if exists then do\n"), cons(boxString("    contents <- readFile filename\n"), cons(boxString("    boxString contents\n"), cons(boxString("  else pure Nothing\n\n"), cons(boxString("hsWriteFile :: String -> String -> IO ()\n"), cons(boxString("hsWriteFile = writeFile\n\n"), cons(boxString("hsGetStringArray :: Int -> [String] -> IO String\n"), cons(boxString("hsGetStringArray index strs = pure (strs !! index)\n\n"), cons(boxString("hsProgramArgs :: IO [String]\n"), cons(boxString("hsProgramArgs = readIORef globalArgs\n\n"), cons(boxString("hsProgramArgsCount :: IO Int\n"), cons(boxString("hsProgramArgsCount = readIORef globalArgsCount\n\n"), cons(boxString("hsCharacter :: Int -> IO String\n"), cons(boxString("hsCharacter num = pure [chr num]\n\n"), cons(boxString("hsRemainder :: Int -> Int -> IO Int\n"), cons(boxString("hsRemainder a b = pure (a `mod` b)\n\n"), cons(boxString("hsMakeHash :: IO (IORef [(String, String)])\n"), cons(boxString("hsMakeHash = newIORef []\n\n"), cons(boxString("hsSetHash :: IORef [(String, String)] -> String -> String -> IO ()\n"), cons(boxString("hsSetHash hash key value = modifyIORef hash ((key, value) :)\n\n"), cons(boxString("hsGetHash :: IORef [(String, String)] -> String -> IO String\n"), cons(boxString("hsGetHash hash key = do\n"), cons(boxString("  pairs <- readIORef hash\n"), cons(boxString("  pure (maybe \"\" (\\x -> x) (lookup key pairs))\n\n"), cons(boxString("hsInHash :: IORef [(String, String)] -> String -> IO Bool\n"), cons(boxString("hsInHash hash key = do\n"), cons(boxString("  pairs <- readIORef hash\n"), cons(boxString("  pure (not (isNothing (lookup key pairs)))\n\n"), cons(boxString("hsMakeArray :: Int -> IO [String]\n"), cons(boxString("hsMakeArray len = pure (replicate len \"\")\n\n"), cons(boxString("hsSetArray :: [String] -> Int -> String -> IO ()\n"), cons(boxString("hsSetArray _ _ _ = pure ()\n\n"), cons(boxString("hsGetArray :: [String] -> Int -> IO String\n"), cons(boxString("hsGetArray array index = pure (array !! index)\n\n"), undef)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));

}


# Function haskellMainEntry from line 687

sub haskellMainEntry {
  my () = @_;
  
  return cons(boxString("\nmain :: IO ()\n"), cons(boxString("main = do\n"), cons(boxString("  args <- getArgs\n"), cons(boxString("  let qargs = \"fixmeprogname\" : args\n"), cons(boxString("  writeIORef globalArgs qargs\n"), cons(boxString("  writeIORef globalArgsCount (length qargs)\n"), cons(boxString("  _ <- start\n"), cons(boxString("  pure ()\n"), undef))))))));

}


# Function haskellApplyTypeAliases from line 699

sub haskellApplyTypeAliases {
  my ($tree, $types) = @_;
  my $node = undef;
my $alias = undef;
my $target = undef;

  if ( isEmpty($types) ) {
    return $tree;

  } else {
  };

  $node = car($types);

  if ( isList(second($node)) ) {
    return haskellApplyTypeAliases($tree, cdr($types));

  } else {
  };

  $alias = first($node);

  if ( equalString(stringify(haskellTypeMap($alias)), stringify($alias)) ) {
    $target = haskellTypeMap(second($node));

    return haskellApplyTypeAliases(macroSymbolSingle($tree, stringify($alias), stringify($target)), cdr($types));

  } else {
    return haskellApplyTypeAliases($tree, cdr($types));

  };

}


# Function haskellLoadProgram from line 715

sub haskellLoadProgram {
  my ($filename) = @_;
  my $tree = undef;
my $replace = undef;

  $tree = loadQuon($filename);

  $tree = insertInclude($tree, "q/shims/haskell.qon");

  $tree = loadIncludes($tree, undef);

  $tree = macrowalk($tree);

  $replace = cons(boxSymbol("hPrintf"), cons(boxSymbol("stderr"), undef));

  $tree = macrolist($tree, stringConcatenate("q", "log"), $replace);

  $tree = haskellApplyTypeAliases($tree, cdr(getTypes($tree)));

  return $tree;

}


# Function haskellProgramTree from line 726

sub haskellProgramTree {
  my ($tree) = @_;
  
  return cons(id(haskellIncludes(cdr(first($tree)))), cons(id(haskellTypes(cdr(second($tree)))), cons(id(haskellFunctions(cdr(third($tree)))), cons(id(haskellMainEntry()), cons(boxString("\n"), undef)))));

}


# Function haskellProgram from line 735

sub haskellProgram {
  my ($tree) = @_;
  
  return ListToString(flatten(haskellProgramTree($tree)), 0, $true, $false);

}


# Function haskellCompileString from line 739

sub haskellCompileString {
  my ($filename) = @_;
  
  return haskellProgram(haskellLoadProgram($filename));

}


# Function haskellCompile from line 743

sub haskellCompile {
  my ($filename) = @_;
  my $tree = undef;
my $replace = undef;

  fprintf($stderr, "Scanning file...%s\n", $filename);

  $tree = loadQuon($filename);

  fprintf($stderr, "Adding Haskell shim functions\n");

  $tree = insertInclude($tree, "q/shims/haskell.qon");

  fprintf($stderr, "Loading includes\n");

  $tree = loadIncludes($tree, undef);

  fprintf($stderr, "Walking tree\n");

  $tree = macrowalk($tree);

  fprintf($stderr, "Replacing q log\n");

  $replace = cons(boxSymbol("hPrintf"), cons(boxSymbol("stderr"), undef));

  $tree = macrolist($tree, stringConcatenate("q", "log"), $replace);

  $tree = haskellApplyTypeAliases($tree, cdr(getTypes($tree)));

  fprintf($stderr, "Printing program\n");

  printStringTree(haskellProgramTree($tree));

}


# Function javaFunctionArgs from line 5

sub javaFunctionArgs {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return emptyList();

  } else {
    if ( equalString(stringify(first($tree)), "...") ) {
      if ( isNil(cddr($tree)) ) {
        return cons(boxString("Object... args"), undef);

      } else {
        return cons(boxString("Object... args, "), cons(id(javaFunctionArgs(cddr($tree))), undef));

      };

    } else {
      if ( isNil(cddr($tree)) ) {
        return cons(id(javaTypeMap(first($tree))), cons(boxString(" "), cons(id(javaFuncMap(second($tree))), undef)));

      } else {
        return cons(id(javaTypeMap(first($tree))), cons(boxString(" "), cons(id(javaFuncMap(second($tree))), cons(boxString(", "), cons(id(javaFunctionArgs(cddr($tree))), undef)))));

      };

    };

  };

}


# Function javaAtom from line 26

sub javaAtom {
  my ($tree) = @_;
  
  if ( equalString("string", boxType($tree)) ) {
    return cons(boxString("\""), cons(id(boxString(stringify($tree))), cons(boxString("\""), undef)));

  } else {
    return cons(id(javaFuncMap($tree)), undef);

  };

}


# Function javaExpression from line 32

sub javaExpression {
  my ($tree, $indent) = @_;
  my $thing = undef;

  if ( notBool(isList($tree)) ) {
    return javaAtom($tree);

  } else {
    if ( equal(1, listLength($tree)) ) {
      if ( equalBox(boxString("return"), car($tree)) ) {
        return cons(id(javaFuncMap(car($tree))), undef);

      } else {
        return cons(id(javaFuncMap(car($tree))), cons(boxString("()"), undef));

      };

    } else {
      $thing = first($tree);

      if ( equalBox(boxSymbol("get-struct"), $thing) ) {
        return cons(id(javaExpression(second($tree), $indent)), cons(boxString("."), cons(id(third($tree)), undef)));

      } else {
        if ( equalBox(boxSymbol("new"), $thing) ) {
          return cons(boxString("new "), cons(id(javaTypeMap(second($tree))), cons(boxString("()"), undef)));

        } else {
          if ( equalBox(boxSymbol("passthrough"), $thing) ) {
            return cons(id(second($tree)), undef);

          } else {
            if ( equalBox(boxSymbol("binop"), $thing) ) {
              return cons(boxString("("), cons(id(javaExpression(third($tree), $indent)), cons(boxString(" "), cons(id(second($tree)), cons(boxString(" "), cons(id(javaExpression(fourth($tree), $indent)), cons(boxString(")"), undef)))))));

            } else {
              return cons(id(javaFuncMap(car($tree))), cons(boxString("("), cons(id(javaRecurList(cdr($tree), $indent)), cons(boxString(")"), undef))));

            };

          };

        };

      };

    };

  };

}


# Function javaRecurList from line 78

sub javaRecurList {
  my ($expr, $indent) = @_;
  
  if ( isEmpty($expr) ) {
    return emptyList();

  } else {
    if ( isNil(cdr($expr)) ) {
      return javaExpression(car($expr), $indent);

    } else {
      return cons(id(javaExpression(car($expr), $indent)), cons(boxString(", "), cons(id(javaRecurList(cdr($expr), $indent)), undef)));

    };

  };

}


# Function javaIf from line 91

sub javaIf {
  my ($node, $indent) = @_;
  
  return cons(id(listNewLine($indent)), cons(boxString("if ( "), cons(id(javaExpression(second($node), 0)), cons(boxString(") {"), cons(id(javaBody(cdr(third($node)), add1($indent))), cons(id(listNewLine($indent)), cons(boxString("} else {"), cons(id(javaBody(cdr(fourth($node)), add1($indent))), cons(id(listNewLine($indent)), cons(boxString("}"), undef))))))))));

}


# Function javaSetStruct from line 105

sub javaSetStruct {
  my ($node, $indent) = @_;
  
  return cons(id(listNewLine($indent)), cons(id(javaExpression(second($node), $indent)), cons(boxString("."), cons(id(third($node)), cons(boxString(" = "), cons(id(javaExpression(fourth($node), $indent)), undef))))));

}


# Function javaSet from line 115

sub javaSet {
  my ($node, $indent) = @_;
  
  return cons(id(listNewLine($indent)), cons(id(javaExpression(second($node), $indent)), cons(boxString(" = "), cons(id(javaExpression(third($node), $indent)), undef))));

}


# Function javaReturn from line 123

sub javaReturn {
  my ($node, $indent) = @_;
  
  if ( equal(listLength($node), 1) ) {
    return cons(id(listNewLine($indent)), cons(boxString("return"), undef));

  } else {
    return cons(id(listNewLine($indent)), cons(boxString("return "), cons(id(javaExpression(cadr($node), $indent)), undef)));

  };

}


# Function javaStatement from line 133

sub javaStatement {
  my ($node, $indent) = @_;
  
  if ( equalBox(boxString("set"), first($node)) ) {
    return cons(id(javaSet($node, $indent)), cons(boxString(";\n"), undef));

  } else {
    if ( equalBox(boxString("set-struct"), first($node)) ) {
      return cons(id(javaSetStruct($node, $indent)), cons(boxString(";\n"), undef));

    } else {
      if ( equalBox(boxString("if"), first($node)) ) {
        return cons(id(javaIf($node, $indent)), cons(boxString("\n"), undef));

      } else {
        if ( equalBox(boxString("return"), first($node)) ) {
          return cons(id(javaReturn($node, $indent)), cons(boxString(";\n"), undef));

        } else {
          return cons(id(listNewLine($indent)), cons(id(javaExpression($node, $indent)), cons(boxString(";\n"), undef)));

        };

      };

    };

  };

}


# Function javaBody from line 152

sub javaBody {
  my ($tree, $indent) = @_;
  my $code = undef;

  if ( isEmpty($tree) ) {
    return emptyList();

  } else {
    $code = car($tree);

    return cons(id(javaStatement($code, $indent)), cons(id(javaBody(cdr($tree), $indent)), undef));

  };

}


# Function javaDeclarations from line 162

sub javaDeclarations {
  my ($decls, $indent) = @_;
  my $decl = undef;

  if ( isEmpty($decls) ) {
    return emptyList();

  } else {
    $decl = car($decls);

    return cons(id(javaTypeMap(first($decl))), cons(boxString(" "), cons(id(javaFuncMap(second($decl))), cons(boxString(" = "), cons(id(javaExpression(third($decl), $indent)), cons(boxString(";\n"), cons(id(javaDeclarations(cdr($decls), $indent)), undef)))))));

  };

}


# Function javaFunction from line 177

sub javaFunction {
  my ($node) = @_;
  my $name = undef;

  $name = second($node);

  if ( isNil($node) ) {
    return emptyList();

  } else {
    return cons(id(listNewLine(0)), cons(id(listNewLine(0)), cons(id(javaTypeMap(first($node))), cons(boxString(" "), cons(id(javaFuncMap(second($node))), cons(boxString("("), cons(id(javaFunctionArgs(third($node))), cons(boxString(") {"), cons(id(listNewLine(1)), cons(id(javaDeclarations(cdr(fourth($node)), 1)), cons(id(javaBody(cdr(fifth($node)), 1)), cons(boxString("\n}\n"), undef))))))))))));

  };

}


# Function javaFunctions from line 197

sub javaFunctions {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return emptyList();

  } else {
    return cons(id(javaFunction(car($tree))), cons(id(javaFunctions(cdr($tree))), undef));

  };

}


# Function javaIncludes from line 206

sub javaIncludes {
  my ($nodes) = @_;
  
  return cons(boxString("import java.nio.charset.StandardCharsets;\n"), cons(boxString("import java.nio.file.Files;\n"), cons(boxString("import java.nio.file.Paths;\n"), cons(boxString("import java.util.HashMap;\n\n"), cons(boxString("class QuonProgram {\n"), cons(boxString("  boolean globalTrace = false;\n"), cons(boxString("  boolean globalStepTrace = false;\n"), cons(boxString("  boolean releaseMode = false;\n"), cons(boxString("  Box globalStackTrace = null;\n"), cons(boxString("  String caller = \"\";\n"), cons(boxString("  String[] globalArgs = new String[0];\n"), cons(boxString("  int globalArgsCount = 0;\n\n"), cons(boxString("  Object stderr = new Object();\n\n"), cons(boxString("  void fprintf(Object stream, String format, Object... args) {\n"), cons(boxString("    if (args.length == 0) {\n"), cons(boxString("      System.err.print(format);\n"), cons(boxString("    } else {\n"), cons(boxString("      System.err.printf(format, args);\n"), cons(boxString("    }\n"), cons(boxString("  }\n\n"), cons(boxString("  void exit(int code) {\n"), cons(boxString("    System.exit(code);\n"), cons(boxString("  }\n\n"), cons(boxString("  Box readFileBox(String filename) {\n"), cons(boxString("    try {\n"), cons(boxString("      return boxString(Files.readString(Paths.get(filename)));\n"), cons(boxString("    } catch (Exception e) {\n"), cons(boxString("      return null;\n"), cons(boxString("    }\n"), cons(boxString("  }\n\n"), cons(boxString("  void writeFileUnchecked(String filename, String data) {\n"), cons(boxString("    try {\n"), cons(boxString("      Files.write(Paths.get(filename), data.getBytes(StandardCharsets.UTF_8));\n"), cons(boxString("    } catch (Exception e) {\n"), cons(boxString("      throw new RuntimeException(\"Could not write file: \" + filename, e);\n"), cons(boxString("    }\n"), cons(boxString("  }\n"), undef)))))))))))))))))))))))))))))))))))));

}


# Function javaTypeMap from line 247

sub javaTypeMap {
  my ($aSym) = @_;
  my $symMap = undef;

  $symMap = alistCons(boxSymbol("pair"), boxSymbol("Box"), alistCons(boxSymbol("box"), boxSymbol("Box"), alistCons(boxSymbol("list"), boxSymbol("Box"), alistCons(boxSymbol("Box*"), boxSymbol("Box"), alistCons(boxSymbol("struct"), boxSymbol(""), alistCons(boxSymbol("bool"), boxSymbol("boolean"), alistCons(boxSymbol("uint"), boxSymbol("int"), alistCons(boxSymbol("float"), boxSymbol("double"), alistCons(boxSymbol("stringArray"), boxSymbol("String[]"), alistCons(boxSymbol("array"), boxSymbol("String[]"), alistCons(boxSymbol("hashmap"), boxSymbol("HashMap<String, String>"), alistCons(boxSymbol("string"), boxSymbol("String"), undef))))))))))));

  if ( truthy(assoc(stringify($aSym), $symMap)) ) {
    return cdr(assoc(stringify($aSym), $symMap));

  } else {
    return $aSym;

  };

}


# Function javaPointerBase from line 267

sub javaPointerBase {
  my ($aSym) = @_;
  my $name = "";

  $name = stringify($aSym);

  if ( equalString("*", substr($name, sub1(length($name)), 1)) ) {
    return boxSymbol(substr($name, 0, sub1(length($name))));

  } else {
    return $aSym;

  };

}


# Function javaFuncMap from line 274

sub javaFuncMap {
  my ($aSym) = @_;
  my $symMap = undef;

  if ( equalString("symbol", boxType($aSym)) ) {
    $symMap = alistCons(boxSymbol("printf"), boxSymbol("System.out.printf"), alistCons(boxSymbol(stringConcatenate("q", "log")), boxSymbol("System.err.printf"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("null"), alistCons(boxSymbol("old"), boxSymbol("oldValue"), alistCons(boxSymbol("new"), boxSymbol("newValue"), undef)))))))))));

    if ( truthy(assoc(stringify($aSym), $symMap)) ) {
      return cdr(assoc(stringify($aSym), $symMap));

    } else {
      return $aSym;

    };

  } else {
    return $aSym;

  };

}


# Function javaTypeDecl from line 316

sub javaTypeDecl {
  my ($l) = @_;
  
  if ( greaterthan(listLength($l), 2) ) {
    return cons(id(boxString(stringIndent(1))), cons(id(javaTypeMap(listLast($l))), cons(boxString(" "), cons(id(first($l)), cons(boxString(";\n"), undef)))));

  } else {
    return cons(id(boxString(stringIndent(1))), cons(id(javaTypeMap(listLast($l))), cons(boxString(" "), cons(id(car($l)), cons(boxString(";\n"), undef)))));

  };

}


# Function javaStructComponents from line 334

sub javaStructComponents {
  my ($node) = @_;
  
  if ( isEmpty($node) ) {
    return emptyList();

  } else {
    return cons(id(javaTypeDecl(car($node))), cons(id(javaStructComponents(cdr($node))), undef));

  };

}


# Function javaStruct from line 343

sub javaStruct {
  my ($node) = @_;
  
  return javaStructComponents(cdr($node));

}


# Function javaType from line 347

sub javaType {
  my ($node) = @_;
  
  if ( isList(second($node)) ) {
    return cons(boxString("\nclass "), cons(id(first($node)), cons(boxString(" {\n"), cons(id(javaStruct(second($node))), cons(boxString("}\n"), undef)))));

  } else {
    return emptyList();

  };

}


# Function javaTypes from line 359

sub javaTypes {
  my ($nodes) = @_;
  
  if ( isEmpty($nodes) ) {
    return emptyList();

  } else {
    return cons(id(javaType(car($nodes))), cons(id(javaTypes(cdr($nodes))), undef));

  };

}


# Function javaApplyTypeAliases from line 368

sub javaApplyTypeAliases {
  my ($tree, $types) = @_;
  my $node = undef;
my $alias = undef;
my $target = undef;

  if ( isEmpty($types) ) {
    return $tree;

  } else {
  };

  $node = car($types);

  if ( isList(second($node)) ) {
    return javaApplyTypeAliases($tree, cdr($types));

  } else {
  };

  $alias = first($node);

  if ( equalString(stringify(javaTypeMap($alias)), stringify($alias)) ) {
    $target = javaTypeMap(javaPointerBase(second($node)));

    return javaApplyTypeAliases(macroSymbolSingle($tree, stringify($alias), stringify($target)), cdr($types));

  } else {
    return javaApplyTypeAliases($tree, cdr($types));

  };

}


# Function javaMainEntry from line 384

sub javaMainEntry {
  my () = @_;
  
  return cons(boxString("\npublic static void main(String[] args) {\n"), cons(boxString("  QuonProgram program = new QuonProgram();\n"), cons(boxString("  program.globalArgs = new String[args.length + 1];\n"), cons(boxString("  program.globalArgs[0] = \"fixmeprogname\";\n"), cons(boxString("  System.arraycopy(args, 0, program.globalArgs, 1, args.length);\n"), cons(boxString("  program.globalArgsCount = program.globalArgs.length;\n"), cons(boxString("  program.start();\n"), cons(boxString("}\n"), cons(boxString("}\n"), undef)))))))));

}


# Function javaLoadProgram from line 397

sub javaLoadProgram {
  my ($filename) = @_;
  my $tree = undef;
my $replace = undef;

  $tree = loadQuon($filename);

  $tree = buildProg(cons(boxString("q/shims/java.qon"), getIncludes($tree)), getTypes($tree), getFunctions($tree));

  $tree = loadIncludes($tree, undef);

  $tree = macrowalk($tree);

  $replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), undef));

  $tree = macrolist($tree, stringConcatenate("q", "log"), $replace);

  $tree = javaApplyTypeAliases($tree, cdr(getTypes($tree)));

  return $tree;

}


# Function javaProgramTree from line 408

sub javaProgramTree {
  my ($tree) = @_;
  
  return cons(id(javaIncludes(cdr(first($tree)))), cons(id(javaTypes(cdr(second($tree)))), cons(id(javaFunctions(cdr(third($tree)))), cons(id(javaMainEntry()), cons(boxString("\n"), undef)))));

}


# Function javaProgram from line 417

sub javaProgram {
  my ($tree) = @_;
  
  return ListToString(flatten(javaProgramTree($tree)), 0, $true, $false);

}


# Function javaCompileString from line 421

sub javaCompileString {
  my ($filename) = @_;
  
  return javaProgram(javaLoadProgram($filename));

}


# Function javaCompile from line 425

sub javaCompile {
  my ($filename) = @_;
  
  printStringTree(javaProgramTree(javaLoadProgram($filename)));

  fprintf($stderr, "//Done printing program\n");

}


# Function ansi3FunctionArgs from line 5

sub ansi3FunctionArgs {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return emptyList();

  } else {
    if ( equalString(stringify(first($tree)), "...") ) {
      if ( isNil(cddr($tree)) ) {
        return cons(boxString("..."), undef);

      } else {
        return cons(boxString("..."), cons(boxString(", "), cons(id(ansi3FunctionArgs(cddr($tree))), undef)));

      };

    } else {
      if ( isNil(cddr($tree)) ) {
        return cons(id(ansi3TypeMap(first($tree))), cons(boxString(" "), cons(id(second($tree)), undef)));

      } else {
        return cons(id(ansi3TypeMap(first($tree))), cons(boxString(" "), cons(id(second($tree)), cons(boxString(", "), cons(id(ansi3FunctionArgs(cddr($tree))), undef)))));

      };

    };

  };

}


# Function ansi3Atom from line 26

sub ansi3Atom {
  my ($tree) = @_;
  
  if ( equalString("string", boxType($tree)) ) {
    return cons(boxString("\""), cons(id(boxString(stringify($tree))), cons(boxString("\""), undef)));

  } else {
    return cons(id(ansi3FuncMap($tree)), undef);

  };

}


# Function ansi3Expression from line 32

sub ansi3Expression {
  my ($tree, $indent) = @_;
  my $thing = undef;

  if ( notBool(isList($tree)) ) {
    return ansi3Atom($tree);

  } else {
    if ( equal(1, listLength($tree)) ) {
      if ( equalBox(boxString("return"), car($tree)) ) {
        return cons(id(ansi3FuncMap(car($tree))), undef);

      } else {
        return cons(id(ansi3FuncMap(car($tree))), cons(boxString("()"), undef));

      };

    } else {
      $thing = first($tree);

      if ( equalBox(boxSymbol("get-struct"), $thing) ) {
        return cons(id(second($tree)), cons(boxString("->"), cons(id(third($tree)), undef)));

      } else {
        if ( equalBox(boxSymbol("new"), $thing) ) {
          return cons(boxString("malloc(sizeof("), cons(id(third($tree)), cons(boxString("))"), undef)));

        } else {
          if ( equalBox(boxSymbol("passthrough"), $thing) ) {
            return cons(id(second($tree)), undef);

          } else {
            if ( equalBox(boxSymbol("binop"), $thing) ) {
              return cons(boxString("("), cons(id(ansi3Expression(third($tree), $indent)), cons(boxString(" "), cons(id(second($tree)), cons(boxString(" "), cons(id(ansi3Expression(fourth($tree), $indent)), cons(boxString(")"), undef)))))));

            } else {
              return cons(id(ansi3FuncMap(car($tree))), cons(boxString("("), cons(id(ansi3RecurList(cdr($tree), $indent)), cons(boxString(")"), undef))));

            };

          };

        };

      };

    };

  };

}


# Function ansi3RecurList from line 78

sub ansi3RecurList {
  my ($expr, $indent) = @_;
  
  if ( isEmpty($expr) ) {
    return emptyList();

  } else {
    if ( isNil(cdr($expr)) ) {
      return ansi3Expression(car($expr), $indent);

    } else {
      return cons(id(ansi3Expression(car($expr), $indent)), cons(boxString(", "), cons(id(ansi3RecurList(cdr($expr), $indent)), undef)));

    };

  };

}


# Function ansi3If from line 91

sub ansi3If {
  my ($node, $indent, $functionName) = @_;
  
  return cons(id(listNewLine($indent)), cons(boxString("if ( "), cons(id(ansi3Expression(second($node), 0)), cons(boxString(") {"), cons(id(ansi3Body(cdr(third($node)), add1($indent), $functionName)), cons(id(listNewLine($indent)), cons(boxString("} else {"), cons(id(ansi3Body(cdr(fourth($node)), add1($indent), $functionName)), cons(id(listNewLine($indent)), cons(boxString("}"), undef))))))))));

}


# Function ansi3SetStruct from line 105

sub ansi3SetStruct {
  my ($node, $indent) = @_;
  
  return cons(id(listNewLine($indent)), cons(id(second($node)), cons(boxString("->"), cons(id(third($node)), cons(boxString(" = "), cons(id(ansi3Expression(fourth($node), $indent)), undef))))));

}


# Function ansi3Set from line 115

sub ansi3Set {
  my ($node, $indent) = @_;
  
  return cons(id(listNewLine($indent)), cons(id(ansi3Expression(second($node), $indent)), cons(boxString(" = "), cons(id(ansi3Expression(third($node), $indent)), undef))));

}


# Function ansi3Return from line 123

sub ansi3Return {
  my ($node, $indent) = @_;
  
  if ( equal(listLength($node), 1) ) {
    return cons(id(listNewLine($indent)), cons(boxString("return;"), undef));

  } else {
    return cons(id(listNewLine($indent)), cons(boxString("return "), cons(id(ansi3Expression(cadr($node), $indent)), cons(boxString(";"), undef))));

  };

}


# Function ansi3TraceReturn from line 134

sub ansi3TraceReturn {
  my ($node, $indent, $functionName) = @_;
  
  if ( $releaseMode ) {
    return ansi3Return($node, $indent);

  } else {
    if ( inList(boxString($functionName), NoStackTrace_list()) ) {
      return ansi3Return($node, $indent);

    } else {
      return cons(boxString("\n"), cons(id(boxString(stringIndent($indent))), cons(boxString("StackTraceMove(\"out\", \"\", \"\", \"\");\n"), cons(id(ansi3Return($node, $indent)), undef))));

    };

  };

}


# Function ansi3Statement from line 148

sub ansi3Statement {
  my ($node, $indent, $functionName) = @_;
  
  if ( equalBox(boxString("set"), first($node)) ) {
    return cons(id(ansi3Set($node, $indent)), cons(boxString(";\n"), undef));

  } else {
    if ( equalBox(boxString("set-struct"), first($node)) ) {
      return cons(id(ansi3SetStruct($node, $indent)), cons(boxString(";\n"), undef));

    } else {
      if ( equalBox(boxString("if"), first($node)) ) {
        return cons(id(ansi3If($node, $indent, $functionName)), cons(boxString(";\n"), undef));

      } else {
        if ( equalBox(boxString("return"), first($node)) ) {
          return cons(id(ansi3TraceReturn($node, $indent, $functionName)), cons(boxString(";\n"), undef));

        } else {
          return cons(id(listNewLine($indent)), cons(id(ansi3Expression($node, $indent)), cons(boxString(";\n"), undef)));

        };

      };

    };

  };

}


# Function ansi3StatementTrace from line 167

sub ansi3StatementTrace {
  my ($code, $indent, $functionName) = @_;
  
  if ( $releaseMode ) {
    return emptyList();

  } else {
    if ( inList(boxString($functionName), NoTrace_list()) ) {
      return emptyList();

    } else {
      return cons(boxString("\nif (globalTrace)\n    snprintf(caller, 1024, \"from "), cons(id(getTagFail(car($code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), cons(boxString(":"), cons(id(getTagFail(car($code), boxString("line"), boxString("Line missing"))), cons(boxString("\");\n"), undef)))));

    };

  };

}


# Function ansi3StepTrace from line 182

sub ansi3StepTrace {
  my ($indent) = @_;
  
  if ( $releaseMode ) {
    return emptyList();

  } else {
    return cons(id(boxString(stringIndent($indent))), cons(boxString("if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n"), undef));

  };

}


# Function ansi3Body from line 191

sub ansi3Body {
  my ($tree, $indent, $functionName) = @_;
  my $code = undef;

  if ( isEmpty($tree) ) {
    return emptyList();

  } else {
    $code = car($tree);

    return cons(id(ansi3StatementTrace($code, $indent, $functionName)), cons(id(ansi3StepTrace($indent)), cons(id(ansi3Statement($code, $indent, $functionName)), cons(id(ansi3Body(cdr($tree), $indent, $functionName)), undef))));

  };

}


# Function ansi3Declarations from line 203

sub ansi3Declarations {
  my ($decls, $indent) = @_;
  my $decl = undef;

  if ( isEmpty($decls) ) {
    return emptyList();

  } else {
    $decl = car($decls);

    return cons(id(ansi3TypeMap(first($decl))), cons(boxString(" "), cons(id(second($decl)), cons(boxString(" = "), cons(id(ansi3Expression(third($decl), $indent)), cons(boxString(";\n"), cons(id(ansi3Declarations(cdr($decls), $indent)), undef)))))));

  };

}


# Function ansi3FunctionTrace from line 218

sub ansi3FunctionTrace {
  my ($name) = @_;
  
  if ( $releaseMode ) {
    return emptyList();

  } else {
    if ( inList($name, NoTrace_list()) ) {
      return emptyList();

    } else {
      return cons(boxString("\nif (globalTrace)\n    printf(\""), cons(id($name), cons(boxString(" at "), cons(id(getTag($name, boxString("filename"))), cons(boxString(":"), cons(id(getTag($name, boxString("line"))), cons(boxString(" (%s)\\n\", caller);\n"), undef)))))));

    };

  };

}


# Function ansi3FunctionStackTrace from line 235

sub ansi3FunctionStackTrace {
  my ($name) = @_;
  
  if ( $releaseMode ) {
    return emptyList();

  } else {
    if ( inList($name, NoStackTrace_list()) ) {
      return emptyList();

    } else {
      return cons(boxString("\n  StackTraceMove(\"in\", \""), cons(id(getTag($name, boxString("filename"))), cons(boxString("\", \""), cons(id($name), cons(boxString("\", \""), cons(id(getTag($name, boxString("line"))), cons(boxString("\" );\n"), undef)))))));

    };

  };

}


# Function ansi3Function from line 252

sub ansi3Function {
  my ($node) = @_;
  my $name = undef;

  $name = second($node);

  if ( isNil($node) ) {
    return emptyList();

  } else {
    return cons(id(listNewLine(0)), cons(id(listNewLine(0)), cons(id(ansi3TypeMap(first($node))), cons(boxString(" "), cons(id(second($node)), cons(boxString("("), cons(id(ansi3FunctionArgs(third($node))), cons(boxString(") {"), cons(id(listNewLine(1)), cons(id(ansi3Declarations(cdr(fourth($node)), 1)), cons(id(ansi3FunctionTrace($name)), cons(id(ansi3FunctionStackTrace($name)), cons(id(ansi3Body(cdr(fifth($node)), 1, stringify($name))), cons(boxString("\n}\n"), undef))))))))))))));

  };

}


# Function ansi3ForwardDeclaration from line 274

sub ansi3ForwardDeclaration {
  my ($node) = @_;
  
  if ( isNil($node) ) {
    return emptyList();

  } else {
    return cons(boxString("\n"), cons(id(ansi3TypeMap(first($node))), cons(boxString(" "), cons(id(second($node)), cons(boxString("("), cons(id(ansi3FunctionArgs(third($node))), cons(boxString(");"), undef)))))));

  };

}


# Function ansi3ForwardDeclarations from line 288

sub ansi3ForwardDeclarations {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return emptyList();

  } else {
    return cons(id(ansi3ForwardDeclaration(car($tree))), cons(id(ansi3ForwardDeclarations(cdr($tree))), undef));

  };

}


# Function ansi3Functions from line 297

sub ansi3Functions {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return emptyList();

  } else {
    return cons(id(ansi3Function(car($tree))), cons(id(ansi3Functions(cdr($tree))), undef));

  };

}


# Function ansi3Includes from line 306

sub ansi3Includes {
  my ($nodes) = @_;
  
  return cons(boxString("\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\n#include <unistd.h>\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\nbool releaseMode = false;\n\n"), cons(boxString("void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n"), undef));

}


# Function ansi3TypeDecl from line 312

sub ansi3TypeDecl {
  my ($l) = @_;
  
  if ( greaterthan(listLength($l), 2) ) {
    return cons(id(boxString(stringIndent(1))), cons(id(second($l)), cons(boxString(" "), cons(id(ansi3TypeMap(listLast($l))), cons(boxString(" "), cons(id(first($l)), cons(boxString(";\n"), undef)))))));

  } else {
    return cons(id(boxString(stringIndent(1))), cons(id(ansi3TypeMap(listLast($l))), cons(boxString(" "), cons(id(car($l)), cons(boxString(";\n"), undef)))));

  };

}


# Function ansi3StructComponents from line 332

sub ansi3StructComponents {
  my ($node) = @_;
  
  if ( isEmpty($node) ) {
    return emptyList();

  } else {
    return cons(id(ansi3TypeDecl(car($node))), cons(id(ansi3StructComponents(cdr($node))), undef));

  };

}


# Function ansi3Struct from line 341

sub ansi3Struct {
  my ($node) = @_;
  
  return ansi3StructComponents(cdr($node));

}


# Function ansi3TypeMap from line 345

sub ansi3TypeMap {
  my ($aSym) = @_;
  my $symMap = undef;

  $symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), undef));

  if ( truthy(assoc(stringify($aSym), $symMap)) ) {
    return cdr(assoc(stringify($aSym), $symMap));

  } else {
    return $aSym;

  };

}


# Function ansi3FuncMap from line 355

sub ansi3FuncMap {
  my ($aSym) = @_;
  my $symMap = undef;

  if ( equalString("symbol", boxType($aSym)) ) {
    $symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("sub_string"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), undef)))))));

    if ( truthy(assoc(stringify($aSym), $symMap)) ) {
      return cdr(assoc(stringify($aSym), $symMap));

    } else {
      return $aSym;

    };

  } else {
    return $aSym;

  };

}


# Function ansi3Type from line 385

sub ansi3Type {
  my ($node) = @_;
  
  if ( isList(second($node)) ) {
    return cons(boxString("\ntypedef struct "), cons(id(first($node)), cons(boxString(" {\n"), cons(id(ansi3Struct(second($node))), cons(boxString("\n} "), cons(id(first($node)), cons(boxString(";\n"), undef)))))));

  } else {
    return cons(boxString("typedef "), cons(id(ansi3TypeDecl($node)), undef));

  };

}


# Function ansi3Types from line 402

sub ansi3Types {
  my ($nodes) = @_;
  
  if ( isEmpty($nodes) ) {
    return emptyList();

  } else {
    return cons(id(ansi3Type(car($nodes))), cons(id(ansi3Types(cdr($nodes))), undef));

  };

}


# Function ansi3LoadProgram from line 411

sub ansi3LoadProgram {
  my ($filename) = @_;
  my $tree = undef;
my $replace = undef;

  $tree = loadQuon($filename);

  $tree = buildProg(cons(boxString("q/shims/ansi3.qon"), getIncludes($tree)), getTypes($tree), getFunctions($tree));

  $tree = loadIncludes($tree, undef);

  $tree = macrowalk($tree);

  $replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), undef));

  $tree = macrolist($tree, stringConcatenate("q", "log"), $replace);

  return $tree;

}


# Function ansi3ProgramTree from line 421

sub ansi3ProgramTree {
  my ($tree) = @_;
  
  return cons(id(ansi3Includes(cdr(first($tree)))), cons(id(ansi3Types(cdr(second($tree)))), cons(boxString("Box* globalStackTrace = NULL;\n"), cons(boxString("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n"), cons(id(ansi3ForwardDeclarations(cdr(third($tree)))), cons(boxString("\n\n//End forward declarations\n\n"), cons(id(ansi3Functions(cdr(third($tree)))), cons(boxString("\n"), undef))))))));

}


# Function ansi3Program from line 433

sub ansi3Program {
  my ($tree) = @_;
  
  return ListToString(flatten(ansi3ProgramTree($tree)), 0, $true, $false);

}


# Function ansi3CompileString from line 437

sub ansi3CompileString {
  my ($filename) = @_;
  
  return ansi3Program(ansi3LoadProgram($filename));

}


# Function ansi3Compile from line 441

sub ansi3Compile {
  my ($filename) = @_;
  
  printStringTree(ansi3ProgramTree(ansi3LoadProgram($filename)));

  fprintf($stderr, "//Done printing program\n");

}


# Function dollar from line 4

sub dollar {
  my () = @_;
  
  return character(36);

}


# Function atsymbol from line 8

sub atsymbol {
  my () = @_;
  
  return character(64);

}


# Function singleQuote from line 12

sub singleQuote {
  my () = @_;
  
  return "'";

}


# Function escapedSingleQuote from line 16

sub escapedSingleQuote {
  my () = @_;
  
  return "\\'";

}


# Function backslash from line 20

sub backslash {
  my () = @_;
  
  return character(92);

}


# Function escapedDollar from line 24

sub escapedDollar {
  my () = @_;
  
  return StringListJoin(cons(boxString(backslash()), cons(boxString(dollar()), undef)), "");

}


# Function escapedAtSign from line 28

sub escapedAtSign {
  my () = @_;
  
  return StringListJoin(cons(boxString(backslash()), cons(boxString(atsymbol()), undef)), "");

}


# Function escapeSingleQuotes from line 32

sub escapeSingleQuotes {
  my ($s) = @_;
  
  return stringReplace(singleQuote(), escapedSingleQuote(), $s);

}


# Function escapePerlString from line 36

sub escapePerlString {
  my ($s) = @_;
  
  return stringReplace(atsymbol(), escapedAtSign(), stringReplace(dollar(), escapedDollar(), $s));

}


# Function getGlobalVariables from line 41

sub getGlobalVariables {
  my () = @_;
  
  return cons(id(boxSymbol("stderr")), cons(id(boxSymbol("true")), cons(id(boxSymbol("false")), cons(id(boxSymbol("releaseMode")), cons(id(boxSymbol("caller")), cons(id(boxSymbol("globalTrace")), cons(id(boxSymbol("globalStepTrace")), cons(id(boxSymbol("globalStackTrace")), cons(id(boxSymbol("globalArgsCount")), cons(id(boxSymbol("globalArgs")), cons(id(boxSymbol("quonGlobalArgs")), undef)))))))))));

}


# Function collectVariables from line 45

sub collectVariables {
  my ($args, $decls) = @_;
  my $variables = undef;
my $decl = undef;

  $variables = collectVariablesFromArgs($args);

  $variables = appendVariables($variables, collectVariablesFromDecls($decls));

  $variables = appendVariables($variables, getGlobalVariables());

  return $variables;

}


# Function perlGlobalVariables from line 52

sub perlGlobalVariables {
  my () = @_;
  
  return cons(boxString("our "), cons(boxString(dollar()), cons(boxString("globalArgsCount;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("globalArgs;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("releaseMode;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("globalTrace;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("globalStepTrace;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("globalStackTrace;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("caller;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("false = 0;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("true = 1;\n"), cons(boxString("my "), cons(boxString(dollar()), cons(boxString("stderr = \\*STDERR;\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("quonGlobalArgs;\n"), undef)))))))))))))))))))))))))))))))));

}


# Function perlMainEntry from line 67

sub perlMainEntry {
  my () = @_;
  
  return cons(boxString("\n# Main entry point\n"), cons(boxString(dollar()), cons(boxString("globalArgsCount = scalar("), cons(boxString(atsymbol()), cons(boxString("ARGV) + 1;\n"), cons(boxString(dollar()), cons(boxString("globalArgs = \\"), cons(boxString(atsymbol()), cons(boxString("ARGV;\n"), cons(boxString("unshift "), cons(boxString(atsymbol()), cons(boxString(dollar()), cons(boxString("globalArgs, 'fixmeprogname' ;\n"), cons(boxString(dollar()), cons(boxString("quonGlobalArgs = [];\n"), cons(boxString("for my "), cons(boxString(dollar()), cons(boxString("arg ("), cons(boxString(atsymbol()), cons(boxString(dollar()), cons(boxString("globalArgs) {\n"), cons(boxString("    push "), cons(boxString(atsymbol()), cons(boxString(dollar()), cons(boxString("quonGlobalArgs, {car => "), cons(boxString(dollar()), cons(boxString("arg, cdr => undef};\n"), cons(boxString("}\n"), cons(boxString("for (my "), cons(boxString(dollar()), cons(boxString("i = scalar("), cons(boxString(atsymbol()), cons(boxString(dollar()), cons(boxString("quonGlobalArgs) - 1; "), cons(boxString(dollar()), cons(boxString("i >= 0; "), cons(boxString(dollar()), cons(boxString("i--) {\n"), cons(boxString("    "), cons(boxString(dollar()), cons(boxString("quonGlobalArgs->["), cons(boxString(dollar()), cons(boxString("i]->{cdr} = "), cons(boxString(dollar()), cons(boxString("quonGlobalArgs->["), cons(boxString(dollar()), cons(boxString("i + 1];\n"), cons(boxString("}\n"), cons(boxString("*stderr = *STDERR;\n"), cons(boxString("sub fprintf { my "), cons(boxString(dollar()), cons(boxString("f = shift; printf "), cons(boxString(dollar()), cons(boxString("f "), cons(boxString(atsymbol()), cons(boxString("_ }\n"), cons(boxString("start();\n"), undef)))))))))))))))))))))))))))))))))))))))))))))))))))))))));

}


# Function collectVariablesFromArgs from line 85

sub collectVariablesFromArgs {
  my ($args) = @_;
  my $variables = undef;

  if ( isNil($args) ) {
    return $variables;

  } else {
    if ( equalString(stringify(first($args)), "list") ) {
      $variables = cons(second($args), $variables);

      return appendVariables($variables, collectVariablesFromArgs(cddr($args)));

    } else {
      $variables = cons(second($args), $variables);

      return appendVariables($variables, collectVariablesFromArgs(cddr($args)));

    };

  };

}


# Function collectVariablesFromDecls from line 98

sub collectVariablesFromDecls {
  my ($decls) = @_;
  my $variables = undef;
my $decl = undef;

  if ( isNil($decls) ) {
    return $variables;

  } else {
    $decl = car($decls);

    $variables = cons(second($decl), $variables);

    return appendVariables($variables, collectVariablesFromDecls(cdr($decls)));

  };

}


# Function appendVariables from line 107

sub appendVariables {
  my ($vars1, $vars2) = @_;
  
  if ( isNil($vars2) ) {
    return $vars1;

  } else {
    $vars1 = cons(car($vars2), $vars1);

    return appendVariables($vars1, cdr($vars2));

  };

}


# Function perlFunctionArgs from line 116

sub perlFunctionArgs {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return emptyList();

  } else {
    if ( isNil(cddr($tree)) ) {
      return cons(id(boxString(dollar())), cons(id(second($tree)), undef));

    } else {
      return cons(id(boxString(dollar())), cons(id(second($tree)), cons(boxString(", "), cons(id(perlFunctionArgs(cddr($tree))), undef))));

    };

  };

}


# Function perlAtom from line 129

sub perlAtom {
  my ($tree, $variables) = @_;
  
  if ( equalString("string", boxType($tree)) ) {
    return cons(boxString("\""), cons(id(boxString(escapePerlString(stringify($tree)))), cons(boxString("\""), undef)));

  } else {
    return cons(id(perlFuncMap($tree, $variables)), undef);

  };

}


# Function perlExpression from line 135

sub perlExpression {
  my ($tree, $indent, $variables) = @_;
  my $thing = undef;

  if ( notBool(isList($tree)) ) {
    return perlAtom($tree, $variables);

  } else {
    if ( equal(1, listLength($tree)) ) {
      if ( equalBox(boxString("return"), car($tree)) ) {
        return cons(id(perlFuncMap(car($tree), $variables)), undef);

      } else {
        return cons(id(perlFuncMap(car($tree), $variables)), cons(boxString("()"), undef));

      };

    } else {
      $thing = first($tree);

      if ( equalBox(boxSymbol("get-struct"), $thing) ) {
        return cons(id(boxString(dollar())), cons(id(second($tree)), cons(boxString("->{"), cons(id(third($tree)), cons(boxString("}"), undef)))));

      } else {
        if ( equalBox(boxSymbol("new"), $thing) ) {
          return cons(boxString("{}"), undef);

        } else {
          if ( equalBox(boxSymbol("passthrough"), $thing) ) {
            return cons(id(second($tree)), undef);

          } else {
            if ( equalBox(boxSymbol("binop"), $thing) ) {
              return cons(boxString("("), cons(id(perlExpression(third($tree), $indent, $variables)), cons(boxString(" "), cons(id(second($tree)), cons(boxString(" "), cons(id(perlExpression(fourth($tree), $indent, $variables)), cons(boxString(")"), undef)))))));

            } else {
              return cons(id(perlFuncMap(car($tree), $variables)), cons(boxString("("), cons(id(perlRecurList(cdr($tree), $indent, $variables)), cons(boxString(")"), undef))));

            };

          };

        };

      };

    };

  };

}


# Function perlRecurList from line 179

sub perlRecurList {
  my ($expr, $indent, $variables) = @_;
  
  if ( isEmpty($expr) ) {
    return emptyList();

  } else {
    if ( isNil(cdr($expr)) ) {
      return perlExpression(car($expr), $indent, $variables);

    } else {
      return cons(id(perlExpression(car($expr), $indent, $variables)), cons(boxString(", "), cons(id(perlRecurList(cdr($expr), $indent, $variables)), undef)));

    };

  };

}


# Function perlSet from line 191

sub perlSet {
  my ($node, $indent, $variables) = @_;
  
  return cons(id(listNewLine($indent)), cons(id(perlFuncMap(second($node), $variables)), cons(boxString(" = "), cons(id(perlExpression(third($node), $indent, $variables)), undef))));

}


# Function perlSetStruct from line 199

sub perlSetStruct {
  my ($node, $indent, $variables) = @_;
  
  return cons(id(listNewLine($indent)), cons(id(perlFuncMap(second($node), $variables)), cons(boxString("->{"), cons(id(third($node)), cons(boxString("} = "), cons(id(perlExpression(fourth($node), $indent, $variables)), undef))))));

}


# Function perlReturn from line 209

sub perlReturn {
  my ($node, $indent, $variables) = @_;
  
  if ( greaterthan(listLength($node), 1) ) {
    return cons(id(listNewLine($indent)), cons(boxString("return "), cons(id(perlExpression(cadr($node), $indent, $variables)), undef)));

  } else {
    return cons(id(listNewLine($indent)), cons(boxString("return"), undef));

  };

}


# Function perlIf from line 218

sub perlIf {
  my ($node, $indent, $variables) = @_;
  
  return cons(id(listNewLine($indent)), cons(boxString("if ( "), cons(id(perlExpression(second($node), 0, $variables)), cons(boxString(" ) {"), cons(id(perlBody(cdr(third($node)), add1($indent), $variables)), cons(id(listNewLine($indent)), cons(boxString("} else {"), cons(id(perlBody(cdr(fourth($node)), add1($indent), $variables)), cons(id(listNewLine($indent)), cons(boxString("}"), undef))))))))));

}


# Function perlStatement from line 232

sub perlStatement {
  my ($node, $indent, $variables) = @_;
  
  if ( equalBox(boxString("set"), first($node)) ) {
    return cons(id(perlSet($node, $indent, $variables)), cons(boxString(";\n"), undef));

  } else {
    if ( equalBox(boxString("set-struct"), first($node)) ) {
      return cons(id(perlSetStruct($node, $indent, $variables)), cons(boxString(";\n"), undef));

    } else {
      if ( equalBox(boxString("if"), first($node)) ) {
        return cons(id(perlIf($node, $indent, $variables)), cons(boxString(";\n"), undef));

      } else {
        if ( equalBox(boxString("return"), first($node)) ) {
          return cons(id(perlReturn($node, $indent, $variables)), cons(boxString(";\n"), undef));

        } else {
          return cons(id(listNewLine($indent)), cons(id(perlExpression($node, $indent, $variables)), cons(boxString(";\n"), undef)));

        };

      };

    };

  };

}


# Function perlBody from line 251

sub perlBody {
  my ($tree, $indent, $variables) = @_;
  my $code = undef;

  if ( isEmpty($tree) ) {
    return emptyList();

  } else {
    $code = car($tree);

    return cons(id(perlStatement($code, $indent, $variables)), cons(id(perlBody(cdr($tree), $indent, $variables)), undef));

  };

}


# Function perlGetStruct from line 261

sub perlGetStruct {
  my ($node, $indent) = @_;
  
  return cons(id(listNewLine($indent)), cons(id(boxString(dollar())), cons(id(first($node)), cons(boxString("->{"), cons(id(second($node)), cons(boxString("}"), undef))))));

}


# Function perlDeclarations from line 271

sub perlDeclarations {
  my ($decls, $indent, $variables) = @_;
  my $decl = undef;

  if ( isEmpty($decls) ) {
    return emptyList();

  } else {
    $decl = car($decls);

    return cons(boxString("my "), cons(id(boxString(dollar())), cons(id(second($decl)), cons(boxString(" = "), cons(id(perlExpression(third($decl), $indent, $variables)), cons(boxString(";\n"), cons(id(perlDeclarations(cdr($decls), $indent, $variables)), undef)))))));

  };

}


# Function perlFunction from line 286

sub perlFunction {
  my ($node) = @_;
  my $name = undef;
my $variables = undef;
my $args = undef;
my $decls = undef;

  $name = second($node);

  if ( isNil($node) ) {
    return emptyList();

  } else {
    $args = third($node);

    $decls = cdr(fourth($node));

    $variables = collectVariables($args, $decls);

    return cons(boxString("\n\n# Function "), cons(id($name), cons(boxString(" from line "), cons(id(getTag($name, boxString("line"))), cons(id(listNewLine(0)), cons(id(listNewLine(0)), cons(boxString("sub "), cons(id(perlFuncMap(second($node), undef)), cons(boxString(" {"), cons(id(listNewLine(1)), cons(boxString("my ("), cons(id(perlFunctionArgs($args)), cons(boxString(") = "), cons(id(boxString(atsymbol())), cons(boxString("_;"), cons(id(listNewLine(1)), cons(id(perlDeclarations($decls, 1, $variables)), cons(id(perlBody(cdr(fifth($node)), 1, $variables)), cons(boxString("\n}\n"), undef)))))))))))))))))));

  };

}


# Function perlForwardDeclaration from line 316

sub perlForwardDeclaration {
  my ($node) = @_;
  
  if ( isNil($node) ) {
    return emptyList();

  } else {
    return cons(boxString("sub "), cons(id(perlFuncMap(second($node), undef)), cons(boxString(";\n"), undef)));

  };

}


# Function perlForwardDeclarations from line 323

sub perlForwardDeclarations {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return emptyList();

  } else {
    return cons(id(perlForwardDeclaration(car($tree))), cons(id(perlForwardDeclarations(cdr($tree))), undef));

  };

}


# Function perlFunctions from line 332

sub perlFunctions {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return emptyList();

  } else {
    return cons(id(perlFunction(car($tree))), cons(id(perlFunctions(cdr($tree))), undef));

  };

}


# Function perlIncludes from line 341

sub perlIncludes {
  my ($nodes) = @_;
  
  return cons(boxString("use strict;\n"), cons(boxString("use warnings;\n"), cons(boxString("use v5.10;\n\n"), cons(boxString("no warnings 'recursion';\n"), cons(boxString("our "), cons(boxString(dollar()), cons(boxString("^M = 10_000;\n"), undef)))))));

}


# Function perlTypes from line 350

sub perlTypes {
  my ($nodes) = @_;
  
  return emptyList();

}


# Function perlTypeMap from line 354

sub perlTypeMap {
  my ($aSym) = @_;
  my $symMap = undef;

  $symMap = alistCons(boxSymbol("stringArray"), boxSymbol("array"), alistCons(boxSymbol("string"), boxSymbol("string"), undef));

  if ( truthy(assoc(stringify($aSym), $symMap)) ) {
    return cdr(assoc(stringify($aSym), $symMap));

  } else {
    return $aSym;

  };

}


# Function perlFuncMap from line 363

sub perlFuncMap {
  my ($aSym, $variables) = @_;
  my $symMap = undef;

  if ( equalString("symbol", boxType($aSym)) ) {
    if ( inList($aSym, $variables) ) {
      return boxSymbol(stringConcatenate(dollar(), stringify($aSym)));

    } else {
      $symMap = alistCons(boxSymbol("sub"), boxSymbol("subtract"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("sub-string"), boxSymbol("substr"), alistCons(boxSymbol("read-file"), boxSymbol("read_file"), alistCons(boxSymbol("write-file"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string-length"), boxSymbol("length"), alistCons(boxSymbol("say"), boxSymbol("say_"), alistCons(boxSymbol("nil"), boxSymbol("undef"), undef)))))))));

      if ( truthy(assoc(stringify($aSym), $symMap)) ) {
        return cdr(assoc(stringify($aSym), $symMap));

      } else {
        return $aSym;

      };

    };

  } else {
    return $aSym;

  };

}


# Function perlLoadProgram from line 386

sub perlLoadProgram {
  my ($filename) = @_;
  my $tree = undef;
my $replace = undef;

  $tree = loadQuon($filename);

  $tree = insertInclude($tree, "q/shims/perl.qon");

  $tree = loadIncludes($tree, undef);

  $tree = macrowalk($tree);

  $replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), undef));

  $tree = macrolist($tree, stringConcatenate("q", "log"), $replace);

  return $tree;

}


# Function perlProgramTree from line 396

sub perlProgramTree {
  my ($tree) = @_;
  
  return cons(id(perlIncludes(cdr(first($tree)))), cons(id(perlTypes(cdr(second($tree)))), cons(id(perlGlobalVariables()), cons(boxString("\n# Forward declarations\n"), cons(id(perlForwardDeclarations(cdr(third($tree)))), cons(boxString("\n# End forward declarations\n"), cons(id(perlFunctions(cdr(third($tree)))), cons(id(perlMainEntry()), cons(boxString("\n"), undef)))))))));

}


# Function perlProgram from line 409

sub perlProgram {
  my ($tree) = @_;
  
  return ListToString(flatten(perlProgramTree($tree)), 0, $true, $false);

}


# Function perlCompileString from line 413

sub perlCompileString {
  my ($filename) = @_;
  
  return perlProgram(perlLoadProgram($filename));

}


# Function perlCompile from line 417

sub perlCompile {
  my ($filename) = @_;
  my $tree = undef;
my $replace = undef;

  fprintf($stderr, "Scanning file...%s\n", $filename);

  $tree = loadQuon($filename);

  fprintf($stderr, "Adding shim functions\n");

  $tree = insertInclude($tree, "q/shims/perl.qon");

  fprintf($stderr, "Loading includes\n");

  $tree = loadIncludes($tree, undef);

  fprintf($stderr, "Walking tree\n");

  $tree = macrowalk($tree);

  fprintf($stderr, "Replacing q log\n");

  $replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), undef));

  $tree = macrolist($tree, stringConcatenate("q", "log"), $replace);

  fprintf($stderr, "Printing program\n");

  printStringTree(perlProgramTree($tree));

}


# Function readSexpr from line 4

sub readSexpr {
  my ($aStr, $filename) = @_;
  my $tokens = undef;
my $as = undef;
my $tree = undef;

  $tokens = emptyList();

  $tokens = filterTokens(filterVoid(scan($aStr, 0, 1, 0, 0, $filename)));

  parserValidateParens($tokens, undef, $filename);

  $as = sexprTree($tokens);

  parserValidateRoot($as, $filename);

  $tree = car($as);

  parserValidateProgram($tree, $filename);

  return $tree;

}


# Function parserPanicAt from line 15

sub parserPanicAt {
  my ($filename, $token, $message) = @_;
  
  if ( isNil($token) ) {
    printf("Parse error in %s: %s\n", $filename, $message);

  } else {
    printf("Parse error in %s:%s:%s: %s\n", stringify(getTagFail($token, boxString("filename"), boxString($filename))), stringify(getTagFail($token, boxString("line"), boxString("?"))), stringify(getTagFail($token, boxString("column"), boxString("?"))), $message);

  };

  exit(1);

}


# Function parserPanicAtNode from line 29

sub parserPanicAtNode {
  my ($filename, $node, $message) = @_;
  
  if ( isNil($node) ) {
    parserPanicAt($filename, undef, $message);

  } else {
    if ( isList($node) ) {
      if ( isEmpty($node) ) {
        parserPanicAt($filename, undef, $message);

      } else {
        parserPanicAt($filename, car($node), $message);

      };

    } else {
      parserPanicAt($filename, $node, $message);

    };

  };

}


# Function parserSymbolIs from line 41

sub parserSymbolIs {
  my ($b, $name) = @_;
  
  if ( isNil($b) ) {
    return $false;

  } else {
  };

  if ( isList($b) ) {
    return $false;

  } else {
  };

  if ( equalString("symbol", boxType($b)) ) {
    return equalString($name, stringify($b));

  } else {
    return $false;

  };

}


# Function parserListStartsWith from line 49

sub parserListStartsWith {
  my ($node, $name) = @_;
  
  if ( isNil($node) ) {
    return $false;

  } else {
  };

  if ( isList($node) ) {
    if ( isEmpty($node) ) {
      return $false;

    } else {
      return parserSymbolIs(car($node), $name);

    };

  } else {
    return $false;

  };

}


# Function parserValidateParens from line 59

sub parserValidateParens {
  my ($tokens, $openStack, $filename) = @_;
  my $token = undef;

  if ( isEmpty($tokens) ) {
    if ( isEmpty($openStack) ) {
      return;

    } else {
      parserPanicAt($filename, car($openStack), "missing ')'");

    };

  } else {
    $token = car($tokens);

    if ( isOpenBrace($token) ) {
      parserValidateParens(cdr($tokens), cons($token, $openStack), $filename);

    } else {
      if ( isCloseBrace($token) ) {
        if ( isEmpty($openStack) ) {
          parserPanicAt($filename, $token, "unexpected ')'");

        } else {
          parserValidateParens(cdr($tokens), cdr($openStack), $filename);

        };

      } else {
        parserValidateParens(cdr($tokens), $openStack, $filename);

      };

    };

  };

}


# Function parserValidateRoot from line 78

sub parserValidateRoot {
  my ($roots, $filename) = @_;
  
  if ( equal(listLength($roots), 1) ) {
    return;

  } else {
    if ( isEmpty($roots) ) {
      parserPanicAt($filename, undef, "expected one top-level program form");

    } else {
      parserPanicAtNode($filename, second($roots), "extra top-level form after program");

    };

  };

}


# Function parserValidateSection from line 87

sub parserValidateSection {
  my ($section, $name, $filename) = @_;
  
  if ( isNil($section) ) {
    parserPanicAt($filename, undef, "missing program section");

  } else {
  };

  if ( isList($section) ) {
  } else {
    parserPanicAtNode($filename, $section, "program section must be a list");

  };

  if ( parserListStartsWith($section, $name) ) {
    return;

  } else {
    parserPanicAtNode($filename, $section, stringConcatenate("expected program section ", $name));

  };

}


# Function parserIsFunctionDefinition from line 99

sub parserIsFunctionDefinition {
  my ($node) = @_;
  
  if ( isNil($node) ) {
    return $false;

  } else {
  };

  if ( isList($node) ) {
  } else {
    return $false;

  };

  if ( equal(listLength($node), 5) ) {
  } else {
    return $false;

  };

  if ( isList(first($node)) ) {
    return $false;

  } else {
  };

  if ( isList(second($node)) ) {
    return $false;

  } else {
  };

  if ( isList(third($node)) ) {
  } else {
    return $false;

  };

  if ( parserListStartsWith(fourth($node), "declare") ) {
  } else {
    return $false;

  };

  if ( parserListStartsWith(fifth($node), "body") ) {
    return $true;

  } else {
    return $false;

  };

}


# Function parserRejectFunctionDefinitions from line 110

sub parserRejectFunctionDefinitions {
  my ($node, $filename) = @_;
  
  if ( isNil($node) ) {
    return;

  } else {
  };

  if ( parserIsFunctionDefinition($node) ) {
    parserPanicAtNode($filename, $node, "function definition is not allowed here");

  } else {
  };

  if ( isList($node) ) {
    parserRejectFunctionDefinitionsList($node, $filename);

  } else {
    return;

  };

}


# Function parserRejectFunctionDefinitionsList from line 122

sub parserRejectFunctionDefinitionsList {
  my ($nodes, $filename) = @_;
  
  if ( isEmpty($nodes) ) {
    return;

  } else {
    parserRejectFunctionDefinitions(car($nodes), $filename);

    parserRejectFunctionDefinitionsList(cdr($nodes), $filename);

  };

}


# Function parserValidateProgram from line 130

sub parserValidateProgram {
  my ($program, $filename) = @_;
  
  if ( isNil($program) ) {
    parserPanicAt($filename, undef, "empty program");

  } else {
  };

  if ( isList($program) ) {
  } else {
    parserPanicAtNode($filename, $program, "program must be a list");

  };

  if ( equal(listLength($program), 3) ) {
  } else {
    if ( equal(listLength($program), 4) ) {
    } else {
      parserPanicAtNode($filename, $program, "program must contain includes, types, and functions sections");

    };

  };

  parserValidateSection(first($program), "includes", $filename);

  parserValidateSection(second($program), "types", $filename);

  parserValidateSection(third($program), "functions", $filename);

  parserRejectFunctionDefinitions(cdr(first($program)), $filename);

  parserRejectFunctionDefinitions(cdr(second($program)), $filename);

  if ( equal(listLength($program), 4) ) {
    parserValidateSection(fourth($program), "globals", $filename);

    parserRejectFunctionDefinitions(cdr(fourth($program)), $filename);

  } else {
  };

  parserValidateFunctions(cdr(third($program)), $filename);

}


# Function parserValidateFunctions from line 156

sub parserValidateFunctions {
  my ($functions, $filename) = @_;
  my $fn = undef;

  if ( isEmpty($functions) ) {
    return;

  } else {
    $fn = car($functions);

    if ( parserIsFunctionDefinition($fn) ) {
      parserValidateFunction($fn, $filename);

    } else {
      parserPanicAtNode($filename, $fn, "invalid function definition");

    };

    parserValidateFunctions(cdr($functions), $filename);

  };

}


# Function parserValidateFunction from line 167

sub parserValidateFunction {
  my ($fn, $filename) = @_;
  
  parserRejectFunctionDefinitions(third($fn), $filename);

  parserRejectFunctionDefinitions(cdr(fourth($fn)), $filename);

  parserValidateBody(cdr(fifth($fn)), $filename);

}


# Function parserValidateBody from line 173

sub parserValidateBody {
  my ($forms, $filename) = @_;
  
  if ( isEmpty($forms) ) {
    return;

  } else {
    parserValidateStatement(car($forms), $filename);

    parserValidateBody(cdr($forms), $filename);

  };

}


# Function parserValidateStatement from line 181

sub parserValidateStatement {
  my ($stmt, $filename) = @_;
  
  if ( isNil($stmt) ) {
    return;

  } else {
  };

  if ( isList($stmt) ) {
  } else {
    parserPanicAtNode($filename, $stmt, "statement must be a list");

  };

  if ( isEmpty($stmt) ) {
    return;

  } else {
  };

  if ( parserIsFunctionDefinition($stmt) ) {
    parserPanicAtNode($filename, $stmt, "function definition nested inside body");

  } else {
  };

  if ( parserListStartsWith($stmt, "if") ) {
    parserValidateIf($stmt, $filename);

    return;

  } else {
  };

  if ( parserListStartsWith($stmt, "then") ) {
    parserPanicAtNode($filename, $stmt, "then branch outside if");

  } else {
  };

  if ( parserListStartsWith($stmt, "else") ) {
    parserPanicAtNode($filename, $stmt, "else branch outside if");

  } else {
  };

  if ( parserListStartsWith($stmt, "declare") ) {
    parserPanicAtNode($filename, $stmt, "declare block outside function header");

  } else {
  };

  if ( parserListStartsWith($stmt, "body") ) {
    parserPanicAtNode($filename, $stmt, "body block nested inside body");

  } else {
  };

  if ( parserListStartsWith($stmt, "functions") ) {
    parserPanicAtNode($filename, $stmt, "functions section nested inside body");

  } else {
  };

  if ( parserListStartsWith($stmt, "types") ) {
    parserPanicAtNode($filename, $stmt, "types section nested inside body");

  } else {
  };

  if ( parserListStartsWith($stmt, "includes") ) {
    parserPanicAtNode($filename, $stmt, "includes section nested inside body");

  } else {
  };

  if ( parserListStartsWith($stmt, "return") ) {
    parserValidateReturn($stmt, $filename);

    return;

  } else {
  };

  if ( parserListStartsWith($stmt, "set") ) {
    parserValidateSet($stmt, $filename);

    return;

  } else {
  };

  if ( parserListStartsWith($stmt, "set-struct") ) {
    parserValidateSetStruct($stmt, $filename);

    return;

  } else {
  };

  parserValidateExpression($stmt, $filename);

}


# Function parserValidateReturn from line 230

sub parserValidateReturn {
  my ($stmt, $filename) = @_;
  
  if ( greaterthan(listLength($stmt), 2) ) {
    parserPanicAtNode($filename, $stmt, "return takes zero or one value");

  } else {
  };

  if ( equal(listLength($stmt), 2) ) {
    parserValidateExpression(second($stmt), $filename);

  } else {
    return;

  };

}


# Function parserValidateSet from line 239

sub parserValidateSet {
  my ($stmt, $filename) = @_;
  
  if ( equal(listLength($stmt), 3) ) {
    parserValidateExpression(second($stmt), $filename);

    parserValidateExpression(third($stmt), $filename);

  } else {
    parserPanicAtNode($filename, $stmt, "set takes a target and value");

  };

}


# Function parserValidateSetStruct from line 247

sub parserValidateSetStruct {
  my ($stmt, $filename) = @_;
  
  if ( equal(listLength($stmt), 4) ) {
    parserValidateExpression(second($stmt), $filename);

    parserValidateExpression(third($stmt), $filename);

    parserValidateExpression(fourth($stmt), $filename);

  } else {
    parserPanicAtNode($filename, $stmt, "set-struct takes a target, field, and value");

  };

}


# Function parserValidateIf from line 256

sub parserValidateIf {
  my ($stmt, $filename) = @_;
  
  if ( equal(listLength($stmt), 4) ) {
  } else {
    parserPanicAtNode($filename, $stmt, "if must contain condition, then, and else");

  };

  parserValidateExpression(second($stmt), $filename);

  parserValidateBranch(third($stmt), "then", $filename);

  parserValidateBranch(fourth($stmt), "else", $filename);

}


# Function parserValidateBranch from line 265

sub parserValidateBranch {
  my ($branch, $name, $filename) = @_;
  
  if ( parserListStartsWith($branch, $name) ) {
    parserValidateBody(cdr($branch), $filename);

  } else {
    parserPanicAtNode($filename, $branch, stringConcatenate("expected ", $name));

  };

}


# Function parserValidateExpression from line 271

sub parserValidateExpression {
  my ($expr, $filename) = @_;
  
  if ( isNil($expr) ) {
    return;

  } else {
  };

  if ( isList($expr) ) {
  } else {
    return;

  };

  if ( isEmpty($expr) ) {
    return;

  } else {
  };

  if ( parserIsFunctionDefinition($expr) ) {
    parserPanicAtNode($filename, $expr, "function definition nested inside expression");

  } else {
  };

  if ( parserListStartsWith($expr, "if") ) {
    parserValidateIf($expr, $filename);

    return;

  } else {
  };

  if ( parserListStartsWith($expr, "then") ) {
    parserPanicAtNode($filename, $expr, "then branch outside if");

  } else {
  };

  if ( parserListStartsWith($expr, "else") ) {
    parserPanicAtNode($filename, $expr, "else branch outside if");

  } else {
  };

  if ( parserListStartsWith($expr, "declare") ) {
    parserPanicAtNode($filename, $expr, "declare block inside expression");

  } else {
  };

  if ( parserListStartsWith($expr, "body") ) {
    parserPanicAtNode($filename, $expr, "body block inside expression");

  } else {
  };

  if ( parserListStartsWith($expr, "functions") ) {
    parserPanicAtNode($filename, $expr, "functions section inside expression");

  } else {
  };

  if ( parserListStartsWith($expr, "types") ) {
    parserPanicAtNode($filename, $expr, "types section inside expression");

  } else {
  };

  if ( parserListStartsWith($expr, "includes") ) {
    parserPanicAtNode($filename, $expr, "includes section inside expression");

  } else {
  };

  parserValidateExpressionList($expr, $filename);

}


# Function parserValidateExpressionList from line 311

sub parserValidateExpressionList {
  my ($exprs, $filename) = @_;
  
  if ( isEmpty($exprs) ) {
    return;

  } else {
    parserValidateExpression(car($exprs), $filename);

    parserValidateExpressionList(cdr($exprs), $filename);

  };

}


# Function sexprTree from line 319

sub sexprTree {
  my ($l) = @_;
  my $b = undef;

  if ( isEmpty($l) ) {
    return emptyList();

  } else {
    $b = car($l);

    if ( isOpenBrace($b) ) {
      return cons(sexprTree(cdr($l)), sexprTree(skipList(cdr($l))));

    } else {
      if ( isCloseBrace($b) ) {
        return emptyList();

      } else {
        return setTag(boxString("line"), getTagFail($b, boxString("line"), boxInt(-1)), cons($b, sexprTree(cdr($l))));

      };

    };

  };

}


# Function loadQuon from line 337

sub loadQuon {
  my ($filename) = @_;
  my $programBox = undef;
my $programStr = "";
my $tree = undef;

  $programBox = read_file($filename);

  if ( isNil($programBox) ) {
    fprintf($stderr, "Could not read file: ");

    fprintf($stderr, $filename);

    fprintf($stderr, "\n");

    exit(1);

  } else {
  };

  $programStr = unBoxString($programBox);

  $tree = readSexpr($programStr, $filename);

  return $tree;

}


# Function getIncludes from line 354

sub getIncludes {
  my ($program) = @_;
  
  return cdr(first($program));

}


# Function getTypes from line 358

sub getTypes {
  my ($program) = @_;
  
  return cdr(second($program));

}


# Function getFunctions from line 362

sub getFunctions {
  my ($program) = @_;
  
  return cdr(third($program));

}


# Function insertInclude from line 366

sub insertInclude {
  my ($tree, $extra) = @_;
  my $newProg = undef;
my $includes = undef;
my $types = undef;
my $functions = undef;
my $boxedExtra = undef;
my $newIncludes = undef;

  if ( isNil($tree) ) {
    printf("insertInlcude: tree is nil");

    return undef;

  } else {
    $includes = getIncludes($tree);

    $types = getTypes($tree);

    $functions = getFunctions($tree);

    $boxedExtra = boxSymbol($extra);

    $newIncludes = cons($boxedExtra, $includes);

    $newProg = buildProg($newIncludes, $types, $functions);

    return $newProg;

  };

}


# Function stringInList from line 395

sub stringInList {
  my ($item, $l) = @_;
  
  if ( isNil($l) ) {
    return $false;

  } else {
    if ( equalString($item, stringify(car($l))) ) {
      return $true;

    } else {
      return stringInList($item, cdr($l));

    };

  };

}


# Function appendMissingIncludes from line 404

sub appendMissingIncludes {
  my ($candidates, $pending, $seen) = @_;
  my $candidate = undef;
my $candidateFile = "";

  if ( isNil($candidates) ) {
    return $pending;

  } else {
    $candidate = car($candidates);

    $candidateFile = stringify($candidate);

    if ( orBool(stringInList($candidateFile, $seen), stringInList($candidateFile, $pending)) ) {
      return appendMissingIncludes(cdr($candidates), $pending, $seen);

    } else {
      return cons($candidate, appendMissingIncludes(cdr($candidates), $pending, $seen));

    };

  };

}


# Function loadIncludes from line 415

sub loadIncludes {
  my ($tree, $seen) = @_;
  my $newProg = undef;
my $includeFile = "";
my $functionsCombined = undef;
my $typesCombined = undef;
my $includeTree = undef;
my $pendingIncludes = undef;
my $nextIncludes = undef;
my $nextSeen = undef;
my $contentsBox = undef;
my $contents = "";

  if ( greaterthan(listLength(getIncludes($tree)), 0) ) {
    $includeFile = stringify(first(getIncludes($tree)));

    if ( stringInList($includeFile, $seen) ) {
      $newProg = buildProg(cdr(getIncludes($tree)), getTypes($tree), getFunctions($tree));

      return loadIncludes($newProg, $seen);

    } else {
    };

    $nextSeen = cons(boxString($includeFile), $seen);

    $contentsBox = read_file($includeFile);

    if ( isNil($contentsBox) ) {
      fprintf($stderr, "Could not read include file: ");

      fprintf($stderr, $includeFile);

      fprintf($stderr, "\n");

      exit(1);

      return undef;

    } else {
    };

    $contents = unBoxString($contentsBox);

    $includeTree = readSexpr($contents, $includeFile);

    if ( isNil($includeTree) ) {
      fprintf($stderr, "Could not parse include file: ");

      fprintf($stderr, $includeFile);

      fprintf($stderr, "\n");

      exit(1);

      return undef;

    } else {
      $functionsCombined = concatLists(getFunctions($includeTree), getFunctions($tree));

      $typesCombined = concatLists(getTypes($includeTree), getTypes($tree));

      $pendingIncludes = cdr(getIncludes($tree));

      $nextIncludes = appendMissingIncludes(getIncludes($includeTree), $pendingIncludes, $nextSeen);

      $newProg = buildProg($nextIncludes, $typesCombined, $functionsCombined);

      return loadIncludes($newProg, $nextSeen);

    };

  } else {
    return $tree;

  };

}


# Function buildProg from line 464

sub buildProg {
  my ($includes, $types, $functions) = @_;
  my $program = undef;

  $includes = cons(boxSymbol("includes"), $includes);

  $types = cons(boxSymbol("types"), $types);

  $functions = cons(boxSymbol("functions"), $functions);

  $program = cons($includes, cons($types, cons($functions, undef)));

  return $program;

}


# Function car from line 9

sub car {
  my ($l) = @_;
  
  if ( isNil($l) ) {
    printf("Cannot call car on empty list!\n");

    panic("Cannot call car on empty list!\n");

    return undef;

  } else {
    assertType("list", $l, 18, "q/lists.qon");

    if ( isNil($l->{car}) ) {
      return undef;

    } else {
      return $l->{car};

    };

  };

}


# Function cdr from line 23

sub cdr {
  my ($l) = @_;
  
  if ( isEmpty($l) ) {
    printf("Attempt to cdr an empty list!!!!\n");

    panic("Attempt to cdr an empty list!!!!\n");

    return undef;

  } else {
    return $l->{cdr};

  };

}


# Function cons from line 33

sub cons {
  my ($data, $l) = @_;
  my $p = undef;

  $p = makePair();

  $p->{cdr} = $l;

  $p->{car} = $data;

  $p->{typ} = "list";

  return $p;

}


# Function caar from line 45

sub caar {
  my ($l) = @_;
  
  return car(car($l));

}


# Function cadr from line 46

sub cadr {
  my ($l) = @_;
  
  return car(cdr($l));

}


# Function caddr from line 47

sub caddr {
  my ($l) = @_;
  
  return car(cdr(cdr($l)));

}


# Function cadddr from line 48

sub cadddr {
  my ($l) = @_;
  
  return car(cdr(cdr(cdr($l))));

}


# Function caddddr from line 49

sub caddddr {
  my ($l) = @_;
  
  return car(cdr(cdr(cdr(cdr($l)))));

}


# Function cddr from line 50

sub cddr {
  my ($l) = @_;
  
  return cdr(cdr($l));

}


# Function first from line 51

sub first {
  my ($l) = @_;
  
  return car($l);

}


# Function second from line 52

sub second {
  my ($l) = @_;
  
  return cadr($l);

}


# Function third from line 53

sub third {
  my ($l) = @_;
  
  return caddr($l);

}


# Function fourth from line 54

sub fourth {
  my ($l) = @_;
  
  return cadddr($l);

}


# Function fifth from line 55

sub fifth {
  my ($l) = @_;
  
  return caddddr($l);

}


# Function sixth from line 56

sub sixth {
  my ($l) = @_;
  
  return car(cdr(cdr(cdr(cdr(cdr($l))))));

}


# Function seventh from line 57

sub seventh {
  my ($l) = @_;
  
  return car(cdr(cdr(cdr(cdr(cdr(cdr($l)))))));

}


# Function eighth from line 58

sub eighth {
  my ($l) = @_;
  
  return car(cdr(cdr(cdr(cdr(cdr(cdr(cdr($l))))))));

}


# Function ninth from line 59

sub ninth {
  my ($l) = @_;
  
  return car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr($l)))))))));

}


# Function tenth from line 60

sub tenth {
  my ($l) = @_;
  
  return car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr($l))))))))));

}


# Function eleventh from line 61

sub eleventh {
  my ($l) = @_;
  
  return car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr($l)))))))))));

}


# Function twelfth from line 62

sub twelfth {
  my ($l) = @_;
  
  return car(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr(cdr($l))))))))))));

}


# Function rest from line 63

sub rest {
  my ($l) = @_;
  
  return cdr($l);

}


# Function isList from line 66

sub isList {
  my ($b) = @_;
  
  if ( isNil($b) ) {
    return $true;

  } else {
    return equalString("list", $b->{typ});

  };

}


# Function emptyList from line 73

sub emptyList {
  my () = @_;
  
  return undef;

}


# Function isEmpty from line 75

sub isEmpty {
  my ($b) = @_;
  
  if ( isNil($b) ) {
    return $true;

  } else {
    return $false;

  };

}


# Function listLength from line 82

sub listLength {
  my ($l) = @_;
  
  if ( isEmpty($l) ) {
    return 0;

  } else {
    return add1(listLength(cdr($l)));

  };

}


# Function alistCons from line 91

sub alistCons {
  my ($key, $value, $alist) = @_;
  
  return cons(cons($key, $value), $alist);

}


# Function assoc from line 94

sub assoc {
  my ($searchTerm, $l) = @_;
  my $elem = undef;

  assertType("list", $l, 96, "q/lists.qon");

  if ( isEmpty($l) ) {
    return boxBool($false);

  } else {
    $elem = car($l);

    assertType("list", $elem, 102, "q/lists.qon");

    if ( isEmpty($elem) ) {
      return assoc($searchTerm, cdr($l));

    } else {
      if ( $false ) {
        printf("Comparing %s and %s\n", $searchTerm, stringify(car($elem)));

      } else {
        printf("");

      };

      if ( equalString($searchTerm, stringify(car($elem))) ) {
        return $elem;

      } else {
        return assoc($searchTerm, cdr($l));

      };

    };

  };

}


# Function chooseBox from line 114

sub chooseBox {
  my ($aType) = @_;
  
  if ( equalString("string", $aType) ) {
    return "boxString";

  } else {
    if ( equalString("symbol", $aType) ) {
      return "boxSymbol";

    } else {
      if ( equalString("bool", $aType) ) {
        return "boxBool";

      } else {
        if ( equalString("int", $aType) ) {
          return "boxInt";

        } else {
          if ( equalString("float", $aType) ) {
            return "boxFloat";

          } else {
            panic("Invalid type");

          };

        };

      };

    };

  };

  return "";

}


# Function mlistLiteral from line 130

sub mlistLiteral {
  my ($b) = @_;
  
  if ( isNil($b) ) {
    return undef;

  } else {
    if ( equalString("string", boxType($b)) ) {
      return $b;

    } else {
      if ( equalString("bool", boxType($b)) ) {
        return $b;

      } else {
        if ( equalString("int", boxType($b)) ) {
          return $b;

        } else {
          if ( equalString("symbol", boxType($b)) ) {
            return boxString(unBoxSymbol($b));

          } else {
            return boxString(stringConcatenate("Unsupported type in mlistLiteral: ", boxType($b)));

          };

        };

      };

    };

  };

}


# Function doMultiList from line 154

sub doMultiList {
  my ($l) = @_;
  my $newlist = undef;
my $ret = undef;
my $elem = undef;

  if ( isNil($l) ) {
    return cons(boxSymbol("nil"), undef);

  } else {
    if ( isEmpty($l) ) {
      return undef;

    } else {
      $elem = first($l);

      $newlist = cons(boxString(chooseBox($elem->{typ})), cons(mlistLiteral(first($l)), $newlist));

      $ret = cons(cons(boxSymbol("cons"), cons($newlist, doMultiList(cdr($l)))), undef);

      return $ret;

    };

  };

}


# Function isDigit from line 176

sub isDigit {
  my ($val) = @_;
  
  if ( equal(length($val), 1) ) {
    return stringContains("0123456789", $val);

  } else {
    return $false;

  };

}


# Function isUnsignedIntFrom from line 182

sub isUnsignedIntFrom {
  my ($val, $pos) = @_;
  my $len = 0;

  $len = length($val);

  if ( greaterthan(add1($pos), $len) ) {
    return $true;

  } else {
    if ( isDigit(substr($val, $pos, 1)) ) {
      return isUnsignedIntFrom($val, add1($pos));

    } else {
      return $false;

    };

  };

}


# Function isInt from line 192

sub isInt {
  my ($val) = @_;
  my $len = 0;
my $firstLetter = "";

  $len = length($val);

  if ( equal($len, 0) ) {
    return $false;

  } else {
  };

  $firstLetter = substr($val, 0, 1);

  if ( equalString("-", $firstLetter) ) {
    if ( equal($len, 1) ) {
      return $false;

    } else {
      return isUnsignedIntFrom($val, 1);

    };

  } else {
    return isUnsignedIntFrom($val, 0);

  };

}


# Function isFloatFrom from line 206

sub isFloatFrom {
  my ($val, $pos, $seenDot, $seenDigit, $digitAfterDot) = @_;
  my $len = 0;
my $ch = "";

  $len = length($val);

  if ( greaterthan(add1($pos), $len) ) {
    return andBool($seenDot, andBool($seenDigit, $digitAfterDot));

  } else {
  };

  $ch = substr($val, $pos, 1);

  if ( isDigit($ch) ) {
    return isFloatFrom($val, add1($pos), $seenDot, $true, orBool($digitAfterDot, $seenDot));

  } else {
    if ( equalString(".", $ch) ) {
      if ( $seenDot ) {
        return $false;

      } else {
        return isFloatFrom($val, add1($pos), $true, $seenDigit, $false);

      };

    } else {
      return $false;

    };

  };

}


# Function isFloat from line 223

sub isFloat {
  my ($val) = @_;
  my $len = 0;
my $firstLetter = "";

  $len = length($val);

  if ( equal($len, 0) ) {
    return $false;

  } else {
  };

  $firstLetter = substr($val, 0, 1);

  if ( equalString("-", $firstLetter) ) {
    if ( equal($len, 1) ) {
      return $false;

    } else {
      return isFloatFrom($val, 1, $false, $false, $false);

    };

  } else {
    return isFloatFrom($val, 0, $false, $false, $false);

  };

}


# Function id from line 237

sub id {
  my ($b) = @_;
  
  return $b;

}


# Function chooseBoxInterp from line 240

sub chooseBoxInterp {
  my ($b) = @_;
  my $val = stringify($b);
my $firstLetter = substr($val, 0, 1);

  if ( equalString("string", boxType($b)) ) {
    return "boxString";

  } else {
    if ( equalString("\"", $firstLetter) ) {
      return "boxString";

    } else {
      if ( equalString("true", $val) ) {
        return "boxBool";

      } else {
        if ( equalString("false", $val) ) {
          return "boxBool";

        } else {
          if ( isFloat($val) ) {
            return "boxFloat";

          } else {
            if ( isInt($val) ) {
              return "boxInt";

            } else {
              return "id";

            };

          };

        };

      };

    };

  };

}


# Function doInterpolatedList from line 265

sub doInterpolatedList {
  my ($l) = @_;
  my $newlist = undef;
my $ret = undef;
my $elem = undef;

  if ( isNil($l) ) {
    return cons(boxSymbol("nil"), undef);

  } else {
    if ( isEmpty($l) ) {
      return undef;

    } else {
      $elem = first($l);

      $newlist = cons(boxString(chooseBoxInterp($elem)), cons(first($l), $newlist));

      $ret = cons(cons(boxSymbol("cons"), cons($newlist, doInterpolatedList(cdr($l)))), undef);

      return $ret;

    };

  };

}


# Function doStringList from line 289

sub doStringList {
  my ($l) = @_;
  my $newlist = undef;
my $ret = undef;

  if ( isNil($l) ) {
    return cons(boxSymbol("nil"), undef);

  } else {
    $newlist = cons(boxSymbol("boxString"), cons(first($l), $newlist));

    $ret = cons(cons(boxSymbol("cons"), cons($newlist, doStringList(cdr($l)))), undef);

    return $ret;

  };

}


# Function doSymbolList from line 306

sub doSymbolList {
  my ($l) = @_;
  my $newlist = undef;
my $ret = undef;

  if ( isNil($l) ) {
    return cons(boxSymbol("nil"), undef);

  } else {
    $newlist = cons(boxSymbol("boxSymbol"), cons(first($l), $newlist));

    $ret = cons(cons(boxSymbol("cons"), cons($newlist, doSymbolList(cdr($l)))), undef);

    return $ret;

  };

}


# Function doBoxList from line 324

sub doBoxList {
  my ($l) = @_;
  
  if ( isNil($l) ) {
    return cons(boxSymbol("nil"), undef);

  } else {
    return cons(cons(boxSymbol("cons"), cons(first($l), doBoxList(cdr($l)))), undef);

  };

}


# Function concatLists from line 343

sub concatLists {
  my ($seq1, $seq2) = @_;
  
  if ( isNil($seq1) ) {
    return $seq2;

  } else {
    return cons(car($seq1), concatLists(cdr($seq1), $seq2));

  };

}


# Function alistKeys from line 349

sub alistKeys {
  my ($alist) = @_;
  
  if ( isNil($alist) ) {
    return undef;

  } else {
    return cons(car(car($alist)), alistKeys(cdr($alist)));

  };

}


# Function display from line 355

sub display {
  my ($l) = @_;
  
  if ( isEmpty($l) ) {
    printf("nil ");

    return;

  } else {
    if ( isList($l) ) {
      printf("[");

      displayList($l, 0, $true);

      printf("]");

    } else {
      displayList($l, 0, $true);

    };

  };

}


# Function displayList from line 364

sub displayList {
  my ($l, $indent, $first) = @_;
  my $val = undef;

  if ( isEmpty($l) ) {
    return;

  } else {
    if ( isList($l) ) {
      if ( isEmpty($l) ) {
        return;

      } else {
        if ( $first ) {
        } else {
          printf(" ");

        };

        $val = car($l);

        if ( isList($val) ) {
          newLine($indent);

          printf("%s", openBrace());

          displayList(car($l), add1($indent), $true);

          printf("%s", closeBrace());

          displayList(cdr($l), $indent, $false);

        } else {
          if ( equalString("string", $val->{typ}) ) {
            printf("\"%s\"", unBoxString($val));

          } else {
            printf("%s", stringify($val));

          };

          displayList(cdr($l), $indent, $false);

        };

      };

    } else {
      if ( equalString("string", $l->{typ}) ) {
        printf("\"%s\"", unBoxString($l));

      } else {
        printf("%s", stringify($l));

      };

    };

  };

}


# Function StringListJoinRec from line 395

sub StringListJoinRec {
  my ($l, $sep) = @_;
  my $val = undef;

  if ( isEmpty($l) ) {
    return "";

  } else {
    if ( isList($l) ) {
      if ( isEmpty($l) ) {
        return "";

      } else {
        if ( equal(listLength($l), 1) ) {
          return stringify(car($l));

        } else {
          return stringConcatenate(stringify(car($l)), stringConcatenate($sep, StringListJoinRec(cdr($l), $sep)));

        };

      };

    } else {
      return "";

    };

  };

}


# Function StringListJoin from line 418

sub StringListJoin {
  my ($l, $sep) = @_;
  my $val = undef;

  if ( greaterthan(listLength($l), 1) ) {
    return stringConcatenate(stringify(car($l)), stringConcatenate($sep, StringListJoinRec(cdr($l), $sep)));

  } else {
    return stringify(car($l));

  };

}


# Function ListToBoxString from line 428

sub ListToBoxString {
  my ($l, $indent) = @_;
  
  return boxString(ListToString($l, $indent, $true, $false));

}


# Function ListToString from line 433

sub ListToString {
  my ($l, $indent, $first, $withNewLines) = @_;
  my $val = undef;

  if ( isEmpty($l) ) {
    return "";

  } else {
    if ( isList($l) ) {
      if ( isEmpty($l) ) {
        return "";

      } else {
        $val = car($l);

        if ( isList($val) ) {
          return StringListJoin(cons(boxString(stringify(tern($withNewLines, boxString("\n"), boxString(stringIndent($indent))))), cons(boxString(openBrace()), cons(boxString(" "), cons(boxString(ListToString(car($l), add1($indent), $true, $withNewLines)), cons(boxString(closeBrace()), cons(boxString(" "), cons(boxString(ListToString(cdr($l), $indent, $false, $withNewLines)), undef))))))), "");

        } else {
          return stringConcatenate(stringify($val), ListToString(cdr($l), $indent, $false, $withNewLines));

        };

      };

    } else {
      return stringify($l);

    };

  };

}


# Function listReverse from line 473

sub listReverse {
  my ($l) = @_;
  
  if ( isNil($l) ) {
    return undef;

  } else {
    return cons(car($l), listReverse(cdr($l)));

  };

}


# Function inList from line 479

sub inList {
  my ($item, $l) = @_;
  
  if ( isNil($l) ) {
    return $false;

  } else {
    if ( equalBox(car($l), $item) ) {
      return $true;

    } else {
      return inList($item, cdr($l));

    };

  };

}


# Function equalList from line 489

sub equalList {
  my ($a, $b) = @_;
  
  if ( isNil($a) ) {
    if ( isNil($b) ) {
      return $true;

    } else {
      return $false;

    };

  } else {
  };

  if ( isNil($b) ) {
    if ( isNil($a) ) {
      return $true;

    } else {
      return $false;

    };

  } else {
  };

  if ( equalBox(car($a), car($b)) ) {
    return equalList(cdr($a), cdr($b));

  } else {
    return $false;

  };

}


# Function reverseRec from line 512

sub reverseRec {
  my ($oldL, $newL) = @_;
  
  if ( isEmpty($oldL) ) {
    return $newL;

  } else {
    return reverseRec(cdr($oldL), cons(first($oldL), $newL));

  };

}


# Function reverseList from line 519

sub reverseList {
  my ($l) = @_;
  
  return reverseRec($l, undef);

}


# Function flatten from line 524

sub flatten {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return emptyList();

  } else {
    if ( isList(car($tree)) ) {
      return concatLists(flatten(car($tree)), flatten(cdr($tree)));

    } else {
      return cons(car($tree), flatten(cdr($tree)));

    };

  };

}


# Function printStringTree from line 535

sub printStringTree {
  my ($tree) = @_;
  my $val = undef;

  if ( isEmpty($tree) ) {
    return;

  } else {
  };

  $val = car($tree);

  if ( isList($val) ) {
    printStringTree(car($tree));

  } else {
    printf("%s", stringify($val));

  };

  printStringTree(cdr($tree));

}


# Function macrowalk from line 5

sub macrowalk {
  my ($l) = @_;
  
  if ( isEmpty($l) ) {
    return undef;

  } else {
    if ( isList($l) ) {
      if ( equalString(stringConcatenate("box", "List"), stringify(car($l))) ) {
        return car(doBoxList(cdr($l)));

      } else {
      };

      if ( equalString(stringConcatenate("string", "List"), stringify(car($l))) ) {
        return car(doStringList(cdr($l)));

      } else {
      };

      if ( equalString(stringConcatenate("symbol", "List"), stringify(car($l))) ) {
        return car(doSymbolList(cdr($l)));

      } else {
      };

      if ( equalString(stringConcatenate("multi", "List"), stringify(car($l))) ) {
        return car(doMultiList(cdr($l)));

      } else {
      };

      if ( equalString(stringConcatenate("makeL", "ist"), stringify(car($l))) ) {
        return car(doInterpolatedList(cdr($l)));

      } else {
      };

      return cons(macrowalk(car($l)), macrowalk(cdr($l)));

    } else {
      return $l;

    };

  };

}


# Function macrosingle from line 55

sub macrosingle {
  my ($tree, $search, $replace) = @_;
  my $val = undef;

  if ( isEmpty($tree) ) {
    return undef;

  } else {
    if ( isList($tree) ) {
      return cons(macrosingle(car($tree), $search, $replace), macrosingle(cdr($tree), $search, $replace));

    } else {
      if ( equalString($search, stringify($tree)) ) {
        $val = clone($tree);

        $val->{str} = $replace;

        return $val;

      } else {
      };

      return $tree;

    };

  };

}


# Function macroSymbolSingle from line 81

sub macroSymbolSingle {
  my ($tree, $search, $replace) = @_;
  my $val = undef;

  if ( isEmpty($tree) ) {
    return undef;

  } else {
    if ( isList($tree) ) {
      return cons(macroSymbolSingle(car($tree), $search, $replace), macroSymbolSingle(cdr($tree), $search, $replace));

    } else {
      if ( equalString("symbol", boxType($tree)) ) {
        if ( equalString($search, stringify($tree)) ) {
          $val = clone($tree);

          $val->{str} = $replace;

          return $val;

        } else {
        };

      } else {
      };

      return $tree;

    };

  };

}


# Function macrolist from line 101

sub macrolist {
  my ($l, $search, $replace) = @_;
  my $val = undef;

  if ( isEmpty($l) ) {
    return undef;

  } else {
    if ( isList($l) ) {
      if ( equalString($search, stringify(car($l))) ) {
        return concatLists($replace, macrolist(cdr($l), $search, $replace));

      } else {
        return cons(macrolist(car($l), $search, $replace), macrolist(cdr($l), $search, $replace));

      };

    } else {
      return $l;

    };

  };

}


# Function filterVoid from line 8

sub filterVoid {
  my ($l) = @_;
  my $token = undef;

  if ( isEmpty($l) ) {
    return emptyList();

  } else {
    $token = car($l);

    if ( equalString("void", $token->{typ}) ) {
      return filterVoid(cdr($l));

    } else {
      return cons($token, filterVoid(cdr($l)));

    };

  };

}


# Function filterTokens from line 20

sub filterTokens {
  my ($l) = @_;
  my $token = undef;

  if ( isEmpty($l) ) {
    return emptyList();

  } else {
    $token = car($l);

    if ( equalString(boxType($token), "symbol") ) {
      if ( equalString("__LINE__", stringify($token)) ) {
        return cons(getTagFail($token, boxString("line"), boxInt(-1)), filterTokens(cdr($l)));

      } else {
        if ( equalString("__COLUMN__", stringify($token)) ) {
          return cons(getTagFail($token, boxString("column"), boxInt(-1)), filterTokens(cdr($l)));

        } else {
          if ( equalString("__FILE__", stringify($token)) ) {
            return cons(getTagFail($token, boxString("filename"), boxString("Unknown file")), filterTokens(cdr($l)));

          } else {
            return cons($token, filterTokens(cdr($l)));

          };

        };

      };

    } else {
      return cons($token, filterTokens(cdr($l)));

    };

  };

}


# Function finish_token from line 54

sub finish_token {
  my ($prog, $start, $len, $line, $column, $filename) = @_;
  my $token = undef;

  if ( greaterthan($len, 0) ) {
    $token = boxSymbol(substr($prog, $start, $len));

    $token->{tag} = alistCons(boxString("filename"), boxString($filename), alistCons(boxString("column"), boxInt($column), alistCons(boxString("line"), boxInt($line), alistCons(boxString("totalCharPos"), boxInt($start), undef))));

    return $token;

  } else {
    return newVoid();

  };

}


# Function readString from line 69

sub readString {
  my ($prog, $start, $len) = @_;
  my $token = "";

  $token = substr($prog, sub1(add($start, $len)), 1);

  if ( equalString("\"", $token) ) {
    return substr($prog, $start, sub1($len));

  } else {
    if ( equalString("\\", $token) ) {
      return readString($prog, $start, add(2, $len));

    } else {
      return readString($prog, $start, add1($len));

    };

  };

}


# Function readComment from line 80

sub readComment {
  my ($prog, $start, $len) = @_;
  my $token = "";

  if ( greaterthan(add($start, $len), length($prog)) ) {
    return "";

  } else {
    $token = substr($prog, sub1(add($start, $len)), 1);

    if ( isLineBreak($token) ) {
      return substr($prog, $start, sub1($len));

    } else {
      return readComment($prog, $start, add1($len));

    };

  };

}


# Function isLineBreak from line 90

sub isLineBreak {
  my ($s) = @_;
  
  if ( equalString("\n", $s) ) {
    return $true;

  } else {
    if ( equalString("\r", $s) ) {
      return $true;

    } else {
      return $false;

    };

  };

}


# Function incForNewLine from line 97

sub incForNewLine {
  my ($token, $val) = @_;
  
  if ( equalString("\n", stringify($token)) ) {
    return add1($val);

  } else {
    return $val;

  };

}


# Function annotateReadPosition from line 105

sub annotateReadPosition {
  my ($filename, $linecount, $column, $start, $newBox) = @_;
  
  return setTag(boxString("filename"), boxString($filename), setTag(boxString("column"), boxInt($column), setTag(boxString("line"), boxInt($linecount), setTag(boxString("totalCharPos"), boxInt($start), $newBox))));

}


# Function scan from line 117

sub scan {
  my ($prog, $start, $len, $linecount, $column, $filename) = @_;
  my $token = undef;
my $newString = "";
my $newBox = undef;

  if ( greaterthan(length($prog), sub1(add($start, $len))) ) {
    $token = boxSymbol(substr($prog, sub1(add($start, $len)), 1));

    $token->{tag} = alistCons(boxString("totalCharPos"), boxInt($start), undef);

    if ( isOpenBrace($token) ) {
      return cons(finish_token($prog, $start, sub1($len), $linecount, $column, $filename), cons(annotateReadPosition($filename, $linecount, $column, $start, boxSymbol(openBrace())), scan($prog, add1($start), 1, $linecount, add1($column), $filename)));

    } else {
      if ( isCloseBrace($token) ) {
        return cons(finish_token($prog, $start, sub1($len), $linecount, $column, $filename), cons(annotateReadPosition($filename, $linecount, $column, $start, boxSymbol(closeBrace())), scan($prog, add($start, $len), 1, $linecount, add1($column), $filename)));

      } else {
        if ( isWhiteSpace(stringify($token)) ) {
          return cons(finish_token($prog, $start, sub1($len), $linecount, $column, $filename), scan($prog, add($start, $len), 1, incForNewLine($token, $linecount), 0, $filename));

        } else {
          if ( equalBox(boxSymbol(";"), $token) ) {
            return scan($prog, add($start, add1(add1(length(readComment($prog, add1($start), $len))))), 1, add1($linecount), 0, $filename);

          } else {
            if ( equalBox(boxSymbol("\""), $token) ) {
              $newString = readString($prog, add1($start), $len);

              $newBox = annotateReadPosition($filename, $linecount, $column, $start, boxString($newString));

              return cons($newBox, scan($prog, add($start, add1(add1(length($newString)))), 1, $linecount, add1($column), $filename));

            } else {
              return scan($prog, $start, subtract($len, -1), $linecount, add1($column), $filename);

            };

          };

        };

      };

    };

  } else {
    return emptyList();

  };

}


# Function isOpenBrace from line 157

sub isOpenBrace {
  my ($b) = @_;
  
  if ( equalBox(boxSymbol(openBrace()), $b) ) {
    return $true;

  } else {
    return $false;

  };

}


# Function isCloseBrace from line 164

sub isCloseBrace {
  my ($b) = @_;
  
  if ( equalBox(boxSymbol(closeBrace()), $b) ) {
    return $true;

  } else {
    return $false;

  };

}


# Function skipList from line 174

sub skipList {
  my ($l) = @_;
  my $b = undef;

  if ( isEmpty($l) ) {
    return emptyList();

  } else {
    $b = car($l);

    if ( isOpenBrace($b) ) {
      return skipList(skipList(cdr($l)));

    } else {
      if ( isCloseBrace($b) ) {
        return cdr($l);

      } else {
        return skipList(cdr($l));

      };

    };

  };

}


# Function add from line 20

sub add {
  my ($a, $b) = @_;
  
  return subtract($a, subtract(0, $b));

}


# Function addf from line 21

sub addf {
  my ($a, $b) = @_;
  
  return subf($a, subf(0, $b));

}


# Function sub1 from line 22

sub sub1 {
  my ($a) = @_;
  
  return subtract($a, 1);

}


# Function add1 from line 23

sub add1 {
  my ($a) = @_;
  
  return add($a, 1);

}


# Function clone from line 25

sub clone {
  my ($b) = @_;
  my $newb = undef;

  $newb = makeBox();

  if ( isNil($newb) ) {
    printf("clone: newb is nil\n");

    panic("clone: newb is nil");

    return $newb;

  } else {
    $newb->{typ} = $b->{typ};

    $newb->{voi} = $b->{voi};

    $newb->{boo} = $b->{boo};

    $newb->{tag} = $b->{tag};

    $newb->{lis} = $b->{lis};

    $newb->{str} = $b->{str};

    $newb->{i} = $b->{i};

    $newb->{f} = $b->{f};

    $newb->{lengt} = $b->{lengt};

    $newb->{car} = $b->{car};

    $newb->{cdr} = $b->{cdr};

    return $newb;

  };

}


# Function tern from line 48

sub tern {
  my ($cond, $tr, $fal) = @_;
  
  if ( $cond ) {
    return $tr;

  } else {
    return $fal;

  };

}


# Function ternString from line 52

sub ternString {
  my ($cond, $tr, $fal) = @_;
  
  if ( $cond ) {
    return $tr;

  } else {
    return $fal;

  };

}


# Function ternList from line 56

sub ternList {
  my ($cond, $tr, $fal) = @_;
  
  if ( $cond ) {
    return $tr;

  } else {
    return $fal;

  };

}


# Function newVoid from line 61

sub newVoid {
  my () = @_;
  my $newb = undef;

  $newb = makeBox();

  $newb->{voi} = $true;

  $newb->{typ} = "void";

  return $newb;

}


# Function stackDump from line 70

sub stackDump {
  my () = @_;
  
  printf("");

}


# Function nop from line 75

sub nop {
  my () = @_;
  
  printf("");

}


# Function equalBox from line 78

sub equalBox {
  my ($a, $b) = @_;
  
  if ( isList($b) ) {
    return $false;

  } else {
    if ( equalString("string", boxType($a)) ) {
      return equalString(unBoxString($a), stringify($b));

    } else {
      if ( equalString("bool", boxType($a)) ) {
        return andBool(unBoxBool($a), unBoxBool($b));

      } else {
        if ( equalString("symbol", boxType($a)) ) {
          if ( equalString("symbol", boxType($b)) ) {
            return equalString(unBoxSymbol($a), unBoxSymbol($b));

          } else {
            return $false;

          };

        } else {
          if ( equalString("int", boxType($a)) ) {
            return equal(unBoxInt($a), unBoxInt($b));

          } else {
            if ( equalString("float", boxType($a)) ) {
              if ( equalString("float", boxType($b)) ) {
                return equalf(unBoxFloat($a), unBoxFloat($b));

              } else {
                return $false;

              };

            } else {
              return $false;

            };

          };

        };

      };

    };

  };

}


# Function openBrace from line 105

sub openBrace {
  my () = @_;
  
  return "(";

}


# Function closeBrace from line 106

sub closeBrace {
  my () = @_;
  
  return ")";

}


# Function boxType from line 111

sub boxType {
  my ($b) = @_;
  
  return $b->{typ};

}


# Function makeBox from line 115

sub makeBox {
  my () = @_;
  my $b = undef;

  $b = {};

  if ( isNil($b) ) {
    panic("failed to create box!");

  } else {
  };

  $b->{tag} = undef;

  $b->{car} = undef;

  $b->{cdr} = undef;

  $b->{lis} = undef;

  $b->{typ} = "None - error!";

  return $b;

}


# Function makePair from line 129

sub makePair {
  my () = @_;
  
  return makeBox();

}


# Function boxString from line 134

sub boxString {
  my ($s) = @_;
  my $b = undef;

  $b = makeBox();

  $b->{str} = $s;

  $b->{lengt} = length($s);

  $b->{typ} = "string";

  return $b;

}


# Function boxSymbol from line 144

sub boxSymbol {
  my ($s) = @_;
  my $b = undef;

  $b = boxString($s);

  $b->{typ} = "symbol";

  return $b;

}


# Function boxBool from line 153

sub boxBool {
  my ($boo) = @_;
  my $b = undef;

  $b = makeBox();

  $b->{boo} = $boo;

  $b->{typ} = "bool";

  return $b;

}


# Function boxInt from line 162

sub boxInt {
  my ($val) = @_;
  my $b = undef;

  $b = makeBox();

  $b->{i} = $val;

  $b->{typ} = "int";

  return $b;

}


# Function boxFloat from line 172

sub boxFloat {
  my ($val) = @_;
  my $b = undef;

  $b = makeBox();

  $b->{f} = $val;

  $b->{typ} = "float";

  return $b;

}


# Function assertType from line 181

sub assertType {
  my ($atype, $abox, $line, $file) = @_;
  
  if ( isNil($abox) ) {
    if ( equalString($atype, "nil") ) {
      return;

    } else {
      return;

    };

  } else {
    if ( equalString($atype, boxType($abox)) ) {
      return;

    } else {
      printf("Assertion failure at line %d, in file %s: provided value is not a '%s'!  It was actually '%s'. Contents:", $line, $file, $atype, boxType($abox));

      display($abox);

      printf("\n");

      display(cons(boxString("Token may have been read from "), cons(boxString(stringify(getTagFail($abox, boxString("filename"), boxString("source file not found")))), cons(boxString(":"), cons(boxString(stringify(getTagFail($abox, boxString("line"), boxString("source line not found")))), undef)))));

      StackTracePrint();

      panic("Invalid type!");

    };

  };

}


# Function unBoxString from line 198

sub unBoxString {
  my ($b) = @_;
  
  assertType("string", $b, 199, "q/base.qon");

  return $b->{str};

}


# Function unBoxSymbol from line 201

sub unBoxSymbol {
  my ($b) = @_;
  
  return $b->{str};

}


# Function unBoxBool from line 202

sub unBoxBool {
  my ($b) = @_;
  
  return $b->{boo};

}


# Function unBoxInt from line 203

sub unBoxInt {
  my ($b) = @_;
  
  return $b->{i};

}


# Function unBoxFloat from line 204

sub unBoxFloat {
  my ($b) = @_;
  
  return $b->{f};

}


# Function stringify_rec from line 206

sub stringify_rec {
  my ($b) = @_;
  
  if ( isNil($b) ) {
    return "";

  } else {
    return stringConcatenate(stringify(car($b)), stringConcatenate(" ", stringify_rec(cdr($b))));

  };

}


# Function stringify from line 215

sub stringify {
  my ($b) = @_;
  
  if ( isNil($b) ) {
    return "()";

  } else {
    if ( equalString("string", boxType($b)) ) {
      return unBoxString($b);

    } else {
      if ( equalString("bool", boxType($b)) ) {
        if ( unBoxBool($b) ) {
          return "true";

        } else {
          return "false";

        };

      } else {
        if ( equalString("int", boxType($b)) ) {
          return intToString(unBoxInt($b));

        } else {
          if ( equalString("float", boxType($b)) ) {
            return floatToString(unBoxFloat($b));

          } else {
            if ( equalString("symbol", boxType($b)) ) {
              return unBoxSymbol($b);

            } else {
              if ( equalString("list", boxType($b)) ) {
                return stringConcatenate("(", stringConcatenate(stringify(car($b)), stringConcatenate(" ", stringConcatenate(stringify_rec(cdr($b)), ")"))));

              } else {
                return stringConcatenate("Unsupported type in stringify: ", boxType($b));

              };

            };

          };

        };

      };

    };

  };

}


# Function hasTag from line 253

sub hasTag {
  my ($aBox, $key) = @_;
  
  if ( isNil($aBox) ) {
    return $false;

  } else {
    return isNotFalse(assoc(stringify($key), $aBox->{tag}));

  };

}


# Function getTag from line 260

sub getTag {
  my ($aBox, $key) = @_;
  
  if ( $false ) {
    printf("Getting %s from: ", stringify($key));

    display(alistKeys($aBox->{tag}));

    printf("\n");

  } else {
    printf("");

  };

  return cdr(assoc(stringify($key), $aBox->{tag}));

}


# Function getTagFail from line 272

sub getTagFail {
  my ($aBox, $key, $onFail) = @_;
  
  if ( hasTag($aBox, $key) ) {
    return getTag($aBox, $key);

  } else {
    return $onFail;

  };

}


# Function assocExists from line 282

sub assocExists {
  my ($key, $aBox) = @_;
  
  if ( isNil($aBox) ) {
    return $false;

  } else {
    return isNotFalse(assoc($key, $aBox));

  };

}


# Function assocFail from line 290

sub assocFail {
  my ($key, $aBox, $onFail) = @_;
  
  if ( assocExists($key, $aBox) ) {
    return assoc($key, $aBox);

  } else {
    return cons(boxString($key), $onFail);

  };

}


# Function assocPanic from line 297

sub assocPanic {
  my ($key, $aBox, $onFail) = @_;
  
  if ( assocExists($key, $aBox) ) {
    return assoc($key, $aBox);

  } else {
    panic($onFail);

  };

  panic("Inconceivable");

  return undef;

}


# Function setTag from line 308

sub setTag {
  my ($key, $val, $aStruct) = @_;
  
  $aStruct->{tag} = alistCons($key, $val, $aStruct->{tag});

  return $aStruct;

}


# Function locPanic from line 314

sub locPanic {
  my ($file, $line, $message) = @_;
  
  printf("%s %s:%s\n", $file, $line, $message);

  panic($message);

}


# Function truthy from line 320

sub truthy {
  my ($aVal) = @_;
  
  return isNotFalse($aVal);

}


# Function isNotFalse from line 325

sub isNotFalse {
  my ($aVal) = @_;
  
  if ( equalString(boxType($aVal), "bool") ) {
    if ( unBoxBool($aVal) ) {
      return $true;

    } else {
      return $false;

    };

  } else {
    return $true;

  };

}


# Function toStr from line 332

sub toStr {
  my ($thing) = @_;
  
  return boxString(stringify($thing));

}


# Function listLast from line 336

sub listLast {
  my ($alist) = @_;
  
  if ( isEmpty(cdr($alist)) ) {
    return car($alist);

  } else {
    return listLast(cdr($alist));

  };

}


# Function newLine from line 343

sub newLine {
  my ($indent) = @_;
  
  printf("\n");

  printIndent($indent);

}


# Function printIndent from line 347

sub printIndent {
  my ($ii) = @_;
  
  if ( greaterthan($ii, 0) ) {
    printf("  ");

    printIndent(sub1($ii));

  } else {
    return;

  };

}


# Function stringIndent from line 354

sub stringIndent {
  my ($ii) = @_;
  
  if ( greaterthan($ii, 0) ) {
    return stringConcatenate("  ", stringIndent(sub1($ii)));

  } else {
    return "";

  };

}


# Function listIndent from line 360

sub listIndent {
  my ($ii) = @_;
  
  return cons(id(boxString(stringIndent($ii))), undef);

}


# Function listNewLine from line 366

sub listNewLine {
  my ($ii) = @_;
  
  return cons(id(boxString(stringConcatenate("\n", stringIndent($ii)))), undef);

}


# Function argList from line 372

sub argList {
  my ($count, $pos, $args) = @_;
  
  if ( greaterthan($count, $pos) ) {
    return cons(boxString(getStringArray($pos, $args)), argList($count, add1($pos), $args));

  } else {
    return undef;

  };

}


# Function tron from line 382

sub tron {
  my () = @_;
  
  $globalTrace = $true;

}


# Function troff from line 383

sub troff {
  my () = @_;
  
  $globalTrace = $false;

}


# Function stron from line 384

sub stron {
  my () = @_;
  
  $globalStepTrace = $true;

}


# Function stroff from line 385

sub stroff {
  my () = @_;
  
  $globalStepTrace = $false;

}


# Function StackTraceMove from line 389

sub StackTraceMove {
  my ($direction, $filename, $fname, $line) = @_;
  
  if ( equalString($direction, "in") ) {
    $globalStackTrace = cons(cons(boxString($filename), cons(boxString($line), cons(boxString($fname), undef))), $globalStackTrace);

  } else {
    $globalStackTrace = cdr($globalStackTrace);

  };

}


# Function StackTracePrint from line 397

sub StackTracePrint {
  my () = @_;
  
  printf("Stack trace:\n");

  if ( isNil($globalStackTrace) ) {
    printf("  <empty>\n");

  } else {
    StackTracePrintHelper($globalStackTrace);

  };

}


# Function StackTracePrintHelper from line 405

sub StackTracePrintHelper {
  my ($stack) = @_;
  my $file = stringify(first(car($stack)));
my $line = "";
my $func = "";

  if ( isNil($stack) ) {
    printf("  <end>\n");

    return;

  } else {
    $file = stringify(first(car($stack)));

    $line = stringify(second(car($stack)));

    $func = stringify(third(first($stack)));

    printf("  %s:%s %s\n", $file, $line, $func);

    StackTracePrintHelper(cdr($stack));

  };

}


# Function NoStackTrace_list from line 430

sub NoStackTrace_list {
  my () = @_;
  
  return cons(boxString("StackTraceMove"), cons(boxString("StackTracePrint"), cons(boxString("StackTracePrintHelper"), cons(boxString("NoStackTrace_list"), cons(boxString("car"), cons(boxString("cdr"), cons(boxString("cons"), cons(boxString("set"), cons(boxString("boxString"), cons(boxString("makePair"), cons(boxString("set-struct"), cons(boxString("display"), cons(boxString("list"), cons(boxString("assertType"), cons(boxString("isEmpty"), cons(boxString("isNil"), cons(boxString("get-struct"), cons(boxString("equalString"), cons(boxString("binop"), cons(boxString("strcmp"), cons(boxString("main"), cons(boxString("makeBox"), cons(boxString("string_length"), cons(boxString("boxType"), cons(boxString("displayList"), cons(boxString("newLine"), cons(boxString("panic"), undef)))))))))))))))))))))))))));

}


# Function NoTrace_list from line 435

sub NoTrace_list {
  my () = @_;
  
  return cons(boxString("StackTraceMove"), cons(boxString("StackTracePrint"), cons(boxString("StackTracePrintHelper"), cons(boxString("NoStackTrace_list"), cons(boxString("car"), cons(boxString("cdr"), cons(boxString("cons"), cons(boxString("set"), cons(boxString("boxString"), cons(boxString("makePair"), cons(boxString("set-struct"), cons(boxString("display"), cons(boxString("list"), cons(boxString("assertType"), cons(boxString("isEmpty"), cons(boxString("isNil"), cons(boxString("get-struct"), cons(boxString("equalString"), cons(boxString("binop"), cons(boxString("strcmp"), cons(boxString("main"), cons(boxString("makeBox"), cons(boxString("string_length"), cons(boxString("boxType"), cons(boxString("displayList"), cons(boxString("newLine"), cons(boxString("panic"), cons(boxString("boxString"), cons(boxString("boxSymbol"), cons(boxString("boxType"), cons(boxString("equalString"), cons(boxString("unBoxSymbol"), cons(boxString("isList"), cons(boxString("makeBox"), cons(boxString("equalBox"), cons(boxString("sub"), cons(boxString("sub1"), cons(boxString("stringify"), cons(boxString("add"), cons(boxString("greaterthan"), undef))))))))))))))))))))))))))))))))))))))));

}


# Function indexOfHelper from line 444

sub indexOfHelper {
  my ($haystack, $needle, $start, $current) = @_;
  
  if ( greaterthan(add($current, length($needle)), length($haystack)) ) {
    return -1;

  } else {
    if ( equalString(substr($haystack, $current, length($needle)), $needle) ) {
      return $current;

    } else {
      return indexOfHelper($haystack, $needle, $start, add1($current));

    };

  };

}


# Function indexOf from line 453

sub indexOf {
  my ($haystack, $needle, $start) = @_;
  
  if ( equal(length($needle), 0) ) {
    return $start;

  } else {
    return indexOfHelper($haystack, $needle, $start, $start);

  };

}


# Function stringReplace from line 460

sub stringReplace {
  my ($old, $new, $s) = @_;
  my $pos = 0;

  $pos = indexOf($s, $old, 0);

  if ( equal($pos, -1) ) {
    return $s;

  } else {
    return stringConcatenate(substr($s, 0, $pos), stringConcatenate($new, stringReplace($old, $new, substr($s, add($pos, length($old)), subtract(length($s), add($pos, length($old)))))));

  };

}


# Function stringContains from line 475

sub stringContains {
  my ($haystack, $needle) = @_;
  my $haystackLength = 0;
my $needleLength = 0;

  $haystackLength = length($haystack);

  $needleLength = length($needle);

  if ( greaterthan($needleLength, $haystackLength) ) {
    return $false;

  } else {
    return stringContainsHelper($haystack, $needle, 0);

  };

}


# Function stringContainsHelper from line 490

sub stringContainsHelper {
  my ($haystack, $needle, $startIndex) = @_;
  my $haystackLength = 0;
my $needleLength = 0;

  $haystackLength = length($haystack);

  $needleLength = length($needle);

  if ( greaterthan(add($startIndex, $needleLength), $haystackLength) ) {
    return $false;

  } else {
    if ( equalString(substr($haystack, $startIndex, $needleLength), $needle) ) {
      return $true;

    } else {
      return stringContainsHelper($haystack, $needle, add($startIndex, 1));

    };

  };

}


# Function isWhiteSpace from line 511

sub isWhiteSpace {
  my ($s) = @_;
  
  if ( equalString(" ", $s) ) {
    return $true;

  } else {
    if ( equalString("\t", $s) ) {
      return $true;

    } else {
      if ( equalString("\n", $s) ) {
        return $true;

      } else {
        if ( equalString("\r", $s) ) {
          return $true;

        } else {
          return $false;

        };

      };

    };

  };

}


# Function stringTrim from line 526

sub stringTrim {
  my ($s) = @_;
  
  if ( equal(length($s), 0) ) {
    return "";

  } else {
    if ( isWhiteSpace(substr($s, 0, 1)) ) {
      return stringTrim(substr($s, 1, sub1(length($s))));

    } else {
      if ( isWhiteSpace(substr($s, subtract(length($s), 1), 1)) ) {
        return stringTrim(substr($s, 0, subtract(length($s), 1)));

      } else {
        return $s;

      };

    };

  };

}


# Function stringSplit from line 542

sub stringSplit {
  my ($s, $delimiter) = @_;
  my $end = 0;
my $delimiterLength = 0;

  printf("Entering stringSplit with s: %.20s..., delimiter: %s\n", $s, $delimiter);

  $delimiterLength = length($delimiter);

  $end = indexOf($s, $delimiter, 0);

  if ( equal($end, -1) ) {
    printf("No delimiter found in stringSplit\n");

    return cons(boxString($s), undef);

  } else {
    printf("Splitting string in stringSplit\n");

    return cons(boxString(substr($s, 0, $end)), stringSplit(substr($s, add($end, $delimiterLength), subtract(length($s), add($end, $delimiterLength))), $delimiter));

  };

}


# Function perlIsNil from line 4

sub perlIsNil {
  my ($a) = @_;
  
  if ( !defined $a ) {
    return $true;

  } else {
    return $false;

  };

}


# Function getEnv from line 11

sub getEnv {
  my ($key) = @_;
  
  return $ENV{$key};

}


# Function panic from line 15

sub panic {
  my ($s) = @_;
  
  printf("Panic: %s\n", $s);

  die();

}


# Function subtract from line 20

sub subtract {
  my ($a, $b) = @_;
  
  return ($a - $b);

}


# Function mult from line 24

sub mult {
  my ($a, $b) = @_;
  
  return ($a * $b);

}


# Function greaterthan from line 28

sub greaterthan {
  my ($a, $b) = @_;
  
  return ($a > $b);

}


# Function subf from line 32

sub subf {
  my ($a, $b) = @_;
  
  return ($a - $b);

}


# Function multf from line 36

sub multf {
  my ($a, $b) = @_;
  
  return ($a * $b);

}


# Function greaterthanf from line 40

sub greaterthanf {
  my ($a, $b) = @_;
  
  return ($a > $b);

}


# Function equalf from line 44

sub equalf {
  my ($a, $b) = @_;
  
  return ($a == $b);

}


# Function equal from line 48

sub equal {
  my ($a, $b) = @_;
  
  return ($a == $b);

}


# Function equalString from line 52

sub equalString {
  my ($a, $b) = @_;
  
  return ($a eq $b);

}


# Function string_length from line 56

sub string_length {
  my ($s) = @_;
  
  return length($s);

}


# Function setSubString from line 60

sub setSubString {
  my ($target, $start, $source) = @_;
  
  substr($target, $start, 1, $source);

  return $target;

}


# Function sub_string from line 65

sub sub_string {
  my ($s, $start, $length) = @_;
  
  return substr($s, $start, $length);

}


# Function stringConcatenate from line 69

sub stringConcatenate {
  my ($a, $b) = @_;
  
  return ($a . $b);

}


# Function intToString from line 73

sub intToString {
  my ($a) = @_;
  
  return sprintf("%d", $a);

}


# Function floatToString from line 77

sub floatToString {
  my ($a) = @_;
  
  return sprintf("%g", $a);

}


# Function read_file from line 81

sub read_file {
  my ($filename) = @_;
  my $contents = "";

  if ( !open(my $fh, '<', $filename) ) {
    return undef;

  } else {
    local $/= undef;

    $contents = <$fh>;

    close($fh);

    return boxString($contents);

  };

}


# Function write_file from line 91

sub write_file {
  my ($filename, $data) = @_;
  
  open my $fh, '>', $filename or die 'Cannot open file: ' . $!;

  print $fh $data;

  close($fh);

}


# Function getStringArray from line 97

sub getStringArray {
  my ($index, $strs) = @_;
  
  return $strs->[$index];

}


# Function programArgs from line 101

sub programArgs {
  my () = @_;
  
  return \@ARGV;

}


# Function programArgsCount from line 105

sub programArgsCount {
  my () = @_;
  
  return scalar @ARGV;

}


# Function character from line 109

sub character {
  my ($num) = @_;
  
  return chr($num);

}


# Function displays from line 113

sub displays {
  my ($s) = @_;
  
  printf("%s", $s);

}


# Function remainder from line 117

sub remainder {
  my ($a, $b) = @_;
  
  return ($a % $b);

}


# Function or from line 121

sub or {
  my ($a, $b) = @_;
  
  return ($a || $b);

}


# Function max from line 125

sub max {
  my ($a, $b) = @_;
  
  if ( greaterthan($a, $b) ) {
    return $a;

  } else {
    return $b;

  };

}


# Function min from line 131

sub min {
  my ($a, $b) = @_;
  
  if ( greaterthan($a, $b) ) {
    return $b;

  } else {
    return $a;

  };

}


# Function makeHash from line 137

sub makeHash {
  my () = @_;
  
  return {};

}


# Function setHash from line 141

sub setHash {
  my ($hash, $key, $value) = @_;
  
  $hash->{$key} = $value;

}


# Function getHash from line 145

sub getHash {
  my ($hash, $key) = @_;
  
  return $hash->{$key};

}


# Function inHash from line 149

sub inHash {
  my ($hash, $key) = @_;
  
  return exists $hash->{$key};

}


# Function makeArray from line 153

sub makeArray {
  my ($length) = @_;
  
  return [];

}


# Function setArray from line 157

sub setArray {
  my ($array, $index, $value) = @_;
  
  $array->[$index] = $value;

}


# Function getArray from line 161

sub getArray {
  my ($array, $index) = @_;
  
  return $array->[$index];

}


# Function isNil from line 165

sub isNil {
  my ($a) = @_;
  
  return !defined $a;

}


# Function start from line 5

sub start {
  my () = @_;
  my $runTests = $false;
my $cmdLine = undef;
my $filenameBox = undef;
my $filename = "";
my $runPerl = $false;
my $runJava = $false;
my $runNode = $false;
my $runNode2 = $false;
my $runHaskell = $false;
my $runAnsi3 = $false;
my $runTree = $false;

  $cmdLine = listReverse(argList($globalArgsCount, 0, $globalArgs));

  if ( greaterthan(listLength($cmdLine), 1) ) {
    $filenameBox = second($cmdLine);

  } else {
    $filenameBox = boxString("compiler.qon");

  };

  $filename = unBoxString($filenameBox);

  $releaseMode = inList(boxString("--release"), $cmdLine);

  $runTests = inList(boxString("--test"), $cmdLine);

  $runJava = inList(boxString("--java"), $cmdLine);

  $runPerl = inList(boxString("--perl"), $cmdLine);

  $runTree = inList(boxString("--tree"), $cmdLine);

  $runNode = inList(boxString("--node"), $cmdLine);

  $runNode2 = inList(boxString("--node2"), $cmdLine);

  $runHaskell = orBool(inList(boxString("--haskell"), $cmdLine), inList(boxString("--hs"), $cmdLine));

  $runAnsi3 = inList(boxString("--ansi3"), $cmdLine);

  $globalTrace = inList(boxString("--trace"), $cmdLine);

  $globalStepTrace = inList(boxString("--steptrace"), $cmdLine);

  if ( orBool(inList(boxString("--help"), $cmdLine), inList(boxString("-h"), $cmdLine)) ) {
    printf("Usage: quon file [options]\n\nNote the options go after the file name\n");

    printf("Options:\n");

    printf("  -h, --help  Display this help\n");

    printf("  --release   Compile in release mode\n");

    printf("  --test      Run the test suite\n");

    printf("  --java      Compile to Java\n");

    printf("  --perl      Compile to Perl\n");

    printf("  --tree      Compile to an s-expression tree\n");

    printf("  --node      Compile to Node.js\n");

    printf("  --node2      Compile to Node.js, new outputter\n");

    printf("  --haskell, --hs Compile to Haskell\n");

    printf("  --ansi3     Compile to ANSI C (quon version 3)\n");

    printf("  --trace     Trace execution\n");

    printf("  --steptrace Step trace execution\n");

    exit(0);

  } else {
  };

  if ( $runTests ) {
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

    test14();

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

    test27();

    test28();

    printf("\n\nAfter all that hard work, I need a beer...\n");

    beers(9);

  } else {
    if ( $runTree ) {
      display(macrowalk(loadQuon($filename)));

    } else {
      if ( orBool($runNode, $runNode2) ) {
        node2Compile($filename);

        printf("\n");

      } else {
        if ( $runHaskell ) {
          haskellCompile($filename);

          printf("\n");

        } else {
          if ( $runPerl ) {
            perlCompile($filename);

            printf("\n");

          } else {
            if ( $runJava ) {
              javaCompile($filename);

              printf("\n");

            } else {
              if ( $runAnsi3 ) {
                ansi3Compile($filename);

                printf("\n");

              } else {
                ansi3Compile($filename);

                printf("\n");

              };

            };

          };

        };

      };

    };

  };

  return 0;

}

# Main entry point
$globalArgsCount = scalar(@ARGV) + 1;
$globalArgs = \@ARGV;
unshift @$globalArgs, 'fixmeprogname' ;
$quonGlobalArgs = [];
for my $arg (@$globalArgs) {
    push @$quonGlobalArgs, {car => $arg, cdr => undef};
}
for (my $i = scalar(@$quonGlobalArgs) - 1; $i >= 0; $i--) {
    $quonGlobalArgs->[$i]->{cdr} = $quonGlobalArgs->[$i + 1];
}
*stderr = *STDERR;
sub fprintf { my $f = shift; printf $f @_ }
start();


