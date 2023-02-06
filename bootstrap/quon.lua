
function luaDump(o)
   if type(o) == 'table' then
      local s = '{ '
      for k,v in pairs(o) do
         if type(k) ~= 'number' then k = '"'..k..'"' end
         s = s .. '['..k..'] = ' .. luaDump(v) .. ','
      end
      return s .. '} '
   else
      return tostring(o)
   end
end
printf = function(s,...)
return io.write(s:format(...))
end -- function
    
function stringConcatenate(a,b)
return a..b
end
    
function getStringArray(index, arr)
return arr[index]
end
       
function luaWriteFile(name, data)  
local file = io.open(name, "w")
file:write(data)
file:close(file)
end
    function luaSubstring(s, start, length)
return string.sub(s, start, start+length)
end
    
    function luaReadFile(file)
      local f = assert(io.open(file, "rb"))
      local content = f:read("*all")      f:close()
      return content
    end
     
function equalString(a,b)
        return a==b;
     end
    
     function new()
        return {};
     end
    
     function isNil(val)
        return val == nil;
     end
    
     function getEnv(key)
        return os.getenv(key);
     end
    
    function panic(s)
      print(s);
    os.exit()
    end
    
    function sub(a, b) 
      return a - b; 
    end

    function mult(a, b) 
      return a * b;
    end
    
    function greaterthan(a, b)
      return a > b;
    end
    
    function subf(a, b) 
      return a - b;
    end
    
    function multf(a, b)
      return a * b;
    end
    
    function greaterthanf(a, b)
      return a > b;
    end
    
    function equal(a, b)
      return a == b;
    end
    
    function andBool(a, b)
      return a == b;
    end
    
    function string_length(s)
      return strlen(s);
    end
    
    function setSubString(target, start, source)
      panic("stub");
      end
    
    function sub_string(s, start, length)
      panic("stub");
    end
    
    function intToString(a)
      panic("stub")
 return a
    end

    function gc_malloc(size)
      return ""
    end
    
    function makeArray(length)
      return {}
    end
    
    function at(arr, index)
      return arr[index+1];
    end
    
    function setAt(array, index, value)
      array[index+1] = value;
    end
    
    function read_file(file)
      local f = io.open(file, "r")
      local content = ""
      local length = 0

      while f:read(0) ~= "" do
          local current = f:read("*all")

          print(#current, length)
          length = length + #current

          content = content .. current
      end

      return content
    end
    
    function write_file(filename, data)
      local file = io.open(filename,'w')
      file:write(tostring(data))
      file:close()
    end
    
    caller="main";
    
    globalArgs={};
    globalArgsCount=0;
    globalTrace = false;
    globalStepTrace = false;

    function main()
      globalArgs = arg;
      globalArgsCount = #arg + 1;
      return start();
    end
    
-- Chose function name bashdisplays
function bashdisplays(s)
print("caller: ", caller, "-> bashdisplays")
caller = "bashdisplays:Unknown file:-1"
  printf("%s", s);

end
-- Chose function name bashFunctionArgs
function bashFunctionArgs(decls,argNum,indent)
print("caller: ", caller, "-> bashFunctionArgs")
caller = "bashFunctionArgs:Unknown file:-1"
  if isEmpty(decls) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      printf("local %s=\"%s%s", stringify(second(decls)), dollar(), stringify(boxInt(argNum)));

caller = ":Unknown file:-1"
      printf("\" ;\n");

caller = ":Unknown file:-1"
      bashFunctionArgs(cdr(cdr(decls)), add(1, argNum), indent);

  end

end
-- Chose function name bashExpression
function bashExpression(tree,indent,statement)
print("caller: ", caller, "-> bashExpression")
local thing =nil
caller = "bashExpression:Unknown file:-1"
  if isList(tree) then
caller = ":Unknown file:-1"
      if equal(1, listLength(tree)) then
caller = ":Unknown file:-1"
          display(car(tree));

caller = ":Unknown file:-1"
          if equalBox(boxString("return"), car(tree)) then
          else
caller = ":Unknown file:-1"
              bashdisplays("()");

          end

      else
caller = ":Unknown file:-1"
          thing = first(tree)
caller = ":Unknown file:-1"
          if equalBox(boxSymbol("get-struct"), thing) then
caller = ":Unknown file:-1"
              printf("%s->%s", stringify(second(tree)), stringify(third(tree)));

          else
caller = ":Unknown file:-1"
              if equalBox(boxSymbol("new"), thing) then
caller = ":Unknown file:-1"
                  printf("malloc(sizeof(%s))", stringify(third(tree)));

              else
caller = ":Unknown file:-1"
                  if equalBox(boxSymbol("passthrough"), thing) then
caller = ":Unknown file:-1"
                      printf("%s", stringify(second(tree)));

                  else
caller = ":Unknown file:-1"
                      if equalBox(boxSymbol("binop"), thing) then
caller = ":Unknown file:-1"
                          printf("(");

caller = ":Unknown file:-1"
                          bashExpression(third(tree), indent, false);

caller = ":Unknown file:-1"
                          printf(" %s ", stringify(second(tree)));

caller = ":Unknown file:-1"
                          bashExpression(fourth(tree), indent, false);

caller = ":Unknown file:-1"
                          printf(")");

                      else
caller = ":Unknown file:-1"
                          if statement then
caller = ":Unknown file:-1"
                              printf("%s ", stringify(bashFuncMap(car(tree))));

caller = ":Unknown file:-1"
                              bashRecurList(cdr(tree), indent);

                          else
caller = ":Unknown file:-1"
                              printf("%s(%s ", dollar(), stringify(bashFuncMap(car(tree))));

caller = ":Unknown file:-1"
                              bashRecurList(cdr(tree), indent);

caller = ":Unknown file:-1"
                              printf(")");

                          end

                      end

                  end

              end

          end

      end

  else
caller = ":Unknown file:-1"
      display(bashVarOrLit(tree));

  end

end
-- Chose function name bashVarOrLit
function bashVarOrLit(a)
print("caller: ", caller, "-> bashVarOrLit")
caller = "bashVarOrLit:Unknown file:-1"
  if equalString("symbol", boxType(a)) then
caller = ":Unknown file:-1"
      return boxSymbol(stringConcatenate(dollar(), stringify(a)))

  else
caller = ":Unknown file:-1"
      return a

  end

end
-- Chose function name bashRecurList
function bashRecurList(expr,indent)
print("caller: ", caller, "-> bashRecurList")
caller = "bashRecurList:Unknown file:-1"
  if isEmpty(expr) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      bashExpression(car(expr), indent, false);

caller = ":Unknown file:-1"
      if isNil(cdr(expr)) then
caller = ":Unknown file:-1"
          bashdisplays("");

      else
caller = ":Unknown file:-1"
          bashdisplays(" ");

caller = ":Unknown file:-1"
          bashRecurList(cdr(expr), indent);

      end

  end

end
-- Chose function name bashIf
function bashIf(node,indent)
print("caller: ", caller, "-> bashIf")
caller = "bashIf:Unknown file:-1"
  newLine(indent);

caller = "bashIf:Unknown file:-1"
  bashdisplays("if (( ");

caller = "bashIf:Unknown file:-1"
  bashExpression(second(node), 0, false);

caller = "bashIf:Unknown file:-1"
  bashdisplays(" )) ; then ");

caller = "bashIf:Unknown file:-1"
  bashBody(cdr(third(node)), add1(indent));

caller = "bashIf:Unknown file:-1"
  newLine(indent);

caller = "bashIf:Unknown file:-1"
  bashdisplays(" else ");

caller = "bashIf:Unknown file:-1"
  bashBody(cdr(fourth(node)), add1(indent));

caller = "bashIf:Unknown file:-1"
  newLine(indent);

caller = "bashIf:Unknown file:-1"
  bashdisplays("fi");

end
-- Chose function name bashSetStruct
function bashSetStruct(node,indent)
print("caller: ", caller, "-> bashSetStruct")
caller = "bashSetStruct:Unknown file:-1"
  newLine(indent);

caller = "bashSetStruct:Unknown file:-1"
  printf("%s%s_%s%s=", dollar(), stringify(second(node)), dollar(), stringify(third(node)));

caller = "bashSetStruct:Unknown file:-1"
  bashExpression(fourth(node), indent, false);

end
-- Chose function name bashGetStruct
function bashGetStruct(node,indent)
print("caller: ", caller, "-> bashGetStruct")
caller = "bashGetStruct:Unknown file:-1"
  newLine(indent);

caller = "bashGetStruct:Unknown file:-1"
  printf("%s%s_%s%s", dollar(), stringify(first(node)), dollar(), stringify(second(node)));

end
-- Chose function name bashSet
function bashSet(node,indent)
print("caller: ", caller, "-> bashSet")
caller = "bashSet:Unknown file:-1"
  newLine(indent);

caller = "bashSet:Unknown file:-1"
  display(first(cdr(node)));

caller = "bashSet:Unknown file:-1"
  printf("=");

caller = "bashSet:Unknown file:-1"
  bashExpression(third(node), indent, false);

end
-- Chose function name bashReturn
function bashReturn(node,indent)
print("caller: ", caller, "-> bashReturn")
caller = "bashReturn:Unknown file:-1"
  newLine(indent);

caller = "bashReturn:Unknown file:-1"
  if equal(listLength(node), 1) then
caller = ":Unknown file:-1"
      bashdisplays("return;");

  else
caller = ":Unknown file:-1"
      bashdisplays("return ");

caller = ":Unknown file:-1"
      bashExpression(cadr(node), indent, false);

caller = ":Unknown file:-1"
      bashdisplays(";");

  end

end
-- Chose function name bashStatement
function bashStatement(node,indent)
print("caller: ", caller, "-> bashStatement")
caller = "bashStatement:Unknown file:-1"
  if equalBox(boxString("set"), first(node)) then
caller = ":Unknown file:-1"
      bashSet(node, indent);

  else
caller = ":Unknown file:-1"
      if equalBox(boxString("set-struct"), first(node)) then
caller = ":Unknown file:-1"
          bashSetStruct(node, indent);

      else
caller = ":Unknown file:-1"
          if equalBox(boxString("if"), first(node)) then
caller = ":Unknown file:-1"
              bashIf(node, indent);

          else
caller = ":Unknown file:-1"
              if equalBox(boxString("return"), first(node)) then
caller = ":Unknown file:-1"
                  bashReturn(node, indent);

              else
caller = ":Unknown file:-1"
                  newLine(indent);

caller = ":Unknown file:-1"
                  bashExpression(node, indent, true);

              end

          end

      end

  end

caller = "bashStatement:Unknown file:-1"
  bashdisplays(" \n");

end
-- Chose function name bashBody
function bashBody(tree,indent)
print("caller: ", caller, "-> bashBody")
local code =nil
caller = "bashBody:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      code = tree
caller = ":Unknown file:-1"
      if isNil(code) then
      else
caller = ":Unknown file:-1"
          code = car(tree)
caller = ":Unknown file:-1"
          if not(releaseMode) then
caller = ":Unknown file:-1"
              printf("\nif (( $globalTrace )) ; then\n    caller=\"from %s:%s\"\nfi", stringify(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), stringify(getTagFail(car(code), boxString("line"), boxString("Line missing"))));

          else
          end

      end

caller = ":Unknown file:-1"
      if not(releaseMode) then
      else
      end

caller = ":Unknown file:-1"
      bashStatement(code, indent);

caller = ":Unknown file:-1"
      bashBody(cdr(tree), indent);

  end

end
-- Chose function name bashDeclarations
function bashDeclarations(decls,indent)
print("caller: ", caller, "-> bashDeclarations")
local decl =nil
caller = "bashDeclarations:Unknown file:-1"
  if isEmpty(decls) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      decl = car(decls)
caller = ":Unknown file:-1"
      printf("local %s=\"", stringify(second(decl)));

caller = ":Unknown file:-1"
      bashExpression(third(decl), indent, false);

caller = ":Unknown file:-1"
      printf("\";\n");

caller = ":Unknown file:-1"
      bashDeclarations(cdr(decls), indent);

  end

end
-- Chose function name bashFunction
function bashFunction(node)
print("caller: ", caller, "-> bashFunction")
local name =nil
caller = "bashFunction:Unknown file:-1"
  name = second(node)
caller = "bashFunction:Unknown file:-1"
  printf("\n\n#Building function %s from line:%s", stringify(name), stringify(getTag(name, boxString("line"))));

caller = "bashFunction:Unknown file:-1"
  newLine(0);

caller = "bashFunction:Unknown file:-1"
  if isNil(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      newLine(0);

caller = ":Unknown file:-1"
      printf("%s(", stringify(second(node)));

caller = ":Unknown file:-1"
      printf(") {");

caller = ":Unknown file:-1"
      newLine(1);

caller = ":Unknown file:-1"
      bashFunctionArgs(third(node), 1, 1);

caller = ":Unknown file:-1"
      bashDeclarations(cdr(fourth(node)), 1);

caller = ":Unknown file:-1"
      if releaseMode then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf("\nif (( $globalTrace )) ; then\n    echo \"%s at %s:%s \" $caller\nfi", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

      end

caller = ":Unknown file:-1"
      if releaseMode then
caller = ":Unknown file:-1"
          printf("");

      else
      end

caller = ":Unknown file:-1"
      bashBody(cdr(fifth(node)), 1);

caller = ":Unknown file:-1"
      if releaseMode then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf("\nif (( $globalTrace ))\n    echo \"Leaving %s\\n\"\n", stringify(name));

      end

caller = ":Unknown file:-1"
      printf("\n}\n");

  end

end
-- Chose function name bashForwardDeclaration
function bashForwardDeclaration(node)
print("caller: ", caller, "-> bashForwardDeclaration")
end
-- Chose function name bashForwardDeclarations
function bashForwardDeclarations(tree)
print("caller: ", caller, "-> bashForwardDeclarations")
caller = "bashForwardDeclarations:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      bashForwardDeclaration(car(tree));

caller = ":Unknown file:-1"
      bashForwardDeclarations(cdr(tree));

  end

end
-- Chose function name bashFunctions
function bashFunctions(tree)
print("caller: ", caller, "-> bashFunctions")
caller = "bashFunctions:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      bashFunction(car(tree));

caller = ":Unknown file:-1"
      bashFunctions(cdr(tree));

  end

end
-- Chose function name bashIncludes
function bashIncludes(nodes)
print("caller: ", caller, "-> bashIncludes")
caller = "bashIncludes:Unknown file:-1"
  printf("%s", "\n\n#define true 1\n#define false 0\n\n\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\nbool releaseMode = false;\n\n");

caller = "bashIncludes:Unknown file:-1"
  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n");

end
-- Chose function name bashTypeDecl
function bashTypeDecl(l)
print("caller: ", caller, "-> bashTypeDecl")
end
-- Chose function name bashStructComponents
function bashStructComponents(node)
print("caller: ", caller, "-> bashStructComponents")
caller = "bashStructComponents:Unknown file:-1"
  if isEmpty(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      bashTypeDecl(car(node));

caller = ":Unknown file:-1"
      bashStructComponents(cdr(node));

  end

end
-- Chose function name bashStruct
function bashStruct(node)
print("caller: ", caller, "-> bashStruct")
caller = "bashStruct:Unknown file:-1"
  bashStructComponents(cdr(node));

end
-- Chose function name bashTypeMap
function bashTypeMap(aSym)
print("caller: ", caller, "-> bashTypeMap")
local symMap =nil
caller = "bashTypeMap:Unknown file:-1"
  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), nil))
caller = "bashTypeMap:Unknown file:-1"
  if truthy(assoc(stringify(aSym), symMap)) then
caller = ":Unknown file:-1"
      return cdr(assoc(stringify(aSym), symMap))

  else
caller = ":Unknown file:-1"
      return aSym

  end

end
-- Chose function name bashFuncMap
function bashFuncMap(aSym)
print("caller: ", caller, "-> bashFuncMap")
local symMap =nil
caller = "bashFuncMap:Unknown file:-1"
  if equalString("symbol", boxType(aSym)) then
caller = ":Unknown file:-1"
      symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("luaSubstring"), boxSymbol("sub_string"), alistCons(boxSymbol("luaReadFile"), boxSymbol("read_file"), alistCons(boxSymbol("luaWriteFile"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string.len"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), nil)))))))
caller = ":Unknown file:-1"
      if truthy(assoc(stringify(aSym), symMap)) then
caller = ":Unknown file:-1"
          return cdr(assoc(stringify(aSym), symMap))

      else
caller = ":Unknown file:-1"
          return aSym

      end

  else
caller = ":Unknown file:-1"
      return aSym

  end

end
-- Chose function name bashType
function bashType(node)
print("caller: ", caller, "-> bashType")
end
-- Chose function name bashTypes
function bashTypes(nodes)
print("caller: ", caller, "-> bashTypes")
caller = "bashTypes:Unknown file:-1"
  if isEmpty(nodes) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      bashType(car(nodes));

caller = ":Unknown file:-1"
      bashTypes(cdr(nodes));

  end

end
-- Chose function name bashCompile
function bashCompile(filename)
print("caller: ", caller, "-> bashCompile")
local tree =nil
local replace =nil
caller = "bashCompile:Unknown file:-1"
  qlog("//Scanning file...%s\n", filename);

caller = "bashCompile:Unknown file:-1"
  tree = loadQuon(filename)
caller = "bashCompile:Unknown file:-1"
  qlog("//Building sexpr\n");

caller = "bashCompile:Unknown file:-1"
  qlog("Loading shim bash\n");

caller = "bashCompile:Unknown file:-1"
  tree = buildProg(cons(boxString("q/shims/bash.qon"), getIncludes(tree)), getTypes(tree), getFunctions(tree))
caller = "bashCompile:Unknown file:-1"
  qlog("Loading all includes\n");

caller = "bashCompile:Unknown file:-1"
  tree = loadIncludes(tree)
caller = "bashCompile:Unknown file:-1"
  qlog("Applying macros\n");

caller = "bashCompile:Unknown file:-1"
  tree = macrowalk(tree)
caller = "bashCompile:Unknown file:-1"
  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), nil))
caller = "bashCompile:Unknown file:-1"
  tree = macrolist(tree, stringConcatenate("q", "log"), replace)
caller = "bashCompile:Unknown file:-1"
  qlog("//Printing program\n");

caller = "bashCompile:Unknown file:-1"
  bashIncludes(cdr(first(tree)));

caller = "bashCompile:Unknown file:-1"
  bashTypes(cdr(second(tree)));

caller = "bashCompile:Unknown file:-1"
  bashdisplays("Box* globalStackTrace = NULL;\n");

caller = "bashCompile:Unknown file:-1"
  bashdisplays("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");

caller = "bashCompile:Unknown file:-1"
  bashForwardDeclarations(cdr(third(tree)));

caller = "bashCompile:Unknown file:-1"
  bashdisplays("\n\n//End forward declarations\n\n");

caller = "bashCompile:Unknown file:-1"
  bashFunctions(cdr(third(tree)));

caller = "bashCompile:Unknown file:-1"
  bashdisplays("\n");

caller = "bashCompile:Unknown file:-1"
  qlog("//Done printing program\n");

end
-- Chose function name imaFunctionArgs
function imaFunctionArgs(indent,tree)
print("caller: ", caller, "-> imaFunctionArgs")
caller = "imaFunctionArgs:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      display(second(tree));

caller = ":Unknown file:-1"
      printf(": ");

caller = ":Unknown file:-1"
      display(first(tree));

caller = ":Unknown file:-1"
      if isNil(cddr(tree)) then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf(", ");

      end

caller = ":Unknown file:-1"
      imaFunctionArgs(indent, cddr(tree));

  end

end
-- Chose function name imaFunction
function imaFunction(indent,functionDefinition)
print("caller: ", caller, "-> imaFunction")
local fname =""
caller = "imaFunction:Unknown file:-1"
  fname = stringify(second(functionDefinition))
caller = "imaFunction:Unknown file:-1"
  printf("\nfu %s(", fname);

caller = "imaFunction:Unknown file:-1"
  imaFunctionArgs(indent, third(functionDefinition));

caller = "imaFunction:Unknown file:-1"
  printf(") ");

caller = "imaFunction:Unknown file:-1"
  printf("-> %s", stringify(first(functionDefinition)));

caller = "imaFunction:Unknown file:-1"
  imaDeclarations(add1(indent), cdr(fourth(functionDefinition)));

caller = "imaFunction:Unknown file:-1"
  if greaterthan(listLength(cdr(fourth(functionDefinition))), 0) then
caller = ":Unknown file:-1"
      printf("\n");

  else
caller = ":Unknown file:-1"
      printf(" ");

  end

caller = "imaFunction:Unknown file:-1"
  printIndent(indent);

caller = "imaFunction:Unknown file:-1"
  printf("in\n");

caller = "imaFunction:Unknown file:-1"
  imaBody(fname, indent, cdr(fifth(functionDefinition)));

caller = "imaFunction:Unknown file:-1"
  printf("end function\n");

end
-- Chose function name imaDeclarations
function imaDeclarations(indent,declarations)
print("caller: ", caller, "-> imaDeclarations")
local decl =nil
caller = "imaDeclarations:Unknown file:-1"
  if isNil(declarations) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      decl = first(declarations)
caller = ":Unknown file:-1"
      printf("\n");

caller = ":Unknown file:-1"
      printIndent(indent);

caller = ":Unknown file:-1"
      printf("%s: %s ", stringify(second(decl)), stringify(first(decl)));

caller = ":Unknown file:-1"
      imaExpressionStart(indent, third(decl));

caller = ":Unknown file:-1"
      imaDeclarations(indent, cdr(declarations));

  end

end
-- Chose function name imaExpressionStart
function imaExpressionStart(indent,program)
print("caller: ", caller, "-> imaExpressionStart")
caller = "imaExpressionStart:Unknown file:-1"
  if isNil(program) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      if isList(program) then
caller = ":Unknown file:-1"
          if equalString(stringify(car(program)), "get-struct") then
caller = ":Unknown file:-1"
              printf("%s.%s", stringify(second(program)), stringify(third(program)));

          else
caller = ":Unknown file:-1"
              if equalString(stringify(car(program)), ">") then
caller = ":Unknown file:-1"
                  printf("greaterthan(");

caller = ":Unknown file:-1"
                  imaExpression(indent, cdr(program));

caller = ":Unknown file:-1"
                  printf(")");

              else
caller = ":Unknown file:-1"
                  if equalString(stringify(car(program)), "=") then
caller = ":Unknown file:-1"
                      printf("equal(");

caller = ":Unknown file:-1"
                      imaExpression(indent, cdr(program));

caller = ":Unknown file:-1"
                      printf(")");

                  else
caller = ":Unknown file:-1"
                      printf("%s(", stringify(car(program)));

caller = ":Unknown file:-1"
                      imaExpression(indent, cdr(program));

caller = ":Unknown file:-1"
                      printf(")");

                  end

              end

          end

      else
caller = ":Unknown file:-1"
          imaExpression(indent, program);

      end

  end

end
-- Chose function name imaExpression
function imaExpression(indent,program)
print("caller: ", caller, "-> imaExpression")
caller = "imaExpression:Unknown file:-1"
  if isNil(program) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      if isList(program) then
caller = ":Unknown file:-1"
          if isList(car(program)) then
caller = ":Unknown file:-1"
              imaExpressionStart(indent, car(program));

          else
caller = ":Unknown file:-1"
              display(car(program));

          end

caller = ":Unknown file:-1"
          if greaterthan(listLength(program), 1) then
caller = ":Unknown file:-1"
              printf(", ");

          else
          end

caller = ":Unknown file:-1"
          imaExpression(indent, cdr(program));

      else
caller = ":Unknown file:-1"
          display(program);

      end

  end

end
-- Chose function name imaStatement
function imaStatement(indent,statement)
print("caller: ", caller, "-> imaStatement")
caller = "imaStatement:Unknown file:-1"
  if equalString(stringify(car(statement)), "if") then
caller = ":Unknown file:-1"
      printIndent(indent);

caller = ":Unknown file:-1"
      printf("if ");

caller = ":Unknown file:-1"
      add1(indent);

caller = ":Unknown file:-1"
      imaExpressionStart(add1(indent), second(statement));

caller = ":Unknown file:-1"
      printf(" then\n");

caller = ":Unknown file:-1"
      imaBody(caller, add1(indent), cdr(third(statement)));

caller = ":Unknown file:-1"
      printIndent(indent);

caller = ":Unknown file:-1"
      printf("else\n");

caller = ":Unknown file:-1"
      imaBody(caller, add1(indent), cdr(fourth(statement)));

caller = ":Unknown file:-1"
      printIndent(indent);

caller = ":Unknown file:-1"
      printf("end\n");

  else
caller = ":Unknown file:-1"
      if equalString(stringify(car(statement)), "set") then
caller = ":Unknown file:-1"
          printIndent(indent);

caller = ":Unknown file:-1"
          printf("%s = ", stringify(second(statement)));

caller = ":Unknown file:-1"
          imaExpressionStart(add1(indent), third(statement));

caller = ":Unknown file:-1"
          printf(";\n");

      else
caller = ":Unknown file:-1"
          if equalString(stringify(car(statement)), "set-struct") then
caller = ":Unknown file:-1"
              printIndent(indent);

caller = ":Unknown file:-1"
              printf("%s.%s = ", stringify(second(statement)), stringify(third(statement)));

caller = ":Unknown file:-1"
              imaExpressionStart(indent, fourth(statement));

caller = ":Unknown file:-1"
              printf(";\n");

          else
caller = ":Unknown file:-1"
              if equalString(stringify(car(statement)), "return") then
caller = ":Unknown file:-1"
                  printIndent(indent);

caller = ":Unknown file:-1"
                  printf("return; ");

caller = ":Unknown file:-1"
                  if greaterthan(listLength(statement), 1) then
caller = ":Unknown file:-1"
                      imaExpressionStart(indent, second(statement));

                  else
                  end

caller = ":Unknown file:-1"
                  printf("\n");

              else
caller = ":Unknown file:-1"
                  printIndent(indent);

caller = ":Unknown file:-1"
                  imaExpressionStart(indent, statement);

caller = ":Unknown file:-1"
                  printf(";\n");

              end

          end

      end

  end

end
-- Chose function name imaBody
function imaBody(local_caller,indent,program)
print("caller: ", caller, "-> imaBody")
local statement =nil
caller = "imaBody:Unknown file:-1"
  if isNil(program) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      statement = car(program)
caller = ":Unknown file:-1"
      imaStatement(add1(indent), statement);

caller = ":Unknown file:-1"
      imaBody(local_caller, indent, cdr(program));

  end

end
-- Chose function name imaFunctions
function imaFunctions(indent,program)
print("caller: ", caller, "-> imaFunctions")
caller = "imaFunctions:Unknown file:-1"
  if isNil(program) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      imaFunction(indent, car(program));

caller = ":Unknown file:-1"
      imaFunctions(indent, cdr(program));

  end

end
-- Chose function name imaTypeDecl
function imaTypeDecl(l)
print("caller: ", caller, "-> imaTypeDecl")
local name =""
local body =nil
caller = "imaTypeDecl:Unknown file:-1"
  name = stringify(first(l))
caller = "imaTypeDecl:Unknown file:-1"
  body = cdr(l)
caller = "imaTypeDecl:Unknown file:-1"
  if greaterthan(listLength(l), 2) then
caller = ":Unknown file:-1"
      printIndent(1);

caller = ":Unknown file:-1"
      printf("%s is ", name);

caller = ":Unknown file:-1"
      displayList(body, 0, true);

caller = ":Unknown file:-1"
      printf(";\n");

  else
caller = ":Unknown file:-1"
      printIndent(1);

caller = ":Unknown file:-1"
      printf("%s is %s;\n", name, stringify(second(l)));

  end

end
-- Chose function name imaStructComponents
function imaStructComponents(node)
print("caller: ", caller, "-> imaStructComponents")
caller = "imaStructComponents:Unknown file:-1"
  if isEmpty(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      imaTypeDecl(car(node));

caller = ":Unknown file:-1"
      imaStructComponents(cdr(node));

  end

end
-- Chose function name imaStruct
function imaStruct(node)
print("caller: ", caller, "-> imaStruct")
caller = "imaStruct:Unknown file:-1"
  imaStructComponents(cdr(car(node)));

end
-- Chose function name imaTypeMap
function imaTypeMap(aSym)
print("caller: ", caller, "-> imaTypeMap")
local symMap =nil
caller = "imaTypeMap:Unknown file:-1"
  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), nil))
caller = "imaTypeMap:Unknown file:-1"
  if truthy(assoc(stringify(aSym), symMap)) then
caller = ":Unknown file:-1"
      return cdr(assoc(stringify(aSym), symMap))

  else
caller = ":Unknown file:-1"
      return aSym

  end

end
-- Chose function name imaType
function imaType(node)
print("caller: ", caller, "-> imaType")
local name =""
local body =nil
caller = "imaType:Unknown file:-1"
  name = stringify(first(node))
caller = "imaType:Unknown file:-1"
  body = cdr(node)
caller = "imaType:Unknown file:-1"
  if isList(first(body)) then
caller = ":Unknown file:-1"
      printf("\ntype %s is struct (\n", name);

caller = ":Unknown file:-1"
      imaStruct(body);

caller = ":Unknown file:-1"
      printf(");\n");

  else
caller = ":Unknown file:-1"
      printf("type");

caller = ":Unknown file:-1"
      imaTypeDecl(node);

  end

end
-- Chose function name imaTypes
function imaTypes(indent,nodes)
print("caller: ", caller, "-> imaTypes")
caller = "imaTypes:Unknown file:-1"
  if isEmpty(nodes) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      imaType(car(nodes));

caller = ":Unknown file:-1"
      imaTypes(indent, cdr(nodes));

  end

end
-- Chose function name imaProgram
function imaProgram(program)
print("caller: ", caller, "-> imaProgram")
caller = "imaProgram:Unknown file:-1"
  imaIncludes(0, cdr(first(program)));

caller = "imaProgram:Unknown file:-1"
  printf("\nTypes:\n");

caller = "imaProgram:Unknown file:-1"
  imaTypes(0, cdr(second(program)));

caller = "imaProgram:Unknown file:-1"
  printf("\nFunctions:\n");

caller = "imaProgram:Unknown file:-1"
  imaFunctions(0, cdr(third(program)));

end
-- Chose function name imaIncludes
function imaIncludes(indent,nodes)
print("caller: ", caller, "-> imaIncludes")
caller = "imaIncludes:Unknown file:-1"
  printf("Includes: \n");

caller = "imaIncludes:Unknown file:-1"
  displayList(nodes, 0, true);

end
-- Chose function name imaCompile
function imaCompile(filename)
print("caller: ", caller, "-> imaCompile")
local tree =nil
caller = "imaCompile:Unknown file:-1"
  tree = loadQuon("compiler.qon")
caller = "imaCompile:Unknown file:-1"
  tree = loadIncludes(tree)
caller = "imaCompile:Unknown file:-1"
  tree = macrowalk(tree)
caller = "imaCompile:Unknown file:-1"
  tree = macrosingle(tree, "luaWriteFile", "imaWriteFile")
caller = "imaCompile:Unknown file:-1"
  tree = macrosingle(tree, "luaReadFile", "imaReadFile")
caller = "imaCompile:Unknown file:-1"
  tree = macrosingle(tree, "string.len", "string.len")
caller = "imaCompile:Unknown file:-1"
  tree = macrosingle(tree, "luaSubstring", "imaSubstring")
caller = "imaCompile:Unknown file:-1"
  tree = macrosingle(tree, "string.len", "string.len")
caller = "imaCompile:Unknown file:-1"
  imaProgram(tree);

caller = "imaCompile:Unknown file:-1"
  printf("\n");

caller = "imaCompile:Unknown file:-1"
  printf("function main()\nglobalArgs = arg\nglobalArgsCount = #arg\nstart()\nend\n");

caller = "imaCompile:Unknown file:-1"
  printf("main()");

end
-- Chose function name not
function not(a)
print("caller: ", caller, "-> not")
caller = "not:Unknown file:-1"
  if a then
caller = ":Unknown file:-1"
      return false

  else
caller = ":Unknown file:-1"
      return true

  end

end
-- Chose function name andBool
function andBool(a,b)
print("caller: ", caller, "-> andBool")
caller = "andBool:Unknown file:-1"
  if a then
caller = ":Unknown file:-1"
      if b then
caller = ":Unknown file:-1"
          return true

      else
caller = ":Unknown file:-1"
          return false

      end

  else
caller = ":Unknown file:-1"
      return false

  end

end
-- Chose function name nand
function nand(a,b)
print("caller: ", caller, "-> nand")
caller = "nand:Unknown file:-1"
  return not(andBool(a, b))

end
-- Chose function name xor
function xor(a,b)
print("caller: ", caller, "-> xor")
caller = "xor:Unknown file:-1"
  return nand(nand(a, nand(a, b)), nand(b, nand(a, b)))

end
-- Chose function name luaFunctionArgs
function luaFunctionArgs(indent,tree)
print("caller: ", caller, "-> luaFunctionArgs")
caller = "luaFunctionArgs:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      display(second(tree));

caller = ":Unknown file:-1"
      if isNil(cddr(tree)) then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf(",");

      end

caller = ":Unknown file:-1"
      luaFunctionArgs(indent, cddr(tree));

  end

end
-- Chose function name luaFunction
function luaFunction(indent,functionDefinition)
print("caller: ", caller, "-> luaFunction")
local fname =""
caller = "luaFunction:Unknown file:-1"
  fname = stringify(second(functionDefinition))
caller = "luaFunction:Unknown file:-1"
  printf("-- Chose function name %s", fname);

caller = "luaFunction:Unknown file:-1"
  printf("\nfunction %s(", fname);

caller = "luaFunction:Unknown file:-1"
  luaFunctionArgs(indent, third(functionDefinition));

caller = "luaFunction:Unknown file:-1"
  printf(")\n");

caller = "luaFunction:Unknown file:-1"
  printf("print(\"caller: \", caller, \"-> %s\")\n", fname);

caller = "luaFunction:Unknown file:-1"
  luaDeclarations(add1(indent), cdr(fourth(functionDefinition)));

caller = "luaFunction:Unknown file:-1"
  luaBody(fname, indent, cdr(fifth(functionDefinition)));

caller = "luaFunction:Unknown file:-1"
  printf("end\n");

