use strict;
use warnings;
use v5.10;

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


# Function node2FunctionArgs from line 4

sub node2FunctionArgs {
  my ($tree) = @_;
  my $out = undef;

  $out = undef;

  if ( isEmpty($tree) ) {
    return undef;

  } else {
    if ( equalString(stringify(first($tree)), '...') ) {
      $out = cons(id($out), cons(boxString('...'), undef));

    } else {
      $out = cons(boxString(' '), cons(id(second($tree)), undef));

    };

    if ( isNil(cddr($tree)) ) {
    } else {
      $out = cons(id($out), cons(boxString(', '), undef));

    };

    return cons(id($out), cons(id(node2FunctionArgs(cddr($tree))), undef));

  };

}


# Function node2Expression from line 21

sub node2Expression {
  my ($tree, $indent) = @_;
  my $thing = undef;

  if ( isList($tree) ) {
    if ( equal(1, listLength($tree)) ) {
      if ( equalBox(boxString('return'), car($tree)) ) {
        return boxString('return');

      } else {
        return cons(id(car($tree)), cons(boxString('()'), undef));

      };

    } else {
      $thing = first($tree);

      if ( equalBox(boxSymbol('get-struct'), $thing) ) {
        return cons(id(second($tree)), cons(id(boxString('.')), cons(id(third($tree)), undef)));

      } else {
        if ( equalBox(boxSymbol('new'), $thing) ) {
          return cons(id(boxString('new')), cons(id(third($tree)), undef));

        } else {
          if ( equalBox(boxSymbol('passthrough'), $thing) ) {
            return second($tree);

          } else {
            if ( equalBox(boxSymbol('binop'), $thing) ) {
              return cons(id(boxString('(1')), cons(id(node2Expression(third($tree), $indent)), cons(id(boxString(' ')), cons(id(second($tree)), cons(id(boxString(' ')), cons(id(node2Expression(fourth($tree), $indent)), cons(id(boxString(')')), undef)))))));

            } else {
              return cons(id(node2FuncMap(car($tree))), cons(id(boxString('(2')), cons(id(node2RecurList(cdr($tree), $indent)), cons(id(boxString(')')), undef))));

            };

          };

        };

      };

    };

  } else {
    return node2FuncMap($tree);

  };

}


# Function node2RecurList from line 85

sub node2RecurList {
  my ($expr, $indent) = @_;
  
  if ( isEmpty($expr) ) {
    return boxString('');

  } else {
    return node2Expression(car($expr), $indent);

    if ( isNil(cdr($expr)) ) {
      boxString('');

    } else {
      return cons(id(boxString(', ')), cons(id(node2RecurList(cdr($expr), $indent)), undef));

    };

  };

}


# Function node2If from line 103

sub node2If {
  my ($node, $indent, $functionName) = @_;
  
  return cons(id(listNewLine($indent)), cons(id(boxString('if (4 ')), cons(id(boxString(stringify(node2Expression(second($node), 0)))), cons(id(boxString(') {')), cons(id(node2Body(cdr(third($node)), add1($indent), $functionName)), cons(id(listNewLine($indent)), cons(id(boxString('} else {')), cons(id(node2Body(cdr(fourth($node)), add1($indent), $functionName)), cons(id(listNewLine($indent)), cons(id(boxString('}')), undef))))))))));

}


# Function node2SetStruct from line 117

sub node2SetStruct {
  my ($node, $indent) = @_;
  
  return cons(id(listNewLine($indent)), cons(id(boxString(stringify(second($node)))), cons(id(boxString('.')), cons(id(boxString(stringify(third($node)))), cons(id(boxString(' = ')), cons(id(boxString(stringify(node2Expression(fourth($node), $indent)))), undef))))));

}


# Function node2GetStruct from line 127

sub node2GetStruct {
  my ($node, $indent) = @_;
  
  return cons(id(listNewLine($indent)), cons(id(boxString(stringify(first($node)))), cons(id(boxString('.')), cons(id(boxString(stringify(second($node)))), undef))));

}


# Function node2Set from line 135

sub node2Set {
  my ($node, $indent) = @_;
  
  return cons(id(listNewLine($indent)), cons(id(boxString(stringify(node2Expression(first(cdr($node)), $indent)))), cons(id(boxString(' = ')), cons(id(boxString(stringify(node2Expression(third($node), $indent)))), undef))));

}


# Function node2Return from line 143

sub node2Return {
  my ($node, $indent) = @_;
  
  if ( equal(listLength($node), 1) ) {
    return cons(id(listNewLine($indent)), cons(id(boxString('return;')), undef));

  } else {
    return cons(id(listNewLine($indent)), cons(id(boxString('return ')), cons(id(node2Expression(cadr($node), $indent)), cons(id(boxString(';')), undef))));

  };

}


# Function node2Statement from line 153

sub node2Statement {
  my ($node, $indent, $functionname) = @_;
  my $out = undef;

  $out = undef;

  if ( equalBox(boxString('set'), first($node)) ) {
    $out = node2Set($node, $indent);

  } else {
    if ( equalBox(boxString('set-struct'), first($node)) ) {
      $out = node2SetStruct($node, $indent);

    } else {
      if ( equalBox(boxString('if'), first($node)) ) {
        $out = node2If($node, $indent, $functionname);

      } else {
        if ( equalBox(boxString('return'), first($node)) ) {
          if ( inList(boxString($functionname), NoStackTrace_list()) ) {
          } else {
            $out = cons(id(boxString('\n')), cons(id(listIndent($indent)), cons(id(boxString('StackTraceMove(\"out\", \"\", \"\", \"\");\n')), undef)));

          };

          $out = cons(id($out), cons(id(node2Return($node, $indent)), undef));

        } else {
          $out = cons(id(listNewLine($indent)), cons(id(boxString(stringify(node2Expression($node, $indent)))), undef));

        };

      };

    };

  };

  $out = cons(id($out), cons(id(boxString(';\n')), undef));

  return $out;

}


# Function node2Body from line 182

sub node2Body {
  my ($tree, $indent, $functionName) = @_;
  my $code = undef;
my $out = undef;

  $out = undef;

  if ( isEmpty($tree) ) {
    return undef;

  } else {
    $code = $tree;

    if ( isNil($code) ) {
      return undef;

    } else {
      $code = car($tree);

      if ( notBool($releaseMode) ) {
        if ( inList(boxString($functionName), NoTrace_list()) ) {
          $out = cons(id($out), cons(id(boxString('//Function ')), cons(id(boxString($functionName)), cons(id(boxString(' omitted due to the no trace list\n')), undef))));

        } else {
          $out = cons(id($out), cons(id(boxString('\nif (globalTrace)\n    snprintf(caller, 1024, \"from:%s:%s\", ')), cons(id(boxString(stringify(getTagFail(car($code), boxString('filename'), boxString('Unknown file (not provided by parser)'))))), cons(id(boxString(stringify(getTagFail(car($code), boxString('line'), boxString('Line missing'))))), undef))));

        };

      } else {
      };

    };

    if ( notBool($releaseMode) ) {
      $out = cons(id($out), cons(id(listIndent($indent)), cons(id(boxString('if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n')), undef)));

    } else {
    };

    return cons(id($out), cons(id(node2Statement($code, $indent, $functionName)), cons(id(node2Body(cdr($tree), $indent, $functionName)), undef)));

  };

}


# Function node2eclarations from line 219

sub node2eclarations {
  my ($decls, $indent) = @_;
  my $decl = undef;

  if ( isEmpty($decls) ) {
    return undef;

  } else {
    $decl = car($decls);

    return cons(id(boxString('var ')), cons(id(boxString(stringify(node2TypeMap(first($decl))))), cons(id(boxString(' ')), cons(id(boxString(stringify(second($decl)))), cons(id(boxString(' = ')), cons(id(node2Expression(third($decl), $indent)), cons(id(boxString(';\n')), cons(id(node2eclarations(cdr($decls), $indent)), undef))))))));

  };

}


# Function node2Function from line 235

sub node2Function {
  my ($node) = @_;
  my $name = undef;

  $name = second($node);

  newLine(0);

  if ( isNil($node) ) {
    return undef;

  } else {
    return cons(id(listNewLine(0)), cons(id(boxString('function')), cons(id(boxString(' ')), cons(id(boxString(stringify(second($node)))), cons(id(boxString('(3')), cons(id(node2FunctionArgs(third($node))), cons(id(boxString(') {')), cons(id(listNewLine(1)), cons(id(node2eclarations(cdr(fourth($node)), 1)), cons(id(node2Body(cdr(fifth($node)), 1, stringify($name))), cons(id(boxString('\n}\n')), undef)))))))))));

  };

}


# Function node2Functions from line 264

sub node2Functions {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return undef;

  } else {
    return cons(id(node2Function(car($tree))), cons(id(node2Functions(cdr($tree))), undef));

  };

}


# Function node2Includes from line 274

sub node2Includes {
  my ($nodes) = @_;
  
  return undef;

}


# Function node2TypeDecl from line 278

sub node2TypeDecl {
  my ($l) = @_;
  
  return undef;

}


# Function node2StructComponents from line 282

sub node2StructComponents {
  my ($node) = @_;
  
  if ( isEmpty($node) ) {
    return undef;

  } else {
    return cons(id(node2TypeDecl(car($node))), cons(id(node2StructComponents(cdr($node))), undef));

  };

}


# Function node2Struct from line 288

sub node2Struct {
  my ($node) = @_;
  
  node2StructComponents(cdr($node));

}


# Function node2TypeMap from line 291

sub node2TypeMap {
  my ($aSym) = @_;
  my $symMap = undef;

  $symMap = alistCons(boxSymbol('stringArray'), boxSymbol('char**'), alistCons(boxSymbol('string'), boxSymbol('char*'), undef));

  if ( truthy(assoc(stringify($aSym), $symMap)) ) {
    return cdr(assoc(stringify($aSym), $symMap));

  } else {
    return $aSym;

  };

}


# Function node2FuncMap from line 301

sub node2FuncMap {
  my ($aSym) = @_;
  my $symMap = undef;

  if ( equalString('symbol', boxType($aSym)) ) {
    $symMap = alistCons(boxSymbol('='), boxSymbol('equal'), alistCons(boxSymbol('sub-string'), boxSymbol('sub_string'), alistCons(boxSymbol('read-file'), boxSymbol('read_file'), alistCons(boxSymbol('write-file'), boxSymbol('write_file'), alistCons(boxSymbol('>'), boxSymbol('greaterthan'), alistCons(boxSymbol('string-length'), boxSymbol('string_length'), alistCons(boxSymbol('nil'), boxSymbol('NULL'), undef)))))));

    if ( truthy(assoc(stringify($aSym), $symMap)) ) {
      return cdr(assoc(stringify($aSym), $symMap));

    } else {
      return $aSym;

    };

  } else {
    return $aSym;

  };

}


# Function node2Type from line 332

sub node2Type {
  my ($node) = @_;
  
  return undef;

}


# Function node2Types from line 337

sub node2Types {
  my ($nodes) = @_;
  
  if ( isEmpty($nodes) ) {
    return undef;

  } else {
    return cons(id(node2Type(car($nodes))), cons(id(node2Types(cdr($nodes))), undef));

  };

}


# Function node2Compile from line 347

sub node2Compile {
  my ($filename) = @_;
  my $tree = undef;
my $replace = undef;

  fprintf($stderr, '//Scanning file...%s\n', $filename);

  $tree = loadQuon($filename);

  fprintf($stderr, '//Building sexpr\n');

  fprintf($stderr, 'Loading shim node2\n');

  $tree = buildProg(cons(boxString('q/shims/node2.qon'), getIncludes($tree)), getTypes($tree), getFunctions($tree));

  fprintf($stderr, 'Loading all includes\n');

  $tree = loadIncludes($tree);

  fprintf($stderr, 'Applying macros\n');

  $tree = macrowalk($tree);

  $replace = cons(boxSymbol('fprintf'), cons(boxSymbol('stderr'), undef));

  $tree = macrolist($tree, stringConcatenate('q', 'log'), $replace);

  fprintf($stderr, '//Printing program\n');

  printf('%s', stringify(flatten(node2Includes(cdr(first($tree))))));

  printf('%s', stringify(flatten(node2Types(cdr(second($tree))))));

  printf('%s', stringify(flatten(node2Functions(cdr(third($tree))))));

  printf('\n');

  fprintf($stderr, '//Done printing program\n');

}


