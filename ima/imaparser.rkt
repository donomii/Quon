#lang racket
(require parsack)
(require srfi/1)

(define ts (lambda (l)
             (map list->string l)))
(define $keywords (<any> (string "then")(string "else")(string "end")(string "in")(string "fu")(string "return")(string "if")))
(define (unSep e) (if (empty? e) "\"" (list->string e)))
(define (makeStr e) (if (string? e) e (list->string e))) 
(define $string (parser-compose
                 (char #\")
                 (str <- (sepBy (many (noneOf "\\\"")) (string "\\\"")))
                 (char #\")
                 (return (string-join (map unSep str) "\""))))
(define $atom (<or> $string (many $alphaNum)))
(define $whitespace  (many (or $space $newline $tab $eol)))
(define $mustWhitespace  (many1 (or $space $newline $tab $eol)))
(define $extraBody (parser-compose
                    $whitespace
                     (string",")
                     $whitespace
                    (exp <- $expression)
                    (more <- (<or> (try $extraBody) (return '())))
                    (return (cons exp more))
                    ))
(define $expBody (parser-compose
                   (string "(")
                   (body <- $expression) 
                  (extraBody <-  (<or> (try $extraBody) (return '())))
                  (string ")")
                  (return (cons body extraBody))))
(define $expression (parser-compose
                     $whitespace
                     (notFollowedBy (>> $keywords $mustWhitespace))
                     (notFollowedBy $eol)
                     (head <- $atom)
                     (body <-  (<or> (try $expBody) (return '())))
                     (return  (if (empty? body)
                                  (makeStr head)
                                  (cons  (makeStr head)   body)))))


(define $set-statement(parser-compose
                       $whitespace
                       (var <-(many $alphaNum))
                       $whitespace
                       (char #\=)
                       $whitespace
                       (expression <- $expression)
                       (return (list "set" (list->string var)  expression))))
(define $return-statement(parser-compose
                          $whitespace
                          (string "return")
                          $whitespace
                          (expression <- $expression)
                          (return (list "return"   expression))))
(define $if-statement (parser-compose
                       $whitespace
                       (string "if")
                       $whitespace
                       (condition <- $expression)
                       $whitespace
                       (string "then")
                       $whitespace
                       (trueBranch <- (<or> (try $statements) (return '())))
                       $whitespace
                   
                       (string "else")
                       $whitespace
                       (falseBranch <-  (<or> (try  $statements) (return '())))
                       $whitespace
                       (string "end")
                   
                       (return (list "if"  condition (cons "then" trueBranch) (cons "else" falseBranch )))))
(define $exp-statement (parser-compose
                        $whitespace
                        ;(string "side")
                        (notFollowedBy (string "end"))
     (notFollowedBy (string "then"))
     (notFollowedBy (string "else"))
                        (exp <- $expression)
                         
     (char #\;)
                        (return exp)
                        ))
(define $statements
  (parser-compose
    
     ;(notFollowedBy (string "end"))
     ;(notFollowedBy (string "then"))
     ;(notFollowedBy (string "else"))
           
     (head <- (<any>     (try $if-statement)  (try $set-statement)  (try $return-statement)   (try $exp-statement )))
     
     (more <- (<or> (try $statements) (return '())))
     (return (cons head more))
                                    ))
(define $arg (parser-compose
              (<any> $whitespace)
              (name <- (manyTill $identifier (string ":")))
              (<any> $whitespace)
              (type <-  (many $identifier ))
              (<any> $whitespace)
              (return (ts (list (car type) (car name) )))))
(define $args (sepBy $arg (string",")))
(define $decl (parser-compose
               $whitespace
               (name <- (manyTill $alphaNum (string ":")))
               $whitespace
               (type <- (between (string "*") (string "*") (many $alphaNum)))
               (init <- (manyTill $anyChar $eol))
               (return (ts (list name type init)))))
(define $function (parser-compose
                   (try $whitespace)
                   (string "fu")
                   (many $space)
                   (name <- (manyTill $letter (char #\()))
                   (arg <- $args)
                   (string ")")
                   (many $space)
                   (string "->")
                   (many $space)
                   (returnType <-(manyTill $letter $whitespace))
                   (decl <- (manyTill (<or>  $decl $whitespace) (string "in") ))
                   
                   
                   (try $whitespace)
                   (s <-  $statements)
                   (try $whitespace)
                   (string "end function")
                   (return (list (list->string returnType) (list->string name) (flatten arg) (cons "declare" decl) (cons "body" s) ))))
(define (test-expression) (parse-result $expression "cons(macrosingle(car(l), search, replace), macrosingle(cdr(l), search, replace))")
)
(define (test-if) (parse-result $if-statement "

if la then

else

end
"))
(define (test-statements) (parse-result $statements "
return nil;
runTests = inList(boxString(a), cmdLine);
"))


  (test-expression)
(test-statements)
  (test-if)

(parse-result
 $function
  
 "

fu start() -> int
  runTests: *bool* false
  cmdLine: *list* nil
  filename: *box* nil
  runPerl: *bool* false
  runJava: *bool* false
  runAst: *bool* false
  runNode: *bool* false
  runLua: *bool* false
  runIma: *bool* false
  runTree: *bool* false
in
  cmdLine = listReverse(argList(globalArgsCount, 0, globalArgs))
  if greaterthan(listLength(cmdLine), 1) then
      filename = second(cmdLine);
  else
      filename = boxString(\"compiler.qon\");
  end

runTests = inList(boxString(\"--test\"), cmdLine);
 
  if runTests then
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
     
      beers(9);
  else
      if runTree then
          display(macrowalk(treeCompile(unBoxString(filename))));
      else
          if runAst then
              astCompile(unBoxString(filename));
          else
              if runNode then
                  nodeCompile(unBoxString(filename));
                 
              else
                  if runPerl then
                      perlCompile(unBoxString(filename));
                    
                  else
                      if runJava then
                          javaCompile(unBoxString(filename));
                        
                      else
                          if runLua then
                              luaCompile(unBoxString(filename));
                           
                          else
                              if runIma then
                                  imaCompile(unBoxString(filename));
                                
                              else
                                  ansiCompile(unBoxString(filename));
                                 
                              end
                          end
                      end
                  end
              end
          end
      end
  end
  return 0
end function
")


;send(\"l\",5,add(\"two\",3))