end
-- Chose function name luaDeclarations
function luaDeclarations(indent,declarations)
print("caller: ", caller, "-> luaDeclarations")
local decl =nil
caller = "luaDeclarations:Unknown file:-1"
  if isNil(declarations) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      decl = first(declarations)
caller = ":Unknown file:-1"
      printf("local %s =", stringify(second(decl)));

caller = ":Unknown file:-1"
      luaExpressionStart(indent, third(decl));

caller = ":Unknown file:-1"
      printf("\n");

caller = ":Unknown file:-1"
      luaDeclarations(indent, cdr(declarations));

  end

end
-- Chose function name luaExpressionStart
function luaExpressionStart(indent,program)
print("caller: ", caller, "-> luaExpressionStart")
caller = "luaExpressionStart:Unknown file:-1"
  if isNil(program) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      if isList(program) then
caller = ":Unknown file:-1"
          if equalString(stringify(car(program)), "get-struct") then
caller = ":Unknown file:-1"
              printf("%s.%s", stringify(second(program)), stringify(third(program)));

          else
caller = ":Unknown file:-1"
              if equalString(stringify(car(program)), ">") then
caller = ":Unknown file:-1"
                  printf("greaterthan(");

caller = ":Unknown file:-1"
                  luaExpression(indent, cdr(program));

caller = ":Unknown file:-1"
                  printf(")");

              else
caller = ":Unknown file:-1"
                  if equalString(stringify(car(program)), "=") then
caller = ":Unknown file:-1"
                      printf("equal(");

caller = ":Unknown file:-1"
                      luaExpression(indent, cdr(program));

caller = ":Unknown file:-1"
                      printf(")");

                  else
caller = ":Unknown file:-1"
                      printf("%s(", stringify(car(program)));

caller = ":Unknown file:-1"
                      luaExpression(indent, cdr(program));

caller = ":Unknown file:-1"
                      printf(")");

                  end

              end

          end

      else
caller = ":Unknown file:-1"
          luaExpression(indent, program);

      end

  end

end
-- Chose function name luaExpression
function luaExpression(indent,program)
print("caller: ", caller, "-> luaExpression")
caller = "luaExpression:Unknown file:-1"
  if isNil(program) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      if isList(program) then
caller = ":Unknown file:-1"
          if isList(car(program)) then
caller = ":Unknown file:-1"
              luaExpressionStart(indent, car(program));

          else
caller = ":Unknown file:-1"
              display(car(program));

          end

caller = ":Unknown file:-1"
          if greaterthan(listLength(program), 1) then
caller = ":Unknown file:-1"
              printf(", ");

          else
          end

caller = ":Unknown file:-1"
          luaExpression(indent, cdr(program));

      else
caller = ":Unknown file:-1"
          display(program);

      end

  end

end
-- Chose function name luaStatement
function luaStatement(indent,statement)
print("caller: ", caller, "-> luaStatement")
caller = "luaStatement:Unknown file:-1"
  if equalString(stringify(car(statement)), "if") then
caller = ":Unknown file:-1"
      printIndent(indent);

caller = ":Unknown file:-1"
      printf("if ");

caller = ":Unknown file:-1"
      add1(indent);

caller = ":Unknown file:-1"
      luaExpressionStart(add1(indent), second(statement));

caller = ":Unknown file:-1"
      printf(" then\n");

caller = ":Unknown file:-1"
      luaBody(caller, add1(indent), cdr(third(statement)));

caller = ":Unknown file:-1"
      printIndent(indent);

caller = ":Unknown file:-1"
      printf("else\n");

caller = ":Unknown file:-1"
      luaBody(caller, add1(indent), cdr(fourth(statement)));

caller = ":Unknown file:-1"
      printIndent(indent);

caller = ":Unknown file:-1"
      printf("end\n");

  else
caller = ":Unknown file:-1"
      if equalString(stringify(car(statement)), "set") then
caller = ":Unknown file:-1"
          printIndent(indent);

caller = ":Unknown file:-1"
          printf("%s = ", stringify(second(statement)));

caller = ":Unknown file:-1"
          luaExpressionStart(add1(indent), third(statement));

      else
caller = ":Unknown file:-1"
          if equalString(stringify(car(statement)), "set-struct") then
caller = ":Unknown file:-1"
              printf("%s.%s = ", stringify(second(statement)), stringify(third(statement)));

caller = ":Unknown file:-1"
              luaExpressionStart(indent, fourth(statement));

          else
caller = ":Unknown file:-1"
              if equalString(stringify(car(statement)), "return") then
caller = ":Unknown file:-1"
                  printIndent(indent);

caller = ":Unknown file:-1"
                  printf("return ");

caller = ":Unknown file:-1"
                  if greaterthan(listLength(statement), 1) then
caller = ":Unknown file:-1"
                      luaExpressionStart(indent, second(statement));

                  else
                  end

caller = ":Unknown file:-1"
                  printf("\n");

              else
caller = ":Unknown file:-1"
                  printIndent(indent);

caller = ":Unknown file:-1"
                  luaExpressionStart(indent, statement);

caller = ":Unknown file:-1"
                  printf(";\n");

              end

          end

      end

  end

end
-- Chose function name luaBody
function luaBody(local_caller,indent,program)
print("caller: ", caller, "-> luaBody")
local statement =nil
caller = "luaBody:Unknown file:-1"
  if isNil(program) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      statement = car(program)
caller = ":Unknown file:-1"
      printf("caller = \"%s:%s:%d\"\n", local_caller, unBoxString(getTagFail(statement, boxString("filename"), boxString("Unknown file"))), unBoxInt(getTagFail(statement, boxString("line"), boxInt(-1))));

caller = ":Unknown file:-1"
      luaStatement(add1(indent), statement);

caller = ":Unknown file:-1"
      printf("\n");

caller = ":Unknown file:-1"
      luaBody(local_caller, indent, cdr(program));

  end

end
-- Chose function name luaFunctions
function luaFunctions(indent,program)
print("caller: ", caller, "-> luaFunctions")
caller = "luaFunctions:Unknown file:-1"
  if isNil(program) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      luaFunction(indent, car(program));

caller = ":Unknown file:-1"
      luaFunctions(indent, cdr(program));

  end

end
-- Chose function name luaProgram
function luaProgram(program)
print("caller: ", caller, "-> luaProgram")
caller = "luaProgram:Unknown file:-1"
  luaIncludes(nil);

caller = "luaProgram:Unknown file:-1"
  luaFunctions(0, cdr(third(program)));

end
-- Chose function name luaIncludes
function luaIncludes(nodes)
print("caller: ", caller, "-> luaIncludes")
caller = "luaIncludes:Unknown file:-1"
  printf("%s", "\nfunction luaDump(o)\n   if type(o) == 'table' then\n      local s = '{ '\n      for k,v in pairs(o) do\n         if type(k) ~= 'number' then k = '\"'..k..'\"' end\n         s = s .. '['..k..'] = ' .. luaDump(v) .. ','\n      end\n      return s .. '} '\n   else\n      return tostring(o)\n   end\nend\nprintf = function(s,...)\nreturn io.write(s:format(...))\nend -- function\n    \nfunction stringConcatenate(a,b)\nreturn a..b\nend\n    \nfunction getStringArray(index, arr)\nreturn arr[index]\nend\n       \nfunction luaWriteFile(name, data)  \nlocal file = io.open(name, \"w\")\nfile:write(data)\nfile:close(file)\nend\n    function luaSubstring(s, start, length)\nreturn string.sub(s, start, start+length)\nend\n    \n    function luaReadFile(file)\n      local f = assert(io.open(file, \"rb\"))\n      local content = f:read(\"*all\")      f:close()\n      return content\n    end\n     \nfunction equalString(a,b)\n        return a==b;\n     end\n    \n     function new()\n        return {};\n     end\n    \n     function isNil(val)\n        return val == nil;\n     end\n    \n     function getEnv(key)\n        return os.getenv(key);\n     end\n    \n    function panic(s)\n      print(s);\n    os.exit()\n    end\n    \n    function sub(a, b) \n      return a - b; \n    end\n\n    function mult(a, b) \n      return a * b;\n    end\n    \n    function greaterthan(a, b)\n      return a > b;\n    end\n    \n    function subf(a, b) \n      return a - b;\n    end\n    \n    function multf(a, b)\n      return a * b;\n    end\n    \n    function greaterthanf(a, b)\n      return a > b;\n    end\n    \n    function equal(a, b)\n      return a == b;\n    end\n    \n    function andBool(a, b)\n      return a == b;\n    end\n    \n    function string_length(s)\n      return strlen(s);\n    end\n    \n    function setSubString(target, start, source)\n      panic(\"stub\");\n      end\n    \n    function sub_string(s, start, length)\n      panic(\"stub\");\n    end\n    \n    function intToString(a)\n      panic(\"stub\")\n return a\n    end\n\n    function gc_malloc(size)\n      return \"\"\n    end\n    \n    function makeArray(length)\n      return {}\n    end\n    \n    function at(arr, index)\n      return arr[index+1];\n    end\n    \n    function setAt(array, index, value)\n      array[index+1] = value;\n    end\n    \n    function read_file(file)\n      local f = io.open(file, \"r\")\n      local content = \"\"\n      local length = 0\n\n      while f:read(0) ~= \"\" do\n          local current = f:read(\"*all\")\n\n          print(#current, length)\n          length = length + #current\n\n          content = content .. current\n      end\n\n      return content\n    end\n    \n    function write_file(filename, data)\n      local file = io.open(filename,'w')\n      file:write(tostring(data))\n      file:close()\n    end\n    \n    caller=\"main\";\n    \n    globalArgs={};\n    globalArgsCount=0;\n    globalTrace = false;\n    globalStepTrace = false;\n\n    function main()\n      globalArgs = arg;\n      globalArgsCount = #arg + 1;\n      return start();\n    end\n    \n");

end
-- Chose function name luaCompile
function luaCompile(filename)
print("caller: ", caller, "-> luaCompile")
local tree =nil
caller = "luaCompile:Unknown file:-1"
  tree = loadQuon(filename)
caller = "luaCompile:Unknown file:-1"
  tree = loadIncludes(tree)
caller = "luaCompile:Unknown file:-1"
  tree = macrowalk(tree)
caller = "luaCompile:Unknown file:-1"
  tree = macrosingle(tree, "luaWriteFile", "luaWriteFile")
caller = "luaCompile:Unknown file:-1"
  tree = macrosingle(tree, "luaReadFile", "luaReadFile")
caller = "luaCompile:Unknown file:-1"
  tree = macrosingle(tree, "string.len", "string.len")
caller = "luaCompile:Unknown file:-1"
  tree = macrosingle(tree, "luaSubstring", "luaSubstring")
caller = "luaCompile:Unknown file:-1"
  tree = macrosingle(tree, "string.len", "string.len")
caller = "luaCompile:Unknown file:-1"
  luaProgram(tree);

caller = "luaCompile:Unknown file:-1"
  printf("\n");

caller = "luaCompile:Unknown file:-1"
  printf("function main()\nglobalArgs = arg\nglobalArgsCount = #arg\nstart()\nend\n");

caller = "luaCompile:Unknown file:-1"
  printf("main()");

end
-- Chose function name javaFunctionArgs
function javaFunctionArgs(tree)
print("caller: ", caller, "-> javaFunctionArgs")
caller = "javaFunctionArgs:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      display(javaTypeMap(first(tree)));

caller = ":Unknown file:-1"
      printf(" ");

caller = ":Unknown file:-1"
      display(second(tree));

caller = ":Unknown file:-1"
      if isNil(cddr(tree)) then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf(",");

      end

caller = ":Unknown file:-1"
      javaFunctionArgs(cddr(tree));

  end

end
-- Chose function name javaLeaf
function javaLeaf(thisNode,indent)
print("caller: ", caller, "-> javaLeaf")
caller = "javaLeaf:Unknown file:-1"
  display(javaFuncMap(codeof(thisNode)));

end
-- Chose function name javaStructGetterExpression
function javaStructGetterExpression(thisNode,indent)
print("caller: ", caller, "-> javaStructGetterExpression")
caller = "javaStructGetterExpression:Unknown file:-1"
  if equalBox(boxString("structGetter"), subnameof(thisNode)) then
caller = ":Unknown file:-1"
      javaGetStruct(thisNode, indent);

  else
caller = ":Unknown file:-1"
      javaLeaf(thisNode, indent);

  end

end
-- Chose function name javaExpression
function javaExpression(node,indent)
print("caller: ", caller, "-> javaExpression")
caller = "javaExpression:Unknown file:-1"
  if isLeaf(node) then
caller = ":Unknown file:-1"
      display(javaFuncMap(codeof(node)));

  else
caller = ":Unknown file:-1"
      javaSubExpression(node, indent);

  end

end
-- Chose function name javaRecurList
function javaRecurList(expr,indent)
print("caller: ", caller, "-> javaRecurList")
caller = "javaRecurList:Unknown file:-1"
  if isEmpty(expr) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      javaExpression(car(expr), indent);

caller = ":Unknown file:-1"
      if isNil(cdr(expr)) then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf(", ");

caller = ":Unknown file:-1"
          javaRecurList(cdr(expr), indent);

      end

  end

end
-- Chose function name javaSubExpression
function javaSubExpression(tree,indent)
print("caller: ", caller, "-> javaSubExpression")
local thing =nil
caller = "javaSubExpression:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      if isNode(childrenof(tree)) then
caller = ":Unknown file:-1"
          javaSubExpression(childrenof(tree), indent);

      else
caller = ":Unknown file:-1"
          if isLeaf(tree) then
caller = ":Unknown file:-1"
              display(javaFuncMap(codeof(tree)));

          else
caller = ":Unknown file:-1"
              if equal(1, listLength(childrenof(tree))) then
caller = ":Unknown file:-1"
                  display(codeof(car(childrenof(tree))));

caller = ":Unknown file:-1"
                  if equalBox(boxString("return"), codeof(car(childrenof(tree)))) then
caller = ":Unknown file:-1"
                      printf("");

                  else
caller = ":Unknown file:-1"
                      printf("()");

                  end

              else
caller = ":Unknown file:-1"
                  thing = codeof(car(childrenof(tree)))
caller = ":Unknown file:-1"
                  if equalBox(boxSymbol("get-struct"), thing) then
caller = ":Unknown file:-1"
                      printf("%s.%s", stringify(codeof(second(childrenof(tree)))), stringify(codeof(third(childrenof(tree)))));

                  else
caller = ":Unknown file:-1"
                      if equalBox(boxSymbol("new"), thing) then
caller = ":Unknown file:-1"
                          printf("new %s()", stringify(codeof(third(childrenof(tree)))));

                      else
caller = ":Unknown file:-1"
                          printf("%s(", stringify(javaFuncMap(codeof(car(childrenof(tree))))));

caller = ":Unknown file:-1"
                          javaRecurList(cdr(childrenof(tree)), indent);

caller = ":Unknown file:-1"
                          printf(")");

                      end

                  end

              end

          end

      end

  end

end
-- Chose function name javaIf
function javaIf(node,indent)
print("caller: ", caller, "-> javaIf")
caller = "javaIf:Unknown file:-1"
  newLine(indent);

caller = "javaIf:Unknown file:-1"
  printf("if ( ");

caller = "javaIf:Unknown file:-1"
  javaExpression(car(first(childrenof(node))), 0);

caller = "javaIf:Unknown file:-1"
  printf(") {");

caller = "javaIf:Unknown file:-1"
  javaBody(second(childrenof(node)), add1(indent));

caller = "javaIf:Unknown file:-1"
  newLine(indent);

caller = "javaIf:Unknown file:-1"
  printf("} else {");

caller = "javaIf:Unknown file:-1"
  javaBody(third(childrenof(node)), add1(indent));

caller = "javaIf:Unknown file:-1"
  newLine(indent);

caller = "javaIf:Unknown file:-1"
  printf("}");

end
-- Chose function name javaSetStruct
function javaSetStruct(node,indent)
print("caller: ", caller, "-> javaSetStruct")
caller = "javaSetStruct:Unknown file:-1"
  newLine(indent);

caller = "javaSetStruct:Unknown file:-1"
  printf("%s.%s = ", stringify(first(codeof(node))), stringify(second(codeof(node))));

caller = "javaSetStruct:Unknown file:-1"
  javaExpression(childrenof(node), indent);

caller = "javaSetStruct:Unknown file:-1"
  printf(";");

end
-- Chose function name javaGetStruct
function javaGetStruct(node,indent)
print("caller: ", caller, "-> javaGetStruct")
caller = "javaGetStruct:Unknown file:-1"
  newLine(indent);

caller = "javaGetStruct:Unknown file:-1"
  printf("%s.%s", stringify(first(codeof(node))), stringify(second(codeof(node))));

end
-- Chose function name javaSet
function javaSet(node,indent)
print("caller: ", caller, "-> javaSet")
caller = "javaSet:Unknown file:-1"
  newLine(indent);

caller = "javaSet:Unknown file:-1"
  printf("%s = ", stringify(first(codeof(node))));

caller = "javaSet:Unknown file:-1"
  javaExpression(childrenof(node), indent);

caller = "javaSet:Unknown file:-1"
  printf(";");

end
-- Chose function name javaStatement
function javaStatement(node,indent)
print("caller: ", caller, "-> javaStatement")
caller = "javaStatement:Unknown file:-1"
  if equalBox(boxString("setter"), subnameof(node)) then
caller = ":Unknown file:-1"
      javaSet(node, indent);

  else
caller = ":Unknown file:-1"
      if equalBox(boxString("structSetter"), subnameof(node)) then
caller = ":Unknown file:-1"
          javaSetStruct(node, indent);

      else
caller = ":Unknown file:-1"
          if equalBox(boxString("if"), subnameof(node)) then
caller = ":Unknown file:-1"
              javaIf(node, indent);

          else
caller = ":Unknown file:-1"
              if equalBox(boxString("returnvoid"), subnameof(node)) then
caller = ":Unknown file:-1"
                  newLine(indent);

caller = ":Unknown file:-1"
                  printf("return;");

              else
caller = ":Unknown file:-1"
                  newLine(indent);

caller = ":Unknown file:-1"
                  javaExpression(childrenof(node), indent);

caller = ":Unknown file:-1"
                  printf(";");

              end

          end

      end

  end

end
-- Chose function name javaBody
function javaBody(tree,indent)
print("caller: ", caller, "-> javaBody")
caller = "javaBody:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      printIndent(indent);

caller = ":Unknown file:-1"
      printf("");

caller = ":Unknown file:-1"
      javaStatement(car(tree), indent);

caller = ":Unknown file:-1"
      javaBody(cdr(tree), indent);

  end

end
-- Chose function name javaDeclarations
function javaDeclarations(decls,indent)
print("caller: ", caller, "-> javaDeclarations")
local decl =nil
caller = "javaDeclarations:Unknown file:-1"
  if isEmpty(decls) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      decl = car(decls)
caller = ":Unknown file:-1"
      printf("%s %s = ", stringify(javaTypeMap(first(decl))), stringify(second(decl)));

caller = ":Unknown file:-1"
      display(javaFuncMap(third(decl)));

caller = ":Unknown file:-1"
      printf(";\n");

caller = ":Unknown file:-1"
      javaDeclarations(cdr(decls), indent);

  end

end
-- Chose function name javaFunction
function javaFunction(node)
print("caller: ", caller, "-> javaFunction")
local name =nil
caller = "javaFunction:Unknown file:-1"
  name = subnameof(node)
caller = "javaFunction:Unknown file:-1"
  printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));

caller = "javaFunction:Unknown file:-1"
  newLine(0);

caller = "javaFunction:Unknown file:-1"
  if isNil(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      newLine(0);

caller = ":Unknown file:-1"
      printf("public %s %s(", stringify(javaTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));

caller = ":Unknown file:-1"
      javaFunctionArgs(cdr(assoc("intype", cdr(node))));

caller = ":Unknown file:-1"
      printf(") {");

caller = ":Unknown file:-1"
      newLine(1);

caller = ":Unknown file:-1"
      javaDeclarations(declarationsof(node), 1);

caller = ":Unknown file:-1"
      if inList(toStr(name), noStackTrace()) then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf("");

      end

caller = ":Unknown file:-1"
      if inList(toStr(name), noStackTrace()) then
caller = ":Unknown file:-1"
          printf("");

      else
      end

caller = ":Unknown file:-1"
      javaBody(childrenof(node), 1);

caller = ":Unknown file:-1"
      if inList(toStr(name), noStackTrace()) then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          if equalString("void", stringify(javaTypeMap(cdr(assoc("outtype", cdr(node)))))) then
caller = ":Unknown file:-1"
              printf("\nif (globalTrace)\n   System.out. printf(\"Leaving %s\\n\");\n", stringify(name));

          else
caller = ":Unknown file:-1"
              printf("");

          end

      end

caller = ":Unknown file:-1"
      printf("\n}\n");

  end

end
-- Chose function name javaFunctions
function javaFunctions(tree)
print("caller: ", caller, "-> javaFunctions")
caller = "javaFunctions:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      javaFunction(car(tree));

caller = ":Unknown file:-1"
      javaFunctions(cdr(tree));

  end

end
-- Chose function name javaIncludes
function javaIncludes(nodes)
print("caller: ", caller, "-> javaIncludes")
caller = "javaIncludes:Unknown file:-1"
  printf("%s", "public void panic(String s) {System.exit(1);}\n");

caller = "javaIncludes:Unknown file:-1"
  printf("%s", "public void exit(Integer s) {System.exit(s);}\n");

caller = "javaIncludes:Unknown file:-1"
  printf("%s", "public int sub(int a, int b) { return a - b; }\n");

caller = "javaIncludes:Unknown file:-1"
  printf("%s", "public Integer mult(int a, int b) { return a * b; }\n");

caller = "javaIncludes:Unknown file:-1"
  printf("%s", "public boolean greaterthan(int a, int b) { return a > b; }\n");

caller = "javaIncludes:Unknown file:-1"
  printf("%s", "public double subf(double a, double b) { return a - b; }\n");

caller = "javaIncludes:Unknown file:-1"
  printf("%s", "public double multf(double a, double b) { return a * b; }\n");

caller = "javaIncludes:Unknown file:-1"
  printf("%s", "public boolean greaterthanf(double a, double b) { return a > b; }\n");

caller = "javaIncludes:Unknown file:-1"
  printf("%s", "public boolean equal(int a, int b) { return a == b; }\n");

caller = "javaIncludes:Unknown file:-1"
  printf("%s", "public boolean equalString(String a, String b) { return a.equals(b); }\n");

caller = "javaIncludes:Unknown file:-1"
  printf("%s", "public int string_length(String s) { return s.length();}\n");

caller = "javaIncludes:Unknown file:-1"
  printf("%s", "public String stringConcatenate(String s1, String s2) { return s1 + s2; }\n");

caller = "javaIncludes:Unknown file:-1"
  printf("%s", "public int strcmp(String s1, String s2) { return s1.compareTo(s2);}\n");

caller = "javaIncludes:Unknown file:-1"
  printf("%s", "public String read_file(String filename) {try { return new String(Files.readAllBytes(Paths.get(filename)));} catch (Exception e) {panic(\"Could not read file\");return \"\";}}\n");

caller = "javaIncludes:Unknown file:-1"
  printf("%s", "public void write_file(String filename, String data) {try {Files.write(Paths.get(filename), data.getBytes(\"UTF-8\"));} catch (Exception e) {panic(\"Could not write file\");}}\n");

caller = "javaIncludes:Unknown file:-1"
  printf("%s", "public String sub_string(String s, int start, int length) {\nreturn s.substring(start, start+length);\n}\n\n\n\n");

caller = "javaIncludes:Unknown file:-1"
  printf("%s", "public String intToString(int num) { char c=(char) num;  String s=Character.toString(c); return s;}");

caller = "javaIncludes:Unknown file:-1"
  printf("%s", "public String character(int num) { char c=(char) num;  String s=Character.toString(c); return s;}");

caller = "javaIncludes:Unknown file:-1"
  printf("%s", "public String getStringArray(int index, String[] arr) { return arr[index];}");

end
-- Chose function name javaTypeDecl
function javaTypeDecl(l)
print("caller: ", caller, "-> javaTypeDecl")
caller = "javaTypeDecl:Unknown file:-1"
  if greaterthan(listLength(l), 2) then
caller = ":Unknown file:-1"
      printIndent(1);

caller = ":Unknown file:-1"
      printf("%s %s;\n", stringify(javaTypeMap(listLast(l))), stringify(first(l)));

  else
caller = ":Unknown file:-1"
      printIndent(1);

caller = ":Unknown file:-1"
      printf("%s %s;\n", stringify(javaTypeMap(listLast(l))), stringify(car(l)));

  end

end
-- Chose function name javaStructComponents
function javaStructComponents(node)
print("caller: ", caller, "-> javaStructComponents")
caller = "javaStructComponents:Unknown file:-1"
  if isEmpty(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      javaTypeDecl(car(node));

caller = ":Unknown file:-1"
      javaStructComponents(cdr(node));

  end

end
-- Chose function name javaStruct
function javaStruct(node)
print("caller: ", caller, "-> javaStruct")
caller = "javaStruct:Unknown file:-1"
  javaStructComponents(cdr(car(node)));

end
-- Chose function name javaTypeMap
function javaTypeMap(aSym)
print("caller: ", caller, "-> javaTypeMap")
local symMap =nil
caller = "javaTypeMap:Unknown file:-1"
  symMap = alistCons(boxSymbol("pair"), boxSymbol("Box"), alistCons(boxSymbol("bool"), boxSymbol("boolean"), alistCons(boxSymbol("box"), boxSymbol("Box"), alistCons(boxSymbol("list"), boxSymbol("Box"), alistCons(boxSymbol("Box*"), boxSymbol("Box"), alistCons(boxSymbol("struct"), boxSymbol(""), alistCons(boxSymbol("int"), boxSymbol("Integer"), alistCons(boxSymbol("float"), boxSymbol("double"), alistCons(boxSymbol("stringArray"), boxSymbol("String[]"), alistCons(boxSymbol("string"), boxSymbol("String"), nil))))))))))
caller = "javaTypeMap:Unknown file:-1"
  if truthy(assoc(stringify(aSym), symMap)) then
caller = ":Unknown file:-1"
      return cdr(assoc(stringify(aSym), symMap))

  else
caller = ":Unknown file:-1"
      return aSym

  end

end
-- Chose function name javaTypesNoDeclare
function javaTypesNoDeclare()
print("caller: ", caller, "-> javaTypesNoDeclare")
local syms =nil
caller = "javaTypesNoDeclare:Unknown file:-1"
  syms = cons(boxString("pair"), cons(boxString("box"), nil))
caller = "javaTypesNoDeclare:Unknown file:-1"
  return syms

end
-- Chose function name javaFuncMap
function javaFuncMap(aSym)
print("caller: ", caller, "-> javaFuncMap")
local symMap =nil
caller = "javaFuncMap:Unknown file:-1"
  if equalString("symbol", boxType(aSym)) then
caller = ":Unknown file:-1"
      symMap = alistCons(boxSymbol("printf"), boxSymbol("System.out.printf"), alistCons(boxSymbol(stringConcatenate("q", "log")), boxSymbol("System.err.printf"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("luaSubstring"), boxSymbol("sub_string"), alistCons(boxSymbol("luaReadFile"), boxSymbol("read_file"), alistCons(boxSymbol("luaWriteFile"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string.len"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("null"), nil)))))))))
caller = ":Unknown file:-1"
      if truthy(assoc(stringify(aSym), symMap)) then
caller = ":Unknown file:-1"
          return cdr(assoc(stringify(aSym), symMap))

      else
caller = ":Unknown file:-1"
          return aSym

      end

  else
caller = ":Unknown file:-1"
      return aSym

  end

end
-- Chose function name javaType
function javaType(node)
print("caller: ", caller, "-> javaType")
caller = "javaType:Unknown file:-1"
  if equalBox(subnameof(node), boxString("struct")) then
caller = ":Unknown file:-1"
      printf("\npublic class %s {\n", stringify(first(codeof(node))));

caller = ":Unknown file:-1"
      printf("\npublic String caller =\"\";");

caller = ":Unknown file:-1"
      javaStruct(cdr(codeof(node)));

caller = ":Unknown file:-1"
      printf("\n};\n");

  else
caller = ":Unknown file:-1"
      if inList(boxString(stringify(first(codeof(node)))), javaTypesNoDeclare()) then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf("public class %s extends %s {};\n", stringify(first(codeof(node))), stringify(javaTypeMap(listLast(codeof(node)))));

      end

  end

end
-- Chose function name javaTypes
function javaTypes(nodes)
print("caller: ", caller, "-> javaTypes")
caller = "javaTypes:Unknown file:-1"
  if isEmpty(nodes) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      javaType(car(nodes));

caller = ":Unknown file:-1"
      javaTypes(cdr(nodes));

  end

end
-- Chose function name javaCompile
function javaCompile(filename)
print("caller: ", caller, "-> javaCompile")
local programStr =""
local tree =nil
local program =nil
caller = "javaCompile:Unknown file:-1"
  printf("%s", "package quonverter;\n");

caller = "javaCompile:Unknown file:-1"
  printf("%s", "import java.nio.file.Files;\n");

caller = "javaCompile:Unknown file:-1"
  printf("%s", "import java.nio.file.Paths;\n");

caller = "javaCompile:Unknown file:-1"
  printf("%s", "import java.io.IOException;\n");

caller = "javaCompile:Unknown file:-1"
  printf("%s", "import java.io.UnsupportedEncodingException;\n");

caller = "javaCompile:Unknown file:-1"
  printf("class MyProgram {\n");

caller = "javaCompile:Unknown file:-1"
  printf("\npublic String caller =\"\";");

caller = "javaCompile:Unknown file:-1"
  programStr = luaReadFile(filename)
caller = "javaCompile:Unknown file:-1"
  tree = readSexpr(programStr, filename)
caller = "javaCompile:Unknown file:-1"
  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), nil)))
caller = "javaCompile:Unknown file:-1"
  program = mergeIncludes(program)
caller = "javaCompile:Unknown file:-1"
  javaIncludes(cdr(assoc("includes", program)));

caller = "javaCompile:Unknown file:-1"
  javaTypes(childrenof(cdr(assoc("types", program))));

caller = "javaCompile:Unknown file:-1"
  printf("public boolean globalStackTrace = false;\n");

caller = "javaCompile:Unknown file:-1"
  printf("public boolean globalStepTrace = false;\n");

caller = "javaCompile:Unknown file:-1"
  printf("public boolean globalTrace = false;\n");

caller = "javaCompile:Unknown file:-1"
  printf("public boolean releaseMode = false;\n");

caller = "javaCompile:Unknown file:-1"
  printf("public String FILE = null;\n");

caller = "javaCompile:Unknown file:-1"
  printf("public Integer LINE = 0;\n");

caller = "javaCompile:Unknown file:-1"
  printf("public static Integer globalArgsCount = 0;\n");

caller = "javaCompile:Unknown file:-1"
  printf("public static String globalArgs[];\n");

caller = "javaCompile:Unknown file:-1"
  printf("\npublic boolean isNil(Box p) {\n    return p == null;\n}\n\n\n");

caller = "javaCompile:Unknown file:-1"
  javaFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));

caller = "javaCompile:Unknown file:-1"
  printf("%s", "public static void main(String args[]) {\nglobalArgs = args;\nglobalArgsCount = args.length;MyProgram mp = new MyProgram(); mp.start();\n}");

caller = "javaCompile:Unknown file:-1"
  printf("}\n");

end
-- Chose function name node2Compile
function node2Compile(filename)
print("caller: ", caller, "-> node2Compile")
local programStr =""
local tree =nil
local program =nil
caller = "node2Compile:Unknown file:-1"
  programStr = luaReadFile(filename)
caller = "node2Compile:Unknown file:-1"
  tree = readSexpr(programStr, filename)
caller = "node2Compile:Unknown file:-1"
  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), emptyList())))
caller = "node2Compile:Unknown file:-1"
  program = mergeIncludes(program)
caller = "node2Compile:Unknown file:-1"
  qlog("Loading shim node2\n");

caller = "node2Compile:Unknown file:-1"
  program = buildProg(cons(boxString("q/shims/node2.qon"), getIncludes(program)), getTypes(program), getFunctions(program))
caller = "node2Compile:Unknown file:-1"
  return cons(node2Includes(cdr(assoc("includes", program))), cons(boxString("\nvar globalStackTrace = NULL;\n"), cons(boxString("\nvar caller = \"\";\n"), cons(boxString("\nfunction isNil(p) {\n    return p == NULL;\n}\n\n"), cons(node2Functions(cdr(assoc("children", cdr(cdr(assoc("functions", program)))))), cons(boxString("\n"), cons(boxString("const [asfdasdf, ...qwerqwer] = process.argv;"), cons(boxString("globalArgs = qwerqwer;"), cons(boxString("globalArgsCount = qwerqwer.length;"), cons(boxString("start();\n"), emptyList()))))))))))

end
-- Chose function name node2Includes
function node2Includes(nodes)
print("caller: ", caller, "-> node2Includes")
caller = "node2Includes:Unknown file:-1"
  return cons(boxString("function read_file(filename) {return fs.readFileSync(filename);}\n"), cons(boxString("function write_file(filename, data) {fs.writeFileSync(filename, data);}\n"), cons(boxString("var util = require('util');\n"), cons(boxString("function printf() {process.stdout.write(util.format.apply(this, arguments));}\n"), cons(boxString("function qlog()   {process.stderr.write(util.format.apply(this, arguments));}\n"), cons(boxString("var fs = require('fs');\n"), cons(boxString("function equalString(a,b) {if (a==null) {return false;}if (b==null) {return false;}return a.toString()===b.toString() }\n"), cons(boxString("function panic(s){console.trace(s);process.exit(1);}\n"), cons(boxString("function dump(s){console.log(s)}"), cons(boxString("function sub(a, b) { return a - b; }\n"), cons(boxString("function mult(a, b) { return a * b; }\n"), cons(boxString("function greaterthan(a, b) { return a > b; }\n"), cons(boxString("function subf(a, b) { return a - b; }\n"), cons(boxString("function multf(a, b) { return a * b; }\n"), cons(boxString("function greaterthanf(a, b) { return a > b; }\n"), cons(boxString("function equal(a, b) { return a == b; }\n"), cons(boxString("function andBool(a, b) { return a == b;}\n"), cons(boxString("function string_length(s) { return s.length;}\n"), cons(boxString("function sub_string(str, start, len) {str = ''+str;return str.substring(start, start+len)};\n"), cons(boxString("function stringConcatenate(a, b) { return a + b}\n"), cons(boxString("function intToString(a) {}\n\n\n"), cons(boxString("function gc_malloc( size ) {\nreturn {};\n}\n\n"), cons(boxString("function makeArray(length) {\n   return [];\n}\n\n"), cons(boxString("function at(arr, index) {\n  return arr[index];\n}\n\n"), cons(boxString("function setAt(array, index, value) {\n    array[index] = value;\n}\n\n"), cons(boxString("function getStringArray(index, strs) {\nreturn strs[index];\n}\n\n"), cons(boxString("var NULL = null;"), cons(boxString("var globalArgs;\nvar globalArgsCount;\nvar globalTrace = false;\nvar globalStepTrace = false;\nvar releaseMode = false;\n"), cons(boxString("function character(num) {}"), nil)))))))))))))))))))))))))))))