# Function test0 from line 7

sub test0 {
  my () = @_;
  
  if ( equalString(stringify(boxString('hello')), stringify(boxString('hello'))) ) {
    printf('0.  pass string compare works\n');

  } else {
    printf('0.  pass string compare fails\n');

  };

  if ( equalString(stringify(boxString('hello')), stringify(boxSymbol('hello'))) ) {
    printf('0.  pass string compare works\n');

  } else {
    printf('0.  pass string compare fails\n');

  };

}


# Function test1 from line 20

sub test1 {
  my () = @_;
  
  printf('1.  pass Function call and print work\n');

}


# Function test2_do from line 24

sub test2_do {
  my ($message) = @_;
  
  printf('2.  pass Function call with arg works: %s\n', $message);

}


# Function test2 from line 28

sub test2 {
  my () = @_;
  
  test2_do('This is the argument');

}


# Function test3_do from line 30

sub test3_do {
  my ($b, $c) = @_;
  
  printf('3.1 pass Two arg call, first arg: %d\n', $b);

  printf('3.2 pass Two arg call, second arg: %s\n', $c);

}


# Function test3 from line 36

sub test3 {
  my () = @_;
  
  test3_do(42, 'Fourty-two');

}


# Function test4_do from line 37

sub test4_do {
  my () = @_;
  
  return 'pass Return works';

}


# Function returnThis from line 39

sub returnThis {
  my ($returnMessage) = @_;
  
  return $returnMessage;

}


# Function test4 from line 42

sub test4 {
  my () = @_;
  my $message = 'fail';

  $message = test4_do();

  printf('4.  %s\n', $message);

}


# Function test5 from line 45

sub test5 {
  my () = @_;
  my $message = 'fail';

  $message = returnThis('pass return passthrough string');

  printf('5.  %s\n', $message);

}


# Function test6 from line 50

sub test6 {
  my () = @_;
  
  if ( $true ) {
    printf('6.  pass If statement works\n');

  } else {
    printf('6.  fail If statement works\n');

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
    printf('7.  pass count works\n');

  } else {
    printf('7.  fail count fails\n');

  };

}


# Function beer from line 74

sub beer {
  my () = @_;
  
  printf('%d bottle of beer on the wall, %d bottle of beer.  Take one down, pass it round, no bottles of beer on the wall\n', 1, 1);

}


# Function plural from line 83

sub plural {
  my ($num) = @_;
  
  if ( equal($num, 1) ) {
    return '';

  } else {
    return 's';

  };

}


# Function beers from line 88

sub beers {
  my ($count) = @_;
  my $newcount = 0;

  $newcount = subtract($count, 1);

  printf('%d bottle%s of beer on the wall, %d bottle%s of beer.  Take one down, pass it round, %d bottle%s of beer on the wall\n', $count, plural($count), $count, plural($count), $newcount, plural($newcount));

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
    printf('8.  pass Nested expressions work\n');

  } else {
    printf('8.  fail Nested expressions don\'t work\n');

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
    printf('9.1  pass sub works\n');

  } else {
    printf('9.1  fail sub\n');

  };

  $answer = add(2, 3);

  if ( equal($answer, 5) ) {
    printf('9.2  pass add works\n');

  } else {
    printf('9.2  fail add\n');

  };

  $answer = mult($a, $b);

  if ( equal($answer, 6) ) {
    printf('9.3  pass mult works\n');

  } else {
    printf('9.3  fail mult\n');

  };

  if ( greaterthan(2, 1) ) {
    printf('9.4  pass greaterthan works\n');

  } else {
    printf('9.4  fail greaterthan\n');

  };

  if ( equal(1, 1) ) {
    printf('9.5  pass integer equal works\n');

  } else {
    printf('9.5  fail integer equal\n');

  };

  if ( equalString('hello', 'hello') ) {
    printf('9.6  pass string equal works\n');

  } else {
    printf('9.6  fail string equal\n');

  };

  if ( equalString('hello', 'world') ) {
    printf('9.7  fail string equal\n');

  } else {
    printf('9.7  pass string equal\n');

  };

  if ( andBool($false, $false) ) {
    printf('9.8  fail andBool\n');

  } else {
    printf('9.8  pass andBool works\n');

  };

  if ( andBool($true, $true) ) {
    printf('9.9  pass andBool works\n');

  } else {
    printf('9.9  fail andBool\n');

  };

  if ( andBool($true, $false) ) {
    printf('9.10  fail andBool\n');

  } else {
    printf('9.10  pass andBool works\n');

  };

  if ( equalString('hello', 'hello') ) {
    printf('9.11  pass string equal\n');

  } else {
    printf('9.11  fail string equal\n');

  };

  if ( equalString('!', character(33)) ) {
    printf('9.12  pass character\n');

  } else {
    printf('9.12  fail character\n');

  };

  if ( equalString('33', intToString(33)) ) {
    printf('9.13  pass intToString\n');

  } else {
    printf('9.13  fail intToString\n');

  };

  if ( equalString('llo', substr('hello', $a, $b)) ) {
    printf('9.14  pass sub-string\n');

  } else {
    printf('9.14  fail sub-string: %s\n', substr('hello', $a, $b));

  };

}


# Function test10 from line 170

sub test10 {
  my () = @_;
  my $testString = 'This is a test string';

  if ( equalString($testString, unBoxString(car(cons(boxString($testString), undef)))) ) {
    printf('10. pass cons and car work\n');

  } else {
    printf('10. fail cons and car fail\n');

  };

}


# Function test12 from line 180

sub test12 {
  my () = @_;
  my $b = undef;

  $b = {};

  $b->{str} = '12. pass structure accessors\n';

  printf('%s', $b->{str});

}


# Function test13 from line 188

sub test13 {
  my () = @_;
  my $testString = 'Hello from the filesystem!';
my $contents = '';

  write_file('test.txt', $testString);

  $contents = read_file('test.txt');

  if ( equalString($testString, $contents) ) {
    printf('13. pass Read and write files\n');

  } else {
    printf('13. fail Read and write files\n');

    printf('Expected: %s\n', $testString);

    printf('Got: %s\n', $contents);

  };

}


# Function test15 from line 204

sub test15 {
  my () = @_;
  my $a = 'hello';
my $b = ' world';
my $c = '';

  $c = stringConcatenate($a, $b);

  if ( equalString($c, 'hello world') ) {
    printf('15. pass String concatenate\n');

  } else {
    printf('15. fail String concatenate\n');

  };

}


# Function test16 from line 212

sub test16 {
  my () = @_;
  my $assocCell1 = undef;
my $assList = undef;
my $assocCell2 = undef;
my $assocCell3 = undef;

  $assocCell1 = cons(boxString('Hello'), boxString('world'));

  $assocCell2 = cons(boxString('goodnight'), boxString('moon'));

  $assocCell3 = cons(boxSymbol('ohio'), boxString('gozaimasu'));

  $assList = cons($assocCell2, emptyList());

  $assList = cons($assocCell1, $assList);

  $assList = cons($assocCell3, $assList);

  if ( equalBox(cdr(assoc('Hello', $assList)), boxString('world')) ) {
    printf('16.1 pass Basic assoc works\n');

  } else {
    printf('16.1 fail Basic assoc fails\n');

  };

  if ( andBool(andBool(equalBox(cdr(assoc('Hello', $assList)), boxString('world')), equalBox(cdr(assoc('goodnight', $assList)), boxString('moon'))), equalBox(cdr(assoc('ohio', $assList)), boxString('gozaimasu'))) ) {
    printf('16.2 pass assoc list\n');

  } else {
    printf('16.2 fail assoc list\n');

  };

}


# Function test17 from line 236

sub test17 {
  my () = @_;
  my $l = undef;

  $l = cons(boxInt(1), cons(boxInt(2), cons(boxInt(3), undef)));

  if ( equalBox(car($l), boxInt(1)) ) {
    printf('17. pass list literal works\n');

  } else {
    printf('17. fail list literal failed\n');

  };

}


# Function test18 from line 247

sub test18 {
  my () = @_;
  my $val1 = 'a';
my $val2 = 'b';
my $l = undef;

  $l = cons(boxString($val1), cons(boxString($val2), cons(boxString('c'), undef)));

  if ( equalList($l, cons(boxString('a'), cons(boxString('b'), cons(boxString('c'), undef)))) ) {
    printf('18. pass string list constructor works\n');

  } else {
    printf('18. fail string list constructor failed\n');

  };

}


# Function test19 from line 261

sub test19 {
  my () = @_;
  my $val1 = 'a';
my $val2 = 'b';
my $l = undef;
my $revlist = undef;
my $answer = undef;

  $l = cons(boxString($val1), cons(boxString($val2), cons(boxString('c'), undef)));

  $answer = cons(boxString('c'), cons(boxString($val2), cons(boxString($val1), undef)));

  $revlist = reverseList($l);

  if ( equalList($answer, $revlist) ) {
    printf('19. pass reverseList\n');

  } else {
    printf('19. fail reverseList\n');

  };

}


# Function concatenateLists from line 279

sub concatenateLists {
  my ($oldL, $newL) = @_;
  
  return reverseRec(reverseList($oldL), $newL);

}


# Function test20 from line 284

sub test20 {
  my () = @_;
  my $val1 = 'a';
my $val2 = 'b';
my $val3 = 'c';
my $l = undef;
my $l2 = undef;
my $l3 = undef;
my $combined = undef;

  $l = cons(boxString($val1), cons(boxString($val2), cons(boxString('c'), undef)));

  $l2 = cons(boxString('d'), cons(boxString('e'), cons(boxString('f'), undef)));

  $l3 = cons(boxString($val1), cons(boxString($val2), cons(boxString($val3), cons(boxString('d'), cons(boxString('e'), cons(boxString('f'), undef))))));

  $combined = concatenateLists($l, $l2);

  if ( equalList($l3, $combined) ) {
    printf('21. pass concatenateLists\n');

  } else {
    printf('21. fail concatenateLists\n');

  };

}


# Function test21 from line 304

sub test21 {
  my () = @_;
  my $val1 = 'a';
my $val2 = 'b';
my $val3 = 'c';
my $l = undef;
my $l2 = undef;

  $l = cons(boxString($val1), cons(boxString($val2), cons(boxString($val3), undef)));

  $l2 = cons(boxString('a'), cons(boxString('b'), cons(boxString('c'), undef)));

  if ( equalList($l, $l2) ) {
    printf('21. pass equalList\n');

  } else {
    printf('21. fail equalList\n');

  };

}


# Function test22 from line 320

sub test22 {
  my () = @_;
  my $original = undef;
my $out = undef;
my $replace = undef;
my $correct = undef;

  $original = cons(boxString(stringConcatenate('q', 'log')), cons(boxString('%s'), cons(boxString('hello'), undef)));

  $replace = cons(boxString('fprintf'), cons(boxString('stderr'), undef));

  $out = macrolist($original, stringConcatenate('q', 'log'), $replace);

  $correct = cons(boxString('fprintf'), cons(boxString('stderr'), cons(boxString('%s'), cons(boxString('hello'), undef))));

  if ( equalList($out, $correct) ) {
    printf('22. pass macroList\n');

  } else {
    printf('22. fail macroList\n');

    printf('In: ');

    displayList($original, 0, $true);

    printf('\nOut: ');

    displayList($out, 0, $true);

    printf('\n');

  };

}


# Function test23 from line 343

sub test23 {
  my () = @_;
  my $original = undef;
my $out = undef;
my $replace = undef;
my $correct = undef;

  $original = cons(boxString(stringConcatenate('q', 'log')), cons(boxString('%s'), cons(boxString('hello'), undef)));

  $replace = cons(boxString('fprintf'), cons(boxString('stderr'), undef));

  $out = concatLists($original, $replace);

  $correct = cons(boxString(stringConcatenate('q', 'log')), cons(boxString('%s'), cons(boxString('hello'), cons(boxString('fprintf'), cons(boxString('stderr'), undef)))));

  if ( equalList($out, $correct) ) {
    printf('23. pass concatLists\n');

  } else {
    printf('23. fail concatLists\n');

    printf('In: ');

    displayList($original, 0, $true);

    printf('\nOut: ');

    displayList($out, 0, $true);

  };

}


