     use Parse::RecDescent;
     $::RD_HINT   = 1;
     $::RD_WARN   = 1;
     $::RD_ERRORS = 1;
	my $text = join(" ", <>);

my $grammar = '
	includes: "Includes:" atom(s)  ..."Types" {$return =  "(includes @{$item[2]})\n"} | <error>
	typeHeader: "Types:"  | <error>
	typeDecls: typedef|structdef
	types: typeHeader typeDecls(s?) {$return = "(types @{$item[2]})"}| <error>
	typedefBody: identifier "is" identifier(s) ";" { $return =  "($item[1] @{$item[3]})\n";1;}
	typedef: "type" typedefBody { $return = $item[2] }
	structHeader: "type" identifier "is" "struct" "("  {$return =  $item[2]}
	structdef: structHeader typedefBody(s?) ")" ";" {$return = "($item[1] (struct \n@{$item[2]}))"}
	identifier: /[A-Za-z_*][A-Za-z0-9_*]*/
	atom: ...!"Types" identifier { $return = $item[2] }| <perl_quotelike> { $return = join("", @{$item[1]}) }| /[0-9.-]*/ {$return=$item[1]}
	expression: identifier "(" expression(s? /,/) ")" { $return =  "($item[1] @{$item[3]})" } | atom { $return =  $item[1] }
	return: "return" "(" expression ")" ";" { $return = "\n($item[1] $item[3])" }
	expressionStatement: expression ";" { $return =  "\n".$item[1] }
	ifStatement: "if" expression "then" statement(s?) "else" statement(s?) "end" { $return =  "\n(if $item[2] \n(then @{$item[4]}) \n(else @{$item[6]}))\n"}
	setStatement: identifier "=" expression ";" { $return = "\n(set $item[1] $item[3])" }
	nullReturn: "return" ";" { $return =  "\n(return)" }
	statement: ifStatement | setStatement | nullReturn | return | expressionStatement | <error>
	fun: "fu" identifier "(" argList ")" "->" identifier declare statement(s)  "end" "function" { $return =  "($item[7] $item[2] (@{$item[4]})\n(declare $item[8])\n(body @{$item[9]}))\n " } | <error>
	functions: "Functions:" fun(s?) {$return =  "(functions \n\n@{$item[2]})" }
	arg: identifier ":" identifier  { $return = "$item[3] $item[1]" }
	argList: arg(s? /,/) { $return = $item[1] }
	declare1: identifier ":" identifier expression { $return = "\n($item[3] $item[1] $item[4])" }
	declare: declare1(s?) "in" { $return = scalar(@{$item[1]}) ? "@{$item[1]}" : "" } | <error>
	program: includes types functions {$return = "(\n$item[1]\n$item[2]\n$item[3]\n)"}| <error>
';
# 
     # Generate a parser from the specification in $grammar:

         my $parser = new Parse::RecDescent ($grammar);


     # Parse $text using rule 'startrule' (which must be
     # defined in $grammar):

     use Data::Dumper;
        my $p = $parser->program($text);
        print $p;