end
-- Chose function name node2Functions
function node2Functions(tree)
print("caller: ", caller, "-> node2Functions")
caller = "node2Functions:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return emptyList()

  else
caller = ":Unknown file:-1"
      return cons(node2Function(car(tree)), node2Functions(cdr(tree)))

  end

end
-- Chose function name node2Function
function node2Function(node)
print("caller: ", caller, "-> node2Function")
local name =nil
caller = "node2Function:Unknown file:-1"
  if isNil(node) then
caller = ":Unknown file:-1"
      return emptyList()

  else
caller = ":Unknown file:-1"
      name = subnameof(node)
caller = ":Unknown file:-1"
      return cons(boxString("\n\n//Building function "), cons(boxString(stringify(name)), cons(boxString(" from line: "), cons(boxString(stringify(getTag(name, boxString("line")))), nil))))

  end

caller = "node2Function:Unknown file:-1"
  return emptyList()

end
-- Chose function name node2FunctionArgs
function node2FunctionArgs(tree)
print("caller: ", caller, "-> node2FunctionArgs")
caller = "node2FunctionArgs:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return emptyList()

  else
caller = ":Unknown file:-1"
      return cons(second(tree), cons(tern(isNil(cddr(tree)), boxString(""), boxString(",")), cons(node2FunctionArgs(cddr(tree)), emptyList())))

  end

end
-- Chose function name node2Declarations
function node2Declarations(decls,indent)
print("caller: ", caller, "-> node2Declarations")
local decl =nil
caller = "node2Declarations:Unknown file:-1"
  if isEmpty(decls) then
caller = ":Unknown file:-1"
      return emptyList()

  else
caller = ":Unknown file:-1"
      decl = car(decls)
caller = ":Unknown file:-1"
      return cons(boxString("var %s = "), cons(second(decl), cons(nodeFuncMap(third(decl)), cons(boxString(";\n"), node2Declarations(cdr(decls), indent)))))

  end

end
-- Chose function name nodeFunctionArgs
function nodeFunctionArgs(tree)
print("caller: ", caller, "-> nodeFunctionArgs")
caller = "nodeFunctionArgs:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      display(second(tree));

caller = ":Unknown file:-1"
      if isNil(cddr(tree)) then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf(",");

      end

caller = ":Unknown file:-1"
      nodeFunctionArgs(cddr(tree));

  end

end
-- Chose function name nodeLeaf
function nodeLeaf(thisNode,indent)
print("caller: ", caller, "-> nodeLeaf")
caller = "nodeLeaf:Unknown file:-1"
  display(nodeFuncMap(codeof(thisNode)));

end
-- Chose function name nodeStructGetterExpression
function nodeStructGetterExpression(thisNode,indent)
print("caller: ", caller, "-> nodeStructGetterExpression")
caller = "nodeStructGetterExpression:Unknown file:-1"
  if equalBox(boxString("structGetter"), subnameof(thisNode)) then
caller = ":Unknown file:-1"
      nodeGetStruct(thisNode, indent);

  else
caller = ":Unknown file:-1"
      nodeLeaf(thisNode, indent);

  end

end
-- Chose function name nodeExpression
function nodeExpression(node,indent)
print("caller: ", caller, "-> nodeExpression")
caller = "nodeExpression:Unknown file:-1"
  if isLeaf(node) then
caller = ":Unknown file:-1"
      display(nodeFuncMap(codeof(node)));

  else
caller = ":Unknown file:-1"
      nodeSubExpression(node, indent);

  end

end
-- Chose function name nodeRecurList
function nodeRecurList(expr,indent)
print("caller: ", caller, "-> nodeRecurList")
caller = "nodeRecurList:Unknown file:-1"
  if isEmpty(expr) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      nodeExpression(car(expr), indent);

caller = ":Unknown file:-1"
      if isNil(cdr(expr)) then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf(", ");

caller = ":Unknown file:-1"
          nodeRecurList(cdr(expr), indent);

      end

  end

end
-- Chose function name nodeSubExpression
function nodeSubExpression(tree,indent)
print("caller: ", caller, "-> nodeSubExpression")
local thing =nil
caller = "nodeSubExpression:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      if isNode(childrenof(tree)) then
caller = ":Unknown file:-1"
          nodeSubExpression(childrenof(tree), indent);

      else
caller = ":Unknown file:-1"
          if isLeaf(tree) then
caller = ":Unknown file:-1"
              display(nodeFuncMap(codeof(tree)));

          else
caller = ":Unknown file:-1"
              if equal(1, listLength(childrenof(tree))) then
caller = ":Unknown file:-1"
                  display(codeof(car(childrenof(tree))));

caller = ":Unknown file:-1"
                  if equalBox(boxString("return"), codeof(car(childrenof(tree)))) then
caller = ":Unknown file:-1"
                      printf("");

                  else
caller = ":Unknown file:-1"
                      printf("()");

                  end

              else
caller = ":Unknown file:-1"
                  thing = codeof(car(childrenof(tree)))
caller = ":Unknown file:-1"
                  if equalBox(boxSymbol("get-struct"), thing) then
caller = ":Unknown file:-1"
                      printf("%s.%s", stringify(codeof(second(childrenof(tree)))), stringify(codeof(third(childrenof(tree)))));

                  else
caller = ":Unknown file:-1"
                      if equalBox(boxSymbol("new"), thing) then
caller = ":Unknown file:-1"
                          printf("{}");

                      else
caller = ":Unknown file:-1"
                          printf("%s(", stringify(nodeFuncMap(codeof(car(childrenof(tree))))));

caller = ":Unknown file:-1"
                          nodeRecurList(cdr(childrenof(tree)), indent);

caller = ":Unknown file:-1"
                          printf(")");

                      end

                  end

              end

          end

      end

  end

end
-- Chose function name nodeIf
function nodeIf(node,indent)
print("caller: ", caller, "-> nodeIf")
caller = "nodeIf:Unknown file:-1"
  newLine(indent);

caller = "nodeIf:Unknown file:-1"
  printf("if ( ");

caller = "nodeIf:Unknown file:-1"
  nodeExpression(car(first(childrenof(node))), 0);

caller = "nodeIf:Unknown file:-1"
  printf(") {");

caller = "nodeIf:Unknown file:-1"
  nodeBody(second(childrenof(node)), add1(indent));

caller = "nodeIf:Unknown file:-1"
  newLine(indent);

caller = "nodeIf:Unknown file:-1"
  printf("} else {");

caller = "nodeIf:Unknown file:-1"
  nodeBody(third(childrenof(node)), add1(indent));

caller = "nodeIf:Unknown file:-1"
  newLine(indent);

caller = "nodeIf:Unknown file:-1"
  printf("}");

end
-- Chose function name nodeGetStruct
function nodeGetStruct(node,indent)
print("caller: ", caller, "-> nodeGetStruct")
caller = "nodeGetStruct:Unknown file:-1"
  newLine(indent);

caller = "nodeGetStruct:Unknown file:-1"
  printf("%s.%s", stringify(first(codeof(node))), stringify(second(codeof(node))));

end
-- Chose function name nodeSet
function nodeSet(node,indent)
print("caller: ", caller, "-> nodeSet")
caller = "nodeSet:Unknown file:-1"
  newLine(indent);

caller = "nodeSet:Unknown file:-1"
  printf("%s = ", stringify(first(codeof(node))));

caller = "nodeSet:Unknown file:-1"
  nodeExpression(childrenof(node), indent);

end
-- Chose function name nodeSetStruct
function nodeSetStruct(node,indent)
print("caller: ", caller, "-> nodeSetStruct")
caller = "nodeSetStruct:Unknown file:-1"
  newLine(indent);

caller = "nodeSetStruct:Unknown file:-1"
  printf("%s.%s = ", stringify(first(codeof(node))), stringify(second(codeof(node))));

caller = "nodeSetStruct:Unknown file:-1"
  nodeExpression(childrenof(node), indent);

end
-- Chose function name nodeStatement
function nodeStatement(node,indent)
print("caller: ", caller, "-> nodeStatement")
caller = "nodeStatement:Unknown file:-1"
  if equalBox(boxString("setter"), subnameof(node)) then
caller = ":Unknown file:-1"
      nodeSet(node, indent);

  else
caller = ":Unknown file:-1"
      if equalBox(boxString("structSetter"), subnameof(node)) then
caller = ":Unknown file:-1"
          nodeSetStruct(node, indent);

      else
caller = ":Unknown file:-1"
          if equalBox(boxString("if"), subnameof(node)) then
caller = ":Unknown file:-1"
              nodeIf(node, indent);

          else
caller = ":Unknown file:-1"
              if equalBox(boxString("returnvoid"), subnameof(node)) then
caller = ":Unknown file:-1"
                  newLine(indent);

caller = ":Unknown file:-1"
                  printf("return");

              else
caller = ":Unknown file:-1"
                  newLine(indent);

caller = ":Unknown file:-1"
                  nodeExpression(childrenof(node), indent);

              end

          end

      end

  end

caller = "nodeStatement:Unknown file:-1"
  printf(";\n");

end
-- Chose function name nodeBody
function nodeBody(tree,indent)
print("caller: ", caller, "-> nodeBody")
caller = "nodeBody:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      printIndent(indent);

caller = ":Unknown file:-1"
      printf("%s", "if (globalStepTrace) {console.log(new Error(\"StepTrace \\n\"));}\n");

caller = ":Unknown file:-1"
      nodeStatement(car(tree), indent);

caller = ":Unknown file:-1"
      nodeBody(cdr(tree), indent);

  end

end
-- Chose function name nodeDeclarations
function nodeDeclarations(decls,indent)
print("caller: ", caller, "-> nodeDeclarations")
local decl =nil
caller = "nodeDeclarations:Unknown file:-1"
  if isEmpty(decls) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      decl = car(decls)
caller = ":Unknown file:-1"
      printf("var %s = ", stringify(second(decl)));

caller = ":Unknown file:-1"
      display(nodeFuncMap(third(decl)));

caller = ":Unknown file:-1"
      printf(";\n");

caller = ":Unknown file:-1"
      nodeDeclarations(cdr(decls), indent);

  end

end
-- Chose function name nodeFunction
function nodeFunction(node)
print("caller: ", caller, "-> nodeFunction")
local name =nil
caller = "nodeFunction:Unknown file:-1"
  name = subnameof(node)
caller = "nodeFunction:Unknown file:-1"
  printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));

caller = "nodeFunction:Unknown file:-1"
  newLine(0);

caller = "nodeFunction:Unknown file:-1"
  if isNil(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      newLine(0);

caller = ":Unknown file:-1"
      printf("function %s(", stringify(subnameof(node)));

caller = ":Unknown file:-1"
      nodeFunctionArgs(cdr(assoc("intype", cdr(node))));

caller = ":Unknown file:-1"
      printf(") {");

caller = ":Unknown file:-1"
      newLine(1);

caller = ":Unknown file:-1"
      nodeDeclarations(declarationsof(node), 1);

caller = ":Unknown file:-1"
      if releaseMode then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf("\nif (globalTrace)\n    {printf(\"%s at %s:%s\\n\");}\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

      end

caller = ":Unknown file:-1"
      if releaseMode then
caller = ":Unknown file:-1"
          printf("");

      else
      end

caller = ":Unknown file:-1"
      nodeBody(childrenof(node), 1);

caller = ":Unknown file:-1"
      if releaseMode then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf("\nif (globalTrace)\n    {printf(\"Leaving %s\\n\");}\n", stringify(name));

      end

caller = ":Unknown file:-1"
      printf("\n}\n");

  end

end
-- Chose function name nodeForwardDeclaration
function nodeForwardDeclaration(node)
print("caller: ", caller, "-> nodeForwardDeclaration")
caller = "nodeForwardDeclaration:Unknown file:-1"
  if isNil(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      printf("\n%s %s(", stringify(nodeTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));

caller = ":Unknown file:-1"
      nodeFunctionArgs(cdr(assoc("intype", cdr(node))));

caller = ":Unknown file:-1"
      printf(");");

  end

end
-- Chose function name nodeForwardDeclarations
function nodeForwardDeclarations(tree)
print("caller: ", caller, "-> nodeForwardDeclarations")
caller = "nodeForwardDeclarations:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      nodeForwardDeclaration(car(tree));

caller = ":Unknown file:-1"
      nodeForwardDeclarations(cdr(tree));

  end

end
-- Chose function name nodeFunctions
function nodeFunctions(tree)
print("caller: ", caller, "-> nodeFunctions")
caller = "nodeFunctions:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      nodeFunction(car(tree));

caller = ":Unknown file:-1"
      nodeFunctions(cdr(tree));

  end

end
-- Chose function name nodeIncludes
function nodeIncludes(nodes)
print("caller: ", caller, "-> nodeIncludes")
caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function read_file(filename) {return fs.readFileSync(filename);}\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function write_file(filename, data) {fs.writeFileSync(filename, data);}\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "var util = require('util');\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function printf() {process.stdout.write(util.format.apply(this, arguments));}\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function qlog()   {process.stderr.write(util.format.apply(this, arguments));}\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "var fs = require('fs');\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function equalString(a,b) {if (a==null) {return false;}if (b==null) {return false;}return a.toString()===b.toString() }\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function panic(s){console.trace(s);process.exit(1);}\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function dump(s){console.log(s)}");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function sub(a, b) { return a - b; }\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function mult(a, b) { return a * b; }\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function greaterthan(a, b) { return a > b; }\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function subf(a, b) { return a - b; }\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function multf(a, b) { return a * b; }\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function greaterthanf(a, b) { return a > b; }\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function equal(a, b) { return a == b; }\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function andBool(a, b) { return a == b;}\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function string_length(s) { return s.length;}\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function sub_string(str, start, len) {str = ''+str;return str.substring(start, start+len)};\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function stringConcatenate(a, b) { return a + b}\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function intToString(a) {}\n\n\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function gc_malloc( size ) {\nreturn {};\n}\n\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function makeArray(length) {\n   return [];\n}\n\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function at(arr, index) {\n  return arr[index];\n}\n\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function setAt(array, index, value) {\n    array[index] = value;\n}\n\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function getStringArray(index, strs) {\nreturn strs[index];\n}\n\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "var NULL = null;");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "var globalArgs;\nvar globalArgsCount;\nvar globalTrace = false;\nvar globalStepTrace = false;\nvar releaseMode = false;\n");

caller = "nodeIncludes:Unknown file:-1"
  printf("%s", "function character(num) {}");

end
-- Chose function name nodeTypeDecl
function nodeTypeDecl(l)
print("caller: ", caller, "-> nodeTypeDecl")
caller = "nodeTypeDecl:Unknown file:-1"
  if greaterthan(listLength(l), 2) then
caller = ":Unknown file:-1"
      printIndent(1);

caller = ":Unknown file:-1"
      printf("%s %s %s;\n", stringify(second(l)), stringify(nodeTypeMap(listLast(l))), stringify(first(l)));

  else
caller = ":Unknown file:-1"
      printIndent(1);

caller = ":Unknown file:-1"
      printf("%s %s;\n", stringify(nodeTypeMap(listLast(l))), stringify(car(l)));

  end

end
-- Chose function name nodeStructComponents
function nodeStructComponents(node)
print("caller: ", caller, "-> nodeStructComponents")
caller = "nodeStructComponents:Unknown file:-1"
  if isEmpty(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      nodeTypeDecl(car(node));

caller = ":Unknown file:-1"
      nodeStructComponents(cdr(node));

  end

end
-- Chose function name nodeStruct
function nodeStruct(node)
print("caller: ", caller, "-> nodeStruct")
caller = "nodeStruct:Unknown file:-1"
  nodeStructComponents(cdr(car(node)));

end
-- Chose function name nodeTypeMap
function nodeTypeMap(aSym)
print("caller: ", caller, "-> nodeTypeMap")
local symMap =nil
caller = "nodeTypeMap:Unknown file:-1"
  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), nil))
caller = "nodeTypeMap:Unknown file:-1"
  if truthy(assoc(stringify(aSym), symMap)) then
caller = ":Unknown file:-1"
      return cdr(assoc(stringify(aSym), symMap))

  else
caller = ":Unknown file:-1"
      return aSym

  end

end
-- Chose function name nodeFuncMap
function nodeFuncMap(aSym)
print("caller: ", caller, "-> nodeFuncMap")
local symMap =nil
caller = "nodeFuncMap:Unknown file:-1"
  if equalString("symbol", boxType(aSym)) then
caller = ":Unknown file:-1"
      symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("luaSubstring"), boxSymbol("sub_string"), alistCons(boxSymbol("luaReadFile"), boxSymbol("read_file"), alistCons(boxSymbol("luaWriteFile"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string.len"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), nil)))))))
caller = ":Unknown file:-1"
      if truthy(assoc(stringify(aSym), symMap)) then
caller = ":Unknown file:-1"
          return cdr(assoc(stringify(aSym), symMap))

      else
caller = ":Unknown file:-1"
          return aSym

      end

  else
caller = ":Unknown file:-1"
      return aSym

  end

end
-- Chose function name nodeType
function nodeType(node)
print("caller: ", caller, "-> nodeType")
end
-- Chose function name nodeTypes
function nodeTypes(nodes)
print("caller: ", caller, "-> nodeTypes")
caller = "nodeTypes:Unknown file:-1"
  if isEmpty(nodes) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      nodeType(car(nodes));

caller = ":Unknown file:-1"
      nodeTypes(cdr(nodes));

  end

end
-- Chose function name nodeCompile
function nodeCompile(filename)
print("caller: ", caller, "-> nodeCompile")
local programStr =""
local tree =nil
local program =nil
caller = "nodeCompile:Unknown file:-1"
  programStr = luaReadFile(filename)
caller = "nodeCompile:Unknown file:-1"
  tree = readSexpr(programStr, filename)
caller = "nodeCompile:Unknown file:-1"
  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), nil)))
caller = "nodeCompile:Unknown file:-1"
  program = mergeIncludes(program)
caller = "nodeCompile:Unknown file:-1"
  nodeIncludes(cdr(assoc("includes", program)));

caller = "nodeCompile:Unknown file:-1"
  nodeTypes(childrenof(cdr(assoc("types", program))));

caller = "nodeCompile:Unknown file:-1"
  printf("\nvar globalStackTrace = NULL;\n");

caller = "nodeCompile:Unknown file:-1"
  printf("\nvar caller = \"\";\n");

caller = "nodeCompile:Unknown file:-1"
  printf("\nfunction isNil(p) {\n    return p == NULL;\n}\n\n");

caller = "nodeCompile:Unknown file:-1"
  nodeFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));

caller = "nodeCompile:Unknown file:-1"
  printf("\n");

caller = "nodeCompile:Unknown file:-1"
  printf("const [asfdasdf, ...qwerqwer] = process.argv;");

caller = "nodeCompile:Unknown file:-1"
  printf("globalArgs = qwerqwer;");

caller = "nodeCompile:Unknown file:-1"
  printf("globalArgsCount = qwerqwer.length;");

caller = "nodeCompile:Unknown file:-1"
  printf("%s", "start();\n");

end
-- Chose function name test0
function test0()
print("caller: ", caller, "-> test0")
caller = "test0:Unknown file:-1"
  if equalString(stringify(boxString("hello")), stringify(boxString("hello"))) then
caller = ":Unknown file:-1"
      printf("0.  pass string compare works\n");

  else
caller = ":Unknown file:-1"
      printf("0.  pass string compare fails\n");

  end

caller = "test0:Unknown file:-1"
  if equalString(stringify(boxString("hello")), stringify(boxSymbol("hello"))) then
caller = ":Unknown file:-1"
      printf("0.  pass string compare works\n");

  else
caller = ":Unknown file:-1"
      printf("0.  pass string compare fails\n");

  end

end
-- Chose function name test1
function test1()
print("caller: ", caller, "-> test1")
caller = "test1:Unknown file:-1"
  printf("1.  pass Function call and print work\n");

end
-- Chose function name test2_do
function test2_do(message)
print("caller: ", caller, "-> test2_do")
caller = "test2_do:Unknown file:-1"
  printf("2.  pass Function call with arg works: %s\n", message);

end
-- Chose function name test2
function test2()
print("caller: ", caller, "-> test2")
caller = "test2:Unknown file:-1"
  test2_do("This is the argument");

end
-- Chose function name test3_do
function test3_do(b,c)
print("caller: ", caller, "-> test3_do")
caller = "test3_do:Unknown file:-1"
  printf("3.1 pass Two arg call, first arg: %d\n", b);

caller = "test3_do:Unknown file:-1"
  printf("3.2 pass Two arg call, second arg: %s\n", c);

end
-- Chose function name test3
function test3()
print("caller: ", caller, "-> test3")
caller = "test3:Unknown file:-1"
  test3_do(42, "Fourty-two");

end
-- Chose function name test4_do
function test4_do()
print("caller: ", caller, "-> test4_do")
caller = "test4_do:Unknown file:-1"
  return "pass Return works"

end
-- Chose function name returnThis
function returnThis(returnMessage)
print("caller: ", caller, "-> returnThis")
caller = "returnThis:Unknown file:-1"
  return returnMessage

end
-- Chose function name test4
function test4()
print("caller: ", caller, "-> test4")
local message ="fail"
caller = "test4:Unknown file:-1"
  message = test4_do()
caller = "test4:Unknown file:-1"
  printf("4.  %s\n", message);

end
-- Chose function name test5
function test5()
print("caller: ", caller, "-> test5")
local message ="fail"
caller = "test5:Unknown file:-1"
  message = returnThis("pass return passthrough string")
caller = "test5:Unknown file:-1"
  printf("5.  %s\n", message);

end
-- Chose function name test6
function test6()
print("caller: ", caller, "-> test6")
caller = "test6:Unknown file:-1"
  if true then
caller = ":Unknown file:-1"
      printf("6.  pass If statement works\n");

  else
caller = ":Unknown file:-1"
      printf("6.  fail If statement works\n");

  end

end
-- Chose function name test7_do
function test7_do(count)
print("caller: ", caller, "-> test7_do")
caller = "test7_do:Unknown file:-1"
  count = sub(count, 1)
caller = "test7_do:Unknown file:-1"
  if greaterthan(count, 0) then
caller = ":Unknown file:-1"
      count = test7_do(count)
  else
caller = ":Unknown file:-1"
      return count

  end

caller = "test7_do:Unknown file:-1"
  return count

end
-- Chose function name test7
function test7()
print("caller: ", caller, "-> test7")
caller = "test7:Unknown file:-1"
  if equal(0, test7_do(10)) then
caller = ":Unknown file:-1"
      printf("7.  pass count works\n");

  else
caller = ":Unknown file:-1"
      printf("7.  fail count fails\n");

  end

end
-- Chose function name beer
function beer()
print("caller: ", caller, "-> beer")
caller = "beer:Unknown file:-1"
  printf("%d bottle of beer on the wall, %d bottle of beer.  Take one down, pass it round, no bottles of beer on the wall\n", 1, 1);

end
-- Chose function name plural
function plural(num)
print("caller: ", caller, "-> plural")
caller = "plural:Unknown file:-1"
  if equal(num, 1) then
caller = ":Unknown file:-1"
      return ""

  else
caller = ":Unknown file:-1"
      return "s"

  end

end
-- Chose function name beers
function beers(count)
print("caller: ", caller, "-> beers")
local newcount =0
caller = "beers:Unknown file:-1"
  newcount = sub(count, 1)
caller = "beers:Unknown file:-1"
  printf("%d bottle%s of beer on the wall, %d bottle%s of beer.  Take one down, pass it round, %d bottle%s of beer on the wall\n", count, plural(count), count, plural(count), newcount, plural(newcount));

caller = "beers:Unknown file:-1"
  if greaterthan(count, 1) then
caller = ":Unknown file:-1"
      count = beers(newcount)
  else
caller = ":Unknown file:-1"
      return count

  end

caller = "beers:Unknown file:-1"
  return 0

end
-- Chose function name test8
function test8()
print("caller: ", caller, "-> test8")
caller = "test8:Unknown file:-1"
  if equal(sub(sub(2, 1), sub(3, 1)), -1) then
caller = ":Unknown file:-1"
      printf("8.  pass Nested expressions work\n");

  else
caller = ":Unknown file:-1"
      printf("8.  fail Nested expressions don't work\n");

  end

end
-- Chose function name test9
function test9()
print("caller: ", caller, "-> test9")
local answer =-999999
local a =2
local b =3
caller = "test9:Unknown file:-1"
  answer = sub(sub(20, 1), sub(3, 1))
caller = "test9:Unknown file:-1"
  if equal(answer, 17) then
caller = ":Unknown file:-1"
      printf("9.1  pass sub works\n");

  else
caller = ":Unknown file:-1"
      printf("9.1  fail sub\n");

  end

caller = "test9:Unknown file:-1"
  answer = add(2, 3)
caller = "test9:Unknown file:-1"
  if equal(answer, 5) then
caller = ":Unknown file:-1"
      printf("9.2  pass add works\n");

  else
caller = ":Unknown file:-1"
      printf("9.2  fail add\n");

  end

caller = "test9:Unknown file:-1"
  answer = mult(a, b)
caller = "test9:Unknown file:-1"
  if equal(answer, 6) then
caller = ":Unknown file:-1"
      printf("9.3  pass mult works\n");

  else
caller = ":Unknown file:-1"
      printf("9.3  fail mult\n");

  end

caller = "test9:Unknown file:-1"
  if greaterthan(2, 1) then
caller = ":Unknown file:-1"
      printf("9.4  pass greaterthan works\n");

  else
caller = ":Unknown file:-1"
      printf("9.4  fail greaterthan\n");

  end

caller = "test9:Unknown file:-1"
  if equal(1, 1) then
caller = ":Unknown file:-1"
      printf("9.5  pass integer equal works\n");

  else
caller = ":Unknown file:-1"
      printf("9.5  fail integer equal\n");

  end

caller = "test9:Unknown file:-1"
  if equalString("hello", "hello") then
caller = ":Unknown file:-1"
      printf("9.6  pass string equal works\n");

  else
caller = ":Unknown file:-1"
      printf("9.6  fail string equal\n");

  end

caller = "test9:Unknown file:-1"
  if equalString("hello", "world") then
caller = ":Unknown file:-1"
      printf("9.7  fail string equal\n");

  else
caller = ":Unknown file:-1"
      printf("9.7  pass string equal\n");

  end

caller = "test9:Unknown file:-1"
  if andBool(false, false) then
caller = ":Unknown file:-1"
      printf("9.8  fail andBool\n");

  else
caller = ":Unknown file:-1"
      printf("9.8  pass andBool works\n");

  end

caller = "test9:Unknown file:-1"
  if andBool(true, true) then
caller = ":Unknown file:-1"
      printf("9.9  pass andBool works\n");

  else
caller = ":Unknown file:-1"
      printf("9.9  fail andBool\n");

  end

caller = "test9:Unknown file:-1"
  if andBool(true, false) then
caller = ":Unknown file:-1"
      printf("9.10  fail andBool\n");

  else
caller = ":Unknown file:-1"
      printf("9.10  pass andBool works\n");

  end

caller = "test9:Unknown file:-1"
  if equalString("hello", "hello") then
caller = ":Unknown file:-1"
      printf("9.11  pass string equal\n");

  else
caller = ":Unknown file:-1"
      printf("9.11  fail string equal\n");

  end

caller = "test9:Unknown file:-1"
  if equalString("!", character(33)) then
caller = ":Unknown file:-1"
      printf("9.12  pass character\n");

  else
caller = ":Unknown file:-1"
      printf("9.12  fail character\n");

  end

caller = "test9:Unknown file:-1"
  if equalString("33", intToString(33)) then
caller = ":Unknown file:-1"
      printf("9.13  pass intToString\n");

  else
caller = ":Unknown file:-1"
      printf("9.13  fail intToString\n");

  end

caller = "test9:Unknown file:-1"
  if equalString("llo", luaSubstring("hello", a, b)) then
caller = ":Unknown file:-1"
      printf("9.14  pass sub-string\n");

  else
caller = ":Unknown file:-1"
      printf("9.14  fail sub-string: %s\n", luaSubstring("hello", a, b));

  end

end
-- Chose function name test10
function test10()
print("caller: ", caller, "-> test10")
local testString ="This is a test string"
caller = "test10:Unknown file:-1"
  if equalString(testString, unBoxString(car(cons(boxString(testString), nil)))) then
caller = ":Unknown file:-1"
      printf("10. pass cons and car work\n");

  else
caller = ":Unknown file:-1"
      printf("10. fail cons and car fail\n");

  end

end
-- Chose function name test12
function test12()
print("caller: ", caller, "-> test12")
local b =nil
caller = "test12:Unknown file:-1"
  b = new(box, Box)
caller = "test12:Unknown file:-1"
b.str = "12. pass structure accessors\n"
caller = "test12:Unknown file:-1"
  printf("%s", b.str);

end
-- Chose function name test13
function test13()
print("caller: ", caller, "-> test13")
local testString ="Hello from the filesystem!"
local contents =""
caller = "test13:Unknown file:-1"
  luaWriteFile("test.txt", testString);

caller = "test13:Unknown file:-1"
  contents = luaReadFile("test.txt")
caller = "test13:Unknown file:-1"
  if equalString(testString, contents) then
caller = ":Unknown file:-1"
      printf("13. pass Read and write files\n");

  else
caller = ":Unknown file:-1"
      printf("13. fail Read and write files\n");

caller = ":Unknown file:-1"
      printf("Expected: %s\n", testString);

caller = ":Unknown file:-1"
      printf("Got: %s\n", contents);

  end

end
-- Chose function name test15
function test15()
print("caller: ", caller, "-> test15")
local a ="hello"
local b =" world"
local c =""
caller = "test15:Unknown file:-1"
  c = stringConcatenate(a, b)
caller = "test15:Unknown file:-1"
  if equalString(c, "hello world") then
caller = ":Unknown file:-1"
      printf("15. pass String concatenate\n");

  else
caller = ":Unknown file:-1"
      printf("15. fail String concatenate\n");

  end

end
-- Chose function name test16
function test16()
print("caller: ", caller, "-> test16")
local assocCell1 =nil
local assList =nil
local assocCell2 =nil
local assocCell3 =nil
caller = "test16:Unknown file:-1"
  assocCell1 = cons(boxString("Hello"), boxString("world"))
caller = "test16:Unknown file:-1"
  assocCell2 = cons(boxString("goodnight"), boxString("moon"))
caller = "test16:Unknown file:-1"
  assocCell3 = cons(boxSymbol("ohio"), boxString("gozaimasu"))
caller = "test16:Unknown file:-1"
  assList = cons(assocCell2, emptyList())
caller = "test16:Unknown file:-1"
  assList = cons(assocCell1, assList)
caller = "test16:Unknown file:-1"
  assList = cons(assocCell3, assList)
caller = "test16:Unknown file:-1"
  if equalBox(cdr(assoc("Hello", assList)), boxString("world")) then
caller = ":Unknown file:-1"
      printf("16.1 pass Basic assoc works\n");

  else
caller = ":Unknown file:-1"
      printf("16.1 fail Basic assoc fails\n");

  end

caller = "test16:Unknown file:-1"
  if andBool(andBool(equalBox(cdr(assoc("Hello", assList)), boxString("world")), equalBox(cdr(assoc("goodnight", assList)), boxString("moon"))), equalBox(cdr(assoc("ohio", assList)), boxString("gozaimasu"))) then
caller = ":Unknown file:-1"
      printf("16.2 pass assoc list\n");

  else
caller = ":Unknown file:-1"
      printf("16.2 fail assoc list\n");

  end

end
-- Chose function name test17
function test17()
print("caller: ", caller, "-> test17")
local l =nil
caller = "test17:Unknown file:-1"
  l = cons(boxInt(1), cons(boxInt(2), cons(boxInt(3), nil)))
caller = "test17:Unknown file:-1"
  if equalBox(car(l), boxInt(1)) then
caller = ":Unknown file:-1"
      printf("17. pass list literal works\n");

  else
caller = ":Unknown file:-1"
      printf("17. fail list literal failed\n");

  end

end
-- Chose function name test18
function test18()
print("caller: ", caller, "-> test18")
local val1 ="a"
local val2 ="b"
local l =nil
caller = "test18:Unknown file:-1"
  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), nil)))
caller = "test18:Unknown file:-1"
  if equalList(l, cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), nil)))) then
caller = ":Unknown file:-1"
      printf("18. pass string list constructor works\n");

  else
caller = ":Unknown file:-1"
      printf("18. fail string list constructor failed\n");

  end

end
-- Chose function name test19
function test19()
print("caller: ", caller, "-> test19")
local val1 ="a"
local val2 ="b"
local l =nil
local revlist =nil
local answer =nil
caller = "test19:Unknown file:-1"
  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), nil)))
caller = "test19:Unknown file:-1"
  answer = cons(boxString("c"), cons(boxString(val2), cons(boxString(val1), nil)))
caller = "test19:Unknown file:-1"
  revlist = reverseList(l)
caller = "test19:Unknown file:-1"
  if equalList(answer, revlist) then
caller = ":Unknown file:-1"
      printf("19. pass reverseList\n");

  else
caller = ":Unknown file:-1"
      printf("19. fail reverseList\n");

  end

end
-- Chose function name concatenateLists
function concatenateLists(oldL,newL)
print("caller: ", caller, "-> concatenateLists")
caller = "concatenateLists:Unknown file:-1"
  return reverseRec(reverseList(oldL), newL)