# Function test24 from line 366

sub test24 {
  my () = @_;
  my $expected = 'a b c';
my $res = '';

  $res = StringListJoin(cons(boxString('a'), cons(boxString('b'), cons(boxString('c'), undef))), ' ');

  if ( equalString($expected, $res) ) {
    printf('24. pass StringListJoin\n');

  } else {
    printf('24. fail StringListJoin.  expected %s, got %s\n', $expected, $res);

  };

}


# Function test25 from line 380

sub test25 {
  my () = @_;
  my $expected = '( a b ) c d e';
my $res = '';
my $testsubstr = cons(boxString('c '), cons(boxString('d '), cons(boxString('e'), undef)));
my $input = undef;

  $input = cons(boxString('a '), cons(boxString('b '), undef));

  $input = cons($input, $testsubstr);

  $res = ListToString($input, 0, $true, $false);

  if ( equalString($expected, $res) ) {
    printf('25. pass ListToString\n');

  } else {
    printf('25. fail ListToString.  expected %s, got %s\n', $expected, $res);

  };

}


# Function test27 from line 416

sub test27 {
  my () = @_;
  my $expected = 'a b c d e';
my $res = '';
my $variable = cons(boxString('c '), cons(boxString('d '), undef));
my $input = undef;

  $input = cons(boxString('a '), cons(boxString('b '), cons(id($variable), cons(boxString('e'), undef))));

  $res = ListToString(flatten($input), 0, $true, $false);

  if ( equalString($expected, $res) ) {
    printf('27. pass Interpolated List\n');

  } else {
    printf('27. fail Interpolated List.  expected %s, got %s\n', $expected, $res);

  };

}


# Function ansi3displays from line 5

sub ansi3displays {
  my ($s) = @_;
  
  printf('%s', $s);

}


# Function ansi3FunctionArgs from line 11

sub ansi3FunctionArgs {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return;

  } else {
    if ( equalString(stringify(first($tree)), '...') ) {
      printf('...');

    } else {
      display(ansi3TypeMap(first($tree)));

      ansi3displays(' ');

      display(second($tree));

    };

    if ( isNil(cddr($tree)) ) {
    } else {
      ansi3displays(', ');

    };

    ansi3FunctionArgs(cddr($tree));

  };

}


# Function ansi3Expression from line 28

sub ansi3Expression {
  my ($tree, $indent) = @_;
  my $thing = undef;

  if ( isList($tree) ) {
    if ( equal(1, listLength($tree)) ) {
      display(car($tree));

      if ( equalBox(boxString('return'), car($tree)) ) {
      } else {
        ansi3displays('()');

      };

    } else {
      $thing = first($tree);

      if ( equalBox(boxSymbol('get-struct'), $thing) ) {
        printf('%s->%s', stringify(second($tree)), stringify(third($tree)));

      } else {
        if ( equalBox(boxSymbol('new'), $thing) ) {
          printf('malloc(sizeof(%s))', stringify(third($tree)));

        } else {
          if ( equalBox(boxSymbol('passthrough'), $thing) ) {
            printf('%s', stringify(second($tree)));

          } else {
            if ( equalBox(boxSymbol('binop'), $thing) ) {
              printf('(');

              ansi3Expression(third($tree), $indent);

              printf(' %s ', stringify(second($tree)));

              ansi3Expression(fourth($tree), $indent);

              printf(')');

            } else {
              printf('%s(', stringify(ansi3FuncMap(car($tree))));

              ansi3RecurList(cdr($tree), $indent);

              printf(')');

            };

          };

        };

      };

    };

  } else {
    display(ansi3FuncMap($tree));

  };

}


# Function ansi3RecurList from line 99

sub ansi3RecurList {
  my ($expr, $indent) = @_;
  
  if ( isEmpty($expr) ) {
    return;

  } else {
    ansi3Expression(car($expr), $indent);

    if ( isNil(cdr($expr)) ) {
      ansi3displays('');

    } else {
      ansi3displays(', ');

      ansi3RecurList(cdr($expr), $indent);

    };

  };

}


# Function ansi3If from line 116

sub ansi3If {
  my ($node, $indent, $functionName) = @_;
  
  newLine($indent);

  ansi3displays('if ( ');

  ansi3Expression(second($node), 0);

  ansi3displays(') {');

  ansi3Body(cdr(third($node)), add1($indent), $functionName);

  newLine($indent);

  ansi3displays('} else {');

  ansi3Body(cdr(fourth($node)), add1($indent), $functionName);

  newLine($indent);

  ansi3displays('}');

}


# Function ansi3SetStruct from line 129

sub ansi3SetStruct {
  my ($node, $indent) = @_;
  
  newLine($indent);

  printf('%s->%s = ', stringify(second($node)), stringify(third($node)));

  ansi3Expression(fourth($node), $indent);

}


# Function ansi3GetStruct from line 138

sub ansi3GetStruct {
  my ($node, $indent) = @_;
  
  newLine($indent);

  printf('%s->%s', stringify(first($node)), stringify(second($node)));

}


# Function ansi3Set from line 146

sub ansi3Set {
  my ($node, $indent) = @_;
  
  newLine($indent);

  ansi3Expression(first(cdr($node)), $indent);

  printf(' = ');

  ansi3Expression(third($node), $indent);

}


# Function ansi3Return from line 153

sub ansi3Return {
  my ($node, $indent) = @_;
  
  newLine($indent);

  if ( equal(listLength($node), 1) ) {
    ansi3displays('return;');

  } else {
    ansi3displays('return ');

    ansi3Expression(cadr($node), $indent);

    ansi3displays(';');

  };

}


# Function ansi3Statement from line 167

sub ansi3Statement {
  my ($node, $indent, $functionname) = @_;
  
  if ( equalBox(boxString('set'), first($node)) ) {
    ansi3Set($node, $indent);

  } else {
    if ( equalBox(boxString('set-struct'), first($node)) ) {
      ansi3SetStruct($node, $indent);

    } else {
      if ( equalBox(boxString('if'), first($node)) ) {
        ansi3If($node, $indent, $functionname);

      } else {
        if ( equalBox(boxString('return'), first($node)) ) {
          if ( inList(boxString($functionname), NoStackTrace_list()) ) {
          } else {
            printf('\n');

            printIndent($indent);

            printf('%s', 'StackTraceMove(\"out\", \"\", \"\", \"\");\n');

          };

          ansi3Return($node, $indent);

        } else {
          newLine($indent);

          ansi3Expression($node, $indent);

        };

      };

    };

  };

  ansi3displays(';\n');

}


# Function ansi3Body from line 192

sub ansi3Body {
  my ($tree, $indent, $functionName) = @_;
  my $code = undef;

  if ( isEmpty($tree) ) {
    return;

  } else {
    $code = $tree;

    if ( isNil($code) ) {
    } else {
      $code = car($tree);

      if ( notBool($releaseMode) ) {
        if ( inList(boxString($functionName), NoTrace_list()) ) {
          printf('//Function %s omitted due to the no trace list\n', $functionName);

        } else {
          printf('\nif (globalTrace)\n    snprintf(caller, 1024, \"from %s:%s\");\n', stringify(getTagFail(car($code), boxString('filename'), boxString('Unknown file (not provided by parser)'))), stringify(getTagFail(car($code), boxString('line'), boxString('Line missing'))));

        };

      } else {
      };

    };

    if ( notBool($releaseMode) ) {
      printIndent($indent);

      printf('%s', 'if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n');

    } else {
    };

    ansi3Statement($code, $indent, $functionName);

    ansi3Body(cdr($tree), $indent, $functionName);

  };

}


# Function ansi3Declarations from line 221

sub ansi3Declarations {
  my ($decls, $indent) = @_;
  my $decl = undef;

  if ( isEmpty($decls) ) {
    return;

  } else {
    $decl = car($decls);

    printf('%s %s = ', stringify(ansi3TypeMap(first($decl))), stringify(second($decl)));

    ansi3Expression(third($decl), $indent);

    printf(';\n');

    ansi3Declarations(cdr($decls), $indent);

  };

}


# Function ansi3Function from line 235

sub ansi3Function {
  my ($node) = @_;
  my $name = undef;

  $name = second($node);

  newLine(0);

  if ( isNil($node) ) {
    return;

  } else {
    newLine(0);

    printf('%s %s(', stringify(ansi3TypeMap(first($node))), stringify(second($node)));

    ansi3FunctionArgs(third($node));

    printf(') {');

    newLine(1);

    ansi3Declarations(cdr(fourth($node)), 1);

    if ( $releaseMode ) {
      printf('');

    } else {
      if ( inList($name, NoTrace_list()) ) {
      } else {
        printf('\nif (globalTrace)\n    printf(\"%s at %s:%s (%%s)\\n\", caller);\n', stringify($name), stringify(getTag($name, boxString('filename'))), stringify(getTag($name, boxString('line'))));

      };

    };

    if ( $releaseMode ) {
      printf('');

    } else {
      if ( inList($name, NoStackTrace_list()) ) {
      } else {
        printf('\n  StackTraceMove(\"in\", \"%s\", \"%s\", \"%s\" );\n', stringify(getTag($name, boxString('filename'))), stringify($name), stringify(getTag($name, boxString('line'))));

      };

    };

    ansi3Body(cdr(fifth($node)), 1, stringify($name));

    printf('\n}\n');

  };

}


# Function ansi3ForwardDeclaration from line 275

sub ansi3ForwardDeclaration {
  my ($node) = @_;
  
  if ( isNil($node) ) {
    return;

  } else {
    printf('\n%s %s(', stringify(ansi3TypeMap(first($node))), stringify(second($node)));

    ansi3FunctionArgs(third($node));

    ansi3displays(');');

  };

}


# Function ansi3ForwardDeclarations from line 285

sub ansi3ForwardDeclarations {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return;

  } else {
    ansi3ForwardDeclaration(car($tree));

    ansi3ForwardDeclarations(cdr($tree));

  };

}


# Function ansi3Functions from line 291

sub ansi3Functions {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return;

  } else {
    ansi3Function(car($tree));

    ansi3Functions(cdr($tree));

  };

}


# Function ansi3Includes from line 297

sub ansi3Includes {
  my ($nodes) = @_;
  
  printf('%s', '\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\n#include <unistd.h>\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\n\nint start();  //Forwards declare the user\'s main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\nbool releaseMode = false;\n\n');

  printf('%s', 'void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n');

}


# Function ansi3TypeDecl from line 305

sub ansi3TypeDecl {
  my ($l) = @_;
  
  if ( greaterthan(listLength($l), 2) ) {
    printIndent(1);

    printf('%s %s %s;\n', stringify(second($l)), stringify(ansi3TypeMap(listLast($l))), stringify(first($l)));

  } else {
    printIndent(1);

    printf('%s %s;\n', stringify(ansi3TypeMap(listLast($l))), stringify(car($l)));

  };

}


# Function ansi3StructComponents from line 322

sub ansi3StructComponents {
  my ($node) = @_;
  
  if ( isEmpty($node) ) {
    return;

  } else {
    ansi3TypeDecl(car($node));

    ansi3StructComponents(cdr($node));

  };

}


# Function ansi3Struct from line 328

sub ansi3Struct {
  my ($node) = @_;
  
  ansi3StructComponents(cdr($node));

}


# Function ansi3TypeMap from line 331

sub ansi3TypeMap {
  my ($aSym) = @_;
  my $symMap = undef;

  $symMap = alistCons(boxSymbol('stringArray'), boxSymbol('char**'), alistCons(boxSymbol('string'), boxSymbol('char*'), undef));

  if ( truthy(assoc(stringify($aSym), $symMap)) ) {
    return cdr(assoc(stringify($aSym), $symMap));

  } else {
    return $aSym;

  };

}


# Function ansi3FuncMap from line 341