end
-- Chose function name test20
function test20()
print("caller: ", caller, "-> test20")
local val1 ="a"
local val2 ="b"
local val3 ="c"
local l =nil
local l2 =nil
local l3 =nil
local combined =nil
caller = "test20:Unknown file:-1"
  l = cons(boxString(val1), cons(boxString(val2), cons(boxString("c"), nil)))
caller = "test20:Unknown file:-1"
  l2 = cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), nil)))
caller = "test20:Unknown file:-1"
  l3 = cons(boxString(val1), cons(boxString(val2), cons(boxString(val3), cons(boxString("d"), cons(boxString("e"), cons(boxString("f"), nil))))))
caller = "test20:Unknown file:-1"
  combined = concatenateLists(l, l2)
caller = "test20:Unknown file:-1"
  if equalList(l3, combined) then
caller = ":Unknown file:-1"
      printf("21. pass concatenateLists\n");

  else
caller = ":Unknown file:-1"
      printf("21. fail concatenateLists\n");

  end

end
-- Chose function name test21
function test21()
print("caller: ", caller, "-> test21")
local val1 ="a"
local val2 ="b"
local val3 ="c"
local l =nil
local l2 =nil
caller = "test21:Unknown file:-1"
  l = cons(boxString(val1), cons(boxString(val2), cons(boxString(val3), nil)))
caller = "test21:Unknown file:-1"
  l2 = cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), nil)))
caller = "test21:Unknown file:-1"
  if equalList(l, l2) then
caller = ":Unknown file:-1"
      printf("21. pass equalList\n");

  else
caller = ":Unknown file:-1"
      printf("21. fail equalList\n");

  end

end
-- Chose function name test22
function test22()
print("caller: ", caller, "-> test22")
local original =nil
local out =nil
local replace =nil
local correct =nil
caller = "test22:Unknown file:-1"
  original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), nil)))
caller = "test22:Unknown file:-1"
  replace = cons(boxString("fprintf"), cons(boxString("stderr"), nil))
caller = "test22:Unknown file:-1"
  out = macrolist(original, stringConcatenate("q", "log"), replace)
caller = "test22:Unknown file:-1"
  correct = cons(boxString("fprintf"), cons(boxString("stderr"), cons(boxString("%s"), cons(boxString("hello"), nil))))
caller = "test22:Unknown file:-1"
  if equalList(out, correct) then
caller = ":Unknown file:-1"
      printf("22. pass macroList\n");

  else
caller = ":Unknown file:-1"
      printf("22. fail macroList\n");

caller = ":Unknown file:-1"
      printf("In: ");

caller = ":Unknown file:-1"
      displayList(original, 0, true);

caller = ":Unknown file:-1"
      printf("\nOut: ");

caller = ":Unknown file:-1"
      displayList(out, 0, true);

caller = ":Unknown file:-1"
      printf("\n");

  end

end
-- Chose function name test23
function test23()
print("caller: ", caller, "-> test23")
local original =nil
local out =nil
local replace =nil
local correct =nil
caller = "test23:Unknown file:-1"
  original = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), nil)))
caller = "test23:Unknown file:-1"
  replace = cons(boxString("fprintf"), cons(boxString("stderr"), nil))
caller = "test23:Unknown file:-1"
  out = concatLists(original, replace)
caller = "test23:Unknown file:-1"
  correct = cons(boxString(stringConcatenate("q", "log")), cons(boxString("%s"), cons(boxString("hello"), cons(boxString("fprintf"), cons(boxString("stderr"), nil)))))
caller = "test23:Unknown file:-1"
  if equalList(out, correct) then
caller = ":Unknown file:-1"
      printf("23. pass concatLists\n");

  else
caller = ":Unknown file:-1"
      printf("23. fail concatLists\n");

caller = ":Unknown file:-1"
      printf("In: ");

caller = ":Unknown file:-1"
      displayList(original, 0, true);

caller = ":Unknown file:-1"
      printf("\nOut: ");

caller = ":Unknown file:-1"
      displayList(out, 0, true);

  end

end
-- Chose function name test24
function test24()
print("caller: ", caller, "-> test24")
local expected ="a b c"
local res =""
caller = "test24:Unknown file:-1"
  res = StringListJoin(cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), nil))), " ")
caller = "test24:Unknown file:-1"
  if equalString(expected, res) then
caller = ":Unknown file:-1"
      printf("24. pass StringListJoin\n");

  else
caller = ":Unknown file:-1"
      printf("24. fail StringListJoin.  expected '%s', got '%s'\n", expected, res);

  end

end
-- Chose function name test25
function test25()
print("caller: ", caller, "-> test25")
local expected ="( a b ) c d e"
local res =""
local testsubstr =cons(boxString("c "), cons(boxString("d "), cons(boxString("e"), nil)))
local input =nil
caller = "test25:Unknown file:-1"
  input = cons(boxString("a "), cons(boxString("b "), nil))
caller = "test25:Unknown file:-1"
  input = cons(input, testsubstr)
caller = "test25:Unknown file:-1"
  res = ListToString(input, 0, true, false)
caller = "test25:Unknown file:-1"
  if equalString(expected, res) then
caller = ":Unknown file:-1"
      printf("25. pass ListToString\n");

  else
caller = ":Unknown file:-1"
      printf("25. fail ListToString.  expected '%s', got '%s'\n", expected, res);

  end

end
-- Chose function name ansi3displays
function ansi3displays(s)
print("caller: ", caller, "-> ansi3displays")
caller = "ansi3displays:Unknown file:-1"
  printf("%s", s);

end
-- Chose function name ansi3FunctionArgs
function ansi3FunctionArgs(tree)
print("caller: ", caller, "-> ansi3FunctionArgs")
caller = "ansi3FunctionArgs:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      if equalString(stringify(first(tree)), "...") then
caller = ":Unknown file:-1"
          printf("...");

      else
caller = ":Unknown file:-1"
          display(ansi3TypeMap(first(tree)));

caller = ":Unknown file:-1"
          ansi3displays(" ");

caller = ":Unknown file:-1"
          display(second(tree));

      end

caller = ":Unknown file:-1"
      if isNil(cddr(tree)) then
      else
caller = ":Unknown file:-1"
          ansi3displays(", ");

      end

caller = ":Unknown file:-1"
      ansi3FunctionArgs(cddr(tree));

  end

end
-- Chose function name ansi3Expression
function ansi3Expression(tree,indent)
print("caller: ", caller, "-> ansi3Expression")
local thing =nil
caller = "ansi3Expression:Unknown file:-1"
  if isList(tree) then
caller = ":Unknown file:-1"
      if equal(1, listLength(tree)) then
caller = ":Unknown file:-1"
          display(car(tree));

caller = ":Unknown file:-1"
          if equalBox(boxString("return"), car(tree)) then
          else
caller = ":Unknown file:-1"
              ansi3displays("()");

          end

      else
caller = ":Unknown file:-1"
          thing = first(tree)
caller = ":Unknown file:-1"
          if equalBox(boxSymbol("get-struct"), thing) then
caller = ":Unknown file:-1"
              printf("%s->%s", stringify(second(tree)), stringify(third(tree)));

          else
caller = ":Unknown file:-1"
              if equalBox(boxSymbol("new"), thing) then
caller = ":Unknown file:-1"
                  printf("malloc(sizeof(%s))", stringify(third(tree)));

              else
caller = ":Unknown file:-1"
                  if equalBox(boxSymbol("passthrough"), thing) then
caller = ":Unknown file:-1"
                      printf("%s", stringify(second(tree)));

                  else
caller = ":Unknown file:-1"
                      if equalBox(boxSymbol("binop"), thing) then
caller = ":Unknown file:-1"
                          printf("(");

caller = ":Unknown file:-1"
                          ansi3Expression(third(tree), indent);

caller = ":Unknown file:-1"
                          printf(" %s ", stringify(second(tree)));

caller = ":Unknown file:-1"
                          ansi3Expression(fourth(tree), indent);

caller = ":Unknown file:-1"
                          printf(")");

                      else
caller = ":Unknown file:-1"
                          printf("%s(", stringify(ansi3FuncMap(car(tree))));

caller = ":Unknown file:-1"
                          ansi3RecurList(cdr(tree), indent);

caller = ":Unknown file:-1"
                          printf(")");

                      end

                  end

              end

          end

      end

  else
caller = ":Unknown file:-1"
      display(ansi3FuncMap(tree));

  end

end
-- Chose function name ansi3RecurList
function ansi3RecurList(expr,indent)
print("caller: ", caller, "-> ansi3RecurList")
caller = "ansi3RecurList:Unknown file:-1"
  if isEmpty(expr) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      ansi3Expression(car(expr), indent);

caller = ":Unknown file:-1"
      if isNil(cdr(expr)) then
caller = ":Unknown file:-1"
          ansi3displays("");

      else
caller = ":Unknown file:-1"
          ansi3displays(", ");

caller = ":Unknown file:-1"
          ansi3RecurList(cdr(expr), indent);

      end

  end

end
-- Chose function name ansi3If
function ansi3If(node,indent)
print("caller: ", caller, "-> ansi3If")
caller = "ansi3If:Unknown file:-1"
  newLine(indent);

caller = "ansi3If:Unknown file:-1"
  ansi3displays("if ( ");

caller = "ansi3If:Unknown file:-1"
  ansi3Expression(second(node), 0);

caller = "ansi3If:Unknown file:-1"
  ansi3displays(") {");

caller = "ansi3If:Unknown file:-1"
  ansi3Body(cdr(third(node)), add1(indent));

caller = "ansi3If:Unknown file:-1"
  newLine(indent);

caller = "ansi3If:Unknown file:-1"
  ansi3displays("} else {");

caller = "ansi3If:Unknown file:-1"
  ansi3Body(cdr(fourth(node)), add1(indent));

caller = "ansi3If:Unknown file:-1"
  newLine(indent);

caller = "ansi3If:Unknown file:-1"
  ansi3displays("}");

end
-- Chose function name ansi3SetStruct
function ansi3SetStruct(node,indent)
print("caller: ", caller, "-> ansi3SetStruct")
caller = "ansi3SetStruct:Unknown file:-1"
  newLine(indent);

caller = "ansi3SetStruct:Unknown file:-1"
  printf("%s->%s = ", stringify(second(node)), stringify(third(node)));

caller = "ansi3SetStruct:Unknown file:-1"
  ansi3Expression(fourth(node), indent);

end
-- Chose function name ansi3GetStruct
function ansi3GetStruct(node,indent)
print("caller: ", caller, "-> ansi3GetStruct")
caller = "ansi3GetStruct:Unknown file:-1"
  newLine(indent);

caller = "ansi3GetStruct:Unknown file:-1"
  printf("%s->%s", stringify(first(node)), stringify(second(node)));

end
-- Chose function name ansi3Set
function ansi3Set(node,indent)
print("caller: ", caller, "-> ansi3Set")
caller = "ansi3Set:Unknown file:-1"
  newLine(indent);

caller = "ansi3Set:Unknown file:-1"
  ansi3Expression(first(cdr(node)), indent);

caller = "ansi3Set:Unknown file:-1"
  printf(" = ");

caller = "ansi3Set:Unknown file:-1"
  ansi3Expression(third(node), indent);

end
-- Chose function name ansi3Return
function ansi3Return(node,indent)
print("caller: ", caller, "-> ansi3Return")
caller = "ansi3Return:Unknown file:-1"
  newLine(indent);

caller = "ansi3Return:Unknown file:-1"
  if equal(listLength(node), 1) then
caller = ":Unknown file:-1"
      ansi3displays("return;");

  else
caller = ":Unknown file:-1"
      ansi3displays("return ");

caller = ":Unknown file:-1"
      ansi3Expression(cadr(node), indent);

caller = ":Unknown file:-1"
      ansi3displays(";");

  end

end
-- Chose function name ansi3Statement
function ansi3Statement(node,indent)
print("caller: ", caller, "-> ansi3Statement")
caller = "ansi3Statement:Unknown file:-1"
  if equalBox(boxString("set"), first(node)) then
caller = ":Unknown file:-1"
      ansi3Set(node, indent);

  else
caller = ":Unknown file:-1"
      if equalBox(boxString("set-struct"), first(node)) then
caller = ":Unknown file:-1"
          ansi3SetStruct(node, indent);

      else
caller = ":Unknown file:-1"
          if equalBox(boxString("if"), first(node)) then
caller = ":Unknown file:-1"
              ansi3If(node, indent);

          else
caller = ":Unknown file:-1"
              if equalBox(boxString("return"), first(node)) then
caller = ":Unknown file:-1"
                  ansi3Return(node, indent);

              else
caller = ":Unknown file:-1"
                  newLine(indent);

caller = ":Unknown file:-1"
                  ansi3Expression(node, indent);

              end

          end

      end

  end

caller = "ansi3Statement:Unknown file:-1"
  ansi3displays(";\n");

end
-- Chose function name ansi3Body
function ansi3Body(tree,indent)
print("caller: ", caller, "-> ansi3Body")
local code =nil
caller = "ansi3Body:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      code = tree
caller = ":Unknown file:-1"
      if isNil(code) then
      else
caller = ":Unknown file:-1"
          code = car(tree)
caller = ":Unknown file:-1"
          if not(releaseMode) then
caller = ":Unknown file:-1"
              printf("\nif (globalTrace)\n    snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), stringify(getTagFail(car(code), boxString("line"), boxString("Line missing"))));

          else
          end

      end

caller = ":Unknown file:-1"
      if not(releaseMode) then
caller = ":Unknown file:-1"
          printIndent(indent);

caller = ":Unknown file:-1"
          printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n");

      else
      end

caller = ":Unknown file:-1"
      ansi3Statement(code, indent);

caller = ":Unknown file:-1"
      ansi3Body(cdr(tree), indent);

  end

end
-- Chose function name ansi3Declarations
function ansi3Declarations(decls,indent)
print("caller: ", caller, "-> ansi3Declarations")
local decl =nil
caller = "ansi3Declarations:Unknown file:-1"
  if isEmpty(decls) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      decl = car(decls)
caller = ":Unknown file:-1"
      printf("%s %s = ", stringify(ansi3TypeMap(first(decl))), stringify(second(decl)));

caller = ":Unknown file:-1"
      ansi3Expression(third(decl), indent);

caller = ":Unknown file:-1"
      printf(";\n");

caller = ":Unknown file:-1"
      ansi3Declarations(cdr(decls), indent);

  end

end
-- Chose function name ansi3Function
function ansi3Function(node)
print("caller: ", caller, "-> ansi3Function")
local name =nil
caller = "ansi3Function:Unknown file:-1"
  name = second(node)
caller = "ansi3Function:Unknown file:-1"
  printf("\n\n//Building function %s from file %s, line: %s", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

caller = "ansi3Function:Unknown file:-1"
  newLine(0);

caller = "ansi3Function:Unknown file:-1"
  if isNil(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      newLine(0);

caller = ":Unknown file:-1"
      printf("%s %s(", stringify(ansi3TypeMap(first(node))), stringify(second(node)));

caller = ":Unknown file:-1"
      ansi3FunctionArgs(third(node));

caller = ":Unknown file:-1"
      printf(") {");

caller = ":Unknown file:-1"
      newLine(1);

caller = ":Unknown file:-1"
      ansi3Declarations(cdr(fourth(node)), 1);

caller = ":Unknown file:-1"
      if releaseMode then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf("\nif (globalTrace)\n    printf(\"%s at %s:%s (%%s)\\n\", caller);\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

      end

caller = ":Unknown file:-1"
      if releaseMode then
caller = ":Unknown file:-1"
          printf("");

      else
      end

caller = ":Unknown file:-1"
      ansi3Body(cdr(fifth(node)), 1);

caller = ":Unknown file:-1"
      if releaseMode then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf("\nif (globalTrace)\n    printf(\"Leaving %s\\n\");\n", stringify(name));

      end

caller = ":Unknown file:-1"
      printf("\n}\n");

  end

end
-- Chose function name ansi3ForwardDeclaration
function ansi3ForwardDeclaration(node)
print("caller: ", caller, "-> ansi3ForwardDeclaration")
caller = "ansi3ForwardDeclaration:Unknown file:-1"
  if isNil(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      printf("\n%s %s(", stringify(ansi3TypeMap(first(node))), stringify(second(node)));

caller = ":Unknown file:-1"
      ansi3FunctionArgs(third(node));

caller = ":Unknown file:-1"
      ansi3displays(");");

  end

end
-- Chose function name ansi3ForwardDeclarations
function ansi3ForwardDeclarations(tree)
print("caller: ", caller, "-> ansi3ForwardDeclarations")
caller = "ansi3ForwardDeclarations:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      ansi3ForwardDeclaration(car(tree));

caller = ":Unknown file:-1"
      ansi3ForwardDeclarations(cdr(tree));

  end

end
-- Chose function name ansi3Functions
function ansi3Functions(tree)
print("caller: ", caller, "-> ansi3Functions")
caller = "ansi3Functions:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      ansi3Function(car(tree));

caller = ":Unknown file:-1"
      ansi3Functions(cdr(tree));

  end

end
-- Chose function name ansi3Includes
function ansi3Includes(nodes)
print("caller: ", caller, "-> ansi3Includes")
caller = "ansi3Includes:Unknown file:-1"
  printf("%s", "\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\n#include <unistd.h>\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\nbool releaseMode = false;\n\n");

caller = "ansi3Includes:Unknown file:-1"
  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n//End include block\n");

end
-- Chose function name ansi3TypeDecl
function ansi3TypeDecl(l)
print("caller: ", caller, "-> ansi3TypeDecl")
caller = "ansi3TypeDecl:Unknown file:-1"
  if greaterthan(listLength(l), 2) then
caller = ":Unknown file:-1"
      printIndent(1);

caller = ":Unknown file:-1"
      printf("%s %s %s;\n", stringify(second(l)), stringify(ansi3TypeMap(listLast(l))), stringify(first(l)));

  else
caller = ":Unknown file:-1"
      printIndent(1);

caller = ":Unknown file:-1"
      printf("%s %s;\n", stringify(ansi3TypeMap(listLast(l))), stringify(car(l)));

  end

end
-- Chose function name ansi3StructComponents
function ansi3StructComponents(node)
print("caller: ", caller, "-> ansi3StructComponents")
caller = "ansi3StructComponents:Unknown file:-1"
  if isEmpty(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      ansi3TypeDecl(car(node));

caller = ":Unknown file:-1"
      ansi3StructComponents(cdr(node));

  end

end
-- Chose function name ansi3Struct
function ansi3Struct(node)
print("caller: ", caller, "-> ansi3Struct")
caller = "ansi3Struct:Unknown file:-1"
  ansi3StructComponents(cdr(node));

end
-- Chose function name ansi3TypeMap
function ansi3TypeMap(aSym)
print("caller: ", caller, "-> ansi3TypeMap")
local symMap =nil
caller = "ansi3TypeMap:Unknown file:-1"
  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), nil))
caller = "ansi3TypeMap:Unknown file:-1"
  if truthy(assoc(stringify(aSym), symMap)) then
caller = ":Unknown file:-1"
      return cdr(assoc(stringify(aSym), symMap))

  else
caller = ":Unknown file:-1"
      return aSym

  end

end
-- Chose function name ansi3FuncMap
function ansi3FuncMap(aSym)
print("caller: ", caller, "-> ansi3FuncMap")
local symMap =nil
caller = "ansi3FuncMap:Unknown file:-1"
  if equalString("symbol", boxType(aSym)) then
caller = ":Unknown file:-1"
      symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("luaSubstring"), boxSymbol("sub_string"), alistCons(boxSymbol("luaReadFile"), boxSymbol("read_file"), alistCons(boxSymbol("luaWriteFile"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string.len"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), nil)))))))
caller = ":Unknown file:-1"
      if truthy(assoc(stringify(aSym), symMap)) then
caller = ":Unknown file:-1"
          return cdr(assoc(stringify(aSym), symMap))

      else
caller = ":Unknown file:-1"
          return aSym

      end

  else
caller = ":Unknown file:-1"
      return aSym

  end

end
-- Chose function name ansi3Type
function ansi3Type(node)
print("caller: ", caller, "-> ansi3Type")
caller = "ansi3Type:Unknown file:-1"
  if isList(second(node)) then
caller = ":Unknown file:-1"
      printf("\ntypedef struct %s {\n", stringify(first(node)));

caller = ":Unknown file:-1"
      ansi3Struct(second(node));

caller = ":Unknown file:-1"
      printf("\n} %s;\n", stringify(first(node)));

  else
caller = ":Unknown file:-1"
      ansi3displays("typedef ");

caller = ":Unknown file:-1"
      ansi3TypeDecl(node);

  end

end
-- Chose function name ansi3Types
function ansi3Types(nodes)
print("caller: ", caller, "-> ansi3Types")
caller = "ansi3Types:Unknown file:-1"
  if isEmpty(nodes) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      ansi3Type(car(nodes));

caller = ":Unknown file:-1"
      ansi3Types(cdr(nodes));

  end

end
-- Chose function name ansi3Compile
function ansi3Compile(filename)
print("caller: ", caller, "-> ansi3Compile")
local tree =nil
local replace =nil
caller = "ansi3Compile:Unknown file:-1"
  qlog("//Scanning file...%s\n", filename);

caller = "ansi3Compile:Unknown file:-1"
  tree = loadQuon(filename)
caller = "ansi3Compile:Unknown file:-1"
  qlog("//Building sexpr\n");

caller = "ansi3Compile:Unknown file:-1"
  qlog("Loading shim ansi3\n");

caller = "ansi3Compile:Unknown file:-1"
  tree = buildProg(cons(boxString("q/shims/ansi3.qon"), getIncludes(tree)), getTypes(tree), getFunctions(tree))
caller = "ansi3Compile:Unknown file:-1"
  qlog("Loading all includes\n");

caller = "ansi3Compile:Unknown file:-1"
  tree = loadIncludes(tree)
caller = "ansi3Compile:Unknown file:-1"
  qlog("Applying macros\n");

caller = "ansi3Compile:Unknown file:-1"
  tree = macrowalk(tree)
caller = "ansi3Compile:Unknown file:-1"
  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), nil))
caller = "ansi3Compile:Unknown file:-1"
  tree = macrolist(tree, stringConcatenate("q", "log"), replace)
caller = "ansi3Compile:Unknown file:-1"
  qlog("//Printing program\n");

caller = "ansi3Compile:Unknown file:-1"
  ansi3Includes(cdr(first(tree)));

caller = "ansi3Compile:Unknown file:-1"
  ansi3Types(cdr(second(tree)));

caller = "ansi3Compile:Unknown file:-1"
  ansi3displays("Box* globalStackTrace = NULL;\n");

caller = "ansi3Compile:Unknown file:-1"
  ansi3displays("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");

caller = "ansi3Compile:Unknown file:-1"
  ansi3ForwardDeclarations(cdr(third(tree)));

caller = "ansi3Compile:Unknown file:-1"
  ansi3displays("\n\n//End forward declarations\n\n");

caller = "ansi3Compile:Unknown file:-1"
  ansi3Functions(cdr(third(tree)));

caller = "ansi3Compile:Unknown file:-1"
  ansi3displays("\n");

caller = "ansi3Compile:Unknown file:-1"
  qlog("//Done printing program\n");

end
-- Chose function name ansi2displays
function ansi2displays(s)
print("caller: ", caller, "-> ansi2displays")
caller = "ansi2displays:Unknown file:-1"
  printf("%s", s);

end
-- Chose function name ansi2FunctionArgs
function ansi2FunctionArgs(tree)
print("caller: ", caller, "-> ansi2FunctionArgs")
caller = "ansi2FunctionArgs:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      if equalString(stringify(first(tree)), "...") then
caller = ":Unknown file:-1"
          printf("...");

      else
caller = ":Unknown file:-1"
          display(ansi2TypeMap(first(tree)));

caller = ":Unknown file:-1"
          ansi2displays(" ");

caller = ":Unknown file:-1"
          display(second(tree));

      end

caller = ":Unknown file:-1"
      if isNil(cddr(tree)) then
      else
caller = ":Unknown file:-1"
          ansi2displays(", ");

      end

caller = ":Unknown file:-1"
      ansi2FunctionArgs(cddr(tree));

  end

end
-- Chose function name ansi2Expression
function ansi2Expression(tree,indent)
print("caller: ", caller, "-> ansi2Expression")
local thing =nil
caller = "ansi2Expression:Unknown file:-1"
  if isList(tree) then
caller = ":Unknown file:-1"
      if equal(1, listLength(tree)) then
caller = ":Unknown file:-1"
          display(car(tree));

caller = ":Unknown file:-1"
          if equalBox(boxString("return"), car(tree)) then
          else
caller = ":Unknown file:-1"
              ansi2displays("()");

          end

      else
caller = ":Unknown file:-1"
          thing = first(tree)
caller = ":Unknown file:-1"
          if equalBox(boxSymbol("get-struct"), thing) then
caller = ":Unknown file:-1"
              printf("%s->%s", stringify(second(tree)), stringify(third(tree)));

          else
caller = ":Unknown file:-1"
              if equalBox(boxSymbol("new"), thing) then
caller = ":Unknown file:-1"
                  printf("malloc(sizeof(%s))", stringify(third(tree)));

              else
caller = ":Unknown file:-1"
                  if equalBox(boxSymbol("passthrough"), thing) then
caller = ":Unknown file:-1"
                      printf("%s", stringify(second(tree)));

                  else
caller = ":Unknown file:-1"
                      if equalBox(boxSymbol("binop"), thing) then
caller = ":Unknown file:-1"
                          printf("(");

caller = ":Unknown file:-1"
                          ansi2Expression(third(tree), indent);

caller = ":Unknown file:-1"
                          printf(" %s ", stringify(second(tree)));

caller = ":Unknown file:-1"
                          ansi2Expression(fourth(tree), indent);

caller = ":Unknown file:-1"
                          printf(")");

                      else
caller = ":Unknown file:-1"
                          printf("%s(", stringify(ansi2FuncMap(car(tree))));

caller = ":Unknown file:-1"
                          ansi2RecurList(cdr(tree), indent);

caller = ":Unknown file:-1"
                          printf(")");

                      end

                  end

              end

          end

      end

  else
caller = ":Unknown file:-1"
      display(ansi2FuncMap(tree));

  end

end
-- Chose function name ansi2RecurList
function ansi2RecurList(expr,indent)
print("caller: ", caller, "-> ansi2RecurList")
caller = "ansi2RecurList:Unknown file:-1"
  if isEmpty(expr) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      ansi2Expression(car(expr), indent);

caller = ":Unknown file:-1"
      if isNil(cdr(expr)) then
caller = ":Unknown file:-1"
          ansi2displays("");

      else
caller = ":Unknown file:-1"
          ansi2displays(", ");

caller = ":Unknown file:-1"
          ansi2RecurList(cdr(expr), indent);

      end

  end

end
-- Chose function name ansi2If
function ansi2If(node,indent)
print("caller: ", caller, "-> ansi2If")
caller = "ansi2If:Unknown file:-1"
  newLine(indent);

caller = "ansi2If:Unknown file:-1"
  ansi2displays("if ( ");

caller = "ansi2If:Unknown file:-1"
  ansi2Expression(second(node), 0);

caller = "ansi2If:Unknown file:-1"
  ansi2displays(") {");

caller = "ansi2If:Unknown file:-1"
  ansi2Body(cdr(third(node)), add1(indent));

caller = "ansi2If:Unknown file:-1"
  newLine(indent);

caller = "ansi2If:Unknown file:-1"
  ansi2displays("} else {");

caller = "ansi2If:Unknown file:-1"
  ansi2Body(cdr(fourth(node)), add1(indent));

caller = "ansi2If:Unknown file:-1"
  newLine(indent);

caller = "ansi2If:Unknown file:-1"
  ansi2displays("}");

end
-- Chose function name ansi2SetStruct
function ansi2SetStruct(node,indent)
print("caller: ", caller, "-> ansi2SetStruct")
caller = "ansi2SetStruct:Unknown file:-1"
  newLine(indent);

caller = "ansi2SetStruct:Unknown file:-1"
  printf("%s->%s = ", stringify(second(node)), stringify(third(node)));

caller = "ansi2SetStruct:Unknown file:-1"
  ansi2Expression(fourth(node), indent);

end
-- Chose function name ansi2GetStruct
function ansi2GetStruct(node,indent)
print("caller: ", caller, "-> ansi2GetStruct")
caller = "ansi2GetStruct:Unknown file:-1"
  newLine(indent);

caller = "ansi2GetStruct:Unknown file:-1"
  printf("%s->%s", stringify(first(node)), stringify(second(node)));

end
-- Chose function name ansi2Set
function ansi2Set(node,indent)
print("caller: ", caller, "-> ansi2Set")
caller = "ansi2Set:Unknown file:-1"
  newLine(indent);

caller = "ansi2Set:Unknown file:-1"
  ansi2Expression(first(cdr(node)), indent);

caller = "ansi2Set:Unknown file:-1"
  printf(" = ");

caller = "ansi2Set:Unknown file:-1"
  ansi2Expression(third(node), indent);

end
-- Chose function name ansi2Return
function ansi2Return(node,indent)
print("caller: ", caller, "-> ansi2Return")
caller = "ansi2Return:Unknown file:-1"
  newLine(indent);

caller = "ansi2Return:Unknown file:-1"
  if equal(listLength(node), 1) then
caller = ":Unknown file:-1"
      ansi2displays("return;");

  else
caller = ":Unknown file:-1"
      ansi2displays("return ");

caller = ":Unknown file:-1"
      ansi2Expression(cadr(node), indent);

caller = ":Unknown file:-1"
      ansi2displays(";");

  end

end
-- Chose function name ansi2Statement
function ansi2Statement(node,indent)
print("caller: ", caller, "-> ansi2Statement")
caller = "ansi2Statement:Unknown file:-1"
  if equalBox(boxString("set"), first(node)) then
caller = ":Unknown file:-1"
      ansi2Set(node, indent);

  else
caller = ":Unknown file:-1"
      if equalBox(boxString("set-struct"), first(node)) then
caller = ":Unknown file:-1"
          ansi2SetStruct(node, indent);

      else
caller = ":Unknown file:-1"
          if equalBox(boxString("if"), first(node)) then
caller = ":Unknown file:-1"
              ansi2If(node, indent);

          else
caller = ":Unknown file:-1"
              if equalBox(boxString("return"), first(node)) then
caller = ":Unknown file:-1"
                  ansi2Return(node, indent);

              else
caller = ":Unknown file:-1"
                  newLine(indent);

caller = ":Unknown file:-1"
                  ansi2Expression(node, indent);

              end

          end

      end

  end

caller = "ansi2Statement:Unknown file:-1"
  ansi2displays(";\n");

end
-- Chose function name ansi2Body
function ansi2Body(tree,indent)
print("caller: ", caller, "-> ansi2Body")
local code =nil
caller = "ansi2Body:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      code = tree
caller = ":Unknown file:-1"
      if isNil(code) then
      else
caller = ":Unknown file:-1"
          code = car(tree)
caller = ":Unknown file:-1"
          printf("\nif (globalTrace)\n    snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail(car(code), boxString("filename"), boxString("Unknown file (not provided by parser)"))), stringify(getTagFail(car(code), boxString("line"), boxString("Line missing"))));

      end

caller = ":Unknown file:-1"
      printIndent(indent);

caller = ":Unknown file:-1"
      printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n");

caller = ":Unknown file:-1"
      ansi2Statement(code, indent);

caller = ":Unknown file:-1"
      ansi2Body(cdr(tree), indent);

  end

end
-- Chose function name ansi2Declarations
function ansi2Declarations(decls,indent)
print("caller: ", caller, "-> ansi2Declarations")
local decl =nil
caller = "ansi2Declarations:Unknown file:-1"
  if isEmpty(decls) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      decl = car(decls)
caller = ":Unknown file:-1"
      printf("%s %s = ", stringify(ansi2TypeMap(first(decl))), stringify(second(decl)));

caller = ":Unknown file:-1"
      ansi2Expression(third(decl), indent);

caller = ":Unknown file:-1"
      printf(";\n");

caller = ":Unknown file:-1"
      ansi2Declarations(cdr(decls), indent);

  end

end
-- Chose function name ansi2Function
function ansi2Function(node)
print("caller: ", caller, "-> ansi2Function")
local name =nil
caller = "ansi2Function:Unknown file:-1"
  name = second(node)
caller = "ansi2Function:Unknown file:-1"
  printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));

caller = "ansi2Function:Unknown file:-1"
  newLine(0);

caller = "ansi2Function:Unknown file:-1"
  if isNil(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      newLine(0);

caller = ":Unknown file:-1"
      printf("%s %s(", stringify(ansi2TypeMap(first(node))), stringify(second(node)));

caller = ":Unknown file:-1"
      ansi2FunctionArgs(third(node));

caller = ":Unknown file:-1"
      printf(") {");

caller = ":Unknown file:-1"
      newLine(1);

caller = ":Unknown file:-1"
      ansi2Declarations(cdr(fourth(node)), 1);

caller = ":Unknown file:-1"
      if inList(toStr(name), noStackTrace()) then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf("\nif (globalTrace)\n    printf(\"%s at %s:%s (%%s)\\n\", caller);\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

      end

caller = ":Unknown file:-1"
      if inList(toStr(name), noStackTrace()) then
caller = ":Unknown file:-1"
          printf("");

      else
      end

caller = ":Unknown file:-1"
      ansi2Body(cdr(fifth(node)), 1);

caller = ":Unknown file:-1"
      if inList(toStr(name), noStackTrace()) then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf("\nif (globalTrace)\n    printf(\"Leaving %s\\n\");\n", stringify(name));

      end

caller = ":Unknown file:-1"
      printf("\n}\n");

  end

end
-- Chose function name ansi2ForwardDeclaration
function ansi2ForwardDeclaration(node)
print("caller: ", caller, "-> ansi2ForwardDeclaration")
caller = "ansi2ForwardDeclaration:Unknown file:-1"
  if isNil(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      printf("\n%s %s(", stringify(ansi2TypeMap(first(node))), stringify(second(node)));

caller = ":Unknown file:-1"
      ansi2FunctionArgs(third(node));

caller = ":Unknown file:-1"
      ansi2displays(");");

  end

end
-- Chose function name ansi2ForwardDeclarations
function ansi2ForwardDeclarations(tree)
print("caller: ", caller, "-> ansi2ForwardDeclarations")
caller = "ansi2ForwardDeclarations:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      ansi2ForwardDeclaration(car(tree));

caller = ":Unknown file:-1"
      ansi2ForwardDeclarations(cdr(tree));

  end

end
-- Chose function name ansi2Functions
function ansi2Functions(tree)
print("caller: ", caller, "-> ansi2Functions")
caller = "ansi2Functions:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      ansi2Function(car(tree));

caller = ":Unknown file:-1"
      ansi2Functions(cdr(tree));

  end

end
-- Chose function name ansi2Includes
function ansi2Includes(nodes)
print("caller: ", caller, "-> ansi2Includes")
caller = "ansi2Includes:Unknown file:-1"
  printf("%s", "\n//Start include block\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\nconst char* getEnv(char* key){return getenv(key);}\n void panic(char* s){abort();exit(1);}\nint sub(int a, int b) { return a - b; }\nfloat mult(int a, int b) { return a * b; }\nint greaterthan(int a, int b) { return a > b; }\nfloat subf(float a, float b) { return a - b; }\nfloat multf(float a, float b) { return a * b; }\nint greaterthanf(float a, float b) { return a > b; }\nint equal(int a, int b) { return a == b; }\nint equalString(char* a, char* b) { return !strcmp(a,b); }\nint andBool(int a, int b) { return a && b;}\nint string_length(char* s) { return strlen(s);}\nchar* setSubString(char* target, int start,char *source){target[start]=source[0]; return target;}\nchar* sub_string(char* s, int start, int length) {\nchar* substr = calloc(length+1, 1);\nstrncpy(substr, s+start, length);\nreturn substr;\n}\n\n\n\nchar* stringConcatenate(char* a, char* b) {\nint len = strlen(a) + strlen(b) + 1;\nchar* target = calloc(len,1);\nstrncat(target, a, len);\nstrncat(target, b, len);\nreturn target;\n}\n\nchar* intToString(int a) {\nint len = 100;\nchar* target = calloc(len,1);\nsnprintf(target, 99, \"%d\", a);\nreturn target;\n}\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\nvoid * gc_malloc( unsigned int size ) {\nreturn malloc( size);\n}\n\nint* makeArray(int length) {\n    int * array = gc_malloc(length*sizeof(int));\n    return array;\n}\n\nint at(int* arr, int index) {\n  return arr[index];\n}\n\nvoid setAt(int* array, int index, int value) {\n    array[index] = value;\n}\n\nchar * read_file(char * filename) {\nchar * buffer = 0;\nlong length;\nFILE * f = fopen (filename, \"rb\");\n\nif (f)\n{\n  fseek (f, 0, SEEK_END);\n  length = ftell (f);\n  fseek (f, 0, SEEK_SET);\n  buffer = calloc (length+1,1);\n  if (buffer == NULL) {\n  printf(\"Malloc failed!\\n\");\n  exit(1);\n}\n  if (buffer)\n  {\n    fread (buffer, 1, length, f);\n  }\n  fclose (f);\n}\nreturn buffer;\n}\n\n\nvoid write_file (char * filename, char * data) {\nFILE *f = fopen(filename, \"w\");\nif (f == NULL)\n{\n    printf(\"Error opening file!\");\n    exit(1);\n}\n\nfprintf(f, \"%s\", data);\n\nfclose(f);\n}\n\nchar* getStringArray(int index, char** strs) {\nreturn strs[index];\n}\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\n\nint main( int argc, char *argv[] )  {\n  globalArgs = argv;\n  globalArgsCount = argc;\n  caller=calloc(1024,1);\n\n  return start();\n\n}\n\n");

caller = "ansi2Includes:Unknown file:-1"
  printf("%s", "char * character(int num) { char *string = malloc(2); if (!string) return 0; string[0] = num; string[1] = 0; return string; }");

caller = "ansi2Includes:Unknown file:-1"
  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }\n\n");

caller = "ansi2Includes:Unknown file:-1"
  printf("%s", "bool nand(bool a, bool b) { return !(a&&b); }\n//End include block\n");

end
-- Chose function name ansi2TypeDecl
function ansi2TypeDecl(l)
print("caller: ", caller, "-> ansi2TypeDecl")
caller = "ansi2TypeDecl:Unknown file:-1"
  if greaterthan(listLength(l), 2) then
caller = ":Unknown file:-1"
      printIndent(1);

caller = ":Unknown file:-1"
      printf("%s %s %s;\n", stringify(second(l)), stringify(ansi2TypeMap(listLast(l))), stringify(first(l)));

  else
caller = ":Unknown file:-1"
      printIndent(1);

caller = ":Unknown file:-1"
      printf("%s %s;\n", stringify(ansi2TypeMap(listLast(l))), stringify(car(l)));

  end

end
-- Chose function name ansi2StructComponents
function ansi2StructComponents(node)
print("caller: ", caller, "-> ansi2StructComponents")
caller = "ansi2StructComponents:Unknown file:-1"
  if isEmpty(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      ansi2TypeDecl(car(node));

caller = ":Unknown file:-1"
      ansi2StructComponents(cdr(node));

  end

end
-- Chose function name ansi2Struct
function ansi2Struct(node)
print("caller: ", caller, "-> ansi2Struct")
caller = "ansi2Struct:Unknown file:-1"
  ansi2StructComponents(cdr(node));

end
-- Chose function name ansi2TypeMap
function ansi2TypeMap(aSym)
print("caller: ", caller, "-> ansi2TypeMap")
local symMap =nil
caller = "ansi2TypeMap:Unknown file:-1"
  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), nil))
caller = "ansi2TypeMap:Unknown file:-1"
  if truthy(assoc(stringify(aSym), symMap)) then
caller = ":Unknown file:-1"
      return cdr(assoc(stringify(aSym), symMap))

  else
caller = ":Unknown file:-1"
      return aSym

  end

end
-- Chose function name ansi2FuncMap
function ansi2FuncMap(aSym)
print("caller: ", caller, "-> ansi2FuncMap")
local symMap =nil
caller = "ansi2FuncMap:Unknown file:-1"
  if equalString("symbol", boxType(aSym)) then
caller = ":Unknown file:-1"
      symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("luaSubstring"), boxSymbol("sub_string"), alistCons(boxSymbol("luaReadFile"), boxSymbol("read_file"), alistCons(boxSymbol("luaWriteFile"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string.len"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), nil)))))))
caller = ":Unknown file:-1"
      if truthy(assoc(stringify(aSym), symMap)) then
caller = ":Unknown file:-1"
          return cdr(assoc(stringify(aSym), symMap))

      else
caller = ":Unknown file:-1"
          return aSym

      end

  else
caller = ":Unknown file:-1"
      return aSym

  end

end
-- Chose function name ansi2Type
function ansi2Type(node)
print("caller: ", caller, "-> ansi2Type")
caller = "ansi2Type:Unknown file:-1"
  if isList(second(node)) then
caller = ":Unknown file:-1"
      printf("\ntypedef struct %s {\n", stringify(first(node)));

caller = ":Unknown file:-1"
      ansi2Struct(second(node));

caller = ":Unknown file:-1"
      printf("\n} %s;\n", stringify(first(node)));

  else
caller = ":Unknown file:-1"
      ansi2displays("typedef ");

caller = ":Unknown file:-1"
      ansi2TypeDecl(node);

  end

end
-- Chose function name ansi2Types
function ansi2Types(nodes)
print("caller: ", caller, "-> ansi2Types")
caller = "ansi2Types:Unknown file:-1"
  if isEmpty(nodes) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      ansi2Type(car(nodes));

caller = ":Unknown file:-1"
      ansi2Types(cdr(nodes));

  end

end
-- Chose function name ansi2Compile
function ansi2Compile(filename)
print("caller: ", caller, "-> ansi2Compile")
local tree =nil
local replace =nil
caller = "ansi2Compile:Unknown file:-1"
  qlog("//Scanning file...%s\n", filename);

caller = "ansi2Compile:Unknown file:-1"
  tree = loadQuon(filename)
caller = "ansi2Compile:Unknown file:-1"
  qlog("//Building sexpr\n");

caller = "ansi2Compile:Unknown file:-1"
  tree = loadIncludes(tree)
caller = "ansi2Compile:Unknown file:-1"
  tree = macrowalk(tree)
caller = "ansi2Compile:Unknown file:-1"
  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), nil))
caller = "ansi2Compile:Unknown file:-1"
  tree = macrolist(tree, stringConcatenate("q", "log"), replace)
caller = "ansi2Compile:Unknown file:-1"
  qlog("//Printing program\n");

caller = "ansi2Compile:Unknown file:-1"
  ansi2Includes(cdr(first(tree)));

caller = "ansi2Compile:Unknown file:-1"
  ansi2Types(cdr(second(tree)));

caller = "ansi2Compile:Unknown file:-1"
  ansi2displays("Box* globalStackTrace = NULL;\n");

caller = "ansi2Compile:Unknown file:-1"
  ansi2displays("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");

caller = "ansi2Compile:Unknown file:-1"
  ansi2ForwardDeclarations(cdr(third(tree)));

caller = "ansi2Compile:Unknown file:-1"
  ansi2displays("\n\n//End forward declarations\n\n");

caller = "ansi2Compile:Unknown file:-1"
  ansi2Functions(cdr(third(tree)));

caller = "ansi2Compile:Unknown file:-1"
  ansi2displays("\n");

end
-- Chose function name ansiFunctionArgs
function ansiFunctionArgs(tree)
print("caller: ", caller, "-> ansiFunctionArgs")
caller = "ansiFunctionArgs:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      display(ansiTypeMap(first(tree)));

caller = ":Unknown file:-1"
      printf(" ");

caller = ":Unknown file:-1"
      display(second(tree));

caller = ":Unknown file:-1"
      if isNil(cddr(tree)) then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf(",");

      end

caller = ":Unknown file:-1"
      ansiFunctionArgs(cddr(tree));

  end

end
-- Chose function name ansiLeaf
function ansiLeaf(thisNode,indent)
print("caller: ", caller, "-> ansiLeaf")
caller = "ansiLeaf:Unknown file:-1"
  display(ansiFuncMap(codeof(thisNode)));

end
-- Chose function name ansiStructGetterExpression
function ansiStructGetterExpression(thisNode,indent)
print("caller: ", caller, "-> ansiStructGetterExpression")
caller = "ansiStructGetterExpression:Unknown file:-1"
  if equalBox(boxString("structGetter"), subnameof(thisNode)) then
caller = ":Unknown file:-1"
      ansiGetStruct(thisNode, indent);

  else
caller = ":Unknown file:-1"
      ansiLeaf(thisNode, indent);

  end

end
-- Chose function name ansiExpression
function ansiExpression(node,indent)
print("caller: ", caller, "-> ansiExpression")
caller = "ansiExpression:Unknown file:-1"
  if isLeaf(node) then
caller = ":Unknown file:-1"
      display(ansiFuncMap(codeof(node)));

  else
caller = ":Unknown file:-1"
      ansiSubExpression(node, indent);

  end

end
-- Chose function name ansiRecurList
function ansiRecurList(expr,indent)
print("caller: ", caller, "-> ansiRecurList")
caller = "ansiRecurList:Unknown file:-1"
  if isEmpty(expr) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      ansiExpression(car(expr), indent);

caller = ":Unknown file:-1"
      if isNil(cdr(expr)) then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf(", ");

caller = ":Unknown file:-1"
          ansiRecurList(cdr(expr), indent);

      end

  end

end
-- Chose function name ansiSubExpression
function ansiSubExpression(tree,indent)
print("caller: ", caller, "-> ansiSubExpression")
local thing =nil
caller = "ansiSubExpression:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      if isNode(childrenof(tree)) then
caller = ":Unknown file:-1"
          ansiSubExpression(childrenof(tree), indent);

      else
caller = ":Unknown file:-1"
          if isLeaf(tree) then
caller = ":Unknown file:-1"
              display(ansiFuncMap(codeof(tree)));

          else
caller = ":Unknown file:-1"
              if equal(1, listLength(childrenof(tree))) then
caller = ":Unknown file:-1"
                  display(codeof(car(childrenof(tree))));

caller = ":Unknown file:-1"
                  if equalBox(boxString("return"), codeof(car(childrenof(tree)))) then
caller = ":Unknown file:-1"
                      printf("");

                  else
caller = ":Unknown file:-1"
                      printf("()");

                  end

              else
caller = ":Unknown file:-1"
                  thing = codeof(car(childrenof(tree)))
caller = ":Unknown file:-1"
                  if equalBox(boxSymbol("get-struct"), thing) then
caller = ":Unknown file:-1"
                      printf("%s->%s", stringify(codeof(second(childrenof(tree)))), stringify(codeof(third(childrenof(tree)))));

                  else
caller = ":Unknown file:-1"
                      if equalBox(boxSymbol("new"), thing) then
caller = ":Unknown file:-1"
                          printf("malloc(sizeof(%s))", stringify(codeof(third(childrenof(tree)))));

                      else
caller = ":Unknown file:-1"
                          printf("%s(", stringify(ansiFuncMap(codeof(car(childrenof(tree))))));

caller = ":Unknown file:-1"
                          ansiRecurList(cdr(childrenof(tree)), indent);

caller = ":Unknown file:-1"
                          printf(")");

                      end

                  end

              end

          end

      end

  end

end
-- Chose function name ansiIf
function ansiIf(node,indent)
print("caller: ", caller, "-> ansiIf")
caller = "ansiIf:Unknown file:-1"
  newLine(indent);

caller = "ansiIf:Unknown file:-1"
  printf("if ( ");

caller = "ansiIf:Unknown file:-1"
  ansiExpression(car(first(childrenof(node))), 0);

caller = "ansiIf:Unknown file:-1"
  printf(") {");

caller = "ansiIf:Unknown file:-1"
  ansiBody(second(childrenof(node)), add1(indent));

caller = "ansiIf:Unknown file:-1"
  newLine(indent);

caller = "ansiIf:Unknown file:-1"
  printf("} else {");

caller = "ansiIf:Unknown file:-1"
  ansiBody(third(childrenof(node)), add1(indent));

caller = "ansiIf:Unknown file:-1"
  newLine(indent);

caller = "ansiIf:Unknown file:-1"
  printf("}");

end
-- Chose function name ansiSetStruct
function ansiSetStruct(node,indent)
print("caller: ", caller, "-> ansiSetStruct")
caller = "ansiSetStruct:Unknown file:-1"
  newLine(indent);

caller = "ansiSetStruct:Unknown file:-1"
  printf("%s->%s = ", stringify(first(codeof(node))), stringify(second(codeof(node))));

caller = "ansiSetStruct:Unknown file:-1"
  ansiExpression(childrenof(node), indent);

end
-- Chose function name ansiGetStruct
function ansiGetStruct(node,indent)
print("caller: ", caller, "-> ansiGetStruct")
caller = "ansiGetStruct:Unknown file:-1"
  newLine(indent);

caller = "ansiGetStruct:Unknown file:-1"
  printf("%s->%s", stringify(first(codeof(node))), stringify(second(codeof(node))));

end
-- Chose function name ansiSet
function ansiSet(node,indent)
print("caller: ", caller, "-> ansiSet")
caller = "ansiSet:Unknown file:-1"
  newLine(indent);

caller = "ansiSet:Unknown file:-1"
  printf("%s = ", stringify(first(codeof(node))));

caller = "ansiSet:Unknown file:-1"
  ansiExpression(childrenof(node), indent);

end
-- Chose function name ansiStatement
function ansiStatement(node,indent)
print("caller: ", caller, "-> ansiStatement")
caller = "ansiStatement:Unknown file:-1"
  if equalBox(boxString("setter"), subnameof(node)) then
caller = ":Unknown file:-1"
      ansiSet(node, indent);

  else
caller = ":Unknown file:-1"
      if equalBox(boxString("structSetter"), subnameof(node)) then
caller = ":Unknown file:-1"
          ansiSetStruct(node, indent);

      else
caller = ":Unknown file:-1"
          if equalBox(boxString("if"), subnameof(node)) then
caller = ":Unknown file:-1"
              ansiIf(node, indent);

          else
caller = ":Unknown file:-1"
              if equalBox(boxString("returnvoid"), subnameof(node)) then
caller = ":Unknown file:-1"
                  newLine(indent);

caller = ":Unknown file:-1"
                  printf("return");

              else
caller = ":Unknown file:-1"
                  newLine(indent);

caller = ":Unknown file:-1"
                  ansiExpression(childrenof(node), indent);

              end

          end

      end

  end

caller = "ansiStatement:Unknown file:-1"
  printf(";\n");

end
-- Chose function name ansiBody
function ansiBody(tree,indent)
print("caller: ", caller, "-> ansiBody")
local code =nil
caller = "ansiBody:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      code = codeof(car(tree))
caller = ":Unknown file:-1"
      if isNil(code) then
      else
caller = ":Unknown file:-1"
          code = car(codeof(car(tree)))
caller = ":Unknown file:-1"
          printf("\n");

caller = ":Unknown file:-1"
          printIndent(indent);

caller = ":Unknown file:-1"
          printf("if (globalTrace)   snprintf(caller, 1024, \"from %s:%s\");\n", stringify(getTagFail(code, boxString("filename"), boxString("Unknown"))), stringify(getTagFail(code, boxString("line"), boxString("Unknown"))));

      end

caller = ":Unknown file:-1"
      printIndent(indent);

caller = ":Unknown file:-1"
      printf("%s", "if (globalStepTrace) printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__);\n");

caller = ":Unknown file:-1"
      ansiStatement(car(tree), indent);

caller = ":Unknown file:-1"
      ansiBody(cdr(tree), indent);

  end

end
-- Chose function name ansiDeclarations
function ansiDeclarations(decls,indent)
print("caller: ", caller, "-> ansiDeclarations")
local decl =nil
caller = "ansiDeclarations:Unknown file:-1"
  if isEmpty(decls) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      decl = car(decls)
caller = ":Unknown file:-1"
      printf("%s %s = ", stringify(ansiTypeMap(first(decl))), stringify(second(decl)));

caller = ":Unknown file:-1"
      display(ansiFuncMap(third(decl)));

caller = ":Unknown file:-1"
      printf(";\n");

caller = ":Unknown file:-1"
      ansiDeclarations(cdr(decls), indent);

  end

end
-- Chose function name ansiFunction
function ansiFunction(node)
print("caller: ", caller, "-> ansiFunction")
local name =nil
caller = "ansiFunction:Unknown file:-1"
  name = subnameof(node)
caller = "ansiFunction:Unknown file:-1"
  printf("\n\n//Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));

caller = "ansiFunction:Unknown file:-1"
  newLine(0);

caller = "ansiFunction:Unknown file:-1"
  if isNil(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      newLine(0);

caller = ":Unknown file:-1"
      printf("%s %s(", stringify(ansiTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));

caller = ":Unknown file:-1"
      ansiFunctionArgs(cdr(assoc("intype", cdr(node))));

caller = ":Unknown file:-1"
      printf(") {");

caller = ":Unknown file:-1"
      newLine(1);

caller = ":Unknown file:-1"
      ansiDeclarations(declarationsof(node), 1);

caller = ":Unknown file:-1"
      if inList(toStr(name), noStackTrace()) then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf("\nif (globalTrace)\n    fprintf(stderr, \"%s at %s:%s (%%s)\\n\", caller);\n", stringify(name), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

      end

caller = ":Unknown file:-1"
      if inList(toStr(name), noStackTrace()) then
caller = ":Unknown file:-1"
          printf("");

      else
      end

caller = ":Unknown file:-1"
      ansiBody(childrenof(node), 1);

caller = ":Unknown file:-1"
      if inList(toStr(name), noStackTrace()) then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf("\nif (globalTrace)\n    fprintf(stderr, \"Leaving %s\\n\");\n", stringify(name));

      end

caller = ":Unknown file:-1"
      printf("\n}\n");

  end

end
-- Chose function name ansiForwardDeclaration
function ansiForwardDeclaration(node)
print("caller: ", caller, "-> ansiForwardDeclaration")
caller = "ansiForwardDeclaration:Unknown file:-1"
  if isNil(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      printf("\n%s %s(", stringify(ansiTypeMap(cdr(assoc("outtype", cdr(node))))), stringify(subnameof(node)));

caller = ":Unknown file:-1"
      ansiFunctionArgs(cdr(assoc("intype", cdr(node))));

caller = ":Unknown file:-1"
      printf(");");

  end

end
-- Chose function name ansiForwardDeclarations
function ansiForwardDeclarations(tree)
print("caller: ", caller, "-> ansiForwardDeclarations")
caller = "ansiForwardDeclarations:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      ansiForwardDeclaration(car(tree));

caller = ":Unknown file:-1"
      ansiForwardDeclarations(cdr(tree));

  end

end
-- Chose function name ansiFunctions
function ansiFunctions(tree)
print("caller: ", caller, "-> ansiFunctions")
caller = "ansiFunctions:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      ansiFunction(car(tree));

caller = ":Unknown file:-1"
      ansiFunctions(cdr(tree));

  end

end
-- Chose function name ansiIncludes
function ansiIncludes(nodes)
print("caller: ", caller, "-> ansiIncludes")
caller = "ansiIncludes:Unknown file:-1"
  printf("%s", "\n#include <stdarg.h>\n#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\nconst char* getEnv(char* key){return getenv(key);}\n void panic(char* s){abort();exit(1);}\nint not(int a){return !a;}\nint sub(int a, int b) { return a - b; }\nfloat mult(int a, int b) { return a * b; }\nint greaterthan(int a, int b) { return a > b; }\nfloat subf(float a, float b) { return a - b; }\nfloat multf(float a, float b) { return a * b; }\nint greaterthanf(float a, float b) { return a > b; }\nint equal(int a, int b) { return a == b; }\nint equalString(char* a, char* b) { return !strcmp(a,b); }\nint andBool(int a, int b) { return a && b;}\nint string_length(char* s) { return strlen(s);}\nchar* setSubString(char* target, int start,char *source){target[start]=source[0]; return target;}\nchar* sub_string(char* s, int start, int length) {\nchar* substr = calloc(length+1, 1);\nstrncpy(substr, s+start, length);\nreturn substr;\n}\n\n\n\nchar* stringConcatenate(char* a, char* b) {\nint len = strlen(a) + strlen(b) + 1;\nchar* target = calloc(len,1);\nstrncat(target, a, len);\nstrncat(target, b, len);\nreturn target;\n}\n\nchar* intToString(int a) {\nint len = 100;\nchar* target = calloc(len,1);\nsnprintf(target, 99, \"%d\", a);\nreturn target;\n}\n\ntypedef int*  array;\ntypedef int bool;\n#define true 1\n#define false 0\n\n\nvoid * gc_malloc( unsigned int size ) {\nreturn malloc(size);\n}\n\nint* makeArray(int length) {\n    int * array = gc_malloc(length*sizeof(int));\n    return array;\n}\n\nint at(int* arr, int index) {\n  return arr[index];\n}\n\nvoid setAt(int* array, int index, int value) {\n    array[index] = value;\n}\n\nchar * read_file(char * filename) {\nchar * buffer = 0;\nlong length;\nFILE * f = fopen (filename, \"rb\");\n\nif (f)\n{\n  fseek (f, 0, SEEK_END);\n  length = ftell (f);\n  fseek (f, 0, SEEK_SET);\n  buffer = calloc (length+1,1);\n  if (buffer == NULL) {\n  printf(\"Malloc failed!\\n\");\n  exit(1);\n}\n  if (buffer)\n  {\n    fread (buffer, 1, length, f);\n  }\n  fclose (f);\n}\nreturn buffer;\n}\n\n\nvoid write_file (char * filename, char * data) {\nFILE *f = fopen(filename, \"w\");\nif (f == NULL)\n{\n    printf(\"Error opening file!\");\n    exit(1);\n}\n\nfprintf(f, \"%s\", data);\n\nfclose(f);\n}\n\nchar* getStringArray(int index, char** strs) {\nreturn strs[index];\n}\n\nint start();  //Forwards declare the user's main routine\nchar* caller;\nchar** globalArgs;\nint globalArgsCount;\nbool globalTrace = false;\nbool globalStepTrace = false;\n\nint main( int argc, char *argv[] )  {\n  globalArgs = argv;\n  globalArgsCount = argc;\n  caller=calloc(1024,1);\n\n  return start();\n\n}\n\n");

caller = "ansiIncludes:Unknown file:-1"
  printf("%s", "char * character(int num) { char *string = malloc(2); if (!string) return 0; string[0] = num; string[1] = 0; return string; }");

caller = "ansiIncludes:Unknown file:-1"
  printf("%s", "void qlog(const char* format, ...) { va_list args; va_start (args, format); vfprintf (stderr, format, args); va_end (args); }");

caller = "ansiIncludes:Unknown file:-1"
  printf("%s", "bool nand(bool a, bool b) { return !(a&&b); }\n//End include block\n");

end
-- Chose function name ansiTypeDecl
function ansiTypeDecl(l)
print("caller: ", caller, "-> ansiTypeDecl")
caller = "ansiTypeDecl:Unknown file:-1"
  if greaterthan(listLength(l), 2) then
caller = ":Unknown file:-1"
      printIndent(1);

caller = ":Unknown file:-1"
      printf("%s %s %s;\n", stringify(second(l)), stringify(ansiTypeMap(listLast(l))), stringify(first(l)));

  else
caller = ":Unknown file:-1"
      printIndent(1);

caller = ":Unknown file:-1"
      printf("%s %s;\n", stringify(ansiTypeMap(listLast(l))), stringify(car(l)));

  end

end
-- Chose function name ansiStructComponents
function ansiStructComponents(node)
print("caller: ", caller, "-> ansiStructComponents")
caller = "ansiStructComponents:Unknown file:-1"
  if isEmpty(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      ansiTypeDecl(car(node));

caller = ":Unknown file:-1"
      ansiStructComponents(cdr(node));

  end

end
-- Chose function name ansiStruct
function ansiStruct(node)
print("caller: ", caller, "-> ansiStruct")
caller = "ansiStruct:Unknown file:-1"
  ansiStructComponents(cdr(car(node)));

end
-- Chose function name ansiTypeMap
function ansiTypeMap(aSym)
print("caller: ", caller, "-> ansiTypeMap")
local symMap =nil
caller = "ansiTypeMap:Unknown file:-1"
  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), nil))
caller = "ansiTypeMap:Unknown file:-1"
  if truthy(assoc(stringify(aSym), symMap)) then
caller = ":Unknown file:-1"
      return cdr(assoc(stringify(aSym), symMap))

  else
caller = ":Unknown file:-1"
      return aSym

  end

end
-- Chose function name ansiFuncMap
function ansiFuncMap(aSym)
print("caller: ", caller, "-> ansiFuncMap")
local symMap =nil
caller = "ansiFuncMap:Unknown file:-1"
  if equalString("symbol", boxType(aSym)) then
caller = ":Unknown file:-1"
      symMap = alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("luaSubstring"), boxSymbol("sub_string"), alistCons(boxSymbol("luaReadFile"), boxSymbol("read_file"), alistCons(boxSymbol("luaWriteFile"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string.len"), boxSymbol("string_length"), alistCons(boxSymbol("nil"), boxSymbol("NULL"), nil)))))))
caller = ":Unknown file:-1"
      if truthy(assoc(stringify(aSym), symMap)) then
caller = ":Unknown file:-1"
          return cdr(assoc(stringify(aSym), symMap))

      else
caller = ":Unknown file:-1"
          return aSym

      end

  else
caller = ":Unknown file:-1"
      return aSym

  end

end
-- Chose function name ansiType
function ansiType(node)
print("caller: ", caller, "-> ansiType")
caller = "ansiType:Unknown file:-1"
  if equalBox(subnameof(node), boxString("struct")) then
caller = ":Unknown file:-1"
      printf("\ntypedef struct %s {\n", stringify(first(codeof(node))));

caller = ":Unknown file:-1"
      ansiStruct(cdr(codeof(node)));

caller = ":Unknown file:-1"
      printf("\n} %s;\n", stringify(first(codeof(node))));

  else
caller = ":Unknown file:-1"
      printf("typedef ");

caller = ":Unknown file:-1"
      ansiTypeDecl(codeof(node));

  end

end
-- Chose function name ansiTypes
function ansiTypes(nodes)
print("caller: ", caller, "-> ansiTypes")
caller = "ansiTypes:Unknown file:-1"
  if isEmpty(nodes) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      ansiType(car(nodes));

caller = ":Unknown file:-1"
      ansiTypes(cdr(nodes));

  end

end
-- Chose function name ansiCompile
function ansiCompile(filename)
print("caller: ", caller, "-> ansiCompile")
local programStr =""
local tree =nil
local program =nil
caller = "ansiCompile:Unknown file:-1"
  printf("//Scanning file...%s\n", filename);

caller = "ansiCompile:Unknown file:-1"
  programStr = luaReadFile(filename)
caller = "ansiCompile:Unknown file:-1"
  printf("//Building sexpr\n");

caller = "ansiCompile:Unknown file:-1"
  tree = readSexpr(programStr, filename)
caller = "ansiCompile:Unknown file:-1"
  tree = macrowalk(tree)
caller = "ansiCompile:Unknown file:-1"
  cons(boxString("a"), cons(boxString("b"), cons(boxString("c"), nil)));

caller = "ansiCompile:Unknown file:-1"
  printf("//Building AST\n");

caller = "ansiCompile:Unknown file:-1"
  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), nil)))
caller = "ansiCompile:Unknown file:-1"
  printf("//Merging ASTs\n");

caller = "ansiCompile:Unknown file:-1"
  program = mergeIncludes(program)
caller = "ansiCompile:Unknown file:-1"
  printf("//Printing program\n");

caller = "ansiCompile:Unknown file:-1"
  ansiIncludes(cdr(assoc("includes", program)));

caller = "ansiCompile:Unknown file:-1"
  ansiTypes(childrenof(cdr(assoc("types", program))));

caller = "ansiCompile:Unknown file:-1"
  printf("Box* globalStackTrace = NULL;\n");

caller = "ansiCompile:Unknown file:-1"
  printf("\nbool isNil(list p) {\n    return p == NULL;\n}\n\n\n//Forward declarations\n");

caller = "ansiCompile:Unknown file:-1"
  ansiForwardDeclarations(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));

caller = "ansiCompile:Unknown file:-1"
  printf("\n\n//End forward declarations\n\n");

caller = "ansiCompile:Unknown file:-1"
  ansiFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));

caller = "ansiCompile:Unknown file:-1"
  printf("\n");

end
-- Chose function name numbers
function numbers(num)
print("caller: ", caller, "-> numbers")
caller = "numbers:Unknown file:-1"
  if greaterthan(0, num) then
caller = ":Unknown file:-1"
      return cons(boxString("-"), nil)

  else
caller = ":Unknown file:-1"
      return cons(boxString(stringify(boxInt(num))), numbers(sub1(num)))

  end

end
-- Chose function name lexType
function lexType(abox)
print("caller: ", caller, "-> lexType")
caller = "lexType:Unknown file:-1"
  if equalString("string", boxType(abox)) then
caller = ":Unknown file:-1"
      return "string"

  else
caller = ":Unknown file:-1"
      if inList(boxString(luaSubstring(stringify(abox), 0, 1)), numbers(9)) then
caller = ":Unknown file:-1"
          return "number"

      else
caller = ":Unknown file:-1"
          return "symbol"

      end

  end

end
-- Chose function name perlLeaf
function perlLeaf(thisNode,indent)
print("caller: ", caller, "-> perlLeaf")
caller = "perlLeaf:Unknown file:-1"
  if equalString("symbol", lexType(codeof(thisNode))) then
caller = ":Unknown file:-1"
      printf("%s", dollar());

  else
caller = ":Unknown file:-1"
      printf("");

  end

caller = "perlLeaf:Unknown file:-1"
  display(perlFuncMap(codeof(thisNode)));

end
-- Chose function name perlStructGetterExpression
function perlStructGetterExpression(thisNode,indent)
print("caller: ", caller, "-> perlStructGetterExpression")
caller = "perlStructGetterExpression:Unknown file:-1"
  if equalBox(boxString("structGetter"), subnameof(thisNode)) then
caller = ":Unknown file:-1"
      perlGetStruct(thisNode, indent);

  else
caller = ":Unknown file:-1"
      perlLeaf(thisNode, indent);

  end

end
-- Chose function name perlExpression
function perlExpression(node,indent)
print("caller: ", caller, "-> perlExpression")
caller = "perlExpression:Unknown file:-1"
  if isLeaf(node) then
caller = ":Unknown file:-1"
      perlLeaf(node, indent);

  else
caller = ":Unknown file:-1"
      perlSubExpression(node, indent);

  end

end
-- Chose function name perlRecurList
function perlRecurList(expr,indent)
print("caller: ", caller, "-> perlRecurList")
caller = "perlRecurList:Unknown file:-1"
  if isEmpty(expr) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      perlExpression(car(expr), indent);

caller = ":Unknown file:-1"
      if isNil(cdr(expr)) then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf(", ");

caller = ":Unknown file:-1"
          perlRecurList(cdr(expr), indent);

      end

  end

end
-- Chose function name perlSubExpression
function perlSubExpression(tree,indent)
print("caller: ", caller, "-> perlSubExpression")
local thing =nil
caller = "perlSubExpression:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      if isNode(childrenof(tree)) then
caller = ":Unknown file:-1"
          perlSubExpression(childrenof(tree), indent);

      else
caller = ":Unknown file:-1"
          if isLeaf(tree) then
caller = ":Unknown file:-1"
              printf("%s", dollar());

caller = ":Unknown file:-1"
              display(perlFuncMap(codeof(tree)));

          else
caller = ":Unknown file:-1"
              if equal(1, listLength(childrenof(tree))) then
caller = ":Unknown file:-1"
                  display(codeof(car(childrenof(tree))));

caller = ":Unknown file:-1"
                  if equalBox(boxString("return"), codeof(car(childrenof(tree)))) then
caller = ":Unknown file:-1"
                      printf("");

                  else
caller = ":Unknown file:-1"
                      printf("()");

                  end

              else
caller = ":Unknown file:-1"
                  thing = codeof(car(childrenof(tree)))
caller = ":Unknown file:-1"
                  if equalBox(boxSymbol("get-struct"), thing) then
caller = ":Unknown file:-1"
                      printf("%s%s->{%s}", dollar(), stringify(codeof(second(childrenof(tree)))), stringify(codeof(third(childrenof(tree)))));

                  else