sub ansi3FuncMap {
  my ($aSym) = @_;
  my $symMap = undef;

  if ( equalString('symbol', boxType($aSym)) ) {
    $symMap = alistCons(boxSymbol('='), boxSymbol('equal'), alistCons(boxSymbol('sub-string'), boxSymbol('sub_string'), alistCons(boxSymbol('read-file'), boxSymbol('read_file'), alistCons(boxSymbol('write-file'), boxSymbol('write_file'), alistCons(boxSymbol('>'), boxSymbol('greaterthan'), alistCons(boxSymbol('string-length'), boxSymbol('string_length'), alistCons(boxSymbol('nil'), boxSymbol('NULL'), undef)))))));

    if ( truthy(assoc(stringify($aSym), $symMap)) ) {
      return cdr(assoc(stringify($aSym), $symMap));

    } else {
      return $aSym;

    };

  } else {
    return $aSym;

  };

}


# Function ansi3Type from line 372

sub ansi3Type {
  my ($node) = @_;
  
  if ( isList(second($node)) ) {
    printf('\ntypedef struct %s {\n', stringify(first($node)));

    ansi3Struct(second($node));

    printf('\n} %s;\n', stringify(first($node)));

  } else {
    ansi3displays('typedef ');

    ansi3TypeDecl($node);

  };

}


# Function ansi3Types from line 382

sub ansi3Types {
  my ($nodes) = @_;
  
  if ( isEmpty($nodes) ) {
    return;

  } else {
    ansi3Type(car($nodes));

    ansi3Types(cdr($nodes));

  };

}


# Function ansi3Compile from line 392

sub ansi3Compile {
  my ($filename) = @_;
  my $tree = undef;
my $replace = undef;

  fprintf($stderr, '//Scanning file...%s\n', $filename);

  $tree = loadQuon($filename);

  fprintf($stderr, '//Building sexpr\n');

  fprintf($stderr, 'Loading shim ansi3\n');

  $tree = buildProg(cons(boxString('q/shims/ansi3.qon'), getIncludes($tree)), getTypes($tree), getFunctions($tree));

  fprintf($stderr, 'Loading all includes\n');

  $tree = loadIncludes($tree);

  fprintf($stderr, 'Applying macros\n');

  $tree = macrowalk($tree);

  $replace = cons(boxSymbol('fprintf'), cons(boxSymbol('stderr'), undef));

  $tree = macrolist($tree, stringConcatenate('q', 'log'), $replace);

  fprintf($stderr, '//Printing program\n');

  ansi3Includes(cdr(first($tree)));

  ansi3Types(cdr(second($tree)));

  ansi3displays('Box* globalStackTrace = NULL;\n');

  ansi3displays('\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n');

  ansi3ForwardDeclarations(cdr(third($tree)));

  ansi3displays('\n\n//End forward declarations\n\n');

  ansi3Functions(cdr(third($tree)));

  ansi3displays('\n');

  fprintf($stderr, '//Done printing program\n');

}


# Function dollar from line 4

sub dollar {
  my () = @_;
  
  return '$';

}


# Function singleQuote from line 8

sub singleQuote {
  my () = @_;
  
  return '\'';

}


# Function escapedSingleQuote from line 12

sub escapedSingleQuote {
  my () = @_;
  
  return '\\\'';

}


# Function escapeSingleQuotes from line 16

sub escapeSingleQuotes {
  my ($s) = @_;
  
  return stringReplace(singleQuote(), escapedSingleQuote(), $s);

}


# Function getGlobalVariables from line 20

sub getGlobalVariables {
  my () = @_;
  
  return cons(id(boxSymbol('stderr')), cons(id(boxSymbol('true')), cons(id(boxSymbol('false')), cons(id(boxSymbol('releaseMode')), cons(id(boxSymbol('caller')), cons(id(boxSymbol('globalTrace')), cons(id(boxSymbol('globalStepTrace')), cons(id(boxSymbol('globalStackTrace')), cons(id(boxSymbol('globalArgsCount')), cons(id(boxSymbol('globalArgs')), cons(id(boxSymbol('quonGlobalArgs')), undef)))))))))));

}


# Function collectVariables from line 24

sub collectVariables {
  my ($args, $decls) = @_;
  my $variables = undef;
my $decl = undef;

  $variables = collectVariablesFromArgs($args);

  $variables = appendVariables($variables, collectVariablesFromDecls($decls));

  $variables = appendVariables($variables, getGlobalVariables());

  return $variables;

}


# Function perlGlobalVariables from line 31

sub perlGlobalVariables {
  my () = @_;
  
  printf('our $globalArgsCount;\n');

  printf('our $globalArgs;\n');

  printf('our $releaseMode;\n');

  printf('our $globalTrace;\n');

  printf('our $globalStepTrace;\n');

  printf('our $globalStackTrace;\n');

  printf('our $caller;\n');

  printf('our $false = 0;\n');

  printf('our $true = 1;\n');

  printf('my $stderr = \\*STDERR;\n');

  printf('our $quonGlobalArgs;\n');

}


# Function perlMainEntry from line 45

sub perlMainEntry {
  my () = @_;
  
  printf('\n# Main entry point\n');

  printf('$globalArgsCount = scalar(@ARGV);\n');

  printf('$globalArgs = \\@ARGV;\n');

  printf('$quonGlobalArgs = [];\n');

  printf('for my $arg (@$globalArgs) {\n');

  printf('    push @$quonGlobalArgs, {car => $arg, cdr => undef};\n');

  printf('}\n');

  printf('for (my $i = $#$quonGlobalArgs - 1; $i >= 0; $i--) {\n');

  printf('    $quonGlobalArgs->[$i]->{cdr} = $quonGlobalArgs->[$i + 1];\n');

  printf('}\n');

  printf('start();\n');

}


# Function collectVariablesFromArgs from line 59

sub collectVariablesFromArgs {
  my ($args) = @_;
  my $variables = undef;

  if ( isNil($args) ) {
    return $variables;

  } else {
    if ( equalString(stringify(first($args)), 'list') ) {
      $variables = cons(second($args), $variables);

      return appendVariables($variables, collectVariablesFromArgs(cddr($args)));

    } else {
      $variables = cons(second($args), $variables);

      return appendVariables($variables, collectVariablesFromArgs(cddr($args)));

    };

  };

}


# Function collectVariablesFromDecls from line 72

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


# Function appendVariables from line 81

sub appendVariables {
  my ($vars1, $vars2) = @_;
  
  if ( isNil($vars2) ) {
    return $vars1;

  } else {
    $vars1 = cons(car($vars2), $vars1);

    return appendVariables($vars1, cdr($vars2));

  };

}


# Function perlFunctionArgs from line 90

sub perlFunctionArgs {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return;

  } else {
    printf(dollar());

    display(second($tree));

    if ( isNil(cddr($tree)) ) {
      printf('');

    } else {
      printf(', ');

    };

    perlFunctionArgs(cddr($tree));

  };

}


# Function perlExpression from line 100

sub perlExpression {
  my ($tree, $indent, $variables) = @_;
  my $thing = undef;

  if ( isList($tree) ) {
    if ( equal(1, listLength($tree)) ) {
      display(perlFuncMap(car($tree), $variables));

      if ( equalBox(boxString('return'), car($tree)) ) {
      } else {
        printf('()');

      };

    } else {
      $thing = first($tree);

      if ( equalBox(boxSymbol('get-struct'), $thing) ) {
        printf('$%s->{%s}', stringify(second($tree)), stringify(third($tree)));

      } else {
        if ( equalBox(boxSymbol('new'), $thing) ) {
          printf('{}');

        } else {
          if ( equalBox(boxSymbol('passthrough'), $thing) ) {
            printf('%s', stringify(second($tree)));

          } else {
            if ( equalBox(boxSymbol('binop'), $thing) ) {
              printf('(');

              perlExpression(third($tree), $indent, $variables);

              printf(' %s ', stringify(second($tree)));

              perlExpression(fourth($tree), $indent, $variables);

              printf(')');

            } else {
              printf('%s(', stringify(perlFuncMap(car($tree), $variables)));

              perlRecurList(cdr($tree), $indent, $variables);

              printf(')');

            };

          };

        };

      };

    };

  } else {
    if ( equalString('string', boxType($tree)) ) {
      printf('\'%s\'', escapeSingleQuotes(stringify($tree)));

    } else {
      display(perlFuncMap($tree, $variables));

    };

  };

}


# Function perlRecurList from line 145

sub perlRecurList {
  my ($expr, $indent, $variables) = @_;
  
  if ( isEmpty($expr) ) {
    return;

  } else {
    perlExpression(car($expr), $indent, $variables);

    if ( isNil(cdr($expr)) ) {
      printf('');

    } else {
      printf(', ');

      perlRecurList(cdr($expr), $indent, $variables);

    };

  };

}


# Function perlStatement from line 155

sub perlStatement {
  my ($node, $indent, $variables) = @_;
  
  if ( equalBox(boxString('set'), first($node)) ) {
    perlSet($node, $indent, $variables);

  } else {
    if ( equalBox(boxString('set-struct'), first($node)) ) {
      perlSetStruct($node, $indent, $variables);

    } else {
      if ( equalBox(boxString('if'), first($node)) ) {
        perlIf($node, $indent, $variables);

      } else {
        if ( equalBox(boxString('return'), first($node)) ) {
          newLine($indent);

          printf('return');

          if ( greaterthan(listLength($node), 1) ) {
            printf(' ');

            perlExpression(cadr($node), $indent, $variables);

          } else {
            printf('');

          };

        } else {
          newLine($indent);

          perlExpression($node, $indent, $variables);

        };

      };

    };

  };

  printf(';\n');

}


# Function perlBody from line 180

sub perlBody {
  my ($tree, $indent, $variables) = @_;
  my $code = undef;

  if ( isEmpty($tree) ) {
    return;

  } else {
    $code = car($tree);

    perlStatement($code, $indent, $variables);

    perlBody(cdr($tree), $indent, $variables);

  };

}


# Function perlSet from line 189

sub perlSet {
  my ($node, $indent, $variables) = @_;
  
  newLine($indent);

  printf('%s = ', stringify(perlFuncMap(first(cdr($node)), $variables)));

  perlExpression(third($node), $indent, $variables);

}


# Function perlSetStruct from line 195

sub perlSetStruct {
  my ($node, $indent, $variables) = @_;
  
  newLine($indent);

  printf('%s->{%s} = ', stringify(perlFuncMap(second($node), $variables)), stringify(third($node)));

  perlExpression(fourth($node), $indent, $variables);

}


# Function perlIf from line 203

sub perlIf {
  my ($node, $indent, $variables) = @_;
  
  newLine($indent);

  printf('if ( ');

  perlExpression(second($node), 0, $variables);

  printf(' ) {');

  perlBody(cdr(third($node)), add1($indent), $variables);

  newLine($indent);

  printf('} else {');

  perlBody(cdr(fourth($node)), add1($indent), $variables);

  newLine($indent);

  printf('}');

}


# Function perlGetStruct from line 218

sub perlGetStruct {
  my ($node, $indent) = @_;
  
  newLine($indent);

  printf('$%s->{%s}', stringify(first($node)), stringify(second($node)));

}


# Function perlDeclarations from line 228

sub perlDeclarations {
  my ($decls, $indent, $variables) = @_;
  my $decl = undef;

  if ( isEmpty($decls) ) {
    return;

  } else {
    $decl = car($decls);

    printf('my $%s = ', stringify(second($decl)));

    perlExpression(third($decl), $indent, $variables);

    printf(';\n');

    perlDeclarations(cdr($decls), $indent, $variables);

  };

}


# Function perlFunction from line 239

sub perlFunction {
  my ($node) = @_;
  my $name = undef;
my $variables = undef;
my $args = undef;
my $decls = undef;

  $name = second($node);

  printf('\n\n# Function %s from line %s', stringify($name), stringify(getTag($name, boxString('line'))));

  newLine(0);

  if ( isNil($node) ) {
    return;

  } else {
    newLine(0);

    printf('sub %s {', stringify(second($node)));

    newLine(1);

    printf('my (');

    perlFunctionArgs(third($node));

    printf(') = @_;');

    newLine(1);

    $args = third($node);

    $decls = cdr(fourth($node));

    $variables = collectVariables($args, $decls);

    perlDeclarations($decls, 1, $variables);

    perlBody(cdr(fifth($node)), 1, $variables);

    printf('\n}\n');

  };

}


# Function perlForwardDeclaration from line 262

sub perlForwardDeclaration {
  my ($node) = @_;
  
  if ( isNil($node) ) {
    return;

  } else {
    printf('sub %s;', stringify(second($node)));

  };

}


# Function perlForwardDeclarations from line 269