caller = ":Unknown file:-1"
                      if equalBox(boxSymbol("new"), thing) then
caller = ":Unknown file:-1"
                          printf("{}");

                      else
caller = ":Unknown file:-1"
                          printf("%s(", stringify(perlFuncMap(codeof(car(childrenof(tree))))));

caller = ":Unknown file:-1"
                          perlRecurList(cdr(childrenof(tree)), indent);

caller = ":Unknown file:-1"
                          printf(")");

                      end

                  end

              end

          end

      end

  end

end
-- Chose function name perlIf
function perlIf(node,indent)
print("caller: ", caller, "-> perlIf")
caller = "perlIf:Unknown file:-1"
  newLine(indent);

caller = "perlIf:Unknown file:-1"
  printf("if ( ");

caller = "perlIf:Unknown file:-1"
  perlExpression(car(first(childrenof(node))), 0);

caller = "perlIf:Unknown file:-1"
  printf(") {");

caller = "perlIf:Unknown file:-1"
  perlBody(second(childrenof(node)), add1(indent));

caller = "perlIf:Unknown file:-1"
  newLine(indent);

caller = "perlIf:Unknown file:-1"
  printf("} else {");

caller = "perlIf:Unknown file:-1"
  perlBody(third(childrenof(node)), add1(indent));

caller = "perlIf:Unknown file:-1"
  newLine(indent);

caller = "perlIf:Unknown file:-1"
  printf("}");

end
-- Chose function name perlSetStruct
function perlSetStruct(node,indent)
print("caller: ", caller, "-> perlSetStruct")
caller = "perlSetStruct:Unknown file:-1"
  newLine(indent);

caller = "perlSetStruct:Unknown file:-1"
  printf("%s%s->{%s} = ", dollar(), stringify(first(codeof(node))), stringify(second(codeof(node))));

caller = "perlSetStruct:Unknown file:-1"
  perlExpression(childrenof(node), indent);

end
-- Chose function name perlGetStruct
function perlGetStruct(node,indent)
print("caller: ", caller, "-> perlGetStruct")
caller = "perlGetStruct:Unknown file:-1"
  newLine(indent);

caller = "perlGetStruct:Unknown file:-1"
  printf("%s%s->{%s}", dollar(), stringify(first(codeof(node))), stringify(second(codeof(node))));

end
-- Chose function name perlSet
function perlSet(node,indent)
print("caller: ", caller, "-> perlSet")
caller = "perlSet:Unknown file:-1"
  newLine(indent);

caller = "perlSet:Unknown file:-1"
  printf("%s%s = ", dollar(), stringify(first(codeof(node))));

caller = "perlSet:Unknown file:-1"
  perlExpression(childrenof(node), indent);

end
-- Chose function name assertNode
function assertNode(node)
print("caller: ", caller, "-> assertNode")
caller = "assertNode:Unknown file:-1"
  if isNode(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      panic("Not a node!");

  end

end
-- Chose function name perlStatement
function perlStatement(node,indent)
print("caller: ", caller, "-> perlStatement")
local functionName =nil
caller = "perlStatement:Unknown file:-1"
  assertNode(node);

caller = "perlStatement:Unknown file:-1"
  if equalBox(boxString("setter"), subnameof(node)) then
caller = ":Unknown file:-1"
      perlSet(node, indent);

  else
caller = ":Unknown file:-1"
      if equalBox(boxString("structSetter"), subnameof(node)) then
caller = ":Unknown file:-1"
          perlSetStruct(node, indent);

      else
caller = ":Unknown file:-1"
          if equalBox(boxString("if"), subnameof(node)) then
caller = ":Unknown file:-1"
              perlIf(node, indent);

          else
caller = ":Unknown file:-1"
              if equalBox(boxString("returnvoid"), subnameof(node)) then
caller = ":Unknown file:-1"
                  functionName = functionNameof(node)
caller = ":Unknown file:-1"
                  printf("\n#Returnvoid\n");

caller = ":Unknown file:-1"
                  newLine(indent);

caller = ":Unknown file:-1"
                  newLine(indent);

caller = ":Unknown file:-1"
                  printf("return");

              else
caller = ":Unknown file:-1"
                  if equalBox(boxString("return"), subnameof(node)) then
caller = ":Unknown file:-1"
                      functionName = functionNameof(node)
caller = ":Unknown file:-1"
                      if inList(functionName, noStackTrace()) then
caller = ":Unknown file:-1"
                          printf("");

                      else
caller = ":Unknown file:-1"
                          printf("\n#standard return: %s\n", stringify(functionName));

caller = ":Unknown file:-1"
                          newLine(indent);

caller = ":Unknown file:-1"
                          printf("%s%s%s", "if (", dollar(), "globalTrace) {printf(\"Leaving \\n\")}\n");

                      end

caller = ":Unknown file:-1"
                      newLine(indent);

caller = ":Unknown file:-1"
                      perlExpression(childrenof(node), indent);

                  else
caller = ":Unknown file:-1"
                      if inList(functionName, noStackTrace()) then
caller = ":Unknown file:-1"
                          printf("");

                      else
caller = ":Unknown file:-1"
                          printf("\n#standard expression\n");

                      end

caller = ":Unknown file:-1"
                      newLine(indent);

caller = ":Unknown file:-1"
                      perlExpression(childrenof(node), indent);

caller = ":Unknown file:-1"
                      newLine(indent);

                  end

              end

          end

      end

  end

caller = "perlStatement:Unknown file:-1"
  printf(";\n");

end
-- Chose function name perlBody
function perlBody(tree,indent)
print("caller: ", caller, "-> perlBody")
caller = "perlBody:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      printIndent(indent);

caller = ":Unknown file:-1"
      printf("%s%s%s", "if (", dollar(), "globalStepTrace) {printf(\"StepTrace %s:%d\\n\", __FILE__, __LINE__)}\n");

caller = ":Unknown file:-1"
      perlStatement(car(tree), indent);

caller = ":Unknown file:-1"
      perlBody(cdr(tree), indent);

  end

end
-- Chose function name perlDeclarations
function perlDeclarations(decls,indent)
print("caller: ", caller, "-> perlDeclarations")
local decl =nil
caller = "perlDeclarations:Unknown file:-1"
  if isEmpty(decls) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      decl = car(decls)
caller = ":Unknown file:-1"
      printf("my %s%s = ", dollar(), stringify(second(decl)));

caller = ":Unknown file:-1"
      display(perlConstMap(third(decl)));

caller = ":Unknown file:-1"
      printf(";\n");

caller = ":Unknown file:-1"
      perlDeclarations(cdr(decls), indent);

  end

end
-- Chose function name perlFunction
function perlFunction(node)
print("caller: ", caller, "-> perlFunction")
local name =nil
caller = "perlFunction:Unknown file:-1"
  name = subnameof(node)
caller = "perlFunction:Unknown file:-1"
  printf("\n\n#Building function %s from line: %s", stringify(name), stringify(getTag(name, boxString("line"))));

caller = "perlFunction:Unknown file:-1"
  newLine(0);

caller = "perlFunction:Unknown file:-1"
  if isNil(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      newLine(0);

caller = ":Unknown file:-1"
      printf("sub %s", stringify(subnameof(node)));

caller = ":Unknown file:-1"
      printf(" {");

caller = ":Unknown file:-1"
      newLine(1);

caller = ":Unknown file:-1"
      perlFunctionArgs(cdr(assoc("intype", cdr(node))));

caller = ":Unknown file:-1"
      newLine(1);

caller = ":Unknown file:-1"
      perlDeclarations(declarationsof(node), 1);

caller = ":Unknown file:-1"
      printf("\nif (%sglobalTrace) { printf(\"%s at %s:%s\\n\") }\n", dollar(), stringify(subnameof(node)), stringify(getTag(name, boxString("filename"))), stringify(getTag(name, boxString("line"))));

caller = ":Unknown file:-1"
      if inList(name, noStackTrace()) then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf("");

      end

caller = ":Unknown file:-1"
      perlBody(childrenof(node), 1);

caller = ":Unknown file:-1"
      if inList(name, noStackTrace()) then
caller = ":Unknown file:-1"
          printf("");

      else
caller = ":Unknown file:-1"
          printf("");

      end

caller = ":Unknown file:-1"
      printf("\n}\n");

  end

end
-- Chose function name perlForwardDeclaration
function perlForwardDeclaration(node)
print("caller: ", caller, "-> perlForwardDeclaration")
caller = "perlForwardDeclaration:Unknown file:-1"
  if isNil(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      printf("\nsub %s", stringify(subnameof(node)));

caller = ":Unknown file:-1"
      printf(";");

  end

end
-- Chose function name perlForwardDeclarations
function perlForwardDeclarations(tree)
print("caller: ", caller, "-> perlForwardDeclarations")
caller = "perlForwardDeclarations:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      perlForwardDeclaration(car(tree));

caller = ":Unknown file:-1"
      perlForwardDeclarations(cdr(tree));

  end

end
-- Chose function name perlFunctions
function perlFunctions(tree)
print("caller: ", caller, "-> perlFunctions")
caller = "perlFunctions:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      perlFunction(car(tree));

caller = ":Unknown file:-1"
      perlFunctions(cdr(tree));

  end

end
-- Chose function name dollar
function dollar()
print("caller: ", caller, "-> dollar")
caller = "dollar:Unknown file:-1"
  return character(36)

end
-- Chose function name atSym
function atSym()
print("caller: ", caller, "-> atSym")
caller = "atSym:Unknown file:-1"
  return character(64)

end
-- Chose function name perlIncludes
function perlIncludes(nodes)
print("caller: ", caller, "-> perlIncludes")
caller = "perlIncludes:Unknown file:-1"
  printf("%s\n", "use strict;");

caller = "perlIncludes:Unknown file:-1"
  printf("%s%s%s", "my ", dollar(), "caller;\n");

caller = "perlIncludes:Unknown file:-1"
  printf("%s%s%s", "my ", dollar(), "releaseMode;\n");

caller = "perlIncludes:Unknown file:-1"
  printf("%s\n", "use Carp;");

caller = "perlIncludes:Unknown file:-1"
  dollar();

caller = "perlIncludes:Unknown file:-1"
  printf("%s\n", "use Carp::Always;");

caller = "perlIncludes:Unknown file:-1"
  printf("%s%s%s%s%s\n", "sub greaterthan { ", dollar(), "_[0] > ", dollar(), "_[1] };");

caller = "perlIncludes:Unknown file:-1"
  printf("%s%s%s\n", "sub qlog { warn ", "@", "_ };");

caller = "perlIncludes:Unknown file:-1"
  printf("%s%s%s%s%s\n", "sub mult { ", dollar(), "_[0] * ", dollar(), "_[1] };");

caller = "perlIncludes:Unknown file:-1"
  printf("%s%s%s%s%s\n", "sub multf { ", dollar(), "_[0] * ", dollar(), "_[1] };");

caller = "perlIncludes:Unknown file:-1"
  printf("%s%s%s%s%s\n", "sub greaterthanf { ", dollar(), "_[0] > ", dollar(), "_[1] };");

caller = "perlIncludes:Unknown file:-1"
  printf("%s%s%s%s%s\n", "sub equalString { ", dollar(), "_[0] eq ", dollar(), "_[1] };");

caller = "perlIncludes:Unknown file:-1"
  printf("sub read_file { my %sfile = shift; %sfile || die \"Empty file name!!!\"; open my %sfh, '<', %sfile or die; local %s/ = undef; my %scont = <%sfh>; close %sfh; return %scont; }; \n", dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar());

caller = "perlIncludes:Unknown file:-1"
  printf("sub write_file {my %sfile = shift; my %sdata = shift; %sfile || die \"Empty file name!!!\"; open my %sfh, '>', %sfile or die; print %sfh %sdata; close %sfh; } \n", dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar(), dollar());

caller = "perlIncludes:Unknown file:-1"
  printf("%s%s%s%s%s\n", "sub stringConcatenate { ", dollar(), "_[0] . ", dollar(), "_[1]}");

caller = "perlIncludes:Unknown file:-1"
  printf("%s%s%s%s%s\n", "sub subtract { ", dollar(), "_[0] - ", dollar(), "_[1]}");

caller = "perlIncludes:Unknown file:-1"
  printf("%s%s%s%s%s\n", "sub subf { ", dollar(), "_[0] - ", dollar(), "_[1]}");

caller = "perlIncludes:Unknown file:-1"
  printf("%s%s%s%s%s\n", "sub andBool { ", dollar(), "_[0] && ", dollar(), "_[1]}");

caller = "perlIncludes:Unknown file:-1"
  printf("%s%s%s%s%s\n", "sub equal { ", dollar(), "_[0] == ", dollar(), "_[1]}");

caller = "perlIncludes:Unknown file:-1"
  printf("%s%s%s%s%s\n", "sub panic { carp ", atSym(), "_; die \"", atSym(), "_\"}");

caller = "perlIncludes:Unknown file:-1"
  printf("sub intToString { return %s_[0]}\n", dollar());

caller = "perlIncludes:Unknown file:-1"
  printf("sub character { return chr(%s_[0])}\n", dollar());

caller = "perlIncludes:Unknown file:-1"
  printf("%s%s%s%s%s%s%s%s%s\n", "sub getStringArray { my ", dollar(), "index = shift; my ", dollar(), "arr = shift; return ", dollar(), "arr->[", dollar(), "index]}");

end
-- Chose function name perlTypeDecl
function perlTypeDecl(l)
print("caller: ", caller, "-> perlTypeDecl")
end
-- Chose function name perlStructComponents
function perlStructComponents(node)
print("caller: ", caller, "-> perlStructComponents")
caller = "perlStructComponents:Unknown file:-1"
  if isEmpty(node) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      perlTypeDecl(car(node));

caller = ":Unknown file:-1"
      perlStructComponents(cdr(node));

  end

end
-- Chose function name perlStruct
function perlStruct(node)
print("caller: ", caller, "-> perlStruct")
caller = "perlStruct:Unknown file:-1"
  perlStructComponents(cdr(car(node)));

end
-- Chose function name perlTypeMap
function perlTypeMap(aSym)
print("caller: ", caller, "-> perlTypeMap")
local symMap =nil
caller = "perlTypeMap:Unknown file:-1"
  symMap = alistCons(boxSymbol("stringArray"), boxSymbol("char**"), alistCons(boxSymbol("string"), boxSymbol("char*"), nil))
caller = "perlTypeMap:Unknown file:-1"
  if truthy(assoc(stringify(aSym), symMap)) then
caller = ":Unknown file:-1"
      return cdr(assoc(stringify(aSym), symMap))

  else
caller = ":Unknown file:-1"
      return aSym

  end

end
-- Chose function name perlConstMap
function perlConstMap(aSym)
print("caller: ", caller, "-> perlConstMap")
local symMap =nil
caller = "perlConstMap:Unknown file:-1"
  if equalString("symbol", boxType(aSym)) then
caller = ":Unknown file:-1"
      symMap = alistCons(boxSymbol("false"), boxSymbol("0"), alistCons(boxSymbol("nil"), boxSymbol("undef"), nil))
caller = ":Unknown file:-1"
      return cdr(assocFail(stringify(aSym), symMap, aSym))

  else
caller = ":Unknown file:-1"
      return aSym

  end

end
-- Chose function name perlFuncMap
function perlFuncMap(aSym)
print("caller: ", caller, "-> perlFuncMap")
local symMap =nil
caller = "perlFuncMap:Unknown file:-1"
  if equalString("symbol", boxType(aSym)) then
caller = ":Unknown file:-1"
      symMap = alistCons(boxSymbol("sub"), boxSymbol("subtract"), alistCons(boxSymbol("="), boxSymbol("equal"), alistCons(boxSymbol("luaSubstring"), boxSymbol("substr"), alistCons(boxSymbol("luaReadFile"), boxSymbol("read_file"), alistCons(boxSymbol("luaWriteFile"), boxSymbol("write_file"), alistCons(boxSymbol(">"), boxSymbol("greaterthan"), alistCons(boxSymbol("string.len"), boxSymbol("length"), alistCons(boxSymbol("nil"), boxSymbol("undef"), nil))))))))
caller = ":Unknown file:-1"
      return cdr(assocFail(stringify(aSym), symMap, aSym))

  else
caller = ":Unknown file:-1"
      return aSym

  end

end
-- Chose function name perlType
function perlType(node)
print("caller: ", caller, "-> perlType")
end
-- Chose function name perlTypes
function perlTypes(nodes)
print("caller: ", caller, "-> perlTypes")
caller = "perlTypes:Unknown file:-1"
  if isEmpty(nodes) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      perlType(car(nodes));

caller = ":Unknown file:-1"
      perlTypes(cdr(nodes));

  end

end
-- Chose function name perlFunctionArgs
function perlFunctionArgs(tree)
print("caller: ", caller, "-> perlFunctionArgs")
caller = "perlFunctionArgs:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      printf("%s%s", "my ", dollar());

caller = ":Unknown file:-1"
      display(second(tree));

caller = ":Unknown file:-1"
      printf(" = shift;\n");

caller = ":Unknown file:-1"
      perlFunctionArgs(cddr(tree));

  end

end
-- Chose function name perlCompile
function perlCompile(filename)
print("caller: ", caller, "-> perlCompile")
local programStr =""
local tree =nil
local program =nil
caller = "perlCompile:Unknown file:-1"
  programStr = luaReadFile(filename)
caller = "perlCompile:Unknown file:-1"
  tree = readSexpr(programStr, filename)
caller = "perlCompile:Unknown file:-1"
  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), nil)))
caller = "perlCompile:Unknown file:-1"
  program = mergeIncludes(program)
caller = "perlCompile:Unknown file:-1"
  perlIncludes(cdr(assoc("includes", program)));

caller = "perlCompile:Unknown file:-1"
  perlTypes(childrenof(cdr(assoc("types", program))));

caller = "perlCompile:Unknown file:-1"
  printf("use strict;\n");

caller = "perlCompile:Unknown file:-1"
  printf("use Carp;\n");

caller = "perlCompile:Unknown file:-1"
  printf("use Data::Dumper;\n");

caller = "perlCompile:Unknown file:-1"
  printf("%s%s%s", "my ", dollar(), "globalStackTrace = undef;\n");

caller = "perlCompile:Unknown file:-1"
  printf("%s%s%s", "my ", dollar(), "globalTrace = undef;\n");

caller = "perlCompile:Unknown file:-1"
  printf("%s%s%s", "my ", dollar(), "globalStepTrace = undef;\n");

caller = "perlCompile:Unknown file:-1"
  printf("%s%s%s", "my ", dollar(), "globalArgs = undef;\n");

caller = "perlCompile:Unknown file:-1"
  printf("%s%s%s", "my ", dollar(), "globalArgsCount = undef;\n");

caller = "perlCompile:Unknown file:-1"
  printf("%s%s%s\n", "my ", dollar(), "true = 1;\n");

caller = "perlCompile:Unknown file:-1"
  printf("%s%s%s", "my ", dollar(), "false = 0;\n");

caller = "perlCompile:Unknown file:-1"
  printf("%s%s%s", "my ", dollar(), "undef;\n");

caller = "perlCompile:Unknown file:-1"
  printf("%s%s%s", "\nsub isNil {\n    return !defined(", dollar(), "_[0]);\n}\n\n\n#Forward declarations\n");

caller = "perlCompile:Unknown file:-1"
  perlForwardDeclarations(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));

caller = "perlCompile:Unknown file:-1"
  printf("\n\n#End forward declarations\n\n");

caller = "perlCompile:Unknown file:-1"
  perlFunctions(cdr(assoc("children", cdr(cdr(assoc("functions", program))))));

caller = "perlCompile:Unknown file:-1"
  printf(";\n");

caller = "perlCompile:Unknown file:-1"
  printf("%s%s%s%s", dollar(), "globalArgs = [ 1, ", atSym(), "ARGV];");

caller = "perlCompile:Unknown file:-1"
  printf("%s%s%s%s", dollar(), "globalArgsCount = scalar(", atSym(), "ARGV)+1;\n");

caller = "perlCompile:Unknown file:-1"
  printf("start();");

end
-- Chose function name readSexpr
function readSexpr(aStr,filename)
print("caller: ", caller, "-> readSexpr")
local tokens =nil
local as =nil
caller = "readSexpr:Unknown file:-1"
  tokens = emptyList()
caller = "readSexpr:Unknown file:-1"
  tokens = filterTokens(filterVoid(scan(aStr, 0, 1, 0, 0, filename)))
caller = "readSexpr:Unknown file:-1"
  as = sexprTree(tokens)
caller = "readSexpr:Unknown file:-1"
  return car(as)

end
-- Chose function name sexprTree
function sexprTree(l)
print("caller: ", caller, "-> sexprTree")
local b =nil
caller = "sexprTree:Unknown file:-1"
  if isEmpty(l) then
caller = ":Unknown file:-1"
      return emptyList()

  else
caller = ":Unknown file:-1"
      b = car(l)
caller = ":Unknown file:-1"
      if isOpenBrace(b) then
caller = ":Unknown file:-1"
          return cons(sexprTree(cdr(l)), sexprTree(skipList(cdr(l))))

      else
caller = ":Unknown file:-1"
          if isCloseBrace(b) then
caller = ":Unknown file:-1"
              return emptyList()

          else
caller = ":Unknown file:-1"
              return setTag(boxString("line"), getTagFail(b, boxString("line"), boxInt(-1)), cons(b, sexprTree(cdr(l))))

          end

      end

  end

end
-- Chose function name loadQuon
function loadQuon(filename)
print("caller: ", caller, "-> loadQuon")
local programStr =""
local tree =nil
caller = "loadQuon:Unknown file:-1"
  programStr = luaReadFile(filename)
caller = "loadQuon:Unknown file:-1"
  tree = readSexpr(programStr, filename)
caller = "loadQuon:Unknown file:-1"
  return tree

end
-- Chose function name getIncludes
function getIncludes(program)
print("caller: ", caller, "-> getIncludes")
caller = "getIncludes:Unknown file:-1"
  return cdr(first(program))

end
-- Chose function name getTypes
function getTypes(program)
print("caller: ", caller, "-> getTypes")
caller = "getTypes:Unknown file:-1"
  return cdr(second(program))

end
-- Chose function name getFunctions
function getFunctions(program)
print("caller: ", caller, "-> getFunctions")
caller = "getFunctions:Unknown file:-1"
  return cdr(third(program))

end
-- Chose function name loadIncludes
function loadIncludes(tree)
print("caller: ", caller, "-> loadIncludes")
local newProg =nil
local includeFile =""
local functionsCombined =nil
local typesCombined =nil
local includeTree =nil
caller = "loadIncludes:Unknown file:-1"
  if greaterthan(listLength(getIncludes(tree)), 0) then
caller = ":Unknown file:-1"
      includeFile = stringify(first(getIncludes(tree)))
caller = ":Unknown file:-1"
      includeTree = loadQuon(includeFile)
caller = ":Unknown file:-1"
      functionsCombined = concatLists(getFunctions(includeTree), getFunctions(tree))
caller = ":Unknown file:-1"
      typesCombined = concatLists(getTypes(includeTree), getTypes(tree))
caller = ":Unknown file:-1"
      newProg = buildProg(cdr(getIncludes(tree)), typesCombined, functionsCombined)
caller = ":Unknown file:-1"
      return loadIncludes(newProg)

  else
caller = ":Unknown file:-1"
      return tree

  end

end
-- Chose function name buildProg
function buildProg(includes,types,functions)
print("caller: ", caller, "-> buildProg")
local program =nil
caller = "buildProg:Unknown file:-1"
  includes = cons(boxSymbol("includes"), includes)
caller = "buildProg:Unknown file:-1"
  types = cons(boxSymbol("types"), types)
caller = "buildProg:Unknown file:-1"
  functions = cons(boxSymbol("functions"), functions)
caller = "buildProg:Unknown file:-1"
  program = cons(includes, cons(types, cons(functions, nil)))
caller = "buildProg:Unknown file:-1"
  return program

end
-- Chose function name car
function car(l)
print("caller: ", caller, "-> car")
caller = "car:Unknown file:-1"
  if isNil(l) then
caller = ":Unknown file:-1"
      printf("Cannot call car on empty list!\n");

caller = ":Unknown file:-1"
      panic("Cannot call car on empty list!\n");

caller = ":Unknown file:-1"
      return nil

  else
caller = ":Unknown file:-1"
      assertType("list", l, 18, "q/lists.qon");

caller = ":Unknown file:-1"
      if isNil(l.car) then
caller = ":Unknown file:-1"
          return nil

      else
caller = ":Unknown file:-1"
          return l.car

      end

  end

end
-- Chose function name cdr
function cdr(l)
print("caller: ", caller, "-> cdr")
caller = "cdr:Unknown file:-1"
  assertType("list", l, 25, "q/lists.qon");

caller = "cdr:Unknown file:-1"
  if isEmpty(l) then
caller = ":Unknown file:-1"
      printf("Attempt to cdr an empty list!!!!\n");

caller = ":Unknown file:-1"
      panic("Attempt to cdr an empty list!!!!\n");

caller = ":Unknown file:-1"
      return nil

  else
caller = ":Unknown file:-1"
      return l.cdr

  end

end
-- Chose function name cons
function cons(data,l)
print("caller: ", caller, "-> cons")
local p =nil
caller = "cons:Unknown file:-1"
  p = makePair()
caller = "cons:Unknown file:-1"
p.cdr = l
caller = "cons:Unknown file:-1"
p.car = data
caller = "cons:Unknown file:-1"
p.typ = "list"
caller = "cons:Unknown file:-1"
  return p

end
-- Chose function name caar
function caar(l)
print("caller: ", caller, "-> caar")
caller = "caar:Unknown file:-1"
  return car(car(l))

end
-- Chose function name cadr
function cadr(l)
print("caller: ", caller, "-> cadr")
caller = "cadr:Unknown file:-1"
  return car(cdr(l))

end
-- Chose function name caddr
function caddr(l)
print("caller: ", caller, "-> caddr")
caller = "caddr:Unknown file:-1"
  return car(cdr(cdr(l)))

end
-- Chose function name cadddr
function cadddr(l)
print("caller: ", caller, "-> cadddr")
caller = "cadddr:Unknown file:-1"
  return car(cdr(cdr(cdr(l))))

end
-- Chose function name caddddr
function caddddr(l)
print("caller: ", caller, "-> caddddr")
caller = "caddddr:Unknown file:-1"
  return car(cdr(cdr(cdr(cdr(l)))))

end
-- Chose function name cddr
function cddr(l)
print("caller: ", caller, "-> cddr")
caller = "cddr:Unknown file:-1"
  return cdr(cdr(l))

end
-- Chose function name first
function first(l)
print("caller: ", caller, "-> first")
caller = "first:Unknown file:-1"
  return car(l)

end
-- Chose function name second
function second(l)
print("caller: ", caller, "-> second")
caller = "second:Unknown file:-1"
  return cadr(l)

end
-- Chose function name third
function third(l)
print("caller: ", caller, "-> third")
caller = "third:Unknown file:-1"
  return caddr(l)

end
-- Chose function name fourth
function fourth(l)
print("caller: ", caller, "-> fourth")
caller = "fourth:Unknown file:-1"
  return cadddr(l)

end
-- Chose function name fifth
function fifth(l)
print("caller: ", caller, "-> fifth")
caller = "fifth:Unknown file:-1"
  return caddddr(l)

end
-- Chose function name isList
function isList(b)
print("caller: ", caller, "-> isList")
caller = "isList:Unknown file:-1"
  if isNil(b) then
caller = ":Unknown file:-1"
      return true

  else
caller = ":Unknown file:-1"
      return equalString("list", b.typ)

  end

end
-- Chose function name emptyList
function emptyList()
print("caller: ", caller, "-> emptyList")
caller = "emptyList:Unknown file:-1"
  return nil

end
-- Chose function name isEmpty
function isEmpty(b)
print("caller: ", caller, "-> isEmpty")
caller = "isEmpty:Unknown file:-1"
  if isNil(b) then
caller = ":Unknown file:-1"
      return true

  else
caller = ":Unknown file:-1"
      return false

  end

end
-- Chose function name listLength
function listLength(l)
print("caller: ", caller, "-> listLength")
caller = "listLength:Unknown file:-1"
  if isEmpty(l) then
caller = ":Unknown file:-1"
      return 0

  else
caller = ":Unknown file:-1"
      return add1(listLength(cdr(l)))

  end

end
-- Chose function name alistCons
function alistCons(key,value,alist)
print("caller: ", caller, "-> alistCons")
caller = "alistCons:Unknown file:-1"
  return cons(cons(key, value), alist)

end
-- Chose function name assoc
function assoc(searchTerm,l)
print("caller: ", caller, "-> assoc")
local elem =nil
caller = "assoc:Unknown file:-1"
  assertType("list", l, 88, "q/lists.qon");

caller = "assoc:Unknown file:-1"
  if isEmpty(l) then
caller = ":Unknown file:-1"
      return boxBool(false)

  else
caller = ":Unknown file:-1"
      elem = car(l)
caller = ":Unknown file:-1"
      assertType("list", elem, 94, "q/lists.qon");

caller = ":Unknown file:-1"
      if isEmpty(elem) then
caller = ":Unknown file:-1"
          return assoc(searchTerm, cdr(l))

      else
caller = ":Unknown file:-1"
          if false then
caller = ":Unknown file:-1"
              printf("Comparing %s and %s\n", searchTerm, stringify(car(elem)));

          else
caller = ":Unknown file:-1"
              printf("");

          end

caller = ":Unknown file:-1"
          if equalString(searchTerm, stringify(car(elem))) then
caller = ":Unknown file:-1"
              return elem

          else
caller = ":Unknown file:-1"
              return assoc(searchTerm, cdr(l))

          end

      end

  end

end
-- Chose function name chooseBox
function chooseBox(aType)
print("caller: ", caller, "-> chooseBox")
caller = "chooseBox:Unknown file:-1"
  if equalString("string", aType) then
caller = ":Unknown file:-1"
      return "boxString"

  else
caller = ":Unknown file:-1"
      if equalString("symbol", aType) then
caller = ":Unknown file:-1"
          return "boxSymbol"

      else
caller = ":Unknown file:-1"
          if equalString("bool", aType) then
caller = ":Unknown file:-1"
              return "boxBool"

          else
caller = ":Unknown file:-1"
              if equalString("int", aType) then
caller = ":Unknown file:-1"
                  return "boxInt"

              else
caller = ":Unknown file:-1"
                  if equalString("float", aType) then
caller = ":Unknown file:-1"
                      return "boxFloat"

                  else
caller = ":Unknown file:-1"
                      panic("Invalid type");

                  end

              end

          end

      end

  end

caller = "chooseBox:Unknown file:-1"
  return ""

end
-- Chose function name mlistLiteral
function mlistLiteral(b)
print("caller: ", caller, "-> mlistLiteral")
caller = "mlistLiteral:Unknown file:-1"
  if isNil(b) then
caller = ":Unknown file:-1"
      return nil

  else
caller = ":Unknown file:-1"
      if equalString("string", boxType(b)) then
caller = ":Unknown file:-1"
          return b

      else
caller = ":Unknown file:-1"
          if equalString("bool", boxType(b)) then
caller = ":Unknown file:-1"
              return b

          else
caller = ":Unknown file:-1"
              if equalString("int", boxType(b)) then
caller = ":Unknown file:-1"
                  return b

              else
caller = ":Unknown file:-1"
                  if equalString("symbol", boxType(b)) then
caller = ":Unknown file:-1"
                      return boxString(unBoxSymbol(b))

                  else
caller = ":Unknown file:-1"
                      return boxString(stringConcatenate("Unsupported type: ", boxType(b)))

                  end

              end

          end

      end

  end

end
-- Chose function name doMultiList
function doMultiList(l)
print("caller: ", caller, "-> doMultiList")
local newlist =nil
local ret =nil
local elem =nil
caller = "doMultiList:Unknown file:-1"
  if isNil(l) then
caller = ":Unknown file:-1"
      return cons(boxSymbol("nil"), nil)

  else
caller = ":Unknown file:-1"
      if isEmpty(l) then
caller = ":Unknown file:-1"
          return nil

      else
caller = ":Unknown file:-1"
          elem = first(l)
caller = ":Unknown file:-1"
          newlist = cons(boxString(chooseBox(elem.typ)), cons(mlistLiteral(first(l)), newlist))
caller = ":Unknown file:-1"
          ret = cons(cons(boxSymbol("cons"), cons(newlist, doMultiList(cdr(l)))), nil)
caller = ":Unknown file:-1"
          return ret

      end

  end

end
-- Chose function name doMakeList
function doMakeList(l)
print("caller: ", caller, "-> doMakeList")
local newlist =nil
local ret =nil
local elem =nil
caller = "doMakeList:Unknown file:-1"
  if isNil(l) then
caller = ":Unknown file:-1"
      return cons(boxSymbol("nil"), nil)

  else
caller = ":Unknown file:-1"
      if isEmpty(l) then
caller = ":Unknown file:-1"
          return nil

      else
caller = ":Unknown file:-1"
          elem = first(l)
caller = ":Unknown file:-1"
          newlist = cons(first(l), newlist)
caller = ":Unknown file:-1"
          ret = cons(cons(boxSymbol("cons"), cons(newlist, doMakeList(cdr(l)))), nil)
caller = ":Unknown file:-1"
          return ret

      end

  end

end
-- Chose function name doStringList
function doStringList(l)
print("caller: ", caller, "-> doStringList")
local newlist =nil
local ret =nil
caller = "doStringList:Unknown file:-1"
  if isNil(l) then
caller = ":Unknown file:-1"
      return cons(boxSymbol("nil"), nil)

  else
caller = ":Unknown file:-1"
      newlist = cons(boxSymbol("boxString"), cons(first(l), newlist))
caller = ":Unknown file:-1"
      ret = cons(cons(boxSymbol("cons"), cons(newlist, doStringList(cdr(l)))), nil)
caller = ":Unknown file:-1"
      return ret

  end

end
-- Chose function name doSymbolList
function doSymbolList(l)
print("caller: ", caller, "-> doSymbolList")
local newlist =nil
local ret =nil
caller = "doSymbolList:Unknown file:-1"
  if isNil(l) then
caller = ":Unknown file:-1"
      return cons(boxSymbol("nil"), nil)

  else
caller = ":Unknown file:-1"
      newlist = cons(boxSymbol("boxSymbol"), cons(first(l), newlist))