sub perlForwardDeclarations {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return;

  } else {
    perlForwardDeclaration(car($tree));

    perlForwardDeclarations(cdr($tree));

  };

}


# Function perlFunctions from line 277

sub perlFunctions {
  my ($tree) = @_;
  
  if ( isEmpty($tree) ) {
    return;

  } else {
    perlFunction(car($tree));

    perlFunctions(cdr($tree));

  };

}


# Function perlIncludes from line 285

sub perlIncludes {
  my ($nodes) = @_;
  
  printf('use strict;\n');

  printf('use warnings;\n');

  printf('use v5.10;\n\n');

}


# Function perlTypeMap from line 292

sub perlTypeMap {
  my ($aSym) = @_;
  my $symMap = undef;

  $symMap = alistCons(boxSymbol('stringArray'), boxSymbol('array'), alistCons(boxSymbol('string'), boxSymbol('string'), undef));

  if ( truthy(assoc(stringify($aSym), $symMap)) ) {
    return cdr(assoc(stringify($aSym), $symMap));

  } else {
    return $aSym;

  };

}


# Function perlFuncMap from line 301

sub perlFuncMap {
  my ($aSym, $variables) = @_;
  my $symMap = undef;

  if ( equalString('symbol', boxType($aSym)) ) {
    if ( inList($aSym, $variables) ) {
      return boxSymbol(stringConcatenate(dollar(), stringify($aSym)));

    } else {
      $symMap = alistCons(boxSymbol('sub'), boxSymbol('subtract'), alistCons(boxSymbol('='), boxSymbol('equal'), alistCons(boxSymbol('sub-string'), boxSymbol('substr'), alistCons(boxSymbol('read-file'), boxSymbol('read_file'), alistCons(boxSymbol('write-file'), boxSymbol('write_file'), alistCons(boxSymbol('>'), boxSymbol('greaterthan'), alistCons(boxSymbol('string-length'), boxSymbol('length'), alistCons(boxSymbol('nil'), boxSymbol('undef'), undef))))))));

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


# Function perlCompile from line 322

sub perlCompile {
  my ($filename) = @_;
  my $tree = undef;
my $replace = undef;

  fprintf($stderr, 'Scanning file...%s\n', $filename);

  $tree = loadQuon($filename);

  fprintf($stderr, 'Building sexpr\n');

  $tree = loadIncludes($tree);

  $tree = macrowalk($tree);

  $replace = cons(boxSymbol('fprintf'), cons(boxSymbol('stderr'), undef));

  $tree = macrolist($tree, stringConcatenate('q', 'log'), $replace);

  fprintf($stderr, 'Printing program\n');

  perlIncludes(cdr(first($tree)));

  perlGlobalVariables();

  perlFunctions(cdr(third($tree)));

  perlMainEntry();

  printf('\n');

}


# Function readSexpr from line 4

sub readSexpr {
  my ($aStr, $filename) = @_;
  my $tokens = undef;
my $as = undef;

  $tokens = emptyList();

  $tokens = filterTokens(filterVoid(scan($aStr, 0, 1, 0, 0, $filename)));

  $as = sexprTree($tokens);

  return car($as);

}


# Function sexprTree from line 11

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
        return setTag(boxString('line'), getTagFail($b, boxString('line'), boxInt(-1)), cons($b, sexprTree(cdr($l))));

      };

    };

  };

}


# Function loadQuon from line 29

sub loadQuon {
  my ($filename) = @_;
  my $programStr = '';
my $tree = undef;

  $programStr = read_file($filename);

  $tree = readSexpr($programStr, $filename);

  return $tree;

}


# Function getIncludes from line 38

sub getIncludes {
  my ($program) = @_;
  
  return cdr(first($program));

}


# Function getTypes from line 42

sub getTypes {
  my ($program) = @_;
  
  return cdr(second($program));

}


# Function getFunctions from line 46

sub getFunctions {
  my ($program) = @_;
  
  return cdr(third($program));

}


# Function insertInclude from line 50

sub insertInclude {
  my ($tree, $extra) = @_;
  my $newProg = undef;
my $includes = undef;
my $types = undef;
my $functions = undef;
my $boxedExtra = undef;
my $newIncludes = undef;

  if ( isNil($tree) ) {
    return undef;

  } else {
    $includes = getIncludes($tree);

    $types = getTypes($tree);

    $functions = getFunctions($tree);

    $boxedExtra = cons(boxSymbol($extra), undef);

    $newIncludes = cons($boxedExtra, $includes);

    $newProg = buildProg($newIncludes, $types, $functions);

    return $newProg;

  };

}


# Function loadIncludes from line 72

sub loadIncludes {
  my ($tree) = @_;
  my $newProg = undef;
my $includeFile = '';
my $functionsCombined = undef;
my $typesCombined = undef;
my $includeTree = undef;
my $contents = '';

  if ( greaterthan(listLength(getIncludes($tree)), 0) ) {
    $includeFile = stringify(first(getIncludes($tree)));

    $contents = read_file($includeFile);

    if ( equalString($contents, '') ) {
      fprintf($stderr, 'Could not read include file: ');

      fprintf($stderr, $includeFile);

      return undef;

    } else {
      $includeTree = readSexpr($contents, $includeFile);

      if ( isNil($includeTree) ) {
        fprintf($stderr, 'Could not parse include file: ');

        fprintf($stderr, $includeFile);

        return undef;

      } else {
        $functionsCombined = concatLists(getFunctions($includeTree), getFunctions($tree));

        $typesCombined = concatLists(getTypes($includeTree), getTypes($tree));

        $newProg = buildProg(cdr(getIncludes($tree)), $typesCombined, $functionsCombined);

        return loadIncludes($newProg);

      };

    };

  } else {
    return $tree;

  };

}


# Function buildProg from line 104

sub buildProg {
  my ($includes, $types, $functions) = @_;
  my $program = undef;

  $includes = cons(boxSymbol('includes'), $includes);

  $types = cons(boxSymbol('types'), $types);

  $functions = cons(boxSymbol('functions'), $functions);

  $program = cons($includes, cons($types, cons($functions, undef)));

  return $program;

}


# Function car from line 9