caller = ":Unknown file:-1"
      ret = cons(cons(boxSymbol("cons"), cons(newlist, doSymbolList(cdr(l)))), nil)
caller = ":Unknown file:-1"
      return ret

  end

end
-- Chose function name doBoxList
function doBoxList(l)
print("caller: ", caller, "-> doBoxList")
caller = "doBoxList:Unknown file:-1"
  if isNil(l) then
caller = ":Unknown file:-1"
      return cons(boxSymbol("nil"), nil)

  else
caller = ":Unknown file:-1"
      return cons(cons(boxSymbol("cons"), cons(first(l), doBoxList(cdr(l)))), nil)

  end

end
-- Chose function name concatLists
function concatLists(seq1,seq2)
print("caller: ", caller, "-> concatLists")
caller = "concatLists:Unknown file:-1"
  if isNil(seq1) then
caller = ":Unknown file:-1"
      return seq2

  else
caller = ":Unknown file:-1"
      return cons(car(seq1), concatLists(cdr(seq1), seq2))

  end

end
-- Chose function name alistKeys
function alistKeys(alist)
print("caller: ", caller, "-> alistKeys")
caller = "alistKeys:Unknown file:-1"
  if isNil(alist) then
caller = ":Unknown file:-1"
      return nil

  else
caller = ":Unknown file:-1"
      return cons(car(car(alist)), alistKeys(cdr(alist)))

  end

end
-- Chose function name display
function display(l)
print("caller: ", caller, "-> display")
caller = "display:Unknown file:-1"
  if isEmpty(l) then
caller = ":Unknown file:-1"
      printf("nil ");

caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      if isList(l) then
caller = ":Unknown file:-1"
          printf("[");

caller = ":Unknown file:-1"
          displayList(l, 0, true);

caller = ":Unknown file:-1"
          printf("]");

      else
caller = ":Unknown file:-1"
          displayList(l, 0, true);

      end

  end

end
-- Chose function name displayList
function displayList(l,indent,first)
print("caller: ", caller, "-> displayList")
local val =nil
caller = "displayList:Unknown file:-1"
  if isEmpty(l) then
caller = ":Unknown file:-1"
      return 

  else
caller = ":Unknown file:-1"
      if isList(l) then
caller = ":Unknown file:-1"
          if isEmpty(l) then
caller = ":Unknown file:-1"
              return 

          else
caller = ":Unknown file:-1"
              if first then
              else
caller = ":Unknown file:-1"
                  printf(" ");

              end

caller = ":Unknown file:-1"
              val = car(l)
caller = ":Unknown file:-1"
              if isList(val) then
caller = ":Unknown file:-1"
                  newLine(indent);

caller = ":Unknown file:-1"
                  printf("%s", openBrace());

caller = ":Unknown file:-1"
                  displayList(car(l), add1(indent), true);

caller = ":Unknown file:-1"
                  printf("%s", closeBrace());

caller = ":Unknown file:-1"
                  displayList(cdr(l), indent, false);

              else
caller = ":Unknown file:-1"
                  if equalString("string", val.typ) then
caller = ":Unknown file:-1"
                      printf("\"%s\"", unBoxString(val));

                  else
caller = ":Unknown file:-1"
                      printf("%s", stringify(val));

                  end

caller = ":Unknown file:-1"
                  displayList(cdr(l), indent, false);

              end

          end

      else
caller = ":Unknown file:-1"
          if equalString("string", l.typ) then
caller = ":Unknown file:-1"
              printf("\"%s\"", unBoxString(l));

          else
caller = ":Unknown file:-1"
              printf("%s", stringify(l));

          end

      end

  end

end
-- Chose function name StringListJoinRec
function StringListJoinRec(l,sep)
print("caller: ", caller, "-> StringListJoinRec")
local val =nil
caller = "StringListJoinRec:Unknown file:-1"
  if isEmpty(l) then
caller = ":Unknown file:-1"
      return ""

  else
caller = ":Unknown file:-1"
      if isList(l) then
caller = ":Unknown file:-1"
          if isEmpty(l) then
caller = ":Unknown file:-1"
              return ""

          else
caller = ":Unknown file:-1"
              if equal(listLength(l), 1) then
caller = ":Unknown file:-1"
                  return stringify(car(l))

              else
caller = ":Unknown file:-1"
                  return stringConcatenate(stringify(car(l)), stringConcatenate(sep, StringListJoinRec(cdr(l), sep)))

              end

          end

      else
caller = ":Unknown file:-1"
          return ""

      end

  end

end
-- Chose function name StringListJoin
function StringListJoin(l,sep)
print("caller: ", caller, "-> StringListJoin")
local val =nil
caller = "StringListJoin:Unknown file:-1"
  if greaterthan(listLength(l), 1) then
caller = ":Unknown file:-1"
      return stringConcatenate(stringify(car(l)), stringConcatenate(sep, StringListJoinRec(cdr(l), sep)))

  else
caller = ":Unknown file:-1"
      return stringify(car(l))

  end

end
-- Chose function name ListToBoxString
function ListToBoxString(l)
print("caller: ", caller, "-> ListToBoxString")
caller = "ListToBoxString:Unknown file:-1"
  return boxString(ListToString(l, 0, true, false))

end
-- Chose function name ListToString
function ListToString(l,indent,first,withNewLines)
print("caller: ", caller, "-> ListToString")
local val =nil
caller = "ListToString:Unknown file:-1"
  if isEmpty(l) then
caller = ":Unknown file:-1"
      return ""

  else
caller = ":Unknown file:-1"
      if isList(l) then
caller = ":Unknown file:-1"
          if isEmpty(l) then
caller = ":Unknown file:-1"
              return ""

          else
caller = ":Unknown file:-1"
              val = car(l)
caller = ":Unknown file:-1"
              if isList(val) then
caller = ":Unknown file:-1"
                  return StringListJoin(cons(boxString(stringify(tern(withNewLines, boxString("\n"), boxString(stringIndent(indent))))), cons(boxString(openBrace()), cons(boxString(" "), cons(boxString(ListToString(car(l), add1(indent), true, withNewLines)), cons(boxString(closeBrace()), cons(boxString(" "), cons(boxString(ListToString(cdr(l), indent, false, withNewLines)), nil))))))), "")

              else
caller = ":Unknown file:-1"
                  return stringConcatenate(stringify(val), ListToString(cdr(l), indent, false, withNewLines))

              end

          end

      else
caller = ":Unknown file:-1"
          return stringify(l)

      end

  end

end
-- Chose function name listReverse
function listReverse(l)
print("caller: ", caller, "-> listReverse")
caller = "listReverse:Unknown file:-1"
  if isNil(l) then
caller = ":Unknown file:-1"
      return nil

  else
caller = ":Unknown file:-1"
      return cons(car(l), listReverse(cdr(l)))

  end

end
-- Chose function name inList
function inList(item,l)
print("caller: ", caller, "-> inList")
caller = "inList:Unknown file:-1"
  if isNil(l) then
caller = ":Unknown file:-1"
      return false

  else
caller = ":Unknown file:-1"
      if equalBox(car(l), item) then
caller = ":Unknown file:-1"
          return true

      else
caller = ":Unknown file:-1"
          return inList(item, cdr(l))

      end

  end

end
-- Chose function name equalList
function equalList(a,b)
print("caller: ", caller, "-> equalList")
caller = "equalList:Unknown file:-1"
  if isNil(a) then
caller = ":Unknown file:-1"
      if isNil(b) then
caller = ":Unknown file:-1"
          return true

      else
caller = ":Unknown file:-1"
          return false

      end

  else
  end

caller = "equalList:Unknown file:-1"
  if isNil(b) then
caller = ":Unknown file:-1"
      if isNil(a) then
caller = ":Unknown file:-1"
          return true

      else
caller = ":Unknown file:-1"
          return false

      end

  else
  end

caller = "equalList:Unknown file:-1"
  if equalBox(car(a), car(b)) then
caller = ":Unknown file:-1"
      return equalList(cdr(a), cdr(b))

  else
caller = ":Unknown file:-1"
      return false

  end

end
-- Chose function name reverseRec
function reverseRec(oldL,newL)
print("caller: ", caller, "-> reverseRec")
caller = "reverseRec:Unknown file:-1"
  if isEmpty(oldL) then
caller = ":Unknown file:-1"
      return newL

  else
caller = ":Unknown file:-1"
      return reverseRec(cdr(oldL), cons(first(oldL), newL))

  end

end
-- Chose function name reverseList
function reverseList(l)
print("caller: ", caller, "-> reverseList")
caller = "reverseList:Unknown file:-1"
  return reverseRec(l, nil)

end
-- Chose function name flatten
function flatten(tree)
print("caller: ", caller, "-> flatten")
caller = "flatten:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return emptyList()

  else
caller = ":Unknown file:-1"
      if isList(car(tree)) then
caller = ":Unknown file:-1"
          return concatenateLists(flatten(car(tree)), flatten(cdr(tree)))

      else
caller = ":Unknown file:-1"
          return cons(car(tree), flatten(cdr(tree)))

      end

  end

end
-- Chose function name macrowalk
function macrowalk(l)
print("caller: ", caller, "-> macrowalk")
caller = "macrowalk:Unknown file:-1"
  if isEmpty(l) then
caller = ":Unknown file:-1"
      return nil

  else
caller = ":Unknown file:-1"
      if isList(l) then
caller = ":Unknown file:-1"
          if equalString(stringConcatenate("box", "List"), stringify(car(l))) then
caller = ":Unknown file:-1"
              return car(doBoxList(cdr(l)))

          else
          end

caller = ":Unknown file:-1"
          if equalString(stringConcatenate("string", "List"), stringify(car(l))) then
caller = ":Unknown file:-1"
              return car(doStringList(cdr(l)))

          else
          end

caller = ":Unknown file:-1"
          if equalString(stringConcatenate("symbol", "List"), stringify(car(l))) then
caller = ":Unknown file:-1"
              return car(doSymbolList(cdr(l)))

          else
          end

caller = ":Unknown file:-1"
          if equalString(stringConcatenate("multi", "List"), stringify(car(l))) then
caller = ":Unknown file:-1"
              return car(doMultiList(cdr(l)))

          else
          end

caller = ":Unknown file:-1"
          if equalString(stringConcatenate("makeL", "ist"), stringify(car(l))) then
caller = ":Unknown file:-1"
              return doMakeList(cdr(l))

          else
          end

caller = ":Unknown file:-1"
          return cons(macrowalk(car(l)), macrowalk(cdr(l)))

      else
caller = ":Unknown file:-1"
          return l

      end

  end

end
-- Chose function name macrosingle
function macrosingle(l,search,replace)
print("caller: ", caller, "-> macrosingle")
local val =nil
caller = "macrosingle:Unknown file:-1"
  if isEmpty(l) then
caller = ":Unknown file:-1"
      return nil

  else
caller = ":Unknown file:-1"
      if isList(l) then
caller = ":Unknown file:-1"
          return cons(macrosingle(car(l), search, replace), macrosingle(cdr(l), search, replace))

      else
caller = ":Unknown file:-1"
          if equalString(search, stringify(l)) then
caller = ":Unknown file:-1"
              val = clone(l)
caller = ":Unknown file:-1"
val.str = replace
caller = ":Unknown file:-1"
              return val

          else
          end

caller = ":Unknown file:-1"
          return l

      end

  end

end
-- Chose function name macrolist
function macrolist(l,search,replace)
print("caller: ", caller, "-> macrolist")
local val =nil
caller = "macrolist:Unknown file:-1"
  if isEmpty(l) then
caller = ":Unknown file:-1"
      return nil

  else
caller = ":Unknown file:-1"
      if isList(l) then
caller = ":Unknown file:-1"
          if equalString(search, stringify(car(l))) then
caller = ":Unknown file:-1"
              return concatLists(replace, macrolist(cdr(l), search, replace))

          else
caller = ":Unknown file:-1"
              return cons(macrolist(car(l), search, replace), macrolist(cdr(l), search, replace))

          end

      else
caller = ":Unknown file:-1"
          return l

      end

  end

end
-- Chose function name filterVoid
function filterVoid(l)
print("caller: ", caller, "-> filterVoid")
local token =nil
caller = "filterVoid:Unknown file:-1"
  if isEmpty(l) then
caller = ":Unknown file:-1"
      return emptyList()

  else
caller = ":Unknown file:-1"
      token = car(l)
caller = ":Unknown file:-1"
      if equalString("void", token.typ) then
caller = ":Unknown file:-1"
          return filterVoid(cdr(l))

      else
caller = ":Unknown file:-1"
          return cons(token, filterVoid(cdr(l)))

      end

  end

end
-- Chose function name filterTokens
function filterTokens(l)
print("caller: ", caller, "-> filterTokens")
local token =nil
caller = "filterTokens:Unknown file:-1"
  if isEmpty(l) then
caller = ":Unknown file:-1"
      return emptyList()

  else
caller = ":Unknown file:-1"
      token = car(l)
caller = ":Unknown file:-1"
      if equalString(boxType(token), "symbol") then
caller = ":Unknown file:-1"
          if equalString("__LINE__", stringify(token)) then
caller = ":Unknown file:-1"
              return cons(getTagFail(token, boxString("line"), boxInt(-1)), filterTokens(cdr(l)))

          else
caller = ":Unknown file:-1"
              if equalString("__COLUMN__", stringify(token)) then
caller = ":Unknown file:-1"
                  return cons(getTagFail(token, boxString("column"), boxInt(-1)), filterTokens(cdr(l)))

              else
caller = ":Unknown file:-1"
                  if equalString("__FILE__", stringify(token)) then
caller = ":Unknown file:-1"
                      return cons(getTagFail(token, boxString("filename"), boxString("Unknown file")), filterTokens(cdr(l)))

                  else
caller = ":Unknown file:-1"
                      return cons(token, filterTokens(cdr(l)))

                  end

              end

          end

      else
caller = ":Unknown file:-1"
          return cons(token, filterTokens(cdr(l)))

      end

  end

end
-- Chose function name finish_token
function finish_token(prog,start,len,line,column,filename)
print("caller: ", caller, "-> finish_token")
local token =nil
caller = "finish_token:Unknown file:-1"
  if greaterthan(len, 0) then
caller = ":Unknown file:-1"
      token = boxSymbol(luaSubstring(prog, start, len))
caller = ":Unknown file:-1"
token.tag = alistCons(boxString("filename"), boxString(filename), alistCons(boxString("column"), boxInt(column), alistCons(boxString("line"), boxInt(line), alistCons(boxString("totalCharPos"), boxInt(start), nil))))
caller = ":Unknown file:-1"
      return token

  else
caller = ":Unknown file:-1"
      return newVoid()

  end

end
-- Chose function name readString
function readString(prog,start,len)
print("caller: ", caller, "-> readString")
local token =""
caller = "readString:Unknown file:-1"
  token = luaSubstring(prog, sub1(add(start, len)), 1)
caller = "readString:Unknown file:-1"
  if equalString("\"", token) then
caller = ":Unknown file:-1"
      return luaSubstring(prog, start, sub1(len))

  else
caller = ":Unknown file:-1"
      if equalString("\\", token) then
caller = ":Unknown file:-1"
          return readString(prog, start, add(2, len))

      else
caller = ":Unknown file:-1"
          return readString(prog, start, add1(len))

      end

  end

end
-- Chose function name readComment
function readComment(prog,start,len)
print("caller: ", caller, "-> readComment")
local token =""
caller = "readComment:Unknown file:-1"
  if greaterthan(add(start, len), string.len(prog)) then
caller = ":Unknown file:-1"
      return ""

  else
caller = ":Unknown file:-1"
      token = luaSubstring(prog, sub1(add(start, len)), 1)
caller = ":Unknown file:-1"
      if isLineBreak(token) then
caller = ":Unknown file:-1"
          return luaSubstring(prog, start, sub1(len))

      else
caller = ":Unknown file:-1"
          return readComment(prog, start, add1(len))

      end

  end

end
-- Chose function name isWhiteSpace
function isWhiteSpace(s)
print("caller: ", caller, "-> isWhiteSpace")
caller = "isWhiteSpace:Unknown file:-1"
  if equalString(" ", s) then
caller = ":Unknown file:-1"
      return true

  else
caller = ":Unknown file:-1"
      if equalString("\t", s) then
caller = ":Unknown file:-1"
          return true

      else
caller = ":Unknown file:-1"
          if equalString("\n", s) then
caller = ":Unknown file:-1"
              return true

          else
caller = ":Unknown file:-1"
              if equalString("\r", s) then
caller = ":Unknown file:-1"
                  return true

              else
caller = ":Unknown file:-1"
                  return false

              end

          end

      end

  end

end
-- Chose function name isLineBreak
function isLineBreak(s)
print("caller: ", caller, "-> isLineBreak")
caller = "isLineBreak:Unknown file:-1"
  if equalString("\n", s) then
caller = ":Unknown file:-1"
      return true

  else
caller = ":Unknown file:-1"
      if equalString("\r", s) then
caller = ":Unknown file:-1"
          return true

      else
caller = ":Unknown file:-1"
          return false

      end

  end

end
-- Chose function name incForNewLine
function incForNewLine(token,val)
print("caller: ", caller, "-> incForNewLine")
caller = "incForNewLine:Unknown file:-1"
  if equalString("\n", stringify(token)) then
caller = ":Unknown file:-1"
      return add1(val)

  else
caller = ":Unknown file:-1"
      return val

  end

end
-- Chose function name annotateReadPosition
function annotateReadPosition(filename,linecount,column,start,newBox)
print("caller: ", caller, "-> annotateReadPosition")
caller = "annotateReadPosition:Unknown file:-1"
  return setTag(boxString("filename"), boxString(filename), setTag(boxString("column"), boxInt(column), setTag(boxString("line"), boxInt(linecount), setTag(boxString("totalCharPos"), boxInt(start), newBox))))

end
-- Chose function name scan
function scan(prog,start,len,linecount,column,filename)
print("caller: ", caller, "-> scan")
local token =nil
local newString =""
local newBox =nil
caller = "scan:Unknown file:-1"
  if greaterthan(string.len(prog), sub(start, sub(0, len))) then
caller = ":Unknown file:-1"
      token = boxSymbol(luaSubstring(prog, sub1(add(start, len)), 1))
caller = ":Unknown file:-1"
token.tag = alistCons(boxString("totalCharPos"), boxInt(start), nil)
caller = ":Unknown file:-1"
      if isOpenBrace(token) then
caller = ":Unknown file:-1"
          return cons(finish_token(prog, start, sub1(len), linecount, column, filename), cons(boxSymbol(openBrace()), scan(prog, add1(start), 1, linecount, add1(column), filename)))

      else
caller = ":Unknown file:-1"
          if isCloseBrace(token) then
caller = ":Unknown file:-1"
              return cons(finish_token(prog, start, sub1(len), linecount, column, filename), cons(annotateReadPosition(filename, linecount, column, start, boxSymbol(closeBrace())), scan(prog, add(start, len), 1, linecount, add1(column), filename)))

          else
caller = ":Unknown file:-1"
              if isWhiteSpace(stringify(token)) then
caller = ":Unknown file:-1"
                  return cons(finish_token(prog, start, sub1(len), linecount, column, filename), scan(prog, add(start, len), 1, incForNewLine(token, linecount), 0, filename))

              else
caller = ":Unknown file:-1"
                  if equalBox(boxSymbol(";"), token) then
caller = ":Unknown file:-1"
                      return scan(prog, add(start, add1(add1(string.len(readComment(prog, add1(start), len))))), 1, add1(linecount), 0, filename)

                  else
caller = ":Unknown file:-1"
                      if equalBox(boxSymbol("\""), token) then
caller = ":Unknown file:-1"
                          newString = readString(prog, add1(start), len)
caller = ":Unknown file:-1"
                          newBox = annotateReadPosition(filename, linecount, column, start, boxString(newString))
caller = ":Unknown file:-1"
                          return cons(newBox, scan(prog, add(start, add1(add1(string.len(newString)))), 1, linecount, add1(column), filename))

                      else
caller = ":Unknown file:-1"
                          return scan(prog, start, sub(len, -1), linecount, add1(column), filename)

                      end

                  end

              end

          end

      end

  else
caller = ":Unknown file:-1"
      return emptyList()

  end

end
-- Chose function name isOpenBrace
function isOpenBrace(b)
print("caller: ", caller, "-> isOpenBrace")
caller = "isOpenBrace:Unknown file:-1"
  if equalBox(boxSymbol(openBrace()), b) then
caller = ":Unknown file:-1"
      return true

  else
caller = ":Unknown file:-1"
      if equalBox(boxSymbol("["), b) then
caller = ":Unknown file:-1"
          return true

      else
caller = ":Unknown file:-1"
          return false

      end

  end

end
-- Chose function name isCloseBrace
function isCloseBrace(b)
print("caller: ", caller, "-> isCloseBrace")
caller = "isCloseBrace:Unknown file:-1"
  if equalBox(boxSymbol(closeBrace()), b) then
caller = ":Unknown file:-1"
      return true

  else
caller = ":Unknown file:-1"
      if equalBox(boxSymbol("]"), b) then
caller = ":Unknown file:-1"
          return true

      else
caller = ":Unknown file:-1"
          return false

      end

  end

end
-- Chose function name skipList
function skipList(l)
print("caller: ", caller, "-> skipList")
local b =nil
caller = "skipList:Unknown file:-1"
  if isEmpty(l) then
caller = ":Unknown file:-1"
      return emptyList()

  else
caller = ":Unknown file:-1"
      b = car(l)
caller = ":Unknown file:-1"
      if isOpenBrace(b) then
caller = ":Unknown file:-1"
          return skipList(skipList(cdr(l)))

      else
caller = ":Unknown file:-1"
          if isCloseBrace(b) then
caller = ":Unknown file:-1"
              return cdr(l)

          else
caller = ":Unknown file:-1"
              return skipList(cdr(l))

          end

      end

  end

end
-- Chose function name makeNode
function makeNode(name,subname,code,children)
print("caller: ", caller, "-> makeNode")
caller = "makeNode:Unknown file:-1"
  return cons(boxSymbol("node"), alistCons(boxSymbol("line"), getTagFail(code, boxString("line"), boxInt(-1)), cons(cons(boxSymbol("name"), boxString(name)), cons(cons(boxSymbol("subname"), boxString(subname)), cons(cons(boxSymbol("code"), code), alistCons(boxSymbol("children"), children, emptyList()))))))

end
-- Chose function name addToNode
function addToNode(key,val,node)
print("caller: ", caller, "-> addToNode")
caller = "addToNode:Unknown file:-1"
  return cons(boxSymbol("node"), alistCons(key, val, cdr(node)))

end
-- Chose function name makeStatementNode
function makeStatementNode(name,subname,code,children,functionName)
print("caller: ", caller, "-> makeStatementNode")
caller = "makeStatementNode:Unknown file:-1"
  return addToNode(boxSymbol("functionName"), functionName, makeNode(name, subname, code, children))

end
-- Chose function name astExpression
function astExpression(tree)
print("caller: ", caller, "-> astExpression")
caller = "astExpression:Unknown file:-1"
  if isList(tree) then
caller = ":Unknown file:-1"
      return makeNode("expression", "expression", nil, astSubExpression(tree))

  else
caller = ":Unknown file:-1"
      return astSubExpression(tree)

  end

end
-- Chose function name astSubExpression
function astSubExpression(tree)
print("caller: ", caller, "-> astSubExpression")
caller = "astSubExpression:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return emptyList()

  else
caller = ":Unknown file:-1"
      if isList(tree) then
caller = ":Unknown file:-1"
          return cons(astExpression(car(tree)), astSubExpression(cdr(tree)))

      else
caller = ":Unknown file:-1"
          return makeNode("expression", "leaf", tree, nil)

      end

  end

end
-- Chose function name astIf
function astIf(tree,fname)
print("caller: ", caller, "-> astIf")
caller = "astIf:Unknown file:-1"
  if equalBox(boxString("then"), car(second(tree))) then
caller = ":Unknown file:-1"
      nop();

  else
caller = ":Unknown file:-1"
      printf("Error at %s:%s!  If statement is missing the true branch.\n\n", stringify(getTag(car(first(tree)), boxString("filename"))), stringify(getTag(car(first(tree)), boxString("line"))));

caller = ":Unknown file:-1"
      panic("Missing true branch in if statement!  All if statements must have a true and false branch, like this:\n\n(if hungryForApples\n(then (printf \"yes!\"))\n(else (printf \"no!\")))\n\n\n");

  end

caller = "astIf:Unknown file:-1"
  if equalBox(boxString("else"), car(third(tree))) then
caller = ":Unknown file:-1"
      nop();

  else
caller = ":Unknown file:-1"
      printf("Error at %s:%s!  If statement is missing the false branch.\n\n", stringify(getTag(car(first(tree)), boxString("filename"))), stringify(getTag(car(first(tree)), boxString("line"))));

caller = ":Unknown file:-1"
      panic("Missing false branch in if statement!  All if statements must have a true and false branch, like this:\n\n(if hungryForApples\n(then (printf \"yes!\"))\n(else (printf \"no!\")))\n\n\n");

  end

caller = "astIf:Unknown file:-1"
  return makeNode("statement", "if", tree, cons(cons(astExpression(first(tree)), nil), cons(astBody(cdr(second(tree)), fname), cons(astBody(cdr(third(tree)), fname), nil))))

end
-- Chose function name astSetStruct
function astSetStruct(tree)
print("caller: ", caller, "-> astSetStruct")
caller = "astSetStruct:Unknown file:-1"
  return makeNode("statement", "structSetter", tree, astExpression(third(tree)))

end
-- Chose function name astSet
function astSet(tree)
print("caller: ", caller, "-> astSet")
caller = "astSet:Unknown file:-1"
  return makeNode("statement", "setter", tree, astExpression(second(tree)))

end
-- Chose function name astGetStruct
function astGetStruct(tree)
print("caller: ", caller, "-> astGetStruct")
caller = "astGetStruct:Unknown file:-1"
  return makeNode("expression", "structGetter", tree, nil)

end
-- Chose function name astReturnVoid
function astReturnVoid(fname)
print("caller: ", caller, "-> astReturnVoid")
caller = "astReturnVoid:Unknown file:-1"
  return makeStatementNode("statement", "returnvoid", nil, nil, fname)

end
-- Chose function name astStatement
function astStatement(tree,fname)
print("caller: ", caller, "-> astStatement")
caller = "astStatement:Unknown file:-1"
  if isList(tree) then
caller = ":Unknown file:-1"
      nop();

  else
caller = ":Unknown file:-1"
      printf("Error at %s:%s!  Statement must be a list.\n\n", stringify(getTag(car(first(tree)), boxString("filename"))), stringify(getTag(car(first(tree)), boxString("line"))));

caller = ":Unknown file:-1"
      panic("A statement must be a list: (printf \"Hello\")\n\n\n");

  end

caller = "astStatement:Unknown file:-1"
  if equalBox(boxString("if"), car(tree)) then
caller = ":Unknown file:-1"
      return astIf(cdr(tree), fname)

  else
caller = ":Unknown file:-1"
      if equalBox(boxString("set"), car(tree)) then
caller = ":Unknown file:-1"
          return astSet(cdr(tree))

      else
caller = ":Unknown file:-1"
          if equalBox(boxString("get-struct"), car(tree)) then
caller = ":Unknown file:-1"
              printf("Choosing get-struct statement\n");

caller = ":Unknown file:-1"
              return astGetStruct(cdr(tree))

          else
caller = ":Unknown file:-1"
              if equalBox(boxString("set-struct"), car(tree)) then
caller = ":Unknown file:-1"
                  return astSetStruct(cdr(tree))

              else
caller = ":Unknown file:-1"
                  if equalBox(boxString("return"), car(tree)) then
caller = ":Unknown file:-1"
                      if equal(listLength(tree), 1) then
caller = ":Unknown file:-1"
                          return astReturnVoid(fname)

                      else
caller = ":Unknown file:-1"
                          return makeStatementNode("statement", "return", tree, makeNode("expression", "expression", tree, astExpression(tree)), fname)

                      end

                  else
caller = ":Unknown file:-1"
                      return makeStatementNode("statement", "statement", tree, makeNode("expression", "expression", tree, astExpression(tree)), fname)

                  end

              end

          end

      end

  end

end
-- Chose function name astBody
function astBody(tree,fname)
print("caller: ", caller, "-> astBody")
caller = "astBody:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return emptyList()

  else
caller = ":Unknown file:-1"
      return cons(astStatement(car(tree), fname), astBody(cdr(tree), fname))

  end

end
-- Chose function name astFunction
function astFunction(tree)
print("caller: ", caller, "-> astFunction")
local file =""
local line =""
local fname =nil
caller = "astFunction:Unknown file:-1"
  fname = second(tree)
caller = "astFunction:Unknown file:-1"
  line = stringify(getTag(fname, boxString("line")))
caller = "astFunction:Unknown file:-1"
  file = stringify(getTag(fname, boxString("filename")))
caller = "astFunction:Unknown file:-1"
  if greaterthan(1, listLength(tree)) then
caller = ":Unknown file:-1"
      locPanic(file, line, "Malformed function, seems to be empty");

  else
  end

caller = "astFunction:Unknown file:-1"
  if greaterthan(2, listLength(tree)) then
caller = ":Unknown file:-1"
      locPanic(file, line, "Malformed function, expected function name");

  else
  end

caller = "astFunction:Unknown file:-1"
  if greaterthan(3, listLength(tree)) then
caller = ":Unknown file:-1"
      locPanic(file, line, "Malformed function, expected argument list");

  else
  end

caller = "astFunction:Unknown file:-1"
  if greaterthan(4, listLength(tree)) then
caller = ":Unknown file:-1"
      locPanic(file, line, "Malformed function, expected variable declarations");

  else
  end

caller = "astFunction:Unknown file:-1"
  if greaterthan(5, listLength(tree)) then
caller = ":Unknown file:-1"
      locPanic(file, line, "Malformed function, expected body");

  else
  end

caller = "astFunction:Unknown file:-1"
  return alistCons(boxSymbol("file"), getTag(fname, boxString("filename")), alistCons(boxSymbol("line"), getTag(fname, boxString("line")), cons(cons(boxSymbol("name"), boxString("function")), cons(cons(boxSymbol("subname"), second(tree)), cons(cons(boxSymbol("declarations"), cdr(fourth(tree))), cons(cons(boxSymbol("intype"), third(tree)), cons(cons(boxSymbol("outtype"), car(tree)), cons(cons(boxSymbol("children"), astBody(cdr(fifth(tree)), fname)), emptyList()))))))))

end
-- Chose function name astFunctionList
function astFunctionList(tree)
print("caller: ", caller, "-> astFunctionList")
caller = "astFunctionList:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return emptyList()

  else
caller = ":Unknown file:-1"
      return cons(astFunction(car(tree)), astFunctionList(cdr(tree)))

  end

end
-- Chose function name astFunctions
function astFunctions(tree)
print("caller: ", caller, "-> astFunctions")
caller = "astFunctions:Unknown file:-1"
  if equalBox(boxString("functions"), car(tree)) then
caller = ":Unknown file:-1"
      return makeNode("functions", "functions", tree, astFunctionList(cdr(tree)))

  else
caller = ":Unknown file:-1"
      panic("Functions section not found!  Every program must have a function section, even if you don't define any functions, although that is a rather pointless program.  Your function section should look like:'\n\n(return_type function_name (arg1 arg2 arg3 ...) (declare types) (body (statement)(statement)))\n\n\nThe function section must be directly after the types section.");

caller = ":Unknown file:-1"
      return nil

  end

end
-- Chose function name loadLib
function loadLib(path)
print("caller: ", caller, "-> loadLib")
local programStr =""
local tree =nil
local library =nil
caller = "loadLib:Unknown file:-1"
  programStr = luaReadFile(path)
caller = "loadLib:Unknown file:-1"
  tree = readSexpr(programStr, path)
caller = "loadLib:Unknown file:-1"
  tree = macrowalk(tree)
caller = "loadLib:Unknown file:-1"
  library = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), nil)))
caller = "loadLib:Unknown file:-1"
  return library

end
-- Chose function name astInclude
function astInclude(tree)
print("caller: ", caller, "-> astInclude")
caller = "astInclude:Unknown file:-1"
  return loadLib(stringify(tree))

end
-- Chose function name astIncludeList
function astIncludeList(tree)
print("caller: ", caller, "-> astIncludeList")
caller = "astIncludeList:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return emptyList()

  else
caller = ":Unknown file:-1"
      return cons(astInclude(car(tree)), astIncludeList(cdr(tree)))

  end

end
-- Chose function name astIncludes
function astIncludes(tree)
print("caller: ", caller, "-> astIncludes")
caller = "astIncludes:Unknown file:-1"
  if equalBox(boxString("includes"), car(tree)) then
caller = ":Unknown file:-1"
      return makeNode("includes", "includes", tree, astIncludeList(cdr(tree)))

  else
caller = ":Unknown file:-1"
      panic("Includes section not found!  Every program must have an include section, even if you don't import any libraries.  Your include section should look like:'\n\n(includes file1.qon file.qon)\n\n\nThe includes section must be the first section of the file.");

caller = ":Unknown file:-1"
      return nil

  end

end
-- Chose function name astStruct
function astStruct(tree)
print("caller: ", caller, "-> astStruct")
caller = "astStruct:Unknown file:-1"
  return makeNode("type", "struct", tree, nil)

end
-- Chose function name astType
function astType(tree)
print("caller: ", caller, "-> astType")
caller = "astType:Unknown file:-1"
  if isList(cadr(tree)) then
caller = ":Unknown file:-1"
      return astStruct(tree)

  else
caller = ":Unknown file:-1"
      return makeNode("type", "type", tree, nil)

  end

end
-- Chose function name astTypeList
function astTypeList(tree)
print("caller: ", caller, "-> astTypeList")
caller = "astTypeList:Unknown file:-1"
  if isEmpty(tree) then
caller = ":Unknown file:-1"
      return emptyList()

  else
caller = ":Unknown file:-1"
      return cons(astType(car(tree)), astTypeList(cdr(tree)))

  end

end
-- Chose function name astTypes
function astTypes(tree)
print("caller: ", caller, "-> astTypes")
caller = "astTypes:Unknown file:-1"
  if isNil(tree) then
caller = ":Unknown file:-1"
      panic("Empty or absent types section");

caller = ":Unknown file:-1"
      return boxString("!!!Fuck")

  else
caller = ":Unknown file:-1"
      if equalBox(boxString("types"), car(tree)) then
caller = ":Unknown file:-1"
          return makeNode("types", "types", tree, astTypeList(cdr(tree)))

      else
caller = ":Unknown file:-1"
          panic("Types section not found!  Every program must have a types section, even if you don't define any types");

caller = ":Unknown file:-1"
          printf("Types section not found!  Every program must have a types section, even if you don't define any types");

caller = ":Unknown file:-1"
          return boxString("!!!Fuck")

      end

  end

end
-- Chose function name declarationsof
function declarationsof(ass)
print("caller: ", caller, "-> declarationsof")
caller = "declarationsof:Unknown file:-1"
  return cdr(assocPanic("declarations", cdr(ass), "Cons list has no declarations key"))

end
-- Chose function name codeof
function codeof(ass)
print("caller: ", caller, "-> codeof")
caller = "codeof:Unknown file:-1"
  return cdr(assocPanic("code", cdr(ass), "Given cons list does not contain a code key"))

end
-- Chose function name functionNameof
function functionNameof(ass)
print("caller: ", caller, "-> functionNameof")
caller = "functionNameof:Unknown file:-1"
  return cdr(assoc("functionName", cdr(ass)))

end
-- Chose function name nodeof
function nodeof(ass)
print("caller: ", caller, "-> nodeof")
caller = "nodeof:Unknown file:-1"
  if equalBox(boxBool(false), assoc("node", cdr(ass))) then
caller = ":Unknown file:-1"
      printf("Given list does not contain nodes");

caller = ":Unknown file:-1"
      return boxBool(false)

  else
caller = ":Unknown file:-1"
      return cdr(assoc("node", cdr(ass)))

  end

end
-- Chose function name lineof
function lineof(ass)
print("caller: ", caller, "-> lineof")
caller = "lineof:Unknown file:-1"
  return cdr(assocFail("line", cdr(ass), boxInt(-1)))

end
-- Chose function name subnameof
function subnameof(ass)
print("caller: ", caller, "-> subnameof")
caller = "subnameof:Unknown file:-1"
  return cdr(assoc("subname", cdr(ass)))

end
-- Chose function name nameof
function nameof(ass)
print("caller: ", caller, "-> nameof")
caller = "nameof:Unknown file:-1"
  return cdr(assoc("name", cdr(ass)))

end
-- Chose function name childrenof
function childrenof(ass)
print("caller: ", caller, "-> childrenof")
caller = "childrenof:Unknown file:-1"
  return cdr(assoc("children", cdr(ass)))

end
-- Chose function name isNode
function isNode(val)
print("caller: ", caller, "-> isNode")
caller = "isNode:Unknown file:-1"
  if isEmpty(val) then
caller = ":Unknown file:-1"
      return false

  else
caller = ":Unknown file:-1"
      if isList(val) then
caller = ":Unknown file:-1"
          if equalBox(boxSymbol("node"), car(val)) then
caller = ":Unknown file:-1"
              return true

          else
caller = ":Unknown file:-1"
              return false

          end

      else
caller = ":Unknown file:-1"
          return false

      end

  end

end
-- Chose function name isLeaf
function isLeaf(n)
print("caller: ", caller, "-> isLeaf")
caller = "isLeaf:Unknown file:-1"
  return equalBox(boxString("leaf"), subnameof(n))

end
-- Chose function name noStackTrace
function noStackTrace()
print("caller: ", caller, "-> noStackTrace")
caller = "noStackTrace:Unknown file:-1"
  return cons(boxString("boxType"), cons(boxString("stringify"), cons(boxString("isEmpty"), cons(boxString("unBoxString"), cons(boxString("isList"), cons(boxString("unBoxBool"), cons(boxString("unBoxSymbol"), cons(boxString("equalBox"), cons(boxString("assoc"), cons(boxString("inList"), cons(boxString("unBoxInt"), cons(boxString("listLength"), cons(boxString("stroff"), cons(boxString("troff"), cons(boxString("tron"), cons(boxString("stron"), cons(boxString("car"), cons(boxString("cdr"), cons(boxString("cons"), cons(boxString("stackTracePush"), cons(boxString("stackTracePop"), cons(boxString("assertType"), cons(boxString("boxString"), cons(boxString("boxSymbol"), cons(boxString("boxInt"), nil)))))))))))))))))))))))))

end
-- Chose function name treeCompile
function treeCompile(filename)
print("caller: ", caller, "-> treeCompile")
local programStr =""
local tree =nil
caller = "treeCompile:Unknown file:-1"
  programStr = luaReadFile(filename)
caller = "treeCompile:Unknown file:-1"
  tree = readSexpr(programStr, filename)
caller = "treeCompile:Unknown file:-1"
  return tree

end
-- Chose function name astBuild
function astBuild(filename)
print("caller: ", caller, "-> astBuild")
local programStr =""
local tree =nil
local program =nil
caller = "astBuild:Unknown file:-1"
  programStr = luaReadFile(filename)
caller = "astBuild:Unknown file:-1"
  tree = readSexpr(programStr, filename)
caller = "astBuild:Unknown file:-1"
  program = alistCons(boxString("includes"), astIncludes(first(tree)), alistCons(boxString("types"), astTypes(second(tree)), alistCons(boxString("functions"), astFunctions(third(tree)), nil)))
caller = "astBuild:Unknown file:-1"
  program = mergeIncludes(program)
caller = "astBuild:Unknown file:-1"
  return program

end
-- Chose function name astCompile
function astCompile(filename)
print("caller: ", caller, "-> astCompile")
local tree =nil
local replace =nil
caller = "astCompile:Unknown file:-1"
  tree = loadQuon(filename)
caller = "astCompile:Unknown file:-1"
  qlog("Final program: \n");

caller = "astCompile:Unknown file:-1"
  tree = loadIncludes(tree)
caller = "astCompile:Unknown file:-1"
  tree = macrowalk(tree)
caller = "astCompile:Unknown file:-1"
  tree = macrosingle(tree, "luaWriteFile", "luaWriteFile")
caller = "astCompile:Unknown file:-1"
  tree = macrosingle(tree, "luaReadFile", "luaReadFile")
caller = "astCompile:Unknown file:-1"
  tree = macrosingle(tree, "string.len", "string.len")
caller = "astCompile:Unknown file:-1"
  tree = macrosingle(tree, "luaSubstring", "luaSubstring")
caller = "astCompile:Unknown file:-1"
  tree = macrosingle(tree, "string.len", "string.len")
caller = "astCompile:Unknown file:-1"
  replace = cons(boxSymbol("fprintf"), cons(boxSymbol("stderr"), nil))
caller = "astCompile:Unknown file:-1"
  tree = macrolist(tree, stringConcatenate("q", "log"), replace)
caller = "astCompile:Unknown file:-1"
  displayList(tree, 0, true);

caller = "astCompile:Unknown file:-1"
  qlog("Transformed tree");

caller = "astCompile:Unknown file:-1"
  printf("\n");

end
-- Chose function name mergeIncludes
function mergeIncludes(program)
print("caller: ", caller, "-> mergeIncludes")
caller = "mergeIncludes:Unknown file:-1"
  return merge_recur(childrenof(cdr(cdr(assocPanic("includes", program, "Program lacks include section")))), program)

end
-- Chose function name merge_recur
function merge_recur(incs,program)
print("caller: ", caller, "-> merge_recur")
caller = "merge_recur:Unknown file:-1"
  if greaterthan(listLength(incs), 0) then
caller = ":Unknown file:-1"
      return mergeInclude(car(incs), merge_recur(cdr(incs), program))

  else
caller = ":Unknown file:-1"
      return program

  end

end
-- Chose function name mergeInclude
function mergeInclude(inc,program)
print("caller: ", caller, "-> mergeInclude")
local newProgram =nil
local oldfunctionsnode =nil
local oldfunctions =nil
local newfunctions =nil
local newFunctionNode =nil
local functions =nil
local oldtypesnode =nil
local oldtypes =nil
local newtypes =nil
local newTypeNode =nil
local types =nil
caller = "mergeInclude:Unknown file:-1"
  if isNil(inc) then
caller = ":Unknown file:-1"
      return program

  else
caller = ":Unknown file:-1"
      functions = childrenof(cdr(assocPanic("functions", inc, "Included file has no functions section")))
caller = ":Unknown file:-1"
      oldfunctionsnode = cdr(assocPanic("functions", program, "Current module has no functions section"))
caller = ":Unknown file:-1"
      oldfunctions = childrenof(oldfunctionsnode)
caller = ":Unknown file:-1"
      newfunctions = concatLists(functions, oldfunctions)
caller = ":Unknown file:-1"
      newFunctionNode = cons(boxSymbol("node"), alistCons(boxSymbol("children"), newfunctions, cdr(oldfunctionsnode)))
caller = ":Unknown file:-1"
      types = childrenof(cdr(assocPanic("types", inc, "Included file has no types section")))
caller = ":Unknown file:-1"
      oldtypesnode = cdr(assocPanic("types", program, "Current module has no types section"))
caller = ":Unknown file:-1"
      oldtypes = childrenof(oldtypesnode)
caller = ":Unknown file:-1"
      newtypes = concatLists(types, oldtypes)
caller = ":Unknown file:-1"
      newTypeNode = cons(boxSymbol("node"), alistCons(boxSymbol("children"), newtypes, cdr(oldtypesnode)))
caller = ":Unknown file:-1"
      newProgram = alistCons(boxString("functions"), newFunctionNode, alistCons(boxString("types"), newTypeNode, alistCons(boxString("includes"), cons(boxSymbol("includes"), nil), newProgram)))
caller = ":Unknown file:-1"
      return newProgram

  end

end
-- Chose function name add
function add(a,b)
print("caller: ", caller, "-> add")
caller = "add:Unknown file:-1"
  return sub(a, sub(0, b))

end
-- Chose function name addf
function addf(a,b)
print("caller: ", caller, "-> addf")
caller = "addf:Unknown file:-1"
  return subf(a, subf(0, b))

end
-- Chose function name sub1
function sub1(a)
print("caller: ", caller, "-> sub1")
caller = "sub1:Unknown file:-1"
  return sub(a, 1)

end
-- Chose function name add1
function add1(a)
print("caller: ", caller, "-> add1")
caller = "add1:Unknown file:-1"
  return add(a, 1)

end
-- Chose function name clone
function clone(b)
print("caller: ", caller, "-> clone")
local newb =nil
caller = "clone:Unknown file:-1"
  newb = makeBox()
caller = "clone:Unknown file:-1"
newb.typ = b.typ
caller = "clone:Unknown file:-1"
newb.tag = b.tag
caller = "clone:Unknown file:-1"
newb.lis = b.lis
caller = "clone:Unknown file:-1"
newb.str = b.str
caller = "clone:Unknown file:-1"
newb.i = b.i
caller = "clone:Unknown file:-1"
newb.lengt = b.lengt
caller = "clone:Unknown file:-1"
  return newb

end
-- Chose function name tern
function tern(cond,tr,fal)
print("caller: ", caller, "-> tern")
caller = "tern:Unknown file:-1"
  if cond then
caller = ":Unknown file:-1"
      return tr

  else
caller = ":Unknown file:-1"
      return fal

  end

end
-- Chose function name ternString
function ternString(cond,tr,fal)
print("caller: ", caller, "-> ternString")
caller = "ternString:Unknown file:-1"
  if cond then
caller = ":Unknown file:-1"
      return tr

  else
caller = ":Unknown file:-1"
      return fal

  end

end
-- Chose function name ternList
function ternList(cond,tr,fal)
print("caller: ", caller, "-> ternList")
caller = "ternList:Unknown file:-1"
  if cond then
caller = ":Unknown file:-1"
      return tr

  else
caller = ":Unknown file:-1"
      return fal

  end

end
-- Chose function name newVoid
function newVoid()
print("caller: ", caller, "-> newVoid")
local newb =nil
caller = "newVoid:Unknown file:-1"
  newb = makeBox()
caller = "newVoid:Unknown file:-1"
newb.voi = true
caller = "newVoid:Unknown file:-1"
newb.typ = "void"
caller = "newVoid:Unknown file:-1"
  return newb

end
-- Chose function name stackDump
function stackDump()
print("caller: ", caller, "-> stackDump")
caller = "stackDump:Unknown file:-1"
  printf("");

end
-- Chose function name nop
function nop()
print("caller: ", caller, "-> nop")
caller = "nop:Unknown file:-1"
  printf("");

end
-- Chose function name equalBox
function equalBox(a,b)
print("caller: ", caller, "-> equalBox")
caller = "equalBox:Unknown file:-1"
  if isList(b) then
caller = ":Unknown file:-1"
      return false

  else
caller = ":Unknown file:-1"
      if equalString("string", boxType(a)) then
caller = ":Unknown file:-1"
          return equalString(unBoxString(a), stringify(b))

      else
caller = ":Unknown file:-1"
          if equalString("bool", boxType(a)) then
caller = ":Unknown file:-1"
              return andBool(unBoxBool(a), unBoxBool(b))

          else
caller = ":Unknown file:-1"
              if equalString("symbol", boxType(a)) then
caller = ":Unknown file:-1"
                  if equalString("symbol", boxType(b)) then
caller = ":Unknown file:-1"
                      return equalString(unBoxSymbol(a), unBoxSymbol(b))

                  else
caller = ":Unknown file:-1"
                      return false

                  end

              else
caller = ":Unknown file:-1"
                  if equalString("int", boxType(a)) then
caller = ":Unknown file:-1"
                      return equal(unBoxInt(a), unBoxInt(b))

                  else
caller = ":Unknown file:-1"
                      return false

                  end

              end

          end

      end

  end

end
-- Chose function name openBrace
function openBrace()
print("caller: ", caller, "-> openBrace")
caller = "openBrace:Unknown file:-1"
  return "("

end
-- Chose function name closeBrace
function closeBrace()
print("caller: ", caller, "-> closeBrace")
caller = "closeBrace:Unknown file:-1"
  return ")"

end
-- Chose function name boxType
function boxType(b)
print("caller: ", caller, "-> boxType")
caller = "boxType:Unknown file:-1"
  return b.typ

end
-- Chose function name makeBox
function makeBox()
print("caller: ", caller, "-> makeBox")
local b =nil
caller = "makeBox:Unknown file:-1"
  b = new(box, Box)
caller = "makeBox:Unknown file:-1"
  if isNil(b) then
caller = ":Unknown file:-1"
      panic("failed to create box!");

  else
  end

caller = "makeBox:Unknown file:-1"
b.tag = nil
caller = "makeBox:Unknown file:-1"
b.car = nil
caller = "makeBox:Unknown file:-1"
b.cdr = nil
caller = "makeBox:Unknown file:-1"
b.lis = nil
caller = "makeBox:Unknown file:-1"
b.typ = "None - error!"
caller = "makeBox:Unknown file:-1"
  return b

end
-- Chose function name makePair
function makePair()
print("caller: ", caller, "-> makePair")
caller = "makePair:Unknown file:-1"
  return makeBox()

end
-- Chose function name boxString
function boxString(s)
print("caller: ", caller, "-> boxString")
local b =nil
caller = "boxString:Unknown file:-1"
  b = makeBox()
caller = "boxString:Unknown file:-1"
b.str = s
caller = "boxString:Unknown file:-1"
b.lengt = string.len(s)
caller = "boxString:Unknown file:-1"
b.typ = "string"
caller = "boxString:Unknown file:-1"
  return b

end
-- Chose function name boxSymbol
function boxSymbol(s)
print("caller: ", caller, "-> boxSymbol")
local b =nil
caller = "boxSymbol:Unknown file:-1"
  b = boxString(s)
caller = "boxSymbol:Unknown file:-1"
b.typ = "symbol"
caller = "boxSymbol:Unknown file:-1"
  return b

end
-- Chose function name boxBool
function boxBool(boo)
print("caller: ", caller, "-> boxBool")
local b =nil
caller = "boxBool:Unknown file:-1"
  b = makeBox()
caller = "boxBool:Unknown file:-1"
b.boo = boo
caller = "boxBool:Unknown file:-1"
b.typ = "bool"
caller = "boxBool:Unknown file:-1"
  return b

end
-- Chose function name boxInt
function boxInt(val)
print("caller: ", caller, "-> boxInt")
local b =nil
caller = "boxInt:Unknown file:-1"
  b = makeBox()
caller = "boxInt:Unknown file:-1"
b.i = val
caller = "boxInt:Unknown file:-1"
b.typ = "int"
caller = "boxInt:Unknown file:-1"
  return b

end
-- Chose function name assertType
function assertType(atype,abox,line,file)
print("caller: ", caller, "-> assertType")
caller = "assertType:Unknown file:-1"
  if isNil(abox) then
caller = ":Unknown file:-1"
      if equalString(atype, "nil") then
caller = ":Unknown file:-1"
          return 

      else
caller = ":Unknown file:-1"
          return 

      end

  else
caller = ":Unknown file:-1"
      if equalString(atype, boxType(abox)) then
caller = ":Unknown file:-1"
          return 

      else
caller = ":Unknown file:-1"
          printf("Assertion failure at line %d, in file %s: provided value is not a '%s'!  It was actually '%s'. Contents:", line, file, atype, boxType(abox));

caller = ":Unknown file:-1"
          display(abox);

caller = ":Unknown file:-1"
          display(cons(boxString("\nToken may have been read from "), cons(boxString(stringify(getTagFail(abox, boxString("filename"), boxString("source file not found")))), cons(boxString(":"), cons(boxString(stringify(getTagFail(abox, boxString("line"), boxString("source line not found")))), nil)))));

caller = ":Unknown file:-1"
          panic("Invalid type!");

      end

  end

end
-- Chose function name unBoxString
function unBoxString(b)
print("caller: ", caller, "-> unBoxString")
caller = "unBoxString:Unknown file:-1"
  assertType("string", b, 175, "q/base.qon");

caller = "unBoxString:Unknown file:-1"
  return b.str

end
-- Chose function name unBoxSymbol
function unBoxSymbol(b)
print("caller: ", caller, "-> unBoxSymbol")
caller = "unBoxSymbol:Unknown file:-1"
  return b.str

end
-- Chose function name unBoxBool
function unBoxBool(b)
print("caller: ", caller, "-> unBoxBool")
caller = "unBoxBool:Unknown file:-1"
  return b.boo

end
-- Chose function name unBoxInt
function unBoxInt(b)
print("caller: ", caller, "-> unBoxInt")
caller = "unBoxInt:Unknown file:-1"
  return b.i

end
-- Chose function name stringify_rec
function stringify_rec(b)
print("caller: ", caller, "-> stringify_rec")
caller = "stringify_rec:Unknown file:-1"
  if isNil(b) then
caller = ":Unknown file:-1"
      return ""

  else
caller = ":Unknown file:-1"
      return stringConcatenate(stringify(car(b)), stringConcatenate(" ", stringify_rec(cdr(b))))

  end

end
-- Chose function name stringify
function stringify(b)
print("caller: ", caller, "-> stringify")
caller = "stringify:Unknown file:-1"
  if isNil(b) then
caller = ":Unknown file:-1"
      return "()"

  else
caller = ":Unknown file:-1"
      if equalString("string", boxType(b)) then
caller = ":Unknown file:-1"
          return unBoxString(b)

      else
caller = ":Unknown file:-1"
          if equalString("bool", boxType(b)) then
caller = ":Unknown file:-1"
              if unBoxBool(b) then
caller = ":Unknown file:-1"
                  return "true"

              else
caller = ":Unknown file:-1"
                  return "false"

              end

          else
caller = ":Unknown file:-1"
              if equalString("int", boxType(b)) then
caller = ":Unknown file:-1"
                  return intToString(unBoxInt(b))

              else
caller = ":Unknown file:-1"
                  if equalString("symbol", boxType(b)) then
caller = ":Unknown file:-1"
                      return unBoxSymbol(b)

                  else
caller = ":Unknown file:-1"
                      if equalString("list", boxType(b)) then
caller = ":Unknown file:-1"
                          return stringConcatenate("(", stringConcatenate(stringify(car(b)), stringConcatenate(" ", stringConcatenate(stringify_rec(cdr(b)), ")"))))

                      else
caller = ":Unknown file:-1"
                          return stringConcatenate("Unsupported type: ", boxType(b))

                      end

                  end

              end

          end

      end

  end

end
-- Chose function name hasTag
function hasTag(aBox,key)
print("caller: ", caller, "-> hasTag")
caller = "hasTag:Unknown file:-1"
  if isNil(aBox) then
caller = ":Unknown file:-1"
      return false

  else
caller = ":Unknown file:-1"
      return isNotFalse(assoc(stringify(key), aBox.tag))

  end

end
-- Chose function name getTag
function getTag(aBox,key)
print("caller: ", caller, "-> getTag")
caller = "getTag:Unknown file:-1"
  if false then
caller = ":Unknown file:-1"
      printf("Getting %s from: ", stringify(key));

caller = ":Unknown file:-1"
      display(alistKeys(aBox.tag));

caller = ":Unknown file:-1"
      printf("\n");

  else
caller = ":Unknown file:-1"
      printf("");

  end

caller = "getTag:Unknown file:-1"
  return cdr(assoc(stringify(key), aBox.tag))

end
-- Chose function name getTagFail
function getTagFail(aBox,key,onFail)
print("caller: ", caller, "-> getTagFail")
caller = "getTagFail:Unknown file:-1"
  if hasTag(aBox, key) then
caller = ":Unknown file:-1"
      return getTag(aBox, key)

  else
caller = ":Unknown file:-1"
      return onFail

  end

end
-- Chose function name assocExists
function assocExists(key,aBox)
print("caller: ", caller, "-> assocExists")
caller = "assocExists:Unknown file:-1"
  if isNil(aBox) then
caller = ":Unknown file:-1"
      return false

  else
caller = ":Unknown file:-1"
      return isNotFalse(assoc(key, aBox))

  end

end
-- Chose function name assocFail
function assocFail(key,aBox,onFail)
print("caller: ", caller, "-> assocFail")
caller = "assocFail:Unknown file:-1"
  if assocExists(key, aBox) then
caller = ":Unknown file:-1"
      return assoc(key, aBox)

  else
caller = ":Unknown file:-1"
      return cons(boxString(key), onFail)

  end

end
-- Chose function name assocPanic
function assocPanic(key,aBox,onFail)
print("caller: ", caller, "-> assocPanic")
caller = "assocPanic:Unknown file:-1"
  if assocExists(key, aBox) then
caller = ":Unknown file:-1"
      return assoc(key, aBox)

  else
caller = ":Unknown file:-1"
      panic(onFail);

  end

caller = "assocPanic:Unknown file:-1"
  panic("Inconceivable");

caller = "assocPanic:Unknown file:-1"
  return nil

end
-- Chose function name setTag
function setTag(key,val,aStruct)
print("caller: ", caller, "-> setTag")
caller = "setTag:Unknown file:-1"
aStruct.tag = alistCons(key, val, aStruct.tag)
caller = "setTag:Unknown file:-1"
  return aStruct

end
-- Chose function name locPanic
function locPanic(file,line,message)
print("caller: ", caller, "-> locPanic")
caller = "locPanic:Unknown file:-1"
  printf("%s %s:%s\n", file, line, message);

caller = "locPanic:Unknown file:-1"
  panic(message);

end
-- Chose function name truthy
function truthy(aVal)
print("caller: ", caller, "-> truthy")
caller = "truthy:Unknown file:-1"
  return isNotFalse(aVal)

end
-- Chose function name isNotFalse
function isNotFalse(aVal)
print("caller: ", caller, "-> isNotFalse")
caller = "isNotFalse:Unknown file:-1"
  if equalString(boxType(aVal), "bool") then
caller = ":Unknown file:-1"
      if unBoxBool(aVal) then
caller = ":Unknown file:-1"
          return true

      else
caller = ":Unknown file:-1"
          return false

      end

  else
caller = ":Unknown file:-1"
      return true

  end

end
-- Chose function name toStr
function toStr(thing)
print("caller: ", caller, "-> toStr")
caller = "toStr:Unknown file:-1"
  return boxString(stringify(thing))

end
-- Chose function name listLast
function listLast(alist)
print("caller: ", caller, "-> listLast")
caller = "listLast:Unknown file:-1"
  if isEmpty(cdr(alist)) then
caller = ":Unknown file:-1"
      return car(alist)

  else
caller = ":Unknown file:-1"
      return listLast(cdr(alist))

  end

end
-- Chose function name newLine
function newLine(indent)
print("caller: ", caller, "-> newLine")
caller = "newLine:Unknown file:-1"
  printf("\n");

caller = "newLine:Unknown file:-1"
  printIndent(indent);

end
-- Chose function name printIndent
function printIndent(ii)
print("caller: ", caller, "-> printIndent")
caller = "printIndent:Unknown file:-1"
  if greaterthan(ii, 0) then
caller = ":Unknown file:-1"
      printf("  ");

caller = ":Unknown file:-1"
      printIndent(sub1(ii));

  else
caller = ":Unknown file:-1"
      return 

  end

end
-- Chose function name stringIndent
function stringIndent(ii)
print("caller: ", caller, "-> stringIndent")
caller = "stringIndent:Unknown file:-1"
  if greaterthan(ii, 0) then
caller = ":Unknown file:-1"
      return stringConcatenate("  ", stringIndent(sub1(ii)))

  else
caller = ":Unknown file:-1"
      return ""

  end

end
-- Chose function name argList
function argList(count,pos,args)
print("caller: ", caller, "-> argList")
caller = "argList:Unknown file:-1"
  if greaterthan(count, pos) then
caller = ":Unknown file:-1"
      return cons(boxString(getStringArray(pos, args)), argList(count, add1(pos), args))

  else
caller = ":Unknown file:-1"
      return nil

  end

end
-- Chose function name tron
function tron()
print("caller: ", caller, "-> tron")
caller = "tron:Unknown file:-1"
  globalTrace = true
end
-- Chose function name troff
function troff()
print("caller: ", caller, "-> troff")
caller = "troff:Unknown file:-1"
  globalTrace = false
end
-- Chose function name stron
function stron()
print("caller: ", caller, "-> stron")
caller = "stron:Unknown file:-1"
  globalStepTrace = true
end
-- Chose function name stroff
function stroff()
print("caller: ", caller, "-> stroff")
caller = "stroff:Unknown file:-1"
  globalStepTrace = false
end
-- Chose function name start
function start()
print("caller: ", caller, "-> start")
local runTests =false
local cmdLine =nil
local filename =nil
local runPerl =false
local runJava =false
local runAst =false
local runNode =false
local runNode2 =false
local runLua =false
local runIma =false
local runAnsi2 =false
local runAnsi3 =false
local runBash =false
local runTree =false
caller = "start:Unknown file:-1"
  cmdLine = listReverse(argList(globalArgsCount, 0, globalArgs))
caller = "start:Unknown file:-1"
  if greaterthan(listLength(cmdLine), 1) then
caller = ":Unknown file:-1"
      filename = second(cmdLine)
  else
caller = ":Unknown file:-1"
      filename = boxString("compiler.qon")
  end

caller = "start:Unknown file:-1"
  releaseMode = inList(boxString("--release"), cmdLine)
caller = "start:Unknown file:-1"
  runTests = inList(boxString("--test"), cmdLine)
caller = "start:Unknown file:-1"
  runJava = inList(boxString("--java"), cmdLine)
caller = "start:Unknown file:-1"
  runPerl = inList(boxString("--perl"), cmdLine)
caller = "start:Unknown file:-1"
  runAst = inList(boxString("--ast"), cmdLine)
caller = "start:Unknown file:-1"
  runTree = inList(boxString("--tree"), cmdLine)
caller = "start:Unknown file:-1"
  runNode = inList(boxString("--node"), cmdLine)
caller = "start:Unknown file:-1"
  runNode2 = inList(boxString("--node2"), cmdLine)
caller = "start:Unknown file:-1"
  runLua = inList(boxString("--lua"), cmdLine)
caller = "start:Unknown file:-1"
  runIma = inList(boxString("--ima"), cmdLine)
caller = "start:Unknown file:-1"
  runAnsi2 = inList(boxString("--ansi2"), cmdLine)
caller = "start:Unknown file:-1"
  runAnsi3 = inList(boxString("--ansi3"), cmdLine)
caller = "start:Unknown file:-1"
  runBash = inList(boxString("--bash"), cmdLine)
caller = "start:Unknown file:-1"
  globalTrace = inList(boxString("--trace"), cmdLine)
caller = "start:Unknown file:-1"
  globalStepTrace = inList(boxString("--steptrace"), cmdLine)
caller = "start:Unknown file:-1"
  if inList(boxString("--help"), cmdLine) then
caller = ":Unknown file:-1"
      printf("Usage: quon file [options]\n\nNote the options go after the file name\n");

caller = ":Unknown file:-1"
      printf("Options:\n");

caller = ":Unknown file:-1"
      printf("  --help      Display this help\n");

caller = ":Unknown file:-1"
      printf("  --release   Compile in release mode\n");

caller = ":Unknown file:-1"
      printf("  --test      Run the test suite\n");

caller = ":Unknown file:-1"
      printf("  --java      Compile to Java\n");

caller = ":Unknown file:-1"
      printf("  --perl      Compile to Perl\n");

caller = ":Unknown file:-1"
      printf("  --ast       Compile to the Abstract Syntax Tree\n");

caller = ":Unknown file:-1"
      printf("  --tree      Compile to an s-expression tree\n");

caller = ":Unknown file:-1"
      printf("  --node      Compile to Node.js\n");

caller = ":Unknown file:-1"
      printf("  --node2      Compile to Node.js, new outputter\n");

caller = ":Unknown file:-1"
      printf("  --lua       Compile to Lua\n");

caller = ":Unknown file:-1"
      printf("  --ima       Compile to Imaginary, the human-friendly language\n");

caller = ":Unknown file:-1"
      printf("  --ansi2     Compile to ANSI C, (quon version 2)\n");

caller = ":Unknown file:-1"
      printf("  --ansi3     Compile to ANSI C (quon version 3)\n");

caller = ":Unknown file:-1"
      printf("  --bash      Compile to Bash\n");

caller = ":Unknown file:-1"
      printf("  --trace     Trace execution\n");

caller = ":Unknown file:-1"
      printf("  --steptrace Step trace execution\n");

caller = ":Unknown file:-1"
      printf("  --help      Display this help\n");

caller = ":Unknown file:-1"
      exit(0);

  else
  end

caller = "start:Unknown file:-1"
  if runTests then
caller = ":Unknown file:-1"
      test0();

caller = ":Unknown file:-1"
      test1();

caller = ":Unknown file:-1"
      test2();

caller = ":Unknown file:-1"
      test3();

caller = ":Unknown file:-1"
      test4();

caller = ":Unknown file:-1"
      test5();

caller = ":Unknown file:-1"
      test6();

caller = ":Unknown file:-1"
      test7();

caller = ":Unknown file:-1"
      test8();

caller = ":Unknown file:-1"
      test9();

caller = ":Unknown file:-1"
      test10();

caller = ":Unknown file:-1"
      test12();

caller = ":Unknown file:-1"
      test13();

caller = ":Unknown file:-1"
      test15();

caller = ":Unknown file:-1"
      test16();

caller = ":Unknown file:-1"
      test17();

caller = ":Unknown file:-1"
      test18();

caller = ":Unknown file:-1"
      test19();

caller = ":Unknown file:-1"
      test20();

caller = ":Unknown file:-1"
      test21();

caller = ":Unknown file:-1"
      test22();

caller = ":Unknown file:-1"
      test23();

caller = ":Unknown file:-1"
      test24();

caller = ":Unknown file:-1"
      test25();

caller = ":Unknown file:-1"
      printf("\n\nAfter all that hard work, I need a beer...\n");

caller = ":Unknown file:-1"
      beers(9);

  else
caller = ":Unknown file:-1"
      if runTree then
caller = ":Unknown file:-1"
          display(macrowalk(treeCompile(unBoxString(filename))));

      else
caller = ":Unknown file:-1"
          if runAst then
caller = ":Unknown file:-1"
              astCompile(unBoxString(filename));

          else
caller = ":Unknown file:-1"
              if runNode then
caller = ":Unknown file:-1"
                  nodeCompile(unBoxString(filename));

caller = ":Unknown file:-1"
                  printf("\n");

              else
caller = ":Unknown file:-1"
                  if runNode2 then
caller = ":Unknown file:-1"
                      printf(StringListJoin(flatten(node2Compile(unBoxString(filename))), " "));

                  else
caller = ":Unknown file:-1"
                      if runPerl then
caller = ":Unknown file:-1"
                          perlCompile(unBoxString(filename));

caller = ":Unknown file:-1"
                          printf("\n");

                      else
caller = ":Unknown file:-1"
                          if runJava then
caller = ":Unknown file:-1"
                              javaCompile(unBoxString(filename));

caller = ":Unknown file:-1"
                              printf("\n");

                          else
caller = ":Unknown file:-1"
                              if runLua then
caller = ":Unknown file:-1"
                                  luaCompile(unBoxString(filename));

caller = ":Unknown file:-1"
                                  printf("\n");

                              else
caller = ":Unknown file:-1"
                                  if runIma then
caller = ":Unknown file:-1"
                                      imaCompile(unBoxString(filename));

caller = ":Unknown file:-1"
                                      printf("\n");

                                  else
caller = ":Unknown file:-1"
                                      if runAnsi2 then
caller = ":Unknown file:-1"
                                          ansi2Compile(unBoxString(filename));

caller = ":Unknown file:-1"
                                          printf("\n");

                                      else
caller = ":Unknown file:-1"
                                          if runAnsi3 then
caller = ":Unknown file:-1"
                                              ansi3Compile(unBoxString(filename));

caller = ":Unknown file:-1"
                                              printf("\n");

                                          else
caller = ":Unknown file:-1"
                                              if runBash then
caller = ":Unknown file:-1"
                                                  bashCompile(unBoxString(filename));

caller = ":Unknown file:-1"
                                                  printf("\n");

                                              else
caller = ":Unknown file:-1"
                                                  ansi3Compile(unBoxString(filename));

caller = ":Unknown file:-1"
                                                  printf("\n");

                                              end

                                          end

                                      end

                                  end

                              end

                          end

                      end

                  end

              end

          end

      end

  end

caller = "start:Unknown file:-1"
  return 0

end

function main()
globalArgs = arg
globalArgsCount = #arg
start()
end
main()