sub car {
  my ($l) = @_;
  
  if ( isNil($l) ) {
    printf('Cannot call car on empty list!\n');

    panic('Cannot call car on empty list!\n');

    return undef;

  } else {
    assertType('list', $l, 18, 'q/lists.qon');

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
    printf('Attempt to cdr an empty list!!!!\n');

    panic('Attempt to cdr an empty list!!!!\n');

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

  $p->{typ} = 'list';

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
    return equalString('list', $b->{typ});

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

  assertType('list', $l, 96, 'q/lists.qon');

  if ( isEmpty($l) ) {
    return boxBool($false);

  } else {
    $elem = car($l);

    assertType('list', $elem, 102, 'q/lists.qon');

    if ( isEmpty($elem) ) {
      return assoc($searchTerm, cdr($l));

    } else {
      if ( $false ) {
        printf('Comparing %s and %s\n', $searchTerm, stringify(car($elem)));

      } else {
        printf('');

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
  
  if ( equalString('string', $aType) ) {
    return 'boxString';

  } else {
    if ( equalString('symbol', $aType) ) {
      return 'boxSymbol';

    } else {
      if ( equalString('bool', $aType) ) {
        return 'boxBool';

      } else {
        if ( equalString('int', $aType) ) {
          return 'boxInt';

        } else {
          if ( equalString('float', $aType) ) {
            return 'boxFloat';

          } else {
            panic('Invalid type');

          };

        };

      };

    };

  };

  return '';

}


# Function mlistLiteral from line 130

sub mlistLiteral {
  my ($b) = @_;
  
  if ( isNil($b) ) {
    return undef;

  } else {
    if ( equalString('string', boxType($b)) ) {
      return $b;

    } else {
      if ( equalString('bool', boxType($b)) ) {
        return $b;

      } else {
        if ( equalString('int', boxType($b)) ) {
          return $b;

        } else {
          if ( equalString('symbol', boxType($b)) ) {
            return boxString(unBoxSymbol($b));

          } else {
            return boxString(stringConcatenate('Unsupported type in mlistLiteral: ', boxType($b)));

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
    return cons(boxSymbol('nil'), undef);

  } else {
    if ( isEmpty($l) ) {
      return undef;

    } else {
      $elem = first($l);

      $newlist = cons(boxString(chooseBox($elem->{typ})), cons(mlistLiteral(first($l)), $newlist));

      $ret = cons(cons(boxSymbol('cons'), cons($newlist, doMultiList(cdr($l)))), undef);

      return $ret;

    };

  };

}


# Function isInt from line 176

sub isInt {
  my ($val) = @_;
  my $firstLetter = substr($val, 0, 1);

  if ( equalString('-', $firstLetter) ) {
    return $true;

  } else {
    if ( equalString('0', $firstLetter) ) {
      return $true;

    } else {
      if ( equalString('1', $firstLetter) ) {
        return $true;

      } else {
        if ( equalString('2', $firstLetter) ) {
          return $true;

        } else {
          if ( equalString('3', $firstLetter) ) {
            return $true;

          } else {
            if ( equalString('4', $firstLetter) ) {
              return $true;

            } else {
              if ( equalString('5', $firstLetter) ) {
                return $true;

              } else {
                if ( equalString('6', $firstLetter) ) {
                  return $true;

                } else {
                  if ( equalString('7', $firstLetter) ) {
                    return $true;

                  } else {
                    if ( equalString('8', $firstLetter) ) {
                      return $true;

                    } else {
                      if ( equalString('9', $firstLetter) ) {
                        return $true;

                      } else {
                        return $false;

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


# Function id from line 204

sub id {
  my ($b) = @_;
  
  return $b;

}


# Function chooseBoxInterp from line 207

sub chooseBoxInterp {
  my ($b) = @_;
  my $val = stringify($b);
my $firstLetter = substr($val, 0, 1);

  if ( equalString('string', boxType($b)) ) {
    return 'boxString';

  } else {
    if ( equalString('\"', $firstLetter) ) {
      return 'boxString';

    } else {
      if ( equalString('true', $val) ) {
        return 'boxBool';

      } else {
        if ( equalString('false', $val) ) {
          return 'boxBool';

        } else {
          if ( isInt($val) ) {
            return 'boxInt';

          } else {
            if ( isInt($val) ) {
              return 'boxFloat';

            } else {
              return 'id';

            };

          };

        };

      };

    };

  };

}


# Function doInterpolatedList from line 232

sub doInterpolatedList {
  my ($l) = @_;
  my $newlist = undef;
my $ret = undef;
my $elem = undef;

  if ( isNil($l) ) {
    return cons(boxSymbol('nil'), undef);

  } else {
    if ( isEmpty($l) ) {
      return undef;

    } else {
      $elem = first($l);

      $newlist = cons(boxString(chooseBoxInterp($elem)), cons(first($l), $newlist));

      $ret = cons(cons(boxSymbol('cons'), cons($newlist, doInterpolatedList(cdr($l)))), undef);

      return $ret;

    };

  };

}


# Function doStringList from line 256

sub doStringList {
  my ($l) = @_;
  my $newlist = undef;
my $ret = undef;

  if ( isNil($l) ) {
    return cons(boxSymbol('nil'), undef);

  } else {
    $newlist = cons(boxSymbol('boxString'), cons(first($l), $newlist));

    $ret = cons(cons(boxSymbol('cons'), cons($newlist, doStringList(cdr($l)))), undef);

    return $ret;

  };

}


# Function doSymbolList from line 273

sub doSymbolList {
  my ($l) = @_;
  my $newlist = undef;
my $ret = undef;

  if ( isNil($l) ) {
    return cons(boxSymbol('nil'), undef);

  } else {
    $newlist = cons(boxSymbol('boxSymbol'), cons(first($l), $newlist));

    $ret = cons(cons(boxSymbol('cons'), cons($newlist, doSymbolList(cdr($l)))), undef);

    return $ret;

  };

}


# Function doBoxList from line 291

sub doBoxList {
  my ($l) = @_;
  
  if ( isNil($l) ) {
    return cons(boxSymbol('nil'), undef);

  } else {
    return cons(cons(boxSymbol('cons'), cons(first($l), doBoxList(cdr($l)))), undef);

  };

}


# Function concatLists from line 310

sub concatLists {
  my ($seq1, $seq2) = @_;
  
  if ( isNil($seq1) ) {
    return $seq2;

  } else {
    return cons(car($seq1), concatLists(cdr($seq1), $seq2));

  };

}


# Function alistKeys from line 316

sub alistKeys {
  my ($alist) = @_;
  
  if ( isNil($alist) ) {
    return undef;

  } else {
    return cons(car(car($alist)), alistKeys(cdr($alist)));

  };

}


# Function display from line 322

sub display {
  my ($l) = @_;
  
  if ( isEmpty($l) ) {
    printf('nil ');

    return;

  } else {
    if ( isList($l) ) {
      printf('[');

      displayList($l, 0, $true);

      printf(']');

    } else {
      displayList($l, 0, $true);

    };

  };

}


# Function displayList from line 331

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
          printf(' ');

        };

        $val = car($l);

        if ( isList($val) ) {
          newLine($indent);

          printf('%s', openBrace());

          displayList(car($l), add1($indent), $true);

          printf('%s', closeBrace());

          displayList(cdr($l), $indent, $false);

        } else {
          if ( equalString('string', $val->{typ}) ) {
            printf('\"%s\"', unBoxString($val));

          } else {
            printf('%s', stringify($val));

          };

          displayList(cdr($l), $indent, $false);

        };

      };

    } else {
      if ( equalString('string', $l->{typ}) ) {
        printf('\"%s\"', unBoxString($l));

      } else {
        printf('%s', stringify($l));

      };

    };

  };

}


# Function StringListJoinRec from line 362

sub StringListJoinRec {
  my ($l, $sep) = @_;
  my $val = undef;

  if ( isEmpty($l) ) {
    return '';

  } else {
    if ( isList($l) ) {
      if ( isEmpty($l) ) {
        return '';

      } else {
        if ( equal(listLength($l), 1) ) {
          return stringify(car($l));

        } else {
          return stringConcatenate(stringify(car($l)), stringConcatenate($sep, StringListJoinRec(cdr($l), $sep)));

        };

      };

    } else {
      return '';

    };

  };

}


# Function StringListJoin from line 385

sub StringListJoin {
  my ($l, $sep) = @_;
  my $val = undef;

  if ( greaterthan(listLength($l), 1) ) {
    return stringConcatenate(stringify(car($l)), stringConcatenate($sep, StringListJoinRec(cdr($l), $sep)));

  } else {
    return stringify(car($l));

  };

}


# Function ListToBoxString from line 395

sub ListToBoxString {
  my ($l, $indent) = @_;
  
  return boxString(ListToString($l, $indent, $true, $false));

}


# Function ListToString from line 400

sub ListToString {
  my ($l, $indent, $first, $withNewLines) = @_;
  my $val = undef;

  if ( isEmpty($l) ) {
    return '';

  } else {
    if ( isList($l) ) {
      if ( isEmpty($l) ) {
        return '';

      } else {
        $val = car($l);

        if ( isList($val) ) {
          return StringListJoin(cons(boxString(stringify(tern($withNewLines, boxString('\n'), boxString(stringIndent($indent))))), cons(boxString(openBrace()), cons(boxString(' '), cons(boxString(ListToString(car($l), add1($indent), $true, $withNewLines)), cons(boxString(closeBrace()), cons(boxString(' '), cons(boxString(ListToString(cdr($l), $indent, $false, $withNewLines)), undef))))))), '');

        } else {
          return stringConcatenate(stringify($val), ListToString(cdr($l), $indent, $false, $withNewLines));

        };

      };

    } else {
      return stringify($l);

    };

  };

}


# Function listReverse from line 440

sub listReverse {
  my ($l) = @_;
  
  if ( isNil($l) ) {
    return undef;

  } else {
    return cons(car($l), listReverse(cdr($l)));

  };

}


# Function inList from line 446

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


# Function equalList from line 456

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


# Function reverseRec from line 479

sub reverseRec {
  my ($oldL, $newL) = @_;
  
  if ( isEmpty($oldL) ) {
    return $newL;

  } else {
    return reverseRec(cdr($oldL), cons(first($oldL), $newL));

  };

}


# Function reverseList from line 486

sub reverseList {
  my ($l) = @_;
  
  return reverseRec($l, undef);

}


# Function flatten from line 491

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


# Function macrowalk from line 5

sub macrowalk {
  my ($l) = @_;
  
  if ( isEmpty($l) ) {
    return undef;

  } else {
    if ( isList($l) ) {
      if ( equalString(stringConcatenate('box', 'List'), stringify(car($l))) ) {
        return car(doBoxList(cdr($l)));

      } else {
      };

      if ( equalString(stringConcatenate('string', 'List'), stringify(car($l))) ) {
        return car(doStringList(cdr($l)));

      } else {
      };

      if ( equalString(stringConcatenate('symbol', 'List'), stringify(car($l))) ) {
        return car(doSymbolList(cdr($l)));

      } else {
      };

      if ( equalString(stringConcatenate('multi', 'List'), stringify(car($l))) ) {
        return car(doMultiList(cdr($l)));

      } else {
      };

      if ( equalString(stringConcatenate('makeL', 'ist'), stringify(car($l))) ) {
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


# Function macrolist from line 82

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

    if ( equalString('void', $token->{typ}) ) {
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

    if ( equalString(boxType($token), 'symbol') ) {
      if ( equalString('__LINE__', stringify($token)) ) {
        return cons(getTagFail($token, boxString('line'), boxInt(-1)), filterTokens(cdr($l)));

      } else {
        if ( equalString('__COLUMN__', stringify($token)) ) {
          return cons(getTagFail($token, boxString('column'), boxInt(-1)), filterTokens(cdr($l)));

        } else {
          if ( equalString('__FILE__', stringify($token)) ) {
            return cons(getTagFail($token, boxString('filename'), boxString('Unknown file')), filterTokens(cdr($l)));

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

    $token->{tag} = alistCons(boxString('filename'), boxString($filename), alistCons(boxString('column'), boxInt($column), alistCons(boxString('line'), boxInt($line), alistCons(boxString('totalCharPos'), boxInt($start), undef))));

    return $token;

  } else {
    return newVoid();

  };

}


# Function readString from line 69

sub readString {
  my ($prog, $start, $len) = @_;
  my $token = '';

  $token = substr($prog, sub1(add($start, $len)), 1);

  if ( equalString('\"', $token) ) {
    return substr($prog, $start, sub1($len));

  } else {
    if ( equalString('\\', $token) ) {
      return readString($prog, $start, add(2, $len));

    } else {
      return readString($prog, $start, add1($len));

    };

  };

}


# Function readComment from line 80

sub readComment {
  my ($prog, $start, $len) = @_;
  my $token = '';

  if ( greaterthan(add($start, $len), length($prog)) ) {
    return '';

  } else {
    $token = substr($prog, sub1(add($start, $len)), 1);

    if ( isLineBreak($token) ) {
      return substr($prog, $start, sub1($len));

    } else {
      return readComment($prog, $start, add1($len));

    };

  };

}


# Function isWhiteSpace from line 91

sub isWhiteSpace {
  my ($s) = @_;
  
  if ( equalString(' ', $s) ) {
    return $true;

  } else {
    if ( equalString('\t', $s) ) {
      return $true;

    } else {
      if ( equalString('\n', $s) ) {
        return $true;

      } else {
        if ( equalString('\r', $s) ) {
          return $true;

        } else {
          return $false;

        };

      };

    };

  };

}


# Function isLineBreak from line 108

sub isLineBreak {
  my ($s) = @_;
  
  if ( equalString('\n', $s) ) {
    return $true;

  } else {
    if ( equalString('\r', $s) ) {
      return $true;

    } else {
      return $false;

    };

  };

}


# Function incForNewLine from line 115

sub incForNewLine {
  my ($token, $val) = @_;
  
  if ( equalString('\n', stringify($token)) ) {
    return add1($val);

  } else {
    return $val;

  };

}


# Function annotateReadPosition from line 123

sub annotateReadPosition {
  my ($filename, $linecount, $column, $start, $newBox) = @_;
  
  return setTag(boxString('filename'), boxString($filename), setTag(boxString('column'), boxInt($column), setTag(boxString('line'), boxInt($linecount), setTag(boxString('totalCharPos'), boxInt($start), $newBox))));

}


# Function scan from line 135

sub scan {
  my ($prog, $start, $len, $linecount, $column, $filename) = @_;
  my $token = undef;
my $newString = '';
my $newBox = undef;

  if ( greaterthan(length($prog), subtract($start, subtract(0, $len))) ) {
    $token = boxSymbol(substr($prog, sub1(add($start, $len)), 1));

    $token->{tag} = alistCons(boxString('totalCharPos'), boxInt($start), undef);

    if ( isOpenBrace($token) ) {
      return cons(finish_token($prog, $start, sub1($len), $linecount, $column, $filename), cons(boxSymbol(openBrace()), scan($prog, add1($start), 1, $linecount, add1($column), $filename)));

    } else {
      if ( isCloseBrace($token) ) {
        return cons(finish_token($prog, $start, sub1($len), $linecount, $column, $filename), cons(annotateReadPosition($filename, $linecount, $column, $start, boxSymbol(closeBrace())), scan($prog, add($start, $len), 1, $linecount, add1($column), $filename)));

      } else {
        if ( isWhiteSpace(stringify($token)) ) {
          return cons(finish_token($prog, $start, sub1($len), $linecount, $column, $filename), scan($prog, add($start, $len), 1, incForNewLine($token, $linecount), 0, $filename));

        } else {
          if ( equalBox(boxSymbol(';'), $token) ) {
            return scan($prog, add($start, add1(add1(length(readComment($prog, add1($start), $len))))), 1, add1($linecount), 0, $filename);

          } else {
            if ( equalBox(boxSymbol('\"'), $token) ) {
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


# Function isOpenBrace from line 175

sub isOpenBrace {
  my ($b) = @_;
  
  if ( equalBox(boxSymbol(openBrace()), $b) ) {
    return $true;

  } else {
    if ( equalBox(boxSymbol('['), $b) ) {
      return $true;

    } else {
      return $false;

    };

  };

}


# Function isCloseBrace from line 184

sub isCloseBrace {
  my ($b) = @_;
  
  if ( equalBox(boxSymbol(closeBrace()), $b) ) {
    return $true;

  } else {
    if ( equalBox(boxSymbol(']'), $b) ) {
      return $true;

    } else {
      return $false;

    };

  };

}


# Function skipList from line 197

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


# Function makeNode from line 219

sub makeNode {
  my ($name, $subname, $code, $children) = @_;
  
  return cons(boxSymbol('node'), alistCons(boxSymbol('line'), getTagFail($code, boxString('line'), boxInt(-1)), cons(cons(boxSymbol('name'), boxString($name)), cons(cons(boxSymbol('subname'), boxString($subname)), cons(cons(boxSymbol('code'), $code), alistCons(boxSymbol('children'), $children, emptyList()))))));

}


# Function addToNode from line 235

sub addToNode {
  my ($key, $val, $node) = @_;
  
  return cons(boxSymbol('node'), alistCons($key, $val, cdr($node)));

}


# Function makeStatementNode from line 240

sub makeStatementNode {
  my ($name, $subname, $code, $children, $functionName) = @_;
  
  return addToNode(boxSymbol('functionName'), $functionName, makeNode($name, $subname, $code, $children));

}


# Function declarationsof from line 245

sub declarationsof {
  my ($ass) = @_;
  
  return cdr(assocPanic('declarations', cdr($ass), 'Cons list has no declarations key'));

}


# Function codeof from line 248

sub codeof {
  my ($ass) = @_;
  
  return cdr(assocPanic('code', cdr($ass), 'Given cons list does not contain a code key'));

}


# Function functionNameof from line 251

sub functionNameof {
  my ($ass) = @_;
  
  return cdr(assoc('functionName', cdr($ass)));

}


# Function nodeof from line 254

sub nodeof {
  my ($ass) = @_;
  
  if ( equalBox(boxBool($false), assoc('node', cdr($ass))) ) {
    printf('Given list does not contain nodes');

    return boxBool($false);

  } else {
    return cdr(assoc('node', cdr($ass)));

  };

}


# Function lineof from line 262

sub lineof {
  my ($ass) = @_;
  
  return cdr(assocFail('line', cdr($ass), boxInt(-1)));

}


# Function subnameof from line 267

sub subnameof {
  my ($ass) = @_;
  
  return cdr(assoc('subname', cdr($ass)));

}


# Function nameof from line 270

sub nameof {
  my ($ass) = @_;
  
  return cdr(assoc('name', cdr($ass)));

}


# Function childrenof from line 273

sub childrenof {
  my ($ass) = @_;
  
  return cdr(assoc('children', cdr($ass)));

}


# Function isNode from line 277

sub isNode {
  my ($val) = @_;
  
  if ( isEmpty($val) ) {
    return $false;

  } else {
    if ( isList($val) ) {
      if ( equalBox(boxSymbol('node'), car($val)) ) {
        return $true;

      } else {
        return $false;

      };

    } else {
      return $false;

    };

  };

}


# Function isLeaf from line 293

sub isLeaf {
  my ($n) = @_;
  
  return equalBox(boxString('leaf'), subnameof($n));

}


# Function noStackTrace from line 299

sub noStackTrace {
  my () = @_;
  
  return cons(boxString('boxType'), cons(boxString('stringify'), cons(boxString('isEmpty'), cons(boxString('unBoxString'), cons(boxString('isList'), cons(boxString('unBoxBool'), cons(boxString('unBoxSymbol'), cons(boxString('equalBox'), cons(boxString('assoc'), cons(boxString('inList'), cons(boxString('unBoxInt'), cons(boxString('listLength'), cons(boxString('stroff'), cons(boxString('troff'), cons(boxString('tron'), cons(boxString('stron'), cons(boxString('car'), cons(boxString('cdr'), cons(boxString('cons'), cons(boxString('stackTracePush'), cons(boxString('stackTracePop'), cons(boxString('assertType'), cons(boxString('boxString'), cons(boxString('boxSymbol'), cons(boxString('boxInt'), undef)))))))))))))))))))))))));

}


# Function treeCompile from line 331

sub treeCompile {
  my ($filename) = @_;
  my $programStr = '';
my $tree = undef;

  $programStr = read_file($filename);

  if ( equalString($programStr, '') ) {
    printf('Error: Could not read file \'%s\'\n', $filename);

    return undef;

  } else {
    $tree = readSexpr($programStr, $filename);

    return $tree;

  };

}


# Function mergeIncludes from line 346

sub mergeIncludes {
  my ($program) = @_;
  
  return merge_recur(childrenof(cdr(cdr(assocPanic('includes', $program, 'Program lacks include section')))), $program);

}


# Function merge_recur from line 353

sub merge_recur {
  my ($incs, $program) = @_;
  
  if ( greaterthan(listLength($incs), 0) ) {
    return mergeInclude(car($incs), merge_recur(cdr($incs), $program));

  } else {
    return $program;

  };

}


# Function mergeInclude from line 361

sub mergeInclude {
  my ($inc, $program) = @_;
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

  if ( isNil($inc) ) {
    return $program;

  } else {
    $functions = childrenof(cdr(assocPanic('functions', $inc, 'Included file has no functions section')));

    $oldfunctionsnode = cdr(assocPanic('functions', $program, 'Current module has no functions section'));

    $oldfunctions = childrenof($oldfunctionsnode);

    $newfunctions = concatLists($functions, $oldfunctions);

    $newFunctionNode = cons(boxSymbol('node'), alistCons(boxSymbol('children'), $newfunctions, cdr($oldfunctionsnode)));

    $types = childrenof(cdr(assocPanic('types', $inc, 'Included file has no types section')));

    $oldtypesnode = cdr(assocPanic('types', $program, 'Current module has no types section'));

    $oldtypes = childrenof($oldtypesnode);

    $newtypes = concatLists($types, $oldtypes);

    $newTypeNode = cons(boxSymbol('node'), alistCons(boxSymbol('children'), $newtypes, cdr($oldtypesnode)));

    $newProgram = alistCons(boxString('functions'), $newFunctionNode, alistCons(boxString('types'), $newTypeNode, alistCons(boxString('includes'), cons(boxSymbol('includes'), undef), $newProgram)));

    return $newProgram;

  };

}


# Function add from line 19

sub add {
  my ($a, $b) = @_;
  
  return subtract($a, subtract(0, $b));

}


# Function addf from line 20

sub addf {
  my ($a, $b) = @_;
  
  return subf($a, subf(0, $b));

}


# Function sub1 from line 21

sub sub1 {
  my ($a) = @_;
  
  return subtract($a, 1);

}


# Function add1 from line 22

sub add1 {
  my ($a) = @_;
  
  return add($a, 1);

}


# Function clone from line 24

sub clone {
  my ($b) = @_;
  my $newb = undef;

  $newb = makeBox();

  if ( isNil($newb) ) {
    printf('clone: newb is nil\n');

    panic('clone: newb is nil');

    return $newb;

  } else {
    $newb->{typ} = $b->{typ};

    $newb->{tag} = $b->{tag};

    $newb->{lis} = $b->{lis};

    $newb->{str} = $b->{str};

    $newb->{i} = $b->{i};

    $newb->{lengt} = $b->{lengt};

    return $newb;

  };

}


# Function tern from line 42

sub tern {
  my ($cond, $tr, $fal) = @_;
  
  if ( $cond ) {
    return $tr;

  } else {
    return $fal;

  };

}


# Function ternString from line 46

sub ternString {
  my ($cond, $tr, $fal) = @_;
  
  if ( $cond ) {
    return $tr;

  } else {
    return $fal;

  };

}


# Function ternList from line 50

sub ternList {
  my ($cond, $tr, $fal) = @_;
  
  if ( $cond ) {
    return $tr;

  } else {
    return $fal;

  };

}


# Function newVoid from line 55

sub newVoid {
  my () = @_;
  my $newb = undef;

  $newb = makeBox();

  $newb->{voi} = $true;

  $newb->{typ} = 'void';

  return $newb;

}


# Function stackDump from line 64

sub stackDump {
  my () = @_;
  
  printf('');

}


# Function nop from line 69

sub nop {
  my () = @_;
  
  printf('');

}


# Function equalBox from line 72

sub equalBox {
  my ($a, $b) = @_;
  
  if ( isList($b) ) {
    return $false;

  } else {
    if ( equalString('string', boxType($a)) ) {
      return equalString(unBoxString($a), stringify($b));

    } else {
      if ( equalString('bool', boxType($a)) ) {
        return andBool(unBoxBool($a), unBoxBool($b));

      } else {
        if ( equalString('symbol', boxType($a)) ) {
          if ( equalString('symbol', boxType($b)) ) {
            return equalString(unBoxSymbol($a), unBoxSymbol($b));

          } else {
            return $false;

          };

        } else {
          if ( equalString('int', boxType($a)) ) {
            return equal(unBoxInt($a), unBoxInt($b));

          } else {
            return $false;

          };

        };

      };

    };

  };

}


# Function openBrace from line 93

sub openBrace {
  my () = @_;
  
  return '(';

}


# Function closeBrace from line 94

sub closeBrace {
  my () = @_;
  
  return ')';

}


# Function boxType from line 99

sub boxType {
  my ($b) = @_;
  
  return $b->{typ};

}


# Function makeBox from line 103

sub makeBox {
  my () = @_;
  my $b = undef;

  $b = {};

  if ( isNil($b) ) {
    panic('failed to create box!');

  } else {
  };

  $b->{tag} = undef;

  $b->{car} = undef;

  $b->{cdr} = undef;

  $b->{lis} = undef;

  $b->{typ} = 'None - error!';

  return $b;

}


# Function makePair from line 117

sub makePair {
  my () = @_;
  
  return makeBox();

}


# Function boxString from line 122

sub boxString {
  my ($s) = @_;
  my $b = undef;

  $b = makeBox();

  $b->{str} = $s;

  $b->{lengt} = length($s);

  $b->{typ} = 'string';

  return $b;

}


# Function boxSymbol from line 132

sub boxSymbol {
  my ($s) = @_;
  my $b = undef;

  $b = boxString($s);

  $b->{typ} = 'symbol';

  return $b;

}


# Function boxBool from line 141

sub boxBool {
  my ($boo) = @_;
  my $b = undef;

  $b = makeBox();

  $b->{boo} = $boo;

  $b->{typ} = 'bool';

  return $b;

}


# Function boxInt from line 150

sub boxInt {
  my ($val) = @_;
  my $b = undef;

  $b = makeBox();

  $b->{i} = $val;

  $b->{typ} = 'int';

  return $b;

}


# Function assertType from line 159

sub assertType {
  my ($atype, $abox, $line, $file) = @_;
  
  if ( isNil($abox) ) {
    if ( equalString($atype, 'nil') ) {
      return;

    } else {
      return;

    };

  } else {
    if ( equalString($atype, boxType($abox)) ) {
      return;

    } else {
      printf('Assertion failure at line %d, in file %s: provided value is not a \'%s\'!  It was actually \'%s\'. Contents:', $line, $file, $atype, boxType($abox));

      display($abox);

      printf('\n');

      display(cons(boxString('Token may have been read from '), cons(boxString(stringify(getTagFail($abox, boxString('filename'), boxString('source file not found')))), cons(boxString(':'), cons(boxString(stringify(getTagFail($abox, boxString('line'), boxString('source line not found')))), undef)))));

      StackTracePrint();

      panic('Invalid type!');

    };

  };

}


# Function unBoxString from line 176

sub unBoxString {
  my ($b) = @_;
  
  assertType('string', $b, 177, 'q/base.qon');

  return $b->{str};

}


# Function unBoxSymbol from line 179

sub unBoxSymbol {
  my ($b) = @_;
  
  return $b->{str};

}


# Function unBoxBool from line 180

sub unBoxBool {
  my ($b) = @_;
  
  return $b->{boo};

}


# Function unBoxInt from line 181

sub unBoxInt {
  my ($b) = @_;
  
  return $b->{i};

}


# Function stringify_rec from line 183

sub stringify_rec {
  my ($b) = @_;
  
  if ( isNil($b) ) {
    return '';

  } else {
    return stringConcatenate(stringify(car($b)), stringConcatenate(' ', stringify_rec(cdr($b))));

  };

}


# Function stringify from line 192

sub stringify {
  my ($b) = @_;
  
  if ( isNil($b) ) {
    return '()';

  } else {
    if ( equalString('string', boxType($b)) ) {
      return unBoxString($b);

    } else {
      if ( equalString('bool', boxType($b)) ) {
        if ( unBoxBool($b) ) {
          return 'true';

        } else {
          return 'false';

        };

      } else {
        if ( equalString('int', boxType($b)) ) {
          return intToString(unBoxInt($b));

        } else {
          if ( equalString('symbol', boxType($b)) ) {
            return unBoxSymbol($b);

          } else {
            if ( equalString('list', boxType($b)) ) {
              return stringConcatenate('(', stringConcatenate(stringify(car($b)), stringConcatenate(' ', stringConcatenate(stringify_rec(cdr($b)), ')'))));

            } else {
              return stringConcatenate('Unsupported type in stringify: ', boxType($b));

            };

          };

        };

      };

    };

  };

}


# Function hasTag from line 227

sub hasTag {
  my ($aBox, $key) = @_;
  
  if ( isNil($aBox) ) {
    return $false;

  } else {
    return isNotFalse(assoc(stringify($key), $aBox->{tag}));

  };

}


# Function getTag from line 234

sub getTag {
  my ($aBox, $key) = @_;
  
  if ( $false ) {
    printf('Getting %s from: ', stringify($key));

    display(alistKeys($aBox->{tag}));

    printf('\n');

  } else {
    printf('');

  };

  return cdr(assoc(stringify($key), $aBox->{tag}));

}


# Function getTagFail from line 246

sub getTagFail {
  my ($aBox, $key, $onFail) = @_;
  
  if ( hasTag($aBox, $key) ) {
    return getTag($aBox, $key);

  } else {
    return $onFail;

  };

}


# Function assocExists from line 256

sub assocExists {
  my ($key, $aBox) = @_;
  
  if ( isNil($aBox) ) {
    return $false;

  } else {
    return isNotFalse(assoc($key, $aBox));

  };

}


# Function assocFail from line 264

sub assocFail {
  my ($key, $aBox, $onFail) = @_;
  
  if ( assocExists($key, $aBox) ) {
    return assoc($key, $aBox);

  } else {
    return cons(boxString($key), $onFail);

  };

}


# Function assocPanic from line 271

sub assocPanic {
  my ($key, $aBox, $onFail) = @_;
  
  if ( assocExists($key, $aBox) ) {
    return assoc($key, $aBox);

  } else {
    panic($onFail);

  };

  panic('Inconceivable');

  return undef;

}


# Function setTag from line 282

sub setTag {
  my ($key, $val, $aStruct) = @_;
  
  $aStruct->{tag} = alistCons($key, $val, $aStruct->{tag});

  return $aStruct;

}


# Function locPanic from line 288

sub locPanic {
  my ($file, $line, $message) = @_;
  
  printf('%s %s:%s\n', $file, $line, $message);

  panic($message);

}


# Function truthy from line 294

sub truthy {
  my ($aVal) = @_;
  
  return isNotFalse($aVal);

}


# Function isNotFalse from line 299

sub isNotFalse {
  my ($aVal) = @_;
  
  if ( equalString(boxType($aVal), 'bool') ) {
    if ( unBoxBool($aVal) ) {
      return $true;

    } else {
      return $false;

    };

  } else {
    return $true;

  };

}


# Function toStr from line 306

sub toStr {
  my ($thing) = @_;
  
  return boxString(stringify($thing));

}


# Function listLast from line 310

sub listLast {
  my ($alist) = @_;
  
  if ( isEmpty(cdr($alist)) ) {
    return car($alist);

  } else {
    return listLast(cdr($alist));

  };

}


# Function newLine from line 317

sub newLine {
  my ($indent) = @_;
  
  printf('\n');

  printIndent($indent);

}


# Function printIndent from line 321

sub printIndent {
  my ($ii) = @_;
  
  if ( greaterthan($ii, 0) ) {
    printf('  ');

    printIndent(sub1($ii));

  } else {
    return;

  };

}


# Function stringIndent from line 328

sub stringIndent {
  my ($ii) = @_;
  
  if ( greaterthan($ii, 0) ) {
    return stringConcatenate('  ', stringIndent(sub1($ii)));

  } else {
    return '';

  };

}


# Function listIndent from line 334

sub listIndent {
  my ($ii) = @_;
  
  return cons(id(boxString(stringIndent($ii))), undef);

}


# Function listNewLine from line 340

sub listNewLine {
  my ($ii) = @_;
  
  return cons(id(boxString(stringConcatenate('\n', stringIndent($ii)))), undef);

}


# Function argList from line 346

sub argList {
  my ($count, $pos, $args) = @_;
  
  if ( greaterthan($count, $pos) ) {
    return cons(boxString(getStringArray($pos, $args)), argList($count, add1($pos), $args));

  } else {
    return undef;

  };

}


# Function tron from line 356

sub tron {
  my () = @_;
  
  $globalTrace = $true;

}


# Function troff from line 357

sub troff {
  my () = @_;
  
  $globalTrace = $false;

}


# Function stron from line 358

sub stron {
  my () = @_;
  
  $globalStepTrace = $true;

}


# Function stroff from line 359

sub stroff {
  my () = @_;
  
  $globalStepTrace = $false;

}


# Function StackTraceMove from line 363

sub StackTraceMove {
  my ($direction, $filename, $fname, $line) = @_;
  
  if ( equalString($direction, 'in') ) {
    $globalStackTrace = cons(cons(boxString($filename), cons(boxString($line), cons(boxString($fname), undef))), $globalStackTrace);

  } else {
    $globalStackTrace = cdr($globalStackTrace);

  };

}


# Function StackTracePrint from line 371

sub StackTracePrint {
  my () = @_;
  
  printf('Stack trace:\n');

  if ( isNil($globalStackTrace) ) {
    printf('  <empty>\n');

  } else {
    StackTracePrintHelper($globalStackTrace);

  };

}


# Function StackTracePrintHelper from line 379

sub StackTracePrintHelper {
  my ($stack) = @_;
  my $file = stringify(first(car($stack)));
my $line = '';
my $func = '';

  if ( isNil($stack) ) {
    printf('  <end>\n');

    return;

  } else {
    $file = stringify(first(car($stack)));

    $line = stringify(second(car($stack)));

    $func = stringify(third(first($stack)));

    printf('  %s:%s %s\n', $file, $line, $func);

    StackTracePrintHelper(cdr($stack));

  };

}


# Function NoStackTrace_list from line 404

sub NoStackTrace_list {
  my () = @_;
  
  return cons(boxString('StackTraceMove'), cons(boxString('StackTracePrint'), cons(boxString('StackTracePrintHelper'), cons(boxString('NoStackTrace_list'), cons(boxString('car'), cons(boxString('cdr'), cons(boxString('cons'), cons(boxString('set'), cons(boxString('boxString'), cons(boxString('makePair'), cons(boxString('set-struct'), cons(boxString('display'), cons(boxString('list'), cons(boxString('assertType'), cons(boxString('isEmpty'), cons(boxString('isNil'), cons(boxString('get-struct'), cons(boxString('equalString'), cons(boxString('binop'), cons(boxString('strcmp'), cons(boxString('main'), cons(boxString('makeBox'), cons(boxString('string_length'), cons(boxString('boxType'), cons(boxString('displayList'), cons(boxString('newLine'), cons(boxString('panic'), undef)))))))))))))))))))))))))));

}


# Function NoTrace_list from line 409

sub NoTrace_list {
  my () = @_;
  
  return cons(boxString('StackTraceMove'), cons(boxString('StackTracePrint'), cons(boxString('StackTracePrintHelper'), cons(boxString('NoStackTrace_list'), cons(boxString('car'), cons(boxString('cdr'), cons(boxString('cons'), cons(boxString('set'), cons(boxString('boxString'), cons(boxString('makePair'), cons(boxString('set-struct'), cons(boxString('display'), cons(boxString('list'), cons(boxString('assertType'), cons(boxString('isEmpty'), cons(boxString('isNil'), cons(boxString('get-struct'), cons(boxString('equalString'), cons(boxString('binop'), cons(boxString('strcmp'), cons(boxString('main'), cons(boxString('makeBox'), cons(boxString('string_length'), cons(boxString('boxType'), cons(boxString('displayList'), cons(boxString('newLine'), cons(boxString('panic'), cons(boxString('boxString'), cons(boxString('boxSymbol'), cons(boxString('boxType'), cons(boxString('equalString'), cons(boxString('unBoxSymbol'), cons(boxString('isList'), cons(boxString('makeBox'), cons(boxString('equalBox'), cons(boxString('sub'), cons(boxString('sub1'), cons(boxString('stringify'), cons(boxString('add'), cons(boxString('greaterthan'), undef))))))))))))))))))))))))))))))))))))))));

}


# Function indexOfHelper from line 418

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


# Function indexOf from line 427

sub indexOf {
  my ($haystack, $needle, $start) = @_;
  
  if ( equal(length($needle), 0) ) {
    return $start;

  } else {
    return indexOfHelper($haystack, $needle, $start, $start);

  };

}


# Function stringReplace from line 434

sub stringReplace {
  my ($old, $new, $s) = @_;
  my $pos = 0;

  $pos = indexOf($s, $old, 0);

  if ( equal($pos, -1) ) {
    return $s;

  } else {
    return stringConcatenate(substr($s, 0, $pos), stringConcatenate($new, stringReplace($old, $new, substr($s, add($pos, length($old)), length($s)))));

  };

}


# Function stringContains from line 448

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


# Function stringContainsHelper from line 463

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


# Function stringTrim from line 484

sub stringTrim {
  my ($s) = @_;
  
  if ( equal(length($s), 0) ) {
    return '';

  } else {
    if ( isWhiteSpace(substr($s, 0, 1)) ) {
      return stringTrim(substr($s, 1, length($s)));

    } else {
      if ( isWhiteSpace(substr($s, subtract(length($s), 1), length($s))) ) {
        return stringTrim(substr($s, 0, subtract(length($s), 1)));

      } else {
        return $s;

      };

    };

  };

}


# Function stringSplit from line 500

sub stringSplit {
  my ($s, $delimiter) = @_;
  my $end = 0;
my $delimiterLength = 0;

  printf('Entering stringSplit with s: %.20s..., delimiter: %s\n', $s, $delimiter);

  $delimiterLength = length($delimiter);

  $end = indexOf($s, $delimiter, 0);

  if ( equal($end, -1) ) {
    printf('No delimiter found in stringSplit\n');

    return cons(boxString($s), undef);

  } else {
    printf('Splitting string in stringSplit\n');

    return cons(boxString(substr($s, 0, $end)), stringSplit(substr($s, add($end, $delimiterLength), length($s)), $delimiter));

  };

}


# Function start from line 5

sub start {
  my () = @_;
  my $runTests = $false;
my $cmdLine = undef;
my $filenameBox = undef;
my $filename = '';
my $runPerl = $false;
my $runJava = $false;
my $runAst = $false;
my $runNode = $false;
my $runNode2 = $false;
my $runIma = $false;
my $runAnsi3 = $false;
my $runBash = $false;
my $runTree = $false;

  $cmdLine = listReverse(argList($globalArgsCount, 0, $globalArgs));

  if ( greaterthan(listLength($cmdLine), 1) ) {
    $filenameBox = second($cmdLine);

  } else {
    $filenameBox = boxString('compiler.qon');

  };

  $filename = unBoxString($filenameBox);

  $releaseMode = inList(boxString('--release'), $cmdLine);

  $runTests = inList(boxString('--test'), $cmdLine);

  $runJava = inList(boxString('--java'), $cmdLine);

  $runPerl = inList(boxString('--perl'), $cmdLine);

  $runAst = inList(boxString('--ast'), $cmdLine);

  $runTree = inList(boxString('--tree'), $cmdLine);

  $runNode = inList(boxString('--node'), $cmdLine);

  $runNode2 = inList(boxString('--node2'), $cmdLine);

  $runIma = inList(boxString('--ima'), $cmdLine);

  $runAnsi3 = inList(boxString('--ansi3'), $cmdLine);

  $runBash = inList(boxString('--bash'), $cmdLine);

  $globalTrace = inList(boxString('--trace'), $cmdLine);

  $globalStepTrace = inList(boxString('--steptrace'), $cmdLine);

  if ( inList(boxString('--help'), $cmdLine) ) {
    printf('Usage: quon file [options]\n\nNote the options go after the file name\n');

    printf('Options:\n');

    printf('  --help      Display this help\n');

    printf('  --release   Compile in release mode\n');

    printf('  --test      Run the test suite\n');

    printf('  --java      Compile to Java\n');

    printf('  --perl      Compile to Perl\n');

    printf('  --ast       Compile to the Abstract Syntax Tree\n');

    printf('  --tree      Compile to an s-expression tree\n');

    printf('  --node      Compile to Node.js\n');

    printf('  --node2      Compile to Node.js, new outputter\n');

    printf('  --ima       Compile to Imaginary, the human-friendly language\n');

    printf('  --ansi3     Compile to ANSI C (quon version 3)\n');

    printf('  --bash      Compile to Bash\n');

    printf('  --trace     Trace execution\n');

    printf('  --steptrace Step trace execution\n');

    printf('  --help      Display this help\n');

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

    printf('\n\nAfter all that hard work, I need a beer...\n');

    beers(9);

  } else {
    if ( $runTree ) {
      display(macrowalk(treeCompile($filename)));

    } else {
      if ( $runNode2 ) {
        node2Compile($filename);

        printf('\n');

      } else {
        if ( $runPerl ) {
          perlCompile($filename);

          printf('\n');

        } else {
          if ( $runAnsi3 ) {
            ansi3Compile($filename);

            printf('\n');

          } else {
            ansi3Compile($filename);

            printf('\n');

          };

        };

      };

    };

  };

  return 0;

}

# Main entry point
$globalArgsCount = scalar(@ARGV);
$globalArgs = \@ARGV;
$quonGlobalArgs = [];
for my $arg (@$globalArgs) {
    push @$quonGlobalArgs, {car => $arg, cdr => undef};
}
for (my $i = $#$quonGlobalArgs - 1; $i >= 0; $i--) {
    $quonGlobalArgs->[$i]->{cdr} = $quonGlobalArgs->[$i + 1];
}
start();


